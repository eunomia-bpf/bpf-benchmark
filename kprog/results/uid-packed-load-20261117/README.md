# Packed UID/GID load

Source `235f08262`, candidate recipe `5cce4c6c4`, forward fixture repair
`b6615cb0c`, first-failure receipts `622aed1eb`. The retry completed and
pushed source at 2026-11-17T17:26:51Z. All existing LTO remains on.

The sole kernel's BTF reports task_struct.cred at byte **3328**, cred.uid
at **8** and cred.gid at **12**, with both ID fields **4 bytes**. The job
reuses `vendor/bpf/core-answers.py` and the canonical bpftool against the
sole build's vmlinux; it adds no BTF parser, source tree or kernel build.
See [actual target facts](target-layout.json).

`current_uid_gid` in `include/linux/cred.h:401-407` reads both fields from
one captured credential pointer. `Documentation/security/credentials.rst:
255-278,289-301` states that published credential contents are immutable
apart from listed reference/keyring exceptions; UID/GID are not exceptions.
The existing LTO fact writer already requires both ID fields to be u32.
The existing leaf's init_user_ns identity-mapping and caller-lifetime
contract remains unchanged.

For UID immediately followed by GID, x86 little-endian memory already has
`(gid << 32) | uid` order. The new code reads exactly those eight bytes
with one qword load. Nonadjacent or reversed layouts retain independent
32-bit loads followed by shift/OR. Selection occurs during LTO, with no
new per-call layout or namespace test. The existing memory-operand encoder
shortens field displacements, and existing local sizing shortens the null
branch. No new encoder, runtime check, flag, limit, refusal, public schema,
module, kernel or benchmark change was introduced.

The normal adjacent path replaces four instructions (two field loads,
shift, OR) with one load. It still fetches current and current->cred live
and preserves null-current `-EINVAL`. It does not cache ID values or add a
kernel helper call. Both caller-saved-register and existing range-conversion
contracts are preserved.

Actual local host bytes:

| Layout | Previous leaf | New leaf |
| --- | ---: | ---: |
| Sole kernel: task 3328, UID/GID 8/12 | 53 | 34 |
| Original fixture: task 16, UID/GID 8/12 | 53 | 31 |
| Zero-offset adjacent fixture | 53 | 29 |

Other tested layouts range 31-45 bytes; see [all sizes](local-sizes.txt).
These are local leaf bodies, not installed application totals or a measured
per-call gain. Native source flags are unchanged across applications.

Validation:

- Full canonical release linker suite: **54 passed**, zero failed, three
  existing ignored tests.
- **5,330** actual UID executions: 533 cases for nine synthetic layouts and
  the actual kernel layout. Cases include adjacent, reversed/nonadjacent,
  zero/short/wide displacement boundaries, unaligned and exact guard-end
  reads, read-only credentials, changing IDs, random/sentinel u32 values and
  null current. Static read counts also distinguish three reads for adjacent
  layouts from four for independent fields.
- Existing shared E8/E9 leaf bindings and unrelated helper preservation pass.
- **634** other files compare byte-identical: 423 memory bodies and 211
  probe/recovery/LPM/clock/LRU/ARRAY/task payloads.

See [host output](host-output.txt), [other comparisons](payload-comparison.txt),
[memory comparisons](memory-comparison.txt) and [raw location](host-location.txt).
The host used timing SH, image EX, one CPU-19 worker and the canonical
release target. Tested source and receipts were committed/pushed under Git
EX before releasing image EX. All raw files stay under `/workspaces`.

The first host attempt exited 101: 53 tests passed, but a literal newline
in the new C fixture's printf string caused compilation to fail before UID
execution. [First attempt](first-attempt.json), [first output](first-host-output.txt)
and [first target facts](first-target-layout.json) retain that result. The
forward retry fixes the fixture spelling and uses an existing test counter
in its print, removing warnings; UID runtime logic was unchanged. No source
was published until the full retry and byte comparisons passed.

Omp's separate Tracee batch ended while the retry waited. That image's row
is not a measurement of this later source commit. Application per-call,
throughput, equal work and installed native/JIT effects remain pending its
next image/check/target-app batch. PERF started no image or guest.

Next: inventory known scalar error-zeroing before adding cross-leaf tail
sharing. Current fixed scalar reads still carry generic zeroing loops even
when the copy count is already proven; keeping that count for error zeroing
can be a smaller change than introducing new tail-relocation plumbing.
