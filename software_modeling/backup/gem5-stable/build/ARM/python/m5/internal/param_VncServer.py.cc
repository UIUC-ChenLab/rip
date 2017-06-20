#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_VncServer[] = {
    120,156,189,88,253,114,219,198,17,223,3,64,74,164,72,139,
    178,44,201,150,228,136,77,199,13,235,105,196,214,141,235,206,
    88,117,227,102,210,153,100,166,114,10,166,181,195,100,138,66,
    192,137,4,69,2,28,224,100,153,25,234,159,202,211,246,5,
    250,8,253,163,111,211,55,106,119,247,0,16,162,228,78,102,
    82,74,38,206,135,195,221,222,126,252,246,227,206,131,244,175,
    132,207,199,77,128,36,22,0,62,254,4,12,1,70,2,186,
    2,132,20,224,223,129,147,18,196,31,129,95,130,183,0,93,
    3,164,1,23,216,49,225,107,3,194,26,175,41,195,208,228,
    17,1,147,42,72,11,186,37,120,25,174,129,37,203,112,82,
    133,248,207,32,132,8,5,188,242,151,192,95,134,183,72,29,
    59,21,38,184,12,52,88,229,193,10,248,43,60,88,5,191,
    198,157,21,152,52,64,214,160,91,167,105,221,91,72,246,33,
    146,93,101,178,255,38,178,62,126,217,0,255,22,77,71,190,
    190,162,153,22,205,228,253,86,153,74,35,227,114,13,186,183,
    179,254,122,161,127,167,208,223,224,62,238,122,27,6,155,48,
    216,130,193,93,56,70,69,172,229,59,220,3,105,194,96,27,
    186,219,32,241,119,15,46,80,87,254,237,194,138,29,94,177,
    158,175,216,229,21,247,161,123,31,36,254,118,245,138,50,116,
    90,155,168,255,224,63,248,215,66,253,131,170,97,243,90,198,
    73,16,133,78,16,30,71,129,65,223,203,212,144,181,60,106,
    150,82,179,125,66,102,251,23,176,205,124,35,53,219,57,32,
    97,65,178,12,13,56,231,206,185,1,147,22,76,5,12,44,
    240,77,152,226,54,37,98,160,39,224,194,128,111,76,154,112,
    142,173,133,202,125,15,44,165,109,54,96,229,106,74,75,112,
    94,130,105,9,58,175,166,6,13,156,84,32,254,39,124,187,
    203,68,151,153,168,1,83,108,45,184,176,224,188,12,47,113,
    18,14,13,42,36,190,120,53,69,73,113,164,211,178,144,219,
    195,130,184,36,138,31,196,161,59,146,170,129,125,103,236,198,
    238,200,249,99,232,117,100,140,122,104,85,179,89,81,178,63,
    118,85,223,230,101,38,233,99,52,86,76,46,10,165,90,193,
    206,113,16,250,206,40,242,79,135,82,45,19,45,231,56,24,
    74,199,225,143,159,141,198,81,172,62,141,227,40,182,73,165,
    60,56,140,220,124,5,41,212,27,70,137,108,209,110,188,141,
    77,228,21,205,62,30,51,69,98,128,89,165,197,190,76,188,
    56,24,43,180,148,166,72,179,137,90,139,108,196,77,242,2,
    155,118,63,26,201,246,137,28,141,100,44,31,181,123,114,244,
    152,155,15,19,229,30,13,101,251,232,52,24,250,237,231,246,
    239,218,227,137,234,71,97,27,191,7,161,146,168,148,97,123,
    78,29,251,56,229,54,17,62,11,122,78,192,34,57,125,57,
    28,203,184,78,163,219,180,169,104,136,154,40,11,83,180,68,
    29,123,37,124,76,177,107,172,136,195,128,132,242,72,80,194,
    147,85,68,16,153,85,192,137,1,241,46,225,99,128,63,65,
    6,69,148,116,232,155,193,223,126,79,218,208,163,3,147,172,
    174,7,167,140,41,4,23,206,60,32,51,135,192,192,40,193,
    160,12,26,48,136,51,141,160,120,66,45,78,39,50,6,18,
    183,32,249,7,160,118,17,42,83,72,97,116,97,130,8,27,
    160,170,228,201,56,186,137,27,254,133,145,216,105,17,251,135,
    140,8,213,15,146,232,44,100,189,83,159,125,167,131,154,249,
    98,242,226,104,32,61,149,236,225,192,87,209,105,211,115,195,
    48,82,77,215,247,155,174,82,113,112,116,170,100,210,84,81,
    243,65,210,34,83,218,107,25,168,114,122,147,113,6,34,50,
    56,130,72,191,248,129,167,240,101,157,95,216,10,137,84,8,
    136,126,228,39,56,78,36,122,82,217,196,164,34,37,71,204,
    8,227,197,161,169,180,61,206,187,133,239,207,51,78,24,148,
    173,114,6,161,68,14,143,85,149,209,232,38,137,195,156,208,
    56,3,143,8,191,118,135,167,146,169,35,130,20,50,68,93,
    205,195,130,161,119,151,196,200,164,102,81,194,40,244,39,200,
    89,224,125,64,155,222,101,0,214,24,130,27,8,191,37,108,
    203,248,127,89,108,26,158,149,130,174,156,1,143,66,159,2,
    54,187,72,45,143,32,188,192,48,211,50,56,78,176,52,236,
    137,239,83,143,22,219,187,212,220,167,230,61,106,246,50,129,
    23,39,117,125,94,234,39,180,147,193,162,178,80,100,20,51,
    19,202,191,228,77,247,102,222,132,129,176,67,94,97,144,239,
    204,188,194,162,160,25,63,163,22,167,178,191,153,144,124,73,
    33,154,188,135,137,145,163,32,228,169,55,115,4,86,145,77,
    65,179,181,156,97,216,38,96,22,209,217,43,160,211,38,235,
    48,52,237,123,89,4,116,104,134,6,165,189,67,164,74,215,
    232,184,73,205,15,22,175,232,25,188,122,87,224,245,148,54,
    109,164,240,170,51,172,170,248,52,12,207,76,181,159,103,196,
    245,57,88,17,166,172,107,48,245,35,234,153,87,229,189,49,
    56,165,82,254,182,0,39,98,204,40,10,115,136,157,201,22,
    201,80,4,210,22,38,246,151,225,22,230,106,131,115,245,79,
    57,87,115,190,231,170,71,7,100,147,99,178,238,148,72,25,
    199,38,108,166,57,56,169,96,59,142,163,55,147,102,116,220,
    84,44,45,197,207,131,7,201,254,131,228,41,70,198,230,51,
    142,73,58,54,234,232,23,203,49,69,47,90,250,233,27,79,
    114,238,227,55,199,209,193,202,225,192,229,164,57,21,49,181,
    65,170,52,50,29,115,216,78,84,76,209,122,193,90,174,230,
    90,38,166,63,167,109,170,172,98,83,108,33,126,170,130,121,
    113,116,124,230,170,138,191,226,243,27,82,59,201,43,129,106,
    96,187,163,57,101,33,72,28,251,39,151,48,178,48,17,236,
    54,210,252,67,134,141,242,12,27,244,152,25,208,255,6,92,
    105,10,248,43,144,245,209,200,41,208,115,191,32,115,175,211,
    244,63,1,123,196,53,121,158,227,74,135,114,59,207,192,112,
    147,60,225,169,58,237,127,14,127,47,184,83,150,156,205,180,
    150,44,38,103,43,143,73,12,155,239,148,128,173,203,193,139,
    204,210,119,19,154,166,35,210,204,67,103,1,63,47,2,49,
    34,47,14,67,203,122,3,135,120,249,102,134,32,74,111,59,
    98,221,40,224,226,103,212,60,202,33,33,178,177,133,176,181,
    7,239,206,194,142,142,246,95,211,222,22,115,187,186,196,30,
    154,83,200,177,94,202,176,254,40,199,186,228,172,244,150,15,
    20,212,26,100,226,11,67,224,201,14,11,49,58,72,89,32,
    75,208,45,147,87,112,193,44,82,167,17,89,188,162,232,118,
    41,229,177,50,14,181,154,114,43,107,3,82,243,102,193,113,
    128,108,120,48,116,71,71,190,251,236,132,54,161,157,188,204,
    141,140,140,237,70,145,109,114,1,241,46,206,249,245,113,198,
    254,235,5,199,128,95,32,205,156,109,70,188,31,121,236,248,
    95,246,101,115,36,71,71,120,86,236,7,227,230,241,208,237,
    177,53,204,84,172,23,153,88,138,205,57,95,56,36,15,169,
    141,154,94,20,98,64,62,245,84,20,55,125,137,71,40,233,
    55,63,108,114,52,111,6,73,211,61,194,175,174,167,52,164,
    47,251,35,87,165,110,220,75,184,0,61,57,163,238,13,88,
    211,193,115,113,128,69,248,8,242,180,169,143,108,121,112,230,
    242,90,123,8,102,56,60,28,169,137,142,73,84,68,216,251,
    212,252,24,110,38,134,127,4,12,42,72,72,69,101,177,99,
    84,12,181,90,116,199,47,104,77,114,213,41,207,190,139,83,
    234,139,150,212,53,203,52,83,46,209,121,156,218,10,133,241,
    110,53,27,92,225,182,198,131,245,236,46,231,22,15,174,242,
    253,72,153,71,214,200,179,151,190,175,103,179,127,220,128,103,
    168,255,171,67,219,79,110,152,107,251,151,144,102,241,119,57,
    179,40,138,84,215,107,7,34,59,40,20,229,225,27,136,205,
    171,200,114,188,88,186,74,106,179,236,46,92,64,14,5,122,
    203,179,153,127,94,45,107,159,231,178,92,112,221,50,185,195,
    214,210,103,35,182,150,120,25,110,99,125,107,113,125,123,64,
    245,237,148,5,119,12,93,226,206,0,88,202,229,39,85,134,
    242,204,153,211,129,46,97,137,51,119,60,150,161,111,63,132,
    98,85,202,159,23,108,247,167,26,142,179,18,194,20,119,176,
    12,189,234,101,20,83,11,178,177,217,74,185,95,45,222,128,
    140,208,139,12,161,45,186,108,154,5,86,251,128,26,14,165,
    121,20,181,127,157,171,127,251,26,248,133,167,132,106,58,234,
    252,175,207,88,200,176,125,244,43,31,4,231,103,242,93,23,
    145,121,231,71,34,66,234,163,23,86,56,251,131,47,135,82,
    201,121,72,232,203,70,157,35,124,137,57,46,154,224,225,133,
    143,4,248,62,116,156,155,72,14,191,74,213,204,193,10,147,
    131,40,99,122,216,16,27,70,165,92,17,156,103,231,110,127,
    53,63,84,6,235,226,119,146,216,28,71,86,115,19,240,45,
    101,150,243,200,90,92,252,29,186,35,125,203,196,247,40,246,
    15,33,61,253,218,31,228,166,164,27,1,62,113,232,243,28,
    122,17,215,0,156,242,237,159,103,214,29,61,222,207,4,218,
    207,5,250,44,28,159,42,190,38,29,61,86,59,215,206,234,
    4,35,125,37,167,214,230,190,251,177,139,253,141,185,209,68,
    198,129,59,12,190,213,119,112,217,48,231,245,185,109,151,53,
    26,248,133,179,237,229,32,200,22,142,101,47,72,144,4,175,
    207,38,167,161,129,108,160,118,175,129,84,113,225,13,128,65,
    23,170,250,220,252,140,110,102,146,143,177,161,123,180,202,106,
    5,129,65,17,195,196,99,107,93,88,102,173,81,177,106,43,
    21,171,178,100,242,53,72,29,15,35,85,171,178,82,19,250,
    223,30,194,167,106,236,173,85,196,127,1,16,4,171,213,
};

EmbeddedPython embedded_m5_internal_param_VncServer(
    "m5/internal/param_VncServer.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_VncServer.py",
    "m5.internal.param_VncServer",
    data_m5_internal_param_VncServer,
    2223,
    6630);

} // anonymous namespace
