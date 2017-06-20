#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_core[] = {
    120,156,181,89,221,111,220,198,17,31,126,220,73,119,146,34,
    201,178,36,127,200,214,217,142,237,179,227,88,109,154,52,15,
    113,221,74,178,226,58,141,101,135,114,96,231,18,148,165,184,
    171,59,74,60,242,66,238,217,190,64,42,138,202,104,139,162,
    232,67,129,246,161,15,125,40,208,2,237,95,211,255,168,157,
    153,37,121,39,127,20,41,196,74,226,122,56,92,206,206,206,
    252,230,99,105,31,178,159,10,94,63,106,0,164,210,4,16,
    248,103,64,8,208,53,160,101,128,33,13,16,231,97,175,2,
    201,251,32,42,240,2,160,101,2,78,60,68,194,130,47,77,
    136,38,249,157,42,132,22,115,12,24,212,65,218,208,170,192,
    227,104,22,108,89,133,189,58,36,63,3,195,48,34,3,158,
    136,49,16,227,240,2,165,35,81,99,129,227,64,204,58,51,
    107,32,38,152,89,7,49,201,196,4,12,102,64,78,66,107,
    138,166,181,222,66,177,215,81,236,52,139,253,23,137,21,248,
    100,25,196,91,52,29,245,250,130,102,218,52,147,215,155,102,
    41,51,32,88,202,14,238,103,182,152,56,11,210,130,221,19,
    208,58,1,18,255,102,225,144,182,140,172,57,104,205,129,156,
    131,221,147,208,58,9,226,4,203,152,231,217,243,68,136,57,
    230,44,48,103,129,8,113,146,57,139,204,89,204,137,83,52,
    230,66,79,67,235,52,115,207,140,114,207,66,235,44,136,121,
    126,123,137,31,47,17,33,22,152,115,142,57,231,136,16,139,
    204,57,207,156,243,68,136,83,204,89,102,206,50,17,226,52,
    115,26,204,105,16,33,206,48,231,2,115,46,16,33,206,50,
    231,34,115,46,18,33,150,152,115,137,57,151,136,16,231,152,
    243,54,115,222,102,2,141,113,25,90,151,153,184,2,173,43,
    76,92,133,214,85,38,154,208,106,50,113,13,90,215,152,184,
    14,173,235,76,188,3,173,119,152,184,1,173,27,132,148,173,
    38,162,13,130,127,227,79,211,64,74,77,226,240,84,38,105,
    16,71,110,16,237,196,129,73,207,171,52,16,64,125,26,198,
    50,164,174,19,82,255,1,12,83,97,102,72,61,0,48,232,
    30,32,52,225,128,137,3,19,6,77,216,55,96,215,6,97,
    193,62,46,83,33,155,183,13,56,52,225,43,139,38,28,224,
    104,35,158,206,131,173,52,76,119,25,79,90,210,24,28,84,
    96,191,2,91,79,246,77,98,236,213,32,249,27,124,179,196,
    66,199,89,168,9,251,56,218,112,104,195,65,21,30,227,36,
    100,237,214,8,92,198,147,125,220,41,114,182,154,54,106,187,
    57,178,93,218,138,8,146,200,235,74,69,91,114,253,56,145,
    205,122,254,40,78,111,246,60,213,113,120,174,69,70,232,246,
    20,203,136,35,169,38,144,216,9,34,225,118,99,209,15,165,
    26,39,1,238,78,16,74,215,229,135,247,186,189,56,81,27,
    73,18,39,14,217,145,153,97,236,21,111,208,146,126,24,167,
    178,73,171,241,50,14,137,87,52,123,167,199,18,73,1,214,
    143,94,22,50,245,147,160,167,208,61,90,34,205,38,105,77,
    114,12,15,233,15,112,88,233,196,93,185,178,39,187,93,153,
    200,247,86,218,178,251,1,15,239,166,202,219,14,229,202,118,
    63,8,197,202,170,115,127,165,55,80,157,56,90,73,159,5,
    237,21,218,252,77,100,156,32,49,200,112,3,222,128,219,145,
    97,79,38,83,196,61,67,75,24,51,198,164,81,53,44,163,
    105,76,33,85,193,203,50,150,204,9,99,51,160,45,248,180,
    45,130,140,61,10,18,242,156,1,123,38,36,75,4,129,93,
    252,51,200,103,8,132,45,122,102,242,179,207,104,239,154,187,
    107,145,99,53,115,159,97,131,248,193,153,183,200,147,17,176,
    239,43,176,91,5,141,9,132,146,6,73,50,160,17,167,147,
    24,19,133,219,144,254,17,208,150,136,134,125,200,144,114,104,
    129,17,205,128,170,83,126,66,238,2,46,248,75,6,219,86,
    147,212,223,100,255,171,78,144,198,207,34,182,50,209,28,30,
    91,104,153,135,131,7,219,187,210,87,233,50,50,190,136,251,
    13,223,139,162,88,53,60,33,26,158,82,73,176,221,87,50,
    109,168,184,113,57,109,146,227,156,217,28,66,133,188,65,47,
    135,12,185,23,33,163,111,68,224,43,188,153,227,27,246,66,
    42,21,186,191,19,139,20,249,36,162,45,149,67,74,42,50,
    114,204,138,48,58,92,154,74,203,227,188,183,240,126,53,215,
    132,33,216,172,230,128,73,101,184,163,234,140,61,47,77,93,
    214,132,248,69,24,60,245,194,190,100,233,136,23,133,10,17,
    169,117,40,21,104,167,72,233,124,143,172,120,20,71,98,128,
    122,4,254,85,90,226,20,195,109,146,1,55,143,96,27,195,
    177,138,255,86,141,5,211,183,51,136,85,115,152,45,208,6,
    129,157,108,100,126,70,200,29,98,222,104,154,28,248,172,59,
    71,217,69,162,232,101,103,137,134,115,52,156,167,97,57,223,
    94,89,123,156,122,121,143,31,146,92,147,55,198,91,32,131,
    91,249,22,196,145,72,57,61,140,20,204,99,91,132,120,147,
    226,98,136,120,155,114,94,114,155,70,156,202,177,100,65,250,
    136,50,44,69,6,11,163,32,64,56,19,53,4,57,27,196,
    153,161,141,142,231,248,116,8,116,163,200,107,143,32,207,33,
    95,48,236,156,211,121,46,115,105,134,6,156,115,150,68,85,
    94,99,209,6,13,23,202,54,235,16,58,237,87,160,243,17,
    45,49,147,65,103,138,33,83,199,107,198,244,173,204,214,69,
    249,154,123,9,50,132,23,251,53,120,185,66,148,245,234,238,
    254,79,80,201,246,244,241,8,84,72,13,115,84,245,77,36,
    6,139,164,241,40,72,22,177,230,62,142,22,177,140,154,92,
    70,191,195,101,148,75,49,247,96,58,145,90,156,75,53,81,
    161,173,239,88,176,144,149,199,180,134,99,47,137,159,15,26,
    241,78,67,241,222,40,239,221,186,156,222,188,156,126,132,25,
    173,113,155,115,137,206,105,58,107,37,178,71,89,135,94,221,
    120,238,75,174,80,124,231,186,58,201,184,156,112,220,172,242,
    33,94,230,201,112,102,110,81,78,183,169,74,40,203,150,106,
    211,122,97,83,82,241,19,18,90,103,131,90,198,34,98,163,
    110,240,202,174,206,162,220,222,240,83,188,214,200,200,180,59,
    9,212,127,59,91,90,47,86,153,148,119,110,28,241,127,73,
    10,59,43,40,225,243,220,239,213,161,223,233,178,114,200,254,
    26,184,125,54,224,87,64,158,69,7,102,144,45,16,78,174,
    156,163,233,63,5,198,246,107,106,47,231,131,45,170,183,60,
    3,211,68,250,33,79,213,165,248,19,248,205,72,96,228,5,
    211,202,90,184,209,130,105,23,185,132,33,241,173,138,162,125,
    52,233,144,19,58,94,74,211,116,38,25,198,218,48,45,23,
    109,24,102,210,178,240,49,174,197,185,180,242,87,67,116,80,
    201,57,107,204,153,35,62,255,46,13,239,21,238,54,114,94,
    9,74,44,195,155,235,160,171,51,240,151,180,146,205,186,77,
    143,113,61,94,31,248,33,182,131,57,100,43,57,100,239,20,
    144,149,92,38,94,112,131,78,163,73,190,59,52,13,60,28,
    234,99,33,246,62,116,182,168,130,28,163,62,154,142,124,149,
    236,200,135,112,167,69,24,126,249,197,105,135,146,212,145,170,
    196,150,216,212,54,42,28,170,125,69,195,243,82,195,153,220,
    117,43,244,186,219,194,187,221,38,145,36,215,207,227,195,204,
    149,156,25,85,146,176,109,188,73,79,190,253,32,87,246,105,
    169,161,252,125,148,80,40,201,192,21,177,207,241,251,168,35,
    27,93,217,221,198,147,86,39,232,53,118,66,175,205,150,206,
    107,211,221,220,145,42,223,193,239,244,57,234,36,111,43,111,
    2,232,224,250,56,58,131,201,222,230,100,255,67,74,246,251,
    28,208,174,169,243,253,208,65,92,155,249,208,64,16,143,228,
    51,87,35,72,167,113,114,182,215,235,201,72,56,215,143,196,
    31,119,134,94,210,214,243,74,119,166,139,199,204,0,27,222,
    221,97,236,77,99,110,62,137,185,249,85,236,145,42,35,59,
    226,16,172,20,193,184,84,178,126,236,191,175,115,255,233,54,
    190,72,252,220,96,235,152,197,90,137,199,35,53,208,25,240,
    38,13,215,104,184,85,24,156,98,70,72,60,240,201,204,230,
    106,6,138,38,11,207,116,42,137,7,88,33,185,18,225,125,
    232,186,229,215,149,247,81,194,78,110,228,42,38,183,170,89,
    171,214,134,70,46,98,103,106,8,59,120,37,112,10,252,36,
    113,247,126,224,39,241,195,245,97,90,238,247,252,82,85,94,
    165,244,1,71,91,160,255,81,85,154,17,197,73,215,11,71,
    181,117,214,202,182,238,186,78,56,199,81,149,122,172,32,117,
    142,218,181,124,77,41,171,252,226,248,154,98,161,122,208,87,
    189,190,186,19,36,67,4,8,188,41,83,217,13,148,240,219,
    17,101,33,251,41,50,66,189,80,246,229,82,52,12,188,120,
    227,121,160,214,67,233,69,253,94,249,113,117,23,37,252,254,
    24,42,206,177,217,82,90,105,53,12,63,13,82,37,35,44,
    11,229,43,250,99,148,240,135,227,57,190,206,142,151,194,241,
    34,17,119,181,219,237,140,87,170,174,247,80,194,159,142,167,
    235,172,6,233,122,24,251,123,31,39,242,235,190,140,252,129,
    86,153,82,183,10,252,189,244,161,76,182,164,143,173,86,169,
    202,255,4,37,252,249,24,136,160,50,224,247,147,71,168,97,
    249,40,184,143,18,254,114,60,203,234,240,79,2,47,12,190,
    33,204,14,63,165,250,61,229,150,157,2,232,152,251,215,227,
    41,76,51,240,68,189,222,145,254,94,47,14,34,165,83,235,
    131,178,109,251,16,37,252,253,120,170,210,167,215,126,84,88,
    247,110,24,111,123,97,170,45,108,178,133,75,213,248,51,148,
    240,207,161,198,220,245,189,244,201,95,175,247,46,228,71,175,
    65,234,16,199,153,46,116,230,175,212,121,15,68,58,241,193,
    127,211,235,234,239,142,252,173,205,185,4,217,87,20,135,62,
    236,233,46,137,190,35,241,121,87,127,41,192,150,148,191,21,
    240,1,208,249,30,13,212,180,112,134,212,109,19,55,76,137,
    108,83,146,76,56,243,248,79,189,132,161,119,223,123,78,1,
    195,61,3,87,99,46,116,124,178,90,11,218,27,145,8,188,
    104,109,160,228,131,68,200,132,229,96,220,163,141,34,197,54,
    127,117,142,34,181,63,13,148,10,229,127,125,123,254,77,211,
    184,120,113,121,224,212,203,57,141,115,3,199,32,227,154,17,
    195,78,96,140,102,133,31,91,128,53,20,152,237,106,85,136,
    68,145,177,239,69,79,17,19,226,81,39,145,158,184,119,135,
    223,200,120,15,227,68,33,135,58,84,63,238,246,130,80,222,
    241,148,228,116,77,71,11,247,206,198,218,231,119,245,255,87,
    208,237,166,190,159,206,239,31,57,171,235,247,54,239,186,15,
    54,75,207,55,250,192,166,63,250,220,38,5,210,159,227,64,
    159,115,107,211,53,108,65,233,127,14,44,163,142,221,190,109,
    77,206,212,236,201,137,154,93,27,179,248,139,221,20,158,191,
    235,118,109,98,97,178,134,119,53,163,102,213,204,225,239,148,
    161,175,111,245,107,140,254,254,7,132,215,4,144,
};

EmbeddedPython embedded_m5_internal_core(
    "m5/internal/core.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/swig/core.py",
    "m5.internal.core",
    data_m5_internal_core,
    2509,
    7535);

} // anonymous namespace
