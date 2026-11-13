"""Prepare resolved CO-RE IR for x86 codegen.

Three edits, each of which the shipped native objects already have and a raw frontend IR
does not:

  1. **Name the helper calls.** The BPF frontend leaves helpers as
     `inttoptr (i64 <id> to ptr)(...)`. The native linker resolves a helper by NAME, and
     clang is free to hoist such a constant into a register far from the call (and clobber
     it), so the call arrives unresolvable. The shipped objects carry
     `R_X86_64_PLT32 bpf_<name>` instead. This rewrites each `inttoptr` call into a call to
     a declaration of the uapi helper name.

  2. **Drop the frontend's target attributes.** The module and functions carry
     `"target-features"="+sse,+sse2"`, which overrides `-mgeneral-regs-only` at codegen and
     expands `llvm.memset`/`memcpy` into `movdqa`/`pxor`. Native code stays SIMD-free, so the
     attributes are removed.

  3. **Clear `dso_local` on the `.maps` globals.** With it, clang references the section
     symbol (`R_X86_64_PC32 .maps`, the *address* of a copy); without it, it emits the
     `GOTPCRELX` load whose slot the loader fills with the map pointer — the shipped form.

Usage: native-ir-prep.py <in.ll> <out.ll>
"""
import re
import pathlib
import sys

ROOT = pathlib.Path('/workspaces/repository')
UAPI = ROOT / 'vendor/linux-framework/include/uapi/linux/bpf.h'


def helper_names() -> dict[int, str]:
    return {int(m.group(2)): 'bpf_' + m.group(1)
            for m in re.finditer(r'FN\((\w+),\s*(\d+),', UAPI.read_text())}


CALL = re.compile(r'inttoptr \(i64 (\d+) to ptr\)\(')


def main(argv):
    src, dst = pathlib.Path(argv[1]), pathlib.Path(argv[2])
    names = helper_names()
    text = src.read_text()

    missing = set()

    def repl(m):
        name = names.get(int(m.group(1)))
        if name is None:
            missing.add(int(m.group(1)))
            return m.group(0)
        return f'@{name}('

    text = CALL.sub(repl, text)
    if missing:
        raise SystemExit(f'helper ids with no uapi name: {sorted(missing)}')

    # Declare each named helper once, typed by the first call site that uses it.
    for name in sorted(set(re.findall(r'@(bpf_\w+)\(', text))):
        if re.search(rf'^declare .*@{name}\(', text, re.M):
            continue
        m = re.search(rf'(%\S+) = (?:tail )?call ([\w*]+) @{name}\(', text)
        retty = m.group(2) if m else 'void'
        text = text.replace('\n\n', f'\ndeclare {retty} @{name}(...) ; bpf helper\n\n', 1)

    # 2 and 3.
    text = re.sub(r'"target-features"="[^"]*"\s*', '', text)
    # The frontend records "frame-pointer"="all" on every function, which overrides
    # -fomit-frame-pointer at codegen; the shipped objects are built without one.
    text = re.sub(r'"frame-pointer"="[^"]*"\s*', '', text)
    text = re.sub(r'"target-cpu"="[^"]*"\s*', '', text)
    # Every data global the native object references by address, not just .maps: a
    # dso_local global makes clang emit an R_X86_64_PC32 against the SECTION symbol (the
    # address of a copy), where the shipped objects carry a GOTPCRELX load of the slot the
    # loader fills from the symbol's name.  Only definitions are touched; declarations are
    # already non-dso_local.
    text = re.sub(r'^(@\S+ = )dso_local (global .*)$', r'\1\2', text, flags=re.M)
    text = re.sub(r'^(@\S+ = )dso_local (constant .*)$', r'\1\2', text, flags=re.M)

    dst.write_text(text)
    named = len(set(re.findall(r'@(bpf_\w+)\(', text)))
    print('helpers named', named, '| passthrough left',
          text.count('llvm.bpf.passthrough'))


if __name__ == '__main__':
    main(sys.argv)