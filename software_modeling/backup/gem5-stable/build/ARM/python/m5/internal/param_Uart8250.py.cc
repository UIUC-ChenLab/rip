#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_Uart8250[] = {
    120,156,189,88,109,83,28,199,17,238,217,221,59,184,3,4,
    8,1,146,64,226,100,71,210,137,196,224,40,86,228,42,19,
    37,178,236,84,217,85,194,202,158,92,146,177,43,155,101,119,
    128,61,246,229,106,119,16,58,21,84,37,65,21,231,83,190,
    229,39,228,67,254,77,254,81,210,221,179,187,183,28,80,113,
    149,125,66,119,163,190,121,233,233,151,167,123,122,198,131,252,
    175,134,223,223,181,0,178,75,6,128,143,31,1,33,64,36,
    96,75,128,144,2,252,43,176,95,131,244,35,240,107,240,22,
    96,203,0,105,192,9,18,38,124,107,64,60,201,107,234,16,
    154,220,35,160,223,4,105,193,86,13,94,196,179,96,201,58,
    236,55,33,253,19,8,33,98,1,47,253,49,240,199,225,45,
    114,71,162,193,12,199,129,58,155,220,217,0,127,130,59,155,
    224,79,50,49,1,253,25,144,147,176,53,69,211,182,46,33,
    219,85,100,59,205,108,255,67,108,125,28,153,7,255,18,77,
    71,185,190,161,153,22,205,228,253,166,153,203,76,33,229,44,
    108,93,46,232,185,10,125,165,66,207,87,232,133,10,189,88,
    161,175,86,232,107,21,250,122,133,94,170,208,203,21,250,70,
    133,190,89,161,87,42,116,171,66,223,170,208,239,49,141,22,
    185,12,221,247,161,251,51,232,222,134,29,116,210,108,169,253,
    29,144,38,116,239,194,214,93,144,248,185,3,39,232,71,255,
    114,101,69,155,87,204,149,43,238,241,138,85,216,90,5,137,
    159,123,122,69,29,58,237,5,196,70,240,95,252,107,11,164,
    212,36,54,175,100,154,5,73,236,4,241,78,18,24,52,94,
    167,134,144,228,81,51,150,67,234,9,65,234,223,192,120,242,
    141,28,82,199,128,140,5,233,18,26,112,204,196,177,1,253,
    54,28,9,232,90,224,155,112,132,219,212,72,128,93,1,39,
    6,124,103,210,132,99,108,45,116,252,77,176,148,198,83,151,
    29,175,57,141,193,113,13,142,106,208,121,121,100,80,199,126,
    3,210,127,193,155,101,102,58,206,76,13,56,194,214,130,19,
    11,142,235,240,2,39,97,87,183,65,234,139,151,71,168,41,
    246,116,218,22,74,187,89,81,151,84,241,131,52,118,35,169,
    166,145,118,122,110,234,70,206,215,110,170,62,190,255,224,195,
    118,179,152,148,100,107,61,87,237,217,188,202,36,115,68,61,
    197,220,146,88,170,9,36,118,130,216,119,162,196,63,8,165,
    26,39,86,206,78,16,74,199,225,193,47,162,94,146,170,207,
    211,52,73,109,178,40,119,134,137,91,174,32,123,122,97,146,
    201,54,237,198,219,216,196,94,209,236,157,30,115,36,1,88,
    82,90,236,203,204,75,131,158,66,71,105,142,52,155,184,181,
    201,69,220,100,155,216,172,239,37,145,92,223,151,81,36,83,
    121,127,125,87,70,15,184,249,32,83,238,118,40,215,183,15,
    130,208,95,127,108,63,93,239,245,213,94,18,175,227,120,16,
    43,137,54,9,215,79,91,99,13,103,92,38,190,135,193,174,
    19,176,70,206,158,12,123,50,157,162,222,235,180,167,152,17,
    147,162,46,76,209,22,83,72,213,240,107,138,101,99,66,108,
    6,164,147,71,122,18,154,172,42,126,200,169,2,246,13,72,
    151,9,29,93,252,8,114,39,98,164,67,99,6,143,253,129,
    140,161,123,187,38,249,92,119,30,49,162,16,90,56,115,131,
    156,28,3,195,162,6,221,58,104,184,32,202,52,126,210,62,
    181,56,157,216,24,200,220,130,236,159,128,198,69,160,28,65,
    14,162,19,19,68,60,3,170,73,57,6,123,23,112,195,191,
    50,14,59,109,18,127,147,1,161,246,130,44,57,140,217,236,
    68,115,228,116,208,50,207,250,95,109,119,165,167,178,21,236,
    248,38,57,104,121,110,28,39,170,229,250,126,203,85,42,13,
    182,15,148,204,90,42,105,221,206,218,228,73,123,182,192,84,
    201,175,223,43,48,68,254,70,12,233,31,126,224,41,252,49,
    199,63,216,11,153,84,136,135,189,196,207,176,159,88,236,74,
    101,147,144,138,140,156,176,32,12,23,135,166,210,246,56,239,
    18,254,126,92,72,194,152,108,215,11,4,101,50,220,81,77,
    6,163,155,101,14,75,66,253,140,59,98,252,202,13,15,36,
    115,71,0,41,20,136,72,45,195,104,145,119,149,180,40,148,
    102,77,226,36,246,251,40,88,224,221,165,61,175,50,254,38,
    25,129,243,136,190,49,108,235,248,127,93,44,24,158,149,99,
    174,94,224,142,242,158,2,246,186,200,29,143,24,60,193,28,
    211,54,56,73,176,50,28,135,239,17,69,139,237,101,106,110,
    80,115,147,154,149,66,223,145,41,61,53,172,244,67,218,200,
    96,77,89,39,114,137,89,232,228,159,138,165,107,131,88,194,
    36,216,161,152,48,40,114,6,49,97,81,194,76,31,81,139,
    83,57,218,76,200,158,83,122,166,216,97,102,20,38,8,120,
    162,6,97,192,22,178,103,72,243,241,2,193,54,193,178,138,
    205,221,10,54,109,114,14,3,211,190,86,164,63,135,102,104,
    72,218,75,196,170,118,142,137,91,212,220,26,185,157,7,224,
    218,61,3,174,79,104,207,153,28,92,83,12,170,38,126,103,
    12,207,204,141,95,30,134,115,67,160,34,68,89,231,32,234,
    14,81,230,89,117,223,21,152,114,37,127,95,1,19,201,101,
    84,117,33,1,250,139,164,66,21,70,139,120,164,191,136,23,
    241,148,54,248,148,254,144,79,105,62,233,185,22,211,201,216,
    228,124,172,137,26,217,98,199,132,133,252,244,205,26,216,246,
    210,228,117,191,149,236,180,20,43,75,185,115,227,118,182,118,
    59,251,4,179,98,235,17,231,35,157,23,117,230,75,101,143,
    50,23,45,253,252,181,39,249,216,227,95,142,163,19,149,195,
    73,203,201,143,83,68,212,60,89,210,40,76,204,41,59,83,
    41,101,234,209,26,185,89,26,153,100,254,146,118,105,178,133,
    77,177,136,232,105,10,22,197,209,169,153,203,41,30,197,239,
    167,100,117,82,87,2,21,230,118,71,11,202,58,144,54,246,
    47,78,33,100,84,26,216,235,200,242,235,2,25,245,1,50,
    232,107,22,40,255,30,184,194,20,240,55,32,223,163,139,115,
    148,151,65,65,206,158,163,233,127,4,14,135,115,78,120,206,
    41,29,58,213,121,6,166,154,236,33,79,213,7,254,151,240,
    247,74,44,21,199,178,153,215,144,213,99,217,42,243,17,131,
    230,7,29,189,214,233,196,69,94,217,115,51,154,166,179,209,
    32,60,7,185,190,172,254,48,27,143,12,65,227,154,191,67,
    162,124,55,192,15,29,108,75,98,206,168,160,226,151,212,220,
    47,1,33,138,190,81,72,181,2,23,31,191,142,206,243,223,
    210,214,22,11,59,61,198,106,20,12,74,156,215,10,156,223,
    47,113,46,249,56,122,203,183,8,106,13,242,239,137,33,240,
    170,137,245,23,221,236,44,144,53,216,170,83,68,112,153,44,
    242,128,17,69,170,162,196,118,234,172,99,83,108,106,35,149,
    46,214,222,163,230,245,104,83,0,105,190,17,186,209,182,239,
    62,122,77,123,208,70,94,17,66,70,33,245,76,85,106,130,
    191,184,72,112,254,249,160,144,254,213,104,195,255,215,100,160,
    66,106,6,187,159,120,28,243,207,247,100,43,146,209,54,94,
    15,247,130,94,107,39,116,119,217,23,102,174,213,87,133,86,
    138,157,57,92,47,100,171,212,38,45,47,137,49,19,31,120,
    42,73,91,190,196,107,147,244,91,31,180,56,141,183,130,172,
    229,110,227,168,235,41,13,231,211,161,200,165,168,155,238,102,
    92,117,238,31,18,57,122,95,58,120,19,14,176,240,126,3,
    229,113,169,111,105,101,86,230,146,90,71,7,158,108,120,33,
    82,125,157,141,168,118,176,215,168,185,7,239,36,121,127,132,
    44,15,137,55,25,168,46,150,140,134,193,194,21,115,158,209,
    138,236,108,60,62,253,33,241,168,31,125,242,168,172,23,175,
    69,99,32,249,2,69,15,58,245,252,65,7,67,117,236,199,
    134,42,35,126,244,88,255,203,79,26,161,246,195,119,43,180,
    253,49,228,39,242,69,209,41,170,26,77,233,232,236,138,162,
    224,175,170,195,207,8,243,103,192,226,120,169,116,149,212,62,
    89,30,181,122,28,217,122,199,183,131,120,59,91,158,62,46,
    53,57,225,10,164,127,133,93,165,111,56,236,42,241,34,190,
    142,117,170,197,117,234,6,213,169,71,172,182,99,232,82,117,
    0,190,90,169,61,61,111,196,242,208,57,109,1,93,137,146,
    96,110,175,39,99,223,94,133,106,113,201,195,163,245,57,229,
    145,239,161,82,11,152,226,10,86,147,103,227,139,18,100,69,
    51,246,89,173,140,168,145,123,143,193,249,143,2,156,109,170,
    235,7,89,210,222,160,134,243,98,153,18,237,223,66,145,38,
    75,248,249,50,148,74,14,249,64,209,186,252,102,233,75,60,
    34,146,62,22,253,92,75,227,239,208,113,222,65,114,253,13,
    178,252,51,228,247,21,76,174,162,110,52,204,70,189,33,248,
    132,26,122,42,213,162,252,28,138,138,177,159,217,28,176,211,
    165,174,252,166,87,28,23,100,27,190,209,108,186,145,126,148,
    225,119,7,251,125,200,239,139,246,221,210,112,116,133,230,50,
    93,95,129,16,176,124,122,242,97,105,255,138,250,233,117,35,
    122,176,86,232,178,54,208,133,31,20,163,7,234,250,185,51,
    158,133,174,218,73,210,72,221,56,119,248,139,88,165,79,240,
    230,149,38,33,95,153,207,206,232,244,51,37,35,181,52,52,
    40,227,131,200,121,42,163,36,237,63,77,124,169,150,135,198,
    31,251,126,106,187,241,174,116,94,73,42,12,212,173,225,9,
    121,85,160,121,20,179,90,231,202,112,122,238,25,89,244,36,
    28,212,239,116,92,217,158,29,127,18,38,222,190,244,243,57,
    231,155,131,231,124,150,68,46,246,159,191,75,39,40,118,153,
    29,26,247,83,90,53,63,212,155,201,52,112,195,224,141,188,
    192,63,207,101,26,5,248,243,2,205,63,117,179,192,123,22,
    36,159,201,87,129,39,47,144,105,48,78,0,44,6,249,226,
    90,129,137,149,159,3,92,81,156,58,21,56,6,83,185,27,
    160,167,83,94,70,35,121,166,164,16,225,125,135,206,144,234,
    154,209,71,170,46,193,245,91,192,35,122,107,202,182,176,161,
    135,193,198,116,3,163,150,242,167,137,119,241,41,97,153,147,
    51,13,107,114,162,97,53,198,76,126,217,153,194,59,86,211,
    106,76,76,138,255,247,111,5,35,191,105,172,32,199,255,1,
    130,30,251,163,
};

EmbeddedPython embedded_m5_internal_param_Uart8250(
    "m5/internal/param_Uart8250.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_Uart8250.py",
    "m5.internal.param_Uart8250",
    data_m5_internal_param_Uart8250,
    2340,
    7018);

} // anonymous namespace
