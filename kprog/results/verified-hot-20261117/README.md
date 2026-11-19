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

Run `x86_kvm_corpus_20261117_205400_990352`, 1 sample × 10 s, stats on. The guest finished at
`2026-11-18T05:07:47Z` with exit 255 (the launcher reports the guest's own non-zero exit, not an app
crash), first request 20:55:00Z, last 05:07:40Z. Raw
`/workspaces/kprog-raw/verified/20261117-checked-hot/tracee/`, session `session-l8nw5lav`. **47
requests: 20 verified, 25 direct-native, 2 hard failures.** Every request records
`execution_mode=checked-sim-c`; the 25 fallbacks are the ones whose simulator failed a stage.


- **20 verified and installed** (`execution_path=checked-sim-c`, `b_generated=true`,
  `b_stock_passed=true`, `status=0`): requests 1, 2, 3, 6, 7, 9, 10, 25, 26, 29, 30, 31, 33, 35, 41,
  42, 43, 45, 46, 47. 20 distinct native bodies (`checked-simulator.native.o` sha256), 20,888 B to
  2,082,296 B. The largest are the whole syscall path: request 30 at 2.08 MB and requests 25/26 at
  1.27 MB.
- **25 direct-native** (`execution_path=direct-native`, `b_stock_passed=false`): 17 stopped by the stock
  verifier, 8 by `llc-18` at the generation stage. These are recorded fallbacks, not silent ones: each
  archive carries `simulator-failure.json` and a `load-direct.*` pair.
- **2 hard failures**: requests 23 and 24, `status=-5`, no `phase`, no `execution_path` — the loader's link
  step refused the object before B could be checked (cause below).
- The application itself keeps running on eBPF where a native body is missing, and the shim side agrees with
  the journal: `tracee__monitor.post_rejit.log` records **45 `native-loader replaced`** (20 verified + 25
  direct-native), **2 `native-loader failed`** (both `syscall__execve`, i.e. requests 23/24), 2 `no manifest
  match`, 12 skipped feature probes and 90 `native-loader jit`. The shim never kept a program silently on
  eBPF in this run: `verified program kept on eBPF` appears zero times, so all 45 installs landed.

The 17 verifier rejections are five classes, taken from each archive's `verify.stderr` last line and the
program name in its own failure record — the subject under test is the native body, and each class is a
different emitter defect:

| requests | programs | verifier's last line |
|---|---|---|
| 4 | `sys_enter_init` | `R1 invalid mem access 'scalar'` |
| 11, 13, 15, 17, 19, 21 | `trace_ptrace`, `trace_process_vm_writev`, `trace_arch_prctl`, `trace_dup`, `trace_dup2`, `trace_dup3` | `R9 invalid mem access 'scalar'` |
| 12, 14, 16, 18, 20, 22 | the six matching `trace_ret_*` | `invalid write to stack R10 off=-520 size=8` |
| 8, 27, 32 | `sys_exit_submit`, `sys_dup_exit_tail`, `uprobe_lkm_seeker_submitter` | `math between fp pointer and register with unbounded min value is not allowed` |
| 44 | `syscall__accept4` | `R2 unbounded memory access, use 'var &= const' or 'if (var < const)'` |

`off=-520` is a whole-frame overflow, not one slot past the budget. Measured from each archive's own
`trusted_x86.bpf.o`, those six bodies emit a **1176-byte** frame (147 contiguous 8-byte slots, 8 through
1176), and the verifier stops at the first write past its 512-byte budget. The frame is 240 B of guest stack
(`X86_SIM_STACK_BYTES 240U`, 30 words) plus the two scalarized fact arrays (`__x86_stack_value_tag_N` and
`__x86_stack_value_ptr_N`, 30 slots each, address-taken by `X86_SIM_BIND_INLINE`) plus 8-byte spill slots.
`llc-18` is run with `-bpf-stack-size=4096` (`kprog/x86/trusted_specializer.py:30,99`), so the overflow
reaches the verifier instead of being caught at emission; recompiling the same request's `bounds.bc` with
`-bpf-stack-size=512` makes clang itself stop, at `x86_mem_access.h:152` in the same function.

It is specific to these six bodies. Every other request in the run fits: the largest is 488 B (request 8),
and a passing 3,364-operation request (47) builds unchanged at `-bpf-stack-size=512`. All six emit exactly
87,963 instructions for 1,633 guest operations — 53.9 per operation, against 1.8 to 2.4 for every other
request — so they are one body shape whose code is heavily replicated (58,316 of the 87,963 instructions
repeat an earlier 12-instruction window). That replication, not the 240-byte guest stack, is what spends the
extra 664 B.

### Fixed cause: requests 23 / 24, one absolute-memory instruction

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
logged as failed, 94,194 B blob each. So this is one emitter site, not a linker policy gap, and the app's
native bytes are not implicated: `request.native.o` carries no such instruction.

The site is `compile_sim_ir.cpp`'s `address()`, which lowers the simulator's BPF asm load to
`getelementptr i8, ptr %base, i64 112`. The archived `checked-simulator.native.bc` shows the base arriving
as `%5306 = phi ptr [%5289, ..], [%5297, ..], [null, ..]` — a simulator register that is not present reads
as a constant null pointer (`X86_SIM_L_REG_VALUE` returns `(void *)0`) — so the backend folds the `gep` and
the guest displacement 112 becomes a host absolute address. Minimal reproduction: the same fold needs a
provably null base, and a base loaded from a pointer keeps `0x70(%rax)`.

The fix barriers the base bits into a register before the `gep`, so the load stays relative and the address
is still base + displacement. Replaying request 23's archived link plan against the rebuilt proof object:

```
native-link: wrote 96431 bytes -> fixed.blob (17 relocs)
```

where the original proof was refused at IP 0x3b96; the object now has zero absolute memory operands, the
non-null path still emits `mov 0x70(%rdx),%rdx`, and the simulator's own frame is unchanged at `0x138`.

### Fixed cause: eight requests fail generation on a LOCAL `.L` map name

Requests 5, 28, 34, 36, 37, 38, 39 and 40 record only `llc-18` exiting 1. Re-running the packed MIR that
each archive retains gives the real messages: first `trusted_x86.bpf.c:7335: Looks like the BPF stack limit
is exceeded`, and with `-bpf-stack-size` raised to 65536, `Undefined temporary symbol .L.str.2`.

That symbol is the defect. `readelf` shows `.L.str.2` is a 15-byte **LOCAL** object in `.rodata.str1.1` —
a string literal that shares an address with the map at `value_offset 31` (ARRAY, key 4, value 246).
`normalize()` (`kprog/trusted_service.py:126-139`) takes the shim envelope's `item['name']` verbatim, so
the generator emitted `extern __u8 __x86_trusted_map_8[] __asm__(".L.str.2") __ksym`, and no undefined
external reference can bind a LOCAL symbol. The name can only have come from the ELF: `kernel.facts.json`
carries the map's shape and nothing else, and the `.maps` section's GLOBAL names do not include it.

Validated as the whole defect: rewriting only `.L.str.2` to a plain identifier in the retained
`trusted_x86.bpf.packed.mir` and re-running the same `llc-18` line produces a 547,600-byte object with
`__trusted_map_8` left `GLOBAL UND`, exactly like the `event_data_map`/`config_map` externs that already
resolve. Nothing else about the request changes, so the name alone is what `llc` rejects.

The fix sanitizes the **assembler spelling** and leaves the ELF name alone. `native_map_label()`
(`kprog/trusted_generation.py:37-46`) returns the name unchanged unless it starts with `.L`, in which case
it prefixes `kprog` and hex-escapes every byte outside `[A-Za-z0-9_.]` (mirroring the C++ helper at
`native_loader_link_plan.hpp:53-76`); `.L.str.2` becomes `kprog.L.str.2`. The generator
(`generate_micro_sim_proofs.py:1949-1953`) emits that spelling in the `__asm__` label, and the loader adds
a matching alias binding (`native_loader.cpp:3988-3995`) so `relocate_trusted_proof` resolves the extern to
the same kernel map identity. Both ELF-keyed tables (`map_addrs`, `map_addr_ids`, `source_pointers`) stay on
the raw symbol, so nothing else moves.

Verified on request 38's archived inputs. The regenerated `generated/trusted_x86.bpf.c:16` now reads
`extern __u8 __x86_trusted_map_8[] __asm__("kprog.L.str.2") __ksym;`, and that line is the only difference
from the archived C (4 diff lines, 5 bytes). The rename alone is sufficient: rewriting `.L.str.2` to
`kprog.L.str.2` in the archived `trusted_x86.bpf.packed.mir` and re-running the same `llc-18` line builds at
`-bpf-stack-size` 4096, 8192 and 65536 (547,592 B each), while the unmodified MIR fails at both 4096 and
65536 with `Undefined temporary symbol .L.str.2` — so the stack-limit message those messages showed first is
a separate, later-building condition, not part of this defect.

Pre-existing, not introduced by item 5(d): this run uses the base loader `430a337f2c316c4e` from 11-17
20:27Z, and 5(d) landed at 22:58Z.

### Equal work

Not yet asserted: 20 of 47 programs are native and 27 are not (25 recorded fallbacks plus the 2 that never
loaded), so the two arms cannot be compared as equal work until the verifier and emitter classes above are
fixed. This section reports the verified path, not a timing ratio.

## Tetragon (tetragon/observer)

Run `x86_kvm_corpus_20261118_133241_377898`, 1 sample × 10 s, stats on, `SKIP_REJIT=norejit`. Raw
`/workspaces/kprog-raw/verified/20261118-checked-hot/tetragon-c/`, session
`session-4u0ra04z`. **8 verified and installed** (requests 1-8, `execution_mode=checked-sim-c`,
`status=0`, zero failures); the run is still consuming the application's startup, one program at a time.

### The baseline never opened its gate before this run

The 11:41Z attempt (`corpus/results/x86_kvm_corpus_20261118_114111_107961`) recorded **zero BPF
requests**: the application sat in the shim gate until its own 1800 s lifecycle timeout. Its baseline
shim log holds 311 `BPF_PROG_LOAD`, 50 `LINK_CREATE`, every loader thread finished by t=127 s, and
**8,152** `socket: cmd=list_progs` polls from t=102.5 s to t=1902 s.

The gate holds the program set empty while `native_bound_completed == 0`
(`runner/libs/rejit.py`, `_list_app_shim_program_ids`). That counter's only increment sits inside
`shim_maybe_replace_with_native_fd`, past an early return when the loader is disabled, and the loader is
disabled for every value but `"1"` (`bpfopt/shim/shim_native_loader.h`, `shim_native_loader_enabled`).
`corpus/driver.py` sets `BPFREJIT_SHIM_NATIVE_LOADER=1` for the loadtime phase alone, so the baseline
app inherits `"post"` while `BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1` keeps the gate on: a counter
no baseline process can move, waited on forever.

Measured on the image with the shipped shim and one loaded program, through the runner's own gate
function: ids `()` under `"post"`, `(37273,)` under `"1"`. The gate now requires the progress fields
only when the loader can run; a program the loader skips still returns `()` under `"1"`, so the
obligation stays where it belongs. With that change the baseline of this run measures
(`measurement_done phase=baseline status=ok`) and the requests follow.

### The frontend compile is linear in instruction sites, and one arm inflates each site

Request 6 (`request-iwtue2bu`, `trusted_x86.bpf.c` 356 KB) spent **74 minutes** in the frontend compile
`clang -w -g -O3 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096 -emit-llvm -c`; requests 1-5 took
about 24 s each, and request 3 was 7.5 MB packed, so the driver is the program's shape rather than its
size.

The 2026-11-18 record blamed `GVNPass::findLeader` from a gdb backtrace. That attribution is wrong:
every GVN knob leaves the time unchanged, and only `-Xclang -ftime-report` (the `-mllvm -time-passes`
route prints nothing on this clang) measures the real split. At `-O1` on the real 5,647,010-byte input
`InstCombinePass` costs 190.2 s of 307.7 s (61.8%), against `SROAPass` 35.9 s and `AlwaysInlinerPass`
18.4 s.

Cost is linear in instruction sites, so splitting the function cannot help. Label-preserving truncations
of the real input at `-O3` gave 360 labels → 579 s and 720 labels → 1176 s, a slope of **1.658 s per
label**; extrapolated to the program's 2,885 labels that is 4,766 s ≈ 80 min, which reproduces the
recorded 74 minutes to within a few percent. The same truncations at `-O1` were linear too (720 → 179 s,
1440 → 249 s).

The per-site cost is 1.35 MB of frontend IR for a helper-call site against 10 KB for a MOV-immediate
site, because `X86_SIM_DECLARE_INSTRUCTION` expands `X86_SIM_L_EXEC_DISPATCH` over all 57 arms in every
constant-opcode wrapper, and `X86_SIM_L_ARM_CALL_HELPER` expands `X86_SIM_BPF_CALL_ID(IMM)` as a
`switch` over all 70 helper slots. At `-O0` the frontend emits every arm body at every site — one
`CALL_HELPER` call in an otherwise empty program emits 198,407 IR lines from 70 switch cases of ~1,830
lines each — and only the optimizer removes the dead arms afterwards. Measured on the archived input:
5.5 MB / 1 s with no call, 62 KB with one MOV-immediate call, 1.35 MB with one `CALL_HELPER` call,
156.8 MB / 34 s with the helper switch reduced to one body, 929.3 MB / 198 s as shipped.

Tetragon's verified run therefore completes but costs up to 74 minutes on a large straight-line program.
Cilium, Katran and OTel follow in that order; each gets its own section here.

### The frontend IR is not what the optimizer spends its time on (measured 2026-11-19)

The per-site IR inflation above is real at `-O0`, but it does not explain the optimization cost. Removing it
was measured, and the optimizer got *slower*.

Every one of the 2,689 `X86_SIM_RUN_OP` sites in the archived input maps to an opcode whose
`DIRECT_STEP_MACROS` entry (`kprog/x86/micro-prog/generated_x86_specialization.py`) names a dedicated
`X86_SIM_L_EXEC_*` handler that bypasses the 57-arm chain; the 432 helper sites map to
`STATIC_HELPER_CALLS` (`generate_micro_sim_proofs.py:1143`, the same table `direct_step_statement` already
uses for the fidelity encoder). Rewriting the generated C that way, on the same archived program:

| input | `-O0` IR / time | `-O1` time |
|---|---|---|
| as shipped | 929.3 MB / 198 s | 356 s |
| helper sites → direct call (432 sites) | 147.1 MB / 39 s | — |
| all literal sites → `X86_SIM_L_EXEC_*` | **50.0 MB / 33 s** | **847 s** |

An 18× smaller frontend makes optimization **2.4× slower**. `-Xclang -ftime-report` on that smaller input
gives the same shape as the shipped one — `InstCombinePass` 494.1 s of 847.1 s (60.5%), `SROAPass` 217.8 s
(26.6%) — so the cost tracks the optimizer's work on the surviving code, not the byte count the frontend
emitted. Two earlier rewrites (per-site arm macro, per-site arm function) were flat or worse for the same
reason. Splitting the function does not help either, for the linear reason already recorded.

Consequence: the cliff is a property of `-O3` on a large straight-line dispatcher, and the only lever that
measured is the optimization level. `be3946f6d` moved B's frontend/backend to `-O1` (keeping `-g` for the
BTF map externs libbpf must open) for that reason; P and the final native compile stay at `-O3`.

That level change is not neutral for the artifact. B is analyzed and never executed
(`kprog/docs/design.md:108`), so no timed number moves, but the emitted eBPF differs: compiling all 43
`kprog/x86/micro-prog/*.bpf.c` at both levels and diffing the `llvm-objdump -d` streams gives 9 identical,
28 larger at `-O1`, 6 smaller — 15,253 instructions at `-O1` against 13,624 at `-O3`, **+12.0%**, worst
`packet_record_bounds_window` 453 vs 325 (**+39.4%**). The extra size lands on the B the verifier analyzes;
it is not a claim about the timed native code.

## Cilium (cilium/agent)

Run `x86_kvm_corpus_20261119_170933_095060`, 1 sample × 10 s, stats on, `SKIP_REJIT=norejit`. Raw
`/workspaces/kprog-raw/verified/20261119-checked-cilium/` (started 17:07:42Z, finished 17:20:00Z, exit
code 0), session `session-i6twz_f2`. **64 requests: 14 verified and installed, 49 direct-native, 1 hard
failure.** Every request carries `execution_mode=checked-sim-c`; the 49 fallbacks each hold their own
`simulator-failure.json` plus a `load-direct.*` pair, so none is silent.

The shim side agrees with the journal: `cilium__agent.post_rejit.log` records **63 `native-loader
replaced`** (14 verified + 49 direct-native) and **0 `native-loader failed`**, against 100 `jit` in the
baseline arm and 159 in the post arm. The one request that failed never reached an install, which is why
63 replaces match 63 `status=0` journal lines.

- **14 verified and installed** (`execution_path=checked-sim-c`, `b_generated=true`,
  `b_stock_passed=true`, `status=0`): requests 1, 2, 4, 5, 8, 13, 30, 34, 39, 46, 51, 52, 54, 62.
  **14 distinct native bodies**, 352,024 B total, 13,656 B to 34,208 B each. Twelve resolve to a name in
  the run's own result file: `cil_xdp_entry`, `cil_to_host` (3), `cil_host_policy` (2), `cil_lxc_policy`
  (two spelling lengths), `tail_drop_notif` (4). Two (requests 30, 62) report a `prog_id` the arm's
  snapshot does not carry, and their archives record only ids, so their names are not claimed here.
- **49 direct-native**: 46 stopped by the stock verifier, 3 by the emitter before B existed. Ten of the
  49 also have no name in the result file, for the same snapshot reason.
- **1 hard failure**: request 64 (`tail_nodeport_nat_egress_ipv4`, `source_prog_id=622`), `status=-5`.
  Its generation failed verification first (`invalid access to packet, off=18 size=2, R6(id=0,off=18,r=0)`)
  and the fallback `load-direct` then could not find its arm image
  (`trusted-native-loader: arm kernel native image: No such file or directory`), so neither path completed.

The 46 verifier rejections are one class, in two forms — the subject is the native body, not the app:

| requests | verifier's last line |
|---|---|
| 40 | `invalid access to packet, off=<N> size=<S>, R<r>(id=0,off=<N>,r=0)` then `R<r> offset is outside of the packet` |
| 6 | `only read is supported` (a store through a `trusted_ptr_sk_buff` + offset) |

Both forms say the same thing about the emitter: the native body reads or writes the packet at a fixed
offset without the bounds check the verifier wants. Request 7 is the smallest instance — 22 instructions in,
`22: (61) r1 = *(u32 *)(r1 +76)` makes `R1=pkt(r=0)`, then `23: (69) r2 = *(u16 *)(r1 +20)` is rejected at
`off=20`. Request 6 is the store form: `65: (bf) r2 = r0` / `66: (07) r2 += 46` / `67: (6b) *(u16 *)(r2 +0) = r1`
over `R0=trusted_ptr_sk_buff()`. The offsets recur in families (`off=12`, `18`, `20`, `23`, `26`, `4`),
i.e. structural fields of the packet parsers, not one bad constant.

The 3 generation failures (requests 22, 40, 58, all `tail_handle_snat*`) stop in the same place:
`relative table computation has live register or flag results`
(`generate_micro_sim_proofs.py:1852`, `lower_relative_tables`) — the emitter will not lower a relative
table while a register or the flags still hold a live value across it.

### Equal work

The two arms do not hold the same program set (baseline 55 programs, post 51; `cil_from_netdev` appears
only in the baseline), so this run is not a timing comparison. Totals: baseline 7,633,169 runs /
7.542 s of BPF, post 40,748,428 runs / 4.128 s. The run counts differ because the post arm's window opens
after the load phase, which spent 12 minutes generating and checking B. The one program with large counts
in both arms is `cil_from_container`: 7.63 M runs at 988.0 ns/run baseline against 20.37 M at 157.2 ns/run
native — a different measurement window over a different program set, so not a ratio either. This section
reports the verified path, not a speedup.

## Katran (katran)

Run `x86_kvm_corpus_20261119_174534_794158`, 1 sample × 10 s, stats on. Raw
`/workspaces/kprog-raw/verified/20261119-checked-katran2/` (started 17:46:04Z, finished 17:49:18Z, exit
code 0). **1 request: verified and installed**, `execution_path=checked-sim-c`, `b_generated=true`,
`b_stock_passed=true`, `status=0`; zero fallbacks, zero failures. Katran loads exactly one program,
`balancer_ingress` (XDP), so this is the whole application.

- The shim agrees: `katran.post_rejit.log` holds **1 `native-loader replaced`**, **0 `native-loader
  failed`**, against 1 `jit` in the baseline arm.
- The native body for it is 459,944 B (`checked-simulator.native.o`); its frontend text is 4,936,546 B.
- **This run is equal work.** Both arms hold the same one program and the same four pktgen components
  (thread ids 0-3, 64-byte UDP, `clone_skb 0`), with durations of 10.15 s and 10.14 s. Baseline
  10,400,282 runs / 5.335 s of BPF; native 10,822,535 runs / 4.951 s — 512.96 against 457.49 ns per
  invocation across the arm, i.e. the native arm is 0.892x. That is one 10-second sample, so it is the
  verified path's own record, not a timed result for the ratio table.

### The first attempt never ran the workload

Run `x86_kvm_corpus_20261119_174125_871203` recorded **zero requests** and `status=error`:

```
command failed (2): ip netns exec katran-router sh -c 'printf "%s\n" rem_device_all > /proc/net/pktgen/kpktgend_2'
sh: 1: cannot create /proc/net/pktgen/kpktgend_2: Directory nonexistent
```

`checked-corpus` gave the checked guest `--cpus 2`, and Katran's pktgen workload drives pktgen threads
0-3 (`KATRAN_PKTGEN_THREAD_IDS` at `runner/libs/app_runners/katran.py:618`), so threads 2 and 3 had no
`kpktgend_N` interface. The Makefile now takes `CHECKED_VM_CPUS` (default 2, so every earlier run is
unchanged) and this run passes 4; the workload then started and the request follows.

## OTel (otelcol-ebpf-profiler/profiling)

Run `x86_kvm_corpus_20261119_183202_247645`, 1 sample × 10 s, stats on. Raw
`/workspaces/kprog-raw/verified/20261119-checked-otel2/` (started 18:29:37Z, finished 18:32:02Z, exit
code 0). **14 requests: 3 verified and installed, 11 direct-native, 0 hard failures.** All 14 install:
`otelcol-ebpf-profiler__profiling.post_rejit.log` records **14 `native-loader replaced`** and **0
`native-loader failed`**, against 0 replaced in the baseline arm. Both arms hold all 13 programs, so this
is equal work.

- **3 verified** (`execution_path=checked-sim-c`, `b_generated=true`, `b_stock_passed=true`, `status=0`):
  requests 4 `perf_unwind_hotspot` (596,720 B), 6 `perf_unwind_php` (521,544 B), 12
  `tracepoint__sched_process_free` (32,144 B). The result file truncates program names to 15 characters
  (`perf_unwind_hot`, `native_tracer_e`); the names here and below are the untruncated ones from each
  request's `generation.metadata.json`.
- **11 direct-native**: 8 stopped by the stock verifier, 3 by it in a second form.
- The run's own timing is not a speedup: `native_tracer_entry` (the one program with real traffic) takes
  4,201 ns per invocation in the baseline arm and 5,744 ns in the native arm over 10 s windows (3,270,614
  against 3,247,507 runs), and the python workers' `ops` counters also differ (1.54 M + 1.34 M baseline
  against 0.86 M + 1.01 M native), so the two arms did not see the same machine load. Both are 10-second
  samples, and 11 of 13 programs are not native bodies anyway.

### The first attempt recorded zero requests, and the cause was in the linker

Run `x86_kvm_corpus_20261119_175017_970933` finished with the app `status=ok` and **no requests at all**;
its shim log held 14 `native-loader failed`, every one the same:

```
native-loader failed prog=read_task_struct ... error=native-link proof failed (rc=1)
stderr:
Error: iced bailed decoding bpf_get_current_pid_tgid at IP 0x280
```

The service never saw a request because the loader's own entry-proof step failed first, and that step runs
before the specializer endpoint is consulted.

The cause is a shape only OTel's native object has. Every other app references a helper as one undefined
symbol; OTel's object carries **both** the undefined reference and an 8-byte `OBJECT` in `.rodata.cst8`
naming the same helper and holding its id (`objdump -s -j .rodata.cst8` starts `0e000000…`, helper 14 =
`bpf_get_current_pid_tgid`). `resolve_x86_plt32_defined_target_addr` resolved the `R_X86_64_PLT32` call
relocation to that defined object at `0xf8`+`0x188`, the reachability walk queued it as a function, and the
decoder then read the id bytes as instructions. All 14 helper names in that object have this second
definition, so all five probed programs failed, in every mode.

The linker now takes a PLT32 defined target to be code — `SymbolKind::Text`, or a symbol in a code section
(`kprog/x86/native_lab/native_link/src/x86.rs`, `resolve_x86_plt32_defined_target_addr`). Checked directly
on the image's own object, all five previously failing programs link (`read_task_struct` 247 B,
`perf_unwind_stop` 5,757 B, `perf_unwind_native` 27,047 B, `kprobe_unwind_v8` 32,580 B,
`tracepoint__sched_process_free` 1,163 B), Katran's and Cilium's still link, and `cargo test --release`
passes 38. One earlier fix on this path was already in the tree from another lane (`21b4f3012`), so the
record above is the state of the whole file, not a separate patch.

### The 11 fallbacks

| requests | programs | verifier's last line |
|---|---|---|
| 8 (3, 5, 7, 9, 10, 11, 13, 14) | `perf_unwind_native`, `perf_unwind_perl`, `perf_unwind_python`, `perf_unwind_v8`, `perf_unwind_dotnet`, `perf_go_labels`, `native_tracer_entry`, `custom__generic` | `math between fp pointer and register with unbounded min value is not allowed` |
| 3 (1, 2, 8) | `read_task_struct`, `perf_unwind_stop`, `perf_unwind_ruby` | `R1`/`R0 invalid mem access 'scalar'` after `(79) r1 = *(u64 *)(r1 +120)` |

Both classes are the emitter's: the first adds an unbounded register to a frame pointer, the second loads
through a register the verifier still treats as a plain scalar. Neither is a missing capability of the
checked path — the same requests are recorded as fallbacks with their own `simulator-failure.json`, exactly
as the other apps' do.
### Cilium re-run with the head-length matcher fix (omp 2026-11-19T23:05Z)

After PERF landed the `classifier` head-length matcher (`cdd26e9cd` … `80dbcfc51`), Cilium was run again
through the same checked path with that compiler installed into the service base: raw
`/workspaces/kprog-raw/verified/omp-cilium-20261119/postfix-20261119T214810Z` (`checked-corpus
CHECKED_APP=cilium/agent`, exit 0, 64 requests, guest consumed the base built at 21:47 from `80dbcfc51`).

**14 install, 41 `invalid access to packet`, 6 `only read is supported`, 3 emitter refusals** — the same
split as the baseline above. So the fix is real but not sufficient, and the verified count has not moved
yet. The diagnosis is in `kprog/results/cilium-packet-bounds-20261119/README.md`: each `skb->data` re-read
is a new packet pointer, and 33 of the 41 programs reload `data` up to 38 times, so the emitted bound must
sit on the load the read uses rather than on the one the matcher happened to match.
