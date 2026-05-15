# Katran bpfopt Loader Performance Smoke

Date: 2026-05-14 local time

This report covers the host-side `bpfopt-loader` smoke for Katran
`balancer_ingress` comparing the regular Rust `bpfopt` noop path with the
LLVM-based `bpfopt` binary, plus a Katran hard-hint smoke for LLVM
`map_inline`:

- Object: `bpfopt/testobject/katran_balancer.bpf.o`
- Program: `balancer_ingress`
- Regular noop binary: `bpfopt/target/debug/bpfopt`
- LLVM binary: `bpfopt/llvm/build/bpfopt`
- Regular path: `--pass noop`
- LLVM O0 path: `--pass noop` with strict LLVM roundtrip
- LLVM O3 path: `--pass dce`; the LLVM bpfopt currently maps non-`noop`
  passes to the O3 LLVM pipeline
- LLVM map_inline path: `--pass map_inline` through
  `docs/tmp/bpfopt_llvm_mapinline_katran_wrapper.sh`, which injects the same
  Katran hard hints and overlays used by the app-specific pass config
- LLVM workdir root: `/tmp/bpfopt-loader-katran-llvm-perf-20260514-212113`
- Regular noop workdir root:
  `/tmp/bpfopt-loader-katran-rust-noop-perf-20260514-212955`
- LLVM map_inline semantic workdir root:
  `/tmp/bpfopt-loader-katran-llvm-mapinline-hints-20260514-215111`
- LLVM map_inline performance workdir root:
  `/tmp/bpfopt-loader-katran-llvm-mapinline-hints-perf-20260514-215150`

This is not the Katran corpus benchmark path. It does not start
`katran_server_grpc`, network namespaces, or workload traffic. It is a
developer smoke that loads the transformed bytecode on the host and runs
`bpf_prog_test_run_opts()`.

## Commands

The semantic check used `--repeat 1`. The regular noop command shape was:

```sh
sudo -n bash -lc 'ulimit -l unlimited; cd /home/yunwei37/workspace/bpf-benchmark; \
  bpfopt/target/debug/bpfopt-loader \
    --obj bpfopt/testobject/katran_balancer.bpf.o \
    --pass noop \
    --bpfopt bpfopt/target/debug/bpfopt \
    --target /tmp/bpfopt-loader-katran-rust-noop-perf-20260514-212955/target.json \
    --bpftestrun \
    --katran-maps \
    --repeat 1 \
    --workdir /tmp/bpfopt-loader-katran-rust-noop-perf-20260514-212955/rust_noop_repeat1_run1'
```

The LLVM O0 command uses the same loader path but points `--bpfopt` at the
LLVM binary:

```sh
sudo -n bash -lc 'ulimit -l unlimited; cd /home/yunwei37/workspace/bpf-benchmark; \
  bpfopt/target/debug/bpfopt-loader \
    --obj bpfopt/testobject/katran_balancer.bpf.o \
    --pass noop \
    --bpfopt bpfopt/llvm/build/bpfopt \
    --target /tmp/bpfopt-loader-katran-llvm-perf-20260514-212113/target.json \
    --bpftestrun \
    --katran-maps \
    --repeat 1 \
    --workdir /tmp/bpfopt-loader-katran-llvm-perf-20260514-212113/o0_repeat1_run1'
```

The LLVM O3 run also replaces `--pass noop` with `--pass dce`. Performance
samples used the same command shape with `--repeat 10000`.

The LLVM map_inline hard-hint command uses the same loader path but points
`--bpfopt` at the temporary wrapper in `docs/tmp`:

```sh
sudo -n bash -lc 'ulimit -l unlimited; cd /home/yunwei37/workspace/bpf-benchmark; \
  bpfopt/target/debug/bpfopt-loader \
    --obj bpfopt/testobject/katran_balancer.bpf.o \
    --pass map_inline \
    --bpfopt docs/tmp/bpfopt_llvm_mapinline_katran_wrapper.sh \
    --target /tmp/bpfopt-loader-katran-llvm-mapinline-hints-20260514-215111/target.json \
    --bpftestrun \
    --katran-maps \
    --repeat 1 \
    --workdir /tmp/bpfopt-loader-katran-llvm-mapinline-hints-20260514-215111/work'
```

For Katran, loader `--repeat > 1` uses XDP live-frames mode. In that mode the
kernel does not return an output packet, so `data_size_out=0`; the reported
number below is the raw `duration_ns` returned by `bpf_prog_test_run_opts()`.

## Semantic Check

All paths returned `XDP_TX` (`retval=3`) with an 84-byte output packet for
`--repeat 1`.

| Mode | Pass | repeat | retval | duration_ns | data_size_out |
| --- | --- | ---: | ---: | ---: | ---: |
| Regular | noop | 1 | 3 | 3047 | 84 |
| LLVM O0 | noop | 1 | 3 | 2950 | 84 |
| LLVM O3 | dce | 1 | 3 | 2909 | 84 |
| LLVM map_inline | map_inline | 1 | 3 | 1822 | 84 |

## Transform Size

| Mode | Pass | input insns | output insns | delta |
| --- | --- | ---: | ---: | ---: |
| Regular | noop | 2542 | 2542 | 0 |
| LLVM O0 | noop | 2542 | 2646 | +104 |
| LLVM O3 | dce | 2542 | 2559 | +17 |
| LLVM map_inline | map_inline | 2542 | 2601 | +59 |

All outputs are verifier-loaded by `bpfopt-loader`. The regular Rust noop is
the unchanged baseline. The LLVM paths are strict roundtrip outputs, not raw
input bytecode.

The LLVM map_inline run applied 16 hard-hint lookup rewrites. The inlined
entries covered `vip_map`, `reals`, `ch_rings`, `ctl_array`, and
`server_id_map`; large Katran arrays came from the temporary wrapper's
`overlays.json` injection.

## Performance Samples

Raw `duration_ns` samples from `--repeat 10000`:

| Run | Regular noop | LLVM O0 noop | LLVM O3 dce | LLVM map_inline |
| ---: | ---: | ---: | ---: | ---: |
| 1 | 118 | 115 | 104 | 119 |
| 2 | 118 | 118 | 108 | 121 |
| 3 | 112 | 120 | 113 | 119 |
| 4 | 121 | 103 | 118 | 122 |
| 5 | 113 | 119 | 117 | 116 |
| 6 | 112 | 110 | 117 | 121 |
| 7 | 121 | 114 | 121 | 122 |
| 8 | 115 | 116 | 120 | 112 |
| 9 | 112 | 109 | 115 | 122 |
| 10 | 109 | 113 | 123 | 118 |

Summary of the raw host loader samples:

| Mode | Pass | n | min | max | mean |
| --- | --- | ---: | ---: | ---: | ---: |
| Regular | noop | 10 | 109 | 121 | 115.1 |
| LLVM O0 | noop | 10 | 103 | 120 | 113.7 |
| LLVM O3 | dce | 10 | 104 | 123 | 115.6 |
| LLVM map_inline | map_inline | 10 | 112 | 122 | 119.2 |

The sample sets overlap heavily. This loader smoke does not show a clear Katran
performance delta among regular noop, LLVM O0 roundtrip, LLVM O3, and LLVM
map_inline. Treat these numbers as a functional and rough host-side signal
only; corpus/app-level Katran performance must still be measured through the
real Katran application path.
