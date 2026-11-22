# Actual ARM64 conditional-select path helper

`Arm64SelectPath.lean` proves the exported `Arm64Numeric.f_kprog_arm64_csel_path` itself in 26 real Clight steps. It covers all eight supported codes (28, 29, 30, 52, 61, 62, 68, 69), every 64-bit width, arbitrary global environment, memory and continuation. Only plain CSEL (28) at width 8 returns one; all other covered inputs return zero. The full memory is preserved and the continuation is `CC.callCont k`. Unsupported source behavior is outside this normal-return theorem.

The public internal run also closes all Kstop relational behaviors: every finite run is a silent prefix reaching that return, stuck endpoints agree, and infinite executions are excluded. This is the actual pointer/tag-path policy helper, not a whole CSEL handler or ISA refinement result.

The focused 42-job build and three public type/axiom queries passed at the unchanged 200000-heartbeat/512-depth limits on CPU 17, one worker, 32 GiB. Computation uses kernel-checked reduction, not a native oracle. `executes` uses only logical axioms; relational certificates inherit the existing CompCert external/assembly assumptions. See `validation.json` for exact hashes, commands, timings and every retained attempt. The first step-count draft omitted a real break across Kseq; the checked certificate counts 26. No runtime, loader, benchmark or performance-path edit was made.

Next: compose the actual source helper call and return with condition site35, preserve its selected source raw/tag pair (including the STACK-tag source), then actual writer/native/seventh-call correspondence. M5/O1/O2/O4 and M6 remain open; complete ISA families stay zero.
