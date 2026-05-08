"""Build the daemon `execute_plan` socket payload from per-pass YAML config.

Each pass declares its daemon step in `runner/config/passes/<pass>/default.yaml`;
optional per-app overrides live at `runner/config/passes/<pass>/<app>.yaml`
with a `programs` map keyed by prog_name (and `default` fallback). YAML is the
single source of truth — runner never queries `bpfopt list-passes`. Drift
between yaml and bpfopt CLI is caught offline by `analysis/validate_pass_configs.py`.

Lookup (no merge — first match wins):
  1. <pass>/<app>.yaml -> programs[<prog_name>]
  2. <pass>/<app>.yaml -> programs.default
  3. <pass>/default.yaml -> top-level command

Per-pass yaml's `log_level` is the *input* level the pass needs (predecessor's
rejit must produce at least this verifier-log verbosity). The runner sets each
step's outgoing daemon `log_level` to the next step's input requirement.
"""
from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping, Sequence

import yaml

CONFIG_ROOT = Path(__file__).resolve().parents[1] / "config" / "passes"


@dataclass(frozen=True)
class StepConfig:
    command: str        # multi-line yaml block collapsed to single shell line
    log_level: int      # 1 or 2 — predecessor must rejit at this level
    kinsns: tuple[tuple[str, tuple[str, ...]], ...]
    """((json_name, (alias,...)),) — daemon target.json kinsn probes."""


def _load(path: Path) -> Mapping[str, Any]:
    with open(path) as fh:
        return yaml.safe_load(fh)


def _collapse(s: object) -> str:
    return " ".join(str(s).split())


def _kinsns(payload: Mapping[str, Any]) -> tuple[tuple[str, tuple[str, ...]], ...]:
    return tuple(sorted(
        (str(k["name"]), tuple(sorted(str(a) for a in k["aliases"])))
        for k in (payload.get("kinsns") or [])
    ))


def find_step_config(
    pass_name: str, app_name: str | None, prog_name: str | None,
) -> StepConfig:
    pass_dir = CONFIG_ROOT / pass_name
    default = _load(pass_dir / "default.yaml")
    kinsns = _kinsns(default)

    if app_name is not None:
        app_path = pass_dir / f"{app_name}.yaml"
        if app_path.is_file():
            override = _load(app_path)
            programs = override["programs"]
            entry = programs.get(prog_name) if prog_name else None
            if entry is None:
                if "default" not in programs:
                    raise RuntimeError(
                        f"{app_path}: programs.{prog_name!r} not found and "
                        f"programs.default fallback is missing — every app "
                        f"override yaml must list every prog explicitly or "
                        f"provide a default"
                    )
                entry = programs["default"]
            return StepConfig(
                command=_collapse(entry["command"]),
                log_level=int(override["log_level"]),
                kinsns=kinsns,
            )

    return StepConfig(
        command=_collapse(default["command"]),
        log_level=int(default["log_level"]),
        kinsns=kinsns,
    )


def build_kinsn_probes(enabled_passes: Sequence[str]) -> list[dict[str, Any]]:
    """Union of kinsn probes across the chosen passes (read from default.yaml)."""
    by_name: dict[str, set[str]] = {}
    for pass_name in enabled_passes:
        for json_name, aliases in find_step_config(pass_name, None, None).kinsns:
            by_name.setdefault(json_name, set()).update(aliases)
    return [
        {"name": n, "aliases": sorted(a)}
        for n, a in sorted(by_name.items())
    ]


def build_execute_plan_payload(
    prog_ids: Sequence[int],
    enabled_passes: Sequence[str],
    *,
    app_name: str | None = None,
    prog_names_by_id: Mapping[int, str] | None = None,
) -> dict[str, Any]:
    """Per-prog steps with command/log_level resolved from yaml.

    `step.log_level` (daemon-side rejit verbosity *after* this step's bytecode
    lands) = next step's declared input requirement, or 1 for the last step.
    """
    if not prog_ids:
        raise ValueError("execute_plan requires at least one prog_id")
    passes = [str(p).strip() for p in enabled_passes if str(p).strip()]
    if not passes:
        raise ValueError("execute_plan requires at least one pass")

    programs: list[dict[str, Any]] = []
    for pid in prog_ids:
        prog_name = prog_names_by_id.get(int(pid)) if prog_names_by_id else None
        configs = [find_step_config(p, app_name, prog_name) for p in passes]
        steps = [
            {
                "name": p,
                "command": cfg.command,
                "log_level": int(configs[i + 1].log_level if i + 1 < len(configs) else 1),
            }
            for i, (p, cfg) in enumerate(zip(passes, configs))
        ]
        programs.append({"prog_id": int(pid), "steps": steps})

    return {
        "cmd": "execute_plan",
        "programs": programs,
        "kinsn_probes": build_kinsn_probes(passes),
    }
