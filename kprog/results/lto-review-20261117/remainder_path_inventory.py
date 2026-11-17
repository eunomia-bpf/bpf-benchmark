#!/usr/bin/env python3
"""Count successful copy-region instruction paths in already-emitted code."""
import argparse
import json
from pathlib import Path
import re
import subprocess

here = Path(__file__).resolve().parent
prior = json.loads((here / 'evidence.json').read_text())['typed_unwinder']
fixture = Path('/var/tmp/kprog-tmp/probe-test/user.bin')
capture_path = Path('/workspaces/kprog-raw/perf/20261117-remainder-review/user-fixture.json')


def decode(path):
    output = subprocess.check_output(['objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64',
                                     '-M', 'intel', '--no-show-raw-insn', str(path)], text=True)
    rows = []
    for line in output.splitlines():
        match = re.match(r'^\s*([0-9a-f]+):\s+(\S+)\s*(.*)', line)
        if match:
            rows.append((int(match[1], 16), match[2], match[3]))
    return rows


def cut(rows, start, end):
    return [row for row in rows if start <= row[0] < end]


def success(rows, after):
    return next(row[0] for row in rows if row[0] > after and row[1:] == ('xor', 'eax,eax'))


parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--capture', action='store_true', help='Record the existing fixture before analysis.')
options = parser.parse_args()
if options.capture:
    capture_path.parent.mkdir(parents=True, exist_ok=True)
    capture = dict(source=str(fixture), mtime_ns=fixture.stat().st_mtime_ns,
                   instruction_bytes=fixture.read_bytes().hex(),
                   instructions=decode(fixture),
                   sites=fixture.with_suffix('.sites').read_text())
    capture_path.write_text(json.dumps(capture, indent=2) + '\n')
capture = json.loads(capture_path.read_text())
old = decode(Path(prior['blob']))
old_word, old_byte = [site['offset'] for site in prior['probe_recovery_sites']]
old_fragments = dict(prefix=cut(old, old_word-9, old_word),
                     word=cut(old, old_word, old_byte-8),
                     zero=cut(old, old_byte-8, old_byte),
                     byte=cut(old, old_byte, success(old, old_byte)))
new = [tuple(row) for row in capture['instructions']]
feature_setup = next(i for i, row in enumerate(new) if row[1:] == ('setne', 'r15b'))
feature_cleanup = next(i for i, row in enumerate(new) if row[1:] == ('test', 'r15b,r15b'))
selection_indices = list(range(feature_setup-2, feature_setup+2)) + [feature_cleanup, feature_cleanup+1]
smap_selection = dict(instructions=[new[i] for i in selection_indices],
                      instruction_count=len(selection_indices),
                      conditional_branches=sum(new[i][1].startswith('j') for i in selection_indices),
                      instruction_bytes=sum(new[i+1][0]-new[i][0] for i in selection_indices),
                      scope='Feature-decision instructions only; excludes STAC/CLAC, saves and policy. Guest enabled-state is not inferred from this host fixture.')
site_lines = capture['sites'].splitlines()
word, four, two, one = [int(line.split()[0]) for line in site_lines[1:5]]
new_fragments = dict(prefix=cut(new, word-9, word), word=cut(new, word, four-9),
                     test4=cut(new, four-9, four), step4=cut(new, four, two-9),
                     test2=cut(new, two-9, two), step2=cut(new, two, one-8),
                     test1=cut(new, one-8, one), step1=cut(new, one, success(new, one)))
models = []
for size in [0, 1, 2, 3, 4, 5, 6, 7, 8, 16, 144]:
    words, remainder = divmod(size, 8)
    old_path = (old_fragments['prefix'] + old_fragments['word'] * words +
                old_fragments['zero'] + old_fragments['byte'] * remainder)
    new_path = (new_fragments['prefix'] + new_fragments['word'] * words +
                new_fragments['test4'] + new_fragments['step4'] * (remainder >= 4) +
                new_fragments['test2'] + new_fragments['step2'] * (remainder % 4 >= 2) +
                new_fragments['test1'] + new_fragments['step1'] * (remainder % 2))
    models.append(dict(size=size, old_instructions=len(old_path), new_instructions=len(new_path),
                       old_conditional_branches=sum(row[1].startswith('j') for row in old_path),
                       new_conditional_branches=sum(row[1].startswith('j') for row in new_path)))
result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              scope='Static successful copy-region paths only, ending before success XOR. Excludes policy, saves, SMAP, cleanup and cycles. No execution, build or measured regression.',
              old_blob=prior['blob'], old_user_routine_bytes=326,
              current_fixture=capture['source'], fixture_mtime_ns=capture['mtime_ns'],
              fixture_capture=str(capture_path),
              fixture_user_routine_bytes=len(bytes.fromhex(capture['instruction_bytes'])),
              observed_historical_literal_sizes=prior['nearby_esi_literals_bytes'],
              smap_selection=smap_selection,
              old_fragments=old_fragments, new_fragments=new_fragments, paths=models,
              captured_new_copy_instruction_bytes=bytes.fromhex(capture['instruction_bytes'])[word-9:success(new, one)].hex())
(here / 'remainder-paths.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps([row for row in models if row['size'] in [2, 4, 8, 16, 144]]))
