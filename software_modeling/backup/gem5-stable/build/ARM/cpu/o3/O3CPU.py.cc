#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_O3CPU[] = {
    120,156,173,152,91,119,19,71,18,128,91,178,145,47,24,108,
    108,12,225,62,220,197,197,40,64,32,132,144,4,91,182,65,
    137,177,197,72,94,206,250,69,103,52,221,178,218,30,205,136,
    233,25,99,239,201,62,177,111,251,176,121,216,95,176,191,100,
    31,243,184,255,104,183,170,122,122,212,50,132,156,61,193,178,
    198,211,95,87,87,87,245,165,186,218,62,203,126,70,224,251,
    220,97,76,197,240,194,225,183,192,2,198,122,5,182,85,96,
    5,44,23,89,80,100,205,236,109,68,191,141,176,96,148,245,
    70,217,214,104,46,115,68,215,140,178,160,196,122,37,182,85,
    202,107,198,160,230,8,19,163,172,83,96,188,196,254,198,216,
    123,198,254,188,53,206,248,24,107,148,199,161,91,249,95,248,
    41,23,224,45,193,98,59,149,1,95,9,247,52,193,199,109,
    253,58,6,143,37,79,137,106,125,83,131,9,120,108,60,172,
    118,133,191,43,226,100,18,74,203,34,150,123,128,234,155,190,
    241,112,20,91,161,135,127,135,55,193,208,49,176,108,171,136,
    174,110,141,160,97,96,37,90,5,69,178,19,220,203,138,37,
    42,142,154,226,24,19,227,108,103,130,129,59,224,200,251,34,
    219,154,52,100,140,241,113,34,71,137,76,49,14,112,146,200,
    49,139,28,37,114,220,34,83,68,166,45,114,140,200,140,209,
    124,156,241,105,34,39,12,153,97,252,4,145,89,67,102,25,
    159,35,50,103,233,57,73,228,164,69,230,137,204,91,228,20,
    145,83,22,57,77,228,180,213,251,23,68,190,176,100,206,16,
    57,99,145,179,68,206,90,228,28,145,115,150,158,243,68,206,
    91,50,23,136,92,48,228,34,227,151,136,92,180,100,28,34,
    151,44,61,151,137,56,22,185,66,228,178,69,174,18,185,66,
    228,42,19,215,112,201,241,107,4,175,91,202,175,19,185,97,
    145,27,68,110,90,170,110,18,41,91,164,76,228,150,105,117,
    139,241,219,68,110,91,122,238,16,185,99,90,221,101,124,129,
    200,93,139,220,35,178,96,77,98,133,200,61,139,124,73,164,
    98,200,125,198,31,16,249,146,200,125,38,30,48,254,144,200,
    67,35,243,21,227,143,136,124,101,200,99,198,191,38,242,200,
    34,79,136,60,54,4,126,191,33,242,181,33,79,25,255,150,
    200,19,139,60,35,242,13,110,129,173,167,76,124,203,248,119,
    236,12,223,100,187,37,22,135,35,226,25,219,121,130,190,157,
    132,202,144,101,237,4,180,123,78,237,190,179,150,240,34,145,
    239,13,89,98,188,74,228,7,203,162,101,34,207,137,44,50,
    190,194,248,42,145,37,67,94,48,254,146,72,149,200,50,227,
    53,198,127,36,178,98,201,252,68,100,213,146,89,35,242,194,
    146,121,69,228,165,37,179,78,164,102,100,54,24,175,19,249,
    145,200,79,76,172,49,254,154,137,87,108,7,36,33,220,185,
    84,187,97,102,38,27,155,31,216,46,132,154,6,213,213,25,
    111,98,48,217,122,205,220,70,249,79,16,152,92,140,78,106,
    26,30,126,63,173,68,15,43,28,3,216,189,110,215,199,0,
    103,190,85,12,95,40,9,33,171,81,46,194,203,122,82,194,
    0,40,123,50,220,46,99,148,211,1,17,163,185,31,40,77,
    240,161,30,194,163,210,141,122,162,178,43,122,61,17,139,7,
    149,109,209,123,68,143,5,149,120,237,64,84,84,236,87,178,
    238,41,116,222,235,31,36,71,161,93,79,244,162,248,160,213,
    139,184,184,133,186,176,99,86,252,184,101,9,3,203,144,172,
    107,75,144,53,227,84,80,201,45,25,123,254,152,81,199,161,
    93,44,222,166,50,22,45,223,243,187,66,45,252,159,118,185,
    227,102,172,62,151,77,39,176,113,218,239,71,113,210,74,188,
    93,209,138,246,68,124,127,96,150,36,237,199,224,81,11,101,
    34,189,192,241,163,52,76,228,175,136,113,148,171,232,136,83,
    135,246,74,162,97,106,158,206,49,31,70,221,73,34,167,35,
    18,191,235,112,17,120,7,84,227,138,208,235,125,80,115,3,
    245,43,149,138,202,202,190,240,211,68,84,222,196,50,17,109,
    207,223,253,152,146,106,212,235,201,228,80,141,28,55,38,173,
    18,124,39,121,210,149,207,17,158,205,97,59,237,116,68,236,
    40,249,23,225,200,208,105,31,36,66,73,7,101,202,185,204,
    219,84,164,34,23,233,73,63,142,22,162,190,114,250,34,94,
    72,186,177,240,184,58,53,228,9,215,222,106,251,110,126,218,
    149,33,217,83,67,190,12,85,205,231,230,28,174,153,26,140,
    47,185,248,123,61,198,218,206,143,245,248,65,213,96,222,134,
    170,166,6,238,14,186,28,168,249,173,206,245,180,224,58,162,
    6,131,1,251,100,3,245,192,248,131,162,66,11,233,42,167,
    44,195,68,196,33,172,66,168,74,96,221,213,86,222,56,176,
    186,183,197,45,133,187,107,89,170,190,151,79,62,45,6,173,
    73,151,49,80,13,122,211,236,36,14,116,26,250,137,140,80,
    239,38,172,114,167,31,69,193,239,13,171,175,221,215,38,95,
    28,114,47,22,81,12,129,208,44,182,193,24,102,67,166,59,
    70,208,120,155,122,202,44,85,220,100,68,155,177,215,119,2,
    47,17,161,127,160,102,7,11,193,194,242,8,10,223,69,97,
    9,157,218,203,186,19,65,207,96,228,59,47,230,138,204,76,
    67,233,123,232,159,186,253,91,13,224,139,242,135,196,207,99,
    224,73,123,109,144,140,58,78,16,121,60,219,28,34,76,98,
    41,148,186,48,36,160,146,40,22,195,18,146,14,136,59,67,
    98,253,192,243,133,194,129,82,93,217,73,28,143,115,176,88,
    116,176,177,143,201,176,170,225,208,116,163,52,224,48,120,125,
    17,114,116,217,217,147,81,160,237,2,105,45,41,56,89,143,
    150,41,231,134,54,64,57,64,118,82,149,100,69,249,203,127,
    70,24,169,28,118,165,162,205,149,161,74,148,233,30,151,20,
    244,232,244,99,193,165,15,245,96,34,153,209,70,193,61,47,
    144,28,198,159,75,204,202,201,249,53,15,250,161,32,4,166,
    104,133,20,107,105,100,213,105,244,131,160,18,137,83,91,182,
    235,206,12,25,228,102,75,102,137,230,69,73,60,5,212,181,
    225,97,235,30,40,152,152,192,193,61,176,13,44,22,219,82,
    193,118,80,135,199,215,8,118,192,205,4,78,88,88,207,208,
    102,32,79,87,141,230,162,251,98,165,217,170,53,22,233,216,
    245,226,30,253,221,127,242,88,93,250,184,58,223,183,186,188,
    58,36,131,131,24,167,180,135,14,205,255,191,113,254,157,33,
    225,67,219,195,172,37,220,67,141,87,77,103,32,72,203,30,
    237,111,234,168,155,208,150,1,16,136,140,204,100,109,244,6,
    233,71,129,244,245,217,95,247,226,68,162,57,66,7,107,20,
    90,107,188,118,26,93,47,70,141,117,18,149,28,173,187,106,
    213,163,94,152,114,152,241,92,210,139,97,91,163,207,243,153,
    92,237,176,26,117,101,80,243,41,5,198,16,119,99,233,176,
    134,171,86,213,39,84,208,204,185,112,0,115,55,106,195,160,
    159,200,154,101,129,69,43,35,161,48,237,101,99,68,131,180,
    20,123,33,140,80,221,172,107,90,154,43,33,45,199,102,99,
    195,121,69,185,146,131,185,82,64,153,8,70,237,9,147,137,
    252,75,103,34,144,190,157,129,27,31,38,203,255,192,107,38,
    94,151,11,120,217,254,43,92,182,147,34,102,213,63,51,182,
    51,130,215,75,200,160,224,86,153,28,193,139,37,60,223,179,
    81,168,106,149,216,207,5,76,141,81,108,140,237,140,99,226,
    137,239,37,214,26,179,170,38,134,171,52,156,100,89,113,146,
    133,211,120,59,125,241,18,166,26,239,164,250,170,223,40,99,
    0,93,119,113,250,93,92,41,214,189,28,147,165,197,184,215,
    92,91,162,43,250,187,40,222,197,16,64,75,69,236,203,100,
    35,92,137,99,72,97,80,67,218,199,61,110,200,28,138,123,
    113,184,17,6,7,27,225,26,52,210,156,226,26,238,99,140,
    193,43,174,187,225,62,117,178,155,188,19,129,172,147,37,85,
    16,22,96,182,0,46,186,175,28,216,108,151,41,73,34,171,
    84,182,239,202,116,188,98,158,229,98,176,119,17,187,216,111,
    130,65,126,213,11,148,160,188,143,254,129,224,103,255,45,64,
    33,153,180,93,156,71,42,240,164,77,110,66,130,215,130,227,
    100,52,243,140,210,109,109,173,8,58,212,193,103,200,26,113,
    156,32,108,103,14,87,251,233,63,81,27,174,111,86,152,41,
    204,20,167,11,37,248,76,21,206,193,103,118,228,72,129,172,
    48,254,170,44,206,148,209,103,154,143,86,11,143,206,86,139,
    86,110,11,51,246,52,192,34,101,192,7,125,65,220,223,223,
    111,117,97,65,131,243,56,109,126,224,41,5,155,162,27,113,
    23,7,198,197,213,234,78,154,97,163,45,67,202,55,67,37,
    183,33,14,80,193,131,24,181,39,19,189,71,40,7,167,204,
    149,70,174,122,224,7,66,37,56,68,58,225,106,70,20,87,
    150,241,252,38,172,147,162,33,140,41,133,20,239,62,16,213,
    233,193,16,198,46,233,168,120,131,199,61,181,164,162,142,249,
    13,88,76,116,67,32,246,26,131,40,161,57,171,95,157,158,
    105,109,51,166,99,27,206,89,61,219,124,214,232,29,198,71,
    115,87,181,73,185,78,157,203,124,168,243,48,55,227,100,243,
    163,185,193,3,165,166,61,164,107,3,235,141,87,57,68,141,
    18,51,174,102,148,165,92,154,227,106,227,89,102,167,117,78,
    26,73,93,196,249,127,215,214,239,56,147,171,155,117,200,224,
    168,221,178,232,120,105,144,100,4,43,59,41,189,230,190,234,
    216,249,161,89,16,138,7,14,105,7,116,15,88,86,148,184,
    13,202,152,155,173,233,212,140,148,232,193,182,32,10,97,86,
    6,189,13,102,90,39,93,6,225,2,94,123,189,162,143,67,
    42,53,242,18,234,132,243,105,89,244,105,207,53,48,113,162,
    237,177,4,190,232,232,112,76,139,80,61,198,41,149,224,126,
    164,156,164,5,233,71,11,22,183,23,183,224,18,35,35,189,
    23,214,86,27,77,234,24,11,141,70,77,23,198,244,225,1,
    231,139,34,35,225,189,14,25,64,45,76,92,177,173,13,201,
    208,42,166,23,4,241,100,108,113,61,210,235,186,178,90,197,
    26,138,106,100,103,3,162,15,153,24,218,245,116,162,3,169,
    229,142,102,34,48,248,134,160,114,213,67,189,38,31,48,233,
    0,206,102,35,193,19,146,44,5,33,146,200,78,193,41,141,
    96,72,50,128,97,7,220,160,141,167,43,242,147,86,207,105,
    47,169,25,217,227,166,60,16,201,244,129,101,153,204,116,14,
    6,66,25,211,107,202,146,211,231,111,126,252,146,178,102,148,
    198,184,212,194,100,169,78,190,64,204,130,130,139,135,58,173,
    240,118,222,136,166,40,20,144,204,192,97,237,94,26,10,226,
    127,40,146,211,63,112,174,163,130,95,224,129,65,187,84,156,
    30,197,207,108,17,62,5,248,232,39,132,241,252,189,104,253,
    53,239,133,249,252,45,147,203,74,19,217,39,111,55,82,42,
    204,140,205,12,88,225,208,167,56,69,117,115,133,137,226,122,
    121,194,140,69,239,209,61,88,96,50,20,217,154,154,208,172,
    143,97,94,209,240,96,41,142,246,15,92,60,107,220,231,249,
    73,218,97,217,255,169,62,211,144,81,103,207,244,25,245,61,
    222,1,232,230,57,83,152,132,207,140,254,22,255,7,172,197,
    50,137,
};

EmbeddedPython embedded_m5_objects_O3CPU(
    "m5/objects/O3CPU.py",
    "/home/kemmere2/gem5/gem5-stable/src/cpu/o3/O3CPU.py",
    "m5.objects.O3CPU",
    data_m5_objects_O3CPU,
    2546,
    6304);

} // anonymous namespace
