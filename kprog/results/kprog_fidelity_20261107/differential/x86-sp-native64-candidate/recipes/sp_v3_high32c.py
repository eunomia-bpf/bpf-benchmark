from pathlib import Path
import sys
ROOT=Path('/workspaces/repository');SOURCE=ROOT/'kprog/fidelity/build-sp-v3/source'
sys.path.insert(0,str(SOURCE/'kprog/fidelity'))
import negative
# Post-fix proof-load rejection controls only. These bodies are never executed.
negative.FIXTURES['x86']={}
for name,value in [('positive',0x100000000),('negative',0xffffffff00000000)]:
 for lane,kind in [('byte','BYTE'),('qword','QWORD')]:
  negative.FIXTURES['x86']['high32_'+name+'_'+lane]='mov rdx,rsp; sub rsp,16; mov QWORD PTR [rsp],37; mov ecx,1; shl rcx,32; '+('neg rcx; ' if name=='negative' else '')+'add rsp,rcx; '+('mov rax,QWORD PTR [rsp]; ' if lane=='qword' else 'movzx eax,BYTE PTR [rsp]; ')+'mov rsp,rdx; ret'

build=ROOT/'kprog/fidelity/build-sp-v3-high32c';out=ROOT/'kprog/results/kprog_fidelity_20261107/negative/x86-sp-v3-high32c'
if sys.argv[1]=='build':negative.build('x86',build)
else:sys.exit(negative.run_bound('x86',build,out,ROOT/'kprog/fidelity/build-abi-fixed/bound-probe',ROOT/'kprog/fidelity/build-abi-fixed/companion.bpf.o'))
