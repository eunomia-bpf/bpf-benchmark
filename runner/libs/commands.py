from __future__ import annotations

from pathlib import Path


def build_list_programs_command(runner_binary: Path | str, program: Path | str) -> list[str]:
    return [
        str(runner_binary),
        "list-programs",
        "--program",
        str(program),
    ]


__all__ = [
    "build_list_programs_command",
]
