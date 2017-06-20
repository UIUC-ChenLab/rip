#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_BaseGic[] = {
    120,156,189,88,235,114,219,198,21,62,11,128,148,72,81,150,
    100,221,108,75,182,232,56,182,89,79,35,181,110,92,119,38,
    138,167,142,147,118,146,25,43,46,232,142,109,37,83,20,34,
    150,18,40,92,56,192,74,50,51,82,127,68,158,94,30,160,
    143,208,31,125,155,62,71,94,162,61,231,44,0,129,148,212,
    201,76,75,203,228,122,185,123,112,246,92,190,115,89,116,32,
    251,171,224,247,215,77,128,244,7,1,224,225,71,64,0,16,
    10,216,22,32,164,0,111,1,246,43,144,124,12,94,5,222,
    1,108,27,32,13,56,197,137,9,223,24,16,53,248,153,42,
    4,38,175,8,24,212,65,90,176,93,129,87,209,28,88,178,
    10,251,117,72,254,8,66,136,72,192,107,111,2,188,73,120,
    135,220,113,82,99,134,147,64,139,117,94,172,129,55,197,139,
    117,240,26,60,153,130,193,44,200,6,108,79,19,217,246,21,
    100,251,0,217,206,48,219,127,17,91,15,119,22,193,187,66,
    228,40,215,27,162,180,136,146,207,155,97,46,179,185,148,115,
    176,125,53,159,207,151,230,11,165,249,98,105,190,84,154,47,
    151,230,215,74,243,235,165,249,141,210,124,165,52,95,45,205,
    111,150,230,183,74,243,53,158,163,182,87,161,215,132,222,109,
    232,125,0,93,116,192,92,161,217,29,144,38,244,62,132,237,
    15,65,226,231,14,156,162,143,188,171,165,39,238,242,19,243,
    197,19,247,248,137,251,176,125,31,36,126,238,233,39,170,208,
    110,45,161,223,253,127,227,95,11,253,14,170,129,195,161,76,
    82,63,142,28,63,234,198,190,65,251,85,26,8,37,29,26,
    38,50,184,60,35,184,252,19,24,43,158,145,193,229,4,144,
    177,32,93,2,3,78,120,114,98,192,160,5,199,2,122,22,
    120,38,28,227,49,21,18,96,87,192,169,1,223,154,68,112,
    130,163,133,78,189,5,150,210,88,233,177,83,53,167,9,56,
    169,192,113,5,218,175,143,13,90,216,175,65,242,15,248,110,
    149,153,78,50,83,3,142,113,180,224,212,130,147,42,188,66,
    34,92,234,213,72,125,241,250,24,53,197,149,118,203,66,105,
    183,74,234,146,42,158,159,68,110,40,213,21,156,59,125,55,
    113,67,231,51,55,149,191,245,59,173,122,78,19,167,235,125,
    87,237,217,252,144,73,214,8,251,138,153,197,145,84,83,56,
    233,250,145,231,132,177,119,16,72,53,73,156,156,174,31,72,
    199,225,205,47,195,126,156,168,47,146,36,78,108,50,40,47,
    6,177,91,60,65,230,236,4,113,42,91,116,26,31,99,19,
    123,69,212,221,62,115,36,1,88,80,122,216,147,105,39,241,
    251,10,253,164,57,18,53,113,107,145,135,120,72,159,227,176,
    177,23,135,114,99,95,134,161,76,228,195,141,93,25,62,226,
    225,163,84,185,59,129,220,216,57,240,3,111,227,169,253,124,
    163,63,80,123,113,180,129,251,126,164,36,154,36,216,24,50,
    198,58,18,92,37,182,71,254,174,227,179,66,206,158,12,250,
    50,153,166,213,27,116,164,152,21,13,81,21,166,104,137,105,
    156,85,240,107,138,85,99,74,108,249,164,82,135,212,36,44,
    89,101,244,144,75,5,236,27,144,172,18,54,122,248,17,228,
    76,68,72,155,246,12,222,251,29,217,66,175,246,76,242,184,
    94,60,102,60,33,176,144,114,147,92,28,1,131,162,2,189,
    42,104,176,32,198,52,122,146,1,141,72,78,108,12,100,110,
    65,250,119,64,219,34,76,142,33,131,208,169,9,34,154,5,
    85,167,236,129,171,75,120,224,247,140,194,118,139,196,223,98,
    60,168,61,63,141,143,34,182,58,205,57,110,218,104,153,23,
    131,175,119,122,178,163,210,53,92,120,19,31,52,59,110,20,
    197,170,233,122,94,211,85,42,241,119,14,148,76,155,42,110,
    222,77,91,228,72,123,46,135,84,193,111,208,207,33,68,238,
    70,8,233,31,158,223,81,248,99,158,127,176,23,82,169,16,
    14,123,177,151,226,58,177,216,149,202,38,33,21,25,57,102,
    65,24,45,14,145,210,241,72,71,48,127,154,75,194,144,108,
    85,115,0,165,50,232,170,58,99,209,77,83,135,37,161,117,
    134,29,49,62,116,131,3,201,220,17,63,10,5,162,169,150,
    97,172,192,187,70,74,228,58,179,34,81,28,121,3,148,203,
    239,220,167,35,175,49,252,26,12,192,69,4,223,4,142,85,
    252,191,42,150,140,142,149,65,174,154,195,142,146,158,2,118,
    186,200,252,142,16,60,197,4,211,50,56,67,176,46,28,133,
    31,208,140,30,182,87,105,184,73,195,45,26,214,114,117,199,
    165,243,244,168,206,143,233,28,131,21,101,149,200,33,102,174,
    146,55,20,73,215,207,34,9,19,96,155,34,194,160,184,57,
    139,8,139,146,101,242,132,70,36,229,88,51,33,125,73,169,
    153,34,135,153,81,144,32,220,105,118,22,4,108,32,123,150,
    20,159,204,241,107,19,40,203,200,220,45,33,211,38,223,48,
    44,237,235,121,238,115,136,66,3,210,94,33,86,149,11,44,
    220,164,225,246,184,205,124,6,173,221,115,208,250,132,142,156,
    205,160,53,205,144,170,227,119,214,232,152,153,237,139,58,56,
    63,2,41,194,147,117,1,158,238,209,204,60,175,237,123,130,
    82,166,227,111,74,80,34,177,140,178,42,91,56,25,44,147,
    6,101,16,45,99,49,127,21,45,99,125,54,184,62,255,140,
    235,51,215,120,238,176,116,34,54,57,23,235,73,133,76,209,
    53,97,41,171,187,105,13,199,126,18,191,29,52,227,110,83,
    177,174,148,55,55,239,166,235,119,211,79,48,35,54,159,112,
    46,210,57,81,103,189,68,246,41,107,209,163,95,188,237,72,
    174,120,252,203,113,116,146,114,56,97,57,89,37,69,60,45,
    146,33,141,220,194,156,174,83,149,80,150,30,171,141,235,133,
    141,73,228,175,232,144,58,27,216,20,203,136,157,186,96,73,
    28,157,149,185,143,226,93,252,126,70,70,39,109,37,80,183,
    109,183,181,156,172,2,41,99,255,116,8,31,99,82,192,222,
    64,142,191,207,113,81,61,195,5,125,205,28,226,127,1,238,
    44,5,252,25,200,243,232,224,12,226,69,68,144,171,231,137,
    252,15,192,177,112,65,109,231,124,210,166,122,206,20,152,102,
    210,199,76,170,75,253,87,240,215,82,32,229,5,217,204,122,
    199,114,65,182,138,92,196,144,249,81,69,215,26,78,90,228,
    148,61,55,37,50,157,137,206,98,243,44,205,23,109,31,102,
    226,113,225,103,82,179,119,72,146,111,207,208,67,37,109,69,
    204,27,37,76,252,156,134,135,5,28,68,190,54,6,161,214,
    224,242,186,235,232,12,255,13,157,108,177,172,51,19,108,206,
    236,249,2,227,149,28,227,15,11,140,75,174,67,239,248,234,
    64,163,65,206,61,53,4,222,29,177,237,162,171,154,5,178,
    2,219,85,138,6,110,142,69,22,44,34,207,82,148,211,134,
    138,28,27,98,75,155,168,240,175,118,29,13,111,199,26,253,
    228,189,205,192,13,119,60,247,201,1,29,65,231,116,242,240,
    49,114,161,103,203,66,19,244,197,101,114,243,207,71,185,240,
    135,99,141,252,95,34,199,66,104,198,185,23,119,56,220,95,
    238,201,102,40,195,29,188,17,238,249,253,102,55,112,119,217,
    19,102,166,212,215,185,82,138,93,57,218,38,164,15,104,140,
    155,157,56,194,20,124,208,81,113,210,244,36,94,149,164,215,
    252,168,201,249,187,233,167,77,119,7,119,221,142,210,80,30,
    142,66,238,63,221,100,55,229,86,115,255,136,166,99,247,164,
    131,119,95,31,155,237,35,40,202,164,190,152,21,233,88,223,
    22,57,50,176,162,225,37,72,13,116,30,162,150,193,94,167,
    225,39,240,62,178,246,199,218,248,144,146,121,170,98,197,168,
    25,92,238,51,146,23,68,159,158,15,197,55,63,38,20,245,
    11,28,36,144,85,232,77,240,56,73,217,154,222,207,88,217,
    251,25,90,156,130,237,70,254,94,104,154,34,182,250,191,70,
    44,35,127,236,152,255,211,255,53,80,237,199,239,85,102,251,
    87,144,213,228,203,130,116,168,169,123,170,113,162,45,143,149,
    123,176,192,250,233,91,1,235,39,94,69,55,176,187,179,184,
    187,219,164,238,238,152,59,64,199,208,13,222,153,195,184,89,
    231,183,14,100,134,72,30,57,67,104,211,237,27,97,192,237,
    247,101,228,217,15,160,220,145,241,246,88,237,68,49,248,61,
    148,74,168,41,22,176,5,59,143,72,202,45,37,189,24,121,
    149,2,131,171,239,195,159,127,203,253,217,186,50,148,96,236,
    77,26,102,135,178,137,182,249,141,209,232,118,250,129,171,186,
    113,18,82,119,255,223,182,177,134,235,55,73,217,2,27,74,
    45,144,17,100,32,149,28,118,163,162,195,179,251,156,39,49,
    67,199,3,108,182,185,137,197,223,129,227,140,63,185,125,138,
    28,79,32,187,38,96,114,195,187,215,162,81,171,214,4,215,
    135,145,119,147,90,18,26,117,171,54,72,109,142,147,153,194,
    114,172,123,158,173,201,190,124,145,216,114,67,253,30,132,239,
    250,246,29,200,110,105,246,253,194,248,116,111,229,254,88,223,
    60,16,241,92,187,184,84,217,191,200,157,18,62,90,207,85,
    89,215,170,188,200,12,205,175,241,194,71,234,230,133,84,95,
    70,42,121,134,183,154,36,14,248,54,122,158,162,61,72,149,
    12,213,202,200,166,140,14,66,231,185,12,227,100,240,60,246,
    164,90,29,217,127,234,121,137,237,70,187,210,57,148,84,123,
    213,237,81,130,172,240,106,30,57,85,243,66,25,134,105,207,
    201,162,137,112,83,191,255,226,206,241,252,254,179,32,238,236,
    75,47,163,185,216,28,76,243,121,28,186,184,126,241,41,109,
    63,63,101,110,100,223,75,232,169,197,145,213,84,38,190,27,
    248,223,201,75,248,189,240,227,207,229,161,223,209,175,221,242,
    77,69,192,25,37,32,255,23,191,116,241,93,56,11,56,14,
    150,68,238,250,232,174,132,159,47,104,179,212,248,233,197,17,
    92,126,110,236,97,165,155,85,125,95,126,66,111,99,210,151,
    56,208,155,179,218,76,77,84,13,202,151,38,94,88,167,133,
    101,54,102,107,86,99,170,102,213,38,76,126,249,49,141,87,
    145,186,85,155,106,136,203,255,173,97,128,214,141,181,233,154,
    248,15,85,135,204,176,
};

EmbeddedPython embedded_m5_internal_param_BaseGic(
    "m5/internal/param_BaseGic.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_BaseGic.py",
    "m5.internal.param_BaseGic",
    data_m5_internal_param_BaseGic,
    2294,
    6750);

} // anonymous namespace
