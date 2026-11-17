# Compact live globals, prepared item 1c

Prepared 2026-11-17T13:20Z against `11c4b36ac`, not applied or host-validated.
Scope: the probe-read emitter and its existing Rust test module only. The
pending batch-2 source and canonical build remain unchanged.

`edit.py` prints a proposed diff by default; `--apply` updates the sole
checkout after Omp's batch-2 image snapshot. It keeps USER_PTR_MAX, SMAP
capability and virtual-address width as live reads. Full signed-disp32
addresses use absolute SIB operands with 64-bit address size; others retain
MOVABS R11 and an indirect operand. Folding the BTF member displacement
into that full address also removes the redundant disp32 in wide forms.
There is no new runtime check, refusal, selector or cached variable value.

Local encoding sizes: qword load 13 to 8 B for compact addresses;
capability TEST including immediate 21 to 11 B (wide 17 B); byte MOVZX
18 to 8 B (wide 14 B). These are source-derived sizes, not actual installed
app totals or per-call gains. The edit preserves the surrounding policy,
cleanup, zeroing and recovery sequences. The proposed regression test
checks all three forms at seven address boundaries, including high-half
sign extension; existing host execution fixtures retain wide synthetic
addresses. This proposal has not yet passed either test.

Next: preview under timing SH on CPU 19, inspect the patch, then apply
after the image snapshot. Run the full existing linker suite using the
canonical host recipe in `../leaf-batch2-20261117/run-host.sh` under timing
SH with a distinct persistent raw attempt directory. Do not overwrite its
prior receipts. Retain emitted payloads, decode/compare recovery metadata
and record actual sizes; commit source and optimizations.md only after
host validation. Omp schedules image/check and target-app timing under the
batch lock. Constant-size probe specialization remains the next part of
item 1c; this prepared change does not implement it.

Preview receipt, 2026-11-17T13:40:17Z: source-anchor preview exited 0 at13:37:21Z, with empty stderr. `preview.json` records its persistent raw patch path. This checks the prepared edit only; runtime source remains unchanged and Rust/host validation is pending.

Prepared fixture refinement, 2026-11-17T14:03:29Z: folded wide field addresses need relocation relative to the boot_cpu_data marker, not just an exact base match. The edit now includes that C fixture relocation and low signed-disp32 marker relocation into the existing -no-pie globals. Four compact scalar/string execution cases are added beside the four wide ones, with distinct output names, while the seven-boundary decoder test covers high-half sign extension. No production source has been applied and these refined cases are not yet run. Apply after the helper-tail job finishes, under timing SH/image EX; the old snapshot-wait wording is superseded by image-lock ordering in shared-helper-tail-20261117.

Validated 2026-11-17T14:15:55Z: source4d6db459a is committed/pushed. Canonical host suite45 passed/3 existing ignored, including wide/compact execution variants and21 signed-address decode cases. Host2595751 ran14:10:57Z to14:11:37Z under timing SH/image EX/Git EX. `host-output.txt` and `host.json` preserve results. Payload bytes below include RET, not app installed code.

| Leaf | Original wide | New wide | New compact |
|---|---:|---:|---:|
| Kernel scalar |366|362|351|
| User scalar |370|366|355|
| Kernel string |282|278|267|
| User string |400|396|385|

Wide compat fixtures shrink827 to819 B and773 to765 B. Clock341 B and UID/GID53 B are unchanged. Policy, exact-site fault recovery and full zeroing vectors pass in both operand forms. Installed native/JIT and per-call/body/helper/map measurements remain for Omp; no image/guest was started here.
