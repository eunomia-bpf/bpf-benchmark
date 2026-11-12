"""Selection/resource failures must not inflate submissions or shift archive offsets."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile
import tempfile
import unittest

COLLECTOR = Path(__file__).with_name("collect_resident_census.py")
APP = "tetragon/observer"


class CollectorAccounting(unittest.TestCase):
    def test_failure_rows_keep_completed_offset_separate_from_submissions(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            rows = [dict(application=APP, source_prog_id=index, name=f"p{index}",
                         stage=stage, diagnostic="")
                    for index, stage in enumerate([
                        "installed", "native_selection_failed", "resource_failed", "installed"], 1)]
            payload = root / "service.log"
            payload.write_text("fixture service output\n")
            artifacts = []
            for request, index in enumerate([0, 3], 1):
                artifact = root / f"{request}.success.tar.gz"
                with tarfile.open(artifact, "w:gz") as archive:
                    archive.add(payload, arcname="service.log")
                rows[index]["submission"] = {"service": {"artifact_archive": str(artifact)}}
                artifacts.append(artifact)
            journal = root / "outcomes.jsonl"
            journal.write_text("".join(json.dumps(row) + "\n" for row in rows))
            previous = root / "legacy.json"
            previous.write_text(json.dumps(dict(
                submitted=0, applications={APP: {}}, kernel_commit="fixture", model_commit="fixture")))

            for count, submitted, resource_failed, artifact, offset in [
                    (2, 1, 0, artifacts[0], 0), (4, 2, 1, artifacts[1], 2)]:
                prefix = root / f"prefix-{count}"
                receipt = prefix / "receipt.json"
                output_archive = prefix / "increment.tar.gz"
                subprocess.run([
                    sys.executable, str(COLLECTOR), "--journal", str(journal),
                    "--previous", str(previous), "--count", str(count),
                    "--output", str(prefix / "raw"), "--receipt", str(receipt),
                    "--archive", str(output_archive)], check=True, capture_output=True, text=True)
                result = json.loads(receipt.read_text())
                self.assertEqual(result["completed"], count)
                self.assertEqual(result["submitted"], submitted)
                self.assertEqual(result["verified"], submitted)
                self.assertEqual(result["native_selection_failed"], 1)
                self.assertEqual(result["resource_failed"], resource_failed)
                self.assertEqual(result["previous_completed"], offset)
                self.assertEqual(len(result["new_requests"]), 2)
                app = result["applications"][APP]
                self.assertEqual(app["completed"], count)
                self.assertEqual(app["submitted"], submitted)
                self.assertEqual(app["native_selection_failed"], 1)
                self.assertEqual(app["resource_failed"], resource_failed)
                self.assertEqual(result["archived_requests"], [str(artifact)])
                with tarfile.open(output_archive) as archive:
                    self.assertEqual(archive.getnames(), ["outcomes.jsonl", artifact.name])
                    snapshot = archive.extractfile("outcomes.jsonl").read().decode().splitlines()
                self.assertEqual([json.loads(line) for line in snapshot], rows[:count])
                previous = receipt


if __name__ == "__main__":
    unittest.main()
