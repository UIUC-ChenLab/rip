#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_param_Switch[] = {
    120,156,189,88,91,115,219,198,21,62,11,128,148,72,73,22,
    101,89,146,109,41,22,218,142,27,214,211,72,173,27,215,157,
    137,234,214,185,116,166,153,70,73,193,116,236,40,153,162,16,
    176,34,65,225,194,1,86,146,153,161,94,42,79,219,233,123,
    127,66,31,250,111,250,143,154,115,206,2,32,36,217,153,204,
    52,180,76,172,23,139,221,179,231,242,157,203,174,15,197,95,
    3,159,223,218,0,249,63,5,64,128,63,1,17,64,44,224,
    64,128,144,2,130,91,112,220,128,236,93,8,26,240,18,224,
    192,0,105,192,5,118,76,248,210,128,100,145,215,52,33,50,
    121,68,192,184,13,210,130,131,6,60,75,86,192,146,77,56,
    110,67,246,23,16,66,36,2,158,7,115,16,204,195,75,164,
    142,157,22,19,156,7,26,108,243,96,11,130,5,30,108,67,
    176,200,157,5,24,119,64,46,194,193,18,77,59,184,129,100,
    31,32,217,101,38,251,95,34,27,224,151,53,8,110,208,116,
    228,235,11,154,105,209,76,222,111,153,169,116,74,46,87,224,
    224,102,217,95,173,245,111,213,250,107,181,254,122,173,191,193,
    125,228,230,38,12,111,195,240,14,12,239,194,17,42,104,165,
    218,121,19,164,9,195,45,56,216,2,137,191,77,184,64,29,
    6,55,107,43,222,226,21,171,213,138,123,188,98,27,14,182,
    65,226,239,158,94,209,132,94,119,29,237,18,254,15,255,186,
    104,23,80,139,216,156,202,44,15,211,196,13,147,163,52,52,
    232,123,147,26,178,162,79,205,92,97,206,15,200,156,255,1,
    182,101,96,20,230,60,7,36,44,72,150,200,128,115,238,156,
    27,48,238,194,68,192,208,130,192,132,9,110,211,32,6,250,
    2,46,12,248,202,164,9,231,216,90,168,244,123,96,41,109,
    203,33,43,93,83,154,131,243,6,76,26,208,123,62,49,104,
    224,184,5,217,191,225,235,45,38,58,207,68,13,152,96,107,
    193,133,5,231,77,120,134,147,112,104,216,34,241,197,243,9,
    74,138,35,189,174,133,220,238,215,196,37,81,130,48,75,188,
    88,170,37,236,187,35,47,243,98,183,119,22,42,127,208,109,
    151,83,210,124,103,228,169,129,195,107,76,82,70,60,82,76,
    43,77,164,90,192,206,81,152,4,110,156,6,39,145,84,243,
    68,200,61,10,35,233,186,252,241,247,241,40,205,212,71,89,
    150,102,14,233,147,7,163,212,171,86,144,54,253,40,205,101,
    151,118,227,109,28,34,175,104,246,209,136,41,18,3,204,39,
    45,14,100,238,103,225,72,161,153,52,69,154,77,212,186,100,
    32,110,242,63,96,179,59,72,99,185,123,44,227,88,102,242,
    225,110,95,198,143,184,121,39,87,222,97,36,119,15,79,194,
    40,216,125,234,124,178,59,26,171,65,154,236,226,247,48,81,
    18,53,18,237,214,117,177,131,223,111,18,213,179,176,239,134,
    44,143,59,144,209,72,102,164,182,252,46,237,40,58,98,81,
    52,133,41,186,98,9,123,13,124,76,177,101,44,136,253,144,
    36,242,73,74,66,146,85,199,14,25,84,192,177,1,217,22,
    33,99,136,63,65,166,68,124,244,232,155,193,223,254,72,170,
    208,163,67,147,236,173,7,39,140,38,132,21,206,220,35,3,
    39,192,144,104,192,176,9,26,42,136,48,141,157,108,76,45,
    78,39,50,6,18,183,32,255,23,160,106,17,36,19,40,0,
    116,97,130,72,58,160,218,228,219,56,186,142,27,254,149,49,
    216,235,18,251,251,12,7,53,8,243,244,44,97,165,83,159,
    189,6,245,212,255,108,252,233,225,80,250,42,223,198,129,47,
    210,19,219,247,146,36,85,182,23,4,182,167,84,22,30,158,
    40,153,219,42,181,239,231,93,178,163,179,82,34,170,162,55,
    30,149,8,34,107,35,130,244,75,16,250,10,95,86,249,133,
    173,144,75,133,104,24,164,65,142,227,68,162,47,149,67,76,
    42,82,114,202,140,48,88,92,154,74,219,227,188,27,248,254,
    180,228,132,17,217,109,150,248,201,101,116,164,218,12,69,47,
    207,93,230,132,198,25,117,68,248,212,139,78,36,83,71,248,
    40,100,136,186,154,135,89,226,238,54,201,80,138,204,114,36,
    105,18,140,145,173,208,127,155,118,188,205,232,91,100,252,173,
    33,246,230,176,109,226,255,77,177,110,248,86,129,184,102,137,
    58,138,120,10,216,230,162,48,59,34,240,2,163,75,215,224,
    240,192,162,176,15,254,144,122,180,216,217,162,230,45,106,238,
    81,179,93,74,59,35,145,151,174,138,252,152,182,49,88,78,
    150,136,204,97,150,18,5,151,252,232,206,212,143,48,248,245,
    200,31,12,242,154,169,63,88,20,40,179,39,212,226,84,246,
    52,19,242,207,41,44,147,223,48,49,114,17,4,59,245,166,
    46,192,250,113,58,36,247,124,137,94,135,32,89,199,101,191,
    134,75,135,76,195,160,116,238,148,129,207,165,25,26,142,206,
    38,145,106,188,66,193,54,53,63,152,177,150,167,192,234,95,
    3,214,123,180,99,167,0,214,18,3,170,141,79,199,240,205,
    66,245,85,10,92,189,2,40,66,147,245,10,52,253,152,122,
    230,117,97,223,12,144,10,17,127,87,3,18,113,101,212,37,
    217,199,206,120,131,4,168,67,104,3,211,248,179,100,3,51,
    179,193,153,249,103,156,153,57,187,115,237,163,131,176,201,113,
    88,119,26,164,137,35,19,214,139,140,155,183,176,29,101,233,
    139,177,157,30,217,138,69,165,152,185,119,63,223,185,159,191,
    135,209,208,126,194,113,72,199,67,29,241,50,57,162,136,69,
    75,63,122,225,75,78,118,252,230,186,58,64,185,28,172,220,
    34,137,34,154,214,72,143,70,169,96,14,213,185,202,40,66,
    207,82,197,237,74,197,196,241,199,180,71,155,245,107,138,13,
    68,78,91,48,35,174,14,200,92,64,241,87,124,222,39,157,
    147,176,18,168,12,118,122,154,77,150,128,100,113,126,122,9,
    29,179,225,223,217,69,130,127,42,81,209,156,162,130,30,179,
    196,247,223,129,43,74,1,127,3,178,59,154,183,192,119,229,
    14,100,232,85,154,254,103,96,71,120,69,86,231,88,210,163,
    76,206,51,48,196,228,143,121,170,78,242,31,195,63,106,94,
    84,166,98,179,168,25,235,169,216,170,226,16,3,230,59,165,
    91,235,114,192,34,155,12,188,156,166,233,40,52,117,204,105,
    132,175,234,61,140,194,51,66,207,188,166,238,18,35,95,77,
    177,67,201,108,83,172,26,53,68,252,156,154,135,21,24,68,
    57,246,253,243,180,13,175,79,184,174,142,237,95,210,198,22,
    179,186,60,199,117,128,94,94,225,187,81,226,251,97,133,111,
    201,9,232,37,159,23,168,53,200,178,23,134,192,3,29,86,
    91,116,126,178,64,54,224,160,73,158,192,37,177,40,28,69,
    148,1,138,194,217,165,236,198,106,216,215,10,170,140,171,237,
    70,205,139,89,58,62,153,110,47,242,226,195,192,123,18,211,
    14,180,141,95,186,142,81,242,220,169,243,76,176,23,175,99,
    155,95,31,149,188,159,206,210,233,127,137,4,43,158,25,226,
    65,234,179,167,127,62,144,118,44,227,67,60,4,14,194,145,
    125,20,121,125,182,131,89,200,244,105,41,147,98,67,94,173,
    14,242,7,212,166,182,159,38,24,123,79,124,149,102,118,32,
    241,120,36,3,251,29,155,3,183,29,230,182,119,136,95,61,
    95,105,24,95,118,64,46,58,189,172,159,51,174,142,207,168,
    59,107,59,186,120,218,13,177,192,78,161,74,143,250,44,86,
    197,97,46,157,181,87,96,38,195,131,143,26,235,8,68,149,
    130,179,67,205,79,224,13,132,235,119,145,96,68,148,73,57,
    77,177,105,180,140,242,252,129,51,62,163,217,249,117,47,60,
    252,46,94,168,47,84,10,95,108,210,76,57,71,231,107,106,
    91,20,174,233,190,164,81,220,151,208,160,190,47,105,242,200,
    13,242,218,185,255,215,107,25,254,179,6,254,233,247,234,172,
    206,227,55,201,178,243,43,40,82,242,235,28,85,212,229,89,
    210,142,58,20,101,165,95,23,134,111,14,86,175,96,199,245,
    51,233,41,169,173,177,53,91,209,216,193,245,126,227,169,227,
    93,175,75,159,86,82,92,112,249,49,190,197,70,210,199,26,
    54,146,120,150,220,197,2,213,226,2,117,143,10,212,9,139,
    236,26,186,70,157,130,174,81,73,78,182,78,228,153,91,151,
    94,23,160,196,150,55,26,201,36,112,30,64,189,166,228,207,
    179,180,53,5,147,115,168,149,1,166,184,133,69,228,117,159,
    162,24,89,147,138,173,213,168,188,104,198,118,99,72,190,44,
    33,217,93,134,122,160,116,246,168,225,208,88,69,69,231,55,
    149,214,239,94,197,219,105,152,41,55,145,42,167,35,202,183,
    125,198,98,132,235,255,106,132,181,197,0,14,100,36,149,188,
    100,73,54,111,113,36,13,36,102,155,116,140,39,6,46,197,
    241,61,114,221,153,71,234,95,35,193,19,162,76,153,3,35,
    181,104,98,172,94,51,90,205,150,224,100,119,229,110,85,179,
    98,67,89,114,142,115,135,29,126,185,82,29,95,3,150,185,
    135,180,204,234,216,247,98,125,147,195,215,21,206,143,160,56,
    106,58,111,87,38,160,179,55,215,249,250,252,132,160,231,68,
    204,121,215,249,5,141,211,97,52,126,180,83,202,178,163,101,
    121,223,203,67,223,73,177,138,206,248,42,50,126,196,181,225,
    245,137,31,68,169,127,44,3,125,251,245,26,98,60,231,195,
    52,246,112,124,243,149,51,122,97,92,80,88,185,242,61,200,
    104,213,218,149,209,92,102,161,23,133,95,235,11,179,114,152,
    23,95,231,159,174,30,106,239,156,71,107,193,143,129,146,201,
    126,152,211,228,149,203,147,139,216,64,6,85,119,174,2,180,
    190,112,214,152,210,53,167,62,240,62,33,137,242,15,177,161,
    123,175,214,114,11,241,69,241,194,196,35,231,146,176,204,197,
    78,203,90,92,104,89,173,57,147,47,47,150,240,56,209,182,
    90,11,139,98,250,111,27,177,216,54,182,59,45,241,13,150,
    100,146,198,
};

EmbeddedPython embedded_m5_internal_param_Switch(
    "m5/internal/param_Switch.py",
    "/home/kemmere2/gem5/gem5-stable/build/ARM/python/m5/internal/param_Switch.py",
    "m5.internal.param_Switch",
    data_m5_internal_param_Switch,
    2227,
    6569);

} // anonymous namespace
