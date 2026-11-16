"""Compare the two hash implementations, retaining each case's JIT control."""
import json
from pathlib import Path
import sys

raw = Path(sys.argv[1])
result = dict(scope=__doc__, diagnostic='one 60-second sample/case, four vCPUs on 20-23', apps={})
for app in ['katran', 'otel']:
    cases = {}
    for mode in ['shared', 'copy']:
        data = json.loads((raw / f'{app}-{mode}/costs.json').read_text())
        base, native = data['phases']['baseline'], data['phases']['post_rejit']
        cases[mode] = dict(run=data['run'], status=data['status'],
            jit_ns_per_call=base['counter_ns_per_call'], native_ns_per_call=native['counter_ns_per_call'],
            jit_bytes=base['installed_bytes'], native_bytes=native['installed_bytes'],
            jit_over_native_per_call=base['counter_ns_per_call'] / native['counter_ns_per_call'])
        if app == 'katran':
            cases[mode]['workload'] = dict(jit_pps=base['workload_pps'], native_pps=native['workload_pps'])
        else:
            cases[mode]['workload'] = dict(
                scope='integer-loop operations exclude stress-ng; not official throughput summary',
                jit_languages=base['integer_loop_workload_by_language'],
                native_languages=native['integer_loop_workload_by_language'])
    result['apps'][app] = dict(cases=cases,
        native_shared_over_copy_ns=cases['shared']['native_ns_per_call'] / cases['copy']['native_ns_per_call'],
        copy_over_shared_control_normalized_per_call=
            cases['copy']['jit_over_native_per_call'] / cases['shared']['jit_over_native_per_call'],
        copy_added_installed_bytes=cases['copy']['native_bytes'] - cases['shared']['native_bytes'])
(raw / 'comparison.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(result, indent=2))
