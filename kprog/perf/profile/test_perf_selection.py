"""Regression: --perf must reach the IP symbolizer as well as perf report."""
import importlib.util
import pathlib
import subprocess
import unittest
from unittest.mock import patch

import symbolize


class PerfSelection(unittest.TestCase):
    def test_report_symbolizer_uses_selected_tool(self):
        spec = importlib.util.spec_from_file_location(
            "phase_profile", pathlib.Path(__file__).with_name("phase-profile.py"))
        profile = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(profile)
        profile.PERF = pathlib.Path("/selected/perf")
        completed = subprocess.CompletedProcess([], 0, stdout="ffffffff81000000\n")
        with patch.object(symbolize.subprocess, "run", return_value=completed) as run, \
                patch.object(symbolize, "load_kallsyms", return_value=(
                    [0xffffffff81000000], ["bpf_prog_0123456789abcdef_entry"], [""])):
            counts = profile._symbols(pathlib.Path("/recording"), "baseline")
        self.assertEqual(counts["bpf_prog_0123456789abcdef_entry"], 100)
        self.assertEqual(run.call_args.args[0][0], "/selected/perf")

    def test_standalone_symbolizer_retains_default(self):
        completed = subprocess.CompletedProcess([], 0, stdout="ffffffff81000000\n")
        with patch.object(symbolize.subprocess, "run", return_value=completed) as run:
            self.assertEqual(symbolize.samples(pathlib.Path("recording.data")),
                             [0xffffffff81000000])
        self.assertEqual(run.call_args.args[0][0], str(symbolize.PERF))


if __name__ == "__main__":
    unittest.main()
