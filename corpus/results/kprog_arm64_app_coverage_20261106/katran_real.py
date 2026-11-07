"""Generate the actual ARM Katran balancer with unchanged source map types."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
from elftools.elf.elffile import ELFFile
import coverage

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen

phase = Path(sys.argv[1]).resolve()
if len(sys.argv) > 2 and sys.argv[2] == 'install':
    stage = ROOT / 'kprog/arm64/build/app-verified-stage/katran'
    entry = json.loads((phase / 'manifest-entry.json').read_text())
    shutil.copy2(phase / 'native/balancer.native.o', stage / 'balancer.native.o')
    shutil.copy2(phase / 'native/katran_balancer_ingress.proof.o', stage / 'balancer.balancer_ingress.proof.o')
    shutil.copy2(phase / 'objects/katran_balancer_ingress.bpf.o', stage / 'katran_balancer_ingress.bpf.o')
    manifest = stage / 'manifest.json'
    data = json.loads(manifest.read_text())
    matches = [i for i, old in enumerate(data['objects']) if old.get('program') == entry['program']]
    if len(matches) != 1:
        raise RuntimeError('actual Katran balancer selector is not unique')
    data['objects'][matches[0]] = entry
    manifest.write_text(json.dumps(data, indent=2) + '\n')
    print('actual Katran balancer triple installed; every other entry retained')
    sys.exit(0)
phase.mkdir()
for name in ['native', 'original', 'upstream', 'sources']:
    (phase / name).mkdir()
upstream = phase / 'upstream'
shutil.copytree(ROOT / 'vendor/bpf/katran/katran/lib/bpf', upstream / 'katran/lib/bpf')
shutil.copytree(ROOT / 'vendor/bpf/katran/katran/lib/linux_includes', upstream / 'katran/lib/linux_includes')
wrapper = upstream / 'proof-input.bpf.c'
wrapper.write_text('#include <linux/bpf.h>\n#include <bpf_helpers.h>\n'
                   '#define __BPF_HELPERS_H\n#include "katran/lib/bpf/balancer.c"\n')
native = phase / 'native/balancer.native.o'
shutil.copy2(ROOT / 'vendor/build/native-bpf/arm64/stage/katran/balancer.native.o', native)
original = phase / 'original/balancer.bpf.o'
shutil.copy2(ROOT / 'vendor/build/arm64/katran/bpf/balancer.bpf.o', original)
with original.open('rb') as stream:
    elf = ELFFile(stream)
    symbols = {s.name for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name}
name = 'katran_balancer_ingress'
proof = phase / 'native' / (name + '.proof.o')
command = list(map(str, [ROOT / 'kprog/arm64/build/app-native-link/release/native-link',
    '--input', native, '--symbol', 'balancer_ingress', '--mode', 'proof',
    '--preserve-entry-abi', '--output', proof]))
result = subprocess.run(command, capture_output=True, text=True, timeout=120)
(phase / 'link.json').write_text(json.dumps(dict(command=command, returncode=result.returncode,
    stdout=result.stdout, stderr=result.stderr), indent=2) + '\n')
if result.returncode:
    raise RuntimeError(result.stderr)
functions, rodata = gen.parse_native_linked_program(gen.Bench(name, 'balancer_ingress', 'xdp'), phase / 'native')
source = phase / 'sources' / (name + '.bpf.c')
text = gen.render_program(name, 'balancer_ingress', functions, 'xdp', rodata16=rodata,
    linked_exit=True, original_source=wrapper, original_symbols=symbols)
source.write_text(text)
rows = [dict(name=name, proof=str(proof), source=str(source), stage='generate', ok=True, note='',
    original_object=str(original), original_name='balancer_ingress', program_type=6,
    program_section='xdp', compiler_flags=['-D__aarch64__', '-I' + str(upstream),
        '-I/usr/aarch64-linux-gnu/include'])]
(phase / 'programs.jsonl').write_text(''.join(json.dumps(row) + '\n' for row in rows))
(phase / 'manifest-entry.json').write_text(json.dumps(dict(program='balancer_ingres',
    source_btf_symbol='balancer_ingress', prog_type=6, native_object='balancer.native.o',
    symbol='balancer_ingress', simulator_object=name + '.bpf.o',
    simulator_program=name + '_arm64_sim_xdp'), indent=2) + '\n')
coverage.freeze_simulator(phase)
