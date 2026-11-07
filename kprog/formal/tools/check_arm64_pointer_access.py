#!/usr/bin/env python3
"""Reject unaligned pointer-read UB and split/widened actual BPF accesses."""
from pathlib import Path
from check_x86_memory_widths import command, instructions_by_function, accesses

ROOT = Path(__file__).resolve().parent.parent


def main():
    out = ROOT / "build/arm64-pointer-access"
    out.mkdir(parents=True, exist_ok=True)
    source = out / "pointer.c"
    source.write_text(r'''#include "arm64_sim_local_bpf.h"
void *load_pointer(void *p) { return ARM64_SIM_L_LOAD_PTR_ADDR((__u8 *)p + 3); }
void *load_context(void *p) { return ARM64_SIM_L_LOAD_PTR_AT(p, 88); }
void *load_negative(void *p) { return ARM64_SIM_L_LOAD_PTR_AT(p, -3); }
void *load_minimum(void *p) { return ARM64_SIM_L_LOAD_PTR_AT(p, -32768); }
void *load_maximum(void *p) { return ARM64_SIM_L_LOAD_PTR_AT(p, 32767); }
void *load_large(void *p) { return ARM64_SIM_L_LOAD_PTR_AT(p, 32768); }
#ifndef __BPF__
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int main(void) {
  unsigned char bytes[32];
  for (unsigned seed = 0; seed < 64; ++seed) {
    for (unsigned i = 0; i < sizeof(bytes); ++i) bytes[i] = (unsigned char)(17 * seed + 29 * i);
    for (unsigned offset = 0; offset < 8; ++offset) {
      uint64_t expected; memcpy(&expected, bytes + offset + 3, 8);
      if ((uintptr_t)load_pointer(bytes + offset) != expected) return 1;
    }
  }
  puts("ARM pointer access: 512 native reads including all unaligned offsets PASS");
  return 0;
}
#endif
''')
    include = ["-I", str(ROOT), "-I", str(ROOT.parent / "arm64"),
               "-I", str(ROOT.parent.parent / "vendor/libbpf/src")]
    host = out / "pointer"
    command(["cc", "-O2", "-Wall", "-Wextra", "-fsanitize=undefined",
             "-fno-sanitize-recover=undefined", *include, str(source), "-o", str(host)])
    print(command([str(host)]).strip())
    obj = out / "pointer.bpf.o"
    command(["clang-18", "-target", "bpfel", "-O2", "-g",
             "-I", "/usr/include/x86_64-linux-gnu", *include, "-c", str(source), "-o", str(obj)])
    disassembly = command(["llvm-objdump-18", "-d", str(obj)])
    (out / "pointer.asm").write_text(disassembly)
    functions = instructions_by_function(disassembly)
    expected = {"load_pointer": 3, "load_context": 88, "load_negative": -3,
                "load_minimum": -32768, "load_maximum": 32767, "load_large": 32768}
    assert functions.keys() == expected.keys(), functions.keys()
    for name, offset in expected.items():
        actual = accesses(functions[name], fixed_displacement=offset if name not in {"load_pointer", "load_large"} else None)
        assert actual == [("read", offset, 8)], (name, actual)
    print("ARM pointer access: six actual BPF single 8-byte reads, literal context/signed-limit offsets PASS")


if __name__ == "__main__":
    main()
