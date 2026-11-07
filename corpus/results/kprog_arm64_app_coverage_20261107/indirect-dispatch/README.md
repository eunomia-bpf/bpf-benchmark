# Finite dispatch in whole-application ARM runtime artifacts

One generic reader counts finite dispatch in the original generated C artifacts retained by the registered common service. The input cohorts are the closed first-pass BCC, OTel, Cilium, Tetragon and Katran runs. Tracee proceeds in the existing QEMU queue. The raw archives, source summaries and embedded generated-source digests remain explicit in summary.json.

Katran's accepted artifact contains 82 indirect helper-call sites, each with a singleton helper target. Every site reads the actual target register, partitions CODE and helper targets, and contains two literal switches with two rejecting defaults. Its three local-return sites have finite local-target sets of sizes 0, 1 and 2. The recorded application completes with one fresh bound load and matching packet/BPF/receiver work. Counts describe static source sites; the original application records supply the execution counters.

The BCC cohort contains 19 generated sources and 16 accepted bindings; its direct helper calls and finite return-case macros remain counted separately. OTel's first generated source has five singleton indirect-helper sites and retains its readonly-byte loader rejection. Cilium and Tetragon retain their original startup-stage outcomes and zero service requests in these first-pass cohorts. summary.json records both all generated sources and the accepted-binding subset, preserving their distinct denominators.

Reproduce the source census from the retained raw cohorts:

    make -C corpus/results/kprog_arm64_app_coverage_20261107/indirect-dispatch collect

The collector reads existing archives and produces one application-batch summary. Original runtime artifacts stay in their existing archives. Universal ISA, specialization, binding and native-link preservation theorem work supplies the complete safety argument as those obligations close. Finite-dispatch source counts and verifier acceptance remain supporting runtime observations.
