# Untouched-source Tetragon compiler experiment

`upstream-tetragon-ir` uses the upstream Makefile.defs compiler policy and the
object's original variant flags. It compiles the canonical upstream source both
to optimized BPF LLVM IR and directly to BPF ELF, retains dependency hashes, and
compares allocated bytes and relocations with the current image's original BPF
object. Comparisons are evidence, not a benchmark admission rule.

`upstream-tetragon-native` resolves CO-RE against the sole kernel BTF, lowers BPF
asm, then applies the existing native map/helper retargeting. It does not include
native_compat.h or compile the native producer's source overlay. Default image
and vendor native build paths do not invoke these targets.

The asm pass preserves tied masks, signed extension of BPF 32-bit immediates,
masked bounds, pointer-based stores, register loads and the source asm-goto's
unsigned comparisons. Empty/config/tail-call forms continue through the existing
context compiler. Other unhandled forms remain explicit compiler errors there.
The BPF comparison intrinsic becomes its LLVM integer predicate while retaining
the operand width and signedness.

```sh
make -f kprog/perf/native-context/Makefile bpf-asm-check
make -f kprog/perf/native-context/Makefile upstream-tetragon-link \
  SOCKET_BUILD=/var/tmp/kprog-tmp/perf/tetragon-context \
  TETRAGON_UNIT=bpf_generic_kprobe_v61 \
  TETRAGON_SOURCE=/workspaces/repository/vendor/repos/tetragon/bpf/process/bpf_generic_kprobe.c
```

Use a lane's own compiler output directory, or initialize and freeze shared
compiler outputs before concurrent Make processes. Rebuilding an executable in
place while another process launches it can produce EACCES. These are build
outputs; all sources remain in the single checkout.

The host fixture checks ten asm blocks over thirteen boundary values, including
high-bit unsigned inputs, an all-one immediate, unaligned reads, all neighboring
bytes around masked stores, and distinct/shared branch destinations. Original BPF ELF and
instruction disassembly remain alongside the translated/native test inputs.
An additional fixture checks all ten integer predicates at both 32 and 64 bits
over ten-by-ten boundary pairs (2000 results).
Offline proof artifacts do not establish kernel acceptance or application output
parity. In particular, a weak kfunc availability reference must remain real;
link failures must not be hidden by forcing availability or replacing its body.
