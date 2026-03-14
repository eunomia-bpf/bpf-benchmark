# BpfReJIT Architecture Gap Analysis

**Date**: 2026-03-12  
**Scope**: current repository state vs. the PI's correct three-component daemon architecture

---

## Executive Summary

The repository already contains the core mechanism needed for the PI's architecture, but it is packaged in the wrong shape.

- **Already aligned with the target model**: the scanner core operates on post-verifier `xlated` bytecode, the live `--prog-fd` path fetches bytecode from the kernel, the policy compiler builds the same sealed directive blob the daemon will need, and the E2E helpers already reopen live programs by ID and issue `BPF_PROG_JIT_RECOMPILE`.
- **Main architectural mismatch**: the current userspace control plane is still expressed as a scanner CLI plus benchmark harnesses, with offline ELF/object-file convenience paths and object-path-indexed policy lookup treated as first-class inputs.
- **Largest functional gap**: the current userspace logic analyzes only verified BPF bytecode. The PI's target daemon should analyze both BPF bytecode and JITed native code; the kernel/user ABI already exposes the native image, but the repository does not yet consume it.
- **Conclusion**: this is primarily a packaging and integration refactor, not a kernel-mechanism redesign. The kernel ABI surface already supports live discovery, live inspection, and post-load re-JIT.

---

## 1. Target Architecture and Its Implications

The PI's architecture implies three strict boundaries:

1. **Applications are unchanged**
   bpftrace, Tetragon, Cilium, Tracee, and other loaders keep their normal `BPF_PROG_LOAD` path. No custom loader is introduced.
2. **The userspace optimizer is post-load**
   A separate daemon discovers already-loaded programs from the kernel, extracts their state, analyzes them, and requests re-JIT.
3. **The kernel remains the only code generator**
   Userspace sends directives, not native code. The kernel validates and emits only kernel-owned canonical variants.

From this, several concrete requirements follow:

- The steady-state scanner input should be a **live program handle or program ID**, not a `.bpf.o` file.
- The steady-state policy concept should be **live site discovery -> directive selection -> syscall**, not "find an object-specific YAML file first."
- The userspace analyzer should use **both**:
  - verified BPF bytecode (`xlated_prog_insns`)
  - JITed native code (`jited_prog_insns`)
- The system should not require offline artifacts to exist once the application has loaded the program.

---

## 2. What Already Works for the Daemon Model

### 2.1 The scanner core is already live-bytecode compatible

The most reusable part of the current codebase is the scanner library itself.

- `scan_v5_builtin()` in `scanner/src/pattern_v5.cpp:1690` consumes a raw `xlated` byte buffer and emits `V5PolicyRule` records for the eight canonical families.
- `build_policy_blob_v5()` in `scanner/src/pattern_v5.cpp:1795` serializes those rules into the binary directive blob consumed by the kernel recompile path.
- `V5PolicyRule`, `V5ScanSummary`, and `V5ScanOptions` in `scanner/include/bpf_jit_scanner/pattern_v5.hpp:230` are agnostic to ELF files and already match the daemon's live-analysis needs.

This is the right abstraction boundary. The daemon should reuse this library logic instead of reimplementing site detection.

### 2.2 The current CLI already knows how to fetch live verified BPF bytecode

The live path is already implemented in `scanner/src/cli.cpp`.

- `mini_bpf_prog_info` mirrors `struct bpf_prog_info` in `scanner/src/cli.cpp:56`.
- `fetch_prog_info()` calls `BPF_OBJ_GET_INFO_BY_FD` in `scanner/src/cli.cpp:359`.
- `fetch_xlated()` allocates a buffer, sets `info.xlated_prog_insns`, and asks the kernel to copy the verified program into userspace in `scanner/src/cli.cpp:372`.
- `load_input()` chooses the live path when `--prog-fd` is provided in `scanner/src/cli.cpp:395`.
- `run_scan()` and `run_apply()` both work on that live-program input in `scanner/src/cli.cpp:796` and `scanner/src/cli.cpp:879`.

This is already the correct input boundary for a daemon.

### 2.3 The policy filter and manifest model are reusable

The v3 policy representation matches the daemon's "discovered live site subset" abstraction well.

- `V5PolicySite` / `V5PolicyConfig` in `scanner/include/bpf_jit_scanner/policy_config.hpp:13` capture a site by `(insn, family, pattern_kind)`.
- `filter_rules_by_policy_detailed()` in `scanner/src/policy_config.cpp:428` intersects discovered rules with an explicit allowlist.
- `build_scan_manifest()` and `scan_manifest_to_json()` in `scanner/src/policy_config.cpp:524` and `scanner/src/policy_config.cpp:545` already produce a machine-readable live site inventory.

The daemon can keep this abstraction. What needs to change is where the site list comes from and how it is stored, not the site schema itself.

### 2.4 The E2E helpers already operate on live program IDs and FDs

`e2e/common/recompile.py` is the clearest existing prototype of the daemon control loop.

- `_prog_fd_by_id()` in `e2e/common/recompile.py:35` uses `libbpf` to reopen a live program by ID.
- `_scan_live_manifest()` in `e2e/common/recompile.py:210` runs the scanner on a live `prog_fd`.
- `scan_programs()` in `e2e/common/recompile.py:323` batches live scans over multiple program IDs.
- `apply_recompile()` in `e2e/common/recompile.py:375` scans the live program, optionally remaps a policy to the live site layout, and invokes `scanner apply --prog-fd`.

This code already demonstrates:

- live program reopening
- live site discovery
- live apply
- no application restart

Those are core daemon behaviors.

### 2.5 The repository already has bpftool-style live metadata collection

`e2e/common/metrics.py` already uses both `bpftool` and `bpf_prog_info`:

- `BpfProgInfo` includes `jited_prog_len`, `xlated_prog_len`, `jited_prog_insns`, `xlated_prog_insns`, `run_time_ns`, and `run_cnt` in `e2e/common/metrics.py:19`.
- `sample_bpf_stats()` uses `bpftool -j -p prog show` in `e2e/common/metrics.py:116` and falls back to `bpf_prog_get_info_by_fd()` in `e2e/common/metrics.py:144`.

So the repo already depends on live kernel enumeration and live metadata collection. That is exactly the daemon's discovery substrate.

---

## 3. What Still Assumes ELF/Object-File Analysis

### 3.1 The scanner CLI still treats offline files as first-class inputs

`scanner/src/cli.cpp` still exposes an ELF- and file-centric interface:

- CLI usage allows `(<file> | --prog-fd <fd> | --xlated <file>)` in `scanner/src/cli.cpp:505`.
- `data_is_elf_object()` in `scanner/src/cli.cpp:204` checks whether the input begins with ELF magic.
- `read_object_program()` in `scanner/src/cli.cpp:248` reads BPF instructions directly from an ELF object.
- `try_load_object_xlated()` in `scanner/src/cli.cpp:277` attempts to load a `.bpf.o`, then fetch the resulting live `xlated` program.
- `load_input()` falls back to raw ELF-program instructions if loading fails in `scanner/src/cli.cpp:406`.

This is useful for corpus and micro experiments, but it is the wrong steady-state architecture for deployment. The daemon should not need object files at all.

### 3.2 Policy lookup is still indexed by `object_path`

The strongest remaining ELF-era assumption is in the policy utilities.

- `PolicyTarget` includes `object_path` in `e2e/common/recompile.py:18`.
- `resolve_policy_files()` in `e2e/common/recompile.py:302` uses `object_path` plus `program_name` to locate a policy file.
- `object_relative_path()`, `object_policy_stem()`, `program_policy_dir()`, and `policy_path_for_program()` in `corpus/policy_utils.py:120`, `:133`, `:146`, and `:151` build a directory hierarchy rooted in object-file location.
- `resolve_policy_path()` in `corpus/policy_utils.py:159` only finds policies by object path plus program name.

This is incompatible with the PI's model. In the correct deployment architecture:

- the application may not expose its `.bpf.o`
- the daemon may not know the original object path
- policy must be keyed off **live kernel identity**, not offline artifact location

Good future keys would be combinations of `prog_id`, `prog_tag`, program type, attach type, name, and perhaps higher-level workload identity.

### 3.3 Offline-to-live remapping is a transitional workaround, not the target design

The current live policy path still assumes the authoritative policy may originate from an offline artifact and may need remapping.

- `_write_live_remapped_policy()` in `e2e/common/recompile.py:236` rewrites a stored policy against the current live manifest.
- `remap_policy_v3_to_live()` in `corpus/policy_utils.py:307` matches explicit sites by `(family, pattern_kind)` order and assigns live instruction indices sequentially.

This is a practical benchmark-era bridge, but it is not the right steady-state model. A true daemon should generate directives directly from the live program it is about to recompile, which eliminates the drift problem entirely.

### 3.4 The repository does not yet fetch or analyze JITed native code

This is the largest functional gap relative to the PI's architecture.

What exists:

- `mini_bpf_prog_info` already includes `jited_prog_len` and `jited_prog_insns` in `scanner/src/cli.cpp:60`.
- `struct bpf_prog_info` exposes the same fields in `/usr/include/linux/bpf.h:6450`.

What is missing:

- there is **no** `fetch_jited()` helper analogous to `fetch_xlated()`
- there is **no** code path that sets `info.jited_prog_insns` and asks the kernel to copy the JITed image into userspace
- there is **no** scanner or analyzer that looks at native machine code bytes
- `run_dump()` in `scanner/src/cli.cpp:928` only dumps `xlated`, not `jited`

The current userspace analysis is therefore still bytecode-only, even though the ABI already supports dual-view analysis.

### 3.5 There is no resident daemon loop or program-lifecycle state

The current control plane is batch-oriented:

- run scanner once
- maybe load a policy file
- maybe apply once
- exit

Missing daemon behaviors include:

- continuous enumeration or event-driven discovery of newly loaded programs
- tracking already-seen programs by ID/tag
- detecting when a program is replaced or unloaded
- reapplying or retracting policies over time
- maintaining last-known-good state
- centralized observability and rollback

The code proves the mechanism, but not yet the service packaging.

---

## 4. How the Current E2E Pipeline Differs from the Envisioned Daemon

### 4.1 What the current E2E path gets right

The E2E path is already closer to the PI's architecture than the corpus/micro pipeline:

- applications are **unmodified**
- programs are optimized **after load**
- the helper works on **live program IDs/FDs**
- recompile happens **without restart**

This is real architectural progress, not just a benchmark trick.

### 4.2 Where the E2E path still differs from a daemon

| Dimension | Current E2E Pipeline | Correct Daemon Model |
|---|---|---|
| Discovery | Case-specific helpers determine target program IDs | Generic resident discovery over all loaded programs |
| Analysis input | Mostly live `xlated` bytecode | Live `xlated` bytecode + live JITed native code |
| Policy source | Optional YAML policy files, often resolved from `object_path` | Live discovery directly produces directives |
| Lifetime | Batch helper invoked by benchmark harness | Long-running service |
| State | Per-run temporary data | Persistent daemon state and rollback |
| Observability | Per-case logs / JSON outputs | Unified daemon metrics and audit trail |

### 4.3 Practical interpretation

The E2E pipeline should be viewed as the daemon control plane cut into research-friendly pieces:

- discovery and live scan
- optional policy remap
- blob build
- live recompile

It validates the mechanism. It does not yet provide the production packaging the PI wants.

---

## 5. Kernel and bpftool Capabilities Already Available

### 5.1 Enumeration and opening of live programs

The syscall API already exposes the discovery path the daemon needs.

- `/usr/include/linux/bpf.h:388` documents `BPF_PROG_GET_NEXT_ID` as "Fetch the next eBPF program currently loaded into the kernel."
- `/usr/include/linux/bpf.h:414` documents `BPF_PROG_GET_FD_BY_ID` as "Open a file descriptor for the eBPF program corresponding to `prog_id`."
- `e2e/common/recompile.py:35` and `e2e/common/metrics.py:92` already use `bpf_prog_get_fd_by_id()`.

This is enough to implement a generic enumeration loop without application cooperation.

### 5.2 Inspection of BPF bytecode and JITed native code

`BPF_OBJ_GET_INFO_BY_FD` already exposes the program state the daemon needs.

- `/usr/include/linux/bpf.h:432` documents `BPF_OBJ_GET_INFO_BY_FD`.
- `/usr/include/linux/bpf.h:6450` defines `struct bpf_prog_info`.
- The same structure includes:
  - `jited_prog_len`
  - `xlated_prog_len`
  - `jited_prog_insns`
  - `xlated_prog_insns`
  - `run_time_ns`
  - `run_cnt`

Therefore, a privileged daemon can already extract:

- verified BPF instructions
- JITed machine code bytes
- code sizes
- runtime counters

subject to normal kernel permissions and JIT availability.

### 5.3 bpftool already demonstrates these capabilities end-to-end

Local `bpftool prog help` on this machine exposes:

- `bpftool prog show`
- `bpftool prog dump xlated PROG`
- `bpftool prog dump jited PROG`

So "bpftool-like functionality" is not hypothetical. The kernel already exposes the required surfaces, and bpftool already exercises them.

### 5.4 What the repo currently uses vs. what it leaves unused

**Already used in the repo**

- live reopen by program ID
- live `xlated` fetch
- live run-time counters
- `bpftool prog show` metadata collection
- live `BPF_PROG_JIT_RECOMPILE`

**Not yet used**

- live `jited_prog_insns` fetch
- daemon-side correlation between BPF bytecode sites and native-code layout
- generic `BPF_PROG_GET_NEXT_ID` enumeration loop inside the BpfReJIT control plane

---

## 6. Refactor Priority: What Should Change First

### 6.1 Extract a daemon library from the scanner CLI

Keep:

- `scan_v5_builtin()`
- `build_policy_blob_v5()`
- manifest generation
- policy filtering

De-emphasize or isolate:

- ELF convenience input
- offline `--xlated` file paths
- object-file-first CLI usage

### 6.2 Add a generic live program discovery module

New daemon module responsibilities:

- enumerate program IDs
- open FDs
- fetch `bpf_prog_info`
- track `(prog_id, prog_tag)` over time

This should become the canonical source of truth for "what exists in the kernel right now."

### 6.3 Add a dual extractor: `xlated` plus `jited`

Implement a new userspace helper analogous to `fetch_xlated()` but for:

- `jited_prog_len`
- `jited_prog_insns`

Once this exists, the daemon can perform the PI's intended dual-view analysis.

### 6.4 Replace `object_path`-based policy lookup with live identity

Short term:

- allow persisted policy snapshots to be keyed by live program metadata rather than object location

Long term:

- generate directives directly from live discovery
- treat persisted YAML as audit/debug output rather than as the primary control-plane input

### 6.5 Package the current batch flow as a resident daemon

The existing E2E control flow already proves the core mechanism. The remaining work is to make it persistent:

- background service
- state cache
- retry / rollback
- observability
- continuous discovery

---

## 7. Bottom Line

The core scanner logic is reusable. The live apply mechanism is reusable. The kernel ABI already supports the daemon model. The current architectural problem is that the repository still centers its userspace control plane on a CLI, offline artifacts, and object-path-indexed policies, while the PI's design calls for a resident live-state daemon that analyzes both bytecode and native code.

In other words: **the mechanism is largely there; the control plane still needs to be re-shaped around the correct deployment boundary.**
