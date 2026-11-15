# Context-body normal compiler replay

2026-11-15. Archived census body 70/request 16 was replayed from its unchanged
generated C through the current single B pipeline. Standalone bounds compiler
SHA256: `5236d0ea94daf23da9e89a98d00bcb8f6c18c389388f1bf76da4d2592e5987b0`.

The initial attempt ended after successful preprocessing because the replay
script called nonexistent `Popen.check_returncode()`. Commit a5bd3dce3 fixes
error propagation; that attempt is not a compiler rejection. The next attempt
finished compilation at 03:26:49 UTC, exit zero, 2055.53 seconds, CPU 19,
24 GiB address-space cap. Both command streams and results are included.

This confirms B compilation only. No stock verifier acceptance, checked-native
installation, execution or performance gain is inferred. The canonical replay
product remains `/var/tmp/kprog-tmp/perf/context-body-replay/trusted_x86.bpf.o`;
native source input SHA256 is
`489a7a69184baae011350d4c7632faf0f5539d9df8417aa2892246cc49be777f`.
Original request archive and new logs stay under `/workspaces/kprog-raw/perf`.
