#include "sim/init.hh"

namespace {

const uint8_t data_m5_util_dot_writer[] = {
    120,156,181,89,77,108,36,71,21,126,213,61,63,238,241,248,
    103,215,246,218,206,26,112,246,47,35,17,236,108,146,13,228,
    135,36,187,241,174,16,138,189,75,207,38,222,152,221,12,237,
    233,178,221,227,158,233,217,238,246,174,141,198,185,56,2,34,
    113,227,128,136,132,16,39,78,65,226,146,3,156,194,1,14,
    28,56,112,9,18,71,34,132,144,56,193,13,1,239,123,213,
    61,158,201,230,232,140,61,207,85,175,170,94,87,191,247,189,
    159,42,55,41,251,216,252,125,117,145,40,249,39,55,124,254,
    85,20,18,109,244,219,138,54,84,222,182,104,195,146,182,69,
    161,77,237,2,109,20,168,93,164,141,34,41,112,109,10,75,
    212,46,211,70,217,244,11,20,142,80,219,161,13,135,212,193,
    100,46,164,66,27,21,90,239,140,145,82,74,143,162,211,81,
    116,199,47,210,187,252,216,42,249,37,105,140,145,95,150,198,
    56,249,35,210,152,32,223,145,6,75,170,144,127,138,252,81,
    116,143,136,222,218,224,78,85,198,78,147,63,38,141,41,98,
    217,254,56,189,203,251,159,38,127,66,152,51,228,79,74,227,
    12,118,82,175,157,230,87,14,254,199,159,181,154,197,205,180,
    132,126,226,70,81,154,158,146,102,61,104,223,220,108,233,102,
    250,38,127,163,184,166,48,171,204,228,86,20,167,174,222,50,
    140,2,147,135,94,220,105,66,72,149,191,69,254,190,6,157,
    126,147,199,83,162,30,111,83,81,60,131,167,30,90,212,113,
    192,105,73,59,181,168,101,67,161,172,61,48,11,120,161,35,
    155,14,109,232,175,103,209,44,107,102,22,35,69,106,149,184,
    87,160,89,44,43,99,118,207,198,12,204,46,208,254,142,172,
    31,161,150,3,17,43,247,214,233,176,40,172,10,181,70,169,
    87,132,254,143,44,58,44,81,175,132,246,174,77,241,67,136,
    224,39,207,242,240,236,97,153,210,49,17,91,198,116,136,29,
    161,94,129,90,227,212,27,193,11,168,251,15,137,127,215,33,
    116,130,226,231,213,254,183,201,180,87,238,173,210,161,147,117,
    122,14,205,31,86,40,157,164,94,69,222,251,162,218,255,50,
    218,43,247,166,232,112,148,88,183,189,81,8,230,221,168,251,
    163,106,253,254,39,194,171,244,121,159,48,62,120,27,138,90,
    167,133,167,4,79,245,26,236,179,38,234,142,217,70,9,212,
    125,119,41,133,13,26,9,232,185,4,154,95,188,219,121,97,
    177,54,197,45,23,0,79,193,107,116,188,182,78,177,32,214,
    41,32,159,236,109,138,160,174,151,238,164,14,102,52,154,161,
    151,36,141,70,58,34,61,44,224,14,32,226,71,105,163,25,
    107,47,213,60,103,47,73,117,44,72,105,116,25,4,137,72,
    217,213,7,73,90,201,121,141,88,111,37,242,148,109,157,202,
    248,90,212,209,233,196,176,168,78,228,107,121,150,231,251,166,
    35,219,104,238,4,161,31,235,142,43,208,154,124,116,77,146,
    86,179,69,252,14,219,177,215,221,169,85,115,88,38,65,123,
    45,151,212,244,194,80,134,69,1,161,183,169,67,225,111,237,
    133,97,67,94,27,43,242,23,194,136,236,93,20,85,200,122,
    233,120,127,65,127,236,120,38,158,132,93,54,229,9,178,113,
    121,235,104,179,85,131,230,133,36,175,50,89,222,137,218,122,
    121,87,183,219,58,214,79,47,111,235,246,21,33,95,73,82,
    111,51,212,203,73,220,92,238,30,164,59,81,103,153,71,246,
    210,32,92,198,91,63,140,3,222,219,82,247,192,157,97,33,
    215,33,77,100,170,170,114,44,71,157,181,22,236,211,246,25,
    53,195,253,113,117,90,77,219,142,154,84,99,220,27,83,211,
    214,180,37,254,56,202,223,114,238,143,79,241,118,247,127,43,
    56,21,7,20,71,249,21,252,16,44,113,197,158,149,59,138,
    45,206,97,28,101,18,48,98,255,99,7,246,205,228,114,238,
    168,5,64,148,153,179,112,86,118,57,182,41,124,168,152,187,
    102,137,88,101,44,137,241,193,82,227,31,83,58,42,19,148,
    204,177,233,168,192,136,255,136,246,159,64,167,85,229,13,205,
    19,92,113,112,86,217,204,250,57,173,223,159,36,254,21,23,
    28,163,248,201,220,5,199,140,11,142,100,29,246,215,121,246,
    71,54,31,59,35,92,112,78,92,208,49,46,200,190,57,33,
    238,166,140,187,253,151,197,126,44,60,167,207,251,88,92,80,
    188,14,38,93,203,156,205,133,165,107,64,165,59,6,2,124,
    184,0,182,43,60,68,77,23,218,118,1,108,23,80,113,225,
    65,226,27,65,18,116,216,222,157,166,118,37,218,86,51,108,
    3,202,218,223,54,206,160,67,221,214,157,52,113,167,177,246,
    179,124,0,83,147,26,204,234,206,130,204,129,44,128,124,1,
    228,49,144,47,130,124,9,139,33,161,235,46,162,255,56,200,
    185,28,151,39,8,206,75,112,18,72,59,39,224,52,128,60,
    11,72,90,19,234,140,53,169,190,56,4,204,102,33,75,17,
    253,52,241,54,73,44,111,73,130,220,101,144,108,96,227,140,
    199,44,47,216,0,38,167,6,206,1,71,146,87,103,51,22,
    39,132,12,130,10,136,76,37,250,51,238,76,32,69,220,204,
    141,88,148,208,137,176,181,122,181,126,251,186,59,104,79,81,
    210,82,173,146,231,178,56,10,245,177,21,77,48,208,89,208,
    227,8,195,238,45,150,149,1,9,9,121,20,19,43,66,98,
    247,128,53,36,227,215,153,37,15,31,48,22,172,35,107,32,
    245,86,30,102,208,57,14,51,39,109,163,11,44,228,29,72,
    27,17,27,77,176,45,206,171,166,157,5,135,233,220,18,127,
    68,208,38,248,254,254,86,150,185,91,98,137,35,73,225,43,
    247,110,138,182,41,51,136,73,78,200,179,197,60,82,44,136,
    185,74,146,161,101,148,77,58,107,22,112,127,158,19,52,139,
    154,149,108,186,64,252,187,206,54,110,73,128,128,164,18,92,
    5,233,90,193,240,108,105,95,226,8,23,69,92,14,245,144,
    255,203,252,29,65,41,132,34,104,20,117,15,59,146,41,48,
    184,244,225,138,135,107,29,174,114,76,125,116,164,28,83,229,
    172,73,102,188,116,254,185,203,47,102,173,203,79,189,40,166,
    74,118,188,174,150,84,176,26,235,102,20,251,238,124,158,77,
    210,40,10,211,160,107,82,171,153,156,30,132,58,129,151,159,
    139,163,189,142,175,253,39,23,183,130,48,212,190,25,111,70,
    97,20,39,88,123,254,41,249,152,140,195,51,100,68,140,190,
    21,117,82,65,13,22,92,141,3,47,236,179,147,224,187,38,
    73,95,126,214,44,100,158,44,172,33,216,24,252,177,20,237,
    203,246,56,137,197,94,59,145,24,100,24,15,188,112,79,39,
    199,161,72,86,120,221,174,238,152,196,148,164,177,76,12,58,
    65,3,109,0,180,21,5,29,119,57,23,241,90,150,14,199,
    179,152,179,173,59,13,236,96,47,174,149,251,32,150,16,35,
    90,26,61,22,22,116,182,19,131,125,236,74,90,178,29,247,
    202,231,16,113,16,58,223,133,52,192,154,172,146,90,224,244,
    87,181,166,212,130,53,193,61,243,51,46,180,42,84,144,142,
    239,233,28,233,55,72,74,83,70,119,79,101,105,205,55,217,
    79,64,103,16,199,72,75,37,221,177,250,56,160,12,162,206,
    151,10,253,72,141,212,107,80,214,154,251,12,180,242,108,174,
    26,247,57,108,239,51,145,226,126,21,67,3,32,113,191,134,
    5,207,131,188,0,242,34,200,75,32,95,135,218,96,37,99,
    33,83,74,249,218,189,145,247,110,199,123,90,18,212,167,44,
    115,210,10,135,218,126,10,105,211,18,62,74,3,63,19,66,
    5,195,216,219,237,131,174,110,82,246,129,231,92,131,182,159,
    228,134,166,236,40,133,67,20,31,75,164,236,231,19,20,171,
    157,79,80,172,246,141,18,52,207,167,39,215,148,186,1,68,
    4,144,17,192,41,2,188,103,128,183,14,36,11,75,138,5,
    2,77,229,217,104,71,254,94,136,154,21,243,234,111,213,229,
    239,107,183,222,16,69,221,185,118,213,21,198,234,245,85,249,
    187,114,253,77,1,233,205,219,223,184,238,30,171,235,4,117,
    246,58,11,249,0,210,128,214,65,141,53,85,166,26,59,7,
    227,71,148,159,147,76,222,107,9,220,56,150,166,146,244,234,
    172,46,246,101,51,198,129,110,183,68,241,234,240,130,178,44,
    88,149,5,35,188,192,122,100,193,59,195,11,28,89,240,142,
    44,168,80,125,104,108,84,198,222,151,177,234,167,198,198,100,
    236,67,25,27,231,177,2,142,60,245,227,66,73,194,200,53,
    47,209,208,60,130,216,173,32,90,209,15,130,166,54,101,211,
    121,188,42,204,217,190,34,83,35,57,95,38,18,170,234,124,
    138,208,109,81,156,187,70,226,117,28,134,130,216,189,13,206,
    77,144,55,64,112,174,17,192,225,57,119,174,121,177,123,11,
    28,248,225,213,77,142,69,94,51,93,213,237,40,62,112,191,
    133,233,117,216,85,229,78,114,194,102,78,17,154,57,237,203,
    113,160,145,50,250,63,132,232,199,4,254,51,170,108,207,128,
    170,156,202,215,122,20,1,15,200,40,89,34,18,74,160,41,
    242,167,168,158,177,44,97,93,34,127,186,207,178,133,245,60,
    249,51,125,86,65,88,175,147,127,166,207,42,10,171,65,254,
    108,159,85,18,86,76,254,92,102,54,196,139,181,224,175,240,
    171,191,129,252,3,228,55,32,191,3,249,51,72,4,114,0,
    242,67,16,20,108,193,91,32,119,64,126,15,242,11,144,31,
    129,252,26,4,90,8,126,9,85,139,219,14,139,55,188,225,
    103,24,222,240,131,12,111,248,105,134,55,252,72,195,251,212,
    115,37,97,245,177,100,224,3,156,24,80,184,67,200,16,52,
    117,178,240,117,210,8,153,200,16,2,112,100,217,244,15,16,
    62,39,24,153,80,133,71,191,230,236,6,247,65,140,178,129,
    144,226,224,93,74,118,98,227,147,205,19,199,101,26,248,54,
    110,87,204,165,202,161,164,179,158,1,202,7,8,185,239,229,
    51,113,95,178,140,122,44,238,201,114,41,212,178,153,61,250,
    129,220,112,205,190,39,3,102,246,253,53,90,103,87,207,170,
    180,34,78,131,223,231,250,68,170,180,239,201,105,143,163,194,
    93,57,237,241,217,141,207,97,157,179,136,16,61,235,184,62,
    28,28,229,148,27,255,27,66,56,234,115,30,231,194,14,119,
    46,35,180,101,63,34,71,170,152,254,4,174,246,179,90,254,
    56,57,244,157,9,252,41,168,106,190,239,76,252,210,230,109,
    206,206,249,34,123,186,46,249,116,77,86,110,147,124,22,94,
    221,126,70,62,127,122,197,128,1,104,106,123,251,166,3,146,
    53,241,0,95,119,211,157,19,4,7,128,247,82,232,181,55,
    125,239,229,127,65,42,13,190,18,80,80,95,204,202,118,126,
    25,126,43,126,3,112,215,182,223,255,9,62,127,127,197,192,
    85,226,219,119,78,62,190,185,155,44,228,63,249,198,140,83,
    221,165,188,226,228,98,143,79,171,198,203,224,76,238,219,199,
    250,235,246,111,124,226,237,205,70,26,53,118,210,118,88,147,
    51,49,226,112,118,219,40,231,31,39,243,62,113,17,169,42,
    141,96,211,47,245,251,50,36,19,141,27,137,113,12,221,22,
    186,57,160,12,239,196,84,128,114,235,47,148,31,112,11,85,
    229,240,209,214,41,86,185,212,116,172,179,170,130,163,173,125,
    193,170,170,137,66,73,61,97,245,139,77,32,77,162,251,169,
    190,245,112,161,97,1,231,103,50,51,38,200,31,231,47,46,
    61,189,159,127,205,43,72,81,183,11,18,130,180,63,7,203,
    106,50,40,147,179,48,153,26,121,232,92,254,51,18,39,74,
    42,114,134,54,185,169,95,42,251,184,170,181,56,200,152,10,
    185,39,238,165,82,123,176,83,200,174,109,205,91,227,82,73,
    98,72,43,63,27,170,131,75,210,151,123,86,92,244,130,7,
    134,35,140,146,97,172,119,166,113,89,206,101,158,95,206,239,
    72,229,206,28,217,75,234,78,169,0,229,178,207,32,6,216,
    244,3,115,251,135,118,236,117,118,19,221,77,240,134,151,151,
    158,73,96,152,165,228,193,182,105,116,253,173,228,34,55,182,
    188,128,235,243,197,52,90,228,99,143,142,189,84,47,178,194,
    22,163,189,180,187,151,46,110,197,81,123,241,98,118,243,178,
    156,195,124,37,74,229,114,78,46,65,164,174,137,18,115,239,
    179,146,71,12,81,184,64,92,90,13,126,238,64,143,31,238,
    66,144,185,36,40,228,142,193,15,229,194,71,240,206,123,184,
    193,27,195,153,81,238,15,250,23,71,91,25,247,164,243,85,
    73,228,55,152,105,171,126,154,42,169,66,113,142,129,62,198,
    5,204,152,178,237,83,252,215,86,230,209,114,246,120,19,36,
    166,236,2,76,54,217,190,178,212,255,15,130,220,69,155,11,
    45,199,12,101,199,87,43,15,38,204,194,102,68,27,70,193,
    80,201,13,47,76,244,177,138,229,34,67,206,127,114,38,49,
    145,231,110,30,121,196,83,5,215,238,193,144,195,156,116,192,
    54,103,141,151,113,82,147,51,232,5,117,70,77,242,143,45,
    223,138,237,60,238,204,57,37,103,222,153,156,114,156,25,231,
    84,245,130,99,255,31,107,69,45,165,
};

EmbeddedPython embedded_m5_util_dot_writer(
    "m5/util/dot_writer.py",
    "/home/kemmere2/gem5/gem5-stable/src/python/m5/util/dot_writer.py",
    "m5.util.dot_writer",
    data_m5_util_dot_writer,
    2938,
    6771);

} // anonymous namespace
