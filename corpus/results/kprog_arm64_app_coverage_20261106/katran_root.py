"""Pair Katran's actual xdp_root entry with its unchanged upstream map layout."""
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
if len(sys.argv) > 2 and sys.argv[2] == 'install':
    stage = ROOT / 'kprog/arm64/build/app-verified-stage/katran'
    shutil.copy2(phase / 'native/katran_xdp_root.native.o', stage / 'xdp_root.native.o')
    shutil.copy2(phase / 'native/katran_xdp_root.xdp_root.proof.o', stage / 'xdp_root.xdp_root.proof.o')
    shutil.copy2(phase / 'katran_xdp_root.bpf.o', stage / 'katran_xdp_root.bpf.o')
    manifest = stage / 'manifest.json'
    data = json.loads(manifest.read_text())
    entry = json.loads((phase / 'manifest-entry.json').read_text())
    matches = [i for i, old in enumerate(data['objects']) if old.get('program') == 'xdp_root']
    if len(matches) != 1:
        raise RuntimeError('Katran xdp_root selector is not unique')
    data['objects'][matches[0]] = entry
    manifest.write_text(json.dumps(data, indent=2) + '\n')
    print('actual Katran root triple installed; all other entries retained')
    sys.exit(0)
phase.mkdir()
(phase / 'native').mkdir()
name = 'katran_xdp_root'
native = phase / 'native' / (name + '.native.o')
shutil.copy2(ROOT / 'vendor/build/native-bpf/arm64/stage/katran/xdp_root.native.o', native)
source = ROOT / 'vendor/bpf/katran/katran/lib/bpf/xdp_root.c'
prelude = gen.source_prelude(source).replace('#include "bpf.h"', '#include <linux/bpf.h>')
prelude = prelude.replace('#include "bpf_helpers.h"', '#include <bpf_helpers.h>')
(phase / 'original-source.c').write_text(source.read_text())
(phase / 'original-map-prelude.c').write_text(prelude + '\n')
proof = phase / 'native' / (name + '.proof.o')
subprocess.run([ROOT / 'kprog/arm64/build/app-native-link/release/native-link',
    '--input', native, '--symbol', 'xdp_root', '--mode', 'proof',
    '--preserve-entry-abi', '--output', proof], check=True)
shutil.copy2(proof, phase / 'native' / (name + '.xdp_root.proof.o'))
functions, rodata = gen.parse_native_linked_program(gen.Bench(name, 'xdp_root', 'xdp'), phase / 'native')
# This entry passes its context to tail_call without reading packet fields.
# Preserve that real context identity instead of constructing a packet mirror.
text = gen.render_program(name, 'xdp_root', functions, 'raw', prelude=prelude,
                          rodata16=rodata, linked_exit=True, program_section='xdp')
coverage.freeze_simulator(phase)
(phase / (name + '.bpf.c')).write_text(text.replace('#include "../arm64_sim_local_bpf.h"',
    f'#include "{phase}/simulator/arm64_sim_local_bpf.h"'))
(phase / 'manifest-entry.json').write_text(json.dumps(dict(program='xdp_root', prog_type=6,
    native_object='xdp_root.native.o', symbol='xdp_root', simulator_object=name + '.bpf.o',
    simulator_program=name + '_arm64_sim_xdp'), indent=2) + '\n')
entry = json.loads((phase / 'manifest-entry.json').read_text())
entry.update(native_object='/cases/' + native.name, simulator_object='/cases/' + name + '.bpf.o')
(phase / (name + '.manifest.json')).write_text(json.dumps({'objects': [entry]}, indent=2) + '\n')
(phase / 'cases.json').write_text(json.dumps([dict(name=name, expected=0)], indent=2) + '\n')
shutil.copy2(phase.parent / 'fmov-bank-bound-v2/bound-probe', phase / 'bound-probe')
