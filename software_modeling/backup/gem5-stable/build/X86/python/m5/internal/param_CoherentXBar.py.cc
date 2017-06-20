#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_CoherentXBar[] = {
    120,156,189,88,109,115,219,198,17,222,3,64,74,164,222,223,
    109,75,182,96,187,114,88,79,45,181,110,28,103,38,170,91,
    219,77,102,154,153,40,41,152,142,21,38,83,20,34,78,20,
    40,18,224,0,39,217,204,72,51,157,202,147,246,67,251,177,
    63,161,31,250,111,242,11,250,87,218,221,61,0,132,68,42,
    227,78,43,201,228,249,120,183,183,183,123,251,236,203,93,19,
    210,191,18,126,127,101,3,36,255,18,0,62,126,4,116,0,
    186,2,26,2,132,20,224,47,194,97,9,226,247,193,47,193,
    91,128,134,1,210,128,51,236,152,240,181,1,225,36,175,41,
    67,199,228,17,1,253,42,72,11,26,37,120,21,206,129,37,
    203,112,88,133,248,15,32,132,8,5,236,250,99,224,143,195,
    91,228,142,157,10,51,28,7,26,172,242,96,5,252,9,30,
    172,130,63,201,157,9,232,207,130,156,132,198,20,145,53,166,
    145,237,67,100,59,195,108,191,39,182,62,206,44,129,63,77,
    228,40,215,87,68,105,17,37,239,55,195,92,102,51,41,231,
    160,49,159,245,23,10,253,197,66,127,169,208,95,46,244,87,
    10,253,27,133,254,205,66,255,86,161,191,90,232,175,21,250,
    183,11,253,59,220,71,13,231,161,189,14,109,27,218,119,97,
    31,15,125,46,215,230,30,72,19,218,247,161,113,31,36,126,
    238,193,25,218,197,159,47,172,248,17,175,88,200,87,108,240,
    138,7,208,120,0,18,63,27,122,69,25,234,181,101,180,117,
    240,111,252,171,161,173,65,77,98,115,44,227,36,136,66,55,
    8,247,163,192,160,249,50,53,132,140,38,53,99,41,68,94,
    18,68,254,9,140,15,223,72,33,114,10,200,88,144,46,29,
    3,78,185,115,106,64,191,6,39,2,218,22,248,38,156,224,
    54,37,18,160,37,224,204,128,111,76,34,56,197,214,66,67,
    222,1,75,105,124,180,217,144,154,211,24,156,150,224,164,4,
    245,221,19,131,6,14,43,16,255,3,190,93,99,166,227,204,
    212,128,19,108,45,56,179,224,180,12,175,144,8,135,218,21,
    82,95,236,158,160,166,56,82,175,89,40,237,78,65,93,82,
    197,15,226,208,235,74,181,128,125,183,231,197,94,215,125,25,
    29,200,88,134,106,247,133,23,215,170,25,97,148,108,246,60,
    117,224,240,74,147,142,164,219,83,204,49,10,165,154,192,206,
    126,16,250,110,55,242,143,58,82,141,19,59,119,63,232,72,
    215,229,201,223,116,123,81,172,62,142,227,40,118,232,84,121,
    176,19,121,249,10,58,211,102,39,74,100,141,118,227,109,28,
    98,175,136,122,191,199,28,73,0,150,150,22,251,50,105,198,
    65,79,161,177,52,71,162,38,110,53,50,19,55,137,131,205,
    214,65,212,149,91,135,178,219,69,173,30,111,181,100,247,9,
    55,143,18,229,237,117,228,214,222,81,208,241,183,118,63,252,
    96,171,215,87,7,81,184,133,243,65,168,36,158,75,103,107,
    248,68,54,145,106,158,120,191,14,90,110,192,90,185,7,178,
    211,147,241,20,141,222,162,125,197,172,152,20,101,97,138,154,
    152,194,94,9,191,166,88,51,38,196,78,64,122,53,73,87,
    66,149,85,196,17,25,87,192,161,1,241,26,161,164,141,31,
    65,102,69,172,212,105,206,224,185,223,210,129,232,209,182,73,
    182,215,131,39,140,44,132,24,82,110,147,177,67,96,120,148,
    160,93,6,13,27,68,155,198,81,220,167,22,201,137,141,129,
    204,45,72,254,14,120,192,8,152,19,72,193,116,102,130,8,
    103,65,85,41,118,224,232,50,110,248,39,198,99,189,70,226,
    239,48,40,212,65,144,68,175,67,62,122,234,179,7,213,241,
    100,190,232,127,190,215,150,77,149,172,227,192,87,209,145,221,
    244,194,48,82,182,231,251,182,167,84,28,236,29,41,153,216,
    42,178,55,146,26,89,211,153,203,112,149,243,235,247,50,28,
    145,205,17,71,250,135,31,52,21,254,96,192,186,108,133,68,
    42,196,196,65,228,39,56,78,44,90,82,57,36,164,162,67,
    142,88,16,134,140,75,164,180,61,210,77,227,239,231,153,36,
    140,203,90,57,67,81,34,59,251,170,202,128,244,146,196,101,
    73,104,156,177,71,140,143,189,206,145,100,238,8,34,133,2,
    81,87,203,112,245,232,187,65,154,100,138,179,54,97,20,250,
    125,20,46,104,190,71,251,222,96,12,78,50,10,151,16,129,
    99,216,150,241,255,178,88,54,154,86,138,187,114,134,61,138,
    129,10,216,242,34,53,62,226,240,12,227,77,205,224,128,193,
    10,177,63,222,163,30,45,118,214,168,185,77,205,29,106,214,
    51,157,175,84,241,169,139,138,63,165,205,12,214,150,245,34,
    211,152,153,94,254,57,159,186,57,240,41,12,138,117,242,13,
    131,60,104,224,27,22,5,208,248,25,181,72,202,94,103,66,
    242,37,133,107,242,33,102,70,238,130,192,167,222,192,29,248,
    148,156,89,210,126,60,67,178,67,240,44,98,180,85,192,168,
    67,6,98,128,58,55,179,80,232,18,133,134,166,179,74,172,
    74,35,142,217,166,230,238,181,156,245,0,100,173,33,144,125,
    68,251,206,166,32,155,98,112,85,241,59,107,52,205,212,0,
    121,130,92,184,0,46,66,150,53,2,89,15,168,103,14,171,
    124,157,160,74,21,253,164,0,42,146,205,40,234,179,131,157,
    254,10,169,81,132,211,10,166,250,87,225,10,102,111,131,179,
    247,79,57,123,115,5,192,53,151,14,206,38,199,103,221,41,
    209,121,236,155,176,156,102,229,164,130,109,47,142,222,244,237,
    104,223,86,172,48,197,210,237,141,100,115,35,249,8,163,164,
    253,140,227,147,142,147,58,18,198,178,71,145,140,150,126,252,
    166,41,57,21,242,47,215,213,129,203,229,32,230,166,41,22,
    145,181,68,167,105,100,199,204,33,60,81,49,69,238,171,63,
    232,106,126,208,36,247,167,180,83,149,79,217,20,43,136,162,
    170,96,113,92,29,174,185,212,226,89,252,190,160,147,39,149,
    37,80,17,238,212,181,176,172,7,105,228,252,228,28,82,174,
    82,11,103,11,217,254,46,67,72,121,128,16,250,154,25,226,
    255,12,92,129,10,248,14,8,3,104,234,20,241,185,131,144,
    209,23,136,252,247,192,174,49,34,243,115,140,169,83,182,103,
    10,12,61,201,83,38,213,133,192,167,240,151,130,95,101,233,
    218,76,107,204,98,186,182,242,248,196,224,121,167,148,108,157,
    15,100,100,153,3,47,33,50,29,157,6,174,58,136,255,121,
    101,136,209,249,74,145,52,174,247,112,73,156,111,6,56,162,
    132,183,42,22,140,2,58,126,70,205,227,28,24,34,27,187,
    42,201,214,225,242,212,236,234,248,255,53,109,111,177,192,51,
    99,92,47,21,153,228,184,47,101,184,127,156,227,94,114,170,
    122,203,55,14,106,13,178,245,153,33,240,154,137,53,26,221,
    234,44,144,37,104,148,201,67,184,156,22,169,3,137,44,124,
    81,176,59,151,7,249,72,118,244,97,229,230,214,150,164,230,
    205,213,135,5,50,230,118,199,235,238,249,222,51,138,123,9,
    109,214,204,92,202,200,36,159,45,74,78,238,32,46,19,158,
    127,62,201,52,56,190,250,144,240,1,112,142,211,146,179,3,
    248,81,147,227,192,151,7,210,238,202,238,30,94,41,15,130,
    158,189,223,241,90,108,19,51,213,236,243,76,51,197,70,189,
    88,83,36,15,169,141,236,102,20,98,148,62,106,170,40,182,
    125,137,215,44,233,219,143,108,14,241,118,144,216,222,30,206,
    122,77,165,225,125,222,61,185,108,245,226,86,194,21,234,225,
    107,234,94,143,77,93,188,65,7,88,168,31,67,158,78,245,
    205,46,143,216,92,130,107,111,193,204,135,23,40,213,215,81,
    138,234,11,103,147,154,31,195,181,5,246,247,83,11,38,116,
    80,101,177,106,84,12,190,231,21,233,190,160,149,201,176,143,
    254,245,93,124,84,63,2,165,158,90,38,74,57,70,247,119,
    106,43,20,222,27,213,108,112,130,219,73,30,156,202,6,167,
    185,157,225,193,217,236,241,105,142,7,231,161,177,64,175,39,
    52,178,72,222,63,246,191,122,63,59,208,245,184,206,233,255,
    213,233,157,167,215,47,184,243,33,164,137,255,50,135,23,69,
    173,166,180,195,183,69,118,207,40,170,196,47,25,55,71,226,
    206,109,198,210,83,82,219,103,237,58,212,228,160,161,119,253,
    227,192,141,135,171,226,231,185,70,103,92,240,244,23,217,108,
    250,130,197,102,19,175,194,91,88,30,91,92,30,111,83,121,
    124,194,234,187,134,174,144,7,96,44,229,167,64,23,211,80,
    190,118,135,79,66,23,193,36,156,215,235,201,208,119,30,66,
    177,174,229,233,171,199,0,133,169,239,160,80,126,152,98,17,
    11,217,97,191,163,24,92,208,144,237,87,202,61,237,90,44,
    201,128,253,91,6,216,26,199,224,60,16,59,219,212,112,232,
    205,163,174,243,203,220,14,247,71,163,49,9,163,168,71,79,
    124,184,47,221,157,222,137,14,203,34,174,121,138,131,234,209,
    15,45,140,101,210,195,252,39,221,14,162,48,108,246,121,171,
    255,110,5,109,186,156,111,122,113,90,221,190,132,89,63,81,
    178,203,219,253,48,5,177,231,167,32,254,201,176,96,15,246,
    101,71,42,57,2,190,138,142,58,125,23,240,37,38,239,168,
    143,87,53,190,253,224,239,142,235,94,83,202,251,133,14,175,
    144,80,158,195,148,39,202,152,244,150,240,62,191,100,84,202,
    21,193,85,196,133,39,112,45,20,189,50,233,74,191,207,178,
    129,51,147,163,133,223,105,179,116,78,192,226,27,233,142,215,
    213,143,108,252,134,228,16,84,248,206,239,188,151,163,142,142,
    140,175,87,250,10,139,158,207,21,14,23,52,206,207,105,156,
    204,208,125,178,153,105,181,169,181,170,147,85,63,209,72,50,
    152,130,31,47,70,16,178,125,212,234,133,73,25,30,117,221,
    207,100,55,138,251,159,69,190,84,107,23,230,159,251,126,236,
    120,97,75,186,199,146,74,48,117,247,34,65,90,127,105,30,
    25,149,61,82,134,243,180,67,178,104,34,156,212,175,167,124,
    159,24,158,127,217,137,154,135,210,79,105,70,159,10,211,252,
    58,234,122,56,62,122,151,122,144,237,50,119,97,222,143,105,
    213,210,133,209,68,198,129,215,9,190,149,234,214,72,126,47,
    188,68,18,178,24,1,217,28,215,120,35,230,179,31,92,118,
    13,229,59,118,141,88,182,130,132,140,58,93,160,79,227,63,
    33,151,15,103,148,87,22,214,94,143,35,233,59,140,126,100,
    121,54,145,237,67,175,175,149,153,10,58,21,101,6,83,84,
    49,55,88,230,228,108,197,154,156,168,88,149,49,147,159,205,
    166,240,194,90,181,42,19,147,226,178,127,235,232,138,85,99,
    125,190,34,254,3,139,120,130,106,
};

EmbeddedPython embedded_m5_internal_param_CoherentXBar(
    "m5/internal/param_CoherentXBar.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_CoherentXBar.py",
    "m5.internal.param_CoherentXBar",
    data_m5_internal_param_CoherentXBar,
    2393,
    7331);

} // anonymous namespace
