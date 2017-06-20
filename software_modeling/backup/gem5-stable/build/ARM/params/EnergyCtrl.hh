#ifndef __PARAMS__EnergyCtrl__
#define __PARAMS__EnergyCtrl__

class EnergyCtrl;

#include <cstddef>
#include "params/DVFSHandler.hh"

#include "params/BasicPioDevice.hh"

struct EnergyCtrlParams
    : public BasicPioDeviceParams
{
    EnergyCtrl * create();
    DVFSHandler * dvfs_handler;
};

#endif // __PARAMS__EnergyCtrl__
