# RORX dispatch closes SipHash proof compilation OOM

The pure SipHash native program failed during fresh proof compilation in both the 8 GiB and 12 GiB standard runs. The latter guest kernel confirms Clang was OOM-killed. Of its 327 native instructions, 116 RORX instructions expanded the entire generic simulator dispatcher before optimization. This generated 599,577,941 preprocessed bytes.

The existing C RORX arm is extracted into one `X86_SIM_L_EXEC_RORX` macro, called by both the generic dispatcher and direct emitter. The sole specialization contract selects this same macro; generated C/Python/Lean tables, the independent Lean table, and existing C specialization oracles are synchronized. No benchmark-specific rule or new Python semantics. Reads, count, width-confined writeback and preserved flags remain identical. No changed P, compiler flags, verifier limits, guards or workloads, and no image/kernel/module rebuild.

| Actual original P | Fresh generation | Compile | Verifier accepted/bound | Native result/action |
| --- | ---: | ---: | ---: | --- |
| siphash_rotate64_mixer_xdp | 1 | 1 | 1 | 2666935177028490406 / 2 |

The private candidate at the canonical include/table paths generates all 116 direct calls through the production external service; it binds native program 11 to source program 6 and executes correctly. Its complete terminal archive contains the exact original kernel-owned P SHA `6b6bcfc6519f3474f4dc2a7e886f3469081e1fa09d019ee4e204d0f84e47d695`. The guest used 8 GiB/two vCPUs, host CPUs20-23, cached kernel and module. Mainline files outside its mount namespace stayed unchanged during this capture. Only after this success was the byte-exact candidate header promoted; the generated contract table is reproduced canonically rather than retaining the private table override.

Host same-flags compilation succeeds in 13.62 seconds. Preprocessing becomes 24,575,752 bytes; the sequential preprocessing/compile job reports max RSS 2,006,772 KiB. This resource diagnosis is not a performance comparison. Existing SHIFTX/RORX full-state independent oracle passes 195,841 cases under UBSan. Both existing specialization oracles pass (the direct-body comparison covers 534 cases), generator freshness/macro hygiene pass, and the focused generated/independent Lean specialization module checks with private output paths. Full formal and whole-program artifact proofs are not claimed here. Initial harness missing `/usr/bin/time` and initial oracle missing the new direct-body case/count are preserved before their fixes; final checks exit zero.

## Reproduction and raw evidence

`raw.tar.gz` retains the exact before/candidate headers and table, all ten source before/after files, original P and generated C/proof objects, before/after compressed preprocessed units, commands/compiler diagnostics, host oracle source/binary/logs, focused Lean checks, full kernel log/meminfo and the complete registered-service request archive. `checks.json` records source pins, build data, result and receipt. The private VM command and mount namespace are `experiment/run.sh` and `experiment/guest.sh`; host compilation and checks are `experiment/build.sh` and `experiment/checks.sh`.

A standard ordinary-PATH Make run on the promoted canonical handler/table is launched separately at `../micro-rorx-runtime`; its result is pending at this commit. This private component result closes the observed compilation failure but is not a full 29-case rerun or six-application result. Socket LB remains open in the published 27/29 table.
