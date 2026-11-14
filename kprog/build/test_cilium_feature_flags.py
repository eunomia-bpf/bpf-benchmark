"""Catch lost feature-header includes or accidentally forwarded Clang builtins."""
import importlib.util
from pathlib import Path
import tempfile
import unittest

SPEC=importlib.util.spec_from_file_location('replay',Path(__file__).with_name('cilium-upstream.py'))
REPLAY=importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(REPLAY)


class ProbeDefines(unittest.TestCase):
    def test_nested_generated_features_keep_values_without_clang_predefines(self):
        with tempfile.TemporaryDirectory() as directory:
            root=Path(directory)
            common=root/'features.h';xdp=root/'features_xdp.h'
            common.write_text('#pragma once\n#define HAVE_SET_RETVAL 1\n')
            xdp.write_text('#include "features.h"\n#if HAVE_SET_RETVAL\n#define HAVE_XDP_LOAD_BYTES 1\n#endif\n#define CAP_WITH_VALUE (4 + 2)\n')
            flags,record=REPLAY.feature_flags([common,xdp],root/'result')
            self.assertEqual(set(flags),{'-DHAVE_SET_RETVAL=1','-DHAVE_XDP_LOAD_BYTES=1','-DCAP_WITH_VALUE=(4 + 2)'})
            self.assertEqual(len(record['headers']),2)


if __name__=='__main__': unittest.main()
