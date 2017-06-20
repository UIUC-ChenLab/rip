/*
 * Copyright (c) 2015 ARM Limited
 * All rights reserved
 *
 * The license below extends only to copyright in the software and shall
 * not be construed as granting a license to any other intellectual
 * property including but not limited to intellectual property relating
 * to a hardware implementation of the functionality of the software
 * licensed hereunder.  You may use the software subject to the license
 * terms below provided that you ensure that this notice is replicated
 * unmodified and in its entirety in all distributions of the software,
 * modified or unmodified, in source code or in binary form.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Andreas Sandberg
 */

#ifndef __BASE_FRAMEBUFFER_HH__
#define __BASE_FRAMEBUFFER_HH__

#include <cmath>
#include <cstdint>

#include <vector>

#include "base/types.hh"

/**
 * Internal gem5 representation of a Pixel.
 */
struct Pixel
{
    Pixel()
        : red(0), green(0), blue(0), padding(0) {}

    Pixel(uint8_t _red, uint8_t _green, uint8_t _blue)
        : red(_red), green(_green), blue(_blue), padding(0) {}

    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t padding;
};

inline bool
operator==(const Pixel &lhs, const Pixel &rhs)
{
    return lhs.red == rhs.red &&
        lhs.green == rhs.green &&
        lhs.blue == rhs.blue &&
        lhs.padding == rhs.padding;
}


/**
 * Configurable RGB pixel converter.
 *
 * This class converts between external RGB representations and gem5's
 * internal Pixel representation. The class assumes that pixels are
 * stored in a word of configurable length (up to 32 bits). Individual
 * pixels are assumed to be represented by contiguous bit ranges in
 * the word (i.e., it is possible to shift and mask out a contiguous
 * bit range for each pixel).
 */
class PixelConverter
{
  public:
    /**
     * Color channel conversion and scaling helper class.
     */
    struct Channel {
        /**
         * @param offset Offset in bits.
         * @param width Width in bits.
         */
        Channel(unsigned offset, unsigned width);

        /**
         * Get the value of a single color channel represented as an
         * 8-bit number.
         */
        uint8_t toPixel(uint32_t word) const {
            return round(((word >> offset) & mask) * factor);
        }

        /**
         * Convert an 8-bit representation of a color into an external
         * format.
         */
        uint32_t fromPixel(uint8_t ch) const {
            return (static_cast<uint8_t>(round(ch / factor)) & mask) << offset;
        }

        /** Offset in bits */
        unsigned offset;
        /** Bit mask (after shifting) */
        unsigned mask;
        /**
         * Scaling factor when converting to the full range of an
         * 8-bit color channel
         */
        float factor;
    };

    PixelConverter(unsigned length,
                   unsigned ro, unsigned go, unsigned bo,
                   unsigned rw, unsigned gw, unsigned bw,
                   ByteOrder byte_order = LittleEndianByteOrder);

    /** Get the Pixel representation of a color word. */
    Pixel toPixel(uint32_t word) const {
        return Pixel(ch_r.toPixel(word),
                     ch_g.toPixel(word),
                     ch_b.toPixel(word));
    }

    /** Get a Pixel representation by reading a word from memory. */
    Pixel toPixel(const uint8_t *rfb) const {
        return toPixel(readWord(rfb));
    }

    /** Convert a Pixel into a color word */
    uint32_t fromPixel(const Pixel &pixel) const {
        return ch_r.fromPixel(pixel.red) |
            ch_g.fromPixel(pixel.green) |
            ch_b.fromPixel(pixel.blue);
    }

    /**
     * Convert a pixel into a color word and store the resulting word
     * in memory.
     */
    void fromPixel(uint8_t *rfb, const Pixel &pixel) const {
        writeWord(rfb, fromPixel(pixel));
    }

    /**
     * Read a word of a given length and endianness from memory.
     *
     * The number of bytes read from memory is determined by the
     * length of a color word. Note that some of the bytes may be
     * padding.
     *
     * @param p Pointer to the first byte in the word.
     * @return Word in host endianness.
     */
    uint32_t readWord(const uint8_t *p) const;
    /**
     * Write a word of a given length and endianness to memory.
     *
     * @param p Pointer to the first byte in memory.
     * @param word Word to store (host endianness).
     */
    void writeWord(uint8_t *p, uint32_t word) const;

    /** Bytes per pixel when stored in memory (including padding) */
    unsigned length;
    /**
     * Number of bits used to represent one pixel value (excluding
     * padding). This could be less than length * 8 if the pixel value
     * is padded.
     */
    unsigned depth;
    /** Byte order when stored to memory. */
    ByteOrder byte_order;

    /** Red channel conversion helper */
    Channel ch_r;
    /** Green channel conversion helper */
    Channel ch_g;
    /** Blue channel conversion helper */
    Channel ch_b;

    /** Predefined 32-bit RGB (red in least significant bits, 8
     * bits/channel, little endian) conversion helper */
    static const PixelConverter rgba8888_le;
    /** Predefined 16-bit RGB565 (red in least significant bits,
     * little endian) conversion helper */
    static const PixelConverter rgb565_le;

    /** Predefined 32-bit RGB (red in least significant bits, 8
     * bits/channel, big endian) conversion helper */
    static const PixelConverter rgba8888_be;
    /** Predefined 16-bit RGB565 (red in least significant bits,
     * big endian) conversion helper */
    static const PixelConverter rgb565_be;
};

/**
 * Internal gem5 representation of a frame buffer
 *
 * Display controllers and other devices producing images are expected
 * to use this class to represent the final image.
 *
 * Pixels are indexed relative to the upper left corner of the
 * image. That is, the pixel at position (0, 0) is the upper left
 * corner. The backing store is a linear vector of Pixels ordered left
 * to right starting in the upper left corner.
 */
class FrameBuffer
{
  public:
    /**
     * Create a frame buffer of a given size.
     *
     * @param width Width in pixels
     * @param height Height in pixels
     */
    FrameBuffer(unsigned width, unsigned height);
    /** Create an empty (0x0) frame buffer */
    FrameBuffer();

    virtual ~FrameBuffer();

    /**
     * Resize the frame buffer.
     *
     * This method resizes frame buffer including the backing
     * store. The contents of the backing store are undefined after
     * this operation.
     *
     * @param with Width in pixels.
     * @param height Height in pixels.
     */
    void resize(unsigned width, unsigned height);

    /** Frame buffer width in pixels */
    unsigned width() const { return _width; }
    /** Frame buffer height in pixels */
    unsigned height() const { return _height; }
    /** Total number of pixels in frame buffer */
    unsigned area() const { return _width * _height; }

    /**
     * Fill the frame buffer with a single pixel value
     *
     * @param pixel Pixel value to fill with.
     */
    void fill(const Pixel &pixel);
    /**
     * Fill the frame buffer with black pixels
     */
    void clear();

    /**
     * Fill the frame buffer with pixel data from an external buffer
     * of the same width and height as this frame buffer.
     *
     * @param fb External frame buffer
     * @param conv Pixel conversion helper
     */
    void copyIn(const uint8_t *fb, const PixelConverter &conv);
    /**
     * Fill the frame buffer with pixel data from an external buffer
     * of the same width and height as this frame buffer.
     *
     * @param fb External frame buffer
     * @param conv Pixel conversion helper
     */
    void copyIn(const std::vector<uint8_t> &fb, const PixelConverter &conv) {
        copyIn(fb.data(), conv);
    }

    /**
     * Store the contents of this frame buffer in an external buffer
     * of the same width and height as this frame buffer.
     *
     * @param fb External frame buffer
     * @param conv Pixel conversion helper
     */
    void copyOut(uint8_t *fb, const PixelConverter &conv) const;
    /**
     * Store the contents of this frame buffer in an external buffer
     * of the same width and height as this frame buffer.
     *
     * @param fb External frame buffer
     * @param conv Pixel conversion helper
     */
    void copyOut(std::vector<uint8_t> &fb, const PixelConverter &conv) const {
        copyOut(fb.data(), conv);
    }

    /**
     * Get a pixel from an (x, y) coordinate
     *
     * @param x Distance from the left margin.
     * @param y Distance from the top of the frame.
     */
    const Pixel &pixel(unsigned x, unsigned y) const {
        assert(x < _width);
        assert(y < _height);

        return pixels[y * _width + x];
    }

    /**
     * Get a pixel from an (x, y) coordinate
     *
     * @param x Distance from the left margin.
     * @param y Distance from the top of the frame.
     */
    Pixel &pixel(unsigned x, unsigned y) {
        assert(x < _width);
        assert(y < _height);

        return pixels[y * _width + x];
    }

    /**
     * Create a hash of the image that can be used for quick
     * comparisons.
     */
    uint64_t getHash() const;

    /**
     * Static "dummy" frame buffer.
     *
     * This is a dummy frame buffer that can be used as a place holder
     * for devices that always expect a frame buffer to be present.
     */
    static const FrameBuffer dummy;

    /** Frame buffer backing store */
    std::vector<Pixel> pixels;

  protected:
    /** Width in pixels */
    unsigned _width;
    /** Height in pixels */
    unsigned _height;
};

#endif // __BASE_FRAMEBUFFER_HH__
