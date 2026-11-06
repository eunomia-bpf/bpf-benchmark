"""Catch wrong helper IDs, fake returns, and misplaced/truncated SysV arguments."""
import json
import subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
rows=json.loads((HERE/'helper-abi.json').read_text())
lines=['#include <linux/bpf.h>','#include <bpf_helpers.h>','#include <stdint.h>',
       '#include <stdarg.h>','#include <stdio.h>',
       'static unsigned called, count; static uint64_t observed[5];',
       'static const uint64_t inputs[5]={0x123456789abcdef0ULL,0x223456789abcdef1ULL,0x323456789abcdef2ULL,0x423456789abcdef3ULL,0x523456789abcdef4ULL};']
for r in rows:
    result=r['result'].replace('__bpf_fastcall','').strip()
    ps=r['parameters']
    signature=', '.join('...' if p.get('variadic') else p['type']+' '+p['name'] for p in ps) or 'void'
    lines.append(f'static {result} fixture_{r["name"]}({signature}) {{')
    lines.append(f'called={r["id"]}; count={5 if any(p.get("variadic") for p in ps) else len(ps)};')
    for i,p in enumerate(ps):
        if p.get('variadic'):
            lines.append(f'va_list ap; va_start(ap,{ps[i-1]["name"]});')
            lines.extend(f'observed[{j}]=va_arg(ap,uint64_t);' for j in range(i,5))
            lines.append('va_end(ap);')
        else:
            lines.append(f'observed[{i}]=(uint64_t)(uintptr_t){p["name"]};')
    lines.append(f'return ({result})(uintptr_t)0xfedcba9876543210ULL; }}')
    lines.append(f'_Static_assert(__builtin_types_compatible_p(__typeof__({r["name"]}),__typeof__(&fixture_{r["name"]})),"helper signature drift");')
    lines.append(f'#define {r["name"]}(...) fixture_{r["name"]}(__VA_ARGS__)')
lines.extend([f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"',
              'int main(void) { X86_SIM_L_DECLARE_STATE(); unsigned failures=0;'])
regs=['X86_RDI','X86_RSI','X86_RDX','X86_RCX','X86_R8']
for r in rows:
    result=r['result'].replace('__bpf_fastcall','').strip()
    n=5 if any(p.get('variadic') for p in r['parameters']) else len(r['parameters'])
    lines.append(f'_Static_assert(X86_SIM_HELPER_{r["name"]}==BPF_FUNC_{r["name"].removeprefix("bpf_")},"Linux helper number drift");')
    for route in (f'X86_SIM_BPF_CALL_{r["name"]}()',f'X86_SIM_BPF_CALL_ID({r["id"]}ULL)'):
        lines.extend(f'X86_SIM_L_WRITE_REG_WIDTH({reg},inputs[{i}],X86_WIDTH_64);' for i,reg in enumerate(regs))
        lines += ['called=0; count=0;',route+';',f'failures += called!={r["id"]} || count!={n};',
                  f'failures += X86_SIM_L_READ_REG(X86_RAX)!=(uint64_t)(uintptr_t)({result})(uintptr_t)0xfedcba9876543210ULL;']
        for i in range(n):
            p=r['parameters'][min(i,len(r['parameters'])-1)]
            typ='uint64_t' if p.get('variadic') else p['type']
            lines.append(f'failures += observed[{i}]!=(uint64_t)(uintptr_t)({typ})inputs[{i}];')
lines+=['printf("65 Linux helper signatures, 130 direct/ID routes: %u failures\\n",failures); return failures!=0; }']
(HERE/'indirect-build/helper-abi.c').write_text('\n'.join(lines)+'\n')

for number in (0,999):
    source=HERE/'indirect-build'/f'unknown-helper-{number}.c'
    source.write_text(f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"\n'
                      f'void probe(void) {{ X86_SIM_L_DECLARE_STATE(); X86_SIM_BPF_CALL_ID({number}ULL); }}\n')
    command=['cc','-O2','-I'+str(ROOT/'vendor/libbpf/src'),'-I'+str(ROOT/'vendor/libbpf/include/uapi'),
             '-c',str(source),'-o',str(source.with_suffix('.o'))]
    result=subprocess.run(command,text=True,capture_output=True,timeout=60)
    (source.with_suffix('.json')).write_text(json.dumps(dict(command=command,returncode=result.returncode,
                                                            stdout=result.stdout,stderr=result.stderr))+'\n')
    assert result.returncode!=0 and 'unresolved x86 helper ID' in result.stderr, result.stderr
    print('unknown Linux helper ID',number,'rejected during compilation')
