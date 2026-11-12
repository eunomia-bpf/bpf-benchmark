#!/usr/bin/env python3
"""Archive a completed journal prefix without changing the running census."""
import argparse
from collections import Counter
from datetime import datetime, timezone
import json
from pathlib import Path
import shutil
import sys
import tarfile

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from corpus_resident_verifier import failure_class


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--journal", type=Path, required=True)
    parser.add_argument("--previous", type=Path, required=True)
    parser.add_argument("--count", type=int, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--receipt", type=Path, required=True)
    parser.add_argument("--archive", type=Path, required=True)
    args = parser.parse_args()
    previous = json.loads(args.previous.read_text())
    # Old receipts predate selection/resource failures and counted every row
    # as submitted. Keep their completed offset when extending that format.
    previous_completed = previous.get("completed", previous["submitted"])
    lines = args.journal.read_text().splitlines(keepends=True)[:args.count]
    rows = [json.loads(line) for line in lines]
    args.output.mkdir(parents=True, exist_ok=True)
    snapshot = args.output / "outcomes.jsonl"
    snapshot.write_text("".join(lines))
    stages = Counter(row["stage"] for row in rows)
    applications = {}
    for application in previous["applications"]:
        selected = [row for row in rows if row["application"] == application]
        counts = Counter(row["stage"] for row in selected)
        applications[application] = dict(
            completed=len(selected), submitted=sum("submission" in row for row in selected),
            native_selection_failed=counts["native_selection_failed"],
            resource_failed=counts["resource_failed"], verified=counts["installed"],
            verifier_rejected=counts["verifier_rejected"],
            compilation_failed=counts["compilation_failed"], workload_run=None)
    added = rows[previous_completed:]
    services = [row["submission"]["service"] for row in added
                if "service" in row.get("submission", {})]
    artifacts = [Path(service["artifact_archive"] if "artifact_archive" in service
                      else service["failure_archive"]) for service in services]
    raw_archive = args.output / args.archive.name
    with tarfile.open(raw_archive, "w:gz") as archive:
        archive.add(snapshot, arcname="outcomes.jsonl")
        for artifact in artifacts:
            archive.add(artifact, arcname=artifact.name)
    shutil.copy2(raw_archive, args.archive)
    receipt = dict(
        recorded_at=datetime.now(timezone.utc).isoformat(),
        scope="Completed prefix of ongoing 549-instance load-only census",
        raw_directory=str(args.output), journal=str(args.journal),
        kernel_commit=previous["kernel_commit"], model_commit=previous["model_commit"],
        completed=len(rows), submitted=sum("submission" in row for row in rows),
        native_selection_failed=stages["native_selection_failed"],
        resource_failed=stages["resource_failed"],
        stock_verifier_submissions=stages["installed"] + stages["verifier_rejected"],
        verified=stages["installed"], verifier_rejected=stages["verifier_rejected"],
        compilation_failed=stages["compilation_failed"], native_execution_requests=0,
        applications=applications, classes=dict(Counter(failure_class(row) for row in rows)),
        new_requests=[dict(application=row["application"], name=row["name"],
                           retained_source_prog_id=row["source_prog_id"], stage=row["stage"],
                           classified_class=failure_class(row), diagnostic=row["diagnostic"],
                           service={key: value for key, value in
                                    row.get("submission", {}).get("service", {}).items()
                                    if key in ("request_id", "started", "finished", "status",
                                               "prog_id", "artifact_archive", "failure_archive")})
                      for row in added],
        archive=args.archive.name, archive_bytes=args.archive.stat().st_size,
        previous_receipt=str(args.previous), previous_submitted=previous["submitted"],
        previous_completed=previous_completed,
        archived_requests=[str(path) for path in artifacts])
    content = json.dumps(receipt, indent=2) + "\n"
    (args.output / "receipt.json").write_text(content)
    args.receipt.write_text(content)
    print(json.dumps(dict(completed=len(rows), submitted=receipt["submitted"], stages=dict(stages),
                          archive=str(args.archive), archive_bytes=receipt["archive_bytes"])))


if __name__ == "__main__":
    main()
