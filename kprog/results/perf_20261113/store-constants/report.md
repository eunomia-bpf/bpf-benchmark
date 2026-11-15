# Immutable entry ABI and nested store selectors

2026-11-15T10:35:19Z. The entry ABI is now immutable for RAW/XDP/SKB
(1af8005a5). The store width contract and tagged-store width/tag captures
are immutable (6d515de02), and the store-arm byte is initialized with a
conditional expression rather than an if/else merge (69c74d4c6).
The store header and generator change together; generation check passes.
Conditions, byte conversions, dynamic inputs, evaluation counts and volatile
memory order are unchanged. The state-struct route keeps its runtime ABI.
All normal optimization flags and LTO remain together; P is unchanged.

`frontend-constants` observes actual handler expansion before LLVM passes.
The diagnostic uses `-disable-llvm-passes` only to observe that graph; it is
not a production compilation path. Results by stage:

| Actual handler probe | Before branches | Constant ABI | Width/tag | Constant arm | Final IR bytes (before) |
|---|---:|---:|---:|---:|---:|
| Register store, memory |436|353|331|331|129366 (171642)|
| Register store, stack |436|353|331|226|95211 (173655)|
| Immediate store, memory |400|317|298|298|116596 (157781)|
| Immediate store, stack |400|317|298|192|80488 (157781)|

Stack-store branches decrease48.2–52.0%; memory-store branches24.1–25.5%.
This is a small pre-SSA probe, not full OTel compiler or runtime performance.

Final semantic checks pass:

- Actual native CPU versus shared C:512 complete memory/flag store cases;
  4,032 BMI2 value/count/defined-flag cases.
- All32 normal B fixtures compile; allocated section bytes match their
  immediately preceding width-constants outputs32/32. Generic/direct BMI2
  outputs also match16/16. Exact hashes are in `allocated-parity.json`.
- Independent scoped suite:713 load,117782 stack,14 pointer/RSP/recovery,
 1292621 store,65538 width capture,200 helper-output cases per ISA.
- Checked-C versus original native:25 XDP/TC/cgroup_skb host executions,
  complete4,096-byte contexts and qdisc prefixes match; sole-kernel BTF
  confirms metadata48=cb40+qdisc.data8.

These are host execution/normal compilation checks. No new B kernel execution,
OTel application acceptance or runtime speedup is claimed. The prior scoped
checks after width/tag changes and the final store-arm checks both pass;
their exact Make/Clang commands and stdout are retained separately.

Two checked-packet test rebuilds replace90 known compiled products
(15,922,750bytes), preserving42 prior raw metadata/log files. Per-file
path/size/SHA/action/completion manifests and preserved data are under
`rebuild`; `cleanup-summary.json` identifies both runs. All raw results stay
at `/workspaces/kprog-raw/perf/20261115-store-constants` and
`/workspaces/kprog-raw/perf/checked-packet-rebuild`. No compiled output is
archived in this receipt.

The earlier revised OTel frontend911032 continues on its captured width-only
input. One new normal frontend attempt, launcher921682, is queued on its
launcher910213 ending, irrespective of success; no job is stopped or input
overwritten while it runs. The queued attempt uses the same canonical
`otel-whole-word-checked` build, CPUs8–11/16GiBAS, and captures exact input
fingerprints after acquiring imageSH, releasing it before LLVM work. No
second product build, guest or timing lock. Read both actual completion
records before drawing any full-compile conclusion.
