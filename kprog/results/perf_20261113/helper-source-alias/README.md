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
