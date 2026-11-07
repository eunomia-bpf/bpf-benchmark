"""Context-store evidence via the unchanged common native-only service harness."""
from pathlib import Path
from datetime import datetime,timezone
import hashlib,importlib.util,json,shutil,subprocess,sys
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent

def harness(arch):
 spec=importlib.util.spec_from_file_location('common_native_safety',R/'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/check.py')
 m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
 m.ARCH=arch;m.BUILD=R/('kprog/fidelity/build-context-'+arch);m.OUT=O/arch
 if arch=='arm64':m.native_link=lambda:R/'kprog/fidelity/build-return-linker/aarch64-unknown-linux-gnu/release/native-link'
 return m

def build(arch):
 m=harness(arch);m.BUILD.mkdir(parents=True,exist_ok=True);m.OUT.mkdir(parents=True,exist_ok=True)
 old=R/('kprog/formal/build/fidelity-trusted' if arch=='x86' else 'kprog/formal/build/fidelity-trusted-arm64')
 for name in ['bound-probe','context_array.bpf.o','context_hash.bpf.o']:shutil.copy2(old/name,m.BUILD/name)
 programs={'valid_control':'mov eax,2; ret' if arch=='x86' else 'mov w0,#2; ret',
           'context_field_write':'mov QWORD PTR [rdi],0; mov eax,2; ret' if arch=='x86' else 'str xzr,[x0]; mov w0,#2; ret'}
 rows=[]
 for name,assembly in programs.items():
  src=m.BUILD/(name+'.S');native=m.BUILD/(name+'.native.o')
  src.write_text(('.intel_syntax noprefix\n' if arch=='x86' else '')+'.text\n.global entry\n.type entry,%function\nentry:\n'+assembly.replace('; ','\n')+'\n.size entry,.-entry\n.section .note.GNU-stack,"",@progbits\n')
  subprocess.run(['cc' if arch=='x86' else 'aarch64-linux-gnu-gcc','-c',str(src),'-o',str(native)],check=True)
  manifest=m.OUT/(name+'.manifest.json');manifest.write_text(json.dumps(dict(objects=[dict(program='neg_source',source_btf_symbol='neg_source',native_object=str(native),symbol='entry')]),indent=2)+'\n')
  rows.append(dict(name=name,assembly=assembly,negative=name!='valid_control',native_sha256=hashlib.sha256(native.read_bytes()).hexdigest(),manifest=str(manifest)))
 (m.OUT/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
 (m.OUT/'inputs.json').write_text(json.dumps({str(p.relative_to(R)):hashlib.sha256(p.read_bytes()).hexdigest() for p in m.BUILD.iterdir() if p.is_file()},indent=2)+'\n')
 print('prepared',arch,len(rows),'native-only inputs; existing producer/context binaries copied unchanged')

def guest(arch,live=None):
 m=harness(arch);cases=json.loads((m.OUT/'cases.json').read_text())
 if live is not None:
  m.OUT=Path(live);(m.OUT/'cases.json').write_text(json.dumps(cases,indent=2)+'\n')
 try:m.check()
 finally:
  rows=json.loads((m.OUT/'outcomes.json').read_text()) if (m.OUT/'outcomes.json').exists() else []
  summary=dict(ok=len(rows)==len(cases) and all(r['stage'] in ['valid_executed','verifier_rejected','specialization_rejected','loader_rejected','compiler_rejected'] for r in rows),cases=len(rows),accepted_unsafe=sum(r['stage']=='accepted_finding' for r in rows),unsafe_native_executed=any(r['unsafe_native_executed'] for r in rows),finished=datetime.now(timezone.utc).isoformat())
  (m.OUT/'guest.json').write_text(json.dumps(summary,indent=2)+'\n')

if sys.argv[1]=='build':build(sys.argv[2])
elif sys.argv[1]=='guest-x86':guest('x86',sys.argv[2] if len(sys.argv)>2 else None)
elif sys.argv[1]=='guest':guest('arm64',sys.argv[2])
elif sys.argv[1]=='host':
 spec=importlib.util.spec_from_file_location('existing_arm_transport',R/'corpus/results/kprog_arm64_app_coverage_20261106/trusted_service_arm64.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
 m.HERE=O/'arm64';m.__file__=__file__;m.NATIVE_LINK=harness('arm64').native_link();m.host()
else:raise SystemExit('usage: check.py build x86|arm64 | guest-x86 | host | guest LIVE')
