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

    def test_refresh_active_session_programs_rejects_partial_rediscovery(self) -> None:
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
        with (
            mock.patch.object(corpus_driver, "programs_after", return_value=[]),
            mock.patch.object(
                corpus_driver,
                "_runner_rediscovered_programs",
                return_value=(rediscovered, "runner.refresh_programs"),
            ),
        ):
            with self.assertRaisesRegex(
                RuntimeError,
                r"rediscovery returned fewer programs than expected: 1/2",
            ):
                corpus_driver._refresh_active_session_programs([session], "baseline")

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


if __name__ == "__main__":
    unittest.main()
