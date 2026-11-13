"""Regressions for oversized guest exec commands and lost workload exit status."""
import importlib.util
import json
import os
from pathlib import Path
import shlex
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

SCRIPT = Path(__file__).with_name('eqcodex-capture.py')
SPEC = importlib.util.spec_from_file_location('capture', SCRIPT)
CAPTURE = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(CAPTURE)


class GuestControl(unittest.TestCase):
    def test_long_command_stays_in_plan_and_guest_argv_stays_short(self):
        with tempfile.TemporaryDirectory() as directory:
            command = shlex.join(['python3', '-c', 'print("exact output")', 'x' * 5000])
            argv = ['vng', '--run', '/kernel', '--exec', command]
            environment = {'EQCODEX_OUT': directory, 'EQCODEX_TETRA': '/a client/tetra',
                           'EQCODEX_NATIVE_LINK_BINARY': '/a linker/native-link'}
            with patch.object(sys, 'argv', argv), patch.dict(os.environ, environment, clear=True), patch.object(CAPTURE.os, 'execv') as execute:
                CAPTURE.main()
            actual = execute.call_args.args[1]
            wire_command = actual[actual.index('--exec') + 1]
            self.assertLess(len(wire_command), 500)
            plan = json.loads((Path(directory) / 'guest-plan.json').read_text())
            self.assertEqual(shlex.split(plan['command']),
                             ['env', 'BPFREJIT_NATIVE_LINK_BINARY=/a linker/native-link',
                              'python3', '-c', 'print("exact output")', 'x' * 5000])
            self.assertEqual(plan['observer'][-2:], ['--tetra', '/a client/tetra'])
            self.assertEqual(actual[:4], ['vng', '--run', '/kernel', '--exec'])

    def test_guest_returns_workload_failure_and_reaps_its_observer(self):
        with tempfile.TemporaryDirectory() as directory:
            out = Path(directory)
            plan = {'command': shlex.join([sys.executable, '-c', 'print("saved output"); raise SystemExit(7)']),
                    'observer': [sys.executable, '-c', 'import time; time.sleep(60)']}
            (out / 'guest-plan.json').write_text(json.dumps(plan))
            result = subprocess.run([sys.executable, SCRIPT, '--guest', directory],
                                    capture_output=True, text=True, timeout=10)
            self.assertEqual(result.returncode, 7)
            self.assertEqual(result.stdout, 'saved output\n')
            self.assertEqual((out / 'guest.log').read_text(), 'saved output\n')
            self.assertEqual((out / 'observer-exit-code').read_text(), '-15\n')


if __name__ == '__main__':
    unittest.main()
