"""Render the observed Linux helper ABI from vendored libbpf declarations."""
import json
from pathlib import Path
import re
import sys

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog'))
from helper_abi import helper_prototypes
prototypes=helper_prototypes()
rows=json.loads(Path(__file__).with_name('helper-abi.json').read_text())
registers=['X86_RDI','X86_RSI','X86_RDX','X86_RCX','X86_R8']
abi=[]
bodies=[]
for row in rows:
    name=row['name']
    declaration=prototypes[name]
    result,arguments,number=declaration.result,declaration.arguments,declaration.number
    assert number==row['id']
    parameters=[]
    expressions=[]
    for index,arg in enumerate([] if arguments=='void' else arguments.split(',')):
        arg=arg.strip()
        if arg=='...':
            expressions.extend(f'X86_SIM_L_READ_REG({r})' for r in registers[index:])
            parameters.append(dict(variadic=True))
            break
        match=re.fullmatch(r'(.*?)([A-Za-z_]\w*)',arg)
        assert match,arg
        typ=match[1].strip()
        pointer='*' in typ
        expressions.append(f'({typ})'+ ('X86_SIM_L_HELPER_ARG_PTR' if pointer else 'X86_SIM_L_READ_REG')+f'({registers[index]})')
        parameters.append(dict(type=typ,name=match[2],pointer=pointer))
    body='X86_SIM_L_HELPER_POINTER_RESULT' if '*' in result else 'X86_SIM_L_HELPER_SCALAR_RESULT'
    bodies.append(f'#define X86_SIM_BPF_CALL_{name}() \\\n\t{body}({name}({", ".join(expressions)}))\n')
    abi.append(dict(id=number,name=name,result=result,parameters=parameters))
Path('/workspaces/.agent-state/kprog-lanes/C/helper-abi.json').write_text(json.dumps(abi,indent=2)+'\n')
Path(__file__).with_name('helper-abi.json').write_text(json.dumps(abi,indent=2)+'\n')
header=ROOT/'kprog/x86/x86_sim_local_bpf.h'
text=header.read_text()
start=text.index('#define X86_SIM_HELPER_bpf_map_lookup_elem ')
end=text.index('/* The helper-id -> helper-body dispatch contract.',start)
text=text[:start]+''.join(f'#define X86_SIM_HELPER_{r["name"]} {r["id"]}ULL\n' for r in rows)+'\n'+text[end:]
start=text.index('#define X86_SIM_BPF_CALL_bpf_map_lookup_elem()')
end=text.index('#define X86_SIM_BPF_CALL_REG(REG)',start)
common='''/* No machine code is emitted for an unresolved helper: specialization must
 * eliminate this declaration's call before an artifact can compile. */
extern void __x86_sim_unsupported_helper(void)
    __attribute__((error("unresolved x86 helper ID")));
#define X86_SIM_L_UNSUPPORTED_HELPER() __x86_sim_unsupported_helper()

#define X86_SIM_L_HELPER_SCALAR_RESULT(EXPR) \\
    do { \\
        __u64 __x86_helper_result = (__u64)(EXPR); \\
        X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, __x86_helper_result, X86_WIDTH_64); \\
    } while (0)

#define X86_SIM_L_HELPER_POINTER_RESULT(EXPR) \\
    do { \\
        void *__x86_helper_result = (void *)(EXPR); \\
        X86_SIM_L_WRITE_REG_PTR_TAG(X86_RAX, __x86_helper_result, X86_SIM_TAG_MAP_VALUE); \\
    } while (0)

'''
ladder=['#define X86_SIM_BPF_CALL_ID(ID) \\', '\tdo { \\', '\t\tswitch (KPROG_X86_HELPER_SLOT((__u64)(ID))) { \\']
for r in rows:
    ladder += [f'\t\tcase KPROG_X86_HELPER_SLOT(X86_SIM_HELPER_{r["name"]}): \\',
               f'\t\t\tX86_SIM_BPF_CALL_{r["name"]}(); \\', '\t\t\tbreak; \\']
ladder+=['\t\tdefault: X86_SIM_L_UNSUPPORTED_HELPER(); break; \\', '\t\t} \\', '\t} while (0)', '']
text=text[:start]+common+'\n'.join(bodies)+'\n'+'\n'.join(ladder)+'\n'+text[end:]
header.write_text(text)
print('rendered',len(rows),'typed helpers from vendor/libbpf/src/bpf_helper_defs.h')
