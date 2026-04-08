from __future__ import annotations

from pathlib import Path

from runner.libs import state_file


def test_state_file_round_trips_strings(tmp_path: Path) -> None:
    path = tmp_path / "state.json"
    state_file.write_state(path, {"RUN_BUNDLE_TAR": "/tmp/bundle.tar.gz", "STATE_REGION": "us-east-1"})

    assert state_file.read_state(path) == {
        "RUN_BUNDLE_TAR": "/tmp/bundle.tar.gz",
        "STATE_REGION": "us-east-1",
    }


def test_state_file_export_renders_shell_assignments(tmp_path: Path) -> None:
    path = tmp_path / "state.json"
    state_file.write_state(path, {"RUN_BUNDLE_TAR": "/tmp/with space.tar.gz"})

    rendered = state_file.render_shell_assignments(path)

    assert "RUN_BUNDLE_TAR='/tmp/with space.tar.gz'" in rendered
