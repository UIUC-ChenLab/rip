#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_enum_IdeID[] = {
    120,156,189,87,109,115,219,68,16,222,147,100,39,118,236,198,
    105,218,164,165,161,53,48,5,195,64,12,229,165,12,237,116,
    120,105,153,105,63,4,144,97,154,186,29,132,99,93,18,57,
    182,228,145,46,105,205,56,95,72,7,248,3,252,4,62,240,
    111,248,71,176,207,74,178,157,182,204,240,1,147,137,54,167,
    189,213,222,238,115,207,237,94,186,148,253,20,248,249,180,78,
    148,188,169,136,124,254,85,212,39,26,40,106,43,82,90,145,
    95,163,131,2,197,31,144,95,160,167,68,109,139,180,69,39,
    60,176,233,161,69,97,69,190,41,82,223,22,141,162,81,153,
    180,67,237,2,221,15,87,200,209,69,58,40,83,252,3,41,
    165,66,69,219,254,2,249,139,244,148,189,243,160,36,14,23,
    9,202,178,40,75,228,47,137,178,76,126,69,6,75,52,170,
    145,174,80,187,10,179,246,25,118,251,22,187,93,22,183,127,
    194,173,207,51,43,228,159,129,57,199,245,0,150,14,44,101,
    189,101,241,194,46,108,234,173,64,158,32,45,126,57,75,237,
    179,162,93,157,213,158,163,246,57,209,158,159,213,174,81,123,
    77,180,235,212,94,71,182,173,198,89,134,45,248,139,127,26,
    12,27,153,10,139,35,29,39,65,20,122,65,184,27,5,22,
    230,139,16,0,185,11,177,144,161,253,5,208,254,131,4,106,
    223,202,208,62,38,82,120,39,234,91,116,44,131,99,139,70,
    13,26,43,234,57,228,219,52,230,101,10,8,105,79,209,137,
    69,143,108,24,28,179,116,24,147,203,228,152,20,234,158,96,
    146,122,90,160,227,2,141,11,212,218,30,91,80,28,148,40,
    254,157,126,220,16,167,139,226,212,162,49,75,135,78,28,58,
    46,210,125,54,98,85,175,4,36,213,246,152,51,101,77,171,
    225,112,180,91,51,233,34,21,63,136,195,206,64,155,37,30,
    123,58,60,28,120,119,125,125,247,118,163,156,27,68,201,230,
    176,99,246,93,249,194,6,20,131,161,17,79,81,152,126,182,
    27,132,190,55,136,252,195,190,54,139,112,227,237,6,125,237,
    121,50,121,119,48,140,98,115,39,142,163,216,5,154,162,236,
    71,157,201,23,192,178,219,143,18,221,192,106,178,140,11,247,
    6,214,187,67,241,136,0,38,81,250,58,233,198,193,208,240,
    38,165,30,97,13,111,13,108,143,136,228,30,139,230,126,52,
    208,205,3,61,24,232,88,95,107,238,233,193,135,34,222,73,
    76,103,167,175,155,59,135,65,223,111,110,127,252,81,115,56,
    50,251,81,216,228,249,32,52,154,241,232,55,167,72,108,242,
    44,104,146,60,14,246,188,64,178,241,246,117,127,168,227,42,
    180,47,97,61,85,83,21,85,84,182,106,168,42,143,10,252,
    216,106,195,90,82,91,1,242,233,34,71,176,200,153,229,13,
    54,83,209,129,69,241,6,88,209,227,95,133,109,100,110,180,
    48,103,201,220,55,0,34,213,246,108,236,117,170,28,11,147,
    152,82,108,121,19,155,27,146,208,161,64,189,34,165,52,97,
    118,165,188,137,71,144,108,14,55,22,59,119,40,249,141,24,
    88,38,200,152,50,242,156,216,164,194,26,153,50,142,29,107,
    215,120,193,159,132,127,173,6,194,223,18,50,152,253,32,137,
    30,135,2,57,198,114,98,90,140,204,215,163,175,118,122,186,
    107,146,43,172,120,16,29,214,187,157,48,140,76,189,227,251,
    245,142,49,113,176,115,104,116,82,55,81,253,106,210,192,46,
    186,43,57,159,38,254,70,195,156,63,216,107,230,79,250,226,
    7,93,195,47,171,242,34,187,144,104,195,92,216,143,252,132,
    245,112,177,167,141,139,32,13,64,142,36,144,148,208,48,197,
    242,108,119,134,223,63,203,35,17,62,54,138,57,123,18,221,
    223,53,101,33,98,39,73,60,137,4,122,225,28,28,31,117,
    250,135,90,188,51,121,12,7,132,97,26,195,252,88,119,1,
    25,228,9,75,22,97,20,250,35,14,42,232,190,129,245,46,
    8,247,42,194,190,243,204,188,5,150,69,254,91,84,107,86,
    215,201,248,86,204,57,183,134,108,73,118,92,101,155,206,252,
    59,225,186,210,176,164,48,72,34,114,254,94,197,8,31,187,
    27,16,47,67,92,134,184,146,231,58,151,132,171,207,38,124,
    29,139,88,146,165,228,131,173,176,243,124,252,83,103,232,226,
    244,12,113,209,107,225,44,88,56,49,211,179,224,160,64,198,
    183,32,217,84,78,153,77,201,183,40,199,56,51,226,12,199,
    131,137,142,209,148,254,130,142,91,67,214,139,57,115,93,208,
    113,150,147,123,51,156,116,177,49,66,72,247,98,94,242,60,
    88,164,84,116,47,193,85,225,5,240,214,33,94,153,43,198,
    83,82,237,61,71,170,27,88,175,150,145,170,42,100,42,243,
    83,179,186,118,6,252,164,241,173,62,67,38,48,201,121,1,
    147,94,199,200,126,62,213,255,131,68,89,130,95,206,144,8,
    49,89,179,121,108,241,96,180,142,240,103,233,179,206,173,251,
    126,184,206,221,216,146,110,252,174,116,99,233,232,114,29,73,
    139,175,45,245,55,29,20,128,195,174,77,107,89,151,77,74,
    44,135,113,244,100,84,143,118,235,70,18,69,173,188,121,53,
    217,188,154,220,224,42,88,191,37,245,39,173,131,105,165,139,
    245,16,149,10,159,222,121,210,213,210,226,228,205,243,210,194,
    228,73,145,242,178,214,201,76,58,15,20,173,28,94,41,209,
    137,137,81,153,231,7,112,121,2,48,226,133,243,164,44,232,
    218,106,157,89,83,86,18,134,151,150,97,185,50,201,44,63,
    159,3,113,164,170,9,247,82,183,149,6,41,241,35,19,247,
    237,83,204,152,71,244,110,147,221,125,151,51,162,56,101,4,
    30,59,103,246,47,124,243,80,32,197,207,132,61,231,173,205,
    152,61,57,8,216,228,85,152,127,79,114,4,94,208,201,165,
    134,180,208,189,197,130,75,75,114,93,76,211,198,126,143,126,
    157,57,63,121,251,181,179,59,226,108,251,117,38,245,71,200,
    242,175,90,172,115,186,80,97,71,246,59,9,204,210,234,51,
    61,146,211,186,62,185,225,113,245,157,11,115,22,83,223,30,
    194,120,52,229,13,26,216,37,181,106,205,176,225,61,136,107,
    19,34,168,92,247,95,71,116,133,254,185,197,122,105,61,127,
    136,101,29,9,116,121,65,112,123,230,191,130,52,196,11,19,
    240,70,137,11,141,187,12,97,229,167,155,107,1,95,25,205,
    72,238,33,233,146,19,21,142,248,22,95,53,210,91,50,154,
    175,251,26,101,197,211,69,167,119,55,41,235,37,194,223,180,
    38,132,250,177,84,5,217,80,247,125,202,250,209,160,147,112,
    170,178,66,55,10,25,146,208,164,183,21,209,167,87,217,126,
    231,72,159,182,40,228,106,131,107,194,86,142,209,105,163,210,
    236,148,92,144,186,71,157,120,190,7,86,192,187,153,22,188,
    91,104,164,201,39,44,112,227,41,45,151,84,209,194,77,219,
    230,162,83,85,142,93,169,149,156,202,82,201,41,45,216,210,
    186,170,76,170,178,83,170,84,85,201,202,159,191,1,201,216,
    49,137,
};

EmbeddedPython embedded_m5_internal_enum_IdeID(
    "m5/internal/enum_IdeID.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/python/m5/internal/enum_IdeID.py",
    "m5.internal.enum_IdeID",
    data_m5_internal_enum_IdeID,
    1570,
    3890);

} // anonymous namespace
