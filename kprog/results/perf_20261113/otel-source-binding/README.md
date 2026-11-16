2026-11-16T03:13:03Z

OTel `custom__generic` in run `x86_kvm_corpus_20261116_010841_344218` finishes its four reachable stub-verifier instructions and then returns EINVAL. Its native stub retains `perf_progs`, whose program-array owner is PERF_EVENT, while the intercepted KPROBE program uses `kprobe_progs` after the upstream Go runtime rebinding.

The existing source-map resolver follows original ELF relocations to the intercepted BPF instructions and their actual map identities. The current staged manifest omits `source_bpf_object`, so that resolver is inactive. Producer owner C has the concrete request to publish the original embedded BPF ELF and its manifest reference; the generated simulator `.bpf.o` is a different object and cannot substitute for it.

The actual sole-kernel ownership subset passes: KPROBE plus the source array loads; retaining the PERF_EVENT-owned array returns -22/EINVAL despite completing verification (270 log bytes). The test target now mounts its canonical host binary under the persistent guest output, because virtme masks `/var/tmp`. First two attempts failed to launch the binary and are retained alongside successful kernel3. No whole OTel fix or timing result is claimed. Raw: `/workspaces/kprog-raw/perf/20261116-otel-source-binding`.
