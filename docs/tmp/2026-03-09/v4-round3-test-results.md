# v4 Round 3 Test Results

**Run date (UTC):** 2026-03-10 06:15:38 UTC
**Kernel branch:** `jit-directive-v4`
**Kernel commits:**
- `3d3587b8c v4 Round 3: ROTATE multi-pattern support (commuted 4-insn, 5-insn two-copy, 5-insn masked)`
- `d474b8022 v4 JIT policy: fix review issues R1/R3/R5/R6/R7`
- `e7521e8de v4: add interior edge check to prevent wrong cmov transformation`
**Kernel image:** `/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/boot/bzImage`
**Runner:** `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
**Raw outputs:** `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/v4-round3-raw`

## Build Summary

- Kernel build tail: `Kernel: arch/x86/boot/bzImage is ready  (#19)`
- micro_exec build tail: `[100%] Built target micro_exec`
- `rotate64_hash.mem` regenerated successfully before the VM runs.

## Runner Fixes Before Final Rerun

- Accepted `--recompile-wide-mem` as an alias for the existing wide recompile flag.
- Changed staged execution to fall back to packet-backed test input when a program has no `input_map` (needed for `packet_rss_hash`).
- Stopped treating `--input-size` as a hard upper bound on a provided memory blob and padded staged/map-backed inputs to the actual BPF map value size when needed.

## Official Test Status

| Test | Program | Directive | Status | Sites / note | exec_ns | jited_prog_len | xlated_prog_len |
| --- | --- | --- | --- | --- | ---: | ---: | ---: |
| 1 | rotate64_hash | ROTATE | PASS | recompile-rotate: found 115 rotate sites in xlated program (998 insns) | 333 | 2409 | 7984 |
| 2 | rotate64_hash | baseline | PASS | none | 277 | 3559 | 7984 |
| 3 | packet_rss_hash | ROTATE | PASS | recompile-rotate: found 11 rotate sites in xlated program (261 insns) | 125 | 865 | 2088 |
| 4 | packet_rss_hash | baseline | PASS | none | 250 | 1021 | 2088 |
| 5 | cmov_select | CMOV | PASS | recompile-cmov: no cmov-select sites found in xlated program (931 insns) | 2584 | 4168 | 7480 |
| 6 | load_byte_recompose | WIDE_MEM | PASS | recompile-wide: found 1 wide_load sites in xlated program (93 insns) | 576 | 410 | 744 |
| 7 | stride_load_4 | WIDE_MEM | PASS | recompile-wide: found 2 wide_load sites in xlated program (115 insns) | 308 | 493 | 920 |

## Summary Table

| Program | Directive | sites_found | jited_prog_len_before | jited_prog_len_after | exec_ns_before | exec_ns_after | speedup |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| rotate64_hash | ROTATE | 115 | 3559 | 2409 | 277 | 333 | 0.832x |
| packet_rss_hash | ROTATE | 11 | 1021 | 865 | 250 | 125 | 2.000x |
| cmov_select | CMOV | 0 | 4168 | 4168 | 2538 | 2584 | 0.982x |
| load_byte_recompose | WIDE_MEM | 1 | 422 | 410 | 485 | 576 | 0.842x |
| stride_load_4 | WIDE_MEM | 2 | 517 | 493 | 565 | 308 | 1.834x |

Supplemental baselines used for the `before` columns: Tests 8-10 (`cmov_select`, `load_byte_recompose`, `stride_load_4`).

## Key Findings

- ROTATE finally has non-zero kernel coverage. `rotate64_hash` accepted 115 sites and reduced `jited_prog_len` from 3559 to 2409.
- `packet_rss_hash` also moved from zero to 11 rotate sites, with `jited_prog_len` shrinking from 1021 to 865.
- `xlated_prog_len` stayed invariant for every before/after pair in this round, so the kernel rewrite path only changed native emission, not verifier output.

## xlated_prog_len Invariant Check

- `rotate64_hash` `ROTATE`: 7984 -> 7984 (delta 0)
- `packet_rss_hash` `ROTATE`: 2088 -> 2088 (delta 0)
- `cmov_select` `CMOV`: 7480 -> 7480 (delta 0)
- `load_byte_recompose` `WIDE_MEM`: 744 -> 744 (delta 0)
- `stride_load_4` `WIDE_MEM`: 920 -> 920 (delta 0)

## Round 3 vs Round 2

- `rotate64_hash`: Round 2 had 0 rotate sites and no JIT-size change on `--recompile-rotate` (`3559 -> 3559`, `exec_ns 324 -> 391`). Round 3 has 115 sites, `3559 -> 2409`, and `exec_ns 277 -> 333`.
- `packet_rss_hash`: Round 2 had 0 rotate sites and no JIT-size change (`1021 -> 1021`). Round 3 has 11 sites and `1021 -> 865`. Absolute exec/result values are not directly comparable because Round 2 used `--io-mode packet --raw-packet --input-size 54`, while the requested Round 3 command used `--io-mode staged --input-size 56` and now falls back to packet-backed execution for packet-only programs.
- `load_byte_recompose`: WIDE_MEM regression check still finds 1 site and preserves the Round 2 JIT-size delta (`422 -> 410`). Round 2 `exec_ns` was `545 -> 474`; this run measured `485 -> 576`, so the optimization coverage/code-size behavior matches even though the timing moved in the opposite direction.
- `stride_load_4`: WIDE_MEM regression check still finds 2 sites and preserves the Round 2 JIT-size delta (`517 -> 493`). Round 2 `exec_ns` was `647 -> 556`; this run measured `565 -> 308`.
- `cmov_select` was not part of the Round 2 result table. In this round it still reports `no cmov-select sites found in xlated program (931 insns)`, which matches the prior subprog-restriction diagnosis in `docs/tmp/v4-bug-diagnosis.md`.

## Per-Test Details

### Test 1: rotate64_hash ROTATE

- pass_fail: `PASS`
- exit_code: `0`
- command:
```bash
vng --run vendor/linux/arch/x86/boot/bzImage --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/rotate64_hash.bpf.o --memory micro/generated-inputs/rotate64_hash.mem --input-size 64 --io-mode staged --repeat 5 --recompile-rotate" 2>&1
```
- full_output:
```text
{"compile_ns":6164928,"exec_ns":333,"timing_source":"ktime","no_cmov":false,"disabled_passes":[],"wall_exec_ns":3156169,"exec_cycles":11634268,"tsc_freq_hz":3686199480,"result":2666935177028490406,"retval":2,"jited_prog_len":2409,"xlated_prog_len":7984,"code_size":{"bpf_bytecode_bytes":7984,"native_code_bytes":2409,"inflation_ratio":0.301728},"phases_ns":{"memory_prepare_ns":2010295,"object_open_ns":4666409,"object_load_ns":1412408,"input_stage_ns":889,"prog_run_wall_ns":15780508,"result_extract_ns":30},"perf_counters":{},"perf_counters_meta":{"requested":false,"collected":false,"include_kernel":true,"scope":"full_repeat_raw","error":""}}
 section(27) .symtab, size 384, link 1, flags 0, type=2
libbpf: looking for externs among 16 symbols...
libbpf: collected 0 externs total
libbpf: map 'input_map': at sec_idx 5, offset 0.
libbpf: map 'input_map': found type = 2.
libbpf: map 'input_map': found key [8], sz = 4.
libbpf: map 'input_map': found value [11], sz = 64.
libbpf: map 'input_map': found max_entries = 1.
libbpf: sec '.relxdp': collecting relocation for section(3) 'xdp'
libbpf: sec '.relxdp': relo #0: insn #10 against 'input_map'
libbpf: prog 'rotate64_hash_xdp': found map 0 (input_map, sec 5, off 0) for insn #10
libbpf: object 'rotate64_hash': failed (-95) to create BPF token from '/sys/fs/bpf', skipping optional step...
libbpf: map 'input_map': created successfully, fd=8
recompile-rotate: found 115 rotate sites in xlated program (998 insns)
```

### Test 2: rotate64_hash baseline

- pass_fail: `PASS`
- exit_code: `0`
- command:
```bash
vng --run vendor/linux/arch/x86/boot/bzImage --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/rotate64_hash.bpf.o --memory micro/generated-inputs/rotate64_hash.mem --input-size 64 --io-mode staged --repeat 5" 2>&1
```
- full_output:
```text
{"compile_ns":6533845,"exec_ns":277,"timing_source":"ktime","no_cmov":false,"disabled_passes":[],"wall_exec_ns":3828994,"exec_cycles":14114424,"tsc_freq_hz":3686196570,"result":2666935177028490406,"retval":2,"jited_prog_len":3559,"xlated_prog_len":7984,"code_size":{"bpf_bytecode_bytes":7984,"native_code_bytes":3559,"inflation_ratio":0.445767},"phases_ns":{"memory_prepare_ns":1648416,"object_open_ns":4870394,"object_load_ns":1663451,"input_stage_ns":968,"prog_run_wall_ns":19144412,"result_extract_ns":31},"perf_counters":{},"perf_counters_meta":{"requested":false,"collected":false,"include_kernel":true,"scope":"full_repeat_raw","error":""}}
 section(27) .symtab, size 384, link 1, flags 0, type=2
libbpf: looking for externs among 16 symbols...
libbpf: collected 0 externs total
libbpf: map 'input_map': at sec_idx 5, offset 0.
libbpf: map 'input_map': found type = 2.
libbpf: map 'input_map': found key [8], sz = 4.
libbpf: map 'input_map': found value [11], sz = 64.
libbpf: map 'input_map': found max_entries = 1.
libbpf: sec '.relxdp': collecting relocation for section(3) 'xdp'
libbpf: sec '.relxdp': relo #0: insn #10 against 'input_map'
libbpf: prog 'rotate64_hash_xdp': found map 0 (input_map, sec 5, off 0) for insn #10
libbpf: object 'rotate64_hash': failed (-95) to create BPF token from '/sys/fs/bpf', skipping optional step...
libbpf: map 'input_map': created successfully, fd=8
```

### Test 3: packet_rss_hash ROTATE

- pass_fail: `PASS`
- exit_code: `0`
- command:
```bash
vng --run vendor/linux/arch/x86/boot/bzImage --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/packet_rss_hash.bpf.o --memory micro/generated-inputs/packet_rss_hash.mem --input-size 56 --io-mode staged --repeat 5 --recompile-rotate" 2>&1
```
- full_output:
```text
{"compile_ns":5736214,"exec_ns":125,"timing_source":"ktime","no_cmov":false,"disabled_passes":[],"wall_exec_ns":3204573,"exec_cycles":11812722,"tsc_freq_hz":3686208207,"result":11016707074064960918,"retval":2,"jited_prog_len":865,"xlated_prog_len":2088,"code_size":{"bpf_bytecode_bytes":2088,"native_code_bytes":865,"inflation_ratio":0.414272},"phases_ns":{"memory_prepare_ns":2917055,"object_open_ns":4396787,"object_load_ns":1321362,"input_stage_ns":63681,"prog_run_wall_ns":16022628,"result_extract_ns":42},"perf_counters":{},"perf_counters_meta":{"requested":false,"collected":false,"include_kernel":true,"scope":"full_repeat_raw","error":""}}
erns total
libbpf: object 'packet_rss_hash': failed (-95) to create BPF token from '/sys/fs/bpf', skipping optional step...
recompile-rotate: found 11 rotate sites in xlated program (261 insns)
```

### Test 4: packet_rss_hash baseline

- pass_fail: `PASS`
- exit_code: `0`
- command:
```bash
vng --run vendor/linux/arch/x86/boot/bzImage --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/packet_rss_hash.bpf.o --memory micro/generated-inputs/packet_rss_hash.mem --input-size 56 --io-mode staged --repeat 5" 2>&1
```
- full_output:
```text
{"compile_ns":5057733,"exec_ns":250,"timing_source":"ktime","no_cmov":false,"disabled_passes":[],"wall_exec_ns":3293886,"exec_cycles":12141124,"tsc_freq_hz":3685957001,"result":11016707074064960918,"retval":2,"jited_prog_len":1021,"xlated_prog_len":2088,"code_size":{"bpf_bytecode_bytes":2088,"native_code_bytes":1021,"inflation_ratio":0.488985},"phases_ns":{"memory_prepare_ns":1611631,"object_open_ns":3656536,"object_load_ns":1401197,"input_stage_ns":122600,"prog_run_wall_ns":16468774,"result_extract_ns":91},"perf_counters":{},"perf_counters_meta":{"requested":false,"collected":false,"include_kernel":true,"scope":"full_repeat_raw","error":""}}
s total
libbpf: object 'packet_rss_hash': failed (-95) to create BPF token from '/sys/fs/bpf', skipping optional step...
```

### Test 5: cmov_select CMOV

- pass_fail: `PASS`
- exit_code: `0`
- command:
```bash
vng --run vendor/linux/arch/x86/boot/bzImage --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/cmov_select.bpf.o --memory micro/generated-inputs/cmov_select.mem --input-size 1024 --io-mode staged --repeat 5 --recompile-cmov" 2>&1
```
- full_output:
```text
{"compile_ns":15024698,"exec_ns":2584,"timing_source":"ktime","no_cmov":false,"disabled_passes":[],"wall_exec_ns":3111097,"exec_cycles":11468063,"tsc_freq_hz":3686179938,"result":11332120082118096118,"retval":2,"jited_prog_len":4168,"xlated_prog_len":7480,"code_size":{"bpf_bytecode_bytes":7480,"native_code_bytes":4168,"inflation_ratio":0.557219},"phases_ns":{"memory_prepare_ns":2108928,"object_open_ns":5664170,"object_load_ns":9360528,"input_stage_ns":1326,"prog_run_wall_ns":15555092,"result_extract_ns":31},"perf_counters":{},"perf_counters_meta":{"requested":false,"collected":false,"include_kernel":true,"scope":"full_repeat_raw","error":""}}
ect.bpf.o is GPL
libbpf: elf: section(17) .BTF, size 1878, link 0, flags 0, type=1
libbpf: elf: section(19) .BTF.ext, size 8280, link 0, flags 0, type=1
libbpf: elf: section(27) .symtab, size 504, link 1, flags 0, type=2
libbpf: looking for externs among 21 symbols...
libbpf: collected 0 externs total
libbpf: map 'input_map': at sec_idx 5, offset 0.
libbpf: map 'input_map': found type = 2.
libbpf: map 'input_map': found key [8], sz = 4.
libbpf: map 'input_map': found value [11], sz = 4104.
libbpf: map 'input_map': found max_entries = 1.
libbpf: sec '.relxdp': collecting relocation for section(3) 'xdp'
libbpf: sec '.relxdp': relo #0: insn #10 against 'input_map'
libbpf: prog 'cmov_select_xdp': found map 0 (input_map, sec 5, off 0) for insn #10
libbpf: sec '.relxdp': relo #1: insn #285 against '.text'
libbpf: sec '.relxdp': relo #2: insn #375 against '.text'
libbpf: sec '.relxdp': relo #3: insn #753 against '.text'
libbpf: sec '.relxdp': relo #4: insn #859 against '.text'
libbpf: object 'cmov_select': failed (-95) to create BPF token from '/sys/fs/bpf', skipping optional step...
libbpf: prog 'cmov_select_xdp': added 4 insns from sub-prog 'cmov_select_pick'
libbpf: prog 'cmov_select_xdp': insn #285 relocated, imm 639 points to subprog 'cmov_select_pick' (now at 925 offset)
libbpf: prog 'cmov_select_xdp': insn #375 relocated, imm 549 points to subprog 'cmov_select_pick' (now at 925 offset)
libbpf: prog 'cmov_select_xdp': insn #753 relocated, imm 171 points to subprog 'cmov_select_pick' (now at 925 offset)
libbpf: prog 'cmov_select_xdp': insn #859 relocated, imm 65 points to subprog 'cmov_select_pick' (now at 925 offset)
libbpf: map 'input_map': created successfully, fd=8
recompile-cmov: no cmov-select sites found in xlated program (931 insns)
```

### Test 6: load_byte_recompose WIDE_MEM

- pass_fail: `PASS`
- exit_code: `0`
- command:
```bash
vng --run vendor/linux/arch/x86/boot/bzImage --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/load_byte_recompose.bpf.o --memory micro/generated-inputs/load_byte_recompose.mem --input-size 64 --io-mode staged --repeat 5 --recompile-wide-mem" 2>&1
```
- full_output:
```text
{"compile_ns":5275148,"exec_ns":576,"timing_source":"ktime","no_cmov":false,"disabled_passes":[],"wall_exec_ns":3040959,"exec_cycles":11209702,"tsc_freq_hz":3686239636,"result":1253018829653002637,"retval":2,"jited_prog_len":410,"xlated_prog_len":744,"code_size":{"bpf_bytecode_bytes":744,"native_code_bytes":410,"inflation_ratio":0.551075},"phases_ns":{"memory_prepare_ns":1740331,"object_open_ns":3775588,"object_load_ns":1491094,"input_stage_ns":1003,"prog_run_wall_ns":15205156,"result_extract_ns":96},"perf_counters":{},"perf_counters_meta":{"requested":false,"collected":false,"include_kernel":true,"scope":"full_repeat_raw","error":""}}
pe=1
libbpf: elf: section(26) .symtab, size 408, link 1, flags 0, type=2
libbpf: looking for externs among 17 symbols...
libbpf: collected 0 externs total
libbpf: map 'input_map': at sec_idx 5, offset 0.
libbpf: map 'input_map': found type = 2.
libbpf: map 'input_map': found key [8], sz = 4.
libbpf: map 'input_map': found value [11], sz = 1032.
libbpf: map 'input_map': found max_entries = 1.
libbpf: sec '.relxdp': collecting relocation for section(3) 'xdp'
libbpf: sec '.relxdp': relo #0: insn #10 against 'input_map'
libbpf: prog 'load_byte_recompose_xdp': found map 0 (input_map, sec 5, off 0) for insn #10
libbpf: object 'load_byte_recom': failed (-95) to create BPF token from '/sys/fs/bpf', skipping optional step...
libbpf: map 'input_map': created successfully, fd=8
recompile-wide: found 1 wide_load sites in xlated program (93 insns)
```

### Test 7: stride_load_4 WIDE_MEM

- pass_fail: `PASS`
- exit_code: `0`
- command:
```bash
vng --run vendor/linux/arch/x86/boot/bzImage --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/stride_load_4.bpf.o --memory micro/generated-inputs/stride_load_4.mem --input-size 64 --io-mode staged --repeat 5 --recompile-wide-mem" 2>&1
```
- full_output:
```text
{"compile_ns":5639371,"exec_ns":308,"timing_source":"ktime","no_cmov":false,"disabled_passes":[],"wall_exec_ns":3061989,"exec_cycles":11287005,"tsc_freq_hz":3686167634,"result":1982929226459564480,"retval":2,"jited_prog_len":493,"xlated_prog_len":920,"code_size":{"bpf_bytecode_bytes":920,"native_code_bytes":493,"inflation_ratio":0.53587},"phases_ns":{"memory_prepare_ns":1602630,"object_open_ns":3998884,"object_load_ns":1630093,"input_stage_ns":1021,"prog_run_wall_ns":15309542,"result_extract_ns":41},"perf_counters":{},"perf_counters_meta":{"requested":false,"collected":false,"include_kernel":true,"scope":"full_repeat_raw","error":""}}
f: section(26) .symtab, size 408, link 1, flags 0, type=2
libbpf: looking for externs among 17 symbols...
libbpf: collected 0 externs total
libbpf: map 'input_map': at sec_idx 5, offset 0.
libbpf: map 'input_map': found type = 2.
libbpf: map 'input_map': found key [8], sz = 4.
libbpf: map 'input_map': found value [11], sz = 1032.
libbpf: map 'input_map': found max_entries = 1.
libbpf: sec '.relxdp': collecting relocation for section(3) 'xdp'
libbpf: sec '.relxdp': relo #0: insn #10 against 'input_map'
libbpf: prog 'stride_load_4_xdp': found map 0 (input_map, sec 5, off 0) for insn #10
libbpf: object 'stride_load_4': failed (-95) to create BPF token from '/sys/fs/bpf', skipping optional step...
libbpf: map 'input_map': created successfully, fd=8
recompile-wide: found 2 wide_load sites in xlated program (115 insns)
```

## Supplemental Baselines Used For Summary

### Test 8: cmov_select baseline

- pass_fail: `PASS`
- exit_code: `0`
- command:
```bash
vng --run vendor/linux/arch/x86/boot/bzImage --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/cmov_select.bpf.o --memory micro/generated-inputs/cmov_select.mem --input-size 1024 --io-mode staged --repeat 5" 2>&1
```
- full_output:
```text
{"compile_ns":13692153,"exec_ns":2538,"timing_source":"ktime","no_cmov":false,"disabled_passes":[],"wall_exec_ns":3143673,"exec_cycles":11588416,"tsc_freq_hz":3686265913,"result":11332120082118096118,"retval":2,"jited_prog_len":4168,"xlated_prog_len":7480,"code_size":{"bpf_bytecode_bytes":7480,"native_code_bytes":4168,"inflation_ratio":0.557219},"phases_ns":{"memory_prepare_ns":2230726,"object_open_ns":4429454,"object_load_ns":9262699,"input_stage_ns":2413,"prog_run_wall_ns":15718298,"result_extract_ns":32},"perf_counters":{},"perf_counters_meta":{"requested":false,"collected":false,"include_kernel":true,"scope":"full_repeat_raw","error":""}}
ect.bpf.o is GPL
libbpf: elf: section(17) .BTF, size 1878, link 0, flags 0, type=1
libbpf: elf: section(19) .BTF.ext, size 8280, link 0, flags 0, type=1
libbpf: elf: section(27) .symtab, size 504, link 1, flags 0, type=2
libbpf: looking for externs among 21 symbols...
libbpf: collected 0 externs total
libbpf: map 'input_map': at sec_idx 5, offset 0.
libbpf: map 'input_map': found type = 2.
libbpf: map 'input_map': found key [8], sz = 4.
libbpf: map 'input_map': found value [11], sz = 4104.
libbpf: map 'input_map': found max_entries = 1.
libbpf: sec '.relxdp': collecting relocation for section(3) 'xdp'
libbpf: sec '.relxdp': relo #0: insn #10 against 'input_map'
libbpf: prog 'cmov_select_xdp': found map 0 (input_map, sec 5, off 0) for insn #10
libbpf: sec '.relxdp': relo #1: insn #285 against '.text'
libbpf: sec '.relxdp': relo #2: insn #375 against '.text'
libbpf: sec '.relxdp': relo #3: insn #753 against '.text'
libbpf: sec '.relxdp': relo #4: insn #859 against '.text'
libbpf: object 'cmov_select': failed (-95) to create BPF token from '/sys/fs/bpf', skipping optional step...
libbpf: prog 'cmov_select_xdp': added 4 insns from sub-prog 'cmov_select_pick'
libbpf: prog 'cmov_select_xdp': insn #285 relocated, imm 639 points to subprog 'cmov_select_pick' (now at 925 offset)
libbpf: prog 'cmov_select_xdp': insn #375 relocated, imm 549 points to subprog 'cmov_select_pick' (now at 925 offset)
libbpf: prog 'cmov_select_xdp': insn #753 relocated, imm 171 points to subprog 'cmov_select_pick' (now at 925 offset)
libbpf: prog 'cmov_select_xdp': insn #859 relocated, imm 65 points to subprog 'cmov_select_pick' (now at 925 offset)
libbpf: map 'input_map': created successfully, fd=8
```

### Test 9: load_byte_recompose baseline

- pass_fail: `PASS`
- exit_code: `0`
- command:
```bash
vng --run vendor/linux/arch/x86/boot/bzImage --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/load_byte_recompose.bpf.o --memory micro/generated-inputs/load_byte_recompose.mem --input-size 64 --io-mode staged --repeat 5" 2>&1
```
- full_output:
```text
{"compile_ns":6269705,"exec_ns":485,"timing_source":"ktime","no_cmov":false,"disabled_passes":[],"wall_exec_ns":3148954,"exec_cycles":11607728,"tsc_freq_hz":3686216547,"result":1253018829653002637,"retval":2,"jited_prog_len":422,"xlated_prog_len":744,"code_size":{"bpf_bytecode_bytes":744,"native_code_bytes":422,"inflation_ratio":0.567204},"phases_ns":{"memory_prepare_ns":1772333,"object_open_ns":4580067,"object_load_ns":1689638,"input_stage_ns":1113,"prog_run_wall_ns":15744512,"result_extract_ns":38},"perf_counters":{},"perf_counters_meta":{"requested":false,"collected":false,"include_kernel":true,"scope":"full_repeat_raw","error":""}}
pe=1
libbpf: elf: section(26) .symtab, size 408, link 1, flags 0, type=2
libbpf: looking for externs among 17 symbols...
libbpf: collected 0 externs total
libbpf: map 'input_map': at sec_idx 5, offset 0.
libbpf: map 'input_map': found type = 2.
libbpf: map 'input_map': found key [8], sz = 4.
libbpf: map 'input_map': found value [11], sz = 1032.
libbpf: map 'input_map': found max_entries = 1.
libbpf: sec '.relxdp': collecting relocation for section(3) 'xdp'
libbpf: sec '.relxdp': relo #0: insn #10 against 'input_map'
libbpf: prog 'load_byte_recompose_xdp': found map 0 (input_map, sec 5, off 0) for insn #10
libbpf: object 'load_byte_recom': failed (-95) to create BPF token from '/sys/fs/bpf', skipping optional step...
libbpf: map 'input_map': created successfully, fd=8
```

### Test 10: stride_load_4 baseline

- pass_fail: `PASS`
- exit_code: `0`
- command:
```bash
vng --run vendor/linux/arch/x86/boot/bzImage --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/stride_load_4.bpf.o --memory micro/generated-inputs/stride_load_4.mem --input-size 64 --io-mode staged --repeat 5" 2>&1
```
- full_output:
```text
{"compile_ns":6536828,"exec_ns":565,"timing_source":"ktime","no_cmov":false,"disabled_passes":[],"wall_exec_ns":3978938,"exec_cycles":14667538,"tsc_freq_hz":3686294450,"result":1982929226459564480,"retval":2,"jited_prog_len":517,"xlated_prog_len":920,"code_size":{"bpf_bytecode_bytes":920,"native_code_bytes":517,"inflation_ratio":0.561957},"phases_ns":{"memory_prepare_ns":2784094,"object_open_ns":4928433,"object_load_ns":1608395,"input_stage_ns":954,"prog_run_wall_ns":19895435,"result_extract_ns":61},"perf_counters":{},"perf_counters_meta":{"requested":false,"collected":false,"include_kernel":true,"scope":"full_repeat_raw","error":""}}
f: section(26) .symtab, size 408, link 1, flags 0, type=2
libbpf: looking for externs among 17 symbols...
libbpf: collected 0 externs total
libbpf: map 'input_map': at sec_idx 5, offset 0.
libbpf: map 'input_map': found type = 2.
libbpf: map 'input_map': found key [8], sz = 4.
libbpf: map 'input_map': found value [11], sz = 1032.
libbpf: map 'input_map': found max_entries = 1.
libbpf: sec '.relxdp': collecting relocation for section(3) 'xdp'
libbpf: sec '.relxdp': relo #0: insn #10 against 'input_map'
libbpf: prog 'stride_load_4_xdp': found map 0 (input_map, sec 5, off 0) for insn #10
libbpf: object 'stride_load_4': failed (-95) to create BPF token from '/sys/fs/bpf', skipping optional step...
libbpf: map 'input_map': created successfully, fd=8
```

