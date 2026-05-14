# bpfopt Host Loader

`bpfopt-loader` is a host-side developer fixture tool for running `bpfopt` on
real `.bpf.o` programs without the ReJIT daemon or KVM. It is not a benchmark
entrypoint and must not replace app-level corpus loading.

## Commands

```sh
cargo build --manifest-path bpfopt/Cargo.toml -p bpfopt-loader
```

Run one pass against one program in a BPF object:

```sh
bpfopt/target/debug/bpfopt-loader \
  --obj path/to/test.bpf.o \
  --pass noop \
  --workdir /tmp/bpfopt-loader-work
```

The loader always prepares a fresh workdir from the object, runs
`bpfopt --canonicalize-map-refs`, optionally runs one pass through
`runner/config/passes/<pass>/default.yaml`, and verifier-loads the pass output
with `BPF_PROG_LOAD`.

## BPF_PROG_TEST_RUN

`--bpftestrun` runs `bpf_prog_test_run_opts()` after the transformed bytecode
has been verifier-loaded on the host:

```sh
bpfopt/target/debug/bpfopt-loader \
  --obj path/to/test.bpf.o \
  --pass noop \
  --bpftestrun \
  --repeat 128 \
  --workdir /tmp/bpfopt-loader-work
```

Outputs are written under the selected program directory:

- `test_input.bin`: bytes passed through `data_in`.
- `test_run.json`: `retval`, `duration_ns`, `repeat`, and `data_size_out`.
- `test_output.bin`: bytes returned through `data_out` when the kernel returns
  one.

Use `--pass noop` to test unoptimized bytecode. `--bpftestrun` intentionally
requires a pass because the current host verifier path loads `output.bin`.

## Katran Host Smoke

Katran's corpus path uses the real `katran_server_grpc`, network namespaces,
`wrk`, and live ReJIT. The loader path is not that benchmark path: it uses
host-side `BPF_PROG_LOAD + BPF_PROG_TEST_RUN` and is only a functional smoke.

For Katran `balancer_ingress`, use:

```sh
sudo -n bash -lc 'ulimit -l unlimited; cd /home/yunwei37/workspace/bpf-benchmark; \
  bpfopt/target/debug/bpfopt-loader \
    --obj bpfopt/testobject/katran_balancer.bpf.o \
    --pass noop \
    --bpftestrun \
    --katran-maps \
    --repeat 1 \
    --workdir /tmp/bpfopt-loader-katran-bpftestrun'
```

`--katran-maps` recreates the explicit map configuration from
`runner/libs/app_runners/katran.py::configure_katran_maps`:

- `ctl_array[0] = 02:00:00:00:00:0b`.
- `vip_map[10.100.1.1:8080/tcp] = { flags: F_LRU_BYPASS, vip_num: 0 }`.
- `reals[1] = 10.200.0.2`.
- `ch_rings[0..65536] = 1`.

The transformed program is verifier-loaded against the maps that libbpf already
created from the object; the loader does not rebuild Katran maps from scratch.

When `--katran-maps --bpftestrun` is used, the loader reads the same packet file
used by the corpus-side Katran prog-test fixture:
`corpus/inputs/katran_vip_packet_64.bin`. This packet is client
`10.0.0.2` to VIP `10.100.1.1:8080/tcp` at the Katran XDP ingress point. In
host `BPF_PROG_TEST_RUN`, `--repeat 1` is the semantic check: it should return
`XDP_TX` (`retval=3`) with an IPIP-encapsulated packet in `test_output.bin`.

For Katran, `--repeat 1` writes `test_output.bin` for packet inspection. Katran
`--repeat > 1` automatically uses the kernel's XDP live-frames mode, where
`repeat` is a fresh packet count inside one kernel test-run call. That path does
not return `data_out` or `ctx_out`, so `test_output.bin` is not written.

```sh
sudo -n bash -lc 'ulimit -l unlimited; cd /home/yunwei37/workspace/bpf-benchmark; \
  bpfopt/target/debug/bpfopt-loader \
    --obj bpfopt/testobject/katran_balancer.bpf.o \
    --pass noop \
    --bpftestrun \
    --katran-maps \
    --repeat 10000 \
    --workdir /tmp/bpfopt-loader-katran-live-frames'
```

This uses the same corpus ingress packet as a template for every fresh frame.
Do not use the live-frames `retval` as the semantic check; use the prior
`--repeat 1` run and packet output inspection for that.

The loader skips map value dumps unless `--pass map_inline` is selected. For
`map_inline`, large maps are left as `map show` metadata only so Katran's
existing overlay/size-skip path can handle them.

## Workdir Layout

- `<prog>/canonicalize_input.bin`: relocated bytecode from libbpf after object
  load.
- `<prog>/input.bin`: bytecode after `bpfopt --canonicalize-map-refs`.
- `<prog>/map-ids.json`: program `used_maps` IDs in kernel order.
- `<prog>/metadata.json`: selected program name and load metadata.
- `<prog>/verifier.log`: verifier log from the original object load.
- `<prog>/output.bin` / `<prog>/report.json`: pass outputs.
- `<prog>/verify.log`: verifier log from host-loading `output.bin`.
- `<prog>/test_input.bin` / `<prog>/test_run.json` /
  `<prog>/test_output.bin`: optional bpftestrun input and outputs.
- `map-values/`: `bpftool map show` files, plus small `bpftool map dump` files
  when `--pass map_inline` needs value snapshots.

## Boundaries

- The loader invokes `bpfopt` as an external CLI over bytecode files.
- It stays out of `runner/`, `corpus/`, and benchmark Make targets.
- It uses host libbpf/BPF syscalls only for developer fixture preparation and
  optional host verifier/test-run checks.
- Kinsn passes still require a host kernel with matching kfunc modules.
