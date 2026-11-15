# Inline interpreter progress

2026-11-15T14:57Z: 8c5d1d183 replaces production per-instruction macro
expansion with constant arguments to static always-inline interpreter bodies.
Bindings reference existing register/flag/arena/ghost cells without copying
state or drawing extra inputs.02fb4e139 also routes finite indirect helper
cases through that body and shares helper clobber/fact operations. The same C
handlers remain the interpreter; formal extraction of the adapter is open.

| Same OTel P/proof/map metadata | Preprocessed bytes |
|---|---:|
| Previous width-constant macro control |297,172,962|
| Initial inline body |20,020,201|
| Current shared helper effects |5,729,367|

Current source1,090,696B gives5.25x expansion,98.07% smaller than the macro
control. Actual Clang-E:0.275s wall,90,980KiB peak RSS. Streamed C/CPP
are build intermediates in memory, not a second canonical build. Commands,
hashes and input identities in result.json/raw permit reconstruction. Source
header hashes include FORMAL's announced CompCert-only adapters; those working
changes remain FORMAL-owned. This is historical matching metadata, not fresh
app capture or equal-work certification.

Scoped validation: latest final-table1,024 native plus1,024 full-context
simulator cases and normal B compilation pass; earlier initial-inline16BMI2
fixtures pass4,032 CPU/shared-C cases and normal B. Latest independent clock
helper oracle checks call/result, all callee/caller registers, flags/XMM,
64free-stack bytes, ghost facts and24zero-environment choices. Full input
quantification and all other instruction forms remain formal/functional work.

96c004c0f adds nodebug only on interpreter internals, keeping normal-g.
Small table local debug variables12,075→76; executor debug subprogram1→0.
BTF/BTF.ext remain present (1,556/640B), but metadata/B bytes differ; their
presence is not an ABI/kernel-acceptance proof. Table execution/B compile
still passes. This targets measured SROA debug-variable processing.

**Full compiler cost and frame remain unresolved.** Initial-inline and
nodebug-only optimized frontends were still running after20m12s and8m50s
CPU. Three actual initial-inline stack samples show SROA/PromoteMemToReg,
including debug insertion. Both are now SIGSTOP for C's Katran timing, not
successful compiles. Their eventual wall times include this pause; use the
recorded CPU usage and pause stamps. Latest5.73MB full frontend waits on the
nodebug control's actual PID end; scale100/1000 normal-B/code-size/direct-FP
observations wait on initial-inline control. No success prerequisite, restart,
new OTel build directory or mutation of captured live inputs. Direct FP access
is a lower bound, not a complete stack-frame measurement.

Raw `/workspaces/kprog-raw/perf/20261115-inline-interpreter`: every failure
(including missing-time launch), result, command and debugger observation is
retained.14:57 paused exact compiler PIDs911032/1038827/1041837 and released
1038810's imageEX via the existing pidfd helper. No guest or image mutation.
C's Katran timing can proceed; resume compilation outside actual timing.
P-SPECIALIZE parent, full B/stock/checked/app acceptance and speed remain open.
