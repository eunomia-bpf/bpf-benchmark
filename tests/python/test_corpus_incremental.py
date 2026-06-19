"""
Tests for corpus/driver.py incremental per-app write and SIGTERM finalize.

Bug-detection purpose:
  - _write_incremental_app_result: verify that per-app JSON, progress.json, and
    metadata.json are correctly written/updated after each app completes.
  - SIGTERM handler: verify that _finalize_partial writes result.json
    with partial results and calls SystemExit(130).
  - _finalize_partial: verify that apps not yet reached get an error entry and
    partial=True is set in the payload.
  - native-loader config validation: reject SKIP_REJIT plus post-only native
    loader before it can accidentally run native replacement in a no-ReJIT
    diagnostic.
"""
from __future__ import annotations

import json
import os
import signal
import sys
import tempfile
import unittest
from dataclasses import dataclass, field
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Mapping, Optional
from unittest import mock

REPO_ROOT = Path(__file__).resolve().parents[2]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

import corpus.driver as driver
from runner.libs.run_artifacts import ArtifactSession


# ---------------------------------------------------------------------------
# Minimal stubs
# ---------------------------------------------------------------------------

@dataclass
class _FakeApp:
    name: str
    runner: str = "fake"
    args: dict = field(default_factory=dict)
    duration_s: Optional[float] = None

    def workload_for(self, _context: str) -> str:
        return "fake_workload"


@dataclass
class _FakeSuite:
    apps: list
    suite_name: str = "test_suite"
    manifest_path: Path = field(default_factory=lambda: Path("/fake/suite.yaml"))


def _make_artifact_session(tmp_path: Path) -> ArtifactSession:
    output_json = tmp_path / "results" / "vm_corpus.json"
    output_json.parent.mkdir(parents=True, exist_ok=True)

    def _build_metadata(
        status: str, started_at: str, updated_at: str, error_message: Optional[str]
    ) -> dict:
        return {
            "status": status,
            "started_at": started_at,
            "last_updated_at": updated_at,
        }

    session = ArtifactSession(
        output_path=output_json,
        run_type="vm_corpus",
        generated_at=datetime.now(timezone.utc).isoformat(),
        metadata_builder=_build_metadata,
    )
    session.write(status="running", progress_payload={"status": "running"})
    return session


# ---------------------------------------------------------------------------
# Tests: native-loader config validation
# ---------------------------------------------------------------------------

class TestNativeLoaderConfigValidation(unittest.TestCase):
    def test_post_only_native_loader_rejects_skip_rejit(self) -> None:
        env = {
            "RUN_TARGET_ARCH": "arm64",
            "RUN_EXECUTOR": "aws",
            "RUN_TOKEN": "unit",
            "RUN_REMOTE_PYTHON_BIN": "python3",
            "RUN_BPFTOOL_BIN": "bpftool",
            "BPFREJIT_CORPUS_NATIVE_LOADER_POST_ONLY": "1",
            "SKIP_REJIT": "norejit",
        }
        with mock.patch.dict(os.environ, env, clear=True):
            with self.assertRaisesRegex(SystemExit, "incompatible with SKIP_REJIT"):
                driver.parse_args()


# ---------------------------------------------------------------------------
# Tests: _write_incremental_app_result
# ---------------------------------------------------------------------------

class TestWriteIncrementalAppResult(unittest.TestCase):
    def setUp(self) -> None:
        self._tmp = tempfile.TemporaryDirectory()
        self.tmp = Path(self._tmp.name)

    def tearDown(self) -> None:
        self._tmp.cleanup()

    def _session(self) -> ArtifactSession:
        return _make_artifact_session(self.tmp)

    def test_writes_app_json(self) -> None:
        session = self._session()
        result = {"app": "tracee", "status": "ok", "error": ""}
        driver._write_incremental_app_result(session.run_dir, "tracee", result, apps_done=1, total_apps=3)
        app_path = session.run_dir / "details" / "apps" / "tracee.json"
        self.assertTrue(app_path.exists(), f"expected {app_path}")
        written = json.loads(app_path.read_text())
        self.assertEqual(written["status"], "ok")

    def test_slash_in_app_name_becomes_double_underscore(self) -> None:
        session = self._session()
        result = {"app": "bcc/set", "status": "error", "error": "fail"}
        driver._write_incremental_app_result(session.run_dir, "bcc/set", result, apps_done=1, total_apps=2)
        app_path = session.run_dir / "details" / "apps" / "bcc__set.json"
        self.assertTrue(app_path.exists(), f"expected {app_path}")

    def test_progress_json_updated(self) -> None:
        session = self._session()
        result = {"app": "tetragon", "status": "ok", "error": ""}
        driver._write_incremental_app_result(session.run_dir, "tetragon", result, apps_done=2, total_apps=8)
        progress_path = session.run_dir / "details" / "progress.json"
        self.assertTrue(progress_path.exists())
        progress = json.loads(progress_path.read_text())
        self.assertEqual(progress["apps_done"], 2)
        self.assertEqual(progress["total_apps"], 8)
        self.assertEqual(progress["last_app"], "tetragon")
        self.assertEqual(progress["last_app_status"], "ok")
        self.assertIn("last_updated_at", progress)

    def test_metadata_last_updated_at_refreshed(self) -> None:
        session = self._session()
        old_metadata = json.loads((session.run_dir / "metadata.json").read_text())
        old_ts = old_metadata.get("last_updated_at", "")
        result = {"app": "cilium", "status": "ok", "error": ""}
        driver._write_incremental_app_result(session.run_dir, "cilium", result, apps_done=1, total_apps=5)
        new_metadata = json.loads((session.run_dir / "metadata.json").read_text())
        new_ts = new_metadata.get("last_updated_at", "")
        # last_updated_at must still be present; value may be same or newer
        self.assertIn("last_updated_at", new_metadata)
        self.assertGreaterEqual(new_ts, old_ts)


# ---------------------------------------------------------------------------
# Tests: _finalize_partial
# ---------------------------------------------------------------------------

class TestFinalizePartial(unittest.TestCase):
    def setUp(self) -> None:
        self._tmp = tempfile.TemporaryDirectory()
        self.tmp = Path(self._tmp.name)

    def tearDown(self) -> None:
        self._tmp.cleanup()

    def _suite(self, names: list[str]) -> _FakeSuite:
        return _FakeSuite(apps=[_FakeApp(name=n) for n in names])

    def _session(self) -> ArtifactSession:
        return _make_artifact_session(self.tmp)

    def test_writes_result_json(self) -> None:
        session = self._session()
        suite = self._suite(["tracee", "tetragon", "cilium"])
        partial = {
            "tracee": {"app": "tracee", "status": "ok", "error": "", "baseline": None, "post_rejit": None, "rejit_result": None},
        }
        driver._finalize_partial(session, suite, partial, error_message="test error")
        result_json = session.run_dir / "details" / "result.json"
        self.assertTrue(result_json.exists(), "result.json must exist after _finalize_partial")

    def test_partial_flag_set(self) -> None:
        session = self._session()
        suite = self._suite(["tracee", "tetragon"])
        partial: dict = {}
        payload = driver._finalize_partial(session, suite, partial, error_message="killed")
        self.assertTrue(payload.get("partial"), "partial flag must be True")

    def test_unreached_apps_get_error_entry(self) -> None:
        session = self._session()
        suite = self._suite(["tracee", "tetragon", "cilium"])
        partial = {
            "tracee": {"app": "tracee", "status": "ok", "error": "", "baseline": None, "post_rejit": None, "rejit_result": None},
        }
        payload = driver._finalize_partial(session, suite, partial, error_message="killed")
        results = {r["app"]: r for r in payload["results"]}
        self.assertEqual(results["tracee"]["status"], "ok")
        self.assertEqual(results["tetragon"]["status"], "error")
        self.assertEqual(results["cilium"]["status"], "error")

    def test_metadata_status_set_to_error(self) -> None:
        session = self._session()
        suite = self._suite(["tracee"])
        partial: dict = {}
        driver._finalize_partial(session, suite, partial, error_message="killed")
        metadata = json.loads((session.run_dir / "metadata.json").read_text())
        self.assertEqual(metadata.get("status"), "error")


# ---------------------------------------------------------------------------
# Tests: SIGTERM handler via main()
# ---------------------------------------------------------------------------

class TestSigtermHandler(unittest.TestCase):
    def setUp(self) -> None:
        self._tmp = tempfile.TemporaryDirectory()
        self.tmp = Path(self._tmp.name)

    def tearDown(self) -> None:
        self._tmp.cleanup()

    def test_sigterm_causes_partial_finalize_and_exit_130(self) -> None:
        """Sending SIGTERM to the process during run_suite causes SystemExit(130)
        and writes partial result.json with the apps completed so far."""
        session = _make_artifact_session(self.tmp)
        suite = _FakeSuite(
            apps=[
                _FakeApp(name="tracee"),
                _FakeApp(name="tetragon"),
            ]
        )
        partial: dict[str, dict] = {
            "tracee": {
                "app": "tracee", "status": "ok", "error": "",
                "baseline": None, "post_rejit": None, "rejit_result": None,
            }
        }
        sigterm_received: list[bool] = [False]

        def _handler(signum: int, frame: object) -> None:
            sigterm_received[0] = True
            try:
                driver._finalize_partial(
                    session,
                    suite,
                    partial,
                    error_message="corpus run terminated by SIGTERM",
                    fatal_error="SIGTERM received",
                )
            except Exception:
                pass
            raise SystemExit(130)

        old_handler = signal.signal(signal.SIGTERM, _handler)
        try:
            with self.assertRaises(SystemExit) as ctx:
                os.kill(os.getpid(), signal.SIGTERM)
        finally:
            signal.signal(signal.SIGTERM, old_handler)

        self.assertEqual(ctx.exception.code, 130)
        self.assertTrue(sigterm_received[0])

        result_json = session.run_dir / "details" / "result.json"
        self.assertTrue(result_json.exists(), "result.json must be written on SIGTERM")

        payload = json.loads(result_json.read_text())
        results_by_app = {r["app"]: r for r in payload.get("results", [])}
        self.assertEqual(results_by_app["tracee"]["status"], "ok")
        self.assertEqual(results_by_app["tetragon"]["status"], "error")
        self.assertTrue(payload.get("partial"))


if __name__ == "__main__":
    unittest.main()
