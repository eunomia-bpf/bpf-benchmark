# Constant-division strength reduction in native P production

The existing native division pass emits guarded hardware division before LLVM optimization. This candidate retains defined constant divisors as LLVM division/remainder operations so the existing optimizer selects shifts and reciprocal multiplication. Constant zero and signed minus-one keep their original guarded eBPF-semantic lowering. Variable divisors and vector lane semantics retain the original pass. The change is four compiler-source lines before P submission.

| Native object | Control DIV/IDIV sites | Candidate DIV/IDIV sites | Control bytes | Candidate bytes |
| --- | ---: | ---: | ---: | ---: |
| native/bcc/biosnoop.native.o | 0 | 0 | 1293 | 1293 |
| native/bcc/capable.native.o | 0 | 0 | 646 | 646 |
| native/bcc/opensnoop.native.o | 0 | 0 | 824 | 824 |
| native/bcc/runqlat.native.o | 2 | 2 | 1477 | 1464 |
| native/bcc/syscount.native.o | 0 | 0 | 540 | 540 |
| native/bcc/tcpconnect.native.o | 2 | 0 | 1540 | 1572 |
| native/bcc/tcplife.native.o | 2 | 0 | 1494 | 1514 |
| native/bcc/vfsstat.native.o | 0 | 0 | 148 | 148 |
| native/katran/balancer.native.o | 2 | 0 | 8250 | 8284 |
| native/katran/healthchecking.native.o | 0 | 0 | 1154 | 1154 |
| native/katran/healthchecking_ipip.native.o | 0 | 0 | 381 | 381 |
| native/katran/xdp_root.native.o | 0 | 0 | 68 | 68 |

The same current C, helper ABI, compiler flags and existing relocation kinds build both complete12-object producers. Scalar/optnone/flag-frame and vector oracles reuse the existing sources. Constant integer-width fixtures compare actual compiled results with mathematical quotient/remainder over exhaustive8/16-bit numerators and boundary/random32/64-bit numerators; summary.json records exact counts. Raw compiler commands, inputs, native objects and disassemblies accompany raw.tar.gz. Original38, generation-bound application loading, matching work and R-restored05-29 throughput remain subsequent observations. Production compiler source and active canonical/Os application epochs retain their captured definitions. Runtime admission additions0.
