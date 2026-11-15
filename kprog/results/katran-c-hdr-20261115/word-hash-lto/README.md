# Katran compact word hash, fixed frequency

The all-LTO pair completed22:09:49Z on imageb6ed6a16. A/A and A/B each use
three180-second samples, CPU0–7 and the existing fixed-frequency entry.
Both application arms reportOK;73 host controls restore exactly after each run.

| Measure | Prior20:33 | Compact word hash |
|---|---:|---:|
| Per-call A/B divided by A/A |1.031460x|1.015468x|
| Mean throughput A/B divided by A/A |1.031075x|0.994092x|
| Installed native bytes |12418|11048|
| P xdp-section bytes |7965|7965|
| JIT bytes |13641|13641|
| Sampled JIT/native program text ns/call |59.604569 /52.271865|59.348604 /68.159874|

The payload shrinks12386→11016 bytes, while this pair shows no speed gain.
The counter arms are A/A179.440813→177.708909 and A/B176.313066→171.951561ns/call.
All raw TX errors remain with the observations. This is one completed pair;
the previous pair remains recorded, with no sample rejection or replacement.

The one60-second profile completes22:17:26Z on image5f60e756 after C's loader
fix66c32c4bc. P/proof/linker identities stay unchanged; all Katran relocations
are kind1. Replaying the timed plan with the profile boot's two perCPU facts
matches10448 unmasked payload bytes, plus568 relocation-masked bytes. The
masked runtime call/map values are outside that code-identity observation.
The cache metadata and original timed plan are retained here. Full captures
and profiles stay under the raw root in comparison.json.

Native retained source costs45.572898ns/call, close to the prior45.892902;
unmapped/expanded/runtime text rises6.378963→22.586976. The hash tail add at
installed offset10422 receives6.4696 sampled ns/call. Both arms still have
hot instructions immediately following real_pos loads and checksum work.
Samples can skid or alias: these are leads, not isolated instruction latencies.
Program text includes inline helpers; pure application-body1.50x is unproved.
Next inspect known-key specialization and actual dynamic-map lookup paths;
keep all LTO pieces enabled together. Per-call/throughput/body targets stay open.
