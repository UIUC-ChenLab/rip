#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_Vnc[] = {
    120,156,173,82,81,107,212,64,16,158,205,221,229,174,181,130,
    138,218,71,243,84,162,224,5,44,5,31,164,148,62,8,245,
    65,75,174,8,222,75,200,109,230,154,212,236,38,236,238,149,
    246,185,254,111,157,153,94,79,105,193,167,38,217,143,221,217,
    201,55,223,126,179,26,214,207,128,198,81,2,224,191,208,164,
    162,79,65,11,96,20,204,21,40,94,71,208,70,112,86,13,
    0,21,44,21,84,67,248,5,112,3,240,99,62,128,106,4,
    56,144,104,188,137,14,161,26,195,44,157,16,93,243,155,158,
    84,209,44,108,17,204,26,243,109,113,129,58,220,134,24,222,
    5,206,251,110,245,137,237,87,65,255,43,234,152,69,237,209,
    4,129,181,144,148,121,196,234,168,44,14,225,130,42,199,44,
    238,38,130,249,24,242,89,202,255,228,17,129,127,73,176,40,
    61,102,151,86,243,104,152,123,90,215,254,13,109,232,178,15,
    43,135,137,174,75,123,142,85,178,116,165,65,159,132,46,89,
    54,45,122,209,45,162,138,194,210,78,81,132,109,89,152,174,
    90,181,188,28,114,194,117,143,18,215,87,87,69,141,101,133,
    46,140,104,121,90,18,155,100,28,119,93,43,161,207,101,235,
    49,60,165,153,84,42,214,245,83,62,230,95,240,251,4,89,
    221,25,204,126,162,49,232,240,67,118,142,230,64,224,189,15,
    229,162,197,204,59,157,109,206,69,158,77,251,107,57,240,91,
    38,136,9,98,197,175,120,77,219,51,116,151,232,30,122,250,
    241,63,158,146,161,212,105,246,52,150,200,152,251,77,93,230,
    200,132,93,230,50,249,19,46,248,234,158,203,94,202,145,205,
    205,206,46,109,115,78,219,248,128,54,233,59,23,26,57,229,
    115,2,74,77,116,219,160,13,137,93,153,5,186,148,245,230,
    210,62,118,46,103,215,114,169,51,102,171,25,206,116,127,74,
    36,226,44,179,5,206,62,177,33,112,218,154,229,145,12,101,
    221,83,38,152,108,12,125,161,190,166,44,42,236,16,152,131,
    233,230,30,231,112,119,181,41,218,115,239,189,52,68,72,30,
    73,144,220,197,79,183,183,239,112,239,174,211,207,212,118,244,
    122,244,7,205,197,203,154,
};

EmbeddedPython embedded_m5_objects_Vnc(
    "m5/objects/Vnc.py",
    "/home/kemmere2/gem5/gem5-stable/src/base/vnc/Vnc.py",
    "m5.objects.Vnc",
    data_m5_objects_Vnc,
    487,
    965);

} // anonymous namespace
