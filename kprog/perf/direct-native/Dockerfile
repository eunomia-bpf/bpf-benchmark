# SPDX-License-Identifier: GPL-2.0
# Overlay of the direct-native module and one app's native objects, see README.md.
ARG BASE_IMAGE
ARG APP
FROM ${BASE_IMAGE}
ARG APP
COPY bpf_x86_native_lab.ko /artifacts/kinsn/bpf_x86_native_lab.ko
COPY native-app/ /artifacts/user/native-bpf/x86_64/${APP}/
