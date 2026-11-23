# Original logical flags store order and header preservation

The actual CF/ZF/SF/OF/PF bodies, sequence control and inner loop exit compose
in31 source steps, returning the exact five pointer-temporary updates and
reached heap. Every later pointer read follows from the initial header loads
and the actual successful byte stores through `Mem.load_store_other`.
The final five header loads are preserved as part of the result.

The domain explicitly separates each flag data block from the binding-header
block. Flag data locations may share a block; mutual flag-byte separation is
work for native post-state matching. Successful stores are the actual five
heap-transition equations, with the source-produced constants, zero predicate,
sign and parity bytes and the exact intermediate heaps. Individual store theorems retain their
general domains. This is ordered source execution and header preservation;
whole native flags/writeback/handler correspondence continues next.

Focused72 jobs and two public type/axiom queries pass at200000/512 budgets,
j1,32GiB under shared timing. The original source and single external ISA
specification retain their definitions. Latest full confirmation remains
the DIV regression in `m5-xor-full-20261123`.
