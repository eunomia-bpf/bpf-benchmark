# Remaining source-entry and map cross-comparisons

The loader removes16lines that compare a separately captured source-BTF entry with the loaded source entry, query a pinned map a second time, and compare its shape with a separately reopened descriptor. The actual map FD resolution and load_map_meta_from_fd supply the map object used in relocation; their OS errors retain normal propagation. Request/reply matching remains in the transport that returns those replies. These changes follow design priority1 and share the existing kernel/module wire.

```sh
make -C kprog/libnativeloader trusted-service-check BUILD_DIR=/workspaces/.agent-state/kprog-lanes/C/design-only/loader-audit/build
```

The static/shared libraries and trusted-native-loader build successfully. All8existing trusted-service component cases pass. The build uses CPUs8-11. Existing application and R selftest guests retain their captured loader binaries; subsequent complete BCC/Katran replays consume the new loader through an owned path.

The direct native selftest submission still needs program context from the object: current kernel SUBMIT pins source_prog_id and the worker loader reopens it. C is extending that functional context transport so the native P request carries its program type, attach/BTF metadata and map descriptors. R owns selftest enumeration, native compile and annotation comparison. The original eBPF companion verdict stays a separate result.

`build.tar.gz` retains before/after source, owned patch, exact compiler commands/logs/exit, executable and library hashes. Additional runtime admission predicates total0.
