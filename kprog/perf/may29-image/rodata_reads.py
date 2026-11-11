"""Count reads of .rodata globals in native objects: the sites a load-time .rodata fold would touch.

Usage: python3 kprog/perf/may29-image/rodata_reads.py <native-bpf/x86_64 dir>
For each <app>/*.native.o, counts relocations in program sections whose target symbol lives
in a .rodata* section (named globals such as const volatile configuration; string
literals reached through section symbols are left out), and how many distinct such globals
each object reads.
"""
import sys, subprocess, pathlib, re, collections

def sections(obj):
    out = subprocess.run(['readelf', '-SW', obj], capture_output=True, text=True).stdout
    return {int(m.group(1)): m.group(2) for m in re.finditer(r'^\s*\[\s*(\d+)\]\s+(\S+)', out, re.M)}

def symbols(obj):
    out = subprocess.run(['readelf', '-sW', obj], capture_output=True, text=True).stdout
    syms = {}
    for line in out.splitlines():
        f = line.split()
        if len(f) >= 8 and f[0].endswith(':') and f[6].isdigit():
            syms[f[7]] = int(f[6])
    return syms

root = pathlib.Path(sys.argv[1])
print(f'{"object":40} {"programs":>8} {"rodata reads":>12} {"globals":>8}')
for obj in sorted(root.glob('*/*.native.o')):
    secs, syms = sections(obj), symbols(obj)
    rodata = {name for name, idx in syms.items() if secs.get(idx, '').startswith('.rodata')}
    out = subprocess.run(['readelf', '-rW', obj], capture_output=True, text=True).stdout
    reads, progs, cur = collections.Counter(), set(), None
    for line in out.splitlines():
        m = re.match(r"Relocation section '\.rela(.*)'", line)
        if m:
            cur = m.group(1) if not m.group(1).startswith(('.debug', '.eh_frame', '.BTF')) else None
            continue
        f = line.split()
        if cur and len(f) >= 5 and f[2].startswith('R_X86_64'):
            target = f[4].split('+')[0].split('-')[0]
            if target in rodata:
                reads[target] += 1
                progs.add(cur)
    print(f'{str(obj.relative_to(root)):40} {len(progs):>8} {sum(reads.values()):>12} {len(reads):>8}')
