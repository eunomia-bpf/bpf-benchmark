#!/usr/bin/env python3
"""Post-hoc analysis of raw corpus and audit observations (no filtering)."""
import collections
import csv
import gzip
import hashlib
import json
from pathlib import Path
import re
import statistics

root=Path(__file__).resolve().parent
phases=[];programs=[];inventory=[];verdicts=[];loads=[];images=[]

def write_csv(name,rows):
    if not rows:return
    fields=list(dict.fromkeys(k for row in rows for k in row))
    with (root/name).open('w') as f:
        w=csv.DictWriter(f,fieldnames=fields);w.writeheader();w.writerows(rows)

def bytes_int(v):return int.from_bytes(bytes(int(x,16) for x in v),'little')

def metrics(folder):
    out={}
    for f in folder.glob('metrics-map-*.json'):
        values=json.loads(f.read_text())
        if not isinstance(values,list):continue
        for row in values:
            if 'values' not in row:continue
            key=bytes(int(x,16) for x in row['key'])
            out[key.hex()]=dict(reason=key[0],direction=key[1]&3,line=int.from_bytes(key[2:4],'little'),
                file=key[4],packets=sum(bytes_int(x['value'][:8]) for x in row['values']),
                bytes=sum(bytes_int(x['value'][8:16]) for x in row['values']))
    return out

def quantile(values,q):
    v=sorted(values);position=(len(v)-1)*q;i=int(position)
    return v[i] if i==len(v)-1 else v[i]+(v[i+1]-v[i])*(position-i)

def spread(values):
    return dict(n=len(values),median=statistics.median(values),min=min(values),max=max(values),
                q1=quantile(values,.25),q3=quantile(values,.75))

for label in ['paper','current']:
    for run in sorted((root/label).glob('pair-*')):
        raw=list((run/'raw').glob('*/details/apps/*cilium*.json'))
        if not raw:continue
        app=json.loads(raw[0].read_text())
        pair=int(run.name.split('-')[1]);stats=int(run.name.split('-')[3]);control=run.name.endswith('control')
        for phase in ['baseline','post_rejit']:
            data=app.get(phase)
            if data is None:continue
            audit=run/phase;start=audit/'start';finish=audit/'end'
            infos={p['id']:p for d in [start,finish] for p in json.loads((d/'programs.json').read_text())}
            attachments=collections.defaultdict(list)
            for d in [start,finish]:
                for node in json.loads((d/'net.json').read_text()):
                    for kind in ['tc','xdp']:
                        for entry in node.get(kind,[]):
                            ident=entry.get('prog_id',entry.get('id'))
                            key=kind+':'+entry['devname']+':'+entry.get('kind',entry.get('mode',''))
                            if key not in attachments[ident]:attachments[ident].append(key)
            phase_programs=[]
            for ident,p in data['bpf'].items():
                count=p['run_cnt_delta'];ns=p['run_time_ns_delta'];pid=int(ident)
                bindings=';'.join(sorted(attachments.get(pid,[])))
                full_name=infos.get(pid,{}).get('name',p['name'])
                key=bindings if bindings else 'unbound-name:'+full_name+':'+p['type']
                row=dict(label=label,pair=pair,stats=stats,control=control,phase=phase,id=pid,
                    key=key,name=p['name'],full_name=full_name,type=p['type'],run_cnt=count,
                    run_time_ns=ns,ns_per_run=ns/count if count else None,
                    bytes_jited=p['bytes_jited'],bytes_xlated=p['bytes_xlated'])
                for kind in ['jited','xlated']:
                    paths=list(audit.glob(f'*/{pid}-{kind}.bin'))
                    row[kind+'_dump_saved']=bool(paths)
                programs.append(row);phase_programs.append(row)
            b=data['bpf'].values();count=sum(p['run_cnt_delta']for p in b);ns=sum(p['run_time_ns_delta']for p in b)
            pps=[];packets=0;pktgen_errors=0
            for sample in data['workloads']:
                total=0
                for component in sample['components']:
                    text=component['stdout'];total+=int(re.search(r'(\d+)pps',text)[1])
                    packets+=int(re.search(r'pkts-sofar:\s*(\d+)',text)[1])
                    pktgen_errors+=int(re.search(r'pkts-sofar:\s*\d+\s+errors:\s*(\d+)',text)[1])
                pps.append(total)
            mt0=metrics(start);mt1=metrics(finish)
            metric_totals=collections.Counter()
            for key in sorted(mt0.keys()|mt1.keys()):
                identity=mt1.get(key,mt0.get(key));before=mt0.get(key,{}).get('packets',0);after=mt1.get(key,{}).get('packets',0)
                value=after-before
                verdicts.append(dict(label=label,pair=pair,stats=stats,control=control,phase=phase,key=key,
                    **identity,before_packets=before,after_packets=after,delta_packets=value))
                metric_totals[identity['reason']]+=value
            rx=0;tx=0
            for namespace in ['bpfbench-cepa','bpfbench-cepb']:
                filename='namespace-'+namespace+'-interfaces.json'
                a=next(x for x in json.loads((start/filename).read_text()) if x['ifname']=='eth0')['stats64']
                z=next(x for x in json.loads((finish/filename).read_text()) if x['ifname']=='eth0')['stats64']
                rx+=z['rx']['packets']-a['rx']['packets'];tx+=z['tx']['packets']-a['tx']['packets']
            phases.append(dict(label=label,pair=pair,stats=stats,control=control,phase=phase,
                status=app['status'],run_cnt=count,run_time_ns=ns,ns_per_run=ns/count if count else None,
                pps=statistics.median(pps),pktgen_packets=packets,pktgen_errors=pktgen_errors,
                policy_drops=metric_totals[133],metrics_reason_0=metric_totals[0],
                receiver_packets=rx,transmitter_packets=tx,tracked_programs=len(data['bpf']),
                measured_programs_missing_jited=sum(not x['jited_dump_saved']for x in phase_programs),
                measured_programs_missing_xlated=sum(not x['xlated_dump_saved']for x in phase_programs),run=str(run.relative_to(root))))
            a=collections.Counter((x['name'],x['type'])for x in data['bpf'].values())
            for (name,kind),number in sorted(a.items()):inventory.append(dict(label=label,pair=pair,stats=stats,
                control=control,phase=phase,scope='shim-tracked',name=name,type=kind,count=number))
            for moment,d in [('start',start),('end',finish)]:
                a=collections.Counter((x.get('name',''),x['type'])for x in json.loads((d/'programs.json').read_text()))
                for (name,kind),number in sorted(a.items()):inventory.append(dict(label=label,pair=pair,stats=stats,
                    control=control,phase=phase,scope='all-loaded-'+moment,name=name,type=kind,count=number))
            for path in audit.glob('*/*.bin'):
                images.append(dict(path=str(path.relative_to(root)),size=path.stat().st_size,
                    sha256=hashlib.sha256(path.read_bytes()).hexdigest()))
        with gzip.open(run/'host-load.jsonl.gz','rt')as f:samples=[json.loads(l)for l in f]
        for phase in ['baseline','post_rejit']:
            if not (run/phase/'start/commands.json').exists() or not (run/phase/'end/commands.json').exists():continue
            t0=json.loads((run/phase/'start/commands.json').read_text())[-1]['time']
            t1=json.loads((run/phase/'end/commands.json').read_text())[0]['time']
            window=[x for x in samples if t0<=x['time']<=t1]
            if len(window)<2:continue
            before=window[0];after=window[-1];duration=after['time']-before['time']
            for cpu in range(24):
                def ticks(sample):
                    return next(list(map(int,line.split()[1:9]))for line in sample['proc_stat'].splitlines()if line.startswith('cpu'+str(cpu)+' '))
                a=ticks(before);b=ticks(after);total=sum(b)-sum(a)
                loads.append(dict(label=label,pair=pair,stats=stats,control=control,phase=phase,
                    run=str(run.relative_to(root)),cgroup='host:cpu'+str(cpu),own_workspace='',
                    duration_seconds=duration,average_cpu_cores=(total-(b[3]-a[3])-(b[4]-a[4]))/total))
            for name,v in before['pod_cpu_stat'].items():
                if name not in after['pod_cpu_stat']:continue
                x=dict(line.split()for line in v.splitlines());y=dict(line.split()for line in after['pod_cpu_stat'][name].splitlines())
                loads.append(dict(label=label,pair=pair,stats=stats,control=control,phase=phase,run=str(run.relative_to(root)),
                    cgroup=name,own_workspace='pod901a2100_a80e_45e9_9fea_d320be468e69' in name,
                    duration_seconds=duration,average_cpu_cores=(int(y['usage_usec'])-int(x['usage_usec']))/1e6/duration))

write_csv('phases.csv',phases);write_csv('programs.csv',programs);write_csv('inventories.csv',inventory)
write_csv('verdicts.csv',verdicts);write_csv('host-load-by-pod.csv',loads);write_csv('image-manifest.csv',images)
inventory_groups=collections.defaultdict(dict)
for row in inventory:
    key=(row['label'],row['pair'],row['stats'],row['control'],row['scope'])
    inventory_groups[key].setdefault(row['phase'],collections.Counter())[(row['name'][:15],row['type'])]+=row['count']
differences=[]
for (label,pair,stats,control,scope),arms in inventory_groups.items():
    if 'baseline'not in arms or 'post_rejit'not in arms:continue
    a=arms['baseline'];b=arms['post_rejit']
    for name,kind in sorted(a.keys()|b.keys()):
        if a[(name,kind)]!=b[(name,kind)]:
            differences.append(dict(label=label,pair=pair,stats=stats,control=control,scope=scope,
                name=name,type=kind,baseline_count=a[(name,kind)],post_count=b[(name,kind)],
                difference=b[(name,kind)]-a[(name,kind)]))
write_csv('inventory-differences.csv',differences)
summary={}
for label in ['paper','current']:
    info={}
    for control in [False,True]:
        for stats in [1,0]:
            rows=[x for x in phases if x['label']==label and x['control']==control and x['stats']==stats]
            if not rows:continue
            arms={phase:[x for x in rows if x['phase']==phase]for phase in ['baseline','post_rejit']}
            if not all(arms.values()):continue
            result={phase:{'pps':spread([x['pps']for x in a]),'ns_per_run':spread([x['ns_per_run']for x in a]) if stats else None,
                'policy_drops':spread([x['policy_drops']for x in a]),'receiver_packets':spread([x['receiver_packets']for x in a]),
                'tracked_programs':[x['tracked_programs']for x in a]}for phase,a in arms.items()}
            ratios=[]
            for pair in sorted({x['pair']for x in rows}):
                a=next(x for x in arms['baseline'] if x['pair']==pair);b=next(x for x in arms['post_rejit']if x['pair']==pair)
                ratios.append(dict(pair=pair,pps_ratio=b['pps']/a['pps'],ns_ratio=a['ns_per_run']/b['ns_per_run'] if stats else None))
            result['paired_pps_ratio']=spread([x['pps_ratio']for x in ratios])
            result['paired_ns_ratio']=spread([x['ns_ratio']for x in ratios])if stats else None
            result['ratio_of_median_pps']=result['post_rejit']['pps']['median']/result['baseline']['pps']['median']
            result['ratio_of_median_ns']=result['baseline']['ns_per_run']['median']/result['post_rejit']['ns_per_run']['median']if stats else None
            info[('control'if control else 'native')+'-stats-'+str(stats)]=result
    summary[label]=info
(root/'analysis.json').write_text(json.dumps(summary,indent=2)+'\n')

groups=collections.defaultdict(list)
for row in programs:
    if row['stats']==1:groups[(row['label'],row['control'],row['phase'],row['key'])].append(row)
stats=[]
for (label,control,phase,key),rows in sorted(groups.items()):
    values=[x['ns_per_run']for x in rows if x['ns_per_run']is not None]
    stats.append(dict(label=label,control=control,phase=phase,key=key,records=len(rows),
        median_run_cnt=statistics.median(x['run_cnt']for x in rows),total_run_cnt=sum(x['run_cnt']for x in rows),
        **({'ns_'+k:v for k,v in spread(values).items()}if values else {'ns_median':None})))
write_csv('program-summary.csv',stats)
print(json.dumps({k:{g:{'pps':v['ratio_of_median_pps'],'ns':v['ratio_of_median_ns']}for g,v in x.items()}for k,x in summary.items()}))
