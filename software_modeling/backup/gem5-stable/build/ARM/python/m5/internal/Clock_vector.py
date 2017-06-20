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
            fp, pathname, description = imp.find_module('_Clock_vector', [dirname(__file__)])
        except ImportError:
            import _Clock_vector
            return _Clock_vector
        if fp is not None:
            try:
                _mod = imp.load_module('_Clock_vector', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _Clock_vector = swig_import_helper()
    del swig_import_helper
else:
    import _Clock_vector
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
    __swig_destroy__ = _Clock_vector.delete_SwigPyIterator
    __del__ = lambda self: None

    def value(self):
        return _Clock_vector.SwigPyIterator_value(self)

    def incr(self, n=1):
        return _Clock_vector.SwigPyIterator_incr(self, n)

    def decr(self, n=1):
        return _Clock_vector.SwigPyIterator_decr(self, n)

    def distance(self, x):
        return _Clock_vector.SwigPyIterator_distance(self, x)

    def equal(self, x):
        return _Clock_vector.SwigPyIterator_equal(self, x)

    def copy(self):
        return _Clock_vector.SwigPyIterator_copy(self)

    def next(self):
        return _Clock_vector.SwigPyIterator_next(self)

    def __next__(self):
        return _Clock_vector.SwigPyIterator___next__(self)

    def previous(self):
        return _Clock_vector.SwigPyIterator_previous(self)

    def advance(self, n):
        return _Clock_vector.SwigPyIterator_advance(self, n)

    def __eq__(self, x):
        return _Clock_vector.SwigPyIterator___eq__(self, x)

    def __ne__(self, x):
        return _Clock_vector.SwigPyIterator___ne__(self, x)

    def __iadd__(self, n):
        return _Clock_vector.SwigPyIterator___iadd__(self, n)

    def __isub__(self, n):
        return _Clock_vector.SwigPyIterator___isub__(self, n)

    def __add__(self, n):
        return _Clock_vector.SwigPyIterator___add__(self, n)

    def __sub__(self, *args):
        return _Clock_vector.SwigPyIterator___sub__(self, *args)
    def __iter__(self):
        return self
SwigPyIterator_swigregister = _Clock_vector.SwigPyIterator_swigregister
SwigPyIterator_swigregister(SwigPyIterator)

class vector_Clock(object):
    thisown = _swig_property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr

    def iterator(self):
        return _Clock_vector.vector_Clock_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _Clock_vector.vector_Clock___nonzero__(self)

    def __bool__(self):
        return _Clock_vector.vector_Clock___bool__(self)

    def __len__(self):
        return _Clock_vector.vector_Clock___len__(self)

    def __getslice__(self, i, j):
        return _Clock_vector.vector_Clock___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _Clock_vector.vector_Clock___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _Clock_vector.vector_Clock___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _Clock_vector.vector_Clock___delitem__(self, *args)

    def __getitem__(self, *args):
        return _Clock_vector.vector_Clock___getitem__(self, *args)

    def __setitem__(self, *args):
        return _Clock_vector.vector_Clock___setitem__(self, *args)

    def pop(self):
        return _Clock_vector.vector_Clock_pop(self)

    def append(self, x):
        return _Clock_vector.vector_Clock_append(self, x)

    def empty(self):
        return _Clock_vector.vector_Clock_empty(self)

    def size(self):
        return _Clock_vector.vector_Clock_size(self)

    def swap(self, v):
        return _Clock_vector.vector_Clock_swap(self, v)

    def begin(self):
        return _Clock_vector.vector_Clock_begin(self)

    def end(self):
        return _Clock_vector.vector_Clock_end(self)

    def rbegin(self):
        return _Clock_vector.vector_Clock_rbegin(self)

    def rend(self):
        return _Clock_vector.vector_Clock_rend(self)

    def clear(self):
        return _Clock_vector.vector_Clock_clear(self)

    def get_allocator(self):
        return _Clock_vector.vector_Clock_get_allocator(self)

    def pop_back(self):
        return _Clock_vector.vector_Clock_pop_back(self)

    def erase(self, *args):
        return _Clock_vector.vector_Clock_erase(self, *args)

    def __init__(self, *args):
        this = _Clock_vector.new_vector_Clock(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def push_back(self, x):
        return _Clock_vector.vector_Clock_push_back(self, x)

    def front(self):
        return _Clock_vector.vector_Clock_front(self)

    def back(self):
        return _Clock_vector.vector_Clock_back(self)

    def assign(self, n, x):
        return _Clock_vector.vector_Clock_assign(self, n, x)

    def resize(self, *args):
        return _Clock_vector.vector_Clock_resize(self, *args)

    def insert(self, *args):
        return _Clock_vector.vector_Clock_insert(self, *args)

    def reserve(self, n):
        return _Clock_vector.vector_Clock_reserve(self, n)

    def capacity(self):
        return _Clock_vector.vector_Clock_capacity(self)
    __swig_destroy__ = _Clock_vector.delete_vector_Clock
    __del__ = lambda self: None
vector_Clock_swigregister = _Clock_vector.vector_Clock_swigregister
vector_Clock_swigregister(vector_Clock)



