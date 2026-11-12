#!/usr/bin/env python3
"""Native-only negative suite via the common registered service; never run negatives."""
from pathlib import Path
import argparse,hashlib,importlib.util,json,os,subprocess,sys,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;BUILD=ROOT/'kprog/formal/build/fidelity-trusted'
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
spec=importlib.util.spec_from_file_location('fixture_data',ROOT/'kprog/fidelity/negative.py');fixtures=importlib.util.module_from_spec(spec);spec.loader.exec_module(fixtures)
ARCH='x86'
def native_link():
 return ROOT/('kprog/x86/native_lab/native_link/target/release/native-link' if ARCH=='x86' else 'kprog/arm64/build/app-native-link/aarch64-unknown-linux-gnu/release/native-link')
def loader_build():
 return ROOT/('kprog/libnativeloader/build' if ARCH=='x86' else 'kprog/libnativeloader/build-arm64-a-map-order-v3')
POSITIVES={
 'valid_control':'mov eax,2; ret',
 'valid_copy_restore':'mov rax,rsp; mov rsp,rax; mov eax,2; ret',
 'valid_alias_load':'sub rsp,16; mov QWORD PTR [rsp],37; mov rax,rsp; mov ecx,DWORD PTR [rax]; add rsp,16; cmp ecx,37; jne 1f; mov eax,2; ret; 1: mov eax,0; ret',
 'valid_cmov_alias':'sub rsp,16; mov QWORD PTR [rsp],37; mov rax,rsp; xor edx,edx; xor ecx,ecx; cmovz rdx,rax; mov ecx,DWORD PTR [rdx]; add rsp,16; cmp ecx,37; jne 1f; mov eax,2; ret; 1: mov eax,0; ret',
 'valid_cmov_from_sp':'sub rsp,16; mov QWORD PTR [rsp],37; xor eax,eax; xor ecx,ecx; cmovz rax,rsp; mov ecx,DWORD PTR [rax]; add rsp,16; cmp ecx,37; jne 1f; mov eax,2; ret; 1: mov eax,0; ret',
 'valid_cmov_to_sp':'mov rdx,rsp; lea rax,[rsp-16]; xor ecx,ecx; cmovz rsp,rax; mov rsp,rdx; mov eax,2; ret',
 'valid_cmov_self_sp':'xor ecx,ecx; cmovz rsp,rsp; mov eax,2; ret',
 'valid_xchg_alias':'sub rsp,16; mov QWORD PTR [rsp],37; mov rax,rsp; xor ecx,ecx; xchg rax,rcx; mov edx,DWORD PTR [rcx]; add rsp,16; cmp edx,37; jne 1f; mov eax,2; ret; 1: mov eax,0; ret',
 'valid_spill_restore':'sub rsp,32; lea rax,[rsp+16]; mov [rsp],rax; mov rax,[rsp]; mov rsp,rax; add rsp,16; mov eax,2; ret',
}
def cases():
 rows=[dict(name=n,assembly=a,negative=True) for n,a in fixtures.FIXTURES['x86'].items()]
 for direction in ['positive','negative']:
  for lane in ['byte','qword']:
   a='mov rdx,rsp; sub rsp,16; mov QWORD PTR [rsp],37; mov ecx,1; shl rcx,32; '+('neg rcx; ' if direction=='negative' else '')+'add rsp,rcx; '+('mov rax,QWORD PTR [rsp]; ' if lane=='qword' else 'movzx eax,BYTE PTR [rsp]; ')+'mov rsp,rdx; ret'
   rows.append(dict(name='high32_'+direction+'_'+lane,assembly=a,negative=True))
 return [dict(name=n,assembly=a,negative=False) for n,a in POSITIVES.items()]+rows

def build():
 BUILD.mkdir(parents=True,exist_ok=True);rows=cases()
 for row in rows:
  name=row['name'];src=BUILD/(name+'.S');src.write_text(('.intel_syntax noprefix\n' if ARCH=='x86' else '')+'.text\n.global entry\n.type entry,%function\nentry:\n'+row['assembly'].replace('; ','\n')+'\n.size entry,.-entry\n.section .note.GNU-stack,"",@progbits\n')
  subprocess.run(['cc' if ARCH=='x86' else 'aarch64-linux-gnu-gcc','-c',str(src),'-o',str(BUILD/(name+'.native.o'))],check=True)
  row['native_sha256']=hashlib.sha256((BUILD/(name+'.native.o')).read_bytes()).hexdigest()
  plan=OUT/(name+'.manifest.json');plan.write_text(json.dumps({'objects':[dict(program='neg_source',source_btf_symbol='neg_source',native_object=str(BUILD/(name+'.native.o')),symbol='entry')]},indent=2)+'\n');row['manifest']=str(plan)
 for kind in ['array','hash']:
  text=(ROOT/'kprog/fidelity/negative_companion.bpf.c').read_text()
  if kind=='hash':text=text.replace('BPF_MAP_TYPE_ARRAY','BPF_MAP_TYPE_HASH')
  src=BUILD/('context_'+kind+'.bpf.c');src.write_text(text)
  subprocess.run(['clang-18','-O2','-g','-target','bpf','-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(src),'-o',str(src.with_suffix('.o'))],check=True)
 libbpf=ROOT/('runner/build-llvmbpf/vendor/libbpf' if ARCH=='x86' else 'runner/build-arm64-llvmbpf/vendor/libbpf')
 args=['c++' if ARCH=='x86' else 'aarch64-linux-gnu-g++','-std=c++20','-Wall','-Wextra','-Werror','-O2','-D__EXPORTED_HEADERS__','-DNATIVE_LINK_PATH="'+str(native_link())+'"','-I'+str(ROOT/'vendor/linux-framework/include/uapi'),'-I'+str(libbpf/'prefix/include'),str(ROOT/'kprog/fidelity/bound_probe.cpp'),str(loader_build()/'libnative_loader.a'),str(libbpf/'pic-obj/libbpf.a')]
 if ARCH=='arm64':args+=['-static','-L'+str(ROOT/'.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu')]
 args+=['-lelf','-lz']+(['-lzstd'] if ARCH=='arm64' else [])+['-ldl','-pthread','-o',str(BUILD/'bound-probe')]
 subprocess.run(args,check=True);(OUT/'cases.json').write_text(json.dumps(rows,indent=2)+'\n');(OUT/'build.json').write_text(json.dumps(dict(producer_command=args,producer_sha256=hashlib.sha256((BUILD/'bound-probe').read_bytes()).hexdigest(),application_proofs_generated=False,negative_context='mutable HASH,key0 may be absent; ARRAY key0 is a legitimate nonnull case'),indent=2)+'\n')
 print('built native-only inputs',len(rows),'(no application proof)',flush=True)

def classify(record):
 archive=record.get('failure_archive')
 if not archive:return 'infrastructure_error',record.get('error','missing failure archive')
 with tarfile.open(archive) as ar:
  data={m.name:ar.extractfile(m).read().decode(errors='replace') for m in ar.getmembers() if m.isfile() and m.name.endswith(('.stderr','.stdout','.log','.txt'))}
 texts='\n'.join(data.values());error=record.get('error','')
 trace=record.get('traceback','')
 if 'ValueError:' in trace and any('/kprog/'+isa+'/micro-prog/' in trace for isa in ['x86','arm64']):return 'specialization_rejected',error+'\n'+texts
 if ('processed ' in texts and ('BPF_PROG_LOAD' in texts or 'bpf_object__load failed' in texts or 'service simulator verification failed' in texts)):return 'verifier_rejected',texts
 if 'contains no BPF exit' in texts:return 'loader_rejected',texts
 if any(s in error for s in ['unsupported x86','unsupported arm64 instruction','unsupported mnemonic','native ABI','native entry','native return','uninitialized','unsupported instruction','indirect']):return 'specialization_rejected',error+'\n'+texts
 if 'clang' in error and 'returned non-zero' in error:return 'compiler_rejected',error+'\n'+texts
 return 'pipeline_rejected_unclassified',error+'\n'+texts

def check():
 state=OUT/'requests';state.mkdir(mode=0o700,exist_ok=True)
 if list(state.iterdir()):raise RuntimeError('refusing to overwrite request evidence')
 argv=[sys.executable,str(ROOT/'kprog/trusted_service.py'),'--arch','1' if ARCH=='x86' else '2','--endpoint','/sys/kernel/debug/bpf_'+ARCH+'_native_lab/specializer','--state',str(state),'--native-link',str(native_link()),'--loader',str(loader_build()/'trusted-native-loader')]
 service=subprocess.Popen(argv,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True);log=[];outcomes=[]
 env=dict(os.environ,BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF='1')
 try:
  line=service.stdout.readline();log.append(line);assert json.loads(line)['ready']
  for row in json.loads((OUT/'cases.json').read_text()):
   negative=row['negative'];context=BUILD/('context_hash.bpf.o' if negative else 'context_array.bpf.o')
   command=[str(BUILD/'bound-probe'),str(context),row['manifest']]
   if not negative:command+=['0','2']
   # argc3 is strictly load-only. TEST_RUN is reachable only for named positives.
   assert (len(command)==3)==negative
   done=subprocess.run(command,cwd=ROOT/'kprog/fidelity',env=env,text=True,capture_output=True)
   (OUT/(row['name']+'.stdout')).write_text(done.stdout);(OUT/(row['name']+'.stderr')).write_text(done.stderr)
   if service.poll() is not None:raise RuntimeError('common service exited during '+row['name'])
   # A producer which failed before SUBMIT has no service receipt. Do not
   # wait for an event that cannot exist, or count setup failure as rejection.
   if done.returncode and 'trusted specializer refused native program:' not in done.stderr:
    raise RuntimeError('producer/setup failure before expected completion: '+row['name']+'\n'+done.stderr)
   line=service.stdout.readline();log.append(line);record=json.loads(line)
   assert record['native_sha256']==row['native_sha256']
   result=dict(row,command=command,returncode=done.returncode,request=record,unsafe_native_executed=False)
   if negative:
    if record['status']==0:stage,message='accepted_finding',done.stdout+done.stderr
    else:stage,message=classify(record)
   else:stage,message=('valid_executed' if record['status']==0 and done.returncode==0 else 'positive_infrastructure_error'),done.stdout+done.stderr
   result.update(stage=stage,message=message);outcomes.append(result);(OUT/'outcomes.json').write_text(json.dumps(outcomes,indent=2)+'\n');print(row['name'],stage,flush=True)
 finally:
  service.terminate();tail=service.communicate()[0];log.append(tail);(OUT/'service.log').write_text(''.join(log))
 findings=[row for row in outcomes if row['stage'] in ['accepted_finding','positive_infrastructure_error','infrastructure_error','pipeline_rejected_unclassified']]
 if findings:raise RuntimeError('inspect completed native-only findings: '+', '.join(row['name']+':'+row['stage'] for row in findings))
 print('ALL current native-only checks passed',flush=True)

if __name__=='__main__':
 parser=argparse.ArgumentParser();parser.add_argument('mode',choices=['build','check']);parser.add_argument('--out',type=Path);a=parser.parse_args()
 if a.out is not None:OUT=a.out
 (build if a.mode=='build' else check)()
