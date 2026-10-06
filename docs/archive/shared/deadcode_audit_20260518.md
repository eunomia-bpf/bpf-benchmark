# Dead-code and Over-complexity Audit, 2026-05-18

Scope: static/read-only audit of the BPF benchmark repository, with `CLAUDE.md` / `AGENTS.md` rules treated as policy. I did not run build or test commands because this task allowed no writes except this report, and Rust/C++ build checks would create or update build artifacts.

Primary scans used:

```sh
rg -n "live_rejit_programs|LifecycleAbort|before_rejit|_EXCLUDED|skip_rejit|skipped|fallback|warning|continue|\\.ok\\(|unwrap_or|let _ =|summary|geometric_mean|bootstrap_geometric_mean_ci|win_counts|comparison_summary|summarize_phase_timings|summarize_named_counters|derive_perf_metrics" runner/libs runner/suites corpus micro -S --glob '!**/results/**' --glob '!**/.venv/**'
rg -n "#\\[allow\\(dead_code\\)\\]|let _ =|\\.ok\\(|unwrap_or_default|warning|fallback|legacy" bpfopt daemon ebpf-vm runner/src module -S --glob '!**/target/**' --glob '!**/build/**'
rg -n "branch_count|branch_misses|taken_count|not_taken_count|branch_miss_rate" bpfopt/crates/bpfopt/src -S
rg -n "fn x86_mov_reg_payload|mov_reg_payload|BPFOPT_TIME|print_and_reset_timing|live_rejit_programs|SKIP_REJIT" -S
rg -n "bpf_arm64_ldp_x|bpf_arm64_stp_x|ldp_x|stp_x" module bpfopt runner micro corpus ebpf-vm -S --glob '!**/build/**' --glob '!**/target/**' --glob '!**/results/**'
rg -n "if \\(emit && !image\\)" module/arm64 -S
```

## Summary

| file:line | severity | reason | recommendation |
|---|---:|---|---|
| `bpfopt/loader/src/main.rs:2` | Critical | Workspace contains a custom libbpf/bpftool loader binary; policy says app-level loader only and no replacement loader path. | Remove from default workspace/build or move to clearly non-production archive/test fixture. |
| `ebpf-vm/x86/native_lab/native_link/src/main.rs:1090` | Critical | `#[allow(dead_code)]` legacy relocation collector is explicitly kept only to silence dead-code warning. | Delete `collect_elf_relocations` and the associated silencing constants. |
| `runner/libs/app_runners/base.py:35` | High | Forbidden `live_rejit_programs()` hook still exists and can filter ReJIT programs. | Delete hook and all compatibility `hasattr` call sites. |
| `corpus/driver.py:136` | High | `SKIP_REJIT` creates a benchmark path that bypasses ReJIT and writes synthetic skipped results. | Remove from corpus driver; keep any local smoke mode outside result-writing framework. |
| `daemon/src/commands.rs:396` | High | Empty pass list returns an ok skipped result instead of failing the request. | Treat empty steps as invalid input and surface an error. |
| `daemon/src/commands.rs:705` | High | Per-pass bpfopt failure records an error and continues with the previous bytecode. | Stop the per-program pass loop after first transform failure. |
| `daemon/src/commands.rs:801` | High | ReJIT failure records an error and continues to later passes. | Stop the per-program pass loop after first ReJIT failure. |
| `runner/libs/rejit.py:356` | High | Shim path mirrors daemon "continue after failure" behavior. | Remove continuing fallback; one failed pass should end that program's pass chain. |
| `ebpf-vm/x86/native_lab/native_link/src/main.rs:109` | High | Native linker has a documented legacy fallback when `--lookup-site` is absent. | Require explicit lookup-site data whenever helper/map lookups are present. |
| `runner/src/native_lab_runner.cpp:325` | High | Native lab runner discovers tools through env, system path, and host repo fallbacks. | Require one configured binary path in benchmark mode; remove host-path probing. |
| `runner/src/native_lab_runner.cpp:83` | High | Native lab runner ignores mount and BPF info/JIT read failures. | Propagate errors; do not use `(void)` / `continue` for fallible kernel operations. |
| `ebpf-vm/test-others/native_lab_attach.cpp:708` | High | POC intentionally calls an attach path that fails, ignores the return, then duplicates load-only logic. | Split load-only and attach functions; delete the deliberate failed call. |
| `ebpf-vm/test-others/runner.cpp:237` | High | POC computes overhead ratios inside runner code. | Move derived metrics to an analysis script or keep this out of benchmark framework. |
| `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:48` | High | `branch_flip` is registered but real per-site PMU input has no CLI ingestion path. | Add strict profile input parser or remove pass from production registry until integrated. |
| `bpfopt/crates/bpfopt/src/insn.rs:7` | Medium | `bpfopt` re-wraps `libbpf_sys` constants and `struct bpf_insn`. | Replace aliases/wrapper type with direct `libbpf_sys` use plus minimal helpers. |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:17` | Medium | Timing atomics are updated/re-exported but have no caller reading or printing them. | Delete timing counters and updates, or add an explicit CLI feature. |
| `bpfopt/crates/bpfopt/src/verifier_log.rs:166` | Medium | Verifier log parser warns and continues on parse failures that may feed optimization facts. | Return errors for parse failures on state lines used by passes. |
| `bpfopt/crates/bpfopt/src/passes/rotate.rs:174` | Medium | Move-register payload builders are duplicated across passes. | Move shared payload helper into a pass-common module. |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:369` | Medium | `map_inline` has duplicated alias/stack scan logic across long helper functions. | Extract a single lookup-alias tracker or reuse existing CFG facts. |
| `module/arm64/Makefile:16` | Medium | `bpf_arm64_ldp` is built but no bpfopt pass consumes its kfuncs. | Remove from default build or implement a real pass using it. |
| `module/x86/Makefile:15` | Medium | Several x86 micro-only kinsn modules are default-built though no bpfopt pass uses them. | Split micro-only support from bpfopt/evaluation module set. |
| `module/arm64/bpf_arm64_mov.c:59` | Medium | Arm64 kinsn modules repeat the same `emit && !image` boilerplate at 15 sites. | Add one common arm64 emit helper. |
| `runner/libs/rejit_plan.py:63` | Medium | `programs.default` fallback hides missing program-specific pass policy. | Require explicit program policy or fail with a config error. |
| `micro/programs/converter/native_asm_to_handcraft.py:4` | Medium | Converter advertises warning-and-continue behavior and is not production-ready. | Archive outside production path or make unsupported translations fatal. |
| `ebpf-vm/test-others/native_lab_attach.cpp:22` | Medium | POC intentionally copies native_lab runner helper bodies. | Factor shared helper code or keep POC as out-of-tree archive. |

## kinsn

### Finding K1: arm64 LDP/STP module is built but has no pass consumer

Path: `module/arm64/Makefile:16`, `module/arm64/bpf_arm64_ldp.c:9`.

Current code:

```make
obj-m += bpf_arm64_ldp.o
```

```c
__bpf_kfunc void bpf_arm64_ldp_x(...);
__bpf_kfunc void bpf_arm64_stp_x(...);
```

Why this is dead/redundant:

`bpf_arm64_ldp` contributes kfuncs and a module object to the default arm64 build, but the active bpfopt pass registry does not contain an LDP/STP pass. The policy explicitly says every function/module/constant should have a real caller and calls out that `bpf_ldp` currently has no consuming pass. Building and loading it by default increases kernel-module surface without an evaluation path.

Caller / grep evidence:

```text
rg -n "bpf_arm64_ldp_x|bpf_arm64_stp_x|ldp_x|stp_x" module bpfopt runner micro corpus ebpf-vm ...
module/arm64/bpf_arm64_ldp.c:9:__bpf_kfunc void bpf_arm64_ldp_x(...)
module/arm64/bpf_arm64_ldp.c:10:__bpf_kfunc void bpf_arm64_stp_x(...)
module/arm64/bpf_arm64_ldp.c:191:... bpf_arm64_ldp_x ...
module/arm64/bpf_arm64_ldp.c:205:... bpf_arm64_stp_x ...
```

No `bpfopt/crates/bpfopt/src/passes/*::KINSN_TARGETS` entry references those symbols.

Recommendation:

Remove `bpf_arm64_ldp.o` from the default module build until a real pass consumes it, or implement the pass and wire it into benchmark policy. If kept only as future work, keep it out of the default evaluation image.

Estimated removable LOC: about 213 LOC if the whole module is removed from production build.

### Finding K2: x86 micro-only modules are default-built with no bpfopt pass consumer

Path: `module/x86/Makefile:15`.

Current code:

```make
obj-m += bpf_x86_movbe.o
obj-m += bpf_x86_popcnt.o
obj-m += bpf_x86_bmi1.o
obj-m += bpf_x86_imul.o
obj-m += bpf_x86_not.o
obj-m += bpf_x86_shd.o
obj-m += bpf_x86_stack.o
```

Why this is dead/redundant:

These modules are real for micro/native handcraft paths, but they are not consumed by the bpfopt pass policy used by corpus evaluation. Keeping them in the default module set mixes "micro fixture support" with "production kinsn replacement pass support" and makes the default image larger than the active optimization surface.

Caller / grep evidence:

```text
rg -n "bpf_x86_(movbe|popcnt|bmi1|imul|not|stack)|KINSN_TARGETS" module/x86 bpfopt/crates/bpfopt/src/passes micro ...
```

The kfuncs appear in module files and micro handcraft/converter material. The pass registry targets do not include `movbe`, `popcnt`, `bmi1`, `imul`, `not`, or `stack`; `shd` has module/micro coverage but not a dedicated bpfopt pass policy entry beyond unrelated shift/extract lowering.

Recommendation:

Split the x86 module build into two lists: bpfopt/corpus pass modules and micro/native-lab-only modules. Load the micro-only set only from `make micro` or the explicit micro image layer.

Estimated removable LOC from production image: high module surface, but code should not be deleted if micro still depends on it.

### Finding K3: repeated arm64 emit boilerplate across modules

Path: `module/arm64/bpf_arm64_mov.c:59` and 14 similar sites.

Current code:

```c
if (emit && !image)
	return -EINVAL;
if (emit)
	*(u32 *)image = cpu_to_le32(insn);
idx++;
```

Why this is over-complex:

The same three-state emit/count pattern is hand-rolled in nearly every arm64 kinsn encoder. That produces repeated error handling and repeated endian stores, which are easy to drift. The abstraction would have multiple callers and would reduce real duplication.

Caller / grep evidence:

```text
rg -n "if \\(emit && !image\\)" module/arm64
module/arm64/bpf_arm64_mov.c:59
module/arm64/bpf_arm64_prfm.c:61
module/arm64/bpf_arm64_ubfm.c:75
module/arm64/bpf_arm64_csel.c:107
module/arm64/bpf_arm64_csel.c:136
module/arm64/bpf_arm64_ccmp.c:206
module/arm64/bpf_arm64_ccmp.c:235
module/arm64/bpf_arm64_ccmp.c:266
module/arm64/bpf_arm64_ldr.c:134
module/arm64/bpf_arm64_str.c:192
module/arm64/bpf_arm64_str.c:276
module/arm64/bpf_arm64_rev.c:86
module/arm64/bpf_arm64_extr.c:134
module/arm64/bpf_arm64_ldp.c:137
module/arm64/bpf_arm64_ldp.c:170
```

Recommendation:

Add a small common helper such as `kinsn_arm64_emit_one(image, &idx, emit, insn)` in an arm64 kinsn header. It should own the null-image check, `cpu_to_le32`, and index increment.

Estimated removable LOC: 80-120 LOC after replacing duplicated blocks.

### Finding K4: x86 ALU local REX helper overlaps common x86 emit helpers

Path: `module/x86/bpf_x86_alu.c:1001`, `module/include/kinsn_x86_emit.h:411`.

Current code:

```c
static int emit_rex8_mem(u8 **pprog, u8 reg, u8 index, u8 base)
```

Common helper already exists:

```c
static inline u8 *kinsn_emit_rex8_mem(u8 *prog, u8 dst_reg, u8 src_reg)
```

Why this is over-complex:

The local helper is not a pure duplicate because it handles an index/base form, but the naming makes it look like a second implementation of the same primitive. This is minor, but it is exactly the type of small wrapper drift that later creates nearly identical emit APIs.

Caller / grep evidence:

```text
rg -n "emit_rex8_mem|kinsn_emit_rex8_mem" module/x86 module/include
module/x86/bpf_x86_alu.c:1001:static int emit_rex8_mem(...)
module/include/kinsn_x86_emit.h:411:static inline u8 *kinsn_emit_rex8_mem(...)
```

Recommendation:

Either move the indexed/base variant into `kinsn_x86_emit.h` with a precise name, or rename the local helper to describe the addressing mode. This is a cleanup finding, not a deletion blocker.

Estimated removable LOC: small; value is consistency rather than LOC reduction.

## native_lab

### Finding N1: native linker carries an explicit dead legacy relocation collector

Path: `ebpf-vm/x86/native_lab/native_link/src/main.rs:1090`.

Current code:

```rust
/// Legacy: kept for cargo deadcode warning silence; superseded by
/// apply_elf_relocations. To be deleted in a follow-up.
#[allow(dead_code)]
fn collect_elf_relocations(...)
```

Related silencing:

```rust
const TRAMPOLINE_LEN: usize = 14;
let _ = TRAMPOLINE_LEN; // referenced by the design comment / future map path.
let _ = map_addrs; // silence unused warning until maps are wired in
```

Why this is dead/redundant:

This is a direct policy violation: `#[allow(dead_code)]`, a legacy function retained only to silence warnings, and `let _ =` silencing for future work. The current path uses `apply_elf_relocations`; the old collector has no real caller.

Caller / grep evidence:

```text
rg -n "collect_elf_relocations|TRAMPOLINE_LEN|let _ =|allow\\(dead_code\\)" ebpf-vm/x86/native_lab/native_link/src/main.rs
761:const TRAMPOLINE_LEN: usize = 14;
1086:let _ = TRAMPOLINE_LEN;
1090:#[allow(dead_code)]
1093:fn collect_elf_relocations(...)
1212:let _ = map_addrs;
```

No non-definition call to `collect_elf_relocations` appears in the file or repository scan.

Recommendation:

Delete `collect_elf_relocations`, delete the unused trampoline constant if the trampoline map path is gone, and make missing map wiring either a real error or a real implemented path. Do not retain "future map path" code in the production linker.

Estimated removable LOC: about 120-130 LOC.

### Finding N2: native linker has a legacy helper-pool fallback

Path: `ebpf-vm/x86/native_lab/native_link/src/main.rs:109`.

Current code:

```rust
/// If no --lookup-site flags are provided, the legacy behavior is used:
/// bpf_map_lookup_elem calls are redirected through the shared helper pool.
```

Implementation:

```rust
dedicated_pool_addr
    .or_else(|| map_addrs.get(&helper).copied())
```

Why this is redundant/risky:

The native-lab path is supposed to be explicit about map lookup sites and helper redirection. A fallback to a shared helper pool means missing per-site metadata does not fail; it silently downgrades to legacy behavior. That conflicts with fail-fast policy and makes measurement sensitive to whether callers remembered to pass `--lookup-site`.

Caller / grep evidence:

```text
rg -n "lookup-site|legacy behavior|dedicated_pool_addr|map_addrs.get" ebpf-vm/x86/native_lab/native_link/src/main.rs
109:If no --lookup-site flags are provided, the legacy behavior is used
918:let target = dedicated_pool_addr
925:.or_else(|| map_addrs.get(&helper).copied())
```

Recommendation:

When helper/map lookup sites are present, require `--lookup-site` metadata for every site. Exit with a specific error if metadata is missing. If a developer-only legacy mode is still needed, put it behind a different binary or explicit non-benchmark flag.

Estimated removable LOC: modest, but removes a high-risk fallback.

### Finding N3: native lab runner resolves linker binary through multiple fallback paths

Path: `runner/src/native_lab_runner.cpp:325`.

Current code:

```cpp
if (!opts.native_link.empty()) ...
if (const char *env = std::getenv("NATIVE_LINK")) ...
const std::vector<std::string> candidates = {
    "/usr/local/bin/native_link",
    ".../target/release/native_link",
};
```

Why this is over-complex/risky:

Benchmark execution should be reproducible from image layers and make targets. The runner can choose an env var, a system install, or a host repo build path. That is a classic "works on my machine" fallback chain and can silently change which linker was used for a paper run.

Caller / grep evidence:

```text
rg -n "native_link_binary|NATIVE_LINK|target/release/native_link" runner/src/native_lab_runner.cpp
325:static std::string native_link_binary(...)
333:if (const char *env = std::getenv("NATIVE_LINK"))
340:/usr/local/bin/native_link
344:target/release/native_link
```

Recommendation:

Require a single configured linker path in benchmark mode, preferably from the runtime image contract. If the binary is absent, exit 1 with the path that was expected. Remove host repo probing.

Estimated removable LOC: 20-30 LOC.

### Finding N4: native lab runner keeps deprecated direct native object mode

Path: `runner/src/native_lab_runner.cpp:500`, `runner/src/native_lab_runner.cpp:542`, `runner/src/native_lab_runner.cpp:889`.

Current code:

```cpp
// Legacy direct .native.o/.native.so invocation is deprecated.
```

```cpp
if (ends_with(opts.input_obj, ".native.o") || ends_with(opts.input_obj, ".native.so")) {
    return NativeLabPaths{opts.input_obj, opts.input_obj};
}
```

```cpp
// Symbol precedence includes legacy --native-lab-symbol.
```

Why this is redundant:

The runner supports a canonical `.bpf.o + --program-name` pipeline and a deprecated direct native object mode. The legacy mode adds path-resolution branches and symbol precedence rules. Policy says no backwards-compatibility shims.

Caller / grep evidence:

```text
rg -n "Legacy direct|native-lab-symbol|resolve_native_lab_paths|\\.native\\.o|\\.native\\.so" runner/src/native_lab_runner.cpp
500:Legacy direct .native.o/.native.so invocation is deprecated
542:if (ends_with(opts.input_obj, ".native.o") ...
889:legacy --native-lab-symbol
```

Recommendation:

Delete the legacy direct native-object mode and legacy symbol flag. Require `.bpf.o` plus explicit program identity.

Estimated removable LOC: 50-80 LOC including path and symbol fallback branches.

### Finding N5: native lab runner silences kernel/debugfs and BPF info failures

Path: `runner/src/native_lab_runner.cpp:83`, `runner/src/native_lab_runner.cpp:595`.

Current code:

```cpp
(void)mount("none", kDebugfsDir, "debugfs", 0, nullptr);
```

```cpp
if (bpf_obj_get_info_by_fd(map_fd, &info, &len) < 0)
    continue;
```

More instances:

```text
runner/src/native_lab_runner.cpp:603
runner/src/native_lab_runner.cpp:617
runner/src/native_lab_runner.cpp:623
runner/src/native_lab_runner.cpp:703
runner/src/native_lab_runner.cpp:709
```

Why this is dead/redundant/risky:

The runner is measuring native BPF attachment and map/helper relocation. If a debugfs mount, BPF info read, or JIT image fetch fails, continuing with fewer maps or fewer candidates creates partial state. This violates the fail-fast rule and makes measurement opaque.

Caller / grep evidence:

```text
rg -n "\\(void\\)mount|bpf_obj_get_info_by_fd\\(.*< 0\\)|jited_prog_len == 0|continue" runner/src/native_lab_runner.cpp
83:(void)mount(...)
595:if (bpf_obj_get_info_by_fd(...) < 0) continue
603:if (...) continue
617:if (...) continue
623:if (...) continue
703:if (...) continue
709:if (...) continue
```

Recommendation:

Propagate these failures as fatal errors with enough context: fd, expected program/map name, and syscall errno. Only tolerate debugfs mount failure if a subsequent `access(kDebugfsTracing, ...)` proves the needed path exists.

Estimated removable LOC: small, but correctness impact is high.

### Finding N6: native lab runner has retained "future use" xlated path

Path: `runner/src/native_lab_runner.cpp:605`.

Current code:

```cpp
(void)xlated_cnt;
(void)xlated; /* xlated path retained for future use */
```

Why this is dead/redundant:

This is future-work retention by explicit unused-variable silencing. The policy says no dead code and no `let _`/equivalent silencing for fallible work or unused paths. If xlated bytecode is needed, the code should use it now; otherwise delete the allocation/read path.

Caller / grep evidence:

```text
rg -n "xlated_cnt|xlated path retained|\\(void\\)xlated" runner/src/native_lab_runner.cpp
605:(void)xlated_cnt;
605:(void)xlated; /* xlated path retained for future use */
```

Recommendation:

Delete the xlated read path from native-lab runner until a real caller needs it. If the map extraction should use xlated instructions, wire it fully and make failures fatal.

Estimated removable LOC: 10-30 LOC depending on the surrounding allocation path.

### Finding N7: native lab runner embeds large map/JIT analysis logic in measurement runner

Path: `runner/src/native_lab_runner.cpp:406`, `runner/src/native_lab_runner.cpp:458`, `runner/src/native_lab_runner.cpp:554`.

Current code:

```cpp
static std::optional<int64_t> extract_htab_inline_offset(...)
static std::vector<int> walk_lookup_call_maps(...)
static int load_bpf_companion(...)
```

Why this is over-complex:

The runner is 1014 LOC and mixes CLI parsing, libbpf object loading, map-address extraction, JIT disassembly heuristics, native-link invocation, kprobe/uprobe attachment, and measurement. Several helper bodies are duplicated in `ebpf-vm/test-others/native_lab_attach.cpp`. The abstraction boundary is unclear: the runner is both orchestrator and linker-side metadata extractor.

Caller / grep evidence:

```text
rg -n "extract_htab_inline_offset|walk_lookup_call_maps|load_bpf_companion" runner/src/native_lab_runner.cpp ebpf-vm/test-others/native_lab_attach.cpp
runner/src/native_lab_runner.cpp:406:extract_htab_inline_offset
runner/src/native_lab_runner.cpp:458:walk_lookup_call_maps
runner/src/native_lab_runner.cpp:554:load_bpf_companion
```

Recommendation:

Move companion-object analysis and map lookup site extraction into a small shared library or into the native linker side-input generator. Keep `native_lab_runner.cpp` as orchestration and measurement only.

Estimated removable LOC from runner: 150-250 LOC if factored, not deleted.

## bpfopt

### Finding B1: custom `bpfopt-loader` conflicts with app-level loader policy

Path: `bpfopt/loader/src/main.rs:2`, `bpfopt/Cargo.toml:1`.

Current code:

```rust
//! Host-side developer loader for the bpfopt CLI.
```

Workspace:

```toml
[workspace]
members = ["crates/bpfopt", "loader"]
```

Why this is dead/redundant/risky:

The loader is documented as "not a benchmark path", but it is still a first-class workspace member and has a custom path that libbpf-loads programs, shells out to `bpftool`, and re-verifies with `BPF_PROG_LOAD`. The project policy forbids framework-level `.bpf.o` loading and custom loader binaries replacing real upstream apps. Even as a developer helper, keeping it in the default workspace makes it too easy to build or use from evaluation scripts.

Caller / grep evidence:

```text
rg -n "loader|bpfopt-loader|BPF_PROG_LOAD|bpftool|not a benchmark path" bpfopt
bpfopt/Cargo.toml:members = ["crates/bpfopt", "loader"]
bpfopt/loader/README.md:3:not a benchmark path
bpfopt/loader/src/main.rs:2:Host-side developer loader
```

Additional fail-fast issue:

```text
bpfopt/loader/src/main.rs:138:let _ = fs::remove_dir_all(...)
bpfopt/loader/src/main.rs:301:let _ = fs::create_dir_all(...)
bpfopt/loader/src/main.rs:302:let _ = fs::write(...)
```

Recommendation:

Remove `loader` from the default workspace and CI/evaluation build. If the tool remains useful, archive it under a docs/dev-tools area with an explicit "not for benchmark" entrypoint, or convert it into tests that cannot be called as an app loader.

Estimated removable LOC: very high if deleted from production tree; `bpfopt/loader/src/main.rs` is the largest single delete candidate.

### Finding B2: `branch_flip` is registered but has no real PMU profile ingestion path

Path: `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:48`, `bpfopt/crates/bpfopt/src/passes/mod.rs:162`, `bpfopt/crates/bpfopt/src/main.rs:315`.

Current code:

```rust
let program_miss_rate = ctx
    .branch_miss_rate
    .ok_or_else(|| anyhow!("branch_flip requires program-level branch miss rate"))?;
```

Registry:

```rust
pass_entry!(BranchFlipPass, BranchFlipPass::NAME)
```

Context builder:

```rust
fn build_pass_context(args: &Cli) -> anyhow::Result<PassContext> { ... }
```

Why this is dead/redundant:

`branch_flip` requires per-site PGO data by policy. The pass itself correctly refuses missing `ctx.branch_miss_rate`, but there is no CLI parser that sets `branch_miss_rate` or loads per-site `branch_count`, `branch_misses`, `miss_rate`, `taken`, and `not_taken` for real programs. Tests can set context manually, but production CLI invocation cannot.

Caller / grep evidence:

```text
rg -n "branch_count|branch_misses|taken_count|not_taken_count|branch_miss_rate" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/passes/branch_flip.rs:48:ctx.branch_miss_rate
bpfopt/crates/bpfopt/src/passes/branch_flip.rs:129:branch_flip_profile
bpfopt/crates/bpfopt/src/pass.rs:70:pub branch_count
bpfopt/crates/bpfopt/src/pass.rs:71:pub branch_misses
```

No `main.rs` / CLI option sets `PassContext.branch_miss_rate` or imports per-site PMU data.

Recommendation:

Either add a strict `--profile <file>` parser that validates every candidate site has `branch_count`, `branch_misses`, `miss_rate`, `taken`, and `not_taken`, or remove `branch_flip` from the production registry until the profiling toolchain is wired. Missing profile data must exit 1, not skip candidates.

Estimated removable LOC: low if deregistered; higher if fully implemented.

### Finding B3: `branch_misses` field is stored but not validated by the pass

Path: `bpfopt/crates/bpfopt/src/pass.rs:70`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:508`.

Current code:

```rust
pub branch_count: u64,
pub branch_misses: u64,
pub taken_count: u64,
pub not_taken_count: u64,
pub miss_rate: f64,
```

Use site:

```rust
let branch_count = taken_count + not_taken_count;
let miss_rate = profile.miss_rate;
```

Why this is redundant/risky:

Policy says every candidate needs `branch_misses`, but runtime branch-flip decisions use `miss_rate`, `branch_count`, `taken_count`, and `not_taken_count`. The raw `branch_misses` field is not used to validate consistency, so a malformed profile could contain contradictory miss counts and miss rates.

Caller / grep evidence:

```text
rg -n "branch_misses" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/pass.rs:71:pub branch_misses
```

No non-test pass code reads `branch_misses` for validation or decision-making.

Recommendation:

When profile ingestion is added, validate `branch_misses <= branch_count` and that `miss_rate` is consistent with raw counts within a clear tolerance. If raw misses are not needed, do not keep the field as decorative metadata.

Estimated removable LOC: small; correctness issue is in missing validation.

### Finding B4: `insn.rs` wraps libbpf constants and `bpf_insn`

Path: `bpfopt/crates/bpfopt/src/insn.rs:7`, `bpfopt/crates/bpfopt/src/insn.rs:241`.

Current code:

```rust
pub const BPF_LD: u8 = libbpf_sys::BPF_LD as u8;
pub const BPF_LDX: u8 = libbpf_sys::BPF_LDX as u8;
...
#[repr(transparent)]
pub struct BpfInsn(libbpf_sys::bpf_insn);
```

Why this is over-wrapped:

The repository rule says helper/prog/insn types should use `libbpf-rs` / `libbpf-sys` directly and not re-wrap upstream constants or ABI structs. `BpfInsn` is more than a zero-value alias because it contains helpers, but the constant aliases and transparent wrapper still create a parallel ABI vocabulary.

Caller / grep evidence:

```text
rg -n "pub const BPF_|pub struct BpfInsn|libbpf_sys::bpf_insn" bpfopt/crates/bpfopt/src daemon/src
bpfopt/crates/bpfopt/src/insn.rs:7:pub const BPF_LD
bpfopt/crates/bpfopt/src/insn.rs:241:pub struct BpfInsn(libbpf_sys::bpf_insn)
daemon/src/bpf.rs:12:use libbpf_sys::bpf_insn
daemon/src/commands.rs:206:Vec<libbpf_sys::bpf_insn>
```

The daemon already uses raw `libbpf_sys::bpf_insn`, showing the direct style is feasible.

Recommendation:

Replace pure constant aliases with direct `libbpf_sys::*` use. Consider keeping only high-value constructors/serializers as free functions or an extension trait over `libbpf_sys::bpf_insn`, not a separate ABI wrapper type.

Estimated removable LOC: medium, but migration touches many pass files.

### Finding B5: unused timing atomics in `bbprogram` analysis

Path: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:17`, `bpfopt/crates/bpfopt/src/analysis/mod.rs:14`.

Current code:

```rust
static T_TRY_REPLACE_NS: AtomicU64 = AtomicU64::new(0);
static T_INSN_MUT_NS: AtomicU64 = AtomicU64::new(0);
...
pub fn print_and_reset_timing() { ... }
```

Why this is dead:

The atomics are updated in analysis paths and re-exported, but no active code calls `print_and_reset_timing`, no env var reads the counters, and no CLI flag exposes them. This is hidden instrumentation with no consumer.

Caller / grep evidence:

```text
rg -n "BPFOPT_TIME|print_and_reset_timing|T_TRY_REPLACE_NS|T_INSN_MUT_NS|T_BRANCH_REBUILD_NS" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:17:static T_TRY_REPLACE_NS
bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:29:pub fn print_and_reset_timing()
bpfopt/crates/bpfopt/src/analysis/mod.rs:14:pub use bbprogram::print_and_reset_timing
```

No caller appears outside the definition and re-export/update sites.

Recommendation:

Delete the counters, re-export, and update sites. If timing is needed, add an explicit developer CLI option that writes diagnostics outside benchmark result payloads.

Estimated removable LOC: 35-45 LOC.

### Finding B6: duplicate move-register payload helpers across passes

Path: `bpfopt/crates/bpfopt/src/passes/rotate.rs:174`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:269`.

Current code:

```rust
fn x86_mov_reg_payload(dst_reg: u8, src_reg: u8) -> u64 { ... }
```

```rust
fn mov_reg_payload(dst_reg: u8, src_reg: u8) -> u64 { ... }
fn arm64_mov_reg_payload(dst_reg: u8, src_reg: u8) -> u64 { ... }
fn x86_mov_reg_payload(dst_reg: u8, src_reg: u8) -> u64 { ... }
```

Why this is redundant:

Pass-common kinsn descriptor tables already exist in `passes/mod.rs`, but the payload construction for the same move operation is copied in individual passes. That creates needless per-pass drift for register packing.

Caller / grep evidence:

```text
rg -n "fn x86_mov_reg_payload|fn arm64_mov_reg_payload|fn mov_reg_payload" bpfopt/crates/bpfopt/src/passes
rotate.rs:174:fn x86_mov_reg_payload
cond_select.rs:269:fn mov_reg_payload
cond_select.rs:274:fn arm64_mov_reg_payload
cond_select.rs:279:fn x86_mov_reg_payload
```

Recommendation:

Move payload construction to a small pass-common helper next to existing kinsn target definitions. Keep pass-specific code focused on pattern matching and candidate emission.

Estimated removable LOC: 15-25 LOC.

### Finding B7: verifier log parser warns and continues on parse failures

Path: `bpfopt/crates/bpfopt/src/verifier_log.rs:166`, `bpfopt/crates/bpfopt/src/verifier_log.rs:517`.

Current code:

```rust
if let Err(err) = parse_reg_state(...) {
    warn_verifier_log(...);
}
```

```rust
warn_verifier_log(... unknown attr ...);
return None;
```

Why this is risky:

Verifier facts feed `map_inline` / `const_prop` decisions. A warning-and-continue parser can silently drop facts and leave later passes operating on partial state. The fail-fast rule specifically forbids warning-and-continue for parse errors.

Caller / grep evidence:

```text
rg -n "warn_verifier_log|\\.ok\\(\\)\\?|parse_reg_state" bpfopt/crates/bpfopt/src/verifier_log.rs
166:warn_verifier_log(...)
517:warn_verifier_log(...)
525:fn warn_verifier_log(...)
218:.ok()?
223:.ok()?
242:.ok()?
271:.ok()?
348:.ok()?
613:.ok()?
```

Some `.ok()?` uses are normal optional parsing, but state-line parse failures that would affect pass facts should be hard errors.

Recommendation:

Return `Err` with line context for malformed register/stack/map state lines used by optimizer passes. Only ignore truly unrelated verifier log lines.

Estimated removable LOC: neutral; improves failure behavior.

### Finding B8: `map_inline` duplicates alias/stack tracking logic inside a very large pass

Path: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:369`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2593`.

Current code:

```rust
fn find_map_in_map_chain_for_outer(...)
```

```rust
fn classify_r0_uses_with_options(...)
```

Why this is over-complex:

The file is about 3700 LOC and contains repeated local data-flow tracking: alias registers, alias stack slots, null checks, stack store/load scanning, and scan-site bookkeeping. The logic is pass-specific today, but it is repeated enough that one helper would reduce risk.

Caller / grep evidence:

```text
rg -n "find_map_in_map_chain_for_outer|classify_r0_uses_with_options|alias_regs|alias_stack_slots" bpfopt/crates/bpfopt/src/passes/map_inline.rs
369:find_map_in_map_chain_for_outer
2593:classify_r0_uses_with_options
```

Recommendation:

Extract a `LookupAliasTracker` or reuse existing `ProgramCFG` facts. The pass should describe policy decisions; the tracker should own register/stack alias propagation.

Estimated removable LOC: modest direct reduction, but large complexity reduction.

## daemon

### Finding D1: daemon accepts empty pass list and returns ok skipped result

Path: `daemon/src/commands.rs:396`, `daemon/src/commands.rs:436`.

Current code:

```rust
if steps.is_empty() {
    return Ok(skipped_program_result(prog_id));
}
```

```rust
fn skipped_program_result(prog_id: u32) -> OptimizeOneResult {
    OptimizeOneResult { status: "ok".to_string(), ... passes: Vec::new(), ... }
}
```

Why this is dead/redundant/risky:

An empty pass list is a runner policy error or a filtering decision. Returning ok with empty details creates a silent skip path. The top-level rules explicitly forbid skipping/excluding programs from ReJIT and forbid synthetic informational fields instead of errors.

Caller / grep evidence:

```text
rg -n "skipped_program_result|steps.is_empty|deliberately skipped" daemon/src/commands.rs
362:empty steps means the runner deliberately skipped this program
396:if steps.is_empty()
436:fn skipped_program_result
```

Caller chain:

```text
try_execute_plan -> execute_one -> skipped_program_result
```

Recommendation:

Make empty `steps` invalid input with a clear error. If the runner wants no-op behavior, it should send an explicit `noop` pass and still let ReJIT failures surface.

Estimated removable LOC: 15-25 LOC.

### Finding D2: daemon continues pass chain after bpfopt transform failure

Path: `daemon/src/commands.rs:675`, `daemon/src/commands.rs:705`.

Current code:

```rust
let transformed = match invoke_bpfopt_pass(...) {
    Ok(output) => output,
    Err(err) => {
        pass_errors.push(...);
        pass_details.push(...);
        continue;
    }
};
```

Why this is risky:

Continuing after a transform failure means later passes execute against the last successful bytecode, not the requested pass sequence. The result records an error, but still presents a partial pass chain. That is a fallback by another name.

Caller / grep evidence:

```text
rg -n "invoke_bpfopt_pass|pass_errors.push|continue;" daemon/src/commands.rs
675:invoke_bpfopt_pass
705:continue;
```

Recommendation:

After a pass transform failure, append the error detail and stop processing that program. The result should expose the raw failure without attempting later passes.

Estimated removable LOC: small; behavior change is important.

### Finding D3: daemon continues pass chain after ReJIT failure

Path: `daemon/src/commands.rs:790`, `daemon/src/commands.rs:801`.

Current code:

```rust
let rejit_result = match rejit_prog(...) {
    Ok(result) => result,
    Err(err) => {
        pass_errors.push(...);
        pass_details.push(...);
        continue;
    }
};
```

Why this is risky:

A failed `BPF_PROG_REJIT` means the candidate did not become the new program state. Continuing later passes against previous state makes the final result dependent on a hidden fallback. The framework should record the failure and stop the per-program chain.

Caller / grep evidence:

```text
rg -n "rejit_prog|BPF_PROG_REJIT|pass_errors.push|continue;" daemon/src/commands.rs
790:rejit_prog
801:continue;
```

Recommendation:

Stop per-program processing after the first ReJIT failure. Keep the failure in the raw pass details.

Estimated removable LOC: small; behavior change is important.

### Finding D4: top-level apply converts program failures into per-program error results

Path: `daemon/src/commands.rs:314`.

Current code:

```rust
fn apply_program_result(...) -> OptimizeOneResult {
    apply(...).unwrap_or_else(|err| OptimizeOneResult::error(...))
}
```

Why this is suspicious:

This is not as clear-cut as D2/D3 because result.json is supposed to record per-program errors. Still, `unwrap_or_else` converts a daemon-side exception into an ok top-level optimize response containing a program error object. That is a partial-success API. If the caller expects request-level failure on internal daemon bugs, this hides them.

Caller / grep evidence:

```text
rg -n "apply_program_result|unwrap_or_else|try_apply_programs_converts_failures_to_program_results" daemon/src/commands.rs
314:unwrap_or_else(...)
1576:try_apply_programs_converts_failures_to_program_results
```

Recommendation:

Keep this only if the protocol explicitly requires per-program raw error capture for normal ReJIT failures. For internal daemon errors, return request-level failure. At minimum, distinguish expected ReJIT errors from daemon invariant violations.

Estimated removable LOC: neutral; semantic cleanup.

### Finding D5: map snapshot skip marker is a size-based partial side-input path

Path: `daemon/src/commands.rs:62`, `daemon/src/commands.rs:984`.

Current code:

```rust
struct MapSnapshotSkipMarker { reason: String, max_entries: u32, value_size: u32 }
```

```rust
write_map_skip_marker(...)
```

Why this is suspicious:

If a pass requires exact map-value side inputs, a size-based skip marker is a partial-input fallback. It may be intended as raw metadata for bpfopt to reject later, but the current shape looks like "record limitation and continue", which conflicts with fail-fast rules if optimization can proceed without required data.

Caller / grep evidence:

```text
rg -n "MapSnapshotSkipMarker|write_map_skip_marker|skip marker|max_entries" daemon/src/commands.rs
62:struct MapSnapshotSkipMarker
984:write_map_skip_marker
1006:fn write_map_skip_marker
```

Recommendation:

For passes that require map side inputs, make oversize or undumpable maps a hard error unless bpfopt has a well-defined "no transform" response that is recorded as a failed/missing input, not a successful fallback.

Estimated removable LOC: low; policy clarification needed.

### Finding D6: syscall boundary mostly follows policy

Path: `daemon/src/syscall.rs:469`.

Current code:

```rust
libc::syscall(libc::SYS_bpf, BPF_PROG_REJIT, ...)
```

Why this is not a finding:

The scan found direct syscall use for the fork-only `BPF_PROG_REJIT` path, which is explicitly allowed by policy. Standard commands use `libbpf_sys`/`libbpf-rs` style APIs. This area did not show the same wrapper problem as `bpfopt/src/insn.rs`.

Recommendation:

No deletion recommended from this audit point.

## runner

### Finding R1: forbidden `live_rejit_programs()` hook still exists

Path: `runner/libs/app_runners/base.py:35`, `runner/libs/case_common.py:73`, `corpus/driver.py:260`.

Current code:

```python
def live_rejit_programs(self) -> list[dict[str, object]]:
    return [dict(program) for program in self.programs]
```

Compatibility use:

```python
if hasattr(runtime, "live_rejit_programs"):
    programs = program_records(runtime.live_rejit_programs())
```

Corpus use:

```python
expected_programs = normalize_programs(session.runner.live_rejit_programs())
```

Why this is dead/redundant/risky:

The policy explicitly names `live_rejit_programs()` overrides as forbidden because they enable filtering/skipping programs before ReJIT. Even if the base implementation currently returns all programs, the virtual hook is the problem. The `hasattr` fallback also preserves a compatibility shim.

Caller / grep evidence:

```text
rg -n "live_rejit_programs|LifecycleAbort|before_rejit|_EXCLUDED" runner/libs corpus runner/suites
runner/libs/app_runners/base.py:35:def live_rejit_programs
runner/libs/case_common.py:76:hasattr(runtime, "live_rejit_programs")
corpus/driver.py:260:session.runner.live_rejit_programs()
```

No `LifecycleAbort`, `before_rejit`, or `_EXCLUDED` pattern was found in active runner/corpus code.

Recommendation:

Delete `live_rejit_programs()` from the base runner and remove all call sites. The expected program list should come from raw app lifecycle artifacts or daemon live discovery, without a per-app override point.

Estimated removable LOC: 25-40 LOC.

### Finding R2: `SKIP_REJIT` writes synthetic skipped benchmark results

Path: `corpus/driver.py:136`, `corpus/driver.py:619`.

Current code:

```python
skip_rejit=_env_bool("SKIP_REJIT")
```

```python
if self.options.skip_rejit:
    result = {
        "status": "skipped",
        ...
        "per_program": [{"status": "skipped", ...}],
    }
```

Why this is forbidden:

This is a framework-level bypass that still writes result payloads. The rules say every BPF program must naturally attempt ReJIT and failures should surface as errors. A synthetic "skipped" result is neither raw counter data nor a real ReJIT error.

Caller / grep evidence:

```text
rg -n "SKIP_REJIT|skip_rejit|status.*skipped|per_program.*skipped" corpus/driver.py
136:skip_rejit=_env_bool("SKIP_REJIT")
619:if self.options.skip_rejit:
627:"status": "skipped"
628:"per_program": ...
```

Recommendation:

Remove `SKIP_REJIT` from corpus driver. If developers need baseline-only local diagnostics, put it in a separate non-result-writing command or analysis helper.

Estimated removable LOC: 20-30 LOC.

### Finding R3: runner shim continues after per-step failures

Path: `runner/libs/rejit.py:336`, `runner/libs/rejit.py:356`.

Current code:

```python
if not step_resp.get("ok"):
    errors.append(...)
    # Don't break: daemon's per-step loop keeps going ...
    continue
```

Why this is risky:

The runner shim recreates the same fallback semantics as the daemon: later passes run against the last successful bytecode. It records raw errors, but it still produces partial pass results for a pass sequence that did not actually execute as requested.

Caller / grep evidence:

```text
rg -n "_shim_request|Don't break|continue|bpfopt_summary" runner/libs/rejit.py
336:def _shim_request
356:# Don't break
361:continue
```

Recommendation:

Stop the program pass sequence after first bpfopt/ReJIT failure. Keep the raw error in result details; do not continue with later passes.

Estimated removable LOC: small; behavior change mirrors daemon findings.

### Finding R4: `programs.default` pass-plan fallback hides missing program config

Path: `runner/libs/rejit_plan.py:5`, `runner/libs/rejit_plan.py:63`.

Current code:

```python
<pass>/<app>.yaml -> programs.default
```

```python
entry = programs.get(prog_name)
if entry is None and "default" in programs:
    entry = programs["default"]
```

Why this is risky:

Program-specific config omissions silently fall back to `programs.default`. For benchmark policy, a missing entry should be visible unless the default comes from the top-level pass policy and is explicitly intended. Hidden fallback is especially risky when a pass has per-program side inputs.

Caller / grep evidence:

```text
rg -n "programs.default|programs\\[\"default\"\\]|fallback" runner/libs runner/config
runner/libs/rejit_plan.py:5:<pass>/<app>.yaml -> programs.default
runner/libs/rejit_plan.py:65:programs["default"]
```

Recommendation:

If an app override YAML exists, require every live program name to be explicitly listed or fail with a config error. Keep only a single documented pass-level default, not nested per-app fallback.

Estimated removable LOC: 10-20 LOC.

### Finding R5: `bpfopt_summary` naming risks confusion with forbidden framework summaries

Path: `runner/libs/rejit.py:343`, `daemon/src/commands.rs:937`.

Current code:

```python
"bpfopt_summary": step_resp.get("summary"),
```

Daemon detail:

```rust
bpfopt_summary: report.summary
```

Why this is suspicious:

This is not a performance comparison summary, so it is not automatically forbidden. But the framework rules forbid summaries and derived rollups in result payloads. The name `summary` / `bpfopt_summary` is easy to confuse with exactly those banned fields, especially if pass reports start adding counters such as matched/applied sites.

Caller / grep evidence:

```text
rg -n "bpfopt_summary|summary" runner/libs/rejit.py daemon/src/commands.rs
runner/libs/rejit.py:343:bpfopt_summary
daemon/src/commands.rs:937:bpfopt_summary
```

Recommendation:

Rename this to `bpfopt_report` or `pass_report`, and keep it strictly raw pass-output metadata. Do not include any fleet-level aggregation, ratios, or cross-program rollups.

Estimated removable LOC: none; naming/contract cleanup.

## micro+corpus

### Finding M1: `micro/generate_figures.py` contains forbidden metric functions, but appears analysis-side

Path: `micro/generate_figures.py:309`.

Current code:

```python
def geometric_mean(values):
    return math.exp(sum(math.log(v) for v in values) / len(values))
```

Use sites:

```python
ratios = ...
gmean = geometric_mean(...)
```

Why this is suspicious:

The function name is explicitly listed as a forbidden framework pattern. The file appears to be an analysis/figure script rather than benchmark runner code, which makes it acceptable only if it is never called by `make micro`, `make corpus`, or result-generation paths.

Caller / grep evidence:

```text
rg -n "geometric_mean|gmean|ratio|generate_figures" micro
micro/generate_figures.py:309:def geometric_mean
micro/generate_figures.py:409:gmean
micro/generate_figures.py:466:gmean
```

The active runner scan did not show `bootstrap_geometric_mean_ci`, `win_counts`, `comparison_summary`, `summarize_phase_timings`, `summarize_named_counters`, or `derive_perf_metrics` in active runner/corpus code.

Recommendation:

Keep this script clearly under analysis-only documentation and ensure no Makefile benchmark target calls it. If it is reachable from benchmark execution, move it out of `micro/` or rename/package it as post-hoc analysis.

Estimated removable LOC: not recommended if analysis script is needed.

### Finding M2: native ASM converters intentionally warn and continue

Path: `micro/programs/converter/native_asm_to_handcraft.py:4`, `micro/programs/converter/native_asm_to_handcraft_bpf_cf.py:1231`.

Current code:

```python
# Warnings do not stop generation.
```

```python
print("warnings:", ...)
return 0
```

Why this is risky:

The converter README says not to continue the converter as a production path. The scripts emit generated C with warning comments and exit successfully for non-fatal translation gaps. If these scripts are reachable in evaluation builds, they violate fail-fast expectations and can generate partial programs.

Caller / grep evidence:

```text
rg -n "Warnings do not stop|warning|return 0|production path" micro/programs/converter
native_asm_to_handcraft.py:4:Warnings do not stop generation
native_asm_to_handcraft.py:1032:print warnings
native_asm_to_handcraft_bpf_cf.py:1288:has_fatal
native_asm_to_handcraft_bpf_cf.py:1293:return 0
README.md:172:Do not continue this converter as a production path.
```

Recommendation:

Archive these converters outside the production source path, or make every unsupported/unmapped instruction fatal when used by any Makefile target. If they are historical tools only, mark them as such and keep them out of build dependencies.

Estimated removable LOC: no deletion recommended if archived; high if obsolete.

### Finding M3: forbidden performance-summary patterns mostly absent from active framework

Path: active runner/corpus scan.

Current code:

No active hits for:

```text
bootstrap_geometric_mean_ci
win_counts
comparison_summary
summarize_phase_timings
summarize_named_counters
derive_perf_metrics
```

Why this matters:

The highest-risk forbidden performance aggregation function found in active source was `micro/generate_figures.py::geometric_mean`, which looks analysis-side. Historical `corpus/results/**` files contain summary-like words but were excluded as artifacts.

Recommendation:

Keep the analysis/framework boundary strict. Do not move `generate_figures.py` logic into `runner/libs`, `corpus/driver.py`, or `micro` runner result generation.

Estimated removable LOC: none.

## test-others

### Finding T1: `native_lab_attach.cpp` intentionally duplicates native_lab runner helpers

Path: `ebpf-vm/test-others/native_lab_attach.cpp:22`.

Current code:

```cpp
// Function bodies for steps (5)-(6) and helpers (3)-(4) are copied from
// runner/src/native_lab_runner.cpp -- duplication is intentional.
```

Duplicated helpers:

```text
kKfuncName
ensure_debugfs_mounted
find_kfunc_btf_id
kallsyms_lookup
native_link_binary
load_stub_prog
```

Why this is redundant:

The comment explicitly states intentional duplication. That is acceptable for a throwaway POC, but the directory was newly added and now sits in the repo. If it stays, it creates a second implementation of the native-lab attach/link path that can drift from the benchmark runner.

Caller / grep evidence:

```text
rg -n "Function bodies|ensure_debugfs_mounted|find_kfunc_btf_id|kallsyms_lookup|native_link_binary|load_stub_prog" runner/src/native_lab_runner.cpp ebpf-vm/test-others/native_lab_attach.cpp
runner/src/native_lab_runner.cpp:77:ensure_debugfs_mounted
ebpf-vm/test-others/native_lab_attach.cpp:83:ensure_debugfs_mounted
runner/src/native_lab_runner.cpp:173:find_kfunc_btf_id
ebpf-vm/test-others/native_lab_attach.cpp:175:find_kfunc_btf_id
runner/src/native_lab_runner.cpp:271:kallsyms_lookup
ebpf-vm/test-others/native_lab_attach.cpp:248:kallsyms_lookup
```

Recommendation:

Either delete/archive the POC after the experiment, or factor shared native-lab attach/link helpers into one source used by both. If standalone is intentional, keep it outside default benchmark build and state that explicitly.

Estimated removable/factorable LOC: 250-350 LOC.

### Finding T2: uprobe loader deliberately executes a failing attach path and ignores the result

Path: `ebpf-vm/test-others/native_lab_attach.cpp:708`.

Current code:

```cpp
int rc = nl_load_and_attach(... "raw_tp", "__nl_placeholder_no_attach", ...);
// The above call will fail at attach time...
(void)rc;
nl_close(out);
```

Then the file repeats load-only logic inline.

Why this is dead/redundant/risky:

This is a deliberate failure and ignored result used as a control-flow tool. It duplicates about 75 LOC of loading logic after the failed call. That violates fail-fast style and makes the POC harder to trust.

Caller / grep evidence:

```text
rg -n "__nl_placeholder_no_attach|\\(void\\)rc|nl_load_and_attach|uprobe" ebpf-vm/test-others/native_lab_attach.cpp
708:nl_load_and_attach(... "__nl_placeholder_no_attach" ...)
716:(void)rc;
719:repeated load-only path begins
```

Recommendation:

Split `nl_load_only()` from attach-specific code. The uprobe path should call load-only directly and fail if load fails.

Estimated removable LOC: 70-90 LOC.

### Finding T3: test-others attach helper silences cleanup and debugfs errors

Path: `ebpf-vm/test-others/native_lab_attach.cpp:91`, `ebpf-vm/test-others/native_lab_attach.cpp:812`.

Current code:

```cpp
(void)mount("none", kDebugfsDir, "debugfs", 0, nullptr);
```

```cpp
(void)write(fd, "-:nl_target\n", 12);
(void)unlink(kprobe_events_path);
```

Why this is risky:

Even for a POC, ignored debugfs and cleanup failures make later measurements ambiguous. If the cleanup did not run, the next test may observe stale probes. If debugfs did not mount and the path is absent, later errors are less clear.

Caller / grep evidence:

```text
rg -n "\\(void\\)mount|\\(void\\)write|\\(void\\)unlink" ebpf-vm/test-others/native_lab_attach.cpp
91:(void)mount
812:(void)write
818:(void)unlink
```

Recommendation:

Propagate these errors or explicitly verify the desired postcondition after the call. Cleanup failures should at least be reported and should fail in benchmark mode.

Estimated removable LOC: small.

### Finding T4: test-others runner returns zero-valued measurements on errors

Path: `ebpf-vm/test-others/runner.cpp:110`, `ebpf-vm/test-others/runner.cpp:175`.

Current code:

```cpp
return {};
```

Why this is risky:

`run_kernel` and `run_native` return a zero-valued `TimedRun` on open/load/attach/readlink failures. The caller later computes per-call values and ratios from those fields. That turns setup failure into numeric-looking output.

Caller / grep evidence:

```text
rg -n "return \\{\\}|run_kernel|run_native|ratio" ebpf-vm/test-others/runner.cpp
110:run_kernel
175:run_native
237:ratio
```

Recommendation:

Return an error type or exit non-zero on setup failure. Do not feed sentinel zero measurements into ratio calculations.

Estimated removable LOC: neutral; behavior change.

### Finding T5: test-others runner computes derived benchmark ratios inline

Path: `ebpf-vm/test-others/runner.cpp:237`.

Current code:

```cpp
double k_handler = ...
double n_handler = ...
double ratio = n_handler / k_handler;
```

Why this is forbidden if treated as framework:

The repo policy forbids in-framework averages/ratios/derived metrics. This POC calculates handler overhead and ratio directly in the runner. If `test-others` is purely a standalone experimental directory, that may be acceptable; if it is part of the shared evaluation framework, this must move to post-hoc analysis.

Caller / grep evidence:

```text
rg -n "per-call|ratio|baseline|handler" ebpf-vm/test-others/runner.cpp ebpf-vm/test-others/README.md
runner.cpp:237:double ratio
runner.cpp:244:printf baseline/handler/ratio
README.md:74:example ratios
README.md:94:interpretation
```

Recommendation:

Emit raw counters/timestamps only from the runner. Put ratio and overhead interpretation into an analysis script or README-generated postprocessing.

Estimated removable LOC: 20-40 LOC.

### Finding T6: `test-others/build/` contains generated binaries/objects

Path: `ebpf-vm/test-others/build/`.

Current code:

```text
build/*.o
build/runner
build/run-in-vm.sh
```

Why this is suspicious:

Generated objects and helper scripts under a source subtree make audits noisy and can accidentally be committed or consumed. They were excluded from detailed source findings, but the directory should not be treated as source.

Caller / grep evidence:

```text
find ebpf-vm/test-others -maxdepth 2 -type f
```

Recommendation:

Ensure `build/` is ignored and not part of review/evaluation. Prefer a top-level ignored build directory.

Estimated removable LOC: generated artifacts only.

## Cross-cutting forbidden-pattern notes

### No ReJIT filtering patterns

Active hits:

```text
runner/libs/app_runners/base.py:35:live_rejit_programs
runner/libs/case_common.py:76:hasattr(runtime, "live_rejit_programs")
corpus/driver.py:260:session.runner.live_rejit_programs()
corpus/driver.py:136:SKIP_REJIT
daemon/src/commands.rs:396:steps.is_empty -> skipped_program_result
```

No active hits found for:

```text
LifecycleAbort
before_rejit
_EXCLUDED_PROGRAM_NAMES
```

### Summary/aggregation patterns

Active non-artifact hits:

```text
micro/generate_figures.py:309:geometric_mean
runner/libs/rejit.py:343:bpfopt_summary
daemon/src/commands.rs:937:bpfopt_summary
```

No active non-artifact hits found for:

```text
bootstrap_geometric_mean_ci
win_counts
comparison_summary
summarize_phase_timings
summarize_named_counters
derive_perf_metrics
```

Interpretation:

`micro/generate_figures.py` looks analysis-side and should stay there. `bpfopt_summary` should be renamed or documented as raw optimizer output, not benchmark performance summary.

### Dead-code silencing patterns

High-confidence active hits:

```text
ebpf-vm/x86/native_lab/native_link/src/main.rs:1090:#[allow(dead_code)]
ebpf-vm/x86/native_lab/native_link/src/main.rs:1086:let _ = TRAMPOLINE_LEN
ebpf-vm/x86/native_lab/native_link/src/main.rs:1212:let _ = map_addrs
runner/src/native_lab_runner.cpp:605:(void)xlated
ebpf-vm/test-others/native_lab_attach.cpp:716:(void)rc
```

Recommendation:

Treat these as delete-on-sight unless a real caller is added immediately.

## Top 10 deletable / simplifiable LOC estimates

Sorted primarily by severity, then estimated deletion/simplification size.

| rank | target | severity | estimated LOC | action |
|---:|---|---:|---:|---|
| 1 | `bpfopt/loader/` workspace package | Critical | 1000+ | Remove from production workspace or archive as dev-only fixture. |
| 2 | `ebpf-vm/x86/native_lab/native_link/src/main.rs:1090` legacy relocation collector | Critical | 120-130 | Delete dead function, `#[allow(dead_code)]`, and silencing constants. |
| 3 | `ebpf-vm/test-others/native_lab_attach.cpp` duplicated native-lab helper bodies | High | 250-350 | Factor shared helper or archive POC. |
| 4 | `module/arm64/bpf_arm64_ldp.c` default-built no-consumer module | High/Medium | 213 | Remove from default build until a pass consumes it. |
| 5 | `runner/src/native_lab_runner.cpp` legacy direct native-object mode | High | 50-80 | Delete `.native.o/.native.so` and legacy symbol compatibility. |
| 6 | `ebpf-vm/test-others/native_lab_attach.cpp:708` failed attach then duplicate load path | High | 70-90 | Split load-only API and remove deliberate failed call. |
| 7 | `runner/src/native_lab_runner.cpp` embedded companion/JIT/map analysis | Medium | 150-250 factored | Move to shared helper or native linker side-input generator. |
| 8 | `module/arm64/*` repeated emit boilerplate | Medium | 80-120 | Replace with one common arm64 emit helper. |
| 9 | `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs` timing atomics | Medium | 35-45 | Delete unused timing instrumentation. |
| 10 | `runner/libs/app_runners/base.py` / `case_common.py` / `corpus/driver.py` `live_rejit_programs` hook | High | 25-40 | Delete forbidden hook and fallback call sites. |

Near-miss but important:

| target | severity | reason |
|---|---:|---|
| `corpus/driver.py:619` `SKIP_REJIT` | High | Fewer LOC than others, but should be removed early because it can produce invalid benchmark results. |
| `daemon/src/commands.rs:396/705/801` skip/continue paths | High | Small LOC, large semantic impact. |
| `bpfopt/crates/bpfopt/src/passes/branch_flip.rs` profile ingestion gap | High | Not a large deletion, but should be fixed before any Paper B branch-flip benchmark. |

## Suggested cleanup order

1. Remove explicit policy violations first: native_link `#[allow(dead_code)]`, `SKIP_REJIT`, `live_rejit_programs`, daemon skipped empty-plan result.
2. Make daemon/runner pass chains fail-stop after the first bpfopt/ReJIT failure.
3. Remove or quarantine loader/POC code from production workspaces and default builds.
4. Then do low-risk duplication cleanup: arm64 emit helper, move-reg payload helper, native-lab shared helpers.
5. Finally address larger design work: `branch_flip` profile ingestion, `map_inline` alias-tracker extraction, and `insn.rs` direct libbpf type migration.
