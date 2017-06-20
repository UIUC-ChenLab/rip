#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_FUDesc_vector[] = {
    120,156,197,91,125,136,36,71,21,127,221,243,177,55,251,113,
    187,123,251,117,119,187,201,77,62,46,217,68,115,171,49,151,
    68,19,46,198,124,145,136,119,166,55,225,46,155,104,167,119,
    186,118,183,119,103,186,39,221,189,119,183,113,79,137,123,26,
    63,81,241,3,21,17,17,252,67,5,17,4,65,16,4,65,
    16,4,81,16,4,65,16,2,130,32,8,130,255,9,241,253,
    94,117,207,244,236,204,73,46,179,211,119,187,243,174,182,187,
    166,94,253,234,253,234,85,213,171,170,26,37,255,74,252,121,
    127,149,40,186,106,16,185,252,107,80,157,168,97,208,138,65,
    134,50,200,157,166,173,18,133,247,145,91,162,171,68,43,38,
    41,147,246,56,81,160,23,77,242,71,229,59,101,170,23,228,
    137,65,59,195,164,138,180,82,162,243,254,36,21,85,153,182,
    134,41,124,153,12,195,240,13,186,224,14,145,123,136,88,213,
    10,39,42,82,224,33,194,195,97,121,88,33,119,68,30,14,
    147,59,42,137,17,218,153,32,53,74,43,99,200,182,114,152,
    139,189,155,139,29,151,98,255,128,98,93,126,51,67,238,97,
    100,231,122,189,128,156,69,228,20,125,227,82,202,4,185,82,
    202,26,227,153,108,101,156,36,85,160,205,35,180,114,132,20,
    255,78,210,30,67,78,224,76,209,202,116,10,109,38,147,158,
    205,164,231,50,233,163,153,244,177,76,250,184,164,143,164,202,
    167,90,202,231,69,249,2,173,44,144,226,223,121,173,188,76,
    203,139,179,108,17,239,77,254,183,200,22,161,120,148,197,69,
    21,70,94,224,219,158,191,22,120,38,222,151,33,96,191,26,
    196,80,98,200,199,96,200,31,146,88,209,53,19,67,94,33,
    46,216,64,133,234,38,93,145,196,21,147,118,22,105,215,160,
    205,34,185,5,218,101,53,37,84,96,221,160,61,147,94,42,
    32,195,21,150,69,110,238,155,169,24,107,43,110,74,115,235,
    146,134,232,74,137,118,75,180,124,97,215,196,131,173,10,133,
    63,160,87,23,164,208,67,82,168,73,187,44,139,180,87,164,
    43,101,58,207,153,248,209,102,5,240,141,11,187,140,148,159,
    44,47,22,185,182,103,51,112,1,197,245,66,223,105,168,248,
    48,167,237,39,159,127,92,69,53,251,162,170,197,65,184,56,
    156,230,9,162,83,77,39,222,176,228,75,5,180,70,163,25,
    75,97,129,175,226,17,78,172,121,190,107,55,2,119,187,174,
    226,67,40,201,94,243,234,202,182,229,229,211,141,102,16,198,
    79,132,97,16,90,104,80,121,88,15,156,214,55,208,156,181,
    122,16,169,69,104,19,53,22,138,143,145,123,173,41,37,162,
    2,82,81,124,217,229,90,134,94,51,102,59,233,18,145,27,
    165,45,194,66,34,162,15,177,88,218,8,26,106,105,75,53,
    26,42,84,247,46,173,171,198,105,17,247,68,177,179,90,87,
    75,171,219,94,221,93,186,240,224,253,75,205,157,120,35,240,
    151,248,189,231,199,138,155,164,190,212,209,24,167,56,195,17,
    20,123,201,91,183,61,1,100,111,168,122,83,133,99,120,122,
    28,42,141,9,99,212,40,27,5,99,209,24,227,84,137,63,
    5,99,193,28,49,206,122,128,84,3,76,112,169,152,101,15,
    76,106,208,150,73,225,2,184,177,201,191,6,140,201,12,89,
    198,59,83,222,61,139,182,208,79,55,11,176,184,126,184,43,
    124,98,98,113,206,135,97,98,159,132,20,37,218,44,147,38,
    11,115,76,179,39,220,129,228,236,40,198,228,194,139,20,125,
    157,184,109,153,38,187,148,80,104,175,64,134,63,65,241,48,
    250,53,63,157,101,133,159,20,22,46,47,162,250,103,133,15,
    241,134,23,5,151,124,105,117,164,165,223,44,115,203,124,120,
    231,220,234,38,183,87,116,130,31,188,16,108,87,107,142,239,
    7,113,213,113,221,170,19,199,161,183,186,29,171,168,26,7,
    213,147,209,34,12,105,77,166,148,106,149,183,211,76,41,4,
    115,51,133,244,31,174,87,139,249,143,41,249,67,172,16,169,
    152,233,176,17,184,17,63,71,17,235,42,182,80,201,24,141,
    28,72,69,132,45,54,178,66,61,231,3,205,31,77,107,34,
    148,92,44,167,4,138,84,125,45,30,22,46,58,81,100,75,
    77,240,92,104,135,130,47,58,245,109,37,165,51,127,98,174,
    16,146,186,14,3,37,222,81,128,72,49,11,16,63,240,221,
    29,174,151,87,187,19,42,143,10,253,70,133,128,51,76,190,
    33,150,101,254,191,108,204,154,181,98,66,185,114,74,59,56,
    189,152,196,232,70,98,119,166,224,30,59,152,69,83,60,132,
    96,145,94,120,43,82,248,178,181,0,113,19,196,205,16,39,
    82,184,131,194,60,182,31,243,3,208,99,10,80,129,4,131,
    20,82,72,110,71,79,58,214,238,73,236,0,151,209,35,76,
    244,155,118,143,40,194,89,134,103,32,57,171,244,181,2,69,
    207,193,53,163,231,72,97,232,36,76,119,164,218,157,64,26,
    200,154,0,240,67,41,127,45,144,50,203,204,245,12,51,45,
    216,70,104,105,29,75,125,159,141,28,154,144,214,60,138,42,
    245,104,225,42,196,45,131,110,230,54,181,214,187,168,245,16,
    84,78,36,212,26,19,74,13,243,103,194,172,21,146,182,111,
    141,131,83,251,40,5,62,21,123,240,233,14,164,10,221,104,
    115,162,82,130,241,201,12,149,80,45,51,11,229,44,39,118,
    230,128,32,75,162,57,30,204,207,251,115,60,62,155,50,62,
    191,75,198,103,25,227,101,238,163,29,113,65,124,177,78,148,
    208,20,107,5,154,77,198,221,168,194,178,25,6,151,119,170,
    193,90,53,22,172,240,155,15,159,140,78,157,140,30,98,143,
    88,61,35,190,72,251,68,237,245,66,213,132,215,194,87,159,
    184,92,83,50,226,201,95,182,173,157,148,45,14,203,78,70,
    82,230,211,12,26,210,76,91,88,220,117,20,135,240,210,3,
    109,227,225,86,27,163,202,207,64,201,176,52,112,193,152,99,
    238,12,27,82,19,91,123,101,153,71,201,91,254,124,0,141,
    14,180,138,48,15,182,150,117,61,5,2,192,88,239,236,224,
    199,128,0,88,75,92,226,243,41,47,202,109,94,224,83,72,
    41,254,58,201,204,210,160,79,19,44,207,6,78,40,222,234,
    17,48,245,20,178,127,148,164,47,244,24,219,197,159,44,99,
    60,151,28,236,102,162,7,36,171,30,234,159,161,207,100,58,
    82,58,32,23,146,185,99,118,64,46,182,124,145,80,230,45,
    13,186,197,78,167,5,163,108,56,17,178,105,79,212,238,155,
    109,55,223,154,246,177,39,30,20,127,14,233,226,109,212,228,
    165,54,123,48,164,205,27,83,102,134,19,239,134,184,183,69,
    7,35,125,54,128,74,157,160,107,143,187,182,246,240,47,66,
    115,81,234,58,62,36,179,11,61,15,122,154,203,116,184,152,
    22,213,75,41,213,223,104,81,93,201,112,116,85,86,16,144,
    38,108,188,103,26,188,184,227,217,23,214,82,69,82,37,90,
    41,147,26,194,68,31,75,182,82,186,100,43,39,75,182,246,
    42,111,84,210,21,73,143,201,42,143,176,52,75,86,121,227,
    233,42,143,215,103,99,146,152,76,22,114,188,36,75,150,110,
    83,88,186,33,49,157,44,221,86,102,176,158,66,98,54,89,
    79,173,204,97,149,138,196,81,44,5,145,56,70,238,172,36,
    142,147,59,39,137,121,244,98,140,44,210,139,210,143,120,87,
    248,226,142,193,89,12,120,86,155,182,197,75,77,57,136,203,
    3,245,90,96,221,195,117,167,177,234,58,103,214,161,2,122,
    106,105,183,55,211,74,79,100,43,141,46,107,92,171,222,242,
    231,233,180,242,23,7,234,177,238,231,18,91,149,150,254,233,
    6,53,113,83,207,109,168,106,67,53,86,121,37,187,225,53,
    171,107,117,103,93,44,81,72,64,157,75,65,197,194,189,253,
    211,155,232,110,200,160,90,11,124,30,58,182,161,175,234,42,
    94,226,41,183,122,79,85,198,157,170,23,85,157,85,126,235,
    212,98,221,5,59,189,135,204,155,157,112,61,146,41,242,214,
    37,36,7,110,73,155,215,236,30,47,18,60,234,28,222,59,
    8,136,138,185,109,222,73,221,75,45,71,178,64,3,30,102,
    96,180,70,139,105,105,205,90,76,27,211,70,217,52,210,105,
    105,150,102,178,210,157,238,114,49,182,44,75,114,170,63,92,
    98,208,110,95,189,176,109,141,147,217,14,211,130,161,199,184,
    110,36,83,221,72,60,191,22,102,38,47,248,134,63,80,218,
    128,13,80,26,102,40,115,96,104,92,149,69,99,157,25,176,
    109,4,12,116,110,247,13,102,174,7,24,94,230,59,126,77,
    101,0,157,30,52,32,116,234,84,239,229,190,65,245,232,57,
    234,149,109,167,158,39,34,120,26,81,250,177,30,62,234,58,
    188,64,15,182,213,130,230,78,62,78,64,136,6,117,31,63,
    112,16,190,186,28,231,8,2,234,94,235,15,68,143,174,98,
    11,12,219,206,9,72,18,44,19,149,87,15,28,76,51,84,
    23,189,96,59,202,17,76,170,242,245,190,187,252,108,55,30,
    199,189,184,207,141,13,220,47,99,145,149,168,253,92,223,144,
    102,122,241,77,189,194,108,203,209,141,149,133,114,208,250,197,
    193,0,242,213,141,0,4,173,95,238,27,80,79,143,224,241,
    106,188,3,210,192,89,151,204,136,69,239,87,7,4,42,218,
    94,189,33,160,68,239,55,6,225,30,108,59,119,67,73,96,
    76,171,253,22,81,87,96,18,144,158,234,5,233,11,189,60,
    120,79,72,251,205,244,222,124,32,137,218,239,80,247,136,212,
    177,24,219,109,47,198,164,74,121,14,154,30,191,182,237,239,
    182,171,184,40,237,211,10,59,234,93,81,137,0,53,195,160,
    169,194,120,71,199,219,16,26,183,78,65,220,213,225,200,92,
    85,87,177,178,59,45,16,79,80,107,107,192,85,188,104,14,
    118,108,59,105,35,254,130,109,203,170,202,122,4,226,81,136,
    199,32,158,128,120,10,226,105,136,15,66,160,29,172,115,16,
    207,66,44,67,32,104,105,157,135,120,1,2,1,41,235,165,
    142,230,27,212,90,240,62,46,113,13,69,163,169,202,198,188,
    89,49,203,70,197,168,152,149,194,40,255,84,174,245,99,74,
    68,94,151,147,108,57,119,135,201,92,227,45,132,201,244,233,
    135,36,88,86,78,163,99,67,105,116,76,142,59,32,81,145,
    24,153,14,156,85,210,192,153,14,144,141,166,1,178,177,52,
    64,118,56,13,144,141,167,1,178,137,52,64,54,153,6,200,
    142,164,1,178,169,52,64,54,157,6,200,102,210,0,217,108,
    26,32,155,75,3,100,71,211,0,217,49,114,143,166,33,179,
    99,73,200,204,61,46,137,5,114,231,37,113,19,185,11,146,
    184,153,220,155,36,113,130,220,155,37,81,37,247,132,36,110,
    33,183,42,137,91,201,189,69,18,183,145,123,171,36,110,39,
    247,54,73,156,36,247,118,73,220,65,234,78,218,92,164,149,
    187,200,61,41,79,238,70,156,14,91,50,125,197,233,6,62,
    58,75,208,228,199,116,144,225,57,235,129,92,235,108,61,72,
    201,14,194,181,66,115,215,57,81,159,221,223,129,196,149,193,
    217,228,232,63,83,149,63,161,255,227,226,135,91,198,217,219,
    23,117,171,81,94,222,94,252,225,79,123,212,242,58,90,252,
    88,87,139,219,216,13,120,85,133,65,110,43,61,189,119,220,
    210,250,179,254,16,117,115,200,182,87,131,160,158,243,194,85,
    171,252,121,127,88,102,122,96,169,43,63,55,40,122,48,23,
    141,191,200,32,201,238,10,10,146,41,234,156,195,233,29,190,
    110,60,199,123,224,89,87,113,84,247,106,88,25,181,227,236,
    134,244,67,200,205,129,2,28,165,228,216,66,82,133,95,238,
    179,215,245,207,84,123,65,140,218,16,115,156,173,106,108,109,
    221,191,26,148,5,121,178,215,101,65,107,11,162,158,15,198,
    118,5,126,221,183,253,122,57,68,46,159,7,133,70,190,230,
    27,73,161,105,213,191,25,8,50,102,254,141,66,214,82,253,
    219,129,32,139,110,28,178,150,234,223,81,95,222,127,178,11,
    86,51,104,230,228,249,97,0,214,246,251,12,130,183,23,140,
    152,238,2,225,52,155,202,119,243,14,131,105,173,127,236,207,
    34,83,93,96,84,163,25,231,181,63,33,187,44,208,247,167,
    254,80,28,233,66,17,121,175,230,180,211,170,79,164,178,186,
    63,247,205,172,30,48,46,57,205,12,175,6,189,24,210,88,
    88,231,95,14,154,85,171,106,221,243,115,100,149,232,251,235,
    65,123,43,244,242,252,188,21,107,251,91,127,8,186,93,85,
    152,167,33,224,165,180,194,55,14,186,127,135,249,153,2,125,
    2,234,254,126,208,125,162,86,87,78,94,97,0,125,115,131,
    245,253,163,63,20,243,93,40,214,113,24,176,94,15,106,57,
    6,53,80,207,14,189,255,236,15,85,247,10,155,103,10,246,
    170,83,219,202,115,55,53,81,249,175,125,88,174,127,246,216,
    99,80,15,157,72,229,57,111,148,145,29,74,255,189,15,77,
    122,26,93,208,60,222,70,195,80,244,21,172,105,137,66,165,
    215,0,112,1,236,188,127,156,138,220,13,113,156,251,17,28,
    231,222,149,35,185,182,169,79,116,183,163,85,37,202,186,110,
    95,93,178,59,90,65,199,23,113,160,195,194,193,185,204,210,
    14,205,33,111,7,26,220,194,94,196,127,136,210,35,179,227,
    70,193,152,54,198,250,217,232,219,199,217,237,104,67,147,54,
    199,153,168,28,150,79,21,255,247,160,93,228,90,24,248,121,
    157,51,1,123,68,223,155,253,161,232,30,172,114,116,36,24,
    172,160,206,52,14,32,52,210,99,165,19,69,222,186,159,233,
    57,103,114,33,153,44,119,68,117,201,232,215,57,246,152,19,
    41,89,45,228,232,29,101,98,36,90,15,13,0,143,231,71,
    42,140,243,198,163,181,142,100,240,188,61,191,214,29,33,230,
    150,82,225,197,220,79,2,37,106,15,27,7,60,181,168,57,
    77,167,230,229,182,198,198,212,34,85,57,217,3,75,199,30,
    255,13,62,112,61,109,36,251,112,139,239,160,236,246,190,245,
    17,8,217,208,111,239,229,99,91,74,54,140,44,5,129,19,
    246,22,78,148,91,56,182,109,225,236,179,245,10,4,10,180,
    112,212,214,186,4,177,67,233,36,224,10,196,39,32,94,131,
    216,131,248,20,4,206,179,89,159,133,248,60,4,142,78,89,
    95,130,248,10,132,28,41,248,26,4,14,182,88,223,132,248,
    54,4,78,80,88,56,163,96,125,15,226,251,29,93,52,57,
    112,208,57,33,177,145,229,229,142,150,29,84,243,58,92,226,
    143,80,52,174,124,149,141,121,163,108,98,255,255,186,126,134,
    246,159,15,168,24,50,20,236,187,125,175,113,224,202,160,190,
    140,180,19,89,120,98,141,183,26,68,31,30,76,206,105,192,
    182,50,141,56,235,52,244,77,95,185,205,106,221,6,129,77,
    111,235,206,150,225,17,23,149,27,96,250,110,29,79,241,228,
    150,131,92,106,176,222,3,129,179,14,178,74,217,119,184,6,
    135,58,66,94,138,70,252,64,46,83,54,78,159,74,91,235,
    84,211,9,157,70,98,20,185,203,222,56,45,33,216,108,158,
    115,205,76,139,94,163,4,157,167,235,165,242,183,241,238,49,
    84,85,234,214,253,205,101,175,161,111,100,203,212,53,251,222,
    13,29,78,207,236,123,202,174,201,115,234,60,128,136,97,123,
    108,98,100,241,14,156,93,250,126,142,190,218,120,6,33,227,
    8,55,55,113,201,185,50,94,97,166,225,126,125,193,24,230,
    201,110,177,48,58,81,41,142,142,84,138,149,161,130,220,83,
    29,51,166,204,225,98,101,100,246,125,21,99,152,115,102,127,
    102,183,42,198,255,0,91,28,230,156,
};

EmbeddedPython embedded_m5_internal_FUDesc_vector(
    "m5/internal/FUDesc_vector.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/FUDesc_vector.py",
    "m5.internal.FUDesc_vector",
    data_m5_internal_FUDesc_vector,
    3498,
    17301);

} // anonymous namespace
