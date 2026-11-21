# x86 per-CPU/GS generation diagnosis (2026-11-21)

The two archived Tetragon requests reach a B frontend failure at the current_task reference. The adjacent native instruction uses GS addressing; generated B describes an ordinary memory load. The current parser also discards the segment selector. A faithful repair covers the symbol and the current-CPU addressing effect together.

| Archived request | Entry | current_task references | Observed stage |
| --- | --- | ---: | --- |
| 2 | event_exit_disassociate_ctty | 1 | Clang undeclared identifier, generated C113 |
| 101 | generic_kprobe_event | 2 | Clang undeclared identifier, generated C216/C375 |

Original capture: /workspaces/kprog-raw/omp/lto-tetragon-20261120T1151Z/service.tar.gz. The raw archive here preserves its exact service/requests/2.failure.tar.gz and service/requests/101.failure.tar.gz members and their recorded hashes. This is a two-request semantic diagnosis; all-application counts remain in their complete capture receipts.

Request2's native prefix loads the current_task symbol at0x53, then reads QWORD PTR gs:[rax] at0x5a. Its generated C uses X86_OP_MOV_LOAD_MAP_PTR and then X86_OP_MOV_LOAD with zero displacement and ordinary memory AUX. The current parse_mem_terms function returns the same tuple for QWORD PTR [rax], QWORD PTR gs:[rax] and QWORD PTR fs:[rax]: X86_RAX, X86_REG_NONE,0,0. The diagnostic records the actual imported parser result and its source SHA. The sole kernel's arch/x86/include/asm/current.h declares current_task with DECLARE_PER_CPU_CACHE_HOT and get_current uses this_cpu_read_const/this_cpu_read_stable.

From the repository root, the parser observation reproduces with:

```python
import sys
sys.path.insert(0, 'kprog/x86/micro-prog')
import generate_micro_sim_proofs as g
for operand in ['QWORD PTR [rax]', 'QWORD PTR gs:[rax]', 'QWORD PTR fs:[rax]']:
    print(operand, g.parse_mem_terms(operand))
```

The next generic repair retains the segment selector, binds the per-CPU symbol/type through existing kernel facts, and represents the current-CPU address base in the existing memory semantics. Register, flag, stack and architectural fault effects remain part of faithful(I,P). The common operation header is frozen under AGENTS.md's Freeze section; a defect-class opening goes through the coordinator if that body needs additions. The universal per-CPU relation stays with FORMAL. Runtime gates/predicates added0; source changes0; native executions0; benchmark measurements0. The coordinator's live x86 rotation and ARM check retain their image, base and resource ownership.

## Current canonical input scope

The current staged bpf_exit_v511.native.o, containing event_exit_disassociate_ctty, has SHAf32a5db27e88ffc7829d3d5ccb97be4560bfb5ce87a4b43db39dacad316194c5. Its complete symbol table contains zero current_task symbols and its undefined-symbol list is empty. The current native compatibility header routes bpf_get_current_task through helper35. current-input-symbols.json and current-input-raw.tar.gz preserve that exact ELF and both llvm-nm observations.

The archived GS-bearing P and this current P therefore have separate input identities. The diagnosis establishes the archived generation failure and the current parser's segment-loss behavior; current-image application acceptance remains its actual checked replay result. The common-header extension is a verifier-side semantic case for coordinator/FORMAL disposition, with the current performance image, O3 flags and timing rotation retained.
