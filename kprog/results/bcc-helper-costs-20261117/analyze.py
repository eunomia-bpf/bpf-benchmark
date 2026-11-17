#!/usr/bin/env python3
"""Read retained BCC helper ownership and newer per-program counters separately."""
import argparse
import json
from collections import defaultdict
from datetime import datetime, timezone
from pathlib import Path

ROOT=Path(__file__).resolve().parents[3]
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--output',type=Path,required=True)
args=parser.parse_args()
profile=ROOT/'kprog/results/limits-20261114/bcc.json'
raw_profile=Path('/workspaces/kprog-raw/C/limits/bcc')
run=ROOT/'corpus/results/x86_kvm_corpus_20261117_123339_157340'
old=json.loads(profile.read_text())
app=json.loads((run/'details/apps/bcc__set.json').read_text())
command=json.loads((raw_profile/'command.json').read_text())
result={
    'recorded_utc':datetime.now(timezone.utc).isoformat(),
    'historical_profile':{
        'source':str(profile),'raw':str(raw_profile),
        'event':command['event'],'vcpus':command['vcpus'],
        'phase_requested_seconds':command['seconds'],
        'counter_run':'x86_kvm_corpus_20261114_184517_404427',
        'scope':'Historical sampled ownership fractions, not current per-invocation helper costs.',
        'phases':{},
    },
    'newer_counters':{
        'run':str(run),'scope':'Stats-on joined clock batch. Preserve all records and invocation mix; no PMU split.',
        'phases':{},
    },
}
interesting=['program_text','ktime_get_mono_fast_ns','bpf_ktime_get_ns',
    'bpf_perf_event_output_tp','bpf_perf_event_output','bpf_perf_event_output_raw_tp',
    'htab_map_update_elem','bpf_map_update_elem','htab_map_delete_elem','bpf_map_delete_elem',
    'lookup_nulls_elem_raw','__htab_map_lookup_elem']
for phase in ['baseline','post_rejit']:
    data=old[phase]
    result['historical_profile']['phases'][phase]={
        'all_samples':data['samples'],'bpf_owned_samples':data['bpf_samples'],
        'categories':{name:{'samples':value[0],'fraction_of_bpf':value[0]/data['bpf_samples']}
                      for name,value in data['categories'].items()},
        'symbols':{name:{'samples':data['buckets'].get(name,[0])[0],
                         'fraction_of_bpf':data['buckets'].get(name,[0])[0]/data['bpf_samples']}
                   for name in interesting},
    }
    rows=[]
    groups=defaultdict(lambda:{'ids':[],'calls':0,'time_ns':0,'installed_bytes':0})
    for key,p in app[phase]['bpf'].items():
        calls=p['run_cnt_delta'];time=p['run_time_ns_delta']
        rows.append(dict(p,selected_min100=calls>=100,
                         ns_per_call=time/calls if calls else None))
        if calls>=100:
            group=groups[(p['name'],p['type'])]
            group['ids'].append(p['id']);group['calls']+=calls;group['time_ns']+=time
            group['installed_bytes']+=p['bytes_jited']
    summary=[]
    for (name,kind),g in groups.items():
        summary.append(dict(g,name=name,type=kind,ns_per_call=g['time_ns']/g['calls']))
    selected=[r for r in rows if r['selected_min100']]
    calls=sum(r['run_cnt_delta'] for r in selected)
    result['newer_counters']['phases'][phase]={
        'all_program_records':len(rows),'selected_records':len(selected),
        'selected_calls':calls,'selected_time_ns':sum(r['run_time_ns_delta'] for r in selected),
        'selected_ns_per_call':sum(r['run_time_ns_delta'] for r in selected)/calls,
        'all_installed_bytes':sum(r['bytes_jited'] for r in rows),
        'all_records':rows,'groups_by_name_and_type':sorted(summary,key=lambda g:g['time_ns'],reverse=True),
    }
args.output.mkdir(parents=True,exist_ok=True)
(args.output/'costs.json').write_text(json.dumps(result,indent=2)+'\n')
lines=['Historical BCC sampled ownership (cpu-clock, not cycles or ns/call)',
       'Category / eBPF samples, % of owned / native samples, % of owned']
for category in old['baseline']['categories']:
    cells=[]
    for phase in ['baseline','post_rejit']:
        row=result['historical_profile']['phases'][phase]['categories'].get(category,{'samples':0,'fraction_of_bpf':0})
        cells.append(f"{row['samples']} {100*row['fraction_of_bpf']:.3f}%")
    lines.append(f"{category}: {' / '.join(cells)}")
lines+=['','Newer stats-on counters (do not combine with historical sample shares)',
        'Name/type / eBPF calls ns/call / native calls ns/call / count ratio']
phases=result['newer_counters']['phases']
by_phase={p:{(g['name'],g['type']):g for g in phases[p]['groups_by_name_and_type']}
          for p in phases}
for name,kind in sorted(set(by_phase['baseline'])|set(by_phase['post_rejit'])):
    base=by_phase['baseline'].get((name,kind));native=by_phase['post_rejit'].get((name,kind))
    cells=[f"{g['calls']} {g['ns_per_call']:.3f}" if g else 'absent' for g in [base,native]]
    ratio=f"{native['calls']/base['calls']:.6f}" if base and native else 'unpaired'
    lines.append(f"{name}/{kind}: {' / '.join(cells)} / {ratio}")
for phase,p in phases.items():
    lines.append(f"{phase}: {p['selected_records']}/{p['all_program_records']} selected, "
                 f"{p['selected_ns_per_call']:.3f} ns/call, {p['all_installed_bytes']} installed bytes")
(args.output/'readout.txt').write_text('\n'.join(lines)+'\n')
print('\n'.join(lines))
