Current six-app host link replay, 2026-11-16

The next publication needs current-P proof extraction and kernel emission from
the six apps' last captured load facts. The old replay entry was removed by
cleanup; experiments live here rather than recreating a shared test target.

Fresh Tracee capture is needed: all six retained Tracee kernel plans in the
08:xx inventory predate kernel_layout. Missing layout or boot addresses will
not be guessed. The completed C runs demonstrate application loading but do
not retain the loader's temporary native-link cache in their result bundle.

`make -f kprog/results/host-link-replay-20261116/Makefile capture-tracee`
reuses the committed shared-link capture adapter and profile workflow. The
adapter delegates every proof/kernel invocation to the existing image linker
and archives actual input proof, plan, blob, relocations, map patches and ABI.
There is no code substitution. Captures are under the existing corpus result
mount at corpus/results/shared-hash-regression-20261116/captures; commands,
workload logs, counters and live JIT bytes stay under the raw root above.

This is a functional load-fact capture with the existing diagnostic contract:
image 6641a7e1, four vCPUs/32 GiB on 20-23, image SH, one 60-second sample per
arm, cycles:G at 199 Hz. It is not official default timing. C's frozen round
on 0-7 continues. The controller uses a 48 GiB address-space cap. No image,
base, source tool, kernel or benchmark setting is changed. Raw data stays.

Current tools for later replay are the existing release native-link and
vendor/build/native-bpf/x86/stage/kprog-perf-context-lto. The latter is the
P-stage compiler, not a verified-compiler binary or the retired /var/tmp tool.
Entry proof extraction follows native_loader_entry_data.hpp:33-43, without
the old host-only --preserve-entry-abi argument. Missing runtime function,
immutable-data or map-template facts remain explicit coverage limits.

`dry-run` lists the 475 retained candidate entries and tools. `proofs` extracts
all current-P entries with two workers, including the eleven recorded OTel
PERF_EVENT conversions with the current P-stage compiler. It uses the runtime
entry ABI contract. Every command, output and failure is retained separately.
No guest/image/base rebuild is part of that target. Its controller inherits a
16 GiB address-space cap and runs on 16,19. Runtime immutable/map-template and
generated-function facts are not supplied when absent from the retained input;
those limits remain distinct from entry extraction and later kernel emission.
