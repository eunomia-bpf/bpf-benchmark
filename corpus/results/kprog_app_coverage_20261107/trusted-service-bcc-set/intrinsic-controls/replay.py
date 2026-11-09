"""Memset admission controls using F's unchanged native-only service harness."""
from pathlib import Path
import sys,json,subprocess,hashlib,tempfile,tarfile,importlib.util
from datetime import datetime,timezone
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
BUILD=ROOT/'kprog/libnativeloader/build/intrinsic-controls'
ROWS=[
 dict(name='valid_stack_fill',negative=False,assembly='sub rsp,40; mov rdi,rsp; mov esi,122; mov edx,24; call memset; cmp BYTE PTR [rsp+23],122; sete al; movzx eax,al; add eax,1; add rsp,40; ret'),
 dict(name='invalid_context_fill',negative=True,assembly='sub rsp,8; xor esi,esi; mov edx,24; call memset; add rsp,8; mov eax,2; ret'),
 dict(name='invalid_stack_fill',negative=True,assembly='sub rsp,40; mov rdi,rsp; xor esi,esi; mov edx,80; call memset; add rsp,40; mov eax,2; ret')]
if sys.argv[1]=='build':
 BUILD.mkdir(parents=True,exist_ok=True)
 for row in ROWS:
  source=BUILD/(row['name']+'.S');obj=source.with_suffix('.native.o')
  text='.intel_syntax noprefix'+chr(10)+'.text'+chr(10)+'.global entry'+chr(10)+'.type entry,@function'+chr(10)+'entry:'+chr(10)+row['assembly'].replace('; ',chr(10))+chr(10)+'.size entry,.-entry'+chr(10)+'.section .note.GNU-stack,"",@progbits'+chr(10)
  source.write_text(text);subprocess.run(['cc','-c',source,'-o',obj],check=True)
  row['native_sha256']=hashlib.sha256(obj.read_bytes()).hexdigest()
  manifest=OUT/(row['name']+'.manifest.json');row['manifest']=str(manifest)
  manifest.write_text(json.dumps(dict(objects=[dict(program='neg_source',source_btf_symbol='neg_source',native_object=str(obj),symbol='entry')]),indent=2)+chr(10))
 (OUT/'cases.json').write_text(json.dumps(ROWS,indent=2)+chr(10))
else:
 helper=ROOT/'kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/check.py'
 spec=importlib.util.spec_from_file_location('existing_native_only',helper);module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
 summary=dict(ok=False,started=datetime.now(timezone.utc).isoformat(),unsafe_execution_permitted=False,helper_sha256=hashlib.sha256(helper.read_bytes()).hexdigest())
 with tempfile.TemporaryDirectory(prefix='.live-controls-',dir=OUT) as directory:
  live=Path(directory);(live/'cases.json').write_bytes((OUT/'cases.json').read_bytes());module.OUT=live
  try:
   module.check();summary['ok']=True
  finally:
   kernel=subprocess.run(['dmesg','--raw'],capture_output=True,text=True);(live/'kernel.log').write_text(kernel.stdout);(live/'kernel.stderr').write_text(kernel.stderr)
   if (live/'outcomes.json').exists():
    rows=json.loads((live/'outcomes.json').read_text());summary['outcomes']=[{k:r[k] for k in ('name','negative','stage','returncode','unsafe_native_executed')} for r in rows]
   summary['finished']=datetime.now(timezone.utc).isoformat();stamp=datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ');archive=OUT/('controls-'+stamp+'.tar.gz');summary['archive']=archive.name
   (live/'summary.json').write_text(json.dumps(summary,indent=2)+chr(10))
   with tarfile.open(archive,'x:gz') as target:target.add(live,arcname='controls')
   (OUT/'summary.json').write_text(json.dumps(summary,indent=2)+chr(10));print(json.dumps(summary),flush=True)
