# Eight-vCPU matched ARM runtime census

Run `arm64_qemu_corpus_19700101_000007_589955` used the existing two-start
corpus workload, BPF stats on, one sample, two seconds, eight vCPUs and 4GiB
RAM. QEMU measurements are functional. The complete command sequence is in
`runtime-context-v4-build-and-run.log`; `host-console.log` preserves its original
copy. Kernel/modules are the immutable context-v2 pair at 6836f7d44; loader
is T context-v2-map-value (e43eca549, including readonly identity and zero-value-size
adoption). Native linking used the then-published 3b19ec714 interface.

`table.md` records 23 BCC, 287 Tetragon and one Katran baseline counter rows.
`resident-counters.csv` preserves every raw row. There are 480 startup attempts:
465 loaded, six failed and nine unfinished. All attempts and ten native
replacement records remain; anonymous probes and transients are included.
No native workload measurement completed.

BCC encountered stale native proof readonly extents and an opensnoop native
stub EINVAL. The archived exact packaged BCC payload demonstrates the stale
proof pairing; aefcd9c71 fixes that lookup pairing separately. Tetragon reaches
its actual workload with all upstream objects installed, then native startup
needs simulator artifacts. Katran reaches baseline XDP work after the guest
CPU-count repair, then native startup does not expose an attached program.
These are failures to close, not exclusions. Startup-probe coverage is also
being rebuilt against the published strict shim 0bff849bf before the next run;
this older run does not establish all-program verified coverage.

`bcc-manifest.json` is extracted from the actual packaged payload, not the
later mutable stage. The run tarball retains all app JSON and shim logs;
`packaged-bcc-inputs.tar.gz` retains its exact compiler/loader inputs. The older
named log copies remain for provenance and are not this run's command source.
After exporting the run and payload, only the two lane-A rebuildable roots in
`rebuildable-root-removal.json` were removed for disk space. Kernel/modules,
image archives and all raw results remain.
