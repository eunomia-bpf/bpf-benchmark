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

Normal publication finished after A/A released imageSH. The initial new CLI
was6b0fa6f7; removing the unused pre-CFG register-write guess (af7b72e03)
and rebuilding under imageEX gives final CLI45c33e7e. Final Rust run remains
41 passing / one existing ignored, and the release builds without that dead
code warning. Loader4e1a3af7, bounds5236d0ea and checked compiler907b671d are
unchanged. Exact source/tool SHA records are retained. Same base/kernel/image.

Actual sole-kernel subsets:

- First plain-libbpf fixture attempt loaded referenceID5, then stopped before
  the B verifier because kprog_unspecified_input was treated as a kernel BTF
  symbol. This is a fixture resource-binding error, not verifier rejection.
- 1408eb095 uses the production relocate_trusted_proof implementation and an
  actual mutable ARRAY-map ID, as the loader does. The corrected pure-stock
  run returns sourceID3 (72 translated /48 JIT bytes) and B ID4
  (288 translated /119 JIT bytes), both stock_accepted=true. MapIDs1/2 are in
  the raw result. No native installation or KPROBE execution in this run.
- For the registered checked replay, c24fee460 aligns the synthetic source
  and model entry names with the production interface. Its first attempt
  failed before verification because the canonical build directory was not
  mapped into the guest. b3b2cbfbf adds the same explicit mapping as the
  existing replay target, preserving one physical build product.
- Corrected replay870892 exits0 with actual stock_accepted=true,
  context_and_map_shapes_equal=true, checked_installed=true, reply status0
  and native prog_id11. It verifies B before compiling and loading the
  checked native image. The source/IR hashes are bound in the replay result;
  all current input/product identities and the guest-to-host path mapping
  are recorded. This is load-only, not KPROBE execution or an application run.

All failed and corrected logs remain under the raw directory and here. No
compiled object/image copies were archived into this result. The first
corrected pure-stock run predates the fixture-name alignment; its old full
ELF SHA was not captured, so do not attribute the later object SHA to it.
The checked replay records its own frontend identities and source context.

The scheduled-table fixture pipeline is now stock-verified and checked-native
installed. Actual OTel full B compilation/source-context binding, stack
acceptance and whole-app execution remain open. Generating its proof/shared
C does not complete them. No runtime speedup, code-size target, equal-work
certification or six-app result is claimed. All LTO remains combined;
M4–M6 obligations still require the compiler/semantics proof.
