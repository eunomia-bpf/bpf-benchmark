from __future__ import annotations

from typing import Mapping, Sequence


def select_configured_programs(
    live_programs: Sequence[Mapping[str, object]],
    config: Mapping[str, object],
    *,
    case_label: str,
    config_key: str = "target_programs",
    allow_all_when_unset: bool = True,
) -> list[dict[str, object]]:
    available_programs = [dict(program) for program in live_programs if isinstance(program, Mapping)]
    requested_names = [
        str(name).strip()
        for name in (config.get(config_key) or [])
        if str(name).strip()
    ]
    if not requested_names:
        return available_programs if allow_all_when_unset else []

    selected: list[dict[str, object]] = []
    missing: list[str] = []
    for requested_name in requested_names:
        matched = False
        for program in available_programs:
            if str(program.get("name") or "") != requested_name:
                continue
            if program not in selected:
                selected.append(dict(program))
            matched = True
        if not matched:
            missing.append(requested_name)
    if missing:
        raise RuntimeError(
            f"configured {config_key} not found in live {case_label} programs: {', '.join(missing)}"
        )
    return selected
