"""Execute both-safe STXR/STLXR programs with a bound per-site outcome."""
import json
from pathlib import Path
import shutil
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
for width in [4, 8]:
    for release in [False, True]:
        name = f'exclusive_{width}_{int(release)}'
        reg = 'w' if width == 4 else 'x'
        store = 'stlxr' if release else 'stxr'
        body = f'''stp x19,x30,[sp,#-32]!
ldr x19,[x0]
ldr x3,[x0,#8]
add x6,x19,#8
cmp x6,x3
b.hi fail
mov x4,#37
str x4,[sp,#16]
add x2,sp,#16
ldxr {reg}1,[x2]
mov x4,#41
{store} w3,{reg}4,[x2]
cbnz w3,not_written
ldr x4,[sp,#16]
sub x4,x4,#4
b finish
not_written: ldr x4,[sp,#16]
finish: str x4,[x19]
mov w0,#2
b done
fail: mov w0,#0
done: ldp x19,x30,[sp],#32
ret
'''
        asm = phase / 'native' / (name + '.S')
        asm.write_text('.text\n.global entry\n.type entry,%function\nentry:\n' + body + '.size entry,.-entry\n')
        native = asm.with_suffix('.native.o')
        subprocess.run(['aarch64-linux-gnu-gcc', '-c', asm, '-o', native], check=True)
        proof = asm.with_suffix('.proof.o')
        subprocess.run([ROOT / 'kprog/arm64/build/app-native-link/release/native-link',
            '--input', native, '--symbol', 'entry', '--mode', 'proof', '--preserve-entry-abi',
            '--output', proof], check=True)
        shutil.copy2(proof, phase / 'native' / (name + '.entry.proof.o'))
        functions, rodata = gen.parse_native_linked_program(gen.Bench(name, 'entry', 'xdp'), phase / 'native')
        (phase / (name + '.bpf.c')).write_text(gen.render_program(
            name, 'entry', functions, 'xdp', rodata16=rodata, linked_exit=True))
        (phase / (name + '.source.bpf.c')).write_text(
            '#include <linux/bpf.h>\n#include <bpf_helpers.h>\n'
            f'SEC("xdp") int {name}(struct xdp_md *ctx) {{ '
            'void *p=(void *)(long)ctx->data; void *e=(void *)(long)ctx->data_end; '
            'if (p+8>e) return 0; *(__u64 *)p=37; return 2; }\n'
            'char LICENSE[] SEC("license")="GPL";\n')
        (phase / (name + '.manifest.json')).write_text(json.dumps({'objects': [dict(
            program=name, source_btf_symbol=name, native_object='/cases/' + native.name,
            symbol='entry', simulator_object='/cases/' + name + '.bpf.o',
            simulator_program=name + '_arm64_sim_xdp')]}, indent=2) + '\n')
        rows.append(dict(name=name, expected=37, bound_only=True))
(phase / 'cases.json').write_text(json.dumps(rows, indent=2) + '\n')
coverage.freeze_simulator(phase)
for source in phase.glob('*.bpf.c'):
    source.write_text(source.read_text().replace('#include "../arm64_sim_local_bpf.h"',
        f'#include "{phase}/simulator/arm64_sim_local_bpf.h"'))
shutil.copy2(ROOT / 'kprog/fidelity/build-arm64/bound-probe', phase / 'bound-probe')
