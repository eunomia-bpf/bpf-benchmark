# BpfReJIT: Research Progress Report

**Project**: BpfReJIT: Safe Post-Load JIT Specialization for Kernel eBPF  
**Target**: OSDI '26  
**Date**: 2026-03-12  
**Prepared for**: Principal Investigator

---

## 1. Executive Summary

BpfReJIT separates safety from optimization in the Linux kernel's eBPF JIT compiler. The correct deployment model has three fully decoupled components: (A) unmodified applications such as bpftrace, Cilium, Tetragon, and Tracee load BPF programs exactly as they do today; (B) a privileged userspace BpfReJIT daemon enumerates already-loaded programs, extracts both post-verifier BPF bytecode and JIT-compiled native code, analyzes the live kernel state, and decides which optimization directives to apply; (C) the kernel validates those directives and re-JITs using only kernel-owned canonical forms. No custom BPF loader is required, and no `.bpf.o` artifact is required at deployment time.

The current prototype fully implements post-load re-JIT on x86-64, eight canonical optimization families, a standalone scanner/policy compiler, and end-to-end live validation on Tracee, Tetragon, bpftrace, XDP, and scx_rusty census mode. Headline results remain: characterization gap 0.609x (LLVM JIT 39% faster than stock kernel), micro code-size reduction 0.496x, fixed-policy kernel-recompile geomean 1.007x overall on 56 pure-JIT microbenchmarks, corpus packet-test geomeans of 0.868x blind / 0.898x tuned v1 / 0.875x fixed v2, tracing-corpus geomean 1.003x overall / 1.019x applied-only, Tracee `exec_storm` throughput +21.65%, Tetragon app throughput +3.8%, and XDP forwarding 1.003x PPS. The remaining userspace systems step is to consolidate the existing live scanner/apply logic into a resident daemon and extend it to consume JITed native-code bytes as first-class analysis input.

---

## 2. Correct Architecture

### 2.1 Core Insight

The eBPF kernel JIT must be conservative: every instruction-selection decision is hardcoded because a code-generation bug equals a kernel crash. This couples two concerns that should be separate:

- **Kernel safety plane**: defines bounded safe native-code variants, validates candidate rewrites against canonical forms, and fail-closes to stock emission on any validation failure. The kernel never executes userspace-provided code.
- **Userspace optimization plane**: observes workload, CPU, deployment, verified BPF bytecode, and existing native code, then chooses which legal variants should be activated.

This is analogous to how Exokernel separated protection from resource management, or how `sched_ext` separates scheduling mechanism from scheduling policy. BpfReJIT separates JIT safety from JIT optimization policy.

### 2.2 Three Decoupled Components

The correct steady-state architecture is:

1. **Component A: Original application / loader**
   Applications remain completely unchanged. They call `BPF_PROG_LOAD` through libbpf, bpftool, or their own existing runtime exactly as they do today.
2. **Component B: BpfReJIT daemon**
   A separate privileged userspace daemon enumerates loaded BPF programs, opens program FDs, extracts verified BPF bytecode and JITed native code, analyzes both views, generates directives, and issues recompile requests.
3. **Component C: Kernel recompile mechanism**
   The kernel receives a sealed directive blob through `BPF_PROG_JIT_RECOMPILE`, validates it against kernel-owned canonical forms, and re-JITs the target program with fail-closed fallback.

The application never calls a BpfReJIT-specific loader path. The daemon operates after load, against live kernel state.

### 2.3 End-to-End Architecture

```text
Component A: Unmodified Application
  bpftrace / cilium-agent / tetragon / tracee / xdp loader / ...
              |
              | normal BPF_PROG_LOAD
              v
  +-------------------------------------------------------------+
  | Kernel-loaded BPF program                                   |
  | - prog_id / prog_fd / prog_tag                              |
  | - verified BPF bytecode (xlated_prog_insns)                 |
  | - JITed native image (jited_prog_insns)                     |
  +-------------------------------------------------------------+
              ^                                    |
              | enumerate + inspect                | BPF_PROG_JIT_RECOMPILE
              |                                    v
  +-------------------------------------------------------------+
  | Component B: BpfReJIT daemon                                |
  | - discover loaded programs                                  |
  | - fetch bpf_prog_info                                       |
  | - extract xlated BPF + JITed native code                    |
  | - analyze both representations                              |
  | - select live optimization sites                            |
  | - build sealed directive blob                               |
  +-------------------------------------------------------------+
                                                   |
                                                   v
  +-------------------------------------------------------------+
  | Component C: Kernel recompile mechanism                     |
  | - parse and validate directives                             |
  | - enforce digest / arch / CPU-feature checks                |
  | - emit only kernel-owned safe variants                      |
  | - fail closed to stock emission on any error                |
  +-------------------------------------------------------------+
```

Daemon-internal control flow:

```text
program enumeration
   -> program metadata snapshot
   -> xlated bytecode fetch
   -> JITed image fetch
   -> site discovery + profitability policy
   -> directive selection
   -> sealed memfd blob
   -> BPF_PROG_JIT_RECOMPILE
   -> optional post-reJIT verification / metrics collection
```

### 2.4 Live Kernel Introspection Surface

The daemon can be built from existing kernel-facing primitives that are already exposed to userspace:

- `BPF_PROG_GET_NEXT_ID` or `bpftool prog show` for enumeration of loaded programs.
- `BPF_PROG_GET_FD_BY_ID` / `bpf_prog_get_fd_by_id()` to open a live program by ID.
- `BPF_OBJ_GET_INFO_BY_FD` to read `struct bpf_prog_info`, including `id`, `tag`, `name`, `jited_prog_len`, `xlated_prog_len`, `jited_prog_insns`, `xlated_prog_insns`, `run_time_ns`, and `run_cnt`.
- `bpftool prog dump xlated` and `bpftool prog dump jited` as proof that both representations are already inspectable from userspace.
- `BPF_PROG_JIT_RECOMPILE` as the application-independent control path for post-load specialization.

This means the missing piece is not kernel visibility; it is daemon packaging and daemon-side analysis logic.

### 2.5 Eight Canonical Forms

Each canonical form represents a bounded set of safe native-code emission alternatives that the kernel can select between:

| Canonical Form | Description | Corpus Sites |
|---|---|---:|
| **COND_SELECT** | `jcc+mov` diamond/compact to `cmovcc` (policy-sensitive: profitability depends on branch predictability) | 446 |
| **WIDE_MEM** | Consecutive byte loads recomposed into single wide `mov` (50.7% of kernel instruction surplus) | 2,987 |
| **ROTATE** | `shift+or` patterns replaced with `rorx`/`ror` (BMI2 CPU-gated) | 2,685 |
| **ADDR_CALC** | `mov+shl+add` replaced with `lea` addressing mode | 19 |
| **BITFIELD_EXTRACT** | `shift+mask` replaced with `bextr`/optimized sequence (Cilium high-frequency) | 557 |
| **ZERO_EXT_ELIDE** | Redundant 32-bit zero-extension elided (x86-64 native; prepared for RISC-V/ARM64) | 0 (x86) |
| **ENDIAN_FUSION** | `ldx+bswap` / `bswap+stx` fused to `movbe` (MOVBE CPU-gated) | 1,386 |
| **BRANCH_FLIP** | Local if/else body swap (policy-sensitive: optimal branch falls through depends on workload) | 2,279 |

Total corpus site census: **17,637 sites** across 220/627 scanned objects.

### 2.6 Policy Model

The policy abstraction should be understood as a daemon output, not an application input. In steady-state deployment:

- The daemon discovers live sites from already-loaded programs.
- The daemon decides which sites to activate based on CPU, workload, deployment policy, and the current native image.
- The daemon may keep those decisions in memory or persist them for auditability.

For experimental reproducibility, the current repository persists those decisions as version 3 YAML snapshots. The v3 format remains appropriate because it matches live site discovery directly:

- **v1**: family allowlists with implicit defaults (deprecated, removed)
- **v2**: `default` + `families` + per-site overrides with `action` (deprecated)
- **v3 (current)**: explicit per-site directive list; presence means apply, absence means skip

Example persisted directive snapshot for a live Calico program:

```yaml
version: 3
program: 'calico_tc_main'
sites:
  - insn: 424
    family: endian
    pattern_kind: 'endian-load-swap-32'
  - insn: 1180
    family: wide
    pattern_kind: 'wide-load-2'
  - insn: 4196
    family: extract
    pattern_kind: 'bitfield-extract-64-mask-shift'
```

In this specific program, the live snapshot contains 66 selected sites out of 86 discovered; all 20 CMOV sites are skipped by policy.

### 2.7 Interface and Usage

The correct user-facing workflow is daemon-first:

**Step 1: Start the daemon**

```bash
$ sudo ./bpf-rejitd --families all --poll-ms 1000 --log-level info
[info] BpfReJIT daemon started
[info] watching loaded BPF programs
```

**Step 2: Start applications normally**

Applications keep their existing load path:

```bash
$ sudo tracee
$ sudo tetragon
$ sudo bpftrace -e 'tracepoint:sched:sched_switch { @[comm] = count(); }'
```

No custom loader is introduced, and no application restart is required for optimization.

**Step 3: Daemon discovers and optimizes loaded programs**

```text
[info] discovered prog_id=42 name=calico_tc_main type=sched_cls
[info] xlated=8604 insns  jited=46072 bytes
[info] candidate sites: cmov=20 wide=12 rotate=0 extract=1 endian=53 branch-flip=0
[info] selected sites: 66 (cmov skipped by current policy)
[info] BPF_PROG_JIT_RECOMPILE applied successfully
[info] program remained attached; no application restart needed
```

**Step 4: Optionally persist a policy snapshot**

The daemon may write the directive list it used for auditability, offline tuning, or A/B rollout. This is an operational convenience, not a prerequisite for the application.

**Current prototype note**

The repository currently realizes this control plane through `scanner/build/bpf-jit-scanner`, `scanner/src/policy_config.cpp`, `e2e/common/recompile.py`, and the benchmark harnesses. Those components already validate the live post-load path; they are the implementation vehicle for the daemon, not the intended steady-state operator interface.

### 2.8 Canonical Form Transformation Examples

Each canonical form replaces a multi-instruction BPF sequence with a more efficient x86 native emission. Below are four concrete examples from different families.

#### Example 1: COND_SELECT, diamond if/else to CMOV

**BPF bytecode** (`site_len=4`):

```text
insn[0]:  JGT   r1, r2, +2
insn[1]:  MOV64 r0, 0
insn[2]:  JA    +1
insn[3]:  MOV64 r0, 1
```

**Stock kernel x86 emission**:

```asm
cmp    rdi, rsi
jbe    .Lelse
mov    rax, 1
jmp    .Ljoin
.Lelse:
mov    rax, 0
.Ljoin:
```

**BpfReJIT emission**:

```asm
mov    rax, 0
cmp    rdi, rsi
mov    r11, 1
cmova  rax, r11
```

**Why faster**: Eliminates branch misprediction penalty entirely. On dependency chains such as `log2_fold`, the branchless path is 28-46% faster. For highly predictable branches such as `cmov_select`, the branch predictor can do better, which is exactly the policy-sensitivity result the system needs to expose.

#### Example 2: WIDE_MEM, 4 byte loads to 1 wide move

**BPF bytecode** (`site_len=4`, representative prefix):

```text
insn[0]:  LDX_MEM_B  r3, [r1 + 0]
insn[1]:  LDX_MEM_B  r4, [r1 + 1]
insn[2]:  LSH64      r4, 8
insn[3]:  OR64       r3, r4
```

Typical full pattern is 7-10 insns for a 4-byte recomposition.

**Stock kernel x86 emission**:

```asm
movzx  r11d, byte ptr [rbx + 0]
movzx  r12d, byte ptr [rbx + 1]
shl    r12, 8
or     r11, r12
movzx  r12d, byte ptr [rbx + 2]
shl    r12, 16
or     r11, r12
movzx  r12d, byte ptr [rbx + 3]
shl    r12, 24
or     r11, r12
```

**BpfReJIT emission**:

```asm
mov    r11d, dword ptr [rbx + 0]
```

**Why faster**: Replaces roughly 10 instructions with a single `mov`. This family accounts for **50.7%** of the measured native-code instruction surplus between LLVM JIT and the stock kernel.

#### Example 3: ENDIAN_FUSION, load plus byte swap to MOVBE

**BPF bytecode** (`site_len=2`):

```text
insn[0]:  LDX_MEM_W  r3, [r1 + 12]
insn[1]:  END_BE     r3, 32
```

**Stock kernel x86 emission**:

```asm
mov    r11d, dword ptr [rbx + 12]
bswap  r11d
```

**BpfReJIT emission**:

```asm
movbe  r11d, dword ptr [rbx + 12]
```

**Why faster**: Fuses load and byte swap into one instruction. Calico's `calico_tc_main` alone has **53 endian sites**.

#### Example 4: ROTATE, shift plus OR to RORX/ROR

**BPF bytecode** (`site_len=3`):

```text
insn[0]:  RSH64  r3, 17
insn[1]:  LSH64  r4, 47
insn[2]:  OR64   r3, r4
```

**Stock kernel x86 emission**:

```asm
shr    r11, 17
shl    r12, 47
or     r11, r12
```

**BpfReJIT emission** with BMI2:

```asm
rorx   r11, r11, 17
```

**BpfReJIT emission** without BMI2:

```asm
ror    r11, 47
```

**Why faster**: Replaces 3-4 instructions with a single rotate. There are **2,685 rotate sites** across the real-world corpus.

### 2.9 Correctness Verification

BpfReJIT employs a multi-layer verification model:

1. **Scanner-side pattern matching**: userspace matches BPF instruction sequences against canonical form descriptors with opcode, binding, and algebraic-constraint checks.
2. **Kernel-side canonical-site validation**: the kernel re-matches the pattern against the actual verified BPF bytecode and validates family-specific semantics.
3. **Emitter-side fail-closed behavior**: failed or unsupported canonical emission falls back to stock emission, never partial native-code generation.
4. **Measurement-side result comparison**: `micro_exec` compares output equivalence across runtimes.
5. **VM isolation**: corpus and E2E measurements run in controlled framework-kernel VMs for reproducibility.

---

## 3. Implementation Status

### 3.1 Kernel Framework

- **Branch**: `jit-directive-v5` in `vendor/linux-framework` (based on Linux 7.0-rc2)
- **Core files**: `kernel/bpf/jit_directives.c` and `arch/x86/net/bpf_jit_comp.c`
- **v4 legacy removed**: commit `a99cd78ed` deleted 778 LOC of legacy v4 code
- **v5 extensibility demonstrated**: adding a new canonical form requires ~32 LOC (vs. 1,018 LOC in v4, a 32x reduction)
- **v6 tier-1 improvements**: generic site/pattern upper bound 64, `log_buf` added to recompile syscall, tuple/binding limit raised from 12 to 16
- **Validator template**: each new directive requires ~50-100 LOC validator + ~50-100 LOC emitter per architecture; transport, blob parsing, remapping, CPU gating, and fail-closed logic are shared

### 3.2 Userspace Control Plane Foundation

- **Location**: `scanner/` (C++ CMake project)
- **Capabilities already live-compatible**: pattern matching over post-verifier bytecode, v5 wire-format generation, policy compilation, live `apply` path
- **Policy compiler**: reads v3 YAML, filters discovered sites, builds sealed memfd blob
- **Test coverage**: 163 unit test assertions covering pattern families and golden YAML cases
- **Known bug**: `pattern_kind` is parsed but ignored during filtering (P0)
- **Important architectural note**: the scanner CLI still retains ELF and `--xlated` convenience paths for corpus and micro evaluation; those are prototype conveniences, not a requirement of the final daemon architecture

### 3.3 Policy System

- **614 policy YAML files** generated and validated across micro and corpus
- **`corpus/generate_default_policies.py`**: current artifact generator for reproducible policy snapshots
- **`corpus/policy_utils.py`**: v3 parser, live remap logic, and policy I/O
- **`corpus/auto_tune.py`**: 5-phase auto-tuner prototype (census -> screening -> ablation -> combo -> generate)

### 3.4 Current Experimental Pipeline vs. Steady-State Deployment

The steady-state system is: live program discovery -> bytecode/native extraction -> policy decision -> `BPF_PROG_JIT_RECOMPILE` -> continued execution with no application restart.

The current repository decomposes that control plane into reproducible research components:

1. **Micro benchmarks**: `micro/run_micro.py` with `kernel-recompile` runtime and per-benchmark policy files
2. **Corpus**: `corpus/_driver_impl_run_corpus_v5_vm_batch.py` over 560 objects with per-program policy snapshots
3. **E2E**: `e2e/run.py` with Tracee, Tetragon, bpftrace, XDP forwarding, and scx

This decomposition is suitable for evaluation, artifact generation, and debugging. The long-running daemon packaging and the native-code-side analyzer are the remaining integration steps.

### 3.5 CI

- **x86**: passing
- **ARM64**: partial (llvmbpf packet mapping issue; kernel-only fallback works)
- ARM64 kernel emitter is not yet implemented (estimated 3-4 days)

---

## 4. Evaluation Results

### 4.1 Micro Benchmarks (56 Pure-JIT)

**Characterization gap** (llvmbpf vs. stock kernel, strict 30x1000, CPU-pinned, turbo off):

| Metric | Value |
|---|---|
| Exec-time geomean (llvmbpf / kernel) | **0.609x** (LLVM JIT 39% faster) |
| Programs where llvmbpf wins | 53 / 56 |
| Programs where kernel wins | 3 / 56 |

**BpfReJIT kernel-recompile** (post-CMOV-fix, v3 policy, 10/2/500 warmups/iterations/repeat):

| Metric | Value |
|---|---|
| Valid pairs | 56 / 56 (first time zero invalid) |
| Applied pairs | 11 / 56 |
| Overall geomean (stock / recompile) | **1.007x** |
| Applied-only geomean | 0.986x |

Notable per-benchmark results from the authoritative fixed-policy run (#139):

| Benchmark | Ratio (stock/recompile) | Notes |
|---|---:|---|
| `cmov_dense` | 1.230x | 26 CMOV sites applied |
| `memcmp_prefix_64` | 1.229x | 3 wide-mem sites |
| `bpf_call_chain` | 1.109x | 3 sites (wide+cmov) |
| `log2_fold` | 1.042x | 3 sites, policy-sensitive |
| `cmov_select` | 0.975x | 1 CMOV site (known sensitivity) |
| `bounds_ladder` | 0.889x | 4 sites, CMOV still hurts here |

**Policy sensitivity**:

- `log2_fold` with CMOV: **+28-46%**
- `cmov_select` with CMOV: **-82%**
- `switch_dispatch` with CMOV: **+26%**
- `binary_search` with CMOV: **+12%**
- `bounds_ladder` with CMOV: **-18%**
- `large_mixed_500` with CMOV: **-24%**

No fixed kernel heuristic can be optimal across all programs; the same legal transformation helps some workloads and hurts others.

### 4.2 Real-World Corpus

**Corpus inventory**:

| Metric | Count |
|---|---:|
| BPF ELF objects | 560 |
| Total programs | 1,836 |
| Loadable programs | 1,214 |
| Programs with optimization sites | 293 |
| Projects represented | 23 |

**Execution-time results** (framework-kernel VM, `packet_test_run`):

| Configuration | Measured Pairs | Applied | Geomean | Wins | Losses |
|---|---:|---:|---:|---:|---:|
| Blind all-apply | 163 | 92 | **0.868x** | 40 | 107 |
| v1 tuned (cmov:skip for 18 regressors) | 142 | -- | **0.898x** | 42 | 84 |
| v2 fixed (default:apply + cmov:skip) | 156 | 91 | **0.875x** | 45 | 101 |

**CMOV ablation** (45-program sample, 42 measured timing pairs):

| Group | Exec Geomean vs. Stock |
|---|---:|
| With CMOV applied | 0.859x |
| Without CMOV (current policy) | 0.947x |
| Normalized A/B | **0.906x** (CMOV still net-negative) |

Conclusion: CMOV remains net-negative on real-world corpus programs. The current policy correctly skips CMOV at the family level while applying other families.

**Tracing corpus** (non-`packet_test_run` programs, attach+trigger, `run_cnt` / `run_time_ns` measurement):

| Metric | Value |
|---|---|
| Paired measurements | 167 |
| Overall geomean (stock/recompile) | **1.003x** |
| Applied-only geomean | **1.019x** |
| LSM programs | 1.050x (20 paired) |
| Tracing programs | 1.021x (55 paired) |
| Raw tracepoint | 1.008x (27 paired) |
| Kprobe | 1.002x (33 paired) |
| Tracepoint | 0.942x (32 paired) |

### 4.3 Code Size

| Metric | Value |
|---|---|
| Micro pure-JIT geomean (llvmbpf / kernel) | **0.496x** (50% reduction) |
| Real-program code-size geomean | **0.618x** (36 unique programs) |
| Real-program exec-time geomean | **0.514x** (14 unique programs) |
| Full corpus code-size (recompile/stock) | **1.003x** (near-neutral) |

LLVM produces substantially smaller native code; BpfReJIT's current recompile is near code-size neutral because the present objective is execution time, not size minimization.

### 4.4 Overhead

**Scanner latency**:

| Metric | Micro (56 programs) | Corpus (50-object sample) |
|---|---:|---:|
| Median | 4.32 ms | 4.42 ms |
| P90 | 11.94 ms | 112.37 ms |
| P95 | 21.24 ms | 143.15 ms |
| Max | 181.33 ms | 172.52 ms |
| Linear scaling | 13.03 ms/1k insns (R^2=0.997) | 13.27 ms/1k insns (R^2=0.954) |

**Recompile syscall latency**:

| Metric | Value |
|---|---:|
| Median | **29.89 us** |
| P90 | 63.31 us |
| Max | 67.58 us |
| Scaling | ~9.95 us/KiB (R^2=0.928, tracks program size) |

**Policy blob sizes**:

| Representative Program | Sites | Blob Size |
|---|---:|---:|
| Single-site XDP | 1 | 164 B |
| Katran `balancer_ingress` | 18 | 2.2 KB |
| Calico `calico_tc_main` | 86 | 9.6 KB |
| Tracee `cgroup_skb_egress` | 123 | 16.5 KB |
| Worst case (`test_verif_scale2`) | 992 | 213 KB |

The overhead is dominated by userspace analysis latency in the current prototype, not by the kernel recompile hook. For realistic programs, the full pipeline remains in the single-digit-millisecond regime.

### 4.5 Comparison with Prior Work

K2 (SIGCOMM'21), Merlin (ASPLOS'24), and EPSO (ASE'25) optimize at the BPF bytecode or LLVM IR level. BpfReJIT operates at the JIT backend/native emission level. These are orthogonal, not competing.

| System | Optimization Layer | Addresses Backend Gap? | Deployment-Controllable? |
|---|---|:---:|:---:|
| K2 | BPF bytecode | No | No |
| Merlin | LLVM IR + BPF | No | No |
| EPSO | BPF bytecode | No | No |
| **BpfReJIT** | **Backend lowering** | **Yes** | **Yes** |

Backend-only gap decomposition:

- Byte-load recomposition: **50.7%** of kernel instruction surplus
- Branch/CMOV: **19.9%**
- Prologue/epilogue: **18.5%**
- Total backend-only gap: **~89.1%**

LLVM pass ablation confirms the orthogonality claim: disabling `InstCombinePass` + `SimplifyCFGPass` on backend-gap benchmarks yields native code size geomean **0.995x**, while BpfReJIT's backend rotate optimization yields **1.235x** speedup on the same benchmarks.

### 4.6 End-to-End Validation

All deployed agents remained unmodified; BpfReJIT operated after load.

| Case | Configuration | Key Result |
|---|---|---|
| **Tracee** (security agent) | 15 programs, 8 recompiled | `exec_storm` app throughput **+21.65%**, events/s **+21.16%** |
| **Tetragon** (observability) | 5 programs, 1 recompiled | App throughput **+3.8%**, agent CPU **-2.0%** |
| **bpftrace** (tracing scripts) | 5 scripts, 2 with CMOV sites | Validates policy-sensitivity (CMOV-only scripts show slight regression) |
| **XDP forwarding** (PPS) | 3 sites, 2 endian applied | **1.003x** PPS (993K vs. 991K) |
| **scx_rusty** (scheduler) | 13 struct_ops, 28 sites | Baseline + census only (struct_ops live recompile blocked by trampoline regeneration) |

---

## 5. Key Technical Challenges and Solutions

### 5.1 CMOV Emitter Correctness Bug (#138)

**Problem**: the scanner broadened `COND_SELECT` pattern recognition to include guarded-update, switch-chain, and backward-join variants, but the x86 emitter only implemented simple diamond/compact `cmp+cmov` lowering. Broader sites dropped ALU operations and join edges, causing wrong results and VM crashes in 6 benchmarks.

**Solution**: restricted the x86 emitter to simple diamond/compact forms, re-enabled canonical-site validation for `COND_SELECT` and `BITFIELD_EXTRACT`, and fixed a BMI1 `BEXTR` cross-register encoding issue for `mixed_alu_mem`.

**Impact**: all 6 previously crashing or mismatching benchmarks recovered; suite validity improved from 50/56 to 56/56.

### 5.2 Policy Format Evolution

- **v1**: family allowlists with implicit defaults; too coarse
- **v2**: `default` / `families` / `sites`; more precise but more complex
- **v3**: simple per-site directive list; directly matches scanner output and syscall input

### 5.3 Sub-ktime Measurement Noise

Programs below ~100 ns hit the ktime resolution floor. Under strict measurement, filtering to execution time >=100 ns moves the micro gap from 0.609x to 0.645x. For corpus, >=100 ns does not rescue the negative result; only >=200 ns flips positive, and then only with N=13.

### 5.4 struct_ops EOPNOTSUPP

Live attached `struct_ops` programs cannot currently be re-JITed because:

1. the x86 re-JIT first pass originally reused stale `aux->extable` state (fixed)
2. `struct_ops` programs still require trampoline regeneration after re-JIT (not yet implemented)

Current behavior is explicit `-EOPNOTSUPP` with a diagnostic log message, not silent `EINVAL`.

---

## 6. Open Issues and Risks

### 6.1 Critical (P0)

1. **Scanner `pattern_kind` filtering bug**: mistyped `pattern_kind` entries can still match.
2. **Missing canonical-site validation for 3 families**: `WIDE_MEM`, `ROTATE`, and `ADDR_CALC` still bypass exact kernel-owned validation.
3. **No rollback mechanism**: failed recompile can drop the last known-good optimized policy.
4. **No kernel selftests**: malformed policy rejection, overlap resolution, repeated re-JIT memory growth, concurrent recompiles, and rollback are not yet covered by kselftests.

### 6.2 Significant (P1)

5. **Userspace control plane packaging**: the current live path is implemented as scanner CLI + harnesses rather than a resident daemon.
6. **Native-side analysis is not yet first-class in userspace**: the target daemon should analyze both `xlated` and `jited` views, but current userspace logic is still primarily bytecode-driven.
7. **CMOV remains net-negative on corpus**: 0.906x normalized in the current ablation.
8. **Concurrency/lifetime concerns**: concurrent `BPF_PROG_JIT_RECOMPILE` calls appear unsynchronized.
9. **ARM64 not implemented**: x86-only emitter today.
10. **Scanner/emitter capability asymmetry**: scanner recognizes broadened `COND_SELECT` shapes that the x86 emitter intentionally fail-closes.

### 6.3 Moderate (P2)

11. **Greedy scanner**: first-match-wins means results are order-dependent.
12. **No structured observability**: kernel has string logs but no counters, tracepoints, or per-rule statistics.
13. **PMU methodology limitations**: no `time_enabled` / `time_running` scaling; ratios use medians rather than paired per-sample values.

---

## 7. Remaining Work for Submission

### Priority 1: Safety Claim Hardening

- Wire `WIDE_MEM`, `ROTATE`, and `ADDR_CALC` validators into `bpf_jit_validate_canonical_site()`
- Fix `pattern_kind` filtering and update tests
- Add per-program recompile serialization
- Implement last-known-good policy preservation

### Priority 2: Control-Plane Consolidation

- Package the live scanner/apply path as a standalone daemon
- Add explicit program enumeration, state tracking, and rollback hooks
- Promote JITed native-code extraction to a first-class daemon analysis input

### Priority 3: Evaluation Completion

- Complete byte-recompose / callee-saved / BMI per-family ablation
- Finalize per-family micro ablation for all 8 families
- Strengthen CMOV signal with additional CMOV-heavy benchmarks or microarchitectures

### Priority 4: Paper Writing

- Preserve the characterization-gap -> recovery -> policy-sensitivity narrative
- Position K2 / Merlin / EPSO as orthogonal systems
- Frame corpus <1.0x honestly as evidence for policy control rather than fixed heuristics

### Priority 5: Optional Strengthening

- ARM64 kernel emitter port
- Kernel selftests for the recompile path
- Structured kernel observability counters

---

## 8. Timeline Assessment

### 8.1 What Is Done

| Category | Status | Confidence |
|---|---|---|
| Core system design and implementation | Complete | High |
| 8 canonical forms (x86) | Complete | High |
| Micro benchmark suite (56 programs) | Complete, authoritative numbers | High |
| Real-world corpus (560 objects) | Complete, multiple runs | High |
| E2E validation (Tracee, Tetragon, bpftrace, XDP) | Complete | Medium-High |
| Scanner + policy system (v3) | Complete | Medium |
| Overhead measurement | Complete | High |
| Policy-sensitivity evidence | Complete | High |
| Code-size analysis | Complete | High |

### 8.2 What Remains

| Task | Effort | Risk | Impact |
|---|---|---|---|
| Safety claim fixes | 2-3 days | Low | Critical |
| Scanner `pattern_kind` fix | 0.5 day | Low | Medium |
| Daemon packaging + native-input consolidation | 2-4 days | Medium | High |
| Ablation completion | 3-4 days | Medium | High |
| Paper evaluation section | 5-7 days | Low | Critical |
| ARM64 port | 3-4 days | Medium | Moderate |
| Kernel selftests | 2-3 days | Low | Moderate |

### 8.3 Assessment

The kernel mechanism, the canonical-form substrate, the live post-load control path, and the policy-sensitivity evidence are already in place. The principal remaining architectural step is userspace packaging: the research prototype currently exposes the live logic as a scanner CLI plus orchestration code, while the correct deployment artifact is a standalone daemon that continuously observes loaded programs and reasons over both bytecode and native code. That is a control-plane integration task, not a reinvention of the kernel mechanism.

The main narrative risks remain the same as before. Corpus packet-test numbers are below 1.0x under blind or coarse policies, which must be framed as evidence that fixed heuristics are insufficient. CMOV remains the clearest policy-sensitive family and also the most aggregate-negative one, which is a thesis-strengthening result if presented honestly. Safety completeness still requires validator closure for three families before submission.

---

## Appendix: Key Artifacts

| Artifact | Location |
|---|---|
| Master plan document | `docs/kernel-jit-optimization-plan.md` |
| Paper draft | `docs/paper/paper.tex` |
| Micro suite config | `config/micro_pure_jit.yaml` |
| Micro authoritative results (strict) | `micro/results/pure_jit_authoritative_strict_20260312.json` |
| Kernel recompile results | `micro/results/kernel_recompile_v2_fixed_authoritative_20260312.json` |
| Post-cmov-fix micro | `micro/results/post_cmov_fix_micro.json` |
| Corpus v2 fixed results | `corpus/results/corpus_v5_v2_fixed_20260312.json` |
| Tracing corpus results | `corpus/results/tracing_corpus_vm_full_20260312.json` |
| Code-size results | `corpus/results/code_size_full_vm_20260312.json` |
| CMOV ablation | `corpus/results/post_cmov_fix_corpus_ablation.json` |
| E2E Tracee | `e2e/results/tracee-e2e-real.json` |
| E2E Tetragon | `e2e/results/tetragon-real-e2e.json` |
| E2E bpftrace | `e2e/results/bpftrace-real-e2e.json` |
| E2E XDP forwarding | `e2e/results/xdp_forwarding_vm_20260312.json` |
| Architecture review | `docs/tmp/architecture-review-and-diagrams.md` |
| Overhead measurement | `docs/tmp/recompile-overhead-measurement.md` |
| K2/Merlin/EPSO comparison | `docs/tmp/k2-merlin-epso-comparison.md` |
| CMOV emitter fix | `docs/tmp/cmov-emitter-fix.md` |
| Kernel framework | `vendor/linux-framework/` (branch `jit-directive-v5`) |
| Scanner | `scanner/` |
| Policy files | `corpus/policies/`, `micro/policies/` |
