#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_GarnetNetworkInterface[] = {
    120,156,197,88,221,115,219,198,17,223,3,64,74,164,40,139,
    250,182,45,217,98,219,113,195,120,106,169,117,227,56,51,81,
    221,38,105,218,73,30,148,20,76,199,14,227,41,10,1,71,
    9,20,8,112,128,147,100,102,164,60,84,238,199,67,95,251,
    39,244,161,255,77,255,163,116,119,15,0,161,175,216,153,182,
    180,72,158,14,139,187,189,253,248,237,222,222,121,144,253,85,
    240,247,171,22,64,250,141,0,240,241,43,32,4,24,8,232,
    10,16,82,128,191,4,7,21,72,222,1,191,2,47,1,186,
    6,72,3,206,176,99,194,87,6,68,13,158,83,133,208,100,
    138,128,81,29,164,5,221,10,60,141,230,193,146,85,56,168,
    67,242,71,16,66,68,2,158,249,83,224,79,195,75,228,142,
    157,26,51,156,6,34,214,153,88,3,127,134,137,117,240,27,
    220,153,129,81,19,100,3,186,179,52,172,123,3,217,222,71,
    182,115,204,246,223,196,214,199,55,203,224,223,160,225,40,215,
    151,52,210,162,145,188,222,28,115,105,230,82,206,67,119,33,
    239,47,150,250,75,165,254,114,169,191,194,125,148,96,1,250,
    171,208,191,9,253,91,208,67,163,204,23,171,221,6,105,66,
    127,13,186,107,32,241,123,27,206,208,110,254,66,105,198,58,
    207,88,44,102,220,225,25,119,161,123,23,36,126,239,232,25,
    85,232,180,87,208,23,193,183,248,215,70,95,128,106,96,115,
    36,147,52,136,35,39,136,122,113,96,208,251,42,53,228,57,
    143,154,169,204,133,31,145,11,255,5,236,63,223,200,92,120,
    10,200,88,144,46,161,1,167,220,57,53,96,212,134,19,1,
    125,11,124,19,78,112,153,10,9,176,39,224,204,128,231,38,
    13,56,197,214,66,67,223,5,75,105,255,245,217,208,154,211,
    20,156,86,224,164,2,157,103,39,6,17,14,106,144,252,19,
    190,94,103,166,211,204,212,128,19,108,45,56,179,224,180,10,
    79,113,16,146,250,53,82,95,60,59,65,77,145,210,105,91,
    40,237,78,73,93,82,197,15,146,200,29,72,117,7,251,206,
    208,77,220,129,243,91,55,137,164,218,145,234,56,78,14,62,
    137,148,76,122,174,39,219,245,124,74,156,110,14,93,181,111,
    51,15,147,140,51,24,42,230,29,227,188,25,236,244,130,200,
    119,6,177,127,24,74,53,77,140,157,94,16,74,199,225,151,
    159,12,134,113,162,62,78,146,56,177,201,190,76,12,99,183,
    152,65,214,245,194,56,149,109,90,141,151,177,137,189,162,209,
    189,33,115,36,1,88,110,154,236,203,212,75,130,161,66,183,
    105,142,52,154,184,181,201,97,220,164,207,177,217,218,143,7,
    114,235,64,14,6,50,145,15,183,246,228,224,17,55,15,82,
    229,238,134,114,107,247,48,8,253,173,103,239,189,187,53,28,
    169,253,56,218,194,247,1,233,31,185,225,214,119,217,102,19,
    199,47,208,42,199,193,158,19,176,126,206,190,12,135,50,153,
    37,234,109,146,64,52,69,67,84,133,41,218,98,22,123,21,
    252,153,98,221,152,17,59,1,105,232,145,214,132,52,171,140,
    45,114,184,128,3,3,146,117,66,78,31,191,130,92,141,248,
    233,208,59,131,223,253,142,76,163,169,125,147,240,160,137,39,
    140,54,132,29,142,220,38,0,68,192,144,169,64,191,10,26,
    74,136,64,141,173,100,68,45,14,39,54,6,50,183,32,253,
    7,160,169,17,68,39,144,1,236,204,4,17,53,65,213,41,
    222,145,186,130,11,254,137,49,218,105,147,248,59,12,15,181,
    31,164,241,113,196,78,160,62,71,85,7,45,243,249,232,179,
    221,190,244,84,186,129,132,47,227,195,150,231,70,81,172,90,
    174,239,183,92,165,146,96,247,80,201,180,165,226,214,189,180,
    77,126,181,231,115,132,21,252,70,195,28,81,228,125,68,148,
    126,240,3,79,225,195,34,63,176,23,82,169,16,29,251,177,
    159,34,157,88,236,73,101,147,144,138,140,28,179,32,12,30,
    135,134,210,242,56,238,6,62,127,144,75,194,8,109,87,115,
    60,165,50,236,169,58,67,211,77,83,135,37,33,58,163,144,
    24,31,185,225,161,100,238,8,39,133,2,81,87,203,48,73,
    28,222,36,157,114,19,176,94,81,28,249,35,20,51,240,222,
    34,9,110,50,26,27,140,199,101,196,226,20,182,85,252,95,
    21,43,134,103,101,8,172,230,40,164,12,169,128,49,32,50,
    24,32,34,207,48,27,181,13,78,39,172,26,199,232,15,169,
    71,147,237,117,106,40,163,216,119,169,217,200,181,159,144,9,
    102,47,154,224,49,45,107,176,222,172,33,185,203,204,53,244,
    207,197,217,173,113,156,97,242,236,80,188,24,20,85,227,120,
    177,40,209,38,79,168,197,161,28,137,38,164,95,80,90,167,
    184,98,102,20,66,24,12,212,27,135,8,219,203,110,146,29,
    166,115,116,219,4,217,50,110,247,74,184,181,201,85,12,90,
    251,86,158,40,29,26,161,225,106,175,17,171,202,21,6,111,
    81,243,131,9,91,125,12,188,189,75,192,123,159,36,104,102,
    192,155,101,192,213,241,215,52,60,51,115,69,177,165,46,94,
    0,28,161,205,186,2,109,63,166,158,121,89,249,55,3,180,
    76,229,223,148,128,70,82,26,101,205,118,176,51,90,37,133,
    202,16,91,197,50,225,105,180,138,59,191,193,59,255,79,121,
    231,231,234,129,235,41,157,196,77,206,227,186,83,33,203,244,
    76,88,201,118,244,180,134,237,48,137,95,140,90,113,175,165,
    88,117,202,185,219,247,210,205,123,233,251,152,77,91,79,56,
    143,233,124,170,51,102,34,135,148,241,104,234,199,47,60,201,
    155,39,63,57,142,78,112,14,39,59,39,219,148,17,109,203,
    100,87,35,55,56,167,250,84,37,148,225,39,105,242,122,97,
    114,210,224,83,90,179,206,246,54,197,42,34,171,46,88,48,
    71,39,120,46,216,248,45,254,62,36,31,144,242,18,168,212,
    182,59,90,108,214,136,116,179,127,114,14,61,147,209,199,222,
    194,5,126,159,163,166,58,70,13,253,204,60,30,254,10,92,
    209,10,248,11,16,46,208,253,89,60,20,225,67,64,88,164,
    225,127,0,14,156,43,170,6,206,69,29,170,20,120,4,166,
    168,244,49,15,213,69,196,167,240,183,82,212,229,91,189,153,
    213,172,229,173,222,42,242,24,3,234,181,182,115,235,124,194,
    35,31,237,187,41,13,211,89,108,28,200,227,29,163,168,47,
    49,139,79,8,93,211,122,53,135,4,123,62,198,22,109,150,
    107,98,209,40,33,230,103,212,60,44,192,34,114,218,255,95,
    198,13,184,126,131,119,244,222,241,21,9,98,177,232,115,83,
    138,60,117,145,81,17,25,149,60,50,30,22,145,33,121,171,
    123,201,39,27,106,13,194,192,153,33,240,184,137,117,31,157,
    238,44,144,21,232,86,41,134,184,88,23,89,136,137,60,213,
    81,98,60,183,143,178,129,118,180,233,10,24,104,15,83,243,
    98,146,41,132,156,188,29,186,131,93,223,125,18,210,138,180,
    172,151,7,157,145,235,208,44,235,64,1,35,174,83,131,31,
    31,229,186,28,77,50,125,188,139,11,20,58,112,176,248,177,
    199,57,227,139,125,217,26,200,193,46,30,103,247,131,97,171,
    23,186,123,236,39,51,211,241,179,92,71,197,142,190,88,167,
    164,247,169,141,91,94,28,97,150,63,244,84,156,180,124,137,
    7,59,233,183,30,180,120,139,104,5,105,203,221,197,183,174,
    167,116,0,156,15,101,46,143,221,100,47,229,74,248,224,152,
    186,147,246,179,131,231,248,0,143,6,17,20,27,179,62,85,
    22,25,159,139,126,29,79,184,135,226,145,77,141,116,110,163,
    154,197,222,164,230,109,120,3,27,195,59,100,51,90,137,140,
    87,21,107,70,205,80,100,213,171,103,124,78,220,210,203,81,
    253,247,215,137,106,125,125,148,197,118,149,70,202,41,186,89,
    160,182,70,27,69,183,158,19,103,184,109,48,113,54,39,222,
    224,118,142,137,205,252,218,106,158,137,11,208,93,164,123,29,
    162,44,81,190,152,250,111,243,5,7,218,164,67,236,240,127,
    154,38,236,199,111,82,5,251,61,200,202,138,235,82,132,40,
    235,55,171,83,68,95,228,167,157,178,114,124,219,242,163,87,
    160,210,241,18,233,42,169,189,183,62,89,213,57,245,232,245,
    95,140,83,192,229,218,252,131,66,203,51,46,177,70,75,236,
    84,125,244,99,167,138,167,209,109,44,210,45,46,210,183,169,
    72,63,97,147,56,134,174,211,199,160,173,20,150,65,206,16,
    201,227,107,196,211,214,209,69,57,137,233,14,135,50,242,237,
    251,80,174,179,249,245,36,177,66,105,239,27,40,149,62,166,
    88,194,194,250,114,204,82,118,47,105,205,222,173,20,81,58,
    97,63,51,196,255,156,67,188,205,217,189,72,241,246,54,53,
    156,212,139,124,110,255,242,245,241,27,248,116,190,123,173,113,
    88,146,241,53,101,224,171,7,175,26,126,228,165,14,238,55,
    206,17,14,225,5,190,223,12,90,138,47,172,75,68,117,255,
    149,44,130,68,57,248,58,229,21,191,199,112,90,142,206,135,
    5,133,145,194,70,241,101,40,149,252,78,148,115,17,154,93,
    113,248,18,107,134,120,132,39,76,62,170,225,115,232,56,19,
    223,95,127,161,35,30,82,186,184,197,253,85,84,113,135,93,
    22,248,49,106,213,154,224,50,230,194,253,191,22,143,234,111,
    125,44,25,165,54,39,212,185,2,74,124,53,157,87,17,132,
    58,54,217,142,59,208,183,137,124,69,102,147,201,248,250,194,
    126,171,128,36,221,239,240,89,80,159,193,49,105,112,137,197,
    21,149,253,115,162,211,178,131,71,155,185,126,155,90,191,143,
    194,216,59,144,190,190,88,101,228,13,30,241,93,254,53,67,
    127,29,15,92,164,175,93,57,162,19,12,50,70,243,23,222,
    251,9,205,90,190,64,77,101,18,184,97,240,181,190,146,205,
    201,124,155,117,149,116,180,147,156,163,112,141,195,210,94,116,
    16,3,37,145,123,65,138,4,102,120,110,98,150,57,217,133,
    111,191,10,194,101,86,147,70,153,62,107,232,43,148,39,116,
    125,151,126,136,13,221,188,214,230,106,136,56,202,174,166,168,
    99,126,181,204,70,179,102,53,102,106,86,109,202,228,235,177,
    89,60,112,214,173,218,76,67,228,159,13,196,101,221,216,88,
    168,137,255,0,130,214,147,84,
};

EmbeddedPython embedded_m5_internal_param_GarnetNetworkInterface(
    "m5/internal/param_GarnetNetworkInterface.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_GarnetNetworkInterface.py",
    "m5.internal.param_GarnetNetworkInterface",
    data_m5_internal_param_GarnetNetworkInterface,
    2296,
    7245);

} // anonymous namespace
