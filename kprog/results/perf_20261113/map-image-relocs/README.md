# Native map literals and image pointers

Kernel099357174783 / parent5c3c95a4d correct map-pointer/map-value fallthrough
into image-pointer rebasing. Only kind12 may add the image base; map literals
must retain the address resolved from B's lifetime-bound map resources.

The small existing-module/real-kernel fixture covers a map-value offset8,
map-pointer vs direct-value address, and an image-relative code target that
then accesses a map value. It uses a real ARRAY map, stock-verifiable B holding
the map, and BPF_PROG_TEST_RUN; it does not substitute fake map pointers.
The array-value layout is read from boot BTF facts.

Old sole boot8cafa600/kernelbdfa: control-v2 first case load=-524, expected42;
remaining cases not reached. This reproduces the fresh OTel checked-native
installation failure independently. The first control failed because guest
/var/tmp hid the layout file; fixed by an explicit read-only layout mount.
Both attempts/logs remain. No old-kernel execution success is claimed.

Kernel refresh attempt1 failed before boot/image replacement because caller
OUTPUT/Make overrides leaked into Kbuild host-tool outputs.606ae1d0e isolates
those variables at the refresh script boundary; all canonical output arguments
remain explicit.67 accidental host-tool build files/header copies were removed
with exact hash/size inventory; Make logs and command text stay. Retry completed
on the sole build under imageEX, retaining the single kernel, image and base.
The dry-run cannot create the later boot/kernel.kallsyms dependency, so its
missing-generated-file status is recorded separately from actual execution.

Raw: /workspaces/kprog-raw/perf/20261115-map-image-relocs/.
Corrected-kernel execution completed at18:21:41Z, Make0. All three cases load
and execute successfully: map-value-offset42, map-pointer-and-value304 (the
boot-BTF array value offset), image-pointer-to-map-value42. The old-kernel
failure and the fixed executions use the same fixture and real map resources.
Small command/status/result receipts are in fixed/.

Kernel publication completed18:14:16Z, Make0, source099357174783. The sole image
is fc5336c2, replacing d4b19c9f; the packaging cleanup records the superseded
image as already absent. All1193 staged native paths match the image. Existing
clock LTO and app objects stay installed. Kernel source/build/boot, module and
image receipts are in kernel/; full logs/inventories stay in the raw directory.

Fresh whole-app OTel retry launcher1148872 started18:21:58Z, CPUs16-19,
2vCPU16GiB/32GiB address-space cap, imageSH. It uses the existing checked-corpus
target and the current image manifest. Application installation, output parity
and performance remain open.
