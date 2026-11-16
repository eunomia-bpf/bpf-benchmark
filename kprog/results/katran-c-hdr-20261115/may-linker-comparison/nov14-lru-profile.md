# November 14 live LRU paths

2026-11-16T01:26:05Z

The preserved live native payload matches the May-linker replay on 9,560 unmasked bytes. Its 10,164-byte payload starts at byte 19 of the captured 10,196-byte program (SHA256 3148a44deecb1cb1e0ffef20b3da840f04a58edc4f57074da7fa665fa8bbe773). The remaining 604 bytes are call/map relocation immediates. All 27 actual external call destinations were independently decoded from live bytes and resolved using that boot's kallsyms; they agree with the expected helper classes. In particular the generic lookup remains at payload4316; the three ARRAY expansions have no hidden LRU call or ref-byte store.

This establishes the earlier static finding on the November 14 live code. The May historical run itself has no live capture here.

| source LRU site | matched payload range | CPU-clock root samples | sampled period |
| --- | --- | ---: | ---: |
| 5304 | [6334,6367) | 0 | 0 ns |
| 5743 | [6916,6949) | 0 | 0 ns |
| 5831 | [7037,7070) | 6 | 6,006,006 ns |

Each range is the expanded lookup, from `mov eax,[rsi]` through array address computation, before `test rax,rax`. The surrounding setup loads the dynamic map from rsp+0x78. Source5304 has a real-map comparison afterward, source5743 follows the real-array lookup, and source5831 follows the TCP/flag checks. This correspondence uses retained proof/kernel disassemblies and unchanged helper order, recorded in lru-intervals.json.

The 435,681-event native capture has 15,549 root samples on this program. Its perf header records IP/TID/TIME/CALLCHAIN/CPU/PERIOD/IDENTIFIER, with no branch stack or instruction trace. Thus exact execution counts and taken fractions cannot be recovered from this capture. Six samples locate activity near site5831; zero samples do not prove the other sites never execute. CPU-clock skid and periodic sampling apply. No branch-frequency percentage is invented. The capture also includes warmup, while the retained BPF counters cover measured work only.

Raw commands, perf headers, decoded samples and byte-match receipts stay at /workspaces/kprog-raw/perf/20261116-reference-lru-profile. The existing default-entry comparison is queued after the breadth round; this work difference accompanies its numbers.
