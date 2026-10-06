# BPF Benchmark Coverage Gap Analysis

Generated: 2026-03-10

## 1. Current Coverage Matrix

### 1.1 Micro-benchmark Suite (62 programs)

| Suite | Count | Hook Types | Scenarios |
| --- | ---: | --- | --- |
| pure-jit | 50 | XDP, packet-backed | Pure computation, no helper/map in hot path |
| runtime | 11 | XDP (map-backed) | Map lookup, helper call, atomic ops |
| rotate | 1 | XDP | Hash with 64-bit rotations |
| **Total** | **62** | **XDP only** | **Networking data plane only** |

Categories covered in pure-jit:
- baseline (3), alu-mix (6), control-flow (7), dependency-ilp (4), memory-local (11), loop-shape (6), call-size (2), program-scale (4), call-overhead (2)

### 1.2 Production Corpus (code-size + exec-time)

| Project | Objects | Programs | Hook Types | Domain |
| --- | ---: | ---: | --- | --- |
| calico | 8 | 60 | XDP, TC | Networking (CNI) |
| cilium | 3 | ~30 | XDP, TC | Networking (CNI) |
| katran | 5 | ~10 | XDP | Networking (L4 LB) |
| suricata | 2 | 1 | XDP | Networking (IDS) |
| loxilb | 3 | 18 | XDP, TC | Networking (LB) |
| netbird | 1 | 1 | XDP | Networking (VPN) |
| tubular | 1 | 1 | sk_lookup | Networking (dispatcher) |
| xdp-tools | 13 | ~15 | XDP | Networking (utilities) |
| xdp-tutorial | 25 | ~25 | XDP | Networking (examples) |
| xdp-examples | 0 | 0 | XDP | Networking (examples) |
| **bcc** | **57** | **~200** | **kprobe, fentry, fexit, tp_btf, tracepoint, perf_event** | **Tracing/observability** |
| **linux-selftests** | **361** | **~1000** | **Mixed (all types)** | **Testing/validation** |
| **libbpf-bootstrap** | **12** | **~20** | **Mixed** | **Examples** |
| **systemd** | **6** | **6** | **cgroup, LSM** | **Security/resource control** |
| **tetragon** | **0** | **0** | (failed build) | Security/observability |

**Key observation**: The corpus already contains 57 bcc tracing programs and 6 systemd cgroup/LSM programs compiled as `.bpf.o` files. However, NONE of them are included in benchmark execution or the v4/v5 framework evaluation.

### 1.3 BPF Program Type Universe

| Category | Prog Types | In micro? | In corpus? | In eval? |
| --- | --- | --- | --- | --- |
| Network data plane | XDP, TC, cg_skb | Yes | Yes | Yes |
| Network infra | sk_lookup, flow_dissector, lwt, sk_skb, sk_msg, sockops | No | Partial (tubular) | No |
| Tracing (kprobe) | kprobe, kretprobe | No | Yes (bcc 25) | No |
| Tracing (fentry) | fentry, fexit, fmod_ret | No | Yes (bcc 14) | No |
| Tracing (tracepoint) | tracepoint, tp_btf, raw_tracepoint | No | Yes (bcc 15) | No |
| Profiling | perf_event | No | Yes (bcc 4) | No |
| Security | LSM | No | Yes (systemd 2, selftests) | No |
| Resource control | cgroup/* | No | Yes (systemd 4) | No |
| Scheduling | sched_ext (struct_ops) | No | No | No |
| Iteration | iter/* | No | Yes (selftests) | No |
| TCP CC | struct_ops (tcp) | No | Yes (selftests) | No |
| Syscall | syscall | No | Yes (selftests) | No |

## 2. Per-Scenario Detailed Analysis

### 2.1 Tracing: kprobe/kretprobe

**`bpf_prog_test_run` support**: NO. `kprobe_prog_ops` has an empty `test_run` field. Cannot use `bpf_prog_test_run_opts()`.

**Measurement approach**: Two options:
1. **Trigger-based**: Attach to a known kernel function, trigger it from userspace (e.g., `getpid()` for `kprobe/sys_enter`), measure externally. Not suitable for micro-benchmarking the BPF program itself.
2. **Code-size only**: Load, JIT, measure `jited_prog_len`. No exec-time comparison.

**JIT characteristics**:
- Higher helper call density than networking (~6-11% vs ~3-5% for networking)
- Heavy `bpf_probe_read_kernel` / `bpf_probe_read_user_str` usage (e.g., execsnoop: 62 probe_read calls in 2165 insns)
- Access to `struct pt_regs` context (register-based field extraction)
- Typically smaller programs (100-2000 insns vs 10k-40k for production networking)
- More map updates for event output (`bpf_perf_event_output`, ringbuf)

**Directive coverage potential**:
- CMOV: Likely moderate -- tracing programs have filter conditions (PID filter, comm filter)
- WIDE_MEM: Low -- context access is single-field, not byte-recomposition patterns
- ROTATE: Very low -- no hash computation in typical tracing
- LEA: Low -- simple indexing patterns

**Paper value**: HIGH. Tracing is the #1 BPF use case by deployment volume. Not covering it is the most obvious gap.

### 2.2 Tracing: fentry/fexit/fmod_ret

**`bpf_prog_test_run` support**: YES. `tracing_prog_ops` has `.test_run = bpf_prog_test_run_tracing`. However, it only works with `bpf_fentry_test*` functions (kernel test helpers), not arbitrary kernel functions. The test run calls specific test functions and measures the program execution during those calls.

**Measurement approach**: Can use `bpf_prog_test_run_opts()` if the program attaches to `bpf_fentry_test*` or `bpf_modify_return_test`. For real fentry programs (e.g., `fentry/vfs_read`), must trigger from userspace. Alternatively, write synthetic fentry programs that attach to test functions.

**JIT characteristics**:
- BTF-based direct context access (no probe_read needed -- direct memory access via BTF)
- Lower helper overhead than kprobe (no register saving/restoring for BTF tracing)
- Similar program structure to kprobe but with type-safe field access

**Directive coverage potential**: Similar to kprobe but possibly more WIDE_MEM from BTF struct field access patterns.

**Paper value**: MEDIUM-HIGH. Represents modern BPF tracing (BTF-enabled). Differentiates from legacy kprobe.

### 2.3 Tracing: raw_tracepoint

**`bpf_prog_test_run` support**: YES. `raw_tracepoint_prog_ops` has `.test_run = bpf_prog_test_run_raw_tp`. However, it does NOT support `repeat` -- only single invocations. Context is passed via `ctx_in`. No `data_in/data_out`.

**Measurement approach**: Can invoke once via test_run, but no built-in repeat. Would need to wrap in userspace loop calling `bpf_prog_test_run_opts` repeatedly (similar to current kernel runner approach but without the kernel-side repeat).

**JIT characteristics**: Similar to tracepoint. Raw tracepoint gives raw `u64[]` context.

**Directive coverage potential**: Low (simple programs).

**Paper value**: LOW. Niche use case.

### 2.4 Profiling: perf_event

**`bpf_prog_test_run` support**: NO. `perf_event_prog_ops` has empty `test_run`.

**Measurement approach**: Must attach to actual perf events. Cannot benchmark in isolation.

**JIT characteristics**:
- Very short programs (profile.bpf.o: 106 insns)
- Stack walking (`bpf_get_stackid`), map updates
- Minimal compute, mostly helper calls

**Directive coverage potential**: Very low.

**Paper value**: LOW. Programs are too small and helper-dominated.

### 2.5 Security: LSM

**`bpf_prog_test_run` support**: NO. `lsm_prog_ops` has empty `test_run`.

**Measurement approach**: Must trigger via actual security hooks (file open, socket bind, etc.). Cannot benchmark in isolation.

**JIT characteristics** (based on systemd corpus):
- Very small programs (6-258 insns)
- Simple policy checks: map lookup, compare, return allow/deny
- Minimal computation
- systemd LSM programs: only 3 CMOV sites across all 6 programs

**Directive coverage potential**: Very low. Programs are too small.

**Paper value**: MEDIUM for generality argument (different domain), but LOW for JIT optimization value. The programs are so simple that JIT differences are negligible.

### 2.6 Resource Control: cgroup/*

**`bpf_prog_test_run` support**: `cg_skb` has `bpf_prog_test_run_skb` (YES). Other cgroup types (`cg_sock`, `cg_sysctl`, `cg_sockopt`) have NO test_run.

**Measurement approach**: `cgroup_skb` programs can be tested like TC programs. Others require real trigger.

**JIT characteristics**:
- Small programs (systemd: 6-164 insns)
- Socket/sysctl context access
- Policy decisions (allow/deny)

**Directive coverage potential**: Very low. Too small.

**Paper value**: MEDIUM for breadth, LOW for optimization insight.

### 2.7 Socket-level: sockops/sk_msg/sk_skb

**`bpf_prog_test_run` support**: NO for all three. `sk_skb_verifier_ops` and `sk_msg_verifier_ops` have no test_run.

**Measurement approach**: Requires socket setup, data flow through sockmap. Complex harness.

**JIT characteristics**:
- Medium complexity (Cilium uses sockops for socket-level policy)
- Mix of packet parsing and map operations
- Connection tracking logic

**Directive coverage potential**: Moderate (similar to TC programs in structure).

**Paper value**: MEDIUM. Interesting as non-XDP/TC networking, but hard to measure.

### 2.8 Scheduling: sched_ext (struct_ops)

**`bpf_prog_test_run` support**: YES for struct_ops (`bpf_struct_ops_test_run`).

**Measurement approach**: Can test via struct_ops test_run infrastructure. Requires CONFIG_SCHED_CLASS_EXT.

**JIT characteristics**:
- Scheduling decision logic
- Task context access
- Potentially complex policy with multiple hooks

**Directive coverage potential**: Unknown -- no corpus programs available.

**Paper value**: LOW-MEDIUM. Emerging use case but not yet mainstream.

### 2.9 TCP Congestion Control: struct_ops (tcp)

**`bpf_prog_test_run` support**: YES via struct_ops test_run.

**Measurement approach**: Can test via struct_ops infrastructure.

**JIT characteristics** (based on selftests `bpf_cubic.bpf.o`, `bpf_dctcp.bpf.o`):
- Pure computation (cwnd calculation, RTT estimation)
- No map lookups typically
- Math-heavy: division, multiplication, comparison
- Similar to pure-jit micro-benchmarks in spirit

**Directive coverage potential**: Moderate -- math-heavy code could have CMOV patterns.

**Paper value**: MEDIUM-HIGH. Unique domain (not networking data plane, not tracing), and amenable to test_run.

### 2.10 Iterators: iter/*

**`bpf_prog_test_run` support**: Not directly, but iterator programs run via read() on BPF link fd.

**Measurement approach**: Can be invoked via `read()` on iterator link fd. Not standard test_run.

**JIT characteristics**: Iteration over kernel data structures, output via seq_write.

**Paper value**: LOW.

## 3. Priority-Ranked Expansion Suggestions

### Priority 1: fentry/fexit Tracing Micro-benchmarks (HIGH VALUE, LOW EFFORT)

**Rationale**: fentry/fexit has `bpf_prog_test_run` support via `bpf_fentry_test*` functions. This is the lowest-hanging fruit for expanding beyond XDP.

**Concrete benchmarks**:

| Name | Description | JIT Pattern | Measurable? | Effort |
| --- | --- | --- | --- | --- |
| `fentry_filter_pid` | fentry program that filters by PID/TGID from BTF context, reads task fields | BTF ctx access, compare-branch, map lookup | Yes (via bpf_fentry_test) | Low |
| `fentry_field_extract` | Extract multiple struct fields from BTF context, hash and store | BTF field access, ALU, map update | Yes | Low |
| `fentry_stack_heavy` | Deep stack variable usage with many local variables | Register pressure, spill/fill | Yes | Low |
| `fmod_ret_policy` | Modify-return program with complex allow/deny logic | Branch-heavy, compare chains | Yes | Medium |

**Implementation approach**:
1. Write BPF programs using `SEC("fentry/bpf_fentry_test1")` or similar
2. Attach via libbpf
3. Invoke `bpf_prog_test_run_opts()` (it calls the test function internally)
4. Measure exec_ns from test_run duration

**Caveats**:
- `bpf_prog_test_run_tracing` does NOT support `repeat` -- it runs the test functions once (test1 through test10) and measures the aggregate
- Would need kernel-side modifications or userspace loop for proper micro-benchmarking
- The test functions are trivial (just addition); the BPF program overhead is what we measure

**Expected JIT characteristics different from XDP**:
- No packet context, no bounds checks against packet end
- BTF-based direct field access (different instruction patterns)
- Smaller programs, more helper-centric

### Priority 2: TCP Congestion Control struct_ops (MEDIUM-HIGH VALUE, MEDIUM EFFORT)

**Rationale**: struct_ops has `bpf_struct_ops_test_run`. TCP CC programs are pure computation, aligning well with the pure-JIT benchmark philosophy.

**Concrete benchmarks**:

| Name | Description | JIT Pattern | Measurable? | Effort |
| --- | --- | --- | --- | --- |
| `tcp_cc_cubic_step` | BPF cubic cwnd calculation | Math-heavy, division, comparison | Yes (struct_ops test_run) | Medium |
| `tcp_cc_bbr_probe` | BBR-style bandwidth estimation | Pacing rate calculation, shift/multiply | Yes | Medium |

**Implementation approach**:
1. Use existing `bpf_cubic.bpf.o` or `bpf_dctcp.bpf.o` from selftests as templates
2. Invoke via `bpf_struct_ops_test_run`
3. Need to verify repeat support

**Caveats**: struct_ops test_run infrastructure is complex and may not support repeat.

### Priority 3: cgroup_skb Programs (MEDIUM VALUE, LOW EFFORT)

**Rationale**: `cg_skb` uses `bpf_prog_test_run_skb`, identical to TC. Can test with existing harness by using `cgroup_skb/ingress` or `cgroup_skb/egress` section names.

**Concrete benchmarks**:

| Name | Description | JIT Pattern | Measurable? | Effort |
| --- | --- | --- | --- | --- |
| `cgroup_skb_policy` | Packet-based cgroup policy with IP/port matching | Compare chains, map lookup | Yes (skb test_run) | Low |
| `cgroup_skb_rate_limit` | Token bucket rate limiter | Atomic ops, timing helpers | Yes | Low |

**Implementation approach**: Nearly identical to current TC benchmarks. Just change section name. Existing kernel runner already handles skb programs.

**Paper value**: Demonstrates that the framework applies beyond pure XDP. Very low implementation cost.

### Priority 4: Corpus-Based Tracing Evaluation (Code-Size Only) (HIGH VALUE, LOW EFFORT)

**Rationale**: The 57 bcc/libbpf-tools programs are already compiled. We can run the directive scanner on them for code-size analysis without needing exec-time measurement.

**Concrete approach**:
1. Load each bcc .bpf.o via libbpf (some may need BTF, some may fail for missing kernel functions)
2. For programs that load: dump xlated bytecode, run scanner, count directive sites
3. Report CMOV/WIDE/ROTATE/LEA sites across tracing programs
4. Compare directive density between tracing and networking domains

**Expected results**: Tracing programs likely have:
- Fewer WIDE_MEM sites (less byte-recomposition)
- Some CMOV sites (filter conditions)
- Very few ROTATE/LEA sites
- This CONFIRMS that the framework is generalizable (directives apply across domains) or REVEALS domain-specific gaps

**Paper value**: Can add a table showing "directive site census across program domains" to strengthen generality.

### Priority 5: Netfilter (nf) Programs (MEDIUM VALUE, MEDIUM EFFORT)

**Rationale**: `nf_bpf_link.c` has `.test_run = bpf_prog_test_run_nf`. Netfilter BPF is a newer hook point for packet filtering.

**Concrete benchmarks**:

| Name | Description | JIT Pattern | Measurable? | Effort |
| --- | --- | --- | --- | --- |
| `nf_filter_stateless` | Stateless packet filter via netfilter hook | Packet parse, compare | Yes (nf test_run) | Medium |

### Priority 6: raw_tracepoint Micro-benchmarks (LOW-MEDIUM VALUE, MEDIUM EFFORT)

**Rationale**: `raw_tracepoint` has `bpf_prog_test_run_raw_tp` but NO repeat support. Would need userspace-side looping, which adds syscall overhead to measurements.

**Not recommended** for micro-benchmarking due to measurement quality concerns.

### Priority 7: kprobe/LSM/cgroup Corpus Code-Size Census (MEDIUM VALUE, LOW EFFORT)

**Rationale**: Cannot run exec-time benchmarks, but can analyze JIT code size and directive site coverage for these program types already in the corpus.

## 4. Work Effort and ROI Analysis

| Priority | Suggestion | Effort (days) | New Programs | New Domains | test_run? | ROI |
| --- | --- | ---: | ---: | ---: | --- | --- |
| P1 | fentry/fexit micro-benchmarks | 2-3 | 3-4 | Tracing | Yes (limited) | HIGH |
| P2 | TCP CC struct_ops | 3-5 | 2 | Congestion control | Yes | MEDIUM-HIGH |
| P3 | cgroup_skb programs | 1 | 2 | Resource control | Yes (full) | MEDIUM |
| P4 | Corpus tracing code-size census | 1-2 | 0 (57 existing) | Tracing | N/A (code-size) | HIGH |
| P5 | Netfilter programs | 2-3 | 1-2 | Firewalling | Yes | MEDIUM |
| P6 | raw_tp micro-benchmarks | 3-4 | 2-3 | Tracing | Partial | LOW |
| P7 | kprobe/LSM corpus census | 1 | 0 (existing) | Security, tracing | N/A (code-size) | MEDIUM |

**Recommended minimum viable expansion** (for paper deadline): P3 + P4 = **2-3 days of work**.

- P3 adds `cgroup_skb` programs with zero framework changes (same `bpf_prog_test_run_skb`)
- P4 adds a cross-domain directive census table from existing corpus data

**Full expansion** (if time allows): P1 + P2 + P3 + P4 = **7-11 days**.

## 5. Impact on Paper Generality Argument

### 5.1 Current Weakness

The paper currently evaluates:
- 62 micro-benchmarks: all XDP hook, all synthetic
- 60 production programs: all Calico TC/XDP + 1 Suricata XDP
- 4 directive families: only tested on networking data plane

A reviewer can legitimately ask: "Do these directives matter for the 57 BCC tracing tools that represent the majority of real-world BPF deployments?"

### 5.2 What Each Priority Adds

**P3 (cgroup_skb)**: Adds a new program type (`BPF_PROG_TYPE_CGROUP_SKB`) to exec-time evaluation. Proves the framework works beyond XDP/TC. Minimal effort because it uses the same `bpf_prog_test_run_skb` infrastructure. Adds one row to the program-type coverage table.

**P4 (corpus census)**: Adds a table like:

| Domain | Programs | CMOV | WIDE | ROTATE | LEA | Total Sites |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Networking (XDP/TC) | 60 | 197 | 108 | 10 | 0 | 315 |
| Tracing (kprobe/fentry/tp) | 57 | ? | ? | ? | ? | ? |
| Security (LSM/cgroup) | 6 | 3 | 0 | 0 | 0 | 3 |

This directly addresses generality by showing directive prevalence across domains.

**P1 (fentry micro-benchmarks)**: Strongest addition -- proves the JIT optimization framework produces measurable speedups on tracing programs, not just networking. However, the `bpf_prog_test_run_tracing` limitation (no repeat, only test functions) makes this harder to benchmark precisely.

**P2 (TCP CC)**: Unique domain (computation-intensive, no packet I/O). Strong signal that the framework generalizes to pure-compute BPF programs in the kernel.

### 5.3 Recommended Narrative Update

With P3 + P4:
> "We evaluate directive coverage across three BPF program domains: networking (60 production XDP/TC programs from Calico/Suricata), tracing (57 production kprobe/fentry/tp_btf programs from BCC libbpf-tools), and security/resource-control (6 cgroup/LSM programs from systemd). Our micro-benchmark suite covers XDP and cgroup_skb program types, and our directive scanner identifies optimization sites across all domains."

With P1 + P3 + P4:
> "...and we demonstrate measurable JIT speedups on both networking and tracing program types through fentry/fexit micro-benchmarks."

### 5.4 Key Risks

1. **Tracing programs may have very few directive sites**: If the bcc census shows near-zero CMOV/WIDE/ROTATE/LEA sites, it actually WEAKENS the generality argument. However, this is still valuable information -- it means the framework is specialized for networking, and the paper should acknowledge this honestly.

2. **fentry test_run limitation**: The kernel's `bpf_prog_test_run_tracing` runs all `bpf_fentry_test*` functions in sequence without repeat. Micro-benchmarking requires either (a) kernel-side modification to add repeat support, or (b) userspace-side looping with per-call syscall overhead. Neither is ideal.

3. **Program loading failures**: Many tracing programs require specific kernel functions/BTF types. Loading in a VM with a different kernel may fail.

### 5.5 What We Cannot Easily Cover

The following require real-world deployment and cannot be micro-benchmarked:
- **kprobe/kretprobe**: No test_run support, must trigger real kernel events
- **LSM**: No test_run, must trigger security hooks
- **cgroup (non-skb)**: No test_run for sysctl/sockopt/sock types
- **sockops/sk_msg/sk_skb**: No test_run, requires full socket infrastructure
- **sched_ext**: Requires CONFIG_SCHED_CLASS_EXT, deployment-specific

For these, the paper should state: "Code-size analysis covers all program types; exec-time evaluation is limited to program types supporting `bpf_prog_test_run`."

## 6. Answers to Key Questions

### Q: Can tracing programs use `bpf_prog_test_run`?
- **kprobe**: NO
- **fentry/fexit**: YES, but only with `bpf_fentry_test*` kernel functions, and no repeat support
- **raw_tracepoint**: YES, but no repeat/duration support (single invocation only)
- **tracepoint**: NO
- **tp_btf**: NO (uses tracepoint prog ops, not tracing prog ops)
- **perf_event**: NO

### Q: Are LSM programs testable?
NO. `lsm_prog_ops` has no `test_run`. Must trigger real security hooks.

### Q: Do these new scenarios expose different JIT patterns?
YES, based on analysis:
- **Helper call density**: Tracing programs have 2-3x higher helper-to-instruction ratio (6-11% vs 3-5%)
- **probe_read dominance**: Tracing programs use `bpf_probe_read_kernel/user` heavily (execsnoop: 62 calls), which is rare in networking programs
- **Program size**: Tracing programs are typically 100-2000 insns (vs 1000-40000 for production networking)
- **Context type**: `struct pt_regs` (kprobe), BTF types (fentry) vs `struct xdp_md`/`struct __sk_buff`
- **No packet bounds checks**: Tracing programs do not have `data < data_end` patterns

### Q: Do systemd LSM/cgroup programs have directive sites?
Very few. From the corpus-expansion-round2 data:
- 6 systemd programs total: 668 instructions
- 3 CMOV sites total (all in `restrict-ifaces.bpf.o` and `userns-restrict.bpf.o`)
- 0 WIDE, 0 ROTATE, 0 LEA
- Programs are too small (6-258 insns) for meaningful optimization

### Q: Are there kernel selftests with tracing/LSM/cgroup BPF programs?
YES, extensively:
- 361 compiled .bpf.o files in the linux-selftests corpus
- Includes: LSM (`lsm.bpf.o`, `lsm_cgroup.bpf.o`), cgroup (`cgroup_*.bpf.o`), fentry/fexit, struct_ops (TCP CC), iterators, raw_tracepoint, etc.
- Many are small test programs, but some (like `bpf_cubic.bpf.o`) are production-quality implementations
- Can be used for code-size directive census immediately

## 7. Summary Recommendations

### Immediate (before paper submission, 2-3 days):
1. **Run directive scanner on bcc corpus** (57 programs) -- adds cross-domain coverage table
2. **Add 2 cgroup_skb benchmarks** -- proves framework works beyond XDP with zero runner changes
3. **Run directive scanner on linux-selftests corpus** (361 programs) -- massive breadth

### Short-term (1-2 weeks):
4. **Add fentry micro-benchmarks** (3-4 programs) -- strongest generality evidence
5. **Add TCP CC struct_ops benchmark** (1-2 programs) -- unique computation-only domain

### Paper text changes:
- Add "Cross-domain directive census" table (networking vs tracing vs security)
- Add "BPF program types covered" discussion in evaluation section
- Acknowledge limitation: "Exec-time evaluation is limited to program types with bpf_prog_test_run support (XDP, TC, cg_skb, fentry); code-size analysis covers all types"
- Note that tracing programs have fundamentally different JIT profiles (helper-heavy, small, no packet bounds)
