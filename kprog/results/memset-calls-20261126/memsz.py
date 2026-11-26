import subprocess, sys, re, collections, glob
app = sys.argv[1]
sizes = collections.Counter(); unknown = 0; byfn = collections.Counter()
for o in sorted(glob.glob(app + '/**/*.o', recursive=True)):
    out = subprocess.run(['llvm-objdump', '-dr', '--no-show-raw-insn', o], capture_output=True, text=True).stdout.splitlines()
    last = {}
    fn = '?'
    for i, l in enumerate(out):
        m = re.match(r'^[0-9a-f]+ <(.+)>:', l)
        if m:
            fn = m.group(1); last = {}; continue
        m = re.search(r'mov[lq]?\s+\$0x([0-9a-f]+), %(edx|rdx)', l)
        if m:
            last['dx'] = int(m.group(1), 16)
        m2 = re.search(r'R_X86_64_PLT32\s+(memset|memcpy)', l)
        if m2:
            if 'dx' in last:
                sizes[(m2.group(1), last['dx'])] += 1
            else:
                unknown += 1
            byfn[fn] += 1
            last = {}
print(app, 'unknown-size', unknown)
b = collections.Counter()
for (k, s), n in sizes.items():
    bucket = '<=128' if s <= 128 else '<=512' if s <= 512 else '<=4096' if s <= 4096 else '>4096'
    b[(k, bucket)] += n
for k in sorted(b): print(' ', k, b[k])
print('  top sizes', sizes.most_common(8))
print('  top functions', byfn.most_common(6))
