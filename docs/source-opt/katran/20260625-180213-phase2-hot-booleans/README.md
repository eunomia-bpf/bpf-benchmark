# katran phase2 diagnostic: hot-booleans

Status: diagnostic-rejected

## Hypothesis

Stack phase2 attempt 3, then cache packet-local booleans such as `is_udp`,
`is_tcp`, `is_syn`, `is_rst`, and `lru_enabled` so the XDP hot path avoids
repeated packet/vip field tests.

## Decision

Do not run a formal benchmark. The candidate increased the `xdp` section size
to `0x48c8`, larger than both clean source (`0x4870`) and the current phase2
best attempt 3 (`0x47b8`). The optimization likely caused extra register/stack
pressure instead of simplifying the JIT hot path.

This diagnostic is not counted as a phase2 source optimization attempt.
