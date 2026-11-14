"""Keep startup failures observable without inventing a native arm."""
import importlib.util
import tarfile
from pathlib import Path
import tempfile
import unittest

spec = importlib.util.spec_from_file_location('prepare', Path(__file__).with_name('cilium-live-prepare.py'))
prepare = importlib.util.module_from_spec(spec)
spec.loader.exec_module(prepare)


class ReplacementObservationTests(unittest.TestCase):
    def test_failed_snapshot_keeps_raw_error_without_inventing_an_index(self):
        with tempfile.TemporaryDirectory() as directory:
            path=Path(directory)/'cilium-config.tar.gz'
            with tarfile.open(path,'w:gz'):
                pass
            path.with_suffix('.gz.rc').write_text('1\n')
            path.with_suffix('.gz.stderr').write_text('temporary cache file disappeared\n')
            record=prepare.snapshot_record(path)
            self.assertEqual(record['capture_exit'],1)
            self.assertIsNone(record['index'])
            self.assertEqual(record['capture_stderr'],'temporary cache file disappeared\n')
            self.assertEqual(record['bytes'],path.stat().st_size)
            path.with_suffix('.gz.rc').write_text('0\n')
            with self.assertRaises(KeyError):
                prepare.snapshot_record(path)

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
