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
            fp, pathname, description = imp.find_module('_debug', [dirname(__file__)])
        except ImportError:
            import _debug
            return _debug
        if fp is not None:
            try:
                _mod = imp.load_module('_debug', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _debug = swig_import_helper()
    del swig_import_helper
else:
    import _debug
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


class SwigPyIterator(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _debug.delete_SwigPyIterator
    __del__ = lambda self: None

    def value(self):
        return _debug.SwigPyIterator_value(self)

    def incr(self, n=1):
        return _debug.SwigPyIterator_incr(self, n)

    def decr(self, n=1):
        return _debug.SwigPyIterator_decr(self, n)

    def distance(self, x):
        return _debug.SwigPyIterator_distance(self, x)

    def equal(self, x):
        return _debug.SwigPyIterator_equal(self, x)

    def copy(self):
        return _debug.SwigPyIterator_copy(self)

    def next(self):
        return _debug.SwigPyIterator_next(self)

    def __next__(self):
        return _debug.SwigPyIterator___next__(self)

    def previous(self):
        return _debug.SwigPyIterator_previous(self)

    def advance(self, n):
        return _debug.SwigPyIterator_advance(self, n)

    def __eq__(self, x):
        return _debug.SwigPyIterator___eq__(self, x)

    def __ne__(self, x):
        return _debug.SwigPyIterator___ne__(self, x)

    def __iadd__(self, n):
        return _debug.SwigPyIterator___iadd__(self, n)

    def __isub__(self, n):
        return _debug.SwigPyIterator___isub__(self, n)

    def __add__(self, n):
        return _debug.SwigPyIterator___add__(self, n)

    def __sub__(self, *args):
        return _debug.SwigPyIterator___sub__(self, *args)
    def __iter__(self):
        return self
SwigPyIterator_swigregister = _debug.SwigPyIterator_swigregister
SwigPyIterator_swigregister(SwigPyIterator)


def breakpoint():
    return _debug.breakpoint()
breakpoint = _debug.breakpoint
class Flag(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _debug.delete_Flag
    __del__ = lambda self: None

    def name(self):
        return _debug.Flag_name(self)

    def desc(self):
        return _debug.Flag_desc(self)

    def kids(self):
        return _debug.Flag_kids(self)

    def enable(self):
        return _debug.Flag_enable(self)

    def disable(self):
        return _debug.Flag_disable(self)
Flag_swigregister = _debug.Flag_swigregister
Flag_swigregister(Flag)

class SimpleFlag(Flag):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr

    def __init__(self, name, desc):
        this = _debug.new_SimpleFlag(name, desc)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def status(self):
        return _debug.SimpleFlag_status(self)

    def __nonzero__(self):
        return _debug.SimpleFlag___nonzero__(self)
    __bool__ = __nonzero__



    def enable(self):
        return _debug.SimpleFlag_enable(self)

    def disable(self):
        return _debug.SimpleFlag_disable(self)
    __swig_destroy__ = _debug.delete_SimpleFlag
    __del__ = lambda self: None
SimpleFlag_swigregister = _debug.SimpleFlag_swigregister
SimpleFlag_swigregister(SimpleFlag)

class CompoundFlag(SimpleFlag):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr

    def __init__(self, name, desc, f00=None, f01=None, f02=None, f03=None, f04=None, f05=None, f06=None, f07=None, f08=None, f09=None, f10=None, f11=None, f12=None, f13=None, f14=None, f15=None, f16=None, f17=None, f18=None, f19=None):
        this = _debug.new_CompoundFlag(name, desc, f00, f01, f02, f03, f04, f05, f06, f07, f08, f09, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def enable(self):
        return _debug.CompoundFlag_enable(self)

    def disable(self):
        return _debug.CompoundFlag_disable(self)
    __swig_destroy__ = _debug.delete_CompoundFlag
    __del__ = lambda self: None
CompoundFlag_swigregister = _debug.CompoundFlag_swigregister
CompoundFlag_swigregister(CompoundFlag)


def allFlags():
    return _debug.allFlags()
allFlags = _debug.allFlags

def findFlag(name):
    return _debug.findFlag(name)
findFlag = _debug.findFlag

def changeFlag(s, value):
    return _debug.changeFlag(s, value)
changeFlag = _debug.changeFlag

def setDebugFlag(string):
    return _debug.setDebugFlag(string)
setDebugFlag = _debug.setDebugFlag

def clearDebugFlag(string):
    return _debug.clearDebugFlag(string)
clearDebugFlag = _debug.clearDebugFlag

def dumpDebugFlags():
    return _debug.dumpDebugFlags()
dumpDebugFlags = _debug.dumpDebugFlags
class Cycles(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr

    def __init__(self, *args):
        this = _debug.new_Cycles(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _debug.delete_Cycles
    __del__ = lambda self: None
Cycles_swigregister = _debug.Cycles_swigregister
Cycles_swigregister(Cycles)
cvar = _debug.cvar
All = cvar.All
MaxTick = cvar.MaxTick


def romMicroPC(upc):
    return _debug.romMicroPC(upc)
romMicroPC = _debug.romMicroPC

def normalMicroPC(upc):
    return _debug.normalMicroPC(upc)
normalMicroPC = _debug.normalMicroPC

def isRomMicroPC(upc):
    return _debug.isRomMicroPC(upc)
isRomMicroPC = _debug.isRomMicroPC

_debug.BigEndianByteOrder_swigconstant(_debug)
BigEndianByteOrder = _debug.BigEndianByteOrder

_debug.LittleEndianByteOrder_swigconstant(_debug)
LittleEndianByteOrder = _debug.LittleEndianByteOrder

def schedBreak(when):
    return _debug.schedBreak(when)
schedBreak = _debug.schedBreak

def takeCheckpoint(when):
    return _debug.takeCheckpoint(when)
takeCheckpoint = _debug.takeCheckpoint

def eventqDump():
    return _debug.eventqDump()
eventqDump = _debug.eventqDump

def getRemoteGDBPort():
    return _debug.getRemoteGDBPort()
getRemoteGDBPort = _debug.getRemoteGDBPort

def setRemoteGDBPort(port):
    return _debug.setRemoteGDBPort(port)
setRemoteGDBPort = _debug.setRemoteGDBPort
class AllFlags(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr

    def iterator(self):
        return _debug.AllFlags_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _debug.AllFlags___nonzero__(self)

    def __bool__(self):
        return _debug.AllFlags___bool__(self)

    def __len__(self):
        return _debug.AllFlags___len__(self)

    def __getslice__(self, i, j):
        return _debug.AllFlags___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _debug.AllFlags___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _debug.AllFlags___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _debug.AllFlags___delitem__(self, *args)

    def __getitem__(self, *args):
        return _debug.AllFlags___getitem__(self, *args)

    def __setitem__(self, *args):
        return _debug.AllFlags___setitem__(self, *args)

    def pop(self):
        return _debug.AllFlags_pop(self)

    def append(self, x):
        return _debug.AllFlags_append(self, x)

    def empty(self):
        return _debug.AllFlags_empty(self)

    def size(self):
        return _debug.AllFlags_size(self)

    def swap(self, v):
        return _debug.AllFlags_swap(self, v)

    def begin(self):
        return _debug.AllFlags_begin(self)

    def end(self):
        return _debug.AllFlags_end(self)

    def rbegin(self):
        return _debug.AllFlags_rbegin(self)

    def rend(self):
        return _debug.AllFlags_rend(self)

    def clear(self):
        return _debug.AllFlags_clear(self)

    def get_allocator(self):
        return _debug.AllFlags_get_allocator(self)

    def pop_back(self):
        return _debug.AllFlags_pop_back(self)

    def erase(self, *args):
        return _debug.AllFlags_erase(self, *args)

    def __init__(self, *args):
        this = _debug.new_AllFlags(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def push_back(self, x):
        return _debug.AllFlags_push_back(self, x)

    def front(self):
        return _debug.AllFlags_front(self)

    def back(self):
        return _debug.AllFlags_back(self)

    def assign(self, n, x):
        return _debug.AllFlags_assign(self, n, x)

    def resize(self, *args):
        return _debug.AllFlags_resize(self, *args)

    def insert(self, *args):
        return _debug.AllFlags_insert(self, *args)

    def reserve(self, n):
        return _debug.AllFlags_reserve(self, n)

    def capacity(self):
        return _debug.AllFlags_capacity(self)
    __swig_destroy__ = _debug.delete_AllFlags
    __del__ = lambda self: None
AllFlags_swigregister = _debug.AllFlags_swigregister
AllFlags_swigregister(AllFlags)
MicroPCRomBit = cvar.MicroPCRomBit
MaxAddr = cvar.MaxAddr
InvalidThreadID = cvar.InvalidThreadID
InvalidPortID = cvar.InvalidPortID


def getAllFlagsVersion():
    return _debug.getAllFlagsVersion()
getAllFlagsVersion = _debug.getAllFlagsVersion

def getAllFlags():
    return _debug.getAllFlags()
getAllFlags = _debug.getAllFlags


