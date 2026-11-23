# OTel per call 0.930x: host-PMU profile (2026-11-23)

Operator 2026-11-23: "性能是不是不够好? 为啥?"; 2026-11-22: "可以 profile 但是不允许做任何设计之外的事情或者细节调优".

OTel's unwinders run from a perf event with interrupts off, so the guest's cpu-clock profile (profile.sh)
has no samples in them. `profile-host.sh` samples the guest from the host with the PMU (perf kvm --guest,
cpu_core cycles, CPUs 0-7) while the frozen guest target runs one OTel sample. The guest lists BPF
programs from kallsyms every 30 s, copies the loader's link cache (each native program's plan, blob and
relocations) and, with `dump-prog.py`, writes the eBPF program's verifier-rewritten instructions, JITed
code and function addresses. `host-phases.py` compares symbols per second in the two phases (each phase
resolved with its own snapshots); `host-annotate.py` counts samples per instruction of a blob or JITed image.

Runs in /workspaces/kprog-raw/coordinator/profile-20261123: otel-host4-dcf4a1aef, otel-host-77908203a.

Samples per second, eBPF window (guest uptime 110-190 s) and native window (220-310 s) of the run on
77908203a; the work matches (LPM trie lookups 1925/s and 1938/s, user-memory reads 1266/s and 1244/s):

| Symbol | eBPF | native |
|---|---|---|
| perf_unwind_native (the program body) | 755 | 1303 |
| array_map_lookup_elem | 100 | 417 |
| bpf_map_lookup_elem (generic helper) | 127 | 137 |
| trie_lookup_elem | 1925 | 1938 |
| copy_from_user_nofault | 1266 | 1244 |

- Lookup forms are the same in both. The eBPF program's xlated code has 72 calls to the generic helper
  (lookups reached with several maps: each switch case puts a different exe_id_to_N_stack_deltas or its
  inner array in r1), 4 direct trie_lookup_elem calls, 8 __htab_map_lookup_elem calls and 24
  bpf_probe_read_user calls; the native blob on 77908203a has the same 72/4/8/24 (on dcf4a1aef the 4 trie
  lookups, and 28 in perf_unwind_hotspot, went through the generic helper; 77908203a gives a known LPM trie
  the direct call the verifier gives it).
- The hot code in both is the binary search over a page of stack deltas: each step stores mid on the stack
  and calls the generic helper on the inner array. In the eBPF image the samples sit on the load of the
  returned element; in the native blob on the instructions before the next call. Inside
  array_map_lookup_elem the native window's samples sit on +0x7 (after the key load `mov (%rsi),%eax`
  and with `cmp 0x44(%rdi),%eax`): 15204 against 1128 on dcf4a1aef, and the function as a whole stays 4x
  on 77908203a. Cycle samples do not tell a cache miss from a pipeline stall here; a run sampling branch
  misses (EVENT=cpu_core/branch-misses/) is queued after the timing of 77908203a.
- During the run on dcf4a1aef, 3% of the samples on CPUs 0-7 (42269 in 90 s) came from a guest with
  another kernel base (0xffffffff87000000) while this run held the timing lock; the lab node also hosts
  other Workspaces and CI runners.
