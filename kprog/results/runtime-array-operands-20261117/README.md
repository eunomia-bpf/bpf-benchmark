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

This applier is one-shot; a failed applied source
requires a committed forward repair. Raw outputs stay under
`/workspaces/kprog-raw/perf/runtime-array-operands-20261117`.
All LTO is on. Local size does not establish app per-call/body/helpers/maps,
throughput or installed native/JIT size; Omp schedules that batch.
PERF starts no guest or image for this change.

Completed 2026-11-17T18:09:51Z: source `d226f71d0` is pushed. Host
2696608 exited 0, with 55 tests passed and 3 existing ignored tests.
All 36 offset/type cases pass, including positive type 128 staying
imm32 and the complete u32::MAX pattern. The key, bounds, mask,
wide-product, generic-helper argument/alignment, CALL/JMP entry and
external E8 relocation tests still pass. All 223 previous unrelated
leaf/metadata files and 423 memory bodies are byte-identical.

The actual runtime ARRAY fixture is **49 versus 64 bytes**. The type
comparison shrinks by six bytes (disp8 and imm8); the other three reads
shrink by three bytes each. It retains the same instructions and live
field work. Generic dispatch now reaches its stack alignment at local
offset 35 and its E8 relocation slot at 39, both verified. These offsets
are layout results, not a new ABI or hard-coded runtime input.

The production change is one net line smaller and reuses the existing
operand encoder; the test addition has a specific boundary purpose and
needs no driver. The decoder checks encoded instruction lengths because
iced-x86's `memory_displ_size` can describe a sign-extended 64-bit
displacement value rather than its encoded four bytes.

Evidence: [host output](host-output.txt), [measured sizes](local-sizes.txt),
[disassembly](array-disassembly.txt),
[leaf/metadata comparisons](payload-comparison.txt),
[memory comparisons](memory-comparison.txt) and [raw location](host-location.txt).
The recipe is `70000e883`; raw compiler, source diff, execution and
publication logs remain at
`/workspaces/kprog-raw/perf/runtime-array-operands-20261117/host-20261117T180906Z-2696608`.
No app per-call or installed-size improvement is inferred from this
local size result. The same all-LTO target-app batch still has to measure
body, helpers and maps alongside throughput and installed native/JIT.
