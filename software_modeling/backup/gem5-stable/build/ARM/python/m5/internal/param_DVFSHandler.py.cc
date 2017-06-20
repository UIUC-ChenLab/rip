#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_DVFSHandler[] = {
    120,156,189,88,221,115,219,198,17,223,3,64,74,164,36,139,
    250,182,45,217,130,221,186,97,61,141,212,186,113,221,153,168,
    110,221,124,76,147,153,40,9,152,198,14,147,41,10,1,39,
    9,20,8,112,128,147,109,102,164,151,202,211,118,250,222,63,
    160,15,125,200,75,255,150,254,71,237,238,30,0,66,162,220,
    122,166,21,69,242,116,56,236,237,237,199,111,247,246,206,135,
    252,175,134,191,95,217,0,217,63,4,64,128,95,1,17,64,
    95,64,87,128,144,2,130,101,56,170,65,250,14,4,53,120,
    5,208,53,64,26,112,134,29,19,190,54,32,158,229,57,117,
    136,76,30,17,48,108,130,180,160,91,131,167,241,2,88,178,
    14,71,77,72,127,15,66,136,88,192,179,96,10,130,105,120,
    133,220,177,211,96,134,211,64,131,77,30,108,64,48,195,131,
    77,8,102,185,51,3,195,22,200,89,232,206,17,89,247,26,
    178,189,143,108,231,153,237,63,137,109,128,111,86,32,184,70,
    228,40,215,87,68,105,17,37,175,55,207,92,90,133,148,11,
    208,93,44,250,75,149,254,114,165,191,82,233,175,86,250,107,
    149,254,245,74,255,70,165,127,147,251,40,241,34,244,214,161,
    183,1,189,91,176,143,70,92,40,165,187,13,210,132,222,38,
    116,55,65,226,247,54,156,161,157,131,197,202,12,155,103,44,
    149,51,238,240,140,187,208,189,11,18,191,119,244,140,58,116,
    218,171,232,187,240,95,248,215,70,223,129,154,197,230,185,76,
    179,48,137,221,48,222,79,66,131,222,215,169,33,79,251,212,
    76,229,46,127,143,92,254,29,176,191,3,35,119,249,41,32,
    99,65,186,68,6,156,114,231,212,128,97,27,78,4,244,44,
    8,76,56,193,101,106,36,192,129,128,51,3,190,49,137,224,
    20,91,11,29,115,27,44,165,253,221,99,199,104,78,83,112,
    90,131,147,26,116,158,157,24,52,112,212,128,244,239,240,237,
    6,51,157,102,166,6,156,96,107,193,153,5,167,117,120,138,
    68,56,212,107,144,250,226,217,9,106,138,35,157,182,133,210,
    238,86,212,37,85,130,48,141,189,190,84,139,216,119,7,94,
    234,245,221,247,191,252,176,243,27,47,14,34,153,182,155,5,
    93,146,109,13,60,117,232,240,68,147,44,210,31,40,102,152,
    196,82,205,96,103,63,140,3,183,159,4,199,145,84,211,196,
    205,221,15,35,233,186,252,242,163,254,32,73,213,7,105,154,
    164,14,25,149,7,163,196,43,103,144,73,253,40,201,100,155,
    86,227,101,28,98,175,136,122,127,192,28,73,0,22,150,38,
    7,50,243,211,112,160,208,87,154,35,81,19,183,54,121,137,
    155,236,115,108,182,15,147,190,220,62,146,253,190,76,229,131,
    237,3,217,127,200,205,219,153,242,246,34,185,189,119,28,70,
    193,246,19,231,147,237,193,80,29,38,241,54,190,15,99,37,
    209,44,209,246,152,65,182,144,136,76,149,189,8,15,220,144,
    149,114,15,101,52,144,233,28,141,222,164,101,69,75,204,138,
    186,48,69,91,204,97,175,134,63,83,108,24,51,98,55,36,
    181,124,82,149,48,101,85,81,68,174,21,112,100,64,186,65,
    24,233,225,87,144,83,17,41,29,122,103,240,187,207,201,30,
    122,180,103,146,231,245,224,9,227,10,1,134,148,59,228,234,
    24,24,28,53,232,213,65,131,6,177,166,81,148,14,169,69,
    114,98,99,32,115,11,178,191,2,218,23,225,114,2,57,148,
    206,76,16,113,11,84,147,50,1,142,174,226,130,127,96,52,
    118,218,36,254,46,99,66,29,134,89,242,34,102,203,83,159,
    227,167,131,150,249,108,248,233,94,79,250,42,219,196,129,175,
    146,99,219,247,226,56,81,182,23,4,182,167,84,26,238,29,
    43,153,217,42,177,239,101,109,114,166,179,80,192,170,228,55,
    28,20,48,34,151,35,140,244,67,16,250,10,31,150,248,129,
    189,144,73,133,144,56,76,130,12,199,137,197,129,84,14,9,
    169,200,200,9,11,194,136,113,137,148,150,71,186,107,248,252,
    164,144,132,97,217,174,23,32,202,100,180,175,154,140,71,47,
    203,92,150,132,198,25,122,196,248,185,23,29,75,230,142,24,
    82,40,16,117,181,12,87,14,190,235,164,72,161,55,43,19,
    39,113,48,68,217,66,255,45,90,246,58,67,112,150,65,184,
    130,0,156,194,182,142,255,235,98,213,240,173,28,118,245,2,
    122,148,0,21,176,227,69,238,123,132,225,25,38,155,182,193,
    217,130,245,225,104,188,75,61,154,236,108,80,115,139,154,219,
    212,108,22,42,95,165,222,115,23,245,126,68,107,25,172,44,
    171,69,142,49,11,181,130,115,17,117,99,20,81,152,16,59,
    20,25,6,197,207,40,50,44,74,158,233,99,106,145,148,99,
    206,132,236,11,74,213,20,65,204,140,130,5,97,79,189,81,
    48,176,145,156,22,41,63,93,224,216,33,112,86,17,122,80,
    65,168,67,254,97,120,58,55,138,60,232,18,133,6,166,179,
    78,172,106,151,88,217,166,230,206,36,76,61,130,216,193,24,
    196,222,165,101,91,57,196,230,24,90,77,252,181,12,223,204,
    237,95,238,141,75,23,160,69,184,178,46,193,213,15,168,103,
    142,107,60,65,72,229,122,126,88,129,20,137,102,84,213,217,
    197,206,112,141,180,168,130,105,13,55,249,167,241,26,238,219,
    6,239,219,63,230,125,155,247,126,174,158,116,98,54,57,55,
    235,78,141,204,177,111,194,106,190,31,103,13,108,7,105,242,
    114,104,39,251,182,98,125,41,143,238,220,203,182,238,101,239,
    98,134,180,31,115,110,210,57,82,103,193,84,14,40,139,209,
    212,15,94,250,146,119,65,126,114,93,157,180,92,78,96,110,
    190,187,34,174,86,200,152,70,97,101,78,223,153,74,41,107,
    95,185,157,155,165,157,73,236,143,105,161,38,27,217,20,107,
    136,161,166,96,105,92,157,169,185,198,226,183,248,251,53,25,
    158,52,150,64,213,180,211,209,178,178,26,164,144,243,163,115,
    56,185,66,37,156,109,228,250,219,2,31,245,17,62,232,103,
    22,112,255,19,112,229,41,224,143,64,8,64,71,231,112,47,
    163,131,92,190,68,228,191,3,142,139,75,246,124,206,47,29,
    218,231,153,2,211,78,246,136,73,117,9,240,49,252,185,18,
    84,197,70,109,230,181,101,117,163,182,202,220,196,208,121,163,
    205,216,58,159,196,200,49,135,94,70,100,58,51,141,226,116,
    148,250,203,146,16,51,243,85,226,104,90,47,225,146,52,223,
    140,80,68,91,221,186,88,50,42,216,248,9,53,15,74,88,
    136,98,236,138,4,219,132,215,239,201,174,206,252,95,211,234,
    22,203,59,63,197,73,191,194,163,196,124,173,192,252,131,18,
    243,146,247,168,87,124,204,160,214,32,71,159,25,2,207,138,
    88,154,209,209,204,2,89,131,110,157,162,131,139,104,145,7,
    143,40,50,23,229,185,115,27,32,27,100,87,155,170,244,181,
    118,35,53,47,175,60,35,144,39,119,34,175,191,23,120,143,
    7,180,12,173,229,23,225,100,20,130,183,170,130,83,40,136,
    215,201,206,143,15,11,5,158,95,121,54,248,25,114,45,5,
    103,236,7,137,207,41,224,139,67,105,247,101,127,15,79,145,
    135,225,192,222,143,188,3,246,136,153,43,246,105,161,152,98,
    151,94,44,37,178,251,212,38,182,159,196,152,158,143,125,149,
    164,118,32,241,104,37,3,251,109,155,115,187,29,102,182,183,
    135,111,61,95,105,104,159,143,76,174,85,189,244,32,227,178,
    244,232,5,117,39,226,81,23,207,204,33,22,231,41,148,219,
    168,62,204,149,169,154,203,110,29,41,184,227,225,161,73,13,
    117,126,162,178,194,217,162,230,135,48,169,140,254,14,114,77,
    136,61,153,169,46,214,141,134,161,22,206,7,230,103,52,47,
    27,15,207,191,189,73,120,234,75,156,60,72,235,68,41,167,
    232,188,78,109,131,210,122,183,89,12,206,112,59,203,131,115,
    197,224,53,110,231,121,176,85,12,46,112,187,200,131,75,197,
    141,210,50,15,174,64,119,149,174,80,104,100,141,178,193,212,
    255,154,13,56,162,38,18,75,195,255,107,18,112,30,77,92,
    110,231,231,144,215,0,175,75,0,162,170,212,156,78,0,61,
    81,28,55,170,26,241,109,198,245,203,144,232,250,169,244,148,
    212,206,217,152,128,146,156,66,244,162,39,163,168,30,47,142,
    159,148,250,156,113,229,51,92,102,159,233,83,22,251,76,60,
    141,111,98,149,108,113,149,188,67,85,242,9,43,239,26,186,
    80,30,1,177,86,218,128,242,70,44,95,184,99,118,208,165,
    48,201,230,13,6,50,14,156,251,80,173,110,249,245,149,251,
    159,114,214,25,84,202,16,83,44,99,57,59,30,113,148,143,
    43,250,177,243,106,101,140,77,194,141,140,213,191,20,88,109,
    243,17,180,76,202,206,14,53,156,134,203,12,236,252,178,116,
    194,173,75,129,24,36,125,47,140,51,58,57,253,23,10,44,
    137,244,69,163,126,86,27,151,82,203,152,52,99,118,255,145,
    128,184,145,223,245,163,250,254,165,180,217,16,35,37,58,202,
    69,96,166,111,68,72,204,105,135,58,63,204,53,237,248,92,
    220,127,227,44,164,131,151,27,97,120,196,254,144,23,122,99,
    98,90,140,110,18,199,95,49,178,56,1,4,18,117,148,227,
    248,87,228,173,252,114,33,144,88,10,36,67,60,241,241,41,
    10,159,35,215,157,204,14,250,11,228,250,146,216,47,3,239,
    160,162,142,123,232,138,224,143,209,168,55,4,23,37,23,46,
    209,181,84,223,131,226,204,48,204,28,78,160,243,37,226,248,
    170,183,40,15,8,156,124,178,221,245,250,250,162,142,47,162,
    28,98,192,87,7,206,91,37,114,233,66,133,15,106,250,40,
    140,169,131,11,38,174,143,156,159,210,56,221,159,244,31,110,
    21,106,109,117,82,255,189,40,241,143,222,215,0,120,46,169,
    224,226,43,231,254,67,101,95,32,214,54,56,63,133,221,84,
    37,226,119,5,163,205,75,57,124,153,68,202,59,144,57,131,
    155,23,104,242,183,5,139,245,203,133,8,251,250,134,149,43,
    150,234,251,32,37,166,43,23,70,51,153,134,94,20,126,43,
    57,88,199,249,85,53,34,243,23,175,21,121,229,226,146,100,
    220,242,137,203,168,139,187,21,35,51,149,7,97,134,108,152,
    71,73,159,39,112,130,142,186,125,121,80,86,230,78,4,199,
    250,56,162,111,74,30,211,209,44,163,59,10,186,63,109,204,
    55,16,211,148,217,77,209,196,220,110,153,179,173,134,53,59,
    211,176,26,83,38,95,125,205,225,193,179,105,53,102,102,197,
    197,207,38,226,191,105,108,46,53,196,191,1,34,15,84,50,
};

EmbeddedPython embedded_m5_internal_param_DVFSHandler(
    "m5/internal/param_DVFSHandler.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_DVFSHandler.py",
    "m5.internal.param_DVFSHandler",
    data_m5_internal_param_DVFSHandler,
    2368,
    7210);

} // anonymous namespace
