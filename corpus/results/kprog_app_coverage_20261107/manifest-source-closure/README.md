# Source manifest selectors follow libbpf subprogram closure

The generic source scanner follows direct BPF calls and function-address
LDIMM64 relocations through executable function extents. It counts every
reachable function once and collects helpers from that same closure. This
matches libbpf's linked instruction sequence used by the application's actual
BPF_PROG_LOAD. LDIMM64 data words remain part of their original instruction.

The complete Tetragon source scan records 93 objects, 436 named functions
and 70 changed metadata rows. execve_send now selects11296bytes:10368entry
plus928cwd_read_v61 callback. Its prior10368selector rejected the actual
1412instruction source before the common service saw that request. Native
objects, workload and loader match rules retain their original semantics.

Three compiled generic BPF regression tests cover direct local calls, repeated
static/global callbacks with shared descendants, helper closure and LDIMM64
high words. The C++ fixture now tests ambiguity using one explicit source BTF identity
with two different native targets, matching the current identity selector.
The original fixture failure and both fixture sources remain archived. The
existing C++ manifest-check target exits0. Commands:

```sh
CLANG=/usr/lib/llvm-18/bin/clang python3 vendor/bpf/test_write_native_manifest.py -v
make -C kprog/tv manifest-check
```

raw.tar.gz retains original/adopted scanner, fixture, checks, every source BPF
object with hashes, all prior/linked rows, manifest generation command and the
regenerated manifest. observations.json retains counts and source/archive pins.
The next whole-application batch consumes the regenerated manifest through the
existing native-only trusted-service recipe. Universal ISA/token/link/binding
laws supply the safety argument; these checks describe selector correctness.
