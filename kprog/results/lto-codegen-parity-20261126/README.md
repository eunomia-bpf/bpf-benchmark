# Native codegen policy through load-time LTO

2026-11-26T21:47:51Z: phase1 pipeline audit found that vendor/bpf/Makefile supplies
x86-cmov-converter-force-all when P is produced, while the x86 trusted
loader's native_context_lto_object invocation omits it. The option is a
backend setting, not a property preserved in embedded frontend IR.

The real installed native LTO compiler reproduces the loss on an unrolled
search: original P has0cmovs, ordinary regeneration9, regeneration with
the common option0. Each passes16384 independent linear-oracle hostcases
withUBSan. result.json/commands.json/disassemblies/compressed rawobjects
retain exact commands/results. These are codegen and semantic evidence,
not performance measurements or complete stock/app acceptance.

This path belongs to the x86 trusted loader; the frozen direct-native
timing entry uses native_loader.cpp and its initial P. Therefore this
mismatch does not explain the earlier direct OTel/Tetragon timings. ARM
does not invoke this x86 context compiler. No ISA, framework, CPU, image,
P flag, runtime or benchmark setting changed in this reproduction.
The next repair is the same fixed option in every context-LTO invocation
and a cache identity update, with no per-program selection or new knob.
