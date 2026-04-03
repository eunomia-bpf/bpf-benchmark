from __future__ import annotations

import re
from pathlib import Path

import yaml


ROOT_DIR = Path(__file__).resolve().parents[2]
MACRO_APPS_PATH = ROOT_DIR / "corpus" / "config" / "macro_apps.yaml"
ROOT_MAKEFILE = ROOT_DIR / "Makefile"
RUNNER_MAKEFILE = ROOT_DIR / "runner" / "Makefile"


def _extract_make_int(path: Path, variable: str) -> int:
    match = re.search(rf"^{re.escape(variable)}\s*\?=\s*(\d+)\s*$", path.read_text(encoding="utf-8"), re.MULTILINE)
    assert match is not None, f"{path} does not define {variable}"
    return int(match.group(1))


def test_vm_corpus_defaults_fit_runtime_budget() -> None:
    manifest = yaml.safe_load(MACRO_APPS_PATH.read_text(encoding="utf-8"))
    defaults = dict(manifest.get("defaults") or {})
    apps = list(manifest.get("apps") or [])
    suite_default_duration = float(defaults["duration_s"])
    suite_samples = int(defaults["samples"])
    root_make_samples = _extract_make_int(ROOT_MAKEFILE, "VM_CORPUS_SAMPLES")
    runner_make_samples = _extract_make_int(RUNNER_MAKEFILE, "VM_CORPUS_SAMPLES")
    runner_timeout = _extract_make_int(RUNNER_MAKEFILE, "VM_CORPUS_TIMEOUT")

    assert suite_samples == 30
    assert root_make_samples == suite_samples
    assert runner_make_samples == suite_samples

    per_phase_seconds = sum(float(app.get("duration_s", suite_default_duration)) for app in apps)
    baseline_and_rejit_lower_bound = per_phase_seconds * suite_samples * 2.0

    # Leave headroom for app setup/teardown, daemon apply, and guest boot overhead.
    assert baseline_and_rejit_lower_bound < (runner_timeout / 3.0)
