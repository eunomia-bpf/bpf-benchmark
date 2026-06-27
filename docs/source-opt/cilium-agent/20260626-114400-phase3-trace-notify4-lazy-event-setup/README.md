# cilium/agent phase3 pre-attempt: trace notify4 lazy event setup

Status: discarded-before-run; not counted as a formal attempt

Base:

- Started from `20260626-105321-phase3-reserved-identity-cold`.

Candidate:

- In `_send_trace_notify4()`, move trace-id, packet-length, and rate-limit
  setup after `emit_trace_notify()` so filtered trace events do less
  preparation work.

Why it was discarded:

- The local `make -C vendor cilium-x86` check rebuilds the Go agent but does not
  rebuild the runtime Cilium datapath object used for offline `bpf_lxc.o`
  inspection.
- Because the offline diagnostic could not prove a meaningful datapath object
  change before the formal run, the candidate was reverted before benchmarking.
- No `make corpus` run was executed for this directory, so it has no performance
  row and does not count toward the 5 Cilium phase3 attempts.

Artifacts:

- `candidate-only.diff`: the reverted trace helper candidate.
- `source.diff`: cumulative diff as it stood before discard.
- `base-*` / `candidate-*`: offline diagnostics retained as a caution that
  `make -C vendor cilium-x86` is not sufficient for Cilium datapath object
  rebuild provenance.
