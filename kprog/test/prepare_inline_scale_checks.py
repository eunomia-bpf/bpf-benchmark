"""Bind completed inline-scale measurements to the existing stock test suite.

No input is regenerated or compiled. Expected outputs come from the same
scale fixture generator, and the existing checker records each actual load
and execution outcome, including failures.
"""
import argparse
import hashlib
import json
from pathlib import Path
import sys

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'kprog/fidelity'))
import scale


def prepare(a):
    a.output.mkdir(parents=True, exist_ok=True)
    seen = set()
    for profile in a.profiles:
        for measured in json.loads(profile.read_text()):
            name = measured['name']
            if name in seen:
                raise ValueError('Duplicate measured scale case: '+name)
            seen.add(name)
            size = measured['requested_native_instructions']
            pointer, indirect = '_ptr_' in name, name.endswith('_indirect')
            expected_name = f'n{size}_{"ptr" if pointer else "scalar"}_{"indirect" if indirect else "direct"}'
            if name != expected_name:
                raise ValueError('Scale case does not match fixture shape: '+name)
            _, expected = scale.assembly(size, pointer, indirect)
            row = dict(name=name, target_native_instructions=size,
                native_instructions=measured['native_instructions'],
                expected_result=expected, pipeline='stock', profile=str(profile),
                stage='proof_compile_failed', returncode=1)
            if measured.get('bpf_compiled'):
                native = a.build/(name+'.native.o')
                if hashlib.sha256(native.read_bytes()).hexdigest() != measured['native_sha256']:
                    raise ValueError('Measured native object changed: '+name)
                obj = a.build/(name+'.bpf.o')
                with obj.open('rb') as stream:
                    elf = ELFFile(stream)
                    allocated = {section.name: dict(bytes=section.data_size,
                        sha256=hashlib.sha256(section.data()).hexdigest())
                        for section in elf.iter_sections() if section['sh_flags'] & 2}
                if allocated != measured['allocated_sections']:
                    raise ValueError('Measured B allocated sections changed: '+name)
                row.update(stage='compiled', returncode=0,
                    object_sha256=hashlib.sha256(obj.read_bytes()).hexdigest(),
                    bpf_code_bytes=measured['bpf_code_bytes'],
                    post_pei_stack_bytes=measured.get('post_pei_stack_bytes'))
            (a.output/(name+'.json')).write_text(json.dumps(row, indent=2)+'\n')
            print(name+': '+row['stage'], flush=True)
    if not seen:
        raise ValueError('No measured scale cases supplied')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--profiles', nargs='+', type=Path, required=True)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    prepare(parser.parse_args())
