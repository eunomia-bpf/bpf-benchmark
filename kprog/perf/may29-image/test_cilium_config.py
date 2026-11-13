"""Catch flattened endpoint configs and truncated binary compiler evidence."""
import importlib.util
import io
import json
from pathlib import Path
import tarfile
import tempfile
import unittest

SPEC=importlib.util.spec_from_file_location('config',Path(__file__).with_name('cilium-config.py'))
CONFIG=importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(CONFIG)


class GeneratedState(unittest.TestCase):
    def test_distinct_endpoint_configs_and_binary_object_survive_together(self):
        with tempfile.TemporaryDirectory() as directory:
            root=Path(directory)
            for name,data in [('state/templates/a/ep_config.h',b'endpoint-a\n'),
                              ('state/templates/b/ep_config.h',b'endpoint-b\n'),
                              ('state/globals/bpf_xdp.o',bytes(range(256)))]:
                path=root/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(data)
            output=io.BytesIO();CONFIG.capture(root,output);output.seek(0)
            with tarfile.open(fileobj=output) as archive:
                self.assertEqual(archive.extractfile('state/templates/a/ep_config.h').read(),b'endpoint-a\n')
                self.assertEqual(archive.extractfile('state/templates/b/ep_config.h').read(),b'endpoint-b\n')
                self.assertEqual(archive.extractfile('state/globals/bpf_xdp.o').read(),bytes(range(256)))
                index=json.load(archive.extractfile('capture.json'))
                self.assertEqual(len(index['files']),3)

    def test_probe_headers_outside_state_are_retained_as_generated_input(self):
        with tempfile.TemporaryDirectory() as directory:
            root=Path(directory)/'state';root.mkdir()
            features=Path(directory)/'bpf/include/bpf';features.mkdir(parents=True)
            for name in ['features.h','features_skb.h','features_xdp.h']:
                (features/name).write_bytes(('#define '+name.replace('.','_')+' 1\n').encode())
            output=io.BytesIO();CONFIG.capture(root,output,features);output.seek(0)
            with tarfile.open(fileobj=output) as archive:
                index=json.load(archive.extractfile('capture.json'))
                self.assertEqual(len(index['files']),3)
                self.assertEqual(archive.extractfile('generated-features/features_xdp.h').read(),b'#define features_xdp_h 1\n')
                self.assertEqual(index['files'][2]['source'],str(features/'features_xdp.h'))


if __name__=='__main__': unittest.main()
