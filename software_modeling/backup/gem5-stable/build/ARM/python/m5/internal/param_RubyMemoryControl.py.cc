#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_RubyMemoryControl[] = {
    120,156,197,89,91,119,219,198,17,158,5,72,74,164,36,75,
    178,110,190,200,22,115,177,205,56,182,228,56,190,164,181,227,
    212,117,147,115,154,115,162,164,80,122,236,40,57,69,33,98,
    37,129,34,1,22,88,89,166,143,244,82,249,180,125,234,91,
    242,15,250,208,215,254,146,254,163,118,102,22,11,66,148,68,
    73,109,205,90,228,120,57,216,157,217,153,249,102,118,23,91,
    135,244,95,17,191,191,168,2,36,63,9,0,31,63,2,154,
    0,45,1,171,2,132,20,224,79,195,86,17,226,123,224,23,
    225,13,192,170,5,210,130,125,108,216,240,189,5,225,40,143,
    41,65,211,102,142,128,78,5,100,1,86,139,240,60,156,132,
    130,44,193,86,5,226,223,131,16,34,20,240,194,31,2,127,
    24,222,160,116,108,148,89,224,48,16,179,194,204,50,248,35,
    204,172,128,63,202,141,17,232,76,128,28,133,213,49,234,182,
    122,14,197,222,68,177,227,44,246,159,36,214,199,39,51,224,
    159,163,238,56,175,239,168,103,129,122,178,190,113,150,50,97,
    102,57,9,171,231,77,123,42,215,158,206,181,103,114,237,217,
    92,123,46,215,190,192,109,156,217,121,104,92,132,198,37,104,
    92,134,117,116,214,100,54,139,121,144,54,52,174,192,234,21,
    144,248,153,135,125,244,167,127,62,55,226,42,143,152,202,70,
    44,240,136,42,172,86,65,226,103,65,143,40,193,74,109,22,
    99,20,252,11,255,213,48,70,160,70,145,188,148,113,18,68,
    161,27,132,235,81,96,209,243,18,17,138,104,157,200,80,26,
    218,103,20,218,191,3,199,213,183,210,208,238,1,10,22,100,
    75,211,130,61,110,236,89,208,169,193,174,128,70,1,124,27,
    118,81,77,145,38,176,33,96,223,130,31,108,234,176,135,180,
    128,1,184,10,5,165,227,218,224,0,104,73,67,176,87,132,
    221,34,172,188,216,181,136,177,85,134,248,111,240,122,158,133,
    14,179,80,11,118,145,22,96,191,0,123,37,120,142,157,144,
    213,40,147,249,226,197,46,90,138,156,149,90,1,103,187,156,
    51,151,76,241,131,56,244,90,82,93,192,182,219,246,98,175,
    229,58,219,107,157,175,100,43,138,59,207,162,80,197,81,179,
    86,49,189,163,100,177,237,169,77,135,135,219,228,151,86,91,
    177,216,40,148,106,4,27,235,65,232,187,173,200,223,110,74,
    53,76,50,221,245,160,41,93,151,31,254,186,213,142,98,245,
    121,28,71,177,67,174,101,102,51,242,178,17,228,216,122,51,
    74,100,141,180,177,26,135,196,43,234,189,222,102,137,52,1,
    158,50,13,246,101,82,143,131,182,194,136,105,137,212,155,164,
    213,40,86,76,146,231,72,150,54,163,150,92,218,146,173,150,
    140,229,221,165,13,217,186,207,228,118,162,188,181,166,92,90,
    219,14,154,254,210,83,231,171,165,118,71,109,70,225,18,62,
    15,66,37,209,57,205,165,99,220,178,136,93,207,147,130,157,
    96,195,13,216,52,119,83,54,219,50,30,35,238,37,82,46,
    38,196,168,40,9,91,212,196,24,182,138,248,181,197,188,53,
    34,150,3,50,174,78,6,19,190,10,121,68,81,152,5,108,
    89,16,207,19,94,26,248,17,20,96,68,205,10,61,179,248,
    217,111,200,43,154,219,176,9,5,154,185,203,24,67,176,97,
    207,199,20,246,16,24,40,69,104,148,64,3,8,113,167,17,
    21,119,136,98,119,18,99,161,240,2,36,63,2,122,25,161,
    179,11,41,172,246,109,16,225,4,168,10,101,63,114,103,81,
    225,31,25,153,43,53,154,254,50,35,67,109,6,73,180,19,
    178,255,169,205,185,180,130,158,249,166,243,245,90,67,214,85,
    178,128,140,239,162,237,106,221,11,195,72,85,61,223,175,122,
    74,197,193,218,182,146,73,85,69,213,107,73,141,66,234,76,
    26,112,101,242,58,109,3,38,10,60,130,73,255,240,131,186,
    194,31,83,252,131,163,144,72,133,192,216,140,252,4,249,36,
    98,67,42,135,38,169,200,201,17,79,132,113,227,82,87,82,
    143,253,206,225,239,167,102,38,12,206,90,201,64,41,145,205,
    117,85,97,84,122,73,226,242,76,136,207,0,36,193,47,189,
    230,182,100,233,136,36,133,19,162,166,158,195,128,32,200,153,
    107,172,103,147,194,40,244,59,56,195,160,126,131,148,95,96,
    32,142,50,20,103,16,134,67,72,75,248,127,73,204,90,245,
    66,10,190,146,1,32,149,68,5,28,126,145,34,0,193,184,
    143,229,167,102,113,253,96,171,56,51,223,165,22,13,118,230,
    137,92,33,114,149,200,130,49,252,237,91,63,214,107,253,67,
    210,104,177,201,108,28,5,201,54,198,249,7,178,235,98,55,
    187,176,80,174,80,150,88,148,75,221,44,41,80,81,141,159,
    16,197,174,156,127,54,36,223,82,9,167,108,98,97,148,56,
    152,2,212,234,38,6,187,202,153,32,23,12,27,76,59,4,
    212,60,90,55,114,104,117,40,74,12,85,231,162,169,140,46,
    245,208,32,117,46,147,168,226,17,190,174,18,121,103,112,14,
    239,194,109,227,16,220,30,145,242,137,20,110,99,12,179,10,
    126,39,172,186,157,70,33,91,57,167,122,96,70,24,43,28,
    129,177,235,212,178,15,219,61,112,120,165,214,126,145,131,23,
    77,208,202,27,181,140,141,206,28,217,146,7,214,28,110,4,
    158,135,115,184,182,91,188,182,223,225,181,157,247,7,188,147,
    210,5,219,230,154,173,27,69,114,202,186,13,179,233,154,157,
    148,145,182,227,232,85,167,26,173,87,21,91,77,245,245,241,
    181,100,241,90,242,8,43,103,245,9,215,44,93,59,117,117,
    140,101,155,170,27,13,253,252,85,93,242,26,201,191,92,87,
    23,51,151,11,155,155,174,189,136,177,25,114,169,101,124,205,
    101,61,81,49,85,243,1,121,187,146,121,155,38,255,37,169,
    171,176,171,109,49,135,120,170,8,158,147,171,235,56,239,198,
    248,41,126,127,73,238,39,187,37,208,254,218,89,209,51,102,
    99,200,44,231,214,1,204,188,117,83,156,37,148,253,91,131,
    149,82,23,43,244,181,77,2,252,25,120,167,42,224,79,64,
    104,192,160,167,9,144,229,11,133,127,138,186,255,14,56,83,
    142,216,23,112,221,89,161,189,0,247,192,114,148,60,228,174,
    122,155,240,37,252,37,151,102,102,49,183,211,189,104,126,49,
    47,100,53,139,97,116,170,5,187,112,176,184,81,120,54,189,
    132,186,233,138,213,205,220,238,194,144,109,30,177,98,191,125,
    76,13,107,69,46,205,233,135,46,162,104,57,188,44,166,172,
    28,78,62,34,114,55,131,136,48,188,183,58,189,5,56,126,
    245,118,245,234,240,61,205,161,192,179,30,31,82,236,236,94,
    73,89,46,20,77,46,220,205,114,65,242,106,246,134,15,42,
    68,45,10,253,190,37,240,84,137,27,58,58,196,21,64,22,
    97,181,68,89,195,27,112,145,38,149,48,117,141,170,224,129,
    165,146,157,179,172,221,150,69,95,7,150,200,171,1,213,11,
    138,237,227,166,215,90,243,189,39,33,41,35,141,117,147,102,
    150,153,254,68,126,250,148,34,226,56,11,248,231,125,99,198,
    203,1,213,138,7,40,59,155,62,103,134,31,213,185,64,124,
    187,41,171,45,217,90,195,51,233,102,208,174,174,55,189,13,
    142,142,157,154,247,181,49,79,113,120,123,55,32,201,77,162,
    81,181,30,133,88,200,183,235,42,138,171,190,196,35,154,244,
    171,183,171,188,10,84,131,164,234,173,225,83,175,174,52,228,
    15,230,45,239,118,189,120,35,225,141,237,214,14,53,7,24,
    93,23,207,225,1,110,242,219,144,45,187,250,104,152,21,117,
    222,190,235,12,194,21,18,15,95,170,163,107,24,109,70,156,
    69,34,31,192,96,107,255,61,148,221,34,37,228,178,146,184,
    108,149,45,53,119,84,218,126,67,50,146,195,201,251,15,113,
    138,228,213,47,131,210,20,46,81,79,57,68,239,3,136,150,
    105,25,88,173,24,230,8,211,81,102,142,25,230,57,166,227,
    204,156,48,204,73,166,231,153,57,101,152,211,76,103,152,57,
    107,152,115,76,47,48,243,162,97,94,98,122,153,153,243,134,
    121,133,233,85,102,46,24,102,149,233,59,204,124,215,48,223,
    99,250,62,51,175,25,230,117,166,55,152,89,51,204,15,152,
    222,100,230,135,134,121,139,233,109,102,46,26,230,18,211,59,
    204,252,200,48,239,50,253,152,153,247,12,243,62,211,7,204,
    124,104,152,159,48,253,25,51,127,110,94,213,61,98,230,99,
    88,253,148,222,89,17,231,9,21,207,161,255,182,120,114,233,
    25,96,209,217,249,159,214,76,231,225,255,105,246,206,39,144,
    110,168,142,171,151,34,111,218,152,174,151,13,97,206,116,121,
    187,248,37,210,213,227,147,213,173,199,210,83,82,135,107,126,
    96,6,115,245,213,170,95,119,75,225,225,19,200,211,204,182,
    125,222,82,118,166,57,138,250,88,203,81,20,207,195,75,120,
    20,41,240,81,228,49,29,69,118,217,17,174,165,79,35,93,
    128,22,51,127,208,146,16,202,157,195,51,211,62,209,167,14,
    154,161,215,110,203,208,119,110,66,254,32,193,143,7,132,11,
    42,250,127,133,220,46,207,22,211,120,114,56,156,149,180,172,
    229,108,229,112,22,179,60,28,92,96,25,201,63,26,36,215,
    62,131,252,218,230,60,38,194,171,89,182,144,57,159,101,97,
    185,222,7,166,107,94,184,229,174,225,210,121,135,78,174,167,
    237,138,123,80,62,132,117,89,234,230,137,35,183,147,142,171,
    130,150,100,69,103,232,78,202,206,101,202,12,91,125,120,146,
    132,63,108,203,109,28,29,188,214,26,207,210,159,84,142,27,
    149,93,254,137,179,78,92,220,88,184,49,141,58,141,145,185,
    238,121,35,187,108,181,212,87,66,130,123,127,116,72,143,107,
    207,58,134,84,79,177,234,67,207,250,226,193,15,90,173,83,
    66,39,215,213,64,167,203,82,183,79,24,169,253,81,223,196,
    243,165,108,178,174,179,141,32,149,147,169,202,3,79,250,98,
    2,215,7,183,174,154,110,19,107,105,88,239,156,136,161,222,
    254,6,67,61,252,19,101,172,7,175,164,239,250,178,233,157,
    78,103,190,127,94,103,142,175,238,156,32,3,177,230,71,45,
    215,139,49,32,49,206,147,21,159,121,16,105,159,78,181,247,
    62,236,11,143,248,244,69,40,62,92,132,186,172,190,190,226,
    110,76,78,231,219,222,254,198,183,61,252,190,73,30,103,217,
    204,112,63,169,38,244,116,55,53,225,32,91,221,234,39,65,
    122,190,187,19,7,24,141,174,149,103,26,64,74,105,37,233,
    125,208,127,226,114,61,150,201,38,205,49,136,252,147,237,60,
    216,61,179,243,0,91,85,251,72,80,95,120,59,172,230,196,
    78,36,156,47,135,240,135,122,208,167,55,223,203,49,193,99,
    112,40,235,244,30,20,155,219,161,98,69,255,225,80,82,79,
    55,124,199,119,225,189,8,111,37,209,207,18,221,125,140,22,
    142,74,122,35,224,75,60,137,71,29,215,213,47,58,41,66,
    174,59,200,163,235,167,40,251,37,41,161,253,6,30,93,69,
    9,15,175,51,226,132,63,171,92,42,11,126,103,208,115,99,
    174,103,77,183,19,250,133,95,39,113,136,227,140,103,123,24,
    190,209,53,231,118,218,238,240,43,234,101,175,165,111,226,248,
    142,201,121,15,210,155,0,231,70,182,23,162,91,18,126,203,
    170,223,105,227,246,148,223,103,240,235,11,231,99,226,19,132,
    90,247,23,141,217,139,218,236,167,233,203,14,109,58,95,44,
    183,238,243,14,247,112,95,236,163,47,47,249,53,221,225,231,
    207,154,81,125,75,250,105,159,43,199,247,249,85,212,242,144,
    127,180,150,149,192,104,153,236,121,238,199,52,106,166,135,155,
    96,26,121,77,218,182,144,243,12,155,43,244,145,38,242,253,
    230,1,22,191,161,56,250,148,195,56,140,229,70,144,160,88,
    150,121,112,104,186,227,39,156,168,247,251,164,78,94,204,0,
    1,172,95,9,234,27,141,39,116,135,150,208,133,13,221,124,
    150,199,203,8,102,58,16,216,162,130,71,130,130,61,58,81,
    46,140,142,148,11,229,33,155,47,170,198,196,148,85,41,148,
    71,70,69,254,111,1,161,93,177,22,170,101,241,111,225,242,
    20,102,
};

EmbeddedPython embedded_m5_internal_param_RubyMemoryControl(
    "m5/internal/param_RubyMemoryControl.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_RubyMemoryControl.py",
    "m5.internal.param_RubyMemoryControl",
    data_m5_internal_param_RubyMemoryControl,
    2722,
    9178);

} // anonymous namespace
