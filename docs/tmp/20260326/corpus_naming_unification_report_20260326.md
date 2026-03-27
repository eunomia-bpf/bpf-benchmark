# Corpus Naming Unification Report

Date: 2026-03-26

## Summary

- `corpus/config/macro_corpus.yaml` now uses canonical `name` values for all 764 program entries.
- Canonical format is `repo:object:program`.
- To avoid collisions where one repo has multiple objects with the same basename, `object` is the path relative to `corpus/build/<repo>/` when needed, for example `xdp-tutorial:basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func`.
- For entries with `program_names`, the `program` token is the `+`-joined bundle, for example `tracee:tracee.bpf.o:tracepoint__raw_syscalls__sys_enter+sys_enter_init+...`.
- `corpus/modes.py` now treats `name` as the canonical target identifier, auto-generates it when absent, and uses it in filtering, sorting, JSON records, progress metadata, and markdown output.

## Missing-Entry Investigation

### Cilium

Checked built objects under `corpus/build/cilium/`:

- `bpf_lxc.bpf.o`
- `bpf_overlay.bpf.o`
- `bpf_xdp.bpf.o`

All three fail `runner/build/micro_exec list-programs --program <object>` with `bpf_object__open_file failed: Operation not supported` because libbpf rejects static tail programs in these objects.

Per task instruction, no new Cilium per-program corpus entries were added for objects that fail `bpf_object__open_file`.

### xdp-examples

`xdp-examples` is present in `runner/repos.yaml` and checked out under `runner/repos/xdp-examples/`.

I ran:

```bash
make corpus-build-objects REPOS='xdp-examples'
```

Result:

- `corpus/build/xdp-examples/` still contains 0 `.bpf.o` files.
- The generated build report recorded 13 source failures, all at the `clang` stage.
- Because there are no built objects, no `xdp-examples` corpus entries were added.

This build command also refreshed:

- `corpus/results/expanded_corpus_build.latest.json`
- `corpus/results/expanded_corpus_build.md`

### Additional correctness fix

- Corrected the BCC `cpudist` tp_btf program name from `sched_switch` to `sched_switch_btf`.

## Counts

- Program entries before: 764
- Program entries after: 764
- New corpus entries added: 0
- Entries missing `name`: 0
- Duplicate canonical names: 0

## Verification

Requested command:

```bash
python3 -c 'import yaml; targets=yaml.safe_load(open("corpus/config/macro_corpus.yaml")); print(f"entries={len(targets)}")'
```

Output:

```text
entries=5
```

That command counts top-level YAML keys, not corpus programs. The actual program-entry count is:

```text
program_entries=764
```

Python syntax check:

```bash
python3 -m py_compile corpus/modes.py
```

Result: passed.
