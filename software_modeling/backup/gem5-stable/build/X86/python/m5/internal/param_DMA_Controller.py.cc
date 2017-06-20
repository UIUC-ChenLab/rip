#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_DMA_Controller[] = {
    120,156,197,89,221,115,219,198,17,223,3,64,74,164,36,235,
    91,178,45,217,162,147,200,102,61,141,212,186,113,156,25,187,
    110,93,59,153,105,102,172,164,160,91,59,76,166,40,4,156,
    36,80,32,192,2,39,219,204,72,237,76,228,233,199,91,95,
    242,7,244,161,15,253,111,250,215,244,181,221,221,3,64,72,
    162,18,207,184,102,45,241,124,92,44,246,246,227,183,123,123,
    39,15,178,127,21,252,252,188,1,144,254,91,0,248,248,43,
    32,4,232,10,104,11,16,82,128,191,0,251,21,72,62,0,
    191,2,175,0,218,6,72,3,142,113,98,194,151,6,68,147,
    252,78,21,66,147,41,2,250,117,144,22,180,43,240,52,154,
    5,75,86,97,191,14,201,239,64,8,17,9,120,230,143,129,
    63,14,175,80,58,78,106,44,112,28,136,88,103,98,13,252,
    9,38,214,193,159,228,201,4,244,103,64,78,66,123,138,216,
    218,23,80,236,77,20,59,205,98,255,69,98,125,124,178,8,
    254,5,98,71,189,190,32,78,139,56,121,189,105,150,50,147,
    107,57,11,237,185,124,62,95,154,47,148,230,139,165,249,82,
    105,190,92,154,95,44,205,47,149,230,151,75,243,149,210,124,
    181,52,191,82,154,95,45,205,215,74,243,6,207,209,242,57,
    232,92,131,206,59,208,121,23,118,48,24,179,133,149,239,129,
    52,161,179,14,237,117,144,248,251,30,28,99,188,252,185,210,
    27,215,249,141,249,226,141,27,252,70,19,218,77,144,248,123,
    67,191,81,133,86,115,9,49,16,252,7,255,53,17,3,160,
    38,113,120,46,147,52,136,35,39,136,118,226,192,160,231,85,
    26,8,49,30,13,99,25,116,30,18,116,254,9,140,27,223,
    200,160,115,4,40,88,144,45,161,1,71,60,57,50,160,223,
    132,67,1,29,11,124,19,14,113,153,10,41,176,43,224,216,
    128,175,76,98,56,194,209,194,0,95,5,75,105,220,116,56,
    192,90,210,24,28,85,224,176,2,173,103,135,6,17,246,107,
    144,252,3,190,94,101,161,227,44,212,128,67,28,45,56,182,
    224,168,10,79,145,9,73,157,26,153,47,158,29,162,165,72,
    105,53,45,212,118,171,100,46,153,226,7,73,228,118,165,90,
    196,185,211,115,19,183,235,60,122,252,192,121,24,71,42,137,
    195,80,38,205,122,206,26,167,27,61,87,237,217,252,174,73,
    78,233,246,20,203,140,35,169,38,112,178,19,68,190,211,141,
    253,131,80,170,113,18,232,236,4,161,116,28,126,248,203,110,
    47,78,212,199,73,18,39,54,249,149,137,97,236,22,111,144,
    87,189,48,78,101,147,86,227,101,108,18,175,136,123,167,199,
    18,73,1,214,151,94,246,101,234,37,65,79,97,184,180,68,
    226,38,105,77,10,20,15,233,19,28,54,247,226,174,220,220,
    151,221,174,76,228,173,205,93,217,189,205,195,251,169,114,183,
    67,185,185,125,16,132,254,230,179,143,62,220,236,245,213,94,
    28,109,226,243,32,82,18,61,19,110,14,243,201,6,242,205,
    145,244,23,193,174,19,176,93,206,158,12,123,50,153,34,234,
    101,90,89,204,136,73,81,21,166,104,138,41,156,85,240,99,
    138,85,99,66,108,5,100,153,71,214,18,178,172,50,150,40,
    192,2,246,13,72,86,9,41,29,252,21,20,90,196,75,139,
    158,25,252,236,87,228,18,77,237,152,20,127,77,60,100,116,
    33,204,144,243,30,5,60,2,134,72,5,58,85,208,208,65,
    196,105,44,37,125,26,145,157,196,24,40,220,130,244,91,64,
    23,35,104,14,33,3,212,177,9,34,154,1,85,167,186,130,
    212,37,92,240,27,198,100,171,73,234,111,49,44,212,94,144,
    198,47,34,118,62,205,57,139,90,232,153,207,251,159,109,119,
    164,167,210,53,36,124,17,31,52,60,55,138,98,213,112,125,
    191,225,42,149,4,219,7,74,166,13,21,55,214,211,38,197,
    211,158,205,145,85,200,235,247,114,36,81,212,17,73,250,139,
    31,120,10,191,204,243,23,142,66,42,21,162,98,47,246,83,
    164,147,136,93,169,108,82,82,145,147,99,86,132,65,227,16,
    43,45,143,124,23,240,251,131,92,19,70,102,179,154,227,40,
    149,225,142,170,51,36,221,52,117,88,19,162,51,250,72,240,
    115,55,60,144,44,29,97,164,80,33,154,106,29,70,129,191,
    139,100,75,110,58,219,19,197,145,223,71,245,2,239,6,173,
    124,145,81,56,201,56,92,68,12,142,225,88,197,255,171,98,
    201,240,172,12,121,213,28,125,84,9,21,112,236,69,22,126,
    68,226,49,86,157,166,193,101,131,77,226,156,124,135,102,244,
    178,189,74,195,21,26,174,210,176,150,91,253,150,77,159,58,
    109,250,29,90,206,96,123,217,50,10,143,153,91,230,159,200,
    171,75,131,188,194,226,216,162,252,48,40,139,6,249,97,81,
    33,77,238,211,136,172,156,121,38,25,163,116,30,177,48,74,
    25,4,63,205,6,41,193,126,178,103,200,254,241,28,205,54,
    65,180,140,211,221,18,78,109,10,17,131,212,190,148,23,68,
    135,56,52,60,237,21,18,85,25,226,232,6,13,215,70,228,
    237,1,208,118,207,0,237,46,173,60,147,1,109,138,1,86,
    199,207,140,225,153,89,8,138,173,114,254,20,192,8,93,214,
    16,116,93,167,153,121,214,232,209,2,43,51,245,147,18,176,
    72,59,163,108,209,22,78,250,203,100,72,25,82,203,184,237,
    63,141,150,113,39,55,120,39,255,17,239,228,220,13,112,95,
    166,139,180,201,117,90,79,42,228,145,29,19,150,178,29,58,
    173,225,216,75,226,151,253,70,188,211,80,108,50,213,212,123,
    235,233,198,122,122,23,171,101,227,62,215,41,93,47,117,69,
    76,100,143,42,26,189,250,241,75,79,242,166,200,223,28,71,
    23,48,135,139,153,147,109,182,136,46,218,241,217,251,236,104,
    46,229,169,74,168,130,143,194,213,245,194,213,164,249,167,180,
    86,157,253,108,138,101,68,82,93,176,66,142,46,220,220,120,
    241,83,252,252,130,124,79,70,75,160,86,221,110,105,117,217,
    18,178,201,254,225,9,180,188,93,59,236,77,20,252,235,28,
    37,213,1,74,232,99,230,184,255,51,112,71,42,224,79,64,
    56,192,112,103,184,47,210,132,2,63,79,236,191,5,78,144,
    33,93,0,215,154,22,237,252,204,129,37,40,189,195,172,186,
    41,248,20,254,82,202,174,124,235,54,179,158,179,188,117,91,
    69,157,98,0,189,214,246,108,157,44,104,20,155,61,55,37,
    54,93,165,6,9,59,216,9,138,62,17,171,244,91,70,211,
    184,94,197,33,133,190,26,96,137,54,191,21,49,111,148,16,
    242,99,26,110,21,224,16,57,237,237,233,182,6,231,111,212,
    142,222,11,190,36,5,44,86,121,122,140,187,146,147,98,10,
    252,87,114,252,223,42,240,47,121,227,122,197,231,16,26,13,
    138,248,177,33,240,80,138,93,27,157,1,45,144,21,104,87,
    41,83,184,197,22,89,34,137,188,144,81,217,59,177,43,178,
    91,182,180,195,138,160,235,120,210,240,114,20,5,130,66,122,
    47,116,187,219,190,123,255,57,173,68,203,121,121,106,25,185,
    238,51,101,221,41,45,196,121,234,243,215,219,185,13,207,71,
    81,28,62,164,133,114,221,57,21,252,216,227,138,240,100,79,
    54,186,178,187,141,135,205,189,160,215,216,9,221,93,142,139,
    153,217,246,89,110,155,226,192,158,238,50,210,155,52,198,13,
    47,142,176,102,31,120,42,78,26,190,196,227,151,244,27,239,
    55,184,224,55,130,180,225,110,227,83,215,83,26,230,39,19,
    149,155,89,55,217,77,185,111,221,127,65,211,81,197,213,193,
    211,117,128,13,252,75,40,182,87,125,230,43,234,55,39,129,
    206,26,220,9,241,96,165,250,186,98,81,199,97,111,208,240,
    3,24,97,153,255,0,5,31,208,10,228,172,170,88,49,106,
    134,90,56,147,167,159,211,219,233,217,108,253,251,235,100,171,
    190,60,202,114,182,74,156,114,140,206,247,52,214,168,220,183,
    235,57,113,130,199,73,38,78,229,196,11,60,78,51,113,38,
    39,206,242,56,199,196,249,252,38,107,129,137,139,208,94,162,
    43,23,162,44,83,113,24,123,211,226,192,217,53,170,188,250,
    227,255,180,38,216,119,254,31,170,219,31,65,214,33,156,87,
    15,68,217,174,41,93,15,58,34,63,152,148,141,226,11,144,
    149,115,32,233,120,137,116,149,212,81,90,29,141,169,92,87,
    244,186,223,12,242,252,108,27,253,160,176,234,152,187,163,254,
    2,7,79,159,202,56,120,226,105,116,25,251,105,139,251,233,
    123,212,79,31,178,11,28,67,183,212,3,80,86,10,79,208,
    169,37,146,47,156,97,222,208,125,51,169,231,246,122,50,242,
    237,155,80,110,133,249,241,40,176,64,181,236,175,80,234,86,
    76,177,128,189,239,217,28,164,82,93,178,146,163,88,41,178,
    110,68,241,100,232,254,45,135,110,147,207,174,69,189,182,239,
    209,192,21,186,40,206,246,207,138,104,92,63,15,151,126,215,
    197,182,232,247,7,50,242,100,66,167,174,215,101,197,94,138,
    143,107,39,168,220,102,14,125,57,33,150,84,57,33,162,49,
    242,250,188,210,107,51,211,90,211,200,124,138,174,238,158,39,
    128,47,4,51,238,39,241,163,32,113,112,163,142,240,32,67,
    23,203,94,124,16,41,86,224,77,222,39,157,232,34,230,251,
    89,213,253,239,89,38,237,97,23,33,63,73,226,238,185,154,
    190,161,8,82,118,125,160,236,119,115,115,90,112,37,243,101,
    40,149,28,154,194,138,160,150,93,169,248,104,122,18,247,241,
    132,203,71,70,252,30,58,206,200,58,131,159,162,224,63,208,
    10,212,14,96,103,32,170,216,27,44,10,254,49,106,213,154,
    224,150,235,212,95,18,180,98,148,36,250,128,212,79,109,222,
    15,166,139,140,225,203,238,188,243,161,228,226,195,252,150,219,
    213,247,148,124,9,103,191,11,217,133,137,125,163,200,60,186,
    73,226,83,169,62,253,99,13,228,118,144,187,63,251,39,68,
    167,19,90,247,246,70,110,217,70,97,89,171,200,35,131,89,
    212,234,80,78,251,96,187,223,234,167,74,118,207,17,213,10,
    186,189,80,62,150,221,56,233,171,198,80,150,7,89,103,154,
    49,173,12,101,194,135,250,6,153,207,80,103,159,63,12,99,
    111,95,250,25,207,149,243,121,30,197,93,23,233,195,87,65,
    109,51,9,179,167,158,251,9,189,181,120,138,154,202,36,112,
    195,224,107,201,123,204,16,121,218,53,167,23,147,209,1,91,
    132,230,62,142,125,121,198,183,15,124,63,177,221,104,87,58,
    207,37,245,243,234,218,105,134,19,46,203,185,134,187,151,66,
    52,128,41,131,41,231,224,182,117,40,23,253,69,35,95,100,
    64,230,214,119,72,99,193,185,151,200,221,0,173,77,88,232,
    73,113,217,86,75,233,193,166,12,45,31,101,25,163,202,88,
    125,178,212,215,96,247,233,202,53,253,13,14,116,75,94,155,
    174,97,246,210,54,108,138,58,110,196,150,57,57,83,179,38,
    39,106,86,109,204,228,171,205,41,49,111,212,173,218,196,164,
    248,174,159,53,204,250,186,177,54,95,19,255,5,15,66,36,
    187,
};

EmbeddedPython embedded_m5_internal_param_DMA_Controller(
    "m5/internal/param_DMA_Controller.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_DMA_Controller.py",
    "m5.internal.param_DMA_Controller",
    data_m5_internal_param_DMA_Controller,
    2481,
    7789);

} // anonymous namespace
