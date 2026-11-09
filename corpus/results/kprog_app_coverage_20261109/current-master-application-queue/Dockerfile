FROM bpf-benchmark/kprog-current-master:c-base-20261109
COPY native-bpf/ /artifacts/user/native-bpf/x86_64/
COPY libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY native-link /usr/local/bin/native-link
COPY bpf_x86_native_lab.ko /artifacts/kinsn/bpf_x86_native_lab.ko
COPY native_compat.h native_division.so /usr/local/lib/bpfrejit/native/
COPY --chmod=0755 tracee /artifacts/tracee/bin/tracee
COPY tracee.bpf.o /artifacts/tracee/tracee.bpf.o
COPY lsm_support/ /artifacts/tracee/lsm_support/
COPY tetragon-bpf/ /artifacts/tetragon/
