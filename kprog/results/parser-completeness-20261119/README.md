# Native parser completeness regression

PERF 2026-11-19T13:44:32Z: Real host objects validate the coordinator's fixes
10c42d6cf and185091051. An object containing0x06 fails generation at0x1
with the actual objdump `(bad)` line. A second object containing16 zero
bytes parses all18 text bytes after objdump-z. Both cases pass, Make0.

The fixture was queued before these fixes; it executed after both landed.
It is confirmation of the repaired parser, not an executed pre-fix failure.
No parser source was changed by PERF, no guest or invalid instruction was
executed, and the byte-count assertion is a fixture test only. No runtime
coverage or MC-comparison gate was added. Existing generation failure
selection of direct native stays with the service. See result.json and
receipt.json for actual addresses, instructions, source snapshot and raw.
