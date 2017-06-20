#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_enum_AddrMap[] = {
    120,156,189,87,221,114,219,84,16,222,35,201,78,236,216,141,
    211,180,249,105,67,107,96,10,30,6,98,40,48,189,104,39,
    208,102,202,12,29,26,64,134,105,235,118,16,142,117,18,203,
    177,37,143,164,180,53,227,220,144,14,240,2,60,2,23,188,
    13,111,4,251,173,36,91,105,211,25,46,8,153,104,115,180,
    103,181,103,127,190,221,61,233,82,250,83,224,231,243,58,81,
    244,153,34,114,249,87,209,128,104,168,168,173,72,105,69,110,
    141,14,10,20,126,66,110,129,94,16,181,13,210,6,29,243,
    194,164,199,6,249,21,249,166,72,3,83,56,138,198,101,210,
    22,181,11,244,192,95,34,75,23,233,160,76,225,143,164,148,
    242,21,61,116,231,200,157,167,23,172,157,23,37,81,56,79,
    96,150,133,89,34,119,65,152,101,114,43,178,88,160,113,141,
    116,133,218,85,136,181,207,177,218,247,88,237,162,168,253,11,
    106,93,222,89,34,247,28,196,217,174,71,144,180,32,41,231,
    45,138,22,86,97,82,127,9,244,24,110,241,203,121,106,159,
    23,238,114,158,123,129,218,23,132,123,49,207,93,161,246,138,
    112,87,243,220,53,106,175,9,119,157,218,235,136,65,171,113,
    158,131,233,253,205,63,13,14,38,197,21,38,79,117,24,121,
    129,239,120,254,94,224,25,216,47,130,32,244,93,144,185,52,
    7,219,200,193,159,36,9,112,141,52,7,71,68,10,239,68,
    3,131,142,100,113,100,208,184,65,19,69,125,139,92,147,38,
    124,76,1,38,237,43,58,54,232,137,9,129,35,166,22,71,
    234,10,89,113,146,128,190,68,42,209,52,71,71,5,154,20,
    168,245,112,98,128,113,80,162,240,15,250,105,67,148,206,139,
    82,131,38,76,45,58,182,232,168,72,15,88,136,89,253,18,
    226,171,30,78,216,83,230,180,26,22,91,187,147,115,23,174,
    184,94,232,119,134,58,174,242,218,209,254,225,208,185,237,186,
    225,253,206,168,81,206,68,130,104,115,212,137,123,182,124,99,
    34,24,195,81,44,186,2,95,199,11,188,216,243,124,215,25,
    6,238,225,64,199,243,80,228,236,121,3,237,56,178,249,229,
    112,20,132,241,221,48,12,66,27,241,20,230,32,232,76,191,
    64,52,187,131,32,210,13,156,38,199,216,80,31,67,122,111,
    36,26,97,128,216,137,143,93,29,117,67,111,20,115,154,18,
    141,144,134,182,6,18,36,36,250,138,73,179,23,12,117,243,
    64,15,135,58,212,215,155,251,122,248,169,144,15,162,184,179,
    59,208,205,221,67,111,224,54,111,219,247,155,163,113,220,11,
    252,38,239,123,126,172,57,34,131,102,62,22,155,188,15,168,
    68,207,188,125,199,19,127,156,158,30,140,116,136,176,69,151,
    112,162,170,169,138,42,42,83,53,84,149,87,5,126,76,181,
    97,44,168,29,15,30,117,225,37,144,100,229,177,131,132,42,
    58,48,40,220,0,50,250,252,171,144,74,198,71,11,123,134,
    236,125,139,80,36,220,190,137,124,39,204,137,160,137,97,197,
    146,183,144,96,159,4,18,5,234,23,41,129,10,35,44,193,
    78,56,6,101,113,168,49,88,185,69,209,239,196,161,101,144,
    76,40,5,208,177,73,202,175,81,92,70,65,50,119,133,15,
    252,89,48,216,106,192,252,29,129,67,220,243,162,224,153,47,
    65,199,90,170,166,197,145,249,102,252,245,110,95,119,227,232,
    42,51,30,5,135,245,110,199,247,131,184,222,113,221,122,39,
    142,67,111,247,48,214,81,61,14,234,215,162,6,242,104,47,
    101,136,154,234,27,143,50,4,33,219,140,160,228,197,245,186,
    49,191,44,203,139,100,33,210,49,163,161,23,184,17,243,161,
    98,95,199,54,140,140,17,228,64,12,17,176,56,16,197,241,
    44,119,142,223,111,103,150,8,34,27,197,12,63,145,30,236,
    197,101,129,98,39,138,28,177,4,124,65,29,20,63,237,12,
    14,181,104,103,248,196,108,16,150,137,13,103,137,187,53,248,
    144,185,44,126,248,129,239,142,217,44,175,251,46,78,92,19,
    244,85,4,127,23,25,123,115,76,139,252,183,168,86,140,174,
    149,34,174,152,161,110,5,254,146,228,92,165,105,103,4,30,
    115,119,105,24,210,30,196,21,169,193,183,176,194,199,246,6,
    200,27,32,87,64,174,102,222,158,145,203,213,151,93,190,129,
    99,12,241,83,60,66,58,204,204,35,247,68,29,173,207,234,
    136,155,95,11,245,96,160,106,102,245,96,161,81,134,91,160,
    44,42,149,102,82,244,29,218,50,234,70,148,161,68,24,236,
    88,205,74,64,226,99,215,224,247,124,134,94,27,144,204,227,
    114,63,135,75,27,169,17,80,218,235,89,227,115,32,145,192,
    209,190,12,85,133,83,2,92,7,121,243,140,163,60,3,214,
    254,43,192,186,137,19,107,41,176,170,2,168,50,63,53,163,
    107,166,161,159,142,192,229,151,0,5,52,89,167,160,233,29,
    172,204,87,157,253,127,128,148,186,248,69,14,72,176,202,200,
    123,178,195,139,241,42,28,200,67,104,149,199,248,3,127,149,
    39,179,33,147,249,67,153,204,50,221,229,194,146,52,97,83,
    250,112,178,40,32,18,123,38,173,164,19,55,42,49,29,133,
    193,243,113,61,216,171,199,226,42,122,230,173,107,209,230,181,
    232,38,119,195,250,150,244,161,164,31,38,29,47,212,35,116,
    44,124,122,247,121,87,203,176,147,55,199,73,26,148,35,205,
    202,73,135,40,163,233,34,226,104,100,1,150,86,29,197,33,
    58,244,89,134,184,60,13,49,44,190,135,51,202,18,95,83,
    173,50,114,202,74,12,113,146,134,44,23,40,217,229,231,14,
    98,14,103,53,225,238,106,183,18,51,197,3,248,98,191,127,
    2,29,103,99,191,221,100,133,223,103,168,40,206,80,129,199,
    204,240,253,43,223,67,20,128,241,11,33,239,156,222,20,223,
    211,114,64,162,151,33,254,3,73,33,156,50,213,165,151,180,
    48,201,69,130,91,76,116,67,68,147,33,127,143,126,203,85,
    81,54,138,205,244,206,152,31,197,214,180,15,9,96,254,213,
    184,181,78,54,44,228,164,215,137,32,150,116,161,89,97,206,
    58,252,244,190,199,93,248,140,208,51,159,104,119,96,200,147,
    25,118,48,204,46,171,101,35,135,136,143,64,174,79,193,160,
    50,222,127,111,211,85,122,253,192,117,146,222,254,24,7,91,
    98,234,226,156,196,238,165,255,20,18,35,47,77,3,56,142,
    108,112,236,69,16,35,171,114,238,9,124,133,140,199,114,47,
    73,142,156,178,80,234,59,124,245,72,238,205,24,197,246,219,
    148,182,81,27,115,223,222,164,116,174,8,134,147,222,224,235,
    103,210,29,36,169,246,199,224,175,98,21,216,157,59,157,237,
    222,118,32,167,116,3,159,3,227,199,82,188,179,189,188,104,
    176,221,123,173,40,239,165,162,219,233,183,167,137,102,123,50,
    103,118,102,33,62,41,187,112,114,83,110,92,221,167,157,240,
    172,235,94,226,127,43,233,157,91,48,34,218,98,130,43,84,
    105,177,164,138,6,46,239,38,119,175,170,178,204,74,173,100,
    85,22,74,86,105,206,148,57,88,101,100,150,173,82,165,170,
    74,70,254,249,7,76,207,84,204,
};

EmbeddedPython embedded_m5_internal_enum_AddrMap(
    "m5/internal/enum_AddrMap.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/enum_AddrMap.py",
    "m5.internal.enum_AddrMap",
    data_m5_internal_enum_AddrMap,
    1593,
    4003);

} // anonymous namespace
