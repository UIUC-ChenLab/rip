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
            fp, pathname, description = imp.find_module('_MinorFUTiming_vector', [dirname(__file__)])
        except ImportError:
            import _MinorFUTiming_vector
            return _MinorFUTiming_vector
        if fp is not None:
            try:
                _mod = imp.load_module('_MinorFUTiming_vector', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _MinorFUTiming_vector = swig_import_helper()
    del swig_import_helper
else:
    import _MinorFUTiming_vector
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
    __swig_destroy__ = _MinorFUTiming_vector.delete_SwigPyIterator
    __del__ = lambda self: None

    def value(self):
        return _MinorFUTiming_vector.SwigPyIterator_value(self)

    def incr(self, n=1):
        return _MinorFUTiming_vector.SwigPyIterator_incr(self, n)

    def decr(self, n=1):
        return _MinorFUTiming_vector.SwigPyIterator_decr(self, n)

    def distance(self, x):
        return _MinorFUTiming_vector.SwigPyIterator_distance(self, x)

    def equal(self, x):
        return _MinorFUTiming_vector.SwigPyIterator_equal(self, x)

    def copy(self):
        return _MinorFUTiming_vector.SwigPyIterator_copy(self)

    def next(self):
        return _MinorFUTiming_vector.SwigPyIterator_next(self)

    def __next__(self):
        return _MinorFUTiming_vector.SwigPyIterator___next__(self)

    def previous(self):
        return _MinorFUTiming_vector.SwigPyIterator_previous(self)

    def advance(self, n):
        return _MinorFUTiming_vector.SwigPyIterator_advance(self, n)

    def __eq__(self, x):
        return _MinorFUTiming_vector.SwigPyIterator___eq__(self, x)

    def __ne__(self, x):
        return _MinorFUTiming_vector.SwigPyIterator___ne__(self, x)

    def __iadd__(self, n):
        return _MinorFUTiming_vector.SwigPyIterator___iadd__(self, n)

    def __isub__(self, n):
        return _MinorFUTiming_vector.SwigPyIterator___isub__(self, n)

    def __add__(self, n):
        return _MinorFUTiming_vector.SwigPyIterator___add__(self, n)

    def __sub__(self, *args):
        return _MinorFUTiming_vector.SwigPyIterator___sub__(self, *args)
    def __iter__(self):
        return self
SwigPyIterator_swigregister = _MinorFUTiming_vector.SwigPyIterator_swigregister
SwigPyIterator_swigregister(SwigPyIterator)

import m5.internal.param_MinorFUTiming
import m5.internal.param_TimingExpr
import m5.internal.param_SimObject
import m5.internal.drain
import m5.internal.serialize
import m5.internal.param_MinorOpClassSet
import m5.internal.MinorOpClass_vector
import m5.internal.param_MinorOpClass
import m5.internal.enum_OpClass
import m5.internal.Cycles_vector
class vector_MinorFUTiming(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr

    def iterator(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming___nonzero__(self)

    def __bool__(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming___bool__(self)

    def __len__(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming___len__(self)

    def __getslice__(self, i, j):
        return _MinorFUTiming_vector.vector_MinorFUTiming___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _MinorFUTiming_vector.vector_MinorFUTiming___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _MinorFUTiming_vector.vector_MinorFUTiming___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _MinorFUTiming_vector.vector_MinorFUTiming___delitem__(self, *args)

    def __getitem__(self, *args):
        return _MinorFUTiming_vector.vector_MinorFUTiming___getitem__(self, *args)

    def __setitem__(self, *args):
        return _MinorFUTiming_vector.vector_MinorFUTiming___setitem__(self, *args)

    def pop(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_pop(self)

    def append(self, x):
        return _MinorFUTiming_vector.vector_MinorFUTiming_append(self, x)

    def empty(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_empty(self)

    def size(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_size(self)

    def swap(self, v):
        return _MinorFUTiming_vector.vector_MinorFUTiming_swap(self, v)

    def begin(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_begin(self)

    def end(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_end(self)

    def rbegin(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_rbegin(self)

    def rend(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_rend(self)

    def clear(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_clear(self)

    def get_allocator(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_get_allocator(self)

    def pop_back(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_pop_back(self)

    def erase(self, *args):
        return _MinorFUTiming_vector.vector_MinorFUTiming_erase(self, *args)

    def __init__(self, *args):
        this = _MinorFUTiming_vector.new_vector_MinorFUTiming(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def push_back(self, x):
        return _MinorFUTiming_vector.vector_MinorFUTiming_push_back(self, x)

    def front(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_front(self)

    def back(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_back(self)

    def assign(self, n, x):
        return _MinorFUTiming_vector.vector_MinorFUTiming_assign(self, n, x)

    def resize(self, *args):
        return _MinorFUTiming_vector.vector_MinorFUTiming_resize(self, *args)

    def insert(self, *args):
        return _MinorFUTiming_vector.vector_MinorFUTiming_insert(self, *args)

    def reserve(self, n):
        return _MinorFUTiming_vector.vector_MinorFUTiming_reserve(self, n)

    def capacity(self):
        return _MinorFUTiming_vector.vector_MinorFUTiming_capacity(self)
    __swig_destroy__ = _MinorFUTiming_vector.delete_vector_MinorFUTiming
    __del__ = lambda self: None
vector_MinorFUTiming_swigregister = _MinorFUTiming_vector.vector_MinorFUTiming_swigregister
vector_MinorFUTiming_swigregister(vector_MinorFUTiming)



