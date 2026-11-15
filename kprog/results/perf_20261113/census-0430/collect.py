"""Keep a bounded snapshot of new outcomes; original archives stay in place."""
import hashlib
import json
from pathlib import Path

journal = Path('/workspaces/kprog-raw/perf/20261114-census-resume/control/outcomes.jsonl')
data = journal.read_bytes()
rows = [json.loads(line) for line in data.splitlines()]
selected = [row for row in rows if 99 <= row['body_group'] <= 103]
receipts = []
for row in selected:
    submission = row['submission']
    service = submission['service']
    archive = Path(service.get('artifact_archive') or service['failure_archive'])
    with archive.open('rb') as stream:
        archive_sha256 = hashlib.file_digest(stream, 'sha256').hexdigest()
    receipts.append(dict(application=row['application'], body_group=row['body_group'],
        name=row['name'], stage=row['stage'], original_class=row['class'],
        request_id=submission['request_id'], native_id=submission['prog_id'],
        native_object_sha256=submission['native_sha256'],
        execution_mode=service['execution_mode'], started=service['started'], finished=service['finished'],
        diagnostic_tail=row['diagnostic'][-2400:], compiler_failures=row['compiler_failures'],
        archive=str(archive), archive_bytes=archive.stat().st_size, archive_sha256=archive_sha256))
result = dict(journal=str(journal), journal_rows_at_capture=len(rows),
    journal_sha256=hashlib.sha256(data).hexdigest(), new_rows=receipts,
    prior_receipt='../census-late-linker-pairing/report.md',
    scope='Retained producer/worker, submitted-native load only; no execution or current-compiler conclusion')
(Path(__file__).resolve().parent/'receipt.json').write_text(json.dumps(result, indent=2)+'\n')
