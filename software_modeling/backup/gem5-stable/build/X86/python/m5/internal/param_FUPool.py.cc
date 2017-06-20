#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_FUPool[] = {
    120,156,189,88,235,110,220,198,21,62,67,114,87,218,149,100,
    73,150,37,217,150,108,173,91,184,217,26,141,212,186,113,28,
    32,138,219,52,141,209,6,129,236,82,49,236,40,65,89,106,
    57,146,184,218,37,183,36,101,121,83,9,5,42,35,237,11,
    244,5,10,244,71,222,166,111,212,158,239,12,73,81,23,3,
    1,154,181,163,157,12,231,114,230,92,190,115,153,233,80,254,
    175,198,191,95,183,136,210,127,41,162,128,255,20,245,136,250,
    138,182,20,41,173,40,184,70,251,53,74,222,163,160,70,175,
    137,182,44,210,22,157,112,199,166,175,44,138,38,101,79,157,
    122,182,140,40,26,54,73,59,180,85,163,231,209,44,57,186,
    78,251,77,74,254,68,74,169,72,209,139,96,140,130,113,122,
    205,212,185,211,16,130,227,132,193,166,12,54,40,152,144,193,
    38,5,147,210,153,160,225,12,233,73,218,154,194,178,173,43,
    76,246,30,147,157,22,178,255,1,217,128,103,230,41,184,130,
    229,204,215,151,88,233,96,165,156,55,45,84,102,10,46,103,
    105,235,106,209,159,171,244,175,85,250,243,149,254,66,165,191,
    88,233,95,175,244,111,72,159,185,188,74,221,155,212,93,162,
    238,50,237,176,226,102,75,142,110,145,182,169,123,155,182,110,
    147,230,191,91,116,194,186,13,174,86,118,172,200,142,185,114,
    71,75,118,220,161,173,59,164,249,175,101,118,212,105,179,189,
    192,246,10,255,203,255,218,108,47,202,38,185,121,169,147,52,
    140,35,47,140,118,226,208,194,124,29,13,172,219,65,51,150,
    155,249,19,152,249,59,18,27,7,86,110,230,99,98,194,10,
    178,244,44,58,150,206,177,69,195,54,29,41,234,58,20,216,
    116,196,199,212,192,192,174,162,19,139,190,182,177,224,152,91,
    135,141,113,155,156,204,216,184,43,198,48,148,198,232,184,70,
    71,53,218,124,113,100,97,96,191,65,201,191,233,155,101,33,
    58,46,68,45,58,226,214,161,19,135,142,235,244,156,23,241,
    80,183,1,241,213,139,35,150,148,71,54,219,14,115,187,81,
    17,23,162,4,97,18,249,125,157,77,113,223,27,248,137,223,
    247,30,63,123,26,199,189,118,179,88,18,167,171,3,63,219,
    115,101,143,13,101,244,7,153,208,138,35,157,77,112,103,39,
    140,2,175,31,7,7,61,157,141,131,144,183,19,246,180,231,
    201,228,239,251,131,56,201,62,77,146,56,113,161,79,25,236,
    197,126,185,3,218,236,244,226,84,183,113,154,28,227,130,124,
    134,213,59,3,161,8,6,132,79,108,14,116,218,73,194,65,
    198,102,50,20,177,26,212,218,48,144,52,233,231,220,172,237,
    197,125,189,182,175,251,125,157,232,251,107,187,186,255,64,154,
    119,211,204,223,238,233,181,237,131,176,23,172,189,248,224,253,
    181,193,48,219,139,163,53,158,15,163,76,179,70,122,107,85,
    93,172,242,252,85,80,61,12,119,189,80,228,241,246,116,111,
    160,19,168,45,189,137,19,213,140,154,84,117,101,171,182,154,
    226,94,141,127,182,90,182,38,212,70,8,137,58,144,18,72,
    114,170,216,129,65,21,237,91,148,44,3,25,93,254,83,48,
    37,227,99,19,115,150,204,253,1,170,48,163,93,27,246,54,
    131,71,130,38,134,21,175,92,135,129,35,18,72,212,168,91,
    39,3,21,70,152,193,78,50,68,203,203,65,198,98,226,14,
    165,255,36,86,45,131,228,136,114,0,157,216,164,162,25,202,
    154,240,121,30,93,224,3,255,38,24,220,108,131,253,13,129,
    67,182,23,166,241,97,36,74,71,95,188,102,147,53,243,116,
    248,100,187,171,59,89,186,194,3,95,198,7,173,142,31,69,
    113,214,242,131,160,229,103,89,18,110,31,100,58,109,101,113,
    235,110,218,134,29,221,217,2,81,37,189,225,160,64,16,172,
    205,8,50,31,65,216,201,248,99,78,62,196,10,169,206,24,
    13,123,113,144,242,56,72,236,234,204,5,147,25,148,28,11,
    35,2,22,15,75,113,60,175,187,194,223,31,23,156,8,34,
    219,245,2,63,169,238,237,100,77,129,162,159,166,158,112,130,
    113,65,29,8,191,244,123,7,90,168,51,124,50,102,8,93,
    195,195,40,113,119,29,50,20,34,139,28,81,28,5,67,102,
    43,236,188,131,19,175,11,250,38,5,127,243,140,189,49,110,
    235,252,255,186,90,176,58,78,142,184,122,129,58,68,188,140,
    196,230,42,55,59,35,240,132,163,75,219,146,240,32,162,136,
    15,254,8,61,108,118,151,209,220,66,115,27,205,74,33,237,
    136,68,158,58,47,242,67,28,99,137,156,34,17,204,97,23,
    18,5,103,252,232,198,169,31,113,240,219,132,63,88,240,154,
    83,127,112,16,40,147,71,104,121,169,120,154,77,233,23,8,
    203,240,27,33,6,23,97,176,163,119,234,2,162,31,119,6,
    114,143,23,232,117,1,201,42,46,119,43,184,116,97,26,1,
    165,123,163,8,124,30,86,24,56,186,75,32,85,187,68,193,
    45,52,119,70,172,229,83,96,237,94,0,214,135,56,113,38,
    7,214,148,0,170,201,191,25,171,99,231,170,47,83,224,220,
    57,64,1,77,206,37,104,250,9,122,246,69,97,223,14,144,
    114,17,31,87,128,4,174,172,170,36,27,220,25,46,66,128,
    42,132,22,57,141,63,143,22,57,51,91,146,153,127,46,153,
    89,178,187,212,68,38,8,219,18,135,77,167,6,77,236,216,
    180,144,103,220,180,193,237,32,137,95,13,91,241,78,43,19,
    81,17,51,215,239,166,171,119,211,15,57,26,182,30,73,28,
    50,241,208,68,188,68,15,16,177,176,245,211,87,29,45,201,
    78,190,60,207,4,40,79,130,149,151,39,81,70,211,60,244,
    104,21,10,150,80,157,102,9,34,244,40,85,220,44,85,12,
    142,63,195,25,77,209,175,173,22,25,57,77,37,140,120,38,
    32,75,1,37,179,252,251,13,116,14,97,53,161,60,118,55,
    13,155,34,1,100,113,127,118,6,29,163,225,223,93,99,130,
    207,10,84,212,79,81,129,159,93,224,251,239,36,21,165,162,
    111,9,118,103,243,230,248,46,221,1,134,158,195,242,63,146,
    56,194,37,89,93,98,201,38,50,185,172,224,16,147,62,148,
    165,38,201,127,70,255,168,120,81,145,138,237,188,102,172,166,
    98,167,140,67,2,152,239,149,110,157,179,1,11,54,217,243,
    83,44,51,81,232,212,49,79,35,124,89,239,113,20,30,17,
    122,198,13,117,15,140,124,125,138,29,36,179,37,53,103,85,
    16,241,11,52,247,75,48,168,98,236,135,231,105,133,222,156,
    112,61,19,219,191,194,193,142,176,58,61,38,117,128,217,94,
    226,187,86,224,251,126,137,111,45,9,232,181,220,23,208,90,
    176,236,137,165,248,162,199,213,22,238,85,14,233,26,109,213,
    225,9,82,18,171,220,81,84,17,160,16,206,206,100,55,81,
    195,134,81,80,105,92,99,55,52,175,70,233,248,48,221,122,
    207,239,111,7,254,163,24,39,224,152,78,225,58,86,193,243,
    76,149,103,192,94,189,137,109,249,124,80,240,254,114,148,78,
    255,62,19,44,121,22,136,7,113,71,60,253,139,61,221,234,
    235,254,54,95,2,247,194,65,107,167,231,239,138,29,236,92,
    166,39,133,76,153,24,242,124,117,144,222,67,27,183,58,113,
    196,177,247,160,147,197,73,43,208,124,61,210,65,235,221,150,
    4,238,86,152,182,252,109,158,245,59,153,129,241,89,7,148,
    162,211,79,118,83,193,213,254,33,186,163,182,163,199,183,221,
    144,11,236,63,83,153,30,205,93,172,140,195,82,58,27,175,
    224,76,198,23,159,108,104,34,16,42,5,119,21,205,79,233,
    45,132,235,247,152,96,4,202,80,78,93,45,89,13,75,238,
    31,102,197,83,172,78,47,122,225,246,247,241,66,243,208,146,
    251,98,29,43,245,24,238,215,104,27,8,215,120,71,169,229,
    239,40,24,52,239,40,117,25,185,2,175,29,251,127,189,86,
    224,63,106,224,191,250,65,157,213,125,248,54,89,118,63,160,
    60,37,191,201,81,85,85,158,41,227,168,93,85,84,250,85,
    97,228,229,96,238,28,118,188,78,162,253,76,27,107,44,143,
    86,52,113,112,115,222,95,78,29,239,98,93,250,113,41,197,
    137,148,31,195,107,98,36,115,173,17,35,169,231,209,77,46,
    80,29,41,80,215,81,160,30,137,200,158,101,106,212,83,208,
    213,74,201,97,235,72,31,122,85,233,77,1,10,182,252,193,
    64,71,129,123,143,170,53,165,76,143,210,214,8,38,127,165,
    74,25,96,171,107,92,68,94,244,41,196,200,138,84,98,173,
    90,233,69,35,182,155,64,242,219,2,146,237,105,170,6,74,
    119,29,141,132,198,50,42,186,191,42,181,190,120,30,111,143,
    159,125,30,166,25,238,39,111,156,227,50,36,175,49,240,41,
    74,18,220,6,186,167,51,125,198,128,98,213,252,38,26,104,
    78,50,241,144,47,10,82,129,243,119,207,243,70,30,160,63,
    98,130,135,160,140,132,193,1,90,213,57,68,207,91,141,122,
    67,73,142,59,247,164,106,88,193,75,131,169,52,135,169,43,
    126,62,93,106,76,94,255,138,148,3,229,202,45,104,195,239,
    155,7,28,121,165,112,127,76,249,13,211,125,167,212,60,174,
    220,82,222,155,107,19,99,93,242,175,164,91,247,151,24,199,
    138,254,131,213,66,150,213,199,207,126,171,211,142,247,82,35,
    111,203,235,99,255,129,92,147,171,139,10,129,177,244,2,133,
    39,131,42,133,203,183,154,53,23,38,117,116,128,185,79,192,
    99,182,116,233,206,205,176,111,94,216,178,217,115,243,65,226,
    115,127,254,220,104,170,147,208,239,133,223,152,39,181,98,56,
    131,110,207,19,132,138,202,47,201,178,149,208,40,120,74,244,
    46,163,143,173,48,93,93,154,199,141,143,10,117,158,193,111,
    117,219,168,129,103,234,81,115,25,126,132,135,150,244,119,220,
    224,77,172,49,221,96,16,34,150,216,124,29,157,82,142,61,
    57,211,112,38,39,26,78,99,204,150,135,141,41,190,106,52,
    157,198,196,164,58,251,223,10,131,182,105,173,204,52,212,255,
    0,199,245,146,205,
};

EmbeddedPython embedded_m5_internal_param_FUPool(
    "m5/internal/param_FUPool.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_FUPool.py",
    "m5.internal.param_FUPool",
    data_m5_internal_param_FUPool,
    2245,
    6625);

} // anonymous namespace
