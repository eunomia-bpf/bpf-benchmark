# Actual ARM Katran balancer proof and runtimev9

The actual balancer_ingress native entry now generates and compiles its
simulator with unchanged Katran source/map declarations. All other manifest
entries remain. The exact original/native/proof/simulator sources, frozen
headers, compile command and payload exported into this image are archived.

Full-system QEMU run arm64_qemu_corpus_19700101_000007_814845 completes the
unchanged baseline workload: balancer_ingres records250179 runs and540326416ns.
The native start reaches proof relocation, then fails on an unresolved map
relocation. No bound replacement or native counter row is claimed. The
baseline map inventory retains vip_to_down_rea, the kernel's truncated name
for proof/native symbol vip_to_down_reals_map. The loader opened the proof
before its existing native-data resolution supplied that full-name alias.
The next retry moves that resolution before proof-map reuse; no map is invented
or omitted. All raw errors and startup attempts remain in this directory.

Runtimev9 contains T's full matched context-v2-exclusive-choice ARM kernel,
stock modules, all11 kinsn modules and30ccd119a/f0d6998e1 loader, plus the
published9962aec5e shim. The root fixture's earlier success is retained
separately and is not counted as application success. QEMU timings are
functional only. The portable v9 launcher and Spark commands were built.
