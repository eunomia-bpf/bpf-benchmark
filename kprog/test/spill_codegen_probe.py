"""Compare BPF backend spill demand on one retained, immutable bounds IR."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import time


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('bitcode', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--optimization', choices=['O2', 'O3'], default='O3')
    parser.add_argument('--allocator-probes', action='store_true')
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    cases = [('default', []), ('deferred', ['-enable-deferred-spilling']),
             ('reverse', ['-greedy-reverse-local-assignment']),
             ('both', ['-enable-deferred-spilling', '-greedy-reverse-local-assignment'])]
    if args.allocator_probes:
        cases = [('basic', ['-regalloc=basic']), ('split_size', ['-split-spill-mode=size']),
                 ('rematerialize', ['-regalloc-cheap-remat-weight=0']),
                 ('no_loop_iv', ['-enable-split-loopiv-heuristic=false'])]
    results = []
    for name, flags in cases:
        output = args.output / (name + '.mir')
        command = ['/workspaces/repository/kprog/stock-path/bin/clang', '-w', '-g', '-' + args.optimization,
                   '-mcpu=v4', '-target', 'bpf', '-mllvm', '-bpf-stack-size=4096',
                   '-mllvm', '-stop-after=prologepilog']
        for flag in flags:
            command += ['-mllvm', flag]
        command += ['-c', str(args.bitcode), '-o', str(output)]
        start = time.monotonic()
        with (args.output / (name + '.stderr')).open('w') as log:
            process = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT)
        result = dict(name=name, command=command, exit=process.returncode,
                      wall_seconds=time.monotonic() - start)
        if process.returncode == 0:
            text = output.read_text()
            result['stack_sizes'] = list(map(int, re.findall(r'stackSize:\s+(\d+)', text)))
            result['mir_sha256'] = hashlib.sha256(text.encode()).hexdigest()
        results.append(result)
        (args.output / 'results.json').write_text(json.dumps(dict(
            input=str(args.bitcode), input_sha256=hashlib.sha256(args.bitcode.read_bytes()).hexdigest(),
            scope='B compiler diagnostic, no P flags changed; stock acceptance not implied.',
            cases=results), indent=2) + '\n')
        print(json.dumps(result), flush=True)
        process.check_returncode()
