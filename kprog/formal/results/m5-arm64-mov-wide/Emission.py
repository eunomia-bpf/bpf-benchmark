# Data-only audit of the live production emitter; no ISA oracle or source copy.
from pathlib import Path
import dataclasses, importlib.util, json, sys

root=Path(__file__).resolve().parents[4]
directory=root/'kprog/arm64/micro-prog'
sys.path.insert(0,str(directory))
spec=importlib.util.spec_from_file_location('wide_source_emitter',directory/'generate_micro_sim_proofs.py')
if spec is None or spec.loader is None:
    raise RuntimeError('live ARM64 emitter module is unavailable')
encoder=importlib.util.module_from_spec(spec)
sys.modules[spec.name]=encoder
spec.loader.exec_module(encoder)
rows=[]
for register,columns in [('w30',range(2)),('x30',range(4))]:
    for mnemonic in ['movz','movn']:
        for column in columns:
            for immediate in [0,1,0x8000,0xffff]:
                operands=(register,f'#{immediate:#x}',f'lsl #{16*column}')
                text=mnemonic+' '+', '.join(operands)
                source=encoder.NativeInsn(32,mnemonic,operands,text,'target',7)
                normalized=encoder.normalize_alias(source)
                encoded=encoder.encode(source,{}, {})
                rows.append({'source':dataclasses.asdict(source),
                  'normalized':dataclasses.asdict(normalized),'encoded':dataclasses.asdict(encoded)})
print(json.dumps({'emitter':'kprog/arm64/micro-prog/generate_micro_sim_proofs.py',
  'functions':['normalize_alias','encode'],'records':rows},indent=2))
