#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_LRU[] = {
    120,156,189,88,235,114,219,198,21,62,11,128,148,72,73,22,
    101,89,146,109,201,22,218,140,27,214,211,72,173,27,215,157,
    137,234,214,73,211,153,100,26,37,5,157,177,163,100,138,66,
    192,138,4,133,11,7,88,89,166,71,250,83,121,218,190,64,
    251,6,253,209,183,233,27,181,231,156,5,64,232,54,147,153,
    132,145,201,245,114,47,103,207,229,59,151,93,31,138,191,6,
    126,127,103,3,228,255,18,0,1,126,4,68,0,177,128,61,
    1,66,10,8,110,193,97,3,178,247,33,104,192,91,128,61,
    3,164,1,103,216,49,225,107,3,146,121,222,211,132,200,228,
    17,1,227,54,72,11,246,26,240,34,89,2,75,54,225,176,
    13,217,95,64,8,145,8,120,25,204,64,48,11,111,145,58,
    118,90,76,112,22,104,176,205,131,45,8,230,120,176,13,193,
    60,119,230,96,220,1,57,15,123,11,180,108,239,6,146,125,
    136,100,23,153,236,127,137,108,128,51,43,16,220,160,229,200,
    215,87,180,210,162,149,124,222,34,83,233,148,92,46,193,222,
    205,178,191,92,235,223,170,245,87,106,253,213,90,127,173,214,
    191,205,125,228,236,38,12,239,192,240,46,12,215,225,0,149,
    181,84,113,177,1,210,132,225,61,216,187,7,18,63,27,112,
    134,250,12,110,214,118,220,231,29,203,213,142,77,222,97,195,
    158,13,18,63,155,122,71,19,122,221,85,180,81,248,63,252,
    235,162,141,64,205,99,243,74,102,121,152,38,110,152,28,164,
    161,65,243,77,106,200,162,62,53,51,133,105,63,34,211,254,
    7,216,174,129,81,152,246,20,144,176,32,89,34,3,78,185,
    115,106,192,184,11,39,2,134,22,4,38,156,224,49,13,98,
    160,47,224,204,128,111,76,90,112,138,173,133,6,184,15,150,
    210,118,29,178,1,52,165,25,56,109,192,73,3,122,47,79,
    12,26,56,108,65,246,111,120,179,193,68,103,153,168,1,39,
    216,90,112,102,193,105,19,94,224,34,28,26,182,72,124,241,
    242,4,37,197,145,94,215,66,110,119,107,226,146,40,65,152,
    37,94,44,85,27,251,238,200,203,188,216,253,163,243,101,183,
    93,206,167,249,214,200,83,3,135,55,152,164,137,120,164,152,
    80,154,72,53,135,157,131,48,9,220,56,13,142,34,169,102,
    137,138,123,16,70,210,117,121,242,147,120,148,102,234,227,44,
    75,51,135,148,201,131,81,234,85,59,72,149,126,148,230,178,
    75,167,241,49,14,145,87,180,250,96,196,20,137,1,102,146,
    54,7,50,247,179,112,164,208,70,154,34,173,38,106,93,178,
    14,55,249,39,216,108,15,210,88,110,31,202,56,150,153,124,
    180,221,151,241,99,110,222,203,149,183,31,201,237,253,163,48,
    10,182,159,57,159,109,143,198,106,144,38,219,56,31,38,74,
    162,58,162,237,74,17,91,56,121,147,72,30,135,125,55,100,
    97,220,129,140,70,50,91,160,209,187,116,156,232,136,121,209,
    20,166,232,138,5,236,53,240,107,138,13,99,78,236,134,36,
    142,79,34,18,134,172,58,106,200,148,2,14,13,200,54,8,
    19,67,252,8,50,34,34,163,71,115,6,207,253,137,244,160,
    71,135,38,89,90,15,158,48,142,16,80,184,114,135,76,155,
    0,131,161,1,195,38,104,144,32,182,52,106,178,49,181,184,
    156,200,24,72,220,130,252,159,128,122,69,120,156,64,1,157,
    51,19,68,210,1,68,1,122,56,142,174,226,129,127,101,244,
    245,186,196,254,46,99,65,13,194,60,61,78,88,227,212,103,
    127,233,161,102,190,24,127,190,63,148,190,202,55,113,224,171,
    244,200,246,189,36,73,149,237,5,129,237,41,149,133,251,71,
    74,230,182,74,237,7,121,151,140,232,44,149,112,170,232,141,
    71,37,124,200,212,8,31,253,35,8,125,133,63,150,249,7,
    91,33,151,10,161,48,72,131,28,199,137,68,95,42,135,152,
    84,164,228,148,25,97,164,184,180,148,142,199,117,55,240,247,
    179,146,19,134,99,183,89,130,39,151,209,1,227,223,143,188,
    60,119,153,19,26,103,200,17,225,87,94,116,36,153,58,98,
    71,33,67,212,213,60,76,13,116,183,73,128,82,94,22,34,
    73,147,96,140,60,133,254,187,116,220,109,134,222,60,131,111,
    5,129,55,131,109,19,255,111,138,85,195,183,10,184,53,75,
    200,81,160,83,192,6,23,133,205,17,126,103,24,84,186,6,
    71,5,150,131,189,239,199,212,163,205,206,6,53,247,168,185,
    79,205,102,41,234,52,228,93,184,40,239,19,58,195,96,33,
    89,28,50,132,89,138,19,156,243,160,59,19,15,194,128,215,
    35,79,48,200,95,38,158,96,81,112,204,158,82,139,75,217,
    199,76,200,159,83,40,38,143,97,98,228,28,8,115,234,77,
    192,207,202,113,58,36,244,108,137,91,135,192,88,71,100,191,
    134,72,135,236,194,112,116,238,148,241,206,165,21,26,136,206,
    58,145,106,92,161,93,155,154,31,77,83,197,19,72,245,47,
    65,234,3,58,174,83,64,106,129,161,212,198,111,199,240,205,
    66,239,85,206,91,190,0,37,194,145,117,5,142,126,66,61,
    243,178,164,63,0,132,10,249,254,80,131,16,177,100,212,197,
    216,197,206,120,141,184,175,131,103,13,147,246,139,100,13,243,
    176,193,121,248,231,156,135,57,151,115,213,163,3,175,201,177,
    87,119,26,164,134,3,19,86,139,252,154,183,176,29,101,233,
    235,177,157,30,216,138,229,164,56,185,243,32,223,122,144,127,
    128,17,208,126,202,177,71,199,64,29,229,50,57,162,40,69,
    91,63,126,237,75,206,110,252,203,117,117,80,114,117,130,46,
    178,38,226,104,133,148,104,148,218,229,240,156,171,140,162,242,
    212,244,219,174,244,75,236,126,74,7,180,89,185,166,88,67,
    204,180,5,115,225,234,8,204,181,18,207,226,247,67,82,56,
    73,42,129,170,95,167,167,121,100,246,73,16,231,103,231,112,
    49,5,230,157,109,164,246,101,137,135,230,4,15,244,53,75,
    88,255,29,184,114,20,240,55,32,139,163,97,11,88,87,94,
    64,38,94,166,229,127,6,198,255,21,57,156,227,71,143,242,
    54,175,192,176,146,63,225,165,58,165,127,10,255,168,57,79,
    153,120,205,162,54,172,39,94,171,138,61,12,149,111,149,92,
    173,243,65,138,12,50,240,114,90,166,35,207,196,31,39,33,
    189,42,237,48,242,78,3,55,179,154,180,75,92,124,51,65,
    13,165,174,117,177,108,212,176,240,11,106,30,85,48,16,229,
    216,247,204,208,38,92,159,91,93,29,201,191,166,83,45,230,
    115,113,134,149,131,123,43,76,55,74,76,63,170,48,45,57,
    215,188,229,235,0,181,6,25,244,204,16,120,119,195,146,138,
    174,74,22,200,6,236,53,9,253,92,244,138,194,57,68,25,
    145,40,126,157,75,100,172,128,93,173,154,202,166,218,92,212,
    188,158,154,167,147,197,118,34,47,222,15,188,167,9,145,167,
    51,252,210,93,140,146,225,78,157,97,130,186,184,142,103,254,
    249,184,100,252,213,212,188,252,87,72,173,98,152,205,22,164,
    62,187,246,243,129,180,99,25,239,227,237,110,16,142,236,131,
    200,235,179,5,204,66,160,207,75,129,20,155,240,98,9,144,
    63,164,54,181,253,52,193,48,123,228,171,52,179,3,137,87,
    31,25,216,239,217,28,163,237,48,183,189,125,156,245,124,165,
    161,123,222,227,184,166,244,178,126,206,229,227,225,49,117,167,
    106,65,23,239,176,33,22,207,35,168,210,160,190,100,85,33,
    151,203,98,237,9,152,177,240,82,163,198,58,222,80,57,224,
    108,81,243,83,152,118,100,126,31,169,197,68,150,212,210,20,
    235,70,203,224,212,135,211,95,208,186,252,178,219,125,246,109,
    220,78,63,150,20,206,215,44,95,89,102,64,242,213,135,30,
    66,154,197,67,8,122,228,204,119,245,72,70,247,84,113,125,
    252,189,58,162,243,228,7,227,215,249,53,20,249,245,58,39,
    20,117,97,22,180,19,14,69,89,170,215,37,225,27,127,167,
    142,14,215,207,164,167,164,54,194,198,20,133,98,183,213,135,
    189,153,120,212,229,194,242,89,197,255,25,87,17,227,91,108,
    27,125,35,97,219,136,23,201,93,172,48,45,174,48,119,168,
    194,60,97,97,93,67,23,153,19,160,53,42,153,73,43,137,
    60,118,43,185,117,249,72,60,121,163,145,76,2,231,33,212,
    43,66,158,158,154,125,41,62,156,66,45,149,155,226,22,150,
    128,151,61,136,98,94,77,30,54,82,163,242,153,105,154,139,
    49,248,182,196,96,151,74,240,73,224,115,118,168,225,80,87,
    69,57,231,183,80,70,190,10,101,129,140,164,146,19,165,243,
    96,113,235,11,36,198,250,116,140,165,57,151,189,248,59,114,
    221,233,134,202,223,32,181,87,80,92,40,48,84,138,166,209,
    50,91,205,150,224,44,115,225,181,82,115,65,55,74,93,220,
    141,115,135,189,113,177,146,144,223,214,202,184,79,26,225,184,
    187,235,197,250,133,132,95,2,156,119,160,184,203,57,239,86,
    234,162,155,45,87,212,250,142,130,184,228,12,200,9,207,249,
    37,141,83,117,25,63,222,42,197,216,210,98,124,232,229,178,
    39,213,179,60,79,125,126,224,139,31,171,187,215,174,124,238,
    97,174,220,188,114,250,163,40,245,15,101,160,95,157,212,189,
    235,215,252,62,141,61,28,95,191,114,69,47,140,11,10,75,
    23,230,131,140,118,173,92,24,205,101,22,122,81,248,70,63,
    84,149,195,252,62,120,133,124,100,163,250,0,39,186,50,118,
    49,132,50,217,15,115,36,194,20,234,75,11,15,39,115,171,
    213,115,193,174,190,109,170,88,211,53,160,190,110,62,165,71,
    140,156,110,211,244,216,212,90,108,33,238,200,229,77,188,243,
    45,8,203,156,239,180,172,249,185,150,213,154,49,249,221,96,
    1,171,250,182,213,154,155,23,245,127,155,136,211,182,177,137,
    187,255,15,62,158,87,170,
};

EmbeddedPython embedded_m5_internal_param_LRU(
    "m5/internal/param_LRU.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_LRU.py",
    "m5.internal.param_LRU",
    data_m5_internal_param_LRU,
    2199,
    6435);

} // anonymous namespace
