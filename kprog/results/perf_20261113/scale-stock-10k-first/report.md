# First production10K scale case: frontend SIGKILL

The existing bounded production batch completed its first10K case,
`n10000_scalar_direct`, with proof_compile status-9/SIGKILL. Native assembly
contains10036 instructions for the10000 target; generated simulator C is
1067082 bytes and joined preprocessing is296927319 bytes. Ordinary-input
stock-header/chunk/bounds compilation is the current production pipeline.

The failed original frontend command and its resource receipt are included:
5693.314s wall, 5656.785s user,
73,891,664KiB maximum RSS (70.469GiB).

This failed before a B object existed, so this case has no kernel verification
or test executions. A successful native assembly compile is not a proof pass.
No matching OOM-kill line for compiler668188 was found in the available dmesg
read; the reason for SIGKILL remains unconfirmed. The original snapshot near
10GiB RSS was not its eventual peak.

The whole batch666038 remains active, records independent remaining cases and
will run the final kernel stage on whatever actually compiled. No process was
stopped, no duplicate frontend was launched and no in-flight limits changed.
The earlier production100/1K eight actual stock-kernel passes remain separate
valid subset results. This failure is practical compiler-resource evidence,
not a demonstrated kernel capacity bound or a runtime performance result.
Full commands, resources, generated build inputs and failed logs remain at
`/workspaces/kprog-raw/perf/20261114-scale-stock`; the single build is
`/var/tmp/kprog-tmp/perf/scale`. Raw build inputs stay until the batch releases
them; original result/measurement logs are never deleted.
