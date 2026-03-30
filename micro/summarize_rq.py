#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from micro.catalog import (
    DEFAULT_MICRO_MANIFEST,
    load_manifest,
    load_manifest_from_results,
)
from runner.libs.reporting import render_corpus_summary_markdown, render_rq_summary_markdown
DEFAULT_RESULTS_PATH = load_manifest(DEFAULT_MICRO_MANIFEST).defaults.output


def default_results_path() -> Path:
    if DEFAULT_RESULTS_PATH is None:
        raise SystemExit(f"default micro manifest has no output path: {DEFAULT_MICRO_MANIFEST}")
    return DEFAULT_RESULTS_PATH


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Summarize micro benchmark results against the active RQs.")
    parser.add_argument(
        "--results",
        default=str(default_results_path()),
        help="Path to a run_micro-style JSON result file.",
    )
    parser.add_argument(
        "--manifest",
        help="Optional manifest override. Defaults to the manifest recorded in the results file.",
    )
    parser.add_argument(
        "--corpus",
        help="Optional path to a corpus summary JSON file.",
    )
    parser.add_argument(
        "--corpus-manifest",
        help="Macro/corpus manifest used to annotate the corpus snapshot.",
    )
    parser.add_argument("--output", help="Optional markdown output path.")
    parser.add_argument(
        "--bootstrap-iterations",
        type=int,
        default=5000,
        help="Bootstrap iterations for suite/category confidence intervals.",
    )
    parser.add_argument(
        "--bootstrap-seed",
        type=int,
        default=20260306,
        help="Random seed for bootstrap resampling.",
    )
    return parser.parse_args()


def load_json(path: Path) -> dict[str, object]:
    payload = json.loads(path.read_text())
    if not isinstance(payload, dict):
        raise SystemExit(f"expected a JSON object at {path}")
    return payload


def main() -> int:
    args = parse_args()
    results_path = Path(args.results).resolve()
    results = load_json(results_path)

    if args.manifest:
        manifest = load_manifest(Path(args.manifest).resolve())
    else:
        manifest = load_manifest_from_results(results)

    report = render_rq_summary_markdown(
        results,
        manifest=manifest,
        bootstrap_iterations=args.bootstrap_iterations,
        bootstrap_seed=args.bootstrap_seed,
    )

    if args.corpus:
        corpus_path = Path(args.corpus).resolve()
        corpus_manifest = None
        if args.corpus_manifest:
            corpus_manifest_path = Path(args.corpus_manifest).resolve()
            if corpus_manifest_path.exists():
                corpus_manifest = load_manifest(corpus_manifest_path)
        report += "\n" + render_corpus_summary_markdown(load_json(corpus_path), manifest=corpus_manifest)

    if args.output:
        output_path = Path(args.output).resolve()
        output_path.parent.mkdir(parents=True, exist_ok=True)
        output_path.write_text(report + "\n")
        print(f"[done] wrote {output_path}")
        return 0

    print(report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
