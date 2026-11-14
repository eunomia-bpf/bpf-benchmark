# Constant tracing-context load representation

The optional B IR rewrite completed the focused stock-kernel load checks:
four original forms reject their modified context pointers and four rewritten
forms load successfully. The cases cover 8-,16-,32-,64-bit reads at offset80.
Host checks validate the exact emitted load width, original base register1 and
instruction offset80. Disabled bitcode equals the prior base compiler byte for
byte. `host.json`, `commands.json`, `kernel.csv` and `kernel.log` retain the
observations and commands; both small ELF objects are retained.

`KPROG_BPF_CONTEXT_LOADS=1` forwards `--canonical-ctx-loads` in the B-only IR
stage. The rewrite matches a constant address rooted in the original KPROBE
context, including an empty asm whose output is explicitly tied to its input
(`=r,0`). It emits a memory instruction with that base and displacement,
preserving width, volatility and narrow-result zero extension. Other sections,
dynamic addresses and untied asm outputs retain their representations. The
checked native compiler continues to consume the pre-bounds IR.

The kernel test ran on the sole kernel using CPUs22–23, one vCPU,2GiB and a
shared image lock. After tightening identity recognition in `5a75da273`, both
fixture objects equal the kernel-tested objects byte for byte; the additional
untied-output negative case passes the refined host test. The compiler was
built in scratch; the shared base, image and simulator headers retain their
existing versions.

This subset demonstrates the representation correction. The retained census
body70's whole generated C is queued for replay after the active OTel
application job, with24GiB address space on CPU19. `replay-queue.json` records
the exact command. That replay keeps its frontend IR for subsequent repairs,
uses scratch for large compiler files and persistent storage for raw request
facts, commands and results. Its compilation and actual stock-verifier replay
remain the next evidence. Runtime gains and application coverage retain their
separate work items.
