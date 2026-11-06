"""Exercise both targets of real ARM CODE-valued BR and BLR dispatches."""
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import coverage

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen

phase = Path(sys.argv[1]).resolve()
phase.mkdir()
(phase / 'native').mkdir()
rows = []
checks = []
plan = phase / 'plan.json'
plan.write_text(json.dumps(dict(version=1, helpers=[dict(
    name='bpf_get_current_uid_gid', addr=0xffff800012340000)])) + '\n')
linker = ROOT / 'kprog/arm64/build/app-native-link/release/native-link'
for call in [False, True]:
    for flip in [0, 1]:
        name = f'code_{"call" if call else "branch"}_{flip}'
        prefix = '''stp x19,x30,[sp,#-32]!
ldr x19,[x0]
ldr x3,[x0,#8]
add x6,x19,#8
cmp x6,x3
b.hi fail
bl bpf_get_current_uid_gid
ldr x5,[x19]
'''
        if flip:
            prefix += 'eor x5,x5,#1\n'
        prefix += '''cmp x5,#0
adr x8,case37
adr x9,case41
csel x10,x8,x9,eq
'''
        if call:
            body = prefix + 'blr x10\nb finish\n'
        else:
            body = prefix + '''br x10
case37: mov x0,#37
b finish
case41: mov x0,#41
'''
        body += '''finish: str x0,[x19]
mov w0,#2
b done
fail: mov w0,#0
done: ldp x19,x30,[sp],#32
ret
'''
        text = '.text\n.global entry\n.type entry,%function\nentry:\n' + body + '.size entry,.-entry\n'
        if call:
            for value in [37, 41]:
                text += f'.type case{value},%function\ncase{value}:\nmov x0,#{value}\nret\n.size case{value},.-case{value}\n'
        asm = phase / 'native' / (name + '.S')
        asm.write_text(text)
        native = asm.with_suffix('.native.o')
        subprocess.run(['aarch64-linux-gnu-gcc', '-c', asm, '-o', native], check=True)
        proof = phase / 'native' / (name + '.proof.o')
        subprocess.run([ROOT / 'kprog/arm64/build/app-native-link/release/native-link',
                        '--input', native, '--symbol', 'entry', '--mode', 'proof',
                        '--preserve-entry-abi', '--output', proof], check=True)
        shutil.copy2(proof, phase / 'native' / (name + '.entry.proof.o'))
        blob = phase / 'native' / (name + '.bin')
        subprocess.run([linker, '--input', proof, '--symbol', 'entry', '--mode', 'kernel',
                        '--link-plan', plan, '--output', blob,
                        '--output-relocs', blob.with_suffix('.relocs.bin')], check=True)
        data = blob.read_bytes()
        targets = []
        for offset in range(0, len(data), 4):
            word = struct.unpack_from('<I', data, offset)[0]
            if word & 0x9f00001f not in [0x10000008, 0x10000009]:
                continue
            imm = ((word >> 29) & 3) | (((word >> 5) & 0x7ffff) << 2)
            target = offset + (imm if imm < 1 << 20 else imm - (1 << 21))
            value = 37 if word & 31 == 8 else 41
            if target < 0 or target + 4 > len(data) or struct.unpack_from('<I', data, target)[0] != 0xd2800000 | (value << 5):
                raise RuntimeError('CODE relocation missed the actual final target')
            targets.append(dict(offset=offset, target=target, value=value))
        if len(targets) != 2:
            raise RuntimeError('missing finite CODE relocation')
        checks.append(dict(name=name, targets=targets))
        functions, rodata = gen.parse_native_linked_program(gen.Bench(name, 'entry', 'xdp'), phase / 'native')
        (phase / (name + '.bpf.c')).write_text(gen.render_program(
            name, 'entry', functions, 'xdp', rodata16=rodata, linked_exit=True))
        (phase / (name + '.source.bpf.c')).write_text(
            '#include <linux/bpf.h>\n#include <bpf_helpers.h>\n'
            f'SEC("xdp") int {name}(struct xdp_md *ctx) {{ '
            'void *p=(void *)(long)ctx->data; void *e=(void *)(long)ctx->data_end; '
            'if (p+8>e) return 0; bpf_get_current_uid_gid(); '
            f'*(__u64 *)p=((*(__u64 *)p ^ {flip}ULL)==0) ? 37 : 41; return 2; }}\n'
            'char LICENSE[] SEC("license")="GPL";\n')
        (phase / (name + '.manifest.json')).write_text(json.dumps({'objects': [dict(
            program=name, source_btf_symbol=name, native_object='/cases/' + native.name,
            symbol='entry', simulator_object='/cases/' + name + '.bpf.o',
            simulator_program=name + '_arm64_sim_xdp')]}, indent=2) + '\n')
        rows.append(dict(name=name, expected=41 if flip else 37))
(phase / 'cases.json').write_text(json.dumps(rows, indent=2) + '\n')
(phase / 'checks.json').write_text(json.dumps(checks, indent=2) + '\n')
# These candidates are inspected only; unknown targets are never executed.
negative = []
for name, replacement in [('unknown_join', 'ldr x8,[x19]'),
                          ('narrow_code', 'mov w8,w8'),
                          ('helper_clobber', 'bl bpf_get_current_uid_gid')]:
    asm = phase / 'native' / (name + '.S')
    base = (phase / 'native/code_branch_0.S').read_text()
    asm.write_text(base.replace('csel x10,x8,x9,eq', replacement + '\ncsel x10,x8,x9,eq'))
    native = asm.with_suffix('.native.o')
    subprocess.run(['aarch64-linux-gnu-gcc', '-c', asm, '-o', native], check=True)
    proof = asm.with_suffix('.proof.o')
    subprocess.run([linker, '--input', native, '--symbol', 'entry', '--mode', 'proof',
        '--preserve-entry-abi', '--output', proof], check=True)
    output = native.with_suffix('.bad.bin')
    result = subprocess.run([linker, '--input', proof, '--symbol', 'entry', '--mode', 'kernel',
        '--link-plan', plan, '--output', output], capture_output=True, text=True, check=False)
    negative.append(dict(name=name, returncode=result.returncode, stderr=result.stderr))
    (phase / 'negative-checks.json').write_text(json.dumps(negative, indent=2) + '\n')
    if result.returncode != 1 or 'branch br x10' not in result.stderr or output.exists():
        raise RuntimeError('unknown CODE target was admitted or produced partial output')
coverage.freeze_simulator(phase)
for source in phase.glob('*.bpf.c'):
    source.write_text(source.read_text().replace('#include "../arm64_sim_local_bpf.h"',
        f'#include "{phase}/simulator/arm64_sim_local_bpf.h"'))
shutil.copy2(phase.parent / 'fmov-bank-bound-v2/bound-probe', phase / 'bound-probe')
