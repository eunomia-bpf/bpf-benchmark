# Tracee and BCC native probe-read lowering inventory

Actual optimized ARM native IR from the existing8BCC and3paired Tracee translation units. The application C, native production recipe, division lowering, benchmark framework and current running replay epochs retain their captured definitions.

Successful IR compiles: 11/11. Static probe-read helper calls: 61. Scalar kernel-read candidates with a constant single-load width and an unused helper return: 46.

| Helper | Static calls |
| --- | ---: |
| probe_read_kernel | 56 |
| probe_read_kernel_str | 3 |
| probe_read_user_str | 2 |

## Lowering interface

The existing kernel helper copies bytes and clears the destination on a read fault. Its return carries0or-EFAULT. Scalar fixed-size calls whose return is discarded can express the same destination observation through one protected native load followed by the destination store. Sizes1/2/4/8 correspond to the existing native scalar read forms and stock exception-table full-register zero/resume behavior. Calls that consume the helper result, wider copies, strings and user reads retain their existing helper operation while the following lowering work develops their complete return/copy/fault behavior.

The Tracee native helper ABI carries helper identity through its existing empty inline-assembly marker and inttoptr call. BCC uses ordinary named calls. inventory.json retains every site and exact IR line, compiler command, source/dependency identity and status. inputs.tar.gz retains optimized IR, actual source dependencies, plugin, scripts and compiler output. This inventory provides compiler selection evidence; production lowering, generation-bound replay and hardware performance supply subsequent measurements.
