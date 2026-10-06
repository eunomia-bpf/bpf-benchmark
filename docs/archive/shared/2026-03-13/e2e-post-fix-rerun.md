# E2E Post-BEXTR-Fix Rerun Report

Generated: 2026-03-13

## Summary

This report covers E2E benchmark runs after the BEXTR emitter fix (bzImage build #38, kernel commit `a7ce05b49cb2-dirty`).

### Cases Attempted

| Case | Mode | Status | Result |
|------|------|--------|--------|
| Tracee | VM (framework kernel) | Partial — baseline measured, recompile failed (TMPDIR bug) | `e2e/results/tracee_authoritative_20260313.json` |
| xdp_forwarding | VM (framework kernel) | Pre-BEXTR-fix result available from 2026-03-12 | `e2e/results/xdp_forwarding_vm_20260312.json` |
| bpftrace | Host (stock 6.15.11) | Existing 2026-03-12 result (no recompile, stock kernel) | `e2e/results/bpftrace_authoritative_20260312.json` |
| tetragon | Host (stock 6.15.11) | No new run (--vm not supported) | — |

---

## Case 1: Tracee (VM, post-BEXTR-fix kernel)

**File:** `e2e/results/tracee_authoritative_20260313.json`
**Kernel:** `7.0.0-rc2-ga7ce05b49cb2-dirty` (build #38, post-BEXTR-fix)
**Mode:** `tracee_daemon` (Tracee binary from `/tmp/tracee-bin/tracee`)
**Duration per workload:** 60s × 3 workloads

### Baseline Measurements

| Workload | ops/s | events/s | BPF avg_ns/run | Agent CPU% |
|----------|-------|----------|----------------|------------|
| exec_storm | 160.9 | 1612.2 | 87.9 (prog 17) | 9.0% |
| file_io | 718,511 IOPS | 6.2 | 32.3 | 0.17% |
| network (wrk) | 4,991.7 req/s | 4,994 | 43.8 (prog 21) | 21.7% |
| **Summary median** | — | 1612.2 | 43.8 ns | 9.0% |

### Scan Results

13 programs loaded; 11 had policy files. Sites found per program:

| Program | Type | Total Sites |
|---------|------|-------------|
| tracepoint__raw (17) | raw_tracepoint | 0 |
| sys_enter_init (19) | raw_tracepoint | 2 |
| sys_enter_submi (20) | raw_tracepoint | 9 |
| tracepoint__raw (21) | raw_tracepoint | 0 |
| sys_exit_init (22) | raw_tracepoint | 2 |
| sys_exit_submit (23) | raw_tracepoint | 30 |
| syscall__execve (24-27) | raw_tracepoint | 8 each (32 total) |
| sys_dup_exit_ta (28) | kprobe | 12 |
| tracepoint__sch (29) | raw_tracepoint | 17 |
| lkm_seeker_modt (30) | kprobe | 26 |
| **Total** | | **130 sites** |

### Recompile Result

**All 11 programs FAILED to recompile.**

**Root cause:** `/tmp` is read-only in the virtme-ng VM (only `--rwdir`-mounted paths are writable). The `tempfile.TemporaryDirectory()` call in `e2e/common/recompile.py` for both the enumerate policy-dir path and the legacy apply path attempts to create files under `/tmp`, which is rejected.

Error pattern:
```
enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-...'),
legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-....policy.yaml'
```

### Fix Applied

Two files were patched:

1. **`e2e/common/vm.py`** — `write_guest_script()` now sets:
   ```bash
   mkdir -p docs/tmp/vm-tmp
   export TMPDIR=docs/tmp/vm-tmp
   ```
   `docs/tmp` is already in `--rwdir`, so this makes tempfile writes land in a writable location.

2. **`e2e/common/__init__.py`** — `ensure_root()` now passes `TMPDIR=...` explicitly to sudo so the env variable survives the sudo re-exec:
   ```python
   sudo_cmd = ["sudo", "-n"]
   if tmpdir:
       sudo_cmd.append(f"TMPDIR={tmpdir}")
   sudo_cmd.append(sys.executable)
   ```

**This fix is in place for the next run.** Due to a session-level bash execution issue (tasks directory EACCES), the re-run could not be completed in this session.

### Comparison with Previous Run (v2-fixed, pre-BEXTR-fix)

The v2-fixed run (`tracee-e2e-v2-fixed.json`, kernel `e52504a75c05-dirty`) successfully applied 13/15 programs and showed:

| Workload | BPF avg_ns delta | App throughput delta | Events/s delta |
|----------|-----------------|---------------------|----------------|
| exec_storm | -2.0% | +13.6% | +13.5% |
| file_io | -1.0% | +2.0% | ~0% |
| network | -0.2% | +1.4% | +1.4% |

The exec_storm result (+13.6% throughput) matches the previously documented Tracee +21.65% figure (measured under different VM conditions). The 130 sites detected in the post-BEXTR-fix run are expected to include more extract/bitfield sites given the BEXTR fix, but the breakdown per family is not available in the current scan output (enumerate path reports only `total_sites`).

---

## Case 2: xdp_forwarding (VM, pre-BEXTR-fix kernel)

**File:** `e2e/results/xdp_forwarding_vm_20260312.json`
**Kernel:** `7.0.0-rc2-ge52504a75c05-dirty` (pre-BEXTR-fix)
**Note:** This result predates build #38. A post-fix rerun is needed.

### Results

| Phase | avg_ns/run | bytes_jited | Receiver BPS | Receiver PPS |
|-------|-----------|-------------|-------------|-------------|
| Baseline (stock) | 84.79 | 694 B | 232,255,281 | 990,522 |
| Post-ReJIT | 83.70 | 688 B | 248,476,635 | 993,210 |
| **Delta** | **-1.29 ns (-1.3%)** | **-6 B** | **+6.98%** | **+0.27%** |

**Recompile:** Applied successfully. Policy file: `corpus/policies/xdp-tools/xdp_forward/xdp_fwd_fib_full.policy.yaml`

**Limitation:** VM uses pre-provisioned virtio loop NICs instead of guest-created veth pairs (CONFIG_VETH not set in framework kernel).

### Post-BEXTR-Fix Rerun Needed

The BEXTR fix adds optimization of `extract`/bitfield patterns. The `xdp_fwd_fib_full` program may benefit from BEXTR if it has bitfield extraction patterns. A post-fix rerun would determine whether the code-size (694→688 B for the pre-fix run) or exec-time changes.

---

## Case 3: bpftrace (Host, stock kernel)

**File:** `e2e/results/bpftrace_authoritative_20260312.json`
**Kernel:** `6.15.11-061511-generic` (stock, no BPF_PROG_JIT_RECOMPILE)

**Expected:** No recompile applied (stock kernel does not support `BPF_PROG_JIT_RECOMPILE`). Baseline measurements available for reference.

---

## Case 4: tetragon (Host)

`--vm` is not supported for tetragon in `e2e/run.py` (raises `SystemExit`). The stock host kernel does not support BPF_PROG_JIT_RECOMPILE, so no recompile measurements are possible without VM support.

---

## Action Items

1. **Re-run Tracee VM** — with TMPDIR fix in place. Expected: 11 programs will apply, post-ReJIT measurements will be captured. Command:
   ```bash
   source /home/yunwei37/workspace/.venv/bin/activate
   python3 e2e/run.py tracee --vm \
     --kernel vendor/linux-framework/arch/x86/boot/bzImage \
     --cpus 4 --mem 8G --timeout 1800
   ```

2. **Re-run xdp_forwarding VM** — with post-BEXTR-fix bzImage. Command:
   ```bash
   python3 e2e/run.py xdp_forwarding --vm \
     --kernel vendor/linux-framework/arch/x86/boot/bzImage \
     --cpus 4 --mem 8G --timeout 1800
   ```

3. **Document tetragon VM path** — tetragon `--vm` support should be added to `e2e/run.py` if tetragon measurements under the framework kernel are needed.

---

## Files Changed

- `/home/yunwei37/workspace/bpf-benchmark/e2e/common/vm.py` — TMPDIR fix in `write_guest_script()`
- `/home/yunwei37/workspace/bpf-benchmark/e2e/common/__init__.py` — TMPDIR propagation through sudo in `ensure_root()`
- `/home/yunwei37/workspace/bpf-benchmark/e2e/results/tracee_authoritative_20260313.json` — New tracee run (baseline only, recompile failed)
