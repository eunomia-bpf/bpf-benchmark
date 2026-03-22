from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path

import yaml


MICRO_ROOT = Path(__file__).resolve().parent
REPO_ROOT = MICRO_ROOT.parent
ROOT_DIR = REPO_ROOT
CONFIG_PATH = REPO_ROOT / "micro" / "config" / "micro_pure_jit.yaml"


def _manifest_root(path: Path) -> Path:
    try:
        path.relative_to(ROOT_DIR)
    except ValueError:
        return path.parent.parent
    return ROOT_DIR


@dataclass(frozen=True)
class ToolchainSpec:
    name: str
    root: Path


@dataclass(frozen=True)
class BuildSpec:
    commands: dict[str, tuple[str, ...]]
    runner_binary: Path
    bpftool_binary: Path


@dataclass(frozen=True)
class DefaultsSpec:
    iterations: int
    warmups: int
    repeat: int
    runtimes: tuple[str, ...]
    output: Path


@dataclass(frozen=True)
class AnalysisSpec:
    baseline_benchmark: str | None = None


@dataclass(frozen=True)
class RuntimeSpec:
    name: str
    label: str
    mode: str
    default_repeat: int
    aliases: tuple[str, ...] = ()


@dataclass(frozen=True)
class BenchmarkSpec:
    name: str
    description: str
    category: str
    base_name: str
    program_dir: Path
    io_mode: str
    kernel_input_size: int
    family: str | None = None
    level: str | None = None
    hypothesis: str | None = None
    input_generator: str | None = None
    tags: tuple[str, ...] = ()
    expected_result: int | None = None

    @property
    def program_object(self) -> Path:
        return self.program_dir / f"{self.base_name}.bpf.o"


@dataclass(frozen=True)
class SuiteSpec:
    suite_name: str
    manifest_path: Path
    toolchains: dict[str, ToolchainSpec]
    build: BuildSpec
    defaults: DefaultsSpec
    analysis: AnalysisSpec
    runtimes: dict[str, RuntimeSpec]
    runtime_aliases: dict[str, str]
    benchmarks: dict[str, BenchmarkSpec]


def _resolve_path(value: str | Path | None, base: Path) -> Path | None:
    if value is None:
        return None
    path = Path(value)
    if path.is_absolute():
        return path
    return (base / path).resolve()


def _load_commands(raw_commands: dict[str, list[str]]) -> dict[str, tuple[str, ...]]:
    return {name: tuple(command) for name, command in raw_commands.items()}


def load_suite(path: Path = CONFIG_PATH) -> SuiteSpec:
    manifest_path = path.resolve()
    root_dir = _manifest_root(manifest_path)

    data = yaml.safe_load(manifest_path.read_text())
    benchmark_defaults = data.get("benchmark_defaults", {})
    default_io_mode = str(benchmark_defaults.get("io_mode", "map"))

    paths = data["paths"]
    program_dir = _resolve_path(paths["program_dir"], root_dir)

    toolchains = {
        name: ToolchainSpec(name=name, root=_resolve_path(spec["root"], root_dir))
        for name, spec in data["toolchains"].items()
    }

    build_data = data["build"]
    build = BuildSpec(
        commands=_load_commands(build_data["commands"]),
        runner_binary=_resolve_path(build_data["runner_binary"], root_dir),
        bpftool_binary=_resolve_path(build_data["bpftool_binary"], root_dir),
    )

    defaults_data = data["defaults"]
    defaults = DefaultsSpec(
        iterations=int(defaults_data["iterations"]),
        warmups=int(defaults_data["warmups"]),
        repeat=int(defaults_data["repeat"]),
        runtimes=tuple(defaults_data["runtimes"]),
        output=_resolve_path(defaults_data["output"], root_dir),
    )
    analysis = AnalysisSpec(
        baseline_benchmark=data.get("analysis", {}).get("baseline_benchmark"),
    )

    runtimes: dict[str, RuntimeSpec] = {}
    runtime_aliases: dict[str, str] = {}
    for runtime_data in data["runtimes"]:
        runtime = RuntimeSpec(
            name=runtime_data["name"],
            label=runtime_data["label"],
            mode=runtime_data["mode"],
            default_repeat=int(runtime_data.get("repeat", defaults.repeat)),
            aliases=tuple(runtime_data.get("aliases", ())),
        )
        runtimes[runtime.name] = runtime
        for alias in runtime.aliases:
            runtime_aliases[alias] = runtime.name

    benchmarks: dict[str, BenchmarkSpec] = {}
    for benchmark_data in data["benchmarks"]:
        benchmark_name = benchmark_data["name"]
        benchmarks[benchmark_name] = BenchmarkSpec(
            name=benchmark_name,
            description=benchmark_data["description"],
            category=benchmark_data["category"],
            base_name=benchmark_data["base_name"],
            program_dir=program_dir,
            io_mode=str(benchmark_data.get("io_mode", default_io_mode)),
            kernel_input_size=int(benchmark_data["kernel_input_size"]),
            family=benchmark_data.get("family"),
            level=benchmark_data.get("level"),
            hypothesis=benchmark_data.get("hypothesis"),
            input_generator=benchmark_data.get("input_generator"),
            tags=tuple(benchmark_data.get("tags", ())),
            expected_result=benchmark_data.get("expected_result"),
        )

    return SuiteSpec(
        suite_name=str(data.get("suite_name", manifest_path.stem)),
        manifest_path=manifest_path,
        toolchains=toolchains,
        build=build,
        defaults=defaults,
        analysis=analysis,
        runtimes=runtimes,
        runtime_aliases=runtime_aliases,
        benchmarks=benchmarks,
    )


DEFAULT_SUITE = load_suite()
AVAILABLE_BENCHMARKS = DEFAULT_SUITE.benchmarks
AVAILABLE_RUNTIMES = DEFAULT_SUITE.runtimes
