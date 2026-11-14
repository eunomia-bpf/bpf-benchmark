#!/usr/bin/env python3
"""Bind measured guest hardware root IPs to captured program bytes and instructions.

This is sampled root attribution, with hardware skid; a sample after a call is
not proof that the following instruction consumed those cycles. Address-operand
categories describe syntax, not load latency or proven spills. Period sums are
normalized by the measured entry count, never the inlined tail program count.
"""
import argparse
import bisect
from collections import Counter
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import subprocess

_spec = importlib.util.spec_from_file_location('host_costs', Path(__file__).with_name('host-costs.py'))
costs = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(costs)


def instructions(text, start, size):
    rows = []
    for line in text.splitlines():
        match = re.fullmatch(r'\s*([0-9a-f]+):\s+(.+)', line)
        if match:
            address = int(match[1], 16)
            if start <= address < start + size:
                rows.append((address, match[2].strip()))
    if not rows or rows[0][0] != start or any(a[0] >= b[0] for a, b in zip(rows, rows[1:])):
        raise ValueError('incomplete or unordered disassembly')
    return [dict(address=a, end=rows[i+1][0] if i+1 < len(rows) else start+size, asm=asm)
            for i, (a, asm) in enumerate(rows)]


def category(asm):
    mnemonic = asm.split()[0]
    if mnemonic.startswith('call'):
        return 'call'
    if mnemonic.startswith(('ret', 'jmp', 'j')):
        return 'control'
    if mnemonic.startswith(('push', 'pop', 'leave')):
        return 'stack_frame'
    for reg in ('rsp', 'rbp', 'esp', 'ebp'):
        if re.search(r'\(%' + reg + r'[,)]', asm):
            return reg + '_address_operand'
    if '(' in asm and not mnemonic.startswith(('lea', 'nop')):
        return 'other_memory_operand'
    return 'other'


def locate(programs, ip):
    matches = [p for p in programs if p['start'] <= ip < p['end']]
    if len(matches) > 1:
        raise ValueError('overlapping captured program ranges')
    if not matches:
        return None
    p = matches[0]
    i = bisect.bisect_right(p['addresses'], ip) - 1
    row = p['instructions'][i]
    if not row['address'] <= ip < row['end']:
        raise ValueError('sample falls in an undecoded byte range')
    return p, i


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('capture', 'run', 'samples', 'observation', 'profile', 'out'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    args.out.mkdir(parents=True, exist_ok=False)
    samples = costs.parse_samples(args.samples.read_text())
    observation = json.loads(args.observation.read_text())
    appfiles = list((args.run / 'details/apps').glob('*.json'))
    if len(appfiles) != 1:
        raise ValueError('expected one measured app')
    app = json.loads(appfiles[0].read_text())
    host = json.loads((args.profile / 'host.start.clock.json').read_text())
    report = dict(scope=__doc__, phases={})
    for phase in ('baseline', 'post_rejit'):
        windows = [costs.host_window(w, json.loads((args.profile / (phase+'.start.clock.json')).read_text()), host)
                   for w in observation['measurement_intervals'] if w['phase'] == phase]
        dumps = list(args.capture.glob(phase+'-*/*-jit-dump.txt'))
        programs = []
        missing = []
        for dump in sorted(dumps):
            match = re.fullmatch(r'id=(\d+) jited_len=(\d+) address=(0x[0-9a-f]+)\s*', dump.read_text())
            if match is None:
                missing.append(str(dump))
                continue
            ident, size, address = int(match[1]), int(match[2]), int(match[3], 16)
            binary = dump.with_name(f'prog-{ident}-jited.bin')
            if len(binary.read_bytes()) != size:
                raise ValueError('captured length mismatch: ' + str(binary))
            metadata = {p['id']: p for p in json.loads((dump.parent/'programs.json').read_text())}[ident]
            text = subprocess.check_output(['objdump', '-D', '-z', '-w', '--no-show-raw-insn', '-b', 'binary',
                '-m', 'i386:x86-64', f'--adjust-vma={address}', str(binary)], text=True)
            (args.out / f'{phase}-{ident}.asm').write_text(text)
            rows = instructions(text, address, size)
            programs.append(dict(id=ident, name=metadata.get('name'), tag=metadata['tag'],
                start=address, end=address+size, instructions=rows, addresses=[r['address'] for r in rows],
                source=str(binary), sha256=hashlib.sha256(binary.read_bytes()).hexdigest(), samples=Counter(), cycles=Counter(), offsets=Counter()))
        entry = [p for p in app[phase]['bpf'].values() if p['name'].startswith('native_tracer_e')]
        if len(entry) != 1 or entry[0]['run_cnt_delta'] <= 0:
            raise ValueError('missing measured entry count')
        count = entry[0]['run_cnt_delta']
        unknown, modes, pids = Counter(), Counter(), Counter()
        for sample in samples:
            if not any(a <= sample['time_ns'] <= b for a, b in windows):
                continue
            modes[sample['misc']] += 1
            pids[sample['pid']] += 1
            if 'G' not in sample['misc'] or 'g' in sample['misc']:
                continue
            found = locate(programs, sample['ip'])
            if found is None:
                unknown[f"{sample['ip']:x}"] += 1
                continue
            p, i = found
            p['samples'][i] += 1
            p['cycles'][i] += sample['period']
            p['offsets'][sample['ip']-p['start']] += 1
        results = []
        for p in programs:
            cats, catcycles, blocks = Counter(), Counter(), Counter()
            with (args.out/f"{phase}-{p['id']}.tsv").open('w') as out:
                out.write('offset\tbytes\tsamples\tperiod_cycles\tcategory\tprevious_instruction\tinstruction\n')
                for i, row in enumerate(p['instructions']):
                    cat = category(row['asm'])
                    cats[cat] += p['samples'][i]
                    catcycles[cat] += p['cycles'][i]
                    offset = row['address'] - p['start']
                    blocks[offset//64*64] += p['cycles'][i]
                    out.write(f"{offset:x}\t{row['end']-row['address']}\t{p['samples'][i]}\t{p['cycles'][i]}\t{cat}\t"
                              f"{p['instructions'][i-1]['asm'] if i else ''}\t{row['asm']}\n")
            top = [dict(offset=hex(p['instructions'][i]['address']-p['start']), samples=p['samples'][i],
                        cycles=cycles, instruction=p['instructions'][i]['asm'],
                        previous=p['instructions'][i-1]['asm'] if i else None)
                   for i, cycles in p['cycles'].most_common(30)]
            results.append({k: p[k] for k in ('id','name','tag','start','end','source','sha256')} |
                dict(bytes=p['end']-p['start'], samples=sum(p['samples'].values()), cycles=sum(p['cycles'].values()),
                     cycles_per_entry=sum(p['cycles'].values())/count, categories=dict(cats), category_cycles=dict(catcycles),
                     top_instructions=top, top_64byte_blocks=blocks.most_common(20)))
        report['phases'][phase] = dict(entry=entry[0], measurement_host_windows=windows, modes=dict(modes),
            qemu_pids=dict(pids), unavailable_dumps=missing,
            guest_kernel_samples_outside_captured_ranges=sum(unknown.values()),
            outside_ips=dict(unknown.most_common(30)), programs=results)
    (args.out/'report.json').write_text(json.dumps(report, indent=2)+'\n')


if __name__ == '__main__':
    main()
