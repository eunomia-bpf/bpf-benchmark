"""Replay the unchanged native-only intrinsic controls into fresh evidence."""
from pathlib import Path
import hashlib,sys,json
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
SOURCE=ROOT/'corpus/results/kprog_app_coverage_20261107/trusted-service-bcc-set/intrinsic-controls/replay.py'
script=SOURCE.read_text()
assert hashlib.sha256(script.encode()).hexdigest()=='1340d3789e79c86d86121f79b9bcb2fed7390a5899ecedb53724b9a93d14dbfe'
assert not (OUT/'summary.json').exists(),'preserve previous evidence'
pins=['kinsn/module/include/native_lab_group.h','kinsn/module/x86/bpf_x86_native_lab.c','kprog/x86/x86_sim_local_bpf.h','kprog/x86/micro-prog/generate_micro_sim_proofs.py','kprog/tv/build-x86/bpf_x86_native_lab.ko']
(OUT/'source-pins.json').write_text(json.dumps({n:hashlib.sha256((ROOT/n).read_bytes()).hexdigest() for n in pins},indent=2)+chr(10))
original='OUT=Path(__file__).resolve().parent'
assert script.count(original)==1
script=script.replace(original,'OUT=Path('+repr(str(OUT))+')')
sys.argv=[str(SOURCE),'check']
exec(compile(script,str(SOURCE),'exec'),{'__file__':str(SOURCE),'__name__':'__main__'})
