from __future__ import annotations

import sys
from pathlib import Path
import unittest

ROOT_DIR = Path(__file__).resolve().parents[2]
if str(ROOT_DIR) not in sys.path:
    sys.path.insert(0, str(ROOT_DIR))

from corpus.policy_utils import parse_policy_v2

GOLDEN_DIR = ROOT_DIR / "scanner" / "tests" / "policy_v2_golden"
DISCOVERED_SITES = (
    (0, "cmov"),
    (4, "rotate"),
)


def effective_action(document, *, insn: int, family: str) -> str:
    action = document.default
    for family_action in document.families:
        if family_action.family == family:
            action = family_action.action
            break
    for site in document.sites:
        if site.insn == insn and site.family == family:
            action = site.action
            break
    return action


def selected_families(document) -> tuple[str, ...]:
    return tuple(
        family
        for insn, family in DISCOVERED_SITES
        if effective_action(document, insn=insn, family=family) == "apply"
    )


class PolicyUtilsTest(unittest.TestCase):
    def test_valid_golden_cases(self) -> None:
        cases = {
            "01-valid-empty.yaml": {
                "default": "skip",
                "families": (),
                "sites": (),
                "selected": (),
            },
            "02-valid-stock-alias.yaml": {
                "default": "skip",
                "families": (),
                "sites": (),
                "selected": (),
            },
            "03-valid-family-site-precedence.yaml": {
                "default": "apply",
                "families": (("cmov", "skip"), ("rotate", "apply")),
                "sites": ((0, "cmov", "apply"), (4, "rotate", "skip")),
                "selected": ("cmov",),
            },
            "04-valid-family-alias.yaml": {
                "default": "skip",
                "families": (("cmov", "apply"),),
                "sites": (),
                "selected": ("cmov",),
            },
            "05-valid-site-only-apply.yaml": {
                "default": "skip",
                "families": (),
                "sites": ((4, "rotate", "apply"),),
                "selected": ("rotate",),
            },
        }

        for filename, expected in cases.items():
            with self.subTest(filename=filename):
                document = parse_policy_v2(GOLDEN_DIR / filename)
                self.assertEqual(document.version, 2)
                self.assertEqual(document.program, "mixed-demo")
                self.assertEqual(document.default, expected["default"])
                self.assertEqual(
                    tuple((entry.family, entry.action) for entry in document.families),
                    expected["families"],
                )
                self.assertEqual(
                    tuple((entry.insn, entry.family, entry.action) for entry in document.sites),
                    expected["sites"],
                )
                self.assertEqual(selected_families(document), expected["selected"])

    def test_invalid_golden_cases(self) -> None:
        for filename in (
            "06-invalid-missing-site-action.yaml",
            "07-invalid-duplicate-site.yaml",
            "08-invalid-duplicate-family-alias.yaml",
            "09-invalid-duplicate-family-key.yaml",
        ):
            with self.subTest(filename=filename):
                with self.assertRaises(ValueError):
                    parse_policy_v2(GOLDEN_DIR / filename)


if __name__ == "__main__":
    unittest.main()
