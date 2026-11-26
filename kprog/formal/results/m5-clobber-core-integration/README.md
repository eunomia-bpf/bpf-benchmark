# Shared real saved-environment state in actual helper source executions

Original release, tag, GPR, flag and vector source stages now use the common Saved projection: actual Env, memory, live Cur Freeable ranges and same initialized flag. Each genuine effect and cache outcome transports this state directly. Actual memcpy caller metadata stays in its saved Kcall/temp map; its original full program call, all150 helper providers and176 stores, eight local frees and caller return remain checked. The source-equal memset local allocation can use the same genuine helper stages while retaining its own handler and temps.

Focused build 468 and 7 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
