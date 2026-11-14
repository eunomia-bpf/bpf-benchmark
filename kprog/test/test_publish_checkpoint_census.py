"""Catch retry double counting, cross-app body collisions and wrong evidence reuse."""
import contextlib
import io
import json
from pathlib import Path
import tempfile
import unittest

from publish_checkpoint_census import publish


class CensusPublication(unittest.TestCase):
    def test_retry_identity_and_full_archive_reconstruction(self):
        with tempfile.TemporaryDirectory(prefix='census-publication-') as temporary:
            root = Path(temporary)
            evidence = root/'published'
            evidence.mkdir()
            old = evidence/'previous.tar.gz'
            old.write_bytes(b'old request')
            # Equal size and body number do not imply equal request bytes.
            current = root/'current.tar.gz'
            current.write_bytes(b'new request')

            def row(app, finished, stage, archive):
                service = dict(finished=finished)
                service['artifact_archive' if stage=='installed' else 'failure_archive'] = str(archive)
                return dict(application=app, body_group=7, stage=stage,
                            **{'class':'verifier_map_bounds'}, submission=dict(service=service))

            base = root/'base.jsonl'
            base.write_text(json.dumps(row('bcc/set', '2026-11-14T02:00:00Z', 'installed', current))+'\n')
            queue = root/'queue.jsonl'
            # An older retry appended later must not replace the latest verdict;
            # a second app with the same group remains a separate body.
            rows = [row('bcc/set', '2026-11-14T01:00:00Z', 'verifier_rejected', old),
                    row('tracee/monitor', '2026-11-14T03:00:00Z', 'installed', current),
                    row('tracee/monitor', '2026-11-14T04:00:00Z', 'installed', current)]
            queue.write_text(''.join(json.dumps(item)+'\n' for item in rows))
            with contextlib.redirect_stdout(io.StringIO()):
                result = publish(base, [queue], root/'raw', evidence/'complete')
            self.assertEqual(result['attempts'], 4)
            self.assertEqual(result['distinct_bodies'], 2)
            self.assertEqual(result['latest_stages'], {'installed':2})
            self.assertEqual(result['latest_failure_classes'], {})
            self.assertEqual(result['per_application']['bcc/set']['distinct_bodies'], 1)
            self.assertEqual(result['per_application']['tracee/monitor']['native_run'], 0)
            archives = result['new_request_archives']
            self.assertEqual(archives[0]['published_archive'], str(old))
            self.assertNotIn('published_archive', archives[1])
            self.assertEqual(b''.join(Path(part['path']).read_bytes() for part in archives[1]['parts']), current.read_bytes())
            self.assertEqual(archives[2]['parts'], archives[1]['parts'])
            self.assertEqual(len((evidence/'complete'/'outcomes.jsonl').read_text().splitlines()), 4)
            self.assertTrue(old.exists() and current.exists())


if __name__=='__main__':
    unittest.main()
