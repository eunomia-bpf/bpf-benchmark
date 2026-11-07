"""Keep the registered trusted service outside the unchanged corpus container."""
from pathlib import Path
from datetime import datetime,timezone
import argparse,fcntl,hashlib,json,os,shutil,signal,subprocess,sys,tarfile,tempfile,threading,traceback
R=Path('/workspaces/repository');O=Path(__file__).resolve().parent
S=Path('/workspaces/.agent-state/kprog-lanes/C/native-only-runtime')
p=argparse.ArgumentParser();p.add_argument('--samples',type=int,required=True);p.add_argument('--duration',type=int,required=True);p.add_argument('--apps',required=True);p.add_argument('--state',type=Path,default=S);a=p.parse_args();S=a.state.resolve()
subprocess.run(['insmod',str(R/'kprog/tv/build-x86/corpus-modules/bpf_x86_native_lab.ko')],check=True)
summary=dict(started=datetime.now(timezone.utc).isoformat(),apps=a.apps,samples=a.samples,duration=a.duration)
with tempfile.TemporaryDirectory(prefix='.live-',dir=O) as directory, tempfile.TemporaryDirectory(prefix='trusted-',dir=S) as private:
 live=Path(directory);state=Path(private)/'requests';state.mkdir(mode=0o700)
 summary['service_state_directory']=str(state);summary['service_state_mode']=oct(state.stat().st_mode & 0o777)
 log=(live/'service.log').open('w');reader=None;reader_errors=[];registered=False
 service=subprocess.Popen([sys.executable,str(R/'kprog/trusted_service.py'),'--arch','1','--endpoint','/sys/kernel/debug/bpf_x86_native_lab/specializer','--state',str(state),'--native-link',str(R/'kprog/x86/native_lab/native_link/target/release/native-link'),'--loader',str(R/'kprog/libnativeloader/build/trusted-native-loader')],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True,start_new_session=True)
 try:
  line=service.stdout.readline();log.write(line);log.flush()
  if not json.loads(line)['ready']:raise RuntimeError('trusted service did not register')
  registered=True
  def drain():
   try:
    for line in service.stdout:log.write(line);log.flush()
   except Exception as error:reader_errors.append(str(error))
  reader=threading.Thread(target=drain);reader.start()
  env=dict(os.environ,BPFREJIT_CORPUS_APPS=a.apps,BPFREJIT_SHIM_NATIVE_LOADER='post',BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',KEEP_WORKDIRS='all',BPFREJIT_KEEP_ALL_WORKDIRS='1',BPFREJIT_CORPUS_BPF_STATS=os.environ.get('BPFREJIT_CORPUS_BPF_STATS','1'))
  command=['make','-C',str(R),'__runtime-vm-corpus','PLATFORM=kvm','ARCH=x86','RUNTIME_CONTAINER_IMAGE=bpf-benchmark/kprog-native-only:x86-current','RUNTIME_IMAGE_TAR='+str(S/'runtime.image.tar'),'SAMPLES='+str(a.samples),'WORKLOAD_DURATION='+str(a.duration)]
  summary['command']=command
  with (live/'corpus.log').open('w') as output:done=subprocess.run(command,env=env,stdout=output,stderr=subprocess.STDOUT)
  summary['returncode']=done.returncode;done.check_returncode()
 except Exception as error:
  summary.update(error=str(error),traceback=traceback.format_exc());raise
 finally:
  if service.poll() is None:
   if registered:
    # COMPLETE wakes the client before the service finishes its terminal archive.
    with (state/'request.lock').open('rb') as request_lock:
     fcntl.flock(request_lock,fcntl.LOCK_EX)
     if service.poll() is None:os.killpg(service.pid,signal.SIGTERM)
   else:os.killpg(service.pid,signal.SIGTERM)
  service.wait()
  if reader is not None:reader.join()
  service.stdout.close()
  # The service's per-request error.json is the only place an EIO's reason
  # is written, and `private` is a TemporaryDirectory this harness deletes
  # on exit, so a failed run otherwise leaves no diagnosis behind. Keep the
  # terminal records beside the results.
  retained=[]
  root=state.parent if state.is_dir() else None
  if root is not None and root.is_dir():
   # The service writes beside --state, not only inside requests/.
   keep=O/('trusted-state-'+summary['started'].replace(':','').replace('-','')[:15])
   for item in sorted(root.rglob('*')):
    if item.is_file() and (item.suffix in ('.json','.jsonl') or item.name.endswith('.failure.tar.gz')):
     rel=item.relative_to(root);keep.mkdir(parents=True,exist_ok=True)
     (keep/rel).parent.mkdir(parents=True,exist_ok=True);shutil.copy2(item,keep/rel)
     retained.append(str(rel))
  summary['retained_service_state']=str(keep) if retained else None
  summary['retained_service_files']=sorted(retained)
  log.close();summary['finished']=datetime.now(timezone.utc).isoformat()
  with (live/'kernel.log').open('w') as kernel_log:subprocess.run(['dmesg'],stdout=kernel_log,stderr=subprocess.STDOUT)
  (live/'meminfo.txt').write_text(Path('/proc/meminfo').read_text())
  boot=Path('/proc/sys/kernel/random/boot_id').read_text().strip()
  summary['corpus_metadata']=[]
  for m in (R/'corpus/results').glob('x86_kvm_corpus_*/metadata.json'):
   data=json.loads(m.read_text())
   if data.get('launcher_boot_id')==boot:summary['corpus_metadata'].append(dict(path=str(m),status=data['status'],error_message=data.get('error_message')))
  if reader_errors:summary['service_log_error']=reader_errors
  (live/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
  archive=O/('corpus-'+datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')+'.tar.gz')
  with tarfile.open(archive,'x:gz') as target:
   target.add(live,arcname='corpus')
   target.add(state,arcname='corpus/requests')
  summary.update(archive=archive.name,archive_sha256=hashlib.sha256(archive.read_bytes()).hexdigest());(O/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
  print(json.dumps({k:summary.get(k) for k in ['returncode','corpus_metadata','archive']}),flush=True)
  if reader_errors:raise RuntimeError('service log collection failed: '+repr(reader_errors))
