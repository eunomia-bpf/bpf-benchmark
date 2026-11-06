#!/usr/bin/env python3
"""Analyze the archived samples without changing benchmark framework output."""
import csv
import json
from pathlib import Path
import statistics
ROOT=Path(__file__).resolve().parents[4]
OUT=Path(__file__).resolve().parent
SOURCE=ROOT/'micro/results/x86_kvm_micro_20260909_121208_577260/metadata.json'
data=json.loads(SOURCE.read_text())
rows=[]
for bench in data['benchmarks']:
    for run in bench['runs']:
        for sample in run['samples']:
            rows.append(dict(benchmark=bench['name'],runtime=run['runtime'],sample_index=sample['sample_index'],compile_ns=sample['compile_ns'],**sample.get('phases_ns',{})))
fields=['benchmark','runtime','sample_index','compile_ns']+sorted(set().union(*(set(row) for row in rows))-{'benchmark','runtime','sample_index','compile_ns'})
with (OUT/'samples.csv').open('w') as file:
    writer=csv.DictWriter(file,fieldnames=fields,lineterminator="\n");writer.writeheader();writer.writerows(rows)
medians=[]
for runtime in ['kernel','native_kernel']:
    selected=[row for row in rows if row['runtime']==runtime]
    for field in ['compile_ns']+sorted(set().union(*(set(row) for row in selected))-{'benchmark','runtime','sample_index','compile_ns'}):
        per_bench=[]
        for name in sorted({row['benchmark'] for row in selected}):
            values=[row[field] for row in selected if row['benchmark']==name and field in row]
            if values:per_bench.append(statistics.median(values))
        if per_bench:medians.append(dict(runtime=runtime,phase=field,benchmarks=len(per_bench),median_of_benchmark_medians_ns=statistics.median(per_bench)))
(OUT/'phase-medians.json').write_text(json.dumps(medians,indent=2)+'\n')
for row in medians:print(row['runtime'],row['phase'],row['median_of_benchmark_medians_ns']/1e6)
