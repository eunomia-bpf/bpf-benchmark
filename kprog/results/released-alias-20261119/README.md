# Released private-stack address forms

PERF 2026-11-19T10:04:14Z. P-x86-released-alias follows the LOCK fix. The
coordinator's freeze/LOCK BCC batch remains intact; this experiment changes
results files only and runs under timing SH on CPU 19 with a 4 GiB limit.

The real shared C compares RSP, fixed tagged-stack aliases and indexed
tagged-stack aliases reaching arena byte 40, at widths 1/2/4/8. Both live
and released storage are exercised through READ_MEM_VALUE and MOV_LOAD.
The input provider returns one explicit distinct value and counts visits.
The test records all 48 observations before requiring equal values and
input visits for each equal-address group. A failing assertion is expected
from the current fixed-load discrepancy. It supplies no stock, app, runtime
or hardware proof and adds no benchmark gate. Raw failures remain retained.

Source: x86_sim_local_bpf.h:1460 selects KPROG_X86_MEM_LOAD_FIXED when no
index is present, bypassing NATIVE_DATA_LOAD_TAGGED_INTO's released-byte
observation at lines 975–983. MOV_LOAD has the same shape at 1632–1638.
RSP uses STACK_READ and the indexed alias enters the tagged read. The prior
LOCK regression preserved those existing contracts. No request-time header,
generator, compiler, service, loader or formal export is edited here.
