import m5.internal
import m5.util

buildEnv = m5.util.SmartDict([('USE_FENV', True), ('SS_COMPATIBLE_FP', False), ('TARGET_ISA', 'x86'), ('CP_ANNOTATE', False), ('USE_POSIX_CLOCK', True), ('USE_KVM', True), ('PROTOCOL', 'MI_example'), ('HAVE_PROTOBUF', False), ('HAVE_PERF_ATTR_EXCLUDE_HOST', 1)])

compileDate = m5.internal.core.compileDate
_globals = globals()
for key,val in m5.internal.core.__dict__.iteritems():
    if key.startswith('flag_'):
        flag = key[5:]
        _globals[flag] = val
del _globals
