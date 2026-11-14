"""Catch invented packet-field provenance from an untied empty asm output."""
import argparse
import ctypes as c
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]


def check(tool, legacy, output, retained):
    output.mkdir(parents=True, exist_ok=True)
    calls = []

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        calls.append(dict(command=command, returncode=result.returncode,
                          stdout=result.stdout, stderr=result.stderr))
        (output/'commands.json').write_text(json.dumps(calls, indent=2)+'\n')
        result.check_returncode()
        return result

    source = 'target triple = "x86_64-unknown-linux-gnu"\n'
    for name, constraint in [('tied', '=r,0'), ('untied', '={r12},{rdi}')]:
        source += f'''define i32 @{name}(ptr %ctx) section "xdp" {{
%endptr = getelementptr i8, ptr %ctx, i64 4
%start32 = load volatile i32, ptr %ctx, align 4
%end32 = load volatile i32, ptr %endptr, align 4
%opaque = call i32 asm sideeffect "", "{constraint}"(i32 %end32)
%start = zext i32 %start32 to i64
%end = zext i32 %opaque to i64
%length = sub i64 %end, %start
%short = icmp ult i64 %length, 64
%result = zext i1 %short to i32
ret i32 %result
}}
'''
    before = output/'before.ll'
    before.write_text(source)
    run([legacy, before, '-o', output/'legacy.bc'])
    run([tool, before, '-o', output/'off.bc'])
    if (output/'legacy.bc').read_bytes() != (output/'off.bc').read_bytes():
        raise ValueError('Disabled identity change differs from the prior compiler')
    active = run([tool, before, '-o', output/'strict.bc', '--strict-identities'])
    if 'packet length predicates lowered=1' not in active.stderr:
        raise ValueError('Strict mode must recognize the tied field only')
    libraries = {}
    for name, ir in [('before', before), ('legacy', output/'legacy.bc'), ('strict', output/'strict.bc')]:
        library = output/(name+'.so')
        run(['clang-18', '-shared', '-fPIC', '-O2', ir, ROOT/'kprog/test/packet_choice_call.S', '-o', library])
        libraries[name] = c.CDLL(str(library))
        libraries[name].run_packet_choice.argtypes = [c.c_void_p, c.c_void_p, c.c_uint64]
        libraries[name].run_packet_choice.restype = c.c_uint32
    class Context(c.Structure):
        _fields_ = [('data', c.c_uint32), ('end', c.c_uint32)]
    observations = []
    for function in ('tied', 'untied'):
        for start, end in [(0, 0), (0, 128), (64, 128), (100, 200), (0xffffff00, 0xffffffff)]:
            for seed in (0, 1, 63, 64, 200, 0xffffffff):
                context = Context(start, end)
                values = {name: library.run_packet_choice(c.cast(getattr(library, function), c.c_void_p),
                                                          c.byref(context), seed)
                          for name, library in libraries.items()}
                effective_end = end if function == 'tied' else seed
                expected = int(((effective_end-start) & ((1 << 64)-1)) < 64)
                if values['before'] != expected or values['strict'] != expected:
                    raise ValueError(f'Identity semantics changed: {function}/{start}/{end}/{seed}/{values}/{expected}')
                observations.append(dict(function=function, start=start, end=end, seed=seed,
                                         expected=expected, **values))
    counterexample = next(row for row in observations if row['function']=='untied' and
                          row['start']==100 and row['end']==200 and row['seed']==0)
    if counterexample['legacy'] == counterexample['expected']:
        raise ValueError('The actual legacy counterexample was disconnected')
    (output/'execution.json').write_text(json.dumps(observations, indent=2)+'\n')
    replay = []
    for index, path in enumerate(retained):
        old, default, strict = [output/f'retained-{index}-{label}.bc' for label in ('old', 'off', 'strict')]
        run([legacy, path, '-o', old])
        run([tool, path, '-o', default])
        run([tool, path, '-o', strict, '--strict-identities'])
        if old.read_bytes() != default.read_bytes():
            raise ValueError('Default compiler changed a retained packet input')
        replay.append(dict(input=str(path), default_equal=True,
                           strict_equal=old.read_bytes()==strict.read_bytes()))
    result = dict(default_equal=True, counterexample=counterexample,
                  execution_cases=len(observations), retained=replay)
    (output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(result))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('tool', 'legacy', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--retained', type=Path, action='append', default=[])
    args = parser.parse_args()
    check(args.tool, args.legacy, args.output, args.retained)
