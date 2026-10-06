# Tracee `syscall__init_module` REJIT `EINVAL` Investigation

## Conclusion

This looks like a **kernel-side `BPF_PROG_REJIT` limitation**, not a daemon bug that generated verifier-invalid bytecode.

The failing program is a Tracee `raw_tracepoint` program named `syscall__init_module` / `syscall__init_m` with:

- `prog_type = 17` (`raw_tracepoint`)
- `btf_id = 20`
- one direct tail call through `prog_array_tp` with constant key `3`

The daemon does transform this program, but:

- every changed intermediate is accepted by per-pass `BPF_PROG_LOAD`
- the final instruction count stays `101 -> 101`
- the tail-call-sensitive passes already preserve REJIT index stability

The kernel source narrows the live `EINVAL` to the REJIT poke-table compatibility check for direct tail calls. That is a kernel REJIT constraint, not a generic verifier rejection.

## 1. Where The Daemon Gets `EINVAL`

The final live apply path is:

1. `try_apply_one()` builds the optimized instruction stream, relocates map FDs, and calls `bpf::bpf_prog_rejit(...)`  
   `daemon/src/commands.rs:725-740`
2. `bpf_prog_rejit()` calls `run_rejit_once()` and retries with `log_level=2` on failure  
   `daemon/src/bpf.rs:1662-1692`
3. `run_rejit_once()` issues the `BPF_PROG_REJIT` syscall and, on negative return, reports the raw errno as `BPF_PROG_REJIT: ...`  
   `daemon/src/bpf.rs:1608-1657`

So the userspace daemon is not synthesizing `EINVAL` itself. It is surfacing the kernel's syscall failure.

## 2. Did The Daemon Produce Invalid Bytecode?

I did not find evidence for that.

From the existing Tracee run artifact for this exact program (`result.json`, prog id `113` / `630`):

- `map_inline` changed 1 site, at `PC=14`
- `const_prop` changed 1 site
- `dce` changed 2 sites
- every changed pass had `verify_result = accepted`
- `verifier_rejections = 0`
- final instruction count stayed `101`
- `dce` explicitly reported: `neutralized 2 dead-def insns to preserve tail-call poke indices`

Source references:

- per-pass live verification uses `BPF_PROG_LOAD` after map-FD relocation  
  `daemon/src/commands.rs:533-627`
- final live REJIT uses the same relocated map-FD path  
  `daemon/src/commands.rs:725-740`

Pass behavior is also already tail-call-aware:

- `const_prop` computes a protected prefix ending at the last tail call and filters replacements through `tail_safe_const_prop_replacement(...)`  
  `daemon/src/passes/const_prop.rs:198-219`
- `dce` disables unreachable/NOP stripping when a tail call exists and uses `eliminate_dead_register_defs_tail_safe(...)` instead  
  `daemon/src/passes/dce.rs:37-87`
- the protected region is defined specifically to preserve tail-call poke descriptor indices during REJIT  
  `daemon/src/passes/utils.rs:83-104`

The live run details also matter:

- the only `map_inline` success is at `PC=14`
- the direct tail call is near the end of the program, not at the rewritten site
- instruction count remained unchanged after every changed pass

That combination does **not** look like "daemon emitted bytecode the verifier rejects." The verifier already accepted each changed program.

## 3. Kernel `EINVAL` Path For `BPF_PROG_REJIT`

The interesting kernel path is in `vendor/linux-framework/kernel/bpf/syscall.c`.

Top-level `bpf_prog_rejit()` does have two trivial `-EINVAL` exits for malformed attrs:

- `CHECK_ATTR(BPF_PROG_REJIT)`  
  `vendor/linux-framework/kernel/bpf/syscall.c:3611-3612`
- non-zero `attr->rejit.flags`  
  `vendor/linux-framework/kernel/bpf/syscall.c:3614-3615`

Those are not credible here: the same daemon path succeeds for the other 157 Tracee programs.

After verification/JIT, the program-specific `EINVAL` path is:

- `bpf_prog_rejit()` calls `bpf_prog_rejit_update_poke_tab(prog, tmp)`  
  `vendor/linux-framework/kernel/bpf/syscall.c:3799-3808`
- if that returns an error, the kernel warns `bpf_rejit: poke_tab update failed: %d` and aborts the REJIT  
  `vendor/linux-framework/kernel/bpf/syscall.c:3804-3808`

`bpf_prog_rejit_update_poke_tab()` returns `-EINVAL` only when the old and new direct-tail-call poke patterns do not match:

- `prog->aux->size_poke_tab != tmp->aux->size_poke_tab`  
  `vendor/linux-framework/kernel/bpf/syscall.c:3224-3225`
- or any poke entry differs in:
  - `reason`
  - `tail_call.map`
  - `tail_call.key`  
  `vendor/linux-framework/kernel/bpf/syscall.c:3241-3248`

The kernel comment is explicit:

- REJIT requires the tail-call pattern `(count, map, key)` to be identical between old and new bytecode  
  `vendor/linux-framework/kernel/bpf/syscall.c:3193-3199`

So the concrete failure path is:

`bpf_prog_rejit()` -> `bpf_prog_rejit_update_poke_tab()` -> `return -EINVAL`

## 4. Why `syscall__init_module` Is Special

This program has a direct tail call, which is exactly the feature guarded by the poke-table compatibility check.

From the object disassembly of `corpus/build/tracee/tracee.bpf.o`, section `raw_tracepoint/sys_init_module`:

- `pc 95`: load `prog_array_tp`
- `pc 97`: `r3 = 3`
- `pc 98`: `call bpf_tail_call`
- `pc 99`: `r0 = r6`
- `pc 100`: `exit`

So `syscall__init_module` is not just any raw tracepoint program. It is a raw tracepoint program with a **constant-key direct tail call through a `PROG_ARRAY`**.

The verifier turns exactly that pattern into a poke descriptor:

- `reason = BPF_POKE_REASON_TAIL_CALL`
- `tail_call.map = aux->map_ptr_state.map_ptr`
- `tail_call.key = bpf_map_key_immediate(aux)`  
  `vendor/linux-framework/kernel/bpf/verifier.c:24159-24172`

`bpf_map_key_immediate()` is the immediate key value stored in verifier aux state  
`vendor/linux-framework/kernel/bpf/verifier.c:244-247`

By contrast, I did **not** find a special REJIT rejection path for:

- `raw_tracepoint` itself
- BTF-bearing tracing programs

`bpf_prog_rejit_supported()` only rejects:

- non-JITed programs
- `is_func`
- offloaded/dev-bound programs
- attached `EXT` programs without `dst_prog`  
  `vendor/linux-framework/kernel/bpf/syscall.c:3167-3199`

Tracee `syscall__init_module` does not match those exclusions.

## 5. Is Map Rebinding A Daemon Bug?

I looked at that specifically because the kernel compares raw `tail_call.map` pointers.

The daemon's relocation logic is:

- capture stable `old_fd -> map_id` bindings from the original program  
  `daemon/src/pass.rs:94-98,178-204`
- before per-pass verify and before final REJIT, reopen live map FDs by those map IDs and patch every pseudo-map load  
  `daemon/src/bpf.rs:1311-1413`

This matches the kernel's own ordering:

- the verifier records `used_maps` in first-seen order  
  `vendor/linux-framework/kernel/bpf/verifier.c:22041-22081`
- `BPF_OBJ_GET_INFO_BY_FD` exposes `map_ids` in that same `used_maps` order  
  `vendor/linux-framework/kernel/bpf/syscall.c:5881-5894`

So the daemon's stable binding scheme is consistent with the kernel's metadata model. I did not find evidence that it would accidentally bind `prog_array_tp` to the wrong map object for this program.

That does not mathematically prove the map pointer can never mismatch, but it means there is **no obvious daemon-side relocation bug** in the code path I inspected.

## 6. About `failure_pc = 99`

Do not over-interpret `failure_pc = 99`.

The daemon extracts that from the verifier log with:

- explicit error-line parsing first
- otherwise fallback to the last seen state PC  
  `daemon/src/verifier_log.rs:127-170`

`99` is the instruction immediately after the tail call in this program, so it is consistent with a post-verifier REJIT failure. It is **not** strong evidence that the verifier rejected instruction `99`.

## Root Cause

**Root cause: kernel limitation / kernel-side REJIT rejection, not a daemon bytecode bug.**

More precisely:

- the failing program contains a direct tail call via `prog_array_tp[3]`
- `BPF_PROG_REJIT` requires the old and new direct-tail-call poke pattern to match exactly
- the observed `EINVAL` is most plausibly coming from `bpf_prog_rejit_update_poke_tab()`

Without kernel log access on this host, I cannot distinguish which exact sub-check failed:

- `size_poke_tab` mismatch
- `tail_call.map` mismatch
- `tail_call.key` mismatch

But the failure is still kernel-side either way, and the source code narrows it to that poke-table path.

## Is This Fixable In The Daemon?

**Not in a principled way.**

What the daemon can do:

- keep surfacing the failure in results
- add better diagnostics when a program contains direct tail calls and REJIT returns `EINVAL`

What the daemon should **not** do:

- reintroduce skip logic or exclusions for this program
- silently suppress the failure

Why I do not consider this daemon-fixable:

- the bytecode already passes per-pass verifier checks
- the daemon already preserves instruction-count stability around tail calls
- the kernel is the component enforcing the exact poke-table identity rule

The only daemon-side "fix" would be a workaround such as refusing to transform direct-tail-call programs, which is explicitly the wrong direction for this project.

## Recommended Action

1. Treat this as a **kernel REJIT limitation** for now, not as a daemon correctness bug.
2. Keep reporting the failure naturally in benchmark results. Do not add exclusions.
3. If this must be made to succeed, fix the kernel REJIT path:
   - either relax the poke-table compatibility rule for semantically equivalent direct tail calls
   - or add precise diagnostics telling us whether the mismatch was `size_poke_tab`, `map`, or `key`
4. Optionally improve daemon diagnostics so `EINVAL` on a program with direct tail calls is annotated as "likely poke-table mismatch in kernel REJIT path."

## Prior Analysis Cross-Check

The earlier note in `docs/tmp/tracee-regression-analysis-20260424/summary.md` correctly observed the symptom but did not identify the cause. This investigation narrows that symptom to the kernel REJIT tail-call poke-table path.
