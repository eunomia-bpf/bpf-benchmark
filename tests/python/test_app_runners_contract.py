from __future__ import annotations

import sys
from pathlib import Path
from types import ModuleType

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs.app_runners import AppRunner, get_app_runner
import runner.libs.app_runners as app_runners
from runner.libs.workload import WorkloadResult


class _GoodRunner(AppRunner):
    def __init__(self, **kwargs: object) -> None:
        super().__init__()
        self.kwargs = kwargs

    def start(self) -> list[int]:
        return []

    def run_workload(self, seconds: float) -> WorkloadResult:
        return WorkloadResult(ops_total=0.0, ops_per_sec=0.0, duration_s=float(seconds), stdout="", stderr="")

    def stop(self) -> None:
        return None


class _BadRunner:
    def __init__(self, **kwargs: object) -> None:
        self.kwargs = kwargs


def _install_fake_module(monkeypatch: pytest.MonkeyPatch) -> str:
    module_name = "tests.python._fake_app_runner_module"
    module = ModuleType(module_name)
    module.GoodRunner = _GoodRunner
    module.BadRunner = _BadRunner
    monkeypatch.setitem(sys.modules, module_name, module)
    return module_name


def test_get_app_runner_returns_explicit_app_runner(monkeypatch: pytest.MonkeyPatch) -> None:
    module_name = _install_fake_module(monkeypatch)
    monkeypatch.setitem(app_runners._RUNNERS, "good", (module_name, "GoodRunner", lambda workload, app_name, kwargs: dict(kwargs)))

    runner = get_app_runner("good", marker="demo")

    assert isinstance(runner, AppRunner)
    assert isinstance(runner, _GoodRunner)
    assert runner.kwargs == {"marker": "demo"}


def test_get_app_runner_rejects_non_app_runner_classes(monkeypatch: pytest.MonkeyPatch) -> None:
    module_name = _install_fake_module(monkeypatch)
    monkeypatch.setitem(app_runners._RUNNERS, "bad", (module_name, "BadRunner", lambda workload, app_name, kwargs: dict(kwargs)))

    with pytest.raises(TypeError, match="must inherit AppRunner"):
        get_app_runner("bad")
