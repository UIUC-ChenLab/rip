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
            fp, pathname, description = imp.find_module('_enum_StaticInstFlags', [dirname(__file__)])
        except ImportError:
            import _enum_StaticInstFlags
            return _enum_StaticInstFlags
        if fp is not None:
            try:
                _mod = imp.load_module('_enum_StaticInstFlags', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _enum_StaticInstFlags = swig_import_helper()
    del swig_import_helper
else:
    import _enum_StaticInstFlags
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


class StaticInstFlags(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    IsNop = _enum_StaticInstFlags.StaticInstFlags_IsNop
    IsInteger = _enum_StaticInstFlags.StaticInstFlags_IsInteger
    IsFloating = _enum_StaticInstFlags.StaticInstFlags_IsFloating
    IsCC = _enum_StaticInstFlags.StaticInstFlags_IsCC
    IsMemRef = _enum_StaticInstFlags.StaticInstFlags_IsMemRef
    IsLoad = _enum_StaticInstFlags.StaticInstFlags_IsLoad
    IsStore = _enum_StaticInstFlags.StaticInstFlags_IsStore
    IsStoreConditional = _enum_StaticInstFlags.StaticInstFlags_IsStoreConditional
    IsIndexed = _enum_StaticInstFlags.StaticInstFlags_IsIndexed
    IsInstPrefetch = _enum_StaticInstFlags.StaticInstFlags_IsInstPrefetch
    IsDataPrefetch = _enum_StaticInstFlags.StaticInstFlags_IsDataPrefetch
    IsControl = _enum_StaticInstFlags.StaticInstFlags_IsControl
    IsDirectControl = _enum_StaticInstFlags.StaticInstFlags_IsDirectControl
    IsIndirectControl = _enum_StaticInstFlags.StaticInstFlags_IsIndirectControl
    IsCondControl = _enum_StaticInstFlags.StaticInstFlags_IsCondControl
    IsUncondControl = _enum_StaticInstFlags.StaticInstFlags_IsUncondControl
    IsCall = _enum_StaticInstFlags.StaticInstFlags_IsCall
    IsReturn = _enum_StaticInstFlags.StaticInstFlags_IsReturn
    IsCondDelaySlot = _enum_StaticInstFlags.StaticInstFlags_IsCondDelaySlot
    IsThreadSync = _enum_StaticInstFlags.StaticInstFlags_IsThreadSync
    IsSerializing = _enum_StaticInstFlags.StaticInstFlags_IsSerializing
    IsSerializeBefore = _enum_StaticInstFlags.StaticInstFlags_IsSerializeBefore
    IsSerializeAfter = _enum_StaticInstFlags.StaticInstFlags_IsSerializeAfter
    IsMemBarrier = _enum_StaticInstFlags.StaticInstFlags_IsMemBarrier
    IsWriteBarrier = _enum_StaticInstFlags.StaticInstFlags_IsWriteBarrier
    IsReadBarrier = _enum_StaticInstFlags.StaticInstFlags_IsReadBarrier
    IsERET = _enum_StaticInstFlags.StaticInstFlags_IsERET
    IsNonSpeculative = _enum_StaticInstFlags.StaticInstFlags_IsNonSpeculative
    IsQuiesce = _enum_StaticInstFlags.StaticInstFlags_IsQuiesce
    IsIprAccess = _enum_StaticInstFlags.StaticInstFlags_IsIprAccess
    IsUnverifiable = _enum_StaticInstFlags.StaticInstFlags_IsUnverifiable
    IsSyscall = _enum_StaticInstFlags.StaticInstFlags_IsSyscall
    IsMacroop = _enum_StaticInstFlags.StaticInstFlags_IsMacroop
    IsMicroop = _enum_StaticInstFlags.StaticInstFlags_IsMicroop
    IsDelayedCommit = _enum_StaticInstFlags.StaticInstFlags_IsDelayedCommit
    IsLastMicroop = _enum_StaticInstFlags.StaticInstFlags_IsLastMicroop
    IsFirstMicroop = _enum_StaticInstFlags.StaticInstFlags_IsFirstMicroop
    IsMicroBranch = _enum_StaticInstFlags.StaticInstFlags_IsMicroBranch
    IsDspOp = _enum_StaticInstFlags.StaticInstFlags_IsDspOp
    IsSquashAfter = _enum_StaticInstFlags.StaticInstFlags_IsSquashAfter
    Num_Flags = _enum_StaticInstFlags.StaticInstFlags_Num_Flags
    FlagsStrings = _swig_property(_enum_StaticInstFlags.StaticInstFlags_FlagsStrings_get, _enum_StaticInstFlags.StaticInstFlags_FlagsStrings_set)

    def __init__(self):
        this = _enum_StaticInstFlags.new_StaticInstFlags()
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _enum_StaticInstFlags.delete_StaticInstFlags
    __del__ = lambda self: None
StaticInstFlags_swigregister = _enum_StaticInstFlags.StaticInstFlags_swigregister
StaticInstFlags_swigregister(StaticInstFlags)
cvar = _enum_StaticInstFlags.cvar



