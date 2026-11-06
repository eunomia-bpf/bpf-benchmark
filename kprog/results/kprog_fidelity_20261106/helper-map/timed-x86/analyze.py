"""Analyze R's raw stage2 samples outside framework result generation."""
import csv
import json
from pathlib import Path
from statistics import median
ROOT=Path(__file__).resolve().parents[5]
source=ROOT/'micro/results/x86_kvm_micro_20261106_181845_426714/details/result.json'
data=json.loads(source.read_text())
assert len(data['benchmarks'])==13
rows=[];table=[]
for bench in data['benchmarks']:
    runs={run['runtime']:run for run in bench['runs']}
    assert set(runs)=={'kernel','native_kernel','native_proof'}
    summaries={}
    for runtime,run in runs.items():
        assert len(run['samples'])==3
        for sample in run['samples']:
            assert (sample['result'],sample['retval'])==(bench['expected_result'],bench['expected_retval']),(bench['name'],runtime,sample)
            rows.append(dict(benchmark=bench['name'],runtime=runtime,index=sample['sample_index'],result=sample['result'],retval=sample['retval'],exec_ns=sample['exec_ns'],compile_ns=sample['compile_ns'],**sample['phases_ns']))
        summaries[runtime]=(median(s['exec_ns'] for s in run['samples']),median(s['compile_ns'] for s in run['samples'])/1e6)
    table.append('| '+bench['name']+' | '+str(bench['expected_result'])+' | '+str(bench['expected_retval'])+' | '+' | '.join(str(summaries[r][0]) for r in ['kernel','native_kernel','native_proof'])+' | '+f"{summaries['native_kernel'][1]:.6f}"+' |')
keys=['benchmark','runtime','index','result','retval','exec_ns','compile_ns']+sorted(set().union(*(r.keys() for r in rows))-{'benchmark','runtime','index','result','retval','exec_ns','compile_ns'})
with open('samples.csv','w') as out:
    writer=csv.DictWriter(out,fieldnames=keys,lineterminator="\n");writer.writeheader();writer.writerows(rows)
Path('table.md').write_text('| Program | Expected result | Retval | Kernel ns | Bound native ns | Proof ns | Bound load ms |\n| --- | ---: | ---: | ---: | ---: | ---: | ---: |\n'+'\n'.join(table)+'\n')
print(f'{len(rows)} samples: exact expected result/retval in all13x3x3; zero disagreements')
