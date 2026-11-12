# Generated B stack storage, 2026-11-12

Read-only diagnosis of the shared B storage class, using completed census
request 29 (`generic_kprobe_filter_arg`, retained instance 39) as evidence.
The full native P, generated B and compiler/verifier logs are already in
`resident-stack-access.tar.gz`, published in de976dc14. Counts remain those
in `resident-first-thirty-one-receipt.json`; this analysis adds no load or run.

The generated C preamble defines `X86_SIM_STACK_BYTES 248U` and enumerates
31 named pointer/tag cells, M(0) through M(30). Its native byte arena is
smaller than the stock kernel's 512-byte BPF stack. The compiled B has these
instructions, as decoded by llvm-objdump-18:

```text
     0: *(u64 *)(r10 - 0x290) = r1
    27: *(u64 *)(r10 - 0x2d0) = r2
155092: *(u32 *)(r10 - 0xb00) = r3
155492: r5 = *(u32 *)(r10 - 0xb00)
```

The first instruction saves the incoming context at -656. The verifier log
rejects that write after processing one instruction. The deepest explicit
R10-relative offset in the disassembly is -2816; these later instructions
were not reached by verification. The `kprobe/trusted` section is 0x30b618
(3,192,344) bytes, or 399,043 eight-byte BPF instruction slots, including the
second slots of wide immediates. The object has an empty `.text` section.

The recorded final compiler invocation returned 0 with the existing
`-O3 -mcpu=v4 -target bpf -mllvm -bpf-stack-size=4096` flags. That compiler
setting permits emitting this object. The sole kernel defines
`MAX_BPF_STACK 512` in `include/linux/filter.h:99` and checks write offsets
against that boundary in `kernel/bpf/verifier.c:7583`. The stock rejection
therefore agrees with the compiled B's context save.

The generated native arena size accounts for architectural stack bytes.
Compiled B also has storage for simulator register values and tags, named
stack pointer/tag cells, and compiler-created temporary spills. Shared
definitions are `kprog/x86/x86_sim_local_bpf.h:248` (named cells), `:395`
(register and control state), `:414` (volatile overlapping byte/word arena),
and `:728` (unrolled byte release plus pointer-fact lifetime handling).
These declarations and expanded lifetimes are the general storage work to
investigate after the ranked census. The disassembly establishes total
storage pressure; it does not assign every spill to a particular C variable.

The analysis output is retained under
`/workspaces/kprog-raw/verified/20261112-resident-census/ready/first-thirty-one/stack-analysis/`.
The relevant extraction and decode commands were:

```sh
taskset -c 8-19 tar -xzf /workspaces/kprog-raw/verified/20261112-resident-census/ready/retry2-control/state/session-e0ue5kr8/requests/29.failure.tar.gz -C /workspaces/kprog-raw/verified/20261112-resident-census/ready/first-thirty-one/stack-analysis request/generated/trusted_x86.bpf.c request/generated/trusted_x86.bpf.o request/generated/commands.jsonl request/generation.metadata.json
taskset -c 8-19 llvm-objdump-18 -d --no-show-raw-insn /workspaces/kprog-raw/verified/20261112-resident-census/ready/first-thirty-one/stack-analysis/request/generated/trusted_x86.bpf.o > /workspaces/kprog-raw/verified/20261112-resident-census/ready/first-thirty-one/stack-analysis/bpf-disassembly.txt
```

The full pass continues with model d0890b14f, kernel 74d1097af561 and the same
image/base. This step changes documentation only. General B storage repair
follows the complete failure-class collection under the coordinator's 16:15
order; benchmark settings and compiler/verifier limits remain as recorded.
