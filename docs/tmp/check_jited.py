import json, sys

path = sys.argv[1] if len(sys.argv) > 1 else '/tmp/extract_verify.json'
with open(path) as f:
    d = json.load(f)

for bench in d['benchmarks']:
    print(f"bench={bench['name']}")
    for run in bench['runs']:
        samples = run.get('samples', [])
        if samples:
            s = samples[0]
            jl = s.get('jited_prog_len')
            recomp = s.get('recompile', {})
            execs = [s2.get('exec_ns') for s2 in samples]
            median = sorted(execs)[len(execs)//2]
            print(f"  runtime={run['runtime']}, jited_len={jl}, exec_median={median}ns, applied={recomp.get('applied')}, extract_sites={recomp.get('extract_sites')}, endian_sites={recomp.get('endian_sites')}")
