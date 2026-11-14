"""Catch mixed timestamp/frame parsing and double-counted stack categories."""
import importlib.util
from pathlib import Path
import unittest

spec = importlib.util.spec_from_file_location("costs", Path(__file__).with_name("window-costs.py"))
costs = importlib.util.module_from_spec(spec)
spec.loader.exec_module(costs)


class WindowCosts(unittest.TestCase):
    def test_timestamp_is_not_an_ip_and_final_sample_survives(self):
        records = costs.parse_chains(" 12.345678: \n\tffffffff81000001\n\t1234\n\n"
                                    " 13.000001: \n\tffffffff81000011\n")
        self.assertEqual(records, [(12.345678, [0xffffffff81000001, 0x1234]),
                                   (13.000001, [0xffffffff81000011])])
        with self.assertRaises(ValueError):
            costs.parse_chains(" 12.345678:\n\n")

    def test_inclusive_categories_count_each_sample_once(self):
        table = ([0xffffffff81000000, 0xffffffff81000010],
                 ["bpf_probe_read_user", "bpf_prog_0123456789abcdef_entry"], ["", ""])
        result = costs.analyze([(1.0, [0xffffffff81000001, 0xffffffff81000002,
                                       0xffffffff81000011]), (2.0, [0x1234])], table)
        self.assertEqual(result["samples"], 2)
        self.assertEqual(result["kernel_root_samples"], 1)
        self.assertEqual(result["inclusive_categories"], {"probe_read_user": 1, "program_text": 1})
        self.assertEqual(result["root_categories"], {"probe_read_user": 1})
