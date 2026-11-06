# syntax=docker/dockerfile:1.6
ARG BASE_IMAGE
FROM ${BASE_IMAGE} AS paired-runtime
RUN rm -rf /artifacts/lib/modules /artifacts/kinsn
COPY --from=paired-context /stock/lib/modules /artifacts/lib/modules
COPY --from=paired-context /bpf_x86*.ko /artifacts/kinsn/
COPY --from=paired-context /bzImage /artifacts/kernel/bzImage
RUN depmod -b /artifacts 7.0.0-rc2+
COPY --from=paired-context /libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY --from=bcc-verified /libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
COPY --from=bcc-verified /native-link /usr/local/bin/native-link
FROM paired-runtime AS verified-bcc
COPY --from=bcc-verified /bcc /artifacts/user/native-bpf/x86_64/bcc
