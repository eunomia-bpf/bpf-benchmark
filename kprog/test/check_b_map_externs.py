"""Catch missing BTF VARs for asm-named map bindings without changing B code."""
import argparse
import json
from pathlib import Path
import subprocess
import sys

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86'))
import trusted_specializer as worker


def allocated_code(path):
    with path.open('rb') as stream:
        elf = ELFFile(stream)
        return {section.name: section.data() for section in elf.iter_sections()
                if section['sh_flags'] & 4}


def check(args):
    args.build.mkdir(parents=True, exist_ok=True)
    args.output.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (args.output / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        result.check_returncode()
        return result

    source = args.build / 'externs.c'
    source.write_text('''extern unsigned char second[] __asm__("map.second") __attribute__((section(".ksyms")));
extern unsigned char ordinary[] __attribute__((section(".ksyms")));
extern unsigned char first[] __asm__("map.first") __attribute__((section(".ksyms")));
char LICENSE[] __attribute__((section("license"))) = "GPL";
int entry(void *ctx) __attribute__((section("socket")));
int entry(void *ctx) { return (unsigned long)first + (unsigned long)ordinary + (unsigned long)second; }
''')
    initial = args.build / 'externs.bc'
    run(['clang-18', '-target', 'bpf', '-O3', '-g', '-emit-llvm', '-c', source, '-o', initial])
    lowered = args.build / 'externs.lowered.bc'
    result = run([args.tool, initial, '-o', lowered])
    if 'map extern debug declarations restored=2' not in result.stderr:
        raise ValueError('Both asm-named extern declarations must be restored')
    records = {}
    for name, path in [('original', initial), ('repaired', lowered)]:
        obj = args.build / (name + '.o')
        run(['clang-18', '-target', 'bpf', '-mcpu=v4', '-O3', '-c', path, '-o', obj])
        records[name] = json.loads(run([args.bpftool, '-j', 'btf', 'dump', 'file', obj]).stdout)
    variables = {item['name'] for item in records['repaired']['types'] if item['kind'] == 'VAR'}
    if not {'map.first', 'map.second', 'ordinary'} <= variables:
        raise ValueError('BTF extern symbols differ from actual LLVM/ELF names')
    if allocated_code(args.build / 'original.o') != allocated_code(args.build / 'repaired.o'):
        raise ValueError('Debug repair changed executable B instructions')
    again = run([args.tool, lowered, '-o', args.build / 'twice.bc'])
    if 'map extern debug declarations restored=0' not in again.stderr:
        raise ValueError('Existing debug declarations were replaced')
    record = dict(asm_named_vars=sorted(variables), executable_code_equal=True,
                  existing_metadata_preserved=True)
    if args.frontend:
        actual = args.build / 'actual.lowered.bc'
        run([args.tool, args.frontend, '-o', actual])
        obj = args.build / 'actual.bpf.o'
        worker._compile_simulator_backend(str(ROOT / 'kprog/stock-path/bin/clang'),
            args.build / 'actual.bpf.c', obj, run, compiled_input=actual)
        btf = run([args.bpftool, 'btf', 'dump', 'file', obj]).stdout
        (args.output / 'actual.btf.txt').write_text(btf)
        if "VAR 'count_v4.zero'" not in btf:
            raise ValueError('Actual BCC map extern remains absent from BTF')
        record['actual_bcc_var_present'] = True
        if args.original:
            equal = allocated_code(args.original) == allocated_code(obj)
            record['actual_executable_code_equal'] = equal
            if not equal:
                raise ValueError('Actual BCC executable B instructions changed')
    (args.output / 'result.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps(record))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for field in ('tool', 'bpftool', 'build', 'output'):
        parser.add_argument('--' + field, type=Path, required=True)
    for field in ('frontend', 'original'):
        parser.add_argument('--' + field, type=Path)
    check(parser.parse_args())
