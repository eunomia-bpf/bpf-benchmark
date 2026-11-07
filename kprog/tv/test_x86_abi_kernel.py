"""Build real simulator proofs; inspect JIT host preservation before safe execution."""
import argparse
import importlib.util
import json
import os
import re
import subprocess
import sys
from pathlib import Path
from extract_checked import decode

ROOT=Path(__file__).resolve().parents[2]
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('action',choices=['build','run'])
parser.add_argument('output',type=Path)
parser.add_argument('--probe',type=Path)
args=parser.parse_args()
if args.action=='build':
    sys.path.insert(0,str(ROOT/'kprog/fidelity'))
    spec=importlib.util.spec_from_file_location('abi_negative_builder',ROOT/'kprog/fidelity/negative.py')
    builder=importlib.util.module_from_spec(spec);spec.loader.exec_module(builder)
    rows=json.loads((ROOT/'kprog/tv/build/x86-native-abi/outcomes.json').read_text())
    selected={'bare_rbx','bare_r13','bare_r14','bare_r15','all_four','caller_saved'}
    builder.FIXTURES['x86']={row['name']:row['assembly'] for row in rows if row['name'] in selected}
    builder.build('x86',args.output)
    returncode=0
    for row in json.loads((args.output/'build.json').read_text())['cases']:
        if row['stage']!='generated':
            raise RuntimeError('ABI fixture proof did not compile: '+row['name']+' '+row['message'])
else:
    if args.probe is None:
        raise ValueError('--probe is required')
    masks={'bare_rbx':1,'bare_r13':2,'bare_r14':4,'bare_r15':8,'all_four':15,'caller_saved':0}
    regs=['rbx','r13','r14','r15']
    outcomes=[]
    for name,mask in masks.items():
        directory=args.output/name;directory.mkdir(parents=True,exist_ok=True)
        source=ROOT/'kprog/tv/build/x86-abi-proof'
        manifest=directory/'manifest.json'
        manifest.write_text(json.dumps({'objects':[dict(program='neg_source',source_btf_symbol='neg_source',
            native_object=str(source/(name+'.native.o')),symbol='entry',
            simulator_object=str(source/(name+'.bpf.o')),simulator_program=name+'_x86_sim_xdp')]},indent=2)+'\n')
        base=[str(args.probe.resolve()),str(ROOT/'kprog/fidelity/build-x86/negative-companion.bpf.o'),str(manifest.resolve())]
        env=dict(os.environ,BPFREJIT_NATIVE_LOADER_TV_DIR=str((directory/'load-only').resolve()))
        loaded=subprocess.run(base,env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
        (directory/'load-only.log').write_bytes(loaded.stdout)
        if loaded.returncode:
            raise RuntimeError('bound load failed: '+name+'\n'+loaded.stdout.decode())
        captures=list((directory/'load-only').glob('*/load.json'))
        if len(captures)!=1:
            raise ValueError('one actual bound load record required')
        capture=captures[0].parent
        _,metadata=decode((capture/'checked.snapshot.bin').read_bytes())
        if metadata['binding'][4]!=mask or not metadata['generation']:
            raise ValueError('actual verifier/JIT binding has wrong ABI mask')
        native=(capture/'native.bin').read_bytes();jit=(capture/'jit.bin').read_bytes()
        start=jit.find(native)
        if (capture/'native.relocs').read_bytes() or start<0 or jit.find(native,start+1)>=0:
            raise ValueError('one complete unrelocated actual native body required')
        disasm=subprocess.check_output(['objdump','-D','-b','binary','-m','i386:x86-64','-Mintel',
            '--insn-width=16',str(capture/'jit.bin')],text=True)
        (directory/'actual-jit.asm').write_text(disasm)
        preservation=[]
        for index,reg in enumerate(regs):
            if not mask & (1<<index):continue
            operations=[]
            for line in disasm.splitlines():
                match=re.match(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+(push|pop)\s+'+reg+r'\s*$',line)
                if match:operations.append((int(match[1],16),match[2]))
            if not any(offset<start and op=='push' for offset,op in operations) or \
                    not any(offset>=start+len(native) and op=='pop' for offset,op in operations):
                raise AssertionError('host register not saved/restored outside actual body: '+reg)
            preservation.append(reg)
        # This point is reached only after inspecting actual JIT preservation.
        env['BPFREJIT_NATIVE_LOADER_TV_DIR']=str((directory/'execution').resolve())
        executed=subprocess.run(base+['0','2'],env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
        (directory/'execution.log').write_bytes(executed.stdout)
        if executed.returncode or b'native_bound result=0 retval=2' not in executed.stdout:
            raise RuntimeError('preserved bound execution failed: '+name+'\n'+executed.stdout.decode())
        outcomes.append(dict(name=name,abi_mask=mask,load='passed',generation=metadata['generation'],
            host_registers_preserved=preservation,execution='passed',packet_result=0,retval=2))
        print(name+': actual bound ABI='+hex(mask)+' JIT preservation '+','.join(preservation)+
            '; native execution packet0/retval2 PASS',flush=True)
    (args.output/'outcomes.json').write_text(json.dumps(outcomes,indent=2)+'\n')
    print('actual generation-bound native ABI:6 load/inspection/execution controls PASS',flush=True)
