# Source helper names resolve through their UAPI identity

Tracee sys_enter_submit fails native linking because its upstream object calls
bpf_probe_read, while the unbound loader exports only bpf_probe_read_compat.
Its string-read helper has the corresponding public/kernel spelling mismatch.
The failure precedes native installation; Tracee then reports invalid argument.

The existing unbound helper table associates each kernel symbol with a BPF
helper ID. For every resolved entry, the loader now adds the UAPI name generated
from that ID at the same address. The kernel implementation name stays available.
This handles every differing spelling in the supported table without translating
legacy read helper4 to kernel-only helper113. The context-query path already
binds both spellings to the actual prototype. Upstream Tracee, native P, compile
flags, kernel, workload and the timing entry are unchanged.

The existing kernel helper regression now builds a production unbound link plan
and compares every differing spelling against the actual loaded program's
get_func_proto query and kallsyms. The updated production resolver compiles;
the ten-program-type kernel subset follows. Application timing uses only the
unchanged default corpus entry, as assigned to C's breadth-first round.

The actual ten-program-type kernel subset passes. Kprobe unbound aliases4 and45
match both their kernel symbols and the loaded program's get_func_proto query.
The existing wrong-type query failure is also preserved. All Tracee object
undefined BPF helper spellings are already represented by the supported table;
this fixes the two differing public/kernel spellings without editing its source.
Sole-image loader publication follows, then C's unchanged-default breadth round.

Published00:07:50Z in sole imagefc408f64. Shipped loaderc296f028, linkerf7de4bfc
and shim19f2f67a match their inputs. Kernel/modules, base B compiler and1252
native files remain stable. C's full-default breadth round supplies the
application outcome; the alias kernel test establishes the binding identities.
