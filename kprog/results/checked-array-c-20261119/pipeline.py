"""Exercise the production post-verification API with one retained OTel input."""
import io
import json
from pathlib import Path
import subprocess
import sys
import tarfile

ROOT=Path('/workspaces/repository')
sys.path.insert(0,str(ROOT/'kprog/x86'))
from trusted_specializer import compile_checked_simulator

out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
archive=Path('/workspaces/kprog-raw/perf/20261116-checked-six-apps/otelcol-ebpf-profiler/service.tar.gz')
with tarfile.open(archive) as outer:
    packed=outer.extractfile('service/requests/1.success.tar.gz').read()
with tarfile.open(fileobj=io.BytesIO(packed)) as request:
    artifacts=json.load(request.extractfile('request/generated/artifacts.json'))
    metadata=json.load(request.extractfile('request/generation.metadata.json'))
    for member,name in [('trusted_x86.bpf.i','simulator.i'),
                        ('trusted_x86.bpf.bounds-input.bc','frontend.bc')]:
        (out/name).write_bytes(request.extractfile('request/generated/'+member).read())
artifacts['simulator_preprocessed']=str(out/'simulator.i')
artifacts['simulator_frontend']['path']=str(out/'frontend.bc')
artifacts['maps']=metadata['maps']
artifacts['kernel_btf']='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'
result=compile_checked_simulator(artifacts,
    ROOT/'kprog/x86/native_lab/native_link/target/release/native-link',
    Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir'))
p=subprocess.run(['llvm-objdump-18','-dr',result['native_proof_object']],
                 capture_output=True,text=True,check=True)
(out/'proof.asm').write_text(p.stdout)
assert 'system_analysis' in p.stdout
assert 'bpf_map_lookup_elem' not in p.stdout
assert '__kprog_array_lookup' not in p.stdout
(out/'summary.json').write_text(json.dumps(dict(
    source='OTel retained request 1, 20261116-checked-six-apps',
    native_proof_bytes=Path(result['native_proof_object']).stat().st_size,
    helper_call_removed=True,frontend_reused=(out/'frontend-ir-reuse.json').exists(),
    scope='Host post-verification compilation only; no new stock or app timing run'),indent=2)+'\n')
print('Production checked-sim-c API: retained frontend reused, C helper inlined, proof emitted')
