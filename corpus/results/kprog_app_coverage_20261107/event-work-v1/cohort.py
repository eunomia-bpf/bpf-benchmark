"""Functional real Tetragon cohort replay; no timing interpretation on CPU12-15."""
import os,sys,json,traceback
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent/'per-run-profile'))
import guest as g
(g.OUT/'cohort.snapshot.py').write_bytes(Path(__file__).read_bytes())
for p,v in [('/proc/sys/kernel/bpf_stats_enabled','1'),('/proc/sys/net/core/bpf_jit_kallsyms','1')]:Path(p).write_text(v+chr(10))
try:
 for arm in ['jit','native']:
  os.environ.update(BPFREJIT_SHIM_NATIVE_LOADER='1' if arm=='native' else '0',BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='0',BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF='1',BPFREJIT_NATIVE_LOADER_SO='/usr/local/lib/bpfrejit/libnative_loader.so',RUN_TARGET_ARCH='x86_64',BPFREJIT_NATIVE_DISABLE_MAP_LOWERING='0',BPFREJIT_SHIM_LOG=str(g.OUT/(arm+'.shim.log')))
  os.environ.pop('BPFREJIT_SHIM_NATIVE_MANIFEST',None)
  previous={p['id'] for p in g.proglist()};runner=g.TetragonRunner(setup_result=g.inspect_tetragon_setup())
  try:
   runner.start();g.wait_tetragon_ready(runner,arm)
   before=[p for p in g.proglist() if p['id'] not in previous];g.publish(g.OUT/(arm+'-before.json'),before)
   g.tetragon_work_counters(g.OUT/(arm+'-event-counters-before.json'),before)
   g.command([g.HELPER,'open',0,10000,g.INPUT],g.OUT/(arm+'-work.json'))
   after=[p for p in g.proglist() if p['id'] not in previous];g.publish(g.OUT/(arm+'-after.json'),after)
   g.tetragon_work_counters(g.OUT/(arm+'-event-counters-after.json'),after)
   g.publish(g.OUT/(arm+'-collector.json'),runner.session.collector_snapshot())
  finally:runner.stop()
 g.publish(g.OUT/'complete.json',dict(ok=True,kind='functional real app/cohort replay; no comparative timing'))
except BaseException as e:
 g.publish(g.OUT/'complete.json',dict(ok=False,error=str(e),traceback=traceback.format_exc()));raise
