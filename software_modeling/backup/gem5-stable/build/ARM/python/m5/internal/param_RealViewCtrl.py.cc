#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_RealViewCtrl[] = {
    120,156,189,88,239,114,219,198,17,223,3,64,74,164,36,235,
    191,100,91,178,69,219,149,195,122,26,41,118,227,186,51,81,
    221,58,78,58,147,204,88,113,193,180,118,152,76,81,8,56,
    73,160,64,128,3,156,36,51,35,205,116,42,79,218,15,237,
    199,62,66,63,244,109,250,4,125,149,118,119,15,0,33,137,
    74,60,211,74,50,121,62,222,237,237,237,159,223,238,237,157,
    7,217,95,5,191,191,106,0,164,255,22,0,62,126,4,132,
    0,93,1,109,1,66,10,240,231,96,175,2,201,135,224,87,
    224,45,64,219,0,105,192,9,118,76,248,218,128,104,156,215,
    84,33,52,121,68,64,191,14,210,130,118,5,94,69,211,96,
    201,42,236,213,33,249,3,8,33,34,1,175,253,17,240,71,
    225,45,114,199,78,141,25,142,2,13,214,121,176,6,254,24,
    15,214,193,31,231,206,24,244,167,64,142,67,123,130,200,218,
    215,144,237,3,100,59,201,108,255,69,108,125,156,153,7,255,
    26,145,163,92,95,17,165,69,148,188,223,36,115,153,202,165,
    156,134,246,76,222,159,45,245,231,74,253,249,82,127,161,212,
    95,44,245,175,151,250,55,74,253,155,165,254,82,169,191,92,
    234,223,42,245,111,115,31,53,156,129,206,10,116,26,208,185,
    3,219,104,244,233,66,155,187,32,77,232,220,131,246,61,144,
    248,185,11,39,232,23,127,166,180,226,71,188,98,182,88,177,
    202,43,238,67,251,62,72,252,172,234,21,85,104,53,23,208,
    215,193,127,240,175,137,190,6,53,142,205,129,76,210,32,142,
    156,32,218,142,3,131,230,171,212,16,50,60,106,70,50,136,
    60,39,136,252,19,24,31,190,145,65,228,24,144,177,32,93,
    66,3,142,185,115,108,64,191,9,71,2,58,22,248,38,28,
    225,54,21,18,96,71,192,137,1,223,152,68,112,140,173,133,
    142,188,13,150,210,248,232,176,35,53,167,17,56,174,192,81,
    5,90,175,143,12,26,216,171,65,242,15,248,118,153,153,142,
    50,83,3,142,176,181,224,196,130,227,42,188,66,34,28,234,
    212,72,125,241,250,8,53,197,145,86,211,66,105,55,75,234,
    146,42,126,144,68,110,87,170,89,236,59,61,55,113,187,142,
    45,221,240,119,129,60,124,174,146,176,89,207,9,227,116,173,
    231,170,93,155,87,154,100,146,110,79,49,199,56,146,106,12,
    59,219,65,228,59,221,216,223,15,165,26,37,118,206,118,16,
    74,199,225,201,207,186,189,56,81,159,38,73,156,216,100,85,
    30,12,99,183,88,65,54,245,194,56,149,77,218,141,183,177,
    137,189,34,234,237,30,115,36,1,88,90,90,236,203,212,75,
    130,158,66,103,105,142,68,77,220,154,228,38,110,82,27,155,
    245,221,184,43,215,247,100,183,43,19,249,104,125,71,118,31,
    115,243,126,170,220,173,80,174,111,237,7,161,191,254,204,126,
    177,222,235,171,221,56,90,199,249,32,82,18,237,18,174,159,
    183,200,26,82,205,16,239,195,96,199,9,88,43,103,87,134,
    61,153,76,208,232,77,218,87,76,137,113,81,21,166,104,138,
    9,236,85,240,107,138,101,99,76,108,6,164,151,71,186,18,
    170,172,50,142,200,185,2,246,12,72,150,9,37,29,252,8,
    114,43,98,165,69,115,6,207,253,134,12,162,71,59,38,249,
    94,15,30,49,178,16,98,72,185,65,206,142,128,225,81,129,
    78,21,52,108,16,109,26,71,73,159,90,36,39,54,6,50,
    183,32,253,59,160,129,17,48,71,144,129,233,196,4,17,77,
    129,170,83,238,192,209,5,220,240,79,140,199,86,147,196,223,
    100,80,168,221,32,141,15,35,54,61,245,57,130,90,104,153,
    151,253,47,182,58,210,83,233,10,14,124,21,239,55,60,55,
    138,98,213,112,125,191,225,42,149,4,91,251,74,166,13,21,
    55,86,211,38,121,211,158,206,113,85,240,235,247,114,28,145,
    207,17,71,250,135,31,120,10,127,48,96,29,246,66,42,21,
    98,98,55,246,83,28,39,22,59,82,217,36,164,34,35,199,
    44,8,67,198,33,82,218,30,233,174,225,239,103,185,36,140,
    203,102,53,71,81,42,195,109,85,103,64,186,105,234,176,36,
    52,206,216,35,198,7,110,184,47,153,59,130,72,161,64,212,
    213,50,92,62,250,174,147,38,185,226,172,77,20,71,126,31,
    133,11,188,247,104,223,235,140,193,113,70,225,60,34,112,4,
    219,42,254,95,21,11,134,103,101,184,171,230,216,163,28,168,
    128,61,47,50,231,35,14,79,48,223,52,13,78,24,172,16,
    199,227,93,234,209,98,123,153,154,91,212,220,166,102,37,215,
    249,82,21,159,56,171,248,19,218,204,96,109,89,47,114,141,
    153,235,229,159,138,169,27,131,152,194,164,216,162,216,48,40,
    130,6,177,97,81,2,77,158,82,139,164,28,117,38,164,95,
    82,186,166,24,98,102,20,46,8,124,234,13,194,129,173,100,
    79,145,246,163,57,146,109,130,103,25,163,59,37,140,218,228,
    32,6,168,125,35,79,133,14,81,104,104,218,75,196,170,50,
    196,204,13,106,238,92,137,173,7,32,219,57,7,178,143,104,
    223,169,12,100,19,12,174,58,126,167,12,207,204,28,80,28,
    144,179,103,192,69,200,178,134,32,235,62,245,204,243,42,95,
    37,168,50,69,127,93,2,21,201,102,148,245,217,196,78,127,
    145,212,40,195,105,17,143,250,87,209,34,158,222,6,159,222,
    31,240,233,205,21,0,215,92,58,57,155,156,159,117,167,66,
    246,216,54,97,33,59,149,211,26,182,189,36,126,211,111,196,
    219,13,197,10,83,46,221,88,77,215,86,211,143,48,75,54,
    158,114,126,210,121,82,103,194,68,246,40,147,209,210,79,223,
    120,146,143,66,254,229,56,58,113,57,156,196,156,236,136,69,
    100,205,147,53,141,220,204,156,194,83,149,80,230,190,124,67,
    215,11,67,147,220,159,211,78,117,182,178,41,22,17,69,117,
    193,226,56,58,93,115,169,197,179,248,253,152,44,79,42,75,
    160,34,220,110,105,97,89,15,210,200,254,201,41,164,92,166,
    22,246,58,178,253,109,142,144,234,0,33,244,53,115,196,255,
    25,184,2,21,240,29,16,6,208,213,25,226,139,0,33,167,
    207,18,249,239,129,67,99,200,201,207,57,166,69,167,61,83,
    96,234,73,159,48,169,46,4,62,135,191,148,226,42,63,174,
    205,172,198,44,31,215,86,145,159,24,60,239,116,36,91,167,
    19,25,121,102,215,77,137,76,103,167,65,168,14,242,127,81,
    25,98,118,190,84,36,141,234,61,28,18,231,155,1,142,232,
    192,91,18,179,70,9,29,15,169,121,84,0,67,228,99,151,
    37,217,10,92,124,52,59,58,255,127,77,219,91,44,240,228,
    8,215,75,101,38,5,238,43,57,238,31,21,184,151,124,84,
    189,229,27,7,181,6,249,250,196,16,120,205,196,26,141,110,
    117,22,200,10,180,171,20,33,92,78,139,44,128,68,158,190,
    40,217,157,58,7,217,36,155,218,88,133,187,181,39,169,121,
    115,249,105,129,156,185,17,186,221,45,223,125,74,121,47,165,
    205,188,60,164,140,92,242,169,178,228,20,14,226,34,225,249,
    231,227,92,131,131,203,79,9,63,3,62,227,180,228,28,0,
    126,236,113,30,248,114,87,54,186,178,187,133,87,202,221,160,
    215,216,14,221,29,246,137,153,105,246,69,174,153,98,167,158,
    173,41,210,7,212,198,13,47,142,48,75,239,123,42,78,26,
    190,196,107,150,244,27,239,55,56,197,55,130,180,225,110,225,
    172,235,41,13,239,211,225,201,101,171,155,236,164,92,161,238,
    29,82,247,106,124,234,224,13,58,192,66,253,0,138,227,84,
    223,236,138,140,205,37,184,142,22,60,249,240,2,165,250,58,
    75,81,125,97,175,81,243,99,184,178,196,254,97,230,193,148,
    12,85,21,75,70,205,224,123,94,153,238,37,173,76,207,199,
    232,95,223,37,70,245,35,80,22,169,85,162,148,35,116,127,
    167,182,70,233,189,93,207,7,199,184,29,231,193,137,124,240,
    26,183,147,60,56,149,63,62,77,243,224,12,180,103,233,245,
    132,70,230,40,250,71,254,215,232,231,0,186,154,208,57,254,
    191,6,189,253,228,234,5,183,127,14,217,193,127,81,192,139,
    178,86,19,58,224,59,34,191,103,148,85,226,151,140,27,67,
    113,231,120,137,116,149,212,254,89,190,10,53,57,105,232,93,
    255,56,8,227,243,85,241,179,66,163,19,46,120,250,115,236,
    54,125,193,98,183,137,87,209,77,44,143,45,46,143,55,168,
    60,62,98,245,29,67,87,200,3,48,86,10,43,208,197,52,
    146,135,206,121,75,232,34,152,132,115,123,61,25,249,246,3,
    40,215,181,60,125,249,24,160,52,245,29,148,202,15,83,204,
    97,33,123,62,238,40,7,151,52,100,255,85,138,72,187,18,
    79,50,96,255,150,3,182,201,57,184,72,196,246,6,53,156,
    122,139,172,107,255,178,240,195,242,112,52,6,126,34,249,210,
    244,253,4,88,8,241,147,9,255,226,2,105,8,41,230,127,
    15,233,63,96,118,63,68,67,28,249,53,48,27,248,129,5,
    15,223,129,233,195,179,76,31,178,119,57,16,125,25,74,37,
    135,160,80,145,197,178,235,189,47,241,12,142,251,120,227,226,
    75,12,254,14,29,231,138,78,174,95,232,44,9,41,29,87,
    120,114,137,42,158,93,243,120,45,159,55,106,213,154,224,98,
    224,204,75,182,22,138,30,139,116,193,222,103,217,192,158,44,
    156,158,217,66,159,202,132,15,190,88,110,186,93,253,86,198,
    79,65,246,61,200,174,238,246,123,5,120,56,119,173,231,11,
    28,12,96,46,84,184,46,177,127,74,227,24,18,208,125,188,
    150,107,181,166,181,250,216,77,3,239,101,16,127,34,15,2,
    79,242,171,111,247,177,90,26,74,59,32,187,62,116,190,213,
    79,149,236,158,91,44,163,253,174,243,66,118,227,164,255,34,
    246,37,227,182,60,255,204,247,19,219,141,118,164,115,32,169,
    216,82,119,206,18,100,149,150,230,145,83,13,215,231,52,237,
    5,138,224,164,126,39,101,124,158,159,127,30,198,222,158,244,
    51,154,91,23,211,124,18,119,93,28,31,190,75,43,200,119,
    153,62,51,239,39,180,106,254,204,104,42,147,192,13,131,111,
    245,243,107,62,172,230,8,18,195,124,69,117,220,233,33,174,
    166,206,29,99,28,42,152,5,2,244,78,194,236,78,175,202,
    146,59,225,249,162,120,45,115,184,154,240,210,23,20,253,130,
    242,116,44,223,135,158,86,107,147,53,12,53,74,251,166,168,
    99,226,183,204,241,169,154,53,62,86,179,106,35,38,191,137,
    77,224,109,180,110,213,198,198,197,69,255,86,48,64,235,198,
    202,76,77,252,23,255,30,116,141,
};

EmbeddedPython embedded_m5_internal_param_RealViewCtrl(
    "m5/internal/param_RealViewCtrl.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_RealViewCtrl.py",
    "m5.internal.param_RealViewCtrl",
    data_m5_internal_param_RealViewCtrl,
    2377,
    7296);

} // anonymous namespace
