# Tracee on the fixed base: every program installed, no failures

Run x86_kvm_corpus_20261121_022836_577758, `APP=tracee/monitor`, 3 x 180 s per arm, stats on, on the 3b5fa4b40
image with the base loader rebuilt from HEAD and the base `packet-bounds` carrying the fp-arithmetic pass.

At the time of writing its post arm had installed 52 programs with **zero** `native-loader failed` and zero
`kept on eBPF` lines, against 140 failures on the stale-loader armof 10:01. Every program it reached went native.

Two facts about pacing, measured rather than assumed, because they make this arm slow rather than broken:

- The gap between consecutive `list_progs` commands is ~30-50 s in this arm and ~32 s in the 20:40 arm, i.e. it is
  the app's own load pacing (each command follows a batch of `BPF_PROG_LOAD`s), not shim latency.
- The OTel arm's ~200 ms per `list_progs` I measured earlier is a much lighter app; the two are not comparable.

So a Tracee arm takes hours, and a `list_progs`-to-`list_progs` gap growing to minutes late in the load is the
app, not a stall. No timing number is quoted from this run yet; when the arm finishes, the ratio is reported with
both arms' loaded-program and call counts beside it.
