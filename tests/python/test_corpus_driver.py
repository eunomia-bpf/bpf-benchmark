from __future__ import annotations

import unittest
from types import SimpleNamespace
from unittest import mock

import corpus.driver as corpus_driver
from runner.libs.case_common import CaseLifecycleState, WORKLOAD_MISS_LIMITATION


class _FakeWorkloadResult:
    def __init__(self, call_index: int) -> None:
        self.call_index = call_index

    def to_dict(self) -> dict[str, object]:
        return {"call_index": self.call_index}


class _FakeRunner:
    def __init__(self) -> None:
        self.calls: list[float] = []
        self.programs: list[dict[str, object]] = []

    def run_workload(self, seconds: float) -> _FakeWorkloadResult:
        self.calls.append(seconds)
        return _FakeWorkloadResult(len(self.calls))

    def live_rejit_programs(self) -> list[dict[str, object]]:
        return []


class CorpusDriverTests(unittest.TestCase):
    def test_measure_runner_phase_warms_up_before_recorded_samples(self) -> None:
        runner = _FakeRunner()
        with (
            mock.patch.object(corpus_driver, "sample_bpf_stats", side_effect=[{101: {}}, {101: {}}]),
            mock.patch.object(
                corpus_driver,
                "compute_delta",
                return_value={101: {"run_cnt_delta": 0, "run_time_ns_delta": 0}},
            ),
        ):
            measurement = corpus_driver._measure_runner_phase(
                runner,
                [101],
                workload_seconds=1.5,
                samples=2,
                warmup=True,
            )

        self.assertEqual([1.5, 1.5, 1.5], runner.calls)
        self.assertEqual([{"call_index": 2}, {"call_index": 3}], measurement["workloads"])
        self.assertTrue(measurement["workload_miss"])
        self.assertEqual([WORKLOAD_MISS_LIMITATION], measurement["limitations"])

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

    def test_build_app_result_surfaces_workload_miss_at_top_level(self) -> None:
        app = SimpleNamespace(
            name="demo",
            runner="fake",
            workload_for=lambda _mode: "exec_storm",
        )
        baseline = {"bpf": {101: {"run_cnt_delta": 0, "run_time_ns_delta": 0}}}
        result = corpus_driver._build_app_ok_result(
            app,
            baseline_measurement=baseline,
            apply_result=None,
            rejit_measurement=None,
        )

        self.assertTrue(result["workload_miss"])
        self.assertEqual([WORKLOAD_MISS_LIMITATION], result["limitations"])

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
