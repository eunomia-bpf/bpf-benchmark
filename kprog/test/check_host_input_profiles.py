"""Run the existing full-state/storage-stream profiles against the actual headers."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]
FORMAL = ROOT / 'kprog/formal'


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    build = FORMAL / 'build'
    build.mkdir(exist_ok=True)
    generic = FORMAL / 'c' / ('X86Pointer.c' if a.arch == 'x86' else 'Arm64Address.c')
    obj = build / ('x86_pointer_binding.o' if a.arch == 'x86' else 'arm64_address_binding.o')
    test = FORMAL / 'oracles' / f'test_{a.arch}_storage_profile_host.c'
    binary = build / f'test_{a.arch}_storage_profile_host'
    identity = dict(arch=a.arch, generic_sha256=digest(generic), oracle_sha256=digest(test),
                    header_sha256=digest(ROOT / f'kprog/{a.arch}/{a.arch}_sim_local_bpf.h'),
                    scope='Existing generic/canonical storage and input-stream equivalence; no hardware or full formal proof')
    (a.output / 'inputs.json').write_text(json.dumps(identity, indent=2) + '\n')
    flags = ['cc', '-Wall', '-Wextra', '-O2', '-fsanitize=undefined', '-fno-sanitize-recover=undefined',
             '-I' + str(ROOT / 'vendor/libbpf/include/uapi'), '-I' + str(ROOT / 'vendor/libbpf/src')]
    records = []

    def run(command):
        command = list(map(str, command))
        r = subprocess.run(command, capture_output=True, text=True)
        records.append(dict(command=command, returncode=r.returncode, stdout=r.stdout, stderr=r.stderr))
        (a.output / 'commands.json').write_text(json.dumps(records, indent=2) + '\n')
        r.check_returncode()
        if r.stdout: print(r.stdout, end='', flush=True)

    run([*flags, '-c', generic, '-o', obj])
    profiles = [(1, 0), (7, 0), (9, 0), (64, 0), (200, 0), (376, 0), (64, 1), (200, 1), (376, 1)] if a.arch == 'x86' else [
        (1, 0), (7, -3), (9, 4), (160, 96), (200, 160), (376, 280)]
    for capacity, field in profiles:
        option = 'SCALAR_FACTS' if a.arch == 'x86' else 'BIAS'
        run([*flags, f'-DPROFILE={capacity}', f'-D{option}={field}', test, obj, '-o', binary])
        run([binary])
    (a.output / 'result.json').write_text(json.dumps(dict(identity, completed=True, profiles=profiles), indent=2) + '\n')


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--arch', choices=['x86', 'arm64'], required=True)
    p.add_argument('--output', type=Path, required=True)
    main(p.parse_args())
