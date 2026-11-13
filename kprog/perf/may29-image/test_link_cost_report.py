"""Catch clock-unit mistakes, ambiguous load joins and overlapping-child sums."""
import importlib.util
from pathlib import Path
import unittest

SPEC = importlib.util.spec_from_file_location('cost', Path(__file__).with_name('link-cost-report.py'))
COST = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(COST)


class LinkCostReport(unittest.TestCase):
    def test_pid_clock_join_keeps_ambiguity_and_uses_interval_union(self):
        load = dict(pid=7, start_seconds=1, end_seconds=3, elapsed_seconds=2)
        child = dict(command=['linker', '--output', '/tmp/key.tmp.7.proof.o'],
                     start_monotonic_ns=1500000000, end_monotonic_ns=2500000000)
        overlap = dict(child, start_monotonic_ns=2000000000, end_monotonic_ns=2750000000)
        result = COST.join([child, overlap], [load, dict(load, pid=8)])
        row = result['loads'][0]
        self.assertEqual(len(row['children']), 2)
        self.assertEqual(row['child_wall_union_seconds'], 1.25)
        self.assertEqual(row['outside_recorded_children_seconds'], 0.75)
        self.assertEqual(result['unmatched_children'], [])
        ambiguous = COST.join([child], [load, dict(load)])
        self.assertEqual(ambiguous['unmatched_children'][0]['candidate_load_indices'], [0, 1])
        self.assertTrue(all(not row['children'] for row in ambiguous['loads']))
        absent = COST.join([dict(child, start_monotonic_ns=4000000000,
                                 end_monotonic_ns=5000000000)], [load])
        self.assertEqual(absent['unmatched_children'][0]['candidate_load_indices'], [])


if __name__ == '__main__':
    unittest.main()
