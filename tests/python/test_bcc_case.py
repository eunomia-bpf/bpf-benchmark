from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from e2e.cases.bcc import case


def test_load_config_parses_tool_specific_rejit_pass_overrides(tmp_path: Path) -> None:
    config_path = tmp_path / "bcc-config.yaml"
    config_path.write_text(
        """
tools:
  - name: execsnoop
    description: exec tracing
    expected_programs: 2
    workload_kind: exec_loop
    spawn_timeout_s: 15
    tool_args: ["-T"]
    rejit_passes: ["map_inline"]
measurement_duration_s: 30
smoke_duration_s: 10
attach_timeout_s: 20
""".strip()
        + "\n",
        encoding="utf-8",
    )

    config = case.load_config(config_path)

    assert len(config.tools) == 1
    assert config.tools[0].name == "execsnoop"
    assert config.tools[0].rejit_passes == ("map_inline",)
    assert config.tools[0].tool_args == ("-T",)


def test_load_config_defaults_rejit_passes_to_empty_tuple(tmp_path: Path) -> None:
    config_path = tmp_path / "bcc-config.yaml"
    config_path.write_text(
        """
tools:
  - name: tcplife
    description: tcp tracing
    expected_programs: 2
    workload_kind: tcp_connect
    spawn_timeout_s: 15
measurement_duration_s: 30
smoke_duration_s: 10
attach_timeout_s: 20
""".strip()
        + "\n",
        encoding="utf-8",
    )

    config = case.load_config(config_path)

    assert len(config.tools) == 1
    assert config.tools[0].rejit_passes == ()
