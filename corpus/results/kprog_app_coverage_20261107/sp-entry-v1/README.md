# Private direct-SP numeric candidate

The existing simulator represents RSP as an offset into its private arena. Using that offset as the architectural integer made restored-stack ZF true and hid a real NULL read. This candidate supplies the native entry SP through the existing ABI2 input, adds the base on numeric RSP reads, and normalizes scalar RSP writes back to the arena offset. Pointer-based memory indexing is retained. Narrow writes merge the actual old address before normalization.

| Check | Published header | Private candidate |
|---|---:|---:|
| Native CPU ADD/SUB,8/16/32/64,40,960 cases |23,243 differences|0 differences|
| Same25 load-only negative cases |previous suite had SP accepted|19 verifier rejects,6 specialization rejects,0 accepted|

The CPU comparison executes real ADD/SUB instructions with a general register containing the source SP bits (same architectural value/flag semantics without changing the process stack). It checks all six defined arithmetic flags and full resulting SP bits. Inputs include F's observed ASLR base0x7ffe42c11950, wrap/sign boundaries and1024 samples per width/op/base. The initial harness used a64-bit RHS where ADD-immediate is sign-extended32; that erroneous run is retained and corrected. The final before control uses the exact pinned old header, with the same inputs.

`stack_base_flags` now exposes the NULL read to the verifier and fails at `R1 invalid mem access 'scalar'`, after ABI2 entry SP is modeled as an unknown scalar. Unsafe native code was never executed.

This increment is validated for direct RSP numeric reads and scalar writes. Copied stack pointers and other alias observations still require the complete numeric representation; these results do not close the whole SP family. The first private full check built all367 Lean modules but failed legacy route fixtures that expected zero-origin numeric RSP. The next candidate uses the explicit host entry-input callback and reuses the existing zero-origin host fixture in those oracle builds; actual CPU observers supply their captured base. No old oracle case/assertion is removed. Paired29-micro regression completed:29/29 compile in both arms;28/29 verifier accepts in both, with identical existing Cilium socket-LB scalar NULL-write rejection and no changed outcome. The complete private FULLv2 check exits0, with its full source hashes/logs retained in `full-v2-success.tar.gz`.

`candidate.patch` contains only the intended8 source overlays against `provenance.json`'s base. The same8 source hunks are promoted to production; unrelated shared working changes are preserved. `entry-source-and-cpu.tar.gz` contains exact private headers/contracts and CPU inputs; `frozen-inputs.tar.gz` contains the first negative build's complete inputs; `negative-results.tar.gz` contains raw outcomes and verifier logs. The host-environment correction does not change the BPF ABI2 input operation.

Build/replay through the result Makefile targets `sp-entry-v1-build`, `sp-entry-v1-run`, `sp-entry-v1-positive-build` and `sp-entry-v1-positive-run`. CPU replay uses `cc -O2 -fsanitize=undefined -fno-sanitize-recover=undefined -I PRIVATE_SOURCE/kprog/x86 -I vendor/libbpf/src cpu.c`; the before control additionally defines BEFORE and preincludes the retained before.h. Kernel loads use the same frozen kernel as the other lane C diagnostic runs. CPU12-15 load diagnostics supply no comparative performance numbers.
