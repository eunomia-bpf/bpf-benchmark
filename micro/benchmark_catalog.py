from __future__ import annotations

import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import yaml


MICRO_ROOT = Path(__file__).resolve().parent
REPO_ROOT = MICRO_ROOT.parent
ROOT_DIR = REPO_ROOT
CONFIG_PATH = REPO_ROOT / "config" / "micro_pure_jit.yaml"

_POLICY_FAMILY_ALIASES = {
    "cmov": "cmov",
    "cond-select": "cmov",
    "condselect": "cmov",
    "wide": "wide",
    "wide-mem": "wide",
    "widemem": "wide",
    "wide-load": "wide",
    "wideload": "wide",
    "rotate": "rotate",
    "lea": "lea",
    "addr-calc": "lea",
    "addrcalc": "lea",
    "extract": "extract",
    "bitfield-extract": "extract",
    "bitfieldextract": "extract",
    "zero-ext": "zero-ext",
    "zeroext": "zero-ext",
    "zero-ext-elide": "zero-ext",
    "zeroextelide": "zero-ext",
    "endian": "endian",
    "endian-fusion": "endian",
    "endianfusion": "endian",
    "branch-flip": "branch-flip",
    "branchflip": "branch-flip",
    "bflip": "branch-flip",
}

_POLICY_ACTION_ALIASES = {
    "apply": "apply",
    "enable": "apply",
    "enabled": "apply",
    "keep": "apply",
    "skip": "skip",
    "disable": "skip",
    "disabled": "skip",
    "drop": "skip",
}


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
    require_sudo: bool = False
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
    policy: dict[str, str] | None = None
    policy_file: Path | None = None

    @property
    def program_object(self) -> Path:
        return self.program_dir / f"{self.base_name}.bpf.o"

    @property
    def inline_policy_text(self) -> str | None:
        if self.policy is None:
            return None
        skipped = [
            family
            for family, action in self.policy.items()
            if action == "skip"
        ]
        config = {
            "version": 1,
            "selection": {
                "mode": "denylist",
                "families": skipped,
            },
        }
        return json.dumps(config, sort_keys=True)


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


def _canonical_policy_token(value: str) -> str:
    token = []
    for ch in value.strip():
        if ch.isalnum():
            token.append(ch.lower())
        elif ch in {"-", "_"}:
            token.append("-")
    return "".join(token)


def _load_inline_policy(raw_policy: Any, benchmark_name: str) -> dict[str, str] | None:
    if raw_policy is None:
        return None
    if not isinstance(raw_policy, dict):
        raise ValueError(f"benchmark {benchmark_name}: policy must be a mapping")

    normalized: dict[str, str] = {}
    for raw_family, raw_action in raw_policy.items():
        if not isinstance(raw_family, str):
            raise ValueError(f"benchmark {benchmark_name}: policy family names must be strings")

        family_token = _canonical_policy_token(raw_family)
        family = _POLICY_FAMILY_ALIASES.get(family_token)
        if family is None:
            raise ValueError(
                f"benchmark {benchmark_name}: unknown policy family '{raw_family}'"
            )

        if isinstance(raw_action, bool):
            action = "apply" if raw_action else "skip"
        else:
            action_token = _canonical_policy_token(str(raw_action))
            action = _POLICY_ACTION_ALIASES.get(action_token)
            if action is None:
                raise ValueError(
                    f"benchmark {benchmark_name}: unknown policy action '{raw_action}' "
                    "(expected apply/skip)"
                )

        normalized[family] = action

    return normalized


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
            require_sudo=bool(runtime_data.get("sudo", False)),
            aliases=tuple(runtime_data.get("aliases", ())),
        )
        runtimes[runtime.name] = runtime
        for alias in runtime.aliases:
            runtime_aliases[alias] = runtime.name

    benchmarks = {
        benchmark_data["name"]: BenchmarkSpec(
            name=benchmark_data["name"],
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
            policy=_load_inline_policy(
                benchmark_data.get("policy"),
                benchmark_data["name"],
            ),
            policy_file=_resolve_path(benchmark_data.get("policy_file"), root_dir),
        )
        for benchmark_data in data["benchmarks"]
    }

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
