import importlib.util
from pathlib import Path
import unittest

spec = importlib.util.spec_from_file_location('cpu_stack_summary', Path(__file__).with_name('cpu-stack-summary.py'))
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)


class CpuStackTests(unittest.TestCase):
    def test_recursive_frames_count_once_and_empty_samples_keep_denominator(self):
        text = '''tetragon  42   166.010657:  10101010 cpu-clock:
 ffff do_readlinkat+0x1 ([kernel.kallsyms])
 fffe do_readlinkat+0x2 ([kernel.kallsyms])
 abcd native_loader::load_from_fd(native_loader::FdLoadOptions const&)+0x11 (/lib/native.so)
 abce bpf_map_get_info_by_fd.isra.0+0x8 ([kernel.kallsyms])

tetragon  43   166.020657:  20202020 cpu-clock:

'''
        result = module.summarize(module.samples(text))
        self.assertEqual(result['samples'], 2)
        self.assertEqual(result['empty_stacks'], 1)
        self.assertEqual(result['period_sum'], 30303030)
        self.assertEqual(result['with_file_backed_frames'], 1)
        self.assertEqual(result['groups']['readlink']['samples'], 1)
        self.assertEqual(result['groups']['readlink']['with_native_load'], 1)
        self.assertEqual(result['groups']['map_info']['samples'], 1)
        with self.assertRaises(ValueError):
            module.samples(text + 'broken frame\n')


if __name__ == '__main__':
    unittest.main()
