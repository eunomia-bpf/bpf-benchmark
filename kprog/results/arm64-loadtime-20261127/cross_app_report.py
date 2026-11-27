"""Pair live compilation replay receipts with their original generation stages."""
import collections
import io
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import tarfile

HERE=Path(__file__).resolve().parent
OUT=HERE/sys.argv[1]
record=json.loads((OUT/'controller.json').read_text())
current={case['index']:case for case in record['cases']}
rows=[]
for index,item in enumerate(record['inventory'],1):
    if item['member']:
        with tarfile.open(item['archive']) as outer:
            data=outer.extractfile(item['member']).read()
        archive=tarfile.open(fileobj=io.BytesIO(data))
    else:
        archive=tarfile.open(item['archive'])
    with archive:
        files={Path(m.name).name:m for m in archive.getmembers() if m.isfile()}
        def load(name):
            return json.loads(archive.extractfile(files[name]).read()) if name in files else None
        frontend=load('trusted_arm64.bpf.frontend.compiler.json.broker.json')
        obj=load('trusted_arm64.bpf.o.compiler.json')
        entry=archive.extractfile(files['kernel.entry']).read().decode() if 'kernel.entry' in files else None
        diagnostics=[]
        if (frontend and frontend['returncode']) or (obj and obj['returncode']):
            if 'commands.jsonl' in files:
                commands=archive.extractfile(files['commands.jsonl']).read().decode().splitlines()
                for line in commands:
                    command=json.loads(line)
                    if command['returncode']:
                        stderr=command.get('stderr','')
                        diagnostics.extend(text for text in stderr.splitlines() if any(needle in text for needle in
                            ['LLVM ERROR:', 'Allocation failed', 'PromoteMemToReg', 'SROAPass', 'error:']))
        original=dict(frontend={k:frontend.get(k) for k in ['returncode','wall_seconds','max_rss_kib']} if frontend else None,
                      object={k:obj.get(k) for k in ['returncode','wall_seconds','max_rss_kib']} if obj else None,
                      B_object_archived='trusted_arm64.bpf.o' in files, failure_diagnostics=diagnostics)
    case=current.get(index)
    replay_commands=case.get('commands',[]) if case else []
    replay_frontend=next((c for c in replay_commands if '-emit-llvm' in c['command']),None)
    comparable_flags=(frontend['command'][:frontend['command'].index('-emit-llvm')]==replay_frontend['command'][:replay_frontend['command'].index('-emit-llvm')]) if frontend and replay_frontend else None
    old_failed=bool((frontend and frontend['returncode']) or (obj and obj['returncode']))
    rows.append(dict(index=index,app=item['app'],symbol=entry,input_archive=item['archive'],input_member=item['member'],
                     original=original,original_generation_failed=old_failed,
                     replay_status=case['status'] if case else 'pending',
                     replay_commands=replay_commands,original_and_current_flags_equal=comparable_flags,
                     recovered_generation_failure=bool(old_failed and case and case['status']=='compiled')))
apps={}
for row in rows:
    artifact=OUT/('request-'+str(row['index'])+'-evidence.tar.zst')
    if not artifact.exists() and row['app']=='otelcol-ebpf-profiler/profiling' and not row['original_generation_failed']:
        artifact=OUT/'otel-original-success-evidence.tar.zst'
    if artifact.exists():
        row['replay_artifact_archive']=dict(path=artifact.name,member_prefix=str(row['index'])+'/',bytes=artifact.stat().st_size,sha256=hashlib.sha256(artifact.read_bytes()).hexdigest())
for app in sorted({r['app'] for r in rows}):
    app_rows=[r for r in rows if r['app']==app]
    completed=[r for r in app_rows if r['replay_status']!='pending']
    comparable=[r for r in completed if r['replay_status']=='compiled' and r['original']['frontend'] and r['original']['frontend']['returncode']==0]
    apps[app]=dict(inventory=len(app_rows),completed=len(completed),pending=len(app_rows)-len(completed),
                  replay_status_counts=dict(collections.Counter(r['replay_status'] for r in app_rows)),
                  completed_replay_frontend_seconds=sum(c['wall_seconds'] for r in completed for c in r['replay_commands'] if '-emit-llvm' in c['command']),
                  completed_replay_all_compiler_seconds=sum(c['wall_seconds'] for r in completed for c in r['replay_commands']),
                  original_generation_failures=sum(r['original_generation_failed'] for r in app_rows),
                  recovered_generation_failures=sum(r['recovered_generation_failure'] for r in app_rows),
                  matched_successful_original_frontend_seconds=sum(r['original']['frontend']['wall_seconds'] for r in comparable),
                  matched_replay_frontend_seconds=sum(c['wall_seconds'] for r in comparable for c in r['replay_commands'] if '-emit-llvm' in c['command']),
                  matched_replay_all_compiler_seconds=sum(c['wall_seconds'] for r in comparable for c in r['replay_commands']),
                  completed_original_frontend_max_rss_kib=max((r['original']['frontend']['max_rss_kib'] for r in completed if r['original']['frontend']),default=0),
                  completed_replay_frontend_max_rss_kib=max((c['max_rss_kib'] for r in completed for c in r['replay_commands'] if '-emit-llvm' in c['command']),default=0))
result=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),
            controller='controller.json',controller_status_at_snapshot=record.get('controller_status'),
            producer_sha256=record['producer_sha256'],macro_profile_sha256=record['macro_profile_sha256'],
            scope='Point-in-time original/replay compiler receipt pairing. Completed app compilation does not establish stock verification, native installation or frozen startup. Timing pairs contain only original-success/replay-success inputs; original generation failures/recoveries stay separate.',
            apps=apps,requests=rows)
(OUT/'compatibility.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(dict(utc=result['utc'],apps=apps,original_generation_failures=[dict(index=r['index'],app=r['app'],symbol=r['symbol'],original=r['original'],replay_status=r['replay_status']) for r in rows if r['original_generation_failed']]),indent=2))
