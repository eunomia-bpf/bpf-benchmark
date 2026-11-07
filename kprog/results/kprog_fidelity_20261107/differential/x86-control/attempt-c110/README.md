# Preserved first canonical failure

All 35 finite observers ran 1024 real CPU/C cases each: 35,840 states,
zero differences. The original c110 canonical executable completed observer0
then rejected observer1 JMP RAX (`ff e0`):
`reference: expected two-byte native opcode`.
This is an unavailable reference encoding, not an observed CPU/C mismatch
or verifier rejection. Exact request/states, logs, source closure and native
binary are retained here; the 65,085,464-byte full CPU trace stays locally.
No form is removed from the repaired replay.
