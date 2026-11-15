"""Run independent load, stack and writeback oracles with explicit host inputs."""
import argparse
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]


def main(a):
    a.build.mkdir(parents=True, exist_ok=True)
    a.output.mkdir(parents=True, exist_ok=True)
    adapter = a.build / 'input.c'
    adapter.write_text('''#include <stdlib.h>
/* These independent byte-model grids use native SP origin zero and choose
 * the successful scalar-read outcome at each explicit environment draw. */
unsigned long native_lab_entry_input(unsigned int kind) {
    if (kind == 1 || kind == 6) return 0;
    abort();
}
''')
    records = []
    failures = []
    tests = [(ROOT / 'kprog/formal/oracles' / (name + '.c'), own_input)
             for name, own_input in [('test_x86_mov_load_route_host', False),
                                     ('test_x86_stack_arm_route_host', False),
                                     ('test_stack_output_lifetime_host', True)]]
    tests.append((ROOT / 'kprog/test/load_writeback_host.c', True))
    tests.append((ROOT / 'kprog/formal/oracles/test_x86_store_route_host.c', False))
    variants = [(source, own_input, []) for source, own_input in tests]
    variants.append((ROOT / 'kprog/formal/oracles/test_stack_output_lifetime_host.c',
                     True, ['-DTEST_ARM64']))
    for source, own_input, options in variants:
        name = source.stem + ('_arm64' if options else '')
        executable = a.build / name
        commands = [['cc', '-std=gnu2x', '-O2', '-Wall', '-Wextra', *options,
                     '-I' + str(ROOT), '-I' + str(ROOT / 'kprog/formal'),
                     '-I' + str(ROOT / 'kprog'), '-I' + str(ROOT / 'kprog/x86'),
                     '-I' + str(ROOT / 'vendor/libbpf/src'), source,
                     *([] if own_input else [adapter]), '-o', executable], [executable]]
        for command in commands:
            command = list(map(str, command))
            r = subprocess.run(command, capture_output=True, text=True)
            records.append(dict(name=name, command=command, returncode=r.returncode,
                                stdout=r.stdout, stderr=r.stderr))
            (a.output / 'commands.json').write_text(json.dumps(records, indent=2) + '\n')
            if r.returncode:
                failures.append(dict(name=name, returncode=r.returncode))
                break
            if command == [str(executable)]:
                print(r.stdout.strip(), flush=True)
    (a.output / 'result.json').write_text(json.dumps(dict(failures=failures), indent=2) + '\n')
    if failures:
        raise RuntimeError(f'Load/stack oracle failures: {failures}')


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'output'):
        p.add_argument('--' + name, type=Path, required=True)
    main(p.parse_args())
