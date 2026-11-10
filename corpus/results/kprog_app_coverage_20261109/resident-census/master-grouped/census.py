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


def verifier_message(text):
    """The verifier's own error line precedes its 'processed N insns' summary."""
    lines = (text or '').splitlines()
    for index, line in enumerate(lines):
        if index and re.match(r'processed \d+ insns', line):
            return lines[index - 1].strip(), lines[max(0, index - 4):index]
    return None, []


def normalize(text):
    text = re.sub(r'0x[0-9a-fA-F]+', '0xN', text)
    return re.sub(r'\bR\d+\b', 'Rn', re.sub(r'(?<![A-Za-z])-?\d+', 'N', text)).strip()


def message_class(message):
    return 'verifier: ' + normalize(message)


def error_context(outcome, verifier_context):
    """A few lines of the stage's own error output for representative examples."""
    if verifier_context:
        return verifier_context
    compiler = '\n'.join(c.get('stderr', '') for c in outcome.get('compiler_failures') or [])
    lines = [l for l in compiler.splitlines() if 'error:' in l][:3]
    if lines:
        return lines
    service = (outcome.get('submission') or {}).get('service') or {}
    trace = (service.get('traceback') or '').strip().splitlines()
    if trace:
        return trace[-4:]
    return (outcome.get('diagnostic') or '').strip().splitlines()[-4:]


def stage_class(outcome, label):
    """Name a non-verifier stage by its own first error line when no committed label matches."""
    if label != outcome['stage']:
        return label
    service = (outcome.get('submission') or {}).get('service') or {}
    trace = (service.get('traceback') or '').strip().splitlines()
    if outcome['stage'] == 'generation_failed' and trace:
        code = [l.strip() for l in trace if l.startswith('    ') and set(l.strip()) - set('^~ ')]
        return ('generation_failed: ' + normalize(trace[-1])[:100] +
                (' at ' + code[-1][:100] if code else ''))
    if outcome['stage'] == 'compilation_failed':
        text = '\n'.join(c.get('stderr', '') for c in outcome.get('compiler_failures') or [])
        for line in text.splitlines():
            if 'error:' in line:
                return 'compiler: ' + normalize(line.split('error:', 1)[1])[:120]
    text = (outcome.get('diagnostic') or '').strip()
    return outcome['stage'] + (': ' + normalize(text.splitlines()[0])[:120] if text else '')


def store(base, name, payload):
    """Write one byte stream, split in ordered 48,000,000-byte parts when larger."""
    size = 48_000_000
    if len(payload) <= size:
        (base / name).write_bytes(payload)
        return [base / name]
    paths, parts = [], []
    for number, start in enumerate(range(0, len(payload), size)):
        path = base / (name + '.part' + str(number).zfill(3))
        path.write_bytes(payload[start:start + size])
        paths.append(path)
        parts.append(dict(file=path.name, bytes=path.stat().st_size, sha256=sha(path)))
    write(base / (name + '.parts.json'), dict(format='concatenate parts in order',
          bytes=len(payload), sha256=hashlib.sha256(payload).hexdigest(), parts=parts))
    return paths + [base / (name + '.parts.json')]


def publish():
    census = load('census_classes', I / 'source/kprog/corpus_resident_verifier.py')
    data = json.loads((S / 'groups.json').read_text())
    provenance = json.loads((S / 'provenance.json').read_text())
    RESULTS.mkdir(parents=True, exist_ok=True)
    instances, bodies, outcomes = [], [], {}
    for entry in data['groups']:
        outcome = entry['outcome']
        message, context = verifier_message(outcome.get('diagnostic', ''))
        label = outcome.get('failure_class') or census.failure_class(outcome)
        if outcome['stage'] == 'installed':
            primary = 'installed'
        elif outcome['stage'] == 'verifier_rejected' and message:
            primary = message_class(message)
        else:
            primary = stage_class(outcome, label)
        outcomes[entry['body_sha256']] = outcome
        bodies.append(dict(body_sha256=entry['body_sha256'],
            application=entry['representative']['application'],
            representative_id=entry['representative']['source_prog_id'],
            symbol=entry['representative']['native_candidates'][0]['symbol'],
            native_object=Path(entry['representative']['native_candidates'][0]
                               ['source_native_object']).name,
            instances=len(entry['members']), member_ids=[m['source_prog_id'] for m in entry['members']],
            selection_kinds=dict(collections.Counter(m['selection_kind'] for m in entry['members'])),
            stage=outcome['stage'], driver_class=label, failure_class=primary,
            verifier_message=message, verifier_context=context,
            error_context=error_context(outcome, context),
            generated=outcome.get('generated'), compiled=outcome.get('compiled'),
            worker=entry.get('worker'), cpu=entry.get('cpu'),
            started=entry.get('started'), finished=entry.get('finished')))
        for member in entry['members']:
            instances.append(dict(application=member['application'],
                source_prog_id=member['source_prog_id'], name=member['name'],
                selection_kind=member['selection_kind'], body_sha256=entry['body_sha256'],
                representative_id=entry['representative']['source_prog_id'],
                stage=outcome['stage'], generated=bool(outcome.get('generated')),
                compiled=bool(outcome.get('compiled')), driver_class=label,
                failure_class=primary, verifier_message=message))
    for outcome in data['selection_outcomes']:
        instances.append(dict(application=outcome['application'],
            source_prog_id=outcome['source_prog_id'], name=outcome['name'],
            selection_kind=outcome['selection_kind'], body_sha256=None, representative_id=None,
            stage=outcome['stage'], generated=False, compiled=False,
            driver_class='native_manifest_selection_gap',
            failure_class='native_manifest_selection_gap', verifier_message=None,
            diagnostic=outcome['diagnostic']))
    instances.sort(key=lambda r: (APPS.index(r['application']), r['source_prog_id']))
    previous = json.loads((ROOT / 'corpus/results/kprog_app_coverage_20261109/resident-census/'
                           'grouped-static/all-instances.json').read_text())['programs']

    def phases(rows):
        return dict(instances=len(rows), generated=sum(r['generated'] for r in rows),
                    compiled=sum(r['compiled'] for r in rows),
                    verifier_accepted=sum(r['stage'] == 'installed' for r in rows),
                    verifier_rejected=sum(r['stage'] == 'verifier_rejected' for r in rows))

    applications = []
    for app in APPS:
        rows = [r for r in instances if r['application'] == app]
        old = [r for r in previous if r['application'] == app]
        applications.append(dict(application=app, **phases(rows),
            failure_classes=dict(collections.Counter(
                r['failure_class'] for r in rows if r['stage'] != 'installed').most_common()),
            bodies=sum(b['application'] == app for b in bodies),
            by_selection={kind: phases([r for r in rows if r['selection_kind'] == kind])
                          for kind in sorted({r['selection_kind'] for r in rows})},
            best_verified_path_row=BEST[app],
            census_4f5={k: v for k, v in phases([dict(r, generated=bool(r.get('generated')),
                        compiled=bool(r.get('compiled'))) for r in old]).items()}))
    classes = collections.Counter(r['failure_class'] for r in instances)
    class_bodies = collections.Counter(b['failure_class'] for b in bodies)
    total = phases(instances)
    largest = next(label for label, _ in classes.most_common() if label != 'installed')
    examples = [b for b in bodies if b['failure_class'] == largest]
    examples.sort(key=lambda b: -b['instances'])
    summary = dict(model_head=provenance['model_head'], runtime_model=RUNTIME_MODEL,
        native_body_groups=len(bodies), **total,
        applications=applications,
        classes=[dict(failure_class=k, instances=v, bodies=class_bodies.get(k, 0),
                      per_application={SHORT[a]: sum(r['failure_class'] == k and r['application'] == a
                                                    for r in instances) for a in APPS})
                 for k, v in classes.most_common()],
        largest_failure_class=dict(failure_class=largest, instances=classes[largest],
            bodies=class_bodies[largest],
            representatives=[dict(application=b['application'], representative_id=b['representative_id'],
                                  symbol=b['symbol'], instances=b['instances'],
                                  verifier_message=b['verifier_message'],
                                  error_context=b['error_context']) for b in examples[:3]]),
        native_execution_requests=0, guest_memory=GUEST_MEMORY, workers=WORKERS,
        body_identity=data['body_identity'], bodies=bodies)
    write(RESULTS / 'result.json', summary)
    write(RESULTS / 'instances.json', dict(model_head=provenance['model_head'], programs=instances))
    write(RESULTS / 'provenance.json', provenance)
    paths = [RESULTS / n for n in ['result.json', 'instances.json', 'provenance.json']]
    paths += store(RESULTS, 'outcomes.json.gz', gzip.compress(
        (json.dumps(outcomes, indent=2) + '\n').encode(), mtime=0))
    # Request archives without their byte copies of the submitted native input;
    # each omitted copy is listed with its SHA256 and the identical input object.
    known = {sha(p): os.path.relpath(p, I) for p in (I / 'native').rglob('*.native.o')}
    omitted = []
    raw = io.BytesIO()
    with tarfile.open(fileobj=raw, mode='w:gz') as archive:
        for path in sorted((S / 'workers').glob('*/stock-state/*.tar.gz')):
            prefix = str(path.relative_to(S))
            with tarfile.open(path) as source_archive:
                for member in source_archive.getmembers():
                    data = source_archive.extractfile(member).read() if member.isfile() else None
                    if data is not None and member.name.endswith('.native.o'):
                        digest = hashlib.sha256(data).hexdigest()
                        if digest in known:
                            omitted.append(dict(archive=prefix, member=member.name, sha256=digest,
                                                bytes=len(data), input=known[digest]))
                            continue
                    member.name = prefix + '/' + member.name
                    archive.addfile(member, io.BytesIO(data) if data is not None else None)
        listing = (json.dumps(dict(omitted_native_input_copies=omitted), indent=2) + '\n').encode()
        info = tarfile.TarInfo('omitted-native-copies.json')
        info.size = len(listing)
        archive.addfile(info, io.BytesIO(listing))
    paths += store(RESULTS, 'requests.tar.gz', raw.getvalue())
    raw = io.BytesIO()
    with tarfile.open(fileobj=raw, mode='w:gz') as archive:
        for name in ['census.py', 'provenance.json', 'selection-spec.json', 'groups.json',
                     'prepare.log', 'run.log', 'complete.json', 'bin/vng',
                     'inputs/run-inventory.json', 'inputs/resource-index.json', 'inputs/manifests',
                     'katran-image-payload']:
            if (S / name).exists():
                archive.add(S / name, arcname=name)
        for path in sorted((S / 'proofs').glob('*.command.json')):
            archive.add(path, arcname=str(path.relative_to(S)))
        for worker in sorted((S / 'workers').iterdir()):
            for name in ['controller.log', 'stock-console.log', 'stock-service.log',
                         'stock-compiler.log', 'stock-host.log', 'effective-vng-command.json',
                         'stock-command.json', 'stock-guest.exit', 'stock-guest.sh', 'provenance.json',
                         'run-inventory.json', 'resource-index.json', 'stock-state/requests.jsonl',
                         'stock-compiler/jobs.jsonl']:
                if (worker / name).exists():
                    archive.add(worker / name, arcname=str((worker / name).relative_to(S)))
    paths += store(RESULTS, 'run-raw.tar.gz', raw.getvalue())
    shutil.copy2(Path(__file__).resolve(), RESULTS / 'census.py')
    paths.append(RESULTS / 'census.py')
    readme(summary, provenance)
    paths.append(RESULTS / 'README.md')
    write(S / 'publication-paths.json', [os.path.relpath(p, ROOT) for p in paths])
    print(json.dumps({k: summary[k] for k in ['instances', 'native_body_groups', 'generated',
          'compiled', 'verifier_accepted', 'verifier_rejected']}))


def readme(summary, provenance):
    lines = ['# Resident census at the current model', '',
        'All 549 resident x86-64 instances, model ' + summary['model_head'][:9] +
        ' (model sources identical to the matched runtime model ' + RUNTIME_MODEL[:9] +
        '). Load-only: B is generated, compiled and submitted to the stock verifier; '
        'native execution requests: 0.', '',
        '| Application | Instances | Generated | Compiled | Verifier accepted | Verifier rejected | '
        'Failure classes (instances) | Best verified-path row | 4f5 census accepted |',
        '| --- | ---: | ---: | ---: | ---: | ---: | --- | ---: | ---: |']
    for app in summary['applications']:
        classes = '; '.join('`' + k + '` ' + str(v) for k, v in app['failure_classes'].items()) or '-'
        lines.append('| ' + ' | '.join([SHORT[app['application']], str(app['instances']),
            str(app['generated']), str(app['compiled']), str(app['verifier_accepted']),
            str(app['verifier_rejected']), classes, str(app['best_verified_path_row']),
            str(app['census_4f5']['verifier_accepted'])]) + ' |')
    lines.append('| Total | ' + ' | '.join(str(summary[k]) for k in
        ['instances', 'generated', 'compiled', 'verifier_accepted', 'verifier_rejected']) +
        ' | | ' + str(sum(BEST.values())) + ' | ' +
        str(sum(a['census_4f5']['verifier_accepted'] for a in summary['applications'])) + ' |')
    lines += ['', 'Best verified-path rows are the 2026-11-08 and 2026-11-09 05:18 application '
        'installations. The 4f5 column is the 2026-11-09 census at model 4f5b7ae6d '
        '(grouped-static/all-instances.json): generated 287, compiled 253, accepted 7, rejected 235.', '',
        '## Failure classes', '',
        'Verifier rejections are named by the verifier\'s own final error line, with numbers and '
        'register indices normalized. Other stages keep the committed corpus_resident_verifier label; '
        'where that label is only the stage name, the stage\'s first error line names the class. '
        'instances.json keeps both the committed label (driver_class) and this class.',
        '', '| Class | Instances | Bodies | ' + ' | '.join(SHORT[a] for a in APPS) + ' |',
        '| --- | ---: | ---: | ' + ' | '.join('---:' for _ in APPS) + ' |']
    for row in summary['classes']:
        lines.append('| `' + row['failure_class'] + '` | ' + str(row['instances']) + ' | ' +
                     str(row['bodies']) + ' | ' +
                     ' | '.join(str(row['per_application'][SHORT[a]]) for a in APPS) + ' |')
    largest = summary['largest_failure_class']
    lines += ['', '## Largest remaining class', '',
        '`' + largest['failure_class'] + '`: ' + str(largest['instances']) + ' instances in ' +
        str(largest['bodies']) + ' native bodies. Representative output:', '']
    for rep in largest['representatives']:
        lines.append('* ' + SHORT[rep['application']] + ' ' + rep['symbol'] + ' (resident ' +
                     str(rep['representative_id']) + ', ' + str(rep['instances']) + ' instances):')
        lines.append('')
        lines.append('  ```')
        lines += ['  ' + l[:300] for l in rep['error_context']]
        lines.append('  ```')
    lines += ['', '## Inputs and method', '',
        '* Resident rows and source resources: A\'s prepared 549-instance set (' +
        provenance['resident_rows'] + '); fresh collection over the same coverage archives '
        'reproduces every row field.',
        '* Native P: the payloads of the current-model six-app replay, built with the restored '
        'compiler flags (no external thunks). Selection uses corpus_resident_census.collect on '
        'their manifests. Every manifest selection equals the previous census object+symbol. The '
        'Tetragon manifest selects nothing for 153 residents (bytecode-length mismatch against the '
        'paired source); 152 of them use the previous census object+symbol in the current payload, '
        'and one (credential-commit) has no object in the payload. by_selection in result.json '
        'separates these rows.',
        '* Grouping: SHA256 of the native-link proof ELF (--mode proof --preserve-entry-abi), as in '
        'grouped-static. One representative per body through corpus_resident_groups.shard; the '
        'outcome is weighted by body membership.',
        '* Runtime: af422c391 replay kernel, bpf_kprog_stock module, loader and native-link copies. '
        'Six workers on host CPU pairs 8-9 ... 18-19, one guest vCPU, ' + GUEST_MEMORY + ' guest memory.',
        '* Files: result.json (summary, per-body records), instances.json (549 rows), '
        'outcomes.json.gz (complete representative outcomes with every diagnostic byte), '
        'requests.tar.gz (raw request archives), run-raw.tar.gz (inputs, logs, commands), '
        'provenance.json (hashes and model identity), census.py (controller). Ordered .partNNN files '
        'concatenate to the named stream.', '']
    (RESULTS / 'README.md').write_text('\n'.join(lines))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mode', choices=['prepare', 'run', 'publish'])
    args = parser.parse_args()
    {'prepare': prepare, 'run': run, 'publish': publish}[args.mode]()


if __name__ == '__main__':
    main()
