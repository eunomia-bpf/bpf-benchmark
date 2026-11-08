# Proof compiler storage comparison for the same complete native Tetragon function

The exact original event_execve native P75318ea5 and its map metadata stay unchanged. This comparison compiles the canonical d963 C model and the private alias/LEA representation with clang18 -O2. Earlier -O3 extents are1280 and1264 respectively. This is proof-program compilation storage work for the existing stock-verifier stack frontier. Native compiler flags and native runtime performance remain unchanged; this is not the post-six-app native optimization schedule.

Actual terminal results: [{"exit": 0, "name": "baseline", "sections": [{"instructions": 17118, "maximum_fp_minus_offset": 1280, "name": "tracepoint/trusted/trusted"}], "wall_seconds": 389.98560406873}, {"exit": 0, "name": "alias", "sections": [{"instructions": 17122, "maximum_fp_minus_offset": 1264, "name": "tracepoint/trusted/trusted"}], "wall_seconds": 378.1760353478603}].

All source, exact header dependencies, commands and compiler objects/logs are retained. Compiler output is not stock-verifier acceptance or whole application completion. No production source adoption, runtime check, limit or per-program proof was added.
