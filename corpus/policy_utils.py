from __future__ import annotations

from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parent.parent
CORPUS_DIR = ROOT_DIR / "corpus"
POLICY_DIR = CORPUS_DIR / "policies"
OBJECT_ROOT_NAMES = ("build", "expanded_corpus", "objects")


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


def legacy_flat_policy_path(object_path: Path, policy_dir: Path = POLICY_DIR) -> Path:
    return policy_dir / f"{object_path.name}.policy.yaml"


def resolve_policy_path(object_path: Path, policy_dir: Path = POLICY_DIR) -> Path | None:
    mirrored = policy_path_for_object(object_path, policy_dir)
    if mirrored.exists():
        return mirrored
    flat = legacy_flat_policy_path(object_path, policy_dir)
    if flat.exists():
        return flat
    return None


__all__ = [
    "CORPUS_DIR",
    "OBJECT_ROOT_NAMES",
    "POLICY_DIR",
    "ROOT_DIR",
    "legacy_flat_policy_path",
    "object_relative_path",
    "object_roots",
    "policy_path_for_object",
    "resolve_policy_path",
]
