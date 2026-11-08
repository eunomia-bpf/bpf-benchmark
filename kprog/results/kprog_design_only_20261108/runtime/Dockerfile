FROM bpf-benchmark/kprog-native-only:x86-current
COPY native-link /usr/local/bin/native-link
COPY loader/libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
COPY all-modules/*.ko /artifacts/kinsn/
COPY build/arch/x86/boot/bzImage /artifacts/kernel/bzImage
COPY runtime-modules/lib/modules /artifacts/lib/modules
