"""Check libbpf ELF measurements on all 13 kinds, without an IR resolver."""
import argparse
import ctypes as c
import json
from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile
from audit_core_objects import ROOT, records, sha256, native_answers


def main(args):
    args.output.mkdir(parents=True, exist_ok=True)
    args.build.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()
        return result.stdout

    source, target = args.build/'fixture.bpf.o', args.build/'fixture-target.bpf.o'
    flags = ['clang-18', '-target', 'bpf', '-O2', '-g', '-I/usr/include/x86_64-linux-gnu',
             '-I'+str(ROOT/'vendor/libbpf/src'), '-c', ROOT/'kprog/test/core_audit_fixture.c']
    run([*flags, '-o', source])
    run([*flags, '-DAUDIT_TARGET', '-o', target])
    reference = args.output/'reference.tsv'
    reference.write_text(run([args.build/'core-reference', source, target]))
    rows = records(reference)
    expected = dict(field_offset=8, field_size=8, field_exists=1, field_absent=0,
                    field_signed=0, field_lshift=59, field_rshift=59,
                    type_exists=1, type_absent=0, type_size=24,
                    enum_exists=1, enum_absent=0, enum_value=47, type_matches=0)
    # IDs are ELF-local. Read them through the existing base's libbpf API.
    library = Path('/workspaces/.agent-state/kprog-ck/verified-loader/libnative_loader.so')
    lib = c.CDLL(str(library))
    lib.btf__parse.argtypes = [c.c_char_p, c.c_void_p]
    lib.btf__parse.restype = c.c_void_p
    lib.libbpf_get_error.argtypes = [c.c_void_p]
    lib.libbpf_get_error.restype = c.c_long
    lib.btf__find_by_name_kind.argtypes = [c.c_void_p, c.c_char_p, c.c_uint32]
    lib.btf__find_by_name_kind.restype = c.c_int
    lib.btf__free.argtypes = [c.c_void_p]
    lib.btf__free.restype = None
    for name, path in [('local', source), ('target', target)]:
        btf = lib.btf__parse(str(path).encode(), None)
        if not btf or lib.libbpf_get_error(btf):
            raise ValueError('Could not parse fixture BTF: '+str(path))
        try:
            expected['type_'+name] = lib.btf__find_by_name_kind(btf, b'audit_record', 4)
            if expected['type_'+name] <= 0:
                raise ValueError('Missing audit_record in actual '+name+' BTF')
        finally:
            lib.btf__free(btf)
    kinds = set()
    cases = []
    with source.open('rb') as stream:
        elf = ELFFile(stream)
        for row in rows:
            name = row['section'].split('/')[-1]
            value = int(row['resolved'])
            if value != expected[name] or int(row['poison']):
                raise ValueError(f'{name}: {row}, expected {expected[name]}')
            # Check actual libbpf instruction patch, not only the result scalar.
            if int(row['patched_immediate']) != value:
                raise ValueError('Resolved constant was not patched into its instruction')
            if elf.get_section_by_name(row['section']) is None:
                raise ValueError('Reference row does not identify a real ELF section')
            kinds.add(int(row['kind']))
            cases.append(dict(name=name, kind=int(row['kind']), value=value))
    if len(rows) != 16 or kinds != set(range(13)):
        raise ValueError('Fixture did not cover all 13 kinds and absent cases')
    # Regression: an unbound/stale witness must never turn a row into equal.
    witness = args.output/'stale-witness.json'
    witness.write_text(json.dumps(dict(source_sha256=sha256(source), native_sha256='0'*64, answers=[])))
    try:
        native_answers(witness, sha256(source), sha256(target))
    except ValueError as error:
        if 'different source/native bytes' not in str(error):
            raise
    else:
        raise ValueError('Stale native witness accepted')
    audit_cases = []
    native = args.build/'audit-native.o'
    shared = args.build/'audit-native.so'
    for mode in ('correct', 'wrong', 'unobserved'):
        out = args.output/mode
        out.mkdir(parents=True, exist_ok=True)
        if mode != 'unobserved':
            run(['clang-18', '-O3', '-g', '-march=native', '-foptimize-sibling-calls',
                 '-fomit-frame-pointer', '-mno-red-zone', '-mgeneral-regs-only', '-fno-stack-protector',
                 '-DAUDIT_LOCAL_ID='+str(expected['type_local']),
                 '-DAUDIT_TARGET_ID='+str(expected['type_target']),
                 *(['-DAUDIT_WRONG_ANSWERS'] if mode == 'wrong' else []),
                 '-c', ROOT/'kprog/test/core_audit_native.c', '-o', native])
            run(['clang-18', '-shared', native, '-o', shared])
            # dlclose before replacing the one shared-library build product.
            import _ctypes
            functions = c.CDLL(str(shared))
            try:
                answers = []
                for row in rows:
                    function = getattr(functions, row['section'].split('/')[-1])
                    function.restype = c.c_ulong
                    function.argtypes = []
                    answers.append(dict(local_type_id=int(row['local_type_id']), kind=int(row['kind']),
                                        access=row['access'], value=function(), poison=False))
            finally:
                _ctypes.dlclose(functions._handle)
            witness = out/'observations.json'
            witness.write_text(json.dumps(dict(source_sha256=sha256(source),
                native_sha256=sha256(native), answers=answers), indent=2)+'\n')
        item = dict(app='fixture', object='audit-native.o', source=str(source),
                    native=str(native), native_layout=True)
        if mode != 'unobserved':
            item['observations'] = str(witness)
        inventory = out/'input.json'
        inventory.write_text(json.dumps([item], indent=2)+'\n')
        run(['make', '-r', '-f', ROOT/'kprog/test/core-audit.mk', 'audit',
             'OUTPUT='+str(out), 'TARGET='+str(target), 'AUDIT_ARGS=--inventory '+str(inventory)])
        counts = json.loads((out/'summary.json').read_text())['apps']['fixture']
        expected_counts = dict(correct=(16, 0, 0), wrong=(14, 2, 0), unobserved=(0, 0, 16))[mode]
        if tuple(counts[key] for key in ('equal', 'different', 'unobserved')) != expected_counts:
            raise ValueError('Native observation/layout classification regression: '+str(counts))
        audit_cases.append(dict(mode=mode, counts=counts))
    (args.output/'result.json').write_text(json.dumps(dict(cases=cases, kinds=sorted(kinds),
        source_sha256=sha256(source), target_sha256=sha256(target), libbpf_library=str(library),
        libbpf_library_sha256=sha256(library), stale_witness_rejected=True, native_audits=audit_cases,
        scope='Actual ELF records/libbpf candidate selection and instruction patches; no IR rewrite or program load.'), indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('output', 'build'):
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
