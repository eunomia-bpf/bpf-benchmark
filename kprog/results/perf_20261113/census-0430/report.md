# Five more outcomes from the retained census

2026-11-15. Existing guest 524526 continues without restart. Body groups
99–103 add these terminal observations:

| Body | Entry | Result | Native ID |
| --- | --- | --- | ---: |
| 99 | trace_ret_do_mmap | stock verifier map bounds | — |
| 100 | event_wake_up_new_task | BPF compilation stack failure | — |
| 101 | blk_account_io_merge_bio | installed | 171 |
| 102 | sched_wakeup_new | installed | 175 |
| 103 | event_exit_acct_process | installed | 179 |

Body 99 reaches `bpf_probe_read_str` with an unconstrained map-value offset;
the verifier reports `value_size=32536 off=65677 size=4096`, after 8,748
processed instructions. Body 100's actual compiler command compiles the joined
`.i` directly to BPF with a 4096-byte stack limit and reports stack exhaustion.
That retained command does not run the current bounds/MIR/whole-word pipeline.
Its completion time does not establish use of current source. It is not an
observed failure of this turn's new checked-native flags.

Adding these five to the preceding 94 attempts/89 bodies yields 99 attempts,
94 bodies: 48 installed, 40 stock verifier rejects, five compile failures and
one retained loader/linker invocation mismatch (body 93). All results are
submitted-native load-only with the prior producer. No native execution,
equal-work, whole-app or performance conclusion follows.

`collect.py` binds the journal snapshot and complete original request archives
by SHA256 without copying build products. Full logs, diagnostics and archives
remain under `/workspaces/kprog-raw/perf/20261114-census-resume/control`.
