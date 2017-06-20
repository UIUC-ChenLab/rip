#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_X86ACPIRSDP[] = {
    120,156,189,88,109,115,219,198,17,222,3,64,74,164,36,75,
    178,222,252,34,91,108,58,78,88,183,145,90,55,142,51,19,
    215,173,235,164,51,206,100,100,7,116,199,14,147,41,10,17,
    39,9,20,9,112,128,147,108,122,164,15,173,60,109,254,64,
    251,189,31,250,161,255,166,255,168,221,103,65,64,208,139,157,
    204,180,146,72,158,14,135,189,189,125,121,118,111,239,58,52,
    250,171,240,239,55,13,162,244,239,138,40,224,175,162,30,81,
    95,81,91,145,210,138,130,121,218,169,80,242,17,5,21,122,
    67,212,182,72,91,116,200,29,155,190,177,40,154,148,57,85,
    234,217,50,162,104,88,39,237,80,187,66,207,163,89,114,116,
    149,118,234,148,252,145,148,82,145,162,23,193,24,5,227,244,
    134,185,115,167,38,12,199,9,131,117,25,172,81,48,33,131,
    117,10,38,165,51,65,195,25,210,147,212,158,2,89,251,18,
    179,189,205,108,167,133,237,191,193,54,224,55,11,20,92,2,
    57,203,245,53,40,29,80,202,122,211,194,101,38,151,114,150,
    218,151,243,254,92,169,63,95,234,47,148,250,139,165,254,82,
    169,127,69,250,44,217,101,234,94,165,238,53,234,94,167,77,
    54,214,108,33,197,50,105,155,186,55,168,125,131,52,127,151,
    233,144,237,25,92,46,205,184,41,51,230,138,25,43,50,163,
    65,237,6,105,254,174,100,51,170,212,106,46,178,143,194,255,
    240,95,147,125,68,102,146,155,61,157,164,97,28,121,97,180,
    25,135,22,222,87,209,192,163,29,52,99,35,215,62,130,107,
    255,69,226,215,192,26,185,246,128,152,177,130,46,61,139,14,
    164,115,96,209,176,73,251,138,186,14,5,54,237,243,50,21,
    8,176,165,232,208,162,111,109,16,28,112,235,176,3,110,146,
    99,50,191,118,197,1,25,167,49,58,168,208,126,133,90,47,
    246,45,12,236,212,40,249,39,189,94,22,166,227,194,212,162,
    125,110,29,58,116,232,160,74,207,153,136,135,186,53,168,175,
    94,236,179,166,60,210,106,58,44,237,122,73,93,168,18,132,
    73,228,247,181,185,204,125,111,224,39,126,223,123,241,201,199,
    15,31,61,125,236,182,62,123,218,172,231,116,113,186,58,240,
    205,182,43,19,109,88,164,63,48,194,48,142,180,153,224,206,
    102,24,5,94,63,14,118,123,218,140,131,155,183,25,246,180,
    231,201,203,199,253,65,156,152,207,147,36,78,92,24,85,6,
    123,177,95,204,128,73,59,189,56,213,77,172,38,203,184,96,
    111,64,189,57,16,142,16,64,132,197,228,64,167,157,36,28,
    24,246,85,198,17,212,224,214,132,151,164,73,191,226,102,109,
    59,238,235,181,29,221,239,235,68,223,89,219,210,253,187,210,
    124,152,26,127,163,167,215,54,118,195,94,176,198,58,175,13,
    134,102,59,142,214,248,125,24,25,205,102,233,173,157,50,200,
    42,19,193,84,233,203,112,203,11,69,41,111,91,247,6,58,
    153,194,232,53,44,171,102,212,164,170,42,91,53,213,20,247,
    42,252,179,213,178,53,161,214,67,168,213,129,170,192,148,83,
    70,17,92,171,104,199,162,100,25,24,233,242,87,193,169,140,
    148,22,222,89,242,238,43,216,35,27,237,218,240,124,54,184,
    47,184,98,128,49,229,125,184,58,34,1,71,133,186,85,202,
    64,195,88,203,80,148,12,209,50,57,216,88,204,220,161,244,
    111,196,246,101,184,236,211,8,74,135,54,169,104,134,76,29,
    17,207,163,139,188,224,159,5,141,173,38,196,95,23,76,152,
    237,48,141,95,70,98,121,244,37,126,90,108,153,167,195,39,
    27,93,221,49,233,10,15,124,29,239,54,58,126,20,197,166,
    225,7,65,195,55,38,9,55,118,141,78,27,38,110,220,74,
    155,112,166,59,155,195,170,224,55,28,228,48,130,203,25,70,
    217,67,16,118,12,63,204,201,131,120,33,213,134,33,177,29,
    7,41,143,131,197,150,54,46,132,52,48,114,44,130,8,98,
    60,144,98,121,166,187,196,207,15,115,73,4,150,205,106,14,
    162,84,247,54,77,93,240,232,167,169,39,146,96,92,160,7,
    198,123,126,111,87,11,119,198,144,97,129,208,205,100,56,119,
    240,93,129,34,185,222,162,76,20,71,193,144,101,11,59,31,
    96,217,43,2,193,73,1,225,2,3,112,140,219,42,255,175,
    170,69,171,227,140,96,87,205,161,135,4,104,72,28,175,70,
    190,103,24,30,114,178,105,90,146,45,68,31,137,198,247,208,
    195,100,119,25,205,13,52,55,209,172,228,42,159,167,222,83,
    39,245,190,135,181,44,81,86,212,130,99,236,92,173,224,88,
    68,93,61,138,40,78,136,45,68,134,133,248,57,138,12,7,
    201,51,121,128,150,73,37,230,108,74,159,33,85,35,130,132,
    25,130,133,97,143,222,81,48,136,145,220,25,40,63,158,227,
    216,5,56,203,8,221,42,33,212,133,127,4,158,238,213,60,
    15,122,160,200,128,233,94,7,171,202,25,86,110,160,249,209,
    69,152,250,8,98,91,167,32,246,41,150,157,25,65,108,74,
    160,85,231,223,140,213,177,71,246,47,246,198,185,19,208,2,
    174,156,51,112,245,62,122,246,105,141,47,16,82,35,61,127,
    87,130,20,68,179,202,234,172,115,103,184,4,45,202,96,90,
    226,77,254,121,180,196,251,182,37,251,246,207,101,223,150,189,
    95,170,164,44,49,219,146,155,179,78,5,230,216,180,105,113,
    180,31,167,53,110,7,73,252,106,216,136,55,27,70,244,69,
    30,189,127,43,93,189,149,126,202,25,178,241,64,114,83,150,
    35,179,44,152,232,1,178,24,166,126,254,170,163,101,23,148,
    39,207,203,146,150,39,9,204,27,237,174,140,171,5,24,211,
    202,173,44,233,59,53,9,178,246,185,219,185,94,216,25,98,
    127,129,133,234,98,100,91,45,49,134,234,74,164,241,178,76,
    45,53,150,188,229,223,111,97,120,104,172,9,85,179,219,202,
    100,21,53,160,144,251,179,99,56,57,71,37,220,53,230,250,
    251,28,31,213,35,124,224,103,231,112,255,43,73,229,169,232,
    47,4,4,176,163,71,112,47,162,3,46,159,3,249,31,72,
    226,226,140,61,95,242,75,11,251,188,80,112,218,73,239,9,
    105,86,2,124,65,223,149,130,42,223,168,237,81,109,89,222,
    168,157,34,55,9,116,126,208,102,236,28,79,98,112,204,182,
    159,130,44,203,76,71,113,122,148,250,139,146,144,51,243,121,
    226,104,60,91,194,131,52,223,30,161,8,91,221,117,53,103,
    149,176,241,11,52,119,10,88,168,124,236,156,4,91,161,183,
    239,201,94,150,249,191,193,234,142,200,59,61,102,96,59,230,
    241,184,245,208,123,244,228,203,39,235,45,15,236,242,62,216,
    22,97,80,201,195,224,78,17,6,90,182,173,55,114,242,64,
    107,193,247,135,150,226,99,34,87,107,56,149,57,164,43,212,
    174,34,96,164,174,86,163,120,82,121,50,67,234,59,182,39,
    138,141,214,51,235,21,238,207,60,139,230,213,185,39,9,56,
    247,126,207,239,111,4,254,131,8,203,96,173,78,30,97,86,
    46,248,76,89,112,68,135,122,155,236,242,120,55,87,96,239,
    220,19,196,199,204,181,16,92,194,33,136,59,146,21,158,109,
    235,70,95,247,55,248,96,185,29,14,26,155,61,127,75,60,
    98,143,20,123,146,43,102,196,165,39,171,139,244,54,218,184,
    209,137,35,206,216,187,29,19,39,141,64,243,105,75,7,141,
    15,27,146,238,27,97,218,240,55,248,173,223,49,25,218,143,
    7,171,148,175,126,178,149,74,165,186,243,18,221,11,241,168,
    199,199,232,144,235,245,1,21,59,107,118,190,43,178,183,84,
    226,89,240,240,38,200,231,40,51,204,82,22,42,13,119,21,
    205,79,232,162,146,252,71,204,181,15,246,48,83,85,93,183,
    106,150,153,205,98,53,39,123,138,121,233,233,240,252,199,15,
    9,207,236,254,102,20,164,85,80,234,49,28,225,209,214,144,
    233,219,245,124,112,66,218,73,25,156,202,7,47,73,59,45,
    131,51,249,224,172,180,151,101,112,46,191,76,154,151,193,5,
    106,47,226,86,5,35,75,200,6,99,255,107,54,144,136,186,
    144,88,122,249,127,77,2,238,189,11,151,219,253,132,70,101,
    193,219,18,128,42,43,53,149,37,128,174,202,79,32,101,141,
    228,130,227,202,89,72,244,58,137,246,141,206,156,179,124,1,
    74,74,10,201,22,125,125,20,213,167,235,229,135,133,62,135,
    82,12,13,231,197,103,217,193,75,124,166,158,71,215,184,112,
    118,164,112,190,143,194,121,95,148,247,172,172,118,62,2,98,
    165,176,1,242,70,164,95,122,167,236,144,85,199,144,205,31,
    12,116,20,184,183,169,92,240,202,235,115,247,63,114,214,159,
    168,84,153,216,106,158,43,220,211,17,135,124,92,210,79,156,
    87,41,98,236,34,220,40,88,253,46,199,106,83,78,165,69,
    82,118,239,163,145,52,92,100,96,247,215,133,19,150,207,4,
    98,172,251,94,24,224,44,245,110,2,174,145,178,155,25,121,
    204,107,161,19,180,137,222,11,229,26,22,236,190,135,4,12,
    177,217,228,3,230,218,217,244,105,96,132,221,59,94,131,21,
    124,131,135,183,208,189,122,55,155,87,101,54,120,16,80,72,
    236,6,186,167,141,62,13,93,3,67,143,174,10,2,205,187,
    120,60,228,243,155,156,137,248,185,231,121,23,179,249,253,138,
    185,238,129,253,60,201,230,167,170,188,253,45,40,249,88,181,
    106,77,73,61,113,226,74,60,147,10,215,18,217,9,96,152,
    186,146,251,166,11,176,200,197,109,190,179,3,87,114,78,93,
    247,251,217,181,155,92,43,185,63,166,209,69,128,251,65,1,
    58,92,143,200,177,43,59,216,114,212,75,173,35,165,141,251,
    75,140,227,170,160,127,119,53,87,107,245,164,90,207,228,242,
    184,127,215,188,127,130,112,68,210,26,166,159,233,180,243,12,
    6,243,246,52,42,43,115,235,93,60,203,19,204,245,51,41,
    91,97,63,187,251,148,194,161,252,62,72,124,238,47,156,24,
    77,117,18,250,189,240,181,126,183,54,47,160,13,76,153,191,
    54,176,240,201,37,97,168,226,73,170,25,243,83,250,190,163,
    134,0,47,209,91,97,202,156,133,109,193,98,148,90,129,140,
    183,4,97,121,238,133,192,52,59,40,100,215,26,15,112,121,
    150,226,214,6,151,157,181,233,26,67,22,57,215,86,117,206,
    186,142,61,57,83,115,38,39,106,78,109,204,150,123,170,41,
    62,37,214,157,218,196,164,42,127,86,24,218,117,107,101,174,
    166,254,11,177,242,10,161,
};

EmbeddedPython embedded_m5_internal_param_X86ACPIRSDP(
    "m5/internal/param_X86ACPIRSDP.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/param_X86ACPIRSDP.py",
    "m5.internal.param_X86ACPIRSDP",
    data_m5_internal_param_X86ACPIRSDP,
    2343,
    7099);

} // anonymous namespace
