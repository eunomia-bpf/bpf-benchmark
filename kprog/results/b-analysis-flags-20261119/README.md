# Analysis-only B compile flags

The 2026-11-19T06:20 audit calls for O1/g0 for B after the retained Tetragon
frontend's superlinear O3/GVN compile. P and final native LTO stay O3.
First check the loader metadata contract: the simulator declares typed .ksyms
map externs, which libbpf must open before the stock verifier can inspect B.
The minimal real B object tests O1 with g0, line tables, and full type debug.
This is a host ELF/libbpf-open check, not a stock load or app timing run.
