"""Group recorded ARM service refusals across the frozen corpus applications."""
import collections
import json
from pathlib import Path
import re
import subprocess
import yaml

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
PATTERNS = [
    ('infinite loop', r'infinite loop detected'),
    ('map value bounds', r'invalid access to map value'),
    ('jump sequence complexity', r'The sequence of \d+ jumps is too complex'),
    ('modified context pointer', r'dereference of modified ctx'),
    ('scalar memory access', r'invalid mem access'),
    ('packet bounds', r'invalid access to packet'),
    ('read-only typed object store', r'only read is supported'),
    ('context layout', r'invalid bpf_context access'),
    ('typed argument layout', r"doesn't have \d+-th argument"),
    ('typed field layout', r"doesn't have field"),
    ('unbounded memory access', r'unbounded memory access'),
    ('stack bounds', r'invalid (?:read|write|indirect).*stack|stack limit|BPF stack'),
    ('instruction limit', r'BPF program is too large|too many instructions'),
]
apps = yaml.safe_load((ROOT/'corpus/config/macro_apps.yaml').read_text())['apps']
controllers = [dict(json.loads(p.read_text()), directory=p.parent) for p in HERE.glob('guest-*/controller.json')]
for controller in controllers:
    if 'app' not in controller:
        controller['app'] = controller['cases'][0]['app']
summary = dict(utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
               scope='Latest available completed ARM outcome per frozen corpus app. Active and absent app reports retain their state. Groups describe recorded diagnostics; shared causes and corrected acceptance require investigation.',
               apps=[], stock_refusals=[], generation_failures=[], native_install_failures=[])
for app in apps:
    candidates = sorted((r for r in controllers if r['app'] == app), key=lambda r: r['started_utc'])
    item = dict(app=app, latest_controller=candidates[-1]['directory'].name if candidates else None,
                latest_controller_status=candidates[-1].get('controller_status') if candidates else None)
    selected = None
    for controller in reversed(candidates):
        if 'controller_status' not in controller:
            continue
        name = app.split('/')[0]+'-outcome.json'
        path = controller['directory']/name
        if not path.exists():
            path = HERE/name
        if path.exists():
            report = json.loads(path.read_text())
            if report['revision'] == controller['revision']:
                selected = (controller, path, report)
                break
    if selected is None:
        item['report_state'] = 'pending'
        summary['apps'].append(item)
        continue
    controller, path, report = selected
    item.update(report_state='available', controller=controller['directory'].name,
                report=str(path.relative_to(ROOT)), corpus_status=report['corpus_status'],
                app_status=report['app_status'], install_outcomes=report['counts'],
                phases_present=[key for key, value in report['phases'].items() if value is not None])
    summary['apps'].append(item)
    for request in report['requests']:
        row = dict(app=app, request=request['request_id'], symbol=request['symbol'],
                   report=item['report'], execution_path=request['execution_path'])
        failure = request.get('simulator_failure', {})
        if not request['b_generated']:
            summary['generation_failures'].append(dict(row, stage=failure.get('stage'),
                                                       error=str(failure.get('error', ''))[-800:]))
        elif not request['b_stock_passed']:
            text = request.get('verifier_log') or failure.get('stderr', '')
            family, lines = 'unclassified', []
            for name, pattern in PATTERNS:
                matches = [s for s in text.splitlines() if re.search(pattern, s)]
                if matches:
                    family, lines = name, matches
                    break
            summary['stock_refusals'].append(dict(row, family=family, diagnostics=lines,
                                                 verifier_tail=text.splitlines()[-6:]))
        if request['status'] != 0:
            summary['native_install_failures'].append(dict(row, error=request.get('error'),
                load_stderr=request.get('load-direct.stderr') or request.get('load.stderr')))
summary['stock_refusal_groups'] = dict(collections.Counter(r['family'] for r in summary['stock_refusals']))
(HERE/'refusals.json').write_text(json.dumps(summary, indent=2)+'\n')
with (HERE/'refusals.tsv').open('w') as output:
    output.write('app\trequest\tsymbol\tfamily\texecution_path\tsource_report\tdiagnostics\n')
    for row in summary['stock_refusals']:
        output.write('\t'.join(str(x) for x in [row['app'], row['request'], row['symbol'], row['family'],
            row['execution_path'], row['report'], '; '.join(row['diagnostics'])])+'\n')
for app in summary['apps']:
    print(app['app'], app['report_state'], app.get('corpus_status'), app.get('install_outcomes'))
print('Stock refusal groups:', summary['stock_refusal_groups'])
print('Generation failures:', len(summary['generation_failures']), 'native install failures:', len(summary['native_install_failures']))
