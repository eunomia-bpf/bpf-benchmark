# 2026-05-19 LD_PRELOAD shim ReJIT audit

Scope: read-only audit of the shim migration path. The only write performed for this task is this report.

Primary references:

- `docs/rejit-speculative-optimization-ebpf.md`
- `bpfopt/shim/libbpfrejit_shim.c`
- `daemon/src/`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs`
- `bpfopt/crates/bpfopt/src/passes/{rotate,cond_select,endian,lea,extract,bulk_memory,prefetch,ccmp}.rs`
- `bpfopt/kinsnprober/src/main.rs`
- `runner/libs/rejit.py`
- `runner/libs/app_runners/{tracee,bcc,katran,bpftrace,otelcol_ebpf_profiler,cilium,tetragon}.py`
- `vendor/linux-framework/kernel/bpf/syscall.c`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/include/uapi/linux/bpf.h`

## 1. 总览

The hub doc's idea #1 moves speculative ReJIT from a daemon-owned `BPF_PROG_REJIT` path to an LD_PRELOAD shim that intercepts BPF loads, executes `bpfopt --pass`, reloads transformed bytecode in-process with `BPF_PROG_LOAD`, then reattaches links. That is not a mechanical transport swap: the daemon and shim have different syscall contracts.

| Area | Daemon behavior | Shim behavior found | Gap / consequence |
|---|---|---|---|
| Kernel operation | Uses fork-only `BPF_PROG_REJIT` on an existing live program fd. | Uses stock `BPF_PROG_LOAD` from inside the app process, then reattaches captured links/perf events. | Shim must replay or sanitize the full load ABI. Daemon avoids several `BPF_PROG_LOAD` metadata pitfalls. |
| Process credentials | Runs as a separate privileged process. App thread caps/creds do not directly control the syscall. | Runs in the loader/app process and a shim socket pthread. | Any app capability ring or fd table policy can affect reloads unless shim reopens/sanitizes independently. Current Tracee evidence points more to stale attr/fd_array than caps. |
| fd array construction | `build_rejit_fd_array()` builds maps first, then BTF module fds, and validates module slots are contiguous after the map prefix. | `build_full_fd_array()` parses target JSON by string scan, fills map fds at `[0..nr_maps)`, BTF module fds at target `call_offset`, and leaves holes as `-1`. | The intended layout matches the daemon for katran, but shim lacks daemon-style validation and relies on later kernel errors. |
| `fd_array_cnt` | ReJIT syscall has its own daemon-built attr; it does not replay an app's original `BPF_PROG_LOAD` count. | `reload_and_reattach()` starts from captured original `union bpf_attr` and sets `a.fd_array`, but does not intentionally rebuild/clear all stale fd-array fields. | If original `fd_array_cnt` is nonzero, kernel scans beyond the shim-built array or scans stale entries, producing EBADF/EINVAL. This matches Tracee errors. |
| BTF func/line metadata | ReJIT validates transformed program against existing kernel program context. It does not need to replay original stock-load `func_info` layout as a fresh load. | Shim copies original `func_info`/`line_info` bytes into transformed `BPF_PROG_LOAD`. | If a pass changes instruction layout or subprog offsets, kernel rejects with `func_info BTF section doesn't match subprog layout`. This appears in katran. |
| Verifier-state input | Daemon captures verifier logs after each successful ReJIT and feeds them to later `bpfopt` passes. | Shim writes `verifier_log_stepN.log` and feeds the previous successful log to `bpfopt --verifier-log`. | The transport exists, but verifier PCs may be in a different namespace than the next raw CFG. Current bpfopt mapping fails closed with `verifier state pc ... not present in CFG`. |
| Target/kfunc module model | `kinsnprober` produces module call offsets, then daemon shifts/validates fd slots around maps. | bpfopt shifts module `call_offset` by map prefix; shim consumes shifted target JSON. | The shift logic is coherent. The audit did not find evidence that katran's current failures are caused by an off-by-map-prefix generation bug. |
| Socket discovery | Runner talks to the daemon's stable socket. | Runner discovers `/var/run/bpfrejit/shim-*.sock` and maps `prog_id -> socket`; fallback uses `shim-<app_pid>.sock`. | Multi-process apps need actual loader process injection. `bcc/set` never injects shim env in its custom runner, so no socket appears. |
| Error surface | Daemon errors are isolated to the daemon's syscall path and are usually tied to ReJIT. | Shim errors combine app loader ABI replay, process state, reattach state, and bpfopt output. | Root-cause labels must distinguish bpfopt bytecode generation, shim ABI replay, and kernel verifier rejection. |

The main migration risk is not only "make the same fd_array"; it is that `BPF_PROG_LOAD` has stricter fresh-load metadata requirements than `BPF_PROG_REJIT`. The shim must either reconstruct a minimal clean load attr or remap every metadata side channel it replays.

## 2. #34 根因分析: katran kinsn 4 个 pass 失败

### Artifact sanity check

The retained katran workdir is:

`corpus/results/x86_kvm_corpus_20260519_155851_162854/details/shim-workdirs/work_9/`

It contains the requested files, but the current `output.next.bin` is not a failed kinsn-pass candidate. A read-only disassembly scan for `BPF_JMP | BPF_CALL` with `src_reg = BPF_PSEUDO_KINSN_CALL` found:

| file | bytes | insns | kinsn calls |
|---|---:|---:|---:|
| `output.bin` | 20336 | 2542 | 0 |
| `output.next.bin` | 20264 | 2533 | 0 |

This matches the workdir's later state: `output.next.bin` was overwritten by a later non-kinsn pass output. Therefore this artifact cannot prove the failed rotate/cond_select/endian_fusion/lea call instructions by inspecting the retained `output.next.bin`. Any statement that those retained bytes contain the failed kfunc calls would be incorrect.

The app result JSON for the same corpus run also differs from the symptom summary in the prompt:

- Prompt says rotate failed with `errno=13 EACCES`; this artifact reports rotate as `errno=22 EINVAL` with the `func_info BTF section doesn't match subprog layout` message.
- Prompt says prefetch succeeded; this artifact reports prefetch failed with the same func_info mismatch.
- Prompt says ccmp/bulk_memory/prefetch/extract succeeded; this artifact confirms ccmp, bulk_memory, and extract success, but not prefetch.

The root-cause conclusion below is therefore scoped to the actual retained files and result JSON.

### target.json and slot mapping

`fd-to-id.json` for katran program 9 contains 14 unique map ids. `target.json` has shifted module call offsets in slots 14 through 20:

| fd_array slot | BTF id | kinsn symbols |
|---:|---:|---|
| 14 | 2 | `bpf_x86_andl`, `bpf_x86_shrq` |
| 15 | 4 | `bpf_x86_bswapl`, `bpf_x86_rolw` |
| 16 | 5 | `bpf_x86_cmoveq`, `bpf_x86_cmovneq`, `bpf_x86_testq` |
| 17 | 7 | `bpf_x86_leal`, `bpf_x86_leaq` |
| 18 | 8 | `bpf_x86_movb`, `bpf_x86_movl`, `bpf_x86_movq`, `bpf_x86_movzbl`, `bpf_x86_movzwl` |
| 19 | 13 | `bpf_x86_prefetcht0` |
| 20 | 14 | `bpf_x86_rolq`, `bpf_x86_rorxl` |

This is consistent with `bbprogram_lift.rs`: `shift_target_module_call_offsets_for_map_prefix()` computes `module_base = map_count.max(1)` and shifts original module offsets by `module_base + original_call_offset - 1`. `kinsnprober` emits module offsets starting at 1, so 7 module BTFs become slots 14 through 20 when katran has 14 maps.

Expected failed/success slot use from `target.json`:

| Pass | Expected BTF id(s) | Expected fd_array slot(s) |
|---|---:|---:|
| `rotate` | 14 | 20 |
| `cond_select` | 5, 8 | 16, 18 |
| `endian_fusion` | 4, 8 | 15, 18 |
| `lea` | 7 | 17 |
| `extract` | 2 | 14 |
| `bulk_memory` | 8 | 18 |
| `prefetch` | 13 | 19 |

### bpfopt generation vs shim fd_array vs kernel reject

**bpfopt generation bug:** not supported by the retained target evidence. The shifted offsets are exactly what the daemon-compatible map-prefix model requires. `bpfopt` emits kinsn calls with `insn.off = call_offset` and `insn.imm = kfunc BTF func id`; the target offsets are already shifted. The retained `output.next.bin` cannot confirm individual failed call `off/imm` values because it contains no kinsn calls.

**shim fd_array fill bug:** not supported for the katran slot shift itself. The shim's `build_full_fd_array()` would build a 21-entry array for this target: maps at slots 0-13 and module BTF fds at 14-20. The result context records `fd_array_n=21` and `fd_array_neg1=0`, so the constructed array had no holes. That argues against "slot 14-20 still point at maps" or "missing map-count shift" as the root cause in this artifact.

The shim still has a robustness gap: unlike the daemon, it does not validate that module call offsets are exactly contiguous after the map prefix, and it parses target JSON with ad hoc string scanning. That is a hardening issue, but it is not the best explanation for the observed katran failures here.

**kernel rejection of other fields:** strongly supported for several katran failures. The result JSON contains explicit verifier messages:

- `func_info BTF section doesn't match subprog layout in BPF program`
- `processed 0 insns`

The kernel rejects this in `check_btf_func()` when `func_info` instruction offsets no longer match detected subprogram starts. The shim replays original `func_info`/`line_info` bytes for a transformed fresh `BPF_PROG_LOAD`. Any pass that changes instruction count or subprog-relative layout can therefore fail before real verifier execution. This explains failures such as map_inline/dce/rotate/prefetch/wide_mem in the retained run more directly than fd_array slot confusion.

For cond_select/endian_fusion/lea, the retained result only shows early `EINVAL` / `processed 0 insns` without enough preserved candidate bytecode or full log to prove whether the immediate reject was func_info, kfunc/BTF, or another stale attr field. Because `output.next.bin` was overwritten, the necessary evidence is gone.

### #34 conclusion

The katran retained artifact does not show a bpfopt call-offset shift bug. The expected BTF module slots are coherent and the shim's constructed array length/no-hole context is consistent with the target. The clearest proven bug class is shim fresh-load ABI replay: original BTF func/line metadata is reused after bytecode transformation and the kernel rejects it at attr/metadata validation.

For the four named kinsn failures, the exact per-pass `insn.off/imm` cannot be confirmed from the current workdir because failed candidate bytes were not preserved. The next diagnostic fix should preserve per-step candidate bytecode and full verifier logs before overwriting `output.next.bin`; the product fix should sanitize or remap fresh-load metadata instead of blindly replaying original `func_info`/`line_info`.

## 3. #36 根因分析: bcc/set 0/21 and missing shim socket

The missing socket is not primarily a shebang, bash wrapper, setuid, or setcap stripping issue in the inspected code. The concrete runner topology bug is simpler:

- `runner/libs/app_runners/bcc.py` has shim injection in `BCCRunner.start()` through `_shim_env_for(tool_binary)`.
- `runner/libs/app_runners/bcc_set.py` does not use `BCCRunner.start()`. Its `_spawn_child()` builds `tool_env = os.environ.copy()` and calls `subprocess.Popen(..., env=tool_env)` without adding `LD_PRELOAD` or `BPFREJIT_SHIM_SOCK_DIR`.
- Therefore the `bcc/set` workload children are launched without the shim, so `/var/run/bpfrejit/shim-<pid>.sock` never appears.

The Python wrapper detail is still relevant after the injection bug is fixed:

- `/usr/sbin/*-bpfcc` scripts use a Python shebang, so the actual ELF that receives `LD_PRELOAD` is `/usr/bin/python3`.
- That should work if the env reaches `execve()`: LD_PRELOAD is honored for the interpreter process.
- A fallback socket name derived from the parent app pid is fragile because the BPF loader may be a child Python process, not the wrapper pid tracked by the app runner.

`runner/libs/rejit.py` already has the right broad shape: it discovers all `shim-*.sock` files and asks each socket for `list_progs`, then builds `prog_id -> socket`. That is the correct model for multi-process apps. The fallback to `shim-<app_pid>.sock` should be treated only as a last resort; it cannot fix missing injection and may select the wrong pid.

### #36 fix dimension

The code fix should be in the runner launch path, not in the shim socket thread:

- Inject `_shim_env_for(str(tool_binary))` in `BccSetRunner._spawn_child()` or centralize all bcc child launching through a shared helper.
- After launch, rely on socket discovery by loaded program id, not wrapper pid.
- Keep a diagnostic that reports "no shim sockets discovered for bcc/set child pids" instead of silently falling back to a guessed wrapper socket.

No evidence in the inspected files indicates setuid/setcap stripping LD_PRELOAD for these bcc Python scripts.

## 4. #37 根因分析: tracee cap/cred vs fd/attr

### What Tracee capabilities actually do here

Tracee's capability manager lives under `vendor/repos/tracee/common/capabilities/`. It implements a capability ring:

- `Initialize(Config{Bypass, BaseEbpf})` configures global state.
- `EBPF()`, `Full()`, and `Specific()` temporarily apply caps around callbacks.
- When `Bypass` is true, `apply()` does not call `cap.SetProc`; it only updates internal bookkeeping.

The runner command for Tracee uses `--capabilities bypass=true`. With that flag, Tracee is not actively dropping and restoring process capabilities around its own eBPF load callbacks. That makes a pure "Tracee cap ring removed CAP_BPF/CAP_PERFMON from the shim thread" explanation unlikely for the current run.

I also did not find Tracee application code using `close_range()` or installing a seccomp policy that would explain wholesale loss of loader fds. The source tree has event definitions/tests for these syscalls, not a runtime close-range policy for Tracee itself.

### Observed error shape

The tracee result artifacts contain many errors shaped like:

- `fd -256 is not pointing to valid bpf_map or btf`
- `fd 0 is not pointing to valid bpf_map or btf`
- `fd 65280 is not pointing to valid bpf_map or btf`
- `fd 958976 is not pointing to valid bpf_map or btf`
- `BPF_PROG_LOAD errno=9` / `errno=22`

Those are EBADF/EINVAL fd-array validation failures, not EPERM capability failures. The strange fd values are especially important: they look like reading beyond or misinterpreting a constructed fd array, not like a valid app fd that was closed.

### Kernel path

In the forked kernel verifier, `process_fd_array()` behaves differently depending on `attr->fd_array_cnt`:

- If `fd_array_cnt == 0`, it stores the fd-array pointer for later instruction-level map/BTF resolution.
- If `fd_array_cnt != 0`, it immediately iterates the array and calls `add_fd_from_fd_array()` for every entry. Every entry must be a valid map or BTF fd.

`vendor/linux-framework/include/uapi/linux/bpf.h` defines `fd_array` and `fd_array_cnt` in `BPF_PROG_LOAD` attrs. The count is therefore not harmless stale metadata.

### Shim path

`reload_and_reattach()` begins with:

- `union bpf_attr a = p->load_attr`
- then patches `a.insns`, `a.insn_cnt`, `a.license`, BTF fds, `func_info`, `line_info`, and optionally `a.fd_array`

The inspected code does not reconstruct a clean minimal `BPF_PROG_LOAD` attr. In particular, it does not intentionally clear the original app's `fd_array_cnt` when replacing `a.fd_array` with the shim-built array.

This explains the Tracee pattern:

1. Tracee/libbpf originally loads programs with some fd-array metadata.
2. The shim captures the full original `union bpf_attr`.
3. During reload, the shim swaps in its own smaller or differently shaped `fd_array`.
4. The stale original `fd_array_cnt` makes the kernel scan entries beyond the shim's valid array, or scan slots that are not meant to be eagerly bound.
5. Kernel reports garbage fds such as `-256`, `65280`, or `958976` as invalid map/BTF fds.

The result context often reports sane `nr_map_fds` and constructed `fd_array_n`, but the kernel error mentions invalid fd values that are not plausible reopened map/BTF fds. That is the signature of stale count / dirty attr replay.

### cap/thread/cred dimension

Current evidence points to **fd/attr ABI replay**, not caps:

| Dimension | Assessment |
|---|---|
| Capability | Unlikely root for this run. Tracee is launched with `--capabilities bypass=true`, and failures are EBADF/EINVAL rather than EPERM. |
| Thread credential | Possible future risk if bypass is disabled, because the shim socket thread is not inside Tracee's `EBPF()` callback. Not the best fit for the observed errors. |
| Loader fd lifetime | Less likely as the primary issue because the shim reopens maps/BTF by kernel id. The weird fd values are not normal closed loader fds. |
| Stale `BPF_PROG_LOAD` attr | Strongly supported. It explains EBADF/EINVAL, garbage fd values, and the high failure count without invoking unrecoverable Tracee credentials. |

### fork+exec helper assessment

A fork+exec privileged helper can solve real isolation problems:

- app thread capability rings
- inherited seccomp or signal state
- app fd table churn
- loader-process-specific lifecycle issues

But it is not automatically a fix for #37. If the helper reuses the same captured dirty `union bpf_attr` and stale `fd_array_cnt`, it will reproduce the same kernel rejection in a cleaner process.

The lower-LOC, higher-ROI immediate fix direction is to sanitize the fresh-load attr in the shim:

- Do not blindly replay optional pointer/count pairs from the original load attr.
- If stock `BPF_PROG_LOAD` uses `BPF_PSEUDO_MAP_IDX` plus `fd_array`, set `fd_array_cnt = 0` unless the shim deliberately builds a continuous eagerly-bound array and wants kernel prebinding.
- Rebuild or clear other stale pointer/count fields with the same discipline.
- Treat `func_info`/`line_info` as remapped metadata, not immutable original bytes.

A helper is still a reasonable later architecture if the project wants daemon-like isolation while keeping an in-process interception shim. It should be designed as a clean-attr executor, not as "daemon clone that memcpys original attrs".

## 5. #35 verifier-PC namespace

The existing verifier-state path assumes that verifier log PCs are directly usable as current CFG PCs:

- `verifier_log.rs` parses verifier log instruction/state records with a numeric `pc`.
- `bbprogram_lift.rs` builds a BTF/CFG pc-to-site map from lifted raw bytecode.
- `lift_verifier_states_by_site()` maps verifier states to sites by exact PC, with a limited special case for `InsnDeltaState`.
- If a non-delta state PC is absent, it fails with `verifier state pc ... is not present in the control-flow graph`.

That fail-fast behavior is better than silently attaching state to the wrong instruction, but it exposes the missing abstraction: verifier PCs and raw bpfopt CFG PCs are separate namespaces after transformations, proof lowering, or metadata remapping.

There is already a nearby partial concept in `bbprogram_btf.rs`: `old_pc_to_current_pc()` remaps BTF records from old/raw PCs to current PCs after bpfopt rewrites. #35 needs the same kind of explicit mapping, but for verifier log PC provenance.

### Proposed interface design

No implementation is proposed here; this is the interface shape needed to make the namespace explicit.

```rust
#[derive(Clone, Copy, Debug, Eq, PartialEq, Ord, PartialOrd, Hash)]
pub(crate) struct RawPc(pub usize);

#[derive(Clone, Copy, Debug, Eq, PartialEq, Ord, PartialOrd, Hash)]
pub(crate) struct VerifierPc(pub usize);

#[derive(Clone, Debug)]
pub(crate) struct VerifierPcRemap {
    pub exact: BTreeMap<VerifierPc, InsnSite>,
    pub raw_pc_for_verifier_pc: BTreeMap<VerifierPc, RawPc>,
    pub disposition: BTreeMap<VerifierPc, PcMapDisposition>,
    pub provenance: VerifierPcProvenance,
}

#[derive(Clone, Debug)]
pub(crate) enum PcMapDisposition {
    Exact(InsnSite),
    DeltaToNextSite { from: VerifierPc, to: InsnSite },
    DroppedUnreachable { pc: VerifierPc },
    Unmapped { pc: VerifierPc, reason: String },
}

#[derive(Clone, Debug)]
pub(crate) struct VerifierPcProvenance {
    pub input_insn_count: usize,
    pub input_bytecode_sha256: [u8; 32],
    pub verifier_log_sha256: [u8; 32],
    pub pass_name: String,
}

pub(crate) fn build_verifier_pc_remap(
    raw_insns: &[BpfInsn],
    cfg: &ProgramCFG,
    verifier_insns: &[VerifierInsn],
    rewrite_pc_map: Option<&RewritePcMap>,
) -> anyhow::Result<VerifierPcRemap>;

pub(crate) fn lift_verifier_states_by_site_with_remap(
    verifier_states: Arc<[VerifierInsn]>,
    cfg: &ProgramCFG,
    remap: &VerifierPcRemap,
) -> anyhow::Result<VerifierStatesBySite>;
```

Policy requirements:

- Full verifier states must fail closed if their `VerifierPc` cannot be mapped exactly or through a proven rewrite map.
- `InsnDeltaState` may keep the current "attach to next surviving site" behavior, but only as an explicit `DeltaToNextSite` disposition.
- The remap must carry provenance so bpfopt can reject a verifier log that does not correspond to the immediately previous successful bytecode.
- If verifier PCs are from kernel proof-lowered bytecode rather than raw BPF bytecode, the remapper needs either kernel-emitted proof-region mapping or bpfopt-side lowering records. Without that mapping, it should return `Unmapped` and fail for stateful passes.

This interface keeps verifier-state consumption fail-fast while making the PC namespace conversion auditable.

## 6. 优先级 + 修复方向汇总

| Priority | Issue | Why | Fix direction |
|---:|---|---|---|
| P0 | #36 bcc/set no shim socket | It blocks all bcc/set ReJIT coverage and has a clear root cause. | Inject shim env in `BccSetRunner._spawn_child()` or centralize bcc process launch; rely on socket discovery by program id. |
| P0 | #37 Tracee stale fresh-load attr | It likely explains most EBADF/EINVAL failures and is cheaper than a helper rewrite. | Reconstruct/sanitize `BPF_PROG_LOAD` attr; clear stale `fd_array_cnt` when using shim-built fd arrays; audit all pointer/count pairs. |
| P1 | #34 katran metadata replay | It blocks transformed fresh loads and affects more than kinsn passes. | Remap or drop/rebuild `func_info` and `line_info` for transformed stock loads; preserve per-pass candidate bytecode/logs for future diagnosis. |
| P1 | #35 verifier-PC namespace | Needed for stateful second-run passes like const_prop without unsafe state attachment. | Add explicit verifier-PC remapper API with provenance and fail-closed policy. |
| P2 | Full fork+exec helper | Useful architecture hardening, but not the first fix for the observed failures. | Consider after attr sanitation; helper must execute clean attrs and should not replay dirty captured `union bpf_attr`. |

Recommended order:

1. Fix bcc/set injection first; it is isolated and immediately restores socket discovery for 21 programs.
2. Fix shim attr sanitation next, especially `fd_array_cnt`; this has the best chance of converting Tracee's EBADF/EINVAL failures into either successes or clearer verifier errors.
3. Address transformed metadata replay for katran and any pass that changes instruction layout.
4. Add verifier-PC remapping before treating const_prop second-run verifier-state failures as pass bugs.
5. Re-evaluate fork+exec helper only after the small ABI sanitation fixes. A helper can reduce process-state risk, but it does not replace correct `BPF_PROG_LOAD` attr construction.

Overall recommendation: do not route every issue through a fork+exec helper yet. The current evidence shows two concrete low-level bugs in runner injection and shim attr replay. Fixing those first will reduce noise and make any remaining helper-worthy process-isolation problems much easier to prove.
