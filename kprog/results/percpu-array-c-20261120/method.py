"""Re-derive prior diagnostics with the existing evaluation section 5 code."""
import importlib.util
import json
from pathlib import Path

root=Path('/workspaces/repository');here=Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('corpus_method',root/'analysis/corpus_analyze.py')
method=importlib.util.module_from_spec(spec);spec.loader.exec_module(method)
rows=[]
for name in ['app','combined-app','shared-app','shared-cilium','shared-bcc','tail-bcc','grouped-otel','percpu-otel']:
    receipt=root/'kprog/results/lpm-c-lto-20261120'/(name+'-result.json')
    old=json.loads(receipt.read_text())
    apps=[json.loads(p.read_text()) for p in sorted((Path(old['app_run'])/'details/apps').glob('*.json'))]
    programs=method.collect_per_program({'results':apps},100,pair_by='name-type')
    ratio=method.geomean([p['ratio'] for p in programs]) if programs else None
    rows.append(dict(receipt=str(receipt),run=old['app_run'],programs=programs,
        retained=len(programs),post_over_baseline_geomean=ratio,
        ebpf_over_native=1/ratio if ratio else None,
        pooled_phase_ebpf_over_native=old.get('pooled_phase_ebpf_over_native_per_call',old['ebpf_over_native_per_call'])))
report=dict(method='Existing analysis/corpus_analyze.py collect_per_program, name-type, min run count 100; evaluation.md section 5. No applied-only filter.',
    scope='Analysis correction only. Original receipts/counters stay unchanged. Pooled phase time/count depends on program mix and is supplemental. Threshold affects analysis, never queue admission. Single short diagnostics do not isolate source changes; caller time includes tail targets.',runs=rows)
(here/'method-result.json').write_text(json.dumps(report,indent=2)+'\n')
for row in rows:
    print(Path(row['receipt']).name,row['retained'],row['post_over_baseline_geomean'],row['ebpf_over_native'])
