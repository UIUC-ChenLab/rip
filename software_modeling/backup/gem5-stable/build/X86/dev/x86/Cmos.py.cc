#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_Cmos[] = {
    120,156,173,82,77,111,219,48,12,165,226,216,77,130,98,235,
    31,40,96,12,24,234,21,88,220,102,104,81,20,67,209,143,
    93,118,9,10,59,135,205,23,67,179,217,198,155,101,27,146,
    220,37,231,238,127,111,164,156,98,251,1,147,100,226,241,137,
    38,159,40,21,176,27,30,125,215,33,128,89,18,40,105,9,
    168,1,86,59,36,6,52,130,122,4,202,131,204,3,193,190,
    7,245,24,148,15,153,79,254,24,208,131,7,1,165,15,191,
    0,158,1,190,102,1,148,1,164,209,30,165,172,126,211,136,
    4,33,203,230,120,128,175,200,220,74,83,21,247,85,251,9,
    159,170,2,7,254,53,153,47,23,231,159,27,155,182,189,46,
    240,190,106,236,152,184,59,213,154,226,95,201,183,44,249,134,
    0,2,100,130,133,103,35,86,76,10,73,109,70,154,124,248,
    30,176,82,210,247,76,204,158,99,38,128,19,150,72,90,153,
    156,66,146,70,1,101,73,56,167,217,223,85,79,111,46,47,
    185,162,97,57,37,62,197,155,139,243,184,32,98,190,94,155,
    25,113,39,167,49,173,197,201,233,194,28,147,155,110,141,69,
    21,218,74,97,104,219,176,55,24,70,71,203,246,231,81,248,
    208,234,80,22,182,151,181,219,125,103,222,82,56,29,138,195,
    76,245,216,16,159,172,238,66,89,75,173,66,58,43,106,221,
    119,214,208,118,196,117,236,132,76,158,55,82,97,158,219,153,
    115,84,91,246,53,187,220,23,187,237,208,78,9,20,155,77,
    94,212,210,24,23,197,222,26,101,137,218,250,92,80,106,169,
    92,252,138,68,12,63,18,72,70,12,220,37,53,54,239,170,
    38,226,238,254,53,230,3,153,120,221,42,140,127,160,82,168,
    113,17,63,162,58,115,230,189,177,242,91,141,177,209,69,252,
    210,34,238,217,188,219,186,102,190,225,4,124,205,129,24,230,
    148,230,190,88,186,71,225,36,171,179,121,199,194,140,59,37,
    123,186,221,108,45,95,199,240,36,18,241,18,58,60,9,234,
    155,147,236,242,255,39,173,174,246,199,161,167,87,135,156,136,
    137,153,152,137,3,113,48,250,3,225,87,173,147,
};

EmbeddedPython embedded_m5_objects_Cmos(
    "m5/objects/Cmos.py",
    "/home/kemmere2/gem5/gem5-stable/src/dev/x86/Cmos.py",
    "m5.objects.Cmos",
    data_m5_objects_Cmos,
    477,
    806);

} // anonymous namespace
