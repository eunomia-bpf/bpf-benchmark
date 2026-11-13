"""Name the BPF helper calls in Tracee's frontend IR.

Tracee's frontend (the BPF target) leaves every helper call as
`inttoptr (i64 <id> to ptr)(...)`.  The native linker finds a helper by NAME: it maps an
immediate helper id to a name through its own table and then resolves that name.  A call to
an `inttoptr` constant gives it nothing to key on, and on x86 clang is free to hoist the
constant into a register far from the call (and clobber it), which is exactly the
"unresolved register-indirect call" the linker reported at trace_sys_enter+0x34a.

Naming each helper as a plain declaration gives the linker the same shape the shipped
objects have, and lets it bind by name.

Usage: name-helpers.py <in.ll> <out.ll>
"""
import re
import pathlib
import sys

ROOT = pathlib.Path('/workspaces/repository')
UAPI = ROOT / 'vendor/linux-framework/include/uapi/linux/bpf.h'


def helper_names() -> dict[int, str]:
    out = {}
    for match in re.finditer(r'FN\((\w+),\s*(\d+),', UAPI.read_text()):
        out[int(match.group(2))] = 'bpf_' + match.group(1)
    return out


CALL = re.compile(r'inttoptr \(i64 (\d+) to ptr\)\(')


def main(argv):
    src, dst = pathlib.Path(argv[1]), pathlib.Path(argv[2])
    names = helper_names()
    text = src.read_text()
    used = set()
    missing = set()

    def repl(m):
        helper_id = int(m.group(1))
        name = names.get(helper_id)
        if name is None:
            missing.add(helper_id)
            return m.group(0)
        used.add((name, m.group(0)))
        return f'@{name}('

    text = CALL.sub(repl, text)
    if missing:
        raise SystemExit(f'helper ids with no name in the uapi header: {sorted(missing)}')

    # Declare each named helper once, with the prototype the IR's call sites imply. The
    # linker only needs the name, and the call''s own arguments already type it, so a
    # permissive declaration is enough: varargs keep every call valid.
    for name in sorted({n for n, _ in used}):
        if f'declare' in text and re.search(rf'^declare .*@{name}\(', text, re.M):
            continue
        text = text.replace('\n\n', f'\ndeclare void @{name}(...) ; bpf helper\n\n', 1)
    # A `void(...)` declaration cannot be the operand of a non-void call; give each helper
    # the return type its first use expects.
    for name in sorted({n for n, _ in used}):
        m = re.search(rf'(%\S+) = (?:tail )?call ([\w*]+) @{name}\(', text)
        if not m:
            continue
        retty = m.group(2)
        text = re.sub(rf'^declare void @{name}\(\.\.\.\)', f'declare {retty} @{name}(...)',
                      text, count=1, flags=re.M)
    dst.write_text(text)
    print('helper ids named', len({n for n, _ in used}), '| call sites', text.count('@bpf_'))


if __name__ == '__main__':
    main(sys.argv)