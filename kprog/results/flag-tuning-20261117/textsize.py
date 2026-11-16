"""Executable bytes of every staged native object, per app (sections with the X flag)."""
import glob, os, re, subprocess, sys
root = sys.argv[1]
total = 0
for app in sorted(os.listdir(root)):
    d = os.path.join(root, app)
    if not os.path.isdir(d):
        continue
    size = 0
    for f in glob.glob(d + '/*.native.o'):
        out = subprocess.run(['llvm-readelf', '-SW', f], capture_output=True, text=True).stdout
        for line in out.splitlines():
            m = re.match(r'\s*\[\s*\d+\]\s+\S+\s+PROGBITS\s+\S+\s+\S+\s+([0-9a-fA-F]+)\s+\S+\s+(\S+)', line)
            if m and 'X' in m.group(2):
                size += int(m.group(1), 16)
    total += size
    print(f'{app} exec_bytes {size}')
print(f'all exec_bytes {total}')
