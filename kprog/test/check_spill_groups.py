"""Catch packed-word aliasing, sparse frame IDs and the 544-to-512 boundary."""
import argparse
import importlib.util
import json
from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def check(args):
    args.build.mkdir(parents=True, exist_ok=True)
    args.output.mkdir(parents=True, exist_ok=True)
    spec = importlib.util.spec_from_file_location('spill_groups', ROOT/'kprog/x86/whole_word_spills.py')
    spills = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(spills)
    prior = subprocess.run(['git', 'show', 'b9dc82ceb:kprog/x86/whole_word_spills.py'],
                           cwd=ROOT, text=True, capture_output=True, check=True).stdout
    namespace = dict(__name__='prior_spills')
    exec(compile(prior, str(ROOT/'kprog/x86/whole_word_spills.py'), 'exec'), namespace)
    parity = []
    for name in ('scalar_spill_values.mir', 'scalar_spill_groups.mir'):
        fixture = ROOT/'kprog/test'/name
        old, old_changes = namespace['automatic'](fixture)
        new, new_changes = spills.automatic(fixture)
        if old != new or old_changes != new_changes:
            raise ValueError('Existing single-pair mode changed: '+name)
        parity.append(dict(fixture=name, default_equals_prior=True))
    commands, cases = [], []

    def run(command, expected=True):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        if (result.returncode == 0) != expected:
            raise ValueError('Unexpected command outcome: '+str(commands[-1]))
        return result

    def depth(obj):
        with obj.open('rb') as stream:
            code = ELFFile(stream).get_section_by_name('socket').data()
        offsets = []
        for index in range(0, len(code), 8):
            opcode, regs, offset, _ = struct.unpack_from('<BBhi', code, index)
            kind, dst, src = opcode & 7, regs & 15, regs >> 4
            if (kind == 3 and dst == 10) or (kind == 1 and src == 10):
                offsets.append(-offset)
        return max(offsets)

    base = (ROOT/'kprog/test/scalar_spill_groups.mir').read_text()
    for large in (False, True):
        for packed in (False, True):
            label = ('large' if large else 'small')+('-packed' if packed else '-original')
            source = base
            if large:
                source = source.replace('id: 9, name: \'\', type: default, offset: 0, size: 8,',
                                        'id: 9, name: \'\', type: default, offset: 0, size: 472,')
                source = source.replace('%stack.9, 4', '%stack.9, 468')
            mir = args.build/'fixture.mir'
            mir.write_text(source)
            pairs = []
            if packed:
                source, pairs = spills.automatic(mir, all_scalar_pairs=True)
                if [(r['low'],r['high']) for r in pairs] != [(6,7),(4,5),(2,3),(0,1)]:
                    raise ValueError('Four independent scalar pairs were not selected')
                mir.write_text(source)
            obj = args.build/'fixture.o'
            run(['llc-18', '-O3', '-march=bpf', '-mcpu=v4', '-bpf-stack-size=4096', '-verify-machineinstrs',
                 '-start-before=prologepilog', '-filetype=obj', mir, '-o', obj])
            actual_depth = depth(obj)
            expected_depth = (512 if packed else 544) if large else (48 if packed else 80)
            if actual_depth != expected_depth:
                raise ValueError(f'{label}: frame {actual_depth}, expected {expected_depth}')
            row = dict(phase=label, frame_access_depth=actual_depth, pairs=len(pairs))
            if not args.compile_only:
                result = run([args.build/'values-client', '--groups', label, obj], expected=not (large and not packed))
                if large and not packed:
                    if 'invalid write to stack' not in result.stderr:
                        raise ValueError('Large original rejected for an unrelated reason')
                    row.update(stock_rejected=True, executions=0)
                else:
                    execution = json.loads(result.stdout)
                    if execution['failed'] or execution['executions'] != 1060:
                        raise ValueError('Real packed-word executions did not match the independent reference')
                    row.update(execution)
            cases.append(row)
            (args.output/'cases.json').write_text(json.dumps(cases, indent=2)+'\n')
    pressure = ROOT/'kprog/test/scalar_spill_pressure.mir'
    for packed in (False, True):
        label = 'pressure-packed' if packed else 'pressure-original'
        source = pressure.read_text()
        if packed:
            source, pairs = spills.automatic(pressure, all_scalar_pairs=True)
            if not any(c.get('reuses_dead_source') for p in pairs for c in p['changes']):
                raise ValueError('Pressure fixture did not exercise dead-source reuse')
        mir = args.build/'fixture.mir'
        mir.write_text(source)
        obj = args.build/'fixture.o'
        run(['llc-18', '-O3', '-march=bpf', '-mcpu=v4', '-verify-machineinstrs',
             '-start-before=prologepilog', '-filetype=obj', mir, '-o', obj])
        actual_depth = depth(obj)
        if actual_depth != (8 if packed else 16):
            raise ValueError('Pressure fixture frame layout changed unexpectedly')
        row = dict(phase=label, frame_access_depth=actual_depth)
        if not args.compile_only:
            result = run([args.build/'values-client', '--pressure', label, obj])
            execution = json.loads(result.stdout)
            if execution['failed'] or execution['executions'] != 1060:
                raise ValueError('Dead-source reuse changed live registers or values')
            row.update(execution)
        cases.append(row)
        (args.output/'cases.json').write_text(json.dumps(cases, indent=2)+'\n')
    for name, option, saved_count in [('scalar_spill_pressure_ctx.mir','--pressure-context',1),
                                      ('scalar_spill_pressure_all.mir','--pressure-all-live',2)]:
        fixture = ROOT/'kprog/test'/name
        for packed in (False, True):
            label = option[2:]+('-packed' if packed else '-original')
            source = fixture.read_text()
            if packed:
                source, pairs = spills.automatic(fixture, all_scalar_pairs=True)
                if max(len(c.get('saved_live_registers', [])) for p in pairs for c in p['changes']) != saved_count:
                    raise ValueError('Live scratch preservation was not exercised')
            mir = args.build/'fixture.mir'
            mir.write_text(source)
            obj = args.build/'fixture.o'
            run(['llc-18', '-O3', '-march=bpf', '-mcpu=v4', '-verify-machineinstrs',
                 '-start-before=prologepilog', '-filetype=obj', mir, '-o', obj])
            actual_depth = depth(obj)
            expected_depth = 8+saved_count*8 if packed else 16
            if actual_depth != expected_depth:
                raise ValueError('Live scratch frame layout differs')
            row = dict(phase=label, frame_access_depth=actual_depth)
            if not args.compile_only:
                result = run([args.build/'values-client', option, label, obj])
                execution = json.loads(result.stdout)
                if execution['failed'] or execution['executions'] != 1060:
                    raise ValueError('Saved live register or context pointer changed')
                row.update(execution)
            cases.append(row)
            (args.output/'cases.json').write_text(json.dumps(cases, indent=2)+'\n')
    (args.output/'result.json').write_text(json.dumps(dict(compile_only=args.compile_only,
        default_parity=parity, cases=cases), indent=2)+'\n')
    print(json.dumps(cases))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build','output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--compile-only', action='store_true')
    check(parser.parse_args())
