#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_FuncUnitConfig[] = {
    120,156,197,87,223,111,27,69,16,158,179,207,231,223,137,235,
    164,110,42,164,138,71,83,149,24,90,130,120,168,0,147,31,
    40,208,208,234,156,180,194,15,88,142,119,237,94,123,103,27,
    223,218,130,231,240,119,3,51,115,183,235,61,19,161,10,210,
    38,142,87,223,126,94,207,206,124,55,59,179,30,65,250,151,
    199,247,183,31,3,196,127,34,16,248,239,64,8,16,57,208,
    119,192,161,121,14,194,28,68,121,232,231,147,121,30,66,23,
    206,83,84,64,228,130,244,96,236,128,40,192,31,0,87,0,
    63,247,139,32,60,205,22,13,91,2,81,210,108,217,176,101,
    16,21,205,86,13,91,1,81,211,108,221,176,85,16,91,154,
    221,54,108,13,68,67,179,119,12,91,7,209,212,236,142,97,
    183,64,236,106,246,174,97,183,65,180,160,215,190,135,18,4,
    127,225,95,219,65,164,202,56,244,130,232,249,229,27,57,82,
    9,85,194,225,114,25,132,226,120,186,74,24,26,30,42,15,
    199,211,169,234,62,187,24,217,194,126,71,194,226,27,36,144,
    158,50,151,42,124,5,206,196,33,69,81,221,190,11,126,175,
    77,171,85,17,135,217,252,48,28,198,177,177,24,46,3,130,
    237,130,222,126,48,152,14,35,57,24,168,10,79,162,153,88,
    134,52,165,85,207,231,71,50,30,49,156,205,159,5,177,82,
    244,181,209,108,57,85,109,242,105,61,196,79,113,232,188,158,
    69,178,243,86,70,145,92,200,199,157,137,140,14,120,248,52,
    86,195,203,80,118,226,197,168,51,154,47,59,179,39,157,147,
    229,116,116,49,13,212,225,108,58,14,38,251,243,223,125,242,
    120,159,44,185,56,120,78,211,97,135,208,229,179,101,168,142,
    130,149,17,162,164,133,248,229,159,66,96,252,152,70,87,144,
    75,25,151,153,2,167,15,241,249,9,11,36,11,148,71,247,
    49,125,222,122,176,120,73,233,35,93,26,239,15,60,152,2,
    101,16,230,28,202,88,197,45,124,87,107,153,58,195,34,160,
    30,67,21,176,204,169,180,232,99,176,171,159,243,60,152,203,
    48,152,74,193,81,156,119,253,239,143,207,7,167,189,174,162,
    111,252,246,213,151,1,61,231,32,71,242,81,60,62,217,240,
    105,15,159,166,188,195,201,48,140,165,79,198,124,90,236,215,
    105,168,100,84,191,33,233,41,202,199,100,169,146,74,255,192,
    107,56,141,28,7,118,242,98,96,103,97,81,139,255,195,187,
    138,111,51,133,53,51,225,10,128,207,37,201,215,162,17,154,
    226,63,9,103,67,213,21,130,99,102,149,214,244,97,52,183,
    38,43,21,184,58,157,55,68,76,164,123,47,130,237,160,129,
    111,200,82,41,21,172,233,236,37,249,138,114,109,230,107,89,
    75,246,242,63,228,107,202,23,153,47,89,121,156,39,225,48,
    99,251,5,146,175,98,228,43,107,105,200,141,68,191,172,172,
    148,166,53,90,190,157,89,222,251,117,161,130,61,147,148,222,
    53,122,54,223,175,168,84,45,143,109,81,247,156,7,78,82,
    52,79,207,142,6,180,216,104,218,210,154,186,206,117,197,48,
    197,57,11,231,45,236,90,184,96,97,207,194,69,11,151,44,
    92,182,112,197,194,85,11,215,44,92,183,240,150,133,183,45,
    220,176,240,29,11,55,45,188,99,225,93,46,248,187,124,128,
    238,166,7,168,149,169,84,216,102,4,158,31,78,201,20,119,
    71,163,245,71,225,210,96,58,79,6,175,20,39,10,225,179,
    0,43,191,153,80,217,171,90,19,178,150,246,51,209,123,29,
    140,149,170,217,51,250,88,127,151,50,203,124,170,79,246,6,
    129,254,100,8,114,42,75,172,54,108,96,26,171,186,77,176,
    191,89,134,156,110,108,50,228,90,102,25,103,254,45,20,145,
    143,208,192,143,100,233,33,231,123,237,157,94,216,22,217,45,
    57,20,47,102,11,245,63,110,7,235,100,57,147,17,217,11,
    224,195,107,240,25,26,184,4,187,233,211,94,175,22,129,146,
    55,18,94,41,9,143,13,222,70,124,212,85,199,153,248,120,
    67,241,106,145,9,207,213,225,61,186,54,60,187,156,209,5,
    38,79,229,44,9,213,213,161,250,159,211,240,4,210,122,255,
    129,227,252,2,13,188,89,199,137,117,155,239,75,243,108,152,
    197,127,9,51,233,132,116,249,79,250,155,195,253,173,144,246,
    55,207,60,209,114,98,23,79,177,140,227,164,191,241,227,166,
    110,198,151,170,219,104,93,7,104,96,106,135,255,83,155,234,
    14,87,172,232,96,223,92,250,125,218,142,139,50,178,66,142,
    241,130,24,251,230,183,1,114,243,225,98,24,197,73,179,78,
    119,73,110,97,23,116,17,231,59,50,223,214,248,6,194,29,
    147,203,8,159,35,78,54,126,18,236,207,77,7,201,78,61,
    77,126,30,124,253,9,89,164,219,2,222,19,157,138,83,201,
    181,220,86,189,229,225,235,30,34,124,253,13,249,125,156,201,
};

EmbeddedPython embedded_m5_objects_FuncUnitConfig(
    "m5/objects/FuncUnitConfig.py",
    "/home/kemmere2/gem5/gem5-stable/src/cpu/o3/FuncUnitConfig.py",
    "m5.objects.FuncUnitConfig",
    data_m5_objects_FuncUnitConfig,
    1088,
    3600);

} // anonymous namespace
