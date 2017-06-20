# This file was automatically generated by SWIG (http://www.swig.org).
# Version 3.0.8
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.





from sys import version_info
if version_info >= (2, 6, 0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_param_ArmISA', [dirname(__file__)])
        except ImportError:
            import _param_ArmISA
            return _param_ArmISA
        if fp is not None:
            try:
                _mod = imp.load_module('_param_ArmISA', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _param_ArmISA = swig_import_helper()
    del swig_import_helper
else:
    import _param_ArmISA
del version_info
try:
    _swig_property = property
except NameError:
    pass  # Python < 2.2 doesn't have 'property'.


def _swig_setattr_nondynamic(self, class_type, name, value, static=1):
    if (name == "thisown"):
        return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name, None)
    if method:
        return method(self, value)
    if (not static):
        object.__setattr__(self, name, value)
    else:
        raise AttributeError("You cannot add attributes to %s" % self)


def _swig_setattr(self, class_type, name, value):
    return _swig_setattr_nondynamic(self, class_type, name, value, 0)


def _swig_getattr_nondynamic(self, class_type, name, static=1):
    if (name == "thisown"):
        return self.this.own()
    method = class_type.__swig_getmethods__.get(name, None)
    if method:
        return method(self)
    if (not static):
        return object.__getattr__(self, name)
    else:
        raise AttributeError(name)

def _swig_getattr(self, class_type, name):
    return _swig_getattr_nondynamic(self, class_type, name, 0)


def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object:
        pass
    _newclass = 0



def _swig_setattr_nondynamic_method(set):
    def set_attr(self, name, value):
        if (name == "thisown"):
            return self.this.own(value)
        if hasattr(self, name) or (name == "this"):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add attributes to %s" % self)
    return set_attr


import m5.internal.param_ArmPMU
import m5.internal.param_Platform
import m5.internal.param_IntrControl
import m5.internal.param_System
import m5.internal.enum_MemoryMode
import m5.internal.AddrRange_vector
import m5.internal.AbstractMemory_vector
import m5.internal.param_AbstractMemory
import m5.internal.param_MemObject
import m5.internal.param_ClockedObject
import m5.internal.param_ClockDomain
import m5.internal.param_SimObject
import m5.internal.drain
import m5.internal.serialize
class ArmISA_COLONS_ISA(m5.internal.param_SimObject.SimObject):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
ArmISA_COLONS_ISA_swigregister = _param_ArmISA.ArmISA_COLONS_ISA_swigregister
ArmISA_COLONS_ISA_swigregister(ArmISA_COLONS_ISA)

class ArmISAParams(m5.internal.param_SimObject.SimObjectParams):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr

    def create(self):
        return _param_ArmISA.ArmISAParams_create(self)
    fpsid = _swig_property(_param_ArmISA.ArmISAParams_fpsid_get, _param_ArmISA.ArmISAParams_fpsid_set)
    id_aa64afr0_el1 = _swig_property(_param_ArmISA.ArmISAParams_id_aa64afr0_el1_get, _param_ArmISA.ArmISAParams_id_aa64afr0_el1_set)
    id_aa64afr1_el1 = _swig_property(_param_ArmISA.ArmISAParams_id_aa64afr1_el1_get, _param_ArmISA.ArmISAParams_id_aa64afr1_el1_set)
    id_aa64dfr0_el1 = _swig_property(_param_ArmISA.ArmISAParams_id_aa64dfr0_el1_get, _param_ArmISA.ArmISAParams_id_aa64dfr0_el1_set)
    id_aa64dfr1_el1 = _swig_property(_param_ArmISA.ArmISAParams_id_aa64dfr1_el1_get, _param_ArmISA.ArmISAParams_id_aa64dfr1_el1_set)
    id_aa64isar0_el1 = _swig_property(_param_ArmISA.ArmISAParams_id_aa64isar0_el1_get, _param_ArmISA.ArmISAParams_id_aa64isar0_el1_set)
    id_aa64isar1_el1 = _swig_property(_param_ArmISA.ArmISAParams_id_aa64isar1_el1_get, _param_ArmISA.ArmISAParams_id_aa64isar1_el1_set)
    id_aa64mmfr0_el1 = _swig_property(_param_ArmISA.ArmISAParams_id_aa64mmfr0_el1_get, _param_ArmISA.ArmISAParams_id_aa64mmfr0_el1_set)
    id_aa64mmfr1_el1 = _swig_property(_param_ArmISA.ArmISAParams_id_aa64mmfr1_el1_get, _param_ArmISA.ArmISAParams_id_aa64mmfr1_el1_set)
    id_aa64pfr0_el1 = _swig_property(_param_ArmISA.ArmISAParams_id_aa64pfr0_el1_get, _param_ArmISA.ArmISAParams_id_aa64pfr0_el1_set)
    id_aa64pfr1_el1 = _swig_property(_param_ArmISA.ArmISAParams_id_aa64pfr1_el1_get, _param_ArmISA.ArmISAParams_id_aa64pfr1_el1_set)
    id_isar0 = _swig_property(_param_ArmISA.ArmISAParams_id_isar0_get, _param_ArmISA.ArmISAParams_id_isar0_set)
    id_isar1 = _swig_property(_param_ArmISA.ArmISAParams_id_isar1_get, _param_ArmISA.ArmISAParams_id_isar1_set)
    id_isar2 = _swig_property(_param_ArmISA.ArmISAParams_id_isar2_get, _param_ArmISA.ArmISAParams_id_isar2_set)
    id_isar3 = _swig_property(_param_ArmISA.ArmISAParams_id_isar3_get, _param_ArmISA.ArmISAParams_id_isar3_set)
    id_isar4 = _swig_property(_param_ArmISA.ArmISAParams_id_isar4_get, _param_ArmISA.ArmISAParams_id_isar4_set)
    id_isar5 = _swig_property(_param_ArmISA.ArmISAParams_id_isar5_get, _param_ArmISA.ArmISAParams_id_isar5_set)
    id_mmfr0 = _swig_property(_param_ArmISA.ArmISAParams_id_mmfr0_get, _param_ArmISA.ArmISAParams_id_mmfr0_set)
    id_mmfr1 = _swig_property(_param_ArmISA.ArmISAParams_id_mmfr1_get, _param_ArmISA.ArmISAParams_id_mmfr1_set)
    id_mmfr2 = _swig_property(_param_ArmISA.ArmISAParams_id_mmfr2_get, _param_ArmISA.ArmISAParams_id_mmfr2_set)
    id_mmfr3 = _swig_property(_param_ArmISA.ArmISAParams_id_mmfr3_get, _param_ArmISA.ArmISAParams_id_mmfr3_set)
    id_pfr0 = _swig_property(_param_ArmISA.ArmISAParams_id_pfr0_get, _param_ArmISA.ArmISAParams_id_pfr0_set)
    id_pfr1 = _swig_property(_param_ArmISA.ArmISAParams_id_pfr1_get, _param_ArmISA.ArmISAParams_id_pfr1_set)
    midr = _swig_property(_param_ArmISA.ArmISAParams_midr_get, _param_ArmISA.ArmISAParams_midr_set)
    pmu = _swig_property(_param_ArmISA.ArmISAParams_pmu_get, _param_ArmISA.ArmISAParams_pmu_set)
    system = _swig_property(_param_ArmISA.ArmISAParams_system_get, _param_ArmISA.ArmISAParams_system_set)

    def __init__(self):
        this = _param_ArmISA.new_ArmISAParams()
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _param_ArmISA.delete_ArmISAParams
    __del__ = lambda self: None
ArmISAParams_swigregister = _param_ArmISA.ArmISAParams_swigregister
ArmISAParams_swigregister(ArmISAParams)



