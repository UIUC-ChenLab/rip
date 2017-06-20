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
            fp, pathname, description = imp.find_module('_core', [dirname(__file__)])
        except ImportError:
            import _core
            return _core
        if fp is not None:
            try:
                _mod = imp.load_module('_core', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _core = swig_import_helper()
    del swig_import_helper
else:
    import _core
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


class Cycles(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr

    def __init__(self, *args):
        this = _core.new_Cycles(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _core.delete_Cycles
    __del__ = lambda self: None
Cycles_swigregister = _core.Cycles_swigregister
Cycles_swigregister(Cycles)
cvar = _core.cvar
MaxTick = cvar.MaxTick


def romMicroPC(upc):
    return _core.romMicroPC(upc)
romMicroPC = _core.romMicroPC

def normalMicroPC(upc):
    return _core.normalMicroPC(upc)
normalMicroPC = _core.normalMicroPC

def isRomMicroPC(upc):
    return _core.isRomMicroPC(upc)
isRomMicroPC = _core.isRomMicroPC

_core.BigEndianByteOrder_swigconstant(_core)
BigEndianByteOrder = _core.BigEndianByteOrder

_core.LittleEndianByteOrder_swigconstant(_core)
LittleEndianByteOrder = _core.LittleEndianByteOrder

def setOutputDir(dir):
    return _core.setOutputDir(dir)
setOutputDir = _core.setOutputDir

def doExitCleanup():
    return _core.doExitCleanup()
doExitCleanup = _core.doExitCleanup

def disableAllListeners():
    return _core.disableAllListeners()
disableAllListeners = _core.disableAllListeners

def seedRandom(seed):
    return _core.seedRandom(seed)
seedRandom = _core.seedRandom

def setClockFrequency(ticksPerSecond):
    return _core.setClockFrequency(ticksPerSecond)
setClockFrequency = _core.setClockFrequency

def curTick():
    return _core.curTick()
curTick = _core.curTick

def serializeAll(cpt_dir):
    return _core.serializeAll(cpt_dir)
serializeAll = _core.serializeAll

def getCheckpoint(cpt_dir):
    return _core.getCheckpoint(cpt_dir)
getCheckpoint = _core.getCheckpoint

def unserializeGlobals(cp):
    return _core.unserializeGlobals(cp)
unserializeGlobals = _core.unserializeGlobals

MicroPCRomBit = cvar.MicroPCRomBit
MaxAddr = cvar.MaxAddr
InvalidThreadID = cvar.InvalidThreadID
InvalidPortID = cvar.InvalidPortID
compileDate = cvar.compileDate
flag_DEBUG = cvar.flag_DEBUG
flag_NDEBUG = cvar.flag_NDEBUG
flag_TRACING_ON = cvar.flag_TRACING_ON

