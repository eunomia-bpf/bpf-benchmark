# Corpus Round 4

- Date: 2026-03-29
- Command: `make daemon && make runner && make vm-corpus TARGET=x86 REPEAT=50`
- Host log: `docs/tmp/20260328/corpus_round4_host.log`
- Primary artifact: `runner/corpus/results/vm_corpus_20260329_091745/metadata.json`

## Outcome

- Full corpus completed without crash:
  - `469 / 469 objects`
  - `2009 / 2009 programs`
- Final summary:
  - `compile_pairs=1114`
  - `measured_pairs=705`
  - `comparable_pairs=415`
  - `applied_programs=429`
  - `applied_comparable_pairs=212`
  - `applied-only exec geomean=1.042827240424557`
  - `all-program exec geomean=1.0031117689474556`
  - `code-size geomean=1.0371775367386935`

## Coverage

- Object coverage:
  - `469 / 469 selected objects completed`
- Program coverage:
  - `2009 / 2009 selected programs reached object-level completion`
- Measurement coverage:
  - `705 / 1114 compile-passing pairs measured`
  - `415 / 705 measured pairs comparable`
  - `212 / 415 comparable pairs had applied REJIT changes`

## Per-repo applied-only geomean

- Positive/high-signal repos:
  - `bcc`: `1.0990992360253617` on `104` applied-comparable pairs
  - `linux-selftests`: `1.0938199819773375` on `26` applied-comparable pairs
  - `xdp-tools`: `1.115546702045434` on `2` applied-comparable pairs
  - `xdp-tutorial`: `1.1304038143380557` on `3` applied-comparable pairs
  - `katran`: `1.5438886027619867` on `2` applied-comparable pairs
- Neutral / slightly negative repos:
  - `tetragon`: `1.0096223183702466` on `3` applied-comparable pairs
  - `coroot-node-agent`: `1.0061847146423415` on `4` applied-comparable pairs
  - `libbpf-bootstrap`: `0.9711284622997728` on `6` applied-comparable pairs
  - `calico`: `0.9143358186895306` on `54` applied-comparable pairs
  - `suricata`: `0.5652173913043478` on `1` applied-comparable pair

## Main exclusions and failures

- Largest comparison exclusions:
  - `attach_trigger did not fire the target program in baseline or REJIT (run_cnt_delta=0)`: `211`
  - `bpf_prog_test_run reported exec_ns=0 in baseline and REJIT`: `49`
- Dominant failure reasons:
  - `bpf_object__load failed: Invalid argument`: `567`
  - `bpf_program__attach failed: Operation not supported`: `420`
  - `bpf_program__attach failed: No such file or directory`: `190`

## Long-tail hotspots from host log

- Notable slow objects:
  - `tetragon:bpf_prog_iter.bpf.o`
  - `scx:scx_lavd_main.bpf.o`
  - `systemd:sysctl-monitor.bpf.o`
  - `tetragon:bpf_fork.bpf.o`
  - `tetragon:bpf_generic_tracepoint.bpf.o`
- These were long wall-clock tails, but they still completed and did not crash the batch.

## Decision for next round

- No repo-side fix is required to satisfy the primary goals after this round:
  - full completion achieved
  - applied-only comparable geomean `> 1.0`
- Next rounds should verify reproducibility and watch whether the same long-tail objects remain the dominant runtime hotspots.
