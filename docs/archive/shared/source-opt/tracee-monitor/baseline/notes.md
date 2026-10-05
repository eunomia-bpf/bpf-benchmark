# tracee/monitor clean-source baseline

- Status: accepted
- Source state: no tracee source modifications before run.
- Purpose: baseline for source-only optimization attempts on `tracee/monitor`.
- Correctness gate: suite `status=ok`; app `status=ok`; `error=""`;
  three workload samples returned 0; `post_rejit=null`;
  `rejit_result.mode="skip_rejit_all"`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_122431_943915`
- Disk after run: `/dev/nvme0n1p2 915G 701G 168G 81% /`; no Docker
  image cleanup needed.
