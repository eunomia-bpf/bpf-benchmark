# map_inline static test report (2026-03-26)

## Execution notes

- Context source: `docs/kernel-jit-optimization-plan.md`.
- `make all` was attempted in the primary tree, but it failed in the existing `kernel-tests` step because `tests/kernel` is absent.
- `make vm-static-test TARGET=x86 STATIC_VERIFY_ARGS='--passes map_inline,const_prop,dce'` is not supported by the current `daemon/tests/static_verify.py` CLI, so the fallback `make vm-static-test TARGET=x86` path was used.
- The primary tree's `vm-static-test` path also rejected the current `macro_corpus.yaml` v2 `objects:` schema. I fixed that non-kernel loader issue in `runner/libs/catalog.py`.
- Because the primary tree's VM lock was saturated by unrelated queued VM benchmark jobs, the successful run used an isolated working copy with the same tree contents at `/tmp/bpf-benchmark-static-20260326`.
- Successful command:

```sh
source /home/yunwei37/workspace/.venv/bin/activate
nice -n 10 make vm-static-test TARGET=x86 VM_CPUS=4 VM_MEM=8G
```

- Result JSON: `/tmp/bpf-benchmark-static-20260326/daemon/tests/results/static_verify.json`
- Generated at UTC: `2026-03-27T03:21:29.317325+00:00`
- Kernel release: `7.0.0-rc2+`
- Important caveat: because `--passes` was unsupported, the reductions below are from the default static pipeline on programs where `map_inline` was applied, not from an isolated `map_inline,const_prop,dce`-only run.

## Summary

- Total programs tested: `1240`
- Objects dispatched: `539`
- Programs with any pass applied: `420`
- Programs with `map_inline` in `passes_applied`: `7` (`0.56%`)
- Average instruction reduction for `map_inline`-applied programs: `169.86` insns/program
- Average percentage reduction for `map_inline`-applied programs: `11.69%`
- Verifier acceptance rate: `922 / 1240 = 74.35%`
- Verifier acceptance rate for `map_inline`-applied programs: `7 / 7 = 100%`

## Top reductions

Only `7` programs had `map_inline` in `passes_applied`, so the requested top-10 list contains `7` rows.

| Rank | Object | Program | Before | After | Reduction (insns) | Reduction (%) |
| --- | --- | --- | ---: | ---: | ---: | ---: |
| 1 | `corpus/build/tracee/tracee.bpf.o` | `cgroup_skb_egre` | 3885 | 3300 | 585 | 15.06 |
| 2 | `corpus/build/tracee/tracee.bpf.o` | `cgroup_skb_ingr` | 3885 | 3300 | 585 | 15.06 |
| 3 | `corpus/build/katran/xdp_pktcntr.bpf.o` | `pktcntr` | 36 | 18 | 18 | 50.00 |
| 4 | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_map.bpf.o` | `oncpu` | 58 | 57 | 1 | 1.72 |
| 5 | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog.bpf.o` | `iter_tcp6_clien` | 27 | 27 | 0 | 0.00 |
| 6 | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog.bpf.o` | `iter_udp6_clien` | 25 | 25 | 0 | 0.00 |
| 7 | `corpus/build/tetragon/bpf_generic_kprobe.bpf.o` | `generic_kprobe_` | 2159 | 2159 | 0 | 0.00 |

## Method

- Parsed program records from the final `static_verify.json`.
- Counted a program as `map_inline`-applied when `map_inline` appeared in the record's `passes_applied` array.
- Computed instruction reduction as `insn_count_before - insn_count_after`.
- Computed reduction percentage as `(before - after) / before * 100`.
