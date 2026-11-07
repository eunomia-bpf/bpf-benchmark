# Finite private-stack/external ABI aliases on ARM

The ABI dependency checker dropped different pointer origins to unknown.
An unrelated opaque callee-save slot then made valid HotSpot and Perl loads
look undefined. Edge traces retain the exact HotSpot stack/external select
and Perl SP+152/SP+128 join that caused the failures.

Finite stack offsets and an explicit external-memory alternative now remain
separate, including stack offset0 versus Python False. Loads intersect all
candidate defined bits. Weak stores retain old taint; copied opaque bytes stay
opaque across every source alternative. Pointer-changing arithmetic widens
conservatively, while fixed memory displacements retain finite choices.
Fresh ADR/ADRP addresses reset old provenance. Masking a joined pointer cannot
silently label it external and hide opaque bytes. There is no ISA simulator
change, runtime bound, program-name exception or disabled dependency check.

All173 assembled ABI controls pass, including ten focused alias cases.
The same controls on the prior checker have167 passes: four defined positive
cases reject, a copy-source negative rejects under a different message, and
the opaque masked-pointer negative incorrectly generates. The fixed outcome
JSON retains exact messages; no unsafe native code is executed by this check.

All14 full ELF/BTF candidates now generate for 13 distinct observed OTel
name/type/instruction-count selectors. The extra candidate preserves both
sched_process_free variants sharing one truncated name and size. Runtime
selection uses the exact full source-BTF symbol; no variant is guessed away.
The known probe_bpf_perf_ capability check follows the existing shim policy
and stays unchanged, with every feature-probe record retained separately.

Two earlier compiled proofs were linked and opened successfully with libbpf.
The original object contributes maps/global data through a link-only copy
without duplicate executable sections or their unused BTF.ext records; its
map/global payload bytes are checked unchanged. The upstream application
object remains intact. A prior ELF-only globalization attempt and its BTF
linkage failure are retained. No application loader is replaced.

Current14-proof compilation is detached under otel-real-v8 with one32GiB
compiler (98GiB available at launch). The prior12GiB failure remains recorded.
V8/V9 generated C bodies match after normalizing only the declaration-header
phase path. No current-stage install or full OTel bound workload is claimed;
compilation, verifier acceptance and application execution remain pending.

Reproduce via the dated Makefile: abi-effect-check PHASE=NEW_ABI,
otel-real-generate PHASE=NEW_OTEL, compile PHASE=NEW_OTEL,
then otel-real-link PHASE=NEW_OTEL. Install only after every artifact exists.
The archive freezes all regression assembly/outcomes,14 native/proof/source
inputs and their simulator contracts, constructor code and ELF preflight.
