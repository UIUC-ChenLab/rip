#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_GarnetExtLink[] = {
    120,156,197,88,95,115,219,198,17,223,3,64,74,164,36,139,
    250,111,91,178,69,39,149,77,59,182,212,186,113,156,153,184,
    110,29,215,205,36,211,40,41,152,142,29,37,83,20,34,78,
    18,40,16,224,0,39,203,244,80,47,145,39,237,244,173,15,
    253,8,121,232,183,233,55,106,119,247,0,16,162,168,25,207,
    180,102,101,242,188,60,44,246,110,119,127,251,231,174,5,233,
    95,9,191,191,169,3,36,55,13,0,15,63,2,2,128,142,
    128,29,1,66,10,240,22,225,176,4,241,135,224,149,224,13,
    192,142,1,210,128,83,36,76,248,206,128,112,154,223,41,67,
    96,242,140,128,94,21,164,5,59,37,120,30,206,129,37,203,
    112,88,133,248,207,32,132,8,5,188,240,38,192,155,132,55,
    40,29,137,10,11,156,4,154,172,242,100,5,188,41,158,172,
    130,55,205,196,20,244,106,32,167,97,103,134,216,118,46,161,
    216,59,40,118,150,197,254,139,196,122,248,100,9,188,75,196,
    142,251,250,150,56,45,226,228,245,102,89,74,45,219,229,28,
    236,204,103,244,66,129,94,44,208,75,5,122,185,64,175,20,
    232,203,5,250,74,129,190,90,160,87,11,244,90,129,190,86,
    160,175,23,232,245,2,93,47,208,55,10,244,123,5,250,253,
    2,253,51,166,209,82,243,208,222,128,246,77,104,223,130,61,
    116,222,92,110,149,6,72,19,218,183,97,231,54,72,252,52,
    224,20,253,235,205,23,222,184,195,111,44,228,111,124,192,111,
    220,133,157,187,32,241,243,129,126,163,12,205,198,50,98,198,
    255,55,254,53,4,82,106,26,135,151,50,78,252,40,116,252,
    112,47,242,13,122,94,166,129,16,214,162,97,34,133,218,83,
    130,218,63,129,113,230,25,41,212,78,0,5,11,210,37,48,
    224,132,137,19,3,122,13,232,11,104,91,224,153,208,199,101,
    74,180,129,125,1,167,6,124,111,18,195,9,142,22,2,226,
    58,88,74,227,172,205,128,208,146,38,224,164,4,253,18,52,
    95,244,13,154,56,172,64,252,19,188,94,99,161,147,44,212,
    128,62,142,22,156,90,112,82,134,231,200,132,83,237,10,169,
    47,94,244,81,83,156,105,54,44,220,237,118,65,93,82,197,
    243,227,208,237,72,181,136,180,211,117,99,183,227,124,230,198,
    161,84,207,94,169,223,251,225,97,163,154,113,70,201,102,215,
    85,7,54,191,106,146,77,58,93,197,34,35,100,159,66,98,
    207,15,61,167,19,121,71,129,84,147,36,207,217,243,3,233,
    56,252,240,243,78,55,138,213,179,56,142,98,155,204,202,147,
    65,228,230,111,144,81,91,65,148,200,6,173,198,203,216,36,
    94,17,247,94,151,37,210,6,120,187,244,178,39,147,86,236,
    119,21,122,75,75,36,110,146,214,32,63,241,144,52,113,216,
    58,136,58,114,235,80,118,58,50,150,247,183,246,101,231,1,
    15,247,18,229,238,6,114,107,247,200,15,188,173,23,31,127,
    180,213,237,169,131,40,220,194,231,126,168,36,26,38,216,26,
    97,146,77,100,155,39,225,199,254,190,227,179,90,206,129,12,
    186,50,158,161,217,171,180,176,168,137,105,81,22,166,104,136,
    25,164,74,248,53,197,154,49,37,182,125,82,172,69,202,18,
    174,172,34,146,200,189,2,14,13,136,215,8,39,109,252,8,
    114,44,162,165,73,207,12,126,246,7,178,136,158,109,155,228,
    125,61,217,103,108,33,200,144,243,17,185,59,4,6,72,9,
    218,101,208,192,65,188,105,36,197,61,26,145,157,196,24,40,
    220,130,228,31,128,22,70,200,244,33,133,211,169,9,34,172,
    129,170,82,22,194,217,101,92,240,7,70,100,179,65,219,223,
    102,84,168,3,63,137,142,67,182,61,209,28,67,77,180,204,
    215,189,175,118,219,178,165,146,117,156,248,54,58,170,183,220,
    48,140,84,221,245,188,186,171,84,236,239,30,41,153,212,85,
    84,223,72,26,228,78,123,46,3,86,46,175,215,205,128,68,
    78,71,32,233,31,158,223,82,248,99,129,127,176,23,18,169,
    16,20,7,145,151,224,60,137,216,151,202,166,77,42,50,114,
    196,27,97,204,56,196,74,203,35,223,37,252,253,36,219,9,
    3,179,81,206,96,148,200,96,79,85,25,145,110,146,56,188,
    19,154,103,240,145,224,151,110,112,36,89,58,162,72,225,134,
    136,212,123,24,3,252,46,147,42,153,230,172,78,24,133,94,
    15,119,231,183,110,209,194,151,25,132,211,12,195,37,132,224,
    4,142,101,252,191,44,150,141,150,149,2,175,156,129,143,210,
    160,2,118,189,72,189,143,64,60,197,148,211,48,56,103,176,
    70,28,145,239,17,69,47,219,107,52,92,163,225,58,13,235,
    153,210,239,86,243,153,97,205,31,210,106,6,171,203,138,145,
    115,204,76,49,239,76,84,93,25,68,21,38,198,38,69,135,
    65,49,52,136,14,139,146,104,252,152,70,100,229,184,51,33,
    249,134,82,54,69,17,11,163,128,65,232,19,53,8,8,54,
    147,93,35,245,39,51,44,219,4,208,34,74,247,11,40,181,
    201,67,12,81,251,74,150,13,29,226,208,224,180,87,73,84,
    105,132,157,235,52,220,24,143,177,7,48,219,63,7,179,79,
    104,225,90,10,179,25,134,87,21,191,53,163,101,166,30,200,
    171,228,194,16,188,8,91,214,8,108,221,36,202,60,175,243,
    88,97,149,106,250,187,2,172,104,115,70,81,161,109,36,122,
    43,164,71,17,80,43,88,240,159,135,43,88,195,13,174,225,
    63,231,26,206,125,0,119,112,58,65,155,156,163,53,81,34,
    131,236,153,176,156,214,230,164,130,99,55,142,94,245,234,209,
    94,93,177,198,148,79,31,109,36,155,27,201,39,152,41,235,
    143,57,71,233,92,169,179,97,44,187,148,205,232,213,103,175,
    90,146,235,33,255,114,28,157,188,28,78,100,78,90,103,17,
    91,75,100,78,35,179,51,167,241,68,197,148,189,199,96,233,
    106,110,105,218,248,23,180,84,149,205,108,138,21,196,81,85,
    240,126,28,157,179,185,227,226,167,248,253,148,76,79,58,75,
    160,158,222,110,234,221,178,34,164,146,125,247,12,86,222,169,
    26,246,22,202,253,99,134,145,242,0,35,244,53,51,208,255,
    5,184,19,21,240,35,16,10,208,217,41,232,243,24,33,183,
    47,16,251,159,128,163,99,68,253,231,60,211,164,154,207,28,
    152,126,146,135,204,170,219,129,47,224,175,133,208,202,138,182,
    153,246,154,197,162,109,229,57,138,225,243,86,133,217,58,155,
    204,200,53,7,110,66,108,58,67,13,162,117,80,4,242,6,
    17,51,244,187,197,210,164,94,196,161,253,124,63,64,18,149,
    189,85,177,96,20,240,241,11,26,238,231,208,16,217,220,59,
    219,218,58,92,92,161,29,93,5,190,163,245,45,222,241,236,
    4,103,160,51,82,114,236,151,50,236,223,207,177,47,185,98,
    189,225,195,7,141,6,185,251,212,16,120,114,197,102,141,14,
    138,22,200,18,236,148,41,74,184,177,22,105,16,137,44,135,
    209,122,103,202,33,27,101,91,155,43,247,184,118,38,13,175,
    198,144,27,200,159,143,2,183,179,235,185,143,95,211,66,180,
    90,43,11,43,35,219,122,173,184,117,10,9,113,209,238,249,
    231,131,76,133,151,99,200,11,31,161,220,124,235,28,5,94,
    212,226,100,240,205,129,172,119,100,103,23,207,151,7,126,183,
    190,23,184,251,236,21,51,85,237,171,76,53,197,110,29,110,
    46,146,59,52,70,245,86,20,98,178,62,106,169,40,174,123,
    18,143,92,210,171,223,171,115,166,175,251,73,221,221,197,167,
    110,75,105,136,159,141,81,238,96,221,120,63,225,102,245,240,
    152,200,49,121,213,193,243,180,143,77,123,31,242,178,170,143,
    121,121,226,230,118,92,71,12,86,64,60,76,169,158,206,85,
    212,104,216,155,52,220,134,241,229,247,15,81,110,143,22,32,
    83,149,197,170,81,49,184,149,59,195,248,53,189,155,156,15,
    212,221,183,9,84,125,185,148,134,107,153,56,229,4,157,231,
    105,172,80,154,167,187,163,82,122,119,68,147,250,238,168,204,
    51,151,40,176,39,254,219,192,230,208,24,83,80,156,254,79,
    227,217,126,248,127,216,185,253,49,164,133,253,162,88,22,69,
    181,102,116,44,183,69,118,150,40,234,196,23,22,87,71,3,
    202,105,197,210,85,82,187,104,109,44,138,114,70,208,203,254,
    56,8,209,243,157,239,147,92,167,83,110,105,122,139,236,57,
    125,140,98,207,137,231,225,85,108,129,45,110,129,31,81,11,
    220,103,3,56,134,238,130,7,128,44,229,118,88,193,33,148,
    199,206,8,91,232,78,151,118,231,118,187,50,244,236,59,80,
    108,94,249,241,24,112,64,73,232,111,80,232,48,76,177,136,
    221,234,249,232,163,20,91,208,145,93,88,202,227,109,60,206,
    100,212,254,61,67,109,99,22,138,121,214,126,68,3,103,214,
    60,169,218,191,206,93,177,113,1,36,113,226,56,138,15,157,
    0,167,18,58,36,189,37,39,118,63,220,218,156,153,101,115,
    50,250,61,25,72,37,71,57,94,209,22,211,131,179,39,177,
    168,69,61,60,201,240,217,0,127,7,142,51,174,74,240,43,
    148,251,3,45,64,5,10,43,129,40,99,45,88,50,42,229,
    138,224,210,58,116,73,172,119,116,15,178,30,184,151,216,156,
    59,102,115,19,243,69,102,86,226,200,27,124,90,219,118,59,
    250,18,138,175,88,236,247,33,61,16,219,183,114,87,209,69,
    1,31,60,244,241,14,35,134,203,62,87,121,251,151,52,79,
    77,120,231,193,102,166,210,230,182,182,58,169,226,188,148,212,
    51,240,109,106,231,129,186,54,196,169,149,47,240,115,7,123,
    158,227,105,16,181,14,165,167,239,246,46,144,194,60,191,141,
    58,46,206,175,142,228,104,250,157,84,194,220,208,115,47,166,
    183,150,134,102,19,25,251,110,224,191,150,231,52,212,242,62,
    117,19,191,149,250,76,213,71,178,216,71,187,189,167,120,50,
    142,163,32,64,203,175,93,200,212,236,37,74,118,46,88,8,
    55,222,13,228,151,178,19,197,189,11,22,122,146,118,96,41,
    211,104,3,224,195,212,0,151,71,175,163,55,49,252,178,12,
    143,248,93,20,252,101,228,201,115,90,60,241,188,216,118,195,
    125,153,121,251,198,48,195,153,205,101,92,163,221,200,70,181,
    35,60,13,198,23,104,193,28,108,115,194,116,246,144,47,199,
    71,248,133,110,50,138,19,220,99,157,175,129,28,242,177,220,
    247,19,90,120,126,232,165,180,42,80,80,178,253,71,101,160,
    162,128,49,101,9,125,116,209,55,44,143,233,46,143,15,244,
    116,251,90,153,173,96,198,160,130,97,138,42,150,12,203,156,
    174,85,172,233,169,138,85,153,48,249,210,108,6,143,170,85,
    171,50,53,45,222,230,223,58,230,157,170,177,94,171,136,255,
    0,236,172,153,229,
};

EmbeddedPython embedded_m5_internal_param_GarnetExtLink(
    "m5/internal/param_GarnetExtLink.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_GarnetExtLink.py",
    "m5.internal.param_GarnetExtLink",
    data_m5_internal_param_GarnetExtLink,
    2405,
    7418);

} // anonymous namespace
