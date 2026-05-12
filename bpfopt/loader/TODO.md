# bpfopt Host Loader TODO

Purpose: add a host-side developer test harness that can feed real `.bpf.o`
programs into `bpfopt` without the ReJIT daemon or KVM. This is not a benchmark
entrypoint and must not replace app-level corpus loading.

## Boundaries

- Must invoke `bpfopt` as an external CLI over raw bytecode files.
- Must stay out of `runner/`, `corpus/`, and benchmark Make targets.
- May use host libbpf/BPF syscalls only to prepare test fixtures: load a test
  object, seed maps, collect map snapshots, collect verifier logs, and optionally
  verifier-load the transformed bytecode.
- Must fail fast on missing capabilities. No fallback to skipping verifier state,
  partial map dumps, or silently dropping parser failures.
- Kinsn passes still require a host kernel with the matching kfunc modules. The
  loader only removes the KVM/daemon requirement for pure bytecode passes such as
  `noop`, `map_inline`, `const_prop`, `dce`, `wide_mem`, and packet/CFG rewrites.

## Proposed Flow

1. `loader prepare --obj test.bpf.o --prog <section-or-name> --maps seed.json --out workdir`
   - Open the object with libbpf.
   - Seed maps from a small explicit JSON fixture.
   - Load the selected program on the host with verifier logging enabled.
   - Write:
     - `input.bin`: relocated raw BPF instructions for the selected program.
     - `verifier-states.json`: strict JSON converted from the host verifier log.
     - `map-values/`: the map snapshot schema already accepted by `map_inline`.
     - `map-ids.json`: `{"map_ids":[...]}` in `used_maps` order.

2. `loader run --workdir workdir --pass map_inline -- [bpfopt pass args]`
   - Invoke `bpfopt --pass ... --input input.bin --output output.bin`.
   - Pass `--verifier-states`, `--map-values`, and `--map-ids` from the workdir.
   - Preserve `report.json`, stdout, and stderr for tests.

3. `loader verify --workdir workdir --input output.bin`
   - Optional host `BPF_PROG_LOAD` validation for transformed bytecode.
   - No `BPF_PROG_REJIT`; this only checks ordinary verifier acceptance on the
     host kernel.

## Implementation Notes

- Keep this as a small standalone dev tool under `bpfopt/loader`; do not add a
  compile-time dependency from `bpfopt` to the loader.
- The loader can share fixture schemas by calling the `bpfopt` CLI and writing
  files in existing formats. If Rust code is used, prefer a separate package that
  depends on libbpf-rs/libbpf-sys, not the benchmark runner.
- Raw verifier logs must be converted before `bpfopt` runs. The converter should
  be strict: if a state-looking line or attribute cannot be parsed, exit 1 with a
  line number.
- `.bpf.o` extraction needs an explicit decision:
  - Preferred: use libbpf's relocated program instructions after object open/load
    so map relocations match the host load.
  - If libbpf cannot expose the exact relocated original bytecode, restrict the
    first version to fixtures whose bytecode is already available as `input.bin`.

## Test Plan

- `noop`: load a tiny host fixture, run `bpfopt --pass noop`, verify output is
  byte-identical and host verifier accepts it.
- `map_inline` hard hint: seed an array map, dump snapshot, run with
  `--inline-hint=<pc>:!<key>`, assert the value load becomes a constant.
- `map_inline` soft hint: seed a hash map and use a program with an immediate
  null check; assert lookup/null-check remain while the non-null value load is
  constantized.
- `const_prop + dce`: run after `map_inline` to catch verifier-state JSON and
  BTF/offset remapping mistakes.

## Open Items

- Add real multi-key soft-hint support only after BBProgram grows an explicit
  guarded-CFG insertion helper. Current `map_inline` soft hint intentionally
  supports one guarded key per lookup site.
- Decide whether the loader should be Rust or Python after checking libbpf access
  to relocated instructions. Rust is preferred if it avoids shelling out to
  `bpftool` and gives structured errors.
