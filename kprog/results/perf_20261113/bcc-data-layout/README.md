# BCC DATASEC binding regression

2026-11-16T02:20:09Z

The unchanged current tcplife native object has4118B of .rodata, while its source program loads a4106B ARRAY map. The native target_family offset4116 differs from BPF DATASEC offset4104. The default loader required the native section footprint to fit the loaded map, so it omitted all globals and native-link failed on target_family's GOT relocation. BCC run013455_495442 retains that error. Merely dropping the size filter would still use incorrect offsets.

The loader now binds referenced native globals by name to the loaded DATASEC BTF offset and map value address. This is the existing BTF resolver made canonical. The native-offset path and default-off kernel_data_layout selector are deleted. Entry extraction always supplies the referenced symbol set, preserving entry scope. Stale manifest fields are ignored; no producer, native object, source workload, benchmark entry, kernel or B compiler changes. Existing BTF/layout failures remain; no new check or limit is added.

Host and actual kernel tests pass seven globals/three differently padded maps, configured-byte preservation, selected-entry reachability, cached extraction, fresh/reused native template equality, and writable-data host execution. The real tcplife proof is the retained application ELF witness. Existing missing-variable and malformed-BTF tests retain their behavior and descriptor cleanup. The original host test's stale /var/tmp Cilium witness was absent; that failure stays in raw, and the rerun uses the canonical tcplife proof. Test guests run16-19 under image SH with8GiB address-space limits.

Raw: /workspaces/kprog-raw/perf/20261116-bcc-data-layout. Full BCC app acceptance remains for the post-round default-entry retry. Image fc408f64 stays installed during the breadth round.

The previous waiting reference job1290695/shell1290700 was ended by exact own flock PID1290703 before any publication. Logs remain at /workspaces/kprog-raw/perf/20261116-reference-linker-timing. Its replacement waits behind the same round, publishes the loader fix, runs BCC stats0/1, then current Katran stats0/1 and reference Katran stats0/1 on the same loader, all through the unchanged corpus defaults. It rebuilds current source afterward. This targeted current Katran pair replaces reuse of the earlier loader's round result, avoiding a confounded linker comparison. New raw: /workspaces/kprog-raw/perf/20261116-post-round-data-fix.
