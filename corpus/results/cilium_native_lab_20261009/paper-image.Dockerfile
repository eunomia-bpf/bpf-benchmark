# syntax=docker/dockerfile:1.6
# Historical corpus/loader/kernel, with an existing Ubuntu 24.04 dependency base.
# The old general-suite image references deleted negative-test executables;
# this task image contains the real Cilium startup path and its native artifacts.
ARG BASE_IMAGE
FROM ${BASE_IMAGE}
ARG PAPER_ROOT=/workspaces/.agent-state/bpf-benchmark-supervisor/cilium-lab-20261009/paper-tree
RUN rm -rf /artifacts/lib/modules /artifacts/kinsn /artifacts/user/native-bpf/x86_64/cilium
COPY --from=modules / /artifacts/lib/modules
RUN depmod -b /artifacts 7.0.0-rc2+
COPY --from=boot /bzImage /artifacts/kernel/bzImage
COPY --from=offsets /kernel.config /artifacts/kernel/config
COPY --from=offsets /kernel_offsets.h /artifacts/kernel/kernel_offsets.h
COPY --from=kinsn / /artifacts/kinsn
COPY --from=paper /vendor/build/native-bpf/x86/stage/cilium /artifacts/user/native-bpf/x86_64/cilium
COPY --from=paper /vendor/build/x86/cilium/bin/cilium-agent /usr/local/bin/cilium-agent
COPY --from=bpftool /bpftool /usr/local/bin/bpftool
COPY --from=paper /vendor/repos/cilium/bpf /var/lib/cilium/bpf
COPY --from=paper /bpfopt/shim/build-x86/libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
COPY --from=loader /libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY --from=paper /native-sim/x86/native_lab/native_link/target/release/native-link /usr/local/bin/native-link
COPY --from=paper /runner ${PAPER_ROOT}/runner
COPY --from=paper /corpus/*.py ${PAPER_ROOT}/corpus/
COPY --from=paper /corpus/config ${PAPER_ROOT}/corpus/config
COPY --from=paper /corpus/inputs ${PAPER_ROOT}/corpus/inputs
COPY --from=paper /micro/*.py ${PAPER_ROOT}/micro/
COPY --from=paper /micro/config ${PAPER_ROOT}/micro/config
COPY --from=paper /vendor/bpfrejit_x86_defconfig ${PAPER_ROOT}/vendor/bpfrejit_x86_defconfig
RUN printf '{"kernel_release":"7.0.0-rc2+","target_arch":"x86_64","kernel_image":"bzImage"}\n' >/artifacts/manifest.json && install -d ${PAPER_ROOT}/corpus/results
WORKDIR ${PAPER_ROOT}
ENV BPFREJIT_IMAGE_WORKSPACE=${PAPER_ROOT} PYTHONPATH=${PAPER_ROOT} BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF=""
