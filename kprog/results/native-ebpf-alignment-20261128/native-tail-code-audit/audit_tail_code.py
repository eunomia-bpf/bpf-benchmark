"""Attribute canonical captured blobs to emitted tail-call instruction blocks.

This reads existing archives and plans. It does not execute native code or prove
which paths ran; unmatched signatures and source/installed-code identity are
reported separately. Identical instruction blocks share one disassembly.
"""
from pathlib import Path
import collections,hashlib,json,os,re,struct,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
BASE=OUT.parent;PLAN=BASE/'runtime-plan-audit';rows=[];variants={};sources=[]
def sha(data):return hashlib.sha256(data).hexdigest()
def file_sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def save(name,obj):(OUT/name).write_text(json.dumps(obj,indent=2)+'\n')
def word(data,n):return struct.unpack_from('<I',data,4*n)[0]
def signed(n,bits):return n-(1<<bits) if n&(1<<(bits-1)) else n
def positions(data,needle):
 at=0
 while True:
  at=data.find(needle,at)
  if at<0:return
  yield at;at+=1

def arm_sites(blob,h):
 maxoff=h['__native_arm64_bpf_map_max_entries_offset'];prefix=struct.pack('<III',0x2a0203e2,0xb9400030|((maxoff//4)<<10),0x6b10005f)
 result=[]
 for at in positions(blob,prefix):
  if at%4:continue
  code=blob[at:at+88];r=dict(offset=at,bytes=len(code),diagnostics=[])
  if len(code)!=88:r['diagnostics'].append('truncated candidate');result.append(r);continue
  w=list(struct.unpack('<22I',code));r['refusal_targets']=[at+i*4+signed((w[i]>>5)&0x7ffff,19)*4 for i in [3,6,9]]
  r.update(counter_compare_immediate=(w[5]>>10)&0xfff,array_ptrs_offset=(w[7]>>10)&0xfff,prog_func_offset=((w[19]>>10)&0xfff)*8,target_entry_offset=(w[20]>>10)&0xfff,null_check_word=hex(w[9]),counter_store_word=hex(w[11]),frame_restore_words=[hex(x) for x in w[12:19]])
  checks={'all_refusals_land_after_block':r['refusal_targets']==[at+88]*3,'null_before_counter_store':(w[9]&0xff00001f)==0xb400000e and w[10:12]==[0x91000610,0xf9000350],'shared_counter_load':w[4]==0xf9400350,'limit_33':w[5]==0xf100861f,'array_ptrs_matches_plan':r['array_ptrs_offset']==h['__native_arm64_bpf_array_ptrs_offset'],'func_matches_plan':r['prog_func_offset']==h['__native_arm64_bpf_prog_bpf_func_offset'],'entry_matches_plan':r['target_entry_offset']==h['__native_arm64_tail_call_offset'],'indirect_branch':w[-1]==0xd61f0200}
  r['observations']=checks;r['diagnostics']=[k for k,v in checks.items() if not v];r['variant']=remember('arm64',code);result.append(r)
 return result

def x86_sites(blob,h):
 prefix=b'\x89\xd2\x39\x96'+struct.pack('<I',h['__native_x86_bpf_map_max_entries_offset'])+b'\x0f\x86';result=[]
 for at in positions(blob,prefix):
  r=dict(offset=at,diagnostics=[])
  if at+14>len(blob):r['diagnostics'].append('truncated first refusal');result.append(r);continue
  end=at+14+struct.unpack_from('<i',blob,at+10)[0];r['end']=end
  if not at+14<=end<=len(blob):r['diagnostics'].append('first refusal target outside blob');result.append(r);continue
  code=blob[at:end];r['bytes']=len(code);count=list(positions(code,b'\x48\x83\x38\x21\x0f\x83'));null=list(positions(code,b'\x48\x85\xc9\x0f\x84'));inc=list(positions(code,b'\x48\x83\x00\x01'));targets=[end]
  for offsets,disp in [(count,6),(null,5)]:
   for i in offsets:
    if i+disp+4<=len(code):targets.append(at+i+disp+4+struct.unpack_from('<i',code,i+disp)[0])
  entry=h['__native_x86_tail_call_offset'];entry_add=b'\x48\x83\xc1'+bytes([entry]) if entry<128 else b'\x48\x81\xc1'+struct.pack('<I',entry)
  checks={'three_refusals_same_end':len(targets)==3 and targets==[end]*3,'one_limit_33_comparison':len(count)==1,'null_before_increment':len(null)==len(inc)==1 and null[0]<inc[0],'array_ptrs_matches_plan':b'\x48\x8b\x8c\xd6'+struct.pack('<I',h['__native_x86_bpf_array_ptrs_offset']) in code,'func_matches_plan':b'\x48\x8b\x89'+struct.pack('<I',h['__native_x86_bpf_prog_bpf_func_offset']) in code,'entry_matches_plan':entry_add in code,'indirect_branch':code.endswith(b'\xff\xe1')}
  r.update(refusal_targets=targets,observations=checks,counter_comparison_offsets=count,null_test_offsets=null,counter_increment_offsets=inc,variant=remember('x86',code));r['diagnostics']=[k for k,v in checks.items() if not v];result.append(r)
 return result

def remember(arch,code):
 key=arch+':'+sha(code)
 if key not in variants:variants[key]=dict(architecture=arch,bytes=len(code),sha256=sha(code),hex=code.hex())
 return key

def read_archive(source,expected,plans):
 arch,group=source['architecture'],source['group']
 for p in source['parts']:
  f=ROOT/p['path'];assert f.stat().st_size==p['bytes'] and file_sha(f)==p['sha256']
 sources.append(source)
 a=subprocess.Popen(['cat',*[str(ROOT/p['path']) for p in source['parts']]],stdout=subprocess.PIPE,stdin=subprocess.DEVNULL);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close()
 with tarfile.open(fileobj=b.stdout,mode='r|') as t:
  for m in t:
   if not m.isfile() or not re.fullmatch(r'[0-9a-f]{16}\.blob\.bin',Path(m.name).name):continue
   rel=str(Path(*Path(m.name).parts[1:]));data=t.extractfile(m).read();e=expected[rel];assert len(data)==e['bytes'] and sha(data)==e['sha256']
   app=rel.split('/')[0].split('__')[0] if group=='five' else 'otelcol-ebpf-profiler';key=Path(rel).name.split('.')[0];plan=plans.get((arch,app,key));r=dict(architecture=arch,app=app,cache_key=key,member=rel,bytes=len(data),sha256=sha(data),entry=plan['entry'] if plan else None,plan_origin=plan['plan_origin'] if plan else None)
   if plan:
    h={x['name']:x['addr'] for x in plan['helper_bindings']};r['tail_layout_bindings']={n:v for n,v in h.items() if n.startswith('__native_') and any(k in n for k in ['map_max_entries','array_ptrs','prog_bpf_func','tail_call_offset'])};r['sites']=(arm_sites if arch=='arm64' else x86_sites)(data,h)
   else:r['sites']=[];r['scope']='No retained plan match; no signature inference.'
   rows.append(r)
 b.stdout.close();assert a.wait()==b.wait()==0

def disassemble():
 lines=['# Actual captured instruction variants; offsets below are variant-relative.']
 for key,x in sorted(variants.items()):
  fd=os.memfd_create('captured-tail-code')
  try:
   os.write(fd,bytes.fromhex(x['hex']));os.lseek(fd,0,os.SEEK_SET)
   tool='aarch64-linux-gnu-objdump' if x['architecture']=='arm64' else 'objdump';machine='aarch64' if x['architecture']=='arm64' else 'i386:x86-64'
   p=subprocess.run([tool,'-D','-b','binary','-m',machine,f'/proc/self/fd/{fd}'],pass_fds=(fd,),stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True);assert p.returncode==0,p.stdout
   lines.extend(['',key,p.stdout])
  finally:os.close(fd)
 (OUT/'disassembly.txt').write_text('\n'.join(lines)+'\n')

def capture_sources():
 fragments=[];records=[]
 specs=[('kprog/x86/native_lab/native_link/src/main.rs',1453,1496),('kprog/x86/native_lab/native_link/src/x86.rs',3637,3707),('vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c',501,710),('vendor/linux-framework/arch/x86/net/bpf_jit_comp.c',728,871),('vendor/linux-framework/include/linux/bpf.h',2254,2261)]
 for name,lo,hi in specs:
  p=ROOT/name;s=p.read_text().splitlines();records.append(dict(path=name,sha256=file_sha(p),first_line=lo,last_line=hi));fragments.extend(['',name,*[f'{i}: {s[i-1]}' for i in range(lo,hi+1)]])
 configs=[]
 for name in ['.config','include/generated/autoconf.h']:
  p=Path('/workspaces/.agent-state/kprog-ck/build-arm64')/name;text=p.read_text();configs.append(dict(path=str(p),bytes=p.stat().st_size,sha256=file_sha(p),selected_lines=[x for x in text.splitlines() if any(n in x for n in ['CONFIG_ARM64_BTI','CONFIG_ARM64_PTR_AUTH_KERNEL','CONFIG_BPF_JIT'])]))
 (OUT/'source-fragments.txt').write_text('\n'.join(fragments)+'\n')
 save('source-context.json',dict(utc=now(),kernel_commit=subprocess.check_output(['git','-C','vendor/linux-framework','rev-parse','HEAD'],text=True).strip(),sources=records,arm_build_configs=configs,interpretation='Actual generated config defines ARM64_PTR_AUTH_KERNEL and ARM64_BTI, but not ARM64_BTI_KERNEL. Kernel PROLOGUE_OFFSET is BTI_INSNS + 2 + PAC_INSNS + 4, so this configuration gives seven instructions / 28 bytes. Captured plan offsets are reported independently per blob. Current source fragments alone do not establish captured build identity or taken-tail behavior.'))

controller=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='captured-blob-attribution')
try:
 os.sched_setaffinity(0,{19});save('controller.json',controller);capture_sources()
 r=PLAN/'runtime-plans.json';assert file_sha(r)=='a2653369e9ce17c3c12bebc32ddd1f4e646a4de27080346a822e0892e97eb51b';plan_rows=json.loads(r.read_text())['plans'];plans={(x['architecture'],x['app'],x['cache_key']):x for x in plan_rows}
 for source in json.loads((PLAN/'sources.json').read_text())['archives']:
  if source['architecture']=='arm64':expected=json.loads((BASE/'arm64-frozen-ir/otel-work-check/raw-file-manifest.json').read_text())
  else:
   d=BASE/'check-20261128T034810Z' if source['group']=='five' else ROOT/'kprog/results/x86-otel-perf-20261127/profile-20261128T033629Z';expected=json.loads((d/'collection-controller.json').read_text())['files']
  read_archive(source,expected,plans)
 rows.sort(key=lambda x:(x['architecture'],x['app'],x['cache_key']));disassemble();save('captured-tail-code.json',dict(scope='SHA-verified canonical blob signatures and instruction observations, joined to captured plan keys. No execution or installed-code-equivalence claim. A zero signature count is not proof of no tail-call execution.',plans=len(plans),blobs=rows,variants=variants,sources=sources))
 groups=collections.defaultdict(list)
 for r in rows:groups[(r['architecture'],r['app'])].append(r)
 summary=[dict(architecture=k[0],app=k[1],canonical_blobs=len(v),blobs_with_plan=sum(bool(x['plan_origin']) for x in v),blobs_with_candidates=sum(bool(x['sites']) for x in v),candidate_sites=sum(len(x['sites']) for x in v),sites_with_diagnostics=sum(bool(s['diagnostics']) for x in v for s in x['sites'])) for k,v in sorted(groups.items())]
 save('summary.json',dict(per_app=summary,unique_instruction_variants=len(variants),plan_count=len(plans),canonical_blob_count=len(rows),missing_blob_plan_keys=[list(k) for k in sorted(set(plans)-{(x['architecture'],x['app'],x['cache_key']) for x in rows})],interpretation='Review full diagnostics and disassembly; structural observations are not dynamic tail-count, target, frame, or useful-work equality.'))
 controller.update(controller_status=0,phase='finished',per_app=summary,outputs={n:dict(bytes=(OUT/n).stat().st_size,sha256=file_sha(OUT/n)) for n in ['source-context.json','source-fragments.txt','captured-tail-code.json','summary.json','disassembly.txt']})
except BaseException:
 controller.update(controller_status=1,phase='failed',error=traceback.format_exc());traceback.print_exc()
finally:
 controller['ended_utc']=now();save('controller.json',controller)
raise SystemExit(controller['controller_status'])
