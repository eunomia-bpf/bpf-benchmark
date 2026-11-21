# Original opcode7 dispatch

The generic handler now has a checked 39-step opcode7 dispatcher through its actual width call and every NOP/ADRP/MOV/MOVK/ALU gate, for both W and X widths. Both a world/symbol-bound theorem and the actual source-linked-world theorem preserve the same memory, environment and caller continuation. Real comparison temporaries2823/2824 are0 and2825 is1 for opcode7. The source AST and existing opcode3 public API are unchanged.

Component build passed228 jobs21.441s; two public type/axiom queries passed, standard logic and inherited CompCert external/inline semantics only. Exact hashes/timings/evidence are in validation.json. No proof cap raise, new premise, admission, axiom or instruction model. Whole-library confirmation follows the LHS operand batch; this does not establish complete fourth handler/native correspondence. M5/O1/O2/O4/M6 open, complete ISA families0. No applications, runtime tests or measurements.
