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
                source, pairs = spills.automatic(mir)
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
            source, pairs = spills.automatic(pressure)
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
                source, pairs = spills.automatic(fixture)
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
    # LLVM can reserve8 bytes for a slot whose entire use is STW32/LDW32.
    # Catch missing compaction while retaining genuine64-bit/escaping storage.
    wide = base.replace('size: 4, alignment: 8,', 'size: 8, alignment: 8,')
    normalized, selected = spills.narrow_scalar_storage(wide)
    if selected != list(range(8)):
        raise ValueError('Wide scalar descriptors or the genuine64-bit slot were misclassified')
    for variant in [
        wide.replace('STW32 $w2, %stack.0, 0', 'STD $r2, %stack.0, 0'),
        wide.replace('LDW32 %stack.0, 0', 'LDW32 %stack.0, 4'),
        wide.replace('    RET implicit $r0',
                     '    $r4 = FI_ri %stack.0, 0\n    RET implicit $r0'),
    ]:
        _, selected = spills.narrow_scalar_storage(variant)
        if 0 in selected:
            raise ValueError('Wide/offset/escaping access lost its original spill allocation')
    mir = args.build/'fixture.mir'
    mir.write_text(wide)
    normalizations = []
    lowered, pairs = spills.automatic(mir, normalizations)
    if normalizations != [dict(document=1, slots=list(range(8)))]:
        raise ValueError('Normal route omitted the wide scalar spill normalization')
    mir.write_text(lowered)
    obj = args.build/'fixture.o'
    run(['llc-18', '-O3', '-march=bpf', '-mcpu=v4', '-verify-machineinstrs',
         '-start-before=prologepilog', '-filetype=obj', mir, '-o', obj])
    actual_depth = depth(obj)
    if actual_depth != 48:
        raise ValueError('Wide scalar declarations still waste aligned stack words')
    row = dict(phase='wide-descriptor-packed', frame_access_depth=actual_depth,
               normalized_slots=normalizations)
    if not args.compile_only:
        execution = json.loads(run([args.build/'values-client', '--groups',
                                    'wide-descriptor-packed', obj]).stdout)
        if execution['failed'] or execution['executions'] != 1060:
            raise ValueError('Narrowing the unread upper half changed packed execution')
        row.update(execution)
    cases.append(row)
    # Real OTel MIR annotates a scalar reload's unused definition with `dead`.
    # It is still a definition for scratch liveness, and a supported reload.
    mir = args.build/'fixture.mir'
    mir.write_text(base.replace('    RET implicit $r0',
        '    dead $w2 = LDW32 %stack.7, 0\n    RET implicit $r0'))
    lowered, pairs = spills.automatic(mir)
    if not any('dead $w2 = LDW32' in change['original'] for pair in pairs for change in pair['changes']):
        raise ValueError('Dead-marked scalar reload was omitted from spill lowering')
    mir.write_text(lowered)
    obj = args.build/'fixture.o'
    run(['llc-18', '-O3', '-march=bpf', '-mcpu=v4', '-verify-machineinstrs',
         '-start-before=prologepilog', '-filetype=obj', mir, '-o', obj])
    row = dict(phase='dead-reload', frame_access_depth=depth(obj))
    if not args.compile_only:
        execution = json.loads(run([args.build/'values-client', '--groups', 'dead-reload', obj]).stdout)
        if execution['failed'] or execution['executions'] != 1060:
            raise ValueError('Dead-marked reload changed the packed-word result')
        row.update(execution)
    cases.append(row)
    (args.output/'result.json').write_text(json.dumps(dict(compile_only=args.compile_only,
        cases=cases), indent=2)+'\n')
    print(json.dumps(cases))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build','output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--compile-only', action='store_true')
    check(parser.parse_args())
