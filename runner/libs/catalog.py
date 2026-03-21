from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Mapping, Sequence

import yaml


REPO_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_MICRO_MANIFEST = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"
DEFAULT_MACRO_MANIFEST = REPO_ROOT / "corpus" / "config" / "macro_corpus.yaml"


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


def _policy_mode_for_runtime(name: str, mode: str) -> str:
    text = f"{name} {mode}".lower()
    if "recompile" in text and "v5" in text:
        return "recompile_v5"
    if "recompile" in text:
        return "recompile_v4"
    if "directive" in text:
        return "directive_blob"
    if "policy" in text:
        return "policy_blob"
    return "stock"


def _backend_for_runtime(mode: str) -> str:
    return "llvmbpf" if "llvmbpf" in mode else "kernel"


@dataclass(frozen=True, slots=True)
class CatalogRuntime:
    name: str
    label: str
    mode: str
    backend: str
    policy_mode: str
    transport: str = "local"
    aliases: tuple[str, ...] = ()


@dataclass(frozen=True, slots=True)
class AnalysisSpec:
    baseline_benchmark: str | None = None


@dataclass(frozen=True, slots=True)
class DimensionSummary:
    counts: Mapping[str, int]


@dataclass(frozen=True, slots=True)
class DefaultsSpec:
    iterations: int | None = None
    warmups: int | None = None
    repeat: int | None = None
    runtimes: tuple[str, ...] = ()
    output: Path | None = None
    raw: Mapping[str, object] = field(default_factory=dict)

    def get(self, key: str, default: object = None) -> object:
        if hasattr(self, key):
            value = getattr(self, key)
            return default if value is None else value
        return self.raw.get(key, default)


@dataclass(frozen=True, slots=True)
class CorpusSpec:
    manifest: Path | None = None
    local_repos: Path | None = None
    inventory: Path | None = None


@dataclass(frozen=True, slots=True)
class CatalogTarget:
    name: str
    description: str
    kind: str
    object_path: Path
    program_names: tuple[str, ...] = ()
    sections: tuple[str, ...] = ()
    prog_type: str | None = None
    io_mode: str | None = None
    input_size: int | None = None
    input_path: Path | None = None
    input_generator: str | None = None
    expected_result: int | None = None
    test_method: str | None = None
    trigger: str | None = None
    trigger_timeout_seconds: int | None = None
    compile_loader: str | None = None
    category: str | None = None
    family: str | None = None
    level: str | None = None
    hypothesis: str | None = None
    tags: tuple[str, ...] = ()
    backends: tuple[str, ...] = ()
    policy_modes: tuple[str, ...] = ()
    transports: tuple[str, ...] = ()
    metadata: Mapping[str, object] = field(default_factory=dict)


@dataclass(frozen=True, slots=True)
class CatalogBuild:
    commands: Mapping[str, tuple[str, ...]]
    runner_binary: Path | None = None
    scanner_binary: Path | None = None
    bpftool_binary: str | Path | None = None


@dataclass(frozen=True, slots=True)
class CatalogManifest:
    manifest_path: Path
    manifest_kind: str
    schema_version: int
    suite_name: str
    defaults: DefaultsSpec
    build: CatalogBuild
    runtimes: tuple[CatalogRuntime, ...]
    targets: tuple[CatalogTarget, ...]
    runtime_aliases: Mapping[str, str]
    corpus: CorpusSpec | None = None
    metadata: Mapping[str, object] = field(default_factory=dict)

    @property
    def target_count(self) -> int:
        return len(self.targets)

    @property
    def targets_by_name(self) -> Mapping[str, CatalogTarget]:
        return {target.name: target for target in self.targets}

    @property
    def analysis(self) -> AnalysisSpec:
        analysis = self.metadata.get("analysis")
        if isinstance(analysis, Mapping):
            return AnalysisSpec(baseline_benchmark=str(analysis.get("baseline_benchmark")) if analysis.get("baseline_benchmark") else None)
        return AnalysisSpec()

    @property
    def categories(self) -> tuple[str, ...]:
        return tuple(dict.fromkeys(target.category for target in self.targets if target.category))

    @property
    def families(self) -> tuple[str, ...]:
        return tuple(dict.fromkeys(target.family for target in self.targets if target.family))

    @property
    def dimensions(self) -> Mapping[str, DimensionSummary]:
        def summarize(values: Sequence[str | None]) -> DimensionSummary:
            counts: dict[str, int] = {}
            for value in values:
                if not value:
                    continue
                counts[value] = counts.get(value, 0) + 1
            return DimensionSummary(counts=counts)

        runtime_backends = [runtime.backend for runtime in self.runtimes]
        runtime_policy_modes = [runtime.policy_mode for runtime in self.runtimes]
        runtime_transports = [runtime.transport for runtime in self.runtimes]
        return {
            "category": summarize([target.category for target in self.targets]),
            "family": summarize([target.family for target in self.targets]),
            "level": summarize([target.level for target in self.targets]),
            "kind": summarize([target.kind for target in self.targets]),
            "prog_type": summarize([target.prog_type for target in self.targets]),
            "test_method": summarize([target.test_method for target in self.targets]),
            "backend": summarize(runtime_backends),
            "policy_mode": summarize(runtime_policy_modes),
            "transport": summarize(runtime_transports),
        }


def _normalize_commands(raw_commands: Mapping[str, Sequence[str]] | None) -> dict[str, tuple[str, ...]]:
    if not raw_commands:
        return {}
    return {str(name): tuple(str(token) for token in command) for name, command in raw_commands.items()}


def _load_runtimes(raw_runtimes: Sequence[Mapping[str, Any]]) -> tuple[tuple[CatalogRuntime, ...], dict[str, str]]:
    runtimes: list[CatalogRuntime] = []
    aliases: dict[str, str] = {}
    seen_names: set[str] = set()
    for entry in raw_runtimes:
        name = str(entry["name"])
        if name in seen_names:
            raise ValueError(f"duplicate runtime name: {name}")
        seen_names.add(name)
        mode = str(entry.get("mode", name))
        runtime = CatalogRuntime(
            name=name,
            label=str(entry.get("label", name)),
            mode=mode,
            backend=_backend_for_runtime(mode),
            policy_mode=_policy_mode_for_runtime(name, mode),
            transport=str(entry.get("transport", "local")),
            aliases=tuple(str(alias) for alias in entry.get("aliases", ())),
        )
        runtimes.append(runtime)
        for alias in runtime.aliases:
            if alias in aliases or alias in seen_names:
                raise ValueError(f"runtime alias collision: {alias}")
            aliases[alias] = runtime.name
    return tuple(runtimes), aliases


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
    program_dir = _resolve_path(data.get("paths", {}).get("program_dir"), root_dir)
    if program_dir is None:
        raise ValueError("micro manifest missing paths.program_dir")

    raw_runtimes = data.get("runtimes")
    if not isinstance(raw_runtimes, Sequence) or not raw_runtimes:
        raise ValueError("micro manifest missing runtimes[]")
    runtimes, aliases = _load_runtimes(raw_runtimes)
    runtime_backends = tuple(sorted({runtime.backend for runtime in runtimes}))
    runtime_policy_modes = tuple(sorted({runtime.policy_mode for runtime in runtimes}))
    runtime_transports = tuple(sorted({runtime.transport for runtime in runtimes}))

    targets: list[CatalogTarget] = []
    for benchmark in data.get("benchmarks", []):
        base_name = str(benchmark["base_name"])
        targets.append(
            CatalogTarget(
                name=str(benchmark["name"]),
                description=str(benchmark.get("description", benchmark["name"])),
                kind="micro",
                object_path=(program_dir / f"{base_name}.bpf.o").resolve(),
                program_names=(str(benchmark.get("program_name", f"{base_name}_xdp")),),
                io_mode=str(benchmark.get("io_mode", default_io_mode)),
                input_size=int(benchmark.get("kernel_input_size", 0) or 0),
                input_generator=str(benchmark["input_generator"]) if benchmark.get("input_generator") else None,
                expected_result=int(benchmark["expected_result"]) if benchmark.get("expected_result") is not None else None,
                category=str(benchmark["category"]) if benchmark.get("category") else None,
                family=str(benchmark["family"]) if benchmark.get("family") else None,
                level=str(benchmark["level"]) if benchmark.get("level") else None,
                hypothesis=str(benchmark["hypothesis"]) if benchmark.get("hypothesis") else None,
                tags=tuple(str(tag) for tag in benchmark.get("tags", ())),
                backends=runtime_backends,
                policy_modes=runtime_policy_modes,
                transports=runtime_transports,
                metadata={"base_name": base_name},
            )
        )

    return CatalogManifest(
        manifest_path=path,
        manifest_kind="micro",
        schema_version=int(data.get("schema_version", 1)),
        suite_name=str(data.get("suite_name", path.stem)),
        defaults=DefaultsSpec(
            iterations=int(defaults_raw["iterations"]) if defaults_raw.get("iterations") is not None else None,
            warmups=int(defaults_raw["warmups"]) if defaults_raw.get("warmups") is not None else None,
            repeat=int(defaults_raw["repeat"]) if defaults_raw.get("repeat") is not None else None,
            runtimes=tuple(str(runtime) for runtime in defaults_raw.get("runtimes", ())),
            output=_resolve_path(defaults_raw.get("output"), root_dir),
            raw=defaults_raw,
        ),
        build=CatalogBuild(
            commands=_normalize_commands(build_data.get("commands")),
            runner_binary=_resolve_path(build_data.get("runner_binary"), root_dir),
            bpftool_binary=_resolve_path(build_data.get("bpftool_binary"), root_dir) if build_data.get("bpftool_binary") else None,
        ),
        runtimes=runtimes,
        targets=_validate_target_names(targets),
        runtime_aliases=aliases,
        metadata={"analysis": dict(data.get("analysis", {})), "toolchains": dict(data.get("toolchains", {}))},
    )


def _load_macro_catalog(path: Path, data: Mapping[str, Any]) -> CatalogManifest:
    root_dir = _manifest_root(path)
    defaults_raw = dict(data.get("defaults", {}))
    build_data = dict(data.get("build", {}))
    raw_runtimes = data.get("runtimes")
    if not isinstance(raw_runtimes, Sequence) or not raw_runtimes:
        raise ValueError("macro/corpus manifest missing runtimes[]")
    runtimes, aliases = _load_runtimes(raw_runtimes)
    runtime_backends = tuple(sorted({runtime.backend for runtime in runtimes}))
    runtime_policy_modes = tuple(sorted({runtime.policy_mode for runtime in runtimes}))
    runtime_transports = tuple(sorted({runtime.transport for runtime in runtimes}))

    targets: list[CatalogTarget] = []
    for program in data.get("programs", []):
        names = tuple(str(name) for name in (program.get("program_names") or ([program["program_name"]] if program.get("program_name") else [])))
        sections = tuple(str(section) for section in program.get("sections", ()))
        targets.append(
            CatalogTarget(
                name=str(program["name"]),
                description=str(program.get("description", program["name"])),
                kind=str(program.get("kind", "macro")),
                object_path=_resolve_path(program.get("source"), root_dir) or path,
                program_names=names,
                sections=sections,
                prog_type=str(program["prog_type"]) if program.get("prog_type") else None,
                io_mode=str(program["io_mode"]) if program.get("io_mode") else None,
                input_size=int(program["input_size"]) if program.get("input_size") is not None else None,
                input_path=_resolve_path(program.get("test_input"), root_dir),
                test_method=str(program["test_method"]) if program.get("test_method") else None,
                trigger=str(program["trigger"]) if program.get("trigger") else None,
                trigger_timeout_seconds=int(program.get("trigger_timeout_seconds", 30)),
                compile_loader=str(program.get("compile_loader", "micro_exec")),
                category=str(program["category"]) if program.get("category") else None,
                family=str(program["family"]) if program.get("family") else None,
                level=str(program["level"]) if program.get("level") else None,
                hypothesis=str(program["hypothesis"]) if program.get("hypothesis") else None,
                tags=tuple(str(tag) for tag in program.get("tags", ())),
                backends=runtime_backends,
                policy_modes=runtime_policy_modes,
                transports=runtime_transports,
                metadata={
                    "btf_path": _resolve_path(program.get("btf_path"), root_dir),
                    "recompile_supported": bool(program.get("recompile_supported", True)),
                },
            )
        )

    return CatalogManifest(
        manifest_path=path,
        manifest_kind="macro",
        schema_version=int(data.get("schema_version", 1)),
        suite_name=str(data.get("suite_name", path.stem)),
        defaults=DefaultsSpec(
            iterations=int(defaults_raw["iterations"]) if defaults_raw.get("iterations") is not None else None,
            warmups=int(defaults_raw["warmups"]) if defaults_raw.get("warmups") is not None else None,
            repeat=int(defaults_raw["repeat"]) if defaults_raw.get("repeat") is not None else None,
            output=_resolve_path(defaults_raw.get("output"), root_dir),
            raw=defaults_raw,
        ),
        build=CatalogBuild(
            commands=_normalize_commands(build_data.get("commands")),
            runner_binary=_resolve_path(build_data.get("runner_binary"), root_dir),
            scanner_binary=_resolve_path(build_data.get("scanner_binary"), root_dir),
            bpftool_binary=build_data.get("bpftool_binary"),
        ),
        runtimes=runtimes,
        targets=_validate_target_names(targets),
        runtime_aliases=aliases,
        corpus=CorpusSpec(
            manifest=_resolve_path(data.get("corpus", {}).get("manifest"), root_dir),
            local_repos=_resolve_path(data.get("corpus", {}).get("local_repos"), root_dir),
            inventory=_resolve_path(data.get("corpus", {}).get("inventory"), root_dir),
        ),
        metadata={"corpus": dict(data.get("corpus", {}))},
    )


def load_catalog(path: str | Path) -> CatalogManifest:
    manifest_path = Path(path).resolve()
    data = yaml.safe_load(manifest_path.read_text())
    if not isinstance(data, Mapping):
        raise ValueError(f"manifest is not a mapping: {manifest_path}")

    if "benchmarks" in data:
        return _load_micro_catalog(manifest_path, data)
    if "programs" in data:
        return _load_macro_catalog(manifest_path, data)
    raise ValueError(f"unsupported manifest schema: {manifest_path}")


ManifestSpec = CatalogManifest
load_manifest = load_catalog


def load_manifest_from_results(
    results: Mapping[str, object],
    *,
    fallback: str | Path | None = DEFAULT_MICRO_MANIFEST,
) -> ManifestSpec | None:
    manifest_candidates = [
        results.get("manifest"),
        results.get("manifest_path"),
    ]
    for candidate in manifest_candidates:
        if isinstance(candidate, str) and candidate:
            try:
                return load_catalog(candidate)
            except Exception:
                pass
    if fallback is None:
        return None
    try:
        return load_catalog(fallback)
    except Exception:
        return None


__all__ = [
    "AnalysisSpec",
    "CatalogBuild",
    "CatalogManifest",
    "CatalogRuntime",
    "CatalogTarget",
    "CorpusSpec",
    "DEFAULT_MACRO_MANIFEST",
    "DEFAULT_MICRO_MANIFEST",
    "DefaultsSpec",
    "DimensionSummary",
    "ManifestSpec",
    "load_catalog",
    "load_manifest",
    "load_manifest_from_results",
]
