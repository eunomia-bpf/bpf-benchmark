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


if __name__=='__main__': unittest.main()
