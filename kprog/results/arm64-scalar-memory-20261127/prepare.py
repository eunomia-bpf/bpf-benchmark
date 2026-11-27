"""Read captured ARM B/metadata from committed archives, including deduped runs."""
import hashlib
import io
import json
import os
from pathlib import Path
import subprocess
import tarfile
import traceback

ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
CAPTURE=ROOT/'kprog/results/arm64-checked-corpus-20261127'
CONTROL=ROOT/'kprog/results/arm64-loadtime-20261127'
LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
token=now().replace('-','').replace(':','');OUT=HERE/('run-'+token);OUT.mkdir();RAW=Path('/workspaces/kprog-raw/perf/arm64-scalar-memory-20261127')/token;RAW.mkdir(parents=True)
r=dict(started_utc=now(),pid=os.getpid(),raw=str(RAW),result=str(OUT),source_revision=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),inputs=[],archives=[],scope='All145 originally generated B objects:117 stock-refused plus28 accepted controls acrosssixapps. Five original generation failures are not B inputs. Sources normalized only by removal of exact obsolete runtime75-macro profile; production uses current common headers and flags. Original B and qualified pre-probe controls are separately identified.')
def save():(OUT/'prepare-controller.json').write_text(json.dumps(r,indent=2)+'\n');(LANE/'scalar-run.json').write_text(json.dumps(dict(raw=str(RAW),result=str(OUT),token=token),indent=2)+'\n')
def sha(data):return hashlib.sha256(data).hexdigest()
def parts_checked(folder):
    parts=sorted(folder.glob('evidence.tar.zst.part-*'));assert parts
    for p in parts:
        oid=subprocess.check_output(['git','ls-tree','HEAD','--',str(p.relative_to(ROOT))],text=True).split()[2]
        assert oid==subprocess.check_output(['git','hash-object','--',str(p)],text=True).strip(),p
    return parts
def archive_stream(parts,consume):
    a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close()
    with tarfile.open(fileobj=b.stdout,mode='r|') as t:
        for m in t:consume(t,m)
    b.stdout.close();assert b.wait()==a.wait()==0
try:
    save();inventory=json.loads((CAPTURE/'refusals.json').read_text());profile=(CONTROL/'header-source-20261127T151253Z/runtime-overrides.txt').read_bytes();assert profile.count(b'#undef ')==75
    control_map={}
    for name in ['cross-app-20261127T121315Z','cross-app-20261127T141857Z']:
        controller=json.loads((CONTROL/name/'controller.json').read_text())
        for c in controller['cases']:
            if c['status']=='compiled':control_map.setdefault((c['app'].split('/')[0],c['original_source_sha256']),dict(directory=name,index=c['index']))
    for app in inventory['apps']:
        report=json.loads((ROOT/app['report']).read_text());selected={x['request_id']:x for x in report['requests'] if x['b_generated']};folder=CAPTURE/app['controller'];controller=json.loads((folder/'controller.json').read_text());parts=parts_checked(folder);seen=set()
        r['archives'].append(dict(controller=str(folder/'controller.json'),parts=[str(p) for p in parts]));save()
        def consume(t,m):
            if not m.isfile() or not m.name.endswith('/service.tar.gz'):return
            with tarfile.open(fileobj=t.extractfile(m),mode='r|gz') as service:
                for capsule in service:
                    name=Path(capsule.name).name
                    if not capsule.isfile() or '/requests/' not in capsule.name or not name.endswith('.tar.gz') or not name.split('.')[0].isdigit():continue
                    request=int(name.split('.')[0])
                    if request not in selected:continue
                    old=selected[request];index=len(r['inputs'])+1;dest=RAW/str(index);dest.mkdir();files={}
                    wanted={'trusted_arm64.bpf.c','trusted_arm64.bpf.o','generation.metadata.json','kernel.facts.json','kernel.metadata.json','kernel.entry','source-identities.json'}
                    with tarfile.open(fileobj=service.extractfile(capsule),mode='r|gz') as inner:
                        for member in inner:
                            leaf=Path(member.name).name
                            if member.isfile() and leaf in wanted:files[leaf]=inner.extractfile(member).read()
                    assert wanted<=files.keys(),(app['app'],request,files.keys())
                    for leaf,data in files.items():(dest/('captured.bpf.o' if leaf=='trusted_arm64.bpf.o' else leaf)).write_bytes(data)
                    source=files['trusted_arm64.bpf.c'];count=source.count(profile);assert count in [0,1]
                    normalized=source.replace(b'\n'+profile,b'',1) if count else source
                    (dest/'after.bpf.c').write_bytes(normalized)
                    row=dict(index=index,app=app['app'],request=request,symbol=old['symbol'],original_stock_passed=old['b_stock_passed'],original_native_status=old['status'],baseline_object='captured.bpf.o',baseline_kind='captured-qualified' if count else 'captured-before-const',source_member=m.name+'::'+capsule.name,captured_source_sha256=sha(source),normalized_source_sha256=sha(normalized),removed_obsolete_profile=count,files={leaf:dict(bytes=len(data),sha256=sha(data)) for leaf,data in files.items()})
                    match=control_map.get((app['app'].split('/')[0],sha(source)))
                    if match:row.update(qualified_control=match,baseline_object='const-control.bpf.o',baseline_kind='matched-qualified-pre-probe')
                    r['inputs'].append(row);seen.add(request)
            assert seen==set(selected),(app['app'],seen,set(selected));save();print('PREPARED',app['app'],len(seen),flush=True)
        archive_stream(parts,consume)
    assert len(r['inputs'])==145 and sum(not x['original_stock_passed'] for x in r['inputs'])==117
    for name in ['cross-app-20261127T121315Z','cross-app-20261127T141857Z']:
        wanted={}
        for item in r['inputs']:
            c=item.get('qualified_control')
            if c and c['directory']==name:wanted.setdefault(c['index'],[]).append(item)
        found=set()
        def controls(t,m):
            path=Path(m.name)
            if m.isfile() and path.name=='trusted_arm64.bpf.o' and path.parent.name.isdigit() and int(path.parent.name) in wanted:
                index=int(path.parent.name);data=t.extractfile(m).read()
                for item in wanted[index]:(RAW/str(item['index'])/'const-control.bpf.o').write_bytes(data)
                found.add(index)
        archive_stream(parts_checked(CONTROL/name),controls);assert found==set(wanted)
    r['baseline_kinds']={kind:sum(x['baseline_kind']==kind for x in r['inputs']) for kind in sorted({x['baseline_kind'] for x in r['inputs']})};r['controller_status']=0
except Exception:r.update(controller_status=1,exception=traceback.format_exc())
finally:
    r['ended_utc']=now();save();print(json.dumps(dict(result=str(OUT),raw=str(RAW),inputs=len(r['inputs']),status=r['controller_status'],baseline_kinds=r.get('baseline_kinds'),exception=r.get('exception'))),flush=True)
raise SystemExit(r['controller_status'])
