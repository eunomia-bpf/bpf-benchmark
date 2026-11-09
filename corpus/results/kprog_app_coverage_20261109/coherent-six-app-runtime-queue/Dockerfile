FROM bpf-benchmark/kprog-current-master:c-base-20261109
COPY native-bpf/ /artifacts/user/native-bpf/x86_64/
COPY libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY native-link /usr/local/bin/native-link
COPY native_compat.h native_division.so /usr/local/lib/bpfrejit/native/
COPY --chmod=0755 tracee /artifacts/tracee/bin/tracee
COPY tracee.bpf.o /artifacts/tracee/tracee.bpf.o
COPY lsm_support/ /artifacts/tracee/lsm_support/
COPY tetragon-bpf/ /artifacts/user/repo-artifacts/x86_64/tetragon/
RUN rm -rf /artifacts/lib/modules /artifacts/kinsn
COPY modules/ /artifacts/lib/modules/
COPY kinsn/ /artifacts/kinsn/
COPY kernel/ /artifacts/kernel/
COPY manifest.json /artifacts/manifest.json
RUN depmod -b /artifacts 7.0.0-rc2
COPY libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
