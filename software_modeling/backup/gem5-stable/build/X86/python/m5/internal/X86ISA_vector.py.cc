#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_X86ISA_vector[] = {
    120,156,197,91,125,136,36,71,21,127,221,243,177,59,251,113,
    187,123,251,117,123,119,185,155,124,92,178,137,230,86,99,46,
    137,38,156,137,49,134,139,120,49,189,145,187,108,162,157,222,
    233,218,221,222,157,233,158,116,247,222,221,198,61,37,238,105,
    252,68,197,15,84,68,68,16,21,17,4,65,16,4,65,16,
    4,65,20,4,65,16,132,128,32,8,130,255,9,66,124,191,
    87,221,51,61,59,115,146,203,236,244,221,238,188,171,237,238,
    169,87,191,122,191,122,85,239,85,117,141,146,127,37,254,60,
    90,37,138,94,52,136,92,254,53,168,78,212,48,104,197,32,
    67,25,228,206,208,86,137,194,251,201,45,209,53,162,21,147,
    148,73,123,92,40,208,243,38,249,99,242,157,50,213,11,114,
    197,160,157,17,82,69,90,41,209,5,127,138,138,170,76,91,
    35,20,190,72,134,97,248,6,93,116,135,200,29,166,107,92,
    59,23,42,82,225,48,225,226,136,92,172,144,59,42,23,71,
    200,29,147,194,40,237,76,146,26,163,149,113,60,182,114,136,
    171,189,135,171,157,144,106,255,128,106,93,190,51,75,238,33,
    60,206,237,122,14,79,22,241,164,232,155,144,90,38,201,149,
    90,214,24,207,84,235,193,41,82,5,218,60,76,43,135,73,
    241,239,20,237,49,228,4,206,52,173,204,164,208,102,51,229,
    185,76,121,94,202,135,211,138,167,91,21,31,145,138,23,104,
    101,129,20,255,30,209,21,151,105,121,113,142,123,219,123,157,
    255,45,114,111,83,60,198,226,146,10,35,47,240,109,207,95,
    11,60,19,247,203,16,176,77,13,98,40,49,210,227,48,210,
    143,72,44,228,154,137,145,174,18,87,108,160,65,117,147,174,
    74,225,170,73,59,139,180,107,208,102,145,220,2,237,178,154,
    18,26,176,110,208,158,73,47,20,240,192,85,150,69,238,202,
    19,84,140,181,133,54,165,43,117,77,67,116,181,68,187,37,
    90,190,184,107,226,194,86,133,194,239,211,203,199,165,210,97,
    169,212,164,93,150,69,218,43,210,213,50,93,224,135,248,210,
    102,5,240,141,139,187,140,148,175,44,47,22,185,181,231,51,
    112,1,197,245,66,223,105,168,248,16,151,237,139,15,61,112,
    110,249,49,251,146,170,197,65,184,56,146,62,19,68,167,155,
    78,188,97,201,151,10,232,141,70,51,150,202,2,95,197,163,
    92,88,243,124,215,110,4,238,118,93,197,195,168,201,94,243,
    234,202,182,229,230,185,70,51,8,227,39,194,48,8,45,116,
    168,92,172,7,78,235,27,232,206,90,61,136,212,34,180,137,
    26,11,213,199,120,122,173,41,53,162,1,210,80,124,217,85,
    81,45,244,154,49,219,73,215,136,167,81,219,34,44,36,34,
    250,0,139,165,141,160,161,150,182,84,163,161,66,117,223,210,
    186,106,156,17,113,111,20,59,171,117,181,180,186,237,213,221,
    37,70,189,212,220,137,55,2,127,137,239,123,126,172,184,75,
    234,75,29,157,113,154,31,56,140,106,47,123,235,182,39,128,
    236,13,85,111,170,112,28,87,143,66,165,49,105,140,25,101,
    163,96,44,26,227,92,42,241,167,96,28,55,71,141,243,30,
    32,213,0,19,92,42,102,217,3,147,26,180,101,82,120,28,
    220,216,228,95,3,198,100,134,44,227,158,41,247,158,65,95,
    232,171,155,5,88,92,95,220,21,62,49,177,248,201,71,96,
    98,159,132,20,37,218,44,147,38,11,115,76,179,39,220,129,
    228,199,81,141,201,149,23,41,250,26,113,223,50,77,118,41,
    161,208,94,129,12,127,146,226,17,140,89,190,58,199,10,63,
    33,44,92,94,68,243,207,11,31,226,13,47,10,46,251,210,
    235,40,203,184,89,230,158,249,224,206,211,171,155,220,95,209,
    73,190,240,92,176,93,173,57,190,31,196,85,199,117,171,78,
    28,135,222,234,118,172,162,106,28,84,79,69,139,48,164,53,
    149,82,170,85,223,78,51,165,16,204,205,20,210,127,184,94,
    45,230,63,166,229,15,177,66,164,98,166,195,70,224,70,124,
    29,85,172,171,216,66,35,99,116,114,32,13,17,182,216,120,
    20,234,249,57,208,252,177,180,37,66,201,197,114,74,160,72,
    213,215,226,17,225,162,19,69,182,180,4,215,133,118,168,248,
    146,83,223,86,82,59,243,39,230,6,161,168,219,48,80,226,
    29,1,136,20,179,0,241,3,223,221,225,118,121,181,187,160,
    242,136,208,111,76,8,56,203,228,27,98,89,230,255,203,198,
    156,89,43,38,148,43,167,180,131,211,139,73,140,110,36,118,
    103,10,238,177,131,89,52,197,67,8,22,25,133,183,161,132,
    47,91,199,33,110,129,56,1,113,50,133,59,40,204,227,251,
    49,63,8,61,166,0,21,72,48,72,33,133,228,118,140,164,
    133,246,72,98,7,184,140,17,97,98,220,180,71,68,17,206,
    50,60,11,201,143,202,88,43,80,244,44,92,51,70,142,84,
    134,65,194,116,71,169,61,8,164,131,172,73,0,31,78,249,
    107,129,148,89,102,174,103,152,105,193,54,66,75,107,33,245,
    125,54,158,208,132,180,142,161,170,82,143,30,174,66,220,58,
    232,110,110,83,107,189,139,90,15,67,229,100,66,173,113,161,
    212,8,127,38,205,90,33,233,251,214,60,56,189,143,82,224,
    83,177,7,159,238,68,169,208,141,54,39,42,37,24,223,151,
    161,18,154,101,102,161,156,231,194,206,60,16,100,73,52,207,
    147,249,5,127,158,231,103,83,230,231,183,201,252,44,115,188,
    172,107,180,35,46,136,47,214,133,18,186,98,173,64,115,201,
    188,27,85,88,54,195,224,202,78,53,88,171,198,130,21,126,
    243,145,83,209,233,83,209,195,236,17,171,103,197,23,105,159,
    168,189,94,168,154,240,90,248,234,19,87,106,74,102,60,249,
    203,182,181,147,178,197,97,217,201,76,202,124,154,69,71,154,
    105,15,139,187,142,226,16,94,122,160,125,60,210,234,99,52,
    249,41,40,25,145,14,46,24,243,204,157,17,67,90,98,107,
    175,44,235,40,185,203,159,247,160,211,129,86,17,214,184,214,
    178,110,167,64,0,24,235,173,29,252,24,16,0,107,137,107,
    252,80,202,139,114,155,23,248,20,82,138,191,74,178,178,52,
    232,83,4,203,179,129,19,138,183,70,4,76,61,141,199,63,
    66,50,22,122,204,237,226,79,150,49,159,203,19,236,102,162,
    7,229,81,61,213,63,69,159,206,12,164,116,66,46,36,107,
    199,236,132,92,108,249,34,161,204,27,154,116,139,157,78,11,
    70,217,112,34,60,166,61,81,123,108,182,221,124,107,217,199,
    158,120,80,252,25,214,213,219,104,201,11,109,246,96,74,59,
    102,76,155,25,78,188,29,226,190,22,29,140,244,218,0,26,
    117,146,174,63,239,218,218,195,63,15,205,69,105,235,196,144,
    172,46,244,58,232,28,215,233,112,53,45,170,151,82,170,191,
    214,162,186,146,233,232,154,68,16,144,38,108,188,103,26,28,
    184,241,234,11,113,82,145,84,137,86,202,164,134,176,208,71,
    56,86,74,195,177,114,18,142,181,35,184,49,41,87,164,60,
    46,17,28,33,236,74,34,184,137,52,130,227,216,107,92,10,
    83,73,144,198,225,86,18,150,77,35,44,67,97,38,9,203,
    86,102,17,79,161,48,151,196,83,43,243,136,64,81,56,130,
    48,15,133,5,114,231,164,112,148,220,121,41,28,195,40,198,
    204,34,163,40,253,136,119,133,47,238,152,156,197,128,231,181,
    105,91,188,212,148,131,184,50,80,175,5,214,61,82,119,26,
    171,174,115,118,29,42,160,167,150,14,123,51,109,244,100,182,
    209,24,178,198,245,218,45,127,158,73,27,127,105,160,30,235,
    1,174,177,213,104,25,159,110,80,19,55,245,236,134,170,54,
    84,99,149,35,217,13,175,89,93,171,59,235,98,137,66,2,
    234,233,20,84,44,220,219,191,188,137,238,129,12,170,181,192,
    231,169,99,27,250,170,174,226,16,79,185,213,123,171,50,239,
    84,189,168,234,172,242,93,167,22,235,33,216,233,61,100,221,
    236,132,235,145,44,145,183,46,163,56,112,75,218,28,179,123,
    28,36,120,212,57,189,119,16,16,13,115,219,188,147,182,151,
    90,142,228,56,13,120,154,129,209,26,45,166,165,45,107,49,
    109,92,27,101,211,72,151,165,89,154,73,164,59,211,229,98,
    108,9,75,114,106,63,92,98,208,238,95,29,216,182,230,201,
    236,128,105,193,208,115,92,55,146,233,110,36,158,95,11,51,
    139,23,124,195,31,40,109,192,6,40,13,51,148,57,48,52,
    174,202,162,177,206,14,216,54,2,6,58,183,251,6,51,223,
    3,12,135,249,142,95,83,25,64,103,6,13,8,131,58,213,
    123,165,111,80,61,70,142,122,105,219,169,231,137,8,158,70,
    148,126,180,135,143,186,1,47,208,131,109,181,160,185,147,143,
    19,16,162,65,221,199,14,28,132,175,174,196,57,130,128,186,
    87,250,3,209,99,168,216,2,195,182,115,2,146,36,203,68,
    229,181,3,7,211,12,213,37,47,216,142,114,4,147,170,124,
    181,239,33,63,215,141,199,113,47,237,115,99,3,247,203,8,
    178,18,181,159,237,27,210,108,47,190,169,151,152,109,57,186,
    177,178,80,14,90,191,48,24,64,190,186,25,128,160,245,75,
    125,3,234,233,17,60,142,198,59,32,13,156,117,201,138,88,
    244,126,101,64,160,162,237,213,155,2,74,244,126,125,16,238,
    193,182,115,55,148,36,198,180,218,111,18,117,37,38,1,233,
    201,94,144,62,223,203,131,247,132,180,223,76,239,204,7,146,
    168,253,54,117,207,72,29,193,216,110,59,24,147,38,229,57,
    105,122,124,219,182,191,211,110,226,162,244,79,43,237,168,119,
    69,37,3,212,12,131,166,10,227,29,157,111,67,106,220,58,
    13,113,119,135,35,115,85,93,197,202,238,180,64,60,73,173,
    173,1,87,113,208,28,236,216,118,210,71,252,5,219,150,168,
    202,122,55,196,99,16,143,67,60,1,241,36,196,57,136,247,
    67,160,31,172,167,33,158,129,88,134,64,210,210,186,0,241,
    28,4,18,82,214,11,29,221,55,168,88,240,126,174,113,13,
    85,163,171,202,198,49,179,98,150,141,138,81,49,43,133,49,
    254,169,92,239,199,148,140,188,174,39,217,114,238,78,147,185,
    198,27,72,147,233,147,13,73,178,172,156,102,199,134,210,236,
    152,28,101,64,161,34,57,50,157,56,171,164,137,51,157,32,
    27,75,19,100,227,105,130,236,80,154,32,155,72,19,100,147,
    105,130,108,42,77,144,29,78,19,100,211,105,130,108,38,77,
    144,205,166,9,178,185,52,65,54,159,38,200,142,164,9,178,
    5,114,143,164,41,179,133,36,101,230,30,149,194,113,114,143,
    73,225,22,114,143,75,225,4,185,183,72,225,36,185,39,164,
    80,37,247,164,20,110,37,183,42,133,219,200,189,85,10,183,
    147,123,155,20,238,32,247,118,41,156,34,247,14,41,220,73,
    234,46,218,92,164,149,187,201,61,37,87,238,65,158,14,91,
    50,125,229,233,6,62,59,75,210,228,135,116,144,233,57,235,
    193,92,219,108,61,68,201,14,194,245,82,115,55,184,80,159,
    219,63,128,196,149,193,217,228,232,63,83,149,63,166,255,227,
    226,71,90,198,217,219,151,117,171,81,94,222,94,252,225,79,
    122,180,242,6,122,124,161,171,199,109,236,6,188,172,194,32,
    183,72,79,239,29,183,180,254,180,63,68,221,28,178,237,213,
    32,168,231,28,184,106,149,63,235,15,203,108,15,44,117,229,
    231,6,69,79,230,162,241,231,25,36,217,93,65,65,50,77,
    157,107,56,189,195,215,141,231,104,15,60,235,42,142,234,94,
    13,145,81,59,207,110,200,56,132,220,28,40,192,49,74,142,
    45,36,77,248,197,62,123,221,248,74,181,23,196,168,13,49,
    199,213,170,198,214,214,253,203,65,89,144,23,123,93,22,180,
    182,32,234,249,96,108,55,224,87,125,219,175,151,67,228,250,
    121,82,104,228,107,190,209,20,154,86,253,235,129,32,99,230,
    223,44,100,45,213,191,25,8,178,232,230,33,107,169,254,45,
    245,229,253,167,186,96,53,131,102,78,158,31,6,96,109,191,
    203,32,120,115,201,136,153,46,16,78,179,169,124,55,239,52,
    152,214,250,251,254,44,50,221,5,70,53,154,113,94,251,19,
    178,203,2,125,127,236,15,197,225,46,20,145,247,114,78,59,
    173,250,68,42,171,251,83,223,204,234,1,227,178,211,204,240,
    106,208,193,144,198,194,58,255,124,208,172,90,85,235,158,159,
    35,171,68,223,95,14,218,91,97,148,231,231,173,88,219,95,
    251,67,208,237,170,194,60,13,1,47,165,21,254,237,160,199,
    119,152,159,41,48,38,160,238,181,131,30,19,181,186,114,242,
    74,3,232,55,55,88,223,223,251,67,113,172,11,197,58,14,
    3,214,235,65,45,199,164,6,218,217,161,247,31,253,161,234,
    142,176,121,165,96,175,58,181,173,60,119,83,19,149,255,220,
    135,229,198,87,143,61,38,245,208,137,84,158,235,70,153,217,
    161,244,95,251,208,164,167,209,5,205,123,219,104,24,138,126,
    5,107,70,178,80,233,107,0,120,1,236,130,127,148,138,60,
    12,113,156,251,221,56,206,189,43,71,114,109,83,159,232,110,
    103,171,74,148,117,221,190,186,108,119,244,130,206,47,226,64,
    135,133,131,115,153,208,14,221,33,119,7,154,220,194,94,196,
    191,137,210,35,179,19,70,193,152,49,198,251,217,232,219,199,
    217,237,104,67,147,54,199,149,168,28,150,79,21,255,231,160,
    93,228,90,24,248,121,157,51,1,123,68,223,127,251,67,209,
    61,89,229,232,72,48,89,65,221,235,25,12,111,58,53,210,
    35,210,137,34,111,221,207,140,156,179,185,144,76,194,29,81,
    109,26,253,58,199,30,107,34,37,209,66,142,222,81,22,70,
    162,181,52,0,60,158,31,169,48,206,27,143,214,58,156,193,
    243,230,252,90,119,134,152,123,74,133,151,114,63,9,148,168,
    29,53,14,120,105,81,115,154,78,205,203,45,198,198,210,34,
    85,121,168,7,150,142,61,254,155,124,224,122,202,72,246,225,
    22,223,66,217,237,125,235,195,16,178,161,223,222,203,199,182,
    148,108,24,89,10,2,39,236,45,156,40,183,112,108,219,194,
    217,103,235,37,8,84,104,225,168,173,117,25,98,135,210,69,
    192,85,136,143,67,188,2,177,7,241,73,8,156,103,179,62,
    3,241,57,8,28,157,178,190,8,241,101,8,57,82,240,85,
    8,28,108,177,190,1,241,45,8,156,160,176,112,70,193,250,
    46,196,247,58,134,104,114,224,160,115,65,98,227,145,23,59,
    122,118,80,221,235,112,141,63,64,213,120,229,171,108,28,51,
    202,38,246,255,111,232,103,104,255,249,128,138,33,83,193,190,
    183,239,53,14,228,213,245,203,72,59,145,133,43,214,68,171,
    67,244,225,193,228,156,6,108,43,203,136,243,78,67,191,233,
    43,111,179,90,183,67,96,211,219,186,171,101,120,228,69,229,
    13,48,253,110,29,47,241,228,45,7,121,169,193,122,7,4,
    206,58,72,148,178,239,112,13,14,117,132,28,138,70,124,65,
    94,166,108,156,57,157,246,214,233,166,19,58,141,196,40,242,
    46,123,227,140,212,209,253,204,178,215,208,111,78,203,18,51,
    123,223,13,29,46,207,238,187,202,46,196,115,234,236,232,197,
    0,61,54,27,178,237,26,56,11,244,123,52,250,21,196,179,
    72,237,70,143,178,192,203,200,149,137,10,51,2,239,193,23,
    140,17,94,148,22,11,99,147,149,226,216,104,165,88,25,42,
    200,251,164,227,198,180,57,82,172,140,206,189,171,98,140,240,
    147,250,103,110,171,98,252,15,183,41,146,227,
};

EmbeddedPython embedded_m5_internal_X86ISA_vector(
    "m5/internal/X86ISA_vector.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/X86ISA_vector.py",
    "m5.internal.X86ISA_vector",
    data_m5_internal_X86ISA_vector,
    3468,
    17171);

} // anonymous namespace
