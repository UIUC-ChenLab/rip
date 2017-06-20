#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_GenericTimerMem[] = {
    120,156,197,88,235,115,219,198,17,223,3,64,74,164,36,75,
    178,94,126,200,22,237,68,49,235,105,164,214,141,235,206,68,
    117,235,56,143,73,102,172,184,160,83,59,76,166,40,4,156,
    40,80,32,192,1,78,178,153,145,218,153,200,211,199,183,126,
    201,31,208,15,253,208,255,166,127,77,191,54,187,123,0,4,
    81,146,227,153,214,172,36,158,142,119,123,123,251,248,237,222,
    222,121,144,253,84,240,243,235,6,64,250,111,1,224,227,159,
    128,16,160,39,160,45,64,72,1,254,60,236,86,32,121,15,
    252,10,188,4,104,27,32,13,56,194,142,9,95,25,16,77,
    242,154,42,132,38,143,8,24,212,65,90,208,174,192,211,104,
    22,44,89,133,221,58,36,191,7,33,68,36,224,153,63,6,
    254,56,188,68,238,216,169,49,195,113,160,193,58,15,214,192,
    159,224,193,58,248,147,220,153,128,193,12,200,73,104,79,17,
    89,251,2,178,189,141,108,167,153,237,191,136,173,143,51,11,
    224,95,32,114,148,235,75,162,180,136,146,247,155,102,46,51,
    185,148,179,208,190,152,247,231,74,253,249,82,127,161,212,95,
    44,245,151,74,253,75,165,254,229,82,255,74,169,127,181,212,
    95,46,245,175,149,250,215,75,253,149,82,191,193,125,212,252,
    34,116,111,64,247,38,116,223,130,109,116,198,108,161,229,219,
    32,77,232,174,66,123,21,36,254,189,13,71,232,47,255,98,
    105,197,59,188,98,174,88,113,139,87,52,161,221,4,137,127,
    183,244,138,42,180,154,139,136,129,224,63,248,211,68,12,128,
    154,196,102,95,38,105,16,71,78,16,109,199,129,65,243,85,
    106,8,49,30,53,99,25,116,30,18,116,254,9,140,27,223,
    200,160,115,8,200,88,144,46,161,1,135,220,57,52,96,208,
    132,3,1,93,11,124,19,14,112,155,10,9,208,17,112,100,
    192,215,38,17,28,98,107,161,131,175,131,165,52,110,186,236,
    96,205,105,12,14,43,112,80,129,214,179,3,131,6,118,107,
    144,252,3,190,89,102,166,227,204,212,128,3,108,45,56,178,
    224,176,10,79,145,8,135,186,53,82,95,60,59,64,77,113,
    164,213,180,80,218,205,146,186,164,138,31,36,145,219,147,138,
    44,225,244,221,196,237,57,159,200,72,38,129,247,36,232,201,
    228,145,236,53,235,57,109,156,174,245,93,181,99,243,98,147,
    172,210,235,43,102,26,71,82,77,96,103,59,136,124,167,23,
    251,123,161,84,227,196,209,217,14,66,233,56,60,249,105,175,
    31,39,234,163,36,137,19,155,12,203,131,97,236,22,43,200,
    172,94,24,167,178,73,187,241,54,54,177,87,68,189,221,103,
    142,36,0,11,76,139,125,153,122,73,208,87,232,47,205,145,
    168,137,91,147,60,197,77,250,5,54,235,59,113,79,174,239,
    202,30,106,36,239,172,119,100,239,46,55,239,166,202,221,10,
    229,250,214,94,16,250,235,15,236,71,235,253,129,218,137,163,
    117,156,15,34,37,209,52,225,250,153,70,89,67,194,139,196,
    254,121,208,113,2,86,204,217,145,97,95,38,83,52,122,133,
    182,22,51,98,82,84,133,41,154,98,10,123,21,252,152,98,
    217,152,16,155,1,169,230,145,186,132,45,171,140,38,114,177,
    128,93,3,146,101,194,74,23,255,4,57,23,17,211,162,57,
    131,231,126,67,54,209,163,93,147,16,160,7,15,24,95,8,
    52,164,220,32,151,71,192,32,169,64,183,10,26,60,136,57,
    141,166,100,64,45,146,19,27,3,153,91,144,126,7,104,99,
    132,205,1,100,144,58,50,65,68,51,160,234,148,89,112,116,
    17,55,252,150,81,217,106,146,248,155,140,11,181,19,164,241,
    243,136,173,79,125,142,163,22,90,230,241,224,243,173,174,244,
    84,186,130,3,95,198,123,13,207,141,162,88,53,92,223,111,
    184,74,37,193,214,158,146,105,67,197,141,213,180,73,14,181,
    103,115,104,21,252,6,253,28,74,228,118,132,146,254,226,7,
    158,194,47,115,252,133,189,144,74,133,176,216,137,253,20,199,
    137,69,71,42,155,132,84,100,228,152,5,97,212,56,68,74,
    219,35,221,5,252,254,32,151,132,161,217,172,230,64,74,101,
    184,173,234,140,73,55,77,29,150,132,198,25,126,196,120,223,
    13,247,36,115,71,28,41,20,136,186,90,134,145,0,240,18,
    41,147,235,206,10,69,113,228,15,80,190,192,187,69,91,95,
    98,24,78,50,16,23,16,132,99,216,86,241,127,85,44,26,
    158,149,65,175,154,195,143,82,128,2,118,190,200,252,143,80,
    60,194,196,211,52,56,115,176,78,28,149,55,169,71,139,237,
    101,106,174,81,115,157,154,149,92,237,55,173,251,212,176,238,
    247,104,63,131,21,102,213,200,65,102,174,154,127,34,178,46,
    31,71,22,38,200,22,69,136,65,113,116,28,33,22,37,211,
    228,62,181,72,202,177,103,66,250,132,82,55,69,18,51,163,
    160,65,248,83,239,56,40,216,80,246,12,25,96,60,199,179,
    77,32,45,35,181,83,66,170,77,62,98,152,218,151,243,156,
    232,16,133,6,168,125,149,88,85,206,176,116,131,154,27,163,
    50,247,49,212,58,167,160,246,62,109,61,147,65,109,138,33,
    86,199,207,140,225,153,153,15,138,243,114,110,8,98,132,47,
    235,12,124,189,67,61,243,180,214,35,134,86,166,235,199,37,
    104,145,120,70,89,165,77,236,12,150,72,147,50,168,150,240,
    240,127,26,45,225,121,110,240,121,254,19,62,207,185,38,224,
    234,76,39,106,147,115,181,238,84,200,36,219,38,44,102,231,
    116,90,195,182,159,196,47,6,141,120,187,161,88,103,202,171,
    27,171,233,218,106,250,62,102,204,198,125,206,85,58,103,234,
    172,152,200,62,101,53,90,250,209,11,79,242,201,200,223,28,
    71,39,49,135,19,154,147,157,184,136,175,5,50,168,145,91,
    154,211,121,170,18,202,226,35,177,117,189,176,53,137,254,25,
    109,86,103,67,155,98,9,177,84,23,44,145,163,179,55,215,
    95,60,139,159,15,200,248,164,181,4,170,216,237,150,150,151,
    85,33,165,236,31,159,192,203,27,86,196,94,71,206,95,228,
    56,169,30,227,132,62,102,14,253,63,3,87,166,2,254,4,
    132,4,116,120,6,253,34,82,200,245,115,68,254,59,224,24,
    57,163,22,224,124,211,162,243,159,41,48,13,165,247,152,84,
    151,6,159,193,95,74,1,150,31,224,102,86,123,150,15,112,
    171,200,85,12,161,215,58,164,173,147,73,141,156,179,227,166,
    68,166,51,213,113,204,30,31,7,69,185,136,153,250,77,227,
    105,92,111,227,144,68,95,31,163,137,142,192,171,98,206,40,
    97,228,167,212,220,41,224,33,242,177,55,40,220,10,156,127,
    94,59,250,68,248,138,36,176,88,230,233,49,53,141,255,135,
    248,20,49,80,201,99,224,78,17,3,146,207,175,151,124,37,
    161,214,32,167,31,25,2,239,167,88,190,209,117,208,2,89,
    129,118,149,162,133,139,109,145,5,147,200,179,25,229,190,19,
    135,35,27,102,83,155,172,240,187,118,41,53,47,70,146,37,
    200,171,27,161,219,219,242,221,251,251,180,21,237,231,229,225,
    101,228,194,207,148,133,167,208,16,231,201,207,95,239,230,74,
    236,143,36,67,252,156,118,202,133,231,120,240,99,143,211,194,
    147,29,217,232,201,222,22,222,60,119,130,126,99,59,116,59,
    236,25,51,83,238,243,92,57,197,174,29,46,55,210,219,212,
    198,13,47,142,48,117,239,121,42,78,26,190,196,171,152,244,
    27,239,54,56,239,55,130,180,225,110,225,172,235,41,13,245,
    147,209,202,117,173,155,116,82,46,97,119,159,83,119,100,158,
    117,240,174,29,96,49,255,2,138,99,86,95,0,139,52,206,
    101,186,142,28,60,17,241,146,165,6,58,111,81,233,97,175,
    81,243,35,24,101,182,127,15,57,239,209,22,100,174,170,184,
    106,212,12,181,112,58,88,31,211,250,244,116,200,254,253,117,
    66,86,63,38,101,129,91,37,74,57,70,247,125,106,107,148,
    246,219,245,124,112,130,219,73,30,156,202,7,47,112,59,205,
    131,51,249,224,44,183,23,121,112,46,127,217,154,231,193,5,
    104,47,210,19,12,141,44,81,134,24,251,111,51,4,71,216,
    200,98,235,143,255,211,196,96,223,251,191,200,110,255,2,178,
    90,225,188,164,32,202,138,77,233,164,208,21,249,53,165,172,
    21,191,136,44,159,135,74,199,75,164,171,164,118,212,242,136,
    148,229,244,162,55,254,246,56,218,79,23,213,15,10,189,142,
    184,82,26,204,179,255,244,45,141,253,39,158,70,87,176,186,
    182,184,186,222,160,234,250,128,141,224,24,186,192,62,6,102,
    165,176,5,93,176,34,249,124,88,46,109,15,93,70,147,124,
    110,191,47,35,223,190,13,229,202,152,167,71,130,7,202,105,
    127,133,82,233,98,138,121,44,133,79,71,34,229,236,146,158,
    236,200,74,17,123,163,114,41,227,247,111,57,126,155,124,157,
    45,18,183,189,65,13,167,234,34,75,219,191,42,28,114,253,
    92,112,110,185,169,164,235,215,15,145,96,33,197,103,23,125,
    81,215,206,165,237,96,129,69,220,94,77,65,204,248,225,40,
    240,212,205,115,41,209,34,78,127,103,144,50,195,215,32,35,
    174,116,204,229,3,63,176,102,63,72,212,107,176,102,178,50,
    107,26,96,236,112,200,251,50,148,74,158,141,116,69,254,200,
    158,34,124,137,69,65,60,192,123,33,223,179,240,123,232,56,
    163,59,71,127,137,156,255,64,91,204,3,159,163,162,138,39,
    233,130,224,95,163,86,173,9,46,81,134,158,225,181,100,4,
    37,125,171,24,164,54,167,206,233,2,87,252,80,156,23,10,
    4,65,190,3,111,186,61,253,196,199,207,87,246,91,144,61,
    52,216,183,10,124,82,134,224,171,156,190,52,99,178,224,242,
    137,171,37,251,103,121,14,233,221,93,203,85,91,211,170,125,
    128,240,251,4,81,99,240,172,186,114,38,209,227,208,85,219,
    113,210,99,20,158,158,254,52,82,201,67,188,174,39,113,200,
    207,45,167,41,90,8,30,217,83,87,135,38,101,180,215,115,
    208,160,113,50,120,20,251,146,253,95,158,127,224,251,137,237,
    70,29,233,236,75,42,14,213,141,97,130,172,50,212,60,114,
    170,198,153,50,156,164,61,37,139,38,194,73,253,240,203,87,
    158,211,243,15,195,216,219,149,126,70,115,182,57,152,230,195,
    184,231,226,248,217,187,180,130,124,151,217,161,121,63,161,85,
    11,67,163,41,162,207,13,131,111,228,57,252,30,7,241,135,
    114,63,240,100,30,83,60,201,151,176,97,2,66,71,241,141,
    171,193,179,14,90,14,177,68,118,2,116,91,194,124,138,53,
    217,153,67,248,127,69,160,151,215,143,44,40,245,109,75,63,
    16,221,167,231,200,244,183,216,208,19,114,109,186,134,1,74,
    7,146,41,234,120,36,89,230,228,76,205,154,156,168,89,181,
    49,147,95,253,166,240,142,93,183,106,19,147,226,85,191,43,
    24,216,117,99,101,174,38,190,7,232,213,204,80,
};

EmbeddedPython embedded_m5_internal_param_GenericTimerMem(
    "m5/internal/param_GenericTimerMem.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_GenericTimerMem.py",
    "m5.internal.param_GenericTimerMem",
    data_m5_internal_param_GenericTimerMem,
    2445,
    7565);

} // anonymous namespace
