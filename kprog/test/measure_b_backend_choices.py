"""Diagnose stack pressure on one retained optimized B IR, with ephemeral outputs.

Each choice resumes the same retained IR. A selected B IR compiler starts
from the completed frontend; otherwise the completed bounds IR is used.
This diagnostic never repeats the C frontend or publishes production tools.
"""
import argparse
from collections import Counter
import hashlib
import io
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import tarfile
import time

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT/'kprog/x86'), str(ROOT/'kprog/test')]
import trusted_specializer as worker
from memory_b_pipeline import MemoryPipeline, post_pei_frames
from analyze_spill_lifetimes import analyze as spill_liveness
from whole_word_spills import narrow_scalar_storage
from elftools.elf.elffile import ELFFile

CHOICES = {'normal': [], 'basic': ['-regalloc=basic'], 'pbqp': ['-regalloc=pbqp'],
           'source': ['-misched=source'], 'no-machine-licm': ['-disable-machine-licm'],
           'no-misched': ['-enable-misched=false'],
           'no-slot-sharing': ['-no-stack-slot-sharing']}


def storage_observation(path, fds):
    """Observe IR in memory; retain counts/examples, never a second IR build."""
    command = ['llvm-dis-18', str(path), '-o', '-']
    result = subprocess.run(command, capture_output=True, text=True,
                            pass_fds=tuple(fds), check=True)
    return storage_text_observation(result.stdout, command)


def storage_text_observation(text, command=None):
    lines = text.splitlines()
    definitions = {}
    for line in lines:
        match = re.match(r'\s*(%[-\w.]+) = (.*)', line)
        if match:
            definitions[match[1]] = match[2]
    objects = []
    for line in lines:
        match = re.match(r'\s*(%[-\w.]+) = alloca\b', line)
        if not match:
            continue
        name = match[1]
        operand = re.compile(re.escape(name)+r'(?![-\w.])')
        uses = [item.strip() for item in lines if item != line and operand.search(item)]
        operations = Counter(re.sub(r'^%[-\w.]+ = ', '', item).split()[0] for item in uses)
        dynamic_geps = []
        for item in uses:
            if 'getelementptr' not in item:
                continue
            # Operand definitions expose what prevents constant slot addressing.
            indices = re.findall(r'\bi(?:32|64) (%[-\w.]+)', item)
            if indices:
                dynamic_geps.append(dict(instruction=item,
                    index_definitions={index:definitions[index] for index in indices}))
        objects.append(dict(name=name, declaration=line.strip(), direct_uses=len(uses),
            direct_operations=dict(operations), examples=uses[:12],
            dynamic_gep_count=len(dynamic_geps), dynamic_gep_examples=dynamic_geps[:8],
            other_use_examples=[item for item in uses
                                if 'getelementptr' not in item][:12]))
    return dict(command=command, allocas=objects,
                scope='Direct textual operand observations, not alias/escape proofs or a transformation.')


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    with tarfile.open(a.archive) as outer:
        with tarfile.open(fileobj=outer.extractfile(a.member)) as request:
            retained_member = 'request/generated/trusted_x86.bpf.bounds-input.bc' if a.bounds else 'request/generated/trusted_x86.bpf.bounds.bc'
            lowered = request.extractfile(retained_member).read()
            entry = request.extractfile('request/kernel.entry').read().decode().strip()
    observation = dict(archive=str(a.archive), member=a.member, entry=entry,
        retained_ir_member=retained_member, input_bytes=len(lowered),
        input_sha256=hashlib.sha256(lowered).hexdigest(),
        bounds_compiler=str(a.bounds) if a.bounds else None,
        bounds_compiler_sha256=hashlib.sha256(a.bounds.read_bytes()).hexdigest() if a.bounds else None,
        compile_flags=list(map(str, worker.COMPILE_FLAGS)), scope=__doc__, cases=[])
    for name in a.case or CHOICES:
        pipe = MemoryPipeline()
        case = dict(name=name, flags=CHOICES[name], completed=False, commands=[])
        directory = a.output/name
        directory.mkdir(exist_ok=True)
        try:
            initial = pipe.stage('.bounds-input.bc' if a.bounds else '.bounds.bc')
            initial.write_bytes(lowered)
            def run(command):
                command = list(map(str, command))
                if command[0].endswith('/clang'):
                    extra = [word for option in CHOICES[name] for word in ('-mllvm', option)]
                    command[1:1] = ['-x', 'ir', *extra]
                elif command[0] == 'llc-18':
                    command[1:1] = ['-x=mir']
                elif command[1] == str(ROOT/'kprog/x86/whole_word_spills.py'):
                    command.extend(['--report', str(directory/'lowering.json')])
                started = time.monotonic()
                with (directory/f'command-{len(case["commands"])}.log').open('w') as log:
                    child = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT, pass_fds=tuple(pipe.fds))
                    _, status, usage = os.wait4(child.pid, 0)
                    child.returncode = os.waitstatus_to_exitcode(status)
                case['commands'].append(dict(command=command, returncode=child.returncode,
                    wall_seconds=time.monotonic()-started, user_seconds=usage.ru_utime,
                    system_seconds=usage.ru_stime, max_rss_kib=usage.ru_maxrss))
                (directory/'result.json').write_text(json.dumps(case, indent=2)+'\n')
                if child.returncode:
                    raise subprocess.CalledProcessError(child.returncode, command)
            obj = pipe.stage('.o')
            if a.bounds:
                prepared = pipe.stage('.bounds.bc')
                run([a.bounds, initial, '-o', prepared])
                initial = prepared
            case['ir_storage'] = storage_observation(initial, pipe.fds)
            worker._compile_simulator_backend(str(ROOT/'kprog/stock-path/bin/clang'),
                pipe, obj, run, compiled_input=initial)
            before = pipe.stage('.before.mir').read_text()
            normalized_documents = []
            for document in before.split('\n---\n'):
                if 'body:             |' in document:
                    document, _ = narrow_scalar_storage(document)
                normalized_documents.append(document)
            narrow = pipe.stage('.scalar-shapes.mir')
            narrow.write_text('\n---\n'.join(normalized_documents))
            case['narrow_scalar_liveness'] = spill_liveness(narrow)
            embedded = before.split('\n---\n', 1)[0]
            if not embedded.startswith('--- |\n'):
                raise ValueError('Expected the actual optimized LLVM IR embedded in MIR')
            optimized = '\n'.join(line.removeprefix('  ')
                                   for line in embedded.removeprefix('--- |\n').splitlines())
            case['optimized_ir_storage'] = storage_text_observation(optimized)
            slots = re.findall(r'  - \{ id: (\d+),[^\n]*type: spill-slot,[^\n]*size: (\d+),', before)
            case['spill_slots_before_packing'] = len(slots)
            spill_ids = {int(slot) for slot, _ in slots}
            origins = {slot: dict(stores=0, examples=[]) for slot in sorted(spill_ids)}
            context = []
            for line in before.split('body:             |', 1)[1].splitlines():
                if re.match(r'  bb\.\d+', line):
                    context = [line.strip()]
                store = re.search(r'\b(?:STD|STW32)\b.*%stack\.(\d+), 0(?:,| |$)', line)
                if store and int(store[1]) in spill_ids:
                    origin = origins[int(store[1])]
                    origin['stores'] += 1
                    if len(origin['examples']) < 3:
                        origin['examples'].append(context[-6:]+[line.strip()])
                if line.strip():
                    context.append(line.strip())
            case['spill_store_origins'] = origins
            code = obj.read_bytes()
            case['object_bytes'] = len(code)
            elf = ELFFile(io.BytesIO(code))
            case['code_bytes'] = sum(s['sh_size'] for s in elf.iter_sections() if s['sh_flags'] & 4)
            case['spill_liveness'] = spill_liveness(pipe.stage('.before.mir'))
            frame = pipe.stage('.after.mir')
            run(['llc-18', '-O3', '-march=bpf', '-mcpu=v4', '-bpf-stack-size=4096',
                 '-start-before=prologepilog', '-stop-after=prologepilog',
                 pipe.stage('.packed.mir'), '-o', frame])
            case['post_pei_stack_bytes'] = post_pei_frames(frame.read_text())
            case['completed'] = True
        except (OSError, ValueError, RuntimeError, subprocess.CalledProcessError) as error:
            case['error'] = str(error)
        finally:
            pipe.close()
            (directory/'result.json').write_text(json.dumps(case, indent=2)+'\n')
            observation['cases'].append(case)
            (a.output/'result.json').write_text(json.dumps(observation, indent=2)+'\n')
        print(json.dumps(case), flush=True)
    if any(not case['completed'] for case in observation['cases']):
        raise RuntimeError('One or more backend diagnostics failed; see explicit per-case outcomes')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('archive', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--member', required=True)
    parser.add_argument('--bounds', type=Path,
                        help='Resume from retained frontend IR through this B IR compiler first')
    parser.add_argument('--case', action='append', choices=CHOICES)
    main(parser.parse_args())
