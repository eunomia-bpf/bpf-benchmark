2026-11-16T03:40:59Z

Checked-sim-c now records B generation failures and actual stock-verifier failures, then loads the original P through the existing registered whole-image transport with a minimal BPF stub. The service reports `execution_path=direct-native` and B generation/stock status. This is unverified native execution. Accepted B retains the existing verification-before-compilation checked path. Native errors and binding/transport errors still fail the request. There is no new user option or benchmark change.

The loader gives stock-verification failure its own exception/CLI exit2. A generic exit1 does not trigger continuation. Service archives preserve generation tracebacks or verifier stderr and the original request.

Actual sole-kernel tests pass: rejected B executes P returning2; a B generation failure executes P returning2; accepted B follows checked compilation and returns2. Missing B-file and missing native-entry cases both propagate application errors. Archive assertions verify that an unrelated B-file error never attempts direct loading, while a direct native failure remains a failure. Existing host planner/wire cases and9 service tests pass. First guest attempt lacked the client's canonical linker environment and is retained; kernel2 passes four cases and final kernel3 passes all five.

Tests reuse the existing recovery regression binary to embed the production bridge and loader. The canonical base/image was not rebuilt during the timing round. Guest16-19/imageSH/4GiB, hard12GiBAS; host build8-11/hard8GiB. Raw `/workspaces/kprog-raw/perf/20261116-native-first`. Source is pushed; image publication waits for the running round's image lease. Six-app checked functional acceptance and complete B verification remain open.
