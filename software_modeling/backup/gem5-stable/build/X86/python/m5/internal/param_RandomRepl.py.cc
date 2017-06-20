#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_RandomRepl[] = {
    120,156,189,88,235,114,220,72,21,62,45,105,198,158,177,29,
    143,227,91,18,59,177,128,10,59,164,88,27,194,102,179,85,
    107,2,217,11,85,108,21,222,160,9,149,172,119,11,33,75,
    61,182,198,186,76,73,237,56,147,178,255,224,20,240,2,240,
    6,252,224,109,120,35,56,231,180,164,145,111,85,91,5,99,
    103,212,105,181,186,79,159,203,119,46,221,62,20,127,13,124,
    126,109,3,228,255,16,0,1,254,4,68,0,177,128,93,1,
    66,10,8,150,224,176,1,217,71,16,52,224,61,192,174,1,
    210,128,51,236,152,240,173,1,201,44,175,105,66,100,242,136,
    128,81,27,164,5,187,13,120,149,44,128,37,155,112,216,134,
    236,79,32,132,72,4,188,14,166,32,152,134,247,72,29,59,
    45,38,56,13,52,216,230,193,22,4,51,60,216,134,96,150,
    59,51,48,234,128,156,133,221,57,154,182,123,11,201,62,66,
    178,243,76,246,223,68,54,192,47,203,16,220,162,233,200,215,
    55,52,211,162,153,188,223,60,83,233,148,92,46,192,238,237,
    178,191,88,235,47,213,250,203,181,254,74,173,191,90,235,223,
    225,62,114,118,27,6,119,97,112,15,6,107,208,71,101,45,
    84,92,172,131,52,97,112,31,118,239,131,196,223,58,156,161,
    62,131,219,181,21,15,120,197,98,181,98,131,87,216,176,107,
    131,196,223,134,94,209,132,94,119,5,109,20,254,7,255,186,
    104,35,80,179,216,188,145,89,30,166,137,27,38,253,52,52,
    232,123,147,26,178,168,79,205,84,97,218,207,201,180,255,2,
    182,107,96,20,166,61,5,36,44,72,150,200,128,83,238,156,
    26,48,234,194,137,128,129,5,129,9,39,184,77,131,24,216,
    23,112,102,192,119,38,77,56,197,214,66,3,60,0,75,105,
    187,14,216,0,154,210,20,156,54,224,164,1,189,215,39,6,
    13,28,182,32,251,39,188,91,103,162,211,76,212,128,19,108,
    45,56,179,224,180,9,175,112,18,14,13,90,36,190,120,125,
    130,146,226,72,175,107,33,183,59,53,113,73,148,32,204,18,
    47,150,106,1,251,238,208,203,188,216,117,188,36,72,99,71,
    14,163,110,187,156,150,230,155,67,79,29,56,188,206,36,133,
    196,67,197,244,210,68,170,25,236,244,195,36,112,227,52,56,
    138,164,154,38,98,110,63,140,164,235,242,199,223,198,195,52,
    83,95,102,89,154,57,164,83,30,140,82,175,90,65,26,245,
    163,52,151,93,218,141,183,113,136,188,162,217,253,33,83,36,
    6,152,87,90,28,200,220,207,194,161,66,83,105,138,52,155,
    168,117,201,72,220,228,47,176,217,58,72,99,185,117,40,227,
    88,102,242,241,214,190,140,159,112,243,97,174,188,189,72,110,
    237,29,133,81,176,245,250,147,143,183,134,35,117,144,38,91,
    248,61,76,148,68,173,68,91,23,245,177,137,115,110,19,229,
    227,112,223,13,89,38,247,64,70,67,153,205,209,232,61,218,
    85,116,196,172,104,10,83,116,197,28,246,26,248,152,98,221,
    152,17,59,33,73,229,147,164,132,40,171,142,33,50,172,128,
    67,3,178,117,66,200,0,127,130,76,138,56,233,209,55,131,
    191,253,158,212,161,71,7,38,217,93,15,158,48,170,16,94,
    56,115,155,12,157,0,67,163,1,131,38,104,200,32,210,52,
    134,178,17,181,56,157,200,24,72,220,130,252,239,128,234,69,
    176,156,64,1,164,51,19,68,210,1,213,38,127,199,209,21,
    220,240,207,140,197,94,151,216,223,97,72,168,131,48,79,143,
    19,86,60,245,217,123,122,168,153,23,163,175,247,6,210,87,
    249,6,14,124,147,30,217,190,151,36,169,178,189,32,176,61,
    165,178,112,239,72,201,220,86,169,253,48,239,146,45,157,133,
    18,85,21,189,209,176,68,17,89,28,81,164,95,130,208,87,
    248,178,200,47,108,133,92,42,68,196,65,26,228,56,78,36,
    246,165,114,136,73,69,74,78,153,17,6,140,75,83,105,123,
    156,119,11,223,159,151,156,48,42,187,205,18,67,185,140,250,
    170,205,112,244,242,220,101,78,104,156,145,71,132,223,120,209,
    145,100,234,8,33,133,12,81,87,243,48,105,236,221,33,57,
    74,177,89,150,36,77,130,17,178,22,250,31,208,174,119,24,
    129,179,140,193,101,196,223,20,182,77,252,191,41,86,12,223,
    42,80,215,44,145,71,209,79,1,219,93,20,166,71,20,158,
    97,164,233,26,28,42,88,28,246,197,31,82,143,22,59,235,
    212,220,167,230,1,53,27,165,196,19,20,123,238,162,216,79,
    105,43,131,101,101,169,200,44,102,41,85,112,206,159,238,142,
    253,9,131,97,143,252,194,32,239,25,251,133,69,129,51,123,
    70,45,78,101,143,51,33,127,73,97,154,252,135,137,145,171,
    32,232,169,55,118,5,214,145,211,33,217,167,75,20,59,4,
    205,58,62,247,107,248,116,200,60,12,78,231,110,25,4,93,
    154,161,97,233,172,17,169,198,21,74,182,169,249,193,13,104,
    122,12,176,253,75,0,251,148,118,237,20,0,155,99,96,181,
    241,233,24,190,89,168,191,74,139,139,23,128,69,168,178,174,
    64,213,143,169,103,94,22,248,230,0,85,136,249,155,26,160,
    136,51,163,46,205,14,118,70,171,36,68,29,74,171,152,222,
    95,37,171,152,177,13,206,216,63,227,140,205,89,159,235,35,
    29,148,77,142,203,186,211,32,109,244,77,88,41,50,113,222,
    194,118,152,165,111,71,118,218,183,21,139,75,49,116,251,97,
    190,249,48,255,20,163,163,253,140,227,146,142,143,58,2,102,
    114,72,17,140,150,126,249,214,151,156,0,249,205,117,117,192,
    114,57,120,185,69,98,69,84,45,147,46,141,82,201,28,186,
    115,149,81,196,158,180,154,219,149,154,137,235,175,104,159,54,
    235,216,20,171,136,160,182,96,102,92,29,164,185,184,226,175,
    248,124,70,122,39,129,37,80,185,236,244,52,171,44,5,201,
    227,252,244,28,74,38,39,131,179,133,68,255,80,162,163,57,
    70,7,61,102,137,245,191,2,87,156,2,254,2,100,127,52,
    115,129,245,202,53,200,224,139,52,253,143,192,78,113,69,182,
    231,216,210,163,12,207,51,48,228,228,79,121,170,78,254,95,
    193,223,106,30,85,166,104,179,168,41,235,41,218,170,226,18,
    3,231,123,165,97,235,124,0,35,187,28,120,57,77,211,81,
    105,236,164,227,168,95,213,130,24,149,39,136,162,105,189,131,
    75,204,124,55,198,16,37,185,53,177,104,212,144,241,115,106,
    30,87,160,16,229,216,100,248,218,128,235,147,177,171,99,254,
    183,180,185,197,236,206,79,177,59,140,73,84,120,111,148,120,
    127,92,225,93,114,114,122,207,103,11,106,13,178,242,153,33,
    240,32,136,21,25,157,187,44,144,13,216,109,146,103,112,233,
    44,10,199,17,101,208,162,16,119,46,243,177,58,118,180,162,
    42,67,107,27,82,243,118,210,193,128,204,184,29,121,241,94,
    224,61,75,104,23,218,202,47,93,201,40,249,238,212,249,38,
    55,16,215,177,206,175,79,74,254,223,76,58,16,124,140,68,
    43,190,25,246,65,234,179,247,191,60,144,118,44,227,61,60,
    56,30,132,67,187,31,121,251,108,15,179,144,235,235,82,46,
    197,6,189,88,65,228,143,168,77,109,63,77,48,46,31,249,
    42,205,236,64,226,113,74,6,246,135,54,7,117,59,204,109,
    111,15,191,122,190,210,176,62,239,148,92,160,122,217,126,206,
    181,232,225,49,117,111,194,158,46,158,146,67,44,200,135,80,
    165,79,125,126,171,98,52,151,218,218,75,48,211,225,65,73,
    141,116,100,162,106,194,217,164,230,39,112,67,161,252,35,36,
    26,19,117,82,82,83,172,25,45,67,117,206,249,228,11,90,
    149,95,246,204,223,125,31,207,212,151,51,133,127,54,203,91,
    157,41,144,124,184,162,139,151,102,113,241,130,78,59,245,191,
    58,45,35,255,38,48,127,252,127,245,85,231,233,77,179,237,
    124,2,69,150,190,206,79,69,93,166,57,237,167,3,81,30,
    6,234,2,241,69,195,234,21,144,113,253,76,122,74,106,203,
    172,79,94,68,246,115,189,231,187,177,239,93,46,93,159,87,
    210,156,113,101,50,90,98,131,233,19,16,27,76,188,74,238,
    97,13,107,113,13,187,77,53,236,9,139,238,26,186,140,29,
    131,176,81,105,96,137,66,161,60,118,47,106,65,215,169,196,
    154,55,28,202,36,112,30,65,189,244,228,207,147,182,61,197,
    149,83,168,85,9,166,88,194,90,243,178,175,81,200,172,73,
    199,150,107,84,222,117,3,54,100,152,190,47,97,218,165,202,
    127,28,55,157,109,106,56,58,85,65,210,249,21,148,129,179,
    2,98,32,35,169,228,37,75,112,92,43,78,160,129,196,196,
    145,142,240,96,192,213,54,190,71,174,123,35,1,247,151,72,
    244,13,20,167,26,12,184,162,105,180,204,86,179,37,56,115,
    93,184,92,213,204,208,33,87,215,148,163,220,97,247,157,175,
    228,229,59,192,50,137,144,126,248,220,179,227,197,250,10,135,
    239,40,156,31,65,113,174,116,62,168,148,71,135,109,46,228,
    245,65,9,161,203,89,149,147,168,243,11,26,167,162,54,126,
    178,89,74,179,169,165,249,204,203,101,79,170,231,121,158,250,
    124,17,25,63,81,247,174,157,249,210,195,252,187,113,229,231,
    207,163,212,63,148,129,190,22,83,247,175,159,243,69,26,123,
    56,190,118,229,140,94,24,23,20,22,46,124,15,50,90,181,
    124,97,52,151,89,232,69,225,59,125,147,86,14,243,5,230,
    21,242,145,141,234,3,156,46,47,4,59,6,84,38,247,195,
    28,105,49,161,250,138,34,8,144,213,89,198,75,65,178,190,
    250,38,0,168,107,78,125,16,126,70,151,45,57,157,243,233,
    110,172,53,223,66,48,82,112,48,241,24,58,39,44,115,182,
    211,178,102,103,90,86,107,202,228,139,141,57,60,90,180,173,
    214,204,172,168,255,219,64,240,182,141,13,92,253,95,128,42,
    170,130,
};

EmbeddedPython embedded_m5_internal_param_RandomRepl(
    "m5/internal/param_RandomRepl.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_RandomRepl.py",
    "m5.internal.param_RandomRepl",
    data_m5_internal_param_RandomRepl,
    2210,
    6631);

} // anonymous namespace
