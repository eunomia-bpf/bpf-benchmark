#!/usr/bin/env python3
"""Run the existing native-only safety harness on the retained ARM QEMU runtime."""
from pathlib import Path
import importlib.util,json,sys,subprocess,types
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('native_safety',R/'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/check.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
m.ARCH='arm64';m.OUT=O;m.BUILD=R/'kprog/formal/build/fidelity-trusted-arm64'
# Read the canonical linker as an input; the historical private cache is retained.
LINKER=m.native_link()
POSITIVES={
 'valid_control':'mov w0,#2; ret',
 'valid_copy_restore':'mov x1,sp; mov sp,x1; mov w0,#2; ret',
 'valid_alias_load':'sub sp,sp,#16; mov x1,#37; str x1,[sp]; mov x2,sp; ldr x3,[x2]; add sp,sp,#16; cmp x3,#37; b.ne 1f; mov w0,#2; ret; 1: mov w0,#0; ret',
 'valid_spill_restore':'sub sp,sp,#32; add x1,sp,#16; str x1,[sp]; ldr x1,[sp]; mov sp,x1; add sp,sp,#16; mov w0,#2; ret'}
m.cases=lambda:[dict(name=n,assembly=a,negative=False) for n,a in POSITIVES.items()]+[dict(name=n,assembly=a,negative=True) for n,a in m.fixtures.FIXTURES['arm64'].items()]
if len(sys.argv)==2 and sys.argv[1]=='build':m.build()
elif len(sys.argv) in (2,4) and sys.argv[1]=='host':
 if len(sys.argv)==4 and sys.argv[2]!='--out':raise SystemExit('expected --out DIRECTORY')
 destination=Path(sys.argv[3]).resolve() if len(sys.argv)==4 else O
 destination.mkdir(parents=True,exist_ok=True)
 spec=importlib.util.spec_from_file_location('arm_transport',R/'corpus/results/kprog_arm64_app_coverage_20261106/trusted_service_arm64.py');transport=importlib.util.module_from_spec(spec);spec.loader.exec_module(transport)
 # Reuse A's unchanged readonly-root transport; output/guest dispatch belong to F.
 transport.HERE=destination;transport.__file__=__file__;transport.NATIVE_LINK=LINKER
 # Override only this imported transport's subprocess binding, never the shared
 # module or A's source. Mutating argv also keeps its recorded command accurate.
 def launch(argv,**kwargs):
  if argv[:4]!=['taskset','-c','8-11','qemu-system-aarch64']:raise RuntimeError('unexpected transport guest command')
  argv[2]='20-23'
  return subprocess.Popen(argv,**kwargs)
 transport.subprocess=types.SimpleNamespace(Popen=launch,PIPE=subprocess.PIPE,STDOUT=subprocess.STDOUT)
 transport.host()
elif len(sys.argv) in (3,4) and sys.argv[1]=='guest':
 live=Path(sys.argv[2]);selected=json.loads((O/'cases.json').read_text())
 # A linker change requires fresh receipts for every case, including controls.
 (live/'cases.json').write_text(json.dumps(selected,indent=2)+'\n');m.cases=lambda:selected;m.OUT=live
 try:m.check()
 finally:
  p=live/'outcomes.json';rows=json.loads(p.read_text()) if p.exists() else []
  ok=len(rows)==len(m.cases()) and all(x['stage'] in ['valid_executed','verifier_rejected','specialization_rejected','loader_rejected','compiler_rejected'] for x in rows)
  (live/'guest.json').write_text(json.dumps(dict(ok=ok,cases=len(rows),accepted_unsafe=sum(x['stage']=='accepted_finding' for x in rows)),indent=2)+'\n')
else:raise SystemExit('usage: replay.py build | host [--out DIRECTORY] | guest LIVE')
