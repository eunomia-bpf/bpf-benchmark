# cilium/ebpf shim POC

This POC verifies the cgo hook in `vendor/repos/cilium-ebpf`: unchanged host
application code that uses normal `github.com/cilium/ebpf` APIs can reach the
shim through `LD_PRELOAD`, then the shim runs an `execute_plan` against the
tracked programs.

Covered paths:

- `BPF_MAP_CREATE`, `BPF_MAP_UPDATE_ELEM`, and `BPF_MAP_LOOKUP_ELEM` through
  cilium/ebpf map APIs.
- `BPF_PROG_LOAD` for a socket-filter program that references a map.
- `BPF_LINK_CREATE` for a cgroup skb program attached to a temporary cgroup.
- `execute_plan` with one or more passes, including a post-ReJIT check that the
  cgroup `bpf_link` now points at the new program id returned by the shim.

Build:

```sh
GOTOOLCHAIN=auto CGO_ENABLED=1 go build -o cilium-ebpf-shim-poc .
```

Run on a BpfReJIT kernel with the shim and `bpfopt` available:

```sh
SHIM_DIR=/tmp/cilium-ebpf-shim-poc
install -d "$SHIM_DIR"
sudo env \
  BPFREJIT_SHIM_DIR="$SHIM_DIR" \
  BPFREJIT_SHIM_SOCK_DIR="$SHIM_DIR" \
  BPFREJIT_SHIM_LOG="$SHIM_DIR/shim.log" \
  PATH="/home/yunwei37/workspace/bpf-benchmark/bpfopt/target/release:$PATH" \
  LD_PRELOAD="/home/yunwei37/workspace/bpf-benchmark/bpfopt/shim/build-x86/libbpfrejit_shim.so" \
  ./cilium-ebpf-shim-poc -pass noop,map_inline
```

Expected success ends with:

```text
cilium/ebpf map load, cgroup bpf_link attach, and execute_plan completed
```

On a stock kernel without the fork-only ReJIT command, the program may load but
`execute_plan` is expected to fail in the shim reload step.
