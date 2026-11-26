"""Retain functional-check outcomes without interpreting short-run timing."""
import json
from pathlib import Path
import re

root = Path('/workspaces/repository')
here = Path(__file__).resolve().parent
check = here / 'guest/check.log'
rows, raw = [], []
for line in check.read_text().splitlines() if check.exists() else []:
    match = re.search(r'check (\S+) rc=(\d+) run=(\S*)', line)
    if not match:
        raise ValueError('unrecognized check record: ' + line)
    app, rc, path = match.groups()
    row = dict(app=app, returncode=int(rc), run=path)
    if path:
        run = Path(path)
        if not run.is_absolute():
            run = root / run
        apps = sorted((run / 'details/apps').glob('*.json'))
        row['apps'] = []
        for source in apps:
            data = json.loads(source.read_text())
            row['apps'].append(dict(app=data['app'], status=data['status'], error=data['error']))
        shim = list((run / 'details/shim-logs').glob('*.post_rejit.log'))
        text = '\n'.join(source.read_text() for source in shim)
        row['native_replacements'] = text.count('native-loader replaced prog=')
        row['native_load_failures'] = text.count('native-loader failed')
        paths = [run / 'metadata.json', run / 'details/result.json', run / 'details/progress.json', *apps,
                 *(run / 'details/shim-logs').glob('*.log')]
        raw += [str(p.relative_to(root)) for p in paths if p.exists()]
    rows.append(row)
summary = dict(controller_completed=(here / 'completed.txt').exists(),
               scope='Default six-app functional check; no timing claim.', checks=rows)
(here / 'guest-summary.json').write_text(json.dumps(summary, indent=2) + '\n')
(here / 'raw-paths.txt').write_text('\n'.join(raw) + ('\n' if raw else ''))
print(json.dumps(summary, indent=2))
