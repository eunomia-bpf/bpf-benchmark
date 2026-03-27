# Map Inline Debug Status (2026-03-27)

## Changes Made This Session

### 1. map_inline emit + const_prop fixed point fix (commit c8b18f3)
- MOV64_IMM for 32-bit constants (saves 1 slot/site)
- const_prop+dce iterate to fixed point (max 5 rounds)
- 503 daemon tests pass

### 2. Daemon simplification: remove security passes from default pipeline
- daemon/src/passes/mod.rs: is_default_pass() now excludes live_patch, dangerous_helper_firewall, speculation_barrier
- Default pipeline is performance-only
- 498 daemon tests pass (4 removed: pgo-related)

### 3. Remove --pgo from daemon CLI and startup
- daemon/src/main.rs: removed --pgo CLI flag and PgoConfig (-71 lines)
- daemon/src/commands.rs: removed pgo_config parameter from try_apply_one() and callers
- daemon/src/server.rs: removed pgo from serve/watch (-164 lines net)
- corpus/modes.py: removed --pgo from start_daemon_server()
- Net deletion: ~335 lines

### 4. Remove --passes from C++ runner and daemon socket
- runner/src/kernel_runner.cpp: removed passes from build_daemon_optimize_request()
- runner/src/common.cpp: removed --passes CLI option
- runner/include/micro_exec.hpp: removed passes field
- daemon/src/server.rs: removed parse_request_pass_names()/resolve_request_pass_names()

### 5. Corpus build report fix
- corpus/modes.py: load_corpus_build_report() now calls supplement_with_existing_corpus_build_objects() to include prebuilt .bpf.o files (568 vs 429 objects)

### 6. E2E performance passes wiring
- runner/libs/rejit.py: added benchmark_performance_passes() + pass_names parameter to apply_daemon_rejit()
- All 6 e2e/cases/*/case.py: now pass performance passes via benchmark_performance_passes()

## Key Findings

### map_inline 0 hits in corpus — Root Cause Analysis
1. **find_map_lookup_sites() works**: katran fixture debug test shows 2 lookup sites found correctly
2. **Pattern matcher works**: imm=1 (BPF_FUNC_map_lookup_elem) correctly detected
3. **bpf_map_lookup_elem_by_id() exists**: daemon CAN read live map values from kernel in serve mode
4. **Previous corpus runs had security pass pollution**: live_patch was running despite not being requested, because:
   - daemon serve watch loop used default full pipeline (all passes)
   - per-request passes from C++ runner were correctly sent but watch loop pre-empted
5. **After simplification**: default pipeline is now performance-only, so this issue is resolved
6. **Zero-value inlining is valid**: even with empty maps (value=0), eliminating bpf_map_lookup_elem helper call is a real optimization

### Blocking Issues
1. **Runner spdlog git clone failure**: transient network issue prevents make runner from rebuilding. Fix: rm -rf runner/build/_deps/spdlog-subbuild and retry
2. **vm-corpus not yet run with simplified daemon**: need to verify map_inline actually fires in serve mode
3. **exec_ns measurement limitation**: ktime_get_ns resolution (~4-18ns) masks small improvements; programs that run in <20ns cannot show measurable speedup

## Next Steps
1. Fix runner build (spdlog fetch), rebuild, run vm-corpus REPEAT=50
2. Analyze results: does map_inline fire in serve mode?
3. If map_inline fires: run vm-e2e with performance-only daemon
4. If map_inline doesn't fire: add daemon --debug logging to vm-corpus guest script and capture skip reasons
5. Commit all simplification changes
6. Update plan doc with new task entries
