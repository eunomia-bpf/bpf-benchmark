# Verified path on the hottest programs (2026-11-17, omp)

Todo item 4: for each application, the hottest program's B generation and stock verification, on the one
kernel, one image and one base. Entry point is the whole-app checked-sim-c target
(`make -C kprog/libnativeloader checked-corpus CHECKED_APP=<app>`), which runs the registered service in a
guest; the service generates B for each submitted P, the stock verifier checks B, and the frozen corpus runs
the app with natives installed at load.

## The base had to be refreshed first (two stale pieces, both in place)

Both were older than the loader core they must answer, so every replacement failed before any verification:
BCC's first run (`203012_406070`) installed **0** natives and logged 25 `native-loader failed
... error=native_kernel: invalid immutable-map metadata: 0xffffce9680e7e000`.

- **Loader**: `/workspaces/.agent-state/kprog-ck/verified-loader` was built 2026-11-16 09:03, before
  `4c32e2ac1`, `d6b4d335e`, `6066b311b` and `8b31e4533`. Rebuilt in place with
  `make -C kprog/libnativeloader trusted-service BUILD_DIR=/workspaces/.agent-state/kprog-ck/verified-loader`
  (20:27Z, sha256 `430a337f…`).
- **Module**: `verified-module/bpf_x86_native_lab.ko` was 2026-11-15 12:23, before `e4cd3a12b` taught the
  loader to read the module's two-field `map_value_ptr` reply (`"0x%llx %u"`, frozen bit). The old module
  answers `"0x%llx"` only, so `lookup_native_lab_ptr_by_fd` (`native_loader.cpp:480`) rejected the trailing
  field. Rebuilt in place with
  `make -C kprog/stock-path/module MO=/workspaces/.agent-state/kprog-ck/verified-module`
  (20:44Z, sha256 `317e2e9a…`).
- The checked-sim-c compiler tools did not need a rebuild: their sources predate the 2026-11-16 16:21 build.

Raw runs live under `/workspaces/kprog-raw/verified/20261117-checked-hot/<app>/` (started, finished,
exit-code, `service.tar.gz`, per-request archives); each run's corpus data is under
`corpus/results/x86_kvm_corpus_*`. Running image `bpf-benchmark/kprog:current` = `55c1c443` (build input is
the working tree, unchanged by these runs).

## BCC (bcc/set)

Run `x86_kvm_corpus_20261117_204607_412064`, 1 sample × 10 s, stats on, exit code 0, 20:44:25–20:51:05Z.

- 25 submitted programs, **25 verified and installed**, 15 distinct native bodies, zero failures, zero
  fallbacks: every request journal line has `execution_path=checked-sim-c`, `b_generated=true`,
  `b_stock_passed=true`, `status=0` (`bcc-requests.json`). Verify+install time 207.1 s total, 3.1–8.5 s per
  program (`bcc-service-summary.json`).
- Both arms hold the same 25 programs / 21 distinct names, so this is equal work: baseline 39,990,223 runs
  against native 37,328,235 (0.934x; the native arm's window opens later because it spends the load-phase
  time above).
- Per-program, baseline vs native (runs, ns per run): `sys_exit` 17.91 M → 16.68 M, 81.5 → 76.1 ns
  (0.933x); `sys_enter` 17.91 M → 16.68 M, 117.7 → 128.1 ns (1.089x); `kprobe__cap_cap` (2 programs)
  1.43 M → 1.38 M, 287.1 → 336.6 ns; `tracepoint__sys` (4) 1.10 M → 1.05 M, 673.7 → 764.2 ns;
  `sched_switch` 699 k → 651 k, 252.4 → 319.4 ns; `fentry_vfs_open` 551 k → 526 k, 37.3 → 28.9 ns;
  `sched_wakeup` 360 k → 331 k, 139.8 → 154.0 ns. Small-count entries (n ≤ 214: `fentry_vfs_crea`,
  `block_rq_comple`, `block_rq_issue`, `sched_wakeup_ne`, `blk_account_io_`, `fentry_vfs_fsyn`) and the six
  zero-run entries are not ratios.
- Installed native bytes exceed JIT bytes here (59,674 vs 7,965 B across the arm) because these are the five
  helper calls each probe makes; this run is a verified-path check with 10 s of workload, not a timing run.

## Tracee (tracee/monitor)

Run `x86_kvm_corpus_20261117_205400_990352`, 1 sample × 10 s, stats on, still `"status": "running"` at
02:53Z (service started 20:52:09Z, corpus 20:54:00Z). Raw
`/workspaces/kprog-raw/verified/20261117-checked-hot/tracee/`, session `session-l8nw5lav`. 38 requests
submitted so far; this section is written from the requests journal and each request's own archive, not from
a finished run. Of the 38: **14 verified, 22 direct-native, 2 hard failures**.

- **14 verified and installed** (`execution_path=checked-sim-c`, `b_generated=true`, `b_stock_passed=true`,
  `status=0`): requests 1, 2, 3, 6, 7, 9, 10, 25, 26, 29, 30, 31, 33, 35. 14 distinct native bodies
  (`checked-simulator.native.o` sha256), 20,888 B to 2,082,296 B. The two largest are the whole syscall
  path: request 30 at 2.08 MB and requests 25/26 at 1.27 MB.
- **21 direct-native** (`execution_path=direct-native`, `b_stock_passed=false`): 16 stopped by the stock
  verifier, 5 by `llc-18`. These are recorded fallbacks, not silent ones: each archive carries
  `simulator-failure.json` and a `load-direct.*` pair.
- **2 hard failures**: requests 23 and 24, `status=-5`, no `phase`, no `execution_path` — the loader's link
  step refused the object before B could be checked (cause below).
- The application itself keeps running on eBPF where a native body is missing: the shim's post-rejit log
  records **35 `native-loader replaced`** and **2 `native-loader failed`**, both `syscall__execve` — and
  those two are exactly requests 23/24's program, so the two failures below are visible on both sides. With
  `BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1` a program that fails to load silently stays on eBPF; as of
  `47491721e` the shim reports `native_loads_inflight` / `native_bound_completed` and logs
  `verified program kept on eBPF`, so the next run *names* it instead of leaving it to be inferred.

The 16 verifier rejections are three classes, taken from each archive's `verify.stderr` last line — the
subject under test is the native body, and each class is a different emitter defect:

| requests | programs | verifier's last line |
|---|---|---|
| 4 | `sys_enter_init` | `68: (79) r3 = *(u64 *)(r1 +112)` → `R1 invalid mem access 'scalar'` |
| 11, 13, 15, 17, 19, 21 | `trace_ptrace`, `trace_process_vm_writev`, `trace_arch_prctl`, `trace_dup`, `trace_dup2`, `trace_dup3` | `R9 invalid mem access 'scalar'` |
| 12, 14, 16, 18, 20, 22 | the six matching `trace_ret_*` | `invalid write to stack R10 off=-520 size=8` |
| 8, 27, 32 | `sys_exit_submit`, `sys_dup_exit_tail`, `uprobe_lkm_seeker_submitter` | `math between fp pointer and register with unbounded min value is not allowed` |

`off=-520` is the concrete one: the verifier's stack is 512 B, and these bodies write 8 bytes at −520, one
slot below it. `llc-18` is run with `-bpf-stack-size=4096` (`kprog/x86/trusted_specializer.py:30,99`), so a
frame that overshoots the real 512 B reaches the verifier instead of being caught at emission.

### Open cause: requests 23 / 24, one absolute-memory instruction

`tracee__monitor.post_rejit.log` is not involved; the rejection is the loader's `native-link` call
(`load.stderr` in `23.failure.tar.gz`):

```
native-link: entry=trusted_x86_x86_sim_xdp (94194 bytes), 1 reachable symbol(s) total
Error: instruction at IP 0x3b96 uses absolute memory address 0x70; userspace constants don't map into kernel
```

The check is `kprog/x86/native_lab/native_link/src/x86.rs:3718-3724` (memory operand, no base, no index,
non-zero displacement, not IP-relative). Disassembling the exact input the linker read
(`generated/checked-simulator.proof.o`, entry at 0x0) shows one instruction at that IP:

```
3b91: ba 70 00 00 00        mov $0x70,%edx
3b96: 48 8b 34 25 70 00 00  mov 0x70,%rsi        <- 48 8b 34 25 / SIB 0x25 = no base, no index
```

`mov 0x70,%rsi` loads from absolute address 0x70. In userspace that address is meaningful only through a
segment (fs/gs) base; the decoder reports no base register, so the linker's judgement is right and the
emitter produced the wrong form. Both requests are one program: `artifacts.json` names request 23
`syscall__execve_enter` and request 24 `syscall__execve_exit` — the same `syscall__execve` pair the shim
logged as failed, 94,194 B blob each. So this is one emitter site, not a linker policy gap. Recorded as an
open cause; the fix belongs to whatever emits that load, not to a linker exemption.

### Open cause: six requests fail generation on a LOCAL `.L` map name

Requests 5, 28, 34, 36, 37 and 38 record only `llc-18` exiting 1. Re-running the packed MIR that each
archive retains gives the real messages: first `trusted_x86.bpf.c:7335: Looks like the BPF stack limit is
exceeded`, and with `-bpf-stack-size` raised to 65536, `Undefined temporary symbol .L.str.2`.

That symbol is the defect. `readelf` shows `.L.str.2` is a 15-byte **LOCAL** object in `.rodata.str1.1` —
a string literal that shares an address with the map at `value_offset 31` (ARRAY, key 4, value 246).
`normalize()` (`kprog/trusted_service.py:126-139`) takes the shim envelope's `item['name']` verbatim as the
symbol name, so the generator emits `extern __u8 __x86_trusted_map_8[] __asm__(".L.str.2") __ksym`, and no
undefined external reference can bind a LOCAL symbol. The name can only have come from the ELF:
`kernel.facts.json` carries the map's shape and nothing else, and the `.maps` section's GLOBAL names do not
include it. The fix is in name resolution — skip LOCAL `.L*` symbols, or synthesize a stable name — not in
`native-link`, which never sees this input.

Confirmed systematic, not a one-off: requests 38 and 5 fail identically on the same symbol.

Validated as the whole defect: rewriting only `.L.str.2` to a plain identifier in the retained
`trusted_x86.bpf.packed.mir` and re-running the same `llc-18` line produces a 547,600-byte object with
`__trusted_map_8` left `GLOBAL UND`, exactly like the `event_data_map`/`config_map` externs that already
resolve. Nothing else about the request changes, so the name alone is what `llc` rejects. All six fell
back to `direct-native` with `status 0`, so the app ran; the cost is coverage.

### Equal work

Not yet asserted: 14 of 37 programs are native and 21+2 are not, so the two arms cannot be compared as
equal work until the verifier and emitter classes above are fixed. This section reports the verified path,
not a timing ratio.

## Not yet run

Tetragon, Cilium, Katran and OTel follow in that order; each gets its own section here.