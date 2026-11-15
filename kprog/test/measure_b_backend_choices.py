"""Diagnose stack pressure on one retained optimized B IR, with ephemeral outputs.

Each backend choice consumes the same completed bounds IR. Native P, the C
frontend, bounds transformation and production defaults remain unchanged.
"""
import argparse
import hashlib
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

CHOICES = {'normal': [], 'basic': ['-regalloc=basic'], 'pbqp': ['-regalloc=pbqp'],
           'source': ['-misched=source'], 'no-machine-licm': ['-disable-machine-licm'],
           'no-misched': ['-enable-misched=false']}


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
            worker._compile_simulator_backend(str(ROOT/'kprog/stock-path/bin/clang'),
                pipe, obj, run, compiled_input=initial)
            before = pipe.stage('.before.mir').read_text()
            slots = re.findall(r'  - \{ id: (\d+),[^\n]*type: spill-slot,[^\n]*size: (\d+),', before)
            case['spill_slots_before_packing'] = len(slots)
            case['object_bytes'] = len(obj.read_bytes())
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
