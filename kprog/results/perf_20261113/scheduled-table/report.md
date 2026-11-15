# Scheduled relative code tables preserve the captured target

The normal linker now follows the computed target register through scheduled
instructions until the actual indirect branch, stopping if that register is
written or a different control transfer intervenes. It no longer requires
LEA/MOVSXD/ADD/JMP to be adjacent. Actual OTel overwrites EAX after reading the
table with RAX, so selecting a case from the index at JMP would be wrong.

The one B lowering now captures a finite existing CODE capability before the
schedule and retains the scheduled instructions and generic indirect JMP.
The former early-goto table_dispatch path is removed. Image-bound read/write
and flag effects still require private base/result definitions to be dead;
external CFG entries remain checked. A scheduled read of the removed ADD's
flags or its private registers is rejected, not silently erased. This changes
neither the source application nor the simulator ISA and has no off path.

Validation, same checkout and canonical products, no guest/base publication:

- 41 Rust tests pass, one pre-existing ignored. A real assembly fixture selects
  one of four PC32 code targets, overwrites its index and another observable
  register, and matches all 64 native executions after proof/kernel linking.
  Overwriting the target register removes the table identity.
- The real flag-consuming variant produces a proof but B lowering rejects the
  schedule dependency explicitly. The normal variant compiles through the
  production B path and matches all 64 full shared-simulator executions.
- Existing shared-rodata normal B and 64 simulator cases pass; RELRO map-table
  capability regression preserves 20 cases and three dataflow negatives.
- Current canonical OTel kprobe_unwind_hotspot has four resolved table jumps,
  137 helper-call facts and a full production proof: 39127 blob bytes, 28 nested
  relocations. Its previously unresolved call at +0x211 binds to
  bpf_probe_read_user. The actual proof lowers to shared C: 6945 instructions,
  1030351 source bytes, 1.42 seconds. Native-object/proof/source SHA identities
  and all measurements are retained. This is not the earlier all-object
  59/2504 comparison, nor an app-level acceptance claim.

Raw: /workspaces/kprog-raw/perf/20261115-scheduled-table. New compiled products
replace their canonical files in /var/tmp/kprog-tmp/perf/scheduled-table;
no second CLI/object tree or raw intermediate archive was created. Source
scripts/fixture live in kprog/test. Tests use bounded host CPUs outside0–7
while Katran's isolated A/A runs; no functional guest runs alongside it.

The published normal CLI remains906f5b70 until the image writer lock can be
acquired after A/A. The production release update and actual stock-kernel
subset must follow under the existing locks. Real OTel B backend compilation,
source-context binding, stack acceptance and whole-application execution
remain open; generating shared C is not completing them. No runtime speedup,
code-size target, equal-work certification or final six-app result is claimed.
All native LTO remains combined. M4–M6 obligations for this existing CODE
selection still need the full compiler/semantics proof, not just host tests.
