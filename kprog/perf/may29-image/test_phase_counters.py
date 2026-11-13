"""Catch the moved source path and explicit enum values becoming metric names."""
import importlib.util
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

SPEC = importlib.util.spec_from_file_location('phase', Path(__file__).with_name('phase-counters.py'))
PHASE = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(PHASE)


class MetricIds(unittest.TestCase):
    def test_repository_enum_is_read_without_a_temporary_mapping(self):
        with tempfile.TemporaryDirectory() as directory:
            with patch.object(PHASE, 'METRIC_IDS', Path(directory) / 'absent.json', create=True):
                ids = PHASE.load_ids()
        self.assertEqual(ids['0'], 'metricID_UnwindCallInterpreter')
        self.assertEqual(ids['1'], 'metricID_UnwindErrZeroPC')
        self.assertIn('metricID_UnwindNativeAttempts', ids.values())

    def test_explicit_enum_values_and_gaps_keep_the_numeric_key(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / 'types.h'
            path.write_text('''enum {
metricID_First = 0,
metricID_Second,
metricID_Gap = 0x10, // assigned ID
metricID_AfterGap,
};
''')
            ids = PHASE.load_ids(path)
        self.assertEqual(ids, {'0': 'metricID_First', '1': 'metricID_Second',
                               '16': 'metricID_Gap', '17': 'metricID_AfterGap'})


if __name__ == '__main__':
    unittest.main()
