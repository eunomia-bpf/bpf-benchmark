#!/usr/bin/env python3
"""Record actual resource preparation for retained census resource failures."""
from pathlib import Path
import argparse,collections,datetime,hashlib,importlib.util,json,os,shutil,subprocess,sys,tarfile,traceback
R=Path("/workspaces/repository")
def guest(d):
    spec=importlib.util.spec_from_file_location("resource_submit",R/"kprog/selftests/submit.py")
    submit=importlib.util.module_from_spec(spec);spec.loader.exec_module(submit)
    rows=[]
    state=d/"state";state.mkdir(exist_ok=True)
    for group in json.loads((d/"inputs.json").read_text())["objects"]:
        resource=submit.ObjectResources.__new__(submit.ObjectResources)
        row=dict(application=group["application"],resident_instances=group["resident_instances"],source_object=group["source_object"],source_sha256=group["source_sha256"],entry=group["entry"])
        try:
            resource.__init__("x86",group["snapshot"],group["entry"],state)
            metadata,fds,details=resource.load(group["snapshot"])
            row.update(stage="resources_prepared",metadata=metadata,resources=details,map_count=len(fds))
        except Exception as error:
            row.update(stage="resource_failed",error=str(error),traceback=traceback.format_exc())
        finally:
            resource.close()
        rows.append(row)
        payload=dict(objects=len(rows),resident_instances=sum(r["resident_instances"] for r in rows),resource_instances=dict(collections.Counter({stage:sum(r["resident_instances"] for r in rows if r["stage"]==stage) for stage in {r["stage"] for r in rows}})),application_source_program_loads=0,native_execution_requests=0,programs=rows)
        (d/"progress.json").write_text(json.dumps(payload,indent=2)+"\n")
        print(row["application"],row["resident_instances"],row["stage"],row.get("error",""),flush=True)
    (d/"result.json").write_text((d/"progress.json").read_text())
def host(d,output):
    os.unshare(os.CLONE_NEWNS)
    subprocess.run(["mount","--make-rprivate","/"],check=True)
    subprocess.run(["mount","--bind",str(d/"submit.py"),str(R/"kprog/selftests/submit.py")],check=True)
    subprocess.run(["mount","--bind",str(d/"libnative_loader.so"),str(R/"kprog/libnativeloader/build/libnative_loader.so")],check=True)
    command=["taskset","-c","8-11","vng","--run","/var/tmp/kprog-tmp/S17/x86-build/arch/x86/boot/bzImage","--cpus","2","--memory","2G","--rwdir=/mnt="+str(d),"--exec","mkdir -p "+str(d)+" && mount --bind /mnt "+str(d)+" && python3 /mnt/prepare.py guest --scratch "+str(d),"--qemu-opts=-cpu host,+smap"]
    (d/"command.json").write_text(json.dumps(command,indent=2)+"\n")
    with (d/"console.log").open("w") as log:r=subprocess.run(command,stdout=log,stderr=subprocess.STDOUT)
    (d/"guest.exit").write_text(str(r.returncode)+"\n")
    if (d/"result.json").exists():
        shutil.copy2(d/"result.json",output/"result.json")
        names=["result.json","raw.tar.gz"]
    else:names=["raw.tar.gz"]
    with tarfile.open(output/"raw.tar.gz","w:gz") as tf:
        for name in ["submit.py","prepare.py","inputs.json","command.json","console.log","guest.exit","progress.json","result.json"]:
            p=d/name
            if p.exists():tf.add(p,arcname=name)
    sys.path.insert(0,"/var/tmp/kprog-tmp/A/publication")
    from publish import publish
    receipt=publish([str((output/name).relative_to(R)) for name in names],"Record stock-kernel resource preparation after source metadata adaptation","resident-resource-maps-terminal")
    (d/"publication.json").write_text(json.dumps(receipt,indent=2)+"\n")
    counts=json.loads((d/"result.json").read_text()).get("resource_instances",{}) if (d/"result.json").exists() else {"guest_exit":r.returncode}
    with Path("/workspaces/.agent-state/kprog-lanes/COORDINATION.md").open("a") as f:f.write("\n- LOCAL A FOR C/R/COORDINATOR "+datetime.datetime.now(datetime.timezone.utc).isoformat()+": PUSHED "+receipt["commit"]+" resource-only S17 stock-kernel outcomes "+json.dumps(counts)+". Captured original source/code/data/BTF, temporary local-entry/maps-only view; nativeexecutionrequests0/application-source-program-loads0. Actual generation/compile/verifier remain separate census stages; active275guest retained.\n")
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument("mode",choices=["guest","host"]);p.add_argument("--scratch",type=Path,required=True);p.add_argument("--output",type=Path);a=p.parse_args()
    if a.mode=="guest":guest(a.scratch)
    else:host(a.scratch,a.output)
if __name__=="__main__":main()
