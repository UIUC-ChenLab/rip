#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_BasicPioDevice[] = {
    120,156,197,88,123,115,219,198,17,223,3,64,74,164,40,137,
    178,94,126,200,22,237,88,13,235,105,164,214,141,235,206,68,
    241,212,121,116,166,153,177,226,130,233,216,97,50,69,33,224,
    36,129,34,0,14,112,146,205,148,250,163,149,167,205,23,232,
    71,232,31,253,54,157,126,161,118,119,15,128,64,61,50,158,
    105,205,202,228,249,120,216,219,219,199,111,31,7,15,178,191,
    10,126,127,213,2,72,255,37,0,124,252,8,232,3,132,2,
    186,2,132,20,224,47,193,97,5,146,15,193,175,192,27,128,
    174,1,210,128,83,156,152,240,141,1,81,131,247,84,161,111,
    242,138,128,97,29,164,5,221,10,188,136,22,192,146,85,56,
    172,67,242,7,16,66,68,2,94,250,83,224,79,195,27,228,
    142,147,26,51,156,6,90,172,243,98,13,252,25,94,172,131,
    223,224,201,12,12,155,32,27,208,157,37,178,238,28,178,125,
    128,108,231,153,237,63,137,173,143,79,150,193,159,35,114,148,
    235,107,162,180,136,146,207,155,103,46,205,92,202,5,232,94,
    203,231,139,165,249,82,105,190,92,154,175,148,230,171,165,249,
    245,210,252,70,105,126,179,52,191,85,154,175,149,230,183,121,
    142,90,93,131,222,29,232,173,67,175,5,123,104,232,133,66,
    131,187,32,77,232,221,131,238,61,144,248,185,11,167,232,11,
    255,90,105,199,123,188,99,177,216,113,159,119,108,64,119,3,
    36,126,238,235,29,85,232,180,87,208,191,193,191,241,175,141,
    254,5,213,192,225,88,38,105,16,71,78,16,237,197,129,65,
    207,171,52,16,26,60,26,166,50,88,124,74,176,248,7,48,
    38,124,35,131,197,9,32,99,65,186,244,13,56,225,201,137,
    1,195,54,140,4,244,44,240,77,24,225,49,21,18,96,95,
    192,169,1,223,154,68,112,130,163,133,206,187,3,150,210,152,
    232,177,243,52,167,41,56,169,192,168,2,157,151,35,131,22,
    14,107,144,252,29,190,91,99,166,211,204,212,128,17,142,22,
    156,90,112,82,133,23,72,132,75,189,26,169,47,94,142,80,
    83,92,233,180,45,148,118,167,164,46,169,226,7,73,228,134,
    82,45,227,220,25,184,137,27,58,159,184,105,224,61,15,226,
    207,228,113,224,201,118,61,39,141,211,205,129,171,14,108,222,
    107,146,81,194,129,98,158,113,36,213,12,78,246,130,200,119,
    194,216,63,234,75,53,77,12,157,189,160,47,29,135,31,254,
    38,28,196,137,250,60,73,226,196,38,187,242,98,63,118,139,
    29,100,85,175,31,167,178,77,167,241,49,54,177,87,68,189,
    55,96,142,36,0,203,75,155,125,153,122,73,48,80,232,46,
    205,145,168,137,91,155,28,197,67,250,21,14,91,7,113,40,
    183,14,101,24,202,68,62,220,218,151,225,35,30,62,72,149,
    187,219,151,91,187,71,65,223,223,122,106,63,219,26,12,213,
    65,28,109,225,243,32,82,18,45,211,223,186,204,38,155,72,
    119,141,184,191,10,246,157,128,245,114,14,100,127,32,147,89,
    90,189,73,39,139,166,104,136,170,48,69,91,204,226,172,130,
    95,83,172,25,51,98,39,32,205,60,210,150,144,101,149,177,
    68,14,22,112,104,64,178,70,72,233,225,71,144,107,17,47,
    29,122,102,240,179,223,146,73,244,106,207,36,255,235,197,17,
    163,11,97,134,148,219,228,240,8,24,34,21,232,85,65,67,
    7,17,167,177,148,12,105,68,114,98,99,32,115,11,210,191,
    1,154,24,65,51,130,12,80,167,38,136,168,9,170,78,57,
    3,87,87,240,192,63,51,38,59,109,18,127,135,97,161,14,
    130,52,126,21,177,241,105,206,81,212,65,203,60,31,126,185,
    219,147,158,74,215,113,225,235,248,168,229,185,81,20,171,150,
    235,251,45,87,169,36,216,61,82,50,109,169,184,181,145,182,
    201,159,246,66,142,172,130,223,112,144,35,137,188,142,72,210,
    63,252,192,83,248,99,145,127,176,23,82,169,16,21,7,177,
    159,226,58,177,216,151,202,38,33,21,25,57,102,65,24,52,
    14,145,210,241,72,55,135,191,159,230,146,48,50,219,213,28,
    71,169,236,239,169,58,67,210,77,83,135,37,161,117,70,31,
    49,62,118,251,71,146,185,35,140,20,10,68,83,45,195,36,
    240,119,157,116,201,85,103,125,162,56,242,135,40,94,224,189,
    79,39,95,103,20,54,24,135,203,136,193,41,28,171,248,127,
    85,172,24,158,149,33,175,154,163,143,50,161,2,246,189,200,
    220,143,72,60,197,172,211,54,56,109,176,74,28,147,247,104,
    70,155,237,53,26,110,211,112,135,134,245,92,235,119,172,250,
    236,121,213,31,211,113,6,235,203,154,145,123,204,92,51,127,
    44,174,110,156,197,21,38,199,14,197,135,65,81,116,22,31,
    22,37,210,228,9,141,72,202,145,103,146,50,74,199,17,51,
    163,144,65,240,211,236,44,36,216,78,118,147,244,159,206,209,
    108,19,68,203,56,221,47,225,212,38,23,49,72,237,27,121,
    66,116,136,66,195,211,190,69,172,42,151,24,186,69,195,221,
    9,89,251,12,104,251,23,128,246,17,157,220,204,128,54,203,
    0,171,227,183,105,120,102,230,130,162,84,46,158,3,24,161,
    203,186,4,93,63,162,153,121,81,233,201,2,43,83,245,215,
    37,96,145,116,70,89,163,29,156,12,87,73,145,50,164,86,
    177,236,191,136,86,177,146,27,92,201,127,202,149,156,187,1,
    238,185,116,146,54,57,79,235,73,133,44,178,103,194,74,86,
    161,211,26,142,131,36,126,61,108,197,123,45,197,42,83,78,
    221,222,72,55,55,210,143,48,91,182,158,112,158,210,249,82,
    103,196,68,14,40,163,209,214,207,95,123,146,139,34,255,114,
    28,157,192,28,78,102,78,86,108,17,93,84,241,217,250,108,
    104,78,229,169,74,40,131,79,194,212,245,194,212,36,249,23,
    116,86,157,237,108,138,85,68,82,93,176,64,142,78,220,220,
    120,241,83,252,126,66,182,39,165,37,80,27,110,119,180,184,
    172,9,233,100,255,100,12,45,239,86,15,123,11,25,255,46,
    71,73,245,12,37,244,53,115,220,255,21,184,35,21,240,23,
    32,28,160,187,51,220,23,97,66,142,95,36,242,223,3,7,
    200,37,93,0,231,154,14,85,126,166,192,20,148,62,102,82,
    221,20,124,1,223,151,162,43,47,221,102,214,115,150,75,183,
    85,228,41,6,208,91,149,103,107,60,161,145,111,14,220,148,
    200,116,150,58,11,216,179,74,80,244,137,152,165,223,49,154,
    166,245,41,14,9,244,237,25,150,168,248,221,18,139,70,9,
    33,63,163,225,97,1,14,145,175,189,59,217,214,225,234,66,
    237,232,90,240,13,9,96,177,200,243,83,220,149,140,179,41,
    240,95,201,241,255,176,192,191,228,194,245,134,239,33,52,26,
    228,241,83,67,224,133,19,187,54,186,223,89,32,43,208,173,
    82,164,112,139,45,178,64,18,121,34,163,180,55,86,21,217,
    44,59,218,96,133,211,181,63,105,120,61,137,4,65,46,221,
    238,187,225,174,239,62,73,233,36,58,206,203,67,203,200,101,
    111,150,101,167,176,16,87,137,207,63,31,229,58,28,79,34,
    57,252,34,147,155,101,231,80,240,99,143,51,194,87,7,178,
    21,202,112,23,47,155,7,193,160,181,215,119,247,217,47,102,
    166,219,151,185,110,138,29,123,190,203,72,31,208,24,183,188,
    56,194,156,125,228,169,56,105,249,18,175,95,210,111,125,208,
    226,132,223,10,210,150,187,139,79,93,79,105,152,143,7,42,
    55,179,110,178,159,114,223,122,248,138,166,147,242,171,131,183,
    235,0,27,248,35,40,202,171,190,243,21,249,155,131,64,71,
    13,86,66,188,88,169,161,206,88,212,113,216,155,52,252,24,
    38,152,230,63,68,198,9,157,64,198,170,138,91,70,205,80,
    75,23,226,244,57,237,78,47,70,107,244,54,209,170,95,12,
    33,129,172,66,111,138,199,105,202,242,221,90,190,88,231,113,
    134,23,27,121,116,207,242,226,28,116,231,243,151,80,77,138,
    244,234,127,27,233,28,42,147,10,146,209,255,52,192,237,199,
    255,15,209,237,95,66,86,238,175,10,238,177,238,241,169,14,
    110,237,7,108,10,134,75,172,166,190,140,176,154,226,69,116,
    19,219,72,139,219,200,109,106,35,71,220,106,58,134,238,36,
    207,220,199,119,4,126,3,66,205,122,36,95,57,151,225,82,
    183,139,4,12,119,48,144,145,111,63,128,114,7,200,143,39,
    97,53,10,225,63,65,169,72,155,98,9,91,190,139,104,165,
    12,85,210,146,81,89,41,240,185,54,65,39,127,159,59,185,
    189,48,150,166,236,109,26,154,99,57,73,59,226,238,21,201,
    193,25,4,177,131,45,86,66,87,140,183,160,194,158,65,191,
    248,202,22,212,253,31,218,210,119,149,140,188,33,243,126,43,
    66,98,63,147,177,207,214,216,63,138,138,133,47,251,82,201,
    75,177,164,72,231,236,74,235,75,172,50,241,16,111,24,220,
    178,227,239,190,227,76,44,51,127,140,140,255,72,39,204,233,
    204,140,215,207,101,177,108,212,170,53,193,197,238,220,59,92,
    45,18,93,50,117,107,58,76,109,14,222,249,194,115,108,237,
    188,230,144,127,249,26,181,227,134,250,13,17,191,254,176,223,
    131,236,170,106,191,95,56,159,238,240,124,31,208,247,46,12,
    67,46,196,92,119,237,159,231,70,13,31,109,230,58,109,106,
    157,10,117,248,69,103,248,136,131,248,34,89,103,152,42,25,
    94,224,33,163,163,208,121,38,195,56,25,62,139,125,169,214,
    206,61,127,138,160,177,221,104,95,58,199,146,250,4,198,220,
    24,65,214,36,104,30,57,85,235,82,25,198,105,175,208,7,
    31,234,23,127,220,250,94,124,254,105,63,246,14,165,159,209,
    220,190,154,230,179,56,116,113,253,242,83,58,65,126,202,194,
    185,231,126,66,187,150,207,173,166,50,9,220,126,240,157,126,
    159,152,47,43,242,251,121,55,144,251,138,95,92,250,89,134,
    113,236,49,246,19,185,31,160,87,18,102,115,62,221,126,252,
    131,121,160,188,125,82,193,162,155,106,253,6,224,9,133,125,
    250,28,7,122,65,88,155,175,137,170,65,169,216,196,187,247,
    172,176,204,70,179,102,53,102,106,86,109,202,228,183,58,179,
    120,143,170,91,181,153,134,184,252,223,58,6,92,221,88,159,
    171,137,255,0,180,83,39,71,
};

EmbeddedPython embedded_m5_internal_param_BasicPioDevice(
    "m5/internal/param_BasicPioDevice.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_BasicPioDevice.py",
    "m5.internal.param_BasicPioDevice",
    data_m5_internal_param_BasicPioDevice,
    2296,
    6974);

} // anonymous namespace
