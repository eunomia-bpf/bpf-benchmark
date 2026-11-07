"""Functional cache-key diagnostic; CPU12-15 durations are not timing evidence."""
import json,os,traceback
from pathlib import Path
import guest as g
for p,v in [('/proc/sys/kernel/bpf_stats_enabled','1'),('/proc/sys/net/core/bpf_jit_kallsyms','1')]:Path(p).write_text(v+chr(10))
try:
 for arm,disabled in [('jit',0),('native',0),('native',1)]:
  label=f'{arm}-lowering-disabled-{disabled}'
  os.environ.update(BPFREJIT_SHIM_NATIVE_LOADER='1' if arm=='native' else '0',BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='0',BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF='1',BPFREJIT_NATIVE_LOADER_SO='/usr/local/lib/bpfrejit/libnative_loader.so',RUN_TARGET_ARCH='x86_64',BPFREJIT_NATIVE_DISABLE_MAP_LOWERING=str(disabled),BPFREJIT_SHIM_LOG=str(g.OUT/(label+'.shim.log')))
  os.environ.pop('BPFREJIT_SHIM_NATIVE_MANIFEST',None)
  runner=g.FixedKatran()
  try:
   runner.start();g.publish(g.OUT/(label+'-setup.json'),runner.artifacts)
   attach=runner.session.attach_info;entries=attach.get('xdp',[])
   ident=int(attach.get('prog_id') or attach.get('id') or (entries[0].get('id') if isinstance(entries,list) and entries else 0) or 0)
   if not ident:raise RuntimeError('no actual upstream attached XDP program')
   g.configure_katran_maps(runner.session,flags=0)
   g.command([g.HELPER,'dump',ident,0,g.OUT/(label+'.jit.bin')],g.OUT/(label+'-jit-info.json'))
   g.map_stats(g.OUT/(label+'-before.json'))
   trace=Path('/sys/kernel/tracing')
   with (trace/'kprobe_events').open('a') as f:
    f.write('p:kprog_cache/lookup __htab_map_lookup_elem map=%di:x64 key=%si:x64 k0=+0(%si):x64 k1=+8(%si):x64 k2=+16(%si):x64 k3=+24(%si):x64 k4=+32(%si):x64'+chr(10))
    f.write('r:kprog_cache/lookup_ret __htab_map_lookup_elem ret=$retval:x64 pos=+88($retval):x32'+chr(10))
   (trace/'trace').write_text('')
   (trace/'events/kprog_cache/enable').write_text('1')
   (trace/'tracing_on').write_text('1')
   g.command([g.HELPER,'test',ident,100,g.INPUT],g.OUT/(label+'-work.json'))
   (trace/'tracing_on').write_text('0')
   (trace/'events/kprog_cache/enable').write_text('0')
   (g.OUT/(label+'-lookup-trace.txt')).write_text((trace/'trace').read_text())
   with (trace/'kprobe_events').open('a') as f:f.write('-:kprog_cache/lookup'+chr(10)+'-:kprog_cache/lookup_ret'+chr(10))
   g.map_stats(g.OUT/(label+'-after.json'))
  finally:runner.stop()
 g.publish(g.OUT/'complete.json',dict(ok=True,kind='functional cache diagnostic; no comparative timing'))
except BaseException as e:
 g.publish(g.OUT/'complete.json',dict(ok=False,error=str(e),traceback=traceback.format_exc()));raise
