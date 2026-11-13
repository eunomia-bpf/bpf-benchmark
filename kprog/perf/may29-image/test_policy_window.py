import importlib.util
from pathlib import Path
import unittest

spec = importlib.util.spec_from_file_location('policy_window', Path(__file__).with_name('policy-window.py'))
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)


class PolicyWindowTests(unittest.TestCase):
    def test_missing_counters_and_resets_are_not_zero_filled_or_discarded(self):
        def snapshot(pid, ns, counters, relation='inside'):
            return dict(pid=pid, snapshot=str(ns), policy_query_rc=0,
                        policy_query_clock=dict(start=dict(monotonic_ns=ns), end=dict(monotonic_ns=ns+1)),
                        policy_query_measurement_matches=[dict(phase='post_rejit', relation=relation)],
                        policies=[dict(name='p', state='TP_STATE_ENABLED', stats=dict(action_counters=counters))])
        report = dict(measurement_intervals=[dict(phase='post_rejit', pid='2')], snapshots=[
            snapshot('2', 20, {'post': '3', 'new': '1'}),
            snapshot('2', 10, {'post': '8', 'old': '2'}),
            snapshot('1', 1, {'post': '999'}),
            snapshot('2', 30, {'post': '999'}, 'overlap')])
        row = module.windows(report)[0]
        self.assertEqual(row['observations'], 2)
        self.assertEqual([s['snapshot'] for s in row['endpoints']], ['10', '20'])
        self.assertEqual(row['policies'][0]['action_counter_deltas'], dict(post=-5, old=None, new=None))
        self.assertEqual(row['policy_states'], dict(TP_STATE_ENABLED=2))


if __name__ == '__main__':
    unittest.main()
