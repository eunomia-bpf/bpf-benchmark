# REJIT hot-swap stress tests review (2026-03-26)

## Scope and method

Reviewed files:

- `tests/unittest/rejit_hotswap_common.h`
- `tests/unittest/rejit_hotswap_tracepoint.c` + `tests/unittest/progs/test_hotswap_tracepoint.bpf.c`
- `tests/unittest/rejit_hotswap_kprobe.c` + `tests/unittest/progs/test_hotswap_kprobe.bpf.c`
- `tests/unittest/rejit_hotswap_perf_event.c` + `tests/unittest/progs/test_hotswap_perf_event.bpf.c`
- `tests/unittest/rejit_hotswap_fentry.c` + `tests/unittest/progs/test_hotswap_fentry.bpf.c`
- `tests/unittest/rejit_hotswap_lsm.c` + `tests/unittest/progs/test_hotswap_lsm.bpf.c`
- `tests/unittest/rejit_hotswap_xdp.c` + `tests/unittest/progs/test_hotswap_xdp.bpf.c`
- `tests/unittest/rejit_hotswap_socket_filter.c` + `tests/unittest/progs/test_hotswap_socket_filter.bpf.c`
- `tests/unittest/rejit_hotswap_sched_cls.c` + `tests/unittest/progs/test_hotswap_sched_cls.bpf.c`
- `tests/unittest/rejit_hotswap_cgroup_skb.c` + `tests/unittest/progs/test_hotswap_cgroup_skb.bpf.c`
- `tests/unittest/rejit_hotswap_struct_ops.c` + `tests/unittest/progs/test_hotswap_struct_ops.bpf.c`
- `tests/unittest/rejit_hotswap_ext.c` + `tests/unittest/progs/test_hotswap_ext.bpf.c` + `tests/unittest/progs/test_hotswap_ext_target.bpf.c`
- `tests/unittest/rejit_hotswap_sk_lookup.c` + `tests/unittest/progs/test_hotswap_sk_lookup.bpf.c`

Method:

- Read all unittest control flow and all BPF source.
- Inspected shared patch helpers in `rejit_hotswap_common.h`.
- Inspected shipped compiled objects with `llvm-objdump -dr tests/unittest/build/progs/test_hotswap*.bpf.o` to verify the patch helper assumptions against the actual instruction shape.
- No code was modified.

## Executive summary

Bottom line: these 12 tests do **not** honestly prove that "REJIT can correctly hot-swap all major prog types".

What is solid:

- `tracepoint`, `kprobe`, `perf_event`, `xdp`, `socket_filter`, `sched_cls` are real live-attach tests with real traffic/event drivers and real post-REJIT behavior checks.
- `fentry` and `lsm` are also real live-attach tests when they run, but both have environment/skip caveats.

What is weak:

- `cgroup_skb` and `struct_ops` do test a live attached program, but their post-REJIT checks only require seeing one expected result; they do not prove the old behavior disappeared.

What is not acceptable as hot-swap proof:

- `ext` is not testing live hot-swap at all. It destroys the old EXT instance, loads a fresh one, REJITs it **before attach**, and only then attaches it. That is reload + pre-attach REJIT, not hot-swap.
- `sk_lookup` is the worst case. The verification is weak, and the shipped object strongly suggests the patch helper does not even reach the real key store instruction.

## Common helper review

`tests/unittest/rejit_hotswap_common.h` is the backbone of most tests.

- `hotswap_patch_return_imm()` is fine for the simple return-only programs used by `cgroup_skb`, `socket_filter`, `sched_cls`, and `ext`. Their objects are literally `r0 = imm; exit`.
- `hotswap_patch_atomic_add_imm()` is fine for the `total += 1` pattern used by `kprobe`, `perf_event`, `fentry`, `lsm`, and `xdp`. In the shipped objects, `total` is updated by `lock *(u64 *)(r0 + 0x0) += r2` and the immediate `1` is loaded into `r2` right before it, so the helper does hit the right instruction.
- `hotswap_patch_map_value_store_imm()` is fine for `struct_ops`. In the shipped object the init callback does `r1 = 0x457` followed by `*(u64 *)(r0 + 0x0) = r1`; the helper matches that pattern.
- `hotswap_patch_stack_map_key()` is brittle, and for `sk_lookup` it looks wrong. It only scans the 8 instructions before `bpf_map_lookup_elem()`, but in `test_hotswap_sk_lookup.bpf.o` the key store `*(u32 *)(r10 - 0x4) = r2` is much earlier than that.

## Per-test review

### 1. tracepoint

Files:

- `tests/unittest/rejit_hotswap_tracepoint.c`
- `tests/unittest/progs/test_hotswap_tracepoint.bpf.c`

Assessment:

- Q1 attach + continuous execution: **Yes.** The program is attached with `bpf_program__attach()` (`tracepoint.c`, around `L283-L288`). A worker thread loops on `syscall(__NR_getpid)` (`L219-L227`, `L302-L306`), so the tracepoint is continuously firing.
- Q2 REJIT changes behavior: **Yes.** The BPF program increments `stats->total` and `stats->events` by 1 (`.bpf.c`, `L28-L29`). `patch_total_delta()` rewrites the `total` add immediate to `2` or `1` (`tracepoint.c`, `L130-L152`, loop at `L313-L337`).
- Q3 test verifies the change: **Yes.** `wait_for_expected_delta()` checks that `total_delta / event_delta` converges to the expected ratio (`L176-L217`).
- Q4 PASS with no real verification: **No.** If REJIT succeeds but behavior does not change, the ratio check for `expected=2` times out.
- Q5 TEST_SKIP bypass: **No.**
- Q6 patch may hit wrong instruction: **Low risk / looks correct.** The object shows `r2 = 1` immediately before `lock *(u64 *)(r0 + 0x0) += r2`.
- Q7 ext special mode: **N/A.**

Verdict: **Strong live hot-swap test.**

### 2. kprobe

Files:

- `tests/unittest/rejit_hotswap_kprobe.c`
- `tests/unittest/progs/test_hotswap_kprobe.bpf.c`

Assessment:

- Q1: **Yes.** Attached with `bpf_program__attach()` (`kprobe.c`, `L182-L187`), worker thread loops on `getpid` (`L116-L124`, `L201-L205`).
- Q2: **Yes.** Patches `total += 1` to `total += 2` with `hotswap_patch_atomic_add_imm()` (`L215-L221`).
- Q3: **Yes.** Same ratio-based verification as tracepoint (`L73-L114`, `L232-L236`).
- Q4: **No.** A no-op REJIT would fail the `expected=2` ratio check.
- Q5: **No TEST_SKIP.**
- Q6: **Patch logic matches the shipped object.** `total` uses the `r2` immediate right before the atomic add.
- Q7: **N/A.**

Verdict: **Strong live hot-swap test.**

### 3. perf_event

Files:

- `tests/unittest/rejit_hotswap_perf_event.c`
- `tests/unittest/progs/test_hotswap_perf_event.bpf.c`

Assessment:

- Q1: **Yes.** Attached with `bpf_program__attach_perf_event()` (`perf_event.c`, `L350-L355`). There is no worker thread, but `wait_for_expected_delta()` actively drives the workload itself via busy loop or induced page faults (`L132-L182`, `L201-L220`), so the program is genuinely executed.
- Q2: **Yes.** Patches `total += 1` to `total += 2` (`L378-L384`).
- Q3: **Yes.** Ratio-based validation (`L184-L230`).
- Q4: **No.** If the behavior stays at `1`, the `expected=2` check fails.
- Q5: **No TEST_SKIP.**
- Q6: **Patch logic matches the shipped object.**
- Q7: **N/A.**

Verdict: **Strong live hot-swap test.**

### 4. fentry

Files:

- `tests/unittest/rejit_hotswap_fentry.c`
- `tests/unittest/progs/test_hotswap_fentry.bpf.c`

Assessment:

- Q1: **Yes when it runs.** Attached with `bpf_link_create(..., BPF_TRACE_FENTRY, ...)` (`fentry.c`, `L257-L261`). Worker thread loops on `getpid` (`L122-L130`, `L289-L293`).
- Q2: **Yes when it runs.** Patches `total += 1` to `2` or `1` (`L303-L309`).
- Q3: **Yes when it runs.** Uses the same ratio-based wait (`L79-L120`, `L325-L329`).
- Q4: **If it reaches PASS, it did verify a behavior change.** This is not a fake PASS test.
- Q5 TEST_SKIP: **Yes, heavily.** The test explicitly converts missing/unstable tracing attach BTF context into `TEST_SKIP` in preflight (`L269-L276`) and again inside the main REJIT loop (`L312-L323`).
- Q6: **Patch logic itself looks correct** for the add immediate.
- Q7: **N/A.**

Verdict: **Real live hot-swap test, but coverage is conditional.** On kernels where attached fentry REJIT loses attach BTF context, the suite stays green by skipping the entire proof.

### 5. lsm

Files:

- `tests/unittest/rejit_hotswap_lsm.c`
- `tests/unittest/progs/test_hotswap_lsm.bpf.c`

Assessment:

- Q1: **Yes when it runs.** Attached with `bpf_program__attach_lsm()` (`lsm.c`, `L263-L268`). There is no worker thread, but the wait loop repeatedly opens the temp file 32 times per batch to trigger `file_open` (`L135-L193`).
- Q2: **Yes.** Patches `total += 1` to `2` or `1` (`L291-L297`).
- Q3: **Yes.** Ratio-based validation (`L175-L192`).
- Q4: **If it reaches PASS, it did verify the ratio change.**
- Q5 TEST_SKIP: **Yes.** If BPF LSM is not active, the whole test is skipped (`L85-L118`, `L227-L230`).
- Q6: **Patch logic matches the shipped object.**
- Q7: **N/A.**

Verdict: **Real live hot-swap test when environment supports it.** But a green run on a host without active BPF LSM proves nothing about LSM hot-swap.

### 6. xdp

Files:

- `tests/unittest/rejit_hotswap_xdp.c`
- `tests/unittest/progs/test_hotswap_xdp.bpf.c`

Assessment:

- Q1: **Yes.** Attached with `bpf_xdp_attach()` on a veth ingress interface (`xdp.c`, `L287-L291`). A worker thread continuously sends raw Ethernet frames from the peer interface (`L168-L205`, `L317-L321`).
- Q2: **Yes.** Patches `total += 1` to `2` or `1` (`L334-L340`).
- Q3: **Yes.** Ratio-based validation (`L85-L126`, `L351-L359`).
- Q4: **No fake PASS.** A no-op REJIT fails the `expected=2` check.
- Q5: **No TEST_SKIP.**
- Q6: **Patch logic matches the shipped object.**
- Q7: **N/A.**

Verdict: **Strong live hot-swap test.**

### 7. socket_filter

Files:

- `tests/unittest/rejit_hotswap_socket_filter.c`
- `tests/unittest/progs/test_hotswap_socket_filter.bpf.c`

Assessment:

- Q1: **Yes.** The program is attached to the AF_PACKET capture socket with `SO_ATTACH_BPF` (`socket_filter.c`, `L243-L247`). A worker thread continuously sends UDP packets on loopback (`L153-L180`, `L261-L265`).
- Q2: **Yes.** The BPF program originally returns `0xffff` (accept full packet). REJIT alternates that with `64`, which truncates the captured packet (`L273-L289`).
- Q3: **Yes.** `wait_for_packet_shape()` checks for full packet length versus exact truncated length 64 (`L107-L151`, `L291-L296`).
- Q4: **No fake PASS.** If REJIT does not change the filter return value, the wrong packet shape is observed and the round fails.
- Q5: **No TEST_SKIP.**
- Q6: **Patch logic is correct** for this object: `r0 = imm; exit`.
- Q7: **N/A.**

Verdict: **Strong live hot-swap test.**

### 8. sched_cls

Files:

- `tests/unittest/rejit_hotswap_sched_cls.c`
- `tests/unittest/progs/test_hotswap_sched_cls.bpf.c`

Assessment:

- Q1: **Yes.** Attached with `bpf_tc_attach()` on ingress (`sched_cls.c`, `L431-L449`). A child process in a separate netns continuously sends UDP packets through the peer veth (`L246-L321`, `L463-L466`).
- Q2: **Yes.** The BPF program originally returns `TC_ACT_OK`. REJIT alternates between `TC_ACT_SHOT` and `TC_ACT_OK` (`L479-L492`).
- Q3: **Yes.** The test alternates between asserting "no packet arrives" and "a packet arrives" (`L494-L510`).
- Q4: **No fake PASS.** If behavior does not change, either the first drop round or the first allow round fails.
- Q5: **No TEST_SKIP.**
- Q6: **Patch logic is correct** for this object: `r0 = imm; exit`.
- Q7: **N/A.**

Verdict: **Strong live hot-swap test.**

### 9. cgroup_skb

Files:

- `tests/unittest/rejit_hotswap_cgroup_skb.c`
- `tests/unittest/progs/test_hotswap_cgroup_skb.bpf.c`

Assessment:

- Q1: **Yes.** Attached with `bpf_program__attach_cgroup()` (`cgroup_skb.c`, `L287-L292`). The current process is moved into the child cgroup (`L306-L310`), and a worker thread continuously sends UDP packets (`L168-L202`, `L312-L316`).
- Q2: **Yes.** The BPF program originally returns `1` (allow). REJIT alternates between `0` and `1` (`L323-L339`).
- Q3: **Partially.** `wait_for_send_mode()` only checks whether it sees at least one send success or at least one `EPERM` after the round starts (`L135-L166`, `L341-L345`).
- Q4 PASS with weak verification: **Yes, potentially.** If behavior after REJIT is mixed or flapping, the test still passes as soon as it sees one packet with the expected outcome. It never asserts that the opposite outcome disappeared.
- Q5: **No TEST_SKIP.**
- Q6: **Patch logic is correct** for this object.
- Q7: **N/A.**

Verdict: **Live hot-swap test, but post-REJIT validation is weak.**

### 10. struct_ops

Files:

- `tests/unittest/rejit_hotswap_struct_ops.c`
- `tests/unittest/progs/test_hotswap_struct_ops.bpf.c`

Assessment:

- Q1: **Yes.** `bpf_map__attach_struct_ops()` attaches the congestion-control ops (`struct_ops.c`, `L305-L310`). A worker thread repeatedly creates TCP sockets and sets `TCP_CONGESTION` to `rjhtswp`, which triggers the `.init` callback (`L197-L234`, `L336-L340`). An accept thread keeps the listener drained.
- Q2: **Yes.** The init callback originally writes `1111` to `value_map`; REJIT alternates that with `2222` (`.bpf.c`, `L20-L23`; test loop `L354-L386`).
- Q3: **Partially.** After each REJIT the test resets the map to `0` and waits until the map equals the expected value once (`L373-L383`).
- Q4 PASS with weak verification: **Yes, potentially.** One expected write is enough. If old and new callbacks both continue to fire after REJIT, this test can still pass.
- Q5: **No TEST_SKIP.**
- Q6: **Patch logic matches the shipped object.**
- Q7: **N/A.**

Verdict: **Live hot-swap test, but the assertion is too weak to prove clean convergence to the new behavior.**

### 11. ext

Files:

- `tests/unittest/rejit_hotswap_ext.c`
- `tests/unittest/progs/test_hotswap_ext.bpf.c`
- `tests/unittest/progs/test_hotswap_ext_target.bpf.c`

Assessment:

- Q1 attach + continuous execution: **Not in the sense claimed by hot-swap tests.** The target program is loaded once, but there is no continuous worker. The test drives execution synchronously with `bpf_prog_test_run_opts()` (`ext.c`, `L55-L70`, `L72-L103`).
- Q2 REJIT changes behavior: **Yes, but only on a freshly loaded unattached EXT program.** `load_rejit_attach_ext()` loads a new EXT object, patches its return value, calls `BPF_PROG_REJIT`, and only then attaches it (`L105-L193`).
- Q3 verifies changed behavior: **Yes, but it verifies the behavior of the newly attached instance, not a live hot-swapped instance.**
- Q4 PASS with no real hot-swap verification: **Yes.** A PASS here does not prove live REJIT hot-swap at all.
- Q5 TEST_SKIP: **No.**
- Q6 patch logic: **The return-value patch itself is correct** for the EXT object, but that is beside the main problem.
- Q7 ext special mode: **This test explicitly bypasses live hot-swap.** The code comment at `L166-L170` says attached EXT programs lose the freplace target context, so the test REJITs before attach. The outer loop destroys the old instance before each round (`L254`) and loads a fresh one (`L255-L259`).

Verdict: **Not a hot-swap test.** This is reload + pre-attach REJIT + reattach.

### 12. sk_lookup

Files:

- `tests/unittest/rejit_hotswap_sk_lookup.c`
- `tests/unittest/progs/test_hotswap_sk_lookup.bpf.c`

Assessment:

- Q1: **Yes.** Attached with `bpf_program__attach_netns()` (`sk_lookup.c`, `L302-L307`). A client worker continuously connects, and an accept worker observes both listeners (`L131-L181`, `L183-L212`, `L321-L331`).
- Q2 REJIT changes behavior: **Intended yes, but likely not in the shipped build.** The test wants to change the sockmap lookup key from `0` to `1` with `hotswap_patch_stack_map_key()` (`L341-L347`).
- Q3 verifies changed behavior: **Weakly.** It only waits for the expected listener to accept at least one connection (`L105-L129`, `L358-L362`).
- Q4 PASS with insufficient verification: **Yes, potentially.** The test never checks that the non-expected listener stopped accepting, so mixed routing can pass. More importantly, the observed condition is also compatible with generic `SO_REUSEPORT` distribution if the BPF steering path is ineffective.
- Q5 TEST_SKIP: **No.**
- Q6 patch logic may miss the real instruction: **Yes, this looks like a real bug.** In the shipped `test_hotswap_sk_lookup.bpf.o`, the key store is:
  - insn 0: `r2 = 0`
  - insn 1: `*(u32 *)(r10 - 0x4) = r2`
  - insn 14: `call bpf_map_lookup_elem`

  But `hotswap_patch_stack_map_key()` only scans from `i - 1` down to `i - 8`. That search window does not reach insn 1. Unless `BPF_OBJ_GET_INFO_BY_FD` returns a materially different instruction order than the shipped object, this helper cannot patch the actual key definition.
- Q7 ext special mode: **N/A.**

Verdict: **Not trustworthy.** The validation is weak, and the patch logic itself likely misses the intended instruction.

## Findings

### CRITICAL

1. `rejit_hotswap_ext` is not testing hot-swap.
   - Evidence: each round destroys the old EXT instance first (`tests/unittest/rejit_hotswap_ext.c`, `L254`), then loads a fresh one and calls REJIT before attach (`L166-L178`, `L255-L259`).
   - Impact: a PASS says nothing about live attached EXT hot-swap correctness.

2. `rejit_hotswap_sk_lookup` likely patches the wrong place, or nothing at all.
   - Evidence: `hotswap_patch_stack_map_key()` only scans the 8 instructions before `bpf_map_lookup_elem()` (`tests/unittest/rejit_hotswap_common.h`, `L231-L251`), but the shipped object places the key store much earlier.
   - Impact: the test may never actually change the live program's behavior.

### HIGH

1. `rejit_hotswap_fentry` can skip the entire hot-swap proof on kernels where attached fentry REJIT loses tracing attach BTF context.
   - Evidence: `TEST_SKIP` in preflight (`tests/unittest/rejit_hotswap_fentry.c`, `L269-L276`) and in the main loop (`L312-L323`).
   - Impact: a green suite can include "fentry unverified".

2. `rejit_hotswap_sk_lookup` does not prove exclusive steering after REJIT.
   - Evidence: it only waits for `accepted[expected_idx]` to increase (`tests/unittest/rejit_hotswap_sk_lookup.c`, `L105-L129`).
   - Impact: mixed routing can pass.

### MEDIUM

1. `rejit_hotswap_cgroup_skb` only looks for one expected send result after each REJIT.
   - Evidence: `wait_for_send_mode()` returns on the first success or first `EPERM` (`tests/unittest/rejit_hotswap_cgroup_skb.c`, `L143-L166`).
   - Impact: mixed allow/deny behavior can pass.

2. `rejit_hotswap_struct_ops` only looks for one expected map write after each REJIT.
   - Evidence: `wait_for_map_value()` returns as soon as `value_map == expected` once (`tests/unittest/rejit_hotswap_struct_ops.c`, `L87-L115`).
   - Impact: old and new callbacks could both still be running and the test would not detect it.

3. `rejit_hotswap_lsm` can be skipped entirely on hosts where BPF LSM is not active.
   - Evidence: `TEST_SKIP` on `!bpf_lsm_is_active()` (`tests/unittest/rejit_hotswap_lsm.c`, `L227-L230`).
   - Impact: a green suite on such a host does not cover LSM at all.

## Which tests can PASS without really proving REJIT behavior changed?

Strict answer:

- **Definitely yes:** `ext`
  - PASS only proves "fresh load -> pre-attach REJIT -> attach -> target retval changed".
  - It does **not** prove live hot-swap.

- **Potentially yes because verification is too weak:** `cgroup_skb`, `struct_ops`, `sk_lookup`
  - `cgroup_skb`: one expected send outcome is enough.
  - `struct_ops`: one expected map write is enough.
  - `sk_lookup`: one accept on the expected listener is enough; it never asserts the other listener stopped receiving.

- **No, not in the obvious no-op sense:** `tracepoint`, `kprobe`, `perf_event`, `fentry` (when not skipped), `lsm` (when not skipped), `xdp`, `socket_filter`, `sched_cls`
  - These tests would fail if REJIT returns success but the behavior remains completely unchanged.

## TEST_SKIP usage

Tests using `TEST_SKIP` to bypass validation:

- `fentry`
  - Yes. This is a direct bypass of the key claim on kernels where attached fentry REJIT cannot preserve tracing attach context.

- `lsm`
  - Yes, but this is environment-gating rather than test-body cheating. Still, the result is the same: green does not imply LSM was verified.

No other test in this set uses `TEST_SKIP`.

## Overall conclusion

These 12 tests do **not** justify the statement:

> "REJIT can correctly hot-swap all major prog types."

More defensible statement:

- There is good evidence for live hot-swap correctness in several prog types: `tracepoint`, `kprobe`, `perf_event`, `xdp`, `socket_filter`, `sched_cls`.
- `fentry` and `lsm` provide evidence only on environments where they actually run instead of skipping.
- `cgroup_skb` and `struct_ops` exercise live attached programs, but their assertions are not strong enough to prove clean post-REJIT convergence.
- `ext` does not test hot-swap.
- `sk_lookup` is not trustworthy as written.

Strict verdict:

- **No, the current 12-test set does not honestly prove full REJIT hot-swap correctness across all listed prog types.**
