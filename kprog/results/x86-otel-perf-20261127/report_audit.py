"""Summarize the inventory with explicit measurement and provenance cohorts."""
import collections,csv,hashlib,json
from pathlib import Path
ROOT=Path('/workspaces/repository');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
out=Path(json.loads((LANE/'performance-data-audit.json').read_text())['result']);data=json.loads((out/'inventory.json').read_text());rows=data['runs']
x86=[r for r in rows if r.get('backend')=='x86_kvm_corpus' and r.get('cohort')=='full3x180' and r.get('stats') is True and r.get('app_status')=='ok' and r.get('per_call_ratio') and r['run']>='x86_kvm_corpus_20261122_120000']
arm=[r for r in rows if r.get('documented_batch') and r.get('cohort')=='full3x180' and r.get('stats') is True and r.get('app_status')=='ok' and r.get('per_call_ratio')]
# Keep all observations and sources; duplicate copied Spark records are explicit.
keys=set();unique=[]
for r in arm:
 key=(r['documented_batch'],r['app'],r['app_sha256'])
 if key not in keys:unique.append(r);keys.add(key)
arm=unique
comparisons=dict(scope='Selected recent full3x180 stats-on records from the complete available inventory; no global best selection. Earlier/invalid/diagnostic records remain in inventory.json. Ratios do not alone establish absolute latency or a causal code regression.',x86=x86,arm_spark=arm,missingness=data['summary'])
(out/'recent-full-comparisons.json').write_text(json.dumps(comparisons,indent=2)+'\n')
def table(rs,key):
 lines=['| App | Run / batch | eBPF ns | Native ns | Per-call ratio |','|---|---|---:|---:|---:|']
 for r in sorted(rs,key=lambda r:(r.get('app',''),r.get(key,''),r['run'])):
  lines.append('| '+r['app']+' | '+r.get(key,r['run'])+' | '+f"{r['ebpf_ns']:.1f} | {r['native_ns']:.1f} | {r['per_call_ratio']:.4f} |")
 return '\n'.join(lines)
summary=data['summary']
text=f"""# Performance data review

The inventory reads {summary['metadata_paths']} available metadata paths and expands multi-application records to {summary['rows']} rows. It retains {summary['inventory_errors']} metadata paths with no remaining app JSON and separately lists {summary['directories_without_metadata']} canonical directories without metadata. It does not decode every historical archive or certify every old run's native coverage.

All {summary['missing_image']} rows have empty inspected top-level image fields, and all {summary['missing_commit']} have empty inspected top-level source-commit fields. These schema checks do not prove that nested fields or sidecars lack provenance. Batch READMEs and launcher receipts must supply those identities. The native-size, coverage and code-change receipts remain necessary for causal comparisons. Spark guest clocks often start in1970; their batch path/README supplies chronology. AWS, Docker, Workspace QEMU and Spark are separate cohorts.

There is no single monotonic slowdown in these records. There are real large absolute-latency changes, reference-correctness changes, run spread and ratio changes caused partly by the eBPF denominator. The20% per-call/30% throughput targets remain open.

## Recent x86 full timing

These are all available successful x86 KVM3x180 stats-on observations from the corrected-reference batch beginning11-22 afternoon;10s checks and PMU profiles are excluded. Older points remain in the inventory. One must not treat this chronological table as an isolated code intervention.

{table(x86,'run')}

OTel's valid full-run native values span3371.2–3458.7ns while its ratio spans0.9299–0.9757. A better ratio does not imply a lower absolute native latency: the latest eBPF denominator is also larger. BCC likewise moves from104.1 to110.1native ns while its denominator rises enough for the ratio to improve. Cilium's11-22 clock-address defect is documented by the linker correction; after it, native is602.9/613.6/595.8ns, rather than a monotonic decline. Tetragon's large late-start latency rise affects both arms and is not hidden by its2x–3x ratios. Existing current-image evidence localizes much of the slow tracepoint to kernel ring-buffer locking, with static code equality; dynamic lock/path parity remains to check.

The pre-correction OTel1.849x and Katran fast historical references are not valid equal-work floors (documented perf-context and wrong-map lookup defects). Their raw numbers remain available; they are not promoted as best valid production results. Tracee's early0.047x capture is a diagnosed faulty read-address-policy path, not the current implementation.

## Spark full timing, batches5–8

Only documented Spark batches are listed here; guest1970 timestamps are not used as wall-clock dates.

{table(arm,'documented_batch')}

Cilium run7→run8: native978.2→969.4ns is about0.9% lower, while eBPF1012.3→988.4ns is about2.4% lower. Its per-call ratio therefore falls1.035→1.020 despite the lower native latency. The separate stats-off throughput1.124→1.009 also needs absolute throughput and workload/error context; it is not a per-call metric. Run8's other per-call ratios improve, but BCC/Katran still remain below1 and below the requested margin.

## Current diagnostic and next cause check

The current-image OTel PMU run is1x10/stats-on, not a new full rotation. It measures3193.13/3287.88ns,0.97118x. The current native unwinder body has fewer sampled periods per entry; the largest positive named kernel difference is trie_lookup_elem. Both phases execute that same kernel function. This does not prove more expensive individual trie calls: dynamic helper-call counts, queried keys and trie paths remain unmeasured. Do not rewrite the kernel or add app-specific routes from flat samples alone.

The existing common cmov change's paired short check is3326.1/3463.1ns, versus3506.3/3726.9 before. It also has a mechanism profile showing fewer dependent cmovs/array-helper stalls. Those starts do not supply a new full-rotation gain; the current full x86 timing remains frozen.

## Provenance references

- kprog/results/x86-rotate-20261122/README.md
- kprog/results/x86-rotate-20261123/README.md
- kprog/results/inner-template-20261123/x86-rotate.md
- kprog/results/cmov-branches-20261126/README.md
- kprog/results/profile-20261123/README-otel.md
- kprog/results/arm64-spark-run5-20261123/README.md
- kprog/results/arm64-spark-run6-20261124/README.md
- kprog/results/arm64-spark-run7-20261124/README.md
- kprog/results/arm64-spark-run8-20261126/README.md

The main per-call fields reuse the published may29 evaluator, which retains programs with at least100calls. all_programs_aggregate/all_programs_ratio additionally retain every positive-call program, matching the coordinator timing-history scan. Undefined aggregates are null. These definitions are explicit rather than silently mixed with the old published per-program geometric-mean table.

The inventory preserves source paths, app/metadata hashes, phase program/active counts, sample counts, throughput samples, errors and missingness. It supports a broad audit; it does not silently manufacture absent image/source provenance or treat failed/incomplete runs as performance gains.
"""
(out/'README.md').write_text(text)
print('REVIEW',len(x86),'x86 full points',len(arm),'Spark full points',out)


aliases={'otelcol-ebpf-profiler/profiling':'OTel','bcc/set':'BCC','cilium/agent':'Cilium','tetragon/observer':'Tetragon','tracee/monitor':'Tracee','katran':'Katran'}
reference=ROOT/'kprog/results/timing-history-20261127/all-runs.tsv'
other={(r['run'],r['app']):r for r in csv.DictReader(reference.open(),delimiter='	')}
matched=0;different=[]
for row in rows:
 prior=other.get((row['run'],aliases.get(row.get('app'))));value=row.get('all_programs_ratio')
 if prior is None or value is None:continue
 matched+=1
 if abs(value-float(prior['ratio']))>.000501:different.append(dict(run=row['run'],app=row.get('app'),ours=value,reference=prior['ratio']))
assert not different,different[:5]
receipt=dict(compared_rows=matched,ratio_disagreements_over_rounding=len(different),other_source=str(reference.relative_to(ROOT)),other_sha256=hashlib.sha256(reference.read_bytes()).hexdigest(),methods='All positive-call counters compared with independent coordinator scan; threshold100-compatible fields separate. Undefined numbers are null.',definitions=json.loads((out/'controller.json').read_text())['metric_definitions'])
(out/'counter-definition-crosscheck.json').write_text(json.dumps(receipt,indent=2)+chr(10))
