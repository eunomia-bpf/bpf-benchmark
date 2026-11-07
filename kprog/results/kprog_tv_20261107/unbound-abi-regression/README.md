Generation-zero ABI marker regression, 2026-11-07

The first unbound chunk read undefined R0 through r6..r9 ABI markers. Both ISA
modules now initialize R0 before those markers. Nonzero-generation proofs retain
their previous instruction order and authorization/binding requirements.

* x86: actual verifier/JIT/TEST_RUN on all16 ABI masks, three chunks each;
  shared loader native ELF mask15, three chunks; every execution returns2.
* ARM64: existing canonical Image, module-only incremental build, QEMU actual
  verifier/JIT/TEST_RUN on all16 masks, three chunks each, every result2.
* Actual upstream KatranServerSession loads balancer_ingress through the shim and
  shared loader, successfully replaces the original and attaches native program7
  in driver mode. GET_INFO exposes161 original stub instructions:80 sequential
  sidecar/call pairs, mask15 and generation0 throughout, followed by EXIT.
  The exact raw stub is retained. Native size10129B; original source20336B.

Run `make -C kprog/tv unbound-katran-inputs` once against the existing runtime image,
then `make -C kprog/tv unbound-loader-regression`. This uses existing native/BPF
app artifacts and unchanged upstream server startup; no direct application BPF
loader, workload edit, kernel build or throughput claim. Each Katran run writes
its own timestamped directory below tv/build. Image/server/kernel/module/source
identities and raw receipts accompany these results.

The first Katran test incorrectly expected chunk counts in the replacement log;
it failed its report check after native load and attach succeeded. That original
failure and the subsequent diagnostic capture are retained in
prior-katran-attempts.tar.gz. The final supported Make target validates the raw
GET_INFO sidecars and exits0. x86.json is the earlier synthetic-only checkpoint;
its pending fields describe that checkpoint, while katran.json and arm64.json
record the later completed regressions.
