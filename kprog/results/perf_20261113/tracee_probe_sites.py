"""Locate sampled probe-read return sites in the actual captured program IDs."""
import argparse
import bisect
from collections import Counter, defaultdict
from datetime import datetime, timezone
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT/'kprog/perf/profile'))
import symbolize


def analyse(args, phase, program_id):
    census = json.loads((args.capture/(phase+'.jit-lines.json')).read_text())
    target = next(p for p in census['programs'] if p['id'] == program_id)
    ranges = sorted((f['address'], f['address']+f['length'], p['id'])
                    for p in census['programs'] for f in p['functions'])
    starts = [r[0] for r in ranges]
    addresses, names, _ = symbolize.load_kallsyms(args.capture/(phase+'.kallsyms'))

    def program(ip):
        index = bisect.bisect_right(starts, ip)-1
        return ranges[index] if index >= 0 and ip < ranges[index][1] else None

    def symbol(ip):
        index = bisect.bisect_right(addresses, ip)-1
        return names[index] if index >= 0 else None

    samples, target_any, target_inner, target_outer = 0, 0, 0, 0
    sites = defaultdict(lambda: dict(samples=0, zero_fill_leaf_samples=0, leaves=Counter()))
    zero_fill = {'memset', '__memset', 'memset_erms', '__memset_erms'}

    def sample(ips):
        nonlocal samples, target_any, target_inner, target_outer
        if not ips:
            return
        samples += 1
        frames = [(i, hit) for i, ip in enumerate(ips) if (hit := program(ip)) is not None]
        if not any(hit[2] == program_id for _, hit in frames):
            return
        target_any += 1
        # perf script callchains are leaf first; the FIRST program frame is
        # the immediate program caller. Keep outer-only samples separately.
        index, hit = frames[0]
        if hit[2] != program_id:
            target_outer += 1
            return
        target_inner += 1
        helper = symbol(ips[index-1]) if index else None
        if helper is None or 'bpf_probe_read' not in helper:
            return
        leaf = symbol(ips[0])
        key = (hit[0], ips[index]-hit[0], helper)
        row = sites[key]
        row['samples'] += 1
        row['zero_fill_leaf_samples'] += int(leaf in zero_fill)
        row['leaves'][leaf] += 1

    command = [str(args.perf), 'script', '-i', str(args.capture/(phase+'.data')),
               '-F', 'ip', '--no-inline']
    stderr = args.output/(phase+'.perf-script.stderr')
    with stderr.open('w') as errors:
        process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=errors, text=True)
        ips = []
        for line in process.stdout:
            if line.strip():
                ips.append(int(line.strip(), 16))
            else:
                sample(ips)
                ips = []
        sample(ips)
        status = process.wait()
    if status:
        raise subprocess.CalledProcessError(status, command)

    instructions = []
    for function in target['functions']:
        command_disasm = ['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel', '--insn-width=16',
                          '--adjust-vma='+hex(function['address']), str(args.capture/target['binary'])]
        decoded = subprocess.run(command_disasm, text=True, capture_output=True, check=True)
        (args.output/(phase+'.disassembly.txt')).write_text(decoded.stdout)
        for line in decoded.stdout.splitlines():
            address, separator, _ = line.partition(':')
            if separator:
                try:
                    ip = int(address.strip(), 16)
                except ValueError:
                    continue
                instructions.append((ip, line))
    offsets = [i[0] for i in instructions]
    observations = []
    for (base, offset, helper), row in sorted(sites.items(), key=lambda item: item[1]['zero_fill_leaf_samples'], reverse=True):
        ip = base+offset
        end = bisect.bisect_left(offsets, ip)
        observations.append(dict(function_base=hex(base), return_offset=hex(offset), return_ip=hex(ip),
            return_is_instruction_boundary=end < len(offsets) and offsets[end] == ip, helper=helper,
            samples=row['samples'], zero_fill_leaf_samples=row['zero_fill_leaf_samples'],
            leaves=dict(row['leaves']), instructions_before_return=[line for _, line in instructions[max(0,end-14):end]]))
    result = dict(recorded=datetime.now(timezone.utc).isoformat(), phase=phase, program_id=program_id,
        program={key: target.get(key) for key in ('id','name','tag','jited_bytes','binary','source_status','functions')},
        perf_command=command, samples=samples, target_in_any_frame_samples=target_any,
        target_innermost_samples=target_inner, target_outer_only_samples=target_outer,
        probe_path_samples=sum(r['samples'] for r in observations),
        zero_fill_leaf_samples=sum(r['zero_fill_leaf_samples'] for r in observations), sites=observations,
        scope='Existing captured IP samples; time-weighted samples, not helper invocation or failure counts')
    (args.output/(phase+'.json')).write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps({key: value for key, value in result.items() if key not in ('sites','program','perf_command')}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('capture','output','perf'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--baseline-id', type=int, required=True)
    parser.add_argument('--native-id', type=int, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    analyse(args, 'baseline', args.baseline_id)
    analyse(args, 'post_rejit', args.native_id)
