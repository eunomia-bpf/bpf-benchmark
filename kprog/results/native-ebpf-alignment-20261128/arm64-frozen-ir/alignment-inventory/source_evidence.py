"""Extract available per-object compile evidence and source anchors; do not rebuild."""
from pathlib import Path
import collections,hashlib,json,re,subprocess
from elftools.elf.elffile import ELFFile
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;objects=json.loads((OUT/'objects.json').read_text());groups=collections.defaultdict(list);missing=[]
for path,row in objects.items():
 a=row['embedded_compile_command'] or [];profile={}
 for flag in ['-triple','-target-cpu','-tune-cpu','-target-abi','-target-feature']:
  profile[flag]=sorted(set(a[i+1] for i,v in enumerate(a[:-1]) if v==flag))
 profile['optimization']=sorted(set(v for v in a if v in ['-O0','-O1','-O2','-O3','-Os','-Oz']))
 profile['native_policy_flags']=sorted(set(v for v in a if any(s in v for s in ['omit-frame','stack-protector','red-zone','general-regs','jump-tables','sibling-calls','outline-atomics','reserve-x26','cmov-converter','switch-to-lookup'])))
 if a:
  groups[json.dumps(profile,sort_keys=True)].append(path)
 else:
  with (ROOT/path).open('rb') as f:bc=ELFFile(f).get_section_by_name('.llvmbc').data()
  dis=subprocess.run(['llvm-dis-18','-o','-'],input=bc,stdout=subprocess.PIPE,stderr=subprocess.PIPE);assert dis.returncode==0,dis.stderr.decode();text=dis.stdout.decode();lines=[x for x in text.splitlines() if x.startswith(('target triple','target datalayout','attributes #'))];(OUT/(Path(path).parts[3]+'-'+Path(path).name+'.ir-attributes.txt')).write_text('\n'.join(lines)+'\n');missing.append(dict(path=path,reason='Merged object carries IR but no usable .llvmcmd; target attributes retained, historical full command not recovered.',ir_sha256=hashlib.sha256(bc).hexdigest(),ir_target_lines=[x for x in lines if x.startswith('target')],target_cpus=sorted(set(re.findall(r'"target-cpu"="([^"]+)"',text))),tune_cpus=sorted(set(re.findall(r'"tune-cpu"="([^"]+)"',text))),target_features=sorted(set(re.findall(r'"target-features"="([^"]+)"',text)))))
r=dict(groups=[dict(profile=json.loads(k),objects=v) for k,v in groups.items()],objects_without_compile_command=missing,limits='Signatures cover recorded codegen options; source include paths, defines and frontend-specific switches are retained in objects.json but are not a proof that a live app selected the same source/features. Do not equate optimization in IR with the full historical frontend command.')
(OUT/'codegen-policy.json').write_text(json.dumps(r,indent=2)+'\n')
queries={
'vendor/linux-framework/kernel/bpf/verifier.c':['static int do_misc_fixups','map_gen_lookup','Implement bpf_jiffies64 inline','Implement bpf_get_smp_processor_id() inline','Implement bpf_get_current_task()','convert_ctx_access'],
'vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c':['Implement helper call to bpf_get_smp_processor_id','Implement helper call to bpf_get_current_task','case BPF_JMP | BPF_TAIL_CALL'],
'kprog/x86/native_lab/native_link/src/frozen_ir.rs':['pub(super) fn specialize','section_by_name(".llvmbc")','--immutable-globals'],
'kprog/x86/native_lab/native_link/src/main.rs':['fn a64_fold_frozen_load','fn build_arm64_get_smp_processor_id_inline','fn build_arm64_tail_call_inline','build_arm64_get_smp_processor_id_inline(helper_addrs)','reloc.target_name == "bpf_get_current_task"'],
'kprog/libnativeloader/src/native_loader_trusted.cpp':['if (immutable) {','load.immutable_globals[name]','bind_original_source_maps(source_bpf_object','const auto optimized = native_context_lto_object'],
'kprog/libnativeloader/src/native_loader_link_schema.hpp':['BPF_MAP_TYPE_LPM_TRIE'],
'vendor/bpf/Makefile':['NATIVE_ARCH_CFLAGS :=','NATIVE_CFLAGS :=','CILIUM_AGENT_NODE_OPTIONS :='],
'vendor/bpf/otel/support/ebpf/tracemgmt.h':['struct pt_regs *regs = origin == TRACE_SAMPLING']}
anchors={}
for name,needles in queries.items():
 p=ROOT/name;data=p.read_bytes();lines=data.decode().splitlines();anchors[name]=dict(sha256=hashlib.sha256(data).hexdigest(),matches={needle:[dict(line=i+1,text=t) for i,t in enumerate(lines) if needle in t] for needle in needles})
anchors['kernel_revision']=subprocess.check_output(['git','-C',str(ROOT/'vendor/linux-framework'),'rev-parse','HEAD'],text=True).strip();(OUT/'source-anchors.json').write_text(json.dumps(anchors,indent=2)+'\n')
print(json.dumps(dict(command_groups=[dict(objects=len(g['objects']),arch=g['profile']['-triple'],optimization=g['profile']['optimization'],tune=g['profile']['-tune-cpu']) for g in r['groups']],merged_objects=[dict(path=v['path'],cpu=v['target_cpus'],tune=v['tune_cpus']) for v in missing],kernel=anchors['kernel_revision'])))
