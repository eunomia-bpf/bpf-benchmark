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

2026-11-26T22:00:42Z: repaired both native emission boundaries using the existing fixed
x86 option, with no new configuration. native_context_lto_object supplies it
and changes its cache identity tov3. trusted_specializer's final checked-
native Clang command supplies the same option; helper IR compilation does
not emit native instructions and needs no redundant backend option.

The real old shared-loader call emitted9cmovs; rebuilt loader emits0,
passes16384cases, ignores a deliberately stale old-key cache sentinel,
and reuses its new cache on the next call. The actual checked-native
compiler function likewise changes9→0 and passes16384cases each time;
its frontend IR bytes are identical. This isolated compiler fixture is
not a service admission or stock-verified/installed application result.
Before/after generated artifacts and complete commands are archived.

The verified-loader base was rebuilt in place under imageEX on CPUs16/18
with16GiB address-space cap. The redundant kprog/libnativeloader/build
was removed after retaining its logs/cache/link recipes; that legacy path
now aliases the existing base. Fresh emission through this canonical base
again has0cmovs and passes16384cases, not merely a previous cached result.
No runtime image or kernel was rebuilt. base-refresh.json records actions.

Next finite validation uses the existing kernel-probe-live-20261120 Make
recipe: control plus twelve native probe inputs, stock B verification,
checked-sim-c installation and TEST_RUN on the sole kernel/base. It does
not measure applications or full timing. guest_check.py retains raw files
under /workspaces, archives/publications on completion, and resumes the
lane on every result. This is targeted validation of changed native emission;
it does not close Tetragon's separate oversized-B-frame coverage issue.

2026-11-26T22:12:05Z: finite guest check completed controller1, raw publicationa1d57b754.
All13B programs passed stock and all13installed as checked-sim-c. All13
final native command records carry the fixed common option. The existing
semantic self-check reports10pass/3fail: kernel-fault, kernel-string-fault,
compat-kernel-fault. No case was skipped or relabelled as passing.

The three initial P objects already have only a constant3 return following
their plain memory reads (see *-initial-P.dis). The existing fixture expects
old bpf_probe_read helper EFAULT/zeroing semantics and return2. Current
native-helpers.h uses plain header loads, whose recovered fault value is0;
its byte wrapper returns0 and its string loop can observe that0 as a
terminator. Thus this initial P cannot meet that older oracle regardless
of the new backend flag. The client combines TEST_RUN syscall/retval errors
and does not print a failed retval;3 here is a static code finding, not a
recorded failed TEST_RUN counter. This check remains10pass/3fail, controller1.

History/scope: the old13pass receipt predates78336c8d7 (11-20 08:50Z), which
restored header loads;3aa496416 retained that performance definition. On
11-23 the operator rejected changing direct kernel reads to helper calls
(user-instruction.md lines311-312). This phase1 repair preserves current P;
no source-helper change or weakened/removed oracle was made to turn these
results green. The data establish admission and the restored emission flag,
with an explicit older-helper-contract mismatch, not universal functional
or application acceptance or an improvement in direct-native timing.

All13successful preprocess commands and26removed piece paths were inspected
through complete request archives: joined source is retained, piece source
and expanded pieces are absent. Service archival includes the whole request
directory. guest-outcome.json/log retain per-case receipts, flags and cleanup;
full raw evidence remains in the committed5921744-byte part and persistent
rawdirectory. Current pipeline B-frame coverage and ARM work remain open.
No job remains active; runtime image and full timing stay unchanged.
