# CHUNK ENOENT: active request validity versus map lifetime

This strengthens the earlier Cilium arming report with the Tracee capture and the loader's existing map-FD invariant. It is a source-and-capture deduction, not a newly traced kernel branch. No kernel, loader, request-lifetime policy, benchmark, timeout or running experiment changed.

| failed request | Cilium17 `tail_ipv4_ct_ingress` | Tracee11 `trace_ptrace` |
| --- | ---: | ---: |
| distinct runtime map IDs |7|5|
| cached linker `.relocs.bin` bytes |0|0|
| service finish after corpus result recorded |3.696060s|15.639995s|
| native ELF captured |yes|yes|
| loader stderr |arming CHUNK ENOENT|arming CHUNK ENOENT|

An empty cached `.relocs.bin` does **not** mean the ioctl has no map relocations. `bind_native_map_relocations` appends one relocation for every `.map-patches.tsv` site, using the current companion mapping. Both requests' captured CLI bindings agree with kernel metadata and source map IDs. Those same names feed `collect_relocated_map_ids`.

Before the CHUNK ioctl, `reopen_relocated_map_fds` opens every distinct relocated map ID. An open failure has a different error (`bpf_map_get_fd_by_id(...) for native relocation lifetime`). The opened descriptors are retained by `ScopedFd` objects in `pins` through `arm_and_load`; setting FD_CLOEXEC does not close them because there is no exec between pinning and ioctl. The kernel takes a map user/reference count for these descriptors. With zero base relocation records, every map ID checked by the module's map-lookup loop therefore comes from this already-pinned set under the examined path.

Map disappearance is inconsistent with that invariant. The remaining source ENOENT path is `native_lab_active_capsule`: absent active request, abandoned owner, or request-ID mismatch. Both captured CLI request IDs match their service IDs. The module's owner-release path marks a request abandoned; the late service finishes and the previously documented corpus teardown/startup ordering support request abandonment as an explanation. They do not directly record which active-capsule predicate failed.

The captured loader binary SHA07ccfed2... matches the current ARM loader in both cases. Relevant source files match each guest-start Git revision, and available per-request source hashes also match. Full capture fields and artifact hashes are in `analysis.json`; compressed error/facts/metadata/identities/map-patch/base-relocation records and `source-trace.txt` make the deduction reviewable. The actual in-memory CHUNK wire and kernel active-job state were not captured; source equality alone is not independent module build provenance. This report therefore narrows the source explanation without claiming a new runtime branch observation, successful native install, or a validated repair.

The evidence supports finishing common startup/load work before considering a change to request ownership. Keeping an abandoned request installable, adding retries or extending the frozen deadline is not justified by these captures. Existing scalar compile/stock and queued Tetragon stage2 continue unchanged. Original Cilium/Tracee service archives remain available for further diagnosis; evidence is written directly to result files without a new RAW copy.
