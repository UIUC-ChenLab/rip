#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_enum_X86IntelMPPolarity[] = {
    120,156,189,87,221,110,27,85,16,158,179,187,118,98,199,110,
    146,166,117,146,54,180,6,84,176,16,196,80,126,138,212,170,
    80,42,16,173,32,148,53,40,169,91,177,56,222,147,120,19,
    123,215,218,61,73,106,148,220,144,10,120,1,30,129,11,222,
    134,55,130,249,102,189,182,211,166,18,55,73,148,157,156,157,
    51,59,103,126,190,153,51,105,211,240,39,199,207,231,85,162,
    228,51,69,228,243,175,162,46,81,79,81,83,145,210,138,252,
    57,218,205,81,252,17,249,57,122,78,212,180,72,91,116,204,
    11,155,158,88,20,150,228,155,60,117,109,225,40,26,20,73,
    59,212,204,209,122,56,79,142,206,211,110,145,226,159,73,41,
    21,42,218,240,167,200,159,166,231,172,157,23,5,81,56,77,
    96,22,133,89,32,127,70,152,69,242,75,178,152,161,193,28,
    233,18,53,203,16,107,94,96,181,239,176,218,89,81,251,15,
    212,250,188,51,79,254,5,136,179,93,143,33,233,64,82,206,
    155,21,45,172,194,166,157,121,208,99,184,197,47,23,169,121,
    81,184,11,147,220,75,212,188,36,220,203,147,220,10,53,43,
    194,93,156,228,46,81,115,73,184,203,212,92,70,12,26,181,
    139,28,204,224,95,254,169,113,48,201,148,152,236,235,56,9,
    162,208,11,194,173,40,176,176,159,7,65,232,219,32,83,195,
    28,220,71,14,254,38,73,128,111,13,115,112,68,164,240,78,
    212,181,232,72,22,71,22,13,106,116,168,104,199,33,223,166,
    67,62,38,7,147,182,21,29,91,244,212,134,192,17,83,135,
    35,117,141,28,147,38,96,71,34,149,106,154,162,163,28,29,
    230,168,177,113,104,129,177,91,160,248,47,250,101,69,148,78,
    139,82,139,14,153,58,116,236,208,81,158,214,89,136,89,59,
    5,196,87,109,28,178,167,204,105,212,28,182,118,109,194,93,
    184,226,7,113,216,234,105,179,196,107,79,135,123,61,111,227,
    211,79,30,132,70,119,191,125,244,40,234,182,226,192,12,106,
    197,76,58,74,86,251,45,211,113,229,115,27,113,233,245,141,
    168,141,66,109,102,120,177,21,132,190,215,139,252,189,174,54,
    211,208,233,109,5,93,237,121,178,249,160,215,143,98,243,101,
    28,71,177,139,208,10,179,27,181,70,95,32,176,237,110,148,
    232,26,78,147,99,92,168,55,144,222,234,139,70,24,32,38,
    227,99,95,39,237,56,232,27,206,88,170,17,210,208,86,67,
    174,132,36,235,76,234,157,168,167,235,187,186,215,211,177,190,
    89,223,214,189,143,133,188,151,152,214,102,87,215,55,247,130,
    174,95,103,215,235,253,129,233,68,97,157,247,3,142,2,7,
    167,91,127,69,88,86,89,20,0,74,14,130,109,47,16,215,
    188,142,238,246,117,92,6,247,10,14,87,115,170,164,242,202,
    86,53,85,230,85,142,31,91,173,88,51,106,45,128,115,109,
    56,12,124,57,147,136,66,154,21,237,90,20,175,0,47,59,
    252,171,144,96,70,77,3,123,150,236,125,143,168,164,220,29,
    27,40,72,153,135,130,49,6,27,75,222,65,218,67,18,160,
    228,104,39,79,41,128,24,119,41,162,226,1,40,139,67,141,
    197,202,29,74,254,36,142,50,67,231,144,134,176,58,182,73,
    133,115,100,138,40,83,230,86,248,192,95,5,153,141,26,204,
    95,19,100,152,78,144,68,7,161,196,31,107,169,165,6,71,
    230,209,224,187,205,29,221,54,201,117,102,60,142,246,170,237,
    86,24,70,166,218,242,253,106,203,152,56,216,220,51,58,169,
    154,168,122,35,169,33,165,238,124,6,174,145,190,65,63,3,
    19,18,207,96,74,95,252,160,109,248,101,65,94,36,11,137,
    54,12,140,78,228,39,204,135,138,109,109,92,24,105,16,228,
    72,12,17,220,120,16,197,241,44,119,129,223,239,101,150,8,
    56,107,249,12,74,137,238,110,153,162,160,178,149,36,158,88,
    2,190,0,16,138,247,91,221,61,45,218,25,73,134,13,194,
    50,181,225,156,32,40,149,155,121,47,46,133,81,232,15,216,
    194,160,253,54,14,95,18,32,150,4,138,151,25,134,83,76,
    243,252,55,175,42,86,219,25,130,47,159,1,176,2,215,73,
    210,175,134,8,96,48,30,115,251,169,89,210,63,196,43,169,
    204,55,176,194,199,238,10,200,107,32,215,64,174,103,142,159,
    189,247,229,23,189,191,133,19,45,113,89,156,67,146,236,204,
    57,255,68,117,45,143,171,139,27,101,3,85,98,161,150,198,
    85,226,160,169,198,119,65,89,84,234,207,166,228,7,180,112,
    84,147,40,67,225,112,9,96,53,46,12,9,149,59,135,16,
    76,103,152,118,1,212,73,180,110,79,160,213,69,150,4,170,
    238,114,214,25,61,72,164,32,117,175,66,85,238,148,88,87,
    65,94,63,191,128,143,225,182,253,18,220,110,227,240,185,33,
    220,202,2,179,34,63,115,86,219,30,102,97,116,115,46,188,
    0,51,96,204,57,5,99,111,97,101,191,236,247,185,195,107,
    232,237,87,19,240,130,129,214,164,83,107,188,24,44,194,151,
    73,96,45,242,32,176,30,46,242,221,110,201,221,254,190,220,
    237,50,31,200,200,147,54,108,91,122,118,186,200,33,40,91,
    54,85,134,119,118,82,96,218,143,163,103,131,106,180,85,53,
    226,53,250,235,157,27,201,234,141,228,54,119,206,234,93,233,
    89,105,239,76,187,99,172,251,232,110,248,244,203,103,109,45,
    119,164,188,121,94,218,204,60,105,108,222,240,238,101,140,93,
    70,72,173,44,214,210,214,19,19,163,155,159,83,180,139,163,
    104,195,248,135,56,174,40,161,182,213,34,227,169,168,196,38,
    47,237,227,50,141,201,46,63,95,32,252,240,91,19,6,97,
    183,145,90,44,206,192,45,247,221,19,152,57,115,87,220,58,
    235,254,49,195,74,126,140,21,60,118,86,0,191,243,80,163,
    0,151,223,8,104,224,164,15,11,96,84,47,72,255,2,196,
    127,34,169,148,83,230,2,233,59,13,204,2,34,193,237,40,
    185,37,162,233,152,240,144,254,152,40,179,236,50,183,135,179,
    232,228,101,238,140,122,150,192,232,127,93,216,206,201,230,134,
    244,116,90,9,196,210,142,53,174,220,241,197,48,26,30,185,
    99,159,61,166,166,211,131,60,216,244,116,140,40,92,135,87,
    213,130,53,129,147,15,64,110,142,32,162,50,222,153,154,119,
    157,94,125,123,123,233,237,240,4,54,56,98,245,236,148,68,
    244,133,255,75,82,123,175,140,194,58,72,92,112,220,89,16,
    43,235,8,220,63,120,52,53,3,153,119,210,35,71,44,180,
    133,53,30,105,210,209,28,247,186,251,38,13,187,175,139,33,
    194,93,165,225,205,36,200,78,251,72,168,15,164,147,72,170,
    221,15,193,95,100,114,175,109,130,125,253,117,176,221,145,83,
    218,81,200,49,10,141,84,247,120,207,84,70,175,223,68,7,
    39,37,11,147,91,6,240,185,31,241,191,99,113,47,139,220,
    73,241,217,151,5,12,204,95,59,53,234,39,191,173,188,82,
    78,230,188,246,126,43,62,199,182,33,137,186,147,54,228,187,
    24,1,146,187,76,48,184,21,102,11,42,111,225,191,7,155,
    251,96,89,57,118,105,174,224,148,102,10,78,97,202,150,123,
    182,204,104,46,58,133,82,89,21,172,201,231,63,149,135,144,
    29,
};

EmbeddedPython embedded_m5_internal_enum_X86IntelMPPolarity(
    "m5/internal/enum_X86IntelMPPolarity.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/enum_X86IntelMPPolarity.py",
    "m5.internal.enum_X86IntelMPPolarity",
    data_m5_internal_enum_X86IntelMPPolarity,
    1617,
    4154);

} // anonymous namespace
