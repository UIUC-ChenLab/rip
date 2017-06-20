#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_BadDevice[] = {
    120,156,189,88,123,111,219,200,17,159,37,41,217,146,95,114,
    252,74,98,39,102,146,58,167,6,61,187,77,47,77,129,115,
    211,230,30,5,122,64,156,148,186,34,57,223,161,44,77,174,
    101,202,18,41,144,107,39,58,216,64,81,7,109,129,254,221,
    143,208,63,250,109,250,9,238,171,180,51,179,36,69,203,54,
    122,64,43,59,210,102,181,59,59,187,51,243,155,199,174,15,
    217,95,5,191,191,178,1,210,239,4,64,128,31,1,93,128,
    158,128,93,1,66,10,8,22,225,176,2,201,71,16,84,224,
    61,192,174,1,210,128,51,236,152,240,181,1,209,52,175,169,
    66,215,228,17,1,131,58,72,11,118,43,240,58,154,7,75,
    86,225,176,14,201,31,64,8,17,9,120,19,76,64,48,9,
    239,145,59,118,106,204,112,18,104,176,206,131,53,8,166,120,
    176,14,193,52,119,166,96,208,0,57,13,187,51,68,182,59,
    139,108,31,33,219,57,102,251,47,98,27,224,204,18,4,179,
    68,142,231,250,138,40,45,162,228,253,230,152,75,35,63,229,
    60,236,222,200,251,11,165,254,98,169,191,84,234,47,151,250,
    43,165,254,205,82,255,86,169,127,187,212,95,45,245,215,74,
    253,59,165,254,93,238,163,132,55,160,179,14,29,27,58,247,
    96,31,149,62,95,72,115,31,164,9,157,7,176,251,0,36,
    126,238,195,25,218,37,184,81,90,241,3,94,177,80,172,216,
    224,21,15,97,247,33,72,252,108,232,21,85,104,53,151,209,
    214,225,191,241,175,137,182,6,53,141,205,177,76,210,48,142,
    220,48,218,143,67,131,230,171,212,16,50,124,106,38,50,136,
    124,74,16,249,39,48,62,2,35,131,200,41,32,99,65,178,
    116,13,56,229,206,169,1,131,38,156,8,232,88,16,152,112,
    130,219,84,232,0,109,1,103,6,124,99,18,193,41,182,22,
    26,242,46,88,74,227,163,195,134,212,156,38,224,180,2,39,
    21,104,189,57,49,104,224,176,6,201,63,224,219,53,102,58,
    201,76,13,56,193,214,130,51,11,78,171,240,26,137,112,168,
    83,35,241,197,155,19,148,20,71,90,77,11,79,187,83,18,
    151,68,9,194,36,242,122,82,53,176,239,246,189,196,235,185,
    159,120,193,103,242,56,244,101,179,158,83,197,233,102,223,83,
    7,14,47,51,73,31,189,190,98,118,113,36,213,20,118,246,
    195,40,112,123,113,112,212,149,106,146,120,185,251,97,87,186,
    46,79,254,166,215,143,19,245,121,146,196,137,67,42,229,193,
    110,236,21,43,72,161,126,55,78,101,147,118,227,109,28,98,
    175,136,122,191,207,28,233,0,124,84,90,28,200,212,79,194,
    190,66,75,105,142,68,77,220,154,100,35,110,210,151,216,108,
    29,196,61,185,117,40,123,61,153,200,199,91,109,217,123,194,
    205,135,169,242,246,186,114,107,239,40,236,6,91,207,157,23,
    91,253,129,58,136,163,45,156,15,35,37,81,41,221,173,17,
    117,108,34,201,13,98,252,54,108,187,33,139,228,30,200,110,
    95,38,51,52,122,155,54,21,13,49,45,170,194,20,77,49,
    131,189,10,126,77,177,102,76,137,157,144,132,242,73,80,194,
    147,85,70,16,153,85,192,161,1,201,26,225,163,131,31,65,
    6,69,148,180,104,206,224,185,223,146,54,244,104,199,36,171,
    235,193,19,198,20,130,11,41,183,201,204,17,48,48,42,208,
    169,130,6,12,226,76,35,40,25,80,139,228,196,198,64,230,
    22,164,127,7,212,46,66,229,4,50,24,157,153,32,162,6,
    168,58,69,13,28,93,198,13,255,196,72,108,53,233,248,59,
    140,8,117,16,166,241,219,136,245,78,125,246,157,22,106,230,
    213,224,229,94,71,250,42,93,199,129,175,226,35,219,247,162,
    40,86,182,23,4,182,167,84,18,238,29,41,153,218,42,182,
    55,210,38,153,210,153,207,65,85,240,27,244,115,16,145,193,
    17,68,250,71,16,250,10,127,44,240,15,182,66,42,21,2,
    226,32,14,82,28,39,22,109,169,28,58,164,34,37,199,124,
    16,198,139,75,164,180,61,210,205,226,239,231,249,73,24,148,
    205,106,14,161,84,118,247,85,157,209,232,165,169,203,39,161,
    113,6,30,49,62,246,186,71,146,185,35,130,20,30,136,186,
    250,12,99,134,222,77,18,35,151,154,69,137,226,40,24,224,
    201,66,255,3,218,244,38,3,112,154,33,184,132,240,155,192,
    182,138,255,87,197,178,225,91,25,232,170,57,240,40,244,41,
    96,179,139,204,242,8,194,51,12,51,77,131,227,4,75,195,
    158,120,159,122,180,216,89,163,230,14,53,119,169,89,207,5,
    30,159,212,51,163,82,63,165,157,12,22,149,133,34,163,152,
    185,80,193,57,111,186,53,244,38,12,132,45,242,10,131,124,
    103,232,21,22,5,205,228,25,181,72,202,254,102,66,250,37,
    133,104,242,30,102,70,142,130,144,167,222,208,17,88,69,14,
    5,205,230,100,142,97,135,128,89,70,103,187,132,78,135,172,
    195,208,116,110,229,17,208,37,10,13,74,103,149,88,85,46,
    209,177,77,205,189,241,43,122,8,175,246,5,120,125,76,155,
    54,50,120,205,48,172,234,248,109,24,190,153,105,191,200,136,
    11,35,176,34,76,89,151,96,234,33,245,204,139,242,94,27,
    156,50,41,127,93,130,19,29,204,40,11,179,131,157,193,10,
    201,80,6,210,10,38,246,215,209,10,230,106,131,115,245,143,
    57,87,115,190,231,10,75,7,100,147,99,178,238,84,72,25,
    251,38,44,103,57,56,173,97,219,79,226,119,3,59,222,183,
    21,75,75,241,115,123,35,221,220,72,63,198,200,104,63,227,
    152,164,99,163,142,126,137,236,83,244,162,165,159,191,243,37,
    231,62,254,229,186,58,88,185,28,184,220,44,167,34,166,150,
    72,149,70,174,99,14,219,169,74,40,90,143,89,203,245,66,
    203,116,232,47,104,155,58,171,216,20,43,136,159,186,224,179,
    184,58,62,115,85,197,179,248,253,132,212,78,242,74,160,122,
    219,105,233,147,178,16,36,142,243,163,115,24,25,155,8,206,
    22,242,252,93,142,141,234,16,27,244,53,115,160,255,5,184,
    210,20,240,103,32,235,163,145,51,160,23,126,65,230,94,32,
    242,223,3,123,196,37,121,158,227,74,139,114,59,83,96,184,
    73,159,50,169,78,251,95,192,95,75,238,148,39,103,51,171,
    37,203,201,217,42,98,18,195,230,123,37,96,235,124,240,34,
    179,28,120,41,145,233,136,52,244,208,97,192,47,138,64,140,
    200,227,195,208,164,222,192,165,179,124,51,68,16,165,183,85,
    177,96,148,112,241,19,106,30,23,144,16,249,216,88,142,181,
    14,87,103,97,87,71,251,175,105,111,139,79,59,55,193,30,
    90,112,40,176,94,201,177,254,184,192,186,228,172,244,158,47,
    20,212,26,100,226,51,67,224,45,18,11,49,186,180,89,32,
    43,176,91,37,175,224,130,89,100,78,35,242,120,69,209,237,
    92,202,99,101,236,104,53,21,86,214,6,164,230,221,152,227,
    0,217,112,187,235,245,246,2,239,25,69,185,148,118,242,115,
    55,50,242,99,55,202,199,38,23,16,87,157,156,127,62,201,
    143,127,60,230,24,240,51,224,92,166,143,205,136,15,98,159,
    29,255,203,3,105,247,100,111,15,239,138,7,97,223,222,239,
    122,109,182,134,153,137,245,50,23,75,177,57,71,11,135,244,
    17,181,177,237,199,17,6,228,35,95,197,137,29,72,188,66,
    201,192,254,208,230,104,110,135,169,237,237,225,172,231,43,13,
    233,243,254,200,85,169,151,180,83,46,64,15,223,82,247,26,
    172,233,226,189,56,196,34,252,24,138,180,169,175,108,69,112,
    230,242,90,123,8,102,56,188,28,169,129,142,73,84,68,56,
    155,212,252,16,174,39,134,127,148,217,46,37,21,85,197,170,
    81,51,212,92,217,29,95,209,154,244,162,83,238,125,31,167,
    212,143,58,153,107,86,137,82,78,208,125,156,218,26,133,113,
    122,179,169,100,111,54,52,168,223,108,170,60,50,75,78,60,
    241,191,58,49,187,194,53,56,193,233,255,213,119,157,167,215,
    124,106,231,231,144,37,236,171,252,86,148,69,154,209,126,219,
    17,249,157,160,44,15,63,54,44,95,4,145,235,39,210,83,
    82,155,101,109,236,2,178,215,235,45,255,56,116,197,139,21,
    236,243,66,150,51,46,81,6,139,108,45,125,13,98,107,137,
    215,209,109,44,101,45,46,101,183,169,148,61,97,193,93,67,
    87,179,67,0,86,10,249,73,149,145,124,235,142,232,64,87,
    171,116,50,175,223,151,81,224,60,130,114,1,202,211,99,182,
    59,5,153,247,80,170,22,76,177,136,21,231,69,47,163,240,
    89,146,141,205,86,41,252,106,252,6,100,132,254,45,71,104,
    147,194,210,48,134,58,219,212,112,212,44,2,166,243,203,66,
    253,119,47,129,95,192,63,248,185,4,111,54,255,141,4,107,
    23,46,210,135,67,172,57,6,118,32,187,82,201,81,219,234,
    7,66,29,215,3,137,121,41,30,224,133,131,203,120,252,221,
    117,221,235,8,232,191,208,193,6,82,202,49,24,208,69,21,
    67,250,146,81,171,214,4,103,198,145,247,90,125,26,122,27,
    209,229,234,32,117,56,28,204,21,154,228,119,197,60,75,145,
    210,185,92,219,65,125,232,199,74,122,249,112,30,64,118,95,
    117,62,40,44,66,119,120,190,35,232,27,24,58,3,103,109,
    78,210,206,79,105,28,65,6,189,39,155,185,56,155,185,56,
    105,232,191,10,99,45,19,63,111,246,158,168,213,75,105,135,
    100,55,47,157,111,13,82,37,123,23,22,203,232,168,231,190,
    144,189,56,25,188,136,3,169,214,70,230,159,7,65,226,120,
    81,91,186,199,146,42,15,117,111,148,32,43,59,52,143,156,
    234,114,121,206,211,94,33,8,78,234,55,65,174,158,47,206,
    127,218,141,253,67,25,100,52,119,174,166,249,44,238,121,56,
    126,249,46,173,48,223,101,126,100,62,72,104,213,210,200,104,
    42,147,208,235,134,223,234,167,198,124,88,45,18,36,46,179,
    213,44,187,84,121,136,11,140,243,201,128,29,36,145,237,16,
    77,147,48,175,243,75,178,64,73,64,102,195,140,250,104,121,
    249,53,120,148,174,208,245,131,193,51,122,146,98,15,161,7,
    196,218,92,13,189,139,226,167,137,247,245,25,97,153,211,141,
    154,53,61,85,179,106,19,38,191,255,204,224,45,172,110,213,
    166,166,197,85,255,214,209,47,235,198,122,163,38,254,3,243,
    16,16,164,
};

EmbeddedPython embedded_m5_internal_param_BadDevice(
    "m5/internal/param_BadDevice.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_BadDevice.py",
    "m5.internal.param_BadDevice",
    data_m5_internal_param_BadDevice,
    2323,
    7005);

} // anonymous namespace
