"""Catch counter/name collisions, zero-count omission and false verification."""
import io
import json
import tarfile
import unittest

from collect_verified_app import summarize


def archive(files):
    stream = io.BytesIO()
    with tarfile.open(fileobj=stream, mode='w:gz') as output:
        for name, data in files.items():
            entry = tarfile.TarInfo(name)
            entry.size = len(data)
            output.addfile(entry, io.BytesIO(data))
    stream.seek(0)
    return stream


class AppAccounting(unittest.TestCase):
    def test_ids_zeros_and_unobserved_programs_are_preserved(self):
        requests = []
        files = {'service/summary.json':b'{"returncode":0}'}
        for request, prog in enumerate((10, 11, 12), 1):
            name = f'{request}.success.tar.gz'
            inner = archive({'request/load.stdout':json.dumps(dict(status=0, prog_id=prog)).encode(),
                             'request/generated/commands.jsonl':b'{"returncode":0}\n'})
            files['service/requests/'+name] = inner.getvalue()
            requests.append(dict(request_id=request, source_prog_id=prog+20,
                                 prog_id=prog, status=0, artifact_archive='/old/'+name))
        # A refused request must not be counted as verified or installed.
        requests.append(dict(request_id=4, source_prog_id=33, status=-22))
        files['service/requests/requests.jsonl'] = ''.join(json.dumps(r)+'\n' for r in requests).encode()
        app = dict(app='fixture',status='ok',error='',baseline=dict(bpf={}),
                   post_rejit=dict(bpf={'10':dict(name='same_name',run_cnt_delta=5),
                                       '11':dict(name='same_name',run_cnt_delta=0)}))
        with tarfile.open(fileobj=archive(files)) as service:
            result = summarize(app, service)
        self.assertEqual((result['loaded'], result['verified'], result['installed'], result['run']), (4,3,3,1))
        self.assertEqual(result['installed_without_counter'], [12])
        self.assertEqual(len(result['programs']), 4)
        self.assertEqual(result['programs'][1]['counters']['run_cnt_delta'], 0)
        self.assertIsNone(result['programs'][3]['stock_load'])

    def test_failed_startup_has_no_native_phase_or_program_id(self):
        files = {'service/summary.json':b'{"returncode":0}',
                 'service/requests/requests.jsonl':b'{"request_id":1,"source_prog_id":15,"status":-5}\n'}
        app = dict(app='fixture',status='error',error='native startup refused',
                   baseline=dict(bpf={'6':dict(run_cnt_delta=1)}),post_rejit=None)
        with tarfile.open(fileobj=archive(files)) as service:
            result = summarize(app, service)
        self.assertEqual((result['loaded'],result['verified'],result['installed'],result['run']), (1,0,0,0))
        self.assertEqual(result['application_status'],'error')
        self.assertIsNone(result['programs'][0]['counters'])


if __name__=='__main__':
    unittest.main()
