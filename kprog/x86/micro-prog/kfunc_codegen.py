"""Typed SysV register bridge for kernel functions described by target BTF."""
REGISTERS = ('X86_RDI', 'X86_RSI', 'X86_RDX', 'X86_RCX', 'X86_R8', 'X86_R9')


def declarations(functions):
    lines = sorted({line for f in functions.values() if f['present'] for line in f['forwards']})
    for name, function in functions.items():
        result = function['result']['type'] if function['present'] else 'void'
        args = ', '.join(arg['type'] for arg in function['arguments']) if function['present'] else ''
        weak = ' __weak' if function['weak'] else ''
        lines.append(f'extern {result} {name}({args or "void"}) __ksym{weak};')
    return lines


def call(function, indent):
    if not function['present']:
        return [indent + '__x86_sim_unresolved_indirect_target();']
    args = []
    for arg, reg in zip(function['arguments'], REGISTERS, strict=False):
        read = 'X86_SIM_L_HELPER_CTX_PTR' if arg['pointer'] else 'X86_SIM_L_READ_REG'
        value = f'{read}({reg})'
        if not arg['pointer']:
            value = f'(__u{arg["size"] * 8})({value})'
        args.append(f'({arg["type"]})({value})')
    if len(args) != len(function['arguments']):
        raise ValueError('kernel function exceeds register argument ABI')
    expression = function['name'] + '(' + ', '.join(args) + ')'
    result = function['result']; lines = [indent + 'do {']
    if result['type'] == 'void':
        lines.extend([indent + '    ' + expression + ';',
            indent + '    X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, X86_SIM_L_UNSPECIFIED(), X86_WIDTH_64);'])
    elif result['pointer']:
        lines.extend([indent + '    void *__kfunc_result = (void *)' + expression + ';',
            indent + '    X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, __kfunc_result, X86_SIM_TAG_MAP_VALUE);'])
    else:
        bits = result['size'] * 8
        lines.append(indent + '    __u64 __kfunc_result = (__u64)' + expression + ';')
        if bits < 32:
            lines.append(indent + '    X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, X86_SIM_L_UNSPECIFIED(), X86_WIDTH_64);')
        lines.append(indent + f'    X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __kfunc_result, X86_WIDTH_{bits});')
    for arg, reg in zip(function['arguments'], REGISTERS):
        if not arg['pointer']:
            continue
        # BTF constness is a type qualifier, not a proven memory-effect summary.
        lines.append(indent + f'    if (X86_SIM_L_REG_TAG({reg}) == X86_SIM_TAG_STACK || (X86_SIM_L_REG_TAG({reg}) == X86_SIM_TAG_SCALAR && X86_SIM_L_READ_REG({reg}) != 0)) X86_SIM_L_STACK_VALUES_CLEAR();')
    lines.extend([indent + '    X86_SIM_L_STACK_VALUES_CALL_FRAME();',
                  indent + '    X86_SIM_L_HELPER_REGISTER_CLOBBERS();', indent + '} while (0);'])
    return lines
