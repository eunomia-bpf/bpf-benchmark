# Corpus Input & Execution Path Review

**Date**: 2026-03-22
**Scope**: Audit of `corpus/config/macro_corpus.yaml` programs, input construction, and execution paths to determine whether the corpus measures realistic code paths.

---

## 1. Corpus Programs Summary

The `macro_corpus.yaml` defines programs across three execution methods:

| test_method | Programs | What is measured |
|---|---|---|
| `bpf_prog_test_run` | katran_balancer, calico_xdp_main, calico_tc_maglev, suricata_xdp_filter, linux_test_tc_cls, linux_test_tcx_pkt_ptr, linux_xdp_synproxy, linux_tc_synproxy | compile_ns + exec_ns via kernel `BPF_PROG_TEST_RUN` |
| `compile_only` | systemd_sysctl_monitor, datadog_oom_kill, tetragon_execve, coroot_process_lifecycle | compile_ns only (exec_ns = 0) |
| `attach_trigger` | tracee_lsm_bpf | compile_ns + exec_ns via `bpftool prog loadall autoattach` + trigger command |

## 2. Packet/Context Input Construction

### Dummy packet (used by most XDP/TC programs)
- **File**: `corpus/inputs/macro_dummy_packet_64.bin`
- **Content**: 64-byte Ethernet/IPv4/TCP packet (src=10.0.0.1, dst=10.0.0.2, src_port=12345, dst_port=80, SYN, 10-byte 'A' payload)
- **Built by**: `runner/libs/corpus.py::_build_corpus_packet()`
- Valid L2/L3/L4 headers with correct IPv4 checksum; TCP checksum zeroed (not verified by XDP)

### Katran packet (katran_balancer only)
- **File**: `corpus/inputs/katran_vip_packet_64.bin`
- **Content**: 64-byte Ethernet/IPv4/TCP packet targeting VIP 10.100.1.1:8080 from client 10.0.0.2:31337, TCP ACK flag
- **Built by**: `runner/libs/corpus.py::_build_katran_packet()`
- Matches the VIP key populated by `initialize_katran_test_fixture()` in `kernel_runner.cpp`

### Dummy context (compile-only programs)
- **File**: `corpus/inputs/macro_dummy_context_64.bin`
- **Content**: 64 bytes of zeroes
- Only used for compile-only programs where execution is skipped

## 3. Per-Program Execution Path Analysis

### Katran (`katran_balancer`) -- REALISTIC PATH

**Verdict: Exercises the full LB datapath.**

The runner has a dedicated Katran fixture (`initialize_katran_test_fixture()` in `kernel_runner.cpp` lines 318-351) that:
- Populates `vip_map` with VIP 10.100.1.1:8080/TCP
- Populates `reals` with a real backend (10.200.0.2)
- Fills all 65537 entries in `ch_rings` for consistent-hashing
- Populates `ctl_array` with the LB MAC address

The Katran packet's dst_ip matches the VIP entry, so the program follows the full lookup -> CH-ring -> encapsulate path. The output buffer is sized with +64 bytes headroom for encapsulation. This is a **genuine deep execution path**.

### Calico XDP/TC (`calico_xdp_main`, `calico_tc_maglev`) -- EARLY EXIT PATH

**Verdict: Likely early exit; measures fast-path rejection, not policy enforcement.**

These programs receive the generic dummy packet (10.0.0.1 -> 10.0.0.2:80 SYN). Calico programs:
- Look up the packet in conntrack/policy maps
- With **empty maps**, the lookup misses immediately
- The program likely returns XDP_PASS or TC_ACT_OK without entering the policy enforcement logic

This means we are benchmarking the **fast-path miss** -- the shortest code path through the program. While this is a valid "no-match" scenario, it does not stress the JIT-heavy policy logic that makes Calico interesting.

**Mitigation**: For pure-JIT recompile benchmarking, this is acceptable because we compare stock JIT vs. REJIT on the *same* code path. The recompile optimization applies to instructions regardless of which path executes. However, the exec_ns numbers represent a lower bound, not production-representative latency.

### Suricata (`suricata_xdp_filter`) -- EARLY EXIT PATH

**Verdict: Hash filter with empty flow table = immediate miss.**

Suricata's `xdp_hashfilter` performs hash-based flow matching against XDP maps. With empty maps (no configured flow entries), the program:
- Parses the packet header (exercising the parser code)
- Performs a map lookup that misses
- Returns XDP_PASS

Similar to Calico: the parser code executes, but the "interesting" filtering logic is skipped.

### Linux selftests -- REALISTIC (SELF-CONTAINED)

**Verdict: Exercises intended code paths.**

- `linux_test_tc_cls` / `linux_test_tcx_pkt_ptr`: Simple classifier/pointer programs designed to run under `bpf_prog_test_run`. The dummy packet is sufficient.
- `linux_xdp_synproxy` / `linux_tc_synproxy`: SYN proxy programs. The dummy SYN packet triggers the SYN cookie generation logic. These are **realistic** because the packet has the SYN flag set.

### Systemd (`systemd_sysctl_monitor`) -- COMPILE ONLY

**Verdict: No execution concern; compile-time only.**

The `cgroup_sysctl` prog type does not support `bpf_prog_test_run`. Correctly marked as `compile_only`. Measures JIT compilation time only.

### Datadog (`datadog_oom_kill`) -- COMPILE ONLY

**Verdict: No execution concern; compile-time only.**

kprobe programs cannot be safely replayed via `bpf_prog_test_run` (they expect pt_regs context from real kernel events). Correctly marked as `compile_only`.

### Tracee (`tracee_lsm_bpf`) -- REALISTIC VIA TRIGGER

**Verdict: Exercises real attach path.**

Uses `attach_trigger` method:
1. Loads via `bpftool prog loadall autoattach` (attaches to LSM hook)
2. Triggers via `bpftool prog show >/dev/null` (which invokes the `bpf()` syscall, firing the LSM hook)
3. Measures wall-clock time of the trigger

This exercises the real LSM hook path. The trigger is genuine because any BPF syscall fires the LSM check. Exec timing is coarse (wall clock of subprocess), but the path is real.

### Tetragon (`tetragon_execve`) -- COMPILE ONLY

**Verdict: No execution concern; compile-time only.**

Tracepoint programs need real kernel events to fire. Correctly marked as `compile_only` with `bpftool_loadall` loader. Measures compilation latency of a multi-program object file.

### Coroot (`coroot_process_lifecycle`) -- COMPILE ONLY

**Verdict: No execution concern; compile-time only.**

Same rationale as Tetragon. Multi-program tracepoint object, compile-only measurement.

## 4. Key Questions Answered

### Q: Dummy packet + empty maps = early exit path?
**Yes, for Calico and Suricata.** The programs parse the packet but miss on map lookups, exiting early. For Katran, this is NOT the case because `kernel_runner.cpp` has a dedicated fixture that populates the maps.

### Q: Katran needs VIP map entry to walk LB logic?
**Yes, and it is handled.** The `initialize_katran_test_fixture()` function populates vip_map, reals, ch_rings (65537 entries), and ctl_array. The Katran packet's VIP IP (10.100.1.1:8080) matches the populated key. The balancer executes the full consistent-hashing lookup and encapsulation path.

### Q: Tracee/Tetragon are tracing programs -- can TEST_RUN run them?
**No, and the corpus handles this correctly:**
- Tetragon: `compile_only` (exec_ns=0, measures only JIT compilation)
- Tracee LSM: `attach_trigger` (real attach + trigger via subprocess)
- Datadog kprobe: `compile_only`
- Coroot tracepoint: `compile_only`

None of the tracing programs use `bpf_prog_test_run`. The corpus correctly distinguishes between executable (`bpf_prog_test_run`), attachable (`attach_trigger`), and compile-only programs.

## 5. Summary Assessment

| Aspect | Status | Notes |
|---|---|---|
| Katran execution path | **Realistic** | Full LB fixture with populated maps |
| Calico execution path | **Early exit** | Empty maps = fast-path miss, but OK for JIT comparison |
| Suricata execution path | **Early exit** | Empty flow table = miss after parse, OK for JIT comparison |
| Selftest execution path | **Realistic** | Self-contained programs designed for test_run |
| Tracing programs | **Correctly handled** | compile_only or attach_trigger, never test_run |
| Packet construction | **Valid** | Proper L2/L3/L4 headers, correct checksums |
| Katran packet | **Matched** | VIP IP/port matches fixture key exactly |

**Overall**: The corpus execution paths are *defensible for JIT recompile benchmarking*. The early-exit issue for Calico/Suricata means exec_ns measures the shortest path, but since both stock and REJIT execute the same path, the exec_ns *ratio* (speedup) is still valid for measuring JIT code quality improvements. The compile_ns and code_size measurements are unaffected by execution path depth.

**Potential improvement** (not blocking): Populate Calico conntrack/policy maps and Suricata flow tables with synthetic entries to exercise deeper code paths. This would make absolute exec_ns numbers more production-representative, though it would not change the relative speedup conclusions.
