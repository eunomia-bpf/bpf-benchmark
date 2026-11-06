"""Keep raw-context loads as fixed-width BPF loads with literal offsets."""
from pathlib import Path
import json
import shutil
import sys
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent

def patch(text):
 replacements=[
 ('''\t\t\t__x86_l_value = X86_SIM_L_LOAD_ADDR(             \\
\t\t\t\t(void *)(long)__x86_l_addr,              \\
\t\t\t\t__x86_l_read_mem_width);                  \\''',
 '''\t\t\tif (X86_SIM_L_REG_TAG(BASE_REG) == X86_SIM_TAG_ABI && \\
\t\t\t    X86_MEM_AUX_INDEX(AUX) == X86_REG_NONE)       \\
\t\t\t\t__x86_l_value = KPROG_X86_MEM_LOAD_FIXED( \\
\t\t\t\t\t__x86_l_base_ptr, (STORE_DISP) ?   \\
\t\t\t\t\tx86_store_imm_disp(IMM) : x86_simm(IMM), \\
\t\t\t\t\t__x86_l_read_mem_width);         \\
\t\t\telse                                             \\
\t\t\t\t__x86_l_value = X86_SIM_L_LOAD_ADDR(       \\
\t\t\t\t\t(void *)(long)__x86_l_addr,       \\
\t\t\t\t\t__x86_l_read_mem_width);          \\'''),
 ('''\t\t\t\t__x86_l_value = X86_SIM_L_LOAD_ADDR(      \\
\t\t\t\t\t(void *)(long)__x86_l_addr,       \\
\t\t\t\t\t__x86_l_mem_width);               \\''',
 '''\t\t\t\tif (X86_MEM_AUX_INDEX(AUX) == X86_REG_NONE) \\
\t\t\t\t\t__x86_l_value = KPROG_X86_MEM_LOAD_FIXED( \\
\t\t\t\t\t\t__x86_l_base_ptr, x86_simm(IMM), __x86_l_mem_width); \\
\t\t\t\telse                                      \\
\t\t\t\t\t__x86_l_value = X86_SIM_L_LOAD_ADDR( \\
\t\t\t\t\t\t(void *)(long)__x86_l_addr, __x86_l_mem_width); \\'''),
 ('''\t\t\t__x86_l_value = X86_SIM_L_LOAD_ADDR(             \\
\t\t\t\t(void *)(long)__x86_l_addr,              \\
\t\t\t\t__x86_l_mem_width);                       \\''',
 '''\t\t\tif (X86_SIM_L_REG_TAG(SRC) == X86_SIM_TAG_ABI && \\
\t\t\t    X86_MEM_AUX_INDEX(AUX) == X86_REG_NONE)       \\
\t\t\t\t__x86_l_value = KPROG_X86_MEM_LOAD_FIXED( \\
\t\t\t\t\t__x86_l_base_ptr, x86_simm(IMM), __x86_l_mem_width); \\
\t\t\telse                                             \\
\t\t\t\t__x86_l_value = X86_SIM_L_LOAD_ADDR(       \\
\t\t\t\t\t(void *)(long)__x86_l_addr, __x86_l_mem_width); \\''')]
 for old,new in replacements:
  if text.count(old)!=1:raise ValueError('context-load consumer source drift')
  text=text.replace(old,new,1)
 return text

if __name__=='__main__':
 if sys.argv[1]=='prepare':
  previous=HERE/'bcc-real-13';out=HERE/'bcc-real-14';out.mkdir()
  for name in ['native','original','upstream','sources','simulator']:
   shutil.copytree(previous/name,out/name)
  for path in (out/'sources').glob('*.bpf.c'):
   path.write_text(path.read_text().replace(str(previous),str(out)))
  for name in ['programs.jsonl','manifest.json','load-pairing.json','native-inputs.json']:
   (out/name).write_text((previous/name).read_text().replace(str(previous),str(out)))
  header=out/'simulator/kprog/x86/x86_sim_local_bpf.h'
  header.write_text(patch(header.read_text()))
  shutil.copy2(ROOT/'kprog/formal/generated/x86_mem_access.h',out/'simulator/kprog/formal/generated/x86_mem_access.h')
  print('private BCC phase14 keeps all25 native/source pairs and fixed context offsets')
 elif sys.argv[1]=='integrate':
  path=ROOT/'kprog/x86/x86_sim_local_bpf.h';path.write_text(patch(path.read_text()))
 else:raise ValueError('expected prepare or integrate')
