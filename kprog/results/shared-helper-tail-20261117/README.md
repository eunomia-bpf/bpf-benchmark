# Shared helper leaves must accept helper tail jumps

Source finding at `5ddd51986`, 2026-11-17. Prepared fix only: no source
application, failing execution, actual app failure or validation is claimed.
The pending batch-2 image inputs remain unchanged.

`native_link/src/x86.rs:1232` creates `HelperBranchRel32` with opcode E9 for
a resolved external helper tail transfer. `:1735-1755` validates its original
opcode and writes the same helper relocation kind used for E8 calls, with
four zero displacement bytes. The relocation format therefore carries both
call and tail-jump sites. This includes ordinary compiler sibling calls.

Later, `x86_probe_read.rs:313-324` selects that relocation kind and helper
target, then requires the whole five-byte slot to equal E8/zero-disp32.
`x86_ktime.rs:118-128` repeats that requirement. `x86_task.rs:36` uses the
probe redirect function. Thus an E9 to a newly shared helper reaches the
existing refusal even though the earlier x86 emission explicitly supports
that transfer. Current six-app functional checks pass; those checks do not
demonstrate this source shape is absent from other native programs.

The same predicate appears in generic ARRAY sharing
(`x86_runtime_array.rs:53-60`) and LPM sharing (`x86_lpm_lookup.rs:82-85`).
The prepared class fix routes both through the existing common redirect
too. Their nested external kernel-helper slots remain E8: the direct
loader requires those external call slots, whereas these retargeted local
branches no longer have an external helper relocation. Do not widen the
frozen loader or change the nested fallback to a tail JMP.
The direct-loader predicate is in
`kprog/perf/direct-native/bpf_x86_native_lab.c:222,250-256`; it compares the
external slot against E8 followed by four zero displacement bytes.

The prepared edit widens that one existing slot predicate to accept E8 or
E9 with zero displacement, patches only disp32, and makes clock sharing use
the same redirect function. It removes duplicated clock/map predicates and
adds no new check, refusal, kernel or metadata format. A helper tail jump
must remain E9: changing it to E8 would add a return frame. A leaf's RET then
uses the original caller's return address, just as the external helper does.
The x86 tail cleanup and nested leaf/kernel relocations remain unchanged.

The edit adds a direct relocation regression case that also executes call
and tail-jump entries through the existing native host harness and returns
from the same constant-result body. It makes the existing
clock/credential/ARRAY sharing fixtures contain both opcodes; the LPM
execution fixture also checks mixed sharing and its retained E8 external
kernel call. After applying, run the complete existing linker suite with the fix,
including native execution/fault and recovered-site metadata. Test both
opcodes target the same single shared body and retain their original byte.
An end-to-end compiler sibling-call fixture is useful if actual link
provenance is unclear; do not change the benchmark to manufacture it.

`edit.py` previews by default and applies only with `--apply`. Host preview
and validation take timing SH on CPU 19, with persistent raw logs. Apply
after Omp's batch-2 image snapshot, before the prepared compact-global
optimization: this is pipeline correctness. The old predicate directly
rejects the mixed test's E9 slot; no separate old-version build or second
source copy is needed. Commit source and receipts
after validation and let Omp schedule the next image/check. Successful E8
paths should keep their emitted bytes; E9 previously refused, so its new
native installed bytes/per-call measurements cannot be inferred here.

Preview receipt, 2026-11-17T13:40:17Z: source-anchor preview exited 0 at13:37:21Z, with empty stderr. `preview.json` records its persistent raw patch path. This checks the prepared edit only; runtime source remains unchanged and Rust/host validation is pending.

`run-host.sh` applies this edit and runs the complete canonical linker suite under timing SH on CPU19, with a fresh persistent attempt directory and32GiB address-space bound. Start it after the batch-2 snapshot. It compares every retained batch-2 leaf payload and recovered-load sites file against the new output; successful E8 leaf bodies should stay identical. It does not publish an image or start a guest, and it does not rebuild the unchanged loader. Inspect/reduce the prepared patch before starting it.
