"""Measure width-gate CFGs before LLVM passes, without changing production flags."""
import argparse
import json
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]


def main(a):
    a.build.mkdir(parents=True, exist_ok=True)
    a.output.mkdir(parents=True, exist_ok=True)
    sys.path.insert(0, str(ROOT / 'kprog/x86'))
    import trusted_specializer as worker
    prefix = '#define X86_SIM_ENABLE_STACK 1\n#include ' + json.dumps(str(ROOT / 'kprog/x86/x86_sim_local_bpf.h')) + '\n'
    prefix += '''extern unsigned selected(unsigned);
#define CAPTURE_WIDTH(CODE) ({ const __u8 captured=(CODE); (__u8)KPROG_X86_WIDTH_EFFECTIVE(captured); })
'''
    variants = [('function', '', 'x86_width_effective(raw)'),
                ('const_function', 'const ', 'x86_width_effective(raw)'),
                ('contract', '', '(__u8)KPROG_X86_WIDTH_EFFECTIVE(raw)'),
                ('const_contract', 'const ', '(__u8)KPROG_X86_WIDTH_EFFECTIVE(raw)'),
                ('const_capture', 'const ', 'CAPTURE_WIDTH(raw)')]
    for name, qualifier, expression in variants:
        prefix += f'''unsigned probe_{name}(void) {{
{qualifier}__u8 raw=8;
{qualifier}__u8 width={expression};
if (KPROG_X86_WRITE_WIDTH_ARM(width)==KPROG_X86_WRITE_WIDTH_ARM_B8) return selected(1);
else if (KPROG_X86_WRITE_WIDTH_ARM(width)==KPROG_X86_WRITE_WIDTH_ARM_B16) return selected(2);
else if (KPROG_X86_WRITE_WIDTH_ARM(width)==KPROG_X86_WRITE_WIDTH_ARM_B32) return selected(4);
else return selected(8);
}}
'''
    prefix += '''unsigned probe_real_write(void *ctx) {
X86_SIM_ENTRY_RAW(ctx);
X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, (__u64)(long)ctx, X86_WIDTH_64);
return (__u32)(long)__x86_rax.ptr;
}
'''
    source, output = a.build / 'width.c', a.build / 'width.ll'
    source.write_text(prefix)
    # This is an observation of the pre-optimizer graph, not a B production
    # path or an optimization-level candidate. Normal -O3 flags remain present.
    command = [str(ROOT / 'kprog/stock-path/bin/clang'), *map(str, worker.COMPILE_FLAGS),
               '-Xclang', '-disable-llvm-passes', '-emit-llvm', '-S', str(source), '-o', str(output)]
    r = subprocess.run(command, capture_output=True, text=True)
    (a.output / 'command.json').write_text(json.dumps(dict(command=command, returncode=r.returncode,
        stdout=r.stdout, stderr=r.stderr), indent=2) + '\n')
    r.check_returncode()
    observations = []
    for name, body in re.findall(r'^define[^\n]*@(probe_\w+)\([^\n]*\{\n(.*?)^\}',
                                 output.read_text(), re.M | re.S):
        observations.append(dict(function=name, ir_bytes=len(body),
            branches=len(re.findall(r'^\s+br\b', body, re.M)),
            allocas=len(re.findall(r'\balloca\b', body)), selected_calls=body.count('@selected(')))
    (a.output / 'result.json').write_text(json.dumps(dict(observations=observations,
        scope='Small width-gate diagnostic before LLVM passes; no production change or actual OTel result'), indent=2) + '\n')
    print(json.dumps(observations))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'output'):
        p.add_argument('--' + name, type=Path, required=True)
    main(p.parse_args())
