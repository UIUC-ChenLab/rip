#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_EtherTap[] = {
    120,156,189,88,91,115,219,198,21,62,11,128,148,72,81,22,
    117,183,45,217,98,219,113,195,122,26,169,117,227,56,51,81,
    220,38,173,59,211,60,40,41,232,142,29,38,83,20,34,150,
    34,40,16,224,0,43,219,244,72,121,168,220,203,67,95,251,
    19,250,208,127,211,127,212,156,115,22,11,66,146,53,147,153,
    150,150,137,245,98,119,113,246,92,190,115,217,237,65,254,87,
    193,231,87,45,128,236,91,1,16,224,79,64,4,48,18,208,
    21,32,164,128,96,13,142,43,144,126,0,65,5,222,0,116,
    45,144,22,156,99,199,134,175,45,136,27,252,77,21,34,155,
    71,4,76,234,32,29,232,86,224,89,188,12,142,172,194,113,
    29,210,63,129,16,34,22,240,60,152,131,96,30,222,32,117,
    236,212,152,224,60,208,96,157,7,107,16,44,240,96,29,130,
    6,119,22,96,210,4,217,128,238,34,45,235,222,64,178,247,
    145,236,18,147,253,15,145,13,112,102,29,130,27,180,28,249,
    250,138,86,58,180,146,247,91,98,42,77,195,229,50,116,87,
    76,127,181,212,95,43,245,215,75,253,13,238,35,7,43,48,
    220,132,225,77,24,222,130,62,42,101,185,216,237,54,72,27,
    134,91,208,221,2,137,191,219,112,142,122,11,86,74,95,108,
    243,23,171,197,23,119,248,139,187,208,189,11,18,127,119,244,
    23,85,232,180,55,208,22,225,127,241,175,141,182,0,213,192,
    230,133,76,179,48,137,189,48,238,39,161,69,243,85,106,200,
    114,61,106,230,114,19,254,154,76,248,111,96,251,5,86,110,
    194,51,64,194,130,100,137,44,56,227,206,153,5,147,54,156,
    10,24,58,16,216,112,138,219,84,136,129,35,1,231,22,124,
    99,211,130,51,108,29,84,244,93,112,148,182,223,144,21,173,
    41,205,193,89,5,78,43,208,121,126,106,209,192,113,13,210,
    127,193,235,109,38,58,207,68,45,56,197,214,129,115,7,206,
    170,240,12,23,225,208,176,70,226,139,231,167,40,41,142,116,
    218,14,114,123,80,18,151,68,9,194,52,246,71,82,45,97,
    223,27,251,169,63,242,158,168,129,76,159,250,227,118,221,44,
    74,178,221,177,175,6,46,127,101,147,58,70,99,197,212,146,
    88,170,5,236,244,195,56,240,70,73,112,18,73,53,79,164,
    188,126,24,73,207,227,201,223,141,198,73,170,158,164,105,146,
    186,164,81,30,140,18,191,248,130,244,217,139,146,76,182,105,
    55,222,198,37,242,138,86,247,199,76,145,24,96,78,233,227,
    64,102,189,52,28,43,52,148,166,72,171,137,90,155,76,196,
    77,118,128,205,222,32,25,201,189,99,57,26,201,84,62,216,
    59,146,163,135,220,188,159,41,255,48,146,123,135,39,97,20,
    236,61,255,232,195,189,241,68,13,146,120,15,231,195,88,73,
    212,73,180,119,81,27,187,184,98,133,232,190,12,143,188,144,
    37,242,6,50,26,203,116,145,70,111,211,158,162,41,26,162,
    42,108,209,22,139,216,171,224,99,139,109,107,65,28,132,36,
    83,143,228,36,52,57,101,252,144,81,5,28,91,144,110,19,
    58,134,248,19,100,78,196,72,135,230,44,158,251,61,41,67,
    143,14,109,178,185,30,60,101,68,33,180,112,229,62,25,57,
    6,134,69,5,134,85,208,112,65,148,105,252,164,19,106,113,
    57,145,177,144,184,3,217,63,1,149,139,64,57,133,28,68,
    231,54,136,184,9,170,78,62,141,163,27,184,225,159,25,135,
    157,54,177,127,192,128,80,131,48,75,94,198,172,118,234,179,
    231,116,80,51,95,78,190,56,28,202,158,202,118,112,224,171,
    228,164,213,243,227,56,81,45,63,8,90,190,82,105,120,120,
    162,100,214,82,73,235,94,214,38,75,186,203,6,83,5,189,
    201,216,96,136,236,141,24,210,47,65,216,83,248,178,202,47,
    108,133,76,42,196,195,32,9,50,28,39,18,71,82,185,196,
    164,34,37,39,204,8,195,197,163,165,180,61,174,187,129,239,
    159,26,78,24,147,237,170,65,80,38,163,190,170,51,24,253,
    44,243,152,19,26,103,220,17,225,23,126,116,34,153,58,2,
    72,33,67,212,213,60,204,22,121,55,73,10,35,52,75,18,
    39,113,48,65,198,194,222,123,180,231,77,198,95,131,17,184,
    142,232,155,195,182,138,255,87,197,134,213,115,114,204,85,13,
    238,40,238,41,96,171,139,220,240,136,193,115,140,49,109,139,
    131,4,11,195,126,248,67,234,209,199,238,54,53,119,168,185,
    75,205,142,145,119,102,66,47,94,22,250,17,109,100,177,164,
    44,19,153,196,54,50,5,23,124,233,214,212,151,48,8,118,
    200,39,44,242,156,169,79,56,20,48,211,199,212,226,82,246,
    54,27,178,167,20,158,201,119,152,24,185,9,2,158,122,83,
    55,96,13,185,77,146,124,222,32,216,37,88,150,177,121,84,
    194,166,75,198,97,96,186,183,76,248,243,104,133,134,164,187,
    69,164,42,111,81,113,139,154,31,204,92,207,83,112,29,93,
    1,215,199,180,103,51,7,215,34,131,170,142,79,211,234,217,
    185,242,139,100,184,122,9,84,132,40,231,45,136,250,49,245,
    236,171,226,190,43,48,229,66,254,182,4,38,226,203,42,203,
    66,12,76,54,73,132,50,140,54,49,165,63,139,55,49,75,
    91,156,165,127,198,89,154,51,61,215,62,58,24,219,28,143,
    117,167,66,186,232,219,176,145,103,223,172,134,237,56,77,94,
    77,90,73,191,165,88,88,138,157,251,247,178,221,123,217,199,
    24,21,91,143,57,30,233,184,168,35,95,42,199,20,185,232,
    211,39,175,122,146,211,30,191,121,158,14,84,30,7,45,47,
    79,167,136,168,117,210,164,101,84,204,33,59,83,41,69,234,
    217,42,185,94,40,153,120,254,156,118,169,179,134,109,177,137,
    232,169,11,102,197,211,161,153,203,41,158,197,231,51,210,58,
    137,43,129,10,97,183,163,25,101,25,72,26,247,167,23,16,
    50,43,9,220,61,36,249,7,131,140,234,20,25,244,216,6,
    229,127,3,174,48,5,252,21,200,246,104,226,28,229,133,83,
    144,177,87,105,249,31,129,221,225,45,25,158,99,74,135,178,
    58,175,192,80,147,61,226,165,58,225,127,14,127,47,249,146,
    73,203,118,94,67,150,211,178,83,196,35,6,205,247,74,189,
    206,197,192,69,86,25,248,25,45,211,209,104,234,158,211,88,
    95,84,127,24,141,103,134,160,121,77,223,35,86,190,153,226,
    135,18,219,150,88,181,74,168,248,57,53,15,10,64,8,51,
    54,11,174,118,224,250,244,235,233,56,255,53,109,237,48,179,
    75,115,44,134,33,80,224,188,98,112,254,160,192,185,228,116,
    244,134,79,17,212,90,100,223,115,75,224,209,14,235,47,58,
    73,57,32,43,208,173,146,71,112,153,44,114,135,17,38,84,
    81,96,187,144,235,88,21,7,90,73,133,137,181,245,168,121,
    53,219,16,64,146,239,71,254,232,48,240,31,71,180,7,109,
    212,51,46,100,25,174,155,101,174,9,254,226,58,198,249,245,
    161,225,254,197,108,221,255,67,36,89,112,205,96,15,146,30,
    251,252,211,129,108,141,228,232,16,143,135,131,112,220,234,71,
    254,17,219,194,206,165,250,194,72,165,216,152,151,235,133,236,
    62,181,73,171,151,196,24,137,79,122,42,73,91,129,196,99,
    147,12,90,239,183,56,140,183,194,172,229,31,226,172,223,83,
    26,206,23,93,145,75,81,63,61,202,184,234,60,126,73,221,
    217,219,210,195,147,112,136,133,119,12,69,186,212,167,180,34,
    42,115,73,173,189,3,51,27,30,136,212,68,71,35,170,29,
    220,93,106,126,2,239,36,120,127,64,122,33,218,164,160,170,
    216,178,106,22,51,103,214,124,73,95,100,87,253,241,31,223,
    199,31,245,37,75,238,149,85,90,41,231,232,252,77,109,141,
    194,119,183,110,6,23,184,109,240,224,162,25,188,193,237,18,
    15,54,205,229,206,50,15,174,64,119,149,110,63,104,100,141,
    60,125,238,127,245,116,118,152,217,187,202,201,255,213,193,221,
    71,239,150,105,247,35,200,19,250,117,206,45,202,18,45,106,
    231,30,10,115,94,40,139,195,183,16,235,87,176,230,245,82,
    233,43,169,109,178,61,107,241,56,48,232,29,95,77,221,245,
    106,117,251,105,33,201,57,23,48,147,53,54,149,62,32,177,
    169,196,179,248,54,150,185,14,151,185,251,84,230,158,178,216,
    158,165,43,221,41,248,42,133,244,116,59,18,203,151,222,69,
    13,232,66,150,24,243,199,99,25,7,238,125,40,215,166,60,
    61,91,155,83,24,250,22,74,165,132,45,214,176,24,189,234,
    95,20,95,75,146,177,205,42,133,71,205,220,122,12,206,191,
    24,112,182,57,190,22,65,214,221,167,134,195,106,17,81,221,
    95,22,186,191,121,21,121,135,39,253,236,53,29,118,174,159,
    196,98,134,175,53,248,77,109,94,93,22,156,140,198,76,226,
    186,57,162,192,106,195,151,183,45,226,107,178,107,8,240,156,
    33,64,47,108,41,118,162,64,70,82,201,75,72,82,36,125,
    126,188,14,36,230,201,100,130,39,31,62,80,224,123,228,121,
    239,32,195,124,162,61,7,50,2,59,102,24,81,197,28,179,
    142,199,226,117,171,86,173,9,78,214,151,110,141,53,67,84,
    65,234,226,121,146,185,28,124,150,10,227,241,245,166,201,156,
    100,103,62,220,29,248,35,125,63,197,87,48,238,143,32,63,
    58,187,239,21,32,160,219,4,62,177,232,211,32,58,31,23,
    18,92,55,184,191,160,113,234,141,30,238,26,137,118,75,18,
    253,134,76,102,241,252,53,203,58,225,72,223,230,169,229,75,
    243,65,234,99,127,253,210,104,38,211,208,143,194,215,82,221,
    185,126,219,156,34,201,108,166,153,252,213,37,11,6,50,250,
    157,179,251,133,16,203,80,72,229,81,152,33,29,38,82,90,
    158,71,159,79,140,22,46,129,175,252,233,236,113,163,171,98,
    125,60,127,76,114,101,159,97,67,119,117,181,165,26,98,136,
    98,146,141,199,227,69,225,216,141,102,205,105,44,212,156,218,
    156,205,151,45,139,120,236,169,59,181,133,134,48,255,118,16,
    105,117,107,103,165,38,190,3,132,243,194,203,
};

EmbeddedPython embedded_m5_internal_param_EtherTap(
    "m5/internal/param_EtherTap.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_EtherTap.py",
    "m5.internal.param_EtherTap",
    data_m5_internal_param_EtherTap,
    2252,
    6741);

} // anonymous namespace
