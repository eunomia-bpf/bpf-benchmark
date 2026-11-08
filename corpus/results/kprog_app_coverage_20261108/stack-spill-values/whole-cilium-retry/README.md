# Whole Cilium with private stack spill representation

WholeCilium baseline72, generated2, compiled2, installed1, failures1; nativehashjoins2/2.

| Native entry | Generated | Compiled | Status | Verifier observation |
| --- | ---: | ---: | ---: | --- |
| cil_xdp_entry | 1 | 1 | 0 |  |
| tail_handle_ipv4_from_netdev | 1 | 1 | -5 | R0 invalid mem access 'scalar'; processed 2276 insns (limit 1000000) max_states_per_insn 1 total_states 69 peak_states 69 mark_read 0 |

The complete original upstream application uses the existing c-data-end runtime image, native inputs and workload. The frozen generic model retains raw native bytes plus the separate stack pointer representation. Pure metadata offsets preserve architectural memory accesses and their existing opacity barriers. The captured complete policy body compiles to a376-byte frame; actual whole-application outcomes above retain their own input and service domains. Production header adoption has not occurred. Raw counters and errors remain in work.json and the complete request/result archives.
