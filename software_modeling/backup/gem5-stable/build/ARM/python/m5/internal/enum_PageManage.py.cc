#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_enum_PageManage[] = {
    120,156,189,87,221,110,27,85,16,158,179,187,118,98,199,78,
    156,166,77,210,36,180,6,84,176,16,196,80,64,189,104,85,
    209,162,34,81,169,105,89,83,181,117,43,22,199,123,146,172,
    99,239,90,187,39,105,141,156,27,82,1,47,192,35,112,193,
    219,240,70,48,223,172,215,118,126,144,184,9,81,118,114,118,
    206,236,156,249,249,102,230,164,77,163,159,28,63,95,85,137,
    146,167,138,200,231,95,69,93,162,158,162,166,34,165,21,249,
    21,218,207,81,252,5,249,57,122,75,212,180,72,91,116,204,
    11,155,94,90,20,150,228,155,60,117,109,225,40,26,20,73,
    59,212,204,209,179,112,145,28,157,167,253,34,197,63,146,82,
    42,84,244,220,159,33,127,150,222,178,118,94,20,68,225,44,
    129,89,20,102,129,252,57,97,22,201,47,201,98,142,6,21,
    210,37,106,150,33,214,156,103,181,31,177,218,5,81,251,23,
    212,250,188,179,72,254,60,196,217,174,23,144,116,32,41,231,
    45,136,22,86,97,83,103,17,244,24,110,241,203,37,106,94,
    18,238,210,52,247,50,53,47,11,247,202,52,119,153,154,203,
    194,93,153,230,174,82,115,85,184,87,167,185,107,212,92,19,
    238,58,53,215,17,153,70,237,18,135,56,248,155,127,106,28,
    98,50,37,38,135,58,78,130,40,244,130,112,39,10,44,236,
    231,65,144,144,54,200,204,40,51,95,35,51,127,146,164,197,
    183,70,153,57,34,82,120,39,234,90,116,36,139,35,139,6,
    53,26,42,234,56,228,219,52,228,99,114,48,105,87,209,177,
    69,175,108,8,28,49,117,56,126,215,200,49,105,90,58,18,
    191,84,211,12,29,229,104,152,163,198,243,161,5,198,126,129,
    226,63,232,167,13,81,58,43,74,45,26,50,117,232,216,161,
    163,60,61,99,33,102,117,10,136,186,122,62,100,79,153,211,
    168,57,108,237,214,148,187,112,197,15,226,176,213,211,166,194,
    107,79,135,7,61,239,73,107,87,63,106,133,76,107,197,76,
    42,74,54,251,45,179,231,202,103,54,226,209,235,27,81,23,
    133,218,204,241,98,39,8,125,175,23,249,7,93,109,102,161,
    203,219,9,186,218,243,100,243,219,94,63,138,205,131,56,142,
    98,23,33,21,102,55,106,141,191,64,64,219,221,40,209,53,
    156,38,199,184,80,111,32,189,211,23,141,48,64,76,197,199,
    190,78,218,113,208,55,156,169,84,35,164,161,173,134,28,9,
    73,30,51,169,239,69,61,93,223,215,189,158,142,245,205,250,
    174,238,125,41,228,147,196,180,182,187,186,190,125,16,116,253,
    250,61,247,81,189,63,48,123,81,88,231,253,32,52,154,131,
    210,173,159,10,199,38,139,0,48,201,235,96,215,11,196,37,
    111,79,119,251,58,46,131,187,134,67,85,69,149,84,94,217,
    170,166,202,188,202,241,99,171,13,107,78,109,5,112,170,13,
    71,129,39,103,26,65,72,171,162,125,139,226,13,224,163,195,
    191,10,9,101,148,52,176,103,201,222,119,136,70,202,237,216,
    200,122,202,28,10,166,24,92,44,121,7,105,14,73,128,145,
    163,78,158,82,192,48,206,82,4,197,3,80,22,135,26,139,
    149,59,148,252,78,28,93,134,202,144,70,48,58,182,73,133,
    21,50,69,20,43,115,151,249,192,159,5,137,141,26,204,223,
    18,68,152,189,32,137,94,135,18,119,172,165,118,26,28,153,
    39,131,199,219,29,221,54,201,117,102,188,136,14,170,237,86,
    24,70,166,218,242,253,106,203,152,56,216,62,48,58,169,154,
    168,122,35,169,33,149,238,98,6,170,177,190,65,63,3,17,
    18,206,32,74,95,252,160,109,248,101,73,94,36,11,137,54,
    12,136,189,200,79,152,15,21,187,218,184,48,210,32,200,145,
    24,34,120,241,32,138,227,89,110,158,223,239,101,150,8,40,
    107,249,12,66,137,238,238,152,162,160,177,149,36,158,88,2,
    190,0,15,138,15,91,221,3,45,218,25,65,134,13,194,50,
    181,225,130,161,183,10,55,50,175,197,149,48,10,253,1,91,
    22,180,63,196,161,171,2,192,146,64,240,10,195,111,134,105,
    158,255,230,213,178,213,118,70,160,203,103,192,91,134,203,36,
    105,87,163,204,51,8,143,185,205,212,44,233,19,226,141,84,
    226,123,88,225,99,119,3,228,29,144,107,32,215,51,135,47,
    206,235,242,105,175,111,225,36,75,92,21,167,144,20,59,115,
    202,63,81,77,87,39,213,196,141,176,129,170,176,80,59,147,
    170,112,208,52,227,187,160,44,42,245,102,83,242,61,90,52,
    170,71,148,161,80,24,242,88,77,10,65,66,228,162,105,214,
    102,51,12,187,0,230,52,58,119,167,208,233,34,59,2,77,
    247,106,214,1,61,72,164,160,116,215,161,42,119,78,140,171,
    32,239,94,124,160,39,240,218,61,3,175,219,56,180,50,130,
    87,89,96,85,228,167,98,181,237,81,244,199,19,113,233,20,
    172,128,41,231,28,76,125,128,149,125,214,223,255,13,78,35,
    47,191,153,130,19,12,179,166,157,217,226,197,96,5,62,76,
    3,105,133,7,251,179,112,133,103,181,37,179,250,83,153,213,
    50,239,229,98,147,54,100,91,122,114,186,200,33,24,59,54,
    45,143,102,112,82,96,218,143,163,55,131,106,180,83,53,226,
    45,250,231,157,27,201,230,141,228,54,119,198,234,93,233,73,
    105,111,76,187,95,172,251,232,94,248,244,193,155,182,150,217,
    39,111,158,151,54,43,79,26,151,55,154,169,140,169,43,8,
    165,149,197,88,218,118,98,98,116,235,11,142,114,113,28,101,
    24,253,16,199,20,37,196,182,90,97,252,20,149,216,226,165,
    253,89,110,85,178,203,207,125,132,29,254,106,194,53,215,109,
    164,150,138,19,112,199,253,248,4,70,46,204,5,183,206,58,
    159,102,216,200,79,176,129,199,206,128,254,43,95,78,20,224,
    241,11,33,251,156,228,17,208,199,117,129,116,47,65,252,7,
    146,138,56,103,206,75,95,105,96,182,139,4,183,155,228,150,
    136,166,99,255,33,253,54,85,78,217,112,182,71,119,201,233,
    225,236,140,123,146,192,230,63,13,96,231,100,243,66,90,246,
    90,9,196,210,142,52,169,208,73,195,31,95,2,185,35,95,
    28,134,102,211,3,60,216,242,106,130,32,140,183,117,181,100,
    77,225,226,51,144,155,99,72,168,140,119,33,102,93,167,127,
    159,194,94,218,237,95,226,108,71,172,93,152,145,8,158,250,
    63,34,181,115,99,28,198,65,226,130,227,46,128,88,89,197,
    115,127,224,171,165,25,200,125,37,61,114,204,66,217,111,241,
    149,36,189,82,99,62,187,239,211,168,171,186,184,12,184,155,
    52,154,52,130,228,180,79,132,250,181,116,10,73,173,251,57,
    248,72,61,235,12,69,127,59,10,57,42,161,145,27,15,184,
    102,45,219,110,249,45,110,56,135,250,164,92,249,244,182,220,
    143,229,34,127,66,208,149,127,36,214,199,123,231,107,155,63,
    179,47,159,108,157,200,193,217,79,78,238,139,237,237,195,86,
    252,63,52,9,73,211,157,180,221,222,197,64,79,238,51,193,
    245,171,176,80,80,121,11,119,127,155,187,93,89,57,118,169,
    82,112,74,115,5,167,48,99,203,244,44,51,134,139,78,161,
    84,86,5,235,244,243,15,19,169,117,26,
};

EmbeddedPython embedded_m5_internal_enum_PageManage(
    "m5/internal/enum_PageManage.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/enum_PageManage.py",
    "m5.internal.enum_PageManage",
    data_m5_internal_enum_PageManage,
    1611,
    4098);

} // anonymous namespace
