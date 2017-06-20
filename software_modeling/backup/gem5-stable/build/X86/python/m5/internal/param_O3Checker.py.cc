#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_O3Checker[] = {
    120,156,189,88,109,111,27,199,17,158,189,59,82,34,37,89,
    178,101,73,126,145,45,58,137,99,198,141,197,216,137,227,0,
    113,220,202,78,10,56,136,101,245,232,192,142,18,244,122,186,
    91,73,71,29,239,136,187,149,109,6,18,90,68,70,155,2,
    5,242,169,253,7,253,208,127,211,127,212,206,204,222,29,79,
    148,84,164,104,41,153,92,15,247,101,118,94,158,153,157,93,
    15,178,191,10,126,127,213,0,72,35,3,192,199,143,128,16,
    160,43,96,93,128,144,2,252,243,176,83,129,228,35,240,43,
    240,6,96,221,0,105,192,1,18,38,124,107,64,52,201,107,
    170,16,154,220,35,160,95,7,105,193,122,5,158,71,103,193,
    146,85,216,169,67,242,59,16,66,68,2,94,248,99,224,143,
    195,27,228,142,68,141,25,142,3,117,214,185,179,6,254,4,
    119,214,193,159,100,98,2,250,51,32,39,97,125,138,166,173,
    159,65,182,55,145,237,52,179,253,39,177,245,113,100,14,252,
    51,52,29,229,250,134,102,90,52,147,247,155,102,46,51,185,
    148,103,97,253,92,78,207,150,232,243,37,122,174,68,207,151,
    232,133,18,125,161,68,95,44,209,151,74,244,229,18,189,88,
    162,175,148,232,171,37,122,169,68,55,74,244,181,18,253,86,
    137,126,187,68,191,83,162,175,151,232,119,75,244,141,18,221,
    44,209,239,149,232,155,76,163,197,207,65,231,23,208,121,31,
    58,183,96,19,65,112,182,176,238,50,72,19,58,45,88,111,
    129,196,207,50,28,32,78,252,115,165,21,31,240,138,217,98,
    197,109,94,113,7,214,239,128,196,207,109,189,162,10,237,230,
    60,98,47,248,23,254,53,5,82,106,18,155,151,50,73,131,
    56,114,130,104,51,14,12,26,175,82,67,72,245,168,25,203,
    32,251,136,32,251,15,96,188,250,70,6,217,125,64,198,130,
    116,9,13,216,103,98,223,128,126,19,246,4,116,44,240,77,
    216,195,109,42,36,192,150,128,3,3,190,51,105,194,62,182,
    22,2,235,42,88,74,227,181,195,192,210,156,198,96,191,2,
    123,21,104,191,216,51,168,99,167,6,201,223,225,251,69,102,
    58,206,76,13,216,195,214,130,3,11,246,171,240,28,39,97,
    87,167,70,234,139,23,123,168,41,246,180,155,22,74,187,90,
    82,151,84,241,131,36,114,187,82,205,32,237,244,220,196,237,
    58,79,63,124,180,45,189,29,153,52,235,249,172,56,93,238,
    185,106,219,230,101,38,217,163,219,83,204,46,142,164,154,64,
    98,51,136,124,167,27,251,187,161,84,227,196,203,217,12,66,
    233,56,60,248,184,219,139,19,245,69,146,196,137,77,38,229,
    206,48,118,139,21,100,80,47,140,83,217,164,221,120,27,155,
    216,43,154,189,217,99,142,36,0,139,74,139,125,153,122,73,
    208,83,232,41,205,145,102,19,183,38,249,136,155,244,41,54,
    173,237,184,43,91,59,178,219,149,137,188,211,218,146,221,187,
    220,220,74,149,187,17,202,214,198,110,16,250,173,23,159,124,
    220,234,245,213,118,28,181,112,60,136,148,68,163,132,173,33,
    115,44,227,148,115,196,248,85,176,229,4,172,146,179,45,195,
    158,76,166,168,247,18,109,42,102,196,164,168,10,83,52,197,
    20,82,21,252,154,98,209,152,16,171,1,41,229,145,162,132,
    39,171,140,32,114,171,128,29,3,146,69,194,71,7,63,130,
    28,138,40,105,211,152,193,99,191,33,107,232,222,142,73,94,
    215,157,123,140,41,4,23,206,188,79,110,142,128,129,81,129,
    78,21,52,96,16,103,26,65,73,159,90,156,78,108,12,100,
    110,65,250,87,64,235,34,84,246,32,131,209,129,9,34,154,
    1,85,167,44,134,189,243,184,225,15,140,196,118,147,196,95,
    101,68,168,237,32,141,95,69,108,119,162,57,118,218,104,153,
    181,254,211,141,142,244,84,186,132,29,223,196,187,13,207,141,
    162,88,53,92,223,111,184,74,37,193,198,174,146,105,67,197,
    141,235,105,147,92,105,159,205,65,85,240,235,247,114,16,145,
    195,17,68,250,135,31,120,10,127,204,242,15,246,66,42,21,
    2,98,59,246,83,236,39,22,91,82,217,36,164,34,35,199,
    44,8,227,197,161,169,180,61,206,59,131,191,87,114,73,24,
    148,205,106,14,161,84,134,155,170,206,104,116,211,212,97,73,
    168,159,129,71,140,95,186,225,174,100,238,136,32,133,2,17,
    169,101,24,49,244,46,144,26,185,214,172,74,20,71,126,31,
    37,11,188,27,180,233,5,6,224,36,67,112,14,225,55,134,
    109,21,255,175,138,121,195,179,50,208,85,115,224,81,234,83,
    192,110,23,153,231,17,132,7,152,102,154,6,231,9,214,134,
    35,241,45,162,104,177,189,72,205,21,106,174,82,179,148,43,
    60,58,173,167,134,181,190,71,59,25,172,42,43,69,78,49,
    115,165,252,67,209,116,113,16,77,152,8,219,20,21,6,197,
    206,32,42,44,74,154,201,3,106,113,42,199,155,9,233,51,
    74,209,20,61,204,140,2,5,33,79,212,32,16,216,68,54,
    37,205,230,120,142,97,155,128,89,70,231,86,9,157,54,121,
    135,161,105,95,204,51,160,67,51,52,40,237,203,196,170,114,
    140,141,27,212,92,27,189,161,7,240,218,58,2,175,79,105,
    211,153,12,94,83,12,171,58,126,103,12,207,204,172,95,156,
    136,179,67,176,34,76,89,199,96,234,93,162,204,163,250,158,
    26,156,50,45,127,93,130,19,9,102,148,149,89,69,162,191,
    64,58,148,129,180,128,7,251,243,104,1,207,106,131,207,234,
    15,248,172,230,243,158,43,62,157,144,77,206,201,154,168,144,
    49,54,77,152,207,206,224,180,134,109,47,137,95,247,27,241,
    102,67,177,182,148,63,239,95,79,151,175,167,159,98,102,108,
    60,224,156,164,115,163,206,126,137,236,81,246,162,165,95,188,
    246,36,159,125,252,203,113,116,178,114,56,113,57,217,153,138,
    152,154,35,83,26,185,141,57,109,167,42,161,108,61,98,43,
    215,11,43,147,208,95,210,54,117,54,177,41,22,16,63,117,
    193,178,56,58,63,115,85,197,163,248,125,72,102,39,125,37,
    80,253,111,183,181,164,172,4,169,99,191,127,8,35,35,83,
    193,110,33,207,175,115,108,84,7,216,160,175,153,3,253,79,
    192,149,166,128,63,2,121,31,157,156,1,189,136,11,114,247,
    44,77,255,45,112,68,28,115,206,115,94,105,211,217,206,51,
    48,221,164,247,120,170,62,246,191,132,31,75,225,148,31,206,
    102,86,75,150,15,103,171,200,73,12,155,159,117,0,91,135,
    147,23,185,101,219,77,105,154,206,72,131,8,29,36,252,162,
    8,196,140,60,58,12,141,235,13,28,146,229,187,1,130,232,
    120,187,44,102,141,18,46,110,83,115,167,128,132,200,251,70,
    34,214,18,156,124,10,59,58,219,127,75,123,91,44,237,244,
    24,71,104,193,161,192,122,37,199,250,157,2,235,146,79,165,
    55,124,161,160,214,32,23,31,24,2,111,181,88,136,209,37,
    210,2,89,129,245,42,69,5,23,204,34,11,26,145,231,43,
    202,110,135,142,60,54,198,170,54,83,225,101,237,64,106,94,
    143,56,15,144,15,239,135,110,119,195,119,31,252,129,54,161,
    157,188,60,140,140,92,236,153,178,216,20,2,226,36,201,249,
    231,221,92,252,151,35,206,1,31,35,207,66,108,70,188,31,
    123,28,248,207,182,101,163,43,187,27,120,87,220,14,122,141,
    205,208,221,98,111,152,153,90,79,115,181,20,187,115,184,112,
    72,111,82,27,55,188,56,194,132,188,235,169,56,105,248,18,
    175,80,210,111,220,106,112,54,111,4,105,195,221,192,81,215,
    83,26,210,135,227,145,171,82,55,217,74,185,0,221,121,69,
    228,41,120,211,193,123,113,128,69,248,15,80,28,155,250,202,
    86,36,103,46,175,117,132,224,9,135,151,35,213,215,57,137,
    138,8,123,153,154,247,224,116,114,248,71,200,243,247,196,156,
    76,84,21,151,141,154,161,166,203,225,184,70,107,210,163,65,
    249,228,231,4,165,126,100,202,66,179,154,191,78,141,129,228,
    235,20,61,32,85,179,7,36,140,215,177,255,53,94,25,245,
    167,128,247,63,255,95,195,212,190,119,202,82,219,159,64,118,
    54,159,20,162,162,172,210,148,14,209,142,200,203,255,178,62,
    252,174,48,127,20,47,142,151,72,87,73,237,150,197,145,43,
    200,1,174,183,252,203,32,234,142,22,171,43,133,46,7,92,
    141,244,207,179,183,244,141,135,189,37,158,71,151,176,106,181,
    184,106,189,79,85,235,30,43,238,24,186,112,29,0,176,82,
    232,79,166,140,228,43,103,200,6,186,48,37,201,220,94,79,
    70,190,125,19,202,181,38,15,143,216,239,148,79,126,130,82,
    97,96,138,243,88,92,30,141,50,202,148,37,221,216,109,149,
    34,174,70,239,64,70,232,223,114,132,54,169,208,31,164,75,
    251,62,53,156,32,139,220,104,255,18,242,124,89,96,208,151,
    161,84,114,216,13,250,217,78,103,91,95,226,105,17,247,241,
    26,192,197,53,254,14,29,231,52,210,236,103,200,243,71,200,
    174,48,152,102,69,213,168,153,181,106,77,240,105,53,244,134,
    170,101,249,16,242,18,178,159,218,28,183,211,133,182,252,214,
    151,159,28,100,29,46,161,86,221,174,126,171,225,215,8,251,
    109,200,238,144,246,141,194,116,116,175,230,186,93,223,138,16,
    181,124,146,242,193,105,243,142,228,235,238,221,229,92,153,101,
    173,76,166,202,163,181,175,249,185,177,123,87,93,60,118,222,
    67,55,149,52,233,194,177,163,104,175,103,95,61,84,239,156,
    52,184,230,210,141,19,237,251,220,13,113,183,19,184,180,251,
    169,146,93,117,121,104,80,70,187,93,231,137,236,198,73,255,
    73,236,203,35,138,172,248,126,98,187,209,150,116,94,74,170,
    38,212,181,225,9,89,41,161,121,228,179,26,199,202,112,120,
    238,17,89,244,36,28,212,239,124,92,17,31,99,212,48,70,
    163,250,217,156,43,39,207,249,60,238,186,216,127,252,46,237,
    32,223,229,236,208,184,159,208,170,185,161,222,84,38,129,27,
    6,223,203,255,224,66,242,210,213,147,188,244,85,236,185,225,
    74,47,240,78,176,13,50,8,188,181,32,254,92,190,12,60,
    121,130,212,131,241,97,41,112,135,199,237,149,220,252,39,2,
    9,231,168,75,67,131,143,226,93,34,243,181,199,67,249,49,
    214,147,207,208,119,136,175,225,245,107,73,236,201,52,205,215,
    31,111,159,108,18,199,96,62,196,57,230,72,164,80,210,29,
    252,228,82,235,240,89,201,73,41,145,91,1,2,58,97,30,
    131,233,217,25,242,89,30,147,195,7,108,121,233,41,100,48,
    125,79,209,207,38,15,232,97,46,197,26,7,232,25,181,54,
    93,195,108,70,71,139,41,234,120,184,88,230,228,76,205,154,
    156,168,89,181,49,147,95,193,166,240,46,90,183,106,19,147,
    226,191,253,183,132,25,178,110,44,225,14,255,6,109,62,122,
    196,
};

EmbeddedPython embedded_m5_internal_param_O3Checker(
    "m5/internal/param_O3Checker.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_O3Checker.py",
    "m5.internal.param_O3Checker",
    data_m5_internal_param_O3Checker,
    2433,
    7435);

} // anonymous namespace
