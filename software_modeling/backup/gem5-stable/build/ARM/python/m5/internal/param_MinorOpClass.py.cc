#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_MinorOpClass[] = {
    120,156,189,88,235,114,219,198,21,62,11,128,148,72,73,22,
    101,89,146,101,201,22,219,142,27,214,211,136,173,27,215,157,
    137,234,198,205,36,51,205,76,228,20,76,199,14,147,41,10,
    17,75,18,20,46,28,96,101,153,169,244,39,242,180,125,129,
    62,66,127,244,109,250,70,237,57,103,1,16,186,120,154,153,
    150,148,137,245,98,177,123,246,92,190,115,217,237,65,246,87,
    193,231,163,38,64,154,8,0,15,127,2,2,128,80,64,87,
    128,144,2,188,59,112,92,129,228,3,240,42,240,22,160,107,
    128,52,224,2,59,38,124,109,64,180,204,107,170,16,152,60,
    34,96,82,7,105,65,183,2,47,163,53,176,100,21,142,235,
    144,252,9,132,16,145,128,87,222,2,120,139,240,22,169,99,
    167,198,4,23,129,6,235,60,88,3,111,137,7,235,224,45,
    115,103,9,38,13,144,203,208,93,161,105,221,91,72,246,17,
    146,93,101,178,255,34,178,30,126,217,0,239,22,77,71,190,
    190,162,153,22,205,228,253,86,153,74,35,231,114,13,186,183,
    243,254,122,169,127,167,212,223,224,62,238,122,27,70,155,48,
    218,130,209,93,232,163,34,214,138,29,182,65,154,48,186,7,
    221,123,32,241,183,13,23,168,43,239,118,105,197,14,175,88,
    47,86,236,242,138,251,208,189,15,18,127,187,122,69,21,58,
    173,77,212,191,255,111,252,107,161,254,65,45,99,243,90,38,
    169,31,71,142,31,245,99,223,160,239,85,106,200,90,61,106,
    22,50,179,125,76,102,251,39,176,205,60,35,51,219,57,32,
    97,65,178,4,6,156,115,231,220,128,73,11,206,4,140,44,
    240,76,56,195,109,42,196,192,64,192,133,1,223,152,52,225,
    28,91,11,149,251,0,44,165,109,54,98,229,106,74,11,112,
    94,129,179,10,116,94,157,25,52,112,92,131,228,31,240,237,
    46,19,93,100,162,6,156,97,107,193,133,5,231,85,120,137,
    147,112,104,84,35,241,197,171,51,148,20,71,58,45,11,185,
    61,44,137,75,162,120,126,18,185,161,84,235,216,119,198,110,
    226,134,206,231,126,20,39,47,198,31,7,110,154,182,234,249,
    196,56,221,31,187,106,104,243,74,147,84,18,142,21,83,140,
    35,169,150,176,211,247,35,207,9,99,239,36,144,106,145,200,
    57,125,63,144,142,195,31,127,23,142,227,68,125,146,36,113,
    98,147,86,121,48,136,221,98,5,233,180,23,196,169,108,209,
    110,188,141,77,228,21,205,238,143,153,34,49,192,220,210,98,
    79,166,189,196,31,43,52,150,166,72,179,137,90,139,204,196,
    77,106,99,211,30,198,161,108,31,203,48,148,137,124,220,30,
    200,240,9,55,239,167,202,61,10,100,251,232,196,15,188,246,
    115,251,243,246,120,162,134,113,212,198,239,126,164,36,234,37,
    104,95,215,200,62,206,186,77,180,79,253,129,227,179,84,206,
    80,6,99,153,172,208,232,61,218,87,52,196,178,168,10,83,
    180,196,10,246,42,248,152,98,215,88,18,135,62,201,213,35,
    89,9,85,86,25,71,100,92,1,199,6,36,187,132,146,17,
    254,4,153,21,177,210,161,111,6,127,251,61,41,68,143,142,
    76,178,189,30,60,99,100,33,196,112,230,1,25,59,2,134,
    71,5,70,85,208,176,65,180,105,28,37,19,106,113,58,145,
    49,144,184,5,233,223,1,21,140,128,57,131,12,76,23,38,
    136,168,1,170,78,254,140,163,155,184,225,119,140,199,78,139,
    216,63,100,80,168,161,159,198,167,17,171,158,250,236,65,29,
    212,204,23,147,23,71,35,217,83,233,30,14,124,21,159,52,
    123,110,20,197,170,233,122,94,211,85,42,241,143,78,148,76,
    155,42,110,62,76,91,100,77,123,45,199,85,65,111,50,206,
    113,68,54,71,28,233,23,207,239,41,124,97,192,58,108,133,
    84,42,196,196,48,246,82,28,39,18,3,169,108,98,82,145,
    146,99,102,132,33,227,208,84,218,30,231,221,194,247,231,57,
    39,140,203,86,53,71,81,42,131,190,170,51,32,209,226,14,
    115,66,227,140,61,34,252,218,13,78,36,83,71,16,41,100,
    136,186,154,135,217,163,239,46,73,146,11,206,210,68,113,228,
    77,144,57,191,247,30,237,123,151,49,184,204,40,220,64,4,
    46,96,91,197,255,171,98,211,232,89,25,238,170,57,246,40,
    6,42,96,203,139,204,248,136,195,11,140,55,45,131,3,6,
    11,196,254,248,67,234,209,98,123,151,154,251,212,60,160,102,
    47,151,121,166,130,175,92,21,252,41,109,102,176,180,44,23,
    153,198,204,229,242,46,249,212,246,212,167,48,40,118,200,55,
    12,242,160,169,111,88,20,64,147,103,212,226,84,246,58,19,
    210,47,41,92,147,15,49,49,114,23,4,62,245,166,238,192,
    90,178,27,36,253,98,142,100,155,224,89,198,232,160,132,81,
    155,12,196,0,181,183,243,80,232,208,12,13,77,123,135,72,
    85,110,80,115,147,154,31,204,69,215,83,144,13,174,129,236,
    67,218,183,145,129,108,133,193,85,199,167,97,244,204,204,0,
    69,130,92,191,2,46,66,150,117,3,178,126,76,61,243,186,
    200,243,4,85,38,232,167,37,80,17,111,70,89,158,67,236,
    76,182,72,140,50,156,182,48,213,191,140,182,48,123,27,156,
    189,127,198,217,155,43,0,174,131,116,112,54,57,62,235,78,
    133,244,209,55,97,51,203,202,105,13,219,113,18,191,153,52,
    227,126,83,177,192,20,75,15,30,166,251,15,211,15,49,74,
    54,159,113,124,210,113,82,71,194,68,142,41,146,209,210,79,
    222,244,36,167,66,126,115,28,29,184,28,14,98,78,150,98,
    17,89,27,164,77,35,87,51,135,240,84,37,20,185,103,175,
    232,122,161,104,226,251,51,218,169,206,90,54,197,22,162,168,
    46,152,29,71,135,107,46,181,248,43,62,191,37,205,147,200,
    18,168,48,182,59,154,89,150,131,36,178,127,122,9,41,179,
    148,194,110,35,217,63,228,8,169,78,17,66,143,153,35,254,
    175,192,21,168,128,191,0,97,0,77,157,33,190,112,16,50,
    250,58,77,255,35,176,107,220,144,249,57,198,116,40,219,243,
    12,12,61,233,83,158,170,11,129,207,224,111,37,191,202,211,
    181,153,213,152,229,116,109,21,241,137,193,243,189,82,178,117,
    57,144,145,101,134,110,74,211,116,116,154,186,234,52,254,23,
    149,33,70,231,153,34,105,81,239,225,16,59,223,76,113,68,
    9,111,71,172,27,37,116,252,156,154,199,5,48,68,62,54,
    43,206,246,224,221,169,217,209,241,255,107,218,222,98,134,87,
    23,184,94,42,19,41,112,95,201,113,255,184,192,189,228,84,
    245,150,79,28,212,26,100,235,11,67,224,209,15,107,52,58,
    105,89,32,43,208,173,146,135,112,57,45,50,7,18,121,248,
    162,96,119,41,15,178,74,14,181,178,10,115,107,75,82,243,
    102,246,97,129,140,121,16,184,225,145,231,62,59,166,125,104,
    179,94,238,82,70,206,121,163,204,57,185,131,120,23,243,252,
    250,36,151,224,245,236,67,194,47,145,108,193,57,59,128,23,
    247,56,14,124,57,148,205,80,134,71,120,164,28,250,227,102,
    63,112,7,108,19,51,147,236,69,46,153,98,163,94,173,41,
    210,71,212,198,205,94,28,97,148,62,233,169,56,105,122,18,
    143,89,210,107,190,223,228,16,223,244,211,166,123,132,95,221,
    158,210,240,190,236,158,92,182,186,201,32,229,10,245,248,148,
    186,243,177,169,131,39,104,31,11,245,16,138,116,170,79,118,
    69,196,230,18,92,123,11,102,62,60,64,169,137,142,82,84,
    95,216,251,212,252,4,230,22,216,63,0,70,23,164,164,168,
    170,216,49,106,6,159,243,202,243,190,160,149,55,248,232,209,
    247,241,81,125,49,147,121,106,149,102,202,5,58,191,83,91,
    163,240,78,247,46,149,236,222,133,6,245,189,75,149,71,110,
    145,79,47,252,175,62,205,110,49,31,135,80,255,87,87,182,
    159,206,159,113,251,87,144,165,243,119,185,177,40,75,181,162,
    215,142,68,126,122,40,139,196,247,19,219,55,162,201,233,37,
    210,85,82,219,103,119,30,98,114,40,208,187,158,78,157,243,
    122,173,251,188,144,232,130,203,152,201,29,54,155,62,54,177,
    217,196,203,232,30,22,189,22,23,189,7,84,244,158,177,248,
    142,161,235,222,41,24,43,133,22,232,184,25,201,83,231,186,
    38,116,105,75,204,185,227,177,140,60,251,17,148,171,85,254,
    60,123,12,80,240,249,51,148,138,10,83,220,193,242,244,186,
    223,81,100,45,73,200,246,171,20,158,54,23,75,50,96,191,
    203,1,219,90,133,114,120,181,15,168,225,128,90,196,82,251,
    55,133,29,30,220,140,198,88,191,209,97,232,191,77,193,18,
    71,223,12,234,119,214,28,131,220,147,129,84,242,6,11,43,
    226,38,59,16,123,18,179,86,60,193,51,10,151,253,248,30,
    56,206,156,98,253,175,51,149,165,148,129,48,214,139,42,70,
    251,13,163,86,173,9,78,157,87,238,125,53,67,164,13,93,
    222,78,152,47,176,87,11,101,242,229,100,158,195,72,239,124,
    12,59,116,67,125,179,196,23,39,246,143,32,59,232,218,239,
    21,70,33,117,241,153,66,159,219,208,49,56,173,115,22,183,
    127,65,227,116,16,15,159,236,231,18,237,203,232,36,116,50,
    89,248,110,52,124,162,118,174,204,209,82,119,252,80,95,194,
    169,181,43,223,189,196,197,254,198,149,209,84,38,190,27,248,
    223,234,91,183,124,88,145,148,87,9,18,179,197,27,167,206,
    107,209,141,173,156,200,129,159,34,29,38,82,44,200,220,157,
    172,192,21,243,13,24,43,47,158,15,40,116,33,170,79,202,
    207,232,70,38,253,8,27,186,66,171,173,214,16,32,20,8,
    76,60,165,174,8,203,92,110,212,172,229,165,154,85,91,48,
    249,238,99,5,79,29,117,171,182,180,44,244,191,61,4,82,
    221,216,107,212,196,127,0,147,153,180,28,
};

EmbeddedPython embedded_m5_internal_param_MinorOpClass(
    "m5/internal/param_MinorOpClass.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_MinorOpClass.py",
    "m5.internal.param_MinorOpClass",
    data_m5_internal_param_MinorOpClass,
    2203,
    6634);

} // anonymous namespace
