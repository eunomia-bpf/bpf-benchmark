from __future__ import annotations

import os
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Mapping, Sequence

import yaml


REPO_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_MICRO_MANIFEST = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"


def _manifest_root(path: Path) -> Path:
    try:
        path.relative_to(REPO_ROOT)
    except ValueError:
        return path.parent.parent
    return REPO_ROOT


def _resolve_path(value: str | Path | None, root_dir: Path) -> Path | None:
    if value is None:
        return None
    path = Path(value)
    if path.is_absolute():
        return path
    return (root_dir / path).resolve()


@dataclass(frozen=True, slots=True)
class CatalogRuntime:
    name: str
    default_inner_repeat: int | None = None


@dataclass(frozen=True, slots=True)
class DefaultsSpec:
    samples: int | None = None
    warmups: int | None = None
    inner_repeat: int | None = None
    runtimes: tuple[str, ...] = ()
    output: Path | None = None


@dataclass(frozen=True, slots=True)
class CatalogTarget:
    name: str
    object_path: Path
    native_object_path: Path | None = None
    proof_object_path: Path | None = None
    proof_compile_metadata_path: Path | None = None
    io_mode: str | None = None
    input_size: int | None = None
    input_generator: str | None = None
    expected_result: int | None = None
    expected_retval: int | None = None
    tags: tuple[str, ...] = ()
    runtime_names: tuple[str, ...] = ()
    metadata: Mapping[str, object] = field(default_factory=dict)

    @property
    def kernel_input_size(self) -> int:
        return int(self.input_size or 0)


@dataclass(frozen=True, slots=True)
class CatalogBuild:
    runner_binary: Path | None = None


@dataclass(frozen=True, slots=True)
class CatalogManifest:
    manifest_path: Path
    suite_name: str
    defaults: DefaultsSpec
    build: CatalogBuild
    runtimes: tuple[CatalogRuntime, ...]
    targets: tuple[CatalogTarget, ...]

    @property
    def targets_by_name(self) -> Mapping[str, CatalogTarget]:
        return {target.name: target for target in self.targets}

    @property
    def benchmarks(self) -> Mapping[str, CatalogTarget]:
        return self.targets_by_name


def _load_runtimes(
    raw_runtimes: Sequence[Mapping[str, Any]],
    *,
    default_inner_repeat: int | None = None,
) -> tuple[CatalogRuntime, ...]:
    runtimes: list[CatalogRuntime] = []
    seen_names: set[str] = set()
    for entry in raw_runtimes:
        name = str(entry["name"])
        if name in seen_names:
            raise ValueError(f"duplicate runtime name: {name}")
        seen_names.add(name)
        runtime = CatalogRuntime(
            name=name,
            default_inner_repeat=(
                int(entry.get("inner_repeat", default_inner_repeat))
                if entry.get("inner_repeat", default_inner_repeat) is not None
                else None
            ),
        )
        runtimes.append(runtime)
    return tuple(runtimes)


def _validate_target_names(targets: list[CatalogTarget]) -> tuple[CatalogTarget, ...]:
    seen: set[str] = set()
    for target in targets:
        if target.name in seen:
            raise ValueError(f"duplicate target name: {target.name}")
        seen.add(target.name)
    return tuple(targets)


def _load_micro_catalog(path: Path, data: Mapping[str, Any]) -> CatalogManifest:
    root_dir = _manifest_root(path)
    defaults_raw = dict(data.get("defaults", {}))
    build_data = dict(data.get("build", {}))
    benchmark_defaults = dict(data.get("benchmark_defaults", {}))
    default_io_mode = str(benchmark_defaults.get("io_mode", "map"))
    program_dir_override = os.environ.get("BPFREJIT_MICRO_PROGRAM_DIR", "").strip()
    runner_binary_override = os.environ.get("BPFREJIT_MICRO_RUNNER_BINARY", "").strip()
    proof_dir_override = os.environ.get("BPFREJIT_MICRO_PROOF_DIR", "").strip()
    program_dir = _resolve_path(program_dir_override or data.get("paths", {}).get("program_dir"), root_dir)
    if program_dir is None:
        raise ValueError("micro manifest missing paths.program_dir")
    proof_dir = _resolve_path(proof_dir_override or data.get("paths", {}).get("proof_dir"), root_dir)

    raw_runtimes = data.get("runtimes")
    if not isinstance(raw_runtimes, Sequence) or not raw_runtimes:
        raise ValueError("micro manifest missing runtimes[]")
    default_inner_repeat = int(defaults_raw["inner_repeat"]) if defaults_raw.get("inner_repeat") is not None else None
    runtimes = _load_runtimes(raw_runtimes, default_inner_repeat=default_inner_repeat)

    targets: list[CatalogTarget] = []
    for benchmark in data.get("benchmarks", []):
        base_name = str(benchmark["base_name"])
        object_path = (program_dir / f"{base_name}.bpf.o").resolve()
        tags = tuple(str(tag) for tag in benchmark.get("tags", ()))
        native_suffix = ".native.o" if "stage2" in tags else ".native.so"
        native_object_path = (program_dir / f"{base_name}{native_suffix}").resolve()
        proof_object_path = None
        proof_compile_metadata_path = None
        if proof_dir is not None:
            proof_object_path = (proof_dir / f"{base_name}.bpf.o").resolve()
            proof_compile_metadata_path = (proof_dir / f"{base_name}.compile.json").resolve()
        runtime_names = tuple(str(runtime) for runtime in benchmark.get("runtimes", ()))
        targets.append(
            CatalogTarget(
                name=str(benchmark["name"]),
                object_path=object_path,
                native_object_path=native_object_path,
                proof_object_path=proof_object_path,
                proof_compile_metadata_path=proof_compile_metadata_path,
                io_mode=str(benchmark.get("io_mode", default_io_mode)),
                input_size=int(benchmark.get("kernel_input_size", 0) or 0),
                input_generator=str(benchmark["input_generator"]) if benchmark.get("input_generator") else None,
                expected_result=int(benchmark["expected_result"]) if benchmark.get("expected_result") is not None else None,
                expected_retval=int(benchmark.get("expected_retval", benchmark_defaults.get("expected_retval", 0))),
                tags=tags,
                runtime_names=runtime_names,
                metadata={
                    "base_name": base_name,
                },
            )
        )

    return CatalogManifest(
        manifest_path=path,
        suite_name=str(data.get("suite_name", path.stem)),
        defaults=DefaultsSpec(
            samples=int(defaults_raw["samples"]) if defaults_raw.get("samples") is not None else None,
            warmups=int(defaults_raw["warmups"]) if defaults_raw.get("warmups") is not None else None,
            inner_repeat=default_inner_repeat,
            runtimes=tuple(str(runtime) for runtime in defaults_raw.get("runtimes", ())),
            output=_resolve_path(defaults_raw.get("output"), root_dir),
        ),
        build=CatalogBuild(
            runner_binary=_resolve_path(runner_binary_override or build_data.get("runner_binary"), root_dir),
        ),
        runtimes=runtimes,
        targets=_validate_target_names(targets),
    )

def load_catalog(path: str | Path) -> CatalogManifest:
    manifest_path = Path(path).resolve()
    data = yaml.safe_load(manifest_path.read_text())
    if not isinstance(data, Mapping):
        raise ValueError(f"manifest is not a mapping: {manifest_path}")

    if "benchmarks" in data:
        return _load_micro_catalog(manifest_path, data)
    raise ValueError(f"unsupported manifest schema: {manifest_path}")


load_manifest = load_catalog


__all__ = [
    "CatalogBuild",
    "CatalogManifest",
    "CatalogRuntime",
    "CatalogTarget",
    "DEFAULT_MICRO_MANIFEST",
    "DefaultsSpec",
    "load_catalog",
    "load_manifest",
]
