# x86 BPF JIT ABI and kinsn Register Analysis

This note is analysis-only. It describes the current x86 BPF JIT register
contract, how ordinary BPF instructions use hidden x86 state, and what that
means for handcraft/native-to-kinsn conversion.

## Register ABI

The x86 BPF JIT does not expose all 16 x86 general registers as ordinary BPF
program registers. The architectural BPF register map is:

| BPF reg | x86 reg | Role |
|---|---|---|
| `BPF_REG_0` | `rax` | return value |
| `BPF_REG_1` | `rdi` | arg1 |
| `BPF_REG_2` | `rsi` | arg2 |
| `BPF_REG_3` | `rdx` | arg3 |
| `BPF_REG_4` | `rcx` | arg4 / shift count path |
| `BPF_REG_5` | `r8` | arg5 |
| `BPF_REG_6` | `rbx` | callee-saved BPF reg |
| `BPF_REG_7` | `r13` | callee-saved BPF reg |
| `BPF_REG_8` | `r14` | callee-saved BPF reg |
| `BPF_REG_9` | `r15` | callee-saved BPF reg |
| `BPF_REG_FP` / `BPF_REG_10` | `rbp`, or `r9` in private-stack mode | BPF frame pointer |
| `BPF_REG_AX` | `r10` | JIT/verifier temporary |
| `AUX_REG` | `r11` | JIT temporary |
| `X86_REG_R9` | `r9` | private-stack FP / 6th arg / trampoline use |
| `X86_REG_R12` | `r12` | arena base support |
| native `rsp` | `rsp` | host stack pointer |

Source anchors:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:166` defines `AUX_REG`,
  `X86_REG_R9`, and `X86_REG_R12`.
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:181` defines `reg2hex`.
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1811` remaps
  `BPF_REG_FP` to `X86_REG_R9` when private stack is active.

The practical rule is:

`r0..r9` are BPF data registers, `r10` is BPF frame pointer, and native
`r9/r10/r11/r12/rsp/rbp` are not generally free x86 registers in mixed
BPF/kinsn code.

## Current kinsn Execution Model

Current kinsn descriptors already have a native form:

```c
struct bpf_kinsn {
	struct module *owner;
	u16 max_insn_cnt;
	u16 max_emit_bytes;
	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
	int (*emit_x86)(u8 *image, u32 *off, bool emit,
			u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit,
			  u64 payload, const struct bpf_prog *prog);
};
```

There are two different outputs:

- `instantiate_insn()` returns verifier-facing BPF proof instructions.
- `emit_x86()` / `emit_arm64()` returns final native machine code.

For x86, the JIT calls `emit_x86()` from `emit_kinsn_desc_call()` and splices
the returned bytes into the final JIT image. The callback does not return a
`struct bpf_insn`; it writes native x86 bytes to a scratch buffer and returns the
byte count.

If a kinsn has no native emit callback, the verifier/fixup path can replace the
sidecar+call with the BPF proof sequence returned by `instantiate_insn()`, and
then the ordinary BPF JIT emits that proof sequence. That is effectively a
"proof-only macro" path, not a machine kinsn path. For instructions already
covered by ordinary BPF, the cleaner policy is even simpler: user space should
emit ordinary BPF directly and not emit a kinsn at all.

So there are three choices:

| Desired behavior | Mechanism | Where it belongs |
|---|---|---|
| Use existing BPF JIT lowering | Emit ordinary BPF, no kinsn | User-space pass/converter |
| Keep verifier proof but no native machine instruction | `instantiate_insn()` only; kernel patches to BPF proof sequence | Rare macro/proof-only cases, not normal machine kinsn policy |
| Emit a specific native instruction not expressible by BPF | `instantiate_insn()` plus `emit_x86()`/`emit_arm64()` | kinsn module |

The BPF-to-x86 equivalence table should therefore live in user-space selection
logic, not in the kinsn module:

- normal bpfopt passes should prefer ordinary BPF when the normal BPF JIT
  already emits the desired native instruction;
- the native-asm-to-handcraft converter should use the same table to decide
  whether an x86 instruction can be represented by ordinary BPF or requires a
  kinsn;
- the kernel module should only implement descriptors for instructions that
  actually need native emit or strict handcraft coverage.

Putting this policy in the kernel module would make the module duplicate the
ordinary x86 BPF JIT's instruction selector. Most of those helpers are private
to `bpf_jit_comp.c` anyway, so "ask the kernel JIT to emit the native bytes for
this BPF insn" is not a current module API.

## Hidden Register Users

| Native register/state | Kernel use | Consequence for kinsn |
|---|---|---|
| `r10` / `BPF_REG_AX` | Constant blinding, verifier rewrites, pointer-sanitize rewrites, probe-memory checks, atomic lowering | Safe as a native kinsn register only inside a region where ordinary BPF/JIT rewrites cannot clobber it live. Otherwise use stack shadow and reload around boundaries. |
| `r11` / `AUX_REG` | DIV/MOD source temp, variable shift temp when `rcx` conflicts, probe-memory checks, atomic fetch-op loop temp | Same as `r10`: ordinary BPF instructions may use it as an internal temporary. |
| `r9` | Private-stack frame pointer, helper-call save/restore in private-stack mode, 6th arg/trampoline role | Cannot be treated as a free native data reg when private stack or trampoline paths apply. If a handcraft region uses native `r9`, it must not overlap ordinary stack-addressing semantics that expect `r9` to be FP. |
| `r12` | Arena base loaded in prologue and used by arena `PROBE_MEM32` / `PROBE_ATOMIC` addressing | Not free for arena programs unless region boundaries save/restore arena base before ordinary arena accesses. |
| `rbp` | Normal BPF frame pointer when private stack is not active | Native `rbp` allocation conflicts with ordinary BPF stack addressing and function epilogue assumptions. |
| `rsp` | Host stack pointer | Should not be used as a translated data register unless the whole stack-frame model is explicitly simulated. |
| x86 flags | Ordinary x86 arithmetic/compare/shift instructions update flags; BPF has no cross-instruction flags state | Verifier can use stack-shadow flags, but final x86 still needs physical flags liveness from producer to consumer. |

`BPF_REG_AX` has an explicit kernel comment saying it is inaccessible from user
space, mapped in all JITs, used for constant blinding, and typically stateless:
valid within the executed instruction, not across several instructions
(`vendor/linux-framework/kernel/bpf/core.c:1308`).

## Current BPF-to-x86 Lowering

This is the concrete mapping currently emitted by the x86 BPF JIT. It answers
which x86 instructions are already reachable through existing BPF bytecode, and
which ones need kinsn coverage if we want native-asm parity.

Source anchors:

- ALU/MOV/immediate lowering: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1820`
- endian lowering: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2133`
- memory load/store lowering: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1115`
  and `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1226`
- conditional branch lowering: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2572`
- atomic lowering: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1334`

| Existing BPF insn shape | Current x86 emission | Is it a good native-asm substitute? |
|---|---|---|
| `BPF_ALU{32,64} ADD/SUB/AND/OR/XOR X` | one `add/sub/and/or/xor dst, src` | Yes, for normal two-register ALU. Clobbers flags. |
| `BPF_ALU{32,64} ADD/SUB/AND/OR/XOR K` | one `add/sub/and/or/xor dst, imm8/imm32`, with accumulator short form for `rax/eax` | Yes, except constant blinding may rewrite it through `BPF_REG_AX` before JIT. Clobbers flags. |
| `BPF_ALU{32,64} MOV X` | `mov dst, src` or `mov32 dst, src` | Yes. Does not clobber flags. |
| `BPF_ALU{32,64} MOV X` with sign-extension `off` | `movsx/movsxd dst, src` | Yes for register sign-extension forms. |
| `BPF_ALU{32,64} MOV K` | `mov dst, imm32`, `xor dst,dst` for zero, or sign-propagating `mov r64, imm32` | Mostly yes. Blinding can rewrite. |
| `BPF_LD IMM DW` | `movabs dst, imm64`, or shorter `mov imm32` when possible | Yes for immediate materialization. |
| `BPF_ALU{32,64} NEG` | `neg dst` | Yes. Clobbers flags. |
| `BPF_ALU{32,64} MUL X` | `imul dst, src` | Yes. Clobbers flags. |
| `BPF_ALU{32,64} MUL K` | `imul dst, dst, imm8/imm32` | Yes. Clobbers flags. |
| `BPF_ALU{32,64} DIV/MOD X/K` | multi-insn sequence using `rax`, `rdx`, possible `r11`, `div/idiv`, push/pop | No for 1:1 native parity. It is semantically equivalent BPF, not one native instruction. |
| `BPF_ALU{32,64} LSH/RSH/ARSH K` | `shl/shr/sar dst, imm` | Yes. Clobbers flags. |
| `BPF_ALU{32,64} LSH/RSH/ARSH X` | BMI2 `shlx/shrx/sarx` if available and count is not `rcx`; otherwise move count to `rcx` and emit `shl/shr/sar dst, cl` | Partly. It can emit good native shifts, but the selected x86 differs by CPU feature and register choice. |
| `BPF_ALU END FROM_BE 16` | `ror word dst, 8`; `movzx dst, word dst` | Semantic sequence, not one instruction. |
| `BPF_ALU END FROM_BE 32` | `bswap dst32` | Yes. |
| `BPF_ALU64 END FROM_BE 64` | `bswap dst64` | Yes. |
| `BPF_ALU END FROM_LE 16` | `movzx dst, word dst` | Yes for zero-extension. |
| `BPF_ALU END FROM_LE 32` | `mov dst32, dst32` zero-extension | Yes for zero-extension. |
| `BPF_ST NOSPEC` | `lfence` | Yes. |
| `BPF_LDX MEM B/H/W/DW` | `movzx` byte/word load, `mov` dword/qword load from `[base + off]` | Yes for base+disp loads. No index/scale. |
| `BPF_LDX MEMSX B/H/W` | `movsx/movsxd` from `[base + off]` | Yes for sign-extending base+disp loads. |
| `BPF_STX MEM B/H/W/DW` | `mov [base + off], src` | Yes for base+disp stores. No index/scale. |
| `BPF_ST MEM B/H/W/DW` | `mov [base + off], imm` | Yes for immediate stores within BPF immediate limits. |
| `BPF_PROBE_MEM` loads | address-check sequence using `r10/r11`, branch, then `mov/movsx/movzx` load | No for 1:1 native parity. It is a protected load sequence. |
| `BPF_PROBE_MEM32` / arena loads/stores | `mov/movsx/movzx [base + r12 + off]` using SIB scale 1, plus extable metadata | Only for arena/probe mode. Not a general indexed-address BPF instruction. |
| `BPF_ATOMIC ADD/AND/OR/XOR` no fetch | `lock add/and/or/xor [base + off], src` | Yes for these memory RMW forms. |
| `BPF_ATOMIC ADD | FETCH` | `lock xadd [base + off], src` | Yes. |
| `BPF_ATOMIC XCHG` | `xchg [base + off], src` | Yes. |
| `BPF_ATOMIC CMPXCHG` | `lock cmpxchg [base + off], src`, using `r0/rax` | Yes, but tied to BPF `r0 == rax` ABI. |
| `BPF_ATOMIC AND/OR/XOR | FETCH` | `cmpxchg` loop with `rax` and `r11` | No for 1:1 native parity. |
| `BPF_JMP/JMP32 JEQ/JNE/JGT/JLT/JGE/JLE/JSGT/JSLT/JSGE/JSLE X` | `cmp dst, src`; then `je/jne/ja/jb/jae/jbe/jg/jl/jge/jle` | Semantic branch yes. Not a standalone `cmp`: flags are consumed inside the same BPF insn lowering. |
| `BPF_JMP/JMP32 ... K` | `test dst,dst` for imm 0, otherwise `cmp dst, imm`; then `jcc` | Semantic branch yes. Same flags limitation. |
| `BPF_JMP/JMP32 JSET X/K` | `test dst, src/imm`; then `jne` | Semantic branch yes. Same flags limitation. |
| `BPF_JMP JA` | short/near `jmp`, or optimized out when target is fallthrough | Yes for unconditional direct branch. |
| `BPF_JMP CALL` | helper/subprog call sequence with BPF ABI, accounting, private-stack handling | Not a raw native call substitute. |
| `BPF_JMP EXIT` | cleanup jump or epilogue: restore regs, maybe restore `r12`, `leave`, `ret` | Not a raw `ret` instruction substitute. |

Important gaps relative to arbitrary clang x86 asm:

- No existing BPF insn means "emit `cmp/test` and leave flags live for a later
  instruction". BPF branches emit `cmp/test + jcc` as one semantic unit.
- No existing BPF insn emits `cmovcc` or `setcc` as general operations.
- No general BPF insn encodes `mem[base + index * scale + disp]`; normal
  `LDX/STX` are only `[base + disp]`. Arena/probe paths can use
  `[base + r12 + disp]` with scale 1, but that is not a general addressing mode.
- No ordinary BPF equivalent for `popcnt`, BMI bit ops (`blsi`, `blsr`, etc.),
  `movbe`, or arbitrary `lea base + index * scale + disp`.
- Some existing BPF insns are semantically equivalent but not 1:1 native
  equivalent: `div/mod`, protected probe loads, fetch-and/or/xor atomics,
  helper calls, and exits.

This means a machine-level kinsn can be 1:1 with a final x86 instruction only if
the native instruction is not already better represented by a normal BPF insn,
and its live native registers/flags are not silently clobbered by adjacent
ordinary BPF lowering.

## Current kinsn Over-Add Check

Rule of thumb:

- If existing BPF bytecode already makes the x86 JIT emit the same single x86
  instruction, a pass should normally keep ordinary BPF. The verifier already
  understands it, register provenance is preserved, and there is no kinsn call
  transport risk.
- A kinsn is justified when BPF cannot express the instruction shape: flags
  producer/consumer split, `cmov/setcc`, SIB indexed addressing, `lea`,
  `popcnt`, BMI, `prefetch`, `movbe`, `shld/shrd`, etc.
- A kinsn can still be useful in strict handcraft/native-parity mode even if a
  semantic BPF equivalent exists, but that should not drive normal bpfopt pass
  rewrites.

Current x86 kinsns that are redundant for normal pass output:

| Current kinsn | Existing BPF equivalent | Recommendation |
|---|---|---|
| `bpf_x86_movq_rr` | `BPF_MOV64_REG` emits `mov dst, src` | Do not use in passes. Use normal BPF move. |
| `bpf_x86_movl_rr` | `BPF_MOV32_REG` emits `mov32 dst, src` | Do not use in passes. |
| `bpf_x86_movswl_rr` | BPF sign-extending `MOV` form emits `movsx` | Usually unnecessary for pass output. |
| `bpf_x86_shrq_imm` | `BPF_ALU64 RSH K` emits `shr dst, imm` | Redundant for x86 `extract`; keep BPF. |
| `bpf_x86_andl_imm32` | `BPF_ALU AND K` can emit 32-bit `and dst, imm` | Redundant for x86 `extract`; keep BPF when semantics match. |
| `bpf_x86_xorl_rr` | `BPF_ALU XOR X` emits `xor dst, src` | Redundant unless strict flag/native-reg simulation needs a kinsn. |
| `bpf_x86_imulq_rr` | `BPF_ALU64 MUL X` emits `imul dst, src` | Redundant for BPF-safe regs; only handcraft strict mode may need it. |
| `bpf_x86_movzbl_mem` | `BPF_LDX MEM B` emits `movzx byte [base+off]` | Redundant; use ordinary BPF load. |
| `bpf_x86_movzwl_mem` | `BPF_LDX MEM H` emits `movzx word [base+off]` | Redundant; use ordinary BPF load. |
| `bpf_x86_movl_mem` | `BPF_LDX MEM W` emits `mov dword [base+off]` | Redundant; use ordinary BPF load. |
| `bpf_x86_movq_mem` | `BPF_LDX MEM DW` emits `mov qword [base+off]` | Redundant; use ordinary BPF load. |
| `bpf_x86_movb_mem_reg` | `BPF_STX MEM B` emits `mov byte [base+off], src` | Redundant; use ordinary BPF store. |
| `bpf_x86_movw_mem_reg` | `BPF_STX MEM H` emits `mov word [base+off], src` | Redundant; use ordinary BPF store. |
| `bpf_x86_movl_mem_reg` | `BPF_STX MEM W` emits `mov dword [base+off], src` | Redundant; use ordinary BPF store. |
| `bpf_x86_movq_mem_reg` | `BPF_STX MEM DW` emits `mov qword [base+off], src` | Redundant; use ordinary BPF store. |
| `bpf_x86_movb_imm_mem` | `BPF_ST MEM B` emits `mov byte [base+off], imm` | Redundant; use ordinary BPF store. |
| `bpf_x86_bswapl` | `BPF_END FROM_BE 32` emits `bswap dst32` | Redundant in normal passes. |
| `bpf_x86_bswapq` | `BPF_END FROM_BE 64` emits `bswap dst64` | Redundant in normal passes. |

Current x86 kinsns that are conditionally useful, but should not be used merely
because they exist:

| Current kinsn | Why conditional |
|---|---|
| `bpf_x86_rolw_imm` | BPF endian-16 emits `ror/rol word, 8` plus zero-extension. A standalone word rotate is useful for strict native parity, but endian pass can usually stay BPF. |
| `bpf_x86_addb_imm`, `bpf_x86_andb_imm`, `bpf_x86_xorb_imm`, `bpf_x86_xorb_rr`, `bpf_x86_orb_rr` | BPF ALU is 32/64-bit, not low-byte ALU. Needed only when the native instruction is really byte-width and byte-width flags/result matter. |
| `bpf_x86_incq` | BPF can implement `+1` as `add`, but `inc` differs in flag behavior (`CF` unchanged). Needed only when native flags parity matters. |
| `bpf_x86_not*` | BPF can compute bitwise-not with `xor -1`, but that is not the same machine instruction. Keep for strict native parity, not for ordinary semantic rewrites. |
| `bpf_x86_movzbl_rr`, `bpf_x86_movzwl_rr` | Same-reg zero-extension has BPF endian/ALU alternatives; cross-reg low-byte/low-word extraction may still need explicit kinsn if exact `movzx` matters. |
| `bpf_x86_alu_mem` forms like `addl_mem`, `xorl_mem`, `xorw_mem` | BPF has no ALU-with-memory operand, but semantic BPF can load then ALU. Use only for native 1:1 parity. |

Current x86 kinsns that are genuinely needed for native-shape coverage:

| Current kinsn | Why BPF is insufficient |
|---|---|
| `bpf_x86_cmp*`, `bpf_x86_test*` | BPF can emit `cmp/test + jcc`, but cannot leave flags live for later `cmov/setcc`. |
| `bpf_x86_cmov*` | No BPF instruction for conditional move. |
| `bpf_x86_set*` | No BPF instruction for `setcc`. |
| `bpf_x86_lea*` | BPF can add, but cannot emit flag-preserving `lea` with full addressing shape. |
| `bpf_x86_mov*_sib`, `bpf_x86_movsxd_sib` | Normal BPF load/store lacks general `base + index * scale + disp`. |
| `bpf_x86_movbe*_sib` | No ordinary BPF one-insn `movbe`, especially with SIB addressing. |
| `bpf_x86_popcntq` | No BPF popcount instruction. |
| `bpf_x86_blsi*`, `bpf_x86_blsr*` | No BPF BMI1 instruction. |
| `bpf_x86_prefetcht0` | No BPF prefetch instruction. |
| `bpf_x86_shld*`, `bpf_x86_shrd*` | No BPF double-precision shift instruction. |
| `bpf_x86_sbbl_imm0` | Consumes flags; no BPF flags state. |
| `bpf_x86_rol*/rorx*` | No general BPF rotate instruction. |

Pass-level implication:

- `cond_select`: keep `test/cmov` kinsns; the surrounding `movq_rr` kinsns are
  unnecessary because ordinary BPF `MOV64_REG` emits `mov` and does not clobber
  flags.
- `extract` on x86: current `shrq_imm + andl_imm32` kinsn lowering is likely
  over-added. Existing BPF can emit equivalent `shr/and`; ARM64 `ubfm` remains
  the real kinsn win.
- `endian_fusion` on x86: `mov*_mem + bswap*` mostly duplicates `LDX + BPF_END`
  lowering. It should only use kinsn if it proves a real x86 shape not reachable
  through ordinary BPF.
- `bulk_memory`: byte and word base+disp loads/stores are already ordinary BPF
  load/store shapes. Prefer pure BPF wide/narrow load/store rewrites unless a
  SIB or other non-BPF addressing mode is required.

## Preventing Duplicate kinsns

The risk is that future changes re-add machine kinsns for x86 instructions that
ordinary BPF already emits. To avoid this, classify every candidate first:

| Class | Meaning | Normal pass policy | Kernel/module policy |
|---|---|---|---|
| BPF exact alias | One existing BPF instruction already expresses the operation, and the x86 JIT emits the same instruction shape | Emit ordinary BPF directly | Do not add new native `emit_x86`; optional compatibility alias only |
| Semantic BPF expansion | BPF can prove the semantics but needs multiple BPF instructions or emits a different x86 instruction | Use ordinary BPF when native shape does not matter | kinsn only for strict handcraft/native parity |
| Machine-only | BPF cannot express the native instruction shape or hidden state | Emit kinsn | Must have verifier proof plus native emit |

Examples of BPF exact aliases:

| Candidate x86 kinsn | Canonical BPF |
|---|---|
| `bpf_x86_movq_rr` | `BPF_MOV64_REG(dst, src)` |
| `bpf_x86_movl_rr` | `BPF_MOV32_REG(dst, src)` |
| `bpf_x86_mov{zbl,zwl,l,q}_mem` | `BPF_LDX_MEM(B/H/W/DW, dst, base, off)` |
| `bpf_x86_mov{b,w,l,q}_mem_reg` | `BPF_STX_MEM(B/H/W/DW, base, src, off)` |
| `bpf_x86_movb_imm_mem` | `BPF_ST_MEM(B, base, off, imm)` |
| `bpf_x86_shrq_imm` | `BPF_ALU64_IMM(BPF_RSH, dst, imm)` |
| `bpf_x86_andl_imm32` | `BPF_ALU32_IMM(BPF_AND, dst, imm)` |
| `bpf_x86_imulq_rr` | `BPF_ALU64_REG(BPF_MUL, dst, src)` |
| `bpf_x86_bswapl/q` | `BPF_END FROM_BE 32/64` |

These aliases are useful as documentation and optional backward compatibility,
but normal passes should not generate them. They should generate the canonical
BPF instruction directly.

### Proof-only Forwarding

If an existing kinsn descriptor has `instantiate_insn()` but no `emit_x86()`:

1. The verifier temporarily lowers sidecar+call to the BPF proof sequence.
2. After proof succeeds, the original kinsn region is restored.
3. During misc fixups, if the program is JITed but the kinsn has no native emit,
   the sidecar+call is permanently replaced with the BPF proof sequence.
4. The ordinary BPF JIT emits final x86 for that BPF sequence.

That makes proof-only forwarding possible for compatibility aliases. However,
it still requires BTF/kfunc discovery to find the descriptor and call
`instantiate_insn()`. If compatibility is not needed, the better solution is for
user space to emit canonical BPF directly and avoid the alias kinsn entirely.

### Where the Alias Table Belongs

The BPF-to-x86 equivalence table belongs in user-space selection logic:

- bpfopt passes use it to decide "ordinary BPF or kinsn";
- the native-asm-to-handcraft converter uses it to decide whether an x86
  instruction can be represented by canonical BPF;
- tests can assert that exact aliases are not emitted by normal passes.

Putting this policy in the kernel module would duplicate the x86 BPF JIT's
instruction selector. It also grows the BTF name surface for no performance or
verifier benefit.

## BTF and Core Design Boundary

The current out-of-tree mechanism registers each kinsn as an empty kfunc and
uses BTF name/id discovery as the transport. That is acceptable for a small
number of experimental kinsns. It does not scale well if every x86 instruction
is represented as a separate kfunc:

- BTF function names become a de facto ABI.
- daemon/bpfopt must maintain a large name-to-BTF-id table.
- rename or module split becomes a compatibility issue.
- descriptors, reg use/def metadata, tests, and discovery paths grow with every
  alias, including aliases that should have been plain BPF.

If the project ever wants a full machine-kinsn IR, the better long-term core
shape is a numeric opcode/descriptor registry rather than BTF-per-kfunc as the
primary identity:

- stable opcodes such as `BPF_KINSN_X86_CMOVNEQ_RR`;
- descriptor contains arch, payload schema, register use/def, flag use/def,
  max proof length, and max native bytes;
- verifier core owns proof lowering/restoration;
- JIT core dispatches to arch emit;
- BTF remains only for experimental module extension.

For normal bpfopt, avoid the full-machine-IR route unless the instruction is
machine-only. For handcraft/native parity, a full machine-kinsn IR can be useful
as a research/control mode, but it should not make normal passes emit redundant
aliases.

## Alias Macro Shape

A small module-side macro layer can help document and prevent duplication, but
it should be restricted to BPF exact aliases.

The intended abstraction is "BPF-alias kinsn":

- verifier proof is exactly one existing BPF instruction;
- descriptor has no native `emit_x86`;
- final JIT goes through the ordinary BPF JIT after fixup;
- the alias is marked compatibility/documentation-only, not a normal pass
  target.

The macro should be kind-specific, not a universal kinsn macro, because payload
schemas differ by instruction class.

Possible alias macro families:

```text
DEFINE_ALIAS_RR(name, bpf_class, bpf_op)
DEFINE_ALIAS_UNARY_END(name, bits)
DEFINE_ALIAS_REG_IMM(name, bpf_class, bpf_op)
DEFINE_ALIAS_LDX(name, size)
DEFINE_ALIAS_STX(name, size)
DEFINE_ALIAS_ST_IMM(name, size)
```

These macros would generate the kfunc stub, BTF id entry, `instantiate_insn()`,
and a descriptor with no native emit. They should not be used for real
machine-only kinsns.

### Why Payload Schemas Differ

The difference is not just field order. The payload determines decoding,
validation, verifier proof, liveness, and native encoding.

| Schema | Payload | BPF alias? | Reason |
|---|---|---|---|
| RR | `dst, src` | Yes for simple BPF regs | Maps to `MOV`, `MUL`, `XOR`, etc. But if operands may be shadow native regs, payload also needs `tmp`, and proof is no longer one BPF insn. |
| Unary reg | `reg` | Sometimes | `bswapl/q` aliases to `BPF_END`; `not` and `popcnt` do not. |
| Reg+imm | `dst, imm` | Sometimes | `shr imm` and `andl imm32` alias; `inc` is not exact because `inc` preserves CF while `add 1` changes CF; byte ops are partial-register operations. |
| Base+disp load | `dst, base, off` | Yes | Maps to `BPF_LDX_MEM`; liveness is use `base`, def `dst`. |
| Base+disp store | `src, base, off` | Yes | Maps to `BPF_STX_MEM`; liveness is use `base,src`, no def. |
| SIB memory | `dst/base/index/scale/off/tmp...` | No | BPF has no `[base + index * scale + disp]`; proof must compute address in a temp. |
| ALU memory operand | `dst, base, off, tmp...` | No | BPF has no ALU-with-memory operand; proof must load then ALU. |
| Flags producer/consumer | operands plus flag proof/stack slots/tmp | No | BPF has no architectural flags. `cmp/test` define flags; `cmov/setcc/sbb` consume flags. |
| Shadow reg operand | operand plus temp/shadow slot | No | Verifier proof must load/store stack shadow for native-only regs. |

So the rule for the one-line alias macro is strict:

> Only use it when the verifier proof is exactly one ordinary BPF instruction
> and no hidden machine state is involved.

Everything else remains a real machine kinsn with explicit payload schema and
proof code.

## Micro Native Register Pressure

I scanned the generated `## Native ASM` blocks under `micro/programs/*.md`.
Current results:

| Register | Occurrences | Cases using it |
|---|---:|---:|
| `rax` | 712 | 29 |
| `rbx` | 320 | 20 |
| `rcx` | 591 | 29 |
| `rdx` | 615 | 29 |
| `rsi` | 431 | 29 |
| `rdi` | 513 | 29 |
| `rbp` | 118 | 13 |
| `rsp` | 52 | 5 |
| `r8` | 284 | 25 |
| `r9` | 346 | 23 |
| `r10` | 257 | 21 |
| `r11` | 252 | 19 |
| `r12` | 88 | 10 |
| `r13` | 68 | 7 |
| `r14` | 241 | 17 |
| `r15` | 121 | 15 |

Aggregate:

- 24/29 cases use at least one of `r9/r10/r11/r12/rsp`.
- 21/29 use `r10` or `r11`.
- 23/29 use `r9`.
- 10/29 use `r12`.
- 5/29 use `rsp`.
- 4/29 use all 16 general-purpose registers.

Cases that do not use the extra/reserved set in their native asm:

- `simple`
- `simple_packet`
- `bitmap_popcount_scan`
- `packet_checksum_fold`
- `trace_event_type_switch_dispatch`

High-pressure examples:

| Case | Extra/reserved usage |
|---|---|
| `katran_lb_consistent_hash_select` | `r9` 92, `r10` 88, `r11` 93, `r12` 13, `rsp` 3, `rbp` 24 |
| `bpftrace_comm_key_fnv_hash` | `r9` 11, `r10` 29, `r11` 62, `r12` 6, `rsp` 19, `rbp` 9 |
| `packet_vlan_tcpopt_parser` | `r9` 27, `r10` 26, `r11` 7, `rbp` 3 |
| `siphash_rotate64_mixer` | `r9` 54 |
| `flow_5tuple_rss_hash` | `r9` 29, `r10` 20, `r11` 2, `rbp` 14 |
| `packed_header_bitfield_decode` | `r9` 8, `r10` 10, `r11` 9, `r12` 17, `rsp` 7, `rbp` 13 |
| `tetragon_process_event_arg_filter` | `r9` 10, `r10` 6, `r11` 8, `r12` 9, `rsp` 17, `rbp` 9 |
| `cilium_ct_nat_tuple_rewrite` | `r9` 9, `r10` 9, `r11` 12, `r12` 11, `rbp` 11 |

So full native parity is not blocked by a rare corner. General x86 LLVM output
uses BPF-reserved/native-only registers in most micro programs.

## Flags Through Stack Shadow

Stack-shadow flags are the right verifier-facing model:

- `cmp/test/add/sub/...` kinsns update a stack slot representing ZF/CF/SF/OF/etc.
- `cmov/setcc/jcc` instantiate paths read those stack slots and expand to
  verifier-visible BPF branches/selects.

But that only proves the BPF simulation. The final x86 path still emits one
machine instruction per kinsn and reads real CPU flags. Therefore:

- A flag-producing kinsn and a flag-consuming kinsn must remain in one physical
  flag-live region.
- No final x86 instruction that clobbers flags may be scheduled between them
  unless it is also part of the same intended flag chain.
- Ordinary BPF fallback in the middle of a flag-live region is unsafe, because
  ordinary BPF ALU/JMP lowering may clobber physical flags even though the
  verifier stack-shadow state still looks correct.

This is the main reason `cmp/test` plus `cmov/setcc/jcc` cannot be treated as
independent instructions unless the region has explicit flag-liveness rules.

## Option A: Fully Simulate 16 x86 Registers and Flags

This is the "more absolute" kinsn design:

- User space emits a kinsn stream mechanically from native x86 asm.
- Each kinsn has one final x86 instruction.
- The verifier-facing instantiate path simulates x86 architectural state using
  BPF registers plus stack shadow slots for native regs and flags.

Required mechanisms:

- Stack shadow slots for all native registers that are not BPF architectural
  data regs: at least native `r9/r10/r11/r12/rbp/rsp`, and possibly flags.
- Region boundaries that spill/reload or reconcile shadow state with real BPF
  regs before any ordinary BPF instruction, helper call, tail call, exit, or
  verifier-visible memory access that depends on BPF state.
- A strict "no ordinary BPF inside live native state" rule, or a liveness-aware
  bridge that saves and restores `r9/r10/r11/r12` and flags around ordinary BPF.
- Private-stack awareness for `r9`.
- Arena awareness for `r12`.
- A stack model if native `rsp/rbp` appear as data or addressing registers.
- Flag-live region validation from every producer to every consumer.

Pros:

- Best research control for "how close can kernel JIT get to clang native x86?"
- Lets the converter mechanically translate more native asm.

Cons:

- Hard to make safe in mixed BPF/kinsn programs.
- Large correctness surface: native register liveness, flag liveness,
  private-stack mode, arena mode, helper calls, prologue/epilogue, extable fixups.
- "One kinsn = one final x86 instruction" is achievable only after introducing
  region-level constraints and bridge code. The bridge code is not part of the
  kinsn, but it is still extra machinery.

This route is appropriate for a handcraft/native-parity experiment, especially
for straight-line or no-helper micro cases. It is not the simple production path.

## Option B: Restrict LLVM to the BPF-Safe Register Set

The alternative is to make the native source for conversion use only the BPF
JIT architectural data-register set:

- allocatable data regs: mapped BPF `r0..r9`
- frame pointer: BPF `r10` only as frame pointer, not a data register
- avoid native `r9/r10/r11/r12/rsp/rbp` as general data registers
- avoid cross-instruction physical flags unless represented by adjacent kinsns
  with explicit region validation

This can be viewed as a custom x86 codegen mode whose physical register set is
the x86 BPF JIT register map:

`rax, rdi, rsi, rdx, rcx, r8, rbx, r13, r14, r15`

and not the full SysV x86-64 register file.

Pros:

- Much simpler correctness model.
- Ordinary BPF fallback remains safe because native temporaries do not live in
  JIT-internal registers.
- The converter no longer needs to model most hidden BPF JIT ABI state.
- kinsns can focus on instruction-selection gaps: `lea`, `cmov`, `setcc`,
  `popcnt`, indexed loads, `movbe`, rotates, etc.

Cons:

- It will not match unconstrained clang native x86 register allocation.
- Some native performance will be lost from register pressure.
- It likely needs a real LLVM backend/MI-pass/register-reservation mechanism;
  it is not just a post-hoc textual asm rewrite. A normal SysV x86 function
  still has prologue/epilogue, `rsp`, sometimes `rbp`, and calling-convention
  assumptions.

### Can the Compiler Ban x86 Registers?

I checked the local toolchain:

- `clang` 18.1.3 does not expose x86 `-ffixed-r9/-ffixed-r10/...`.
  It accepts/advertises fixed-register flags for several other targets
  (AArch64/RISC-V/ARM/SPARC/M68k/Hexagon), but x86 `-ffixed-r10` and
  `-ffixed-r11` are unknown, and x86 `-ffixed-r9` is rejected as unsupported.
- LLVM backend option `-reserve-regs-for-regalloc=<string>` does exist and can
  be passed through clang as `-mllvm -reserve-regs-for-regalloc=...`.
  However, this is not currently a supported x86/x86_64 register reservation
  mechanism. The local x86 test accepted the option but still allocated
  `%r9/%r10/%r11/%r12`, even when subregister aliases were listed. LLVM upstream
  discussion/bug reports describe the same boundary: AArch64/RISC-V have
  target-specific reservation mechanisms, while x86/x86_64 lacks a supported
  named-GPR reservation path.
- `gcc` does support x86 `-ffixed-r*`. In the same small test,
  `-ffixed-r9 -ffixed-r10 -ffixed-r11 -ffixed-r12 -ffixed-rbp` avoided those
  registers as allocator choices.

So the practical status is:

| Route | Status |
|---|---|
| Clang command-line flag for x86 fixed regs | Not available in the local clang 18 toolchain. |
| LLVM backend `reserve-regs-for-regalloc` | Option exists, but not wired as a working x86/x86_64 GPR reservation path in this environment. |
| LLVM `-stress-regalloc=N` | Works as an experiment to limit allocator pressure, but it does not ban specific registers and can introduce many stack spills. |
| GCC `-ffixed-r*` | Works for x86 in a smoke test, but changes compiler and codegen, not ideal if the benchmark path is clang/LLVM. |
| LLVM backend patch | Cleanest LLVM route: add a target option/subtarget bit and mark selected x86 physical registers reserved in `X86RegisterInfo::getReservedRegs()` and related allocation masks. |

If we want the x86 native asm to use only BPF-safe data registers, the target
allowed set should be:

```text
rax, rdi, rsi, rdx, rcx, r8, rbx, r13, r14, r15
```

and the compiler should avoid allocating data values in:

```text
r9, r10, r11, r12, rbp
```

`rsp` is already the stack pointer, but stack spills still create native
`rsp`-relative memory references. If the converter cannot model native stack
slots, the codegen mode also needs either no spills or a well-defined stack-slot
translation.

This makes "restrict LLVM to 10 BPF-safe regs" simpler than full x86 state
simulation only if we are willing to patch/control the compiler backend. As a
pure clang flag, it is not currently available for x86 in this environment.

For experiments, this can be useful:

```bash
clang -O2 -S \
  -mllvm -stress-regalloc=6 \
  -fomit-frame-pointer \
  -mno-red-zone \
  input.c -o output.s
```

Then check the generated asm:

```bash
rg -n '%r(9|10|11|12|bp)|%e(9|10|11|12|bp)d|%rsp|\\(%rsp\\)' output.s
```

In a local smoke test:

- `-stress-regalloc=10` still used `%r9/%r10/%r11`;
- `-stress-regalloc=8` still used `%r9/%r10`;
- `-stress-regalloc=6` avoided `%r9/%r10/%r11/%r12/%rbp`, but produced many
  `%rsp`-relative spills/reloads.

So `-stress-regalloc=6` is useful for quick experiments, but it is not a real
solution if the converter cannot model native stack slots. A real BPF-safe x86
mode still needs an LLVM x86 backend reservation option or a post-RA verifier
that rejects forbidden registers and stack spills.

## Comparison

| Question | Full 16-reg kinsn simulation | LLVM restricted to 10 BPF data regs |
|---|---|---|
| Converter complexity | High: translate all x86 state and maintain shadow/liveness | Lower: translate a BPF-JIT-compatible subset |
| Kernel module complexity | High: many machine kinsns plus region rules and ABI bridges | Moderate: targeted kinsns for missing x86 instructions |
| Mixed ordinary BPF safety | Hard; ordinary BPF can clobber native temps/flags | Natural; ordinary BPF owns the same ABI |
| Exact native parity | Best potential | Intentionally gives up unconstrained native parity |
| Production suitability | Risky unless restricted to kinsn-only regions | Better fit |
| Micro research value | High | Medium |

## Conclusion

For production bpfopt/ReJIT, restricting code generation to the BPF-safe
10-data-register subset is the simpler and more robust direction. It aligns the
compiler output with the existing BPF JIT ABI instead of trying to virtualize
the entire x86 machine state inside BPF.

For the handcraft/native-parity experiment, full x86 simulation is still useful,
but it should be treated as a kinsn-only region experiment:

- no ordinary BPF fallback inside live native register/flag regions;
- stack-shadow state for non-BPF native regs and flags;
- explicit region boundaries for helper/call/exit/ordinary-BPF transitions;
- private-stack and arena register ownership handled at the boundary, not by
  pretending `r9` and `r12` are always free.

So the answer is:

LLVM restricted to 10 BPF data registers is simpler for the long-term compiler
path. Full stack-shadow x86 simulation is more powerful as a research/control
mode, but it is substantially more complex than it first looks because it must
model BPF JIT ABI ownership, not just x86 ISA semantics.
