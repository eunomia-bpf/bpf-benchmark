"""Publish every completed checkpoint row and its full retained request bytes."""
import argparse
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import shutil

APPS = ['bcc/set', 'katran', 'cilium/agent', 'otelcol-ebpf-profiler/profiling',
        'tetragon/observer', 'tracee/monitor']


def digest(path):
    value = hashlib.sha256()
    with path.open('rb') as source:
        while block := source.read(1024 * 1024):
            value.update(block)
    return value.hexdigest()


def publish(base, queues, output, published):
    output.mkdir(parents=True)
    published.mkdir(parents=True)
    base_rows = [json.loads(line) for line in base.read_text().splitlines()]
    rows = list(base_rows)
    new = []
    for journal in queues:
        current = [json.loads(line) for line in journal.read_text().splitlines()]
        new.extend(current)
        rows.extend(current)
    (output/'outcomes.jsonl').write_text(''.join(json.dumps(row)+'\n' for row in rows))
    latest = {}
    for row in sorted(rows, key=lambda row: row['submission']['service']['finished']):
        latest[row['application'], row['body_group']] = row
    # Reuse previously published BYTE-IDENTICAL evidence, not another attempt
    # with the same body number. Every new journal row remains in the receipt.
    candidates = {}
    for path in published.parent.glob('*.tar.gz'):
        candidates.setdefault(path.stat().st_size, []).append(path)
    hashes = {}
    packaged = {}
    archives = []
    for row in new:
        service = row['submission']['service']
        source = Path(service['artifact_archive'] if row['stage']=='installed' else service['failure_archive'])
        size, sha = source.stat().st_size, digest(source)
        reused = None
        for candidate in candidates.get(size, []):
            if candidate not in hashes:
                hashes[candidate] = digest(candidate)
            if hashes[candidate] == sha:
                reused = candidate
                break
        record = dict(application=row['application'], body_group=row['body_group'],
                      stage=row['stage'], raw_archive=str(source), bytes=size, sha256=sha)
        if reused is not None:
            record['published_archive'] = str(reused)
        elif sha in packaged:
            record.update(packaged[sha])
        else:
            parts = []
            with source.open('rb') as stream:
                # This is the operator's GitHub file-size packaging constraint,
                # not a program, proof, or benchmark admission limit.
                while block := stream.read(40 * 1024 * 1024):
                    part = published/f'body-{row["body_group"]}-{sha[:12]}.tar.gz.part{len(parts):03d}'
                    with part.open('xb') as destination:
                        destination.write(block)
                    parts.append(dict(path=str(part), bytes=len(block), sha256=hashlib.sha256(block).hexdigest()))
            record.update(parts=parts, reconstruction='Concatenate listed parts; original SHA256 above.')
            packaged[sha] = dict(parts=parts, reconstruction=record['reconstruction'])
        archives.append(record)
    applications = {}
    for app in APPS:
        selected = [row for row in latest.values() if row['application']==app]
        stages = Counter(row['stage'] for row in selected)
        applications[app] = dict(distinct_bodies=len(selected), latest_stages=dict(stages), native_run=0)
    result = dict(recorded=datetime.now(timezone.utc).isoformat(),
        scope='Completed resident load-only replay; not whole-application startup or workload certification',
        base_journal=str(base), queue_journals=[str(path) for path in queues],
        attempts=len(rows), attempt_stages=dict(Counter(row['stage'] for row in rows)),
        distinct_bodies=len(latest), latest_stages=dict(Counter(row['stage'] for row in latest.values())),
        latest_failure_classes=dict(Counter(row['class'] for row in latest.values() if row['stage']!='installed')),
        per_application=applications, native_run=0, new_request_archives=archives,
        raw_directory=str(output), raw_removed=False)
    (output/'receipt.json').write_text(json.dumps(result, indent=2)+'\n')
    shutil.copy2(output/'outcomes.jsonl', published/'outcomes.jsonl')
    shutil.copy2(output/'receipt.json', published/'receipt.json')
    print(json.dumps({key: result[key] for key in ['attempts','attempt_stages','distinct_bodies','latest_stages','latest_failure_classes']}))
    return result


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--base',type=Path,required=True)
    parser.add_argument('--queue',type=Path,action='append',required=True)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--published',type=Path,required=True)
    args=parser.parse_args()
    publish(args.base,args.queue,args.output,args.published)
