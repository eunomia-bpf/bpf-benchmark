from __future__ import annotations

import unittest

from runner.libs.case_common import (
    WORKLOAD_MISS_LIMITATION,
    annotate_workload_measurement,
    measurement_workload_miss,
    merge_measurement_limitations,
)


class WorkloadMeasurementTests(unittest.TestCase):
    def test_annotates_workload_miss_when_all_run_counts_are_zero(self) -> None:
        measurement = annotate_workload_measurement(
            {
                "bpf": {
                    101: {"run_cnt_delta": 0},
                    102: {"run_cnt_delta": 0},
                },
                "limitations": ["existing limitation"],
            }
        )

        self.assertTrue(measurement_workload_miss(measurement))
        self.assertEqual(
            ["existing limitation", WORKLOAD_MISS_LIMITATION],
            measurement["limitations"],
        )

    def test_does_not_mark_workload_miss_when_any_program_ran(self) -> None:
        measurement = annotate_workload_measurement(
            {
                "bpf": {
                    101: {"run_cnt_delta": 0},
                    102: {"run_cnt_delta": 7},
                }
            }
        )

        self.assertFalse(measurement_workload_miss(measurement))
        self.assertEqual([], measurement["limitations"])

    def test_merge_measurement_limitations_deduplicates_entries(self) -> None:
        workload_miss = annotate_workload_measurement({"bpf": {101: {"run_cnt_delta": 0}}})
        merged = merge_measurement_limitations(
            workload_miss,
            {"limitations": [WORKLOAD_MISS_LIMITATION, "other limitation"]},
        )

        self.assertEqual([WORKLOAD_MISS_LIMITATION, "other limitation"], merged)


if __name__ == "__main__":
    unittest.main()
