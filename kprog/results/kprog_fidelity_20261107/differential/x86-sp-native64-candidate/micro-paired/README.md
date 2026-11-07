# Paired unchanged micro inputs

Both phases use the same 29 native proof objects (SHA256 per input in build.json).
58/58 compile. Baseline f734 entry replay and private SP-v2e each admit28/29;
`cilium_socket_lb_service_select` fails in BOTH with `R0 invalid mem access scalar`
after identical null-store BPF instructions142..143. Exit0 means regression parity,
not29 admitted programs. Complete logs and frozen loader/proofs/headers retained.
This v2e parity result does not certify later SP-v3 changes or all applications.
