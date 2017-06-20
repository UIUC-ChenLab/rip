#include "sim/init.hh"

namespace {

const uint8_t data_m5_internal_stattest[] = {
    120,156,181,87,111,111,219,100,16,191,199,118,210,38,77,214,
    180,101,237,198,202,22,64,131,8,65,3,99,99,72,155,42,
    254,104,72,219,139,2,14,104,93,55,97,210,248,73,235,52,
    177,35,219,221,22,148,190,161,19,240,5,248,8,188,224,219,
    240,141,224,126,247,216,73,186,13,9,164,44,141,175,143,207,
    231,123,238,207,239,185,187,116,40,251,20,248,250,172,78,148,
    88,138,200,231,175,162,62,209,64,209,158,34,165,21,249,171,
    116,84,160,248,58,249,5,122,70,180,103,145,182,232,148,23,
    54,61,180,40,172,200,59,69,234,219,194,81,52,42,147,118,
    104,175,64,247,195,21,114,116,145,142,202,20,255,72,74,169,
    80,209,174,191,64,254,34,61,99,237,188,40,137,194,69,2,
    179,44,204,18,249,75,194,44,147,95,145,197,18,141,106,164,
    43,180,87,133,216,222,57,86,251,30,171,93,22,181,127,65,
    173,207,79,214,200,63,7,113,182,235,1,36,29,72,202,126,
    203,162,165,70,126,77,22,43,164,109,234,173,96,225,175,8,
    103,85,56,171,88,176,27,173,198,107,28,143,224,111,254,52,
    56,30,148,86,152,60,214,113,18,68,161,23,132,221,40,176,
    240,188,8,130,232,117,64,22,178,48,126,137,48,254,73,18,
    67,223,202,194,120,66,164,112,79,212,183,232,68,22,39,22,
    141,26,52,86,212,115,200,183,105,204,219,20,232,84,209,129,
    162,83,139,30,217,16,56,97,234,176,179,151,201,73,77,12,
    123,226,172,209,180,64,39,5,26,23,168,181,59,182,192,56,
    42,81,252,7,253,180,41,74,23,69,169,69,99,166,14,157,
    58,116,82,164,251,44,196,172,94,9,33,82,187,99,246,148,
    57,173,134,195,214,238,204,184,11,87,252,32,14,219,3,157,
    150,120,237,37,105,59,77,117,146,54,202,249,227,40,217,26,
    182,211,67,87,228,109,4,98,48,76,69,79,20,234,116,137,
    23,221,32,244,189,65,228,31,247,117,186,8,37,94,55,232,
    107,207,147,135,119,7,195,40,78,239,196,113,20,187,136,165,
    48,251,81,123,242,6,34,217,233,71,137,110,96,55,217,198,
    133,250,20,210,221,161,104,132,1,98,35,94,246,117,210,137,
    131,97,202,41,50,26,33,13,109,13,36,71,72,178,205,164,
    121,24,13,116,243,72,15,6,58,214,215,154,7,122,112,67,
    200,7,236,227,126,95,55,247,143,131,190,223,220,253,244,147,
    230,113,24,136,211,205,220,251,173,225,40,93,133,158,39,193,
    129,23,136,7,222,161,238,15,117,92,5,247,117,236,161,106,
    170,162,138,202,86,13,85,229,85,129,47,91,109,90,75,106,
    39,128,15,29,248,5,220,56,179,72,65,250,20,29,89,20,
    111,2,7,61,254,42,36,142,209,208,194,51,75,158,125,11,
    231,13,183,103,35,187,134,57,22,236,48,136,88,242,54,210,
    25,146,0,160,64,189,34,25,96,48,158,12,82,226,17,40,
    139,67,141,197,202,29,74,126,39,14,38,67,98,76,25,92,
    78,109,82,97,141,210,50,78,16,115,215,121,195,159,5,113,
    173,6,204,223,17,0,164,135,65,18,61,9,37,204,88,203,
    25,105,113,100,190,25,125,189,223,211,157,52,185,194,140,7,
    209,113,189,211,14,195,40,173,183,125,191,206,113,140,131,253,
    99,14,102,61,141,234,87,147,6,50,231,174,228,24,154,232,
    27,13,115,204,32,191,140,25,115,227,7,157,148,111,214,228,
    70,178,144,232,148,243,127,24,249,9,243,161,226,64,167,46,
    140,76,17,228,72,12,17,120,120,16,197,246,44,119,142,239,
    63,207,45,17,12,54,138,57,98,18,221,239,166,101,1,95,
    59,73,60,177,4,124,193,25,20,63,110,247,143,181,104,7,
    44,216,32,44,141,13,243,69,218,5,57,120,153,147,98,121,
    24,133,254,136,13,9,58,239,98,143,11,130,183,138,32,238,
    60,163,109,129,105,145,255,23,213,186,213,113,50,140,21,115,
    156,173,195,67,146,44,171,44,209,140,185,83,174,30,13,75,
    142,191,24,47,231,236,45,172,240,178,187,9,242,6,200,101,
    144,43,185,127,115,115,178,250,188,147,55,161,216,18,207,196,
    7,132,220,206,125,240,207,156,149,139,211,179,194,229,172,5,
    204,91,56,25,83,204,59,40,125,241,54,40,139,202,105,178,
    41,249,14,133,22,103,67,148,225,24,48,160,177,154,194,92,
    34,226,214,224,233,98,142,80,23,176,155,197,222,193,12,246,
    92,36,67,128,231,94,204,203,153,7,9,3,57,247,18,84,
    21,94,18,210,58,200,155,115,143,235,20,60,7,47,128,231,
    22,246,168,101,224,169,10,104,202,124,213,172,142,157,5,123,
    210,198,214,158,3,13,16,227,188,4,49,239,96,101,191,232,
    222,171,2,75,230,212,87,51,96,129,29,214,172,237,59,188,
    24,109,192,228,89,152,108,112,243,189,31,110,112,63,181,164,
    159,126,40,253,84,122,178,76,10,166,152,218,82,79,205,162,
    0,223,187,54,173,103,125,50,65,71,28,198,209,211,81,61,
    234,214,83,113,14,181,239,246,213,100,235,106,114,139,171,90,
    125,91,234,137,169,107,166,114,197,122,136,202,131,87,239,60,
    237,104,105,83,166,181,122,166,208,120,82,116,188,172,253,49,
    98,206,35,114,86,30,82,41,185,73,26,163,210,206,55,168,
    229,73,80,97,227,61,104,45,75,68,109,181,193,232,40,43,
    217,218,51,165,84,6,29,121,202,215,23,136,50,220,211,132,
    49,209,109,25,195,196,102,88,239,190,127,6,1,243,178,216,
    109,178,138,239,243,204,23,167,153,199,101,231,168,253,149,167,
    4,133,228,255,66,200,45,167,48,67,237,4,228,72,230,26,
    196,127,32,129,247,75,58,176,212,132,22,186,174,72,112,169,
    72,110,138,168,105,200,247,232,183,153,179,145,183,77,59,155,
    230,102,219,166,51,169,39,2,138,255,212,26,157,179,133,7,
    89,56,108,39,16,51,213,100,122,220,166,181,121,50,141,113,
    53,157,27,66,22,141,62,15,91,63,154,226,3,141,231,146,
    90,179,102,178,254,17,200,181,73,194,85,206,155,135,21,87,
    232,223,219,161,103,234,240,67,108,229,136,113,203,11,103,160,
    42,5,161,108,138,89,214,46,196,186,29,99,183,204,139,50,
    195,101,27,242,144,31,164,175,0,186,215,89,197,193,76,209,
    250,191,54,86,102,109,140,143,195,87,96,226,13,86,113,52,
    53,81,96,246,220,207,29,179,225,218,4,107,163,196,5,199,
    93,158,216,41,211,121,28,241,100,156,142,100,220,50,153,155,
    176,80,249,118,120,162,50,63,0,48,111,184,111,83,214,71,
    92,12,55,238,22,101,173,84,142,187,41,149,161,126,34,197,
    82,240,239,126,12,130,128,138,201,243,143,132,56,113,219,212,
    227,109,244,243,4,155,97,216,42,45,151,84,209,194,96,111,
    115,125,172,42,199,174,212,74,78,101,169,228,148,22,108,233,
    166,85,62,23,101,167,84,41,89,248,251,7,84,174,39,180,
};

EmbeddedPython embedded_m5_internal_stattest(
    "m5/internal/stattest.py",
    "/home/kemmere2/gem5/gem5-stable/build/X86/unittest/stattest.py",
    "m5.internal.stattest",
    data_m5_internal_stattest,
    1552,
    3942);

} // anonymous namespace
