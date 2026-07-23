#!/usr/bin/env python3

from __future__ import annotations

import json
from pathlib import Path
import tempfile
import unittest

from sync_specialization_profile_coverage import CoverageError, sync_coverage


def write_profile(path: Path, profile: dict[str, object]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(profile), encoding="utf-8")


class SyncSpecializationProfileCoverageTests(unittest.TestCase):
    def test_creates_missing_profiles_without_overwriting_pmu_profile(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            coverage = root / "context"
            program_hash = "0123456789abcdef"
            write_profile(
                coverage / f"hash-{program_hash}.json",
                {
                    "schema_version": 1,
                    "pass": "context_specialize",
                    "program_hash": program_hash,
                    "fields": [],
                },
            )
            tail_root = root / "tail"
            hot_root = root / "hot"
            existing_hot = {
                "schema_version": 1,
                "pass": "hot_region_version",
                "program_hash": program_hash,
                "per_site": {
                    "4": {"branch_count": 10, "taken": 9, "not_taken": 1}
                },
            }
            write_profile(hot_root / f"hash-{program_hash}.json", existing_hot)

            created = sync_coverage(
                coverage,
                {
                    "tail_call_icache": tail_root,
                    "hot_region_version": hot_root,
                },
            )

            self.assertEqual(
                created, [tail_root / f"hash-{program_hash}.json"]
            )
            tail = json.loads(created[0].read_text(encoding="utf-8"))
            self.assertEqual(tail["per_site"], {})
            self.assertEqual(tail["program_hash"], program_hash)
            self.assertEqual(
                json.loads(
                    (hot_root / f"hash-{program_hash}.json").read_text(
                        encoding="utf-8"
                    )
                ),
                existing_hot,
            )

    def test_rejects_profile_hash_that_disagrees_with_filename(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            coverage = root / "context"
            write_profile(
                coverage / "hash-0123456789abcdef.json",
                {
                    "schema_version": 1,
                    "pass": "context_specialize",
                    "program_hash": "fedcba9876543210",
                    "fields": [],
                },
            )
            with self.assertRaisesRegex(CoverageError, "must match filename"):
                sync_coverage(
                    coverage,
                    {"tail_call_icache": root / "tail"},
                )

    def test_adds_explicit_hash_discovered_after_canonical_capture(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            coverage = root / "context"
            canonical_hash = "0123456789abcdef"
            new_hash = "1111111111111111"
            write_profile(
                coverage / f"hash-{canonical_hash}.json",
                {
                    "schema_version": 1,
                    "pass": "context_specialize",
                    "program_hash": canonical_hash,
                    "fields": [],
                },
            )

            created = sync_coverage(
                coverage,
                {"context_specialize": coverage},
                (new_hash,),
            )

            self.assertEqual(
                created, [coverage / f"hash-{new_hash}.json"]
            )
            profile = json.loads(created[0].read_text(encoding="utf-8"))
            self.assertEqual(profile["fields"], [])
            self.assertEqual(profile["program_hash"], new_hash)


if __name__ == "__main__":
    unittest.main()
