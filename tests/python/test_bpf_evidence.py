import json
import subprocess
import tempfile
import unittest
from pathlib import Path
from unittest import mock

from runner.libs import bpf_evidence


class BpfEvidenceTests(unittest.TestCase):
    def test_captures_every_program_array_map(self) -> None:
        def json_payload(command: list[str]) -> object:
            if command == ["bpftool", "-j", "prog", "show"]:
                return []
            if command == ["bpftool", "-j", "map", "show"]:
                return [
                    {"id": 7, "name": "cilium_calls", "type": "prog_array"},
                    {"id": 8, "name": "ordinary", "type": "hash"},
                    {"id": 9, "name": "endpoint_calls", "type": "prog_array"},
                ]
            if command == ["bpftool", "-j", "map", "dump", "id", "7"]:
                return [{"key": 0, "value": {"id": 101, "name": "tail_one"}}]
            if command == ["bpftool", "-j", "map", "dump", "id", "9"]:
                return [{"key": 1, "value": {"id": 102, "name": "tail_two"}}]
            if command == ["ip", "-j", "link", "show"]:
                return []
            self.fail(f"unexpected JSON command: {command}")

        with (
            tempfile.TemporaryDirectory() as tmp,
            mock.patch.object(bpf_evidence, "resolve_bpftool_binary", return_value="bpftool"),
            mock.patch.object(bpf_evidence, "_json_payload", side_effect=json_payload),
            mock.patch.object(
                bpf_evidence,
                "_write_capture",
                return_value={"command": [], "returncode": 0},
            ),
            mock.patch.object(
                bpf_evidence,
                "_capture",
                return_value={"command": [], "returncode": 0, "stdout": "", "stderr": ""},
            ),
        ):
            output = bpf_evidence.capture_bpf_evidence(
                output_root=Path(tmp), app_name="cilium/agent", phase="baseline", program_ids=[]
            )

            inventory = json.loads((output / "map-inventory.json").read_text())
            manifest = json.loads((output / "manifest.json").read_text())
            first = json.loads((output / "map-7-cilium_calls.prog-array.json").read_text())
            second = json.loads((output / "map-9-endpoint_calls.prog-array.json").read_text())

        self.assertEqual([record["id"] for record in inventory], [7, 8, 9])
        self.assertEqual(first[0]["value"]["id"], 101)
        self.assertEqual(second[0]["value"]["id"], 102)
        self.assertEqual(set(manifest["program_array_dumps"]), {"7", "9"})

    def test_retries_when_controller_replaces_program_array(self) -> None:
        map_dump_attempts = 0

        def json_payload(command: list[str]) -> object:
            nonlocal map_dump_attempts
            if command == ["bpftool", "-j", "prog", "show"]:
                return []
            if command == ["bpftool", "-j", "map", "show"]:
                return [{"id": 17, "name": "cilium_calls", "type": "prog_array"}]
            if command == ["bpftool", "-j", "map", "dump", "id", "17"]:
                map_dump_attempts += 1
                if map_dump_attempts == 1:
                    raise subprocess.CalledProcessError(255, command)
                return [{"key": 0, "value": {"id": 201, "name": "tail"}}]
            if command == ["ip", "-j", "link", "show"]:
                return []
            self.fail(f"unexpected JSON command: {command}")

        with (
            tempfile.TemporaryDirectory() as tmp,
            mock.patch.object(bpf_evidence, "resolve_bpftool_binary", return_value="bpftool"),
            mock.patch.object(bpf_evidence, "_json_payload", side_effect=json_payload),
            mock.patch.object(bpf_evidence.time, "sleep"),
            mock.patch.object(
                bpf_evidence,
                "_write_capture",
                return_value={"command": [], "returncode": 0},
            ),
            mock.patch.object(
                bpf_evidence,
                "_capture",
                return_value={"command": [], "returncode": 0, "stdout": "", "stderr": ""},
            ),
        ):
            output = bpf_evidence.capture_bpf_evidence(
                output_root=Path(tmp), app_name="cilium/agent", phase="post_rejit", program_ids=[]
            )

            payload = json.loads(
                (output / "map-17-cilium_calls.prog-array.json").read_text()
            )

        self.assertEqual(map_dump_attempts, 3)
        self.assertEqual(payload[0]["value"]["id"], 201)


if __name__ == "__main__":
    unittest.main()
