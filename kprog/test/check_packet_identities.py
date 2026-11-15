"""Catch invented packet-field provenance from an untied empty asm output."""
import argparse
import ctypes as c
import importlib.util
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]


def check(tool, output, retained, build=Path('/var/tmp/kprog-tmp/perf/packet-identities')):
    output.mkdir(parents=True, exist_ok=True)
    build.mkdir(parents=True, exist_ok=True)
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
    before = build/'before.ll'
    before.write_text(source)
    active = run([tool, before, '-o', build/'strict.bc'])
    if 'packet length predicates lowered=1' not in active.stderr:
        raise ValueError('Normal lowering must recognize the tied field only')
    libraries = {}
    for name, ir in [('before', before), ('strict', build/'strict.bc')]:
        library = build/(name+'.so')
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
    (output/'execution.json').write_text(json.dumps(observations, indent=2)+'\n')
    # The native fixture pins a register to make the permitted untied output
    # reproducible. Exercise the matching rule in BPF's own register domain too.
    bpf = build/'bpf.ll'
    bpf.write_text(source.replace('x86_64-unknown-linux-gnu', 'bpf').replace('={r12},{rdi}', '=r,r'))
    bpf_result = run([tool, bpf, '-o', build/'bpf-strict.bc'])
    if 'packet length predicates lowered=1' not in bpf_result.stderr:
        raise ValueError('BPF untied output received invented field provenance')
    run(['clang-18', '-target', 'bpf', '-mcpu=v4', '-O3', '-c',
         build/'bpf-strict.bc', '-o', build/'bpf-strict.o'])
    replay = []
    for index, path in enumerate(retained):
        strict = build/f'retained-{index}-strict.bc'
        run([tool, path, '-o', strict])
        replay.append(dict(input=str(path), compiled=True))
    pipeline = build/'pipeline.bpf.c'
    pipeline.write_text('''#include <linux/bpf.h>
#include <bpf_helpers.h>
SEC("xdp") int pipeline(struct xdp_md *ctx) {
unsigned long long start = ctx->data;
unsigned long long end = ctx->data_end;
x86_l_0:
asm volatile ("" : "+r"(end));
return end-start < 64;
}
char LICENSE[] SEC("license") = "GPL";
''')
    spec = importlib.util.spec_from_file_location('identity_worker', ROOT/'kprog/x86/trusted_specializer.py')
    worker = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(worker)
    first = len(calls)
    worker.compile_simulator(str(ROOT/'kprog/stock-path/bin/clang'), pipeline,
                             build/'pipeline.o', run, bounds_compiler=tool)
    lowering = [row for row in calls[first:] if row['command'][0] == str(tool)]
    if len(lowering) != 1 or 'packet length predicates lowered=1' not in lowering[0]['stderr']:
        raise ValueError('Normal service compiler omitted packet identity lowering')
    result = dict(counterexample=counterexample,
                  execution_cases=len(observations), retained=replay, normal_service_path=True,
                  bpf_untied_output_preserved=True)
    (output/'result.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(result))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('tool', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--retained', type=Path, action='append', default=[])
    parser.add_argument('--build', type=Path, default=Path('/var/tmp/kprog-tmp/perf/packet-identities'))
    args = parser.parse_args()
    check(args.tool, args.output, args.retained, args.build)
