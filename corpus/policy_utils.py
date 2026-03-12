from __future__ import annotations

import re
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Mapping

import yaml

ROOT_DIR = Path(__file__).resolve().parent.parent
CORPUS_DIR = ROOT_DIR / "corpus"
POLICY_DIR = CORPUS_DIR / "policies"
OBJECT_ROOT_NAMES = ("build", "expanded_corpus", "objects")
PROGRAM_SAFE_CHARS = re.compile(r"[^A-Za-z0-9._-]+")
VALID_POLICY_ACTIONS = {"apply", "skip"}


@dataclass(frozen=True, slots=True)
class PolicySiteV2:
    insn: int
    family: str
    action: str


@dataclass(frozen=True, slots=True)
class PolicyDocumentV2:
    version: int
    program: str | None
    default: str
    sites: tuple[PolicySiteV2, ...]


def object_roots(corpus_dir: Path = CORPUS_DIR) -> tuple[Path, ...]:
    return tuple((corpus_dir / name).resolve() for name in OBJECT_ROOT_NAMES if (corpus_dir / name).exists())


def object_relative_path(object_path: Path, corpus_dir: Path = CORPUS_DIR) -> Path:
    resolved = object_path.resolve()
    for root in object_roots(corpus_dir):
        try:
            return resolved.relative_to(root)
        except ValueError:
            continue
    try:
        return resolved.relative_to(corpus_dir.resolve())
    except ValueError:
        return Path(resolved.name)


def policy_path_for_object(object_path: Path, policy_dir: Path = POLICY_DIR) -> Path:
    relative = object_relative_path(object_path)
    return policy_dir / relative.parent / f"{relative.name}.policy.yaml"


def object_policy_stem(object_path: Path) -> str:
    name = object_relative_path(object_path).name
    if name.endswith(".bpf.o"):
        return name[:-len(".bpf.o")]
    return Path(name).stem


def sanitize_program_name(program_name: str) -> str:
    sanitized = PROGRAM_SAFE_CHARS.sub("_", program_name.strip())
    sanitized = sanitized.strip("._")
    return sanitized or "unnamed-program"


def program_policy_dir(object_path: Path, policy_dir: Path = POLICY_DIR) -> Path:
    relative = object_relative_path(object_path)
    return policy_dir / relative.parent / object_policy_stem(object_path)


def policy_path_for_program(
    object_path: Path,
    program_name: str,
    policy_dir: Path = POLICY_DIR,
) -> Path:
    return program_policy_dir(object_path, policy_dir) / f"{sanitize_program_name(program_name)}.policy.yaml"


def legacy_flat_policy_path(object_path: Path, policy_dir: Path = POLICY_DIR) -> Path:
    return policy_dir / f"{object_path.name}.policy.yaml"


def resolve_policy_path(
    object_path: Path,
    policy_dir: Path = POLICY_DIR,
    program_name: str | None = None,
) -> Path | None:
    if program_name:
        per_program = policy_path_for_program(object_path, program_name, policy_dir)
        if per_program.exists():
            return per_program
    mirrored = policy_path_for_object(object_path, policy_dir)
    if mirrored.exists():
        return mirrored
    flat = legacy_flat_policy_path(object_path, policy_dir)
    if flat.exists():
        return flat
    return None


def _load_policy_payload(policy: Path | str | Mapping[str, Any]) -> Mapping[str, Any]:
    if isinstance(policy, Mapping):
        return policy
    if isinstance(policy, Path):
        loaded = yaml.safe_load(policy.read_text())
    else:
        candidate = Path(policy)
        if "\n" not in policy and candidate.exists():
            loaded = yaml.safe_load(candidate.read_text())
        else:
            loaded = yaml.safe_load(policy)
    if not isinstance(loaded, Mapping):
        raise ValueError("policy document must be a mapping")
    return loaded


def parse_policy_v2(policy: Path | str | Mapping[str, Any]) -> PolicyDocumentV2:
    payload = _load_policy_payload(policy)
    version = int(payload.get("version", 0) or 0)
    if version != 2:
        raise ValueError(f"expected version 2 policy, got {version}")

    default = str(payload.get("default", "")).strip().lower()
    if default not in VALID_POLICY_ACTIONS:
        raise ValueError("policy default must be 'apply' or 'skip'")

    raw_sites = payload.get("sites")
    if raw_sites is None:
        raise ValueError("version 2 policy requires a sites list")
    if not isinstance(raw_sites, list):
        raise ValueError("policy sites must be a list")

    sites: list[PolicySiteV2] = []
    for entry in raw_sites:
        if not isinstance(entry, Mapping):
            raise ValueError("policy sites entries must be mappings")
        insn = int(entry.get("insn", -1))
        family = str(entry.get("family", "")).strip()
        action = str(entry.get("action", "")).strip().lower()
        if insn < 0:
            raise ValueError("policy site insn must be >= 0")
        if not family:
            raise ValueError("policy site family is required")
        if action not in VALID_POLICY_ACTIONS:
            raise ValueError("policy site action must be 'apply' or 'skip'")
        sites.append(PolicySiteV2(insn=insn, family=family, action=action))

    program_value = payload.get("program")
    program = None if program_value is None else str(program_value)
    return PolicyDocumentV2(
        version=2,
        program=program,
        default=default,
        sites=tuple(sites),
    )


def generate_default_policy_v2(
    scanner_binary: Path | str,
    object_path: Path | str,
    *,
    program_name: str | None = None,
    default: str = "skip",
    output_path: Path | str | None = None,
    timeout_seconds: int = 60,
) -> str:
    normalized_default = default.strip().lower()
    if normalized_default not in VALID_POLICY_ACTIONS:
        raise ValueError("default must be 'apply' or 'skip'")

    command = [
        str(Path(scanner_binary).resolve()),
        "generate-policy",
        str(Path(object_path).resolve()),
        "--default",
        normalized_default,
    ]
    if program_name:
        command.extend(["--program-name", program_name])
    if output_path is not None:
        resolved_output = Path(output_path).resolve()
        resolved_output.parent.mkdir(parents=True, exist_ok=True)
        command.extend(["--output", str(resolved_output)])

    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        check=False,
        timeout=timeout_seconds,
    )
    if completed.returncode != 0:
        message = (completed.stderr or completed.stdout).strip()
        raise RuntimeError(message or "scanner generate-policy failed")

    if output_path is not None:
        return Path(output_path).resolve().read_text()
    return completed.stdout


__all__ = [
    "CORPUS_DIR",
    "OBJECT_ROOT_NAMES",
    "POLICY_DIR",
    "ROOT_DIR",
    "legacy_flat_policy_path",
    "object_relative_path",
    "object_roots",
    "object_policy_stem",
    "policy_path_for_object",
    "policy_path_for_program",
    "program_policy_dir",
    "PolicyDocumentV2",
    "PolicySiteV2",
    "generate_default_policy_v2",
    "parse_policy_v2",
    "resolve_policy_path",
    "sanitize_program_name",
]
