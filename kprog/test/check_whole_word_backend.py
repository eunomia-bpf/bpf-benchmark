"""Check that the sole all-pairs MIR route preserves independent-register code."""
import argparse
import importlib.util
import json
from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def allocated(path):
    with path.open('rb') as source:
        elf = ELFFile(source)
        return {section.name: section.data() for section in elf.iter_sections()
                if section['sh_flags'] & 2}


def check(output, clang, build=Path('/var/tmp/kprog-tmp/perf/backend-check')):
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
    result = dict(normal_pipeline_allocations_equal_direct=True, normal_llc_executed=True)
    (output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(result))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--clang', required=True)
    parser.add_argument('--build', type=Path, default=Path('/var/tmp/kprog-tmp/perf/backend-check'))
    args = parser.parse_args()
    check(args.output, args.clang, args.build)
