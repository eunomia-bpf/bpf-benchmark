from __future__ import annotations

import inspect
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from e2e.cases.katran.case import build_parser
from runner.libs.app_runners.katran import KatranRunner


def test_katran_runner_constructor_is_loader_centric() -> None:
    parameters = inspect.signature(KatranRunner).parameters

    assert "loader_binary" in parameters
    assert "object_path" not in parameters
    assert "program_name" not in parameters
    assert "bpftool" not in parameters


def test_katran_case_parser_drops_object_level_flags() -> None:
    parser = build_parser()
    option_strings = {option for action in parser._actions for option in action.option_strings}

    assert "--object-path" not in option_strings
    assert "--program-name" not in option_strings
    assert "--bpftool" not in option_strings
