from pathlib import Path
import json,sys,os,select,hashlib,tarfile,subprocess,traceback,resource
from datetime import datetime,timezone
resource.setrlimit(resource.RLIMIT_CORE,(0,0))
R=Path('/workspaces/repository');O=R/'corpus/results/kprog_app_coverage_20261109/katran-regression-current';G=Path('/var/tmp/kprog-tmp/C/katran-regression-current');C=Path('/workspaces/.agent-state/kprog-lanes/C')
def state(**d):(G/'continuation-status.json').write_text(json.dumps(d,indent=2)+'\n')
try:
 pid=int((G/'native-context.pid').read_text());state(state='waiting_for_actual_katran_compiler',pid=pid)
 try:fd=os.pidfd_open(pid);select.select([fd],[],[]);os.close(fd)
 except ProcessLookupError:pass
 row=json.loads((G/'native-context-compiled.json').read_text());(O/'native-context-observation.json').write_text(json.dumps(row,indent=2)+'\n')
 with tarfile.open(O/'native-context-raw.tar.gz','w:gz')as t:
  for n in ['native-context','native-context.log','native-context-compiled.json']:t.add(G/n,arcname=n)
 if row['status']!='compiled':state(state='requires_compiler_continuation',observation=row);raise SystemExit(0)
 model=R/'kprog/x86/x86_sim_local_bpf.h'
 if hashlib.sha256(model.read_bytes()).hexdigest()!=row['model_sha256']:raise RuntimeError('model source changed after actual compiler capture')
 with(O/'README.md').open('a')as f:f.write('\n\nThe native XDP context repair uses the existing bpf_cast_to_kern_ctx entry representation, with offsets measured from that native ABI base. The three packet pointer fields retain their live verifier-context mapping; other native reads use the existing physical memory primitive shared with SKB. The former compile-error branch is retired. Current rebuilt Katran P compiles successfully; native-context-observation.json/raw records the actual compiler source/hash/commands. Generic runtime predicate additions0. The complete application replay uses the committed source export and preserves each failed program as eBPF.\n')
 sys.path.insert(0,str(O.parent));from publish_owned import publish
 paths=['kprog/x86/x86_sim_local_bpf.h']+[str((O/n).relative_to(R))for n in ['README.md','native-context-observation.json','native-context-raw.tar.gz']]
 h=publish(paths,'Preserve physical XDP context reads through the existing native memory path',G/'native-context-publication.json');state(state='current_master_application',source_commit=h)
 with(C.parent/'COORDINATION.md').open('a')as f:f.write('\n- LOCAL C FOR R/V/A '+datetime.now(timezone.utc).isoformat()+': PUSHED '+h+' actual Katran compiler regression repair. XDP entry now uses existing bpf_cast_to_kern_ctx physical identity likeSKB; offsets share nativeABIbase, packet data/end/meta keep typed mapping, other reads use existing raw memory primitive. Retires unmapped compile-error arm; actual rebuilt completeproducer P compiles. V generic context/O1/O2/O4 handoff remains physicalctx/storage/byte-extraction correspondence, predicates added0. Fullapp starts from readonly'+h+' with per-programBPFfallback.\n')
 with(G/'application-controller.log').open('w')as f:p=subprocess.run(['python3',str(O/'runtime.py'),h],stdout=f,stderr=subprocess.STDOUT)
 (G/'application-controller.exit').write_text(str(p.returncode)+'\n');app=json.loads((Path('/var/tmp/kprog-tmp/C/katran-regression-runtime')/'status.json').read_text());state(state='application_terminal',compiler_commit=h,application=app)
except BaseException as e:state(state='requires_continuation',error=str(e),traceback=traceback.format_exc());raise
