"""Native-result and CFG-join regressions for bounded AArch64 dispatch."""
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
import coverage


def main():
    phase = Path(sys.argv[1]) if len(sys.argv) > 1 else HERE / 'bounded-dispatch'
    phase.mkdir(exist_ok=True)
    build = ROOT / 'kprog/arm64/build/bounded-dispatch'
    build.mkdir(parents=True, exist_ok=True)
    # Both paths of a CFG join must survive; a later write must kill an ID.
    cases = [
        ('join', ['cbz x0, 10', 'mov x8, #5', 'b 14', 'nop',
                  'mov x8, #8', 'blr x8', 'ret'], {('scalar', 5), ('scalar', 8)}),
        ('bypass-cmp', ['cbz x0, 8', 'cmp x8, #5', 'b.eq 10', 'b 14', 'blr x8', 'ret'], None),
        ('stale', ['mov x8, #5', 'ldr x8, [x0]', 'blr x8', 'ret'], None),
        ('caller-clobber', ['mov x8, #5', 'mov x9, #8', 'blr x9', 'blr x8', 'ret'], None),
        ('invalid-id', ['mov x8, #65535', 'blr x8', 'ret'], None),
        ('narrow-move', ['mov x8, #5', 'mov w9, w8', 'blr x9', 'ret'], {('scalar', 5)}),
    ]
    outcomes = []
    for name, operations, expected in cases:
        insns = [gen.NativeInsn(4*i, operation.split()[0],
                 gen.split_operands(operation.partition(' ')[2]), operation)
                 for i, operation in enumerate(operations)]
        try:
            targets = gen.indirect_targets(insns)
            observed = set().union(*targets.values())
            passed = expected is not None and observed == expected
            detail = repr(targets)
        except ValueError as error:
            passed = expected is None
            detail = str(error)
        outcomes.append(dict(name=name, passed=passed, detail=detail))
    (phase / 'analysis.json').write_text(json.dumps(outcomes, indent=2)+'\n')
    if not all(row['passed'] for row in outcomes):
        raise RuntimeError(f'finite-target regressions failed: {outcomes}')
    objects = []
    for stem in ['bounded_branch', 'bounded_dispatch']:
        obj = build/(stem+'.proof.o')
        subprocess.run(['aarch64-linux-gnu-gcc', '-c', str(HERE/(stem+'.S')),
                        '-o', str(obj)], check=True)
        objects.append(obj)
    binary = build / 'native'
    subprocess.run(['aarch64-linux-gnu-gcc', '-O2', '-static', str(HERE/'bounded_native.c'),
                    *[str(obj) for obj in objects], '-o', str(binary)], check=True)
    native = subprocess.run(['qemu-aarch64-static', str(binary)], text=True, capture_output=True)
    (phase/'native.json').write_text(json.dumps(dict(returncode=native.returncode,
                          stdout=native.stdout, stderr=native.stderr))+'\n')
    if native.returncode:
        raise RuntimeError(native.stderr + native.stdout)
    coverage.freeze_simulator(phase)
    sources = phase/'sources'
    inputs = phase/'inputs'
    sources.mkdir(exist_ok=True)
    inputs.mkdir(exist_ok=True)
    rows = []
    for obj in objects:
        stem = obj.name.removesuffix('.proof.o')
        functions, rodata = gen.parse_native_linked_program(gen.Bench(stem, stem, 'xdp'), build)
        for selector in range(2):
            name = f'{stem}_{selector}'
            source = sources/(name+'.bpf.c')
            source.write_text(gen.render_program(name, stem, functions, 'xdp'))
            data = inputs/(name+'.mem')
            data.write_bytes(bytes([selector]) + bytes(7))
            rows.append(dict(name=name, proof=str(obj), source=str(source), stage='generate', ok=True,
                             note='native-matched bounded control-flow regression',
                             input_file=str(data), expected_result=41+selector, expected_retval=2,
                             result_channel='packet', cgroup_skb_input=False, load_timeout_s=600))
    (phase/'programs.jsonl').write_text(''.join(json.dumps(row)+'\n' for row in rows))
    print(native.stdout, end='')
    print(f'{len(outcomes)} CFG regressions pass; {len(rows)} native-matched proof sources generated')


if __name__ == '__main__':
    main()
