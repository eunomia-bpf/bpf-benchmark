from __future__ import annotations

import unittest
from types import SimpleNamespace
from unittest import mock

import corpus.driver as corpus_driver
from runner.libs.case_common import CaseLifecycleState


class _FakeRunner:
    def __init__(self) -> None:
        self.programs: list[dict[str, object]] = []

    def live_rejit_programs(self) -> list[dict[str, object]]:
        return []


class CorpusDriverTests(unittest.TestCase):
    def test_refresh_active_session_programs_accepts_partial_rediscovery(self) -> None:
        runner = _FakeRunner()
        expected_programs = [
            {"id": 101, "name": "prog-a", "type": "tracepoint"},
            {"id": 102, "name": "prog-b", "type": "tracepoint"},
        ]
        state = CaseLifecycleState(
            runtime=runner,
            prog_ids=[101, 102],
            artifacts={"programs": expected_programs},
        )
        session = corpus_driver.CorpusAppSession(
            app=SimpleNamespace(name="demo", runner="fake"),
            runner=runner,
            state=state,
            workload_seconds=1.0,
        )

        rediscovered = [{"id": 201, "name": "prog-a", "type": "tracepoint"}]
        runner.refresh_programs = mock.Mock(return_value=rediscovered)
        with (
            mock.patch.object(corpus_driver, "programs_after", return_value=[]),
            mock.patch.object(corpus_driver, "_print_progress") as print_progress,
        ):
            corpus_driver._refresh_active_session_programs([session], "baseline")

        runner.refresh_programs.assert_called_once_with()
        self.assertEqual([201], session.state.prog_ids)
        self.assertEqual(rediscovered, session.state.artifacts["programs"])
        self.assertEqual(rediscovered, runner.programs)
        self.assertEqual(
            [
                mock.call(
                    "session_warning",
                    app="demo",
                    runner="fake",
                    phase="baseline",
                    warning="rediscovery returned fewer programs than expected: 1/2; accepting partial set",
                    missing_ids=[101, 102],
                    refreshed_ids=[201],
                    discover_source="runner.refresh_programs",
                ),
                mock.call(
                    "session_warning",
                    app="demo",
                    runner="fake",
                    phase="baseline",
                    warning="tracked BPF program ids changed; refreshed live session programs",
                    previous_ids=[101, 102],
                    missing_ids=[101, 102],
                    refreshed_ids=[201],
                    expected_count=2,
                    refreshed_count=1,
                    discover_source="runner.refresh_programs",
                ),
            ],
            print_progress.mock_calls,
        )

    def test_run_suite_lifecycle_sessions_waits_for_quiescence_after_baseline_failure(self) -> None:
        runner = mock.Mock()
        state = CaseLifecycleState(
            runtime=runner,
            prog_ids=[101],
            artifacts={"programs": [{"id": 101}]},
        )
        session = corpus_driver.CorpusAppSession(
            app=SimpleNamespace(name="demo", runner="fake"),
            runner=runner,
            state=state,
            workload_seconds=1.0,
        )
        prepared_daemon_session = SimpleNamespace(
            session=SimpleNamespace(
                proc=SimpleNamespace(poll=mock.Mock(return_value=None)),
                apply_rejit=mock.Mock(),
            )
        )

        with (
            mock.patch.object(corpus_driver, "_refresh_active_session_programs"),
            mock.patch.object(corpus_driver, "_measure_runner_phase", side_effect=RuntimeError("baseline boom")),
            mock.patch.object(corpus_driver, "wait_for_suite_quiescence") as wait_for_suite_quiescence,
            mock.patch.object(corpus_driver, "_print_progress"),
        ):
            results, fatal_error = corpus_driver._run_suite_lifecycle_sessions(
                prepared_daemon_session,
                [session],
                samples=1,
            )

        self.assertEqual("", fatal_error)
        self.assertEqual("baseline boom", results[0].error)
        self.assertTrue(results[0].stopped)
        runner.stop.assert_called_once_with()
        wait_for_suite_quiescence.assert_called_once_with()
        prepared_daemon_session.session.apply_rejit.assert_not_called()


if __name__ == "__main__":
    unittest.main()
