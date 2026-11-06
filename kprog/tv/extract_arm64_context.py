"""Retain the actual raw/physical bytes and load attributes from the Arm guest."""
from pathlib import Path
import json
import re

root = Path(__file__).resolve().parent
log = (root/'build-arm64/context-kernel.log').read_text()
output = root/'build/simple-context-arm64'
output.mkdir(exist_ok=True)
for suffix in ['raw.bin','xlated.bin','context.json']:
    matches = re.findall(r'^TV_CAPTURE '+re.escape(suffix)+r' ([0-9a-f]+)\r?$',log,re.M)
    if len(matches) != 1:
        raise ValueError('missing/duplicate actual Arm capture '+suffix)
    (output/('simple_arm64_sim_xdp.'+suffix)).write_bytes(bytes.fromhex(matches[0]))
x86 = root/'build/simple-context'
for suffix in ['raw.bin','xlated.bin']:
    if (output/('simple_arm64_sim_xdp.'+suffix)).read_bytes() != (x86/('simple_arm64_sim_xdp.'+suffix)).read_bytes():
        raise ValueError('Arm/x86 physical context inputs differ; update the explicit platform instantiation')
context = json.loads((output/'simple_arm64_sim_xdp.context.json').read_text())
if (context['version'],context['program_type'],context['expected_attach_type'],context['prog_flags'],context['attach_btf_id']) != (1,6,37,0,0) or context['source_prog_id'] <= 0:
    raise ValueError('actual Arm kernel load context differs from this platform instantiation')
print('actual Arm kernel: exact same complete clang/physical bytes and type6/attach37/flags0 as the checked platform inputs: PASS')
