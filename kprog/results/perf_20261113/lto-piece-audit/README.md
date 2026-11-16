2026-11-16T12:32:02Z

Installed native code is the size target. `bytes_jited` from the kernel program records is used below, including each program and helper/LTO body installed with it. Input P function bytes are not that size. All records are retained; no hotness/run-count filter affects the size totals. These snapshots are a tracked-program census, not every transient load.

| App / retained configuration | JIT bytes / programs | Native bytes / programs | Native / JIT | Per-call evidence |
| --- | ---: | ---: | ---: | --- |
| bcc / current-stats-off | 7,965 / 25 | 38,841 / 25 | 4.876460 | unavailable (stats off) |
| bcc / retained-stats-on | 7,965 / 25 | 38,841 / 25 | 4.876460 | 113.079 → 88.230 ns, 1.281648x (sys_exit) |
| otel / named-array | 167,504 / 13 | 275,725 / 12 | 1.646080 | 2521.616 → 2737.545 ns, 0.921123x (native_tracer_e) |
| otel / typed-hash | 167,504 / 13 | 276,158 / 12 | 1.648665 | 2487.591 → 2771.795 ns, 0.897466x (native_tracer_e) |
| otel / read-hash-array-lpm | 167,504 / 13 | 305,859 / 12 | 1.825980 | 2406.996 → 2705.071 ns, 0.889809x (native_tracer_e) |
| otel / combined-codegen-lto | 167,504 / 13 | 304,536 / 12 | 1.818082 | 2389.054 → 2145.804 ns, 1.113361x (native_tracer_e) |
| otel / corrected-all-lto | 167,504 / 13 | 314,013 / 13 | 1.874660 | 2323.201 → 2057.735 ns, 1.129009x (native_tracer_e) |
| otel / current-stats-off | 167,504 / 13 | 330,814 / 13 | 1.974962 | unavailable (stats off) |

These are combined configurations from different runs and dates, not component ablations. In particular the 11-14 rows also differ in producer flags, installed program census and workload/environment state. Their chronological difference is not an individual LTO effect. Current OTel own unwind counters remain to check; older unequal-work 1.854x/1.866x/2.020x figures are not performance evidence for the corrected context.

| Piece and source | Per-call effect supported by retained measurements | Installed-byte evidence | Action / remaining attribution |
| --- | --- | --- | --- |
| PERF_EVENT context conversion, perf_context_lto.cpp | Correctness conversion; current stats-off has no per-call time | Current OTel combined 330,814 B vs 167,504 B JIT | Retain correct context semantics. Never remove unwinding to recover an unequal-work ratio. Individual code delta unmeasured. |
| Proven ARRAY / per-CPU ARRAY expansion, x86.rs build_x86_array_lookup | Named-array OTel configuration 0.921123x; individual contribution unmeasured | That combined native set 275,725 B; current BCC/OTel 38,841/330,814 B | No isolated gain or installed delta established. Attribute before deciding removal. |
| Typed hash target and hash-key expansion, x86.rs / x86_hash_lookup.rs | Typed-hash OTel configuration 0.897466x; current BCC sys_exit combined 1.281648x | Historical OTel 276,158 B; current BCC sys_exit 3,483 B vs 406 B JIT | Largest BCC static lead: shared hash routine emits constant cases 4/8/12/16/20 plus general/byte-key paths for each raw lookup target. Attribution still required; a combined gain is not a hash-only gain. |
| Shared runtime ARRAY dispatch, x86_runtime_array.rs | No isolated per-call measurement | Included in current BCC/OTel totals; separate installed delta unmeasured | Source appends one dispatch routine when generic lookup relocations remain. Preserve dynamic-map semantics in any removal. |
| Direct nofault user/kernel reads, x86_probe_read.rs | Combined read/hash/ARRAY/LPM configuration 0.889809x; later combined flags 1.113361x | 305,859 B then 304,536 B in those configurations | Neither combined result isolates the reads. Fault/error clearing and helper semantics must remain equivalent. |
| LPM dispatch, x86_lpm_lookup.rs | Same combined 0.889809x; earlier profile 3587.61 vs 3606.32 sampled cycles/entry is attribution, not per-lookup latency | Included in that 305,859 B set; separate delta unmeasured | Source appends a generic-map type dispatch. Need size/time attribution before removal; do not infer an individual gain. |
| Per-CPU CPU/task helper loads, x86_probe_read.rs percpu | No isolated per-call measurement | Included in combined totals; separate delta unmeasured | Same kernel per-CPU fact/ABI must be retained. |
| Monotonic clock binding, x86.rs runtime_call_target | No isolated OTel/BCC measurement; clock-lto report claims none | Target substitution retains the existing call-slot instruction form; no new routine is emitted by this function | No demonstrated growth-without-gain case. Keep clock basis and numeric helper identity. |
| Native tail-call expansion, x86.rs build_x86_tail_call_inline | No isolated per-call measurement | Included in installed totals; separate delta unmeasured | Required native tail-call semantics; calling the kernel's C helper stub is not an equivalent replacement. |
| Producer target-CPU/CMOV/sibling flags (step 1) | Combined OTel entry 1.113361x, later corrected all-LTO 1.129009x | Combined sets 304,536 B and 314,013 B | Uniform flag set remains. These are not isolated LTO effects. |

No component is newly removed on the basis of a missing measurement. The known compact dynamic word-hash slowdown was already changed forward in 72a2c1d37: retained Katran per-call 1.031460x to 1.015468x, installed bytes 12,418 to 11,048 B, then fixed-length specialization restored. That was a speed/size tradeoff in older controls, not evidence that current hash expansion has an isolated gain. Further removals need an actual piece-specific cost conclusion, not an assumption that unknown means zero. The current installed-size requirement remains unmet.

BCC current throughput is the measured 0.917172979x, with an observed environment/CPU-budget difference: native first-to-last CPU-normalized cap/set/sockfd rates are 0.987/0.991/1.016 while accounted CPU time falls. This is not evidence of a rising CPU cost per reported operation; the underlying cause remains unresolved. It does not justify discarding the result. Retained stats-on sys_enter is 85.473 → 82.676 ns and 108 → 153 B; sys_exit is 113.079 → 88.230 ns and 406 → 3,483 B. Its event counts differ and it is not the queued current stats-on case. See ../bcc-series/README.md.

Reproduce: `make -r -f kprog/test/katran-accounting.mk lto-piece-audit OUTPUT=/workspaces/kprog-raw/perf/20261116-lto-piece-audit`. analysis.json names every raw input and preserves all original per-program counters and colliding IDs. Source review identifies the candidates; separate per-piece installed deltas and current per-call attribution remain open before further LTO optimization. No benchmark knob, program selection or paper text changed.
