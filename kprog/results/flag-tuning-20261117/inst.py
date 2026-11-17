"""Installed native and JIT bytes per run, from the shim's jit-info lines (original = JIT arm, native = installed).

Each replacement logs an original line and then a native line on the same thread; a pair is keyed by the native
program ID, so programs that share a (truncated) name each count once (perf review b6d0e9647)."""
import glob, os, re, sys
pat = re.compile(r'tid=(\d+)\] native-loader jit-info (original|native) fd=\d+ id=(\d+) type=\d+ name=\S* tag=\S+ jited_len=(\d+)')
for r in sys.argv[1:]:
    s = glob.glob(r + '/details/shim-logs/*post_rejit*')
    if not s:
        continue
    pending, pairs = {}, {}
    for line in open(s[0], errors='replace'):
        m = pat.search(line)
        if not m:
            continue
        tid, kind, prog, ln = m.groups()
        if kind == 'original':
            pending[tid] = int(ln)
        elif tid in pending:
            pairs[prog] = (pending.pop(tid), int(ln))
    so = sum(a for a, _ in pairs.values())
    sn = sum(b for _, b in pairs.values())
    print(os.path.basename(r), f'installed programs {len(pairs)} JIT {so} B native {sn} B ratio {sn / so:.2f}x' if so else 'no pairs')
