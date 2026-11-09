# Tracee and BCC native probe-read lowering inventory

Actual optimized ARM native IR from the existing8BCC and3paired Tracee translation units. The application C, native production recipe, division lowering, benchmark framework and current running replay epochs retain their captured definitions.

Successful IR compiles: 11/11. Static probe-read helper calls: 23665. Scalar kernel-read candidates with a constant single-load width and an unused helper return: 17981.

| Helper | Static calls |
| --- | ---: |
| probe_read | 1679 |
| probe_read_kernel | 19746 |
| probe_read_kernel_str | 1510 |
| probe_read_str | 717 |
| probe_read_user | 11 |
| probe_read_user_str | 2 |

## Lowering interface

The existing kernel helper copies bytes and clears the destination on a read fault. Its return carries0or-EFAULT. Scalar fixed-size calls whose return is discarded can express the same destination observation through one protected native load followed by the destination store. Sizes1/2/4/8 correspond to the existing native scalar read forms and stock exception-table full-register zero/resume behavior. Calls that consume the helper result, wider copies, strings and user reads retain their existing helper operation while the following lowering work develops their complete return/copy/fault behavior.

The Tracee native helper ABI carries helper identity through its existing empty inline-assembly marker and inttoptr call. BCC uses ordinary named calls. inventory.json retains every site and exact IR line, compiler command, source/dependency identity and status. inputs.tar.gz retains optimized IR, actual source dependencies, plugin, scripts and compiler output. This inventory provides compiler selection evidence; production lowering, generation-bound replay and hardware performance supply subsequent measurements.

The complete Tracee marker receipt ef3acc532 follows the actual ARM inline-assembly constraint =r,r,r,r,0,~{memory}: helper identity occupies the final input, tied to output0. Debug metadata uses keep their diagnostic role in the IR; executable SSA uses determine return-value consumption. The initial named-call inventory e5fc5ea23 and its preserved initial records remain in the input archive. Full counts are23665static probe-read calls and17981scalar kernel-read candidates:Tracee17935/BCC46. The existing single-load sizes are1:13,2:91,4:3904,8:13973.

Closed Tracee register/width native caches and image copies retired260700270bytes. [cleanup.json](cleanup.json) maps every file to its earlier published paired-artifact archive or the additional content archive closed-tracee-images.tar.gz. The current Unix-length application image, active private model/runtime snapshots and warm compiler/kernel caches retain their current lifetimes.
