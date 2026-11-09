FROM bpf-benchmark/kprog-coherent-six:c-20261109
COPY native-bpf/ /artifacts/user/native-bpf/x86_64/katran/
COPY libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
COPY native_division.so /usr/local/lib/bpfrejit/native/native_division.so
COPY config /artifacts/kernel/config
COPY config /artifacts/boot/config-7.0.0-rc2
COPY config /boot/config-7.0.0-rc2

COPY framework/ /workspaces/repository/
ENV BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1
ENV BPFREJIT_BENCH_PASSES=""
