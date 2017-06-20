#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_X86NativeTrace[] = {
    120,156,197,88,91,115,219,198,21,62,11,128,148,72,81,22,
    101,221,108,75,177,144,116,220,176,158,70,106,221,56,206,140,
    85,183,105,234,206,36,211,200,41,232,142,29,37,83,20,2,
    86,18,40,16,224,0,43,217,204,80,47,165,167,237,244,189,
    63,161,15,253,55,253,71,205,57,103,1,16,186,117,50,211,
    154,149,137,245,98,177,123,246,92,190,115,217,245,33,255,171,
    225,243,75,27,32,251,155,0,8,240,39,32,2,232,11,216,
    19,32,164,128,96,25,142,107,144,126,8,65,13,222,0,236,
    25,32,13,24,99,199,132,175,13,136,91,188,166,14,145,201,
    35,2,134,77,144,22,236,213,224,69,188,8,150,172,195,113,
    19,210,63,130,16,34,22,240,50,152,129,96,22,222,32,117,
    236,52,152,224,44,208,96,147,7,27,16,204,241,96,19,130,
    22,119,230,96,216,6,217,130,189,121,154,182,119,3,201,222,
    71,178,11,76,246,95,68,54,192,47,43,16,220,160,233,200,
    215,87,52,211,162,153,188,223,2,83,105,23,92,46,194,222,
    205,162,191,84,233,47,87,250,43,149,254,106,165,191,198,125,
    228,230,38,244,110,65,239,54,244,238,192,1,42,104,177,220,
    121,29,164,9,189,13,216,219,0,137,191,117,24,163,14,131,
    155,149,21,239,240,138,165,114,197,93,94,177,9,123,155,32,
    241,119,87,175,168,67,183,179,138,118,9,255,141,127,29,180,
    11,168,22,54,167,50,205,194,36,118,195,248,32,9,13,250,
    94,167,134,172,232,83,51,147,155,243,83,50,231,63,129,109,
    25,24,185,57,207,0,9,11,146,37,50,224,140,59,103,6,
    12,59,48,18,208,179,32,48,97,132,219,212,136,129,67,1,
    99,3,190,49,105,194,25,182,22,42,253,46,88,74,219,178,
    199,74,215,148,102,224,172,6,163,26,116,95,142,12,26,56,
    110,64,250,15,248,118,131,137,206,50,81,3,70,216,90,48,
    182,224,172,14,47,112,18,14,245,26,36,190,120,57,66,73,
    113,164,219,177,144,219,221,138,184,36,74,16,166,177,215,151,
    106,5,251,238,192,75,189,190,251,242,227,143,118,61,21,158,
    202,231,169,231,203,78,179,152,154,100,91,3,79,29,57,188,
    214,36,165,244,7,138,105,38,177,84,115,216,57,8,227,192,
    237,39,193,73,36,213,44,17,116,15,194,72,186,46,127,252,
    172,63,72,82,245,52,77,147,212,33,189,242,96,148,120,229,
    10,210,170,31,37,153,236,208,110,188,141,67,228,21,205,62,
    24,48,69,98,128,249,165,197,129,204,252,52,28,40,52,151,
    166,72,179,137,90,135,12,197,77,246,28,155,237,163,164,47,
    183,143,101,191,47,83,249,96,251,80,246,31,114,243,65,166,
    188,253,72,110,239,159,132,81,176,141,98,111,15,134,234,40,
    137,183,241,123,24,43,137,154,137,182,175,210,201,22,206,187,
    73,212,95,133,135,110,200,114,185,71,50,26,200,116,158,70,
    239,208,206,162,45,90,162,46,76,209,17,243,216,171,225,99,
    138,13,99,78,236,134,36,153,79,210,18,178,172,42,150,200,
    192,2,142,13,72,55,8,41,61,252,9,50,45,226,165,75,
    223,12,254,246,59,82,137,30,237,153,100,127,61,56,98,116,
    33,204,112,230,14,25,60,6,134,72,13,122,117,208,208,65,
    196,105,44,165,67,106,113,58,145,49,144,184,5,217,223,1,
    85,140,160,25,65,14,168,177,9,34,110,131,106,146,175,227,
    232,42,110,248,39,198,100,183,67,236,239,50,44,212,81,152,
    37,175,98,86,62,245,217,139,186,168,153,47,135,207,246,123,
    210,87,217,38,14,124,149,156,216,190,23,199,137,178,189,32,
    176,61,165,210,112,255,68,201,204,86,137,125,47,235,144,61,
    157,197,2,89,37,189,225,160,64,18,89,29,145,164,95,130,
    208,87,248,178,196,47,108,133,76,42,68,197,81,18,100,56,
    78,36,14,165,114,136,73,69,74,78,152,17,6,141,75,83,
    105,123,156,119,3,223,63,41,56,97,100,118,234,5,142,50,
    25,29,168,38,67,210,203,50,151,57,161,113,70,31,17,62,
    245,162,19,201,212,17,70,10,25,162,174,230,97,26,248,187,
    69,178,20,162,179,60,113,18,7,67,100,47,244,223,167,157,
    111,49,10,91,140,195,21,196,224,12,182,117,252,191,46,86,
    13,223,202,145,87,47,208,71,145,80,1,219,94,228,230,71,
    36,142,49,234,116,12,14,27,44,18,251,228,123,212,163,197,
    206,6,53,239,80,115,151,154,205,66,234,183,44,250,252,69,
    209,31,209,118,6,203,203,146,145,121,204,66,178,224,156,95,
    221,158,248,21,6,199,46,249,135,65,94,52,241,15,139,2,
    105,250,132,90,156,202,158,103,146,48,74,251,17,19,35,151,
    65,240,83,111,226,18,172,39,167,77,242,207,22,104,118,8,
    162,85,156,30,86,112,234,144,137,24,164,206,237,34,32,186,
    52,67,195,211,89,39,82,181,43,20,109,83,243,238,148,180,
    61,1,218,225,37,160,61,166,157,219,57,208,230,25,96,77,
    124,218,134,111,230,38,40,83,229,210,5,128,17,186,172,43,
    208,245,67,234,153,151,133,158,46,176,114,81,127,83,1,22,
    113,103,84,37,218,197,206,112,141,4,169,66,106,13,211,254,
    139,120,13,51,185,193,153,252,39,156,201,185,26,224,90,73,
    7,105,147,227,180,238,212,72,35,7,38,172,230,25,58,107,
    96,59,72,147,215,67,59,57,176,21,139,76,49,117,231,94,
    182,117,47,123,140,209,210,126,194,113,74,199,75,29,17,83,
    57,160,136,70,75,159,190,246,37,39,69,126,115,93,29,192,
    92,14,102,110,158,108,17,93,148,241,89,251,172,104,14,229,
    153,74,41,130,79,67,213,205,82,213,196,249,231,180,87,147,
    245,108,138,53,68,82,83,48,67,174,14,220,92,120,241,87,
    124,126,69,186,39,161,37,80,249,236,116,53,187,44,9,201,
    228,252,248,28,90,222,174,28,206,54,18,254,125,129,146,250,
    4,37,244,152,5,238,255,2,92,145,10,248,51,16,14,208,
    220,57,238,75,55,33,195,47,209,244,63,0,59,200,21,85,
    0,199,154,46,101,126,158,129,33,40,123,196,83,117,81,240,
    57,252,181,226,93,69,234,54,243,154,179,154,186,173,50,78,
    49,128,190,87,122,182,206,7,52,178,205,145,151,209,52,29,
    165,38,14,59,201,4,101,157,136,81,250,45,163,105,86,239,
    226,18,67,223,76,176,68,201,111,93,44,25,21,132,252,148,
    154,7,37,56,68,49,246,246,120,219,132,235,19,181,171,115,
    193,215,196,128,197,44,47,204,40,82,40,175,118,63,125,246,
    219,103,187,221,11,52,75,103,168,21,206,240,160,116,6,201,
    89,236,13,31,74,168,53,200,252,99,67,224,169,17,75,56,
    58,164,89,32,107,176,87,39,183,225,122,91,228,94,37,138,
    168,70,49,240,92,138,100,29,237,106,237,149,8,208,198,165,
    230,245,52,162,5,217,119,39,242,250,251,129,247,164,79,59,
    209,118,126,225,103,70,193,123,187,202,59,249,136,184,142,125,
    126,125,88,200,112,58,141,72,241,17,18,46,121,103,191,8,
    18,159,195,195,243,35,105,247,101,127,31,79,158,71,225,192,
    62,136,188,67,182,139,153,203,246,172,144,77,177,97,47,150,
    28,217,125,106,19,219,79,98,12,224,39,190,74,82,59,144,
    120,22,147,129,253,129,205,209,223,14,51,219,219,199,175,158,
    175,52,230,207,123,45,87,182,94,122,152,113,17,123,252,138,
    186,211,178,171,139,71,237,16,171,249,4,202,92,171,15,128,
    101,48,231,58,93,187,16,166,69,60,101,169,161,14,95,84,
    126,56,91,212,252,8,166,24,243,63,68,194,17,237,64,202,
    170,139,117,163,97,168,101,236,158,159,249,37,173,206,46,123,
    235,23,223,199,91,245,237,78,238,179,245,226,90,104,6,36,
    159,208,232,230,166,158,223,220,160,35,207,252,183,142,204,158,
    48,45,31,56,253,159,250,175,243,232,255,193,186,243,49,228,
    169,253,58,223,21,85,185,230,181,239,246,68,113,162,168,10,
    197,55,23,235,215,192,199,245,83,233,41,169,173,180,49,29,
    81,57,6,232,125,135,19,159,188,92,255,126,82,74,53,230,
    178,102,184,204,198,211,199,41,54,158,120,17,223,193,66,216,
    226,66,120,135,10,225,17,171,192,53,116,45,60,1,101,173,
    212,4,29,55,98,249,202,189,74,27,186,224,37,246,188,193,
    64,198,129,115,31,170,53,44,127,158,6,22,30,107,156,78,
    202,12,83,44,99,209,122,217,7,41,172,86,164,100,43,214,
    74,175,155,146,61,25,186,227,2,186,29,58,74,76,98,171,
    179,67,13,71,211,50,144,58,191,128,34,184,150,224,12,100,
    36,149,188,210,42,138,86,231,199,219,64,98,146,73,134,120,
    218,224,242,29,223,35,215,157,90,96,254,57,18,62,129,252,
    184,132,129,89,212,141,134,217,168,55,4,103,186,11,183,185,
    154,33,27,138,34,117,152,57,236,218,11,165,220,124,225,88,
    36,28,210,19,31,168,118,189,190,190,43,226,139,16,231,7,
    144,31,90,157,247,75,37,210,105,158,79,6,250,4,134,112,
    230,44,204,73,215,249,25,141,211,177,182,255,112,171,144,104,
    75,75,84,17,135,47,61,251,15,89,247,151,39,62,125,173,
    103,165,106,227,202,239,159,97,37,144,79,184,154,64,55,236,
    235,203,57,181,120,225,123,144,122,216,95,185,48,154,201,52,
    244,162,240,91,125,27,87,12,243,226,203,172,147,11,159,43,
    96,43,31,57,121,242,113,224,63,148,184,140,165,84,30,134,
    25,238,195,155,92,14,5,100,107,245,238,117,97,179,74,96,
    90,240,211,85,170,62,95,63,161,187,156,236,215,216,208,245,
    91,99,161,129,80,164,48,97,226,201,118,94,88,102,171,221,
    176,90,115,13,171,49,99,242,157,201,60,158,82,154,86,99,
    174,37,38,255,54,17,184,77,99,19,215,126,7,184,84,201,
    148,
};

EmbeddedPython embedded_m5_internal_param_X86NativeTrace(
    "m5/internal/param_X86NativeTrace.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_X86NativeTrace.py",
    "m5.internal.param_X86NativeTrace",
    data_m5_internal_param_X86NativeTrace,
    2209,
    6728);

} // anonymous namespace
