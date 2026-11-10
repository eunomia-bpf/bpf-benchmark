#!/usr/bin/env python3
"""Grouped load-only census of the 549 resident x86 instances at one committed model.

The committed resident tools do the work: corpus_resident_census.collect selects
native entries from producer manifests, corpus_resident_groups.shard submits one
representative per linked native body, and corpus_resident_verifier classifies
each outcome. This controller fixes the inputs and runtime files, groups bodies
with the same native-link proof command A used, and runs representatives on host
CPUs 8-19. Native execution requests: 0.
"""
from pathlib import Path
import argparse
import collections
import concurrent.futures
import datetime
import gzip
import hashlib
import importlib.util
import io
import json
import os
import queue
import re
import shutil
import subprocess
import sys
import tarfile
import threading

ROOT = Path('/workspaces/repository')
S = Path('/var/tmp/kprog-tmp/census-claude')
I = S / 'inputs'
RESULTS = ROOT / 'corpus/results/kprog_app_coverage_20261109/resident-census/master-grouped'
A_INPUTS = Path('/var/tmp/kprog-tmp/A/large-stack-observation/inputs')
RUNTIME_MODEL = 'af422c39195084ee3137627df943c055491358c7'
RUNTIME = Path('/var/tmp/kprog-tmp/C/stock-entry/replays') / RUNTIME_MODEL / 'runtime'
PAYLOADS = Path('/var/tmp/kprog-tmp/C/audit-recovery/native-inputs/payloads')
PRODUCERS = {
    'bcc/set': Path('/var/tmp/kprog-tmp/C/audit-recovery/application-bcc/image/native-bpf/bcc'),
    'katran': S / 'katran-image-payload',
    'cilium/agent': PAYLOADS / 'cilium',
    'otelcol-ebpf-profiler/profiling': PAYLOADS / 'otelcol-ebpf-profiler',
    'tracee/monitor': PAYLOADS / 'tracee',
    'tetragon/observer': PAYLOADS / 'tetragon',
}
PRODUCER_ORIGIN = {
    'bcc/set': 'C application-bcc image native-bpf/bcc (committed bcc-frozen-config-set control/bcc)',
    'katran': 'image bpf-benchmark/kprog-coherent-six:c-20261109 /artifacts/user/native-bpf/x86_64/katran',
    'cilium/agent': 'C audit-recovery native-inputs payloads (step5, restored compiler flags)',
    'otelcol-ebpf-profiler/profiling': 'C audit-recovery native-inputs payloads (step5, restored compiler flags)',
    'tracee/monitor': 'C audit-recovery native-inputs payloads (step5, restored compiler flags)',
    'tetragon/observer': 'C audit-recovery native-inputs payloads (step5, restored compiler flags, paired source)',
}
APPS = ['bcc/set', 'katran', 'cilium/agent', 'otelcol-ebpf-profiler/profiling',
        'tracee/monitor', 'tetragon/observer']
SHORT = {'bcc/set': 'BCC', 'katran': 'Katran', 'cilium/agent': 'Cilium',
         'otelcol-ebpf-profiler/profiling': 'OTel', 'tracee/monitor': 'Tracee',
         'tetragon/observer': 'Tetragon'}
BEST = {'bcc/set': 25, 'katran': 1, 'cilium/agent': 14,
        'otelcol-ebpf-profiler/profiling': 2, 'tracee/monitor': 5, 'tetragon/observer': 4}
WORKERS = ['8-9', '10-11', '12-13', '14-15', '16-17', '18-19']
GUEST_MEMORY = '4G'
VNG = '/opt/virtme-ng/bin/vng'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def write(path, value):
    Path(path).write_text(json.dumps(value, indent=2) + '\n')


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    value = importlib.util.module_from_spec(spec)
    sys.path.insert(0, str(Path(path).parent))
    spec.loader.exec_module(value)
    return value


def git(*args):
    return subprocess.check_output(['git', *args], cwd=ROOT, text=True)


def elf_symbols(path):
    from elftools.elf.elffile import ELFFile
    with Path(path).open('rb') as fp:
        return {s.name for s in ELFFile(fp).get_section_by_name('.symtab').iter_symbols()}


def copy_unique(source, directory):
    """Copy one immutable input into a content-named directory."""
    digest = sha(source)
    target = directory / digest[:16] / Path(source).name
    if not target.exists():
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, target)
        target.chmod(0o444)
    return target, digest


def prepare():
    I.mkdir(parents=True, exist_ok=True)
    head = git('rev-parse', 'HEAD').strip()
    files = [p for p in git('ls-tree', '-r', '--name-only', head, '--', 'kprog',
                            'kinsn/module/include').splitlines()
             if (p.startswith('kprog/') and p.count('/') == 1 and p.endswith('.py')) or
             (p.startswith('kprog/x86/') and p.count('/') == 2 and p.endswith(('.py', '.h'))) or
             (p.startswith('kprog/x86/micro-prog/') and p.endswith('.py')) or
             (p.startswith('kprog/formal/generated/') and p.endswith('.h')) or
             (p.startswith('kprog/stock-path/include/') and p.endswith('.h')) or
             p in ('kprog/stock-path/bin/clang', 'kprog/selftests/submit.py') or
             (p.startswith('kinsn/module/include/') and p.endswith('.h'))]
    source = I / 'source'
    source.mkdir(exist_ok=True)
    blob = subprocess.check_output(['git', 'archive', head, *files], cwd=ROOT)
    with tarfile.open(fileobj=io.BytesIO(blob)) as archive:
        archive.extractall(source, filter='data')
    for path in source.rglob('*'):
        if path.is_file():
            path.chmod(0o555 if path.name == 'clang' else 0o444)
    controller = S / 'controller-source'
    if not controller.exists():
        controller.symlink_to(source, target_is_directory=True)
    # Runtime files of the matched af422 replay; model sources at HEAD are
    # compared with that revision in provenance.json.
    runtime = I / 'stock-runtime'
    runtime.mkdir(exist_ok=True)
    for name in ['kprog_stock.ko', 'libnative_loader.so', 'trusted-native-loader']:
        if not (runtime / name).exists():
            shutil.copy2(RUNTIME / name, runtime / name)
    for name, target in [('native-link', I / 'native-link'), ('bzImage', I / 'bzImage')]:
        if not target.exists():
            shutil.copy2(RUNTIME / name, target)
    # Producer manifests: current payloads used by the fixed-model app replay.
    inputs_spec = json.loads((ROOT / 'corpus/results/kprog_app_coverage_20261109/'
                              'resident-census/inputs.json').read_text())
    for app in inputs_spec['applications']:
        app['original_producer'] = app['producer']
        app['producer'] = str(PRODUCERS[app['application']])
        app['coverage'] = str(ROOT / app['coverage'])
        app['archive'] = str(ROOT / app['archive'])
    inputs_spec['source_head'] = head
    write(S / 'selection-spec.json', inputs_spec)
    collector = load('census_collect', source / 'kprog/corpus_resident_census.py')
    selected = collector.collect(inputs_spec)
    selected_by_key = {(r['application'], r['source_prog_id']): r for r in selected['programs']}
    inventory = json.loads((A_INPUTS / 'run-inventory.json').read_text())
    resources = json.loads((A_INPUTS / 'resource-index.json').read_text())
    field_differences = collections.Counter()
    native_files = {}
    for row in inventory['programs']:
        key = (row['application'], row['source_prog_id'])
        fresh = selected_by_key[key]
        for field in ['name', 'context', 'program_info', 'map_info', 'helper_ids']:
            if fresh.get(field) != row.get(field):
                field_differences[field] += 1
        row['previous_native_candidates'] = row['native_candidates']
        row['manifest'] = fresh['manifest']
        row['selection_kind'] = 'current manifest'
        fresh_candidates = fresh['native_candidates']
        if not fresh_candidates and len(row['previous_native_candidates']) == 1:
            # The current manifest selects nothing; reuse the previous census
            # selection identity (object basename + symbol) on the current payload.
            previous = row['previous_native_candidates'][0]
            name = Path(previous.get('source_native_object', previous['native_object'])).name
            target = PRODUCERS[row['application']] / name
            if target.exists() and previous['symbol'] in elf_symbols(target):
                fresh_candidates = [dict(native_object=str(target), symbol=previous['symbol'],
                                         selector=dict(carried_forward=previous['selector']))]
                row['selection_kind'] = 'previous census identity on current payload'
            else:
                row['selection_kind'] = 'current manifest gap; previous identity absent from payload'
        candidates = []
        for candidate in fresh_candidates:
            target, digest = copy_unique(candidate['native_object'], I / 'native')
            native_files[str(target)] = dict(source=candidate['native_object'], sha256=digest)
            candidates.append(dict(native_object=str(target), symbol=candidate['symbol'],
                                   selector=candidate['selector'],
                                   source_native_object=candidate['native_object']))
        row['native_candidates'] = candidates
    resource_files = {}
    for resource in resources['programs']:
        target, digest = copy_unique(resource['bpf_object'], I / 'bpf-resources')
        resource_files[str(target)] = dict(source=resource['bpf_object'], sha256=digest)
        resource['previous_bpf_object'] = resource['bpf_object']
        resource['bpf_object'] = str(target)
    inventory.update(source_head=head, kernel_image=str(I / 'bzImage'),
                     instances=len(inventory['programs']),
                     native_selection='corpus_resident_census.collect on current producer manifests',
                     previous_source_head=inventory['source_head'])
    resources['source_head'] = head
    write(I / 'run-inventory.json', inventory)
    write(I / 'resource-index.json', resources)
    write(I / 'stock-progress.json', dict(source_head=head, programs=[]))
    manifests = {}
    for app, producer in PRODUCERS.items():
        manifests[app] = dict(directory=str(producer), origin=PRODUCER_ORIGIN[app],
                              manifest_sha256=sha(producer / 'manifest.json'),
                              entries=len(json.loads((producer / 'manifest.json').read_text())['objects']))
        target = I / 'manifests' / (SHORT[app] + '.manifest.json')
        target.parent.mkdir(exist_ok=True)
        shutil.copy2(producer / 'manifest.json', target)
    model_paths = ['kprog', 'kinsn', 'vendor/linux-framework', 'vendor/bpf',
                   'runner/libs/cilium_native_build.py']
    provenance = dict(
        model_head=head, runtime_model=RUNTIME_MODEL,
        model_diff_from_runtime_model=git('diff', '--stat', RUNTIME_MODEL, head, '--', *model_paths),
        working_tree_status_model_paths=git('status', '--short', '--', *model_paths),
        exported_source_files=len(files),
        runtime={str(p): sha(p) for p in [I / 'bzImage', I / 'native-link',
                                          *sorted(runtime.iterdir())]},
        runtime_origin=str(RUNTIME),
        producers=manifests, native_objects=native_files, resource_objects=resource_files,
        resident_rows=str(A_INPUTS / 'run-inventory.json'),
        resident_resources=str(A_INPUTS / 'resource-index.json'),
        resident_row_fields_differing_from_fresh_collection=dict(field_differences),
        selection={app: dict(collections.Counter(
            r['selection_kind'] + ': candidates=' + str(len(r['native_candidates']))
            for r in inventory['programs'] if r['application'] == app))
            for app in APPS},
        workers=WORKERS, guest_cpus=1, guest_memory=GUEST_MEMORY,
        native_execution_requests=0)
    write(S / 'provenance.json', provenance)
    group(inventory, head)
    print(json.dumps(dict(model_head=head, selection=provenance['selection'],
                          field_differences=dict(field_differences)), indent=2))


def group(inventory, head):
    """Group by the complete native-link proof ELF, using A's link command."""
    proofs = S / 'proofs'
    proofs.mkdir(exist_ok=True)
    groups = {}
    keyed = collections.defaultdict(list)
    host_rows = []
    for row in inventory['programs']:
        if len(row['native_candidates']) != 1:
            host_rows.append(row)
            continue
        candidate = row['native_candidates'][0]
        keyed[(candidate['native_object'], candidate['symbol'])].append(row)
    for index, ((native, symbol), members) in enumerate(keyed.items()):
        proof = proofs / (str(index) + '.proof.o')
        command = [str(I / 'native-link'), '--input', native, '--symbol', symbol,
                   '--mode', 'proof', '--preserve-entry-abi', '--output', str(proof)]
        done = subprocess.run(command, text=True, capture_output=True)
        write(proof.with_suffix('.command.json'), dict(command=command,
              returncode=done.returncode, stdout=done.stdout, stderr=done.stderr))
        if done.returncode == 0:
            identity, kind = sha(proof), 'proof ELF SHA256'
        else:
            identity = hashlib.sha256((sha(native) + ':' + symbol).encode()).hexdigest()
            kind = 'native object SHA256 plus symbol (host proof link exit %d)' % done.returncode
        entry = groups.setdefault(identity, dict(body_sha256=identity, identity_kind=kind,
            proof_object=str(proof) if done.returncode == 0 else None,
            proof_bytes=proof.stat().st_size if done.returncode == 0 else 0,
            members=[], representative=members[0]))
        entry['members'].extend(members)
    selection = []
    for row in host_rows:
        outcome = {k: row[k] for k in ['application', 'source_prog_id', 'name']}
        outcome.update(model_head=head, stage='native_selection_failed',
                       diagnostic='current producer candidates=%d' % len(row['native_candidates']),
                       generated=False, compiled=False, selection_kind=row['selection_kind'],
                       candidates=row['native_candidates'])
        selection.append(outcome)
    write(S / 'groups.json', dict(model_head=head, original=str(I),
        instances=len(inventory['programs']), candidate_groups=len(keyed),
        native_body_groups=len(groups),
        body_identity='SHA256 of complete native-link proof ELF (--mode proof --preserve-entry-abi)',
        groups=sorted(groups.values(), key=lambda g: -g['proof_bytes']),
        selection_outcomes=selection))


def run():
    data = json.loads((S / 'groups.json').read_text())
    grouped = load('census_groups', I / 'source/kprog/corpus_resident_groups.py')
    wrapper = S / 'bin/vng'
    wrapper.parent.mkdir(exist_ok=True)
    wrapper.write_text('\n'.join([
        '#!/usr/bin/python3',
        'import json, os, sys',
        'from pathlib import Path',
        'a = sys.argv[1:]',
        "a[a.index('--memory') + 1] = os.environ.get('CENSUS_GUEST_MEMORY', '" + GUEST_MEMORY + "')",
        "w = next(x.split('=', 2)[2] for x in a if x.startswith('--rwdir=/mnt='))",
        "Path(w, 'effective-vng-command.json').write_text(json.dumps(['" + VNG + "'] + a, indent=2) + chr(10))",
        "os.execv('" + VNG + "', ['" + VNG + "'] + a)", '']))
    wrapper.chmod(0o755)
    os.environ['PATH'] = str(wrapper.parent) + ':' + os.environ['PATH']
    os.environ.setdefault('CENSUS_GUEST_MEMORY', GUEST_MEMORY)
    pending = queue.Queue()
    for entry in data['groups']:
        if 'outcome' not in entry:
            pending.put(entry)
    lock = threading.Lock()

    def worker(cpu):
        while True:
            try:
                entry = pending.get_nowait()
            except queue.Empty:
                return
            started = datetime.datetime.now(datetime.timezone.utc).isoformat()
            completed = grouped.shard(S, I, entry, cpu)
            with lock:
                entry.update(completed)
                entry['started'] = started
                entry['finished'] = datetime.datetime.now(datetime.timezone.utc).isoformat()
                write(S / 'groups.json', data)
                done = sum('outcome' in g for g in data['groups'])
                print(done, len(data['groups']), entry['outcome']['stage'],
                      entry['outcome'].get('failure_class'), cpu, flush=True)

    with concurrent.futures.ThreadPoolExecutor(max_workers=len(WORKERS)) as pool:
        for job in [pool.submit(worker, cpu) for cpu in WORKERS]:
            job.result()
    write(S / 'complete.json', dict(groups=len(data['groups']),
          completed=sum('outcome' in g for g in data['groups'])))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mode', choices=['prepare', 'run'])
    args = parser.parse_args()
    prepare() if args.mode == 'prepare' else run()


if __name__ == '__main__':
    main()
