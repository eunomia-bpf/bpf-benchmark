# SPDX-License-Identifier: GPL-2.0
# The 2026-05-29 kernel, modules, shim, loader and native objects with this
# tree's frozen benchmark framework, see README.md.
FROM bpf-benchmark/runner-runtime:x86_64
RUN rm -rf /artifacts/lib/modules /artifacts/kinsn /artifacts/user/native-bpf
COPY modules/ /artifacts/lib/modules/
RUN depmod -b /artifacts 7.0.0-rc2+
COPY bzImage /artifacts/kernel/bzImage
COPY kernel.config /artifacts/kernel/config
COPY kernel_offsets.h /artifacts/kernel/kernel_offsets.h
COPY kinsn/ /artifacts/kinsn/
COPY native-bpf/ /artifacts/user/native-bpf/
COPY libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
COPY native-link /usr/local/bin/native-link
COPY Makefile /workspaces/repository/Makefile
COPY runner/ /workspaces/repository/runner/
COPY corpus/driver.py /workspaces/repository/corpus/driver.py
COPY corpus/config/ /workspaces/repository/corpus/config/
COPY corpus/inputs/ /workspaces/repository/corpus/inputs/
COPY micro/config/ /workspaces/repository/micro/config/
COPY vendor/bpfrejit_x86_defconfig /workspaces/repository/vendor/bpfrejit_x86_defconfig
RUN printf '{"kernel_release":"7.0.0-rc2+","target_arch":"x86_64","kernel_image":"bzImage"}\n' >/artifacts/manifest.json \
 && install -d /workspaces/repository/corpus/results && rm -rf /workspaces/repository/corpus/results/*
WORKDIR /workspaces/repository
ENV BPFREJIT_IMAGE_WORKSPACE=/workspaces/repository PYTHONPATH=/workspaces/repository
ENV BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1 BPFREJIT_CORPUS_NATIVE_LOADER_POST_ONLY=1
