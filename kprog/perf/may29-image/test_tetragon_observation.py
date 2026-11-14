"""Catch progress-label joins across restarts and lost measurement boundaries."""
import importlib.util
from pathlib import Path
import tempfile
import unittest

SPEC = importlib.util.spec_from_file_location('obs', Path(__file__).with_name('tetragon-observation.py'))
OBS = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(OBS)


class MeasurementClocks(unittest.TestCase):
    def test_selected_app_log_is_not_replaced_by_tetragon_log(self):
        with tempfile.TemporaryDirectory() as directory:
            run = Path(directory)
            logs = run / 'details/shim-logs'
            logs.mkdir(parents=True)
            for phase in ['baseline', 'post_rejit']:
                (logs / ('otelcol-ebpf-profiler__profiling.' + phase + '.log')).write_text(
                    '[20.0 pid=17 tid=18] socket: cmd=measure_start len=25\n'
                    '[30.0 pid=17 tid=18] socket: cmd=measure_finish len=26\n')
            rows = OBS.measurement_intervals(run, 'otelcol-ebpf-profiler__profiling')
        self.assertEqual([row['phase'] for row in rows], ['baseline', 'post_rejit'])
        self.assertEqual([row['pid'] for row in rows], ['17', '17'])

    def test_pid_and_read_bounds_determine_phase_not_snapshot_label(self):
        with tempfile.TemporaryDirectory() as directory:
            run = Path(directory)
            logs = run / 'details/shim-logs'
            logs.mkdir(parents=True)
            (logs / 'tetragon__observer.baseline.log').write_text(
                '[20.0 pid=7 tid=8] socket: cmd=measure_start len=25\n'
                '[30.0 pid=7 tid=8] socket: cmd=measure_finish len=26\n')
            (logs / 'tetragon__observer.post_rejit.log').write_text(
                '[40.0 pid=9 tid=10] socket: cmd=measure_start len=25\n'
                '[50.0 pid=9 tid=10] socket: cmd=measure_finish len=26\n'
                '[60.0 pid=11 tid=12] socket: cmd=measure_start len=25\n')
            intervals = OBS.measurement_intervals(run)
        timing = lambda first, last: {'start': {'monotonic_ns': first * 1000000000},
                                      'end': {'monotonic_ns': last * 1000000000}}
        self.assertEqual(OBS.clock_matches(intervals, '9', timing(42, 43)),
                         [{'phase': 'post_rejit', 'relation': 'inside'}])
        self.assertEqual(OBS.clock_matches(intervals, '7', timing(29, 31)),
                         [{'phase': 'baseline', 'relation': 'overlap'}])
        self.assertEqual(OBS.clock_matches(intervals, '7', timing(42, 43)), [])
        self.assertEqual(OBS.clock_matches(intervals, '11', timing(62, 63)), [])
        self.assertEqual(intervals[-1], {'phase': 'post_rejit', 'pid': '11', 'start_seconds': 60.0})


if __name__ == '__main__':
    unittest.main()
