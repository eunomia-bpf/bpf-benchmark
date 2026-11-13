import unittest
import symbolize


class RootSampleTests(unittest.TestCase):
    def test_root_count_and_unknown_addresses_keep_denominator(self):
        ips = symbolize.parse_root_ips(' ffffffff80001008\n\n 0\n 1234\n')
        counts = symbolize.resolve(ips, [0xffffffff80001000], ['bpf_prog_0123456789abcdef_entry'], [''])
        self.assertEqual(len(ips), 3)
        self.assertEqual(sum(counts.values()), 3)
        self.assertEqual(counts['bpf_prog_0123456789abcdef_entry'], 1)
        self.assertEqual(counts['[zero-ip]'], 1)
        self.assertEqual(counts['[below-kernel]'], 1)
        with self.assertRaises(ValueError):
            symbolize.parse_root_ips(' ffffffff80001008 symbol (dso)\n')


if __name__ == '__main__':
    unittest.main()
