# LRU work in the reference Katran replay

Three expected LRU lookup sites become ARRAY/PERCPU_ARRAY lookup code in the
reference replay. This explains a concrete difference after the identical P.
It also means the old lookup speed includes a work difference to quantify.

All16 non-lookup helper anchors (clock, adjust-head, map-update) occur in the
same order in the preserved reference output and current helper-site record.
Between adjust-head4942 and clock5535, the source has LRU lookup5304 while
the reference interval contains zero external map lookups. Between clocks5535
and5853, LRU sites5743 and5831 also have zero external map lookups. The entire
reference output has zero generated writes of1 to LRU ref byte35.

The source lookup at3743 retains a generic map lookup; that kernel operation
performs the LRU ref update on a hit. The other three sites select the old
linker's ARRAY/PERCPU_ARRAY case, the lookup cases that emit address arithmetic
instead of a helper call. The raw hash and LRU cases in the May source emit a
helper call; the LRU case additionally emits the ref-bit write.

The May selector uses the first unused BPF-source lookup spec when a native
map name is unknown. This plan has70 BPF-source lookup specs for66 native
lookups. The four LRU sites consume an inner lru_mapping result or fallback_cache
through a stack-slot join; their prior classification is in fixed-frequency/
profile/dynamic-map-sites.json. Upstream balancer_maps.h declares the LRU maps
as BPF_MAP_TYPE_LRU_HASH. Kernel bpf_lru_list.h sets node.ref on a hit.

This is a replay of the preserved May-build linker using current kernel/map
facts. The supplied helper receipts establish instruction-order intervals;
actual branch frequency and the May run's exact live bytes remain open. The
requested default-entry timing after C's round will retain the work difference
alongside throughput, per-call counters and code sizes. The historical
measurements remain recorded. The operator's hard target is native1.50x and
about half the code; the coordinator's pure-body target was withdrawn00:19.

2026-11-16T01:26:05Z: November 14 live code now matches the reference replay on 9,560 unmasked bytes and all 27 external call classes. The three expansions receive 0/0/6 CPU-clock root samples. The capture lacks branch-stack/instruction trace, so exact branch frequency cannot be reconstructed. See nov14-lru-profile.md/json.
