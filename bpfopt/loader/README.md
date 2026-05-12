# bpfopt Host Loader

`bpfopt-loader` is a host-side developer fixture tool for running `bpfopt` on
real `.bpf.o` programs without the ReJIT daemon or KVM. It is not a benchmark
entrypoint and must not replace app-level corpus loading.

## Commands

```sh
cargo build -p bpfopt-loader
```

Prepare a workdir from one program in a BPF object:

```sh
BPFOPT=target/debug/bpfopt target/debug/bpfopt-loader prepare \
  --obj path/to/test.bpf.o \
  --prog xdp \
  --out /tmp/bpfopt-work
```

Run a bpfopt pass on that workdir:

```sh
target/debug/bpfopt-loader run \
  --workdir /tmp/bpfopt-work \
  --pass noop
```

Run `map_inline` with a hard hint:

```sh
target/debug/bpfopt-loader run \
  --workdir /tmp/bpfopt-work \
  --pass map_inline -- --inline-hint=5:!00000000
```

Optionally verifier-load the transformed bytecode on the host:

```sh
target/debug/bpfopt-loader verify --workdir /tmp/bpfopt-work
```

## Workdir Layout

- `canonicalize_input.bin`: relocated bytecode from libbpf after object load.
- `input.bin`: bytecode after `bpfopt --canonicalize-map-refs`.
- `map-ids.json`: program `used_maps` IDs in kernel order.
- `map-values/`: map snapshots in the schema accepted by `map_inline`.
- `metadata.json`: selected program name, section, and program type.
- `verifier.log`: host verifier log from the selected program load.
- `output.bin` / `report.json`: default `run` outputs.

## Boundaries

- The loader invokes `bpfopt` as an external CLI over bytecode files.
- It stays out of `runner/`, `corpus/`, and benchmark Make targets.
- It uses host libbpf/BPF syscalls only for developer fixture preparation and
  optional host verifier checks.
- Kinsn passes still require a host kernel with matching kfunc modules.
- Map-in-map snapshot/verify support is intentionally not implemented yet; the
  loader fails fast if a selected program needs it.
