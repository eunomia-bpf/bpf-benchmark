set -eu
D=/workspaces/.agent-state/kprog-lanes/C/design-only
A="$D/apps"
trap 'echo $? > "$A/run.exit"' EXIT
cd /workspaces/repository
make -C kprog/libnativeloader trusted-service BUILD_DIR="$D/loader"
make -C bpfopt/shim SHIM_SO="$D/libbpfrejit_shim.so" "$D/libbpfrejit_shim.so"
docker build -f "$A/Dockerfile" -t bpf-benchmark/kprog-design-only:c-20261108 "$D"
make -f "$A/Makefile" corpus STATE="$A" CPUS=20-23 VM_CPUS=8 VM_MEM=8G APPS=bcc/set,katran SAMPLES=1 WORKLOAD_DURATION=2
