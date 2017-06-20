#include "sim/init.hh"

namespace {

const uint8_t data_m5_objects_Network[] = {
    120,156,181,84,75,111,211,64,16,30,187,109,218,164,41,9,
    225,81,104,17,178,56,69,72,212,18,82,111,8,80,11,7,
    36,40,85,82,144,200,197,114,236,73,226,198,235,141,118,55,
    37,225,90,254,20,191,14,102,198,113,83,14,28,177,227,201,
    124,51,147,217,111,30,78,2,171,107,131,158,183,1,128,125,
    71,74,74,31,15,114,128,11,214,124,200,61,80,30,12,60,
    240,24,111,64,238,131,242,97,224,19,222,4,244,96,228,65,
    186,5,63,1,174,1,190,13,54,32,173,65,191,187,77,137,
    178,223,116,117,61,210,28,139,231,165,186,71,226,52,215,201,
    20,211,207,195,75,76,92,105,174,147,56,137,109,150,124,204,
    138,169,219,37,212,155,15,151,103,232,190,107,51,77,110,19,
    61,97,162,191,72,65,96,86,68,138,184,16,99,62,154,120,
    17,167,45,24,212,0,183,225,114,135,249,18,203,107,178,215,
    197,210,96,174,196,144,45,187,149,101,187,178,52,197,178,39,
    144,18,222,1,108,193,101,27,210,29,129,119,5,118,32,173,
    11,188,39,240,62,164,13,129,15,4,62,132,116,87,224,62,
    224,35,72,155,162,63,6,60,128,116,79,244,67,232,245,187,
    119,184,60,174,197,113,159,86,69,218,67,210,21,170,208,80,
    225,97,81,26,195,149,243,104,50,177,220,185,51,237,130,254,
    12,147,108,148,97,106,187,156,98,130,65,17,43,12,244,40,
    96,61,83,51,109,28,166,129,211,51,157,235,241,50,80,58,
    157,231,152,53,56,152,155,152,237,144,176,173,245,201,129,209,
    115,135,198,218,206,45,219,135,130,76,163,56,65,107,247,201,
    204,99,177,148,51,192,5,217,139,56,15,10,157,146,239,201,
    141,111,72,63,68,44,130,172,248,43,128,107,61,61,255,18,
    216,60,190,194,128,185,201,209,108,82,177,165,80,177,117,57,
    143,99,98,81,196,213,68,145,107,8,40,201,19,220,228,128,
    229,12,101,83,146,197,34,74,242,216,90,137,98,52,193,56,
    69,35,81,23,102,142,146,42,30,90,103,226,196,185,45,2,
    231,177,137,149,171,145,214,119,38,43,198,18,81,245,200,241,
    48,168,98,119,64,223,197,92,13,209,68,122,20,93,101,198,
    205,227,60,90,13,195,186,54,159,166,11,103,116,30,41,59,
    142,108,246,3,133,2,47,107,127,73,229,40,217,93,30,97,
    100,215,248,43,237,185,54,37,133,221,106,211,123,210,117,89,
    129,213,0,122,242,42,48,71,58,49,27,89,215,172,98,223,
    47,156,188,24,92,60,77,32,202,185,229,107,55,81,191,113,
    83,255,87,238,214,205,201,125,110,254,57,245,89,90,33,163,
    144,90,74,239,39,153,131,184,249,236,114,44,188,91,176,22,
    246,13,137,112,162,21,134,83,84,10,13,190,12,199,168,142,
    69,188,176,46,30,230,24,90,147,132,255,220,224,217,82,86,
    254,25,39,123,74,162,230,85,119,221,171,251,29,175,227,181,
    252,150,39,183,223,244,206,186,155,213,223,130,58,62,154,113,
    231,202,246,244,252,234,229,249,15,12,101,41,94,149,59,247,
    154,73,90,110,72,195,107,123,109,255,15,118,238,68,140,
};

EmbeddedPython embedded_m5_objects_Network(
    "m5/objects/Network.py",
    "/home/kemmere2/gem5/gem5-stable/src/mem/ruby/network/Network.py",
    "m5.objects.Network",
    data_m5_objects_Network,
    703,
    1326);

} // anonymous namespace
