# syntax=docker/dockerfile:1.6
FROM bpf-benchmark/kprog-paired-context:c-20261106
COPY libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
COPY libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY bpf_x86_native_lab.ko /artifacts/kinsn/bpf_x86_native_lab.ko
COPY native-link /usr/local/bin/native-link
COPY bcc /artifacts/user/native-bpf/x86_64/bcc
