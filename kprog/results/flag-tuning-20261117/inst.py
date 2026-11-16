"""Installed native and JIT bytes per run, from the shim's jit-info lines (original = JIT arm, native = installed)."""
import glob, os, re, sys
for r in sys.argv[1:]:
    s = glob.glob(r + '/details/shim-logs/*post_rejit*')
    if not s:
        continue
    t = open(s[0], errors='replace').read()
    o = {}
    n = {}
    for kind, name, ln in re.findall(r'jit-info (original|native) fd=\d+ id=\d+ type=\d+ name=(\S*) tag=\S+ jited_len=(\d+)', t):
        (o if kind == 'original' else n)[name] = int(ln)
    common = [k for k in n if k in o]
    so = sum(o[k] for k in common)
    sn = sum(n[k] for k in common)
    print(os.path.basename(r), f'installed programs {len(common)} JIT {so} B native {sn} B ratio {sn / so:.2f}x' if so else 'no pairs')
