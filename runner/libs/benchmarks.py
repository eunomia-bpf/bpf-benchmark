from __future__ import annotations

from collections.abc import Mapping, Sequence
from pathlib import Path
from typing import Protocol, TypeVar

from .input_generators import materialize_input


class BenchmarkLike(Protocol):
    name: str
    input_generator: str | None


BenchmarkT = TypeVar("BenchmarkT", bound=BenchmarkLike)


class SuiteLike(Protocol[BenchmarkT]):
    benchmarks: Mapping[str, BenchmarkT]


def select_benchmarks(
    names: Sequence[str] | None,
    suite: SuiteLike[BenchmarkT],
    *,
    default_names: Sequence[str] | None = None,
) -> list[BenchmarkT]:
    selected_names = list(names or default_names or ())
    if not selected_names:
        return list(suite.benchmarks.values())

    selected: list[BenchmarkT] = []
    for name in selected_names:
        benchmark = suite.benchmarks.get(name)
        if benchmark is None:
            raise SystemExit(f"unknown benchmark: {name}")
        selected.append(benchmark)
    return selected


def resolve_memory_file(benchmark: BenchmarkLike, regenerate_inputs: bool) -> Path | None:
    if benchmark.input_generator is None:
        return None
    path, _ = materialize_input(benchmark.input_generator, force=regenerate_inputs)
    return path
