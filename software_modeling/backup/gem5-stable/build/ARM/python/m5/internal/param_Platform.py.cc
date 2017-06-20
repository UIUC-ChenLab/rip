#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_Platform[] = {
    120,156,189,88,253,110,27,199,17,159,189,59,82,34,69,89,
    148,101,73,182,165,88,103,39,106,88,163,145,90,55,174,11,
    196,49,234,186,41,144,0,86,220,99,10,219,76,208,235,137,
    183,164,142,186,15,226,110,101,155,169,4,20,149,209,244,5,
    250,8,253,163,111,83,244,133,210,153,217,59,234,72,201,69,
    128,150,146,201,245,114,111,110,118,62,126,243,177,219,133,252,
    175,130,223,95,217,0,217,191,5,128,143,31,1,33,64,36,
    160,35,64,72,1,254,53,56,172,64,250,49,248,21,120,11,
    208,49,64,26,112,138,19,19,190,54,32,110,240,59,85,8,
    77,94,17,48,170,131,180,160,83,129,231,241,50,88,178,10,
    135,117,72,255,8,66,136,88,192,11,127,14,252,121,120,139,
    220,113,82,99,134,243,64,139,117,94,172,129,191,192,139,117,
    240,27,60,89,128,81,19,100,3,58,139,68,214,185,130,108,
    239,34,219,37,102,251,47,98,235,227,147,85,240,175,16,57,
    202,245,146,40,45,162,228,253,150,152,75,179,144,114,25,58,
    87,139,249,74,105,126,173,52,95,45,205,215,74,243,245,210,
    252,122,105,126,163,52,191,89,154,111,148,230,155,165,249,123,
    60,71,173,174,194,224,22,12,182,96,96,67,15,13,189,60,
    214,224,54,72,19,6,119,160,115,7,36,126,110,195,41,250,
    194,191,90,122,227,125,126,99,101,252,198,7,252,198,54,116,
    182,65,226,231,3,253,70,21,218,173,53,244,111,240,61,254,
    181,208,191,160,26,56,188,146,105,22,36,177,27,196,189,36,
    48,232,121,149,6,66,67,151,134,185,28,22,79,8,22,255,
    4,198,132,111,228,176,56,1,100,44,72,151,208,128,19,158,
    156,24,48,106,193,177,128,129,5,190,9,199,184,77,133,4,
    232,11,56,53,224,27,147,8,78,112,180,208,121,183,192,82,
    26,19,3,118,158,230,52,7,39,21,56,174,64,251,197,177,
    65,11,135,53,72,255,1,223,110,50,211,121,102,106,192,49,
    142,22,156,90,112,82,133,231,72,132,75,131,26,169,47,94,
    28,163,166,184,210,110,89,40,237,94,73,93,82,197,15,210,
    216,139,164,90,194,185,59,244,82,47,114,159,133,158,234,37,
    105,212,170,23,68,73,182,51,244,212,129,195,111,153,100,142,
    104,168,152,91,18,75,181,128,147,94,16,251,110,148,248,71,
    161,84,243,196,202,237,5,161,116,93,126,248,121,52,76,82,
    245,89,154,38,169,67,22,229,197,48,241,198,111,144,61,187,
    97,146,201,22,237,198,219,56,196,94,17,117,111,200,28,73,
    0,150,148,94,246,101,214,77,131,161,66,71,105,142,68,77,
    220,90,228,34,30,178,61,28,118,15,146,72,238,30,202,40,
    146,169,188,183,219,151,209,125,30,62,202,148,183,31,202,221,
    253,163,32,244,119,31,59,79,119,135,35,117,144,196,187,248,
    60,136,149,68,155,132,187,147,214,216,65,138,171,196,247,117,
    208,119,3,214,200,61,144,225,80,166,139,180,122,147,246,20,
    77,209,16,85,97,138,150,88,196,89,5,191,166,216,52,22,
    196,94,64,58,117,73,79,66,147,85,198,15,57,85,192,161,
    1,233,38,161,99,128,31,65,238,68,140,180,233,153,193,207,
    126,71,198,208,171,3,147,124,174,23,143,25,81,8,45,164,
    124,72,78,142,129,97,81,129,65,21,52,92,16,101,26,63,
    233,136,70,36,39,54,6,50,183,32,251,59,160,113,17,40,
    199,144,131,232,212,4,17,55,65,213,41,79,224,234,26,110,
    248,23,198,97,187,69,226,239,49,32,212,65,144,37,175,99,
    54,59,205,57,114,218,104,153,103,163,47,247,7,178,171,178,
    45,92,120,153,28,217,93,47,142,19,101,123,190,111,123,74,
    165,193,254,145,146,153,173,18,123,59,107,145,39,157,229,2,
    83,99,126,163,97,129,33,242,55,98,72,255,240,131,174,194,
    31,43,252,131,189,144,73,133,120,56,72,252,12,215,137,69,
    95,42,135,132,84,100,228,132,5,97,184,184,68,74,219,35,
    221,21,252,253,184,144,132,49,217,170,22,8,202,100,216,83,
    117,6,163,151,101,46,75,66,235,140,59,98,252,202,11,143,
    36,115,71,0,41,20,136,166,90,134,217,34,239,58,105,81,
    40,205,154,196,73,236,143,80,176,160,251,33,237,121,157,241,
    215,96,4,174,34,250,230,112,172,226,255,85,177,102,116,173,
    28,115,213,2,119,148,247,20,176,215,69,238,120,196,224,41,
    230,152,150,193,73,130,149,225,56,188,67,51,122,217,217,164,
    225,61,26,110,209,176,85,232,59,51,165,23,167,149,126,64,
    27,25,172,41,235,68,46,49,11,157,252,137,88,186,113,22,
    75,152,4,219,20,19,6,69,206,89,76,88,148,48,211,71,
    52,34,41,71,155,9,217,87,148,158,41,118,152,25,133,9,
    2,158,102,103,97,192,22,114,154,164,249,124,129,96,135,96,
    89,198,102,191,132,77,135,156,195,192,116,110,20,233,207,37,
    10,13,73,103,131,88,85,46,48,177,77,195,237,153,219,249,
    12,92,253,115,224,250,132,246,108,230,224,90,100,80,213,241,
    219,52,186,102,110,252,113,49,92,153,2,21,33,202,186,0,
    81,63,162,153,121,94,221,203,2,83,174,228,111,75,96,34,
    185,140,178,46,36,192,104,157,84,40,195,104,29,75,250,243,
    120,29,171,180,193,85,250,167,92,165,185,210,115,63,165,147,
    177,201,249,88,79,42,100,139,158,9,107,121,245,205,106,56,
    14,211,228,205,200,78,122,182,98,101,41,119,62,220,206,118,
    182,179,79,48,43,218,143,56,31,233,188,168,51,95,42,135,
    148,185,232,213,207,222,116,37,151,61,254,229,186,58,81,185,
    156,180,220,188,156,34,162,86,201,146,70,97,98,78,217,153,
    74,41,83,207,214,200,245,177,145,73,230,47,104,151,58,91,
    216,20,235,136,158,186,96,81,92,157,154,185,157,226,167,248,
    253,53,89,157,212,149,64,205,181,211,214,130,178,14,164,141,
    243,147,9,132,204,74,3,103,23,89,254,190,64,70,245,12,
    25,244,53,11,148,127,7,220,97,10,248,43,144,239,209,197,
    57,202,199,65,65,206,94,33,242,63,0,135,195,5,21,158,
    115,74,155,170,58,83,96,170,201,30,48,169,46,248,95,192,
    223,74,177,84,148,101,51,239,33,203,101,217,26,231,35,6,
    205,15,42,189,214,100,226,34,175,28,120,25,145,233,108,116,
    22,158,103,185,126,220,253,97,54,158,25,130,230,53,127,151,
    68,249,230,12,63,84,216,54,196,138,81,66,197,207,104,184,
    55,6,132,40,214,102,33,213,22,188,187,252,186,58,207,127,
    77,91,91,44,236,210,28,171,81,48,24,227,188,82,224,252,
    222,24,231,146,203,209,91,62,69,208,104,144,127,79,13,129,
    199,69,236,191,232,116,102,129,172,64,167,74,17,193,109,178,
    200,3,70,20,169,138,18,219,68,173,99,83,236,105,35,141,
    93,172,189,71,195,155,217,166,0,210,252,97,232,69,251,190,
    247,40,163,61,104,163,110,17,66,70,33,117,179,44,53,193,
    95,188,75,112,254,121,191,144,254,213,108,195,255,23,185,196,
    44,53,131,221,79,186,28,243,95,29,72,59,146,209,62,30,
    15,15,130,161,221,11,189,62,251,194,204,181,250,178,208,74,
    177,51,167,251,133,236,46,141,137,221,77,98,204,196,71,93,
    149,164,182,47,241,216,36,125,251,35,155,211,184,29,100,182,
    183,143,79,189,174,210,112,158,12,69,110,69,189,180,159,113,
    215,121,248,154,166,179,247,165,139,39,225,0,27,239,35,24,
    151,75,125,74,27,103,101,110,169,117,116,96,101,195,3,145,
    26,233,108,68,189,131,179,67,195,143,225,82,146,247,199,200,
    50,37,222,100,160,170,216,48,106,6,11,87,208,60,163,55,
    178,243,241,248,242,135,196,163,190,184,65,2,89,133,193,28,
    143,243,148,181,233,94,198,202,239,101,104,113,1,58,141,226,
    62,104,145,194,182,250,191,134,45,163,127,246,184,63,254,191,
    70,171,243,224,114,133,118,126,9,121,117,126,87,164,78,52,
    120,143,117,164,106,219,99,13,31,93,99,5,245,25,129,21,
    20,207,227,155,216,233,89,220,233,61,164,78,239,152,187,65,
    215,208,205,222,153,203,184,117,231,107,8,186,32,136,229,107,
    119,18,112,186,151,35,24,120,195,161,140,125,231,46,148,219,
    51,126,60,91,75,81,36,254,25,74,213,212,20,215,176,31,
    59,143,74,74,49,37,205,24,125,149,49,14,55,47,197,165,
    223,21,46,109,93,153,200,51,206,67,26,154,19,73,69,155,
    125,227,92,140,99,210,82,105,87,165,33,117,251,255,245,57,
    22,116,206,115,197,2,219,74,209,166,190,12,165,146,83,190,
    84,180,127,126,198,243,37,38,235,100,132,237,55,119,181,248,
    59,116,221,75,72,115,159,34,203,63,65,126,114,192,52,135,
    231,177,85,163,86,173,9,174,21,83,151,150,90,20,58,115,
    233,222,109,148,57,28,46,75,99,235,241,237,90,145,184,201,
    198,124,182,216,243,34,125,61,194,55,0,206,251,144,159,220,
    156,15,199,14,160,195,44,55,204,250,48,130,192,231,58,198,
    101,203,249,57,173,211,217,46,186,191,83,232,178,163,117,249,
    28,77,253,4,143,48,105,18,242,13,95,116,159,143,160,231,
    9,219,163,76,201,136,221,87,126,40,227,163,200,125,42,163,
    36,29,61,77,124,169,54,167,158,63,246,253,212,241,226,190,
    116,95,73,42,180,234,246,52,65,94,101,53,143,130,202,190,
    80,134,73,218,115,178,104,34,124,168,239,189,184,83,60,255,
    252,73,152,116,15,165,159,211,92,108,21,166,249,77,18,121,
    184,126,241,46,237,160,216,101,121,234,185,159,210,91,171,83,
    171,153,76,3,47,12,190,149,5,192,121,153,175,122,167,25,
    146,3,199,191,184,142,50,183,2,117,140,247,84,246,3,244,
    71,202,12,198,196,121,138,251,244,29,113,88,126,113,246,161,
    161,187,79,125,12,126,68,215,44,217,51,28,232,78,172,182,
    84,19,85,131,18,159,137,199,208,69,97,153,141,102,205,106,
    44,212,172,218,156,201,151,26,139,120,188,168,91,181,133,134,
    184,248,223,22,6,88,221,216,90,172,137,255,0,23,105,199,
    172,
};

EmbeddedPython embedded_m5_internal_param_Platform(
    "m5/internal/param_Platform.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_Platform.py",
    "m5.internal.param_Platform",
    data_m5_internal_param_Platform,
    2273,
    6687);

} // anonymous namespace
