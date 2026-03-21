from __future__ import annotations

from pathlib import Path
from tempfile import TemporaryDirectory
import unittest
from unittest.mock import patch

from runner.libs.policy import render_manifest_policy_v3_text, resolve_live_policy_path
from runner.libs.recompile import PolicyTarget, apply_recompile, resolve_policy_files


class LivePolicyDiscoveryTest(unittest.TestCase):
    def test_render_manifest_policy_tracks_live_and_explicit_family_counts(self) -> None:
        text, summary = render_manifest_policy_v3_text(
            program_name="demo",
            manifest={
                "summary": {"total_sites": 2},
                "sites": [
                    {"insn": 10, "family": "cmov", "pattern_kind": "cond-select-64"},
                    {"insn": 20, "family": "branch-flip", "pattern_kind": "branch-flip"},
                ],
            },
            skip_families=frozenset({"cmov"}),
        )

        self.assertEqual(summary["live_total_sites"], 2)
        self.assertEqual(summary["explicit_sites"], 1)
        self.assertEqual(summary["family_counts"]["cmov"], 1)
        self.assertEqual(summary["family_counts"]["branch-flip"], 1)
        self.assertEqual(summary["explicit_family_counts"], {"branch-flip": 1})
        self.assertEqual(summary["skipped_family_counts"], {"cmov": 1})
        self.assertIn("branch-flip", text)
        self.assertNotIn("cond-select-64", text)

    def test_resolve_live_policy_path_prefers_exact_id_then_unique_name_match(self) -> None:
        with TemporaryDirectory() as tmpdir:
            policy_dir = Path(tmpdir)
            live_dir = policy_dir / "live"
            live_dir.mkdir(parents=True, exist_ok=True)
            exact = live_dir / "00042_demo.policy.yaml"
            exact.write_text("version: 3\nprogram: 'demo'\nsites: []\n")

            resolved = resolve_live_policy_path(
                program_name="demo",
                prog_id=42,
                policy_dir=policy_dir,
            )
            self.assertEqual(resolved, exact)

            exact.unlink()
            unique = live_dir / "00100_demo.policy.yaml"
            unique.write_text("version: 3\nprogram: 'demo'\nsites: []\n")
            resolved = resolve_live_policy_path(
                program_name="demo",
                prog_id=42,
                policy_dir=policy_dir,
            )
            self.assertEqual(resolved, unique)

    def test_resolve_policy_files_prefers_live_artifact_over_object_policy(self) -> None:
        live_path = Path("/tmp/live-demo.policy.yaml")
        offline_path = Path("/tmp/offline-demo.policy.yaml")
        with (
            patch("runner.libs.policy.resolve_live_policy_path", return_value=live_path),
            patch("runner.libs.policy.resolve_policy_path", return_value=offline_path),
        ):
            resolved = resolve_policy_files(
                [
                    PolicyTarget(
                        prog_id=7,
                        object_path="/tmp/demo.bpf.o",
                        program_name="demo",
                    )
                ]
            )
        self.assertEqual(resolved[7], str(live_path.resolve()))

    def test_apply_recompile_auto_generates_live_policy_when_missing(self) -> None:
        with (
            patch("runner.libs.recompile.sample_bpf_stats", return_value={7: {"name": "demo"}}),
            patch(
                "runner.libs.recompile.enumerate_program_record",
                return_value={
                    "name": "demo",
                    "total_sites": 2,
                    "sites": [
                        {"insn": 10, "family": "cmov", "pattern_kind": "cond-select-64"},
                        {"insn": 20, "family": "branch-flip", "pattern_kind": "branch-flip"},
                    ],
                },
            ),
            patch(
                "runner.libs.recompile._enumerate_apply_one",
                return_value={
                    "name": "demo",
                    "recompile_ok": True,
                    "total_sites": 1,
                    "sites": [
                        {"insn": 20, "family": "branch-flip", "pattern_kind": "branch-flip"},
                    ],
                },
            ),
        ):
            results = apply_recompile([7], "/tmp/fake-scanner")

        record = results[7]
        self.assertEqual(record["policy_mode"], "live-auto-policy")
        self.assertTrue(record["applied"])
        self.assertIsNone(record["policy_file"])
        self.assertEqual(record["counts"]["total_sites"], 1)
        self.assertEqual(record["counts"]["branch_flip_sites"], 1)
        self.assertEqual(record["policy_generation"]["explicit_sites"], 1)
        self.assertEqual(record["policy_generation"]["skipped_family_counts"], {"cmov": 1})


if __name__ == "__main__":
    unittest.main()
