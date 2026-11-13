"""Keep startup failures observable without inventing a native arm."""
import importlib.util
from pathlib import Path
import tempfile
import unittest

spec = importlib.util.spec_from_file_location('prepare', Path(__file__).with_name('cilium-live-prepare.py'))
prepare = importlib.util.module_from_spec(spec)
spec.loader.exec_module(prepare)


class ReplacementObservationTests(unittest.TestCase):
    def test_missing_native_phase_is_unknown_but_retry_events_remain_counted(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / 'post.log'
            self.assertIsNone(prepare.replacements({'post_rejit': None}, path))
            path.write_text('native-loader replaced prog=a\nerror\nnative-loader replaced prog=a\n')
            self.assertEqual(prepare.replacements({'post_rejit': None}, path), 2)

    def test_completed_native_phase_requires_its_log(self):
        with tempfile.TemporaryDirectory() as directory:
            with self.assertRaises(FileNotFoundError):
                prepare.replacements({'post_rejit': {}}, Path(directory) / 'missing.log')


if __name__ == '__main__':
    unittest.main()
