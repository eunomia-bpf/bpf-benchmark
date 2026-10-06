# P88 Real Per-Site PMU Profile

Date: 2026-04-30

## Decision

P88 replaces the `bpfprof` placeholder PMU path with real per-site branch profile data. The Paper B data path is now:

```text
live BPF program
  -> bpfprof --per-site
     -> fexit sidecar calls bpf_get_branch_snapshot()
     -> ringbuf LBR records
     -> JIT metadata + JIT image disassembly maps native IP to BPF PC
     -> profile.json per_site
  -> bpfopt branch-flip --profile profile.json
  -> bpfverify
  -> bpfrejit
```

`branch_flip` is production PGO code after P88, but it is still not in the default 11-pass `bpfopt optimize` list. Policy admission waits for Paper B benchmark data.

## Collection

`bpfprof --per-site` uses Linux `bpf_get_branch_snapshot()` from a tracing sidecar attached to each target program. Userspace enables kernel LBR collection with `perf_event_open`, consumes sidecar ringbuf events, and attributes each `perf_branch_entry` to a BPF source PC.

The IP mapping is intentionally fail-fast:

- `BPF_OBJ_GET_INFO_BY_FD` must expose JIT function ranges, JIT line metadata, xlated bytecode, and JIT image bytes.
- `iced-x86` decodes native JIT spans so branch records map to the actual BPF branch PC, not merely the BTF line start.
- If a native branch address cannot be mapped to one unique BPF branch site, profile collection exits 1.
- If no per-site branch data is captured, profile collection exits 1 and reports snapshot/entry/mapping counters.

No fallback to sampling mode, heuristic site selection, or empty profile output is allowed.

## JSON Contract

`profile.json` contains required program-level PMU fields plus required per-site fields:

```json
{
  "prog_id": 123,
  "duration_ms": 500,
  "run_cnt_delta": 15000,
  "run_time_ns_delta": 4500000,
  "branch_miss_rate": 0.032,
  "branch_misses": 480,
  "branch_instructions": 15000,
  "per_site": {
    "42": {
      "branch_count": 15000,
      "branch_misses": 480,
      "miss_rate": 0.032,
      "taken": 12000,
      "not_taken": 3000
    }
  }
}
```

`per_insn`, nullable PMU fields, and missing-site success are removed. `branch_flip` rejects profiles that lack program `branch_miss_rate` or any candidate site's real per-site counters.

## BranchFlip Behavior

`branch_flip` now makes PGO decisions only from real profile data:

- Program `branch_miss_rate` must be finite and within `[0, 1]`.
- Each candidate site must have `branch_count > 0`, valid `branch_misses`, finite `miss_rate`, and non-zero direction data.
- A candidate with missing site profile data returns an error, not a skip.
- The old heuristic fallback path was deleted as dead code.
- High program/site miss rate still skips as a safety gate, but only after real PMU data has been provided.

## Daemon Wiring

The daemon profile socket path now shells out to:

```bash
bpfprof --all --per-site --duration <window> --output-dir <workdir>
```

The runner Python boundary remains unchanged. `profile-start` starts the CLI collector; `profile-stop` reads the JSON files from the daemon work directory.

## Host Integration Result

`scripts/p88_branch_flip_dense_pgo.sh` exercises the end-to-end Paper B path on a host:

1. Build `branch_flip_dense.bpf.c` with `BRANCH_FLIP_DENSE_GROUPS=1` and `BRANCH_FLIP_DENSE_LANES=4` so all candidate branches fit inside the available LBR window.
2. Load the XDP program through the upstream `ip` loader on a veth pair.
3. Generate deterministic all-zero L2 frames from a netns workload.
4. Run `bpfprof --per-site`.
5. Run `bpfopt branch-flip --profile`, requiring `changed=true` and `sites_applied=4`.
6. Verify missing-site profile and missing `--per-site` both exit 1.
7. Run `bpfverify`.
8. Run `bpfrejit`.

On the current host the script reaches `bpfverify` successfully and then fails fast at `bpfrejit`:

```text
kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT: Invalid argument (os error 22)
host kernel UAPI does not expose fork BPF_PROG_REJIT; bpfrejit cannot complete on this host
```

This host has upstream UAPI where command 39 is `BPF_TOKEN_CREATE`, not the project fork `BPF_PROG_REJIT`. The script intentionally does not downgrade or skip ReJIT.

Observed successful pre-ReJIT artifacts from the host run:

| Check | Result |
|---|---|
| `bpfprof --per-site` | real `per_site` keys include candidate PCs `13`, `33`, `50`, `67` |
| `branch_miss_rate` | `0.002261850127843703` |
| `branch_flip` | `changed=true`, `sites_applied=4`, `insn_delta=0` |
| missing site data | exit 1, `no real per-site profile data` |
| missing `--per-site` | exit 1, `bpfprof requires --per-site` |
| `bpfverify` | `status=pass`, `insn_count=104`, `jited_size=411` |

## LOC Delta

Implementation commits before this documentation commit:

| Stage | Commit | Shortstat |
|---|---|---|
| 1 | `641195ba feat(kernel-sys): add perf_event_open + BPF_FUNC_get_branch_snapshot helpers` | 1 file, +577/-1 |
| 2 | `0e42d71d feat(bpfprof): real per-site profile via bpf_get_branch_snapshot LBR` | 4 files, +754/-259 |
| 3 | `0d1dfa06 feat(branch_flip): require real per-site profile, delete heuristic fallback` | 7 files, +217/-225 |
| 4 | `24abbf49 feat(daemon): wire profile-start/profile-stop to bpfprof per-site` | 1 file, +16/-4 |
| 5 | `00bb70b8 test(branch_flip): end-to-end PGO integration with branch_flip_dense` | 7 files, +617/-9 |

Total pre-doc implementation delta: +2181/-498 across staged commits.

## Self-Evaluation

- Real per-site PMU data path is implemented; placeholder fields and heuristic branch_flip fallback are gone.
- Missing PMU/per-site data surfaces as exit 1.
- `kernel-sys` remains the syscall boundary for BPF/perf/JIT metadata access.
- Runner Python, corpus, e2e cases, `micro/driver.py`, `vendor/linux-framework`, and `module/` were not modified.
- Remaining external blocker is host kernel support for project-fork `BPF_PROG_REJIT`; current upstream host fails at the final ReJIT step as designed.
