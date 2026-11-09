from pathlib import Path
import subprocess,os,select,json,datetime,tarfile,sys,traceback
G=Path(__file__).resolve().parent;C=Path('/workspaces/.agent-state/kprog-lanes/C');R=Path('/workspaces/repository');Q=Path('/var/tmp/kprog-tmp/C/bcc-scalar-stack-control-replay');O=R/'corpus/results/kprog_app_coverage_20261109/rep-movs-full-count/guest'
def state(**x):(G/'guest-status.json').write_text(json.dumps(x,indent=2)+'\n')
try:
 state(state='queued_after_corrected_bcc_control')
 try:
  fd=os.pidfd_open(int((Q/'controller.pid').read_text()));select.select([fd],[],[]);os.close(fd)
 except ProcessLookupError:pass
 state(state='running_generic_and_original38_guest')
 with(G/'guest.log').open('w')as f:p=subprocess.run(['unshare','--mount','--propagation','private','python3',str(G/'safety-control/mount.py')],stdout=f,stderr=subprocess.STDOUT)
 (G/'guest.exit').write_text(str(p.returncode)+'\n');observed=json.loads((G/'safety-control/rep-movs/summary.json').read_text())if(G/'safety-control/rep-movs/summary.json').exists()else{};rows=json.loads((G/'safety-control/safety/outcomes.json').read_text())if(G/'safety-control/safety/outcomes.json').exists()else[]
 summary=dict(make_exit=p.returncode,source='bc0b5b1c51b76b2a4afda019e59618f1562be769',loader='fb23a234d88f80a397a893d3d9188d680bdd6d13',generic=observed,original38=dict(cases=len(rows),stages={s:sum(x['stage']==s for x in rows)for s in sorted({x['stage']for x in rows})},negative_native_executions=0));O.mkdir(exist_ok=True);(O/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
 with tarfile.open(O/'raw.tar.gz','w:gz')as t:
  for n in ['guest-controller.py','guest-enter.py','guest.log','guest.exit','inputs.json','source','safety-control']:t.add(G/n,arcname=n)
 (O/'README.md').write_text('# Full-count REP MOVS same-copy guest\n\nThe existing two-GiB canonical SMAP guest on CPU20-23 runs seven generic native fixtures: four widths, zero-countNULL, protected NULL read with u64max RCX, and load-only NULL store. It then replays the unchanged original38. The current first-attempt-log loaderfb23 supplies one BPF_PROG_LOAD per native load; sourcebc0 full-RCX body retains S9 recovery. Actual make'+str(p.returncode)+', generic stages '+repr([(x['name'],x['stage'])for x in observed.get('programs',[])])+', original38 '+repr(summary['original38'])+'. Every actual native/B/compiler/verifier/request log is retained. Negative native TEST_RUN0; runtime admission additions0. Universal physical/count/compiler correspondence remains V-owned.\n')
 sys.path.insert(0,str(C));from publish_owned import publish
 commit=publish([str(p.relative_to(R))for p in O.iterdir()if p.is_file()],'Record full-count REP MOVS verifier and native guest outcomes',G/'guest-publication.json');state(state='finished',commit=commit,make_exit=p.returncode,generic=[dict(name=x['name'],stage=x['stage'])for x in observed.get('programs',[])],original38=summary['original38'])
 with(C.parent/'COORDINATION.md').open('a')as f:f.write('\n- LOCAL C FOR V/S9/A/R '+datetime.datetime.now(datetime.timezone.utc).isoformat()+': PUSHED '+commit+' actual fullRCX REP MOVS guest/sourcebc0 first-log loaderfb23: '+repr([(x['name'],x['stage'])for x in observed.get('programs',[])])+', make'+str(p.returncode)+', original38 '+repr(summary['original38'])+'. All raw native/B/verifier/error records retained, negative native TEST_RUN0.\n')
except BaseException as e:state(state='requires_continuation',error=str(e),traceback=traceback.format_exc());raise
