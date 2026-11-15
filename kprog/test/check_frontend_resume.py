"""Catch stale frontend reuse and command drift in the shared B continuation."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def allocated(path):
    with path.open('rb') as stream:
        return {section.name: hashlib.sha256(section.data()).hexdigest()
                for section in ELFFile(stream).iter_sections() if section['sh_flags'] & 2}


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    records, observations = [], []
    for name in ['store1immindex', 'store8regindex']:
        source, obj = a.build / f'{name}.bpf.c', a.build / f'{name}.bpf.o'
        before = allocated(obj)
        # These files came from the real, successful normal native-stores
        # pipeline. Record their identities, not a fabricated frontend result.
        profile = dict(completed=True, frontend_completed=True,
                       source_sha256=digest(source),
                       frontend_sha256=digest(source.with_suffix('.bounds-input.bc')),
                       provenance='Identity record for actual completed native-stores LLVM output')
        for variant in ['matching', 'pending', 'wrong-llvm', 'wrong-source']:
            record = profile.copy()
            if variant == 'pending': record['completed'] = False
            if variant == 'wrong-llvm': record['frontend_sha256'] = '0' * 64
            if variant == 'wrong-source': record['source_sha256'] = '0' * 64
            identity = a.output / f'{name}-{variant}.json'
            identity.write_text(json.dumps(record, indent=2) + '\n')
            output = a.output / f'{name}-{variant}'
            command = [sys.executable, str(ROOT / 'kprog/test/resume_simulator_frontend.py'),
                       '--profile', str(identity), '--source', str(source), '--object', str(obj),
                       '--bounds', str(a.bounds), '--output', str(output)]
            r = subprocess.run(command, capture_output=True, text=True)
            records.append(dict(command=command, returncode=r.returncode, stdout=r.stdout, stderr=r.stderr))
            (a.output / 'commands.json').write_text(json.dumps(records, indent=2) + '\n')
            result = json.loads((output / 'result.json').read_text())
            if variant == 'matching':
                r.check_returncode()
                if not result['completed'] or before != allocated(obj):
                    raise ValueError(f'{name}: resumed B differs from normal compilation')
            else:
                if r.returncode == 0 or result['completed'] or (output / 'commands.json').exists():
                    raise ValueError(f'{name}/{variant}: nonmatching input reached compilation')
                if before != allocated(obj):
                    raise ValueError(f'{name}/{variant}: rejected input changed the B object')
            observations.append(dict(symbol=name, variant=variant, expected_outcome=True,
                                     allocated_sha256=before))
    (a.output / 'result.json').write_text(json.dumps(dict(cases=observations,
        scope='Two actual normal frontend continuations and six stale/incomplete identity failures; no kernel'), indent=2) + '\n')
    print('frontend resume: 2 actual B continuations match; 6 stale/incomplete inputs stop before compiler')


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    for name in ['build', 'bounds', 'output']:
        p.add_argument('--' + name, type=Path, required=True)
    main(p.parse_args())
