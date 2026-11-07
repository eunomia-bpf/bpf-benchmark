# Independent ARM Katran LRU counter interpretation

The [original 14:59 raw run](../../../../../corpus/results/kprog_arm64_app_coverage_20261106/trusted-bcc-frame-result/context-native/trusted-arm64-katran-result/run-20261107T145906541111Z.tar.gz) matches its published
4b3d09c5543400e5b70aed41a671a1547dda2640 Git blob and SHA256
ac6aa71a8c8f52c48a4510a72e950a2043e04663fa3be86c9e89d965e8fc381f. This review reads its
work.json, guest receipt and nested successful service request directly,
independently of the later A behavior summary. It launches no VM and makes
no application, simulator, loader, kernel or workload change.

| Observation | Raw value |
| --- | ---: |
| pktgen packets / errors | 19,391 / 0 |
| Receiver packet delta, recomputed from before/after | 19,391 |
| Captured native run delta for attached bound program 15 | 19,391 |
| stats[512].v1: total VIP packets | 19,391 |
| stats[512].v2: generic LRU misses | 1 |
| stats[515].v1: fallback cache selections | 19,391 |

The recorded workload uses UDP (IP protocol 17). Katran’s source defines
LRU_CNTRS=0, LRU_MISS_CNTR=1 and FALLBACK_LRU_CNTR=3, relative to MAX_VIPS=512;
the runner labels those slots lru, lru_miss and fallback_lru. The balancer
increments fallback_lru when it selects fallback_cache, before the actual
cache lookup; it increments stats[512].v2 on the consistent-hash miss path.
The slot named lru_miss is a separate TCP SYN/non-SYN breakdown. Thus the
fallback count does not show a miss on every packet; the generic miss field
is 1. Total VIP packets are not asserted to be the LRU lookup denominator.
The verification file pins all three mapping sources and their line locations.

The immutable kernel-owned native input matches the generated input and
request hash. The loader reports a successful bind to program 15, and that
ID is attached in the raw topology. The guest exits 0. All reported stats-map counter and receiver
deltas are independently recomputed from raw before/after snapshots; drop,
pass, encapsulation-failure and consistent-hash-drop fields are zero.
The native run delta is a captured raw receipt field, also repeated in the
guest receipt: separate native kernel-counter before/after snapshots are
not retained, so this review does not independently recompute that field.

This is the historical single-arm functional run, whose worker was later
promoted in b89015df9528fd5d3dcd4d2f451ba2a8e8b2dad9. It does not establish
a new current two-start result, JIT equivalence, a speedup, or ARM hardware
performance. The original raw archive and source pins allow inspection without
copying its bytes or creating a second workload path.

Reproduce the raw counter check from the repository root:

~~~sh
python3 - <<'PY'
import json, tarfile
p = "corpus/results/kprog_arm64_app_coverage_20261106/trusted-bcc-frame-result/context-native/trusted-arm64-katran-result/run-20261107T145906541111Z.tar.gz"
with tarfile.open(p) as t:
    w = json.load(t.extractfile("run/work.json"))
b, a = w["outcomes_before"], w["outcomes_after"]
for name in ("lru", "lru_miss", "fallback_lru"):
    print(name, {k: a["counters"][name][k] - v for k, v in b["counters"][name].items()})
print("receiver", a["receiver"]["rx_packets"] - b["receiver"]["rx_packets"])
print("native raw receipt", w["native_run_counts"])
PY
~~~
