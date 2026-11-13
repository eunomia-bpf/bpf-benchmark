#!/usr/bin/env python3
"""Read-only corpus source audit; writes evidence only to the requested report dir."""
import argparse
import datetime
import difflib
import hashlib
import gzip
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[3]
APPS = {'bcc': 'bcc', 'otel': 'opentelemetry-ebpf-profiler', 'cilium': 'cilium',
        'tetragon': 'tetragon', 'tracee': 'tracee', 'katran': 'katran'}

def run(args, cwd=ROOT):
    p = subprocess.run(args, cwd=cwd, text=True, capture_output=True)
    return {'argv': [str(x) for x in args], 'returncode': p.returncode,
            'stdout': p.stdout, 'stderr': p.stderr}

def sha(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--disassemble', action='store_true', help='Collect the selected read-only ELF disassemblies')
    parser.add_argument('--finish', action='store_true', help='Summarize retained evidence without repeating the scan')
    a = parser.parse_args()
    if a.disassemble:
        disassemble(a.out)
        return
    if a.finish:
        finish(a.out)
        return
    a.out.mkdir(parents=True, exist_ok=True)
    provenance = {'utc': datetime.datetime.now(datetime.timezone.utc).isoformat(),
                  'head': run(['git', 'rev-parse', 'HEAD']),
                  'status': run(['git', 'status', '--porcelain', '--untracked-files=no']),
                  'submodules': run(['git', 'submodule', 'status']),
                  'clang': run(['clang-18', '--version']),
                  'image': run(['docker', 'image', 'inspect', 'bpf-benchmark/kprog:current',
                                '--format', '{{.Id}} {{.Created}}'])}
    changes = []
    with (a.out / 'selected-vs-upstream.patch').open('w') as patch:
        for app, upstream in APPS.items():
            base = ROOT / 'vendor/bpf' / app
            repo = ROOT / 'vendor/repos' / upstream
            provenance[app] = {'head': run(['git', 'rev-parse', 'HEAD'], repo),
                               'status': run(['git', 'status', '--porcelain', '--untracked-files=no'], repo),
                               'history': run(['git', 'log', '-12', '--format=%h %s', '--', str(base.relative_to(ROOT))])}
            for p in sorted(base.rglob('*')):
                if not p.is_file() or p.suffix not in ('.h', '.c'):
                    continue
                rel = p.relative_to(base)
                if any(s in ('objs', 'deps', 'build', '.git') for s in rel.parts):
                    continue
                q = repo / rel
                row = {'app': app, 'selected': str(p.relative_to(ROOT)),
                       'upstream': str(q.relative_to(ROOT)), 'sha256': sha(p)}
                if not q.is_file():
                    row['kind'] = 'selected-only'
                elif p.read_bytes() != q.read_bytes():
                    row['kind'] = 'different'
                    row['upstream_sha256'] = sha(q)
                    row['generated'] = 'vmlinux' in p.name
                    if not row['generated']:
                        patch.writelines(difflib.unified_diff(q.read_text().splitlines(True),
                                         p.read_text().splitlines(True),
                                         fromfile=str(q.relative_to(ROOT)), tofile=str(p.relative_to(ROOT))))
                else:
                    continue
                changes.append(row)
    guards = []
    for p in sorted((ROOT / 'vendor/bpf').rglob('*')):
        if not p.is_file() or p.suffix not in ('.c', '.h', '.py'):
            continue
        lines = p.read_text(errors='replace').splitlines()
        for i, line in enumerate(lines):
            if not re.match(r'\s*#\s*(if|ifdef|ifndef|elif)\b', line) or not re.search(r'MICRO_NATIVE|__NATIVE__|NATIVE_COMPIL', line):
                continue
            # For an elif, capture through the containing branch's endif.
            depth = 0 if re.match(r'\s*#\s*elif\b', line) else -1
            end = len(lines)
            for j in range(i, len(lines)):
                if re.match(r'\s*#\s*(if|ifdef|ifndef)\b', lines[j]):
                    depth += 1
                elif re.match(r'\s*#\s*endif\b', lines[j]):
                    if depth == 0:
                        end = j + 1
                        break
                    depth -= 1
            guards.append({'file': str(p.relative_to(ROOT)), 'line': i + 1,
                           'text': '\n'.join(lines[i:end])})
    objects = []
    stage = ROOT / 'vendor/build/native-bpf/x86/stage'
    for p in sorted(stage.rglob('*.native.o')):
        symbols = run(['llvm-nm-18', '--format=posix', str(p)])
        if symbols['returncode']:
            raise RuntimeError(symbols)
        objects.append({'file': str(p.relative_to(ROOT)), 'sha256': sha(p),
                        'symbols': symbols['stdout']})
    for name, data in [('provenance', provenance), ('source-differences', changes),
                       ('guards', guards), ('objects', objects)]:
        (a.out / (name + '.json')).write_text(json.dumps(data, indent=2) + '\n')
    print(json.dumps({'changed_source_files': {app: sum(r['app'] == app for r in changes) for app in APPS},
                      'guards': len(guards), 'staged_objects': len(objects)}, indent=2))

def disassemble(out):
    rows = []
    items = {'cilium': ['bpf_lxc','bpf_host','bpf_overlay','bpf_sock','bpf_xdp','bpf_wireguard'],
             'bcc': ['runqlat','biosnoop','tcplife'],
             'tetragon': ['bpf_generic_kprobe_v61','bpf_execve_event_v61','bpf_fork_v511'],
             'tracee': ['tracee']}
    for app, names in items.items():
        for name in names:
            p = ROOT/'vendor/build/native-bpf/x86/stage'/app/(name+'.native.o')
            result = run(['llvm-objdump-18','-dr',str(p)])
            if result['returncode']: raise RuntimeError(result)
            filename = app+'-'+name+'-native.txt.gz'
            with gzip.open(out/filename,'wt') as f: f.write(result['stdout'])
            rows.append({'app':app, 'object':str(p.relative_to(ROOT)),
                         'sha256':sha(p), 'disassembly':filename,
                         'lines':len(result['stdout'].splitlines())})
    (out/'disassembly-index.json').write_text(json.dumps(rows,indent=2)+'\n')
    print('Saved',len(rows),'disassemblies')

def finish(out):
    guards = json.loads((out / 'guards.json').read_text())
    deps = json.loads((out / 'dependencies.json').read_text())
    active = {}
    for p in (ROOT / 'vendor/build/native-bpf/x86/stage').glob('*/manifest.json'):
        app = {'otelcol-ebpf-profiler': 'otel'}.get(p.parent.name, p.parent.name)
        j = json.loads(p.read_text())
        active[app] = sorted({Path(e['native_object']).name.removesuffix('.native.o') for e in j['objects']})
    (out / 'manifest-objects.json').write_text(json.dumps(active, indent=2) + '\n')
    def group(f, n):
        if f.endswith('native_memset.h'): return 'D21'
        if f.endswith('native_compat.h'):
            return {4: 'D20', 104: 'D03', 134: 'D03', 310: 'D04', 418: 'D13', 739: 'D20'}[n]
        if '/bcc/' in f: return 'D18'
        if '/otel/' in f: return 'D13'
        if '/tracee/' in f: return 'D15'
        if '/katran/' in f: return 'D16'
        if '/cilium/' in f:
            if f.endswith('bpf_lxc.c'): return 'D09'
            if f.endswith('overloadable_skb.h'): return 'D10'
            if f.endswith('static_data.h'): return 'D17'
            if f.endswith('ctx/skb.h'): return {65:'D02',145:'D10',182:'D16'}[n]
            if f.endswith('include/linux/bpf.h'): return 'D02'
            if f.endswith('helpers.h'): return 'D13'
            return 'D16'
        if '/tetragon/' in f:
            if f.endswith('cel_expr.h'): return 'D07'
            if f.endswith('bpf_process_event.h') and n in (103,158,191): return 'D05'
            if f.endswith('lib/bpf_helpers.h'): return 'D12'
            if f.endswith('lib/config.h'): return 'D17'
            if f.endswith('include/api.h'): return 'D13' if n==287 else 'D06'
            return 'D14'
        raise ValueError((f,n))
    lines = ['# Every explicit native guard', '',
             'All 67 matching conditional directives are indexed here. Full branch text is in guards.json.', '',
             'Reach is an include dependency, not proof that an inlined branch executes. Only manifest-selected objects are listed; OTel units merge into its one selected object.', '',
             '| Location | Report group | Manifest objects including header/source |', '|---|---|---|']
    for g in guards:
        f = g['file']; reaches = []
        for d in deps:
            if d['returncode']: continue
            selected = d['stem'] in active.get(d['app'], []) or d['stem'].split('/')[-1] in active.get(d['app'], []) or d['app']=='otel'
            if selected and (str(ROOT/f) in d['dependencies'] or str(ROOT/f)==d['source']):
                reaches.append(d['app'] + '/' + d['stem'])
        g['report_group'] = group(f, g['line'])
        g['manifest_include_reach'] = reaches
        reach = ', '.join(reaches) if reaches else 'No selected include dependency (or opt-in header)'
        lines.append(f"| `{f}:{g['line']}` | {g['report_group']} | {reach} |")
    (out / 'guard-review.md').write_text('\n'.join(lines)+'\n')
    (out / 'guard-reach.json').write_text(json.dumps(guards, indent=2)+'\n')
    drift = []
    for r in json.loads((out / 'source-differences.json').read_text()):
        now = sha(ROOT/r['selected'])
        if now != r['sha256']: drift.append({'file':r['selected'], 'before':r['sha256'], 'after':now})
    (out / 'end-check.json').write_text(json.dumps({'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
        'source_drift_since_scan':drift, 'head':run(['git','rev-parse','HEAD']),
        'tracked_status':run(['git','status','--porcelain','--untracked-files=no']),
        'ebpf_tetragon_undefined':run(['llvm-nm-18','--undefined-only',str(ROOT/'vendor/build/x86/tetragon/bpf_generic_kprobe_v61.o')]),
        'kernel_request':run(['pahole','-C','request','/workspaces/.agent-state/kprog-ck/build-x86/vmlinux']),
        'kernel_pid_link':run(['pahole','-C','pid_link','/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'])},indent=2)+'\n')
    print('Indexed',len(guards),'guards; source drift',len(drift))

if __name__ == '__main__':
    main()
