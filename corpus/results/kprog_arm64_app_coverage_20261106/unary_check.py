"""Replay real modified unary encodings through the existing full-state CPU driver."""
from pathlib import Path
import sys
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
import generate
forms=[]
for width in ['w','x']:
    for op in ['mvn','neg']:
        for modifier in ['lsl','lsr','asr']+(['ror'] if op=='mvn' else []):
            for shift in [0,1,3,31]+([32,63] if width=='x' else []):
                forms.append(f'{op} {width}0, {width}1, {modifier} #{shift}')
generate.arm64_forms=lambda: forms
generate.main()
