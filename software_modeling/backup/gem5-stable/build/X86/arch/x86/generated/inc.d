decoder.hh: decoder-g.hh.inc decoder-ns.hh.inc
decoder.cc: decoder-g.cc.inc decode-method.cc.inc decoder.hh
inst-constrs.cc: decoder-g.cc.inc decoder-ns.cc.inc decoder.hh
generic_cpu_exec.cc: exec-g.cc.inc exec-ns.cc.inc decoder.hh
max_inst_regs.hh:
