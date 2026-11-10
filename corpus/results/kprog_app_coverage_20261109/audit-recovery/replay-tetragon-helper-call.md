# Tetragon whole-application replay, helper-call default

Guest: `application.py run --revision af422c391 --apps
katran,tracee/monitor,tetragon/observer`, image `9ca3295d...` (built from
`558b8851b`, whose compiler default is the helper-call form at `65c73b03c`),
run directory `x86_kvm_corpus_20261110_132630_028096`, CPUs 20-23.

Tetragon's row, compared with the four installed entries in
[best-installed-reference.json](best-installed-reference.json):

| entry | reference | this replay |
| --- | --- | --- |
| event_exit_acct_process | installed | **installed** |
| event_exit_disassociate_ctty | installed | **installed** |
| event_wake_up_new_task | installed | **installed** |
| execve_rate | installed | **installed** |

**4 of 4 recovered, 0 drops.** The app result is status `ok`: 9 distinct
program names in both arms, 98 baseline program instances and 81 native.

Installed roles beyond the reference: `generic_kprobe_output`,
`generic_kprobe_setup_event`, `generic_kprobe_event`,
`generic_kprobe_process_event`, and others under `generic_kprobe_*` — new
roles, as the 02:14 receipt also recorded.

Failures: 47, one class — "trusted specializer refused native program:
Input/output error" on `event_execve`, `execve_map_upda`, `execve_send` and
the `generic_kprobe_*` variants.

## Cost of the row

The native phase is load-driven: Tetragon submits a compile each time a
program loads, so the request count grew from 54 to 83 while running.
Measured: **83 trusted Clang compiles, 24,060 s (6.7 h)**, mean 290 s,
nine over 20 min, max 1,470 s, at 4-12 GB RSS each, one guest. That is the
unit cost of this row on this image.

Runtime checks added: 0.
