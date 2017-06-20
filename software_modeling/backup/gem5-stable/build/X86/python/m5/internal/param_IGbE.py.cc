#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_IGbE[] = {
    120,156,229,90,221,111,220,198,17,31,242,62,228,59,73,150,
    100,89,146,45,203,214,57,137,227,139,19,75,177,27,39,65,
    227,58,113,99,55,112,144,40,46,149,194,206,37,8,75,145,
    123,58,74,119,228,149,92,217,190,64,6,138,202,109,243,16,
    160,15,109,209,183,190,245,161,175,109,209,167,22,232,159,144,
    183,254,57,237,204,44,151,199,251,144,109,4,57,197,66,172,
    187,245,222,236,236,112,102,246,183,191,221,37,233,66,242,175,
    128,223,119,42,0,241,223,76,0,15,63,6,52,1,90,6,
    212,12,48,132,1,222,18,108,23,32,122,13,188,2,60,2,
    168,153,32,76,216,195,74,14,62,53,33,152,224,62,69,104,
    230,88,98,64,167,12,34,15,181,2,220,9,102,32,47,138,
    176,93,134,232,231,96,24,70,96,192,93,111,12,188,35,240,
    8,173,99,165,196,6,143,0,9,203,44,44,129,55,206,194,
    50,120,19,92,25,135,206,52,136,9,168,77,146,90,237,40,
    154,189,128,102,167,216,236,215,100,214,195,150,211,224,29,37,
    117,244,235,19,210,204,147,38,95,111,138,173,76,131,199,86,
    234,24,207,76,170,56,3,34,7,91,199,160,118,12,4,126,
    102,96,15,67,246,142,105,197,217,84,113,150,21,143,67,237,
    56,8,252,204,42,69,174,145,226,92,170,56,199,138,243,80,
    155,7,129,159,57,165,56,175,21,23,82,197,5,86,60,1,
    181,19,32,240,179,160,20,85,38,79,66,109,81,103,245,84,
    166,190,148,169,159,206,212,207,100,234,203,153,122,37,83,63,
    155,169,63,151,169,63,159,169,191,144,169,159,203,212,95,204,
    212,207,103,234,213,76,253,165,76,253,2,215,49,170,69,216,
    122,25,182,94,129,173,139,28,253,201,52,250,21,142,126,21,
    106,171,32,240,179,162,162,95,204,244,120,149,123,156,74,123,
    92,226,30,151,161,118,25,4,126,46,169,30,69,88,175,158,
    65,252,250,255,195,127,85,3,107,114,2,139,123,34,138,253,
    48,176,253,160,30,250,38,181,23,169,32,180,187,84,140,37,
    176,127,151,96,255,87,96,204,123,102,2,251,135,128,134,13,
    138,165,105,194,67,174,60,52,161,83,133,93,3,182,242,224,
    229,96,23,47,83,32,7,54,13,216,51,225,179,28,41,60,
    196,50,143,224,60,3,121,169,48,191,197,224,84,150,198,224,
    97,1,118,11,176,126,119,215,36,193,118,9,162,191,192,23,
    75,108,244,8,27,53,97,23,203,60,236,229,225,97,17,238,
    160,18,138,182,74,20,190,113,119,23,35,69,201,122,53,143,
    222,174,101,194,165,80,60,63,10,156,150,144,227,88,183,219,
    78,228,180,236,91,239,109,220,172,150,181,66,24,175,180,29,
    217,176,184,71,142,82,209,106,75,182,20,6,170,91,221,15,
    60,187,21,122,59,77,33,143,144,25,187,238,55,133,109,115,
    227,173,86,59,140,228,205,40,10,35,139,178,201,194,102,232,
    164,61,40,151,110,51,140,69,149,174,198,151,177,200,188,36,
    237,122,155,45,146,3,169,151,158,136,221,200,111,75,28,36,
    101,145,180,201,90,149,134,135,139,248,125,44,86,27,97,75,
    172,110,139,86,75,68,226,242,234,166,104,93,225,226,98,44,
    157,141,166,88,221,216,241,155,222,234,221,55,95,95,109,119,
    100,35,12,86,177,221,15,164,192,124,52,87,187,153,88,193,
    214,99,100,243,190,191,105,251,28,141,221,16,205,182,136,38,
    73,186,72,215,51,166,141,9,163,104,228,140,170,49,137,181,
    2,126,115,198,146,57,110,172,249,20,143,75,49,18,138,242,
    89,220,208,96,26,176,109,66,180,68,168,216,194,143,65,195,
    136,216,88,167,54,147,219,126,74,137,80,210,173,28,141,181,
    18,238,50,146,16,82,168,121,149,6,55,0,134,67,1,182,
    138,160,96,130,232,82,184,137,58,84,162,58,153,49,209,120,
    30,226,63,2,38,22,1,178,11,9,120,246,114,96,4,211,
    32,203,196,127,40,157,199,11,254,138,241,183,94,37,247,215,
    24,12,178,225,199,225,253,128,83,78,117,158,49,235,152,153,
    219,157,143,54,182,132,43,227,101,20,124,18,238,84,92,39,
    8,66,89,113,60,175,226,72,25,249,27,59,82,196,21,25,
    86,206,197,85,26,69,107,70,227,41,181,215,105,107,252,208,
    88,35,126,212,15,207,119,37,254,152,229,31,60,10,177,144,
    136,133,70,232,197,40,39,19,155,66,90,228,164,164,36,135,
    236,136,2,52,169,210,229,81,239,40,254,190,174,61,97,60,
    86,139,26,61,177,104,214,101,153,129,232,196,177,205,158,144,
    156,49,71,134,239,57,205,29,193,214,17,60,18,29,162,170,
    242,97,116,168,59,65,17,232,128,57,138,32,12,188,14,58,
    229,187,231,233,122,39,24,123,19,140,190,57,68,222,24,150,
    69,252,191,104,204,155,110,62,193,91,81,99,110,158,162,5,
    30,113,35,25,116,196,223,30,242,74,213,100,98,224,64,120,
    254,61,71,53,234,108,45,81,113,154,10,162,74,107,89,199,
    58,146,128,39,251,3,126,131,46,98,114,148,28,15,13,69,
    78,199,227,245,204,161,147,221,57,132,164,183,78,115,193,164,
    25,211,157,11,121,34,200,232,26,149,168,202,179,44,7,241,
    199,68,199,52,103,216,24,77,15,4,58,213,186,240,231,236,
    88,211,20,245,17,141,92,139,224,152,197,228,102,6,147,22,
    13,12,3,210,58,169,41,207,38,13,5,69,235,20,153,42,
    12,73,111,133,138,179,35,205,113,23,84,155,3,160,122,139,
    174,55,157,128,106,146,193,84,198,239,180,233,230,146,196,167,
    11,223,108,31,152,8,73,249,33,72,122,145,106,185,193,80,
    15,2,68,73,128,63,201,128,136,124,50,179,113,172,97,165,
    179,64,238,103,225,179,128,75,247,157,96,1,87,99,147,87,
    227,87,121,53,230,21,157,247,133,138,124,115,204,191,170,82,
    160,60,212,115,48,159,172,178,113,9,203,118,20,62,232,84,
    194,122,69,114,160,196,149,87,207,197,43,231,226,183,144,5,
    43,215,152,127,20,15,42,166,139,68,155,152,138,186,222,124,
    224,10,94,226,248,151,109,43,98,178,153,164,236,100,233,68,
    36,205,81,22,77,157,94,166,232,88,70,196,204,163,75,112,
    57,77,48,249,75,198,227,50,103,55,103,44,32,106,202,6,
    187,97,43,26,230,45,19,183,226,247,199,148,113,10,85,0,
    29,16,172,117,229,36,251,79,145,88,175,244,32,99,20,222,
    91,171,104,238,103,26,17,197,46,34,232,155,211,200,254,45,
    240,14,210,128,223,0,141,57,14,109,130,236,116,34,208,32,
    207,146,250,231,192,83,96,200,74,206,28,178,78,171,55,107,
    32,181,196,111,176,170,90,216,223,135,47,51,243,71,47,191,
    185,100,143,152,93,126,243,41,255,48,88,158,106,137,205,247,
    18,21,141,72,195,137,73,77,177,79,119,74,118,121,61,221,
    225,33,251,142,4,57,71,148,109,155,220,248,172,139,27,90,
    192,78,25,179,102,6,13,151,168,184,156,2,193,208,178,111,
    219,163,101,216,127,137,181,21,159,127,74,151,205,179,163,83,
    99,156,200,155,178,113,221,243,162,20,218,5,13,237,27,41,
    180,5,175,58,143,248,112,64,165,73,195,186,103,26,120,202,
    85,231,91,220,100,209,209,178,8,98,140,246,240,116,118,45,
    36,103,87,156,22,68,12,140,76,253,101,174,34,102,235,89,
    228,56,47,107,42,99,233,88,171,97,164,226,193,232,56,128,
    70,242,106,211,105,109,120,206,181,77,178,79,23,113,245,60,
    50,181,199,211,89,143,105,14,24,251,57,205,63,175,104,207,
    239,141,110,254,191,142,230,82,143,25,237,94,232,242,164,255,
    184,33,42,45,209,218,192,243,95,195,111,87,234,77,103,147,
    199,64,175,123,239,233,33,150,58,156,175,212,233,238,56,199,
    168,119,27,116,182,188,19,44,226,218,145,231,181,227,109,90,
    59,118,153,5,108,83,45,31,221,161,227,77,64,122,44,10,
    196,125,59,1,151,90,22,8,7,78,187,45,2,207,186,208,
    51,107,121,119,234,68,155,49,235,141,118,156,109,60,10,251,
    184,3,223,234,206,216,41,228,250,227,200,245,131,24,37,191,
    50,241,241,196,45,164,83,120,105,148,206,242,208,254,66,15,
    173,58,100,164,171,10,111,255,213,76,199,85,25,15,111,178,
    163,24,117,133,138,151,168,184,154,142,5,233,122,2,207,166,
    66,15,135,156,134,116,167,135,231,79,25,133,29,92,140,121,
    157,195,223,77,219,30,241,170,245,26,154,171,235,252,23,145,
    45,139,102,169,88,50,120,115,112,171,77,30,138,56,126,150,
    9,137,231,246,104,135,254,222,183,202,67,214,27,7,231,176,
    245,38,36,27,143,239,150,131,38,19,14,74,17,165,18,243,
    67,42,122,249,199,122,75,167,109,116,41,162,249,216,57,12,
    156,243,203,125,56,199,250,17,21,251,178,204,116,151,101,186,
    9,127,155,154,223,233,113,121,36,126,95,71,115,59,251,18,
    202,26,30,102,157,120,251,123,78,40,191,62,108,132,146,58,
    252,236,17,74,130,168,239,156,80,190,60,12,132,242,187,111,
    129,80,116,194,15,138,80,8,67,143,134,16,74,153,9,229,
    142,47,27,183,195,72,126,207,25,229,15,135,141,81,82,135,
    159,21,70,57,154,50,138,134,212,119,78,41,127,58,12,148,
    242,231,111,70,41,51,89,74,73,51,126,80,156,242,30,154,
    251,253,16,78,161,100,146,206,32,155,92,126,26,54,73,120,
    36,15,162,64,108,98,169,7,92,207,58,119,252,227,176,113,
    71,234,240,211,113,7,185,246,145,142,70,242,184,245,63,131,
    137,105,130,175,133,21,55,12,240,8,190,227,202,48,170,120,
    162,238,7,194,171,92,172,240,45,242,138,31,87,156,13,108,
    117,92,169,70,166,239,118,39,145,2,223,87,217,190,79,247,
    79,70,75,13,255,132,244,209,131,122,186,61,108,222,93,237,
    153,124,35,158,82,100,238,239,100,183,168,166,148,89,50,213,
    18,141,237,183,73,115,200,93,132,207,141,111,176,68,155,201,
    42,77,101,137,110,126,227,42,157,8,199,185,156,96,225,164,
    22,30,229,114,138,133,211,90,56,195,229,49,22,206,106,225,
    113,46,231,88,56,175,133,11,92,158,96,225,73,45,92,228,
    242,20,11,151,180,240,52,151,103,88,184,172,133,21,46,207,
    178,240,57,45,124,158,203,23,88,120,78,11,95,228,242,60,
    11,171,90,248,18,151,23,88,248,178,22,190,194,229,69,22,
    174,232,173,202,42,11,95,133,218,37,122,219,133,36,151,137,
    128,198,14,1,1,253,251,176,17,80,234,240,147,9,200,200,
    70,51,9,233,230,5,6,66,73,151,197,238,140,177,221,72,
    56,82,28,192,82,206,196,165,174,246,159,46,181,12,62,213,
    188,158,70,176,199,15,176,122,246,94,198,192,222,235,42,239,
    189,140,167,222,123,165,145,247,239,189,210,39,145,7,176,237,
    250,26,50,15,144,158,213,109,215,127,53,4,171,63,128,39,
    110,187,214,210,76,47,247,226,171,46,164,219,176,221,176,213,
    166,155,205,78,135,158,108,63,81,39,70,29,186,64,127,131,
    92,28,214,177,107,247,49,205,100,114,60,53,169,172,245,185,
    209,112,34,15,23,86,97,59,234,134,214,48,87,7,116,180,
    171,253,13,114,161,183,99,187,209,177,69,219,247,216,232,126,
    109,100,140,223,25,75,4,114,126,80,81,219,216,167,137,76,
    140,37,38,200,194,217,94,181,232,1,61,3,112,109,215,113,
    27,194,142,253,47,4,27,123,178,22,217,165,87,201,6,155,
    228,169,129,206,117,191,30,118,141,63,174,157,204,78,40,179,
    169,80,158,30,232,112,63,242,113,27,223,29,232,199,107,144,
    209,163,202,104,70,220,31,164,124,170,84,12,209,210,169,24,
    108,234,15,85,62,33,21,114,88,42,178,66,185,52,208,1,
    25,212,203,100,226,177,10,100,114,82,153,236,74,251,187,220,
    223,232,159,158,143,85,208,54,123,164,253,136,198,198,174,185,
    253,218,52,218,181,128,169,177,231,216,214,37,235,131,58,182,
    125,128,230,254,69,118,233,229,159,228,216,102,206,25,251,252,
    241,145,142,55,232,125,111,219,86,83,222,84,47,37,116,98,
    139,36,214,84,74,147,60,205,245,211,60,98,84,190,125,189,
    230,180,212,251,125,252,26,155,245,60,21,228,137,117,62,165,
    91,122,43,139,223,4,81,111,215,224,162,198,135,7,62,43,
    88,204,212,244,192,77,30,135,244,97,63,63,250,139,196,166,
    31,99,200,124,247,92,145,135,190,113,223,219,126,163,219,158,
    220,135,235,109,167,131,173,26,210,244,80,221,163,192,115,179,
    117,101,69,39,120,69,37,24,125,17,209,13,113,207,119,5,
    191,29,219,186,194,147,97,80,241,182,235,39,106,139,195,219,
    155,142,172,135,81,107,159,235,220,10,100,244,110,136,69,216,
    228,247,197,6,53,214,59,232,102,107,224,234,34,216,105,217,
    31,138,86,24,117,62,12,61,53,243,178,237,252,100,219,9,
    54,133,125,79,208,233,141,137,162,71,33,57,186,41,27,90,
    171,50,212,135,94,221,125,50,129,141,234,197,84,94,132,6,
    219,223,109,134,238,182,240,18,157,225,233,96,157,27,97,203,
    65,249,240,171,172,251,250,42,51,125,237,94,68,189,230,250,
    164,177,136,124,167,169,201,110,208,222,141,150,147,140,223,62,
    227,235,135,73,59,77,1,221,200,23,31,68,202,184,66,177,
    254,205,71,192,116,7,219,11,187,153,94,213,132,55,62,72,
    209,218,37,160,108,183,209,210,137,122,215,68,189,241,118,141,
    98,137,35,44,232,149,215,210,84,9,169,133,54,127,57,163,
    140,219,191,124,110,98,186,148,159,24,47,229,75,99,57,126,
    119,113,210,152,53,203,249,210,248,252,68,201,40,155,131,229,
    132,241,164,191,229,34,233,45,47,149,140,255,3,161,54,49,
    21,
};

EmbeddedPython embedded_m5_internal_param_IGbE(
    "m5/internal/param_IGbE.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_IGbE.py",
    "m5.internal.param_IGbE",
    data_m5_internal_param_IGbE,
    3089,
    13044);

} // anonymous namespace
