"""Compare every relocation kind in the compiler fixtures with original ELF/libbpf."""
import argparse
import json
from pathlib import Path
import subprocess

from audit_core_objects import query_key, records, report_queries, ROOT


def main(args):
    args.output.mkdir(parents=True, exist_ok=True)
    args.build.mkdir(parents=True, exist_ok=True)
    commands, cases, kinds = [], [], set()

    def run(command, stdout=None):
        command = [str(v) for v in command]
        result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        if stdout is not None:
            stdout.write_text(result.stdout)
        result.check_returncode()

    for fixture in ['test-core-ir.c', 'test-core-ir-ids.c']:
        out = args.output/fixture
        out.mkdir(parents=True, exist_ok=True)
        source = ROOT/'kprog/build'/fixture
        bitcode, original, resolved = [args.build/name for name in ['fixture.bc', 'fixture.bpf.o', 'fixture.resolved.bc']]
        run(['clang-18', '-target', 'bpf', '-O2', '-g', '-I/usr/include/x86_64-linux-gnu',
             '-emit-llvm', '-c', source, '-o', bitcode])
        run(['clang-18', '-target', 'bpf', '-O2', '-g', '-c', bitcode, '-o', original])
        run([args.compiler, bitcode, '--local-bpf', original, '--target-btf', args.target,
             '--report', out/'compiler.json', '-o', resolved])
        run([args.build/'core-reference', original, args.target], out/'reference.tsv')
        queries = report_queries(out/'compiler.json')
        rows = records(out/'reference.tsv')
        if not rows:
            raise ValueError('Fixture did not emit original ELF relocation records')
        seen = set()
        for row in rows:
            key = query_key(row)
            expected = int(row['resolved']), bool(int(row['poison']))
            if queries.get(key) != expected:
                raise ValueError('Compiler and original ELF/libbpf differ: '+str(row))
            kinds.add(int(row['kind']))
            seen.add(key)
        if seen != set(queries):
            raise ValueError('Some compiler queries lack an original ELF reference')
        cases.append(dict(fixture=fixture, elf_relocations=len(rows), compiler_queries=len(queries),
                          all_equal=True))
    if kinds != set(range(13)):
        raise ValueError('Not every CO-RE relocation kind was measured: '+str(kinds))
    (args.output/'result.json').write_text(json.dumps(dict(cases=cases, kinds=sorted(kinds),
        all_equal=True, scope='Host compiler/original ELF comparison; no native workload execution.'), indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for option in ['output', 'build', 'compiler', 'target']:
        parser.add_argument('--'+option, type=Path, required=True)
    main(parser.parse_args())
