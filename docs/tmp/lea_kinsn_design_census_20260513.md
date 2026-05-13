# LEA kinsn design and testbin census

Date: 2026-05-13

Scope: read-only investigation of committed `bpfopt/testbin/*/*/canonicalize_output.bin`
inputs plus the generated `bpfopt/testccode/` native assembly and
`bpfopt/testobject/` BPF objects. No benchmark was run.

## Starting point

The prior x86 native-C gap report says native output uses `lea` heavily:
Katran has 152 sites, `rotate_dense` has 135, `cmov_dense` has 34, and
`large_mixed_500` has 23
(`docs/tmp/x86_native_c_kinsn_gap_20260512.md:246`). The same section states
that BPF can encode `base + imm` memory operands but not full
`base + index * scale + disp` addressing or arithmetic LEA
(`docs/tmp/x86_native_c_kinsn_gap_20260512.md:256`). Its recommendation was to
census bytecode first, split scalar and pointer cases, and start with scalar
`bpf_lea64` only if the site count is high
(`docs/tmp/x86_native_c_kinsn_gap_20260512.md:271`).

The testbin corpus is appropriate for this census because it contains 542 live
BPF program inputs from all 7 apps without rerunning corpus
(`bpfopt/testbin/README.md:7`, `bpfopt/testbin/README.md:71`). The per-program
input used here is `canonicalize_output.bin`, documented as post
`bpfopt --canonicalize-map-refs` bytecode and equal to the noop pass input
(`bpfopt/testbin/README.md:36`, `bpfopt/testbin/README.md:39`,
`bpfopt/testbin/README.md:40`). The binaries are pre-ReJIT baseline bytecode
(`bpfopt/testbin/README.md:75`).

## Existing implementation conventions

Current kinsn passes use a packed sidecar ABI, not normal C call arguments.
`emit_packed_kinsn_call_with_off()` emits a sidecar pseudo-insn immediately
before the kinsn call, and the result register is encoded in the payload
(`bpfopt/crates/bpfopt/src/insn.rs:642`). The sidecar payload has 52 usable bits:
dst register in bits 0..3, off bits 4..19, and imm bits 20..51
(`bpfopt/crates/bpfopt/src/insn.rs:541`).

Reference pass shape:

- `rotate` declares `bpf_rotate64` and `bpf_rotate32` in `KINSN_TARGETS`
  (`bpfopt/crates/bpfopt/src/passes/rotate.rs:5`), scans block windows
  (`bpfopt/crates/bpfopt/src/passes/rotate.rs:21`), checks liveness for a
  clobbered temporary (`bpfopt/crates/bpfopt/src/passes/rotate.rs:37`), packs
  registers and immediates into the sidecar payload
  (`bpfopt/crates/bpfopt/src/passes/rotate.rs:64`), then emits the packed kinsn
  call (`bpfopt/crates/bpfopt/src/passes/rotate.rs:70`).
- `cond_select` shows a multi-operand payload: dst/true/false/cond registers
  are packed at 4-bit offsets (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:125`).
- The pass registry records kinsn targets and whether verifier states are
  required (`bpfopt/crates/bpfopt/src/passes/mod.rs:30`), and deliberately does
  not do kinsn preflight arch gating (`bpfopt/crates/bpfopt/src/passes/mod.rs:35`).
- `ProgramCFG::reg_kind()` maps verifier state strings to scalar/pointer kinds
  when verifier states are available (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:358`,
  `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1016`). The public kind set is
  in `RegKind` (`bpfopt/crates/bpfopt/src/pass.rs:26`).
- In-block replacement passes should explicitly reject interior branch targets.
  `wide_mem` obtains branch-target entry sites and skips a candidate if any
  interior site is targeted (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:156`,
  `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:183`). Pair passes also use
  `collect_cross_block_pair_skips()` to surface a block-split skip signal
  (`bpfopt/crates/bpfopt/src/pass.rs:495`).

Reference module shape:

- x86 modules expose void kfunc stubs and BTF IDs, for example
  `bpf_rotate64`/`bpf_rotate32`
  (`module/x86/bpf_rotate.c:8`) and `bpf_select64`
  (`module/x86/bpf_select.c:8`).
- Payload decode helpers live in the module, using shared helpers such as
  `kinsn_payload_reg()`, `kinsn_payload_u8()`, and `kinsn_payload_s16()`
  (`module/include/kinsn_common.h:17`).
- x86 register mapping helpers are already shared
  (`module/include/kinsn_common.h:46`), and the module registration macro is
  `DEFINE_KINSN_V2_MODULE()` (`module/include/kinsn_common.h:124`).
- Each kinsn descriptor supplies `instantiate_insn` and an arch emitter, e.g.
  rotate at `module/x86/bpf_rotate.c:230` and select at
  `module/x86/bpf_select.c:148`.
- New x86 objects are listed in `module/x86/Makefile`
  (`module/x86/Makefile:8`). ARM64 mirrors the same module pattern and emitter
  callback shape (`module/arm64/bpf_rotate.c:171`).
- Existing pass YAML uses `log_level: 1`, a `kinsns:` list with `name` and
  `aliases`, and a daemon-substituted `bpfopt --pass ... --target ${TARGET}`
  command (`runner/config/passes/rotate/default.yaml:4`,
  `runner/config/passes/rotate/default.yaml:5`,
  `runner/config/passes/rotate/default.yaml:12`).

## Census method

I parsed every `canonicalize_output.bin` as little-endian `struct bpf_insn[]`.
The detector used the same byte layout as `BpfInsn::from_raw_bytes()`:
`code`, packed dst/src register byte, signed `off`, and signed `imm`
(`bpfopt/crates/bpfopt/src/insn.rs:323`).

Detected shapes:

```text
a: MOV dst, base; ADD dst, src
b: MOV dst, idx;  LSH dst, N; ADD dst, base                  N in {1,2,3}
c: MOV dst, idx;  LSH dst, N; ADD dst, base; ADD dst, imm    N in {1,2,3}
d: MOV dst, base; ADD dst, imm1; ADD dst, imm2; ...          >=2 imm adds
e: ADD dst, src1; ADD dst, src2                              broad signal only
```

Static filters:

- skipped any candidate with an interior branch target;
- skipped any candidate whose source registers included `r10`;
- required the overwritten temp `dst` not to be the later register-add source,
  so `MOV dst, base; ADD dst, dst` was not misclassified as `base + src`;
- for scaled-index forms, required `base != dst`, because the initial `MOV`
  clobbers `dst`;
- counted non-overlapping windows by priority `c`, `b`, `d`, `a`, then `e`;
- classified scalar/pointer/unknown with a small abstract interpreter. This is
  an estimate, not a verifier result. The committed noop reports do not contain
  verifier states; a production pass should use `ProgramCFG::reg_kind()`.

The classifier marks obvious scalar producers (`MOV imm`, ALU32, ordinary loads)
as scalar, obvious pointer producers (`r10`, `r1` context, map pseudo loads,
common map/ringbuf pointer-returning helpers, and ctx `data`/`data_end` loads)
as pointer, and branch-join-sensitive cases as unknown.

## Census result

Strict first-wave result: 13,321 non-overlapping sites across 5 apps. All strict
sites are pattern `a`. No pattern `b`, `c`, or `d` sites were present, even
before scalar/pointer filtering. Pattern `e` had 44 broad matches in Tetragon,
but none had duplicate sources and none is directly implementable as one
two-input LEA without extra value proof, so `e` is excluded from first-wave ROI.

| app | programs | insns | a | b | c | d | e strict | scalar | pointer | unknown | total | sites / 1k insn |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| bcc | 21 | 1,221 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0.00 |
| bpftrace | 9 | 1,020 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0.00 |
| cilium | 53 | 50,247 | 79 | 0 | 0 | 0 | 0 | 74 | 4 | 1 | 79 | 1.57 |
| katran | 1 | 2,542 | 4 | 0 | 0 | 0 | 0 | 0 | 4 | 0 | 4 | 1.57 |
| otel | 13 | 59,577 | 470 | 0 | 0 | 0 | 0 | 363 | 89 | 18 | 470 | 7.89 |
| tetragon | 287 | 407,908 | 6,363 | 0 | 0 | 0 | 0 | 4,843 | 831 | 689 | 6,363 | 15.60 |
| tracee | 158 | 424,159 | 6,405 | 0 | 0 | 0 | 0 | 5,642 | 510 | 253 | 6,405 | 15.10 |

Scalar-fusable estimate: 10,922 / 13,321 strict sites = 82.0%. The count spans
4 apps: cilium, otel, tetragon, and tracee. Tracee has the highest scalar count
(5,642); Tetragon has the highest density (15.60 strict sites per 1k insns).
Katran has only 4 strict runtime-testbin sites and all 4 look pointer-like under
the static classifier, despite the earlier native-C Katran signal of 152 `lea`
instructions.

Representative strict windows:

```text
bpfopt/testbin/cilium_agent/162_tail_nodeport_nat_egress_ipv4/canonicalize_output.bin @ pc 908
00908: mov32 r1, r9
00909: add32 r1, r6

bpfopt/testbin/katran/530_balancer_ingress/canonicalize_output.bin @ pc 414
00414: mov64 r4, r7
00415: add64 r4, r5

bpfopt/testbin/otelcol-ebpf-profiler_profiling/47_perf_unwind_php/canonicalize_output.bin @ pc 109
00109: mov64 r3, r6
00110: add64 r3, r1

bpfopt/testbin/tracee_monitor/595_trace_security_bprm_check/canonicalize_output.bin @ pc 72
00072: mov64 r3, r6
00073: add64 r3, r1
```

Representative broad-but-not-first-wave `e` window:

```text
bpfopt/testbin/tetragon_observer/245_generic_kprobe_filter_arg/canonicalize_output.bin @ pc 1920
01920: add64 r1, r3
01921: add64 r1, r2
```

That `e` form computes `old_r1 + r3 + r2`. x86 LEA has only base + index +
disp, so it cannot replace both adds unless the pass proves one operand is
already zero/equal or leaves one add in place. The first pass should not claim
these 44 sites.

Highest-density programs in the strict census:

| rank | app | program | strict sites | static split |
|---:|---|---|---:|---|
| 1 | tracee | `595_trace_security_bprm_check` | 231 | 190 scalar, 40 pointer, 1 unknown |
| 2 | tracee | `686_trace_security_task_prctl` | 216 | 134 scalar, 79 pointer, 3 unknown |
| 3 | tracee | `680_trace_execute_finished` | 196 | 193 scalar, 3 unknown |
| 4 | tracee | `585_trace_call_usermodehelper` | 190 | 185 scalar, 5 unknown |
| 5 | tracee | `701_tracepoint__exec_test` | 176 | 126 scalar, 40 pointer, 10 unknown |
| 6 | otel | `47_perf_unwind_php` | 95 | 57 scalar, 38 pointer |
| 7 | tetragon | `273_generic_retkprobe_event` | 89 | 75 scalar, 6 pointer, 8 unknown |

## Native asm vs BPF object census (testccode + testobject)

The first census above used only runtime `testbin` bytecode after
`canonicalize-map-refs`. The generated comparison corpus adds two different
views:

- `bpfopt/testccode/*.x86.s`: clang output when the same `.bpf.c` sources are
  compiled directly for x86, not for BPF;
- `bpfopt/testobject/*.o`: the corresponding BPF ELF objects, disassembled with
  `llvm-objdump -d` and scanned with the same bytecode patterns `a..e` used for
  `testbin`.

No loader, benchmark, or `bpfopt` pass was run for this section.

Inventory:

| app | stems | `.bpf.c` / `.c` | `.x86.s` | `.arm64.s` | `.bpf.o` / `.o` |
|---|---|---:|---:|---:|---:|
| bcc | `bcc_biosnoop`, `bcc_capable`, `bcc_opensnoop`, `bcc_runqlat`, `bcc_syscount`, `bcc_tcpconnect`, `bcc_tcplife`, `bcc_vfsstat` | 8 | 8 | 8 | 8 |
| bpftrace | `bpftrace_base`, `bpftrace_map_map`, `bpftrace_process_process`, `bpftrace_strings_strings`, `bpftrace_system_system`, `bpftrace_task_task`, `bpftrace_task_vma`, `bpftrace_test_test`, `bpftrace_usdt_usdt` | 9 | 9 | 9 | 9 |
| cilium | `cilium_bpf_alignchecker`, `cilium_bpf_host`, `cilium_bpf_lxc`, `cilium_bpf_overlay`, `cilium_bpf_sock`, `cilium_bpf_wireguard`, `cilium_bpf_xdp` | 7 | 7 | 7 | 7 |
| katran | `katran_balancer`, `katran_healthchecking`, `katran_healthchecking_ipip`, `katran_xdp_pktcntr`, `katran_xdp_root` | 5 | 5 | 5 | 5 |
| otel | `otel_generic_probe`, `otel_native_stack_trace`, `otel_sched_monitor` | 3 | 3 | 3 | 3 |
| tetragon | `tetragon_bpf_generic_kprobe`, `tetragon_bpf_generic_tracepoint` | 2 | 2 | 2 | 2 |
| tracee | `tracee_lsm_support_kprobe_check`, `tracee_lsm_support_lsm_check`, `tracee_tracee` | 3 | 3 | 3 | 3 |
| total | 37 program stems | 37 | 37 | 37 | 37 |

Extra support files in `testccode/`: `Makefile`, `mock_bpf_native.h`,
`native_shims/core_builtins.h`, and 27 app shim headers under
`native_shims/{bpftrace,cilium,tetragon,tracee}/`.

Native x86 LEA buckets:

- `simple`: `lea dst, [base + disp]`, including stack offsets and RIP-relative
  symbols;
- `scaled`: `lea dst, [base + index * scale]`;
- `scaled+disp`: `lea dst, [base + index * scale + disp]`;
- `reg-only`: `lea dst, [base + index]`;
- `other`: valid native LEA forms outside those four buckets, mostly no-base
  scaled forms such as `[4*rdi + 34]`.

Per-app native x86 result:

| app | `.x86.s` files | native `lea` | simple | scaled | scaled+disp | reg-only | other |
|---|---:|---:|---:|---:|---:|---:|---:|
| bcc | 8 | 285 | 279 | 0 | 0 | 6 | 0 |
| bpftrace | 9 | 20 | 19 | 0 | 0 | 1 | 0 |
| cilium | 7 | 1,796 | 1,761 | 0 | 0 | 25 | 10 |
| katran | 5 | 225 | 221 | 2 | 0 | 2 | 0 |
| otel | 3 | 359 | 323 | 2 | 0 | 32 | 2 |
| tetragon | 2 | 2,841 | 2,582 | 30 | 0 | 185 | 44 |
| tracee | 3 | 36,627 | 31,806 | 87 | 0 | 4,729 | 5 |
| total | 37 | 42,153 | 36,991 | 121 | 0 | 4,980 | 61 |

Per-file native x86 result:

| file | app | native `lea` | simple | scaled | scaled+disp | reg-only | other |
|---|---|---:|---:|---:|---:|---:|---:|
| `bcc_biosnoop.bpf.x86.s` | bcc | 41 | 41 | 0 | 0 | 0 | 0 |
| `bcc_capable.bpf.x86.s` | bcc | 21 | 21 | 0 | 0 | 0 | 0 |
| `bcc_opensnoop.bpf.x86.s` | bcc | 70 | 67 | 0 | 0 | 3 | 0 |
| `bcc_runqlat.bpf.x86.s` | bcc | 46 | 45 | 0 | 0 | 1 | 0 |
| `bcc_syscount.bpf.x86.s` | bcc | 17 | 17 | 0 | 0 | 0 | 0 |
| `bcc_tcpconnect.bpf.x86.s` | bcc | 52 | 52 | 0 | 0 | 0 | 0 |
| `bcc_tcplife.bpf.x86.s` | bcc | 38 | 36 | 0 | 0 | 2 | 0 |
| `bcc_vfsstat.bpf.x86.s` | bcc | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_base.bpf.x86.s` | bpftrace | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_map_map.bpf.x86.s` | bpftrace | 1 | 1 | 0 | 0 | 0 | 0 |
| `bpftrace_process_process.bpf.x86.s` | bpftrace | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_strings_strings.bpf.x86.s` | bpftrace | 4 | 3 | 0 | 0 | 1 | 0 |
| `bpftrace_system_system.bpf.x86.s` | bpftrace | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_task_task.bpf.x86.s` | bpftrace | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_task_vma.bpf.x86.s` | bpftrace | 4 | 4 | 0 | 0 | 0 | 0 |
| `bpftrace_test_test.bpf.x86.s` | bpftrace | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_usdt_usdt.bpf.x86.s` | bpftrace | 11 | 11 | 0 | 0 | 0 | 0 |
| `cilium_bpf_alignchecker.bpf.x86.s` | cilium | 164 | 162 | 0 | 0 | 2 | 0 |
| `cilium_bpf_host.bpf.x86.s` | cilium | 681 | 673 | 0 | 0 | 8 | 0 |
| `cilium_bpf_lxc.bpf.x86.s` | cilium | 460 | 454 | 0 | 0 | 2 | 4 |
| `cilium_bpf_overlay.bpf.x86.s` | cilium | 219 | 215 | 0 | 0 | 2 | 2 |
| `cilium_bpf_sock.bpf.x86.s` | cilium | 0 | 0 | 0 | 0 | 0 | 0 |
| `cilium_bpf_wireguard.bpf.x86.s` | cilium | 222 | 218 | 0 | 0 | 2 | 2 |
| `cilium_bpf_xdp.bpf.x86.s` | cilium | 50 | 39 | 0 | 0 | 9 | 2 |
| `katran_balancer.bpf.x86.s` | katran | 180 | 176 | 2 | 0 | 2 | 0 |
| `katran_healthchecking.bpf.x86.s` | katran | 32 | 32 | 0 | 0 | 0 | 0 |
| `katran_healthchecking_ipip.bpf.x86.s` | katran | 9 | 9 | 0 | 0 | 0 | 0 |
| `katran_xdp_pktcntr.bpf.x86.s` | katran | 3 | 3 | 0 | 0 | 0 | 0 |
| `katran_xdp_root.bpf.x86.s` | katran | 1 | 1 | 0 | 0 | 0 | 0 |
| `otel_generic_probe.bpf.x86.s` | otel | 50 | 49 | 0 | 0 | 0 | 1 |
| `otel_native_stack_trace.bpf.x86.s` | otel | 275 | 240 | 2 | 0 | 32 | 1 |
| `otel_sched_monitor.bpf.x86.s` | otel | 34 | 34 | 0 | 0 | 0 | 0 |
| `tetragon_bpf_generic_kprobe.x86.s` | tetragon | 1,611 | 1,446 | 15 | 0 | 127 | 23 |
| `tetragon_bpf_generic_tracepoint.x86.s` | tetragon | 1,230 | 1,136 | 15 | 0 | 58 | 21 |
| `tracee_lsm_support_kprobe_check.bpf.x86.s` | tracee | 3 | 3 | 0 | 0 | 0 | 0 |
| `tracee_lsm_support_lsm_check.bpf.x86.s` | tracee | 3 | 3 | 0 | 0 | 0 | 0 |
| `tracee_tracee.bpf.x86.s` | tracee | 36,621 | 31,800 | 87 | 0 | 4,729 | 5 |

Representative native LEA sites:

| app | examples |
|---|---|
| bcc | `bcc_biosnoop.bpf.x86.s:16 lea rdi, [rip + cgroup_map]`; `bcc_biosnoop.bpf.x86.s:30 lea rbx, [rsp + 16]`; `bcc_runqlat.bpf.x86.s:376 lea rdx, [r12 + rax]` |
| bpftrace | `bpftrace_map_map.bpf.x86.s:34 lea rsi, [rip + __empty_map_elem_cb]`; `bpftrace_strings_strings.bpf.x86.s:73 lea rbx, [r8 + r10]`; `bpftrace_task_vma.bpf.x86.s:27 lea rdi, [rsp + 8]` |
| cilium | `cilium_bpf_alignchecker.bpf.x86.s:50 lea rdx, [rsp + 56]`; `cilium_bpf_alignchecker.bpf.x86.s:61 lea esi, [r14 + 6]`; `cilium_bpf_xdp.bpf.x86.s:394 lea edi, [4*rdi + 34]` |
| katran | `katran_balancer.bpf.x86.s:28 lea rax, [r15 + 14]`; `katran_balancer.bpf.x86.s:35 lea rdi, [rip + stats]`; `katran_balancer.bpf.x86.s:565 lea eax, [rsi + 4*rax]` |
| otel | `otel_generic_probe.bpf.x86.s:46 lea rsi, [rsp + 80]`; `otel_generic_probe.bpf.x86.s:77 lea rdi, [r14 + 16]`; `otel_native_stack_trace.bpf.x86.s:1599 lea r15, [rax + 8*rdx]` |
| tetragon | `tetragon_bpf_generic_kprobe.x86.s:18 lea rdi, [rip + process_call_heap]`; `tetragon_bpf_generic_kprobe.x86.s:26 lea rsi, [rax + 24296]`; `tetragon_bpf_generic_tracepoint.x86.s:2116 lea rdx, [r12 + 8*r13]` |
| tracee | `tracee_tracee.bpf.x86.s:12 lea rax, [rdi + r8]`; `tracee_tracee.bpf.x86.s:50 lea ecx, [rcx + 4*rcx]`; `tracee_tracee.bpf.x86.s:275 lea rdi, [rsp + 4]` |

BPF object detector:

- disassembled every `bpfopt/testobject/*.o` with `llvm-objdump -d`;
- split detection by ELF text section;
- parsed raw BPF instruction bytes from objdump output;
- skipped any candidate with an interior branch target;
- skipped source `r10`;
- counted non-overlapping windows by priority `c`, `b`, `d`, `a`, then broad
  signal `e`;
- treated strict foldable total as `a + b + c + d`; `e` remains broad signal
  only and is not included in ROI.

Per-app BPF object result:

| app | object files | BPF insns | a | b | c | d | e broad | strict total |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| bcc | 8 | 2,913 | 36 | 0 | 0 | 0 | 0 | 36 |
| bpftrace | 9 | 798 | 10 | 0 | 0 | 0 | 0 | 10 |
| cilium | 7 | 217,663 | 440 | 0 | 0 | 0 | 2 | 440 |
| katran | 5 | 3,009 | 4 | 0 | 0 | 0 | 0 | 4 |
| otel | 3 | 6,058 | 8 | 0 | 0 | 0 | 0 | 8 |
| tetragon | 2 | 37,018 | 1,169 | 4 | 0 | 0 | 0 | 1,173 |
| tracee | 3 | 435,373 | 5,328 | 0 | 0 | 0 | 14 | 5,328 |
| total | 37 | 702,832 | 6,995 | 4 | 0 | 0 | 16 | 6,999 |

Per-file BPF object result:

| file | app | BPF insns | a | b | c | d | e broad | strict total |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| `bcc_biosnoop.bpf.o` | bcc | 559 | 4 | 0 | 0 | 0 | 0 | 4 |
| `bcc_capable.bpf.o` | bcc | 180 | 0 | 0 | 0 | 0 | 0 | 0 |
| `bcc_opensnoop.bpf.o` | bcc | 787 | 3 | 0 | 0 | 0 | 0 | 3 |
| `bcc_runqlat.bpf.o` | bcc | 422 | 8 | 0 | 0 | 0 | 0 | 8 |
| `bcc_syscount.bpf.o` | bcc | 151 | 0 | 0 | 0 | 0 | 0 | 0 |
| `bcc_tcpconnect.bpf.o` | bcc | 409 | 8 | 0 | 0 | 0 | 0 | 8 |
| `bcc_tcplife.bpf.o` | bcc | 309 | 13 | 0 | 0 | 0 | 0 | 13 |
| `bcc_vfsstat.bpf.o` | bcc | 96 | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_base.bpf.o` | bpftrace | 26 | 2 | 0 | 0 | 0 | 0 | 2 |
| `bpftrace_map_map.bpf.o` | bpftrace | 17 | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_process_process.bpf.o` | bpftrace | 4 | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_strings_strings.bpf.o` | bpftrace | 354 | 5 | 0 | 0 | 0 | 0 | 5 |
| `bpftrace_system_system.bpf.o` | bpftrace | 6 | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_task_task.bpf.o` | bpftrace | 149 | 1 | 0 | 0 | 0 | 0 | 1 |
| `bpftrace_task_vma.bpf.o` | bpftrace | 40 | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_test_test.bpf.o` | bpftrace | 2 | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace_usdt_usdt.bpf.o` | bpftrace | 200 | 2 | 0 | 0 | 0 | 0 | 2 |
| `cilium_bpf_alignchecker.bpf.o` | cilium | 1,117 | 0 | 0 | 0 | 0 | 0 | 0 |
| `cilium_bpf_host.bpf.o` | cilium | 68,955 | 130 | 0 | 0 | 0 | 1 | 130 |
| `cilium_bpf_lxc.bpf.o` | cilium | 53,856 | 57 | 0 | 0 | 0 | 1 | 57 |
| `cilium_bpf_overlay.bpf.o` | cilium | 30,950 | 89 | 0 | 0 | 0 | 0 | 89 |
| `cilium_bpf_sock.bpf.o` | cilium | 5,166 | 0 | 0 | 0 | 0 | 0 | 0 |
| `cilium_bpf_wireguard.bpf.o` | cilium | 27,221 | 44 | 0 | 0 | 0 | 0 | 44 |
| `cilium_bpf_xdp.bpf.o` | cilium | 30,398 | 120 | 0 | 0 | 0 | 0 | 120 |
| `katran_balancer.bpf.o` | katran | 2,542 | 4 | 0 | 0 | 0 | 0 | 4 |
| `katran_healthchecking.bpf.o` | katran | 325 | 0 | 0 | 0 | 0 | 0 | 0 |
| `katran_healthchecking_ipip.bpf.o` | katran | 103 | 0 | 0 | 0 | 0 | 0 | 0 |
| `katran_xdp_pktcntr.bpf.o` | katran | 22 | 0 | 0 | 0 | 0 | 0 | 0 |
| `katran_xdp_root.bpf.o` | katran | 17 | 0 | 0 | 0 | 0 | 0 | 0 |
| `otel_generic_probe.bpf.o` | otel | 1,166 | 0 | 0 | 0 | 0 | 0 | 0 |
| `otel_native_stack_trace.bpf.o` | otel | 4,326 | 8 | 0 | 0 | 0 | 0 | 8 |
| `otel_sched_monitor.bpf.o` | otel | 566 | 0 | 0 | 0 | 0 | 0 | 0 |
| `tetragon_bpf_generic_kprobe.o` | tetragon | 19,426 | 665 | 2 | 0 | 0 | 0 | 667 |
| `tetragon_bpf_generic_tracepoint.o` | tetragon | 17,592 | 504 | 2 | 0 | 0 | 0 | 506 |
| `tracee_lsm_support_kprobe_check.bpf.o` | tracee | 14 | 0 | 0 | 0 | 0 | 0 | 0 |
| `tracee_lsm_support_lsm_check.bpf.o` | tracee | 14 | 0 | 0 | 0 | 0 | 0 | 0 |
| `tracee_tracee.bpf.o` | tracee | 435,345 | 5,328 | 0 | 0 | 0 | 14 | 5,328 |

Representative BPF object foldable sites:

| app | examples |
|---|---|
| bcc | `bcc_biosnoop.bpf.o tp_btf/block_rq_insert pc 75: r3 = r7; r3 += r1`; `bcc_runqlat.bpf.o .text pc 14: r3 = r7; r3 += r1` |
| bpftrace | `bpftrace_base.bpf.o .text pc 13: r0 = r1; r0 += r4`; `bpftrace_strings_strings.bpf.o .text pc 6: r4 = r1; r4 += r3` |
| cilium | `cilium_bpf_host.bpf.o .text pc 3315: w2 = w7; w2 += w8`; `cilium_bpf_host.bpf.o tc/tail pc 1479: r4 = r1; r4 += r3` |
| katran | `katran_balancer.bpf.o xdp pc 414: r4 = r7; r4 += r5`; `katran_balancer.bpf.o xdp pc 442: r3 = r7; r3 += r4` |
| otel | `otel_native_stack_trace.bpf.o perf_event/unwind_native pc 128: r2 = r7; r2 += r1`; `otel_native_stack_trace.bpf.o perf_event/unwind_native pc 341: r7 = r8; r7 += r1` |
| tetragon | `tetragon_bpf_generic_kprobe.o kprobe pc 31: r3 = r9; r3 += r1`; `tetragon_bpf_generic_kprobe.o kprobe pc 40: r3 = r9; r3 += r1` |
| tracee | `tracee_tracee.bpf.o .text pc 14: r0 = r1; r0 += r3`; `tracee_tracee.bpf.o raw_tracepoint/sys_enter_init pc 73: r3 = r7; r3 += r9` |

Per-app native-vs-BPF comparison:

| app | native `lea` | BPF object strict | BPF/native | runtime testbin strict |
|---|---:|---:|---:|---:|
| bcc | 285 | 36 | 12.6% | 0 |
| bpftrace | 20 | 10 | 50.0% | 0 |
| cilium | 1,796 | 440 | 24.5% | 79 |
| katran | 225 | 4 | 1.8% | 4 |
| otel | 359 | 8 | 2.2% | 470 |
| tetragon | 2,841 | 1,173 | 41.3% | 6,363 |
| tracee | 36,627 | 5,328 | 14.5% | 6,405 |
| total | 42,153 | 6,999 | 16.6% | 13,321 |

Interpretation:

- Native x86 LEA count is real and much larger than BPF foldable count, but it
  is mostly not evidence for a BPF-level LEA kinsn. The dominant native bucket is
  simple base+disp address materialization: 36,991 / 42,153 native LEAs.
- The BPF object corpus confirms the runtime-testbin shape: strict BPF foldable
  sites are almost entirely plain `MOV dst, base; ADD dst, src`. In
  `testobject`, 6,995 / 6,999 strict sites are pattern `a`; only 4 are scaled
  pattern `b`; `c` scaled+disp and `d` add-imm-chain remain zero.
- Files with native LEA but no BPF strict site include
  `cilium_bpf_alignchecker` (164 native), `otel_generic_probe` (50),
  `otel_sched_monitor` (34), `katran_healthchecking` (32), `bcc_capable` (21),
  `bcc_syscount` (17), `katran_healthchecking_ipip` (9),
  `tracee_lsm_support_{kprobe,lsm}_check` (3 each), `katran_xdp_pktcntr` (3),
  and `katran_xdp_root` (1). Those LEAs are native address-mode artifacts or
  native codegen choices that are not expressed as foldable BPF ALU windows.
- Files with BPF strict sites but zero native LEA are rare:
  `bpftrace_base` has 2 BPF strict sites and `bpftrace_task_task` has 1. These
  are cases where the BPF object contains `MOV+ADD`, but x86 native compilation
  of the C source did not choose a visible `lea` instruction.

Katran-specific result:

- Actual `testccode` Katran native x86 count is 225, not the earlier 152 claim:
  `katran_balancer` 180, `katran_healthchecking` 32,
  `katran_healthchecking_ipip` 9, `katran_xdp_pktcntr` 3, and
  `katran_xdp_root` 1.
- Katran native modes are 221 simple base+disp, 2 scaled, 2 register-only, and
  0 scaled+disp.
- Katran BPF object strict count is 4, all in `katran_balancer.bpf.o`, matching
  the 4 runtime-testbin sites from `530_balancer_ingress`.
- Therefore Katran's native LEA richness is almost entirely x86 address-mode
  materialization, not arithmetic that survived into BPF bytecode. A BPF
  `bpf_lea` kinsn would not capture the Katran gap that motivated this check.

Revised design implication: the kinsn design below is retained as a concrete
sketch, but the combined evidence no longer justifies implementing it as a
first-wave `bpfopt` pass. A core kernel-JIT peephole would be the technically
direct lowering for adjacent verified BPF `MOV+ADD`, but that is not the
preferred engineering path for this project: kinsn exists to avoid editing the
core kernel JIT. Under that no-core-JIT-change policy, the actionable conclusion
is to defer LEA rather than to pursue a kernel peephole. If the kinsn route is
revived, treat it as a narrow scalar-only experiment with lower priority than
endian MOVBE and compare-select.

## Design: kernel kinsn

Use the existing packed sidecar ABI. The C-visible kfunc stubs should follow
the current module convention:

```c
__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_lea64(void) {}
__bpf_kfunc void bpf_lea32(void) {}
__bpf_kfunc_end_defs();
```

Semantic operation:

```text
dst = base + (has_index ? index << scale_log2 : 0) + disp
```

Payload layout:

```text
bits  0..3   dst_reg
bits  4..7   base_reg
bits  8..11  index_reg        ignored when has_index == 0
bits 12..13  scale_log2       0,1,2,3 maps to x86 SIB scale 1,2,4,8
bit      14  has_index
bit      15  reserved, must be 0
bits 16..47  disp_s32
bits 48..51  reserved, must be 0
```

Register validation:

- `dst`, `base`, and `index` must be `<= BPF_REG_10`;
- first-wave bpfopt should not emit any source `r10`;
- first-wave bpfopt should require `dst != base` and `dst != index` for the
  scaled forms so the verifier instantiation can use `dst` as its temporary;
- the module can support `base == index`, which encodes useful `base + base*2`
  style LEA forms.

Verifier instantiation:

```text
has_index=1, scale=0, disp=0:
    MOV{32,64} dst, base
    ADD{32,64} dst, index

has_index=1, scale>0:
    MOV{32,64} dst, index
    LSH{32,64} dst, scale_log2
    ADD{32,64} dst, base
    optional ADD{32,64} dst, disp

has_index=0:
    MOV{32,64} dst, base
    optional ADD{32,64} dst, disp
```

This preserves verifier-visible scalar math. Pointer LEA is intentionally out of
the first bpfopt pass, even though exact instantiation could model it later.

x86 emitter:

```text
lea r64_dst, [base + index * (1 << scale_log2) + disp32]
lea r32_dst, [base + index * (1 << scale_log2) + disp32]
```

Use SIB form unconditionally. The shared x86 register map has no BPF register
whose low x86 code is `rsp` as an index, so the SIB index field is available.
For `has_index=0`, emit SIB index `100b` with REX.X clear. For base registers
whose x86 code is `101b` (`r7`/`r10` in the shared mapping), force at least a
disp8 of 0 so the encoding is base-relative, not RIP/no-base.

ARM64 emitter:

```text
add xD, xBase, xIndex, lsl #N
add wD, wBase, wIndex, lsl #N
optional add/sub immediate for disp
```

For the current corpus first wave, `disp == 0` for every strict site. If future
`c`/`d` sites appear, arm64 should either emit only immediate values encodable by
ADD/SUB immediate or return `-EINVAL`; bpfopt can also skip non-encodable ARM64
displacements once target-specific admission exists.

If the superseded kinsn route is revived, `bpf_lea32` should travel with
`bpf_lea64`. Only 63 runtime-testbin strict sites are ALU32 today, all in
Cilium, but ALU32 semantics are clean: x86 `lea r32, [...]` wraps to 32 bits and
zero-extends, matching BPF ALU32 destination semantics.

## Design: bpfopt pass

New file: `bpfopt/crates/bpfopt/src/passes/lea.rs`.

Registry wiring:

```rust
mod lea;

pass_entry!("lea", lea::LeaPass, lea::KINSN_TARGETS, true)
```

`needs_verifier_states=true` is intentional for the first implementation because
the pass should admit scalar-only sites. This means the pass YAML should mirror
`bulk_memory` by passing `${VERIFIER_STATES}`.

Kinsn descriptors:

```rust
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor { name: "bpf_lea64", register_uses: lea_register_uses },
    KinsnDescriptor { name: "bpf_lea32", register_uses: lea_register_uses },
];

fn lea_register_uses(payload: u64) -> RegSet {
    let mut regs = regs_from_offsets(payload, &[0, 4]); // dst + base, matching existing conservative convention
    if ((payload >> 14) & 1) != 0 {
        regs.insert(kinsn_payload_reg(payload, 8));
    }
    regs
}
```

Scan:

- call `prog.branch_target_entry_sites()?` once;
- scan block starts with max lookahead 4;
- match `c`, `b`, `d`, then `a`; do not implement broad `e` in v1;
- reject an interior branch target exactly as `wide_mem` does;
- reject any source `r10`;
- require `prog.reg_kind(start, base) == Some(RegKind::Scalar)` and, when
  present, `prog.reg_kind(start, index) == Some(RegKind::Scalar)`;
- reject `Unknown` instead of guessing;
- require `dst != base` and `dst != index` for scaled forms;
- no scratch register is needed with the sidecar ABI.

Replacement:

```rust
let target = if site.width == LeaWidth::W64 { "bpf_lea64" } else { "bpf_lea32" };
let (btf_id, kfunc_off) = prog.kinsn_call(target)?;
let payload = BpfInsn::pack_u4(site.dst_reg, 0)
    | BpfInsn::pack_u4(site.base_reg, 4)
    | BpfInsn::pack_u4(site.index_reg.unwrap_or(0), 8)
    | (((site.scale_log2 as u64) & 0x3) << 12)
    | ((site.index_reg.is_some() as u64) << 14)
    | BpfInsn::pack_u32(site.disp as u32, 16);
emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off)
```

Dominant v1 rewrite examples:

```text
mov64 r3, r6
add64 r3, r1

=> sidecar(dst=r3, base=r6, index=r1, scale=0, disp=0), call bpf_lea64
=> x86: lea r3_native, [r6_native + r1_native]
```

The current packed call uses 2 BPF instruction slots, so the dominant 2-insn
pattern does not reduce `bytes_xlated`. The ROI is native instruction count and
JIT code quality: one x86 LEA instead of native mov+add. If future `b`/`c`/`d`
sites appear, those would also reduce BPF instruction slots.

## Archived pass YAML

Not recommended after the native-vs-BPF census. This is retained only as the
pass config shape that the superseded kinsn route would have used:

```yaml
# Default per-pass step config for lea.
# Read by runner/libs/pass_config.py at execute_plan build time.
# Daemon substitutes ${...} vars; runner sends this command verbatim.
log_level: 1
kinsns:
  - name: bpf_lea64
    aliases:
      - bpf_lea64
  - name: bpf_lea32
    aliases:
      - bpf_lea32
command: |
  timeout 6000 bpfopt --pass lea --input ${INPUT} --output ${OUTPUT} --report ${REPORT} --prog-type ${PROG_TYPE} --target ${TARGET} --verifier-states ${VERIFIER_STATES}
```

## Archived verification plan

If the superseded bpfopt kinsn route is revived, unit tests in `lea_tests.rs`
should cover:

- `MOV64 + ADD64 reg` -> `bpf_lea64`;
- `MOV32 + ADD32 reg` -> `bpf_lea32`;
- scaled `MOV + LSH 1/2/3 + ADD`;
- scaled plus displacement;
- add-imm chain with displacement folding;
- skip when an interior instruction is a branch target;
- skip when source is `r10`;
- skip when base/index reg kind is pointer or unknown;
- skip broad `ADD dst, src1; ADD dst, src2`;
- payload ABI: exact bit offsets for dst/base/index/scale/has_index/disp.

Host-side testbin checks, without running benchmarks:

```sh
target/debug/bpfopt --pass lea \
  --input bpfopt/testbin/tracee_monitor/595_trace_security_bprm_check/canonicalize_output.bin \
  --output /tmp/lea_tracee.bin \
  --report /tmp/lea_tracee.json \
  --prog-type <prog_type> \
  --target <target.json> \
  --verifier-states <verifier-states.json>

target/debug/bpfopt --pass lea \
  --input bpfopt/testbin/katran/530_balancer_ingress/canonicalize_output.bin \
  --output /tmp/lea_katran.bin \
  --report /tmp/lea_katran.json \
  --prog-type <prog_type> \
  --target <target.json> \
  --verifier-states <verifier-states.json>
```

There is no bpfopt `lea` benchmark plan after this revision. Under the current
no-core-JIT-change policy, do not replace it with a kernel-JIT peephole
benchmark plan. Revisit only if LEA becomes a deliberate low-priority
kinsn-only experiment.

## ROI interpretation

Native-C evidence remains useful as an upper-bound gap signal, but it no longer
supports a BPF-level `bpf_lea` kinsn proposal. Across `testccode`, clang emits
42,153 native x86 `lea` instructions. Only 6,999 strict foldable sites are
present in the matching BPF objects, and the runtime-testbin strict count is
13,321. The native-vs-BPF object ratio is 16.6% overall.

The mismatch is structural:

- Native x86 LEA is dominated by address materialization and x86 addressing
  modes: 36,991 / 42,153 native sites are simple base+disp forms.
- The BPF bytecode opportunity is not the architectural full SIB form. In
  `testobject`, `c` scaled+disp and `d` add-imm-chain are both 0; the whole
  strict signal is 6,995 plain `MOV+ADD` sites plus 4 scaled `b` sites in
  Tetragon.
- The previous runtime-testbin census agrees on shape: all 13,321 strict sites
  are pattern `a`; scaled-index, scaled+disp, and add-imm-chain are 0.
- Katran specifically has 225 native `lea` instructions in `testccode` but only
  4 strict BPF object/runtime sites. That is a 1.8% BPF/native ratio, and the 4
  runtime sites were pointer-like in the static classifier. The native Katran
  signal is therefore not recoverable through a BPF `lea` bytecode rewrite.

Expected effect if implemented as the kinsn design above:

- Up to 10,922 static-scalar runtime-testbin pattern-`a` sites might become one
  native LEA each, if verifier states prove both operands scalar.
- 13,321 total runtime-testbin strict sites exist if pointer/unknown support were
  admitted later with verifier-equivalent semantics.
- The dominant 2-insn `MOV+ADD` pattern would still use 2 BPF instruction slots
  under the packed sidecar ABI, so there is no bytecode-size reduction.
- The implementation would require a new kinsn module, a verifier-state-gated
  bpfopt pass, pass YAML, and tests to get only a one-native-instruction
  lowering for the dominant 2-slot bytecode pattern.

Recommendation: do not implement `bpf_lea64` / `bpf_lea32` as a bpfopt kinsn
pass in the current optimization queue. Also do not recommend a core kernel-JIT
peephole under the project's no-core-JIT-change constraint. The practical action
is to defer LEA and spend implementation effort on cleaner kinsn-native gaps
such as endian MOVBE emission and compare-select.

ROI summary: `testobject` has 6,999 strict BPF sites across all 7 apps
(BPF/native 16.6%); `testbin` has 13,321 strict runtime sites but no scaled+disp
or add-imm-chain sites; Katran has 225 native `lea` but only 4 BPF strict sites.
Revised verdict: defer/no-action for now. No core kernel-JIT peephole; kinsn
route remains possible but low ROI and not first-wave.
