"""Catch private-arena alias/helper changes and accidentally relaxed other accesses."""
import argparse
import ctypes as c
import json
from pathlib import Path
import subprocess


def check(tool, build, output):
    build.mkdir(parents=True, exist_ok=True)
    output.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()
        return result

    source = '''target triple = "x86_64-unknown-linux-gnu"
%union.x86_sim_stack_mem = type { [51 x i64] }
@outside = global i64 0, align 8
define i64 @private(ptr %ctx, i64 %seed, i1 %choose, ptr %helper) {
%arena = alloca %union.x86_sim_stack_mem, align 8
%a = getelementptr %union.x86_sim_stack_mem, ptr %arena, i64 0, i32 0, i64 0
%b = getelementptr %union.x86_sim_stack_mem, ptr %arena, i64 0, i32 0, i64 3
%selected = select i1 %choose, ptr %a, ptr %b
store volatile i64 %seed, ptr %selected, align 8
call void asm sideeffect "", "~{memory}"()
call void %helper(ptr %selected)
call void asm sideeffect "", "~{memory}"()
%value = load volatile i64, ptr %selected, align 8
%external = load volatile i64, ptr %ctx, align 8
%sum = add i64 %value, %external
ret i64 %sum
}
define i64 @mixed(ptr %ctx, i64 %seed, i1 %choose) {
%arena = alloca %union.x86_sim_stack_mem, align 8
%selected = select i1 %choose, ptr %arena, ptr %ctx
store volatile i64 %seed, ptr %selected, align 8
%value = load volatile i64, ptr %selected, align 8
ret i64 %value
}
define i64 @other_local(i64 %seed) {
%arena = alloca [51 x i64], align 8
store volatile i64 %seed, ptr %arena, align 8
%value = load volatile i64, ptr %arena, align 8
ret i64 %value
}
define i64 @global_access(i64 %seed) {
store volatile i64 %seed, ptr @outside, align 8
%value = load volatile i64, ptr @outside, align 8
ret i64 %value
}
define i64 @atomic_private(i64 %seed) {
%arena = alloca %union.x86_sim_stack_mem, align 8
store atomic volatile i64 %seed, ptr %arena seq_cst, align 8
%value = load atomic volatile i64, ptr %arena seq_cst, align 8
ret i64 %value
}
define i64 @real_assembly(i64 %seed) {
call void asm sideeffect "nop", "~{memory}"()
ret i64 %seed
}
'''
    before = build/'before.ll'
    before.write_text(source)
    transformed = build/'normal.bc'
    result = run([tool, before, '-o', transformed])
    if 'private stack accesses normalized=2' not in result.stderr:
        raise ValueError('Only the two proven private-arena accesses may normalize')
    if 'empty memory barriers removed=2' not in result.stderr:
        raise ValueError('Expected exactly the two empty barriers around the real helper')
    ir = run(['llvm-dis-18', transformed, '-o', '-']).stdout
    private_body = ir.split('@private(', 1)[1].split('\n}', 1)[0]
    if 'asm' in private_body or 'call void %helper' not in private_body:
        raise ValueError('Barrier normalization changed the real helper call')
    if 'asm sideeffect "nop", "~{memory}"' not in ir:
        raise ValueError('Barrier normalization removed a real asm operation')
    for name, expected in [('private', 1), ('mixed', 2), ('other_local', 2),
                           ('global_access', 2), ('atomic_private', 2)]:
        body = ir.split('@'+name+'(', 1)[1].split('\n}', 1)[0]
        if body.count('volatile') != expected:
            raise ValueError('Private/global/atomic boundary changed: '+name)
    observations = []
    for variant, path in [('original', before), ('normal', transformed)]:
        library = build/(variant+'.so')
        run(['clang-18', '-shared', '-fPIC', '-O3', path, '-o', library])
        dll = c.CDLL(str(library))
        private = dll.private
        private.argtypes = [c.c_void_p, c.c_uint64, c.c_bool, c.c_void_p]
        private.restype = c.c_uint64
        helper_values = []

        @c.CFUNCTYPE(None, c.POINTER(c.c_uint64))
        def helper(pointer):
            old = pointer[0]
            helper_values.append(old)
            pointer[0] = (old*3+5) & ((1 << 64)-1)

        for seed in (0, 1, (1 << 32)+7, 1 << 63, (1 << 64)-1):
            for choose in (False, True):
                context = c.c_uint64(0x123456789abcdef0)
                actual = private(c.byref(context), seed, choose, c.cast(helper, c.c_void_p))
                expected = (seed*3+5+context.value) & ((1 << 64)-1)
                if actual != expected or helper_values[-1] != seed:
                    raise ValueError('Helper no longer observes and changes the private bytes')
                observations.append(dict(variant=variant, seed=seed, choose=choose,
                                         helper_input=helper_values[-1], result=actual))
                mixed = dll.mixed
                mixed.argtypes = [c.c_void_p, c.c_uint64, c.c_bool]
                mixed.restype = c.c_uint64
                if mixed(c.byref(context), seed, choose) != seed:
                    raise ValueError('Mixed local/nonlocal alias changed its value')
                expected_context = 0x123456789abcdef0 if choose else seed
                if context.value != expected_context:
                    raise ValueError('Mixed alias lost its external store')
            for name in ('other_local', 'global_access', 'atomic_private', 'real_assembly'):
                function = getattr(dll, name)
                function.argtypes = [c.c_uint64]
                function.restype = c.c_uint64
                if function(seed) != seed:
                    raise ValueError('Preserved access changed bits: '+name)
    record = dict(private_helper_executions=len(observations),
                  mixed_alias_executions=len(observations),
                  other_access_executions=40, normalized_accesses=2,
                  empty_barriers_removed=2,
                  helper_observations=observations,
                  scope='Real host loads/stores and external helper mutation; IR boundaries for nonlocal/mixed/atomic/other-local accesses. Actual app/frame acceptance is separate.')
    (output/'result.json').write_text(json.dumps(record, indent=2)+'\n')
    print(json.dumps({k:v for k,v in record.items() if k != 'helper_observations'}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('tool', 'build', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    args = parser.parse_args()
    check(args.tool, args.build, args.output)
