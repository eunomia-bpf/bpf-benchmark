# Policy Loading Pipeline Analysis

This document traces how a policy YAML file becomes a live BPF JIT recompile in the current `bpf-benchmark` tree.

## Executive Summary

There are really two different pipelines in this repo:

1. `micro_exec` object-file pipeline
   - Used by the micro benchmark and by corpus VM batch.
   - Starts from an ELF object path plus program name.
   - Loads the BPF program itself.
   - Compiles policy YAML inline inside `micro_exec` using the scanner library.
   - Applies the blob with raw `bpf(BPF_PROG_JIT_RECOMPILE, ...)`.

2. Live-program scanner pipeline
   - Used by the e2e `bpftrace`, `tracee`, and `tetragon` cases.
   - Starts from a live program ID / FD owned by another process or by the harness.
   - Uses `bpf-jit-scanner scan/apply --prog-fd`.
   - Applies recompilation to the already-loaded live program.
   - Current e2e wrappers do not pass policy YAML at all; they only do auto-scan `--all --v5`.

The scanner itself can do YAML-driven live apply with:

```bash
bpf-jit-scanner apply --prog-fd <fd> --config policy.yaml
```

But none of the current e2e cases wire that option through.

## High-Level Matrix

| Scenario | Entry point | Policy source | Blob built by | Kernel apply path | Can target program loaded by another process? |
| --- | --- | --- | --- | --- | --- |
| Micro benchmark (`kernel-recompile`) | `micro/run_micro.py` -> `micro/driver.py` -> `micro/_driver_impl_run_micro.py` | Suite YAML `policy:` or `policy_file:` | Inline in `micro_exec` | Raw `BPF_PROG_JIT_RECOMPILE` syscall from `micro_exec` | No |
| Corpus VM batch (`--use-policy`) | `corpus/_driver_impl_run_corpus_v5_vm_batch.py` | `corpus/policies/...` via `resolve_policy_path()` | Inline in `micro_exec` | Raw `BPF_PROG_JIT_RECOMPILE` syscall from `micro_exec` | No |
| E2E bpftrace | `e2e/cases/bpftrace/case.py` | None today | `bpf-jit-scanner apply --all --v5` auto-scan | Raw `BPF_PROG_JIT_RECOMPILE` syscall inside scanner | Yes, if it can reacquire a prog FD |
| E2E tracee | `e2e/cases/tracee/case.py` | None today | `bpf-jit-scanner apply --all --v5` auto-scan | Raw `BPF_PROG_JIT_RECOMPILE` syscall inside scanner | Yes |
| E2E tetragon | `e2e/cases/tetragon/case.py` | None for JIT policy | `bpf-jit-scanner apply --all --v5` auto-scan | Raw `BPF_PROG_JIT_RECOMPILE` syscall inside scanner | Yes |

## What A Typical Policy YAML Looks Like

### What exists under `corpus/policies/`

Most files in `corpus/policies/` are auto-generated family-action maps, for example:

### Example 1: `corpus/policies/tracee/tracee.bpf.o.policy.yaml`

```yaml
families:
  cmov: skip
  wide_mem: apply
  rotate: apply
  extract: apply
  lea: apply
  zeroext: apply
  endian: apply
  bflip: apply
```

Source: `corpus/policies/tracee/tracee.bpf.o.policy.yaml:1-14`

### Example 2: `corpus/policies/tetragon/bpf_execve_event.bpf.o.policy.yaml`

```yaml
families:
  cmov: apply
  wide_mem: apply
  rotate: apply
  extract: apply
  lea: apply
  zeroext: apply
  endian: apply
  bflip: apply
```

Source: `corpus/policies/tetragon/bpf_execve_event.bpf.o.policy.yaml:1-13`

### Example 3: `corpus/policies/calico/from_wep_debug.bpf.o.policy.yaml`

```yaml
families:
  cmov: skip
  wide_mem: apply
  rotate: apply
  extract: apply
  lea: apply
  zeroext: apply
  endian: apply
  bflip: apply
```

Source: `corpus/policies/calico/from_wep_debug.bpf.o.policy.yaml:1-14`

### Important observation

`corpus/policies/` is mostly using the shorthand `families:` mapping form, not the explicit:

```yaml
version: 1
selection:
  mode: allowlist|denylist
  families: [...]
site_overrides:
  - site_id: ...
    action: enable|disable
```

The parser treats the shorthand mapping as an allowlist of every family marked `apply`; anything marked `skip` or omitted is excluded. That behavior is implemented by `parse_family_action_map()` in `scanner/src/policy_config.cpp:243-298`.

For contrast, the micro benchmark's hand-written `micro/policies/cmov_dense.yaml` uses the explicit schema:

```yaml
version: 1
selection:
  mode: allowlist
  families: [cond-select]
```

Source: `micro/policies/cmov_dense.yaml:1-4`

## How `scanner/src/policy_config.cpp` Parses Policy

The policy parser lives in `scanner/src/policy_config.cpp` and is exposed through `scanner/include/bpf_jit_scanner/policy_config.hpp`.

### Schema

`V5PolicyConfig` contains:

- `version`
- `selection.mode`
- `selection.families`
- `site_overrides`

Defined in `scanner/include/bpf_jit_scanner/policy_config.hpp:13-32`.

### Accepted forms

`parse_policy_node()` supports two top-level styles (`scanner/src/policy_config.cpp:343-383`):

1. Explicit style:

```yaml
version: 1
selection:
  mode: allowlist
  families: [cmov, rotate]
site_overrides:
  - site_id: cmov:0:cond-select-64
    action: disable
```

2. Shorthand mapping style:

```yaml
families:
  cmov: skip
  rotate: apply
  lea: apply
```

### Selection semantics

- `selection.mode` must be `allowlist` or `denylist` (`scanner/src/policy_config.cpp:180-201`).
- `selection.families` can be a scalar or sequence (`scanner/src/policy_config.cpp:203-241`).
- Family aliases are normalized by `parse_v5_family_name()` in `scanner/src/pattern_v5.cpp:964-1008`.
  - Examples: `cond-select` -> `cmov`, `wide_mem` -> `wide`, `addr-calc` -> `lea`, `bflip` -> `branch-flip`.

### Shorthand `families:` mapping behavior

`parse_family_action_map()` (`scanner/src/policy_config.cpp:243-298`) converts:

- `apply`, `enable`, `enabled`, `keep`, `on`, `true` -> enabled
- `skip`, `disable`, `disabled`, `drop`, `off`, `false` -> disabled

It then builds an allowlist containing only enabled families.

### Site overrides

`site_overrides` is parsed by `parse_site_overrides()` (`scanner/src/policy_config.cpp:300-341`):

- each entry must be a mapping
- `site_id` is required
- `action` must be `enable` or `disable`

`filter_rules_by_policy()` first applies family selection, then overrides matching `rule_site_id(rule)` (`scanner/src/policy_config.cpp:424-447`).

### How filtering works

The important call chain is:

1. `scan_v5_builtin()` discovers candidate `V5PolicyRule`s.
2. `filter_rules_by_policy()` keeps only rules allowed by the parsed config.
3. `build_policy_blob_v5()` serializes the filtered rules into the kernel wire format.

## What `scanner/src/cli.cpp` Exposes

The scanner CLI usage is printed by `print_usage()` in `scanner/src/cli.cpp:499-530`.

### Relevant subcommands

#### `scan`

Usage:

```bash
bpf-jit-scanner scan (<file> | --prog-fd <fd> | --xlated <file>) [family flags] [--json] [--output <blob>]
```

Behavior:

- scans a live prog FD or offline input
- does not accept `--config` (`scanner/src/cli.cpp:691-692`)
- can emit JSON manifest (`--json`)
- can also write an unfiltered v5 blob via `--output` (`scanner/src/cli.cpp:741-771`)

#### `compile-policy`

Usage:

```bash
bpf-jit-scanner compile-policy (<file> | --prog-fd <fd> | --xlated <file>) --config <policy.{yaml,json}> [family flags] [--output <blob>|-]
```

Behavior:

- scans input
- parses YAML/JSON with `load_policy_config_or_die()`
- filters rules with `filter_rules_by_policy()`
- writes filtered blob with `build_policy_blob_v5()`

Implementation: `scanner/src/cli.cpp:773-795`

#### `apply`

Usage:

```bash
bpf-jit-scanner apply --prog-fd <fd> [family flags] [--config <policy.{yaml,json}>] [--output <blob>]
```

Behavior:

- requires `--prog-fd` (`scanner/src/cli.cpp:674-676`)
- does not accept `--xlated` (`scanner/src/cli.cpp:678-679`)
- does live scan of the program's xlated instructions
- optionally filters with `--config`
- builds blob
- applies blob with raw `BPF_PROG_JIT_RECOMPILE`

Implementation: `scanner/src/cli.cpp:797-827`

#### `dump`

Useful support command:

```bash
bpf-jit-scanner dump --prog-fd <fd> [--output <file>]
```

It dumps live xlated bytecode for offline analysis (`scanner/src/cli.cpp:830-843`).

### How scanner builds input

`load_input()` (`scanner/src/cli.cpp:393-434`) does two different things:

- with `--prog-fd`, it uses `BPF_OBJ_GET_INFO_BY_FD` to fetch:
  - xlated instructions
  - `insn_cnt`
  - `prog_tag`
  - program name
- with file input, it reads either:
  - a raw xlated blob
  - or an ELF object and extracts a program from it

So scanner can compile offline blobs, but live `apply` is always prog-FD-driven.

## How A Blob Is Serialized

`build_policy_blob_v5()` lives in `scanner/src/pattern_v5.cpp:1795-1868`.

It writes a packed header containing:

- `magic`
- `version`
- `hdr_len`
- `total_len`
- `rule_cnt`
- `insn_cnt`
- `prog_tag[8]`
- `arch_id`
- `flags`

Then it appends one wire record per rule plus pattern / constraint / binding arrays.

That means every usable blob is bound to:

- the translated instruction count
- the program tag
- the architecture

This is why both scanner and `micro_exec` fetch live `prog_tag` and `xlated_prog_len` before applying.

## How The Blob Reaches The Kernel

Both scanner and `micro_exec` use the same basic mechanism:

1. create a memfd with `memfd_create`
2. write the blob into it
3. seal it with `F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK`
4. call raw `bpf(BPF_PROG_JIT_RECOMPILE, ...)`

### In scanner

`apply_policy_blob()` in `scanner/src/cli.cpp:441-497` does exactly that. The raw attr contains:

```c
{
    uint32_t prog_fd;
    int32_t  policy_fd;
    uint32_t flags;
    uint32_t log_level;
    uint32_t log_size;
    uint64_t log_buf;
}
```

The syscall is issued at `scanner/src/cli.cpp:486-487`.

### In `micro_exec`

`run_kernel()` in `micro/runner/src/kernel_runner.cpp:1096-1143` builds the memfd and then calls:

```c
syscall(__NR_bpf, BPF_PROG_JIT_RECOMPILE, attr_buf, sizeof(attr_buf))
```

The local attr only carries:

```c
{
    __u32 prog_fd;
    __s32 policy_fd;
    __u32 flags;
}
```

The enum value is locally defined as `39` in `micro/runner/src/kernel_runner.cpp:65-68`.

No scenario in this document uses `bpftool` to apply JIT policy.

## Shared E2E Recompile Helper

`e2e/common/recompile.py` is the shared live-program helper for `bpftrace`, `tracee`, and `tetragon`.

### How it finds a usable prog FD

`_prog_fd_by_id()` (`e2e/common/recompile.py:24-32`) tries:

1. `libbpf.bpf_prog_get_fd_by_id(prog_id)`
2. if that fails, `_dup_prog_fd_from_proc()` scans `/proc/*/fdinfo/*` for a matching `prog_id:` entry and opens `/proc/<pid>/fd/<n>` (`e2e/common/recompile.py:35-56`)

So the e2e layer can target programs not loaded by itself, provided it has enough privilege and a reachable owner FD.

### What commands it actually runs

`scan_programs()` runs:

```bash
bpf-jit-scanner scan --prog-fd <fd> --all --json --v5 --program-name <name>
```

Implementation: `e2e/common/recompile.py:153-202`

`apply_recompile()` runs:

```bash
bpf-jit-scanner apply --prog-fd <fd> --all --v5 --program-name <name>
```

Implementation: `e2e/common/recompile.py:205-255`

Important: it never passes `--config`, so current e2e recompilation is always auto-scan and never policy-YAML-driven.

The helper also sets each FD inheritable and launches scanner with `pass_fds=(fd,)`, so the scanner subprocess is operating on the already-open live prog FD (`e2e/common/recompile.py:175-192`, `228-244`).

## Scenario 1: Micro Benchmark (`kernel-recompile`)

### Entry point

The entry chain is:

1. `micro/run_micro.py:12-21`
2. `micro/driver.py:62-71`
3. `micro/_driver_impl_run_micro.py:255-445`

`run_micro.py` simply forwards to `driver.main(["suite", "--", ...])`.

### How the policy YAML is found / resolved

The suite file is parsed by `load_suite()` in `micro/benchmark_catalog.py:212-290`.

Each benchmark may specify:

- inline `policy:` mapping
- or `policy_file:`

These are stored on `BenchmarkSpec.policy` and `BenchmarkSpec.policy_file` (`micro/benchmark_catalog.py:101-140`, `262-282`).

Two forms are supported:

1. Inline benchmark policy:

```yaml
policy:
  COND_SELECT: skip
```

Example: `config/micro_pure_jit.yaml:106-118`

2. External file:

```yaml
policy_file: micro/policies/cmov_dense.yaml
```

Example: `config/micro_pure_jit.yaml:206-217`

Inline benchmark policy is converted by `BenchmarkSpec.inline_policy_text` into a JSON string of the form:

```json
{"version":1,"selection":{"mode":"denylist","families":["cmov"]}}
```

That conversion happens in `micro/benchmark_catalog.py:124-140`.

At runtime, `_driver_impl_run_micro.resolve_policy_inputs()` returns either:

- `(inline_policy_text, None)`
- or `(None, benchmark.policy_file)`

Implementation: `micro/_driver_impl_run_micro.py:179-184`

Only `kernel-recompile` runtimes use those fields (`micro/_driver_impl_run_micro.py:341-358`).

Important nuance: `BenchmarkSpec.inline_policy_text` only serializes families whose action is `skip` and always emits a `denylist` policy (`micro/benchmark_catalog.py:124-140`).

That means:

- `policy: { COND_SELECT: skip }` becomes a real denylist of `cmov`
- `policy: { COND_SELECT: apply }` becomes `denylist: []`, which effectively means "allow every family"

So inline `apply` entries in the micro suite are not a strict allowlist.

### How `run_micro.py` invokes `micro_exec`

`build_micro_benchmark_command()` in `micro/orchestrator/commands.py:115-176` builds the final `micro_exec` command.

For `kernel-recompile` it emits:

- `--policy <json>` if inline policy exists
- `--policy-file <path>` if file policy exists
- otherwise `--recompile-v5 --recompile-all`

That branch is in `micro/orchestrator/commands.py:158-174`.

So the typical command shape is:

```bash
sudo -n micro/build/runner/micro_exec run-kernel \
  --program <obj> \
  --io-mode <mode> \
  --repeat <n> \
  --memory <input> \
  --input-size <n> \
  --policy-file micro/policies/cmov_dense.yaml
```

or:

```bash
sudo -n micro/build/runner/micro_exec run-kernel ... --policy '{"version":1,"selection":{"mode":"denylist","families":["cmov"]}}'
```

`build_micro_benchmark_command()` prepends `sudo -n` when the runtime requires it (`micro/orchestrator/commands.py:99-103`, `156`, `174`), and the default `kernel-recompile` runtime in `config/micro_pure_jit.yaml` does require sudo (`config/micro_pure_jit.yaml:49-54`).

### How policy YAML becomes a blob

This happens inside `micro_exec`, not by shelling out to `scanner compile-policy`.

The path is:

1. CLI parse in `micro/runner/src/common.cpp:227-279`
2. validation that policy mode is only valid for `run-kernel` and cannot be mixed with auto-scan flags in `micro/runner/src/common.cpp:396-459`
3. `run_kernel()` loads the object and gets `program_fd` in `micro/runner/src/kernel_runner.cpp:794-837`
4. if `--policy` or `--policy-file` was provided:
   - parse config: `parse_policy_config_text()` or `load_policy_config_file()` (`micro/runner/src/kernel_runner.cpp:1028-1034`)
   - fetch xlated program with `BPF_OBJ_GET_INFO_BY_FD` (`load_xlated_program()` at `micro/runner/src/kernel_runner.cpp:529-550`, called at `1037`)
   - scan all families: `scan_v5_builtin()` (`1039-1051`)
   - filter rules: `filter_rules_by_policy()` (`1054-1056`)
   - summarize: `summarize_rules()` (`1057-1059`)
   - build blob: `build_policy_blob_v5()` (`1078-1081`)

So for micro benchmark policy mode:

- scanner library is used
- scanner CLI is not used

### How the blob is passed to the kernel

Still inside `micro_exec`:

1. blob -> memfd (`micro/runner/src/kernel_runner.cpp:1096-1108`)
2. syscall -> `BPF_PROG_JIT_RECOMPILE` (`1113-1133`)

If the syscall succeeds, `sample.recompile.applied = true` (`1141-1142`).
If it fails, the runner records the error and continues with the stock JIT image (`1134-1141`).

### What happens if the program is already loaded by another process?

Nothing to that already-running program.

`micro_exec` always loads its own instance from the object file (`micro/runner/src/kernel_runner.cpp:811-837`) and recompiles the returned `program_fd`.

Even if another daemon previously loaded an equivalent object, the micro benchmark does not attach to that live instance.

### Can it apply policy to a program it did not load itself?

No.

`micro_exec` has no `--prog-fd`, `--prog-id`, or pinned-path apply mode. This pipeline is object-file-driven only.

## Scenario 2: Corpus Recompile VM Batch (`_driver_impl_run_corpus_v5_vm_batch.py --use-policy`)

### Entry point

Direct entry is `corpus/_driver_impl_run_corpus_v5_vm_batch.py:1230-1382`.

Through the unified driver:

1. `micro/driver.py:89-108`
2. mode `corpus v5-vm-batch`
3. dispatches to `corpus/_driver_impl_run_corpus_v5_vm_batch.py`

### Control flow

Normal VM mode is:

1. host `main()` decides VM vs host fallback (`corpus/_driver_impl_run_corpus_v5_vm_batch.py:1263-1304`)
2. each target is sent to the guest with `run_target_in_guest()` (`727-787`)
3. guest re-invokes the same script with `--guest-target-json`
4. `run_guest_target_mode()` calls `run_target_locally(..., enable_recompile=True, use_policy=args.use_policy, ...)` (`652-675`)

### How policy YAML is found / resolved

When `--use-policy` is enabled, `run_target_locally()` resolves a `policy_path` via `resolve_policy_path()` (`corpus/_driver_impl_run_corpus_v5_vm_batch.py:493-497`).

The resolver lives in `corpus/policy_utils.py:66-81` and searches in this order:

1. per-program policy:
   - `corpus/policies/<relative-dir>/<object-stem>/<sanitized-program-name>.policy.yaml`
   - built by `policy_path_for_program()` (`corpus/policy_utils.py:54-59`)
2. mirrored object policy:
   - `corpus/policies/<relative-dir>/<object-name>.policy.yaml`
   - built by `policy_path_for_object()` (`corpus/policy_utils.py:31-34`)
3. legacy flat object policy:
   - `corpus/policies/<object-name>.policy.yaml`
   - built by `legacy_flat_policy_path()` (`corpus/policy_utils.py:62-63`)

So `--use-policy` means "try policy file resolution from `corpus/policies/` first, otherwise fall back to auto-scan."

### How the benchmark invokes `micro_exec`

`run_target_locally()` builds two kinds of recompile commands:

- compile-only recompile run: `corpus/_driver_impl_run_corpus_v5_vm_batch.py:542-560`
- execute-after-load recompile run: `580-598`

Those go through:

1. local wrapper `build_runner_command()` (`331-360`)
   - implementation: `corpus/_driver_impl_run_corpus_v5_vm_batch.py:331-360`
2. shared `build_run_kernel_command()` in `corpus/common.py:194-233`
3. shared micro command builder in `micro/orchestrator/commands.py`

Important detail: `build_run_kernel_command()` sets:

```python
recompile_all = recompile_v5 and policy_file is None
```

(`corpus/common.py:212-229`)

So:

- if a resolved policy file exists, the command uses `--policy-file`
- if no policy file exists, it falls back to `--recompile-v5 --recompile-all`

### How policy YAML becomes a blob

Exactly the same as the micro benchmark path, because corpus VM batch also delegates application to `micro_exec`.

The corpus script does run the scanner binary, but only to produce offline site counts from a dumped xlated program:

- baseline compile dumps xlated to a temp file (`corpus/_driver_impl_run_corpus_v5_vm_batch.py:503-523`)
- scanner runs on that dump (`524-532`)

That scanner invocation is informational only. It is not the mechanism that applies policy.

Actual policy compilation/apply still happens in-process inside `micro_exec`:

- parse config
- scan xlated instructions
- filter rules
- build blob
- call `BPF_PROG_JIT_RECOMPILE`

### How the blob is passed to the kernel

Still through `micro_exec`'s raw syscall path in `micro/runner/src/kernel_runner.cpp:1096-1143`.

No `bpftool`.

### What happens if the program is already loaded by another process?

Same answer as micro benchmark: corpus VM batch loads its own instance from the object file and recompiles that instance only.

It never attaches to an already-loaded daemon-owned program.

### Can it apply policy to a program it did not load itself?

No.

This pipeline is also object-file-driven and has no prog-FD targeting interface.

### Important caveat: host fallback

If VM setup fails, host fallback mode explicitly sets:

- `enable_recompile=False`
- `enable_exec=False`

in `corpus/_driver_impl_run_corpus_v5_vm_batch.py:1328-1342`.

So in host fallback, policy resolution may still run for bookkeeping, but no policy is actually applied.

## Scenario 3: E2E bpftrace

### Entry point

The case entry is `run_case()` in `e2e/cases/bpftrace/case.py:666-757`.

For each selected script, it runs:

1. baseline `run_phase(..., apply_rejit=False)` (`683-689`)
2. rejit `run_phase(..., apply_rejit=True)` (`691-698`)

The per-phase work is in `run_phase()` (`347-430`).

### How policy YAML is found / resolved

It is not.

This case has no policy-YAML resolution logic, no `--policy` CLI, and no use of `corpus/policies/`.

### How recompilation is done

`run_phase()`:

1. starts `bpftrace` (`355`)
2. waits for attached programs belonging to that process (`380-384`)
3. collects `prog_ids` (`386-388`)
4. scans them with `scan_programs(prog_ids, scanner_binary)` (`390-392`)
5. if `apply_rejit=True`, filters to programs with at least one site (`394-404`)
6. applies recompilation with `apply_recompile(eligible_prog_ids, scanner_binary)` (`406`)

`apply_recompile()` in `e2e/common/recompile.py:205-255` runs:

```bash
bpf-jit-scanner apply --prog-fd <fd> --all --v5 --program-name <name>
```

No `--config` is passed, so this is always scanner auto-scan apply.

### How the blob is passed to the kernel

Inside scanner:

1. live xlated fetch by prog FD
2. `scan_v5_builtin()`
3. `build_policy_blob_v5()`
4. memfd
5. raw `BPF_PROG_JIT_RECOMPILE`

Implementation:

- `scanner/src/cli.cpp:393-434`
- `scanner/src/cli.cpp:797-827`
- `scanner/src/cli.cpp:441-497`

### What if bpftrace owns the program?

This is exactly the intended case.

The harness discovers bpftrace-owned program IDs, then reacquires a program FD using either:

- `bpf_prog_get_fd_by_id()`
- or `/proc/<pid>/fd/<n>` duplication fallback

from `e2e/common/recompile.py:24-56`.

If that succeeds, scanner applies recompilation to the live bpftrace-owned program in place.

If it fails, the per-program result contains an error and the case may be skipped.

### Can it apply policy to a program it did not load itself?

Yes, in principle.

But current `bpftrace` case only supports auto-scan apply, not policy-YAML apply.

## Scenario 4: E2E tracee

### Entry point

The case entry is `run_tracee_case()` in `e2e/cases/tracee/case.py:734-825`.

It has two modes:

1. daemon mode if a Tracee binary is available
2. manual fallback mode if it is not (`756-765`)

### How policy YAML is found / resolved

It is not.

`e2e/cases/tracee/config.yaml` is workload/event configuration, not scanner policy.

No JIT policy YAML is resolved or passed.

### Daemon mode

`TraceeAgentSession` (`e2e/cases/tracee/case.py:168-251`) launches Tracee and then duplicates live owner FDs from the Tracee process:

- it finds programs belonging to the daemon (`196-219`)
- for each owner FD, it duplicates it via `pidfd_getfd` or `/proc/<pid>/fd/<n>` (`85-103`, `213-219`)
- stores them in `session.program_fds`

Then `run_tracee_case()` does:

```python
scan_results = scan_programs(prog_ids, scanner_binary, prog_fds=session.program_fds)
recompile_results = apply_recompile(prog_ids, scanner_binary, prog_fds=session.program_fds)
```

(`e2e/cases/tracee/case.py:783-784`)

So the live Tracee-owned programs are scanned and recompiled via prog FD.

### Manual fallback mode

If Tracee daemon mode is unavailable, `run_manual_fallback()` (`e2e/cases/tracee/case.py:676-731`) loads programs itself and passes owned FDs into the same shared helpers.

That path still does:

```python
scan_programs(..., prog_fds=prog_fds)
apply_recompile(..., prog_fds=prog_fds)
```

### How policy becomes a blob

Again, no YAML today.

The blob is built inside scanner auto-apply using:

- live xlated fetch
- `scan_v5_builtin()`
- `build_policy_blob_v5()`

### What happens if Tracee already owns the program?

Daemon mode is built around that case. The harness duplicates the owner's FD and recompiles the live program in place.

### Can it apply policy to a program it did not load itself?

Yes, in daemon mode, provided it can duplicate the daemon's prog FD.

But like bpftrace, current wiring is auto-scan only; no YAML config is passed through.

## Scenario 5: E2E tetragon

### Entry point

The main case flow is `run_tetragon_case()` in `e2e/cases/tetragon/case.py:1080-1142`.

It also has:

1. daemon mode via `daemon_payload()` (`1015-1068`)
2. manual fallback via `manual_fallback_payload()` (`946-1012`)

### Does it support policy?

It supports Tetragon tracing-policy YAML, not scanner JIT policy YAML.

This is the most important distinction in this case.

`write_tetragon_policy()` and `write_tetragon_policies()` generate Kubernetes-style `TracingPolicy` YAMLs for Tetragon itself (`e2e/cases/tetragon/case.py:485-540`), e.g.:

```yaml
apiVersion: cilium.io/v1alpha1
kind: TracingPolicy
...
```

Those files control what Tetragon loads and attaches. They are not passed to `bpf-jit-scanner --config`.

### Daemon mode

`daemon_payload()`:

1. writes temporary Tetragon tracing-policy YAMLs (`1026-1028`)
2. starts `tetragon --tracing-policy-dir <dir>` (`1029`)
3. collects live program IDs from the running daemon (`1030-1032`)
4. scans them with `scan_programs()` (`1033`)
5. recompiles them with `apply_recompile()` (`1034`)

Again, `apply_recompile()` is the shared auto-scan helper and does not pass YAML config.

### Manual fallback mode

`manual_fallback_payload()` loads specific Tetragon corpus objects directly (`957-975`) and then uses the same scanner helpers on the resulting prog IDs.

### How the blob is passed to the kernel

Through scanner `apply`:

- memfd
- raw `BPF_PROG_JIT_RECOMPILE`

### What happens if Tetragon owns the program?

Daemon mode recompiles that live Tetragon-owned program, assuming the harness can open or duplicate a prog FD.

### Can it apply policy to a program it did not load itself?

Yes for auto-scan live apply.

No for JIT policy YAML today, because the case never threads `--config` into scanner.

## Direct Answers To The Ownership Questions

### What happens if the program is already loaded by another process?

It depends on which pipeline you use.

#### Micro benchmark / corpus VM batch

- They load a fresh instance from the ELF object.
- Recompile is applied only to that newly loaded FD.
- The already-running external program is untouched.

#### E2E bpftrace / tracee / tetragon

- They discover the live program ID.
- They reacquire or duplicate a live prog FD.
- Scanner applies recompile to that already-loaded program in place.

So for live daemons, the e2e path can modify the program the daemon is actually using.

### Can we apply policy to a program we didn't load ourselves?

#### Repo capability

Yes, the repo has the primitive for it:

```bash
bpf-jit-scanner apply --prog-fd <fd> --config policy.yaml
```

Scanner supports this in `scanner/src/cli.cpp:797-827`.

#### Current scenario coverage

- Micro benchmark: No
- Corpus VM batch: No
- E2E bpftrace: Yes for auto-scan, no for YAML policy
- E2E tracee: Yes for auto-scan, no for YAML policy
- E2E tetragon: Yes for auto-scan, no for YAML policy

## Where The Pipeline Breaks Today

### 1. E2E live-program cases do not support YAML policy

This is the biggest gap.

`e2e/common/recompile.py` always runs scanner `apply --all --v5` without `--config` (`e2e/common/recompile.py:230-244`).

That means:

- bpftrace cannot use `corpus/policies/...`
- tracee cannot use `corpus/policies/...`
- tetragon cannot use `corpus/policies/...`

The scanner supports it; the wrappers just do not expose it.

### 2. Micro/corpus policy apply is limited to programs loaded by `micro_exec`

The object-file-driven pipeline cannot target a live existing program. There is no `micro_exec run-kernel --prog-fd ...` mode.

So `run_micro.py` and corpus VM batch are not useful for "apply policy to the program bpftrace already loaded".

### 3. Policy resolution exists only for object paths, not for live daemon-owned programs

`corpus/policy_utils.py` resolves policy based on object-path layout.

Live e2e programs are discovered as `(prog_id, prog name, owner pid/fd)`, not as a stable originating object path. That makes automatic `corpus/policies/` lookup for live programs underspecified today.

### 4. Scanner `apply` only takes `--prog-fd`

This is workable but awkward.

The repo had to build custom prog-ID -> FD recovery logic in `e2e/common/recompile.py`. Scanner itself has no:

- `--prog-id`
- pinned-path input
- owner-pid/fd discovery

So every live-program harness has to solve FD acquisition separately.

### 5. Host fallback in corpus VM batch never applies policy

When VM mode is unavailable, corpus VM batch intentionally disables recompile. So `--use-policy` in host fallback is bookkeeping only.

### 6. There are two policy-compilation front ends

Today both of these exist:

- scanner CLI path: `bpf-jit-scanner compile-policy/apply`
- in-process `micro_exec` path using scanner library calls directly

They share the same lower-level library, but there are still two user-facing orchestration paths. That makes it easy for live-program and object-file workflows to drift.

### 7. Corpus policies are mostly coarse family-level policies

The corpus files under `corpus/policies/` are almost all family action maps. The parser supports `site_overrides`, but the corpus policy set does not really use that power today.

For complex multi-program real-world objects, family-only control may be too coarse.

### 8. Micro inline policy semantics are weaker than they look

Because `BenchmarkSpec.inline_policy_text` only records `skip` actions (`micro/benchmark_catalog.py:124-140`), a manifest entry like:

```yaml
policy:
  COND_SELECT: apply
```

does not mean "only apply CMOV". It means "denylist nothing", so any other discovered family would also be eligible.

## Practical Bottom Line

### If you start from a suite YAML / object file

Use the `micro_exec` pipeline:

- policy resolved from suite or `corpus/policies/`
- parsed in-process
- blob built in-process
- raw `BPF_PROG_JIT_RECOMPILE`

This is what micro benchmark and corpus VM batch do.

### If you start from a live already-loaded program

Use the scanner live-program pipeline:

- get a prog FD
- run `bpf-jit-scanner apply --prog-fd <fd> [--config policy.yaml]`

This is what the e2e harnesses almost do today, except they omit `--config` and therefore never apply YAML-driven policy.

### The main missing bridge

The repo already has all the pieces for:

1. resolve a policy YAML for a live program
2. get a live prog FD
3. run `scanner apply --prog-fd <fd> --config <policy>`

But the current e2e cases only implement steps 2 and 3 in auto-scan mode, not the YAML-policy version.
