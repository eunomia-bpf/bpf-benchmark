"""Render real AAPCS helper calls and ABI regressions from vendored libbpf."""
import json
from pathlib import Path
import re

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
FORMAL = ROOT/'kprog/formal'
HEADER = ROOT/'kprog/arm64/arm64_sim_local_bpf.h'


def main():
    definitions = (ROOT/'vendor/libbpf/src/bpf_helper_defs.h').read_text()
    prototypes = {name: (result.strip(), args.strip(), int(number))
                  for result, name, args, number in re.findall(
        r'^static (.*?)\(\* const (bpf_\w+)\)\((.*?)\) = \(void \*\) (\d+);', definitions, re.M)}
    rows = json.loads((FORMAL/'contracts/arm64_helper_idents_spec.json').read_text())['rows']
    bodies, abi, stubs, tests = [], [], [], []
    for row in rows:
        name = row['name']
        result, arguments, number = prototypes[name]
        if number != row['id']:
            raise ValueError(f'{name}: helper ID differs from libbpf')
        parameters, expressions, checks = [], [], []
        declarations = []
        for index, arg in enumerate([] if arguments == 'void' else arguments.split(',')):
            arg = arg.strip()
            if arg == '...':
                expressions.extend(f'ARM64_SIM_L_READ_REG(ARM64_X{i})' for i in range(index, 5))
                parameters.append(dict(variadic=True))
                checks += ['va_list rest;', f'va_start(rest, arg{index-1});']
                checks += [f'check_arg({i}, va_arg(rest, __u64));' for i in range(index, 5)]
                checks += ['va_end(rest);']
                declarations.append('...')
                break
            match = re.fullmatch(r'(.*?)([A-Za-z_]\w*)', arg)
            if match is None:
                raise ValueError(f'{name}: cannot parse parameter {arg}')
            typ = match[1].strip()
            pointer = '*' in typ
            accessor = 'ARM64_SIM_L_HELPER_ARG_PTR' if pointer else 'ARM64_SIM_L_READ_REG'
            expressions.append(f'({typ}){accessor}(ARM64_X{index})')
            parameters.append(dict(type=typ, name=match[2], pointer=pointer))
            declarations.append(f'{typ} arg{index}')
            checks.append(f'check_arg({index}, (__u64)(unsigned long)arg{index});')
        result_body = 'ARM64_SIM_L_HELPER_POINTER_RESULT' if '*' in result else 'ARM64_SIM_L_HELPER_SCALAR_RESULT'
        bodies.append(f'#define ARM64_SIM_BPF_CALL_{name}() \\\n\t{result_body}({name}({", ".join(expressions)}))\n')
        abi.append(dict(id=number, name=name, result=result, parameters=parameters))
        stubs.append(f'static {result} {name}({", ".join(declarations) or "void"})\n{{\n'
                     + f'    seen_id = {number}; calls++;\n    ' + '\n    '.join(checks)
                     + f'\n    return ({result})(unsigned long)RETURN_BITS;\n}}\n')
        expected = []
        for index, parameter in enumerate(parameters):
            if parameter.get('variadic'):
                expected.extend(f'expected[{i}] = value_for({i});' for i in range(index, 5))
            elif parameter['pointer']:
                expected.append(f'expected[{index}] = stack_mode ? (__u64)(unsigned long)'
                                f'&__a64_stack.b[ARM64_SIM_STACK_BIAS-8] : value_for({index});')
            else:
                expected.append(f'expected[{index}] = (__u64)(unsigned long)({parameter["type"]})value_for({index});')
        pointer = '*' in result
        mask = sum(1 << i for i, p in enumerate(parameters) if p.get('pointer'))
        tests.append(f'    helper_id={number}; CHECK_HELPER({name}, {result}, {mask}, '
                     f'{"ARM64_SIM_TAG_MAP_VALUE" if pointer else "ARM64_SIM_TAG_SCALAR"},\n'
                     + '        ' + '\n        '.join(expected) + ');\n')
    text = HEADER.read_text()
    marker = '#define ARM64_SIM_L_HELPER_SCALAR_RESULT(EXPR)'
    start = text.index(marker if marker in text else '#define ARM64_SIM_BPF_CALL_bpf_map_lookup_elem()')
    end = text.index('#define ARM64_SIM_RET()', start)
    common = r'''#define ARM64_SIM_L_HELPER_SCALAR_RESULT(EXPR) \
    do { \
        __u64 __a64_helper_result = (__u64)(EXPR); \
        ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X0, __a64_helper_result, ARM64_WIDTH_64); \
    } while (0)

#define ARM64_SIM_L_HELPER_POINTER_RESULT(EXPR) \
    do { \
        void *__a64_helper_result = (void *)(EXPR); \
        ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0, __a64_helper_result, ARM64_SIM_TAG_MAP_VALUE); \
    } while (0)

'''
    HEADER.write_text(text[:start] + common + '\n'.join(bodies) + '\n' + text[end:])
    (HERE/'helper-abi.json').write_text(json.dumps(abi, indent=2)+'\n')
    host = '''/* Generated from vendored Linux helper signatures. Catches wrong helper
 * identity, argument order/width, stack projection, result or clobbered GPRs. */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;
#define __always_inline inline
#define ARM64_SIM_ENABLE_STACK 1
'''
    host += ''.join(f'#define {r["name"]} {r["name"]}_defs\n' for r in rows)
    host += '#include "../arm64/arm64_sim_local_bpf.h"\n'
    host += ''.join(f'#undef {r["name"]}\n' for r in rows)
    host += '''#include <stdio.h>
#include <stdarg.h>
#define RETURN_BITS 0xfedcba9876543210ULL
static unsigned failures, calls, seen_id, cases, helper_id;
static __u64 expected[5];
static __u64 value_for(unsigned i) { return 0x98765432fedcba00ULL + i; }
static void check_arg(unsigned index, __u64 got) {
    if (got != expected[index]) {
        printf("helper%u arg%u got%llx expected%llx\\n", seen_id, index, got, expected[index]);
        failures++;
    }
}
'''
    structs = sorted(set(re.findall(r'struct (\w+)', ' '.join(r['result']+' '+str(r['parameters']) for r in abi))))
    host += ''.join(f'struct {name};\n' for name in structs)
    host += '\n'.join(stubs)
    host += r'''#define CHECK_HELPER(NAME, RESULT, MASK, TAG, ...) \
    do { \
        ARM64_SIM_ENTRY_XDP(&ctx); \
        for (unsigned i=0; i<31; i++) { \
            ARM64_SIM_L_WRITE_REG_WIDTH(i, value_for(i), ARM64_WIDTH_64); \
            if (stack_mode && ((MASK) & (1ULL<<i))) \
                ARM64_SIM_L_WRITE_REG_PTR_TAG(i, (void *)-8L, ARM64_SIM_TAG_STACK); \
        } \
        __VA_ARGS__ \
        calls=0; seen_id=0; \
        __a64_n=0; __a64_z=1; __a64_c=1; __a64_v=0; \
        ARM64_SIM_BPF_CALL_##NAME(); \
        if (calls!=1 || seen_id!=helper_id || __a64_x0.x!=(__u64)(unsigned long)(RESULT)RETURN_BITS \
            || __a64_x0_tag!=(TAG) || __a64_n!=0 || __a64_z!=1 || __a64_c!=1 || __a64_v!=0) failures++; \
        for (unsigned i=1; i<31; i++) { \
            __u64 want = stack_mode && ((MASK) & (1ULL<<i)) ? (__u64)-8LL : value_for(i); \
            __u8 tag = stack_mode && ((MASK) & (1ULL<<i)) ? ARM64_SIM_TAG_STACK : ARM64_SIM_TAG_SCALAR; \
            if (ARM64_SIM_L_READ_REG(i)!=want || ARM64_SIM_L_REG_TAG(i)!=tag) failures++; \
        } \
        if (__a64_sp != 0 || __a64_lr != 0 || __a64_v0 != 0 || __a64_v0_hi != 0) failures++; \
        (void)__a64_sim_skb_ctx; (void)__a64_sim_abi_kind; \
        (void)&__a64_stack; (void)__a64_stack_tag[0]; \
        cases++; \
    } while (0)
'''
    host += 'static void run(unsigned stack_mode) {\n    struct xdp_md ctx={0};\n' + ''.join(tests) + '}\n'
    host += '''int main(void) {
    run(0); run(1);
    printf("arm64 real helper ABI: %u cases, %u failures\\n", cases, failures);
    return failures != 0;
}
'''
    (FORMAL/'oracles/test_arm64_helper_call_host.c').write_text(''.join(line.rstrip()+'\n' for line in host.splitlines()))
    print(f'rendered {len(rows)} real helper calls and identity/argument/result regressions')


if __name__ == '__main__':
    main()
