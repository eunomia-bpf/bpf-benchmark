"""Catch cross-thread load pairing and dropped failed/unfinished requests."""
import importlib.util
from pathlib import Path
import tempfile
import unittest

SPEC = importlib.util.spec_from_file_location('loads', Path(__file__).with_name('load-timeline.py'))
LOADS = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(LOADS)


class LoadTimeline(unittest.TestCase):
    def test_interleaved_threads_failures_and_unfinished_loads(self):
        log = '''[1.0 pid=12 tid=13] BPF_PROG_LOAD type=2 (kprobe) name=foo insn_cnt=20
[1.1 pid=12 tid=14] BPF_PROG_LOAD type=2 (kprobe) name=bar insn_cnt=30
[1.2 pid=12 tid=14] native-loader replaced prog=bar original_fd=2 native_fd=3
[1.5 pid=12 tid=14]   PROG_LOAD -> fd=3 errno=0 kernel_prog_id=9
[2.0 pid=12 tid=13]   PROG_LOAD -> fd=-1 errno=13 kernel_prog_id=0
[2.1 pid=12 tid=13] BPF_PROG_LOAD type=1 (socket_filter) name= insn_cnt=2
'''
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / 'shim.log'
            path.write_text(log)
            result = LOADS.timeline(path)
        bar, foo = result['completed']
        self.assertEqual((bar['name'], bar['id'], bar['native']), ('bar', 9, True))
        self.assertAlmostEqual(bar['elapsed_seconds'], 0.4)
        self.assertEqual((foo['name'], foo['errno'], foo['native']), ('foo', 13, False))
        self.assertEqual(foo['elapsed_seconds'], 1.0)
        self.assertEqual(len(result['unmatched']), 1)
        self.assertEqual(result['unmatched'][0]['name'], '')


if __name__ == '__main__':
    unittest.main()
