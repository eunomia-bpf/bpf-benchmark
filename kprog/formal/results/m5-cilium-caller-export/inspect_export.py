"""Bind the complete actual caller, original inline LINK and packaged export."""
from pathlib import Path
import hashlib,io,json,re,tarfile

FORMAL=Path(__file__).resolve().parents[2];ROOT=FORMAL.parent.parent
RAW=Path('/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z')
def sha(b):return hashlib.sha256(b).hexdigest()
archive=Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/20261127T090610Z/cilium-agent/service.tar.gz')
with tarfile.open(archive) as outer:nested=outer.extractfile('service/requests/1.success.tar.gz').read()
with tarfile.open(fileobj=io.BytesIO(nested)) as request:
 def get(name):return request.extractfile('request/'+name).read()
 source=get('generated/trusted_arm64.bpf.c');native=get('generated/request.native.o')
 ids=json.loads(get('source-identities.json'));original=json.loads(get('generated/artifacts.json'))
assert source==(FORMAL/'c/Arm64CiliumCaller.c').read_bytes()
assert sha(native)==original['native_sha256']
header=ROOT/'kprog/arm64/arm64_sim_local_bpf.h'
current_header_sha256=sha(header.read_bytes())
captured_header_sha256=ids[str(header)]
text=header.read_text()
header_relation='current header byteexact to captured identity'
qualifier_plan_sha256=None
if current_header_sha256 != captured_header_sha256:
 plan_path=ROOT/'kprog/results/arm64-loadtime-20261127/header-const-plan.json'
 plan=json.loads(plan_path.read_text());relative=str(header.relative_to(ROOT))
 row=next(x for x in plan['files'] if x['path']==relative)
 assert row['before_sha256']==captured_header_sha256
 assert row['after_sha256']==current_header_sha256
 for declaration in (x for x in plan['declarations'] if x['path']==relative):
  start=text.index('#define '+declaration['macro']+'(')
  end=text.find('\n#define ',start+1)
  if end<0:end=len(text)
  macro=text[start:end]
  assert macro.count(declaration['after'])==1
  text=text[:start]+macro.replace(declaration['after'],declaration['before'],1)+text[end:]
 assert sha(text.encode())==captured_header_sha256
 header_relation='exact inverse of approved const declarations restores captured header bytes'
 qualifier_plan_sha256=sha(plan_path.read_bytes())
start=text.index('#define ARM64_SIM_L_WRITE_REG_PTR_TAG(REG, VALUE, TAG)')
end=text.index('\n#define ARM64_SIM_L_WRITE_REG_MAP_PTR',start)
expected=text[start:end].strip().replace('ARM64_SIM_L_WRITE_REG_PTR_TAG','KPROG_ARM64_ORIGINAL_LINK_WRITE',1)
binding=(FORMAL/'c/Arm64OriginalLinkBinding.h').read_text()
assert expected in binding
assert binding[binding.index('#define KPROG_ARM64_ORIGINAL_LINK_WRITE'):binding.index('\n\n#undef ARM64_SIM_A64_LINK')]==expected
assert 'kprog_arm64_program_write_pointer' not in binding
unit=(FORMAL/'c/Arm64CiliumCallerUnit.c').read_text()
prefix=source.decode().split('#include ',1)[0]
assert unit=='/* Original captured profile and complete captured caller;LINK stays inline. */\n'+prefix+'#include "../../arm64/arm64_sim_local_bpf.h"\n#include "Arm64OriginalLinkBinding.h"\n#include "Arm64CiliumCaller.c"\n'
package=json.loads(Path(__file__).with_name('packaging.json').read_text())
pieces=[];suffix='end Arm64CiliumCallerUnit\n\n'
for i,row in enumerate(package['parts']):
 path=FORMAL/row['path'];part=path.read_bytes()
 assert sha(part)==row['sha256']
 assert part.endswith(suffix.encode())
 if i==0:pieces.append(part[:row['header_bytes']])
 payload=part[row['header_bytes']:-len(suffix.encode())]
 assert len(payload)==row['body_bytes']
 restored=re.sub(r'(?m)^(@\[noinline\] )?noncomputable def ',lambda m:(m[1] or '')+'def ',payload.decode()).encode()
 assert len(restored)==row['original_body_bytes']
 pieces.append(restored)
pieces.append(suffix.encode());reconstructed=b''.join(pieces)
assert sha(reconstructed)==package['original_export_sha256']
assert reconstructed==(RAW/'cilium-caller-inline-export3.lean').read_bytes()
dep=(FORMAL/'build/clight-Arm64CiliumCaller.d').read_text().replace(chr(92)+'\n',' ')
inputs={}
for token in dep.split(':',1)[1].split():
 if token.endswith(':'):continue
 path=Path(token);path=path if path.is_absolute() else FORMAL/path
 assert path.is_file(),str(path)
 inputs[str(path.resolve())]=sha(path.read_bytes())
record={'archive':str(archive),'archive_sha256':sha(archive.read_bytes()),'request_member_sha256':sha(nested),'native_sha256':sha(native),'literal_c_sha256':sha(source),'original_local_header_sha256':captured_header_sha256,'current_local_header_sha256':current_header_sha256,'local_header_relation':header_relation,'local_header_qualifier_plan_sha256':qualifier_plan_sha256,'export_sha256':sha(reconstructed),'export_bytes':len(reconstructed),'module_parts':len(package['parts']),'declarations':package['declarations'],'kernel_only_ast_data':package['kernel_only_ast_data'],'source_and_packaging_byteequal':True,'frontend_inputs_now':inputs,'scope':'One real retained Cilium caller complete source,existing extraction bindings and original pointer-writer statements inline for LINK. Other operations keep existing formal extraction interfaces;whole-function fidelity/prefix simulation is not asserted. Original inline LINK is checked against captured header bytes;current readonly header evolution,when present,must exactly invert the approved const-only plan to those bytes. All current frontend inputs are recorded separately. Eight BPF-helper sites are not memcpy evidence;loaded symbol/relocation remains explicit.'}
Path(__file__).with_name('artifact.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({k:v for k,v in record.items() if k!='frontend_inputs_now'},indent=2))
