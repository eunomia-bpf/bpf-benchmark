from __future__ import annotations

from pathlib import Path
from typing import Sequence

try:
    from benchmark_catalog import BenchmarkSpec, SuiteSpec
    from input_generators import materialize_input
except ImportError:
    from micro.benchmark_catalog import BenchmarkSpec, SuiteSpec
    from micro.input_generators import materialize_input


def select_benchmarks(
    names: Sequence[str] | None,
    suite: SuiteSpec,
    *,
    default_names: Sequence[str] | None = None,
) -> list[BenchmarkSpec]:
    selected_names = list(names or default_names or ())
    if not selected_names:
        return list(suite.benchmarks.values())

    selected: list[BenchmarkSpec] = []
    for name in selected_names:
        benchmark = suite.benchmarks.get(name)
        if benchmark is None:
            raise SystemExit(f"unknown benchmark: {name}")
        selected.append(benchmark)
    return selected


def resolve_memory_file(benchmark: BenchmarkSpec, regenerate_inputs: bool) -> Path | None:
    if benchmark.input_generator is None:
        return None
    path, _ = materialize_input(benchmark.input_generator, force=regenerate_inputs)
    return path
