# Map Inline Coverage Analysis (2026-03-26)

## Scope and method

- Built the daemon with `source /home/yunwei37/workspace/.venv/bin/activate && make daemon`.
- The user-provided `cargo run ... enumerate/rewrite <object>` recipe is stale for this checkout: current `daemon` CLI only accepts live program IDs, not object paths or `--btf-custom-path`.
- To keep the analysis faithful to the current daemon implementation, I ran an offline helper at `docs/tmp/20260326/map_inline_coverage_tool/` that links the daemon's real `elf_parser`, `pass`, `analysis`, and `map_inline,const_prop,dce` modules directly.
- Raw machine-readable output is in `docs/tmp/20260326/map_inline_coverage_analysis_20260326.json`.
- Each ELF program was analyzed in two modes:
  - `empty maps`: map metadata present, but all maps have no values.
  - `seeded maps`: deterministic synthetic values for inlineable map types (`ARRAY`, `HASH`, `LRU_HASH`) to measure structural opportunity.
- Important caveat: seeded-map results are an upper bound on static opportunity, not proof that production map state will make the same specialization legal or profitable.

## Headline results

- Corpus-wide, the current offline ELF parser found `568` `.bpf.o` objects containing `1488` programs.
- Across all corpus programs, I found `11190` raw `bpf_map_lookup_elem` helper calls (`call imm=1`) and `9079` daemon-recognized lookup sites (`find_map_lookup_sites()`).
- With empty maps, `map_inline` applied on `0` programs and `0` sites. In other words: without readable map values, the current pass does not produce map-inline specialization.
- With seeded inlineable maps, corpus-wide `map_inline` hit `37` programs / `61` sites. In the eight requested projects, it hit only `12` programs / `28` sites out of `314` lookup-bearing programs / `6271` recognized lookup sites.
- In the requested eight-project subset, every applied site was on an `ARRAY` map. There were no `HASH`/`LRU_HASH` hits in `katran`, `tracee`, `calico`, `cilium`, `tetragon`, `bcc`, `scx`, or `loxilb`.

## Per-project table

`Pipeline insns before/after` below is for the full `map_inline,const_prop,dce` pipeline. This overstates map-inline impact when `const_prop+dce` already shrink code without any map specialization; see the marginal table next.

| Project | Objects | Programs | Programs w/ lookup | Programs w/ map_inline | Raw helper calls | Recognized lookup sites | map_inline sites | Pipeline insns before | Pipeline insns after | Delta | Applied map types |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| katran | 5 | 5 | 4 | 1 | 85 | 79 | 1 | 2789 | 2788 | -1 | ARRAY 1 |
| tracee | 2 | 157 | 140 | 3 | 4555 | 2994 | 19 | 436205 | 382950 | -53255 | ARRAY 19 |
| calico | 8 | 8 | 8 | 0 | 534 | 534 | 0 | 158995 | 46344 | -112651 | None |
| cilium | 3 | 6 | 6 | 0 | 953 | 884 | 0 | 97576 | 1650 | -95926 | None |
| tetragon | 23 | 38 | 35 | 8 | 1403 | 1268 | 8 | 172508 | 29146 | -143362 | ARRAY 8 |
| bcc | 57 | 341 | 96 | 0 | 203 | 203 | 0 | 18508 | 17414 | -1094 | None |
| scx | 4 | 77 | 8 | 0 | 32 | 32 | 0 | 8520 | 7682 | -838 | None |
| loxilb | 3 | 18 | 17 | 0 | 277 | 277 | 0 | 77314 | 77314 | 0 | None |

## Marginal effect attributable to map values

This compares the same inline-hit programs in `empty maps` vs `seeded maps`. This is the relevant measure for `map_inline` itself.

| Project | Inline-hit programs | Empty-map insns after | Seeded-map insns after | Marginal delta from map_inline path |
| --- | ---: | ---: | ---: | ---: |
| katran | 1 | 22 | 21 | -1 |
| tracee | 3 | 7238 | 6570 | -668 |
| calico | 0 | 0 | 0 | 0 |
| cilium | 0 | 0 | 0 | 0 |
| tetragon | 8 | 5204 | 5204 | 0 |
| bcc | 0 | 0 | 0 | 0 |
| scx | 0 | 0 | 0 | 0 |
| loxilb | 0 | 0 | 0 | 0 |

Most meaningful seeded-map marginal shrinkage in the target set came from:

- `tracee.bpf.o:cgroup_skb/ingress`: `9` sites, `3596 -> 3266` (`-330`)
- `tracee.bpf.o:cgroup_skb/egress`: `9` sites, `3596 -> 3266` (`-330`)
- `tracee.bpf.o:raw_tracepoint/sched_process_free`: `1` site, `46 -> 38` (`-8`)
- `katran/xdp_pktcntr.bpf.o:xdp`: `1` site, `22 -> 21` (`-1`)

The eight Tetragon hits are real pass hits, but they produce **no additional shrinkage** relative to the empty-map pipeline in this offline setup: `empty` and `seeded` final instruction counts are identical on those programs.

## Key analysis questions

### 1. Without real map values (maps empty), does `map_inline` still produce meaningful optimization?

No.

- `empty maps` produced `0` applied `map_inline` sites corpus-wide and `0` in the requested projects.
- Any code-size reduction seen in empty-map runs comes from plain `const_prop+dce`, not from map specialization.
- Top empty-map blockers in the requested project subset were:
  - `2173` sites: `lookup key is not a constant stack materialization`
  - `1377` sites: `map type 6 not inlineable in v1` (`PERCPU_ARRAY`)
  - `1336` sites: `map type 13 not inlineable in v1` (`HASH_OF_MAPS`)
  - `392` sites: `map type 5 not inlineable in v1` (`PERCPU_HASH`)

Practical implication: static `.bpf.o` analysis without captured map state is not enough to demonstrate real `map_inline` benefit. You need live map snapshots or E2E map capture/replay.

### 2. What types of maps are being inlined (`ARRAY` vs `HASH`)?

For the eight requested projects, all applied sites were `ARRAY`:

- Requested-project lookup-site mix was dominated by unsupported or awkward types:
  - `PERCPU_ARRAY`: `1377`
  - `HASH_OF_MAPS`: `1336`
  - `HASH`: `1209`
  - `LRU_HASH`: `882`
  - `ARRAY`: `501`
- Requested-project applied-site mix:
  - `ARRAY`: `28`
  - `HASH`: `0`

Corpus-wide, seeded maps produced `40` applied `ARRAY` sites and `21` applied `HASH` sites, but the `HASH` hits were outside the requested eight-project subset and had **zero marginal instruction-count benefit** in this analysis. That matches the implementation: `ARRAY` can remove the lookup/null-check pattern, while speculative `HASH` inlining usually keeps the lookup structure and only replaces fixed loads.

### 3. Are the inlined programs the same ones that are hot in production?

Mostly no, or at least not provably.

- `katran`: the only hit is `xdp_pktcntr`, not the main `balancer` datapath. This is not the program I would treat as Katran's production hot path.
- `tracee`: the useful hits are `cgroup_skb/ingress` and `cgroup_skb/egress`. These could matter in network-heavy deployments, but they are not obviously the dominant hooks across all Tracee production workloads.
- `tetragon`: hits land in `generic_*_setup_event` / `filter_arg` / `process_event` programs, but they did not produce any extra shrinkage beyond the empty-map pipeline in this offline pass run.
- `cilium`, `calico`, `loxilb`, `bcc`, and `scx` all had lookup-heavy programs but **zero** `map_inline` hits here. That is a strong signal that the current v1 matcher/type support is not yet covering many of the likely hot real-world datapath/control programs.

So the answer is: the current hit set only partially overlaps with likely hot production programs, and the overlap is weak for the flagship datapath cases.

## Total `map_lookup_elem` helper calls across the corpus

Using daemon-style static analysis:

- Raw helper calls (`call imm=1`): `11190`
- Daemon-recognized lookup sites (`find_map_lookup_sites()`): `9079`
- Difference: `2111`

The gap is concentrated in `tracee`, `tetragon`, `cilium`, and `katran`, and reflects the daemon's stricter requirement that the helper call be paired with a recognizable `pseudo_map_fd` load/pattern.

## Bottom line

- On real corpus objects without live map contents, `map_inline` is effectively a no-op.
- Even with seeded inlineable values, coverage in the eight requested projects is narrow: `12/650` programs total, `12/314` lookup-bearing programs, `28/6271` recognized lookup sites.
- The only requested-project cases with clear marginal benefit are `tracee`'s two `cgroup_skb` programs and `katran/xdp_pktcntr`.
- In the requested set, all useful hits are `ARRAY`-map gates. `HASH` does not show up as a meaningful optimization story here.
- If the goal is a convincing "real programs" map-inline story, the next step is not more static `.bpf.o` sweeping. The next step is E2E map-state capture/replay against the actual hot programs.
