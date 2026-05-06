from __future__ import annotations

import unittest
from pathlib import Path
from unittest import mock

from runner.libs.app_runners import bcc_set
from runner.libs.app_runners.bcc import ToolProcessSession, _TailCapture
from runner.libs.app_runners.bcc_set import BCC_SET_TOOL_SPECS, BCC_SET_WORKLOAD, BccSetRunner


class _FakeProcess:
    def __init__(self, *, pid: int = 4242, returncode: int | None = None) -> None:
        self.pid = pid
        self.returncode = returncode

    def poll(self) -> int | None:
        return self.returncode


class BccSetReadinessTests(unittest.TestCase):
    def _runner(self, *, attach_timeout_s: int) -> BccSetRunner:
        return BccSetRunner(
            tool_binaries={spec.name: Path("/bin/true") for spec in BCC_SET_TOOL_SPECS},
            workload_spec={"kind": BCC_SET_WORKLOAD},
            attach_timeout_s=attach_timeout_s,
        )

    def _attach_fake_process(self, runner: BccSetRunner, tool_name: str = "capable") -> None:
        child = runner._children[tool_name]
        child.command_used = [tool_name]
        child.session = ToolProcessSession(
            process=_FakeProcess(),
            stdout_capture=_TailCapture(max_lines=4, max_chars=200),
            stderr_capture=_TailCapture(max_lines=4, max_chars=200),
            stdout_thread=object(),
            stderr_thread=object(),
        )

    def test_live_child_without_fdinfo_programs_times_out(self) -> None:
        runner = self._runner(attach_timeout_s=0)
        self._attach_fake_process(runner)

        with mock.patch.object(bcc_set, "_program_ids_from_fdinfo", return_value=[]):
            with self.assertRaisesRegex(RuntimeError, "timed out"):
                runner._wait_for_all_tool_program_ids(["capable"])

        record = runner.artifacts["result_details"]["bcc_set"]["tool_startup"][0]
        self.assertEqual(record["tool"], "capable")
        self.assertEqual(record["status"], "timeout")
        self.assertEqual(record["prog_ids"], [])
        self.assertIn("did not expose any BPF program IDs", record["error"])

    def test_attached_status_requires_non_empty_new_fdinfo_programs(self) -> None:
        runner = self._runner(attach_timeout_s=1)
        runner._before_ids = {7}
        self._attach_fake_process(runner)

        with mock.patch.object(bcc_set, "_program_ids_from_fdinfo", return_value=[7, 42]):
            attached = runner._wait_for_all_tool_program_ids(["capable"])

        self.assertEqual(attached, {"capable": [42]})
        record = runner.artifacts["result_details"]["bcc_set"]["tool_startup"][0]
        self.assertEqual(record["status"], "attached")
        self.assertEqual(record["prog_ids"], [42])


if __name__ == "__main__":
    unittest.main()
