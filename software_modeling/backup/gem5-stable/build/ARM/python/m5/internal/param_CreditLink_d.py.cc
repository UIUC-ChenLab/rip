#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_CreditLink_d[] = {
    120,156,189,88,91,111,220,198,21,62,67,114,87,218,149,100,
    73,150,37,217,150,108,177,41,220,108,140,68,219,186,113,93,
    192,138,91,215,73,129,6,137,146,114,19,216,217,4,97,41,
    114,36,113,197,203,130,28,89,222,64,122,169,140,182,232,123,
    127,66,31,250,111,250,143,218,115,206,144,92,234,6,4,104,
    181,242,114,60,28,206,156,57,151,239,92,102,124,40,254,26,
    248,252,214,6,200,255,46,0,2,252,9,136,0,98,1,125,
    1,66,10,8,110,193,65,3,178,15,33,104,192,91,128,190,
    1,210,128,83,236,152,240,173,1,201,44,175,105,66,100,242,
    136,128,81,27,164,5,253,6,188,76,22,193,146,77,56,104,
    67,246,39,16,66,36,2,94,5,83,16,76,195,91,164,142,
    157,22,19,156,6,26,108,243,96,11,130,25,30,108,67,48,
    203,157,25,24,45,128,156,133,254,28,77,235,223,64,178,15,
    145,236,60,147,253,55,145,13,240,203,50,4,55,104,58,242,
    245,13,205,180,104,38,239,55,207,84,22,74,46,23,161,127,
    179,236,47,213,250,183,106,253,229,90,127,165,214,95,229,62,
    114,115,19,6,183,97,112,7,6,119,97,23,21,180,88,237,
    188,6,210,132,193,58,244,215,65,226,111,13,78,81,135,193,
    205,218,138,123,188,98,169,90,113,159,87,108,64,127,3,36,
    254,238,235,21,77,232,117,86,208,46,225,127,240,175,131,118,
    1,53,139,205,107,153,229,97,154,184,97,178,155,134,6,125,
    111,82,67,86,244,169,153,42,204,249,130,204,249,47,96,91,
    6,70,97,206,19,64,194,130,100,137,12,56,225,206,137,1,
    163,14,28,11,24,88,16,152,112,140,219,52,136,129,61,1,
    167,6,124,103,210,132,19,108,45,84,250,125,176,148,182,229,
    128,149,174,41,77,193,73,3,142,27,208,123,117,108,208,192,
    65,11,178,127,194,15,235,76,116,154,137,26,112,140,173,5,
    167,22,156,52,225,37,78,194,161,65,139,196,23,175,142,81,
    82,28,233,117,44,228,118,187,38,46,137,18,132,89,226,197,
    82,45,97,223,29,122,153,23,187,47,50,25,132,234,179,48,
    57,112,131,78,187,156,152,230,155,67,79,237,59,188,210,36,
    149,196,67,197,20,211,68,170,25,236,236,134,73,224,198,105,
    112,24,73,53,77,228,220,221,48,146,174,203,31,255,16,15,
    211,76,125,146,101,105,230,144,86,121,48,74,189,106,5,233,
    212,143,210,92,118,104,55,222,198,33,242,138,102,239,14,153,
    34,49,192,220,210,226,64,230,126,22,14,21,26,75,83,164,
    217,68,173,67,102,226,38,119,176,233,238,167,177,236,30,200,
    56,150,153,124,212,221,147,241,99,110,62,200,149,183,19,201,
    238,206,97,24,5,221,231,206,231,221,225,72,237,167,73,23,
    191,135,137,146,168,151,168,123,81,35,155,56,235,38,209,62,
    10,247,220,144,165,114,247,101,52,148,217,28,141,222,165,125,
    197,130,152,21,77,97,138,142,152,195,94,3,31,83,172,27,
    51,98,59,36,185,124,146,149,80,101,213,113,68,198,21,112,
    96,64,182,78,40,25,224,79,144,89,17,43,61,250,102,240,
    183,63,146,66,244,232,192,36,219,235,193,99,70,22,66,12,
    103,110,145,177,19,96,120,52,96,208,4,13,27,68,155,198,
    81,54,162,22,167,19,25,3,137,91,144,255,3,80,193,8,
    152,99,40,192,116,106,130,72,22,64,181,201,207,113,116,5,
    55,252,51,227,177,215,33,246,183,25,20,106,63,204,211,163,
    132,85,79,125,246,160,30,106,230,203,209,23,59,3,233,171,
    124,3,7,190,73,15,109,223,75,146,84,217,94,16,216,158,
    82,89,184,115,168,100,110,171,212,126,144,119,200,154,206,98,
    137,171,138,222,104,88,226,136,108,142,56,210,47,65,232,43,
    124,97,192,186,108,133,92,42,196,196,126,26,228,56,78,36,
    246,164,114,136,73,69,74,78,153,17,134,140,75,83,105,123,
    156,119,3,223,159,151,156,48,46,59,205,18,69,185,140,118,
    85,155,1,233,229,185,203,156,208,56,99,143,8,191,246,162,
    67,201,212,17,68,10,25,162,174,230,225,250,209,119,155,36,
    41,5,103,105,146,52,9,70,200,92,232,191,75,251,222,102,
    12,206,50,10,151,17,129,83,216,54,241,255,166,88,49,124,
    171,192,93,179,196,30,197,64,5,108,121,81,24,31,113,120,
    138,241,166,99,112,192,96,129,216,31,223,161,30,45,118,214,
    169,185,71,205,125,106,54,74,153,175,85,240,185,243,130,63,
    161,205,12,150,150,229,34,211,152,165,92,193,25,159,186,51,
    246,41,12,138,61,242,13,131,60,104,236,27,22,5,208,236,
    25,181,56,149,189,206,132,252,43,10,215,228,67,76,140,220,
    5,129,79,189,177,59,176,150,156,5,146,126,186,68,178,67,
    240,172,99,116,175,134,81,135,12,196,0,117,238,148,161,208,
    165,25,26,154,206,26,145,106,92,162,102,155,154,159,76,68,
    215,99,144,237,93,0,217,83,218,119,161,0,217,28,131,171,
    141,207,130,225,155,133,1,170,4,185,116,14,92,132,44,235,
    18,100,253,140,122,230,69,145,39,9,170,66,208,223,215,64,
    69,188,25,117,121,182,177,51,90,37,49,234,112,90,197,84,
    255,50,89,197,236,109,112,246,254,57,103,111,174,0,184,62,
    210,193,217,228,248,172,59,13,210,199,174,9,43,69,86,206,
    91,216,14,179,244,205,200,78,119,109,197,2,83,44,221,122,
    144,111,62,200,159,98,148,180,159,113,124,210,113,82,71,194,
    76,14,41,146,209,210,79,222,248,146,83,33,191,185,174,14,
    92,46,7,49,183,72,177,136,172,101,210,166,81,170,153,67,
    120,174,50,138,220,215,175,232,118,165,104,226,251,83,218,169,
    205,90,54,197,42,162,168,45,152,29,87,135,107,46,181,248,
    43,62,191,35,205,147,200,18,168,96,118,122,154,89,150,131,
    36,114,222,63,131,148,235,148,194,233,34,217,175,75,132,52,
    199,8,161,199,44,17,255,87,224,10,84,192,95,128,48,128,
    166,46,16,95,57,8,25,125,137,166,127,15,236,26,151,100,
    126,142,49,61,202,246,60,3,67,79,254,132,167,234,66,224,
    83,248,91,205,175,202,116,109,22,53,102,61,93,91,85,124,
    98,240,252,168,148,108,157,13,100,100,153,125,47,167,105,58,
    58,141,93,117,28,255,171,202,16,163,243,181,34,105,90,239,
    225,18,59,223,141,113,68,9,111,77,44,25,53,116,252,130,
    154,71,21,48,68,57,118,93,156,109,192,213,169,217,213,241,
    255,91,218,222,98,134,231,167,184,94,170,19,169,112,223,40,
    113,255,168,194,189,228,84,245,150,79,28,212,26,100,235,83,
    67,224,145,16,107,52,58,129,89,32,27,208,111,146,135,112,
    57,45,10,7,18,101,248,162,96,119,38,15,178,74,182,181,
    178,42,115,107,75,82,243,230,250,195,2,25,115,43,242,226,
    157,192,123,22,211,62,180,153,95,186,148,81,114,190,80,231,
    156,220,65,92,197,60,191,62,46,37,120,125,253,33,225,87,
    72,182,226,156,29,32,72,125,142,3,95,237,75,59,150,241,
    14,30,41,247,195,161,189,27,121,123,108,19,179,144,236,139,
    82,50,197,70,61,95,83,228,15,169,77,109,63,77,48,74,
    31,250,42,205,236,64,226,49,75,6,246,7,54,135,120,59,
    204,109,111,7,191,122,190,210,240,62,235,158,92,182,122,217,
    94,206,21,234,193,17,117,39,99,83,23,79,208,33,22,234,
    41,84,233,84,159,236,170,136,205,37,184,246,22,204,124,120,
    128,82,35,29,165,168,190,112,54,169,121,15,38,22,216,63,
    68,178,17,209,39,69,53,197,154,209,50,248,156,87,159,247,
    37,173,204,47,250,232,231,63,198,71,245,133,77,225,169,205,
    242,166,103,10,36,31,188,232,50,166,89,92,198,160,251,78,
    253,175,238,203,30,48,25,236,191,254,191,122,173,243,100,242,
    140,59,191,134,34,115,95,229,177,162,46,213,156,246,216,129,
    40,15,10,117,145,248,42,226,206,165,192,113,253,76,122,74,
    106,251,172,79,66,76,246,122,189,235,104,236,135,23,203,218,
    231,149,68,167,92,177,140,110,177,217,244,9,137,205,38,94,
    38,119,177,190,181,184,190,221,162,250,246,152,197,119,13,93,
    226,142,193,216,168,180,64,39,203,68,30,185,23,53,161,171,
    88,98,206,27,14,101,18,56,15,161,94,152,242,231,235,199,
    192,83,141,206,113,253,96,138,91,88,137,94,244,59,10,162,
    53,9,217,126,141,202,211,38,98,73,6,236,105,9,216,14,
    213,13,227,72,234,108,81,195,177,179,10,155,206,111,160,12,
    165,21,36,3,25,73,37,47,177,135,162,181,197,73,53,144,
    152,78,210,17,30,30,184,30,199,247,200,117,39,20,132,63,
    66,178,135,80,156,125,48,8,139,166,209,50,91,205,150,224,
    140,118,238,58,86,179,99,67,89,117,142,152,43,112,230,43,
    153,249,206,176,76,45,164,35,62,29,109,123,177,190,240,225,
    251,12,231,167,80,156,63,157,119,43,5,146,178,184,212,215,
    199,41,4,49,103,91,78,174,206,47,105,156,42,189,248,241,
    102,41,207,166,150,103,91,170,163,52,59,208,2,241,205,101,
    252,248,138,169,47,162,212,63,144,129,190,38,83,247,174,158,
    243,113,26,123,56,190,118,233,140,94,24,23,20,22,207,125,
    15,50,90,181,124,110,52,151,89,232,69,225,15,250,102,173,
    28,230,139,138,203,36,160,72,119,102,132,211,228,133,240,198,
    192,201,228,94,152,35,61,38,118,102,81,225,243,31,149,122,
    187,36,50,214,9,76,6,107,186,240,212,39,227,103,116,3,
    147,127,140,13,93,153,181,230,91,136,59,138,6,38,158,74,
    231,132,101,206,46,180,172,217,153,150,213,154,50,249,174,99,
    14,79,25,109,171,53,51,43,198,255,54,16,165,109,99,3,
    215,254,23,227,11,182,251,
};

EmbeddedPython embedded_m5_internal_param_CreditLink_d(
    "m5/internal/param_CreditLink_d.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_CreditLink_d.py",
    "m5.internal.param_CreditLink_d",
    data_m5_internal_param_CreditLink_d,
    2199,
    6646);

} // anonymous namespace
