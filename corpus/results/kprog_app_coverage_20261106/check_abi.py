"""Check that ABI rejection preserves compiled programs and blind callee saves."""
import importlib.util
import json
from pathlib import Path
import sys
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
spec=importlib.util.spec_from_file_location('abi_generator',ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
g=importlib.util.module_from_spec(spec);sys.modules[spec.name]=g;spec.loader.exec_module(g)
OUT=HERE/'abi-positive';OUT.mkdir(exist_ok=True)
rows=[]
for config,source in [(ROOT/'micro/config/micro_pure_jit.yaml',g.MICRO_PROGRAMS),
                      (ROOT/'micro/config/micro_stage2.yaml',g.STAGE2_PROGRAMS)]:
 for bench in g.load_benches(config):
  try:
   path=g.write_one(bench,source,OUT,g.PROOF_OBJECT_DIR)
   path.write_text(path.read_text().replace('#include "../x86_sim_local_bpf.h"',
      f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"').replace(
      '#include "../../test/include/native_helpers.h"',f'#include "{ROOT}/kprog/test/include/native_helpers.h"'))
   row=dict(name=bench.name,ok=True,source=str(path))
  except (ValueError,RuntimeError) as error:
   row=dict(name=bench.name,ok=False,error=str(error))
  rows.append(row);print(row,flush=True)
(OUT/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
(OUT/'programs.jsonl').write_text(''.join(json.dumps(dict(
    name=r['name'],source=r.get('source',''),proof=str(g.PROOF_OBJECT_DIR/(r['name']+'.proof.o')),
    stage='generate',ok=r['ok'],note=r.get('error','')))+'\n' for r in rows))
negative=json.loads((HERE/'abi-definedness/build.json').read_text())
for name in ('undefined_entry_register','undefined_entry_flags','helper_clobbered_register'):
 r=next(r for r in negative['cases'] if r['name']==name)
 assert r['stage']=='specialization_rejected' and 'undefined native ABI' in r['message'],r
print('all three previously accepted ABI cases rejected for undefined native state')

def code(items):
 return [g.NativeInsn(i,op+' '+','.join(args),op,args) for i,(op,args) in enumerate(items)]
# A native caller may save/restore an opaque incoming callee-saved register.
blind=code([('push',('rbx',)),('mov',('ebx','9')),('mov',('eax','2')),
            ('pop',('rbx',)),('ret',())])
g.render_program('blind_save',blind)
# Copying the same opaque bits into an observed value must not initialize them.
for pair in [('push',('rbx',)),('mov',('QWORD PTR [rsp-8]','rbx'))]:
 if pair[0]=='push':
  instructions=[pair,('pop',('rax',)),('test',('rax','rax')),('je',('5',)),('mov',('eax','2')),('ret',())]
 else:
  instructions=[pair,('mov',('rax','QWORD PTR [rsp-8]')),('test',('rax','rax')),
                ('je',('5',)),('mov',('eax','2')),('ret',())]
 try:g.render_program('opaque_observed',code(instructions))
 except ValueError as error: assert 'undefined native ABI' in str(error),error
 else:raise AssertionError('opaque callee save manufactured a defined value')
# Low byte writes must not initialize the rest; a full 32-bit write does.
for width in ('al','eax'):
 instructions=code([('mov',(width,'2')),('ret',())])
 try:g.render_program('partial',instructions)
 except ValueError:
  assert width=='al'
 else:assert width=='eax'
# A 16-bit load + 32-bit left shift discards the unspecified upper half.
shift=code([('movbe',('si','WORD PTR [rdi]')),('shl',('esi','16')),
            ('mov',('eax','esi')),('ret',())])
g.render_program('discarded_upper',shift)
# CF still comes from an unspecified bit shifted out; it must not be seeded0.
shift=code([('movbe',('si','WORD PTR [rdi]')),('shl',('esi','16')),
            ('jae',('5',)),('mov',('rax','QWORD PTR [rdi+8]')),
            ('movzx',('eax','BYTE PTR [rax]')),('ret',())])
try:g.render_program('undefined_shift_carry',shift)
except ValueError as error: assert 'undefined native ABI flags' in str(error),error
else:raise AssertionError('shift invented a defined carry bit')
try:g.render_program('corrupted_sp',code([('push',('0',)),('pop',('rsp',)),('mov',('eax','2')),('ret',())]))
except ValueError as error:assert 'unbalanced stack pointer' in str(error),error
else:raise AssertionError('entry return used a scalar as the native stack pointer')
print('blind saves/shifts accepted; opaque/partial/undefined-carry/corrupted-SP cases rejected')
raise SystemExit(int(any(not r['ok'] for r in rows)))
