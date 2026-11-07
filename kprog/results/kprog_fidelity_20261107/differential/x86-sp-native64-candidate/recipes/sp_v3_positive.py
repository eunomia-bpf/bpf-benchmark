from pathlib import Path
import importlib.util,json,os,subprocess,sys
ROOT=Path('/workspaces/repository');SOURCE=ROOT/'kprog/fidelity/build-sp-v3/source'
sys.path.insert(0,str(SOURCE/'kprog/fidelity'))
import negative
FIXTURES={
 'xchg_stack_alias':'sub rsp,16; mov QWORD PTR [rsp],37; mov rax,rsp; xchg rax,rcx; mov edx,DWORD PTR [rcx]; add rsp,16; cmp edx,37; jne 1f; mov eax,2; ret; 1: mov eax,0; ret',
 'xchg_stack_restore':'mov rdx,rsp; mov rax,rsp; xchg rax,rsp; mov rsp,rdx; mov eax,2; ret',
 'copy_restore':'mov rax,rsp; mov rsp,rax; mov eax,2; ret',
 'alias_load':'sub rsp,16; mov QWORD PTR [rsp],37; mov rax,rsp; mov ecx,DWORD PTR [rax]; add rsp,16; cmp ecx,37; jne 1f; mov eax,2; ret; 1: mov eax,0; ret',
 'spill_restore':'sub rsp,32; lea rax,[rsp+16]; mov [rsp],rax; mov rax,[rsp]; mov rsp,rax; add rsp,16; mov eax,2; ret',
 'partial_alias':'mov rax,rsp; mov al,1; cmp al,1; jne 1f; mov eax,2; ret; 1: mov eax,0; ret',
}
build=ROOT/'kprog/fidelity/build-sp-v3-positive';out=ROOT/'kprog/results/kprog_fidelity_20261107/negative/x86-sp-v3-positive'
if sys.argv[1]=='build':
 negative.FIXTURES['x86']=FIXTURES;negative.build('x86',build)
 for row in json.loads((build/'build.json').read_text())['cases']:
  if row['stage']!='generated':raise ValueError('valid proof failed to build: '+row['name']+' '+row['message'])
else:
 out.mkdir(parents=True,exist_ok=True);rows=[]
 for name,assembly in FIXTURES.items():
  plan=out/(name+'.manifest.json');plan.write_text(json.dumps({'objects':[dict(program='neg_source',source_btf_symbol='neg_source',native_object=str(build/(name+'.native.o')),symbol='entry',simulator_object=str(build/(name+'.bpf.o')),simulator_program=name+'_x86_sim_xdp')]},indent=2)+'\n')
  command=[str(ROOT/'kprog/fidelity/build-abi-fixed/bound-probe'),str(ROOT/'kprog/fidelity/build-abi-fixed/companion.bpf.o'),str(plan),'0','2']
  env=dict(os.environ,BPFREJIT_NATIVE_LOADER_TV_DIR=str(out/(name+'-capture')))
  result=subprocess.run(command,cwd=ROOT/'kprog/fidelity',env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
  (out/(name+'.log')).write_bytes(result.stdout)
  row=dict(name=name,assembly=assembly,returncode=result.returncode,command=command,message=result.stdout.decode());rows.append(row)
  print(name,'returncode',result.returncode,flush=True)
 (out/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
 if any(row['returncode'] for row in rows):raise SystemExit(1)
