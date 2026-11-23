# Map lookup binding on x86, native against the verifier (2026-11-23)

Design: "就地内联 map 查找". The verifier inlines a lookup (or calls the map type's function) when the call
gets one map on every path, including the inner map of a map-of-maps (the outer map's inner template);
a call reached with several maps keeps the generic helper. native-link binds a lookup by the map symbol in
%rdi along straight-line code and calls the generic helper otherwise.

`lookupflow.py` reads the native objects of the image (vendor/build/native-bpf/x86/stage) and counts, per
app, the lookups whose map is known in %rdi under four rules: A straight-line, registers (today's
native-link); B straight-line, registers and %rsp stack slots; C a meet over the control-flow graph
(a name holds at a join when every predecessor brings the same one), registers; D C plus stack slots.
`inner` counts lookups whose map is the value of a lookup on a known map (an inner map).

| App | lookups | A | B | C | D | inner |
|---|---|---|---|---|---|---|
| OTel | 985 | 841 | 841 | 841 | 841 | 0 |
| BCC | 23 | 23 | 23 | 23 | 23 | 0 |
| Cilium | 749 | 683 | 683 | 683 | 683 | 2 |
| Katran | 79 | 73 | 73 | 73 | 73 | 2 |
| Tracee | 4402 | 2849 | 2849 | 2870 | 2870 | 1525 |

`bpfflow.py` does rule D on the eBPF objects. For every OTel perf_event program the native lookups with
one map are all bound, and the rest match eBPF: perf_unwind_native has 38 single-map lookups and 72
lookups reached with several maps in both (each switch case puts a different exe_id_to_N_stack_deltas in
r1 and jumps to one call), so the verifier also leaves those 72 to the generic helper.

So native binds every lookup the verifier inlines except two groups:
- inner maps: Tracee 1525 (the *_version hash-of-maps and their inner filter maps), Cilium 2, Katran 2
  (vip_to_down_reals_map, the down-reals path);
- Tracee's 21 lookups whose map is the same on every path but reaches the call across a join.
The slow apps (OTel 0.930x, BCC 0.984x, Katran 1.002x per call on dcf4a1aef) have no lookup the
verifier inlines and native does not.
