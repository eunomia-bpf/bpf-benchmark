# Paired x86 kernel and module payload in the existing runtime image

The existing runtime image now carries the current shared x86 Image, ordinary kernel modules and all custom kinsn modules together. The Docker layer copies those three artifact paths from the incremental shared build. Original application/native objects, loader/shim, runner logic and workloads retain their base-image content. Existing tag: bpf-benchmark/kprog-five-step-tracee:c-runner. Base and resulting immutable image identities are in [summary.json](summary.json).

The earlier two Katran attempts retain ip_tunnel BTF errno22 at baseline startup. A fresh shared-kernel guest resolves exactly the current shared ip_tunnel hash and loads it successfully. runner/scripts/bpfrejit-install copies the image /artifacts/lib/modules payload into the running guest module root; refreshing that payload keeps the installer and kernel paired.

The module install uses existing compiled outputs; 842ordinary and15custom modules carry individual hashes. Package build exit0. The first Dockerfile config-ID FROM lookup failure remains archived alongside the corrected existing-local-tag Dockerfile and actual build. The original Katran complete workload continues through its separate terminal collector.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/katran-shared-extent/package-runtime/Makefile image
```

[raw.tar.gz](raw.tar.gz) retains commands, complete build/diagnostic output, image inspection, every installed module hash, actual Image/custom-module bytes and the matching ip_tunnel binary. Full ordinary-module outputs remain in the shared warm kernel tree and the installed package. Runtime admission additions0.
