#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_AtomicSimpleCPU[] = {
    120,156,197,89,235,83,28,199,17,239,217,221,59,184,3,4,
    136,151,30,88,156,228,200,58,43,22,232,25,165,202,138,18,
    164,56,85,118,69,152,236,73,37,25,187,178,89,110,7,216,
    99,31,87,187,131,164,115,193,135,24,149,147,74,170,242,205,
    223,252,37,31,242,33,255,77,254,163,164,187,247,193,0,119,
    21,57,137,46,192,141,250,230,209,211,143,95,247,244,140,218,
    144,255,84,240,243,139,6,64,250,173,1,224,225,159,128,0,
    32,20,176,33,64,72,1,222,44,236,86,32,185,11,94,5,
    222,0,108,24,32,13,56,68,194,132,47,13,136,198,121,77,
    21,2,147,123,4,244,234,32,45,216,168,192,243,104,26,44,
    89,133,221,58,36,191,3,33,68,36,224,133,55,2,222,40,
    188,65,238,72,212,152,225,40,80,103,157,59,107,224,141,113,
    103,29,188,113,38,198,160,55,5,114,28,54,38,104,218,198,
    25,100,123,29,217,78,50,219,127,16,91,15,71,230,192,59,
    67,211,81,174,47,104,166,69,51,121,191,73,230,50,85,72,
    57,13,27,103,11,122,70,163,103,53,122,78,163,231,53,122,
    65,163,207,105,244,121,141,190,160,209,23,53,122,81,163,223,
    211,232,75,26,189,164,209,13,141,190,172,209,87,52,250,125,
    141,254,145,70,95,213,232,15,52,250,154,70,55,53,250,67,
    141,190,174,209,63,214,232,143,152,70,79,156,133,206,13,232,
    44,67,103,5,182,16,28,211,165,213,111,130,52,161,115,11,
    54,110,129,196,191,155,112,136,248,241,206,106,43,110,243,138,
    153,114,197,29,94,113,23,54,238,130,196,191,59,217,138,42,
    180,154,243,136,73,255,159,248,211,20,72,169,113,108,94,202,
    36,245,227,200,241,163,173,216,55,104,188,74,13,33,184,77,
    205,72,14,229,199,4,229,191,3,227,216,51,114,40,31,0,
    50,22,164,75,96,192,1,19,7,6,244,154,176,47,160,99,
    129,103,194,62,110,83,33,1,182,5,28,26,240,149,73,19,
    14,176,181,16,112,151,192,82,25,142,59,12,184,140,211,8,
    28,84,96,191,2,173,23,251,6,117,236,214,32,249,27,124,
    189,200,76,71,153,169,1,251,216,90,112,104,193,65,21,158,
    227,36,236,234,212,72,125,241,98,31,53,197,158,86,211,66,
    105,215,52,117,73,21,207,79,34,55,148,138,44,225,116,221,
    196,13,157,85,21,135,126,187,229,135,221,64,62,94,127,214,
    172,23,115,227,116,185,235,170,29,155,23,155,100,149,176,171,
    152,105,28,73,53,134,196,150,31,121,78,24,123,123,129,84,
    163,196,209,217,242,3,233,56,60,248,105,216,141,19,245,73,
    146,196,137,77,134,229,206,32,118,203,21,100,214,118,16,167,
    178,73,187,241,54,54,177,87,52,123,171,203,28,73,0,22,
    152,22,123,50,109,39,126,87,161,191,50,142,52,155,184,53,
    201,83,220,164,207,176,89,217,137,67,185,178,43,195,80,38,
    242,246,202,182,12,239,113,115,35,85,238,102,32,87,54,247,
    252,192,91,89,181,159,172,116,123,106,39,142,86,112,220,143,
    148,68,211,4,43,125,141,178,140,19,207,18,251,87,254,182,
    227,179,98,206,142,12,186,50,153,160,222,11,180,181,152,18,
    227,162,42,76,209,20,19,72,85,240,99,138,69,99,76,172,
    249,164,90,155,212,37,108,89,58,154,200,197,2,118,13,72,
    22,9,43,29,252,19,228,92,68,76,139,198,12,30,251,13,
    217,36,235,237,152,132,128,172,115,159,241,133,64,195,153,15,
    200,229,17,48,72,42,208,169,66,6,30,196,92,134,166,164,
    71,45,78,39,54,6,50,183,32,253,14,208,198,8,155,125,
    200,33,117,104,130,136,166,64,213,41,211,97,239,60,110,248,
    13,163,178,213,36,241,215,24,23,106,199,79,227,87,17,91,
    159,104,142,163,22,90,102,189,247,249,102,71,182,85,186,132,
    29,95,196,123,141,182,27,69,177,106,184,158,215,112,149,74,
    252,205,61,37,211,134,138,27,87,211,38,57,212,158,46,160,
    85,242,235,117,11,40,145,219,17,74,217,23,207,111,43,252,
    50,195,95,216,11,169,84,8,139,157,216,75,177,159,88,108,
    75,101,147,144,138,140,28,179,32,140,26,135,166,210,246,56,
    239,12,126,95,45,36,97,104,54,171,5,144,82,25,108,169,
    58,99,210,77,83,135,37,161,126,134,31,49,126,233,6,123,
    146,185,35,142,20,10,68,100,38,195,80,0,120,142,148,41,
    116,103,133,162,56,242,122,40,159,223,190,70,91,159,99,24,
    142,51,16,231,16,132,35,216,86,241,223,170,152,55,218,86,
    14,189,106,1,63,74,1,10,216,249,34,247,63,66,241,16,
    19,79,211,224,204,193,58,113,84,94,33,138,22,219,139,212,
    188,71,205,37,106,150,10,181,223,181,238,19,39,117,191,79,
    251,25,172,48,171,70,14,50,11,213,188,99,145,117,254,40,
    178,48,65,182,40,66,12,138,163,163,8,177,40,153,38,15,
    169,197,169,28,123,38,164,79,41,117,83,36,49,51,10,26,
    132,63,81,71,65,193,134,178,167,200,0,163,5,158,109,2,
    169,142,212,109,13,169,54,249,136,97,106,159,47,114,162,67,
    51,50,128,218,23,137,85,165,143,165,27,212,92,30,150,185,
    143,160,182,125,10,106,31,211,214,83,57,212,38,24,98,117,
    252,76,25,109,51,247,65,121,94,206,156,128,24,225,203,234,
    131,175,15,136,50,79,107,61,100,104,229,186,254,74,131,22,
    137,103,232,42,173,33,209,91,32,77,116,80,45,224,225,255,
    60,90,192,243,220,224,243,252,38,159,231,92,19,112,181,152,
    37,106,147,115,117,70,84,200,36,91,38,204,231,231,116,90,
    195,182,155,196,175,123,141,120,171,161,88,103,202,171,15,174,
    166,203,87,211,143,49,99,54,30,114,174,202,114,102,150,21,
    19,217,165,172,70,75,63,121,221,150,124,50,242,55,199,201,
    146,152,195,9,205,201,79,92,196,215,28,25,212,40,44,205,
    233,60,85,9,101,241,161,216,186,94,218,154,68,255,140,54,
    171,179,161,77,177,128,88,170,11,150,200,201,178,55,215,95,
    60,138,159,71,100,124,210,90,2,221,32,236,86,38,47,171,
    66,74,217,31,29,195,203,59,86,196,94,65,206,207,10,156,
    84,143,112,66,31,179,128,254,31,128,43,83,1,223,2,33,
    1,29,158,67,191,140,20,114,253,12,77,255,45,112,140,244,
    169,5,56,223,180,232,252,231,25,152,134,210,251,60,53,43,
    13,62,131,63,106,1,86,28,224,102,94,123,234,7,184,85,
    230,42,134,208,91,29,210,214,241,164,70,206,217,113,83,154,
    150,101,170,163,152,61,58,14,202,114,17,51,245,187,198,211,
    104,182,141,67,18,125,117,132,38,58,2,47,138,25,67,195,
    200,45,106,110,151,240,16,69,223,59,20,110,9,6,159,215,
    78,118,34,124,73,18,88,44,243,228,136,154,4,170,78,142,
    241,41,99,160,82,196,192,237,50,6,36,159,95,111,248,74,
    66,173,65,78,63,52,4,222,151,177,124,163,235,169,5,178,
    2,27,85,138,22,46,182,69,30,76,162,200,102,148,251,142,
    29,142,108,152,181,204,100,165,223,51,151,82,243,122,40,89,
    130,188,250,32,112,195,77,207,125,248,13,109,69,251,181,139,
    240,50,10,225,167,116,225,41,52,196,32,249,249,235,189,66,
    137,151,67,201,16,63,65,206,165,240,28,15,94,220,230,180,
    240,116,71,54,66,25,110,226,205,115,199,239,54,182,2,119,
    155,61,99,230,202,125,94,40,167,216,181,39,203,141,244,58,
    181,113,163,29,71,152,186,247,218,42,78,26,158,196,171,152,
    244,26,55,26,156,247,27,126,218,112,55,113,212,109,171,12,
    234,199,163,149,235,90,55,217,78,185,132,221,125,69,228,208,
    60,235,224,93,219,199,98,254,13,148,199,108,118,1,44,211,
    56,151,233,89,228,224,137,136,151,44,213,203,242,22,149,30,
    246,50,53,31,194,48,179,253,93,228,252,123,218,130,204,85,
    21,23,141,154,161,230,78,7,235,58,173,79,79,135,236,95,
    223,38,100,179,199,173,60,112,171,52,83,142,208,125,159,218,
    26,165,253,141,122,209,57,198,237,56,119,78,20,157,103,184,
    157,228,206,169,162,115,154,219,179,220,57,83,188,180,205,114,
    231,28,108,204,211,19,12,245,44,80,134,24,249,111,51,4,
    71,216,208,98,235,207,255,211,196,96,223,255,191,200,110,255,
    20,242,90,97,80,82,16,186,98,19,89,82,232,136,226,154,
    162,107,197,47,34,139,131,80,233,180,19,233,42,153,57,106,
    113,72,202,114,122,201,54,254,203,81,180,159,46,170,87,75,
    189,14,185,82,234,205,178,255,178,91,26,251,79,60,143,46,
    96,117,109,113,117,253,128,170,235,125,54,130,99,100,5,246,
    17,48,43,165,45,232,130,21,201,87,39,229,202,236,145,149,
    209,36,159,219,237,202,200,179,175,131,94,25,243,240,80,240,
    64,57,237,59,208,74,23,83,204,98,41,124,58,18,41,103,
    107,122,178,35,43,101,236,13,203,165,140,223,239,11,252,54,
    249,58,91,38,110,251,1,53,156,170,203,44,109,255,188,116,
    200,229,129,224,220,114,83,188,35,135,116,3,123,139,89,88,
    78,113,41,154,127,87,203,3,87,164,126,184,23,32,250,28,
    207,85,174,131,122,7,65,202,155,252,192,37,180,227,44,41,
    221,103,240,109,120,249,120,84,255,192,237,245,37,167,182,215,
    6,185,204,236,207,235,149,239,169,29,222,239,223,205,161,13,
    8,75,252,141,33,201,153,196,147,129,196,221,250,174,84,228,
    230,252,133,195,147,88,107,196,61,188,110,242,245,13,191,7,
    142,51,188,227,249,103,200,249,79,180,5,217,8,143,103,81,
    197,3,122,78,240,175,81,171,214,4,87,62,39,94,247,51,
    201,184,40,228,203,74,47,181,57,35,79,150,112,229,247,231,
    162,254,32,100,243,213,122,205,13,179,151,67,126,21,179,223,
    135,252,253,194,190,86,194,158,18,15,223,16,179,187,56,230,
    32,174,202,184,8,179,239,80,63,249,35,188,183,92,168,182,
    156,169,246,200,77,101,169,24,191,130,135,247,56,28,250,76,
    77,220,168,189,179,158,72,122,24,141,19,117,177,239,44,100,
    150,189,200,170,233,19,227,94,226,34,61,119,162,55,149,137,
    239,6,254,215,146,115,103,127,1,73,180,75,125,71,87,147,
    176,165,220,109,121,251,201,147,103,252,130,212,119,202,211,95,
    63,82,141,129,131,132,130,231,110,176,139,54,239,207,161,213,
    75,21,134,252,73,125,101,180,23,58,79,100,24,39,189,39,
    177,39,25,189,250,248,170,231,37,182,27,109,75,231,165,100,
    131,157,52,235,106,94,46,103,60,138,89,3,4,61,54,119,
    128,237,113,48,183,125,127,103,63,14,226,246,174,244,242,57,
    239,13,158,243,203,56,36,95,245,231,130,54,251,148,122,146,
    189,174,74,79,121,141,70,91,171,133,50,3,93,130,115,6,
    15,174,163,51,47,244,29,92,199,84,180,21,39,225,0,225,
    81,174,228,113,140,77,28,156,98,240,56,222,35,178,144,236,
    164,183,10,6,169,122,138,118,70,44,156,92,191,158,196,109,
    153,166,197,250,254,104,205,39,113,28,23,67,252,46,219,47,
    218,168,180,58,214,195,69,127,191,122,138,83,94,34,183,125,
    4,98,194,252,142,173,203,203,11,202,73,234,202,224,52,175,
    241,24,90,162,204,46,214,217,91,224,67,122,121,78,35,108,
    232,127,11,106,147,53,76,154,84,123,152,162,142,213,135,101,
    142,79,213,172,241,177,154,85,27,49,249,129,119,66,204,24,
    117,171,54,54,46,254,147,223,37,76,194,117,99,105,166,38,
    254,5,151,210,138,108,
};

EmbeddedPython embedded_m5_internal_param_AtomicSimpleCPU(
    "m5/internal/param_AtomicSimpleCPU.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_AtomicSimpleCPU.py",
    "m5.internal.param_AtomicSimpleCPU",
    data_m5_internal_param_AtomicSimpleCPU,
    2598,
    8224);

} // anonymous namespace
