"""Link every manifest entry of a native stage with native-link, offline.

Coordinator 2026-11-21: a link failure makes the application's own load fail in the guest, so every
(object, entry symbol) of the stage is linked here first. Kernel addresses are stand-ins (one per
undefined symbol, one per data/map symbol); the loader's struct-offset keys carry the values it passes.
Only native-link's own errors are reported. Usage: offline_link.py STAGE_DIR [x86|arm64]
"""
import json, os, subprocess, sys, tempfile, collections

stage, arch = sys.argv[1], (sys.argv[2] if len(sys.argv) > 2 else 'x86')
NL = '/workspaces/repository/kprog/x86/native_lab/native_link/target/release/native-link'
KEYS = {'x86': {'__native_x86_bpf_map_max_entries_offset': 68, '__native_x86_bpf_array_ptrs_offset': 304,
                '__native_x86_bpf_prog_bpf_func_offset': 72, '__native_x86_tail_call_offset': 12},
        'arm64': {'__native_arm64_thread_info_cpu_offset': 16, '__native_arm64_bpf_map_max_entries_offset': 68,
                  '__native_arm64_bpf_array_ptrs_offset': 304, '__native_arm64_bpf_prog_bpf_func_offset': 72,
                  '__native_arm64_tail_call_offset': 28}}[arch]

import re as _re
# The names the loader's link plan carries: kSupportedHelpers, kTypedHelperSymbols, kRuntimeCallSymbols,
# the lookup symbols, and the canonical bpf_<name> the helper_targets query returns per helper ID.
_src = open('/workspaces/repository/kprog/libnativeloader/src/native_loader.cpp').read()
def _array(name):
    m = _re.search(r'%s\[\] = \{(.*?)\};' % name, _src, _re.S)
    return set(_re.findall(r'"([A-Za-z0-9_]+)"', m.group(1))) if m else set()
_uapi = open('/workspaces/repository/vendor/linux-framework/include/uapi/linux/bpf.h').read()
LOADER_HELPERS = sorted(set(_re.findall(r'\{BPF_FUNC_\w+, "(\w+)"\}', _src)) | _array('kTypedHelperSymbols')
                        | _array('kRuntimeCallSymbols')
                        | set(_re.findall(r'k\w+LookupElemSymbol\s*=\s*\n?\s*"(\w+)"', _src))
                        | {'bpf_' + n for n in _re.findall(r'^\s*FN\((\w+),', _uapi, _re.M)})

def nm(obj, *flags):
    out = subprocess.run(['llvm-nm-18', *flags, '--format=posix', obj], capture_output=True, text=True).stdout
    return [l.split() for l in out.splitlines() if l.strip()]

errors = collections.Counter(); examples = {}; total = ok = lookup_meta = 0
tmp = tempfile.mkdtemp(prefix='offline-link-')
for app in sorted(os.listdir(stage)):
    mpath = os.path.join(stage, app, 'manifest.json')
    if not os.path.exists(mpath):
        continue
    entries = json.load(open(mpath))['objects']
    seen = set()
    for e in entries:
        if not e.get('symbol') or not e.get('native_object'):
            continue
        obj = e['native_object']
        if not os.path.isabs(obj):
            obj = os.path.join(stage, app, os.path.basename(obj))
        if not os.path.exists(obj):
            obj = os.path.join(stage, app, os.path.basename(e['native_object']))
        key = (obj, e['symbol'])
        if key in seen:
            continue
        seen.add(key)
        helpers = [{'name': k, 'addr': v} for k, v in KEYS.items()]
        base = 0xffffffff81000000
        names = list(dict.fromkeys([f[0] for f in nm(obj, '-u')] + LOADER_HELPERS))
        for i, n in enumerate(names):
            helpers.append({'name': n, 'addr': base + 16 * i})
        maps = []
        for i, f in enumerate(nm(obj, '--defined-only')):
            if len(f) >= 2 and f[1] in 'DdBbRrVv':
                maps.append({'name': f[0], 'addr': 0xffff888000000000 + 4096 * i})
        plan = os.path.join(tmp, 'plan.json')
        json.dump({'version': 1, 'helpers': helpers, 'maps': maps, 'lookup_sites': [],
                   'lookup_maps': [], 'update_sites': []}, open(plan, 'w'))
        total += 1
        proof = os.path.join(tmp, 'p.proof.o')
        r = subprocess.run([NL, '--input', obj, '--symbol', e['symbol'], '--mode', 'proof', '--output', proof],
                           capture_output=True, text=True)
        if r.returncode == 0:
            r = subprocess.run([NL, '--input', proof, '--symbol', e['symbol'], '--mode', 'kernel', '--link-plan', plan,
                            '--output', os.path.join(tmp, 'b'), '--output-relocs', os.path.join(tmp, 'r'),
                            '--output-abi', os.path.join(tmp, 'a')], capture_output=True, text=True)
        if r.returncode == 0:
            ok += 1
            continue
        err = [l for l in r.stderr.splitlines() if l.startswith('Error')] or r.stderr.splitlines()[-1:]
        msg = err[0][:200] if err else 'rc=%d' % r.returncode
        if 'no matching link-plan lookup_sites' in msg or 'is missing link-plan lookup_sites' in msg:
            lookup_meta += 1  # the loader supplies lookup metadata at load; the offline plan has none
            continue
        import re
        sig = re.sub(r'"[^"]*"', '"…"', msg.split(' at ')[0])
        sig = re.sub(r'\b(in|for|symbol) [A-Za-z_][A-Za-z0-9_.]*', r'\1 …', sig)
        sig = re.sub(r'\d+', 'N', sig)
        errors[(app, sig)] += 1
        examples.setdefault((app, sig), f"{os.path.basename(obj)}:{e['symbol']}")
print(f'{arch} {stage}: {ok}/{total} entries link; {lookup_meta} stop at lookup metadata the loader supplies')
for (app, sig), n in errors.most_common():
    print(f'  {app:24s} {n:4d}  {sig}   e.g. {examples[(app, sig)]}')
