"""Prevent host/guest CPU-mode mixing and cross-domain measurement timestamps."""
import importlib.util
from pathlib import Path
import unittest

spec = importlib.util.spec_from_file_location("host_costs", Path(__file__).with_name("host-costs.py"))
costs = importlib.util.module_from_spec(spec)
spec.loader.exec_module(costs)


class HostCosts(unittest.TestCase):
    def test_guest_user_overlap_bits_and_host_exits_do_not_become_guest_kernel(self):
        samples = costs.parse_samples(
            " 12/13 [017] G 101.000000001: 40 ffffffff81000001\n"
            " 12/13 [017] KGg 101.000000002: 50 1234\n"
            " 12/13 [017] K 101.000000003: 60 ffffffff81000001\n")
        table = ([0xffffffff81000000], ["bpf_prog_0123456789abcdef_entry"], [""])
        result = costs.analyze(samples, table, 101000000001, 101000000003)
        self.assertEqual(result["modes"], {"G": 1, "KGg": 1, "K": 1})
        self.assertEqual(result["guest_kernel_samples"], 1)
        self.assertEqual(result["sampled_cycles"], 40)
        self.assertEqual(result["root_categories"], {"program_text": 1})
        self.assertEqual(samples[0]["time_ns"], 101000000001)
        with self.assertRaises(ValueError):
            costs.parse_samples("invalid sample")

    def test_guest_clock_window_is_translated_before_filtering_host_samples(self):
        # Guest mono10 coincides with wall100; host mono1000 coincides with wall100.
        first, last = costs.host_window({"start_seconds": 11, "end_seconds": 13},
            {"wall_ns": 100000000000, "monotonic_ns": 10000000000},
            {"wall_ns": 100000000000, "monotonic_ns": 1000000000000})
        self.assertEqual((first, last), (1001000000000, 1003000000000))
        table = ([0xffffffff81000000], ["copy_from_user_nofault"], [""])
        samples = costs.parse_samples(" 1/2 [016] G 1002.0: 17 ffffffff81000001\n"
                                      " 1/2 [016] G 12.0: 100 ffffffff81000001\n")
        result = costs.analyze(samples, table, first, last)
        self.assertEqual(result["root_category_cycles"], {"user_nofault_copy": 17})
