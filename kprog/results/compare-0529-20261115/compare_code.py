import glob, os, subprocess, sys
OLD = '/workspaces/kprog-raw/paper-tree-untracked/vendor/build/native-bpf/x86/stage'
NEW = '/workspaces/repository/vendor/build/native-bpf/x86/stage'
RE = '/usr/lib/llvm-18/bin/llvm-readelf'

def code(path):
    """Executable section bytes by section name (relocations unapplied)."""
    out = subprocess.run([RE, '-S', '-W', path], capture_output=True, text=True).stdout
    secs = {}
    data = open(path, 'rb').read()
    for line in out.splitlines():
        line = line.replace('[ ', '[')
        parts = line.split()
        if len(parts) < 8 or not parts[0].startswith('['):
            continue
        name, flags = parts[1], parts[7] if len(parts) > 7 else ''
        try:
            off, size = int(parts[4], 16), int(parts[5], 16)
        except ValueError:
            continue
        if 'X' in flags and parts[2] == 'PROGBITS' and size:
            secs[name] = data[off:off + size]
    return secs

for app in sorted(os.listdir(OLD)):
    same = differ = only_old = 0
    ob = nb = 0
    changed = []
    for f in sorted(glob.glob(f'{OLD}/{app}/*.native.o')):
        b = os.path.basename(f)
        g = f'{NEW}/{app}/{b}'
        o = code(f)
        ob += sum(map(len, o.values()))
        if not os.path.exists(g):
            only_old += 1
            continue
        n = code(g)
        nb += sum(map(len, n.values()))
        if o == n:
            same += 1
        else:
            differ += 1
            changed.append(f'{b}({sum(map(len, o.values()))}->{sum(map(len, n.values()))})')
    only_new = len([g for g in glob.glob(f'{NEW}/{app}/*.native.o') if not os.path.exists(f'{OLD}/{app}/' + os.path.basename(g))])
    print(f'{app}: objects code-identical={same} differ={differ} only-0529={only_old} only-now={only_new} code-bytes 0529={ob} now={nb}')
    if changed:
        print('   changed:', ' '.join(changed[:8]))
for app in sorted(set(os.listdir(NEW)) - set(os.listdir(OLD))):
    if os.path.isdir(f'{NEW}/{app}'):
        print(f'{app}: only now, {len(glob.glob(f"{NEW}/{app}/*.native.o"))} objects')
# Katran header-route object (timed) against the 05-29 one
k_old = code(f'{OLD}/katran/balancer.native.o')
k_hdr = code('/workspaces/repository/corpus/results/katran-c-hdr-20261115/objects/balancer.native.o')
k_ss = code('/workspaces/repository/corpus/results/katran-mapsink-20261114/objects2/balancer.native.o')
print('katran balancer: 05-29 vs header route identical:', k_old == k_hdr, {k: len(v) for k, v in k_old.items()}, {k: len(v) for k, v in k_hdr.items()})
print('katran balancer: 05-29 vs 11-14 map-sink route identical:', k_old == k_ss, {k: len(v) for k, v in k_ss.items()})
