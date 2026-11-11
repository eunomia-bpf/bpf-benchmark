#!/usr/bin/env python3
"""usage: tally.py <rerun bodies.json>...: helper-call re-check outcome per origin class.

Each census scalar-class body is re-checked through its representative row
(rerun.py rows label row-<app>-<id>); the outcome is weighted by the body's
census instances (rows.json) and grouped by the measured origin of its scalar base."""
import collections, json, re, sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
CENSUS = HERE.parents[2] / 'kprog_app_coverage_20261109/resident-census/master-grouped/instances.json'
rows = {r['body']: r for r in json.load(open(HERE / 'rows.json'))}
programs = json.load(open(CENSUS))['programs']
representative = {}
for p in programs:
    if p['body_sha256'] in rows:
        representative.setdefault(p['body_sha256'], '%s-%d' % (p['application'].split('/')[0], p['representative_id']))
outcomes = {}
for path in sys.argv[1:]:
    for key, record in json.load(open(path))['bodies'].items():
        outcome = record['outcome']
        name = key.replace('row-', '')
        value = outcome.get('failure_class') or outcome['stage']
        # Rows whose source object could not open are re-checked with the linked object
        # (273d897a2); until that outcome arrives they count as pending.
        if value != 'source_elf_open' or name not in outcomes:
            outcomes[name] = 'pending' if value == 'source_elf_open' else value
def origin(text):
    text = re.sub(r'u\d+', 'uN', text)
    if 'get_current_task' in text: return 'bpf_get_current_task return'
    if text == 'load uN from ctx': return 'ctx-loaded pointer'
    if text == 'load uN from map_value': return 'map-value pointer'
    if text == 'load uN from fp': return 'untagged stack slot'
    return 'pointer read through another scalar'
table = collections.defaultdict(collections.Counter)
for body, row in rows.items():
    table[origin(row['origin'])][outcomes.get(representative[body], 'pending')] += row['instances']
for name, counts in sorted(table.items(), key=lambda item: -sum(item[1].values())):
    print('%-38s %4d  %s' % (name, sum(counts.values()), ', '.join('%s %d' % kv for kv in counts.most_common())))
total = collections.Counter()
for counts in table.values(): total.update(counts)
print('%-38s %4d  %s' % ('all', sum(total.values()), ', '.join('%s %d' % kv for kv in total.most_common())))
