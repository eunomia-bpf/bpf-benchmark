#!/usr/bin/env python3
"""Replay every actual argument vector through the production link function in the unit executable."""
import argparse
from collections import Counter,defaultdict
import json
import os
from pathlib import Path
import subprocess
p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True)
p.add_argument('--test-executable',type=Path,required=True);args=p.parse_args()
args.output.mkdir(parents=True,exist_ok=True)
indices=Path('kprog/results/current-link-capture-20261117');summaries=defaultdict(Counter);rows=[];errors=[]
for name in ['otelcol-ebpf-profiler_profiling','bcc_set','cilium_agent','tetragon_observer','tracee_monitor','katran']:
    try:index=json.loads((indices/(name+'.json')).read_text())
    except (OSError,ValueError) as error:errors.append(dict(app=name,error=str(error)));continue
    for request in index['captures']:
        capture=Path(request['capture']);folder=args.output/name/capture.name;folder.mkdir(parents=True)
        argv=['native-link',*json.loads((capture/'adapter.json').read_text())['argv']]
        for option,value in [('--input',request['proof']),('--link-plan',request['plan']),
            ('--output',str(folder/'image.blob')),('--output-relocs',str(folder/'image.relocs')),
            ('--output-map-patches',str(folder/'image.maps')),('--output-abi',str(folder/'image.abi'))]:
            argv[argv.index(option)+1]=value
        if '--show' not in argv:argv.append('--show')
        argfile=folder/'args.json';argfile.write_text(json.dumps(argv,indent=2)+'\n')
        invocation=[str(args.test_executable),'--exact','tests::replay_captured_link_request','--ignored','--nocapture']
        (folder/'invocation.json').write_text(json.dumps(invocation,indent=2)+'\n')
        env=os.environ.copy();env['NATIVE_LINK_CAPTURE_ARGV']=str(argfile)
        with (folder/'stdout').open('w') as stdout,(folder/'stderr').open('w') as stderr:
            status=subprocess.run(invocation,env=env,stdout=stdout,stderr=stderr).returncode
        row=dict(app=request['app'],symbol=request['symbol'],capture=str(capture),
            proof=request['proof'],plan=request['plan'],output=str(folder),
            captured_linker_returncode=request['linker_returncode'],returncode=status)
        c=summaries[request['app']];c.update(requests=1,ok=int(status==0),failed=int(status!=0))
        if status==0:
            data=(folder/'image.blob').read_bytes()
            regions=[json.loads(line.split(' ',1)[1]) for line in (folder/'stderr').read_text().splitlines()
                     if line.startswith('native-link-lto-range ')]
            row.update(payload_bytes=len(data),lto_ranges=regions);c.update(payload_bytes=len(data))
        else:row['error_tail']=((folder/'stderr').read_text()+'\n'+(folder/'stdout').read_text())[-2500:]
        (folder/'result.json').write_text(json.dumps(row,indent=2)+'\n');rows.append(row)
        print(request['app'],request['symbol'],'returncode',status,flush=True)
j=dict(scope='Same production link(Args) body and parser through existing Cargo unit executable, '
    'with actual paired captured arguments and original flags. Canonical CLI is untouched. No invented facts, '
    'installed-program counts, verification or timing claims.',test_executable=str(args.test_executable),
    summaries={k:dict(v) for k,v in sorted(summaries.items())},index_errors=errors,requests=rows)
(args.output/'replay.json').write_text(json.dumps(j,indent=2)+'\n')
lines=['app requests ok failed payload_bytes']+[app+' '+' '.join(str(c[k]) for k in ['requests','ok','failed','payload_bytes']) for app,c in sorted(summaries.items())]
lines.append('index_errors '+str(len(errors)))
(args.output/'replay-summary.txt').write_text('\n'.join(lines)+'\n');print('\n'.join(lines),flush=True)
raise SystemExit(int(bool(errors) or any(c['failed'] for c in summaries.values())))
