"""PMU root costs per measured call; out-of-line roots have no caller claim."""
import bisect
from collections import Counter
import json
from pathlib import Path
import re
import subprocess
import sys

root = Path('/workspaces/repository')
out = Path(sys.argv[1])
app_name = json.loads((out/'command.json').read_text())['app'].replace('/','__')
log = (out/'guest.log').read_text()
run = Path(re.findall(r'"artifact_run_dir":\s*"([^"]+)"',log)[-1])
app = json.loads((run/'details/apps'/(app_name+'.json')).read_text())
perf = '/workspaces/.agent-state/kprog-ck/perf/perf'
command = [perf,'script','-i',str(out/'host.data'),
    '--guestkallsyms',str(out/'baseline.start.kallsyms'),
    '-F','time,misc,ip,pid,tid,cpu,period','--no-inline','--hide-call-graph','--ns']
with (out/'samples.txt').open('w') as output, (out/'decode.stderr').open('w') as error:
    subprocess.run(command,stdout=output,stderr=error,check=True,
                   env={**__import__('os').environ,'DEBUGINFOD_URLS':''})
pattern = re.compile(r'\s*(\d+)/(\d+)\s+\[(\d+)\]\s+(\S+)\s+'
                     r'(\d+)\.(\d{1,9}):\s+(\d+)\s+([0-9a-fA-F]+)')
samples = []
for line in (out/'samples.txt').read_text().splitlines():
    if not line.strip(): continue
    match = pattern.fullmatch(line)
    if match is None: raise ValueError('unexpected perf sample: '+line)
    pid,tid,cpu,mode,sec,frac,period,ip = match.groups()
    samples.append((int(sec)*10**9+int(frac.ljust(9,'0')),mode,int(ip,16),int(period)))

def clock_shift(guest, host):
    return guest['wall_ns']-guest['monotonic_ns']-host['wall_ns']+host['monotonic_ns']

result = dict(run=str(run),app_status=app['status'],phases={},scope=__doc__)
for phase in ('baseline','post_rejit'):
    live = json.loads((out/(phase+'.jit.json')).read_text())
    starts, ends, owners, offsets = [], [], [], []
    programs = {p['id']:dict(id=p['id'],name=p['name'],bytes=p['jited_bytes'],
                           samples=0,cycles=0,offset_cycles=Counter(),source_cycles=Counter())
                for p in live['programs']}
    ranges=[]
    for p in live['programs']:
        offset=0
        for function in p['functions']:
            ranges.append((function['address'],function['address']+function['length'],p['id'],offset))
            offset+=function['length']
    for start,end,owner,offset in sorted(ranges):
        starts.append(start);ends.append(end);owners.append(owner);offsets.append(offset)
    table=[]
    for line in (out/(phase+'.start.kallsyms')).read_text().splitlines():
        fields=line.split()
        if len(fields)>=3 and int(fields[0],16): table.append((int(fields[0],16),fields[2]))
    table.sort();addresses=[r[0] for r in table]
    guest=json.loads((out/(phase+'.start.clock.json')).read_text())
    host=json.loads((out/'host.start.clock.json').read_text())
    shift=clock_shift(guest,host)
    boundaries=[];begin=None
    for line in (run/'details/shim-logs'/(app_name+'.'+phase+'.log')).read_text().splitlines():
        match=re.match(r'\[([0-9.]+) .*?socket: cmd=measure_(start|finish)\b',line)
        if not match: continue
        stamp=round(float(match[1])*10**9)+shift
        if match[2]=='start': begin=stamp
        else:
            if begin is None: raise ValueError('measurement finish without start')
            boundaries.append((begin,stamp));begin=None
    if begin is not None or not boundaries: raise ValueError('incomplete measurement windows')
    roots=Counter();modes=Counter()
    for stamp,mode,ip,period in samples:
        if not any(a<=stamp<=b for a,b in boundaries): continue
        modes[mode]+=1
        if 'G' not in mode or 'g' in mode: continue
        i=bisect.bisect_right(starts,ip)-1
        if i>=0 and ip<ends[i]:
            p=programs[owners[i]];p['samples']+=1;p['cycles']+=period
            p['offset_cycles'][offsets[i]+ip-starts[i]]+=period
            symbol='jit:'+str(p['id'])+':'+p['name']
        else:
            i=bisect.bisect_right(addresses,ip)-1
            symbol=table[i][1] if i>=0 and ip-addresses[i]<(1<<21) else '[unknown]'
        roots[symbol]+=period
    measured=app[phase]['bpf']
    calls=sum(p['run_cnt_delta'] for p in measured.values())
    ns=sum(p['run_time_ns_delta'] for p in measured.values())
    for p in live['programs']:
        row=programs[p['id']]
        lines=sorted(p.get('lines',[]),key=lambda x:x['address'])
        line_ips=[line['address'] for line in lines]
        for start,end,owner,offset in ranges:
            if owner!=p['id']: continue
            for byte,cycles in row['offset_cycles'].items():
                ip=start+byte-offset
                if not start<=ip<end: continue
                i=bisect.bisect_right(line_ips,ip)-1
                if i>=0: row['source_cycles'][str(lines[i]['file'])+':'+str(lines[i]['line'])]+=cycles
        row['offset_cycles']=sorted(row['offset_cycles'].items())
        row['source_cycles']=dict(row['source_cycles'].most_common())
        counters=measured.get(str(p['id']))
        row['measured']=counters
        if counters and counters['run_cnt_delta']:
            row['text_cycles_per_call']=row['cycles']/counters['run_cnt_delta']
    result['phases'][phase]=dict(calls=calls,counter_ns_per_call=ns/calls,
        root_cycles=dict(roots.most_common()),root_cycles_per_app_call={s:n/calls for s,n in roots.most_common()},
        modes=dict(modes),host_windows_ns=boundaries,
        programs=sorted(programs.values(),key=lambda p:-p['cycles']))
    print(phase,'ns/call',ns/calls,'top roots',roots.most_common(8),flush=True)
(out/'costs.json').write_text(json.dumps(result,indent=2)+'\n')
