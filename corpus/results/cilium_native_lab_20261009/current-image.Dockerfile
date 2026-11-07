# syntax=docker/dockerfile:1.6
ARG BASE_IMAGE
FROM ${BASE_IMAGE}
RUN rm -rf /artifacts/lib/modules /artifacts/kinsn
COPY --from=modules / /artifacts/lib/modules
RUN depmod -b /artifacts 7.0.0-rc2+
COPY --from=boot /bzImage /artifacts/kernel/bzImage
COPY --from=offsets /kernel_offsets.h /artifacts/kernel/kernel_offsets.h
COPY --from=kinsn / /artifacts/kinsn
COPY --from=current /vendor/build/native-bpf/x86/stage/cilium /artifacts/user/native-bpf/x86_64/cilium
COPY --from=current /vendor/build/x86/cilium/bin/cilium-agent /usr/local/bin/cilium-agent
COPY --from=current /vendor/repos/cilium/bpf /var/lib/cilium/bpf
COPY --from=bpftool /bpftool /usr/local/bin/bpftool
COPY --from=shim /libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
COPY --from=loader /libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY --from=current /kprog/x86/native_lab/native_link/target/release/native-link /usr/local/bin/native-link
COPY --from=current /runner /workspaces/repository/runner
COPY --from=current /corpus/*.py /workspaces/repository/corpus/
COPY --from=current /corpus/config /workspaces/repository/corpus/config
COPY --from=current /corpus/inputs /workspaces/repository/corpus/inputs
COPY --from=current /micro/*.py /workspaces/repository/micro/
COPY --from=current /micro/config /workspaces/repository/micro/config
COPY --from=current /vendor/bpfrejit_x86_defconfig /workspaces/repository/vendor/bpfrejit_x86_defconfig
RUN install -d /workspaces/repository/corpus/results
WORKDIR /workspaces/repository
ENV BPFREJIT_IMAGE_WORKSPACE=/workspaces/repository PYTHONPATH=/workspaces/repository
