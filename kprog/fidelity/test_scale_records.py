"""Resource sidecars must not abort the scale verifier queue before its cases."""
import json
from pathlib import Path
import tempfile
import unittest
import sys

import scale
import scale_probe_status


class ScaleRecords(unittest.TestCase):
    def test_resource_sidecars_do_not_replace_failed_case_outcomes(self):
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            rows = [dict(name='n100_scalar_direct', stage='proof_compile', returncode=-9),
                    dict(name='n1000_ptr_indirect', stage='proof_compile', returncode=1)]
            for row in rows:
                (directory/(row['name']+'.json')).write_text(json.dumps(row))
                (directory/(row['name']+'.compile.log.resources.json')).write_text(
                    json.dumps(dict(returncode=row['returncode'], wall_seconds=1)))
            output = directory/'out'
            self.assertEqual(scale.check(directory, output), 1)
            self.assertEqual(sorted(p.name for p in output.glob('*.json')),
                             sorted(row['name']+'.json' for row in rows))
            for row in rows:
                self.assertEqual(json.loads((output/(row['name']+'.json')).read_text()), row)

    def test_malformed_actual_case_still_raises(self):
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            (directory/'n100_scalar_direct.json').write_text('{"returncode": 1}')
            with self.assertRaises(KeyError):
                scale.check(directory, directory/'out')

    def test_loader_failure_status_survives_a_successful_recorder(self):
        with tempfile.TemporaryDirectory() as temporary:
            status = Path(temporary)/'probe-status'
            # A recorder may ignore this return code. The actual child result
            # must remain independently observable, including successful runs.
            for expected in (7, 0):
                self.assertEqual(scale_probe_status.run(status, [
                    sys.executable, '-c', f'import sys; sys.exit({expected})']), expected)
                self.assertEqual(int(status.read_text()), expected)


if __name__ == '__main__':
    unittest.main()
