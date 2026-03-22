from __future__ import annotations

import importlib.util
from pathlib import Path
import unittest

ROOT_DIR = Path(__file__).resolve().parents[2]
SCRIPT_PATH = ROOT_DIR / "runner" / "scripts" / "profile_guided_policy.py"


def load_module():
    spec = importlib.util.spec_from_file_location("profile_guided_policy", SCRIPT_PATH)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"unable to load {SCRIPT_PATH}")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


class ProfileGuidedPolicyTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.module = load_module()

    def test_resolve_profile_payload_accepts_wrapper(self) -> None:
        payload = {
            "case": "tracee",
            "profile": {
                "programs": [
                    {"prog_id": 7, "name": "demo", "sites": []},
                ]
            },
        }
        resolved = self.module.resolve_profile_payload(payload)
        self.assertIs(resolved, payload["profile"])

    def test_build_census_index_extracts_nested_enumerate_sites(self) -> None:
        by_id, by_name = self.module.build_census_index(
            {
                "programs": [
                    {
                        "prog_id": 11,
                        "name": "alpha",
                        "enumerate_record": {
                            "sites": [
                                {"insn": 10, "family": "wide", "pattern_kind": "wide-load-2"},
                            ]
                        },
                    }
                ]
            }
        )
        self.assertEqual(by_id[11][0]["family"], "wide")
        self.assertEqual(by_name["alpha"][0]["pattern_kind"], "wide-load-2")

    def test_decide_sites_keeps_only_always_families_without_branch_data(self) -> None:
        decision = self.module.decide_sites(
            {
                "run_cnt": 5000,
                "run_time_ns": 900000,
                "branch_miss_rate": None,
                "branches": None,
            },
            [
                {"insn": 10, "family": "wide", "pattern_kind": "wide-load-2"},
                {"insn": 20, "family": "branch-flip", "pattern_kind": "branch-flip"},
                {"insn": 30, "family": "cmov", "pattern_kind": "cond-select-64"},
            ],
            run_cnt_threshold=1000,
            run_time_threshold_ns=0,
            branch_miss_rate_threshold=0.03,
            cmov_max_branch_miss_rate=0.01,
            min_branch_samples=1000,
            always_families={"wide", "rotate", "lea", "extract", "endian"},
            deny_families=set(),
            deny_pattern_kinds=set(),
        )
        self.assertTrue(decision["hot"])
        self.assertFalse(decision["branch_data_ready"])
        self.assertEqual(
            decision["selected_sites"],
            [{"insn": 10, "family": "wide", "pattern_kind": "wide-load-2"}],
        )

    def test_decide_sites_enables_branch_flip_with_high_miss_rate(self) -> None:
        decision = self.module.decide_sites(
            {
                "run_cnt": 5000,
                "run_time_ns": 900000,
                "branch_miss_rate": 0.08,
                "branches": 2000,
            },
            [
                {"insn": 20, "family": "branch-flip", "pattern_kind": "branch-flip"},
                {"insn": 30, "family": "cmov", "pattern_kind": "cond-select-64"},
            ],
            run_cnt_threshold=1000,
            run_time_threshold_ns=0,
            branch_miss_rate_threshold=0.03,
            cmov_max_branch_miss_rate=0.01,
            min_branch_samples=1000,
            always_families={"wide", "rotate", "lea", "extract", "endian"},
            deny_families=set(),
            deny_pattern_kinds=set(),
        )
        self.assertTrue(decision["allow_branch_flip"])
        self.assertFalse(decision["allow_cmov"])
        self.assertEqual(
            decision["selected_sites"],
            [{"insn": 20, "family": "branch-flip", "pattern_kind": "branch-flip"}],
        )


if __name__ == "__main__":
    unittest.main()
