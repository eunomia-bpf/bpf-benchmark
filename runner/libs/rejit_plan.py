"""Build the shim `execute_plan` socket payload from per-pass YAML config.

Each pass declares its shim step in `runner/config/passes/<pass>/default.yaml`;
optional per-app overrides live at `runner/config/passes/<pass>/<app>.yaml`
with a `programs` map keyed by prog_name (and `default` fallback). YAML is the
single source of truth; runner never queries bpfopt for pass metadata.

Lookup (no merge; first match is selected):
  1. <pass>/<app>.yaml -> programs[<prog_name>]
  2. <pass>/<app>.yaml -> programs.default
  3. <pass>/default.yaml -> top-level command

Per-pass yaml's `log_level` is the *input* level the pass needs (predecessor's
rejit must produce at least this verifier-log verbosity). The runner sets each
step's outgoing daemon `log_level` to the next step's input requirement.
"""
from __future__ import annotations

from pathlib import Path
from typing import Any, Mapping, Sequence

import yaml

CONFIG_ROOT = Path(__file__).resolve().parents[1] / "config" / "passes"


def _load(path: Path) -> Mapping[str, Any]:
    with open(path) as fh:
        return yaml.safe_load(fh)


def _collapse(s: object) -> str:
    return " ".join(str(s).split())


def _command_key_for_prog(prog_name: str) -> str:
    sanitized = "".join(
        c if c.isalnum() or c == "_" else "_" for c in str(prog_name).strip()
    )
    return f"command_{sanitized}"


def find_step_payload(pass_name: str, app_name: str | None) -> dict[str, Any]:
    pass_dir = CONFIG_ROOT / pass_name
    default = _load(pass_dir / "default.yaml")
    command = _collapse(default["command"])
    log_level = int(default["log_level"])
    payload: dict[str, Any] = {"command": command, "log_level": log_level}

    if app_name is None:
        return payload
    app_path = pass_dir / f"{app_name}.yaml"
    if not app_path.is_file():
        return payload

    override = _load(app_path)
    log_level = int(override["log_level"])
    programs = override["programs"]
    if "default" in programs:
        payload["command"] = _collapse(programs["default"]["command"])
    payload["log_level"] = log_level
    for prog_name, entry in programs.items():
        if str(prog_name) == "default":
            continue
        collapsed = _collapse(entry["command"])
        names = {str(prog_name), str(prog_name)[:15]}
        for name in names:
            payload[_command_key_for_prog(name)] = collapsed
    return payload


def build_execute_all_payload(
    enabled_passes: Sequence[str],
    *,
    app_name: str | None = None,
) -> dict[str, Any]:
    passes = [str(p).strip() for p in enabled_passes if str(p).strip()]
    if not passes:
        raise ValueError("execute_plan requires at least one pass")

    configs = [find_step_payload(p, app_name) for p in passes]
    steps: list[dict[str, Any]] = []
    for i, (pass_name, cfg) in enumerate(zip(passes, configs)):
        step = dict(cfg)
        step["name"] = pass_name
        step["log_level"] = int(
            configs[i + 1]["log_level"] if i + 1 < len(configs) else 1
        )
        steps.append(step)
    return {
        "cmd": "execute_plan",
        "steps": steps,
    }
