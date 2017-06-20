#include "sim/init.hh"

namespace {

const uint8_t data_m5_util_attrdict[] = {
    120,156,189,85,221,111,227,68,16,159,93,199,206,71,115,215,
    114,18,45,61,4,184,47,40,18,208,160,59,129,4,220,29,
    199,103,43,36,250,224,60,220,17,129,140,207,222,182,78,99,
    59,242,174,129,160,242,66,249,195,153,25,123,157,180,21,60,
    160,148,164,29,239,206,122,231,227,55,51,191,196,208,124,28,
    252,127,238,3,232,55,5,64,130,127,2,18,9,103,14,76,
    121,171,4,156,162,198,129,191,0,174,0,126,152,74,122,67,
    73,214,118,90,173,67,151,26,173,219,106,59,160,92,72,60,
    184,144,80,238,9,60,70,237,212,131,164,11,202,131,176,11,
    73,143,22,73,31,158,208,99,0,251,71,248,156,117,225,232,
    184,86,215,251,30,237,251,244,230,149,168,143,142,142,143,235,
    11,79,241,241,51,26,185,121,154,240,210,177,254,182,232,120,
    198,127,97,187,237,66,200,238,249,142,117,138,207,218,31,251,
    229,101,142,56,12,97,50,186,135,64,153,30,138,200,152,50,
    73,99,99,72,147,85,115,147,182,154,1,106,138,133,73,139,
    156,182,177,197,24,145,133,47,9,227,207,112,161,48,38,65,
    208,214,80,34,86,53,122,180,232,52,72,79,221,6,92,138,
    158,241,156,118,33,152,140,60,188,175,159,161,120,81,70,11,
    159,124,188,239,235,194,95,22,149,31,71,185,95,105,229,83,
    44,233,171,202,224,42,142,149,214,190,41,252,51,101,198,90,
    25,95,205,85,166,114,163,99,137,38,100,83,252,175,40,176,
    49,46,46,5,92,2,92,120,80,238,211,98,198,26,4,117,
    98,4,24,73,170,43,9,51,199,106,71,148,213,201,168,67,
    176,108,161,8,67,116,147,26,149,133,161,113,41,206,106,161,
    202,128,210,55,59,246,184,13,46,12,71,228,223,208,109,173,
    230,167,188,160,211,17,93,96,193,121,142,207,139,76,141,47,
    84,150,169,82,61,26,159,169,236,35,22,31,104,19,189,154,
    171,177,46,227,241,98,105,206,139,124,140,39,149,73,231,99,
    91,140,67,212,111,173,59,14,195,3,50,235,113,69,134,226,
    158,136,157,6,130,22,134,239,106,24,12,112,182,130,192,208,
    7,164,153,9,170,21,106,202,79,9,11,227,88,56,58,12,
    155,164,245,132,64,115,215,246,156,226,137,33,156,66,46,157,
    33,71,73,90,114,159,96,6,165,209,191,166,230,60,160,228,
    107,164,234,128,181,13,120,181,175,129,29,145,129,128,76,5,
    93,122,157,112,254,37,154,87,106,163,176,5,67,52,241,238,
    10,171,3,177,47,238,168,101,18,53,175,51,187,133,1,158,
    212,24,48,138,171,156,55,155,41,117,230,123,55,186,66,52,
    19,43,109,166,84,173,182,37,108,18,194,182,47,153,226,29,
    199,184,217,254,29,218,254,197,215,105,104,62,36,187,146,67,
    109,11,210,134,249,26,192,181,34,8,228,152,107,209,82,124,
    213,34,65,75,43,76,235,81,37,235,119,17,185,110,35,127,
    188,138,124,68,36,202,76,26,134,121,148,225,33,207,67,24,
    102,69,82,205,105,219,173,59,160,136,177,47,232,61,110,72,
    174,85,240,128,196,235,215,128,222,88,51,144,157,119,200,22,
    185,243,132,39,250,46,127,157,219,68,190,7,255,64,228,65,
    61,245,250,39,104,72,218,58,32,158,54,231,145,241,115,165,
    141,74,110,241,180,210,126,84,153,34,139,76,26,71,243,249,
    210,143,75,133,200,13,124,252,52,87,200,12,254,180,68,101,
    170,244,97,108,135,209,181,245,143,112,177,124,72,157,106,132,
    29,61,105,71,239,69,254,28,58,200,63,23,3,40,127,4,
    33,4,145,90,199,146,218,231,240,39,64,206,23,241,39,243,
    15,73,109,113,9,150,202,28,16,248,152,188,228,126,98,78,
    11,250,132,59,207,36,207,45,183,63,151,245,62,138,47,108,
    106,223,148,101,81,6,52,207,92,210,134,214,110,146,24,93,
    78,54,91,73,10,229,19,178,181,195,85,115,196,67,28,236,
    109,225,201,190,216,17,204,63,193,46,9,42,99,240,134,13,
    254,14,90,138,114,251,152,108,145,79,79,122,226,63,180,210,
    83,20,223,23,73,122,186,188,221,76,145,159,165,90,167,249,
    217,90,63,205,42,109,252,82,153,170,204,181,127,82,228,170,
    165,138,182,85,30,255,123,171,60,104,91,229,144,90,133,234,
    254,114,141,76,220,182,238,210,66,23,236,91,58,36,135,119,
    74,217,228,238,91,178,213,91,171,237,255,89,83,74,238,235,
    182,166,72,19,13,151,101,81,154,135,97,74,24,165,210,54,
    246,239,44,151,105,159,145,27,216,81,8,67,156,113,100,55,
    226,108,230,157,122,132,164,205,130,111,253,22,16,27,5,111,
    147,24,220,73,46,28,249,147,154,119,159,189,69,54,31,161,
    216,150,187,123,187,247,119,123,67,209,199,239,0,71,102,71,
    108,9,87,10,217,197,108,121,37,92,60,217,198,223,75,87,
    244,80,243,55,153,234,125,177,
};

EmbeddedPython embedded_m5_util_attrdict(
    "m5/util/attrdict.py",
    "/home/kemmere2/gem5/gem5-stable/src/python/m5/util/attrdict.py",
    "m5.util.attrdict",
    data_m5_util_attrdict,
    1096,
    3150);

} // anonymous namespace
