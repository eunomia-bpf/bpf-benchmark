"""Catch changed linker arguments, output, or failed-command exit status."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest


class LinkCost(unittest.TestCase):
    def test_real_child_arguments_output_and_failure_are_preserved(self):
        with tempfile.TemporaryDirectory() as directory:
            out = Path(directory)
            script = out / 'native-link'
            shutil.copyfile(Path(__file__).with_name('link-cost.py'), script)
            (out / 'config.json').write_text(json.dumps({'linker': sys.executable}))
            argv = ['-c', 'import sys; print(repr(sys.argv[1:])); raise SystemExit(7)',
                    'a path with spaces', '--mode', 'proof']
            child = subprocess.run([sys.executable, script, *argv], capture_output=True, text=True)
            self.assertEqual(child.returncode, 7)
            self.assertEqual(child.stdout, "['a path with spaces', '--mode', 'proof']\n")
            records = list(out.glob('invocation-*.json'))
            self.assertEqual(len(records), 1)
            record = json.loads(records[0].read_text())
            self.assertEqual(record['command'], [sys.executable, *argv])
            self.assertEqual(record['returncode'], 7)
            self.assertGreater(record['elapsed_seconds'], 0)
            self.assertGreater(record['child_usage']['user_seconds'], 0)


if __name__ == '__main__':
    unittest.main()
