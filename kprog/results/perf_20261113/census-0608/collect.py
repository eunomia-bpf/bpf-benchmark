"""Retain the new terminal row and its actual compiler epoch."""
import hashlib
import json
from pathlib import Path
import tarfile

out = Path(__file__).resolve().parent
journal = Path('/workspaces/kprog-raw/perf/20261114-census-resume/control/outcomes.jsonl')
data = journal.read_bytes()
rows = [json.loads(line) for line in data.splitlines()]
row = next(row for row in rows if row['body_group'] == 104)
submission = row['submission']
service = submission['service']
archive = Path(service.get('artifact_archive') or service['failure_archive'])
with archive.open('rb') as stream:
    digest = hashlib.file_digest(stream, 'sha256').hexdigest()
with tarfile.open(archive, 'r|gz') as stream:
    for member in stream:
        if member.name == 'request/generated/commands.jsonl':
            commands = stream.extractfile(member).read()
            break
    else:
        raise ValueError('Terminal archive lacks actual compiler commands')
(out/'commands.jsonl').write_bytes(commands)
receipt = dict(journal=str(journal), journal_rows_at_capture=len(rows),
    journal_sha256=hashlib.sha256(data).hexdigest(), body_group=row['body_group'],
    application=row['application'], name=row['name'], stage=row['stage'], original_class=row['class'],
    request_id=submission['request_id'], native_id=submission['prog_id'], native_sha256=submission['native_sha256'],
    execution_mode=service['execution_mode'], started=service['started'], finished=service['finished'],
    diagnostic_tail=row['diagnostic'][-2400:], compiler_failures=row['compiler_failures'],
    archive=str(archive), archive_bytes=archive.stat().st_size, archive_sha256=digest,
    scope='Retained producer/worker; direct joined-C compilation, stock rejection, no current normal MIR or execution conclusion')
(out/'receipt.json').write_text(json.dumps(receipt, indent=2)+'\n')
