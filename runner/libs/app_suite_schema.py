from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Mapping

import yaml


@dataclass(frozen=True, slots=True)
class AppSpec:
    name: str
    runner: str
    workload: str
    args: dict[str, object] = field(default_factory=dict)


@dataclass(frozen=True, slots=True)
class AppSuite:
    manifest_path: Path
    suite_name: str
    schema_version: int
    defaults: dict[str, object]
    apps: tuple[AppSpec, ...]


def _string_required(value: Any, *, field_name: str) -> str:
    text = str(value or "").strip()
    if not text:
        raise SystemExit(f"invalid app suite field: {field_name} is required")
    return text


def _mapping(value: Any, *, field_name: str) -> dict[str, object]:
    if value is None:
        return {}
    if not isinstance(value, Mapping):
        raise SystemExit(f"invalid app suite field: {field_name} must be a mapping")
    return {str(key): item for key, item in value.items()}


def _matches_filter(app: AppSpec, lowered_filters: list[str]) -> bool:
    if not lowered_filters:
        return True
    haystacks = [
        app.name.lower(),
        app.runner.lower(),
        app.workload.lower(),
        " ".join(f"{key}={value}" for key, value in sorted(app.args.items())).lower(),
    ]
    return any(any(needle in haystack for haystack in haystacks) for needle in lowered_filters)


def load_app_suite_from_yaml(
    yaml_path: Path,
    *,
    filters: list[str] | None = None,
    max_apps: int | None = None,
) -> tuple[AppSuite, dict[str, object]]:
    manifest = yaml.safe_load(yaml_path.read_text(encoding="utf-8"))
    if not isinstance(manifest, Mapping):
        raise SystemExit(f"app suite YAML root must be a mapping: {yaml_path}")

    schema_version = int(manifest.get("schema_version", 0) or 0)
    if schema_version != 1:
        raise SystemExit(f"app suite YAML must use schema_version: 1: {yaml_path}")

    raw_apps = manifest.get("apps")
    if not isinstance(raw_apps, list) or not raw_apps:
        raise SystemExit(f"app suite YAML field 'apps' must be a non-empty sequence: {yaml_path}")

    defaults = _mapping(manifest.get("defaults"), field_name="defaults")
    suite_name = str(manifest.get("suite_name") or yaml_path.stem).strip() or yaml_path.stem

    apps: list[AppSpec] = []
    seen_names: set[str] = set()
    for index, raw_app in enumerate(raw_apps, start=1):
        if not isinstance(raw_app, Mapping):
            raise SystemExit(f"invalid app suite field: apps[{index}] must be a mapping")
        app = AppSpec(
            name=_string_required(raw_app.get("name"), field_name=f"apps[{index}].name"),
            runner=_string_required(raw_app.get("runner"), field_name=f"apps[{index}].runner"),
            workload=_string_required(raw_app.get("workload"), field_name=f"apps[{index}].workload"),
            args=_mapping(raw_app.get("args"), field_name=f"apps[{index}].args"),
        )
        if app.name in seen_names:
            raise SystemExit(f"invalid app suite field: duplicate app name {app.name!r}")
        seen_names.add(app.name)
        apps.append(app)

    lowered_filters = [item.lower() for item in filters or []]
    selected_apps = [app for app in apps if _matches_filter(app, lowered_filters)]
    if max_apps is not None:
        selected_apps = selected_apps[: max(0, int(max_apps))]

    suite = AppSuite(
        manifest_path=yaml_path,
        suite_name=suite_name,
        schema_version=schema_version,
        defaults=defaults,
        apps=tuple(selected_apps),
    )
    summary = {
        "manifest": str(yaml_path),
        "schema_version": schema_version,
        "suite_name": suite_name,
        "total_apps": len(apps),
        "selected_apps": len(selected_apps),
    }
    return suite, summary


__all__ = [
    "AppSpec",
    "AppSuite",
    "load_app_suite_from_yaml",
]
