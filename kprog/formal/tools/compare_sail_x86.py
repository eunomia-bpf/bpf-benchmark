#!/usr/bin/env python3
"""Compare per-instruction register/flag/PC observations with the upstream Sail x86 model."""
from pathlib import Path
import struct, subprocess, json, re, gzip, hashlib, argparse
import base64
from collections import Counter

def main():
    ROOT = Path(__file__).resolve().parent.parent
    parser = argparse.ArgumentParser(description='Compare native instruction units in Lean and the ACL2-derived Sail x86 model')
    source = parser.add_mutually_exclusive_group(required=True)
    source.add_argument('--model', type=Path)
    source.add_argument('--archive', type=Path, help='Replay fresh reference against pinned archived Sail observations')
    parser.add_argument('--receipt', type=Path, default=ROOT.parent/'results/kprog_verification_20261107/reference-x86-sail.json')
    parser.add_argument('--historical-archive', type=Path, default=ROOT.parent/'results/kprog_verification_20261107/arm64-xdp-host-integration.log.gz')
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--reference', type=Path, default=ROOT / '.lake/build/bin/reference')
    args = parser.parse_args()
    if args.archive is not None:
        return replay_archive(args)
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    model = args.model.resolve()
    ref = args.reference.resolve()
    names = ['rax', 'rcx', 'rdx', 'rbx', 'rsp', 'rbp', 'rsi', 'rdi'] + ['r' + str(i) for i in range(8, 16)]
    forms = []

    def add(op, asm):
        forms.append((op, asm))
    add('NOP', 'nop')
    for w, a, b in [(8, 'al', 'bl'), (16, 'ax', 'bx'), (32, 'eax', 'ebx'), (64, 'rax', 'rbx')]:
        for op, asm in [('MOV_IMM', f'mov {a},7'), ('MOV_REG', f'mov {a},{b}'), ('ADD_IMM', f'add {a},7'), ('ADD_REG', f'add {a},{b}'), ('XOR_REG', f'xor {a},{b}'), ('CMP_IMM', f'cmp {a},7'), ('CMP_REG', f'cmp {a},{b}'), ('TEST_IMM', f'test {a},7'), ('TEST_REG', f'test {a},{b}'), ('XCHG', f'xchg {a},{b}'), ('DIV', f'div {b}')]:
            add(op, asm)
        for insn in ['adc', 'sub', 'sbb', 'and', 'or', 'xor']:
            add('ALU_IMM', f'{insn} {a},7')
            add('ALU_REG', f'{insn} {a},{b}')
        if w >= 16:
            for op, asm in [('CMOV', f'cmovb {a},{b}'), ('POPCNT', f'popcnt {a},{b}'), ('SHLD_IMM', f'shld {a},{b},7'), ('SHRD_IMM', f'shrd {a},{b},7'), ('BT', f'bt {a},{b}'), ('BT_IMM', f'bt {a},7'), ('IMUL_IMM', f'imul {a},{b},7'), ('ROR', f'ror {a},7')]:
                add(op, asm)
        if w >= 32:
            add('BSWAP', f'bswap {a}')
            count = 'ecx' if w == 32 else 'rcx'
            for insn in ['shlx', 'shrx', 'sarx']:
                add('SHIFTX', f'{insn} {a},{b},{count}')
            add('RORX', f'rorx {a},{b},7')
            add('BZHI', f'bzhi {a},{b},{count}')
            add('ANDN', f'andn {a},{b},{count}')
            add('MULX', f'mulx {a},{count},{b}')
    for op, asm in [('MOVZX_REG', 'movzx eax,bl'), ('MOVZX_REG', 'movzx eax,bx'), ('MOVSX_REG', 'movsx rax,bl'), ('MOVSX_REG', 'movsx rax,bx'), ('MOVSX_REG', 'movsxd rax,ebx'), ('SETCC', 'setb al'), ('SETCC', 'setl al'), ('LEA', 'lea rax,[rbx+rcx*4+17]')]:
        add(op, asm)
    vectors = [(0, 1), (1, 3), ((1 << 64) - 1, 1), ((1 << 63) - 1, 1), (1 << 63, (1 << 64) - 1), (1311768467139281697, 18364758545390235393)]
    results = []
    base = 4096
    for n, (op, asm) in enumerate(forms):
        source = out / f'form-{n}.s'
        source.write_text('.intel_syntax noprefix\n.text\n.global _start\n_start:\n' + asm + '\n')
        obj = source.with_suffix('.o')
        raw = source.with_suffix('.bin')
        subprocess.run(['as', '--64', str(source), '-o', str(obj)], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.PIPE)
        subprocess.run(['objcopy', '-O', 'binary', '-j', '.text', str(obj), str(raw)], check=True)
        code = raw.read_bytes()
        header = struct.pack('<16sHHIQQQIHHHHHH', b'\x7fELF' + bytes([2, 1, 1]) + bytes(9), 2, 62, 1, base, 64, 0, 0, 64, 56, 1, 0, 0, 0)
        ph = struct.pack('<IIQQQQQQ', 1, 5, 4096, base, base, len(code), len(code), 4096)
        elf = header + ph
        elf += bytes(4096 - len(elf)) + code
        binary = source.with_suffix('.elf')
        binary.write_bytes(elf)
        for variant, (left, right) in enumerate(vectors):
            for cf in [0, 1]:
                registers = [left, 3, 0, right, 12288, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
                if op == 'DIV':
                    registers[0] = left % 128
                    registers[3] = right | 1
                if op == 'MULX':
                    registers[2] = left
                request = dict(isa='x86_64', native_bytes=list(code), state=dict(registers=registers, flags=2 | cf, pc=base, xmm0=0, fs_base=0, gs_base=0, memory=[]))
                cmd = [str(model), '-e', str(binary)]
                for k, val in [('rip', base), ('ha', base + len(code)), ('rflags', 2 | cf), ('cr4', 512), ('set64bit', 1), ('app_view', 1), *zip(names, registers)]:
                    cmd += ['-C', k + '=' + hex(val)]
                modelrun = subprocess.run(cmd, text=True, capture_output=True)
                leanrun = subprocess.run([str(ref)], input=json.dumps(request) + '\n', text=True, capture_output=True)
                logname = f'form-{n}-{variant}-{cf}.log.gz'
                (out / logname).write_bytes(gzip.compress((modelrun.stdout + modelrun.stderr).encode(), mtime=0))
                values = {k: int(h, 16) for k, h in re.findall('^(\\w+) = 0x([0-9a-fA-F]+)$', modelrun.stdout, re.M)}
                row = dict(operation='X86_OP_' + op, assembly=asm, native_bytes=list(code), variant=variant, carry=cf, request=request, model_exit=modelrun.returncode, lean_exit=leanrun.returncode, model_log=logname, lean_stdout=leanrun.stdout, lean_stderr=leanrun.stderr)
                if leanrun.returncode:
                    row.update(status='lean-domain', error=leanrun.stderr)
                elif modelrun.returncode or not all((k in values for k in names + ['rflags', 'rip'])) or (not re.search('^Steps = 1$', modelrun.stdout, re.M)):
                    row.update(status='model-stopped', error=(modelrun.stdout + modelrun.stderr)[-1000:])
                else:
                    expected = json.loads(leanrun.stdout)
                    actual = dict(registers=[values[k] for k in names], flags=values['rflags'], pc=values['rip'])
                    masks = expected.get('defined_registers', [(1 << 64) - 1] * 16)
                    good = expected['fault'] is None and actual['pc'] == expected['pc'] and all(((a ^ b) & mask == 0 for a, b, mask in zip(actual['registers'], expected['registers'], masks))) and ((actual['flags'] ^ expected['flags']) & expected['defined_flags'] == 0)
                    row.update(status='agree' if good else 'difference', model=actual, lean=expected)
                results.append(row)
        with (out / 'cases.jsonl').open('w') as f:
            for row in results:
                f.write(json.dumps(row, sort_keys=True) + '\n')
        print(n, op, asm, results[-1]['status'], flush=True)
    summary = {s: sum((x['status'] == s for x in results)) for s in sorted({x['status'] for x in results})}
    (out / 'summary.json').write_text(json.dumps(dict(forms=len(forms), cases=len(results), statuses=summary, model_sha256=hashlib.sha256(model.read_bytes()).hexdigest(), lean_sha256=hashlib.sha256(ref.read_bytes()).hexdigest()), indent=2) + '\n')
    print('COMPARISON COMPLETE', summary, flush=True)
    raise SystemExit(0 if all((row['status'] == 'agree' for row in results)) else 1)


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def archived_rows(archive, name, expected):
    found = None
    with gzip.open(archive, 'rt') as stream:
        for line in stream:
            # The older archive also contains human-readable reports and markers.
            if not line.startswith('{'):
                continue
            try:
                entry = json.loads(line)
            except json.JSONDecodeError:
                continue
            if entry.get('path') != name:
                continue
            if found is not None:
                raise ValueError(f'duplicate Sail cohort: {name}')
            data = base64.b64decode(entry['base64'], validate=True)
            identity = (len(data), hashlib.sha256(data).hexdigest())
            if identity != expected or identity != (entry['bytes'], entry['sha256']):
                raise ValueError(f'Sail cohort checksum mismatch: {name}')
            found = [json.loads(row) for row in data.splitlines() if row]
    if not found:
        raise ValueError(f'absent or empty Sail cohort: {name}')
    return found


def byte_accesses(output):
    accesses = []
    for event in output['events']:
        if event['kind'] not in ('read', 'write'):
            raise ValueError(f'unexpected flat Sail comparison event: {event}')
        kind = 'R' if event['kind'] == 'read' else 'W'
        accesses.extend([[kind, (event['address']+i) % (1 << 64), byte]
                         for i, byte in enumerate(event['value'])])
    return accesses


def same_observation(output, oracle, request, trace=None):
    registers = output.get('defined_registers', [(1 << 64)-1]*16)
    if len(output['registers']) != 16 or len(oracle['registers']) != 16 or len(registers) != 16:
        raise ValueError('incomplete Sail/reference register bank')
    good = (output['fault'] is None and output['pc'] == oracle['pc'] and
            all((actual ^ want) & mask == 0 for actual, want, mask in
                zip(output['registers'], oracle['registers'], registers)) and
            (output['flags'] ^ oracle['flags']) & output['defined_flags'] == 0)
    cells = request['state']['memory']
    if 'memory_values' in oracle:
        if len(oracle['memory_values']) != len(cells):
            raise ValueError('incomplete Sail mapped memory observation')
        good &= ([cell['address'] for cell in output['memory']] == [cell['address'] for cell in cells] and
                 [cell['value'] for cell in output['memory']] == oracle['memory_values'])
    elif cells:
        raise ValueError('Sail cohort is missing mapped memory observations')
    if trace is not None:
        good &= byte_accesses(output) == trace
    return bool(good)


def retained_whole_rep(output, row):
    # This is a recorded disagreement, never an agreement with a fabricated Sail
    # completion. The pinned Sail F3/ZF behavior and all raw logs stay visible.
    if row['status'] != 'difference' or row['operation'] != 'X86_OP_REP_MOVS':
        return False
    previous = row['lean']
    oracle = dict(registers=previous['registers'], flags=previous['flags'], pc=previous['pc'],
                  memory_values=[cell['value'] for cell in previous['memory']])
    return same_observation(output, oracle, row['request'], row['canonical_data_accesses'])


def replay_archive(args):
    root = Path(__file__).resolve().parents[1]
    receipt = json.loads(args.receipt.read_text())
    fixed = 'reference-x86-memory-fixed/cases.jsonl'
    manifest = next(entry for entry in receipt['archive']['entries'] if entry['path'] == fixed)
    # Independently pinned to the checked-in receipt, including the selected old
    # register epoch (not the failed/replaced first memory collector).
    fixed_identity = (323150844, 'dfc44dfe84fde554542eafcbd8aba7a5807c99a9556b54777107fc76d5b92c58')
    if (manifest['bytes'], manifest['sha256']) != fixed_identity:
        raise ValueError('unexpected fixed Sail cohort in receipt')
    historical = 'comparison/cases.jsonl'
    historical_identity = (1804202, '3b5cca313ab86c2c70ff56e410225c97420b5a2d837bfa084a3f3ec1ad7113d7')
    cohorts = [(args.historical_archive, historical, historical_identity, 1692),
               (args.archive, fixed, fixed_identity, 3360)]
    archives = {str(path.resolve()): digest(path) for path, _, _, _ in cohorts}
    if archives[str(args.archive.resolve())] != receipt['archive']['sha256']:
        raise ValueError('Sail memory archive differs from committed receipt')
    reference = args.reference.resolve()
    before = digest(reference)
    args.output.mkdir(parents=True, exist_ok=False)
    statuses, per_cohort, operations = Counter(), {}, {}
    with (args.output/'cases.jsonl').open('w') as stream:
        for archive, name, identity, expected_count in cohorts:
            rows = archived_rows(archive, name, identity)
            if len(rows) != expected_count:
                raise ValueError(f'incomplete Sail cohort: {name}')
            counts = Counter()
            for index, row in enumerate(rows):
                run = subprocess.run([str(reference)], input=json.dumps(row['request'])+'\n',
                                     text=True, capture_output=True)
                result = dict(cohort=name, case=index, payload_sha256=identity[1],
                    operation=row['operation'], assembly=row['assembly'], request=row['request'],
                    retained_status=row['status'], retained_model_log=row['model_log'],
                    retained_model_exit=row['model_exit'], retained_model_error=row.get('error'),
                    reference_exit=run.returncode, reference_stdout=run.stdout,
                    reference_stderr=run.stderr)
                if run.returncode:
                    status = 'reference-error'
                else:
                    output = json.loads(run.stdout)
                    result['reference'] = output
                    if row['status'] == 'model-stopped':
                        status = 'model-stopped'
                    else:
                        if row['model_exit'] or row.get('lean_exit'):
                            raise ValueError('retained comparison has an unsuccessful execution')
                        previous = row['lean']
                        if (output['defined_flags'] != previous['defined_flags'] or
                            output.get('defined_registers', [(1 << 64)-1]*16) !=
                            previous.get('defined_registers', [(1 << 64)-1]*16)):
                            status = 'observation-mask-changed'
                        elif same_observation(output, row['model'], row['request'], row.get('model_data_accesses')):
                            status = 'agree'
                        elif retained_whole_rep(output, row):
                            status = 'recorded-rep-difference'
                        else:
                            status = 'difference'
                        result.update(oracle=row['model'], oracle_accesses=row.get('model_data_accesses'))
                result['status'] = status
                stream.write(json.dumps(result, sort_keys=True)+'\n')
                stream.flush()
                statuses[status] += 1
                counts[status] += 1
                operations.setdefault(row['operation'], Counter())[status] += 1
            per_cohort[name] = dict(cases=len(rows), bytes=identity[0], sha256=identity[1], statuses=dict(counts))
            print(name, dict(counts), flush=True)
    after = digest(reference)
    if before != after:
        raise ValueError('reference executable changed during the comparison')
    source_paths = ['ReferenceMain.lean', 'KProgFormal/Reference/X86.lean',
                    'KProgFormal/Reference/Memory.lean', 'external/x86lean/X86/Semantics.lean',
                    'external/x86lean/X86/CheckedMemory.lean']
    summary = dict(mode='fresh x86lean versus pinned archived Sail observations; no live Sail rerun',
        cases=sum(statuses.values()), statuses=dict(statuses), cohorts=per_cohort, operations=operations,
        archives=archives, receipt_sha256=digest(args.receipt), reference_sha256=before,
        recorded_model_sha256=receipt['source_pins']['model'],
        recorded_sail_commit=receipt['historical_register_model']['commit'],
        scope='All16 GPRs,PC,defined RFLAGS; fixed cohort all512 mapped bytes and ordered data-byte read/write values. SIMD/system/permissions and complete REP execution remain separate comparisons.',
        source_sha256={name: digest(root/name) for name in source_paths},
        x86lean_commit=subprocess.check_output(['git','-C',str(root/'external/x86lean'),'rev-parse','HEAD'],text=True).strip())
    (args.output/'summary.json').write_text(json.dumps(summary, indent=2)+'\n')
    print('SAIL ARCHIVE COMPARISON', dict(statuses), flush=True)
    return 0 if set(statuses) <= {'agree', 'model-stopped', 'recorded-rep-difference'} else 1

if __name__ == '__main__':
    raise SystemExit(main())
