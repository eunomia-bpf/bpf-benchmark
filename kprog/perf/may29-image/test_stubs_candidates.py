import json
from pathlib import Path
import subprocess
import tempfile
import unittest


class TinyCandidateTests(unittest.TestCase):
    def test_size_does_not_label_empty_source_a_fallback_or_count_idle_as_work(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            apps = root / 'details/apps'
            apps.mkdir(parents=True)
            programs = {str(n): dict(name=name, bytes_jited=20, bytes_xlated=16,
                                     run_cnt_delta=runs, run_time_ns_delta=runs*100)
                        for n, (name, runs) in enumerate([('empty_kprobe', 2), ('idle_tiny', 0)])}
            (apps/'tracee.json').write_text(json.dumps(dict(baseline=dict(bpf=programs))))
            result = subprocess.run(['python3', str(Path(__file__).with_name('stubs.py')), str(root)],
                                    check=True, capture_output=True, text=True)
            self.assertIn('2 tiny-program candidates, 1 of them carried work', result.stdout)
            self.assertIn('empty_kprobe', result.stdout)
            self.assertIn('idle_tiny', result.stdout)
            self.assertIn('size alone does not establish a fallback', result.stdout)
            self.assertNotIn('distort the run', result.stdout)


if __name__ == '__main__':
    unittest.main()
