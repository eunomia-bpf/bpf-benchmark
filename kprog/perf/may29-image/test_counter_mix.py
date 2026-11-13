"""Catch wrong unwinder denominators and zero-attempt claims in counter analysis."""
import importlib.util
from pathlib import Path
import unittest

SPEC = importlib.util.spec_from_file_location('mix', Path(__file__).with_name('counter-mix.py'))
MIX = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MIX)


class CounterMix(unittest.TestCase):
    def test_family_yield_uses_own_attempts_and_zero_attempts_stay_null(self):
        metrics = {'metricID_UnwindCallInterpreter': 6}
        for family in MIX.FAMILIES:
            metrics['metricID_Unwind' + family + 'Attempts'] = 0
            metrics['metricID_Unwind' + family + 'Frames'] = 0
        metrics.update(metricID_UnwindNativeAttempts=20, metricID_UnwindNativeFrames=10,
                       metricID_UnwindRubyAttempts=4, metricID_UnwindRubyFrames=6,
                       metricID_UnwindRubyErrReadCfp=1)
        window = dict(first='a', last='b', map_id=29, start_time='start', end_time='end',
                      seconds=2, metric_deltas=metrics)
        result = MIX.summarize(window)
        ruby = result['families']['Ruby']
        self.assertEqual(ruby['frames_per_attempt'], 1.5)
        self.assertEqual(ruby['attempts_per_native_attempt'], 0.2)
        self.assertEqual(ruby['other_counters']['metricID_UnwindRubyErrReadCfp']['per_attempt'], 0.25)
        self.assertIsNone(result['families']['Python']['frames_per_attempt'])
        self.assertEqual(result['interpreter_dispatches_per_native_attempt'], 0.3)
        self.assertEqual(result['native_attempts_per_second'], 10)
        metrics['metricID_UnwindNativeAttempts'] = 0
        self.assertIsNone(MIX.summarize(window)['families']['Ruby']['attempts_per_native_attempt'])


if __name__ == '__main__':
    unittest.main()
