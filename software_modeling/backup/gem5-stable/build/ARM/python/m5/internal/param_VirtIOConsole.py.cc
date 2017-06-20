#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_VirtIOConsole[] = {
    120,156,197,88,109,111,219,200,17,158,37,41,217,146,237,88,
    126,139,243,226,196,74,114,73,212,160,103,183,233,165,41,112,
    105,218,92,238,10,228,128,56,87,202,109,114,186,67,89,154,
    92,219,148,41,82,37,215,78,116,176,11,180,14,122,253,80,
    244,219,253,132,126,232,191,233,239,232,159,104,103,102,73,138,
    182,101,52,64,27,213,145,54,171,221,217,217,157,153,103,94,
    118,61,200,254,42,248,253,121,19,32,253,167,0,240,241,35,
    32,4,232,9,232,8,16,82,128,191,8,123,21,72,62,2,
    191,2,111,1,58,6,72,3,142,177,99,194,87,6,68,211,
    188,166,10,161,201,35,2,6,117,144,22,116,42,240,50,154,
    3,75,86,97,175,14,201,111,65,8,17,9,120,229,79,128,
    63,9,111,145,59,118,106,204,112,18,104,176,206,131,53,240,
    167,120,176,14,254,52,119,166,96,208,0,57,13,157,25,34,
    235,92,64,182,247,144,237,44,179,253,7,177,245,113,102,9,
    252,11,68,142,231,250,146,40,45,162,228,253,102,153,75,35,
    63,229,28,116,230,243,254,66,169,191,88,234,47,149,250,23,
    75,253,229,82,255,82,169,127,185,212,191,82,234,95,45,245,
    87,74,253,107,165,254,245,82,127,149,251,40,237,60,116,155,
    208,189,1,221,155,176,141,6,152,43,36,187,5,210,132,238,
    7,208,249,0,36,126,110,193,49,218,200,159,47,173,184,205,
    43,22,138,21,119,120,197,93,232,220,5,137,159,59,122,69,
    21,218,173,139,104,247,224,95,248,215,66,187,131,154,198,230,
    64,38,105,16,71,78,16,109,199,129,65,243,85,106,8,37,
    30,53,19,25,92,158,18,92,254,14,140,21,223,200,224,114,
    4,200,88,144,44,161,1,71,220,57,50,96,208,130,67,1,
    93,11,124,19,14,113,155,10,29,96,71,192,177,1,95,155,
    68,112,132,173,133,70,189,14,150,210,88,233,178,81,53,167,
    9,56,170,192,97,5,218,175,14,13,26,216,171,65,242,55,
    248,102,133,153,78,50,83,3,14,177,181,224,216,130,163,42,
    188,68,34,28,234,214,72,124,241,234,16,37,197,145,118,203,
    194,211,110,148,196,37,81,252,32,137,220,158,84,139,216,119,
    250,110,226,246,156,95,7,137,122,246,226,105,28,165,113,40,
    91,245,156,50,78,215,250,174,218,181,121,169,73,58,233,245,
    21,179,140,35,169,166,176,179,29,68,190,211,139,253,253,80,
    170,73,226,231,108,7,161,116,28,158,124,214,235,199,137,250,
    44,73,226,196,38,181,242,96,24,187,197,10,82,170,23,198,
    169,108,209,110,188,141,77,236,21,81,111,247,153,35,29,128,
    143,75,139,125,153,122,73,208,87,104,45,205,145,168,137,91,
    139,236,196,77,218,198,102,125,55,238,201,245,61,217,235,201,
    68,222,95,223,145,189,7,220,124,152,42,119,43,148,235,91,
    251,65,232,175,63,177,159,175,247,7,106,55,142,214,113,62,
    136,148,68,197,132,235,35,84,178,134,100,243,196,252,117,176,
    227,4,44,150,179,43,195,190,76,102,104,244,10,109,44,26,
    98,90,84,133,41,90,98,6,123,21,252,154,98,197,152,18,
    27,1,9,230,145,176,132,43,171,140,36,50,175,128,61,3,
    146,21,194,73,23,63,130,12,139,104,105,211,156,193,115,191,
    36,141,232,209,174,73,214,215,131,135,140,45,4,25,82,62,
    34,115,71,192,0,169,64,183,10,26,56,136,55,141,164,100,
    64,45,146,19,27,3,153,91,144,126,7,168,97,132,204,33,
    100,112,58,54,65,68,13,80,117,138,36,56,122,17,55,252,
    35,35,178,221,162,227,111,48,42,212,110,144,198,175,35,214,
    61,245,217,135,218,168,153,47,6,47,182,186,210,83,233,42,
    14,124,25,239,55,61,55,138,98,213,116,125,191,233,42,149,
    4,91,251,74,166,77,21,55,111,167,45,50,167,61,151,3,
    171,224,55,232,231,64,34,163,35,144,244,15,63,240,20,254,
    88,224,31,108,133,84,42,4,197,110,236,167,56,78,44,118,
    164,178,233,144,138,148,28,243,65,24,51,14,145,210,246,72,
    119,1,127,63,201,79,194,192,108,85,115,24,165,50,220,86,
    117,70,164,155,166,14,159,132,198,25,124,196,248,192,13,247,
    37,115,71,20,41,60,16,117,245,25,198,0,191,75,36,74,
    46,57,139,19,197,145,63,192,211,5,222,93,218,248,18,131,
    112,154,97,184,132,16,156,192,182,138,255,87,197,69,195,179,
    50,224,85,115,240,81,24,84,192,166,23,153,245,17,136,199,
    24,114,90,6,199,12,150,136,61,242,38,245,104,177,189,66,
    205,53,106,174,83,179,154,11,253,126,37,159,57,45,249,67,
    218,205,96,113,89,48,50,142,153,11,230,159,240,170,203,67,
    175,194,192,216,38,239,48,200,135,134,222,97,81,16,77,30,
    83,139,164,236,119,38,164,155,20,178,201,139,152,25,57,12,
    66,159,122,67,135,96,53,217,13,18,127,50,199,178,77,0,
    45,163,116,167,132,82,155,44,196,16,181,47,231,209,208,33,
    10,13,78,251,42,177,170,140,208,115,147,154,27,227,81,246,
    16,102,59,103,96,246,49,109,220,200,96,54,195,240,170,227,
    183,97,120,102,102,129,34,75,46,156,130,23,97,203,26,129,
    173,59,212,51,207,202,60,86,88,101,146,254,162,4,43,58,
    156,81,22,104,3,59,131,101,146,163,12,168,101,76,248,47,
    163,101,204,225,6,231,240,31,112,14,231,58,128,171,48,29,
    160,77,142,209,186,83,33,133,108,155,112,49,203,205,105,13,
    219,126,18,191,25,52,227,237,166,98,137,41,158,62,186,157,
    174,221,78,63,198,72,217,124,204,49,74,199,74,29,13,19,
    217,167,104,70,75,63,123,227,73,206,135,252,203,113,116,240,
    114,56,144,57,89,158,69,108,45,145,58,141,92,207,28,198,
    83,149,80,244,30,131,166,235,133,166,233,224,159,211,86,117,
    86,179,41,150,17,71,117,193,231,113,116,204,230,138,139,103,
    241,251,9,169,158,100,150,64,117,185,221,214,167,101,65,72,
    36,251,251,39,176,242,94,197,176,215,145,239,175,114,140,84,
    135,24,161,175,153,131,254,91,224,74,84,192,159,128,80,128,
    198,206,64,95,248,8,153,125,129,200,127,3,236,29,35,242,
    63,199,153,54,229,124,166,192,240,147,62,100,82,93,14,124,
    14,127,46,185,86,158,180,205,172,214,44,39,109,171,136,81,
    12,159,119,74,204,214,201,96,70,166,217,117,83,34,211,17,
    106,232,173,195,36,80,20,136,24,161,223,47,150,38,245,38,
    14,157,231,235,33,146,40,237,93,21,11,70,9,31,63,164,
    230,126,1,13,145,143,189,183,163,173,194,249,25,218,209,89,
    224,43,218,223,226,19,207,78,112,4,58,193,165,192,126,37,
    199,254,253,2,251,146,51,214,91,190,124,80,107,144,185,143,
    13,129,183,79,44,214,232,178,103,129,172,64,167,74,94,194,
    133,181,200,156,72,228,49,140,246,59,145,14,89,41,27,90,
    93,133,197,181,49,169,121,51,134,216,64,246,124,20,186,189,
    45,223,125,188,79,27,209,110,94,238,86,70,126,244,70,249,
    232,228,18,226,188,211,243,207,7,185,8,7,99,136,11,63,
    70,190,197,209,217,11,252,216,227,96,176,185,43,155,61,217,
    219,194,251,229,110,208,111,110,135,238,14,91,197,204,68,123,
    145,139,166,216,172,167,139,139,244,30,181,113,211,195,189,84,
    178,239,169,56,105,250,18,175,92,210,111,126,216,228,72,223,
    12,210,166,187,133,179,174,167,52,196,79,250,40,87,176,110,
    178,147,114,177,186,247,154,186,99,178,170,131,247,233,0,139,
    246,215,80,164,85,125,205,43,2,55,151,227,218,99,48,3,
    226,101,74,13,116,172,162,66,195,94,163,230,123,48,190,248,
    254,145,54,4,164,164,170,170,184,106,212,12,46,229,78,16,
    126,65,107,211,179,142,250,151,119,113,84,253,64,148,185,107,
    149,40,229,4,221,231,169,173,81,152,239,212,243,193,41,110,
    167,121,112,38,31,188,192,237,44,15,54,242,135,169,57,30,
    156,135,206,2,189,166,208,200,34,133,128,137,255,54,4,176,
    19,141,201,125,126,255,63,245,124,251,225,255,225,228,246,79,
    32,43,1,206,243,122,81,22,107,70,131,173,43,242,91,71,
    89,38,126,218,184,50,26,122,142,151,72,87,73,109,162,149,
    177,8,202,177,67,111,251,135,161,51,159,173,145,159,20,50,
    29,115,241,51,88,100,203,233,11,23,91,78,188,140,174,96,
    177,108,113,177,252,136,138,229,67,86,128,99,232,122,121,8,
    200,74,161,135,101,108,34,249,218,25,161,11,93,19,211,233,
    220,126,95,70,190,125,15,202,101,46,79,143,1,7,20,174,
    190,133,82,45,98,138,69,172,107,207,122,31,5,227,146,140,
    108,194,74,225,111,227,49,38,163,246,175,57,106,91,28,140,
    139,136,108,63,162,134,99,112,17,126,237,159,21,166,184,113,
    14,36,127,103,75,239,160,29,124,35,233,42,245,14,84,88,
    31,241,117,165,24,81,55,207,91,179,153,184,81,90,176,126,
    7,50,226,77,118,24,14,169,230,57,171,80,79,189,0,53,
    197,172,255,35,17,49,166,188,150,15,176,217,217,75,125,25,
    74,37,71,1,84,145,42,179,167,0,95,98,154,142,7,120,
    55,227,219,14,254,14,29,103,92,185,237,167,200,247,136,54,
    160,87,76,204,109,162,138,217,109,9,175,240,75,70,173,90,
    19,92,48,156,122,250,214,167,162,86,87,246,131,212,230,56,
    55,91,192,129,159,103,243,196,77,200,97,163,110,184,61,253,
    180,198,15,71,246,45,200,174,249,246,221,2,86,244,252,193,
    215,41,125,105,69,239,230,98,134,107,23,251,71,185,90,123,
    15,214,114,177,214,180,88,155,153,234,249,125,184,247,64,93,
    27,73,245,44,82,9,138,142,202,14,249,57,227,44,69,123,
    144,42,217,83,87,79,77,202,104,191,231,60,151,189,56,25,
    60,143,125,169,86,78,205,63,241,253,196,118,163,29,233,28,
    72,42,198,24,233,39,8,178,74,76,243,200,169,154,35,207,
    112,146,246,204,89,52,17,78,234,39,85,190,92,156,157,127,
    26,198,222,158,244,51,154,209,234,96,154,79,227,158,139,227,
    163,119,105,7,249,46,115,167,230,253,132,86,45,157,26,77,
    101,18,184,97,238,182,103,249,105,244,125,42,15,2,79,126,
    226,166,250,65,55,167,81,244,242,120,14,93,163,240,193,225,
    160,46,203,206,36,67,246,169,68,238,4,104,201,132,121,158,
    94,152,165,8,66,254,185,206,93,102,50,38,87,212,55,30,
    253,48,243,152,158,0,211,77,108,232,209,182,54,91,67,183,
    164,236,97,138,58,230,15,203,156,110,212,172,233,169,154,85,
    155,48,249,173,109,6,111,184,117,171,54,53,45,206,255,183,
    138,238,92,55,86,231,107,226,223,175,80,153,241,
};

EmbeddedPython embedded_m5_internal_param_VirtIOConsole(
    "m5/internal/param_VirtIOConsole.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_VirtIOConsole.py",
    "m5.internal.param_VirtIOConsole",
    data_m5_internal_param_VirtIOConsole,
    2413,
    7403);

} // anonymous namespace
