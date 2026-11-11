#!/bin/sh
# Restore everything R's timing needs after a Workspace container restart.
#
# The restart of 2026-11-10 23:53 UTC cleared /var/tmp and every docker image,
# which is why timing stopped. Everything here lives on the persistent volume
# /workspaces/.agent-state/kprog-r-art, so a restart costs one docker load per
# image instead of a rebuild.
#
#   kprog-r-art/art/     the ART that kprog/perf/may29-image expects: the
#                         2026-05-29 kernel, its modules, kinsn modules,
#                         shim, loader, native-link, kernel_offsets.h and the
#                         six applications' native objects
#   kprog-r-art/images/  docker save tars: the runner-runtime base, the
#                         2026-05-29 six-application image, the r-restored
#                         image the direct-native path layers on, and the
#                         direct-native image itself
#   kprog-r-art/dn-build/  the direct-native module and its build outputs
#
# The 2026-05-29 kernel's *sources* stay in the cilium-lab-20261009 paper
# tree; only build outputs live here.
set -eu

ART_ROOT=/workspaces/.agent-state/kprog-r-art
IMAGES=$ART_ROOT/images

load() {
    image=$1
    tar=$2
    if docker image inspect "$image" >/dev/null 2>&1; then
        printf 'present  %s\n' "$image"
    else
        printf 'loading  %s\n' "$image"
        docker load -i "$tar" >/dev/null
    fi
}

# Order matters only in that the base must load before images layered on it.
load bpf-benchmark/runner-runtime:x86_64 \
     "$IMAGES/x86_64-runner-runtime.image.tar"
load bpf-benchmark/kprog-may29-six:main \
     "$IMAGES/may29-six.image.tar"
load bpf-benchmark/kprog-five-step-tracee:r-restored \
     "$IMAGES/r-restored.image.tar"
load bpf-benchmark/kprog-direct-native:r-restored \
     "$IMAGES/direct-native.image.tar"

for path in bzImage kernel.config kernel_offsets.h kinsn modules native-bpf \
            libnative_loader.so libbpfrejit_shim.so native-link; do
    if [ ! -e "$ART_ROOT/art/$path" ]; then
        printf 'MISSING  art/%s\n' "$path" >&2
        exit 1
    fi
done
printf 'art       complete\n'

# The recipes write their state under /var/tmp, which a restart clears.
install -d /var/tmp/kprog-tmp/R
printf 'done\n'