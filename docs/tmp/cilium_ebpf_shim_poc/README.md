# cilium/ebpf shim POC

This POC verifies the cgo hook in `vendor/repos/cilium-ebpf`: a program loaded
with `github.com/cilium/ebpf.NewProgram` reaches the shim through
`LD_PRELOAD`, then the shim runs an `execute_plan` step against the tracked
program.

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
  ./cilium-ebpf-shim-poc -pass noop
```

Expected success ends with:

```text
cilium/ebpf load reached shim and execute_plan completed
```

On a stock kernel without the fork-only ReJIT command, the program may load but
`execute_plan` is expected to fail in the shim reload step.
