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

The emitted leaf covers the valid destination ranges admitted by the
original BPF program. It does not emit the kernel's `might_fault` or
`check_object_size` instrumentation. The sole build enables hardened
usercopy, with fault injection and KASAN disabled; these host cases do
not establish parity for invalid native destination pointers or kernel
usercopy rejection paths.

The first host run passes at 2026-11-17T11:28:23Z: two focused tests, no
failures, 43 other tests filtered. User strings execute 4,693 vectors with
239 exact source-site faults, including the successful word-to-byte retry
and cleanup bracket cases. Compat strings execute nine domain/padding
vectors; the sharing test proves direct and repeated compat calls reuse
the existing two string leaves and one dispatcher.

Retained scalar-batch payload comparisons are byte-identical: kernel
366 B, user 370 B, kernel string 284 B and compat scalar 827 B. The new
user-string body is 400 B including its return; the compat-string fixture
is 775 B including its six-byte test caller and both string leaves. These
are host payload bytes, not installed app totals. `first-pass.json` and
`first-pass-output.txt` retain these receipts. The final rerun after the
selector-guard simplification passes at 2026-11-17T11:55:22Z: two tests,
no failures, 43 filtered. All six payloads are byte-identical to the first
pass, and the four retained payloads still match the earlier scalar batch.
Final receipts are `host-summary.json` and `host-output.txt`.

Installed app bytes and per-call/body/helper/map effects remain pending.
No image or guest starts here; the coordinator's reserved
clock and leaf-batch2 publications precede PERF timing. Their working-tree
builds may include joined source, which must be named when interpreting
results. No isolated app-level gain is claimed from source changes.
