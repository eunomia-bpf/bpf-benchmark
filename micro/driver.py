#!/usr/bin/env python3
from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

try:
    from benchmark_catalog import CONFIG_PATH, ROOT_DIR
except ImportError:
    from micro.benchmark_catalog import CONFIG_PATH, ROOT_DIR

try:
    import _driver_impl_run_micro as run_micro_impl
    import _driver_impl_run_pass_ablation as run_pass_ablation_impl
    import _driver_impl_run_rigorous as run_rigorous_impl
    import _driver_impl_run_rigorous_framework_vm as run_rigorous_framework_vm_impl
except ImportError:
    from micro import (
        _driver_impl_run_micro as run_micro_impl,
        _driver_impl_run_pass_ablation as run_pass_ablation_impl,
        _driver_impl_run_rigorous as run_rigorous_impl,
        _driver_impl_run_rigorous_framework_vm as run_rigorous_framework_vm_impl,
    )
from corpus import (
    _driver_impl_run_corpus_perf as run_corpus_perf_impl,
    _driver_impl_run_corpus_tracing as run_corpus_tracing_impl,
    _driver_impl_run_corpus_v5_framework as run_corpus_v5_framework_impl,
    _driver_impl_run_corpus_v5_vm_batch as run_corpus_v5_vm_batch_impl,
    _driver_impl_run_macro_corpus as run_macro_corpus_impl,
    _driver_impl_run_production_corpus_v5_framework as run_production_corpus_v5_framework_impl,
)

def _strip_separator(argv: list[str]) -> list[str]:
    return [arg for arg in argv if arg != "--"]


def _detect_suite_kind(suite_path: Path) -> str:
    try:
        try:
            from orchestrator.catalog import load_catalog
        except ImportError:
            from micro.orchestrator.catalog import load_catalog
        catalog = load_catalog(suite_path)
        return str(catalog.manifest_kind)
    except Exception:
        return "macro" if suite_path.name == "macro_corpus.yaml" else "micro"


def _run_python_script(script_name: str, argv: list[str]) -> int:
    completed = subprocess.run([sys.executable, str(REPO_ROOT / script_name), *argv], cwd=ROOT_DIR)
    return int(completed.returncode)


def _suite_entry(argv: list[str]) -> int:
    argv = _strip_separator(list(argv))
    parser = argparse.ArgumentParser(prog="micro/driver.py suite", add_help=False)
    parser.add_argument("--suite", default=str(CONFIG_PATH))
    known, _ = parser.parse_known_args(argv)
    suite_path = Path(known.suite).resolve()
    manifest_kind = _detect_suite_kind(suite_path)
    if manifest_kind in {"macro", "corpus"}:
        return run_macro_corpus_impl.main(argv)
    return run_micro_impl.main(argv)


def _rigorous_entry(argv: list[str]) -> int:
    argv = _strip_separator(list(argv))
    parser = argparse.ArgumentParser(prog="micro/driver.py rigorous", add_help=False)
    parser.add_argument("--transport", choices=["local", "vm"], default="local")
    known, remaining = parser.parse_known_args(argv)
    remaining = _strip_separator(remaining)
    if known.transport == "vm":
        return run_rigorous_framework_vm_impl.main(remaining)
    return run_rigorous_impl.main(remaining)


def _ablation_entry(argv: list[str]) -> int:
    return run_pass_ablation_impl.main(argv)


def _corpus_entry(argv: list[str]) -> int:
    argv = _strip_separator(list(argv))
    if not argv:
        raise SystemExit("corpus mode required: macro | perf | tracing | v5-framework | v5-production | v5-vm-batch")
    mode, *remaining = argv
    remaining = _strip_separator(remaining)
    dispatch = {
        "macro": run_macro_corpus_impl.main,
        "perf": run_corpus_perf_impl.main,
        "tracing": run_corpus_tracing_impl.main,
        "v5-framework": run_corpus_v5_framework_impl.main,
        "v5-production": run_production_corpus_v5_framework_impl.main,
        "v5-vm-batch": run_corpus_v5_vm_batch_impl.main,
    }
    entry = dispatch.get(mode)
    if entry is None:
        raise SystemExit(f"unknown corpus mode: {mode}")
    return entry(remaining)


def _census_entry(argv: list[str]) -> int:
    argv = _strip_separator(list(argv))
    if not argv:
        return _run_python_script("corpus/directive_census.py", [])
    tool, *remaining = argv
    script_map = {
        "directive": "corpus/directive_census.py",
        "cross-domain": "corpus/cross_domain_census.py",
    }
    script_name = script_map.get(tool)
    if script_name is None:
        raise SystemExit("unknown census mode: expected directive or cross-domain")
    return _run_python_script(script_name, remaining)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Unified benchmark driver entry point.")
    parser.add_argument("subcommand", choices=["suite", "rigorous", "ablation", "census", "corpus"])
    parser.add_argument("args", nargs=argparse.REMAINDER)
    return parser


def main(argv: list[str] | None = None) -> int:
    parsed = build_parser().parse_args(argv)
    if parsed.args and parsed.args[0] == "--":
        forwarded = parsed.args[1:]
    else:
        forwarded = list(parsed.args)

    if parsed.subcommand == "suite":
        return _suite_entry(forwarded)
    if parsed.subcommand == "rigorous":
        return _rigorous_entry(forwarded)
    if parsed.subcommand == "ablation":
        return _ablation_entry(forwarded)
    if parsed.subcommand == "census":
        return _census_entry(forwarded)
    if parsed.subcommand == "corpus":
        return _corpus_entry(forwarded)
    raise SystemExit(f"unsupported subcommand: {parsed.subcommand}")


if __name__ == "__main__":
    raise SystemExit(main())
