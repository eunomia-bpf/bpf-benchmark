#!/usr/bin/env python3
"""Replay a retained Cilium BPF compile using unchanged canonical upstream source."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--capture', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    record = json.loads((args.capture/'parity.json').read_text())
    repo = Path(__file__).resolve().parents[3]
    upstream = repo/'vendor/repos/cilium/bpf'
    original = record['bpf_command']
    command = ['clang-18']
    sources = []
    i = 1
    while i < len(original):
        flag = original[i]
        if flag == '-o':
            command += ['-o', str(args.output.with_suffix('.bc'))]
            i += 2
            continue
        if flag.startswith('-I/var/lib/cilium/bpf'):
            flag = '-I'+str(upstream)+flag[len('-I/var/lib/cilium/bpf'):]
        elif flag.startswith('-I/var/tmp/'):
            # These are retained generated configuration data, not app headers.
            flag = '-I'+str(args.capture/'live-headers')
        elif flag.startswith('/var/lib/cilium/bpf/') and flag.endswith('.c'):
            path = upstream/flag[len('/var/lib/cilium/bpf/'):]
            sources.append(dict(path=str(path), sha256=hashlib.sha256(path.read_bytes()).hexdigest()))
            flag = str(path)
        command.append(flag)
        i += 1
    command.append('-emit-llvm')
    args.output.parent.mkdir(parents=True, exist_ok=True)
    receipt = dict(capture=str(args.capture), original_command=original,
                   replay_command=command, sources=sources,
                   configuration=[dict(path=str(args.capture/h['archive']),
                                       retained_sha256=h['sha256'],
                                       replay_path=str(args.capture/'live-headers'/Path(h['source']).name),
                                       replay_sha256=hashlib.sha256((args.capture/'live-headers'/Path(h['source']).name).read_bytes()).hexdigest())
                                  for h in record['headers']])
    result = subprocess.run(command, capture_output=True, text=True)
    args.output.with_suffix('.stdout').write_text(result.stdout)
    args.output.with_suffix('.stderr').write_text(result.stderr)
    receipt['returncode'] = result.returncode
    args.output.with_suffix('.json').write_text(json.dumps(receipt, indent=2)+'\n')
    result.check_returncode()


if __name__ == '__main__':
    main()
