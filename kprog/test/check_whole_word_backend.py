"""Catch changes to default B bytes and disconnected optional MIR compilation."""
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


def check(output, clang, main_mir=None, accepted_mir=None, prior_revision=None):
    output.mkdir(parents=True, exist_ok=True)
    spec = importlib.util.spec_from_file_location('spill_backend', ROOT/'kprog/x86/trusted_specializer.py')
    worker = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(worker)
    source = output/'backend.bpf.c'
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

    saved = os.environ.pop('KPROG_BPF_WHOLE_WORD_SPILLS', None)
    saved_all = os.environ.pop('KPROG_BPF_WHOLE_WORD_SPILLS_ALL', None)
    try:
        default = output/'default.o'
        prior_bytes = prior_input = None
        if prior_revision:
            prior_source = subprocess.run(['git', 'show', prior_revision+':kprog/x86/trusted_specializer.py'],
                cwd=ROOT, text=True, capture_output=True, check=True).stdout
            namespace = dict(__file__=str(ROOT/'kprog/x86/trusted_specializer.py'),
                             __name__='prior_preprocess_worker')
            exec(compile(prior_source, namespace['__file__'], 'exec'), namespace)
            namespace['PIECE_SOURCE_BYTES'] = worker.PIECE_SOURCE_BYTES = 1
            namespace['compile_simulator'](clang, source, default, run)
            prior_pieces = sum('-E' in row['command'] for row in commands)
            if prior_pieces < 2:
                raise ValueError('Prior/default comparison did not exercise the piece join')
            prior_bytes = default.read_bytes()
            prior_input = source.with_suffix('.i').read_bytes()
        worker.compile_simulator(clang, source, default, run)
        if prior_revision and (default.read_bytes() != prior_bytes or
                               source.with_suffix('.i').read_bytes() != prior_input):
            raise ValueError('Preprocessing cleanup changed default object or input bytes')
        default_bytes = default.read_bytes()
        default_allocated = allocated(default)
        run([clang, *worker.COMPILE_FLAGS, '-c', source.with_suffix('.i'), '-o', default])
        if default_bytes != default.read_bytes():
            raise ValueError('Default compiler object differs from the previous backend command')
        os.environ['KPROG_BPF_WHOLE_WORD_SPILLS'] = '0'
        worker.compile_simulator(clang, source, default, run)
        if default_bytes != default.read_bytes():
            raise ValueError('Explicitly disabled compiler object differs from default')
        os.environ['KPROG_BPF_WHOLE_WORD_SPILLS'] = '1'
        start = len(commands)
        worker.compile_simulator(clang, source, default, run)
        if allocated(default) != default_allocated:
            raise ValueError('Optional pipeline changed code for a fixture with independent registers')
        if not any('llc-18' == row['command'][0] for row in commands[start:]):
            raise ValueError('Optional MIR backend was disconnected')
        os.environ['KPROG_BPF_WHOLE_WORD_SPILLS_ALL'] = '1'
        start = len(commands)
        worker.compile_simulator(clang, source, default, run)
        if allocated(default) != default_allocated:
            raise ValueError('All-pairs pipeline changed the independent-register fixture')
        if not any('--all-scalar-pairs' in row['command'] for row in commands[start:]):
            raise ValueError('All-pairs selection was not forwarded to the real MIR command')
        for enabled, selection in [('0','1'),('1','invalid')]:
            os.environ['KPROG_BPF_WHOLE_WORD_SPILLS'] = enabled
            os.environ['KPROG_BPF_WHOLE_WORD_SPILLS_ALL'] = selection
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
        result = dict(default_equals_previous_command=True, disabled_equals_default=True,
                      optional_pipeline_allocations_equal=True, optional_llc_executed=True,
                      all_pairs_forwarded=True, all_pairs_allocations_equal=True,
                      invalid_all_pairs_configuration_fails_before_compilation=True)
        if prior_revision:
            result.update(prior_revision=prior_revision, prior_preprocessing_pieces=prior_pieces,
                          preprocessing_input_and_default_object_equal=True)
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
        if saved is None:
            os.environ.pop('KPROG_BPF_WHOLE_WORD_SPILLS', None)
        else:
            os.environ['KPROG_BPF_WHOLE_WORD_SPILLS'] = saved
        if saved_all is None:
            os.environ.pop('KPROG_BPF_WHOLE_WORD_SPILLS_ALL', None)
        else:
            os.environ['KPROG_BPF_WHOLE_WORD_SPILLS_ALL'] = saved_all


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--clang', required=True)
    parser.add_argument('--main-mir', type=Path)
    parser.add_argument('--accepted-mir', type=Path)
    parser.add_argument('--prior-revision')
    args = parser.parse_args()
    if (args.main_mir is None) != (args.accepted_mir is None):
        parser.error('--main-mir and --accepted-mir are supplied together')
    check(args.output, args.clang, args.main_mir, args.accepted_mir, args.prior_revision)
