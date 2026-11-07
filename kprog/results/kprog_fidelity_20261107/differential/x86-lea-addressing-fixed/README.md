# Repair absolute and address-size32 LEA encoding

All 69 newly added forms now agree with the real CPU and canonical reference
on 70,656 states. The ten failing forms' 10,240 differences in the sibling
`x86-lea-addressing/` baseline are fixed; its original observations remain.

The production change is two encoder hunks:

- Parse GNU objdump's unbracketed absolute operand `ds:0x...` as its actual
  displacement, including 16-bit partial-register writes.
- Normalize address-size32 LEA with a 64-bit destination through the existing
  32-bit writeback, which truncates the address and zero-extends it. A native
  16-bit destination retains its partial-register write.

No simulator/header instruction semantics or runtime guard was added.
`address32_step_refines` proves the normalization as a whole-state transition
against V's existing canonical LEA step, without assuming upper input bits
are zero. A separate linker hunk admits absolute LEA address computation;
its paired unit keeps actual absolute LOAD rejected. The native-link source
archive contains that exact final hunk and no other lane's uncommitted work.

| Final exact producer observation | Forms | Cases | CPU/C differences | CPU/reference differences |
| --- | ---: | ---: | ---: | ---: |
| LEA family | 73 | 74,752 | 1,024 existing SP | 0 |
| Existing control observers | 42 | 43,008 | 0 | separate earlier coverage |
| Newly added LEA forms | 69 | 70,656 | 0 | 0 |

Primary CPU records are under `published/`. Every generated production
snapshot file was byte-checked against final private tree
`f57ab4a4e1de16ebe04108306ab0b59759cf24a5`. Canonical native-byte reference
revision remains8480a34f137fca66a4b9041a7e3978f22fe5ba90; its executable and
source archive are retained in sibling `x86-lea-published/`. LEA receives no
memory cells and must return no memory events, while every observed memory
byte, 16 GPRs, six arithmetic flags and XMM0 are compared.

Both exact private FULL checks pass: original two-file encoder/theorem tree
5741efa5070326100add18d7fda92c8af4dba278, then final three-file tree above
including the linker repair. Full logs, source manifests and `checked-source`
archive are retained; temporary source/cache exports were deleted on exit.
All 78 Rust linker tests pass. KVM controls and 29+1 proof builds are in
[../../negative/x86-lea-addressing-fixed/](../../negative/x86-lea-addressing-fixed/).

The first broad rerun used the concurrent working-tree header, which included
C's uncommitted stack-write prototype. It has885forms/906240cases and11264
remaining differences across11 SP forms. Its trace, binary, actual header and
all counterexamples are preserved at this directory's root. The exact header
difference is recorded, and this ROOT run is not presented as the checked
private source. The extra `add rsp,16` row exposes the existing missing native
SP bits through PF (native stackbase0x7ffe42c11950, native flags0x206 versus
C0). Earlier stack placement accidentally matched that flag. No ADD encoding
was changed; C has the new counterexample along with the ten older SP rows.
The exact-published LEA run retains its one SP row rather than waiving it.

Commands through bws.sh, from `/workspaces/repository`:

```sh
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-lea-addressing-fixed -f published.mk build cpu
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-lea-addressing-fixed -f published.mk reference
```

The second command exits2 for the real SP mismatch. All raw traces remain in
the Workspace, with recorded hashes; all mismatch inputs are also committed
as compressed JSONL. `published.mk` restores frozen producer source and only
selects LEA forms from the existing generator, retaining its normal control
observers. This is input selection and serialization, not a second ISA model.
