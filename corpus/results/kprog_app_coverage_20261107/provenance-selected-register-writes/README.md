# Provenance-selected partial register writes

The production generator and generated header now select a representation using
the existing input tag. Scalar low8/high8/16 writes use ordinary union storage;
other tags use complete volatile local storage, a partial write, then full64-bit
reload. Both arms preserve every remaining bit and produce the same scalar tag.
The32/64-bit write bodies and generated Lean/JSON bit semantics stay intact.

The adopted header is byte-identical to cf27e323c885 from the complete Katran
trusted-path run213447:1/1fresh generated/compiled/accepted/bound, app ok and
LRU miss0 in both arms. JIT2318117/native2386430sent packets each match their
BPF invocations and XDP TX actions; native2377743received plus5158TX drops and
3529receiver drops accounts for the complete2386430packet workload.
Raw per-arm counters and the exact kernel/native/generated artifacts remain in
the linked katran-tagged-storage result. This is a functional work observation;
R's existing recipe supplies timing.

Production regeneration check and143encoder/ABI,3072CLhost,19renderedMOVX
host/BPF plus100448MOVhost/UBSan cases pass, retaining existing invalid width/
REX and context controls. The raw archive carries original/adopted sources and
complete check output. The complete29suite follows this adopted source epoch.
Universal value/flag/frame, specialization and compiler correspondence laws
supply the generic safety argument; finite tests support those laws.
