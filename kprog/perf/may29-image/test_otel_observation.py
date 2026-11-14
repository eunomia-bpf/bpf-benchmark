"""Catch counter-generation joins to another map thread or failed creation."""
import importlib.util
from pathlib import Path
import tempfile
import unittest

SPEC = importlib.util.spec_from_file_location('otel_obs', Path(__file__).with_name('otel-observation.py'))
OBS = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(OBS)


class MapGenerations(unittest.TestCase):
    def generations(self, text):
        with tempfile.TemporaryDirectory() as directory:
            run = Path(directory)
            logs = run / 'details/shim-logs'
            logs.mkdir(parents=True)
            (logs / 'otelcol-ebpf-profiler__profiling.baseline.log').write_text(text)
            (logs / 'otelcol-ebpf-profiler__profiling.post_rejit.log').write_text('')
            return OBS.map_generations(run)

    def test_interleaved_threads_and_failed_creates_retain_actual_identity(self):
        rows = self.generations(
            '[1.0 pid=7 tid=8] BPF_MAP_CREATE type=6 name=metrics\n'
            '[1.1 pid=7 tid=9] BPF_MAP_CREATE type=6 name=other\n'
            '[1.2 pid=7 tid=8]   MAP_CREATE -> fd=10 errno=0 kernel_map_id=41\n'
            '[1.3 pid=7 tid=9]   MAP_CREATE -> fd=11 errno=0 kernel_map_id=42\n'
            '[1.4 pid=7 tid=8] BPF_MAP_CREATE type=6 name=metrics\n'
            '[1.5 pid=7 tid=8]   MAP_CREATE -> fd=-1 errno=12 kernel_map_id=0\n')
        self.assertEqual([(r['map_id'], r['errno'], r['pid'], r['tid']) for r in rows],
                         [(41, 0, '7', '8'), (0, 12, '7', '8')])

    def test_missing_metrics_map_identity_is_not_invented(self):
        with self.assertRaisesRegex(ValueError, 'kernel identity'):
            self.generations(
                '[1.0 pid=7 tid=8] BPF_MAP_CREATE type=6 name=metrics\n'
                '[1.2 pid=7 tid=8]   MAP_CREATE -> fd=10 errno=0\n')


if __name__ == '__main__':
    unittest.main()
