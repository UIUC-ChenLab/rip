#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_MemCheckerMonitor[] = {
    120,156,197,89,109,83,28,199,17,238,217,221,59,184,3,4,
    8,1,146,64,112,78,34,251,162,138,33,81,44,75,21,19,
    37,142,98,87,197,85,198,206,226,20,242,217,149,205,178,59,
    192,30,251,114,181,59,8,157,10,190,4,85,146,202,247,228,
    31,228,67,126,75,190,228,31,37,221,61,187,123,203,203,33,
    149,21,93,224,110,152,237,157,233,233,151,167,123,122,6,15,
    242,159,26,126,127,217,2,200,254,46,0,124,252,8,8,1,
    34,1,29,1,66,10,240,111,192,65,13,210,15,192,175,193,
    75,128,142,1,210,128,83,236,152,240,141,1,241,36,207,169,
    67,104,50,69,64,191,9,210,130,78,13,182,227,89,176,100,
    29,14,154,144,254,1,132,16,177,128,167,254,24,248,227,240,
    18,185,99,167,193,12,199,129,136,77,38,54,192,159,96,98,
    19,252,73,238,76,64,127,6,228,36,116,166,104,88,231,26,
    178,189,135,108,167,153,237,191,137,173,143,111,230,193,191,70,
    195,81,174,175,105,164,69,35,121,189,105,230,50,83,72,57,
    11,157,235,69,127,174,210,191,81,233,207,87,250,11,149,254,
    98,165,127,147,251,40,217,117,232,222,130,238,109,232,46,193,
    46,26,107,182,148,98,25,164,9,221,59,208,185,3,18,63,
    203,112,138,246,244,175,87,102,172,240,140,185,114,198,42,207,
    104,65,167,5,18,63,171,122,70,29,182,218,11,232,163,224,
    63,248,211,70,31,129,154,196,230,153,76,179,32,137,157,32,
    222,77,2,131,222,215,169,33,143,122,212,140,229,174,125,66,
    174,253,39,176,95,125,35,119,237,9,32,99,65,186,132,6,
    156,112,231,196,128,126,27,142,5,116,45,240,77,56,198,101,
    106,36,192,158,128,83,3,190,53,105,192,9,182,22,58,96,
    5,44,165,253,218,101,7,104,78,99,112,82,131,227,26,108,
    61,61,54,136,112,208,128,244,31,240,98,153,153,142,51,83,
    3,142,177,181,224,212,130,147,58,108,227,32,36,117,27,164,
    190,120,122,140,154,34,101,171,109,161,180,155,21,117,73,21,
    63,72,99,55,146,234,38,246,157,158,155,186,145,243,185,140,
    158,236,75,239,64,166,159,39,113,160,146,180,221,44,70,39,
    217,90,207,85,251,54,79,55,201,46,81,79,49,219,36,150,
    106,2,59,187,65,236,59,81,226,31,134,82,141,19,79,103,
    55,8,165,227,240,203,223,68,189,36,85,159,164,105,146,218,
    100,90,38,134,137,91,206,32,195,122,97,146,201,54,173,198,
    203,216,196,94,209,232,221,30,115,36,1,88,100,154,236,203,
    204,75,131,158,66,143,105,142,52,154,184,181,201,87,220,100,
    219,216,172,239,39,145,92,63,144,81,36,83,121,127,125,79,
    70,15,184,121,63,83,238,78,40,215,119,14,131,208,95,127,
    250,232,195,245,94,95,237,39,241,58,190,15,98,37,209,56,
    225,250,16,179,172,225,208,235,180,192,81,176,231,4,172,154,
    179,47,195,158,76,167,136,122,155,22,23,51,98,82,212,133,
    41,218,98,10,123,53,252,154,98,217,152,16,155,1,41,231,
    145,194,132,47,171,138,40,114,179,128,3,3,210,101,194,75,
    23,63,130,28,140,168,217,162,119,6,191,251,45,89,69,83,
    187,38,161,64,19,143,25,99,8,54,28,185,65,110,143,129,
    129,82,131,110,29,52,128,16,119,26,81,105,159,90,28,78,
    108,12,100,110,65,246,55,64,43,35,116,142,33,135,213,169,
    9,34,158,1,213,164,232,71,234,2,46,248,71,70,230,86,
    155,196,223,100,100,168,253,32,75,142,98,182,63,245,57,150,
    182,208,50,95,246,191,216,233,74,79,101,171,72,248,58,57,
    108,121,110,28,39,170,229,250,126,203,85,42,13,118,14,149,
    204,90,42,105,221,205,218,228,82,123,182,0,87,201,175,223,
    43,192,68,142,71,48,233,7,63,240,20,62,204,241,3,123,
    33,147,10,129,177,159,248,25,210,137,197,158,84,54,9,169,
    200,200,9,11,194,184,113,104,40,45,143,227,174,225,243,199,
    133,36,12,206,118,189,128,82,38,195,93,213,100,84,186,89,
    230,176,36,68,103,0,18,227,103,110,120,40,153,59,34,73,
    161,64,212,213,50,140,8,130,28,185,133,246,172,82,156,196,
    126,31,37,12,188,247,104,241,155,12,196,73,134,226,60,194,
    112,12,219,58,254,173,139,5,195,179,114,240,213,11,0,82,
    74,84,192,238,23,57,2,16,140,167,152,126,218,6,231,15,
    214,138,35,243,123,212,163,201,246,50,53,119,168,89,161,102,
    181,80,252,237,107,63,117,94,251,135,180,162,193,42,179,114,
    228,36,179,80,206,63,19,93,183,6,209,133,137,114,139,162,
    196,160,88,26,68,137,69,73,53,125,76,45,14,229,248,51,
    33,251,138,82,56,69,19,51,163,192,193,16,160,222,32,48,
    216,84,246,12,153,96,188,192,180,77,64,173,162,117,175,130,
    86,155,188,196,80,181,111,21,153,209,161,17,26,164,246,18,
    177,170,93,98,235,22,53,239,140,206,224,3,184,237,93,128,
    219,71,180,248,76,14,183,41,134,89,19,191,51,134,103,230,
    94,40,119,206,185,115,48,35,140,89,151,96,236,93,234,153,
    23,245,30,57,188,114,109,63,173,192,139,4,52,170,74,109,
    98,167,191,72,186,84,129,181,136,133,192,118,188,136,123,187,
    193,123,251,143,121,111,231,250,128,43,41,157,176,77,206,217,
    186,83,35,163,236,154,176,144,239,217,89,3,219,94,154,60,
    239,183,146,221,150,98,173,41,191,110,220,205,214,238,102,31,
    97,230,108,61,230,156,165,115,167,206,142,169,236,81,118,163,
    169,159,60,247,36,239,145,252,228,56,58,153,57,156,216,156,
    124,239,69,140,205,147,73,141,194,214,156,214,51,149,82,54,
    31,145,181,155,165,181,73,248,207,104,185,38,155,218,20,139,
    136,167,166,96,153,28,157,199,185,26,227,183,248,253,21,153,
    159,244,150,64,245,181,189,165,37,102,101,72,45,251,71,103,
    48,243,214,85,177,215,145,247,239,10,172,212,7,88,161,175,
    89,4,192,159,129,43,85,1,127,2,66,3,58,61,15,128,
    50,94,200,253,115,52,252,247,192,145,114,73,93,192,121,103,
    139,106,1,30,129,233,40,123,200,67,117,153,240,25,252,165,
    18,102,197,102,110,230,181,104,117,51,183,202,156,197,48,122,
    173,13,219,58,155,220,200,61,251,110,70,195,116,198,26,68,
    238,96,99,40,139,71,204,216,111,31,83,227,122,33,135,100,
    250,118,128,40,218,14,151,196,156,81,193,201,79,168,185,95,
    66,68,20,180,183,42,222,42,12,223,189,29,189,59,124,67,
    50,88,44,245,244,152,34,99,95,224,84,198,66,173,136,133,
    251,101,44,72,222,205,94,242,65,133,90,131,92,127,106,8,
    60,85,98,65,71,135,56,11,100,13,58,117,138,26,46,192,
    69,30,84,162,200,107,148,5,207,108,149,108,156,77,109,182,
    210,251,218,177,212,60,31,81,190,32,223,110,132,110,180,227,
    187,143,99,90,140,86,244,138,48,51,10,241,103,170,226,83,
    136,136,97,26,240,227,131,66,141,103,35,202,21,31,34,239,
    82,124,142,12,63,241,56,65,124,181,47,91,145,140,118,240,
    76,186,31,244,90,187,161,187,199,222,49,115,245,190,40,212,
    83,236,222,243,5,72,118,143,218,164,229,37,49,38,242,67,
    15,215,107,249,18,143,104,210,111,189,223,226,93,160,21,100,
    45,119,7,223,186,158,210,144,63,27,183,92,237,186,233,94,
    198,133,237,193,17,117,71,232,93,7,207,225,1,22,249,61,
    40,183,93,125,52,44,147,58,151,239,58,130,112,135,196,195,
    151,234,235,28,70,197,136,189,70,205,15,97,180,185,255,3,
    228,29,209,34,100,178,186,88,50,26,134,90,188,44,108,191,
    36,30,217,197,224,253,215,235,4,175,190,12,202,67,184,78,
    35,229,24,221,7,80,219,160,109,160,211,44,136,19,220,78,
    50,113,170,32,94,227,118,154,137,51,5,113,150,219,235,76,
    156,43,136,55,184,157,103,226,66,65,92,228,246,38,19,111,
    21,119,88,183,153,184,4,157,101,186,204,33,202,29,202,42,
    99,111,154,85,56,38,71,24,141,71,255,211,100,98,63,252,
    63,73,111,63,130,188,210,24,150,72,68,85,181,41,157,72,
    186,162,56,236,84,245,226,219,149,149,225,40,118,188,84,186,
    74,106,119,45,143,76,97,78,75,122,233,23,131,28,113,177,
    52,255,184,212,237,148,107,173,254,13,246,162,62,239,177,23,
    197,118,124,27,107,116,139,107,244,13,170,209,143,217,16,142,
    161,203,244,1,64,107,165,61,40,87,198,242,232,162,100,218,
    38,186,28,39,9,221,94,79,198,190,125,15,170,21,54,191,
    30,17,46,40,27,158,66,165,252,49,197,13,44,169,47,70,
    37,229,251,138,174,236,206,90,25,135,163,115,44,35,249,175,
    5,146,219,92,62,150,73,223,222,160,134,211,124,153,225,237,
    95,148,110,121,247,10,152,98,20,120,154,78,71,186,215,29,
    138,197,25,159,78,6,36,117,247,138,153,184,77,198,78,18,
    135,125,94,227,245,70,210,18,116,60,43,41,234,209,21,243,
    248,182,49,114,51,180,163,131,219,123,140,7,34,186,181,246,
    146,195,88,241,162,223,121,50,201,65,110,190,106,144,250,217,
    43,185,203,200,201,2,95,94,46,220,27,76,39,241,86,74,
    241,134,13,83,15,95,181,66,22,186,207,134,72,247,93,231,
    146,104,75,133,104,151,143,121,181,230,94,239,240,77,12,55,
    124,250,25,195,13,29,198,137,130,199,249,50,148,74,14,75,
    109,138,130,47,191,199,242,37,214,143,73,223,113,244,241,28,
    159,67,199,25,101,193,245,115,228,253,12,242,171,78,44,184,
    68,29,75,174,121,81,254,26,141,122,67,112,77,123,238,63,
    58,90,62,186,61,211,7,210,126,102,243,190,57,93,166,18,
    254,143,67,81,87,82,214,225,24,221,116,35,125,83,204,119,
    160,246,247,33,191,169,178,223,43,83,18,221,226,241,45,128,
    190,115,193,93,130,235,109,46,175,237,159,18,157,130,44,122,
    176,86,40,184,118,94,65,254,167,71,244,128,33,117,113,220,
    86,16,233,139,117,62,17,86,223,251,169,139,253,249,115,212,
    76,166,129,27,6,47,228,16,126,184,110,206,111,245,210,247,
    79,194,4,133,242,243,49,119,134,143,249,117,18,209,250,100,
    184,226,181,34,123,158,95,166,161,161,172,159,184,102,190,188,
    188,96,140,165,114,47,160,76,196,156,202,89,249,46,75,238,
    87,63,184,34,50,170,28,70,136,75,125,62,213,215,107,143,
    233,66,55,163,219,67,186,134,111,76,55,16,163,180,9,155,
    162,137,219,176,101,78,206,52,172,201,137,134,213,24,51,249,
    214,116,74,204,25,77,171,49,49,41,170,191,171,136,227,166,
    177,58,223,16,255,5,141,153,66,146,
};

EmbeddedPython embedded_m5_internal_param_MemCheckerMonitor(
    "m5/internal/param_MemCheckerMonitor.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_MemCheckerMonitor.py",
    "m5.internal.param_MemCheckerMonitor",
    data_m5_internal_param_MemCheckerMonitor,
    2410,
    7783);

} // anonymous namespace
