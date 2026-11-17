# User-string and compat-string helper leaves

Multi-day item 1b lowers `bpf_probe_read_user_str` and
`bpf_probe_read_compat_str` through the existing link-time helper path.
The scalar and string forms share their respective user/kernel leaves
within each installed program. Compat strings retain the existing
task-sized address split. No runtime optimization switch or new refusal
is introduced.

User strings follow the sole kernel's `strncpy_from_user` word/byte
semantics: clamp the initial user pointer, fetch words when at least eight
bytes remain, mask and store the whole word containing NUL, and retry
bytes at the same address after a word-load fault. A failed byte load
returns a negative signed-int result and zeros the original requested
destination. Zero count returns before the pagefault/SMAP bracket;
exhaustion forces the last copied byte to NUL. Scalar full-range and
NMI-mm restrictions do not enter the string path.

The word-mask scratch uses RDX, so string cleanup records SMAP in bit 32
of R9 while its original u32 count remains in R9D. Source recovery uses
the existing R11 status and load-site metadata. Each new source load
resets the status, including the byte retry after a word fault. There is
no new frame or callee-saved register use.

`run-host.sh` queues the focused executable and relocation-sharing tests
on CPU 19 under timing SH, using the sole linker build. Each attempt has
a distinct persistent raw directory below
`/workspaces/kprog-raw/perf/user-string-leaf-20261117`.

Cases cover unaligned strings and NUL positions across word boundaries,
truncation, complete fault zeroing, successful byte retry before a guard
page, pointer clamping, absent scalar NMI restrictions, and compat address
domains. The host records and skips the privileged STAC/CLAC instructions
through SIGILL to exercise cleanup-state preservation; this tests the
emitted bracket and registers, not hardware SMAP access protection.
Existing scalar, kernel-string, compat, task-BTF and jiffies cases remain.

Host validation, installed app bytes and per-call/body/helper/map effects
are pending. No image or guest starts here; the coordinator's reserved
clock and leaf-batch2 publications precede PERF timing. Their working-tree
builds may include joined source, which must be named when interpreting
results. No isolated app-level gain is claimed from source changes.
