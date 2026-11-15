"""Check the normal MIR backend and its remaining all-pairs selection."""
import argparse
import importlib.util
import json
import os
from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def allocated(path):
    with path.open('rb') as source:
        elf = ELFFile(source)
        return {section.name: section.data() for section in elf.iter_sections()
                if section['sh_flags'] & 2}


def check(output, clang, main_mir=None, accepted_mir=None, build=Path('/var/tmp/kprog-tmp/perf/backend-check')):
    output.mkdir(parents=True, exist_ok=True)
    build.mkdir(parents=True, exist_ok=True)
    spec = importlib.util.spec_from_file_location('spill_backend', ROOT/'kprog/x86/trusted_specializer.py')
    worker = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(worker)
    source = build/'backend.bpf.c'
    source.write_text('''#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("socket") int backend(struct __sk_buff *ctx) {
unsigned value = ctx->mark;
x86_l_0:
value ^= ctx->priority + 12345u;
x86_l_1:
return value;
}
char LICENSE[] SEC("license") = "GPL";
''')
    commands = []

    def run(command):
        command = [str(value) for value in command]
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()

    saved_all = os.environ.pop('KPROG_BPF_WHOLE_WORD_SPILLS_ALL', None)
    try:
        default = build/'default.o'
        worker.PIECE_SOURCE_BYTES = 1
        worker.compile_simulator(clang, source, default, run)
        default_allocated = allocated(default)
        if sum('-E' in row['command'] for row in commands) < 2:
            raise ValueError('Normal backend did not exercise preprocessing piece join')
        if not any('llc-18' == row['command'][0] for row in commands):
            raise ValueError('Normal MIR backend was disconnected')
        run([clang, *worker.COMPILE_FLAGS, '-c', source.with_suffix('.i'), '-o', default])
        if allocated(default) != default_allocated:
            raise ValueError('Normal backend changed code for an independent-register fixture')
        os.environ['KPROG_BPF_WHOLE_WORD_SPILLS_ALL'] = '1'
        start = len(commands)
        worker.compile_simulator(clang, source, default, run)
        if allocated(default) != default_allocated:
            raise ValueError('All-pairs pipeline changed the independent-register fixture')
        if not any('--all-scalar-pairs' in row['command'] for row in commands[start:]):
            raise ValueError('All-pairs selection was not forwarded to the real MIR command')
        os.environ['KPROG_BPF_WHOLE_WORD_SPILLS_ALL'] = 'invalid'
        start = len(commands)
        try:
            worker.compile_simulator(clang, source, default, run)
        except ValueError as error:
            if 'KPROG_BPF_WHOLE_WORD_SPILLS_ALL' not in str(error):
                raise
        else:
            raise ValueError('Invalid all-pairs configuration was accepted')
        if len(commands) != start:
            raise ValueError('Invalid all-pairs configuration reached compilation')
        result = dict(normal_pipeline_allocations_equal_direct=True, normal_llc_executed=True,
                      all_pairs_forwarded=True, all_pairs_allocations_equal=True,
                      invalid_all_pairs_configuration_fails_before_compilation=True)
        if main_mir is not None:
            spill_spec = importlib.util.spec_from_file_location('whole_word_spills',
                ROOT/'kprog/x86/whole_word_spills.py')
            spills = importlib.util.module_from_spec(spill_spec)
            spill_spec.loader.exec_module(spills)
            automatic, records = spills.automatic(main_mir)
            if automatic != accepted_mir.read_text():
                raise ValueError('Automatic main MIR differs from the retained accepted compilation input')
            result['main_automatic_equals_accepted_mir'] = True
            result['main_selection'] = records
            result['main_mir'] = str(main_mir)
            result['accepted_mir'] = str(accepted_mir)
        (output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
        print(json.dumps(result))
    finally:
        if saved_all is None:
            os.environ.pop('KPROG_BPF_WHOLE_WORD_SPILLS_ALL', None)
        else:
            os.environ['KPROG_BPF_WHOLE_WORD_SPILLS_ALL'] = saved_all


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--clang', required=True)
    parser.add_argument('--build', type=Path, default=Path('/var/tmp/kprog-tmp/perf/backend-check'))
    parser.add_argument('--main-mir', type=Path)
    parser.add_argument('--accepted-mir', type=Path)
    args = parser.parse_args()
    if (args.main_mir is None) != (args.accepted_mir is None):
        parser.error('--main-mir and --accepted-mir are supplied together')
    check(args.output, args.clang, args.main_mir, args.accepted_mir, args.build)
