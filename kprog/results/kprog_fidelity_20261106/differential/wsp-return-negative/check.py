"""Catch acceptance of an ABI-breaking WSP write after enabling its decoder."""
from collections import OrderedDict
import json
from pathlib import Path
import subprocess
import sys

root = Path(__file__).resolve().parents[5]
sys.path.insert(0, str(root/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as encoder

obj = Path(sys.argv[1])
dump = subprocess.check_output(['aarch64-linux-gnu-objdump', '-d', str(obj)], text=True)
obj.with_suffix('.asm').write_text(dump)
program = encoder.parse_flat_instructions(dump)
try:
    encoder.render_program('wsp_return', 'entry', OrderedDict(entry=program), 'xdp')
except ValueError as error:
    if 'unbalanced stack pointer' not in str(error):
        raise
    Path('outcome.json').write_text(json.dumps(dict(stage='specialization', error=str(error)), indent=2)+'\n')
    print(error)
else:
    raise RuntimeError('unsafe WSP return was accepted by the constructor')
