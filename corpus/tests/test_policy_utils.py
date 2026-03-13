from __future__ import annotations

import sys
from pathlib import Path
import unittest

ROOT_DIR = Path(__file__).resolve().parents[2]
if str(ROOT_DIR) not in sys.path:
    sys.path.insert(0, str(ROOT_DIR))

from corpus.policy_utils import parse_policy_v3, remap_policy_v3_to_live

GOLDEN_DIR = ROOT_DIR / "scanner" / "tests" / "policy_v2_golden"


class PolicyUtilsTest(unittest.TestCase):
    def test_valid_golden_cases(self) -> None:
        cases = {
            "01-valid-empty.yaml": {
                "program": "mixed-demo",
                "sites": (),
            },
            "02-valid-rotate-only.yaml": {
                "program": "mixed-demo",
                "sites": ((4, "rotate", "rotate-32"),),
            },
            "03-valid-both-sites.yaml": {
                "program": "mixed-demo",
                "sites": (
                    (0, "cmov", "cond-select-64"),
                    (4, "rotate", "rotate-32"),
                ),
            },
            "04-valid-programless-cmov.yaml": {
                "program": None,
                "sites": ((0, "cmov", "cond-select-64"),),
            },
            "05-valid-rotate-then-cmov.yaml": {
                "program": "mixed-demo",
                "sites": (
                    (4, "rotate", "rotate-32"),
                    (0, "cmov", "cond-select-64"),
                ),
            },
        }

        for filename, expected in cases.items():
            with self.subTest(filename=filename):
                document = parse_policy_v3(GOLDEN_DIR / filename)
                self.assertEqual(document.version, 3)
                self.assertEqual(document.program, expected["program"])
                self.assertEqual(
                    tuple(
                        (entry.insn, entry.family, entry.pattern_kind)
                        for entry in document.sites
                    ),
                    expected["sites"],
                )

    def test_invalid_golden_cases(self) -> None:
        for filename in (
            "06-invalid-version-2.yaml",
            "07-invalid-missing-pattern-kind.yaml",
            "08-invalid-duplicate-site.yaml",
            "09-invalid-noncanonical-family.yaml",
            "10-invalid-unknown-site-field.yaml",
        ):
            with self.subTest(filename=filename):
                with self.assertRaises(ValueError):
                    parse_policy_v3(GOLDEN_DIR / filename)

    def test_remap_policy_v3_to_live_matches_exact_pattern_kind(self) -> None:
        text, summary = remap_policy_v3_to_live(
            {
                "version": 3,
                "program": "mixed-demo",
                "sites": [
                    {"insn": 10, "family": "rotate", "pattern_kind": "rotate-32"},
                    {"insn": 11, "family": "rotate", "pattern_kind": "rotate-64"},
                ],
            },
            {
                "sites": [
                    {"family": "rotate", "start_insn": 400, "pattern_kind": "rotate-64"},
                    {"family": "rotate", "start_insn": 401, "pattern_kind": "rotate-32"},
                ]
            },
        )
        document = parse_policy_v3(text)
        self.assertEqual(
            tuple(
                (site.insn, site.family, site.pattern_kind)
                for site in document.sites
            ),
            (
                (401, "rotate", "rotate-32"),
                (400, "rotate", "rotate-64"),
            ),
        )
        self.assertEqual(summary.remapped_sites, 2)
        self.assertEqual(summary.dropped_sites, 0)

    def test_remap_policy_v3_to_live_drops_kind_mismatch(self) -> None:
        text, summary = remap_policy_v3_to_live(
            {
                "version": 3,
                "program": "mixed-demo",
                "sites": [
                    {"insn": 10, "family": "rotate", "pattern_kind": "rotate-32"},
                ],
            },
            {
                "sites": [
                    {"family": "rotate", "start_insn": 400, "pattern_kind": "rotate-64"},
                ]
            },
        )
        document = parse_policy_v3(text)
        self.assertEqual(document.sites, ())
        self.assertEqual(summary.remapped_sites, 0)
        self.assertEqual(summary.dropped_sites, 1)


if __name__ == "__main__":
    unittest.main()
