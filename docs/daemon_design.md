# Daemon Design

## 1. Purpose

This document defines the long-term userspace architecture for BpfReJIT's
`daemon/` and its interface with `runner/`.

The intent is not to preserve the current implementation shape. The intent is
to make the daemon match the paper/system goals in
`docs/kernel-jit-optimization-plan.md`:

- post-load optimization of live kernel eBPF programs
- transparent operation with no `.bpf.o` requirement at optimization time
- runtime-guided optimization and security hardening
- minimal kernel mechanism, rich userspace policy
- fail-safe behavior: verifier failure means no swap

This is a non-compatible redesign. There should be no compatibility layer for
the current ad-hoc `serve` protocol or the current runner-side string parsing.
If we change the architecture, we replace the old one.

## 2. Design Constraints

The daemon design must satisfy these constraints:

1. The daemon is policy, not mechanism.
   Kernel exports `GET_ORIGINAL`/`REJIT` and kinsn/kfunc capability surfaces;
   daemon decides what to optimize and when.
2. The daemon remains zero-libbpf.
   It may use raw BPF syscalls, procfs/sysfs/BTF parsing, and Unix sockets, but
   it must not depend on libbpf.
3. The daemon is transparent to applications and loaders.
   Optimization targets are live programs identified post-load; no application
   changes, no loader changes, no `.bpf.o` requirement in the public story.
4. Benchmark mode and production mode are both first-class.
   `apply-all` is the deterministic benchmark path; `watch` is the long-running
   production path.
5. Security and performance live in the same framework.
   Optimization, hardening, dangerous-helper containment, and live patching all
   go through the same engine and result model.
6. Failures are structured.
   "Verifier rejected", "dynamic condition not met", "terminal unsupported",
   and "retryable kernel-side failure" must be different result kinds, not free
   form log strings.

## 3. Target Architecture

The daemon/runner split should be:

```text
runner / static_verify / e2e
        |
        v
typed daemon client
        |
        v
Daemon Service
- protocol
- request routing
- worker queue
- watch controller
- capability refresh
        |
        v
Optimization Engine
- snapshot -> analyze -> rewrite -> execute -> classify
        |
        +--> Pass Pipeline
        +--> Kernel adapters
        +--> Profiler / capability providers
```

### 3.1 Layer Responsibilities

#### A. Pass Pipeline

This layer stays close to the current `pass.rs`/`passes/` model, but it must be
pure transformation logic:

- own `BpfProgram`, analyses, pass registry, and transform application
- emit precise transform provenance for each pass
- not print to stdout/stderr
- not know about Unix sockets, CLI modes, or runner JSON
- not call raw syscalls directly

Required new output:

- `TransformLedger`: exact site records, old/new PC mapping, emitted ranges,
  capability dependencies, and pass attribution

The current whole-program conservative attribution is not acceptable as the
long-term model because it makes rollback order-dependent as pass count grows.

#### B. Optimization Engine

This is the core orchestration library. It replaces the current
`try_apply_one()`-centric design.

Input:

- `ProgramSnapshot`
- `CapabilitySnapshot`
- `OptimizationRequest`

Output:

- `OptimizationResult`

Responsibilities:

- run profiling if requested
- build and execute the pass pipeline
- perform map-fd/BTF transport preparation
- invoke REJIT
- classify the result
- run rollback/retry policy using `TransformLedger`
- optionally collect debug artifacts

Non-responsibilities:

- socket I/O
- CLI printing
- runner-specific formatting
- benchmark aggregation

#### C. Kernel/Profiler/Capability Adapters

All live-kernel dependencies must be isolated behind interfaces:

- `ProgramSource`
  - enumerate live programs
  - fetch original insns and metadata
  - fetch runtime xlated/jited images
  - fetch map metadata
- `RejitExecutor`
  - submit rewritten bytecode and fd array
  - return verifier log, errno-classification, and runtime images
- `Profiler`
  - program hotness
  - PMU-derived branch data when available
- `CapabilityProvider`
  - kinsn/kfunc availability
  - BTF transport metadata
  - platform capabilities
  - refresh versioning

The engine may depend on these adapters, but pass code may not.

#### D. Daemon Service

This is the long-running server/controller process.

Responsibilities:

- expose a typed Unix-socket protocol
- manage worker queue and concurrency limits
- own `watch` state and scheduling
- refresh capability snapshots
- expose batch APIs for runner/static verification

The service is allowed to accept concurrent clients, but optimization execution
should default to a bounded queue with worker count 1 until proven safe to
parallelize. This preserves deterministic kernel interaction and avoids hidden
REJIT races.

#### E. Runner Client

Runner becomes a typed client, not a parser for daemon internals.

Responsibilities:

- submit `optimize_one` / `optimize_batch`
- consume typed responses
- convert them into benchmark/static-verify records

Non-responsibilities:

- inferring semantic state from raw log strings
- scraping nested JSON with manual field extraction
- reconstructing retryability or final status on its own

This keeps `runner` aligned with the benchmark-framework rule that runner
measures and orchestrates, while daemon owns optimization semantics.

## 4. Public Interface

The long-term service protocol should be versioned and typed.

### 4.1 Request Envelope

Each request must contain:

- `version`
- `request_id`
- `op`
- `payload`

### 4.2 Response Envelope

Each response must contain:

- `version`
- `request_id`
- `ok`
- `result`
- `error`

Error responses still carry structured classification data. The service must
not have a "success path returns object, failure path returns only message"
split.

### 4.3 Supported Operations

The service API should expose:

- `health`
- `enumerate`
- `optimize_one`
- `optimize_batch`
- `profile_one`
- `watch_admin`

`optimize_batch` is required for `static_verify` and future scalability work.

### 4.4 Optimization Result Model

Each optimization result must distinguish:

- `applied`
- `unchanged_stable`
- `unchanged_dynamic`
- `failed_retryable`
- `failed_terminal`

Required payload groups:

- `program`
- `summary`
- `attempts`
- `failure_classification`
- `capability_snapshot_version`
- `artifacts`

`artifacts` must be controlled by explicit debug level:

- `none`
- `summary`
- `full`

The default hot path is `summary`. Full bytecode and machine-code dumps are
diagnostic artifacts, not baseline protocol payload.

## 5. Watch and Invalidation Model

The current `optimized / no_op / fail_count` model is too weak for the paper
story because the daemon already has dynamic optimization families such as map
inlining invalidation and PGO-sensitive passes.

The long-term watch state machine should be:

- `Pending`
- `DeferredDynamic`
- `Applied`
- `RetryScheduled`
- `TerminalFailure`

Rules:

- Stable no-change is terminal only if the engine explicitly classifies it as
  `unchanged_stable`.
- Runtime-dependent no-change becomes `DeferredDynamic`.
- Dynamic map invalidation is an engine/service feature, not a pass-local hack.
- Capability refresh may move programs back from `DeferredDynamic` to `Pending`.
- `watch` must become the natural home for map invalidation re-REJIT and future
  runtime-guided reoptimization.

This directly supports the main plan's "map stable -> inline -> invalidate ->
re-REJIT" story.

## 6. Refactor Plan

### Phase 1: Extract Core Model

- Define `ProgramSnapshot`, `CapabilitySnapshot`, `OptimizationRequest`,
  `OptimizationResult`, `FailureClassification`, and `TransformLedger`.
- Remove stdout/stderr as part of the engine contract.
- Make CLI and service consume the same engine-facing result types.

### Phase 2: Split Engine from Adapters

- Move raw syscall/BTF/profiler interactions behind adapters.
- Move orchestration out of `commands.rs`.
- Keep pass algorithms unchanged in this phase; only change boundaries.

### Phase 3: Replace Service

- Replace the current `server.rs` implementation with `DaemonService`.
- Implement typed protocol and batch support.
- Make `watch` a controller owned by the service, not a separate command loop
  calling low-level functions directly.

### Phase 4: Replace Runner Integration

- Add typed daemon client in runner.
- Change `static_verify` and benchmark paths to batch-first requests.
- Delete manual JSON scraping and string-based field extraction.

### Phase 5: Delete Old Paths

- Delete the current `serve` protocol implementation.
- Delete old runner parsing logic.
- Delete duplicated CLI orchestration paths.
- Update docs and Make targets together so the new architecture is the only
  documented one.

## 7. Test Organization

The test layout must mirror the architecture.

### 7.1 Pure Rust Unit Tests

Keep and expand:

- analyses
- passes
- transform ledger generation
- rollback attribution
- engine result classification
- watch state transitions in pure model form

These tests must not depend on a live kernel.

### 7.2 Host Integration Tests

Add service-level host tests for:

- request/response schema
- batch execution behavior
- structured error behavior
- debug artifact gating
- safe socket-path handling
- bounded queue behavior under concurrent clients

These tests validate the daemon as a service, not just pass internals.

### 7.3 Runner/Daemon Integration Tests

Use a fake daemon or fake adapters to test:

- typed client parsing
- `optimize_batch` consumption
- static-verify record generation
- retryable vs terminal failure handling

Runner should never need to interpret daemon internals outside the typed client.

### 7.4 VM Integration Tests

Reserve VM coverage for live-kernel behavior:

- REJIT success/failure paths
- verifier log capture
- runtime image fetching
- capability refresh against real kernel state
- watch controller behavior
- dynamic invalidation end-to-end

### 7.5 Make Targets

Testing should be organized through `make`:

- `make daemon-tests`
  - pure Rust unit tests + host service integration tests
- `make daemon-runner-tests`
  - runner/fake-daemon integration
- `make daemon-vm-tests`
  - VM-backed live-kernel daemon tests

The root `Makefile` remains a thin entrypoint; detailed logic should live under
the relevant subdirectories.

## 8. Alignment With kernel-jit-optimization-plan.md

This design is aligned with the main system plan in the following ways:

1. **Matches the paper split of mechanism vs policy.**
   The main plan explicitly assigns kernel to mechanism and daemon to policy.
   This design keeps pass selection, profiling, hardening, rollback, and
   runtime decisions in userspace.
2. **Preserves transparency.**
   The design keeps the daemon operating on live programs discovered post-load,
   not on source artifacts or pre-load optimization hooks.
3. **Preserves zero-libbpf daemon scope.**
   The daemon interface is built on raw syscall/BTF/procfs style adapters, not
   libbpf.
4. **Preserves benchmark vs production split.**
   `apply-all` remains the deterministic measurement path; `watch` becomes the
   production controller.
5. **Supports runtime-guided optimization and security hardening in one engine.**
   This is required by the main plan's four-use-case story.
6. **Supports dynamic map inlining invalidation properly.**
   The main plan already treats this as a paper-core story; the new watch model
   is designed around it.

## 9. Current Gaps vs Design Goal

The current implementation still diverges from the desired architecture in a
few important ways:

- service protocol is ad-hoc and asymmetric
- core orchestration is concentrated in one large function
- rollback attribution is too coarse
- watch state does not model dynamic eligibility/invalidation
- debug capture is too tightly coupled to the hot path
- runner still understands daemon internals instead of a typed client contract

These gaps are implementation issues, not paper-direction issues. The paper
goal and the long-term daemon design are consistent; the current code structure
is what needs to move.
