"""Task-local, synchronous observational hooks; no corpus source is modified."""
import json
import os
from pathlib import Path
import subprocess
import sys
import time

def snapshot(phase, moment):
    dest = Path(os.environ['CILIUM_AUDIT_RUN'])/phase/moment
    dest.mkdir(parents=True, exist_ok=True)
    commands = []
    def capture(name, command):
        result = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        (dest/name).write_text(result.stdout)
        (dest/(name+'.stderr')).write_text(result.stderr)
        commands.append({'time':time.time(),'command':command,'exit_code':result.returncode,'file':name})
        if result.returncode:
            print(json.dumps({'event':'audit_capture_error','command':command,'error':result.stderr}),flush=True)
        return result
    programs = capture('programs.json',['bpftool','-j','prog','show'])
    capture('cilium-version.txt',['cilium-agent','--version'])
    capture('clang-version.txt',['clang','--version'])
    maps = capture('maps.json',['bpftool','-j','map','show'])
    capture('links.json',['bpftool','-j','link','show'])
    capture('net.json',['bpftool','-j','net','show'])
    capture('interfaces.json',['ip','-j','-s','link','show'])
    capture('addresses.json',['ip','-j','addr','show'])
    namespaces = capture('namespaces.json',['ip','-j','netns','list'])
    if namespaces.returncode == 0:
        for namespace in json.loads(namespaces.stdout):
            name = namespace['name']
            capture('namespace-'+name+'-interfaces.json',['ip','-n',name,'-j','-s','link','show'])
            capture('namespace-'+name+'-addresses.json',['ip','-n',name,'-j','addr','show'])
    capture('process-affinity.txt',['sh','-c',
        'ps -eLo pid,tid,psr,comm; for p in /proc/[0-9]*/status; do '
        'sed -n "/^Name:/p;/^Pid:/p;/^Cpus_allowed_list:/p" "$p"; done'])
    if maps.returncode == 0:
        for m in json.loads(maps.stdout):
            if m.get('name','').startswith('cilium_metrics') or m['type']=='prog_array':
                capture(f'metrics-map-{m["id"]}.json',['bpftool','-j','map','dump','id',str(m['id'])])
    if programs.returncode == 0:
        for p in json.loads(programs.stdout):
            for kind in ['jited','xlated']:
                capture(f'{p["id"]}-{kind}.log', ['bpftool','prog','dump',kind,'id',str(p['id']),
                    'file',str(dest/f'{p["id"]}-{kind}.bin')])
    (dest/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')

def install(frame,event,arg):
    if event != 'return' or frame.f_code.co_name != '_print_progress':
        return
    sys.setprofile(None)
    original = frame.f_globals['_print_progress']
    state = {'phase':None,'captured':False}
    rejit = sys.modules['runner.libs.rejit']
    request = rejit._shim_request
    def observed_request(socket, payload):
        if payload.get('cmd') == 'measure_start' and state['phase'] and not state['captured']:
            snapshot(state['phase'],'start')
            state['captured'] = True
        return request(socket, payload)
    rejit._shim_request = observed_request
    def observed(event, **fields):
        phase = fields.get('phase')
        if phase in ['baseline','post_rejit'] and event == 'measurement_start':
            state.update(phase=phase,captured=False)
        if phase in ['baseline','post_rejit'] and event == 'measurement_done':
            snapshot(phase,'end')
        original(event,**fields)
    frame.f_globals['_print_progress'] = observed

if 'CILIUM_AUDIT_RUN' in os.environ:
    sys.setprofile(install)
