"""A checkpoint must preserve an interrupted journal write and all P/B files."""
import json
from pathlib import Path
import tarfile
import tempfile
from types import SimpleNamespace
import unittest

from resident_verified_census import checkpoint


class CensusCheckpoint(unittest.TestCase):
    def test_partial_last_row_and_empty_queue_keep_raw_state_and_completed_prefix(self):
        with tempfile.TemporaryDirectory() as work:
            root = Path(work)
            queues = [root / "queue-0", root / "queue-1"]
            full = json.dumps(dict(body_group=20, stage="installed")).encode() + b"\n"
            interrupted = b'{"body_group":31,"stage":'
            for index, queue in enumerate(queues):
                state = queue / "control/state/session/requests/request"
                state.mkdir(parents=True)
                (state / "kernel.native.o").write_bytes(b"kernel-owned P bytes")
                (state / "simulator.i").write_bytes(b"unfinished B compilation")
                (queue / "control/outcomes.jsonl").write_bytes(full + interrupted if not index else b"")
            output = root / "checkpoint"
            checkpoint(SimpleNamespace(output=output, queue=queues))
            records = json.loads((output / "checkpoint.json").read_text())
            self.assertEqual([r["completed"] for r in records], [1, 0])
            self.assertEqual(records[0]["incomplete_journal_bytes"], len(interrupted))
            for index, queue in enumerate(queues):
                directory = output / queue.name
                original = (queue / "control/outcomes.jsonl").read_bytes()
                self.assertEqual((directory / "journal.raw.jsonl").read_bytes(), original)
                self.assertEqual((directory / "outcomes.jsonl").read_bytes(), full if not index else b"")
                with tarfile.open(records[index]["state_archive"]) as captured:
                    self.assertEqual(captured.extractfile("state/session/requests/request/kernel.native.o").read(),
                                     b"kernel-owned P bytes")
                    self.assertEqual(captured.extractfile("state/session/requests/request/simulator.i").read(),
                                     b"unfinished B compilation")
                self.assertEqual((queue / "control/state/session/requests/request/simulator.i").read_bytes(),
                                 b"unfinished B compilation")


if __name__ == "__main__":
    unittest.main()
