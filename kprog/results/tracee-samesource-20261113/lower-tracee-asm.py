"""Fold llvm.bpf.passthrough and the BPF verifier's inline-asm idioms out of Tracee IR.

Tracee's untouched BPF source produces three things the x86 backend cannot compile, and all
three have an exact IR equivalent:

  1. `llvm.bpf.passthrough.<ty>(i32 CODE, V)` — the BPF backend's own marker; it returns V
     unchanged. Replacing the call by a copy would be correct but produces thousands of
     duplicate SSA names in Tracee's already-numbered IR, so instead every USE of the call
     result is rewritten to V and the call is dropped.

  2. `call void asm sideeffect "", "~{memory}"()` — a bare compiler barrier. Dropped.

  3. `asm sideeffect "if $0 < $1 goto +1; $0 = $1;", "r,i"` — clamp a size register to an
     immediate. No output operand: the clamp lands on the register's storage, so in SSA
     every later use of that value must see the clamped one. Two operand forms exist
     ("r,i" with a register, "r,i" with two constants where the idiom says nothing new) and
     `"=r,r,0"` (common.h's update_min, which has an output and is a direct min).

Usage: lower-tracee-asm.py <in.ll> <out.ll>
"""
import re
import pathlib
import sys

PASSTHROUGH = re.compile(
    r'^(\s*)(%\S+) = (?:tail )?call (ptr|i\d+) @llvm\.bpf\.passthrough\.\S+'
    r'\(i32 -?\d+, (ptr|i\d+) ([^)]+)\)(.*)$')
PASSTHROUGH_DECL = re.compile(r'^declare .*@llvm\.bpf\.passthrough\.')
EMPTY = re.compile(r'^\s*call void asm sideeffect "", "~\{memory\}"\(\)')
CLAMP = re.compile(
    r'^(\s*)call void asm sideeffect "if \$0 < \$1 goto \+1;\\0A\$0 = \$1;\\0A", '
    r'"r,i"\((i\d+) (\d+|%\S+), i(\d+) (-?\d+)\)')
MIN_OUT = re.compile(
    r'^(\s*)(%\S+) = call (i\d+) asm sideeffect "if \$0 <= \$1 goto \+1;\\0A\$0 = \$1;\\0A", '
    r'"=r,r,0"\(i\d+ (-?\d+), (i\d+) (%\S+)\)')


def define_name(n: int) -> str:
    return f'%__lp{n}'


def main(argv):
    src, dst = pathlib.Path(argv[1]), pathlib.Path(argv[2])
    lines = src.read_text().splitlines()

    # Pass 1: passthrough, one function at a time (SSA names repeat across functions, so a
    # whole-file alias map would fold a name from one function into another — which is
    # exactly the type error that appeared when %4 meant an i64 sext in one function and a
    # ptr passthrough in another).
    token = re.compile(r'%[\w.$]+')
    counts = {'functions': 0, 'aliases': 0}

    def fold_function(body: list[str]) -> list[str]:
        aliases = {}
        kept = []
        for line in body:
            if PASSTHROUGH_DECL.match(line):
                continue
            m = PASSTHROUGH.match(line)
            if m:
                _indent, lhs, retty, argty, argval, _tail = m.groups()
                if retty == argty:
                    aliases[lhs] = argval.strip()
                else:
                    kept.append(line)      # cross-type: leave it, it cannot be an alias
                continue
            kept.append(line)
        if aliases:
            counts['aliases'] += len(aliases)

            def resolve(name):
                seen = 0
                while name in aliases and seen < 64:
                    name = aliases[name].strip()
                    seen += 1
                return name

            resolved = {lhs: resolve(lhs) for lhs in aliases}
            renaming = {}

            def fix(line):
                m = re.match(r'^(\s*)(%[\w.$]+) = (.*)$', line)
                folded = token.sub(lambda t: resolved.get(t.group(0), t.group(0)), line)
                if m:
                    indent, lhs, _rhs = m.groups()
                    if re.search(re.escape(lhs) + r'(?![\w.])', folded):
                        new_name = f'{lhs}.lp'
                        renaming[lhs] = new_name
                        folded = re.sub(re.escape(lhs) + r'(?![\w.])', new_name, folded)
                for old_name, new_name in renaming.items():
                    folded = re.sub(re.escape(old_name) + r'(?![\w.])', new_name, folded)
                return folded

            kept = [fix(line) for line in kept]
        return kept

    out_lines, body = [], []
    for line in lines:
        if line.startswith('define '):
            out_lines.extend(fold_function(body))
            body = []
            counts['functions'] += 1
            out_lines.append(line)
            continue
        if line.startswith('}'):
            out_lines.extend(fold_function(body))
            body = []
            out_lines.append(line)
            continue
        body.append(line)
    out_lines.extend(fold_function(body))
    text = '\n'.join(out_lines) + '\n'

    # Pass 2: the asm idioms, now on alias-free text.
    lines = text.splitlines()
    out, pending = [], []
    counts.update({'barriers': 0, 'clamps': 0, 'constant_clamps': 0, 'output_mins': 0})
    index = 0
    for line in lines:
        if EMPTY.match(line):
            counts['barriers'] += 1
            continue
        m = CLAMP.match(line)
        if m:
            indent, ty, value, bty, bound = m.groups()
            if not value.startswith('%'):
                counts['constant_clamps'] += 1
                continue
            wide = 'i64' if (ty == 'i64' or bty == '64') else ty
            name = define_name(index)
            index += 1
            if wide == ty:
                out.append(f'{indent}{name} = call {wide} @llvm.smin.{wide}'
                           f'({wide} {value}, {wide} {bound})')
            else:
                out.append(f'{indent}{name}.w = zext {ty} {value} to {wide}')
                out.append(f'{indent}{name}.m = call {wide} @llvm.smin.{wide}'
                           f'({wide} {name}.w, {wide} {bound})')
                out.append(f'{indent}{name} = trunc {wide} {name}.m to {ty}')
            pending.append((value, name))
            counts['clamps'] += 1
            continue
        m = MIN_OUT.match(line)
        if m:
            indent, lhs, ty, bound, _aty, value = m.groups()
            out.append(f'{indent}{lhs} = call {ty} @llvm.smin.{ty}'
                       f'({ty} {value}, {ty} {bound})')
            counts['output_mins'] += 1
            continue
        for old, new in pending:
            line = re.sub(re.escape(old) + r'(?![\w.])', new, line)
        out.append(line)

    text = '\n'.join(out) + '\n'
    for ty in sorted(set(re.findall(r'@llvm\.smin\.(i\d+)\(', text))):
        decl = f'declare {ty} @llvm.smin.{ty}({ty}, {ty})'
        if decl not in text:
            text = text.replace('\n\n', f'\n{decl}\n\n', 1)
    dst.write_text(text)
    print('folded', counts, '|',
          '| asm left', text.count('asm sideeffect'),
          '| passthrough left', text.count('llvm.bpf.passthrough'))


if __name__ == '__main__':
    main(sys.argv)