# AWS Remote And Runner Refactor

## 1. Purpose

This document is the single source of truth for:

- the runner refactor shape
- the current AWS ARM64 / AWS x86 / local x86 KVM entrypoints
- the important problems found while refactoring
- the ordered todo list that must be completed before full validation is considered done

This document intentionally combines:

- design
- progress log
- open issues

The goal is to keep one precise record instead of multiple drifting notes.

Historical log sections later in this document preserve intermediate states.
If an older log entry conflicts with sections 2-5 or 9.4-9.5, the design and
todo sections win.

In particular, older historical notes may still mention intermediate names such
as `RUN_LOCAL_PROMOTE_ROOT`, `RUN_LOCAL_STAGE_ROOT`,
`RUN_LOCAL_STAGE_MANIFEST`, `RUN_RUNNER_BINARY_MODE`, or deleted shell wrapper
entrypoints. Those names are not part of the current active contract unless
reintroduced explicitly in sections 2-5.

## 2. Product Goal

The desired end-state is:

- one canonical root-`Makefile` entrypoint family
- one target/suite contract
- one manifest-driven bundle path
- one public local-prep entrypoint
- two executors only:
  - `kvm`
  - `aws-ssh`

The concrete supported targets are:

- `x86-kvm`
- `aws-x86`
- `aws-arm64`

The concrete suites are:

- `test`
- `micro`
- `corpus`
- `e2e`

The user-facing entrypoints remain:

- `make vm-test`
- `make vm-micro`
- `make vm-corpus`
- `make vm-e2e`
- `make aws-arm64-test`
- `make aws-arm64-benchmark`
- `make aws-arm64-terminate`
- `make aws-x86-test`
- `make aws-x86-benchmark`
- `make aws-x86-terminate`

These aliases must stay thin.

The static Python regression gate is intentionally minimal now. The kept
contract tests are only:

- `tests/python/test_run_contract.py`
- `tests/python/test_prepare_local_inputs.py`
- `tests/python/test_build_remote_bundle.py`
- `tests/python/test_runtime_file_signatures.py`
- `tests/python/test_workload_api.py`

The previous mock-heavy and case-specific Python tests were deleted on purpose.
The repo should add tests back only when a concrete bug justifies new coverage.

As of the current cleanup pass, `tests/python/` contains only:

- `conftest.py`
- `test_run_contract.py`
- `test_prepare_local_inputs.py`
- `test_build_remote_bundle.py`
- `test_runtime_file_signatures.py`
- `test_workload_api.py`

## 3. Design Summary

### 3.1 Four-layer boundary

The runner should have exactly four layers:

- `target`
  - describes machine capability and execution mode only
  - examples: `x86-kvm`, `aws-x86`, `aws-arm64`
- `suite`
  - describes what a run needs, not where it runs
  - examples: `test`, `micro`, `corpus`, `e2e`
- `local prep`
  - prepares suite-input repos, artifacts, bundles, and staged workspaces
  - is the only public suite-input prep phase
- `executor`
  - only executes an already prepared run
  - `runner.libs.kvm_executor` for local VM execution
  - `runner.libs.aws_executor` for AWS lifecycle, SSH execution, and result fetch

Any logic that mixes these layers is considered design debt.

For AWS, one extra internal step exists before local prep:

- remote preflight / remote prep
  - launches or reuses the instance
  - reconciles machine-global remote state such as kernel and remote prereqs
  - may build host-side machine-setup artifacts needed for that reconciliation
  - must hand off any resolved remote state to local prep explicitly

### 3.2 Canonical control flow

The canonical flow is:

- root `Makefile` thin alias
- `python -m runner.libs.run_target_suite`
- internal AWS-only remote preflight when `RUN_EXECUTOR=aws-ssh`:
  - `runner.libs.aws_remote_prep`
- `runner.libs.prepare_local_inputs`
- executor:
  - `runner.libs.kvm_executor`
  - `runner.libs.aws_executor`
- shared remote/local suite runtime:
  - `runner.libs.execute_workspace`
  - `runner.libs.guest_prereqs`
  - `runner.libs.suite_entrypoint`

`runner.libs.prepare_local_inputs` is the only public local-prep entrypoint.
Executors must not expose their own separate public local-prep control plane.

### 3.3 Current cleanup status

As of the current refactor pass:

- `runner/scripts/` contains no active `.sh` control-plane scripts
- `runner/Makefile` has been deleted; the active path no longer uses
  `make -C runner`
- the old AWS shell helper layer has been deleted
- KVM and AWS local prep now share one public Python entrypoint:
  - `runner.libs.prepare_local_inputs`
- only two static regression tests remain intentionally:
  - `tests/python/test_run_contract.py`
  - `tests/python/test_prepare_local_inputs.py`
- current static gates are:
  - `python3 -m compileall -q runner/libs runner/scripts tests/python e2e daemon docs/paper/helpers`
  - `python3 -m pyflakes runner/libs runner/scripts tests/python e2e docs/paper/helpers`
  - `python3 -m pytest -q tests/python`
  - `git diff --check`
- remaining shell usage in active paths is limited to:
  - root `Makefile` shell execution
  - VM guest script materialization inside `runner.libs.vm`
  - third-party or app-specific fixture/setup scripts

Historical log entries later in this document may still mention deleted shell
helpers. Those entries are chronology only and do not reflect the active tree.

### 3.4 KVM / AWS parity rule

KVM and AWS should not have different product-level prep or suite logic.

They should share:

- the same target/suite manifest model
- the same public local-prep entrypoint
- the same staged-input / bundle-input contract
- the same Python suite orchestrator inside the staged workspace

They may differ only in executor transport and machine lifecycle:

- `runner.libs.kvm_executor`
- `runner.libs.aws_executor`

If KVM and AWS require different runtime assets, those assets must still be
expressed through the same local-prep contract shape rather than separate
public prep flows.

### 3.5 Shared `corpus` / `e2e` contract

`corpus` and `e2e` should share as much of the contract as possible:

- same prerequisite model
- same bundle/staging model
- same runtime environment model
- same app setup contract
- same result/artifact structure shape

They should differ only in:

- workload triggering
- measurement method
- case selection
- result aggregation

If a bug affects paths, tools, setup, staged artifacts, remote env, or app
setup, it should be fixed in the shared contract instead of by suite-specific
branching.

### 3.6 Parallel execution policy

The intended policy is:

- local KVM execution is serialized
- AWS runs may execute in parallel
- AWS benchmark runs must use:
  - dedicated per-run instances
  - dedicated per-run prep roots
  - dedicated per-run remote stage/work directories
- shared host resources may still use explicit locks
- no benchmark lane may depend on another benchmark lane's prep root, bundle,
  or remote workspace

This means "AWS may run in parallel" is a design requirement, but the way to
achieve it is explicit per-run isolation, not ambient shared cache behavior.

Canonical AWS target profiles may keep portable defaults such as region,
instance type, and remote stage paths, but they must not hard-code one
developer's key/profile/network configuration. The following must come from
explicit env or a non-versioned local config layer:

- `*_KEY_NAME`
- `*_KEY_PATH`
- `*_SECURITY_GROUP_ID`
- `*_SUBNET_ID`
- `*_PROFILE`

### 3.7 Prohibited design patterns

The following are explicitly disallowed:

- patching third-party source trees
- keeping two control planes for one target/suite pair
- large monolithic helper stacks that merely shuttle env around
- hidden fallbacks when required artifacts are missing
- bundle assembly that guesses inputs from stale cache layout
- machine-global writes for benchmark assets on remote hosts
- duplicate canonical results such as `latest.json` / `authoritative.json`
- bundle sealing that depends on the caller shell's ambient `LD_LIBRARY_PATH`

## 4. Non-Goals

Out of scope:

- local ARM64 QEMU as a product path
- patching third-party source trees
- duplicate result mirrors such as `latest.json` or `authoritative.json`
- a large orchestration framework with many helper layers
- dynamic fallback behavior when a required artifact or dependency is missing

## 5. Current Refactor State

### 5.1 Current in-tree contract files

The refactor now centers on:

- `runner/targets/aws-arm64.env`
- `runner/targets/aws-x86.env`
- `runner/targets/x86-kvm.env`
- `runner/suites/test.env`
- `runner/suites/micro.env`
- `runner/suites/corpus.env`
- `runner/suites/e2e.env`
- `runner/libs/run_contract.py`
- `runner/libs/run_target_suite.py`
- `runner/libs/prepare_local_inputs.py`
- `runner/libs/local_prep_common.py`
- `runner/libs/kvm_local_prep.py`
- `runner/libs/aws_local_prep.py`
- `runner/libs/aws_remote_prep.py`
- `runner/libs/aws_common.py`
- `runner/libs/kvm_executor.py`
- `runner/libs/aws_executor.py`
- `runner/libs/build_remote_bundle.py`
- `runner/libs/build_upstream_selftests.py`
- `runner/libs/arm64_host_build.py`
- `runner/libs/cli_support.py`
- `runner/libs/portable_runtime.py`
- `runner/libs/aws_remote_prereqs.py`
- `runner/libs/aws_kernel_artifacts.py`
- `runner/libs/arm64_container_build.py`
- `runner/libs/arm64_sysroot.py`
- `runner/libs/arm64_kernel_config.py`
- `runner/scripts/vng-wrapper.py`
- `runner/libs/state_file.py`
- `runner/libs/prereq_contract.py`
- `runner/libs/guest_prereqs.py`
- `runner/libs/execute_workspace.py`
- `runner/libs/suite_entrypoint.py`

For canonical local x86 execution, the manifest now carries explicit VM
execution fields instead of translating back to legacy machine profile names:

- `RUN_VM_BACKEND`
- `RUN_VM_EXECUTABLE`
- `RUN_VM_LOCK_SCOPE`
- `RUN_VM_MACHINE_NAME`
- `RUN_VM_MACHINE_ARCH`
- `RUN_VM_CPUS`
- `RUN_VM_MEM`

For canonical AWS execution, the manifest now also carries the resolved launch
contract instead of making the executor branch on target names:

- `RUN_AWS_KEY_NAME`
- `RUN_AWS_KEY_PATH`
- `RUN_AWS_SECURITY_GROUP_ID`
- `RUN_AWS_SUBNET_ID`
- `RUN_AWS_INSTANCE_MODE`

Run identity is also now explicit in the manifest:

- `RUN_TOKEN`

Historical engineering review/execution docs under `docs/tmp/` may still
exist, but they are archival only. This file is the canonical current design
and todo source of truth.

Host-side prep handoff is no longer `stdout` shell assignments. Canonical
remote-prep/local-prep state now moves through explicit JSON state files
written by `runner/libs/state_file.py`.

Local-prep suite phase ordering is also no longer owned by shell callback
graphs. `runner/libs/prepare_local_inputs.py` computes the phase list and
invokes `init`, per-phase primitive prep functions, and `finalize`
sequentially from Python; the target shell libraries no longer own the phase
graph.

### 5.2 Current local-prep and executor split

Current intended state:

- `runner.libs.prepare_local_inputs` is the single public local-prep entrypoint
- `runner.libs.run_target_suite` is now the canonical host-side suite entrypoint
- `runner.libs.aws_common` is the single shared AWS state/SSH/instance helper plane
- AWS remote preflight is a separate internal step:
  - `runner/libs/aws_remote_prep.py`
- Python-owned bundle assembly now lives in:
  - `runner/libs/build_remote_bundle.py`
- shared Python local-prep helpers now live in:
  - `runner/libs/local_prep_common.py`
- KVM local-prep now lives in:
  - `runner/libs/kvm_local_prep.py`
- AWS local-prep now lives in:
  - `runner/libs/aws_local_prep.py`
- shared runner error/require helpers now live in:
  - `runner/libs/cli_support.py`
- `runner.libs.kvm_executor` consumes only staged KVM state
- `runner.libs.aws_executor` consumes prepared state and handles only:
  - remote execution
  - result fetch
- suite orchestration now lives primarily in Python:
  - `runner/libs/execute_workspace.py`
  - `runner/libs/suite_entrypoint.py`
  - `runner/libs/guest_prereqs.py`

Current intended staged-input rule:

- both KVM and AWS local prep may use per-run local prep roots internally
- `runner.libs.build_remote_bundle` must not derive staged inputs from a
  promote-root
  convention
- bundle-input files now carry explicit bundle input paths for:
  - repos
  - runtime binaries
  - test artifacts
  - native repo build roots
  - SCX binary/object roots
  - workload-tool roots
  - module dirs
  - micro generated-program dirs
- `RUN_LOCAL_PROMOTE_ROOT` is no longer part of the active bundle contract

Current canonical AWS control flow is now:

- `python -m runner.libs.run_target_suite`
- `python -m runner.libs.aws_remote_prep`
  - may launch/reuse instance
  - may install kernel / prereqs
  - may update cached AWS state
  - emits an explicit remote-prep state handoff for local prep
- `python -m runner.libs.prepare_local_inputs`
  - local-only
  - no AWS remote mutations
  - consumes the explicit remote-prep state file handoff passed by
    `runner.libs.run_target_suite` instead of re-reading hidden shared AWS state
- `python -m runner.libs.aws_executor run`
  - consumes existing AWS state plus local bundle state
  - does not call `ensure_instance_for_suite`
  - only uploads, runs, fetches, and terminates dedicated instances when needed
  - unpacks the sealed workspace and then follows the same guest entry sequence
    as KVM:
    - `python -m runner.libs.execute_workspace`

What is still incomplete:

- KVM and AWS still use separate target-specific local-prep modules:
  - `runner/libs/kvm_local_prep.py`
  - `runner/libs/aws_local_prep.py`
  They share phase ordering, bundle sealing, and many build helpers, but not a
  single implementation yet.
- host-side ARM sysroot, host-cross, container-cross, and kernel-config helpers
  live in Python, but the benchmark path still retains a smaller ARM container /
  qemu surface:
  - `runner/libs/arm64_sysroot.py`
  - `runner/libs/arm64_host_build.py`
  - `runner/libs/arm64_container_build.py`
  - `runner/libs/arm64_kernel_config.py`
- canonical manifest resolution is still broader than ideal:
  - `runner/libs/run_contract.py` still resolves many knobs directly from caller
    env instead of a narrower explicit input schema
- guest-side prereq installation, validation, and suite orchestration live in
  Python:
  - `runner/libs/execute_workspace.py`
  - `runner/libs/guest_prereqs.py`
  - `runner/libs/prereq_contract.py`
  - `runner/libs/suite_entrypoint.py`
  Canonical guest execution now enters Python directly through
  `runner.libs.execute_workspace`.
- AWS remote prereq preparation is now base-only machine preparation:
  - `runner/libs/aws_remote_prereqs.py`
  - it no longer performs per-run runtime workload-tool installation or
    executor-side runtime manifest mutation
  - it currently still requires a bootstrap `python3` or `python` to exist on
    the remote host
  - guest-side prereq validation still re-runs inside
    `runner.libs.execute_workspace` before suite execution
- repo selection is now explicit:
  - the old manifest field `RUN_BENCHMARK_REPOS_CSV` is no longer part of the
    active contract
  - `RUN_BUNDLED_REPOS_CSV` defines which repos must be sealed into the bundle
  - `RUN_FETCH_REPOS_CSV` defines the full local fetch set needed before
    bundle/native-build prep begins
- KVM now participates in the same explicit workload-tool bundle contract as
  AWS x86:
  - local prep materializes bundled tools under a local tool root
  - bundle inputs write both `RUN_BUNDLED_WORKLOAD_TOOLS_CSV` and
    `RUN_LOCAL_WORKLOAD_TOOL_ROOT`
  - the bundle manifest now carries the workspace-local runtime tool bin:
    `RUN_REMOTE_WORKLOAD_TOOL_BIN`
  - guest prereq install and guest prereq validation now recognize bundled
    workload tools before falling back to guest package installation
- AWS executor no longer appends workload-tool paths into `run-contract.env`
  during execution; the workspace-local tool contract is now sealed during
  bundle creation
- KVM and AWS now stage the same micro sidecar shape (`*.directive.bin` /
  `*.policy.bin`) during local prep
- ARM host-cross now covers more of canonical runtime prep:
  - `runner.libs.arm64_host_build`
  - `runner.libs.portable_runtime`
  - canonical ARM runtime prep should only fall back to `__cross-arm64` when
    `llvmbpf` or repo-specific benchmark builds still require an ARM userspace
- the deleted shell layers in this pass were:
  - all previously active `runner/scripts/*.sh` control-plane helpers
  - all previously active AWS shell wrapper/manifest/bundle/prereq/suite
    helpers
- upstream selftests no longer depend on repo-owned compat headers or stub
  skeletons; exclusions now live only in the tracked selection manifest
  `runner/config/upstream_selftests_selection.tsv`
- canonical guest execution no longer relies on separate shell wrappers for
  prereq install, prereq validation, and suite entry:
  - `runner/libs/execute_workspace.py` loads `run-contract.env`, installs and
    validates guest prereqs, then dispatches into `runner/libs/suite_entrypoint.py`
- the sealed workload-tool runtime contract is now:
  - `RUN_BUNDLED_WORKLOAD_TOOLS_CSV`
  - `RUN_REMOTE_WORKLOAD_TOOL_BIN`
  `RUN_REMOTE_WORKLOAD_TOOL_ROOT` is no longer part of the active contract

### 5.3 ARM kernel config split

ARM kernel config now has:

- one shared repo-owned fragment:
  - `runner/scripts/arm64_kernel_config_common.sh`
- one local-QEMU-specific script:
  - `runner/scripts/arm64-kernel-config.sh`
- one AWS-specific script:
  - `runner/scripts/aws_arm64_kernel_config.sh`

This removes the duplicated repo-required BPF/tracing option block.

### 5.4 Root `Makefile` state

The root `Makefile` now routes the main suite targets through the new contract:

- `vm-test` -> `python -m runner.libs.run_target_suite run x86-kvm test`
- `vm-micro` -> `python -m runner.libs.run_target_suite run x86-kvm micro`
- `vm-corpus` -> `python -m runner.libs.run_target_suite run x86-kvm corpus`
- `vm-e2e` -> `python -m runner.libs.run_target_suite run x86-kvm e2e`
- `aws-arm64-test` -> `python -m runner.libs.run_target_suite run aws-arm64 test`
- `aws-arm64-benchmark` -> `python -m runner.libs.run_target_suite benchmark aws-arm64 <mode>`
- `aws-arm64-terminate` -> `python -m runner.libs.run_target_suite terminate aws-arm64`
- `aws-x86-test` -> `python -m runner.libs.run_target_suite run aws-x86 test`
- `aws-x86-benchmark` -> `python -m runner.libs.run_target_suite benchmark aws-x86 <mode>`
- `aws-x86-terminate` -> `python -m runner.libs.run_target_suite terminate aws-x86`

The `all` benchmark fanout no longer lives in the root `Makefile`. It now
lives inside `runner.libs.run_target_suite benchmark ...`, so the root aliases stay
thin and `make -n` remains purely static.

The root `Makefile` no longer carries AWS wrapper env blocks such as
`AWS_ARM64_RUN_ENV` / `AWS_X86_RUN_ENV`. Canonical AWS targets now call
`runner.libs.run_target_suite` directly, so `runner/libs/run_contract.py` is the only place
that resolves target-prefixed AWS inputs.

The root `Makefile` has also been thinned further on the developer-build side:

- the old internal `__build-*`, `__corpus-*`, `__daemon-tests`, `__python-tests`,
  and `__smoke` target graph is gone
- `check` now calls runner build/test steps, Python tests, and smoke directly
- canonical `vm-*` / `aws-*` aliases remain thin wrappers over
  `runner.libs.run_target_suite`
- raw kernel/module helper targets are now internal-only (`__kernel*`,
  `__kernel-arm64*`, `__kinsn-modules`, `__virtme-hostfs-modules`,
  `__arm64-worktree`) and are no longer part of the public root surface

What still remains as intentional root-level build/control surface is:

- the canonical suite aliases (`vm-*`, `aws-*`)
- final validation entrypoints (`check`, `validate`)

The canonical run manifest is immutable at creation time for target/suite
contract fields. Executor-local staging paths are not part of the contract.

For canonical local KVM execution, `runner.libs.prepare_local_inputs` now follows the
same local-state handoff shape as AWS local prep: it seals a bundle tar and
writes only this local execution pointer into a run-local sidecar state file
consumed by `runner.libs.run_target_suite`:

- `RUN_BUNDLE_TAR`

The canonical run manifest itself no longer carries those executor scratch
fields. This keeps the target/suite contract stable while letting the KVM
executor untar the same kind of staged workspace that AWS consumes.

AWS launch parameters now also follow the same rule:

- the manifest carries the resolved SSH/AWS launch contract
- `runner.libs.aws_executor` no longer falls back to cached key/subnet/security-group state
- target-specific AMI overrides must be represented in the manifest, not through
  a generic ambient `AWS_AMI_ID`
- guest-side Python selection is part of the manifest contract; executors do not
  inject `PYTHON_BIN` out-of-band
- AWS region/account selection is part of the manifest contract through
  `RUN_AWS_REGION` and `RUN_AWS_PROFILE`, with target-prefixed
  `AWS_ARM64_REGION` / `AWS_ARM64_PROFILE` and `AWS_X86_REGION` /
  `AWS_X86_PROFILE` as the only canonical inputs

Local bundle assembly now follows the same explicit pattern:

- local prep writes a local-only `bundle-inputs.json`
- `runner.libs.build_remote_bundle` consumes:
  - the run manifest
  - the bundle-input state file
- bundle construction no longer depends on:
  - executor-specific ambient env injection
  - `RUN_LOCAL_PROMOTE_ROOT`-anchored path guessing

### 5.5 Deleted legacy AWS control scripts

The old AWS monoliths and ARM64-specific helper chain have been deleted:

- `runner/scripts/aws_arm64.sh`
- `runner/scripts/aws_x86.sh`
- `runner/scripts/aws_arm64_bundle.sh`
- `runner/scripts/aws_arm64_manifest.sh`
- `runner/scripts/aws_arm64_remote_prereqs.sh`
- `runner/scripts/aws_arm64_remote_suite.sh`

### 5.6 Machine config cleanup

The legacy machine-table layer has been removed completely:

- `runner/machines.yaml` is deleted
- `runner/libs/machines.py` is deleted
- `runner/scripts/run_vm_shell.py` no longer accepts `--target`
- `runner/scripts/with_vm_lock.py` no longer resolves target aliases

The canonical `x86-kvm` path now carries its full machine contract directly in
the manifest:

- backend
- executable
- lock scope
- machine name
- machine arch
- cpu/memory sizing
- host Python launcher
- guest kernel image path
- suite timeout
- test-only knobs such as `FUZZ_ROUNDS` and `scx_prog_show_race_*`

`runner.libs.kvm_executor` passes that explicit contract into
`runner/scripts/run_vm_shell.py`.

`runner/Makefile` no longer exposes the old direct VM entrypoints at all:

- `vm-shell`
- `vm-selftest`
- `vm-negative-test`
- `vm-micro-smoke`

The root `Makefile` also no longer exposes local ARM QEMU execution targets:

- `vm-arm64-smoke`
- `vm-arm64-selftest`

Canonical KVM suite execution now performs guest-side prereq installation,
validation, and suite dispatch through one shared workspace launcher:

- `runner.libs.execute_workspace`

## 5. Hard Constraints

These rules are now mandatory:

- Do not patch third-party source trees:
  - `vendor/linux-framework/**`
  - `runner/repos/**`
- Do not keep multiple control paths for the same target/suite pair.
- Do not silently fall back to a different artifact or environment shape.
- Do not let stale `.cache` contents leak into bundles outside the manifest-selected artifact set.
- Do not write bundled benchmark assets into machine-global locations on the remote host.
- Only local KVM suite execution is serialized.
- AWS local prep may run in parallel as long as each run stays inside its
  per-run prep root and truly shared host resources keep explicit locks.
- AWS benchmark runs must use dedicated per-run instances and dedicated remote
  workspaces. Do not reuse one cached benchmark instance across multiple runs.
- Local prep/build work may run in parallel for AWS runs as long as each run
  stays inside its own prep root and explicitly shared host resources remain
  under lock.
- Do not let cached AWS instance metadata act as a fallback control plane for
  required launch parameters.
- Do not proactively close reviewer subagents just because they are slow.
  Reviewer agents should be allowed to run longer unless the user explicitly
  asks to stop them or they have already produced a final result.
- For full-project review passes, do not reduce scope just because the reviewer is taking longer than expected.
  The default behavior is to wait longer and preserve full context.

## 6. Problems Already Removed

The refactor has already removed these specific problems:

- AWS-specific suite policy living in a giant target-specific script
- separate AWS ARM64 bundle/prereq/remote-suite helper chain
- root `Makefile` dependence on positional `INSTANCE_IP` / `INSTANCE_ID`
- direct third-party source patching for Katran and upstream selftests
- duplicated ARM repo-required kernel config block
- `tetragon` strict bundled mode writing `.bpf.o` payloads into `/usr/local/lib/tetragon/bpf`
- the entire `runner/machines.yaml` / `runner.libs.machines` compatibility layer
- executor-specific suite logic split between KVM `vm-*` targets and AWS remote script entrypoints
- `runner/Makefile` carrying a second live `vm-test/vm-micro/vm-corpus/vm-e2e` execution plane
- root `validate` bypassing the canonical target/suite layer for VM micro smoke
- remote execution silently falling back from `python3.11` to `python3`
- requested remote workload tools being treated as optional installs
- AWS launch silently reusing cached key/subnet/security-group metadata outside the manifest
- generic ambient `AWS_AMI_ID` overriding the target-selected AMI outside the manifest
- bundle assembly copying the repo-root `module/` tree wholesale
- setup-script split between repo-managed artifact mode and fallback local-build mode for BCC / Tracee / Tetragon
- AWS remote prereqs acting as an x86 workload-tool source-build plane for
  `wrk`, `sysbench`, or `hackbench`; remote prereqs now allow only bundled
  tools or package-manager-installed tools
- bundle assembly copying repo-owned source trees with broad directory copies instead of tracked-only snapshots
- Tracee runner picking up ambient `corpus/build/tracee` state before running setup
- Katran native staging picking up ambient `e2e/cases/katran/{bin,lib}` state without an explicit caller contract
- Tetragon runner picking up ambient `corpus/build/tetragon/bin/tetragon` state without setup or explicit parameters
- upstream selftest compatibility headers / stubs being embedded in the remote execution script
- corpus / case-common silently manufacturing per-program REJIT records when the daemon result omitted them
- ARM64 daemon builds happening inside the `linux/arm64` Docker/qemu path;
  the daemon is now host-cross-built first and consumed as an explicit input by
  both `cross-arm64` and `arm64-test-artifacts`
- ARM64 `scx` userspace builds happening inside the `linux/arm64` Docker/qemu
  path; `scx_rusty` now has a tracked-only host-cross path driven by a
  repo-local ARM64 sysroot
- the repo-local ARM64 sysroot cache being rebuilt without any lock; sysroot
  population is now serialized with an explicit lock file
- full `test` mode over-declaring the same local prep for `selftest`,
  `negative`, and `test`; canonical manifests and bundle assembly now split
  those three modes cleanly
- `selftest` / `negative` test bundles carrying full upstream-selftests build
  inputs even when upstream tests were not part of the requested mode; those
  assets are now bundled only for full `test`
- `arm64-test-artifacts` always rebuilding the ARM64 Docker/qemu image even
  for `selftest` or `negative`; those modes now stay entirely on the host-cross
  path and only full `test` still enters the upstream-selftest container path
- canonical KVM prep scraping live repo-root outputs for x86 unittest,
  negative, upstream-selftests, kinsn modules, micro programs, and `scx`;
  those inputs are now built or promoted into per-run prep roots before the
  staged workspace snapshot is assembled
- stale `micro/programs/*.directive.bin` / `*.policy.bin` sidecars surviving
  `clean` and leaking into later runs; the micro clean target now removes them,
  and staging now only copies sidecars that match the newly built `.bpf.o`
  set
- guest Python module install assuming `python -m pip` already exists on the
  guest; guest prereq setup now bootstraps `pip` with `ensurepip` before
  installing required Python modules
- dead `runner/Makefile e2e-prep` continuing to exist beside the canonical
  target/suite path; that compatibility target is now removed

## 7. Remaining Design Gaps

The refactor is not finished yet.

### 7.1 Shared AWS helper code is now structurally split

The new shape is materially better than the deleted monoliths. Current state:

- `runner.libs.aws_executor` now owns only:
  - remote execution
  - result fetch
  - dedicated/shared AWS run coordination
- `aws_common_lib.sh` owns:
  - AWS lifecycle
  - state management
  - remote prereq verification/setup
- `aws_prep_paths_lib.sh` owns:
  - AWS host-prep/build path defaults
- `aws_kernel_artifacts_lib.sh` owns:
  - AWS host-side kernel/cache/build helpers
- `runner.libs.aws_remote_prep` owns:
  - AWS remote-prep-only instance/setup reconciliation
- `runner.libs.aws_local_prep` now owns:
  - AWS local artifact preparation
  - AWS bundle-input planning
  - AWS workspace bundle assembly

`aws_common_lib.sh` is no longer carrying host-prep/build helpers or suite
policy. It is still a relatively large shared control-plane library, but that
is now an implementation-size concern rather than a structural blocker. Further
splitting should happen only if a new concrete boundary emerges.

### 7.2 Third-party source handling is now explicit and tracked

Tracked third-party trees are no longer patched and active runner code no
longer relies on repo-owned compat headers or stub skeletons for upstream
selftests.

The remaining source-side handling is now limited to:

- `runner/libs/build_upstream_selftests.py`
  - reads a tracked selection manifest at
    `runner/config/upstream_selftests_selection.tsv`
  - the manifest explicitly records canonical build targets and source-level
    exclusions with reasons
  - every declared source exclusion must still exist in the vendored upstream
    tree or the build fails fast
  - upstream still owns its own `SKEL_BLACKLIST`; the repo contract does not
    shadow or override it
  - the build still uses a filtered local copy when selected upstream sources
    must be excluded from the build, but selection is now explicit and
    auditable instead of being embedded as shell defaults
- `runner/scripts/build_corpus_native.py`
  - still sanitizes a build-local generated `vmlinux.h` when cached declarations
    collide with third-party build inputs

This keeps the contract at explicit build selection plus generated-header
sanitation only; there is no accepted repo-owned third-party compat layer in
the active runner path.

### 7.3 ARM host/cross toolchain contracts are now explicit

Active ARM build paths no longer hide tool or sysroot behavior through
fallback shims:

- `runner/scripts/cross-arm64-build.sh`
  - requires a real `rustfmt` binary via the same explicit contract used by
    host-cross SCX builds
  - no longer injects a repo-owned fake `rustfmt`
- `runner/scripts/prepare-arm64-sysroot.sh`
  - requires an explicit remote sysroot source
  - no longer exposes a cache-only bypass for canonical or debug flows

### 7.4 KVM and AWS now share one explicit staged-input contract

KVM now executes from a staged workspace snapshot instead of the live repo
checkout. That removes the biggest control-plane split and fixes the manifest
lifetime issue.

The staged-input shape is now:

- local prep may use per-run prep roots internally
- `runner.libs.build_remote_bundle` consumes only explicit bundle-input paths
- KVM and AWS write the same kind of bundle-input file instead of relying on
  a promote-root convention
- the active contract no longer uses `RUN_LOCAL_PROMOTE_ROOT`

What still needs review is whether any remaining duplicated bundle input can be
shared through a smaller repo-owned helper without reintroducing hidden path
derivation.

### 7.4 Guest prerequisite execution is now Python-shared

The command/package/python-import policy now lives in one Python place:

- `runner/libs/prereq_contract.py`

The remaining shell bootstrap layer is now limited to internal SSH/bootstrap
primitives under `runner/scripts/aws_common_lib.sh`; the active public guest
execution and remote-prereq entrypoints are Python-owned:

- `runner.libs.execute_workspace`
- `runner.libs.aws_remote_prereqs`

That remaining transport shell is acceptable for now, but it must stay thin
and must not reintroduce duplicated tool/package policy or remote source-build
fallbacks for tools that belong in the local-prep/bundle contract.

### 7.5 Latest review findings still being closed

The latest full-project reviewers highlighted these remaining issues:

- AWS ARM64 `test` no longer uses Docker/qemu for repo-owned unittest /
  negative binaries, but it still relies on a native remote build for upstream
  selftests
- `micro_exec` is still on the ARM64 Docker/qemu path
- same-target shared correctness execution still uses a shared cached instance,
  so only the remote execution step is serialized there
- upstream selftests filtering should keep shrinking as vendored inputs catch
  up, but there should be no repo-owned compat assets left in active code

These are being actively fixed before the ordered validation pass is declared
complete.

### 7.6 Remaining qemu-only work is now narrower

The ARM64 Docker/qemu path is no longer the default place to build every ARM
artifact.

What has moved out of qemu already:

- the repo-owned ARM64 daemon (`bpfrejit-daemon`)
- daemon-only portable runtime bundling for canonical ARM64 `test/corpus/e2e`
  local prep
- `scx` userspace artifacts (`scx_rusty` host-cross path validated)
- repo-owned ARM64 unittest / negative binaries

What still remains in the ARM64 Docker/qemu path today:

- `micro_exec`
- ARM64 native benchmark repo builds (`bcc`, `katran`, `tracee`, `tetragon`)

The current host-cross shape for `scx` is:

- tracked-only staging from `runner/repos/scx` using `git archive`
  - this avoids copying stale `target/` output and `.git`
  - it also removes the disk blow-up that happened when the first host helper
    copied the full checkout, including a multi-GB `target/` tree
- a repo-local ARM64 sysroot prepared by:
  - `runner/scripts/prepare-arm64-sysroot.sh`
- host-side `cargo build --target aarch64-unknown-linux-gnu`
  driven by:
  - `runner/scripts/build-arm64-scx-host.sh`
- cross-friendly runtime library bundling
  - the first host version incorrectly tried to use host `ldd` on an ARM64
    binary and got `not a dynamic executable`
  - the current version uses `aarch64-linux-gnu-readelf` plus the repo-local
    sysroot / cross toolchain paths to resolve `NEEDED` libraries explicitly

This path has been validated through the canonical target:

- `make cross-arm64-scx ARM64_CROSSBUILD_SCX_PACKAGES=scx_rusty ...`
  now succeeds on the x86 host
- it produces:
  - `runner/repos/scx/target/release/scx_rusty` in the promoted output tree
  - `corpus/build/scx/scx_rusty_main.bpf.o`
  - bundled ARM64 runtime libraries (`libelf.so.1`, `libz.so.1`,
    `libgcc_s.so.1`, plus transitive `libzstd.so.1`)

So the remaining qemu-only work is now narrower still:

- `micro_exec`
- ARM64 native benchmark repo builds (`bcc`, `katran`, `tracee`, `tetragon`)

For ARM64 upstream selftests themselves, the canonical `aws-arm64 test` path
now builds and bundles them during local prep using the repo-owned
`runner/scripts/build_upstream_selftests.sh` contract. The remote suite only
validates and executes the bundled `test_verifier` and `test_progs` outputs.
That avoids patching upstream sources, avoids any repo-owned compat layer, and
keeps the remote side on pure execution.

## 8. Tetragon Contract Change

`tetragon` strict bundled mode no longer installs `.bpf.o` files into `/usr/local/lib/tetragon/bpf`.

The new contract is:

- `e2e/cases/tetragon/setup.sh` resolves a bundled BPF directory
- it reports `TETRAGON_BPF_LIB_DIR=...`
- `runner/libs/app_runners/tetragon_support.py` parses that field
- `runner/libs/app_runners/tetragon.py` adds `--bpf-lib <dir>` when starting Tetragon

This keeps Tetragon on workspace-local assets.

## 9. Ordered Todo List

This is the required order from this point onward.

### 9.1 Finish refactor cleanup

1. Static-check the new shell scripts and any touched Python modules.
2. Verify there are no remaining repo-tracked references to the deleted AWS monoliths in active code paths.
3. Keep deleting remaining legacy entrypoints and bypasses instead of leaving them as debug helpers.
4. Finish collapsing remaining hidden fallbacks and dual control planes:
   - KVM staged-only execution
   - suite-specific runtime binary requirements
   - AWS running-instance launch-contract validation
   - KVM promoted-artifact staging
5. Review the new `aws_executor.sh` / `build_remote_bundle.sh` / `suite_entrypoint.py` contract for unnecessary coupling.
6. Keep pushing ARM host-cross farther:
   - daemon is already host-cross
   - `scx` is now host-cross
   - repo-owned ARM test binaries are now host-cross too
   - next candidates are `micro_exec`, and then upstream selftests if they can
     be moved without reintroducing toolchain or contract ambiguity

### 9.2 Review before testing

1. Run subagent review on the current refactor shape only.
2. Fix review findings.
3. Do not restart real-path validation until the review findings are closed.

### 9.3 Validation order after review

1. `make vm-test`
2. `make vm-micro`
3. `make vm-corpus`
4. `make vm-e2e`
5. `make aws-arm64-test`
6. `make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=micro`
7. `make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=corpus`
8. `make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=e2e`
9. `make aws-x86-test`
10. `make aws-x86-benchmark AWS_X86_BENCH_MODE=micro`
11. `make aws-x86-benchmark AWS_X86_BENCH_MODE=corpus`
12. `make aws-x86-benchmark AWS_X86_BENCH_MODE=e2e`

Local KVM suite execution remains serialized. AWS benchmark execution is now
intentionally parallel-safe because each benchmark run gets its own dedicated
instance and dedicated remote workspace; any remaining serialization should be
limited to explicit shared host resources such as per-arch kernel or sysroot
locks during local prep.

### 9.4 Immediate next todo

1. Keep the document current after each newly observed blocker or milestone.
2. Keep the bundle-input contract explicit and auditable:
   - no `RUN_LOCAL_PROMOTE_ROOT`-anchored path guessing in
     `runner.libs.build_remote_bundle`
   - no hidden path reconstruction from cache layout
   - only explicit bundle input paths written by local prep
   - repo selection must stay explicit:
     - `RUN_BUNDLED_REPOS_CSV` for repos sealed into the bundle
     - `RUN_FETCH_REPOS_CSV` for the local fetch set
   - workload-tool selection must stay explicit:
     - `RUN_BUNDLED_WORKLOAD_TOOLS_CSV`
     - `RUN_LOCAL_WORKLOAD_TOOL_ROOT`
3. Keep `runner.libs.prepare_local_inputs` as the only public local-prep entrypoint and
   prevent any drift back toward executor-owned prep logic.
4. Keep the active control plane Python-only:
   - `runner/scripts/` must stay free of `.sh` control-plane code
   - do not reintroduce shell wrapper libraries for AWS or KVM orchestration
   - if shell remains in an active path, it must be third-party/app-specific or
     VM guest fixture logic rather than runner control plane
5. Keep upstream selftests build selection explicit and auditable:
   - no repo-owned compat headers
   - no stub skeleton headers
   - no patches to vendor trees
   - no `runner/compat/**` directory in active code
   - all source-level exclusions must live in
     `runner/config/upstream_selftests_selection.tsv` with reasons
   - selection parsing and selected-source-tree staging must stay in
     `runner/libs/build_upstream_selftests.py`, not in script-local shell state
   - every declared source exclusion must fail fast if it no longer exists in
     the vendored upstream tree
   - the canonical LLVM tool suffix contract must flow from the manifest into
     both x86 and ARM upstream-selftests builds
6. Remove stale historical language in this document that still reflects
   deleted shell helpers or intermediate refactor states rather than the
   current structure.
7. Keep replacing hidden env handoffs with explicit manifest/state-file
   handoffs whenever an executor or local-prep step still relies on ambient
   process state.
8. Run full-project static review only after items 2-7 are clean.
9. Do not restart real-path validation until the structural review returns
   `No findings`.

### 9.5 Current active todo and review gate

This subsection is the authoritative current gate. Historical entries later in
the document are retained as chronology, but this block overrides any stale
intermediate status below.

Current review-and-runtime gate:

- whole-tree static review continues in parallel with the fresh runtime lanes
  already in flight for:
  - `x86-kvm corpus`
  - `aws-x86 corpus`
  - `aws-x86 e2e`
  - `aws-arm64 corpus`
  - `aws-arm64 e2e`
- new code changes during this phase may only:
  - fix a fresh blocker from one of those lanes
  - remove stale control planes / fallback paths / dead code
- no new compat layers, hidden fallbacks, or third-party source patches may be
  introduced while closing the remaining findings

Current structural status:

- `runner/scripts/` no longer contains any `.sh` control-plane scripts
- `runner/Makefile` is deleted from the active control plane
- `module/load_all.sh` has been deleted from the active path; kinsn module
  loading now goes through `runner.libs.kinsn`
- KVM and AWS local-prep phase dispatch / bundle finalization now share Python
  helpers in `runner.libs.local_prep_common`
- active runner code no longer depends on root `Makefile` internal x86 kernel
  helpers (`__kernel`, `__kinsn-modules`) or ARM AWS kernel helper
  (`__kernel-arm64-aws`)
- x86 KVM kernel / kinsn staging now goes through
  `runner.libs.x86_kernel_artifacts`
- AWS ARM kernel/worktree/config/build now goes directly through
  `runner.libs.aws_kernel_artifacts` + `runner.libs.arm64_kernel_config`
- KVM per-run local prep now uses the same `target-cache/runs/<token>` shape as
  AWS instead of a separate `.cache/kvm-staged/*` layout
- `make -C runner` is no longer part of the active contract
- active Python build paths no longer shell out to deleted `runner/Makefile`
  targets for `micro_exec` / `vendor_bpftool`; those builds now go through the
  shared Python module `runner.libs.runner_artifacts`
- `runner.libs.aws_remote_prep` now imports the shared AWS helper plane as
  `runner.libs.aws_common` directly; the old `aws_executor` alias leak is gone
- active Katran runtime resolution no longer falls back to repo-global
  `corpus/build/katran/{bin,lib}` or caller ambient `LD_LIBRARY_PATH`; sealed
  bundle paths are now mandatory in the active runner path
- tracked repo-owned `.sh` files remain only in archived `docs/tmp/**` notes or
  deleted historical files pending commit; active source files are Python /
  Makefile only

Current ordered todo:

1. Keep local prep as one Python control plane:
   - `runner.libs.prepare_local_inputs` remains the only public local-prep
     entrypoint
   - KVM/AWS phase dispatch and bundle finalization should keep using shared
     Python helpers rather than duplicating orchestration in target-specific
     modules
   - do not reintroduce executor-owned prep side paths
2. Keep the explicit bundle/runtime contract strict:
   - repo selection stays split between `RUN_BUNDLED_REPOS_CSV` and
     `RUN_FETCH_REPOS_CSV`
   - tracked-tree sealing must reject untracked files under active runtime
     trees instead of silently omitting them from bundles
   - workload-tool paths must be explicit whenever `RUN_WORKLOAD_TOOLS_CSV` is
     non-empty; do not rely on hard-coded `.cache/workload-tools/bin` fallbacks
   - KVM/AWS guest/runtime prereq paths must consume the sealed workspace-local
     manifest contract, not executor-side mutation
   - AWS base remote prereqs must stay machine-global only; runtime prereqs must
     not reappear as a second executor-side control plane
   - `run_contract` must consume only explicit process environment plus
     checked-in target/suite files; no `~/.config/...` or extra local env side
     plane is allowed
   - sealed runner trees must explicitly include every active runtime module
     needed by `execute_workspace` and `guest_prereqs`; no live import may rely
     on an untracked file being absent from the bundle
3. Reduce the remaining ARM canonical local-prep qemu/container path:
   - `ARM64 runner` with `MICRO_EXEC_ENABLE_LLVMBPF=OFF` should prefer host-cross
     and portable bundling over the containerized ARM build path
   - keep moving host-crossable ARM work out of `runner.libs.arm64_container_build`
   - keep extending the ARM sysroot contract only where it is needed for
     host-cross support
   - `aws-arm64 micro` must not pull daemon/sysroot/cargo work unless the suite
     contract explicitly needs the daemon
  - ARM Katran dependency prep no longer calls upstream `build_katran.sh`;
     keep the Python `getdeps.py --only-deps` path as the only active dependency
     plane for that build
  - keep closing the remaining x86/arm64 Katran build-source divergence:
    both arches now hand `build_remote_bundle` the same staged runtime contract
    (`RUN_KATRAN_SERVER_BINARY` / `RUN_KATRAN_SERVER_LIB_DIR`) rooted at the
    same sealed workspace path `corpus/build/katran/{bin,lib}`, while
    `corpus/build/katran` still also carries Katran BPF objects; arm64 still
    source-builds that runtime bundle from `runner/repos/katran` while x86
    still seals the checked-in helper bundle, so the sealed-workspace path is
    unified but the build-source split is still a remaining cleanup target
4. Keep upstream selftests on the tracked selection path:
   - selection lives only in `runner/config/upstream_selftests_selection.tsv`
   - no script-local hidden exclusions
   - selection/staging logic lives in `runner/libs/build_upstream_selftests.py`
   - tracked selection now owns:
     - build targets
     - build-view excludes
     - generated `vmlinux.h` excludes
   - `runner.libs.build_upstream_selftests` must emit an auditable
     `selection.json` into the output dir
   - no build helper may silently ignore stale manifest rows
5. Finish one more stale-reference sweep in active code, `README.md`, and this
   document, especially for deleted shell libraries, deleted `runner/Makefile`
   targets, and older shell entrypoint names.
6. Keep root `Makefile` as thin public surface plus developer helpers that
   call the same Python implementation:
   - x86 kernel/module helpers now delegate to
     `runner.libs.x86_kernel_artifacts`
   - ARM64 AWS kernel helper remains developer-only and must not reappear in
     active runner control flow
7. Keep active control-plane helpers consolidated in Python:
   - shared runner failure/path guards now live in `runner/libs/cli_support.py`
   - do not reintroduce per-module `_die` / `_require_path` / `_require_nonempty_dir`
     wrappers in active runner code
   - keep `runner/scripts/` Python-only; remaining shell in active paths is
     limited to:
     - root `Makefile` command execution
     - VM guest script materialization in `runner.libs.vm`
     - third-party or app fixture/setup scripts
8. Re-run whole-tree reviewer passes and fold any remaining structural findings
   back into the tree.
   - latest closed structural/runtime findings include:
     - AWS kernel-build lock recursion no longer self-deadlocks
     - ARM ENA config now keys off `CONFIG_ENA_ETHERNET`
     - AWS ARM `negative` local prep no longer requires upstream selftests
     - ARM build override env vars survive manifest filtering
     - AWS remote-prep now writes explicit sysroot remote-host/user/key state
     - AWS executor and remote-prep now share one Python AWS helper plane:
       `runner.libs.aws_common`
     - `runner.libs.aws_remote_prep` no longer leaks the old
       `aws_executor` alias name into the active Python control plane
     - repo materialization is no longer re-triggered inside SCX/native
       artifact builders; canonical fetch remains in the explicit
       `fetch_repos` prep phase
    - Katran staging now uses one sealed runtime path for both x86 and arm64:
      `RUN_KATRAN_SERVER_BINARY` / `RUN_KATRAN_SERVER_LIB_DIR` resolve inside
      `corpus/build/katran/{bin,lib}` and no longer fall back to repo-global
      runtime trees or ambient library search paths
    - bundle sealing now removes tracked `e2e/cases/katran/bin|lib` before
      staging prepared runtime inputs, so ARM bundles cannot retain stale x86
      Katran helper files through overlay copy
    - active bundle assembly now consumes only the generic
      `RUN_KATRAN_SERVER_*` contract; arch-specific `X86_KATRAN_SERVER_*` /
      `ARM64_KATRAN_SERVER_*` bundle keys are gone
    - ARM Katran dependency prep now runs through Python-owned `getdeps.py`
      invocation instead of upstream `build_katran.sh`
     - active Python build paths no longer call deleted `runner/Makefile`
       targets for `micro_exec` or `vendor_bpftool`
     - Katran runtime resolution no longer falls back to repo-global build
       outputs or ambient `LD_LIBRARY_PATH`
     - ARM host SCX prep no longer hard-requires `rustfmt` or exports
       `RUSTFMT` on build paths that do not use it
     - `runner.libs.aws_remote_prereqs` now reuses
       `runner.libs.run_contract.parse_manifest` and
       `runner.libs.cli_support.fail`; it no longer carries a second manifest
       grammar/error plane
     - dead ARM container knob `ARM64_CROSSBUILD_ENABLE_LLVMBPF` is removed
       from the active local-prep contract
9. Keep root `Makefile` thin:
   - `vm-*` / `aws-*` remain the only public run entrypoints
   - internal `__*` targets remain internal-only
   - `check` stays static-only and `validate` stays `check + vm-test`
10. Do not restart real-path validation until:
   - full-tree static review returns `No findings`, and
   - this document no longer describes deleted shell control planes as current
   - the latest confirmed runtime/build regressions from review have been
     closed:
     - `runner/libs/reporting.py` now imports `statistics`
     - thin wrappers `aws_remote_prep.sh`, `prepare_local_inputs.sh`,
       `run_target_suite.sh`, `kvm_executor.sh`, `aws_executor.sh`,
       `execute_workspace.sh`, `build_upstream_selftests.sh`, and
       `aws_remote_prereqs.sh` are no longer part of the active path
     - dead root `Makefile` targets
       `corpus-build-libbpf-bootstrap`,
       `corpus-build-xdp-tools`, and
       `corpus-build-xdp-tutorial` have been deleted
11. Re-run full static review gates:
   - `python3 -m compileall -q runner/libs runner/scripts tests/python e2e daemon docs/paper/helpers`
   - `python3 -m pyflakes runner/libs runner/scripts tests/python e2e docs/paper/helpers`
   - `python3 -m pytest -q tests/python`
   - `git diff --check`
   - `make -n` on canonical aliases
12. Only after reviewer output is `No findings`:
   - restart real-path validation in the documented matrix order

Current real-path validation state:

- all interrupted `aws-arm64-test`, `aws-x86-test`, and `vm-test` runs were stopped
- no canonical real-path validation process is intentionally left running
- the current static gate is green:
  - `python3 -m compileall -q runner/libs runner/scripts tests/python e2e daemon docs/paper/helpers` passed
  - `python3 -m pyflakes runner/libs runner/scripts tests/python e2e docs/paper/helpers` passed
  - `git diff --check` passed
  - `python3 -m pytest -q tests/python` passed with `14 passed`
  - `make -n aws-arm64-test aws-x86-test aws-arm64-benchmark AWS_ARM64_BENCH_MODE=all aws-x86-benchmark AWS_X86_BENCH_MODE=all vm-test check validate clean` remained pure static thin aliases
  - a full repo grep no longer finds active `make -C ... runner` or `runner/Makefile` references outside archived notes
- latest refactor closures in this gate:
  - host-side benchmark fanout and temp state handling now live in
    `runner/libs/run_target_suite.py`, not shell wrappers
  - host-side local prep and KVM execution now enter directly through:
    - `runner/libs/prepare_local_inputs.py`
    - `runner/libs/kvm_local_prep.py`
    - `runner/libs/kvm_executor.py`
  - repeated active runner `_die` / `require_path` /
    `require_nonempty_dir` helpers are now consolidated in
    `runner/libs/cli_support.py`
  - shared AWS instance/state/SSH helpers now live only in
    `runner/libs/aws_common.py`; `runner.libs.aws_executor` no longer
    carries a second copy
  - canonical KVM/AWS guest execution now goes directly through
    `runner/libs/execute_workspace.py`, so executors no longer open-code
    `install -> validate -> suite` as three separate shell steps
  - KVM/AWS local prep now shares Python helper code in
    `runner/libs/local_prep_common.py` instead of duplicating the same bundle
    input writers and x86 staging rules in target-specific shell libraries
  - x86 runner/daemon/micro-program local-prep build steps now share Python
    helpers in `runner/libs/local_prep_common.py`
  - `RUN_SUITE_ENTRYPOINT` has been removed from the active contract
  - dead `runner/Makefile` `corpus-build-*` leaf targets have been deleted
  - AWS local prep now branches on `RUN_TARGET_ARCH` for arch-specific
    behavior instead of carrying extra concrete target-name branches where the
    behavior is really x86-vs-arm64
  - `AWS_*_BENCH_MODE=all` no longer uses recursive `$(MAKE)`
  - `make -n` now stays static and never launches real AWS work
  - canonical root aliases no longer expose deleted local-prep entrypoints
  - upstream selftests selection is now fully tracked and auditable:
    - `runner/config/upstream_selftests_selection.tsv` owns build-view
      exclusions and generated `vmlinux.h` exclusions
    - `runner.libs.build_upstream_selftests` now writes `selection.json`
  - AWS remote-prep naming/runtime cleanup landed in
    `runner.libs.aws_remote_prep`
       `python -m runner.libs.run_target_suite benchmark ...` instead of the
       root `Makefile`
   - remaining:
     - keep root aliases thin and avoid reintroducing orchestration there
     - keep `check` / `validate` from drifting into a second control plane for
       canonical runner behavior
2. Shared AWS split
   - status: done pending final reviewer confirmation
   - completed:
      - `aws_common_lib.sh` now holds shared AWS state/lifecycle/setup helpers
      - `aws_prep_paths_lib.sh` now holds AWS prep/build path defaults
      - `aws_kernel_artifacts_lib.sh` now holds AWS host-side kernel/cache/build helpers
      - `aws_remote_prep_lib.sh` now holds AWS remote-prep-only
        instance/setup reconciliation
      - `runner.libs.aws_local_prep` now holds AWS local-prep artifact/bundle logic
      - `runner.libs.aws_remote_prep` now owns AWS remote preflight
      - AWS remote preflight now emits an explicit state handoff for local prep
      - `runner.libs.prepare_local_inputs` no longer mutates AWS remote state
      - `runner.libs.prepare_local_inputs` now consumes an explicit remote-prep state
        file handoff instead of re-reading hidden shared AWS state
      - the remote-prep state handoff now uses an explicit positional file
        argument instead of an ambient `AWS_STATE_OVERRIDE_PATH` env override
      - `runner.libs.aws_executor run` no longer re-runs `ensure_instance_for_suite`
      - the obsolete `AWS_LOCAL_PREP_MODE` compatibility branch is deleted
      - generic local-prep helpers and AWS host-prep/build helpers no longer
        live in `aws_common_lib.sh`
   - remaining:
     - keep `aws_common_lib.sh` from reabsorbing host-prep/build or
       target/suite policy as later changes land
3. Local prep unification
   - status: mostly done, pending review
   - completed:
     - `runner.libs.prepare_local_inputs` is now the only public local-prep entrypoint
    - `kvm_local_prep.sh` and `aws_local_prep.sh` are deleted
    - `runner.libs.kvm_local_prep` now owns KVM-only local prep internals
     - `runner.libs.local_prep_common` now carries shared local-prep helpers for:
       x86 runtime/test prep, repo fetch/native build, SCX staging, workload-tool
       staging, and common path validation
     - KVM and AWS bundle-input files now converge on the same explicit
       JSON state contract emitted by Python local-prep code
     - KVM and AWS local prep now converge on the same explicit
       `bundle-inputs.json` contract
     - `runner.libs.build_remote_bundle` now consumes explicit runtime and
       test-artifact paths instead of a promote-root convention
     - bundled workload-tool roots are now carried through the same explicit
       bundle-input contract
       instead of being carried as a separate drifting path
     - shared bundle/runtime scripts now prefer `RUN_TARGET_ARCH` /
       `RUN_EXECUTOR` contract fields over hard-coding concrete target names
       where the behavior is really arch/executor-specific
   - remaining:
     - keep KVM/AWS prep semantics aligned as new artifact classes are added
     - review whether any remaining bundle-input variable is truly an extra
       input instead of another path derivable from the promote root
4. Repo cleanup and documentation drift
   - status: in progress
   - completed:
     - design summary at the front of this document now reflects the current
       runner shape
     - upstream selftests no longer use repo-owned compat headers or stub
       skeletons; the build now materializes an explicit selected-source view
       from `runner/config/upstream_selftests_selection.tsv` instead
     - upstream selftests now fail fast if a declared source exclusion no
       longer exists in the vendored upstream tree
     - the manifest-derived LLVM suffix contract now flows through x86 KVM,
       AWS x86, and AWS ARM upstream-selftests builds instead of silently
       falling back to unsuffixed tool names
     - `runner/CMakeLists.txt` no longer executes a runnable `llvm-config`
       binary to resolve llvmbpf link flags; it now links via
       `LLVMConfig.cmake` component resolution, which is a prerequisite for
       future ARM host-cross `micro_exec`
     - `prepare-arm64-sysroot.sh` now includes ARM LLVM headers, shared
       libraries, and `LLVMConfig.cmake` in the sysroot contract so future
       host-cross `micro_exec/llvmbpf` work is not blocked on missing target
       LLVM metadata
     - `runner/compat/` has been deleted from active code; no runner path now
       copies or references repo-owned upstream-selftest compat assets
     - AWS target profiles no longer hard-code operator-local key, subnet,
       security-group, or profile defaults; those are now explicit required
       inputs
     - `RUN_RUNNER_BINARY_MODE` and `TARGET_RUNNER_BINARY_MODE_DEFAULT` were
       removed from active code
     - `make clean` now preserves fetched AWS results and removes only
       prep/build/state subtrees under `.cache/aws-*`
     - shared ARM64 defaults now live in `runner/mk/arm64_defaults.mk`
       instead of being duplicated across the root and runner `Makefile`s
     - `README.md` no longer claims that canonical `vm-*` / `aws-*` runner
       outputs land directly in checked-in top-level `micro/results`,
       `corpus/results`, and `e2e/results`; it now reflects staged KVM and
       fetched AWS result locations
     - generic ARM host-side helper caches no longer default under
       `.cache/aws-arm64/*`; shared host-cross/sysroot/test-artifact defaults
       now use a generic ARM host cache root, while AWS target-local kernel and
       setup caches remain under the AWS target cache
   - remaining:
     - remove remaining deleted-script references, old names, and stale
       historical language that contradicts the new structure
5. Full-project review gate
   - status: static review clean pending final reviewer confirmation
   - only after items 1-4 are clean:
     - run full-project static review
     - run a full-tree reviewer
     - if reviewer finds remaining structural issues, fix them and review again
   - current state:
     - `bash -n` on the key runner scripts is green
     - `git diff --check` is green
     - `pytest` on the runner/static regression set is green
     - `make -n` on the canonical runner aliases is green and no longer starts
       real AWS work
     - a full-context subagent structural review has been launched against the
       current dirty tree and is pending return
   - current self-review status before the next reviewer pass:
     - fixed:
       - AWS local prep no longer performs remote setup/prereq side effects
       - `aws_executor.sh` no longer re-runs remote preflight during `run`
       - remote-prep-only entrypoints no longer live in the shared AWS common
         lib surface
      - duplicated local-prep helper definitions were reduced into shared
        Python prep helpers before the remaining shell helper lib was deleted
       - KVM and AWS local prep now share the same promote-root-based staged
         input contract for standard runtime/test/repo inputs
       - AWS remote preflight now hands resolved remote state to local prep
         explicitly instead of relying on an implicit shared state-file read
       - KVM and AWS executors now both consume a local-state handoff file
         rather than using different positional-vs-sourced handoff shapes
       - the remote-prep state handoff no longer uses an ambient env override
       - shared bundle/runtime scripts now prefer `RUN_TARGET_ARCH` /
         `RUN_EXECUTOR` over hard-coded concrete target names where the
         behavior is really arch/executor-specific
       - benchmark fanout now lives in `run_target_suite.sh benchmark ...`
         instead of the root `Makefile`
       - bundle sealing no longer depends on the caller shell's ambient
         `LD_LIBRARY_PATH`
       - AWS remote prereqs no longer source-build workload tools and now
         require either bundled tools or package-manager-provided tools
       - dedicated AWS runs now clean up leaked instances/run-state if
         remote-prep or local prep fails before the executor starts
       - active code no longer carries the dead runner-binary mode knob
       - canonical ARM daemon-only local prep no longer routes through
         `__cross-arm64`; it now uses host-cross daemon output plus a
         host-side portable runtime bundle step
   - latest reviewer status:
     - reviewer A:
       - found that canonical AWS local prep still accepted an optional
         remote-prep handoff and could therefore fall back to cached AWS state
       - fix applied:
         - `runner.libs.prepare_local_inputs` now requires an explicit remote-prep
           state file for canonical AWS local prep
         - AWS local prep now lives in `runner.libs.aws_local_prep`, which
           requires an explicit remote-prep state file and does not fall back to
           cached AWS state
     - reviewer B:
       - found stale README result-path language
       - fix applied: README now reflects staged KVM and fetched AWS result
         locations instead of top-level checked-in suite result dirs
   - current conclusion:
     - no active compat debt remains in active runner code
     - one remaining structural issue is still under active review:
       canonical AWS ARM local prep still routes `micro_exec` and native
       benchmark repo builds through `__cross-arm64*` and
       `docker --platform linux/arm64`

## 10. Current Progress Log

### 10.1 Completed in this refactor round

- Introduced target profiles and suite plans.
- Added generic contract loader and entrypoint.
- Added explicit host-side KVM preflight via `runner.libs.prepare_local_inputs`.
- Added `kvm` and `aws-ssh` executors.
- Rewired canonical root targets to the new contract.
- Added explicit AWS instance-mode contract in the manifest:
  - `test` -> shared cached target instance
  - `micro|corpus|e2e` -> dedicated per-run instance
- Removed cross-run prep-root pruning from AWS executor so overlapping runs do
  not delete each other's staged inputs.
- Split dedicated AWS per-run instance state out of the mutable prep root so
  `prepare_local_inputs` can rebuild the run root without losing cleanup state.
- Moved shared AWS local setup prep out from under the shared instance lock:
  - shared runs now seed/locate the instance under lock
  - perform local kernel/setup artifact preparation outside the lock
  - then serialize the shared instance reconcile/setup step together with the
    actual remote suite execution under the shared remote-execution lock
- `aws-*-terminate` now resolves all target-owned instances by target role
  instead of only the shared cached tag, so it can clean up leaked dedicated
  benchmark instances too.
- x86 Katran native benchmark prep no longer reads directly from the live
  `e2e/cases/katran` tree; it now stages a clean committed snapshot into the
  per-run promote root before invoking native repo prep.
- common remote bundle assembly now snapshots `vendor/libbpf` and
  `vendor/bpftool` as git checkouts instead of treating them like ordinary
  tracked subtrees, so untracked/generated submodule state no longer leaks into
  bundles.
- AWS bundle preparation no longer writes executor-local staging roots back into
  the manifest just to drive local bundle assembly; those roots are now passed
  as explicit bundle-input state into `runner.libs.build_remote_bundle`.
- `Makefile` benchmark mode `all` now fans out `micro/corpus/e2e` in parallel
  for AWS targets instead of serializing them through one shell branch.
- Removed the root `Makefile` AWS wrapper env blocks entirely; canonical AWS
  targets now call `runner.libs.run_target_suite` directly, so the public AWS input
  surface lives only in `runner/libs/run_contract.py`.
- Renamed ARM-only helper targets to internal-only names:
  - `__arm64-crossbuild-image`
  - `__arm64-daemon-host-cross`
  - `__cross-arm64`
  - `__cross-arm64-scx`
  - `__cross-arm64-bench`
  - `__arm64-test-artifacts`
- Reduced one more executor/bundle coupling layer:
  - `runner.libs.prepare_local_inputs` and `runner.libs.aws_executor` now use
    the same explicit bundle/local-state contract
  - KVM no longer mutates the manifest with `RUN_LOCAL_PROMOTE_ROOT` just to
    drive bundle assembly
  - the manifest stays the target/suite contract, while bundle-local prep state
    remains executor-local input
- Split the remaining shared AWS host-prep layer again:
  - `aws_prep_paths_lib.sh` now owns AWS prep/build path defaults
  - `aws_kernel_artifacts_lib.sh` now owns AWS host-side kernel/cache/build
    helpers
  - `aws_common_lib.sh` is reduced to shared AWS control-plane/state/SSH and
    remote-prereq behavior
- Tightened the staged-input contract around `RUN_LOCAL_PROMOTE_ROOT`:
  - KVM and AWS now derive standard x86/ARM64 runtime and test-artifact
    subpaths from one promote root
  - bundle-input files no longer need to enumerate long duplicated lists of
    x86/ARM64 subpaths just to describe the same staged tree
- Deleted the legacy AWS ARM64/x86 monoliths.
- Removed the old AWS ARM64 helper-chain files.
- Replaced executor-specific suite entrypoints with one shared `suite_entrypoint.sh`.
- Made AWS local bundle preparation explicit before remote suite invocation, while
  keeping AWS machine/kernel setup ahead of ARM64 artifact preparation.
- Tightened bundle assembly so repo-owned source trees are staged from tracked
  files only, reducing untracked-file leakage into remote bundles.
- Removed the last hardcoded KVM `e2e` host setup path; KVM preflight now
  consumes only manifest-selected repos and native artifacts.
- Removed KVM prep dependence on the shared live `runner/repos` tree; promoted
  KVM inputs now fetch repos directly into the per-run promoted repo root.
- Tightened ARM helper staging so `cross-arm64-build.sh` and
  `build-arm64-scx-host.sh` no longer absorb dirty/staged `scx` source trees.
- Removed the duplicate runner-local `vm-test/vm-micro/vm-corpus/vm-e2e`
  execution plane; canonical KVM execution now lives only at the root target layer.
- Removed root-`Makefile` AWS machine defaults so target profiles are now the
  only source of truth for AWS launch and remote-stage defaults.
- Made AWS x86 test bundles consume explicit staged unittest/negative/upstream
  selftest inputs instead of ambient repo-root build directories.
- Slimmed AWS remote prereq installation and verification down to execution-host
  requirements; remote build-toolchain installation is no longer canonical.
- Tightened all git-backed snapshot helpers so staged-but-uncommitted changes
  now fail loudly instead of being silently excluded by `git archive HEAD`.
- Stopped mutating the canonical AWS run manifest with local bundle paths; the
  executor now passes local-only staging inputs as process-local environment.
- Removed cached-state fallback for AWS key/subnet/security-group launch
  parameters; launch now fails unless the manifest already carries the full
  required AWS contract.
- Moved target-specific AMI override handling into the manifest contract via
  `RUN_AMI_ID`; ambient generic `AWS_AMI_ID` no longer bypasses the target layer.
- Added AWS instance-type reuse checks so cached/tagged instances that do not
  match the requested target contract are terminated and relaunched.
- Stopped bundling untracked module build output from the repo root; the remote
  bundle now stages the tracked `module/` tree plus the explicit selected built
  kinsn module directory for the target arch.
- Stopped reading the KVM host Python launcher, guest kernel image path, suite
  timeout, and test knobs from ambient executor state; canonical KVM execution
  now consumes those values from the manifest.
- Moved guest-side Python selection into `RUN_REMOTE_PYTHON_BIN`; KVM and AWS
  now use the same manifest-written interpreter contract instead of executor-side
  `PYTHON_BIN` injection.
- Moved AWS region/profile into the manifest and stopped resolving them from the
  executor host shell after manifest creation.
- Tightened AWS instance reuse so existing instances are reused only when the
  manifest-selected AMI/key/subnet/security-group contract still matches exactly.
- Extended AWS terminate manifests to carry the name-tag/region/profile contract,
  so `aws-*-terminate` no longer depends on ambient AWS CLI state.
- Moved native corpus vendor `bpftool` builds under the active build root instead
  of sharing repo-root `runner/build/vendor/bpftool`.
- Tightened AWS remote prereqs so Python/bpftool provisioning is driven by the
  explicit manifest runtime contract rather than a second hardcoded policy.
- Tightened native corpus prebuilds so any requested repo with `failed` or
  `partial` status now fails the whole prep step; canonical bundle staging also
  rejects empty staged native repo directories.
- Added repo-owned KVM guest prereq installation so canonical local execution no
  longer relies on ambient guest tooling; the x86 KVM target now carries its own
  remote Python default (`python3`) instead of inheriting the AWS-oriented
  `python3.11` contract, plus an explicit guest package-manager contract (`apt`)
  and manifest-written runtime Python module requirement (`PyYAML`).
- Split benchmark bundle assembly by suite so `micro`, `corpus`, and `e2e`
  bundles stage only the code each suite actually runs.
- Replaced repo-root module build outputs in canonical AWS bundle assembly with
  explicit staged `.ko` directories.
- Removed the last hardcoded `FUZZ_ROUNDS` / `scx_prog_show_race_*` fallback in
  the canonical test control plane; test execution now consumes the
  manifest-written test contract end to end through Python orchestration.
- Replaced shell-string `RUN_CORPUS_ARGS` / `RUN_E2E_ARGS` reconstruction with
  manifest argv arrays (`RUN_CORPUS_ARGV` / `RUN_E2E_ARGV`) parsed via `shlex`.
- Tightened AWS remote prereqs so unknown workload-tool tokens fail immediately
  instead of being ignored until later runtime failure.
- Moved ARM64 cross-build roots under repo-local cache paths instead of shared
  `/tmp/codex/...` directories.
- Added explicit KVM guest-side prereq validation before suite execution.
- Added repo-owned KVM guest prereq installation so canonical local `x86-kvm`
  no longer silently depends on ambient guest tool availability.
- Collapsed the guest-prereq tool/package mapping into one shared Python
  module:
  - `runner/libs/prereq_contract.py`
  - `install_guest_prereqs.sh`, `validate_guest_prereqs.sh`, and
    `aws_remote_prereqs.sh` are now thin launchers over Python helpers that
    consume the same command/package/python-import contract
- Removed guest-side auto-sourcing of host virtualenv activation from
  `runner/libs/vm.py`; canonical KVM guest execution no longer inherits host
  Python environment state through generated guest scripts.
- Switched canonical KVM execution from the live repo checkout to a staged
  workspace snapshot generated by `build_remote_bundle.sh`, and wrote only
  `RUN_LOCAL_STAGE_ROOT` / `RUN_LOCAL_STAGE_MANIFEST` back into the run-local
  manifest so guest execution no longer depends on the launcher temp manifest.
- Stopped benchmark bundles from carrying test-only selftest machinery by
  default. `build_remote_bundle.sh` now stages a common runner tree for every
  suite and adds upstream-selftest assets only for `test`.
- Removed the remaining direct runner VM entrypoints and root local ARM QEMU
  execution targets, deleting the last active non-manifest execution surface.
- Fixed ARM64 benchmark container prep so `__cross-arm64-bench` now forwards the
  staged `ARM64_SOURCE_REPO_ROOT` into the ARM userspace instead of silently
  falling back to the shared live `runner/repos` tree.
- Switched ARM64 `micro_exec` / `llvmbpf` local runner builds onto
  `clang/clang++` inside the ARM userspace so they do not silently fall back to
  the old GCC 11 C++ runtime while linking against LLVM 20.
- Fixed the remote prereq stage so `aws_remote_prereqs.sh` now ships the
  minimal Python helper tree (`runner/libs/prereq_contract.py`,
  `runner/libs/run_contract.py`, `runner/libs/aws_remote_prereqs.py`) instead of
  a separate shell-only prereq contract helper.
- Tightened promoted and bundled repo snapshots further:
  - KVM promoted repo snapshots now use `git archive HEAD` and fail on dirty
    promoted repo trees
  - `build_remote_bundle.sh` now accepts either a sealed git checkout snapshot
    or a previously promoted snapshot tree
  - bundled `vendor/linux-framework` subtrees now fail on dirty local
    modifications instead of silently copying working-tree content
- Removed the last KVM manifest impurity for staged execution:
  - `prepare_local_inputs.sh` now emits local stage-root state separately
  - `run_target_suite.sh` passes that local state explicitly to
    `kvm_executor.sh`
  - `kvm_executor.sh` no longer requires executor scratch fields inside the
    run manifest
- Replaced executor-side env injection for bundle construction with an explicit
  local bundle-input contract:
  - both KVM and AWS now write `bundle-inputs.json`
  - `build_remote_bundle.sh` consumes the manifest plus that local bundle spec
- Tightened AWS setup reuse so cached instance state now includes an explicit
  local setup fingerprint derived from the staged kernel image, `vmlinux`, and
  modules tarball; reuse is no longer keyed only to `uname -r`.
- Narrowed AWS remote prereq stamping to the runtime/prereq contract instead of
  the full benchmark manifest, so changing samples/filters/cases does not force
  host package reprovisioning.
- Restored the old `vm-corpus` default sample semantics in the manifest layer:
  `VM_CORPUS_SAMPLES` remains the canonical default unless `SAMPLES` is
  explicitly overridden.
- Extracted shared ARM kernel config.
- Removed Tetragon’s machine-global bundled BPF install path.
- Made canonical `x86-kvm` a single explicit-machine-contract VM target with no
  legacy target alias layer underneath.
- Removed local host-cross ARM upstream selftest binaries from the canonical
  AWS ARM64 `test` contract; repo-owned ARM tests still build locally, but
  upstream `test_verifier` / `test_progs` are now built natively on the AWS
  ARM instance from bundled source/workspace inputs.
- Removed silent per-program REJIT fallback synthesis from `runner/libs/case_common.py`
  and `corpus/driver.py`.
- Removed Tetragon ambient binary fallback to `corpus/build/tetragon/bin/tetragon`.
- Made multi-repo native corpus preparation fail-fast on any requested repo with
  `failed` or `partial` status; canonical bundle staging no longer tolerates
  empty placeholder repo build dirs.
- Narrowed remote benchmark tarballs so `micro`, `corpus`, and `e2e` each stage
  only the suite tree they actually execute.
- Restored the `e2e` bundle contract by staging `corpus/config/` alongside
  `e2e/`, so `e2e/driver.py` can still resolve the default
  `corpus/config/macro_apps.yaml`.
- Removed the Tracee output-style compatibility branch; the runner now uses the
  repo-managed Tracee `json:` output contract directly.
- Removed the bpftrace `usdt` stdlib temporary-source rewrite; bpftrace now
  uses a build-local `vmlinux.h` contract instead.
- Removed the fallback local-build branches from BCC / Tracee / Tetragon setup scripts.
- Updated `runner/Makefile` `e2e-prep` so repo-managed native E2E artifacts are
  prepared explicitly instead of relying on setup-script fallback behavior.
- Deleted `runner/machines.yaml` and `runner/libs/machines.py`, removing the
  last legacy target-alias VM control plane.
- Removed `--target` support from `runner/scripts/run_vm_shell.py` and
  `runner/scripts/with_vm_lock.py`; both now consume only explicit machine data.
- Removed the dead `SUITE_NEEDS_DAEMON` knob from suite definitions.
- Removed the stale `runner.libs.vm.build_vm_shell_command()` compatibility
  helper and its test-only usage.
- Revalidated the explicit-machine-only KVM path with `python3 -m py_compile`
  on the touched VM helpers and `pytest -q tests/python/test_vm.py
  tests/python/test_case_common.py tests/python/test_corpus_driver.py
  tests/python/test_rejit.py` (`46 passed`).
- Tightened KVM bundle assembly so `micro` stages its generated
  `micro/programs/*.bpf.o` and sidecar bin files from explicit prep inputs
  instead of relying on live workspace artifacts.
- Added suite-level runtime binary contracts:
  - `RUN_NEEDS_RUNNER_BINARY`
  - `RUN_NEEDS_DAEMON_BINARY`
  - `RUN_NEEDS_KINSN_MODULES`
  so bundle assembly no longer requires `micro_exec`, `bpfrejit-daemon`, or
  repo kinsn modules for suites that do not actually consume them.
- Switched canonical KVM execution to staged-only mount/cwd wiring:
  `run_vm_shell.py` / `runner.libs.vm` now accept explicit guest cwd/rwdirs,
  and `kvm_executor.sh` now requires `RUN_LOCAL_STAGE_ROOT` /
  `RUN_LOCAL_STAGE_MANIFEST` instead of falling back to the live repo.
- Added a KVM per-run promoted-input root under `.cache/kvm-staged/<token>/prep`
  so staged workspaces consume isolated copies of generated runtime/test/native
  artifacts rather than reading shared repo-root outputs directly.
- Added `run-contract.env` into suite artifacts so both KVM and AWS archives now
  retain the canonical run contract for postmortem and reproducibility.
- Tightened AWS running-instance reuse again so `ensure_instance_running()`
  validates the full launch contract (AMI/key/subnet/security group) before
  keeping a cached instance alive.
- Removed unused KVM tarball retention from staged local runs; KVM now keeps
  the staged workspace and promoted-input root but deletes the unused tarball.
- Split canonical `test` mode prep by actual mode:
  - `selftest` now stages unittest + negative + daemon + kinsn modules, but no
    `scx` or upstream selftests
  - `negative` now stages negative + `scx`, but no daemon, kinsn modules, or
    upstream selftests
  - full `test` continues to stage the complete bundle
- Tightened KVM prep so x86 runtime/test inputs are produced directly into the
  per-run promoted root instead of being copied out of repo-root build dirs:
  - `micro_exec`
  - `bpfrejit-daemon`
  - x86 unittest / negative builds
  - x86 upstream selftests
  - x86 kinsn modules
  - x86 `scx`
- Added explicit output-dir plumbing to `runner/Makefile` for:
  - `micro-programs`
  - `daemon-binary`
  - `unittest-build`
  - `negative-build`
  - `upstream-selftests-build`
  - `kinsn-modules-build`
- Removed dead `runner/Makefile e2e-prep`; canonical suite prep no longer has
  a second E2E preflight surface.
- Added a lock around the repo-local ARM64 sysroot cache used by the new
  host-cross `scx` path, so concurrent host-cross runs no longer destructively
  rebuild the same sysroot tree.
- Fixed guest Python module bootstrapping so `install_guest_prereqs.sh` no
  longer assumes `python -m pip` already exists on the guest image.
- Tightened `arm64-test-artifacts` and test bundle assembly so `selftest`,
  `negative`, and full `test` only build/bundle the artifact classes they
  actually execute.
- Removed the last unconditional ARM64 test-mode Docker dependency:
  `arm64-test-artifacts` now builds the ARM64 Docker/qemu image only for full
  `test`, and `selftest`/`negative` stay on the host-cross path end to end.
- Tightened micro artifact staging again so generated sidecars are copied only
  for the newly built `.bpf.o` set, and stale sidecars are removed by
  `micro/programs/Makefile clean`.

### 10.2 Validation progress in this round

- `make vm-micro` passed on the staged-only KVM path after adding explicit
  `micro/programs` generated artifact staging.
- `make vm-test` regressed once after removing the live repo mount because the
  staged workspace accidentally nested `runner/runner/...`; that bundle-layout
  bug has been fixed.
- A focused staged-VM reproducer for `tests/unittest/build/rejit_regression`
  passed cleanly (`8 passed, 0 failed, 1 skipped`), so the earlier full-suite
  stall is not inside `rejit_regression`.
- The canonical staged-only `make vm-test` path was then rerun and progressed
  through upstream selftests plus most repo-owned unittest binaries, but it
  stalled again inside `rejit_hotswap_sched_cls`.
- The host rebooted at `2026-04-04 22:08`, which interrupted that run before a
  postmortem artifact could be captured. The current x86 KVM blocker is
  therefore narrowed to guest-side behavior in `rejit_hotswap_sched_cls`, not
  to runner control-plane setup.
- The first canonical `make aws-arm64-test` invocation after the refactor failed
  immediately and correctly at contract load time because `AWS_ARM64_REGION`
  was unset. That is now the expected behavior under the explicit manifest
  design: target-prefixed AWS region/profile inputs are required and there is no
  ambient fallback.
- Local operator inputs are now known:
  - profile: `codex-ec2`
  - region: `us-east-1`
- The next canonical `make aws-arm64-test` invocation then failed at the next
  explicit contract gate because the AWS launch tuple was still incomplete:
  `AWS_ARM64_KEY_NAME`, `AWS_ARM64_KEY_PATH`, `AWS_ARM64_SECURITY_GROUP_ID`,
  and `AWS_ARM64_SUBNET_ID` were unset.
- The local operator launch tuple is now known as well:
  - key name: `codex-arm64-test-20260319121631`
  - key path: `~/.ssh/codex-arm64-test-20260319121631.pem`
  - default VPC security group: `sg-0da186840752e6acc`
  - default subnet: `subnet-009460065a1cd946c`
- A first full canonical `make aws-arm64-test` run with those explicit inputs
  launched instance `i-0016ff973845d1927`, but the run then stalled in SSH
  readiness against public IP `100.49.41.239`.
- The root cause was not a runner bug. The explicit launch tuple was still
  wrong: the chosen default security group `sg-0da186840752e6acc` only allows
  intra-group traffic and does not permit inbound SSH from the operator host.
- The correct ARM-specific security group is present in the account already:
  `sg-0ebe13c1e4c0defc9` (`codex-arm64-test-sg-20260319121631`), which has an
  explicit port-22 ingress rule for the current operator IP.
- The failed instance should be terminated and the next canonical
  `make aws-arm64-test` rerun should use:
  - `AWS_ARM64_SECURITY_GROUP_ID=sg-0ebe13c1e4c0defc9`
  - the same key/subnet/region/profile tuple as above
- A rerun with the ARM-specific SSH-enabled security group (`sg-0ebe13c1e4c0defc9`)
  successfully cleared the launch and SSH-readiness gates:
  - the instance received a reachable public IP
  - direct SSH with the configured key succeeded
  - `aws_executor.sh` moved on to kernel build, module packaging, and remote
    prerequisite/setup execution
- The setup path then successfully booted the custom AWS ARM64 kernel:
  - runtime `uname -r` reported `7.0.0-rc2+`
  - `/boot/vmlinuz-7.0.0-rc2+` was the active kernel image
  - the state file recorded both `STATE_KERNEL_RELEASE=7.0.0-rc2+` and a
    non-empty setup fingerprint
- The EC2 console output confirms that this was a controlled poweroff/reboot
  into the custom kernel, not a kernel panic.
- The current first long-running post-setup stage is now local, not remote:
  canonical `aws-arm64-test` is spending most of its time in the minimal
  ARM64 cross-build steps required by the `test` suite, specifically:
  - initial runner-side `micro_exec` build
  - daemon-only Cargo build (`ARM64_CROSSBUILD_RUNTIME_TARGETS=daemon`)
- The current run has not reached a first test-suite failure yet.
  The remaining live work is still artifact preparation and setup sequencing,
  not a repo-owned unittest or upstream selftest failure.
- Subsequent canonical reruns continued to push deeper into the minimal ARM
  test artifact set instead of regressing to the old broad build shape:
  - `aws-arm64 test` now reaches a daemon-only cross-build phase
  - after that, it reaches the ARM `scx_rusty` artifact build path via
    `cross-arm64-scx`
- The current live bottleneck is therefore:
  - local `build_scx_artifacts.py --package scx_rusty`
  - running under the ARM64 cross-build container with qemu-user
  - still producing active Rust compilation subprocesses, so it is slow but not
    a confirmed deadlock
- As of this update, there is still no new `test_test_*` result directory for
  the refactored canonical path, which means the first true test-suite failure
  (if any) has not been observed yet.
- That rerun has now passed the AWS control-plane gates cleanly:
  - the new instance `i-02008d9c50a2aebd7` launched with public IP
    `13.220.12.46`
  - SSH readiness succeeded under the ARM-specific security group
  - remote setup completed and the guest rebooted into
    `7.0.0-rc2+`
  - the canonical state file now records both `STATE_INSTANCE_IP` and
    `STATE_SETUP_FINGERPRINT`
- The current in-progress blocker is no longer remote AWS setup. The run is
  now spending most of its time inside local `cross-arm64` runner artifact
  preparation, specifically the qemu-user/containerized `micro_exec` build used
  by the ARM test bundle. This is currently a performance/latency bottleneck,
  not yet a confirmed functional failure.
- That bottleneck exposed a real contract bug:
  - `RUN_NEEDS_RUNNER_BINARY=0` for `aws-arm64/test`, but
    `aws_executor.sh -> cross-arm64 -> cross-arm64-build.sh` still built both
    `runner` and `daemon`
  - the first fix split runtime preparation by manifest need, but a second bug
    remained because the new `ARM64_CROSSBUILD_RUNTIME_TARGETS` setting was not
    forwarded through the `Makefile` `docker run`
- The corrected contract is now verified in a live rerun:
  - `make cross-arm64` is invoked with
    `ARM64_CROSSBUILD_RUNTIME_TARGETS=daemon`
  - the container now logs `Building ARM64 daemon`
  - `micro_exec` is no longer rebuilt for the ARM test suite
- That live rerun then exposed one more leftover assumption in the root
  `Makefile`: the `cross-arm64` recipe still unconditionally validated both
  `$(ARM64_CROSS_RUNNER_REAL)` and `$(ARM64_CROSS_DAEMON_REAL)` after the
  container finished.
- This was a pure compatibility-tail bug, not a daemon build failure:
  - the ARM daemon had finished successfully
  - the top-level recipe then failed only because `runner/build/micro_exec.real`
    was intentionally absent under the new daemon-only contract
- The post-build verification now follows the same runtime-target selection and
  only checks the artifacts that were actually requested.
- A later full-context review confirmed the next real design blocker: AWS local
  prep was still target-global even after bundle staging became tokenized.
  The same `.cache/<target>/repos`, `bundle-inputs`, `artifacts`,
  `modules-stage`, and ARM cross-build output roots were still reused across
  runs, which blocked clean correctness-run parallelization.
- The executor now moves those mutable local prep paths under a per-run root:
  `.cache/<target>/runs/<manifest-token>/...`
  while leaving only target-level `state/` and `results/` shared.
- x86 AWS local prep now follows the same per-run shape:
  - `micro_exec` builds into a per-run runner build dir
  - `bpfrejit-daemon` builds into a per-run Cargo target dir
  - unittest / negative / upstream selftests build into per-run output dirs
  - x86 kinsn modules are built from a per-run copied module tree instead of
    mutating `module/x86` in the live checkout
- ARM AWS local prep now also consumes per-run mutable roots:
  - ARM64 kinsn modules are built from a per-run copied module tree
  - ARM64 upstream selftest kmods already stage into per-run dirs
  - `cross-arm64`, `cross-arm64-scx`, and `cross-arm64-bench` now accept
    per-run output/build/cargo-home paths from the executor
  - `arm64-test-artifacts` now receives container-visible translated paths, so
    per-run host paths under the repo mount are honored correctly inside Docker
- The kernel-build lock helper itself had to be corrected as part of this work:
  it previously executed locked commands in a subshell, which meant
  `BUILD_KERNEL_RELEASE` / `BUILD_SETUP_FINGERPRINT` assignments were lost after
  leaving the lock scope. The helper now keeps those assignments in the calling
  shell while still holding the same file lock.
- Same-target AWS control state now has an explicit lock around
  `ensure_instance_for_suite` / `terminate_instance`, so concurrent
  `aws-arm64` or concurrent `aws-x86` invocations no longer race on the shared
  `instance.env` file.
- Remote prerequisite helper/manifests no longer upload into a single shared
  target stage root; they now use a per-run subdirectory under the target stage
  area.
- ARM64 setup cache defaults are now keyed by the AWS setup contract
  (`target + region + AMI param/id`) instead of always collapsing onto one
  global `.cache/aws-arm64/kernel-build` and one global cached base config.
  That reduces cross-contract cache poisoning when the canonical ARM target is
  rerun against a different AMI tuple.
- The first ordered-validation rerun after this change exposed one more one-click
  gap: if the cached ARM64 instance is already on the custom kernel but the
  matching base-config cache is absent, the old path stopped with
  `cannot seed AWS ARM64 base config from non-stock kernel`.
  The canonical flow now treats that as a relaunch condition:
  it terminates the cached custom-kernel instance and launches a fresh stock
  AL2023 instance so base-config capture can proceed automatically.
- `micro` bundle assembly no longer falls back to live workspace generated
  files, and AWS benchmark prep no longer first writes generated `.bpf.o`
  objects into the shared repo-root `micro/programs`.
  The `micro/programs` build now accepts an explicit `OUTPUT_DIR`, and AWS prep
  writes generated objects directly into the per-run promoted input dir before
  bundling.
- The first fresh-instance rerun then exposed a local container-entrypoint bug,
  not an AWS bug: `arm64-test-artifacts` invoked
  `/workspace/runner/scripts/build-arm64-test-artifacts.sh` directly inside the
  Docker container, but that tracked file is mode `100644`, so the run failed
  with `Error 126` (`permission denied`).
  The fix is to make every Docker ARM cross-build entrypoint explicit:
  `bash /workspace/runner/scripts/...`.
  This removes hidden dependence on host executable-bit state and keeps the
  container contract stable across clones and refactors.
- The next cleanup pass split the old global kernel build lock into two explicit
  resource locks:
  - one for the shared x86 kernel tree
  - one for the shared AWS ARM64 worktree/build cache
  x86 kinsn-module prep and x86 upstream selftest prep now run under the x86
  lock, and ARM64 kinsn/upstream-test-kmod prep now runs under the ARM64 lock.
  This is the minimum needed shape for clean AWS correctness parallelism; it
  avoids inventing a new framework while removing the single global
  kernel-adjacent bottleneck.
- `runner/Makefile` also dropped the dead VM/debug/benchmark variable layer that
  was no longer consumed by any active target. That file now keeps only the
  build knobs it still uses directly.
- The root `Makefile` no longer provides duplicate default values for AWS test /
  corpus / e2e tuning knobs that are already resolved in the target/suite
  contract. The canonical root entry points still export overrides, but they no
  longer act as the default-value source of truth for those suite parameters.
- One rerun after the container-entrypoint fix was interrupted with
  `make ... Terminated`, but the host did not reboot and no new functional
  blocker was captured. The next action is simply to rerun on the latest tree,
  not to treat that interruption as a kernel/setup regression.
- The next live rerun exposed another real dual-control-plane bug: root `Makefile`
  still exported helper path variables such as `ARM64_TEST_ARTIFACTS_ROOT`,
  `ARM64_CROSSBUILD_OUTPUT_DIR`, and `ARM64_AWS_BUILD_DIR`, so the canonical
  executor inherited shared `.cache/aws-arm64/*` paths and silently overrode the
  per-run roots derived from `RUN_TOKEN`. This broke the new parallel-safe prep
  model even though the executor code had already been refactored toward per-run
  paths.
  The fix is twofold:
  - stop exporting those mutable helper paths from the root `Makefile`
  - make `aws_executor.sh` assign its mutable local prep roots directly from
    `RUN_TOKEN` instead of accepting ambient overrides
  A live run that inherited the old shared paths was terminated and discarded;
  only reruns after this fix count as canonical validation.
- The follow-up rerun confirmed that the fix is actually live, not just a code diff:
  - the new `aws_executor.sh` process environment no longer contains shared
    `ARM64_TEST_*`, `ARM64_CROSSBUILD_OUTPUT_DIR`, or `ARM64_AWS_BUILD_DIR`
    values
  - the kernel build subprocess now uses the keyed setup cache path
    `.cache/aws-arm64/setup/<token>/kernel-build`
  - the canonical run-specific prep root remains under
    `.cache/aws-arm64/runs/<manifest-token>/...`
  This is the first rerun that satisfies the intended per-run/local-prep and
  keyed-setup-cache contract.
- That same rerun then progressed into the next local prep stage with the
  correct per-run wiring still intact:
  - `cross-arm64` runs with
    `ARM64_CROSSBUILD_OUTPUT_DIR=.cache/aws-arm64/runs/<manifest-token>/cross-arm64-output.tmp`
  - `ARM64_CROSSBUILD_BUILD_ROOT` and `ARM64_CROSSBUILD_CARGO_HOME` are both
    under the same per-run root
  - `ARM64_CROSSBUILD_RUNTIME_TARGETS=daemon` remains in effect, so the test
    path continues to avoid rebuilding `micro_exec`
  This confirms that the per-run prep contract now survives not only manifest
  load but also the actual Dockerized ARM64 runtime build step.
- The ARM64 daemon no longer needs that Dockerized ARM64 runtime build step at
  all:
  - a new host-side helper, `runner/scripts/build-arm64-daemon-host.sh`, now
    builds `bpfrejit-daemon` with
    `cargo build --release --target aarch64-unknown-linux-gnu`
  - `cross-arm64` now requires an explicit prebuilt daemon input when the
    daemon runtime target is enabled
  - `arm64-test-artifacts` now also requires an explicit prebuilt daemon input
    instead of running `cargo build` inside the ARM64 container
- The new host-cross daemon path has been validated directly:
  - `make arm64-daemon-host-cross ...` completed successfully
  - the resulting binary is `ELF 64-bit ... ARM aarch64`
  - `readelf -d` shows only `libgcc_s.so.1` and `libc.so.6` as dynamic runtime
    dependencies
- The new mixed path has also been validated for the runtime bundle contract:
  - `make cross-arm64 ARM64_CROSSBUILD_RUNTIME_TARGETS=daemon ...` now succeeds
    with the daemon prebuilt on the host first
  - the ARM64 container only wraps and bundles the prebuilt daemon, instead of
    compiling it
- A heavier `make arm64-test-artifacts ...` verification confirmed the daemon
  contract switch too:
  - the host-side daemon cross-build completes first
  - the ARM64 container then proceeds directly into unittest / negative /
  upstream-selftest work
  - the next blocker is in the pre-existing ARM64 unittest/upstream-selftest
  build chain, not in daemon compilation
- The next qemu-removal pass moved `scx` out of the ARM64 container path too:
  - `runner/scripts/prepare-arm64-sysroot.sh` now prepares a repo-local ARM64
    userspace sysroot
  - `runner/scripts/build-arm64-scx-host.sh` now stages a tracked-only `scx`
    checkout via `git archive` and runs host-side
    `cargo build --target aarch64-unknown-linux-gnu`
  - `make cross-arm64-scx ARM64_CROSSBUILD_SCX_PACKAGES=scx_rusty ...` now
    succeeds on the x86 host and produces:
    - `runner/repos/scx/target/release/scx_rusty`
    - `corpus/build/scx/scx_rusty_main.bpf.o`
- That host-cross move exposed two follow-on contract bugs, both now fixed:
  - the first host `scx` helper copied the full checkout including stale
    multi-GB `target/` output, which filled the disk; it now stages tracked
    files only
  - the first host runtime-lib bundling pass incorrectly used host `ldd` on an
    ARM64 binary and silently missed required non-system libraries; it now uses
    `aarch64-linux-gnu-readelf` plus explicit sysroot/toolchain search instead
- Reintegrating host-cross `scx` into canonical `aws-arm64-test` then exposed
  one more container-tail bug:
  - `cross-arm64-build.sh` only repaired ownership for `OUTPUT_ROOT` and
    `CARGO_HOME`
  - it left `BUILD_ROOT` behind as root-owned after the Dockerized ARM runtime
    phase
  - the next host-side `cross-arm64-scx` step then failed with
    `Permission denied` when trying to create `.../cross-arm64-build-root/scx`
  - the fix now chowns `BUILD_ROOT` too, so the same per-run root can be
    consumed by both the Dockerized runtime phase and the host-native `scx`
    phase
- That heavier verification also exposed an unrelated existing issue worth
  keeping in view: using `vendor/linux-framework/build-arm64/vmlinux` as the
  `VMLINUX_BTF` input can still trigger noisy linker failures against
  `vmlinux.o` during ARM64 unittest/selftest prep. That problem predates the
  daemon change and is not part of the new host-cross daemon contract.
- The next `arm64-crossbuild-image` rebuild surfaced the first new explicit
  post-refactor blocker in the remaining ARM64 Docker/qemu path:
  `build-arm64-test-artifacts.sh` now reaches upstream-selftest signing, but
  the container image was missing the `openssl` executable. The Dockerfile now
  installs both `openssl` and `openssl-devel`.
- That image rebuild has completed successfully, so the current live rerun is
  now the first canonical `aws-arm64-test` attempt on the new tree with:
  - host-cross daemon
  - host-cross `scx`
  - locked repo-local ARM64 sysroot
  - mode-aware `test` prep
  - stricter KVM/AWS staged-input cleanup already in place
- The current live canonical run is:
  - `make aws-arm64-test ...`
  - manifest token: `run.aws-arm64.test.jKrPMF`
  - instance reuse/setup has already cleared
  - the run is currently in local bundle preparation, with the active observed
  subprocess tarring staged ARM64 module inputs under the per-run prep root
  No new repo-owned test failure has been observed yet on this rerun.
- A follow-up cleanup removed one more stale tail in the local ARM test helper:
  `arm64-test-artifacts` no longer forces an ARM64 image rebuild for
  `selftest`. A direct validation on the latest tree now succeeds with:
  - `make arm64-test-artifacts ARM64_TEST_MODE=selftest ...`
  - no `docker buildx`
  - no `docker run --platform linux/arm64`
  - repo-owned ARM64 unittest, negative, and daemon artifacts all produced via
    host cross-compilation only
- That direct validation also exposed and fixed one small compatibility-tail
  bug in the root `Makefile`: the post-build `file | grep` checks still assumed
  non-PIE ARM executables and falsely failed on valid `pie executable`
  binaries. The checks now verify only `ARM aarch64`.
- The old long-running canonical `aws-arm64-test` rerun tied to manifest
  `run.aws-arm64.test.jKrPMF` was then terminated intentionally.
  Reason:
  - it started before the latest `arm64-test-artifacts` cleanup
  - it was still spending time in the outdated qemu-heavy repo-owned test path
  - same-target execution should not stay blocked by a run that no longer
    matches the latest intended contract
- The next canonical action after this update is therefore:
  - rerun `make aws-arm64-test` on the latest tree
  - accept only that rerun as the current source of truth for AWS ARM64 `test`
- The current canonical rerun is now:
  - `make aws-arm64-test ...`
  - manifest token: `run.aws-arm64.test.dTsYAx`
  - instance: `i-0ed82a611f59b0241`
  - active kernel: `7.0.0-rc2+`
- This rerun has now cleared the next two cleanup gates as well:
  - ARM64 repo-owned unittest / negative binaries are built on the host via
    `runner/scripts/build-arm64-repo-tests-host.sh`, not via the ARM64
    Docker/qemu path
  - `scx_rusty` is built on the host via
    `runner/scripts/build-arm64-scx-host.sh` inside the canonical flow, not as
    a separate manual prebuild
- The canonical `dTsYAx` run has also now progressed past all previously known
  upstream-selftest bootstrap blockers:
  - missing `linux/kasan-checks.h`
  - missing `asm/alternative-macros.h`
  - native `llvm-ar` selection
  - missing `openssl-devel`
- `runner/scripts/build_upstream_selftests.sh` now reaches the real ARM64
  upstream selftest compile body on the instance:
  - `libbpf` builds
  - bootstrap `bpftool` builds
  - `vmlinux.h` generation succeeds
  - the remote log has entered `CLNG-BPF [test_progs] ...`
- As of this update, there is still no new fatal error in the canonical remote
  log. The first remaining unknown is now inside the real `test_progs` compile
  / execute path, not in bundle wiring or tool discovery.
- The next real blocker has now been observed inside that real `test_progs`
  path:
  - while compiling the host-side helper object `xsk.o`, the active source tree
    picked up `tools/include/asm/barrier.h -> arch/arm64/include/asm/barrier.h`
    and then failed on:
    - `fatal error: 'linux/kasan-checks.h' file not found`
- this showed that the staged support-include path was only reaching the
  `EXTRA_CFLAGS`-driven BPF/feature compile surface, not the generic
  userspace `CFLAGS` surface used by `xsk.c`
- The fix is repo-owned and contract-level:
  - `runner/scripts/build_upstream_selftests.sh` now also passes
    `USERCFLAGS=-I<support-include-dir>`
  - that support-include directory remains source-tree external and still does not patch
    any upstream file
- That fix has been validated directly on the live AWS ARM instance:
  - compiling `xsk.c` with the same selftest include layout plus
    `-I <support-include-dir>` now succeeds
  - `/tmp/xsk-support.o` was produced as
    `ELF 64-bit LSB relocatable, ARM aarch64`
- The current `dTsYAx` canonical run was started before that fix, so it should
  be treated as obsolete once it exits. The next source of truth is the first
  canonical rerun after `USERCFLAGS` reaches the bundle.
    progress
- The next latest-tree canonical rerun did start and reached a new concrete
  blocker that is unrelated to qemu/toolchain semantics:
  - `run.aws-arm64.test.Nbfact` failed during local ARM kernel
    `modules_install`
  - the destination under
    `.cache/aws-arm64/runs/run.aws-arm64.test.Nbfact/modules-stage/...`
    hit `No space left on device`
  - the underlying issue was stale local cache pressure, not a broken kernel
    build contract
- That disk-pressure blocker has now been addressed conservatively:
  - stale `.cache/kvm-staged/run.x86-kvm.*` prep roots/tarballs were deleted
  - stale `.cache/aws-arm64/runs/run.aws-arm64.test.*` per-run roots were
    deleted
  - stale `/tmp/arm64-*` and `/tmp/upstream-arm64-hostcross.*` validation
    directories were deleted
  - canonical result directories were kept intact
  - the current setup cache under `.cache/aws-arm64/setup/<fingerprint>/` was
    kept intact
- After that cleanup, workspace free space recovered from effectively zero to
  roughly `9.7G`, which is enough for the next rerun to proceed past
  `modules-stage`.
- The next ARM upstream-selftest cleanup removed a real control-plane bug:
  `UPSTREAM_SELFTEST_LLVM_SUFFIX` was not propagated into the ARM host-cross
  helper, so the build silently fell back to unsuffixed host LLVM instead of
  the intended LLVM 20 toolchain.
- ARM host-cross upstream selftests were then made to build cleanly from a
  repo-owned filtered source workspace, but the resulting binaries still linked
  against `GLIBC_2.38`, which is not runnable on AWS AL2023 (`glibc 2.34`).
- The canonical AWS ARM64 `test` contract was changed again after that:
  - local prep still builds repo-owned ARM unittest / negative / daemon assets
  - upstream selftest kmods are still prepared locally
  - upstream `test_verifier` / `test_progs` are no longer required as local
    host-cross artifacts
  - the remote suite now builds upstream selftests natively from bundled
    `vendor/linux-framework/tools/testing/selftests/bpf` source plus
    repo-owned `runner/scripts/build_upstream_selftests.sh`
- The first temporary `remote-native` rerun exposed two concrete contract bugs, both now
  fixed:
  - AWS remote prereq installation originally added `llvm20` instead of
    `llvm20-devel`, so `llvm-config-20` was still missing on the instance
  - the AWS test bundle originally omitted
    `vendor/linux-framework/tools/testing/selftests/bpf` because
    `build_remote_bundle.sh` used the root repo's `git ls-files` against the
    nested `vendor/linux-framework` checkout instead of the nested repo's own
    tracked file list
- The next temporary `remote-native` rerun exposed one more filtered-source-tree bug, also
  now fixed:
  - `build_upstream_selftests.sh` created a filtered root that symlinked
    `kernel/` and `scripts/` but not the top-level kernel `include/`
    directory, so native ARM builds of libbpf failed under
    `arch/arm64/include/asm/barrier.h` with
    `fatal error: 'linux/kasan-checks.h' file not found`
- The follow-up rerun showed that the filtered tree change alone was still not
  sufficient because libbpf's compile path still came in via
  `vendor/linux-framework/tools/include`, so the repo-owned fix was tightened:
  - adding the whole bundled kernel `include/` directory to `EXTRA_CFLAGS`
    turned out to be too broad and caused userspace/kernel header collisions
    during libbpf compilation
  - the current repo-owned fix is therefore narrower: `build_upstream_selftests.sh`
    now copies only the needed kernel headers into a generated include
    directory under the output tree and only adds that generated include root
    instead of exposing the full kernel include tree
- The next temporary `remote-native` ARM-only blockers were all more localized, and all
  point in the same direction: keep feeding upstream selftests a minimal
  repo-owned generated-include overlay and explicit toolchain contract instead
  of widening the
  bundled kernel header surface:
  - `arch/arm64/include/asm/barrier.h` next failed on
    `asm/alternative-macros.h`, so `build_upstream_selftests.sh` was extended
    to copy that arch header into the same generated include directory when it
    exists
  - once libbpf built and bpftool advanced, the remote instance then failed on
    `openssl/opensslv.h`, so `aws_remote_prereqs.sh` was updated to install
    `openssl-devel`
  - the remote-native build also still assumed a bare `llvm-ar` name even
    though the instance only had `llvm-ar-20`; `build_upstream_selftests.sh`
    now pins native `AR` to the same resolved suffixed LLVM tool as `HOSTAR`
- The source of truth at that point was therefore:
  - AWS ARM64 `test` used temporary `remote-native` upstream selftests
  - the bundle now includes the upstream selftests source tree
  - remote prereq stamping now includes both the upstream-selftest execution
    mode and the `aws_remote_prereqs.sh` script content, so dependency changes
    invalidate the remote prereq stamp correctly
- The next concrete blocker after upstream selftests moved fully into the
  then-`remote-native` path was no longer upstream at all; it was the repo-owned ARM
  binaries built locally for `tests/unittest/` and `tests/negative/`:
  - the rerun tied to `run.aws-arm64.test.E0I2zy` reached the repo-owned test
    section and failed 21 cases with the same loader error
  - every failing repo-owned ARM binary was linked against `GLIBC_2.38`
  - AWS AL2023 only provides `glibc 2.34`
- That failure was not fixed by pushing those binaries back onto the instance
  for native build. The repo-owned fix is instead:
  - `runner/scripts/prepare-arm64-sysroot.sh` now prepares one repo-local ARM64
    sysroot by synchronizing the exact AL2023 runtime/devel package files from
    the live AWS ARM instance over SSH
  - the synced sysroot records a remote package fingerprint and is protected by
    a lock, so concurrent runs do not rebuild it blindly
  - the synced sysroot also normalizes AL2023's runtime loader layout so the
    local GNU cross linker can resolve `/lib/ld-linux-aarch64.so.1` and
    `/lib64/libc.so.6` against repo-local content
- Host-cross ARM builders now share that explicit sysroot contract:
  - `runner/scripts/build-arm64-daemon-host.sh`
  - `runner/scripts/build-arm64-repo-tests-host.sh`
  - `runner/scripts/build-arm64-scx-host.sh`
  - `runner/scripts/aws_executor.sh` now passes the remote user/IP/key
    explicitly into those host-cross steps
- That host-cross fix exposed one more real ABI bug:
  - `aarch64-linux-gnu-gcc --sysroot=...` still searched
    `/usr/aarch64-linux-gnu/include` before the synced AL2023 headers
  - `vendor/libbpf` then picked up newer host glibc headers and emitted an
    unresolved `__isoc23_strtoull`
  - the repo-owned fix is to force the repo-owned ARM C wrapper to inject
    `-isystem <repo-local-sysroot>/usr/include`, so standard headers come from
    the synced AL2023 sysroot first
- Direct validation on the latest tree now shows the ABI mismatch is resolved:
  - `make arm64-test-artifacts ARM64_TEST_MODE=test ...` succeeds
  - `aarch64-linux-gnu-readelf --version-info` on the rebuilt daemon/test
    binaries shows `GLIBC_2.34` or older, not `GLIBC_2.38`
  - copying the rebuilt `rejit_audit_tests` and bundled `libelf/z/zstd` to the
    live AWS ARM instance now enters the test logic itself instead of failing
    in the loader
  - the remaining manual failure on that direct execution was expected context
    failure (`Operation not permitted` / missing test inputs), not ABI/runtime
    incompatibility
- The current canonical rerun after the sysroot/ABI fix is now:
  - `make aws-arm64-test`
  - manifest token: `run.aws-arm64.test.y0OoFm`
  - instance: `i-0ed82a611f59b0241`
  - active kernel: `7.0.0-rc2+`
- That rerun no longer failed in the old qemu/daemon path. The next real
  blocker was narrower and stayed entirely in the new host-cross `scx` path:
  - `runner/scripts/build-arm64-scx-host.sh` only searched
    `sysroot/usr/lib64` and `sysroot/lib64` when resolving runtime `NEEDED`
    libraries for the promoted `scx` binary bundle
  - AL2023's loader lives at `sysroot/usr/lib/ld-linux-aarch64.so.1`
  - the repo-owned fix was to make the host-cross wrapper and runtime-bundle
    resolver both search the full repo-local sysroot library surface:
    - `sysroot/usr/lib`
    - `sysroot/usr/lib64`
    - `sysroot/lib`
    - `sysroot/lib64`
  - the root `Makefile` host-cross entrypoints were also tightened so
    `arm64-daemon-host-cross`, `cross-arm64-scx`, and `arm64-test-artifacts`
    all receive the explicit `ARM64_SYSROOT_*` contract instead of depending on
    whatever shared sysroot state happened to already exist
- That fix was validated directly first on the shortest path:
  - `make cross-arm64-scx ARM64_CROSSBUILD_SCX_PACKAGES=scx_rusty ...` now
    succeeds again
  - the promoted output contains:
    - `runner/repos/scx/target/release/scx_rusty`
    - `corpus/build/scx/scx_rusty_main.bpf.o`
- After that direct validation, the next canonical rerun was started again:
  - `make aws-arm64-test`
  - manifest token: `run.aws-arm64.test.A4gkww`
  - instance: `i-0ed82a611f59b0241`
  - active kernel: `7.0.0-rc2+`
  - this rerun is the current source of truth for the next AWS ARM64 blocker
- That rerun finally advanced all the way through:
  - AWS instance launch / reuse
  - custom kernel install / reboot / verification
  - host-cross daemon build
  - host-cross `scx` build
  - host-cross repo-owned unittest / negative builds
  - bundle upload
  - remote suite entry
- The next real runtime blocker exposed by the live remote suite is now:
  - upstream selftests build completed far enough to enter repo-owned tests
  - `rejit_daemon_e2e` then failed the daemon `optimize-all` request with:
    - `failed to rank optimize-all programs by hotness`
    - `hotness ranking requires kernel.bpf_stats_enabled=1 or a loaded profile snapshot`
  - this means the daemon-based suite runtime contract had not been enabling
    `kernel.bpf_stats_enabled=1` before running daemon-driven tests
- The repo-owned fix is now staged in the shared suite entrypoint itself:
  - `runner/scripts/suite_entrypoint.sh` now enables
    `kernel.bpf_stats_enabled=1` for every suite whose manifest declares
    `RUN_NEEDS_DAEMON_BINARY=1`
  - this deliberately makes the requirement explicit for:
    - `test`
    - `corpus`
    - `e2e`
  - the fix is shared-suite contract cleanup, not a one-off patch to
    `rejit_daemon_e2e`
- The completed `A4gkww` rerun ended with:
  - `30 passed, 1 failed`
  - no second ARM-specific runtime failure showed up in that run
  - the single failure remained `rejit_daemon_e2e`, which matches the missing
    `bpf_stats_enabled` runtime precondition above
- The next canonical rerun after the shared `bpf_stats_enabled` fix was:
  - `make aws-arm64-test`
  - manifest token: `run.aws-arm64.test.LoYLwx`
  - fetched result dir:
    `./.cache/aws-arm64/results/test_run.aws-arm64.test.LoYLwx_20260405_141935`
  - final result:
    - upstream `test_verifier`: `527 PASSED, 264 SKIPPED, 0 FAILED`
    - upstream `test_progs`: `112/1599 PASSED, 565 SKIPPED, 0 FAILED`
    - overall suite summary: `31 passed, 0 failed`
  - `rejit_daemon_e2e` passed in that rerun, confirming that the shared
    `kernel.bpf_stats_enabled=1` runtime setup fixed the only failure seen in
    `A4gkww`

### 10.3 Intentionally not done yet

- No full AWS ARM64 validation run after this refactor yet.
- No full AWS x86 validation run after this refactor yet.
- The first canonical `aws-x86-test` rerun after the staged refactor did not
  fail on executor logic or remote setup:
  - it reached local x86 `modules_install`
  - it then failed because the repo host root filesystem was already full
  - the exact failure was:
    `cp: ... BusLogic.ko ... No space left on device`
  - this was local disk pressure from generated cache / failed-run artifacts,
    not a target-specific x86 correctness failure
- Local cache pressure was then reduced conservatively:
  - failed and regenerable `.cache/aws-x86/*` run-stage directories were
    deleted
  - regenerable `.cache/kvm-staged/*`, verification caches, and stale ARM
    setup/kernel-build caches were deleted
  - AWS state and canonical result directories were kept
  - root filesystem free space recovered to roughly `49G`
- A new canonical `aws-x86-test` rerun is now in progress from that cleaned
  state and should be treated as the current x86 source of truth.
- The completed rerun `run.aws-x86.test.UaOyLz` then exposed the first real x86
  suite-runtime blocker:
  - upstream `test_verifier` failed with
    `GLIBC_2.38 not found (required by ./test_verifier)`
  - every repo-owned unittest / negative binary then failed with bundled
    `workspace/lib/libc.so.6` reporting
    `undefined symbol: __tunable_is_initialized, version GLIBC_PRIVATE`
  - this showed the x86 bundle contract was wrong in two separate ways:
    - bundled host-built upstream selftests were executed without per-binary
      portable loader wrapping
    - repo-owned x86 test binaries inherited a global `LD_LIBRARY_PATH` that
      pointed at bundled host glibc, which is invalid for same-arch AWS x86
      runs
- The x86 runtime contract was then tightened:
  - x86 no longer uses global `LD_LIBRARY_PATH` injection from
    `suite_entrypoint.sh`
  - x86 test bundle staging now wraps unittest / negative / upstream selftest
    executables the same way runner/daemon were already wrapped
  - the next canonical rerun is `run.aws-x86.test.Jt3gqK`
- That rerun then exposed one more bundle-contract gap before remote execution:
  - `build_remote_bundle.sh` failed on bundled upstream selftests helper
    `urandom_read`
  - the failure was not a missing system package; it was a local sibling shared
    library contract:
    `missing runtime library ... liburandom_read.so`
  - the fix is to treat the executable's own directory as part of both:
    - wrapper runtime search paths
    - local `ldd` resolution during bundle-time runtime-lib staging
- The next completed canonical rerun `run.aws-x86.test.fbMSXt` then reached the
  remote suite and exposed the next x86-only bundle-runtime bug:
  - wrapped repo-owned test binaries were still failing because the generated
    portable wrapper script embedded the host-local absolute path of
    `${wrapper_path}.bin` at bundle-build time instead of resolving the sibling
    `.bin` relative to the wrapper path on the remote host
  - the wrapped `.bin` payloads also retained their executable bit, so the
    old shell unittest discovery path picked them up as separate `rejit_*`
    tests and tried to execute the raw ELF payload directly
  - that produced two visible failure modes in the same run:
    - wrapper invocations reported host-local paths like
      `/home/yunwei37/workspace/.../rejit_swap_tests.bin` on the remote host
    - direct raw `.bin` execution failed against AWS AL2023 with
      `GLIBC_2.38 not found`, which is expected when the portable wrapper is
      bypassed
- The repo-owned fix is now staged in `runner/scripts/build_remote_bundle.sh`:
  - portable and passthrough wrappers now derive `real_binary` from the runtime
    wrapper path itself (`script_path + ".bin"`)
  - wrapped `.bin` payloads now have their execute bit stripped so the shared
    `find ... -executable` unittest enumeration no longer runs them directly
  - the same no-exec rule also now applies to bundled x86 runner / daemon
    `.bin` payloads
- A fresh canonical rerun is now in progress from that fix:
  - `make aws-x86-test`
  - manifest token: `run.aws-x86.test.W00mm6`
- `run.aws-x86.test.W00mm6` completed local staged prep far enough to produce
  its workspace and bundle inputs, including:
  - x86 kernel/modules build
  - x86 daemon build
  - promoted `scx` checkout build
  - local upstream selftests build into the per-run prep root
- It then failed during local bundle assembly with:
  `manifest is missing explicit x86 scx inputs`
- The repo-owned fix is now staged in `runner/scripts/build_remote_bundle.sh`:
  - x86 `scx` bundle staging now only requires `RUN_LOCAL_PROMOTE_ROOT`
  - repo-root derivation stays centralized in bundle-load setup
- `run.aws-x86.test.W00mm6` did not fetch a canonical result directory under
  `.cache/aws-x86/results`, so it should be treated as a superseded local-prep
  attempt, not as a test result source of truth.
- The current live canonical rerun is now:
  - `make aws-x86-test`
  - manifest token: `run.aws-x86.test.1xrAOp`
- No full x86 KVM benchmark validation run after this refactor yet.
- Canonical x86 KVM correctness has moved forward:
  - `make vm-test` on the staged-only `x86-kvm` path now reaches a green guest
    result again
  - latest observed guest transcript ended with:
    - `RESULTS: 31 passed, 0 failed`
    - `vm-test: ALL PASSED`
  - the outer runner/QEMU process also exited cleanly afterward
  - the remaining KVM work is now the ordered suite validation:
    `vm-micro`, `vm-corpus`, `vm-e2e`
- ARM64 still uses the Docker/qemu path for `micro_exec`. `daemon`, `scx`, and
  repo-owned ARM test binaries have now been moved out, and upstream selftests
  have been moved to a remote-native build phase on AWS ARM instead of local qemu.
  That was a temporary transition stage; the runner-binary mode knob has since
  been removed from active code.
  host-cross.
- Guest prerequisite policy is still split across three active scripts.
- `aws_executor.sh` is now a pure executor entrypoint; the remaining AWS design
  debt is concentrated in `aws_common_lib.sh` and shared local-prep contracts,
  not in the public executor surface.
- The root `Makefile` no longer exports broad mutable `AWS_*` helper defaults
  into the whole build, but it still remains a thin user-input layer on top of
  the target contract. That part is acceptable; the remaining cleanup is in the
  executor and manifest surface, not another round of top-level env export
  removal.
- AWS benchmark parallelization is now an enabled software contract:
  - benchmark manifests carry `RUN_AWS_INSTANCE_MODE=dedicated`
  - dedicated benchmark runs use per-run local prep roots
  - dedicated benchmark runs use unique per-run EC2 instances and remote
    workspaces
  - full runtime validation of this new path is still pending
- Kernel-adjacent shared build state still exists:
  - the shared kernel source/build trees remain intentionally locked
  - x86/ARM kinsn modules and ARM upstream selftest kmods still consume those
    shared kernel build trees rather than fully isolated kernel build roots
- No claim of green status should be made until the review pass and ordered validation pass complete.

## 11. Open Questions To Resolve In Review

The subagent review should focus on these points:

- Is `aws_common_lib.sh` still carrying target/suite policy that should live in the manifest instead?
- Is any remaining path still relying on ambient environment instead of explicit manifest data?
- Is bundle assembly truly manifest-driven, or are there still stale-output leak paths?
- Is any remote suite path still mutating machine-global state outside kernel install / package prereqs?
- Is the new x86 KVM staged-workspace wiring through `prepare_local_inputs.sh`
  and `kvm_executor.sh` thin and correct, or does it still preserve too much
  host-side special-casing?
- Is the remaining third-party build compatibility handling
  (`suite_entrypoint.sh`, `build_corpus_native.py`) the minimum necessary shape, or
  can it be reduced further without reintroducing source patching or remote
  native build?

### 11.1 Parallelization Direction

The current AWS parallelization shape is:

- local prep and remote execute are separate phases
- every target/suite run gets its own mutable per-run prep root
- target-level caches are reused as inputs, not reused as the mutable working
  directory for a live run
- global locks remain only around truly shared mutable resources such as:
  - kernel source/build trees
  - the ARM64 cross-build image build

For the current codebase, that now means:

- `aws-arm64` and `aws-x86` benchmark runs may overlap because they no longer
  share one cached benchmark instance
- local prep may overlap as long as it stays inside per-run roots and respects
  explicit shared-resource locks
- same-target shared correctness runs still serialize the remote execution step
  because they intentionally reuse one cached target instance

### 11.2 Current Commit Split

The current dirty worktree looks cleanest when split this way:

1. Artifact contract fixes:
   - `e2e/cases/bcc/setup.sh`
   - `runner/libs/app_runners/katran_support.py`
   - `runner/scripts/build_corpus_native.py`
   - `runner/repos.yaml`

2. Staged bundle / suite-needs / KVM explicit-workspace changes:
   - `runner/scripts/build_remote_bundle.sh`
   - `runner/scripts/prepare_local_inputs.sh`
   - `runner/scripts/kvm_executor.sh`
   - `runner/scripts/load_run_contract.sh`
   - `runner/scripts/run_target_suite.sh`
   - `runner/scripts/suite_entrypoint.sh`
   - `runner/scripts/run_vm_shell.py`
   - `runner/libs/vm.py`
   - `runner/libs/__init__.py`
   - `runner/Makefile`
   - `runner/suites/*.env`
   - the related root `Makefile` changes that remove dead local-ARM / legacy VM entrypoints

3. AWS executor state/reuse/parallel-prep work:
   - `runner/scripts/aws_executor.sh`
   - `runner/scripts/cross-arm64-build.sh`
   - `runner/scripts/install_guest_prereqs.sh`
   - the related root `Makefile` changes for ARM runtime-target gating and reuse

4. Documentation and canonical result artifacts:
   - `docs/tmp/aws_arm64_remote.md`
   - `micro/results/*`
   - `corpus/results/*`

This split is cleaner than one large mixed commit because the AWS executor and
parallelization work is still the least settled part of the tree.

### 11.3 Latest Full-Tree Reviewer Findings

Two full-project reviewer passes on the current dirty tree converged on the
same remaining issues:

- The broad refactor is still not commit-clean.
- The biggest remaining structural problems are:
  - `aws_common_lib.sh` is still too large and still mixes multiple AWS shared
    concerns in one file
  - remote bundle assembly still depends on executor-injected or
    executor-written local-input paths rather than a smaller sealed manifest
  - the AWS ARM upstream-selftests path still changes the effective upstream
    testcase surface through repo-owned orchestration

The concrete high-severity reviewer findings to keep in view are:

- `aws_common_lib.sh` is still the least-settled file in the tree:
  - it still owns EC2 lifecycle, setup gating, kernel/setup helper logic, and
    other shared AWS concerns in one file
  - it still deserves another shrinking pass even though public local prep and
    public execution are now split out cleanly
- `build_remote_bundle.sh` still consumes many local bundle-input paths through
  the per-run manifest. x86 now derives runner/daemon/test/repo/micro inputs
  from `RUN_LOCAL_PROMOTE_ROOT`, and ARM64 now derives most runtime/test
  artifact paths from `ARM64_CROSSBUILD_OUTPUT_DIR` and
  `ARM64_TEST_ARTIFACTS_ROOT`; the remaining explicit surface is smaller but
  still not yet at the intended final contract.
- The AWS ARM selftest path is cleaner than before but still semantically
  differs from upstream selftests through blacklist/filter/shim orchestration
  in `build_upstream_selftests.sh`.

Some earlier reviewer findings are now closed and should not be treated as
current blockers anymore:

- The root `Makefile` no longer exports broad AWS helper defaults as a second
  control plane for canonical runs.
- The ARM helper targets are now internal-only (`__arm64-*`, `__cross-arm64*`)
  and are no longer public user-facing entrypoints.
- Canonical KVM staged runs now build promoted native repos against staged
  checkouts rather than live `runner/repos`.
- The x86 bundle contract now accepts `RUN_LOCAL_PROMOTE_ROOT` as the primary
  x86 local-input root; x86 runner/daemon/test paths no longer have to be
  written individually into the manifest, and the x86 repo root plus micro
  generated-program directory also now derive from that same promote root. x86
  kinsn module staging now also lives under that same promote root.
- Executor-local staging paths such as `RUN_INPUT_STAGE_ROOT` and
  `RUN_BUNDLE_TAR` are no longer written back into the manifest; they now stay
  local to the executor/bundle-build call boundary.

The reviewers also agreed on commitability boundaries:

- Small dead/compat cleanup slices can be committed independently.
- The broad AWS/ARM host-cross + sysroot + executor refactor is still not ready
  to commit as one clean unit.
- Scratch design/log docs and incomplete benchmark result directories must not
  be mixed into a “clean refactor” commit.

These findings supersede any earlier optimistic claim that the current broad
runner diff is close to a clean landing point.

## 12. Known Historical Context

The minimal already-pushed bug-fix commit that stays independent from this large refactor is:

- `4ae9df0 Fix bundled tool resolution and portable hotswap tests`

That commit is not the runner refactor.
It remains valid and separate.

## 13. Current Live Status And Todo

### 13.1 Active Execution Policy

The current execution policy is:

- local KVM suite execution stays serialized
- AWS local prep/build may overlap when each run uses an isolated per-run root
  and explicit host locks only around truly shared mutable resources
- AWS benchmark remote execution is intended to overlap only after the
  refactor gate below is clean and reviewers return `No findings`
- no new real-path validation runs should start while the tree is still in the
  refactor-and-static-review phase

### 13.2 Current Remote Benchmark Contract

The intended remote benchmark contract remains:

- one local per-run prep root per lane
- one dedicated AWS instance per benchmark lane
- one dedicated remote workspace per lane
- remote prep owns only instance / kernel / base-prereq convergence
- local prep owns all bundle inputs
- runtime prereqs consume only the finished bundle contract
- no shared remote benchmark execution lock across benchmark lanes

### 13.3 Workload Tool Provisioning Decision

The current workload-tool contract is:

- x86 and KVM both stage the same bundle-owned workload tools during local prep
- bundled workload tools are declared explicitly by
  `RUN_BUNDLED_WORKLOAD_TOOLS_CSV`
- the local path that feeds the bundle is declared explicitly by
  `RUN_LOCAL_WORKLOAD_TOOL_ROOT`
- the workspace-local runtime tool bin is sealed explicitly by:
  - `RUN_REMOTE_WORKLOAD_TOOL_BIN`
- remote/guest prereqs must recognize bundled tools before falling back to the
  package manager
- no remote source-build of workload tools
- no writes of bundle-owned tools into machine-global system paths

### 13.4 Current Review Gate

Current status:

- no canonical real-path validation process is intentionally left running
- the tree is in refactor + static-review mode
- the immediate goal is to finish structural cleanup and get reviewer
  `No findings` before restarting runtime validation
- current static gates are green:
  - `python3 -m compileall -q runner/libs runner/scripts tests/python e2e daemon docs/paper/helpers`
  - `python3 -m pyflakes runner/libs runner/scripts tests/python e2e docs/paper/helpers`
  - `git diff --check`
  - `pytest` focused runner suite: `14 passed`
  - `make -n` on canonical aliases stays thin and side-effect free

### 13.5 Current Immediate Todo

1. Finish the remaining local-prep convergence work so KVM and AWS differ only
   in executor transport and machine lifecycle.
2. Keep the repo-selection contract explicit:
   - do not reintroduce `RUN_BENCHMARK_REPOS_CSV`
   - `RUN_BUNDLED_REPOS_CSV` for repos that must exist in the bundle
   - `RUN_FETCH_REPOS_CSV` for the full local fetch set
3. Keep the workload-tool contract explicit:
   - local prep stages bundled tools
   - bundle inputs carry the tool root explicitly
   - remote/guest prereqs and validation must not silently replace missing
     bundled tools with system-package installs
4. Keep shrinking the remaining ARM qemu/containerized prep surface.
   - ARM workload-tool source fetch is now pinned to explicit refs and cached
     under the local source-cache root instead of cloning upstream HEAD
5. Re-run whole-tree reviewer passes and keep fixing findings until they return
   `No findings`.
6. Keep this document aligned with the current Python-only control plane and
   delete stale shell-era wording when found.
7. Only after that, restart the real validation matrix.

### 13.7 2026-04-05 Parallel Benchmark Blocker And Fix

The first real blocker from the canonical parallel benchmark fan-out was not a
remote AWS problem. Both `aws-arm64-benchmark` and `aws-x86-benchmark` failed
locally in `aws_executor.sh` with:

- `x86 kernel build did not produce a kernel release`
- `ARM64 kernel build did not produce a kernel release`

This turned out to be an executor locking bug, not a kernel build failure:

- the built kernel release files were present locally:
  - `vendor/linux-framework/include/config/kernel.release`
  - `.cache/aws-arm64/kernel-build/include/config/kernel.release`
- but the executor lock helpers were still implemented as subshell wrappers:
  - `with_x86_kernel_lock() ( ... )`
  - `with_arm64_kernel_lock() ( ... )`
  - `with_state_lock() ( ... )`
  - `with_remote_execution_lock() ( ... )`
- `BUILD_KERNEL_RELEASE` was assigned inside the locked function and then lost
  when the subshell exited

That bug was especially visible only after enabling benchmark parallel fan-out,
because both arm/x86 benchmark setup lanes now hit the same local kernel-build
path independently.

The fix is now:

- use same-shell explicit-FD locks via `with_locked_file()`
- keep the lock semantics, but let variables such as `BUILD_KERNEL_RELEASE`
  survive after the locked function returns

The failed fan-out sessions that exposed this were:

- ARM benchmark session `86175`
- x86 benchmark session `90426`

Those sessions were started before the lock fix landed, so their failures are
expected stale results. They should not be treated as post-fix benchmark
verdicts.

### 13.8 Updated Immediate Todo

1. Relaunch the canonical parallel AWS benchmark fan-out after the same-shell
   lock fix:
   - `make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=all`
   - `make aws-x86-benchmark AWS_X86_BENCH_MODE=all`
2. Watch for the next true blocker after the lock fix; do not conflate stale
   pre-fix failures with current executor behavior.
3. Keep reconciling reviewer findings against the latest tree; several earlier
   findings were already overtaken by later executor/bundle-contract changes.
4. Do not cut a broad runner commit until:
   - the current benchmark-parallel contract has passed at least one fresh
     post-fix run, and
   - the full-project reviewer pass no longer reports structural
     inconsistencies in the executor/bundle boundary.

### 13.9 2026-04-05 x86 Setup Cache Corruption And Per-Run Micro Prep

The next concrete post-fix benchmark blocker showed up on AWS x86 after the
same-shell lock repair:

- remote setup failed with:
  - `gzip: stdin: unexpected end of file`
  - `tar: Unexpected EOF in archive`
- this was not a transient network/SCP problem

The local cached x86 setup artifact itself was corrupt:

- `.cache/aws-x86/setup-artifacts/x86/7.0.0-rc2+/modules-7.0.0-rc2+.tar.gz`
- local validation of that file reproduced:
  - `EOFError('Compressed file ended before the end-of-stream marker was reached')`

That exposed a real asymmetry between x86 and ARM setup cache reuse:

- ARM already validates cached setup artifacts before reuse
- x86 previously only checked for file existence

The fix now applied is:

- x86 setup cache reuse must validate the cached modules tar before reusing it
- invalid cached tarballs are discarded and rebuilt
- freshly generated x86 modules tarballs are also validated before being linked
  into the per-run artifact root

The corrupted cached x86 setup directory was removed before the fresh rerun so
the next x86 benchmark run would rebuild it under the new validation contract.

At the same time, one more remaining parallel-prep design bug was removed:

- AWS benchmark local prep no longer rebuilds `micro/programs` in the shared
  repo-root output directory
- it now builds micro generated programs into a per-run promoted output root
  and passes that explicit path into the bundle input contract

This removes one more same-arch local-prep collision point from the benchmark
fan-out path.

### 13.10 2026-04-05 Updated Parallel Execution Contract

The execution policy is now narrowed to the shape actually needed by this
repository:

- local KVM suite execution stays serialized
- AWS local prep may run in parallel when each run owns:
  - a per-run prep root
  - explicit per-arch locks around shared host resources
- AWS remote benchmark execution may run in parallel only when each benchmark
  lane owns:
  - a dedicated AWS instance
  - a dedicated remote workspace

This is intentionally narrower than "parallelize everything":

- correctness runs and remote AWS benchmark lanes can overlap when they do not
  share mutable state
- local KVM remains serialized
- host-side shared resources such as kernel build trees and the ARM sysroot stay
  protected by explicit locks instead of being implicitly serialized by a single
  giant executor lock

### 13.11 2026-04-05 ARM Parallel Prep Permission Bug

After enabling the new benchmark fan-out contract, the next concrete ARM
blocker was a host-side path ownership bug, not a remote AWS problem.

The first fresh ARM benchmark fan-out hit:

- `mkdir: cannot create directory .../arm64-cross/cargo-home: Permission denied`

Root cause:

- the host-side `scx` cross-build path (`build-arm64-scx-host.sh`) was still
  using:
  - `ARM64_SCX_BUILD_ROOT="$(ARM64_CROSSBUILD_BUILD_ROOT)"`
  - `ARM64_SCX_CARGO_HOME="$(ARM64_CROSSBUILD_CARGO_HOME)"`
- those paths live under the container-oriented `arm64-cross/` root
- that root can be created by the ARM64 container as `root:root`
- once benchmark lanes were allowed to overlap, the host-side `scx` build hit
  that root-owned directory and failed immediately

The fix is now structural rather than chmod-based:

- host-side ARM `scx` no longer shares the container cross-build root
- it now uses its own per-run host root:
  - `ARM64_HOST_SCX_ROOT`
  - `ARM64_HOST_SCX_BUILD_ROOT`
  - `ARM64_HOST_SCX_CARGO_HOME`
- the container-oriented `arm64-cross/` root remains reserved for the
  `linux/arm64` container path only

The stale failed ARM benchmark session that exposed this was `4446`.
A fresh ARM benchmark rerun was launched after the fix:

- new ARM benchmark session: `52772`
- new run tokens:
  - `run.aws-arm64.micro.UUnko3`
  - `run.aws-arm64.corpus.BJ9qVr`
  - `run.aws-arm64.e2e.NVcmX9`

At the same time, the x86 parallel benchmark rerun remained live as session
`17088`.

### 13.12 2026-04-05 Target-Level AWS Terminate Semantics

One more real operational bug remained even after dedicated benchmark instances
were introduced:

- canonical `aws-*-terminate` could still be narrowed to one shared-state
  instance instead of cleaning all instances for the target
- that left stale dedicated benchmark instances behind when an earlier
  benchmark fan-out failed mid-run

The bug was in terminate semantics rather than EC2 itself:

- `terminate_instance()` still fell back to `STATE_INSTANCE_ID` from shared
  state when no explicit instance id was provided
- that meant target-level terminate was not guaranteed to kill all
  role-tagged dedicated benchmark instances

The fix is now:

- when canonical terminate is called without an explicit instance id, terminate
  all instances tagged with:
  - `Project=bpf-benchmark`
  - `Role=<target>`
- clear both the shared state dir and the per-run `run-state/` tree for that
  target
- only the explicit-instance path keeps the narrower single-instance behavior

This makes target-level cleanup coherent with the dedicated-instance benchmark
model.

### 13.13 2026-04-05 x86 Benchmark Blockers After Parallel Fan-Out

The first fresh x86 benchmark fan-out produced two concrete blockers:

1. A stale `micro` lane failed in local bundle assembly with:
   - `micro generated programs dir is not a directory`
2. Fresh `corpus` and `e2e` runs failed remotely with:
   - `insmod ... bpf_bulk_memory.ko: Invalid module format`

The micro issue was not a benchmark-semantics problem. It exposed that the
executor did not verify the per-run generated micro program directory
immediately after local prep. The executor now fails earlier and explicitly if
`MICRO_PROGRAMS_GENERATED_DIR` was not materialized.

The x86 `kinsn` failure is more structural:

- the staged modules had the expected `vermagic` (`7.0.0-rc2+`)
- the remote instances were also running `7.0.0-rc2+`
- so the failure was not a simple release-string mismatch

The design issue is that x86 `kinsn` modules were still being built during
benchmark prep against the live shared `vendor/linux-framework` build tree,
while the instances booted from sealed cached x86 setup artifacts. That leaves
room for module CRC / modversion drift even when the release string stays the
same.

The fix now applied is:

- x86 `kinsn` modules are sealed into the x86 setup-artifact cache alongside
  the kernel image, vmlinux, and module tarball
- benchmark/test local prep stages x86 `kinsn` modules from that sealed
  per-release cache instead of rebuilding them against the live tree
- if the cached x86 `kinsn` module bundle is missing or invalid, the executor
  invalidates that cached setup-artifact directory and rebuilds it under the
  x86 kernel lock

Fresh reruns were then launched on the updated executor:

- x86 micro fresh rerun: `61572` (`run.aws-x86.micro.QRoClC`)
- x86 corpus fresh rerun: `40586` (`run.aws-x86.corpus.nqteHn`)
- x86 e2e fresh rerun: `79203` (`run.aws-x86.e2e.AkcqGH`)

### 13.14 2026-04-05 Remote Workload Tools Moved To Per-Run State

One more real parallelism leak remained even after dedicated benchmark
instances and per-run local prep roots were introduced:

- remote workload tools (`hackbench`, `sysbench`, `wrk`) were still being
  provisioned under a machine-global path
  (`/var/tmp/bpf-benchmark/workload-tools`)
- the shared suite runner then prepended that machine-global bin dir during
  execution
- that meant benchmark runs on the same target family still depended on a
  second remote control plane outside the per-run workspace contract

The fix now applied is:

- `aws_remote_prereqs.sh` defaults its stamp and workload-tool root to the
  per-run prereq directory next to the copied manifest instead of `/var/tmp`
- workload tools must now materialize under that per-run bin dir; source-build
  helpers no longer silently treat a machine-global `command -v` hit as
  success
- `aws_executor.sh` copies that per-run workload-tool tree into the unpacked
  run workspace before suite execution
- `suite_entrypoint.sh` now defaults to the workspace-local
  `.cache/workload-tools/bin`

This does not eliminate package-manager use on the remote host, but it does
eliminate the old hidden shared `workload-tools` tree and makes concurrent AWS
benchmark lanes consume per-run tool roots.

### 13.15 2026-04-05 Benchmark Prep Graph Narrowed By Suite

Another avoidable source of local contention remained in the benchmark prep
graph itself:

- `micro` prep still built daemon/`scx`/`kinsn` artifacts even though the
  remote micro bundle only needs generated programs plus the runner runtime
- `corpus`/`e2e` prep still built the x86 runner even though those suites do
  not consume `micro_exec`

This was visible in the live x86 micro lane, which progressed into a local
Rust daemon build even after kernel setup had already completed.

The prep graph is now narrowed:

- `micro`
  - generates micro programs
  - builds only the suite-required runner runtime
- `corpus` / `e2e`
  - build only daemon / `scx` / `kinsn` / native repo artifacts required by
    those suites
  - no longer pull in the x86 runner as incidental work

This reduces same-target host contention and makes the new parallel AWS
benchmark model closer to “only prepare what the bundle contract actually
needs”.

### 13.16 2026-04-06 ARM kinsn Snapshot And Cache Contract Fix

The first fresh AWS ARM benchmark failure after the parallel benchmark fan-out
was no longer in EC2 control flow. It was in the ARM `kinsn` module contract:

- ARM `e2e` hit `fatal error: kinsn_common.h: No such file or directory`
- the same lane then surfaced `ARM64 kinsn module release mismatch for
  bpf_bulk_memory.ko`

Root cause:

- ARM `kinsn` rebuilds were snapshotting only `module/arm64`
- the module Makefile expects the shared header at `../include/kinsn_common.h`
- so the per-run rebuild tree was incomplete
- unlike x86, ARM `kinsn` modules were also still being validated from the live
  rebuild tree rather than a sealed per-release cache

The fix now applied is structural:

- `snapshot_kinsn_module_source_tree()` snapshots both:
  - `module/<arch>`
  - `module/include`
- x86 and ARM now both build `kinsn` modules from that complete snapshot shape
- ARM now mirrors x86's sealed per-release `kinsn` cache model under the AWS
  setup-artifact cache
- suite execution also no longer accepts workload tools from ambient system
  `PATH`; required tools must exist in the workspace-local tool bin

The failed lane that exposed this was the old ARM benchmark-all session
`52772`, specifically its `e2e` lane. A fresh ARM `e2e` rerun should be used as
the next correctness gate for this fix.

### 13.17 2026-04-06 Local Prep Root Auto-Cleanup And Disk Recovery

The next concrete blocker was no longer AWS correctness. It was local disk
pressure caused by accumulated per-run prep roots:

- `/` dropped to ~`7.6G` free
- `.cache/aws-x86/runs` alone had grown to ~`11G`
- stale `.cache/aws-arm64/runs/*` directories also still held multi-GB
  host-side cross-build trees

Two things were done:

1. Immediate recovery:
   - stale `.cache/aws-x86/runs/*` directories were deleted
   - stale `.cache/aws-arm64/runs/*` directories were deleted, keeping only the
     live `run.aws-arm64.e2e.RltWwb` lane
   - free space recovered to ~`29G`

2. Structural fix:
   - `aws_executor.sh` now cleans `RUN_PREP_ROOT` automatically after AWS runs
   - cleanup is also wired into the failure path via trap
   - cleanup falls back to `sudo rm -rf` when host-side container-created files
     are root-owned

This keeps per-run local isolation without letting dead prep trees accumulate
until they exhaust the host filesystem.

### 13.18 2026-04-06 Fresh Post-Fix Reruns In Flight

After the ARM `kinsn` snapshot/cache fix and the local prep cleanup fix:

- fresh AWS ARM `e2e` rerun: session `56049`
  - run token: `run.aws-arm64.e2e.RltWwb`
  - current state: remote prereq phase has advanced past the old
    `kinsn_common.h` failure and is now building workload tools under the
    per-run prereq root
- fresh AWS x86 benchmark-all rerun: session `96095`
  - all three dedicated lanes relaunched under the new contract
  - current state: launching three `aws-x86` instances for `micro`, `corpus`,
    and `e2e`

Old x86 benchmark sessions that were started before the latest prep-graph,
remote tool-root, and cleanup changes are no longer treated as final gates.

### 13.19 2026-04-06 x86 Fresh Benchmark Blockers Tightened Again

The first post-cleanup x86 benchmark-all rerun then exposed three concrete
repo-owned orchestration problems:

- `corpus` failed because `stress-ng` was installed on the remote instance but
  was not staged into the workspace-local workload tool bin that
  `suite_entrypoint.sh` now requires
- an earlier `e2e` local-native `tracee` build failed with Go VCS stamping in
  the archived checkout (`error obtaining VCS status: exit status 128`)
- newer x86 `corpus` / `e2e` failures also showed `Invalid module format` for
  `bpf_bulk_memory.ko`, which means the x86 `kinsn` cache contract was still
  too weak when the kernel release string stayed the same across config drift

The fixes now applied are:

- `aws_remote_prereqs.sh`
  - after package-manager installs, stage every required non-`bpftool`,
    non-Python, non-source-built tool into the per-run workload-tool bin
- `build_corpus_native.py`
  - build `tracee` with repo-owned `GOFLAGS=-buildvcs=false`
  - this keeps the fix in our orchestration instead of patching third-party
    source
- `aws_executor.sh`
  - x86 setup artifact reuse is now gated by a stored `.config` fingerprint,
    not just `uname -r`
  - x86 cached `kinsn` modules therefore stop reusing same-release but
    incompatible module builds

After those fixes:

- fresh x86 benchmark-all rerun: session `55703`
  - `micro` token: `run.aws-x86.micro.3CUtSn`
  - `corpus` token: `run.aws-x86.corpus.Vum15r`
  - `e2e` token: `run.aws-x86.e2e.gEXjXH`
- ARM `e2e` live rerun `run.aws-arm64.e2e.RltWwb` is still progressing; it is
  already past the old `kinsn_common.h` failure and has reached deeper ARM
  native benchmark artifact builds (`bcc` / `libbpf-tools`)

The fresh x86 `corpus` lane has already verified the workload-tool fix in
place on the live remote instance:

- workspace-local tool bin:
  `/home/ec2-user/bpf-benchmark-aws-x86/prereq/run.aws-x86.corpus.Vum15r/workload-tools/bin`
- confirmed present there:
  - `stress-ng`
  - `fio`
  - `bpftrace`
  - `sysbench`
  - `hackbench`

So the previous `required workload tool is missing from the workspace-local
tool bin` failure is no longer the active x86 `corpus` blocker.

### 13.20 2026-04-06 ARM Benchmark Local QEMU Shrink And Fresh ARM Relaunch

The next benchmark-shape issue was no longer remote correctness. It was that
AWS ARM benchmark prep was still spending local time in `docker --platform
linux/arm64` / `qemu-binfmt` even when the suite did not truly need a locally
prebuilt ARM runner binary.

What was confirmed:

- `daemon` host cross-compile had already been moved out of the ARM container
- the remaining local `qemu` use on the benchmark path was mostly coming from:
  - `micro`: local ARM `micro_exec` build
  - `corpus` / `e2e`: `ensure_cross_arm64_runtime()` still asking for
    `runner,daemon` together, even though those suites only need the daemon
- a direct host-cross attempt for `micro_exec + llvmbpf` is not trivial on this
  host:
  - the host has GNU ARM cross compilers and the Rust target
  - but it does not have a clean ARM LLVM / yaml-cpp / libelf userland contract
    that matches the remote AL2023 runtime baseline
  - an attempted package-based path (`libllvm20:arm64`, `llvm-20-dev:arm64`,
    `libyaml-cpp-dev:arm64`, `libelf-dev:arm64`, `zlib1g-dev:arm64`) also hit
    the host's current apt resolver breakage and was not adopted as a repo
    contract

The temporary fix applied at that point was explicit and minimal:

- a short-lived manifest contract:
  - `RUN_RUNNER_BINARY_MODE=bundled|remote-native`
- `runner/targets/aws-arm64.env` temporarily defaulted ARM runner binaries to
  `remote-native`
- `build_remote_bundle.sh` temporarily staged the tracked runner source tree,
  plus `vendor/libbpf` and `vendor/llvmbpf`, when that mode was selected
- `suite_entrypoint.sh` temporarily built `runner/build/micro_exec` on the
  dedicated remote ARM instance in that mode
- `aws_remote_prereqs.sh` installed the then-needed remote-native runner build
  dependencies (`clang20`, `llvm20-devel`, `lld20`, `cmake`,
  `yaml-cpp-devel`, `elfutils-libelf-devel`, `zlib-devel`, etc.)
- `aws_executor.sh` computed ARM local runtime targets precisely:
  - `micro` no longer forced local `__cross-arm64` in that temporary mode
  - `corpus` / `e2e` no longer asked the ARM container to build `runner` when
    they only needed `daemon`

The benchmark contract at that point became:

- AWS ARM `micro`:
  - local: build/stage programs, fetch repos, seal bundle
  - remote: native-build `micro_exec`, then run benchmark
- AWS ARM `corpus` / `e2e`:
  - local: do not qemu-build an unnecessary ARM runner
  - remote: execute with the bundled daemon/native artifacts

The old ARM benchmark-all session using the previous contract was explicitly
terminated:

- old tokens:
  - `run.aws-arm64.micro.KGlQCL`
  - `run.aws-arm64.corpus.F0eUoG`
  - `run.aws-arm64.e2e.xfJMEN`

A fresh canonical ARM benchmark-all rerun is now in flight on the new contract:

- session `61337`
- tokens:
  - `run.aws-arm64.micro.R8frlw`
  - `run.aws-arm64.corpus.9wJz81`
  - `run.aws-arm64.e2e.2veoD4`

At the time of this log update:

- all three fresh ARM lanes have launched dedicated instances
- all three have acquired IPs and moved past EC2 `instance-status-ok`
- live state:
  - `micro` instance `i-004f20f8512950980` at `3.227.252.61`
  - `corpus` instance `i-02c132960f0eadd1a` at `35.172.230.83`
  - `e2e` instance `i-049126fe6f2831baf` at `3.231.210.48`
- each lane is currently in `aws_remote_prereqs.sh` installing the base AL2023
  runtime packages

### 13.21 2026-04-06 Current x86 Benchmark Live Status

The current x86 benchmark picture is now narrower than before:

- x86 `micro` is already green:
  - `micro_run.aws-x86.micro.3CUtSn_20260406_011335`
- x86 `corpus` and `e2e` reruns after the earlier libbpf / bpftrace / wrapper
  fixes are still the relevant lanes

Current evidence from the live tree:

- x86 `e2e` token `run.aws-x86.e2e.ZIy75v` is still active locally
- it is not stalled in AWS control-plane or SSH setup
- the current live local work is repo-owned `scx_rusty` artifact preparation:
  - `python3 runner/scripts/build_scx_artifacts.py --force ...`
  - then `clang ... -target bpf -c src/bpf/main.bpf.c`

So the current x86 active blocker is not the previously fixed remote runtime
issues. It is the remaining local `scx` artifact preparation on the x86 `e2e`
lane.

### 13.22 2026-04-06 ARM Remote-Native Micro Fix And AWS Benchmark Parallel Relaunch

The first real blocker from the fresh ARM benchmark-all rerun was on the
`micro` lane, and it was now precise:

- result dir:
  `.cache/aws-arm64/results/micro_run.aws-arm64.micro.R8frlw_20260406_031654`
- failure:
  `MICRO_EXEC_ENABLE_LLVMBPF=ON requires .../workspace/vendor/llvmbpf/libllvmbpf_vm.a`

This showed that the then-new temporary ARM `remote-native` runner contract was only half
complete:

- the remote host was now correctly building `runner/build/micro_exec`
- but the remote-native path still assumed `vendor/llvmbpf/libllvmbpf_vm.a`
  already existed in the workspace
- that archive used to come from the local ARM crossbuild path, which had
  just been removed from the `micro` fast path

The repo-owned fix was minimal:

- `runner/scripts/suite_entrypoint.sh` now builds `vendor/llvmbpf` remotely
  before invoking `make -C runner micro_exec` when:
  - `RUN_RUNNER_BINARY_MODE=remote-native`
  - `RUN_SUITE_NEEDS_LLVMBPF=1`
- it builds directly into:
  - `vendor/llvmbpf/build`
  - `vendor/llvmbpf/libllvmbpf_vm.a`
- this matches the existing `runner/CMakeLists.txt` contract instead of adding
  a second remote-specific artifact layout

At the same time, AWS remote benchmark parallelism was activated on the new
repo contract:

- AWS benchmark lanes now run in parallel when each lane has:
  - a dedicated run token
  - a dedicated instance
  - a dedicated remote workspace
- local KVM remains serialized
- current evidence from `run-state/*/instance.env` confirms dedicated
  instance allocation for benchmark lanes instead of one shared cached machine

Fresh live launches now in flight after this fix:

- ARM micro rerun:
  - session `29573`
  - token `run.aws-arm64.micro.bbGt7a`
- x86 benchmark-all rerun:
  - session `37140`
  - tokens:
    - `run.aws-x86.micro.ZJGENj`
    - `run.aws-x86.corpus.4zlVZI`
    - `run.aws-x86.e2e.bV12sn`

Observed state at this point:

- ARM `corpus` / `e2e` from session `61337` are still active and progressing
  independently on their own dedicated instances
- the new ARM `micro` rerun has already allocated a fresh instance:
  - `run.aws-arm64.micro.bbGt7a`
  - `STATE_INSTANCE_ID=i-02cd97ce4b9bebec9`
- the fresh x86 `micro` / `corpus` / `e2e` reruns have also each allocated a
  separate instance:
  - `run.aws-x86.micro.ZJGENj` -> `i-0840b8ec39afec89c`
  - `run.aws-x86.corpus.4zlVZI` -> `i-0ec0ca2dbe9fdaad2`
  - `run.aws-x86.e2e.bV12sn` -> `i-01d49e7c317d0cd8a`

This means the current bottleneck is no longer benchmark serialization policy.
The open work is now to watch each dedicated lane until it either produces a
result dir or surfaces the next real blocker.

### 13.23 2026-04-06 ARM Micro llvmbpf Blocker And Fresh Parallel AWS Relaunch

The first real blocker from the fresh ARM benchmark-all rerun was on the ARM
`micro` lane, and it was now concrete:

- result dir:
  - `.cache/aws-arm64/results/micro_run.aws-arm64.micro.R8frlw_20260406_031654`
- `remote.log` failure:
  - `MICRO_EXEC_ENABLE_LLVMBPF=ON requires .../vendor/llvmbpf/libllvmbpf_vm.a`

This showed that the new ARM `remote-native` runner contract had only gone
halfway:

- `suite_entrypoint.sh` did native-build `runner/build/micro_exec`
- but it did not first native-build `vendor/llvmbpf/libllvmbpf_vm.a`
- `runner/CMakeLists.txt` still correctly requires that archive when
  `MICRO_EXEC_ENABLE_LLVMBPF=ON`

The repo-owned fix was minimal and keeps the same build contract:

- `suite_entrypoint.sh` then built `vendor/llvmbpf` natively on the dedicated
  remote ARM instance before `make -C runner micro_exec`
- it uses the same layout already assumed by `runner/CMakeLists.txt`:
  - source root: `vendor/llvmbpf`
  - build dir: `vendor/llvmbpf/build`
  - archive output: `vendor/llvmbpf/libllvmbpf_vm.a`
- no new abstraction layer was added

At the same time, benchmark execution is now using the repo's parallel-AWS
policy rather than serializing everything behind one lane:

- a fresh ARM `micro` rerun was launched on the new fix:
  - token `run.aws-arm64.micro.bbGt7a`
- a fresh x86 benchmark-all rerun was also launched in parallel:
  - `run.aws-x86.micro.ZJGENj`
  - `run.aws-x86.corpus.4zlVZI`
  - `run.aws-x86.e2e.bV12sn`

Current live execution state after the relaunch:

- ARM:
  - older `corpus` and `e2e` lanes from the same benchmark-all rerun remain
    active on dedicated instances and are doing per-run isolated local prep
  - fresh `micro` has its own dedicated instance launch in progress
- x86:
  - fresh `micro`, `corpus`, and `e2e` now also have dedicated instance state
    dirs under `.cache/aws-x86/run-state/`
  - none of these share the local KVM serialization path

This is the current intended execution shape:

- local KVM stays serialized
- AWS benchmark lanes use per-run state dirs, dedicated instances, and
  dedicated remote workspaces
- AWS ARM and AWS x86 benchmark lanes may proceed in parallel as long as local
  prep stays per-run isolated and shared host resources remain lock-protected

### 13.24 2026-04-06 ARM Micro Green, x86 Micro Python Loader Pollution

The fresh ARM `micro` rerun with token `run.aws-arm64.micro.bbGt7a` validated
that temporary `remote-native` runner fix end-to-end:

- the earlier fatal error about missing
  `vendor/llvmbpf/libllvmbpf_vm.a` no longer reproduced
- direct remote inspection showed `suite_entrypoint.sh` building
  `vendor/llvmbpf/build` on the dedicated ARM instance with `clang++-20`
- the fetched `remote.log` now contains full benchmark output for all `62`
  micro cases
- ARM `micro` is therefore green on the new contract

At the same time, the fresh x86 `micro` rerun exposed a different concrete
problem:

- result dir:
  - `.cache/aws-x86/results/micro_run.aws-x86.micro.ZJGENj_20260406_032901`
- `remote.log` failure:
  - `python3.11: symbol lookup error: ... workspace/lib/libc.so.6:
    undefined symbol: __tunable_is_initialized, version GLIBC_PRIVATE`

The cause was repo-owned environment pollution:

- `suite_entrypoint.sh` was exporting `LD_LIBRARY_PATH=$WORKSPACE/lib:...`
  into the Python driver process itself
- x86 bundles intentionally contain a copied loader/glibc set for wrapped
  benchmark binaries
- that copied glibc must be used only by the wrapped binaries, not by the
  system `python3.11`

The applied fix is minimal:

- `cross_runtime_ld_library_path()` no longer prepends `$WORKSPACE/lib`
- repo-owned Python code still resolves bundled libbpf through
  `BPFREJIT_LIBBPF_PATH`
- x86/ARM bundled executables still resolve their private runtime through the
  generated wrapper scripts

After this fix, a fresh standalone x86 `micro` rerun was launched to validate
the corrected driver environment.

### 13.25 2026-04-06 x86 Corpus/E2E Stats Gate Was Too Strict

The next concrete x86 blocker came from the latest fetched `corpus` result:

- result dir:
  - `.cache/aws-x86/results/corpus_run.aws-x86.corpus.Vum15r_20260406_011748`
- first fatal error:
  - `RuntimeError: libbpf is missing bpf_prog_get_info_by_fd: libbpf.so.1`

The failure was not in benchmark logic itself. It was in the repo-owned stats
plumbing:

- `corpus/driver.py` enters `with enable_bpf_stats():`
- that context manager came from `runner/libs/bpf_stats.py`
- `runner/libs/bpf_stats.py` was stricter than `runner/libs/metrics.py`
- it rejected the current runtime `libbpf.so.1` during initialization if
  `bpf_prog_get_info_by_fd` was absent, even before any per-program sampling
  was attempted

This was unnecessary and inconsistent with the rest of the repo:

- the benchmark paths already use `bpftool -j prog show` as the primary stats
  source through `runner/libs/metrics.py`
- per-FD `libbpf` reads are only needed to enrich or backfill missing data
- failing the entire suite at context-entry time added a synthetic dependency on
  a bundled/shared `libbpf.so.1` that the benchmark contract did not otherwise
  require

The repo-owned fix was minimal:

- `runner/libs/bpf_stats.py`
  - no longer hard-fails during `_libbpf()` initialization just because
    `bpf_prog_get_next_id`, `bpf_prog_get_fd_by_id`, or
    `bpf_prog_get_info_by_fd` are absent
  - the specific helpers now raise only when the missing symbol is actually
    needed
- `runner/libs/metrics.py`
  - `sample_bpf_stats()` now treats `bpftool -j prog show` as the canonical
    source for already-visible per-program runtime counters
  - FD-based `libbpf` sampling is still used when available, but it no longer
    fails a run if the program already has a complete `bpftool` record
  - missing program IDs still fail loudly
- tests updated and passing:
  - `python3 -m pytest -q tests/python/test_bpf_stats.py tests/python/test_runner_contract.py tests/python/test_corpus_driver.py`
  - `14 passed`

This keeps the design simpler:

- no new runtime `libbpf.so.1` staging layer was added
- no fallback-to-silence was introduced
- the benchmark stats contract is now “`bpftool` is primary, FD info is
  supplemental”

Next action from this point:

- relaunch fresh x86 `corpus` and x86 `e2e` with the current fixes, instead of
  waiting on older bundles that were created before the stats-path correction

### 13.26 2026-04-06 x86 Micro Green, Fresh x86 Corpus/E2E Relaunched

The fresh standalone x86 `micro` rerun is now green:

- token:
  - `run.aws-x86.micro.ObIIbj`
- result dir:
  - `.cache/aws-x86/results/micro_run.aws-x86.micro.ObIIbj_20260406_033816`
- `remote.log` ends with:
  - `[done] wrote .../workspace/micro/results/aws_x86_micro_20260406_033829/metadata.json`
  - `ARTIFACT_DIR=.cache/suite-results/aws-x86_micro_20260406_033827`

This validates the earlier x86 Python/glibc environment fix end-to-end:

- the old `GLIBC_PRIVATE` symbol lookup error no longer reproduces
- x86 `micro` now matches ARM `micro` in the new benchmark contract

Because the older x86 `corpus/e2e` bundles were sealed before the stats-path
fix, fresh canonical reruns were launched immediately instead of waiting for
those older lanes to fail again:

- fresh x86 `corpus`:
  - token `run.aws-x86.corpus.6j0008`
  - dedicated instance `i-077684ae698aaf469`
- fresh x86 `e2e`:
  - token `run.aws-x86.e2e.sYo0p7`
  - dedicated instance `i-0ff43bef5e808d7b2`

Current intent from this point:

- keep ARM `corpus/e2e` running
- keep the fresh x86 `corpus/e2e` reruns running
- take the next blocker only from the fresh reruns, not from superseded older
  bundles

### 13.27 2026-04-06 Reviewer Findings Tightened The Local Prep Contract

Two full-project reviewers converged on the same design problems:

- ARM host-cross was still relying on silent fallback behavior:
  - a fake `rustfmt` wrapper in `build-arm64-scx-host.sh`
  - silent reuse of a cached sysroot when the remote source contract was unset
- canonical KVM staged prep still had a broken local contract:
  - `prepare_local_inputs.sh` called `require_nonempty_dir()` without defining it
  - local prep still hard-coded `python3` instead of consuming the manifest's
    host-Python contract
- bundle assembly still had a path-derivation fallback layer:
  - `build_remote_bundle.sh` reconstructed inputs from
    `RUN_LOCAL_PROMOTE_ROOT` / `ARM64_CROSSBUILD_OUTPUT_DIR` when explicit
    bundle inputs were absent

The repo-owned fixes applied in this round are:

- `runner/scripts/build-arm64-scx-host.sh`
  - deleted the fake `rustfmt` wrapper
  - now requires a real host `rustfmt` binary and exports it explicitly via
    `RUSTFMT`
- `runner/scripts/prepare-arm64-sysroot.sh`
  - no longer trusts a cached sysroot unless the remote source contract is
    available and fingerprint-verifiable
  - now also requires `.source` alongside `.package-fingerprint`
- `runner/scripts/load_run_contract.sh`
  - always emits `RUN_HOST_PYTHON_BIN`, not just on the KVM path
- `runner/scripts/prepare_local_inputs.sh`
  - now defines `require_nonempty_dir()`
  - now uses `RUN_HOST_PYTHON_BIN` for repo fetch/native build/scx prep
  - now writes explicit KVM bundle inputs instead of relying on
    `build_remote_bundle.sh` to guess x86 paths
- `runner/scripts/aws_executor.sh`
  - now uses `RUN_HOST_PYTHON_BIN` for local repo/native/scx prep
  - now derives the ARM sysroot source contract from the resolved live AWS
    instance (`STATE_INSTANCE_IP`, `RUN_REMOTE_USER`, `RUN_AWS_KEY_PATH`)
    before host-cross steps
- `runner/scripts/build_remote_bundle.sh`
  - no longer reconstructs local bundle inputs from implicit path conventions
- `runner/scripts/build_corpus_native.py`
  - `scx` now passes explicit `--repo-root`
  - `scx` now refuses non-canonical stage roots instead of silently promoting
    into repo-global defaults
- duplicate policy and stale result-output leftovers were also reduced:
  - `CLAUDE.md` was removed as a second instruction plane
  - legacy top-level `vm_micro.json` / `vm_corpus.json` variables were removed
    from `runner/Makefile`
  - `README.md` now describes timestamped result directories and the current
    VM parameter names

Static verification after these fixes:

- `bash -n` passed for:
  - `build-arm64-scx-host.sh`
  - `prepare-arm64-sysroot.sh`
  - `prepare_local_inputs.sh`
  - `aws_executor.sh`
  - `build_remote_bundle.sh`
- `python3 -m py_compile` passed for:
  - `build_corpus_native.py`
  - `build_scx_artifacts.py`
- `git diff --check` passed for the local-prep / bundle / sysroot change set

Live benchmark state while these fixes were applied:

- fresh x86 `corpus` (`run.aws-x86.corpus.6j0008`) is still active and has
  advanced into local `scx` artifact preparation on its dedicated instance path
- fresh x86 `e2e` (`run.aws-x86.e2e.sYo0p7`) is still active and has advanced
  through setup artifact transfer on its own dedicated instance
- no new final benchmark result directories have appeared yet from those two
  fresh lanes, so the next action remains to keep polling the fresh reruns

### 13.28 2026-04-06 x86 Katran Runtime Bundle Fix For Corpus And E2E

The next fresh x86 blockers converged again, and this time they were both on
the same repo-owned bundle path:

- fresh x86 `corpus` rerun `run.aws-x86.corpus.6j0008` failed at bundle time
  with:
  - `missing runtime library for .../corpus/build/katran/bin/katran_server_grpc: libglog.so.0`
- the older in-flight x86 `e2e` rerun `run.aws-x86.e2e.sYo0p7` later failed
  on the same error

This was not a remote-instance problem. It was a local portable-wrapper bug:

- `build_corpus_native.py` correctly staged Katran as:
  - `corpus/build/katran/bin/katran_server_grpc`
  - `corpus/build/katran/lib/*`
- but `build_remote_bundle.sh` was resolving runtime dependencies for wrapped
  executables using only the binary directory itself
- for Katran that meant `ldd` searched:
  - `.../katran/bin`
  - but not the sibling `.../katran/lib`
- so bundle assembly falsely concluded that `libglog.so.0` was missing even
  though it had already been staged next to the binary

The fix is minimal and general:

- `stage_runtime_libs()` in `build_remote_bundle.sh` now extends its temporary
  `LD_LIBRARY_PATH` with sibling runtime directories when they exist:
  - `../lib`
  - `../lib64`
- local validation against the checked-in x86 Katran bundle now succeeds:
  - `ldd e2e/cases/katran/bin/katran_server_grpc` resolves `libglog.so.0`,
    `libgflags.so.2.2`, `libfmt.so.8`, and the rest through
    `e2e/cases/katran/lib`

Fresh reruns launched immediately after the fix:

- x86 `corpus`:
  - token `run.aws-x86.corpus.2REcge`
  - session `88053`
- x86 `e2e`:
  - token `run.aws-x86.e2e.x3RGcJ`
  - session `12439`

Current live benchmark lanes after this fix:

- x86:
  - `corpus` fresh rerun active
  - `e2e` fresh rerun active
- ARM:
  - `corpus` fresh rerun active
  - `e2e` fresh rerun active

At this point, all four AWS benchmark lanes are again live in parallel on
dedicated instances. The next action remains to keep polling only the fresh
reruns and take the first new blocker from each architecture/suite pair.

### 13.29 2026-04-07 Portable Runtime Shell Prune And Python Test Floor

This round intentionally cut more shell and test surface area instead of
preserving broad compatibility scaffolding.

What was deleted:

- dead portable-wrapper shell helpers:
  - `runner/scripts/build-arm64-portable-binary-host.sh`
  - `runner/scripts/build-x86-portable-libbpf.sh`
  - `runner/scripts/arm64_runtime_bundle_lib.sh`
- almost the entire residual Python test tree under `tests/python/`

What replaced the deleted shell:

- `runner/libs/portable_runtime.py` now owns:
  - ARM64 runtime library discovery and copy
  - ARM64 portable wrapper generation
  - x86 portable `libbpf` build orchestration
  - a small CLI so the remaining host-cross shell entrypoints can call Python
    instead of sourcing another bash library
- `runner/scripts/build-arm64-scx-host.sh` now shells out to
  `python3 -m runner.libs.portable_runtime bundle-arm64-runtime`
  instead of sourcing `arm64_runtime_bundle_lib.sh`
- `runner/scripts/build-arm64-workload-tools-host.sh` now does the same for
  bundled workload tools

The reduced Python test floor is now just:

- `tests/python/test_run_contract.py`
- `tests/python/test_prepare_local_inputs.py`

The retained coverage is deliberately narrow:

- manifest parsing / contract rendering
- guest prereq validation CLI smoke
- local-prep dispatch
- execute-workspace orchestration ordering
- architecture-signature checks follow symlinks
- workload metric parsing for stress-ng bogo-ops

Everything else was dropped on purpose so new Python control-plane paths can be
rebuilt incrementally instead of dragging a large mock-heavy compatibility
suite through each refactor.

### 13.30 2026-04-08 Active Control-Plane Shell Removal And Live Lane State

The active runner control plane is now Python-only inside `runner/`.

Confirmed state:

- `runner/` contains no active `.sh` or `.bash` files
- current shell files still visible in the repo are limited to:
  - historical result artifacts under `corpus/results/` and `runner/corpus/results/`
  - third-party or external source trees such as `runner/repos/`, `vendor/`,
    and `.worktrees/`

This means the current canonical control plane is:

- root `Makefile` alias
- `python -m runner.libs.run_target_suite`
- `python -m runner.libs.aws_remote_prep` for AWS only
- `python -m runner.libs.prepare_local_inputs`
- `python -m runner.libs.aws_executor` or `python -m runner.libs.kvm_executor`
- `python -m runner.libs.execute_workspace`
- `python -m runner.libs.guest_prereqs`
- `python -m runner.libs.suite_entrypoint`

Current live lane state while this document was updated:

- `aws-x86 corpus`
  - still active
  - now past the previous lock-only state
  - currently uploading `modules-7.0.0-rc2+.tar.gz` during remote-prep
- `aws-x86 e2e`
  - still active
  - waiting behind the same x86 kernel/setup artifact lock held by
    `aws-x86 corpus`
- `aws-arm64 corpus`
  - still active
  - in local prep under `arm64_container_build`
  - current hot path is Katran dependency bootstrap via
    `getdeps.py ... katran` under qemu-user
- `aws-arm64 e2e`
  - still active
  - same ARM local-prep bottleneck as `aws-arm64 corpus`
- `x86-kvm corpus`
  - still active
  - no longer only waiting on the kernel-build lock
  - now cloning/staging repos and building local corpus inputs

No new canonical result directories had landed yet at the time of this update.
The main remaining runtime cost is now ARM local Katran dependency build under
qemu-user, not AWS lifecycle or guest SSH setup.

### 13.31 2026-04-08 Sparse Snapshot And Katran Runtime Contract Cleanup

This round addressed three real runtime-contract bugs while keeping the static
gate small.

Fixed:

- sparse-checkout repo sealing no longer copies tracked paths out of the
  working tree; `runner.libs.build_remote_bundle` now uses `git archive HEAD`
  to seal git checkouts. This fixes the `bcc/.github/.../action.yml` failure
  seen during `x86-kvm corpus`.
- ARM64 repo-test prep now passes the correct
  `ARM64_UPSTREAM_SELFTEST_LLVM_SUFFIX` handoff into
  `runner.libs.arm64_host_build`.
- the ARM64 daemon wrapper is now kept on the actual execution path inside the
  sealed bundle:
  - `daemon/target/release/bpfrejit-daemon`
  - `daemon/target/release/bpfrejit-daemon.real`

Katran contract was also simplified:

- e2e now explicitly declares `SUITE_NEEDS_KATRAN_BUNDLE=1`
- `build_remote_bundle` writes the Katran runtime contract into the sealed
  manifest instead of hardcoding `e2e/cases/katran/bin|lib` inside
  `suite_entrypoint`
- `suite_entrypoint` now resolves:
  - `RUN_KATRAN_SERVER_BINARY`
  - `RUN_KATRAN_SERVER_LIB_DIR`
  from the sealed manifest
- e2e bundles now always include `corpus/inputs`, so the Katran packet fixture
  is present in the sealed workspace
- x86 Katran runtime is no longer a second bundle input tree outside
  `corpus/build/katran`; the x86 native build stage now owns the staged server
  binary and staged runtime lib dir together with the staged BPF objects

The minimal Python regression floor is now:

- `tests/python/test_run_contract.py`
- `tests/python/test_prepare_local_inputs.py`
- `tests/python/test_build_remote_bundle.py`
- `tests/python/test_runtime_file_signatures.py`
- `tests/python/test_workload_api.py`

Current static state after these fixes:

- `python3 -m compileall -q runner/libs runner/scripts tests/python e2e daemon docs/paper/helpers`
- `python3 -m pyflakes runner/libs runner/scripts tests/python e2e docs/paper/helpers`
- `python3 -m pytest -q tests/python`
  - `30 passed`
- `git diff --check`
- `make -n check`

Runtime state at the end of this cleanup step:

- stale AWS x86/arm `corpus/e2e` lanes from before the Katran contract changes
  are still running and being monitored, but they do not validate the newest
  bundle layout
- a fresh latest-code local run was started for:
  - `x86-kvm corpus`
  - `SAMPLES=1`
  - `VM_CORPUS_WORKLOAD_SECONDS=1`
  - log: `.cache/runtime-logs/x86-kvm-corpus-latest.log`

### 13.32 2026-04-08 Remote Python 3.9 Execute-Workspace Crash

Fresh `aws-x86 corpus/e2e` reruns reached remote workspace execution and failed
with a new runtime bug:

- `TypeError: unsupported operand type(s) for |: 'type' and 'types.GenericAlias'`
- this came from runtime evaluation of:
  - `cast(dict[str, str | list[str]], contract)`
  - inside:
    - `runner.libs.execute_workspace`
    - `runner.libs.suite_entrypoint`

Root cause:

- remote Amazon Linux still runs Python `3.9`
- `from __future__ import annotations` protects annotations, but not runtime
  expressions inside `typing.cast(...)`
- the remote entrypoints were evaluating a PEP 604 union at runtime

Fixed:

- removed those runtime `cast(...)` expressions entirely and passed the parsed
  manifest mapping through directly
- added a source-level regression in
  `tests/python/test_runtime_file_signatures.py` to prevent reintroducing this
  exact remote-entrypoint pattern

Static gate after the fix:

- `python3 -m pytest -q tests/python/test_runtime_file_signatures.py tests/python/test_build_remote_bundle.py tests/python/test_prepare_local_inputs.py tests/python/test_run_contract.py`
  - `30 passed`
- `python3 -m pyflakes runner/libs/execute_workspace.py runner/libs/suite_entrypoint.py tests/python/test_runtime_file_signatures.py`
- `git diff --check`

Latest live state after the fix:

- fresh latest-code reruns were started for:
  - `aws-x86 corpus`
    - log: `.cache/runtime-logs/aws-x86-corpus-latest.log`
  - `aws-x86 e2e`
    - log: `.cache/runtime-logs/aws-x86-e2e-latest.log`
- existing `aws-arm64 corpus/e2e` runs were left active because they were still
  in local prep and had not yet sealed their final workspace bundle
- `x86-kvm corpus` remains active on the latest tree

### 13.33 2026-04-08 Corpus Filter Contract And ARM SCX Wrapper Cleanup

This round kept working on the runner shape while live lanes continued.

Fixed:

- `RUN_CORPUS_FILTERS` is no longer runtime-only for the most important prep
  contracts. When corpus filters are present, `runner.libs.run_contract` now
  derives the selected runner set from `corpus/config/macro_apps.yaml` and
  prunes:
  - `RUN_BUNDLED_REPOS_CSV`
  - `RUN_NATIVE_REPOS_CSV`
  - `RUN_FETCH_REPOS_CSV`
  - `RUN_SCX_PACKAGES_CSV`
  - `RUN_SUITE_NEEDS_SCHED_EXT`
  - `RUN_NEEDS_KATRAN_BUNDLE`
  This means a filtered corpus rerun is no longer forced to prep Katran or SCX
  when the selected app set does not include them.
- ARM64 `scx` scheduler binaries are no longer sealed as raw ELFs on the
  execution path. `runner.libs.build_remote_bundle` now wraps staged ARM64 SCX
  binaries with the same portable runtime wrapper pattern used for the ARM64
  daemon:
  - wrapper on the execution path
  - real binary at `*.bin`
  - bundle root `lib/` used as the runtime library source

Structure checks:

- active runner entrypoints are now Python-only:
  - `runner/scripts/` contains only `.py`
  - no second shell control plane remains under `runner/scripts`

Static gate after these changes:

- `python3 -m pytest -q tests/python`
  - `34 passed`
- `python3 -m pyflakes runner/libs runner/scripts tests/python e2e docs/paper/helpers`
- `python3 -m compileall -q runner/libs runner/scripts tests/python e2e daemon docs/paper/helpers`
- `git diff --check`

Live runtime state while this cleanup landed:

- latest-code `aws-x86 corpus` and `aws-x86 e2e` reruns are active
- the current x86 blocker that was already observed and fixed in-tree was the
  remote Python 3.9 `execute_workspace` crash
- latest-code `x86-kvm corpus` remains active
- existing `aws-arm64 corpus/e2e` lanes remain in local prep under ARM64
  container build, now with the SCX wrapper fix available before final bundle
  sealing

### 13.34 2026-04-08 Manifest Parser Split And Fresh x86 AWS Reruns

Fresh `aws-x86 corpus/e2e` reruns exposed a new remote-preflight blocker.

Observed:

- both fresh reruns failed in remote base prereq before suite execution
- remote `aws_remote_prereqs.py` imported `runner.libs.run_contract.parse_manifest`
- `run_contract.py` now imports `runner.libs.app_suite_schema`, but the remote
  prereq bundle intentionally does not ship the full local schema/build plane
- result: remote Amazon Linux failed with
  `ModuleNotFoundError: No module named 'runner.libs.app_suite_schema'`

Fixed:

- split manifest parsing/rendering into a new minimal module:
  - `runner/libs/manifest_file.py`
- moved active runtime consumers off heavy `run_contract` imports:
  - `runner/libs/aws_remote_prereqs.py`
  - `runner/libs/execute_workspace.py`
  - `runner/libs/suite_entrypoint.py`
  - `runner/libs/run_target_suite.py`
  - `runner/libs/kvm_executor.py`
  - `runner/libs/aws_common.py`
  - `runner/libs/guest_prereqs.py`
  - `runner/libs/prepare_local_inputs.py`
  - `runner/libs/build_remote_bundle.py`
- `run_contract.py` now consumes that minimal module instead of owning a second
  parser copy

Why this matters:

- remote prereq / execute-workspace paths no longer depend on local manifest
  schema loading
- the parser contract is now one small Python module instead of being buried in
  the heavy manifest-construction layer
- this removes another hidden coupling between local contract construction and
  remote execution

Static gate after the split:

- `python3 -m pyflakes runner/libs/manifest_file.py runner/libs/run_contract.py runner/libs/aws_remote_prereqs.py runner/libs/execute_workspace.py runner/libs/suite_entrypoint.py runner/libs/run_target_suite.py runner/libs/kvm_executor.py runner/libs/aws_common.py runner/libs/guest_prereqs.py runner/libs/prepare_local_inputs.py runner/libs/build_remote_bundle.py tests/python/test_run_contract.py`
- `python3 -m pytest -q tests/python/test_run_contract.py tests/python/test_prepare_local_inputs.py tests/python/test_runtime_file_signatures.py tests/python/test_build_remote_bundle.py tests/python/test_vm_launcher.py`
  - `34 passed`
- `git diff --check`

Live state after the fix:

- fresh reruns were restarted for:
  - `aws-x86 corpus`
  - `aws-x86 e2e`
- `x86-kvm corpus` stayed active and continued moving through local prep on the
  latest tree

### 13.35 2026-04-08 x86 KVM Corpus Runtime Fixes And Fresh x86 AWS Reruns

This round fixed the latest `x86-kvm corpus` runtime blockers while keeping
fresh `aws-x86 corpus/e2e` reruns active.

Observed on the latest `x86-kvm corpus` rerun:

- BCC still resolved tools from the tracked repo checkout instead of the sealed
  native build tree.
- bundled `stress-ng` failed with `Permission denied` when `setpriv` dropped to
  `65534:65534`, because the KVM executor exposed the guest workspace from a
  host path rooted under `/home/yunwei37`, and `/home/yunwei37` is not
  world-traversable.
- `bpftrace` and Katran inherited a stale implicit module-tree contract:
  runtime defaulted to `vendor/linux-framework/.virtme_mods`, but the sealed
  KVM bundle did not stage that tree.
- `tracee` remained brittle under the x86 portable-wrapper model because its
  readiness/FD-owner checks use the launcher pid directly.

Fixed:

- sealed bundles now publish `RUN_BCC_TOOLS_DIR=corpus/build/bcc/libbpf-tools/.output`,
  and `suite_entrypoint` exports that as `BCC_TOOLS_DIR` for runtime consumers.
- the KVM executor no longer extracts the sealed workspace under the repo cache
  path; it now stages under host `/tmp/bpf-benchmark-kvm/...`, which is
  guest-visible and world-traversable for `setpriv` workloads.
- x86 KVM bundles now stage `vendor/linux-framework/.virtme_mods`, and KVM
  runtime explicitly sets `BPFREJIT_KERNEL_MODULES_ROOT` to that sealed path.
- x86 native repo build trees still wrap most dynamic executables, but `tracee`
  is now left unwrapped; its staged `corpus/build/tracee/lib` directory is
  instead added to runtime `LD_LIBRARY_PATH`.

Reviewer results on this slice:

- focused BCC review: `No findings` after the sealed `RUN_BCC_TOOLS_DIR`
  contract landed.
- focused KVM permission review: confirmed that moving the staged KVM workspace
  to host `/tmp` is the design-correct fix.
- focused `.virtme_mods` review: confirmed that staging `.virtme_mods` into the
  sealed KVM bundle and exporting `BPFREJIT_KERNEL_MODULES_ROOT` is the minimal
  correct fix.

Static gate after these fixes:

- `python3 -m pyflakes runner/libs/kvm_executor.py runner/libs/build_remote_bundle.py runner/libs/suite_entrypoint.py tests/python/test_build_remote_bundle.py tests/python/test_suite_entrypoint.py tests/python/test_kvm_executor.py`
- `python3 -m pytest -q tests/python/test_build_remote_bundle.py tests/python/test_suite_entrypoint.py tests/python/test_kvm_executor.py tests/python/test_run_contract.py tests/python/test_aws_remote_prep.py tests/python/test_prepare_local_inputs.py`
  - `37 passed`
- `git diff --check`

Live state after these fixes:

- fresh `aws-x86 corpus` rerun is active in remote prereq/setup on the latest
  tree
- fresh `aws-x86 e2e` rerun is active in local kernel prep on the latest tree
- fresh `x86-kvm corpus` rerun is active on the latest tree and now includes:
  - sealed `RUN_BCC_TOOLS_DIR`
  - KVM staging under host `/tmp`
  - sealed `.virtme_mods`
  - unwrapped staged `tracee` binary with explicit runtime library path

### 13.36 2026-04-08 Sealed Runner Tree Missing `manifest_file.py`

The next shared runtime blocker for `x86-kvm corpus` and `aws-x86 corpus/e2e`
was a missing live runner module in the sealed workspace:

- `runner.libs.execute_workspace` imported `runner.libs.guest_prereqs`
- `guest_prereqs` imported `runner.libs.manifest_file`
- both KVM and AWS sealed runner trees omitted `runner/libs/manifest_file.py`

This happened because sealed runner-tree copying still used the tracked-tree
copy of `runner/libs`, while `manifest_file.py` had become a new active runtime
module in the current tree.

Fixed:

- `runner.libs.build_remote_bundle.BundleBuilder.copy_runner_tree()` now copies
  `runner/libs/manifest_file.py` explicitly into the sealed runner tree when it
  exists

Fresh reruns were restarted immediately after the fix for:

- `x86-kvm corpus`
- `aws-x86 corpus`
- `aws-x86 e2e`

Current live state after the reruns:

- `x86-kvm corpus` has already moved past the old `manifest_file.py` import
  crash and is back in staged local-prep/native-build work
- `aws-x86 corpus/e2e` are alive again and back in AWS remote preflight / local
  prep on the latest tree

Follow-up cleanup in the same lane:

- `run_contract` no longer reads `~/.config/bpf-benchmark/*.env` or
  `BPF_BENCHMARK_LOCAL_ENV`; manifests are now determined only by explicit
  process environment plus checked-in target/suite files
- tracked-tree sealing now rejects untracked files under active runtime trees,
  instead of silently omitting them from sealed bundles
- KVM `/tmp` staging now keys the extracted workspace by run token instead of
  the constant tarball basename, so concurrent KVM runs cannot wipe each
  other's extracted workspace

### 13.37 2026-04-08 Live Corpus/E2E Status, Snapshot Sealing, And `scx` Post-ReJIT Refresh

Current active corpus/e2e lanes:

- `x86-kvm corpus`
  - current token: `run.x86-kvm.corpus.d6421dfc`
  - current state: still alive, currently in local x86 kernel/modules build on
    the fresh tree
- `aws-x86 corpus`
  - current token: `run.aws-x86.corpus.e4f42729`
  - current state: alive; old `manifest_file.py` crash is stale and this rerun
    is now in deeper local prep / repo build (`scx_rusty` build)
- `aws-x86 e2e`
  - current token: `run.aws-x86.e2e.961c343f`
  - current state: alive; old `manifest_file.py` crash is stale and this rerun
    is now in later prep/build after remote setup
- `aws-arm64 corpus`
  - current token: `run.aws-arm64.corpus.d8e4af69`
  - current state: alive; still bottlenecked in local ARM qemu/container prep,
    currently inside Katran getdeps/CMake
- `aws-arm64 e2e`
  - current token: `run.aws-arm64.e2e.1cce46c3`
  - current state: alive; also still bottlenecked in local ARM qemu/container
    prep

New structural/runtime fixes landed in this round:

- `git archive`-based sealing paths now reject untracked files too; they no
  longer silently drop untracked runtime inputs from sealed snapshots.
  This was fixed in:
  - `runner/libs/build_remote_bundle.py`
  - `runner/libs/arm64_container_build.py`
  - `runner/libs/arm64_host_build.py`
- `scx` now refreshes live scheduler programs after ReJIT before post-ReJIT
  measurement, instead of continuing to sample stale pre-ReJIT `struct_ops`
  prog_ids.
  This was fixed in:
  - `runner/libs/app_runners/scx_support.py`
  - `runner/libs/app_runners/scx.py`
  - `corpus/driver.py`
  - `e2e/cases/scx/case.py`

Why the `scx` fix matters:

- the old code selected `struct_ops` prog_ids from baseline and reused them
  after ReJIT
- if `scx_rusty` reloads/recreates live scheduler programs during apply, those
  prog_ids can change
- that could falsely surface as:
  - `did not execute any target programs after rejit`
  - missing post-ReJIT BPF runtime counters even though the scheduler really ran

The new behavior is intentionally narrow:

- only `scx` refreshes live programs after ReJIT
- corpus remaps sampled post-ReJIT stats back onto the original logical program
  ids by stable program name, so apply records and baseline accounting stay on
  one control plane
- e2e `scx` refreshes only the measurement ids for post-ReJIT workload
  sampling; it does not introduce a new generic runner abstraction

Static gate after the latest fixes:

- `python3 -m pyflakes runner/libs/app_runners/scx.py runner/libs/app_runners/scx_support.py corpus/driver.py e2e/cases/scx/case.py runner/libs/build_remote_bundle.py runner/libs/arm64_container_build.py runner/libs/arm64_host_build.py`
- `python3 -m pytest -q tests/python/test_build_remote_bundle.py tests/python/test_prepare_local_inputs.py tests/python/test_run_contract.py tests/python/test_suite_entrypoint.py tests/python/test_aws_remote_prep.py tests/python/test_kvm_executor.py tests/python/test_vm_launcher.py tests/python/test_workload_api.py tests/python/test_runtime_file_signatures.py`
  - `42 passed`
- `git diff --check`

Current active todo:

1. keep monitoring the live `x86-kvm/aws-x86/aws-arm64` corpus/e2e lanes until
   each either finishes or exposes a new first blocker
2. if `x86-kvm corpus` fails again, treat `tracee` readiness and `scx` runtime
   semantics as the most likely next blockers
3. if `aws-x86 corpus/e2e` fail again, inspect the fresh result dirs before
   changing code; the old `manifest_file.py` crash is no longer the active
   blocker
4. keep reviewing the remaining `katran` userspace control plane split:
   - x86 still stages a tracked helper runtime
   - arm64 still builds a userspace bundle locally inside qemu/container prep
   - this is the remaining obvious second control plane in corpus/e2e runtime


### 13.38 2026-04-08: runtime compatibility and fresh x86 corpus/e2e reruns

- New real blocker from fresh `aws-x86 corpus/e2e` reruns was remote Python compatibility, not manifest/prep.
- Remote `python3` rejected `@dataclass(..., slots=True)` in runtime modules loaded by `corpus/driver.py` and `suite_entrypoint.py`.
- Fixed by removing `slots=True` from runtime dataclasses in active `runner/libs`, `corpus`, and `e2e` paths while keeping `frozen=True` where used.
- Also fixed a corpus false-negative: program-mode phase measurement now treats `run_cnt > 0` or `run_time_ns > 0` as execution, instead of requiring only positive `exec_ns`.
- Static gate after this fix stayed green:
  - `pyflakes runner/libs runner/scripts corpus e2e`
  - `compileall runner/libs runner/scripts corpus e2e`
  - focused pytest set `42 passed`
- Fresh reruns started with explicit x86 AWS env restored from cached manifest contract:
  - `aws-x86 corpus`
  - `aws-x86 e2e`
- Existing live lanes kept running:
  - `x86-kvm corpus`
  - `aws-arm64 corpus`
  - `aws-arm64 e2e`

Active todo:
1. Monitor fresh `aws-x86 corpus/e2e` until new result or blocker lands.
2. Keep `x86-kvm corpus` moving; once green, start `x86-kvm e2e`.
3. Keep `aws-arm64 corpus/e2e` alive; next blocker is still local arm64 qemu/container prep unless new result lands first.
4. Re-review `scx`/Katran control-plane findings after the fresh reruns, using current code rather than stale review snapshots.


### 13.39 2026-04-08: x86-kvm corpus blockers and shared policy/workload fixes

- Fresh `x86-kvm corpus` rerun exposed two real runtime blockers:
  - `bpftrace/tcpretrans`: baseline process emitted retransmit events but the short smoke workload still produced no measurable program delta.
  - `scx/rusty`: post-ReJIT scheduler run failed with a real `sched_ext` error (`Failed to acquire dom0 cpumask kptr`), then program counters stayed zero.
- Applied two minimal shared fixes before the next rerun:
  - `runner/libs/workload.py`: made `tcp_retransmit` smoke runs denser and more deterministic by increasing minimum runtime, shrinking per-connection transfer target, and increasing loopback netem loss/delay.
  - `corpus/config/benchmark_config.yaml`: added an explicit shared policy rule for `prog_type=struct_ops` to disable `map_inline` and `dce`; current evidence points to those passes destabilizing `scx_rusty` live scheduler state after apply.
- Focused static gate after these fixes stayed green:
  - `pyflakes`
  - `compileall`
  - focused pytest (`7 passed`)
- Fresh local rerun started:
  - `x86-kvm corpus`
- Fresh AWS x86 reruns are also live again with explicit x86 AWS env restored from cached manifests.

Active todo:
1. Wait for fresh `x86-kvm corpus` result after the `tcpretrans` + `struct_ops` fixes.
2. Wait for fresh `aws-x86 corpus/e2e` result after the remote Python compatibility fix.
3. Keep `aws-arm64 corpus/e2e` alive through local arm64 prep; fix the next concrete blocker when it lands.
4. After fresh corpus results, start/restart `x86-kvm e2e` on the same updated code.


### 13.40 2026-04-08: x86 lanes moved past setup, arm64 lanes still in native repo prep

- Fresh `aws-x86 corpus` and `aws-x86 e2e` are no longer failing in remote prep or
  runtime import compatibility.
- Fresh `x86-kvm corpus` is also no longer blocked in kernel/module prep or the
  previous immediate runtime failures.
- All three x86 lanes now completed:
  - kernel/module prep
  - sealed repo fetch
  - native repo build for:
    - `bcc`
    - `katran`
    - `tracee`
    - `tetragon`
  - and have moved into `runner.libs.build_remote_bundle`
- Fresh x86 lane state at this point:
  - `aws-x86 corpus`: local prep has finished native repo build and entered
    bundle sealing
  - `aws-x86 e2e`: local prep has finished native repo build and entered bundle
    sealing
  - `x86-kvm corpus`: local prep has finished native repo build and entered
    bundle sealing
- The two long-running ARM64 lanes are still not deadlocked:
  - `aws-arm64 corpus`
  - `aws-arm64 e2e`
  - both still have active compiler children under
    `runner.libs.arm64_container_build`
  - current hotspot is still local ARM64 Katran dependency prep
    (`getdeps.py --only-deps` + downstream CMake build), not remote AWS
    execution

Interpretation:

- x86 is now past the last known shared setup/runtime import blockers; the next
  fresh result should represent either real remote/guest execution or the next
  concrete runtime issue after bundle sealing
- arm64 is still dominated by per-run local native repo prep latency; the next
  change there should be driven by a real failure or by eliminating obviously
  duplicated heavy prep rather than by more ad hoc runtime patching

Active todo:
1. Wait for fresh `aws-x86 corpus` and `aws-x86 e2e` results on the updated
   code.
2. Wait for fresh `x86-kvm corpus` result on the updated workload/policy code;
   if green, start `x86-kvm e2e`.
3. Keep `aws-arm64 corpus/e2e` alive; if the next blocker is not a concrete
   runtime failure but duplicated heavy native prep, move more ARM64 native repo
   work out of per-run qemu/container prep.
