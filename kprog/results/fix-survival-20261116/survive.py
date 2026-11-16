"""Inventory of functional fixes since 2026-05-29 and whether their code is still in HEAD.

For every commit since the freeze whose subject reads like a fix and that touches the loader,
linker, trusted module, direct-native module, specializer/B compiler, stock path, shim or the
app compat headers, take its added code lines (stripped, 12+ chars, no comments) and count how
many still appear in the HEAD version of the same file (paths renamed native-sim->kprog and
module->kinsn/module are mapped). Output: one line per commit with survival below 60%.
"""
import re, subprocess, sys, collections, os
os.chdir('/workspaces/repository')
PATHS = ['kprog/libnativeloader', 'kprog/x86', 'kinsn/module', 'kprog/perf/direct-native', 'kprog/stock-path',
         'runner/src', 'vendor/bpf', 'native-sim', 'module', 'runner/libs']
FIX = re.compile(r'\b(fix|fixes|fixed|repair|restore|regress|correct|resolve|handle|support|carry|bind|accept|keep|preserve|recover)', re.I)
SKIP_FILE = re.compile(r'(\.md$|\.json$|\.tsv$|\.txt$|/results/|/test/|_test\.|tests?/|\.lean$|generated|vmlinux)')
def mapped(p):
    if p.startswith('native-sim/'): return 'kprog/' + p[len('native-sim/'):]
    if p.startswith('module/'): return 'kinsn/module/' + p[len('module/'):]
    return p
log = subprocess.run(['git', 'log', '--since=2026-05-29', '--no-merges', '--format=%H%x09%ad%x09%s', '--date=format:%m-%d', '--'] + PATHS,
                     capture_output=True, text=True).stdout.splitlines()
head_cache = {}
def head_lines(p):
    if p not in head_cache:
        r = subprocess.run(['git', 'show', 'HEAD:' + p], capture_output=True, text=True, errors='replace')
        head_cache[p] = None if r.returncode else set(l.strip() for l in r.stdout.splitlines())
    return head_cache[p]
rows = []
n_fix = 0
for line in log:
    h, d, s = line.split('\t', 2)
    if not FIX.search(s): continue
    n_fix += 1
    diff = subprocess.run(['git', 'show', '--format=', '--unified=0', '--no-renames', h, '--'] + PATHS, capture_output=True, text=True, errors='replace').stdout
    cur = None; added = collections.defaultdict(list)
    for l in diff.splitlines():
        if l.startswith('+++ '):
            cur = l[6:] if l.startswith('+++ b/') else None
            if cur and SKIP_FILE.search(cur): cur = None
        elif cur and l.startswith('+') and not l.startswith('+++'):
            x = l[1:].strip()
            if len(x) >= 12 and not x.startswith(('//', '#', '*', '/*', '--')):
                added[cur].append(x)
    tot = kept = 0; gone_files = []
    for f, ls in added.items():
        hl = head_lines(mapped(f))
        tot += len(ls)
        if hl is None:
            gone_files.append(mapped(f)); continue
        kept += sum(1 for x in ls if x in hl)
    if tot >= 3 and kept / tot < 0.6:
        rows.append((d, h[:9], kept, tot, ', '.join(sorted(set(gone_files)))[:120], s[:110]))
print(f'fix-like commits since 05-29 in these paths: {n_fix}; with under 60% of their code still in HEAD: {len(rows)}')
for r in rows:
    print(f'{r[0]} {r[1]} kept {r[2]}/{r[3]} {("files gone: " + r[4]) if r[4] else ""} | {r[5]}')
