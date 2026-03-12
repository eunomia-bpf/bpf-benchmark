from __future__ import annotations

import sys
from pathlib import Path
import unittest

ROOT_DIR = Path(__file__).resolve().parents[2]
if str(ROOT_DIR) not in sys.path:
    sys.path.insert(0, str(ROOT_DIR))

from corpus.policy_utils import parse_policy_v3

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
                "sites": ((4, "rotate", "rotate-64"),),
            },
            "03-valid-both-sites.yaml": {
                "program": "mixed-demo",
                "sites": (
                    (0, "cmov", "cond-select-64"),
                    (4, "rotate", "rotate-64"),
                ),
            },
            "04-valid-programless-cmov.yaml": {
                "program": None,
                "sites": ((0, "cmov", "cond-select-64"),),
            },
            "05-valid-rotate-then-cmov.yaml": {
                "program": "mixed-demo",
                "sites": (
                    (4, "rotate", "rotate-64"),
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


if __name__ == "__main__":
    unittest.main()
