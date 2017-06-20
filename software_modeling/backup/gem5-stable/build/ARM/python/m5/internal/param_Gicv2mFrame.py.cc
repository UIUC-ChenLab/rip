#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_Gicv2mFrame[] = {
    120,156,189,88,91,115,219,198,21,62,11,128,164,72,81,22,
    117,151,45,197,98,219,113,195,122,26,169,117,227,186,51,86,
    213,186,157,164,211,204,68,73,192,116,236,48,153,162,16,176,
    148,64,129,0,7,88,201,102,70,122,169,60,109,31,250,218,
    159,208,135,254,155,254,163,246,156,179,0,8,221,146,204,180,
    162,35,110,22,139,131,179,231,242,157,203,174,7,217,191,10,
    254,126,221,6,72,251,2,192,199,63,1,33,192,80,64,79,
    128,144,2,252,101,56,174,64,242,62,248,21,120,11,208,51,
    64,26,112,129,19,19,190,52,32,106,242,55,85,8,77,94,
    17,48,110,128,180,160,87,129,151,209,2,88,178,10,199,13,
    72,254,4,66,136,72,192,43,191,6,254,12,188,69,238,56,
    169,51,195,25,160,197,6,47,214,193,159,229,197,6,248,77,
    158,204,194,184,5,178,9,189,57,34,235,221,67,182,143,145,
    237,60,179,253,55,177,245,241,205,10,248,247,136,28,229,250,
    130,40,45,162,228,253,230,153,75,43,151,114,1,122,139,249,
    124,169,52,95,230,57,238,180,8,131,21,24,172,194,96,13,
    208,32,254,66,193,117,29,164,9,131,251,208,187,15,18,255,
    214,225,2,237,227,47,150,190,120,192,95,44,21,95,108,240,
    23,155,208,219,4,137,127,27,250,139,42,116,59,171,104,243,
    224,63,248,175,131,54,7,213,196,225,84,38,105,16,71,78,
    16,245,227,192,160,247,85,26,200,67,30,13,181,204,85,191,
    37,87,253,11,216,79,190,145,185,234,28,144,177,32,93,66,
    3,206,121,114,110,192,184,3,103,2,6,22,248,38,156,225,
    54,21,18,224,80,192,133,1,95,153,68,112,142,163,133,6,
    125,8,150,210,126,26,176,65,53,167,26,156,87,224,172,2,
    221,87,103,6,45,28,215,33,249,39,124,189,201,76,103,152,
    169,1,103,56,90,112,97,193,121,21,94,34,17,46,13,234,
    164,190,120,117,134,154,226,74,183,99,161,180,251,37,117,73,
    21,63,72,34,119,40,213,34,206,157,145,155,184,67,231,119,
    129,119,250,100,248,33,78,101,167,145,211,197,233,246,200,85,
    71,54,127,104,146,69,134,35,197,12,227,72,170,89,156,244,
    131,200,119,134,177,127,18,74,53,67,220,156,126,16,74,199,
    225,151,191,31,142,226,68,125,144,36,113,98,147,81,121,49,
    140,221,226,11,50,169,23,198,169,236,208,110,188,141,77,236,
    21,81,247,71,204,145,4,96,97,233,99,95,166,94,18,140,
    20,250,74,115,36,106,226,214,33,47,241,144,126,134,195,206,
    81,60,148,59,199,114,56,148,137,124,178,115,40,135,79,121,
    120,47,85,238,65,40,119,14,78,130,208,223,121,97,127,188,
    51,26,171,163,56,218,193,247,65,164,36,154,37,220,185,102,
    144,109,36,34,83,165,175,131,67,39,96,165,156,35,25,142,
    100,50,71,171,15,104,91,209,18,77,81,21,166,232,136,57,
    156,85,240,103,138,77,99,86,236,7,164,150,71,170,18,166,
    172,50,138,200,181,2,142,13,72,54,9,35,3,252,19,228,
    84,68,74,151,222,25,252,238,51,178,135,94,29,152,228,121,
    189,120,198,184,66,128,33,229,46,185,58,2,6,71,5,6,
    85,208,160,65,172,105,20,37,99,26,145,156,216,24,200,220,
    130,244,31,128,246,69,184,156,65,6,165,11,19,68,212,2,
    213,160,8,198,213,85,220,240,207,140,198,110,135,196,223,103,
    76,168,163,32,141,95,71,108,121,154,115,252,116,209,50,159,
    142,63,57,24,72,79,165,91,184,240,69,124,210,246,220,40,
    138,85,219,245,253,182,171,84,18,28,156,40,153,182,85,220,
    126,148,118,200,153,246,66,14,171,130,223,120,148,195,136,92,
    142,48,210,15,126,224,41,124,88,226,7,246,66,42,21,66,
    226,40,246,83,92,39,22,135,82,217,36,164,34,35,199,44,
    8,35,198,33,82,218,30,233,238,225,243,139,92,18,134,101,
    167,154,131,40,149,97,95,53,24,143,110,154,58,44,9,173,
    51,244,136,241,169,27,158,72,230,142,24,82,40,16,77,181,
    12,119,14,190,117,82,36,215,155,149,137,226,200,31,163,108,
    129,247,46,109,187,206,16,108,50,8,87,16,128,53,28,171,
    248,255,170,88,53,60,43,131,93,53,135,30,37,64,5,236,
    120,145,249,30,97,120,129,201,166,99,112,182,96,125,56,26,
    191,79,51,250,216,222,164,225,29,26,30,210,176,149,171,124,
    151,122,207,93,213,251,25,237,101,176,178,172,22,57,198,204,
    213,242,47,69,212,253,73,68,97,66,236,82,100,24,20,63,
    147,200,176,40,121,38,123,52,34,41,199,156,9,233,231,148,
    170,41,130,152,25,5,11,194,158,102,147,96,96,35,217,45,
    82,126,38,199,177,77,224,44,35,244,176,132,80,155,252,195,
    240,180,239,231,121,208,33,10,13,76,123,131,88,85,110,176,
    114,155,134,239,77,195,212,19,136,29,94,131,216,115,218,182,
    149,65,108,142,161,213,192,95,203,240,204,204,254,69,109,92,
    186,2,45,194,149,117,3,174,126,72,51,243,186,198,83,132,
    84,166,231,135,37,72,145,104,70,89,157,125,156,140,215,72,
    139,50,152,214,176,200,191,140,214,176,110,27,92,183,127,194,
    117,155,107,63,119,61,58,49,155,156,155,245,164,66,230,232,
    155,176,154,213,227,180,142,227,40,137,223,140,219,113,191,173,
    88,95,202,163,187,143,210,237,71,233,115,204,144,237,61,206,
    77,58,71,234,44,152,200,17,101,49,250,244,131,55,158,228,
    42,200,79,142,163,147,150,195,9,204,201,170,43,226,106,133,
    140,105,228,86,230,244,157,170,132,178,246,157,219,185,81,216,
    153,196,254,136,54,106,176,145,77,177,134,24,106,8,150,198,
    209,153,154,123,44,126,139,191,223,144,225,73,99,9,212,5,
    219,93,45,43,171,65,10,217,63,190,132,147,59,84,194,222,
    65,174,127,200,241,81,157,224,131,126,102,14,247,191,2,119,
    158,2,254,2,132,0,116,116,6,247,34,58,200,229,75,68,
    254,71,224,184,184,161,230,115,126,233,82,157,103,10,76,59,
    233,51,38,213,45,192,71,240,183,82,80,229,133,218,204,122,
    203,114,161,182,138,220,196,208,249,78,197,216,186,156,196,200,
    49,71,110,74,100,58,51,77,226,116,146,250,139,150,16,51,
    243,93,226,104,70,111,225,144,52,95,77,80,68,165,110,67,
    44,25,37,108,252,148,134,39,5,44,68,190,118,71,130,109,
    193,237,53,217,209,153,255,75,218,221,98,121,231,107,156,244,
    75,60,10,204,87,114,204,63,41,48,47,185,70,189,229,99,
    6,141,6,57,250,194,16,120,198,195,214,140,142,84,22,200,
    10,244,170,20,29,220,68,139,44,120,68,158,185,40,207,93,
    42,128,108,144,125,109,170,194,215,218,141,52,188,185,243,140,
    64,158,220,13,221,225,129,239,238,13,104,27,218,203,203,195,
    201,200,5,111,149,5,167,80,16,183,201,206,143,79,115,5,
    78,239,60,27,252,28,88,44,45,56,99,223,143,61,78,1,
    159,31,201,246,80,14,15,240,20,121,20,140,218,253,208,61,
    100,143,152,153,98,159,228,138,41,118,233,213,86,34,125,76,
    99,220,246,226,8,211,243,137,167,226,164,237,75,60,90,73,
    191,253,94,155,115,123,59,72,219,238,1,190,117,61,165,161,
    125,57,50,185,87,117,147,195,148,219,210,227,215,52,157,138,
    71,29,60,51,7,216,156,135,80,148,81,125,152,43,82,53,
    183,221,58,82,176,226,225,161,73,141,117,126,162,182,194,222,
    166,225,71,48,173,140,254,62,232,99,125,74,102,170,138,13,
    163,110,168,133,203,129,249,41,125,151,94,15,207,191,127,151,
    240,212,151,47,89,144,86,137,82,214,232,188,78,99,157,210,
    122,175,145,47,206,242,216,228,197,185,124,241,30,143,243,188,
    216,202,47,125,22,120,113,17,122,75,116,91,66,43,203,20,
    248,181,255,53,240,57,120,166,18,54,233,255,53,222,237,103,
    83,151,219,254,5,100,229,254,182,88,23,101,165,230,116,172,
    15,68,126,178,40,107,196,23,23,235,55,129,206,241,18,233,
    42,169,157,179,57,5,37,57,91,232,77,79,39,1,124,189,
    15,126,81,232,115,193,77,206,120,153,125,166,15,84,236,51,
    241,50,122,128,13,177,197,13,241,46,53,196,103,172,188,99,
    232,158,120,2,196,74,97,3,74,17,145,124,237,92,179,131,
    238,122,73,54,119,52,146,145,111,63,134,114,35,203,175,239,
    220,255,207,53,48,39,29,135,41,150,177,115,189,30,113,148,
    122,75,250,177,243,42,69,140,77,195,141,140,213,139,28,171,
    29,78,189,69,254,181,119,105,224,140,91,36,91,251,87,133,
    19,30,220,8,68,236,19,19,58,33,125,211,107,236,123,116,
    217,193,7,245,240,70,186,116,20,56,7,110,42,153,213,183,
    144,16,59,238,246,178,5,245,206,173,244,161,140,152,227,55,
    83,16,195,90,198,16,159,217,161,28,119,190,12,165,146,215,
    97,167,200,72,217,241,221,151,88,108,227,49,158,169,248,156,
    130,207,161,227,76,167,70,253,18,185,38,196,158,238,28,177,
    70,137,42,86,169,21,60,118,175,24,245,106,93,112,209,191,
    114,73,173,101,34,115,232,158,124,156,218,156,181,230,11,55,
    243,85,106,94,126,9,17,124,114,220,199,45,245,253,44,93,
    244,216,63,128,236,104,110,191,91,192,133,46,44,248,32,164,
    143,154,24,175,220,144,112,255,97,255,140,214,105,54,124,186,
    157,43,181,173,149,234,6,67,125,31,200,151,185,195,167,92,
    102,203,100,126,226,226,124,229,202,106,42,147,192,13,131,175,
    245,61,96,190,172,72,145,171,124,73,158,226,137,43,251,213,
    172,202,174,76,228,97,144,34,27,230,81,208,103,137,134,108,
    125,27,48,75,223,78,197,241,186,67,214,135,247,61,58,45,
    164,123,56,208,149,94,125,190,142,32,160,12,100,226,201,121,
    78,88,102,179,85,183,154,179,117,171,94,51,249,54,102,14,
    207,66,13,171,62,219,20,244,223,22,194,164,97,108,45,214,
    197,127,1,27,254,207,128,
};

EmbeddedPython embedded_m5_internal_param_Gicv2mFrame(
    "m5/internal/param_Gicv2mFrame.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_Gicv2mFrame.py",
    "m5.internal.param_Gicv2mFrame",
    data_m5_internal_param_Gicv2mFrame,
    2247,
    6761);

} // anonymous namespace
