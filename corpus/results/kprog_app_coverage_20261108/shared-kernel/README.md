# Shared five-step x86 kernel cache

The existing five-step kernel cache now lives at `kprog/tv/build-kernel-x86`. The runtime Makefile selects this tree for x86 kernel image, vmlinux, standard modules and kernel config. C launch Makefiles use the same path. R can build kernel selftests and run attribution on this shared epoch.

| Artifact | SHA256 before and after promotion |
| --- | --- |
| bzImage | 4eaf9f27f21720e63ee7f18a14e7da83d6cc07269815adbe14e696dfd612bf52 |
| vmlinux | 1530dcc64c783a950d360e27d3589e0ea26e403391fda25e8395d1230c2e738c |
| Module.symvers | 3dbe7f92e2ca73d9c242d31d1d6b7047c2b41d44d7f3472e7d1052cba9d2e77b |
| .config | 98c9d7927c024d3a70ed45d365dd4b1582d755d892158edfe3e9e1f4e01cb864 |

Promotion moves the existing incremental cache. The pre-removal11GiB shared output and C's historical1.7GiB kernel-kfunc-binding output retire after preserving their raw receipts. Workspace disk usage becomes202GiB/251GiB,81percent, with50GiB available. `promotion.json` records both epochs and the exact rewired launchers. `retired-receipts.tar.gz` keeps the historical build logs/source/identity receipts; published whole-application archives retain their native and generated objects. `launchers-before.tar.gz` preserves original commands. The runtime Make dry-run is retained in `make-dry-run.log`; actual BCC/Katran workloads and the38case safety receipt already use the promoted kernel bytes.

```sh
make -n __runtime-vm-corpus PLATFORM=kvm ARCH=x86 RUNTIME_CONTAINER_IMAGE=bpf-benchmark/kprog-five-step-tracee:c-runner
```

The Tracee successor uses the current already-published runner source in an incremental image layer. The inherited image has the historical300second startup timeout; the current runner waits for verified compile/load completion. Native input remains7479850e, and the whole original application supplies the next terminal receipt.

The shared vendor source now consumes the exact three changed headers/verifier snapshots used by the promoted cache. Existing syscall diagnostics already match that epoch. Original source timestamps are preserved, and the existing patch applier reports the complete applied patch with exit0. `source-integration.json` carries before/after hashes and `source-integration.log` carries the actual applier receipt. Each following kernel build uses the existing cache with its matching source.
