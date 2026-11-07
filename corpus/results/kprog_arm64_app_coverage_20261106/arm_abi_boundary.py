"""Real-ELF regression for ARM proof ABI metadata hiding body/callee clobbers."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[3]
out=Path(sys.argv[1]).resolve();out.mkdir(exist_ok=True)
new=ROOT/'kprog/arm64/build/app-native-link/release/native-link'
old=ROOT/'kprog/arm64/build/abi-boundary-baseline/target/release/native-link'
plan=out/'plan.json';plan.write_text(json.dumps(dict(version=1,helpers=[dict(name='bpf_get_current_uid_gid',addr=0xffff800000100000)]))+'\n')
records=[]
def run(name,args,expect):
 r=subprocess.run(list(map(str,args)),capture_output=True,text=True)
 record=dict(case=name,command=list(map(str,args)),returncode=r.returncode,stdout=r.stdout,stderr=r.stderr)
 records.append(record);(out/'commands.json').write_text(json.dumps(records,indent=2)+'\n')
 assert (r.returncode==0)==expect,(name,r.returncode,r.stderr)
 return r
cases=[]
for reg in range(19,23):
 for width in ['x','w']:cases.append((f'{width}{reg}',f'mov {width}{reg},#2\nmov w0,#2\nret\n','',1<<(reg-19)))
cases += [('pair','ldp x19,x20,[x0]\nmov w0,#2\nret\n','',3),
 ('writeback','str x0,[x21,#8]!\nmov w0,#2\nret\n','',4),
 ('exclusive_status','stlxr w22,x0,[x1]\nmov w0,#2\nret\n','',8),
 ('callee','stp x29,x30,[sp,#-16]!\nbl leaf\nldp x29,x30,[sp],#16\nret\n','mov x22,#2\nmov w0,#2\nret\n',8),
 ('helper_and_callee','stp x29,x30,[sp,#-16]!\nbl bpf_get_current_uid_gid\nbl leaf\nldp x29,x30,[sp],#16\nret\n','mov w21,#2\nmov w0,#2\nret\n',4)]
summary=[]
for name,body,leaf,required in cases:
 asm=out/(name+'.S');native=out/(name+'.native.o');proof=out/(name+'.proof.o')
 asm.write_text('.text\n.global entry\n.type entry,%function\nentry:\n'+body+'.size entry,.-entry\n'+
  ('.global leaf\n.type leaf,%function\nleaf:\n'+leaf+'.size leaf,.-leaf\n' if leaf else ''))
 run(name+' assemble',['aarch64-linux-gnu-gcc','-c',asm,'-o',native],True)
 run(name+' proof',[old,'--input',native,'--symbol','entry','--mode','proof','--output',proof],True)
 with proof.open('rb') as f:
  elf=ELFFile(f);metadata=elf.get_section_by_name('.native_link_abi').data().decode();text=elf.get_section_by_name('.text').data()
 declared=int(metadata.strip().splitlines()[-1].split('\t')[1]);assert declared&required==required,(name,metadata)
 def link(binary,case_input,tag,okay):
  return run(name+' '+tag,[binary,'--input',case_input,'--symbol','entry','--mode','kernel',
   '--link-plan',plan,'--output',out/(name+'.'+tag+'.bin'),'--output-abi',out/(name+'.'+tag+'.abi')],okay)
 link(new,proof,'valid',True)
 for bit in range(4):
  if not required&(1<<bit):continue
  bad=out/(name+f'.clear{bit}.proof.o');meta=out/(name+f'.clear{bit}.metadata')
  meta.write_text(metadata.replace('callee_saved_mask\t'+str(declared),'callee_saved_mask\t'+str(declared&~(1<<bit))))
  run(name+f' mutate{bit}',['llvm-objcopy-18','--update-section','.native_link_abi='+str(meta),proof,bad],True)
  with bad.open('rb') as f:assert ELFFile(f).get_section_by_name('.text').data()==text
  link(old,bad,f'old-clear{bit}',True)
  result=link(new,bad,f'new-clear{bit}',False);assert 'understates required native mask' in result.stderr
 summary.append(dict(case=name,required_mask=required,producer_mask=declared,valid_link=True))
# A mask declared by the entry must cover a reachable callee before emission.
(out/'summary.json').write_text(json.dumps(dict(cases=summary,valid=len(summary),underspecified_rejected=sum(x['required_mask'].bit_count() for x in summary),code_unchanged=True),indent=2)+'\n')
(out/'producer-hashes.json').write_text(json.dumps({str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in [old,new]},indent=2)+'\n')
print((out/'summary.json').read_text())
