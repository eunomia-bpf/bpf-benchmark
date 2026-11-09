# Six-save entry: original ISA48 replay

The original 48-case input set ran through the matching six-save JIT entry,
stock module and feature-selected native linker at model epoch
96b561e22981f4a5a0b03ec5b7b0374998e546ed.

| Outcome | Original frame | Six-save frame |
| --- | ---: | ---: |
| Valid execution | 10 | 10 |
| Verifier rejection | 34 | 32 |
| Specialization rejection | 1 | 1 |
| Accepted finding, load-only | 3 | 5 |

The exit_frame_pointer_map and exit_r12 cases change from rejection to acceptance.
Their original annotations stay published. The matching JIT entry now owns
physical RBP/R12 preservation; B retains SP and return-target checks.
The other 46 stages agree with the original-frame replay. The three continuing
findings are uninitialized_stack, immediate_push_branch, and stack_base_flags.
Unsafe native execution requests total 0. The driver retains all five findings
and exits 1; make exits 2. This is a completed diagnostic replay.

Reproduce with the entry-frame Makefile targets kernel module linker prepare isa48,
passing REVISION=96b561e22981f4a5a0b03ec5b7b0374998e546ed. The matching build
receipt sits in ../matched-kernel-build.json. The summary gives every
transition, runtime hash and input catalog hash. The raw archive holds the original
case table, outcomes, service/link/verifier archives, compiler broker records,
guest command, dmesg and exits. The original-frame comparison is
../before-isa48/.
