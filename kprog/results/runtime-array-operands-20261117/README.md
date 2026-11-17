# Runtime ARRAY field operands

The next item after ARRAY direct returns (`eecc7e859`) is routine-local
operand size. Four live u32 field reads currently always use disp32, and
the ARRAY type constant always uses imm32. The existing memory operand
encoder can encode zero/short offsets, and positive type constants through
127 fit the sign-extended immediate form exactly. Other constants retain
their full u32 representation. Existing signed-offset acceptance remains.

The minimal change is in `x86_runtime_array.rs`: reuse that encoder and
choose the type immediate at link time. Key reads, bounds, masking, full
64-bit product, value-pointer arithmetic, success/null returns and generic
aligned E8 helper call keep their existing instructions and semantics.
The value LEA has a SIB operand and stays unchanged. No new encoder,
runtime check, flag, limit, cached field, layout fact or relocation format.

The host recipe uses timing SH then image EX, CPU 19, one worker and a
32 GiB address-space cap. A focused decoder test covers offsets
0/1/127/128/4096/i32::MAX and type values 0/2/127/128/256/u32::MAX.
It checks full field values, displacement/immediate widths, unsigned type
bits, branch targets and the external helper slot. Existing real
key/bounds/mask/wide-product/generic-fallback and CALL/JMP relocation
execution tests remain. Previous unrelated payloads compare byte-for-byte
against the completed ARRAY return host run.

Results are pending. This applier is one-shot; a failed applied source
requires a committed forward repair. Raw outputs stay under
`/workspaces/kprog-raw/perf/runtime-array-operands-20261117`.
All LTO is on. Local size does not establish app per-call/body/helpers/maps,
throughput or installed native/JIT size; Omp schedules that batch.
PERF starts no guest or image for this change.
