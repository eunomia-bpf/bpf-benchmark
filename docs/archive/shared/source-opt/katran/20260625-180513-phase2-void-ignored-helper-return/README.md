# katran phase2 diagnostic: void-ignored-helper-return

Status: diagnostic-rejected

## Hypothesis

Stack phase2 attempt 3, then change two always-inlined helpers whose return
values are ignored by the caller from non-void return types to `void`.

## Decision

Do not run a formal benchmark. The generated `xdp` section stayed identical in
size to phase2 attempt 3 (`0x47b8`, 2221 displayed instruction lines). This
source cleanup does not appear to change emitted hot-path bytecode, so a formal
run would only measure noise.

This diagnostic is not counted as a phase2 source optimization attempt.
