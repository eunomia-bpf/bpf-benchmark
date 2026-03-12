#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import subprocess
import sys
import tempfile
from collections import Counter
from pathlib import Path
from typing import Any

import yaml

ROOT_DIR = Path(__file__).resolve().parents[2]
if str(ROOT_DIR) not in sys.path:
    sys.path.insert(0, str(ROOT_DIR))

from corpus.policy_utils import canonical_policy_family_name, parse_policy_v3, render_policy_v3_text
from micro.benchmark_catalog import CONFIG_PATH, load_suite
from micro.orchestrator.benchmarks import resolve_memory_file

RUNNER = ROOT_DIR / "micro" / "build" / "runner" / "micro_exec"
SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Regenerate micro benchmark version 3 policy files by translating "
            "the v2 policies in HEAD onto live scanner manifests."
        )
    )
    parser.add_argument("--suite", default=str(CONFIG_PATH))
    parser.add_argument("--bench", action="append", dest="benches")
    parser.add_argument(
        "--include-empty",
        action="store_true",
        help="Rewrite policy files even when the selected site list is empty.",
    )
    return parser.parse_args(argv)


def load_head_v2_policy(policy_path: Path) -> dict[str, Any]:
    rel_path = policy_path.resolve().relative_to(ROOT_DIR).as_posix()
    completed = subprocess.run(
        ["git", "-c", f"safe.directory={ROOT_DIR}", "show", f"HEAD:{rel_path}"],
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        detail = completed.stderr.strip() or completed.stdout.strip()
        raise RuntimeError(f"unable to read HEAD policy for {rel_path}: {detail}")
    payload = yaml.safe_load(completed.stdout)
    if not isinstance(payload, dict):
        raise RuntimeError(f"HEAD policy for {rel_path} is not a YAML mapping")
    if int(payload.get("version", 0) or 0) != 2:
        raise RuntimeError(
            f"expected HEAD policy {rel_path} to be version 2, got {payload.get('version')!r}"
        )
    return payload


def dump_live_manifest(benchmark, *, program_name: str) -> dict[str, Any]:
    memory_file = resolve_memory_file(benchmark, False)
    with tempfile.TemporaryDirectory(prefix=f"{benchmark.name}.") as tmp_dir:
        xlated_path = Path(tmp_dir) / f"{benchmark.name}.xlated"
        command = [
            "sudo",
            "-n",
            str(RUNNER),
            "run-kernel",
            "--program",
            str(benchmark.program_object),
            "--program-name",
            program_name,
            "--input-size",
            str(benchmark.kernel_input_size),
            "--io-mode",
            benchmark.io_mode,
            "--repeat",
            "1",
            "--compile-only",
            "--dump-xlated",
            str(xlated_path),
        ]
        if memory_file is not None:
            command.extend(["--input", str(memory_file)])
        completed = subprocess.run(
            command,
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            check=False,
        )
        if completed.returncode != 0:
            detail = completed.stderr.strip() or completed.stdout.strip()
            raise RuntimeError(f"micro_exec failed for {benchmark.name}: {detail}")
        scan = subprocess.run(
            [str(SCANNER), "scan", "--xlated", str(xlated_path), "--all", "--json"],
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            check=False,
        )
        if scan.returncode != 0:
            detail = scan.stderr.strip() or scan.stdout.strip()
            raise RuntimeError(f"scanner failed for {benchmark.name}: {detail}")
        payload = json.loads(scan.stdout)
        if not isinstance(payload, dict):
            raise RuntimeError(f"scanner manifest for {benchmark.name} is not a JSON object")
        return payload


def selected_sites_for_v2_policy(
    policy_v2: dict[str, Any],
    manifest: dict[str, Any],
) -> list[dict[str, Any]]:
    default_action = str(policy_v2.get("default", "skip")).strip().lower()
    family_actions = {
        canonical_policy_family_name(str(name)): str(action).strip().lower()
        for name, action in (policy_v2.get("families") or {}).items()
    }
    explicit_actions: dict[tuple[int, str], str] = {}
    for entry in policy_v2.get("sites") or []:
        if not isinstance(entry, dict):
            continue
        key = (
            int(entry["insn"]),
            canonical_policy_family_name(str(entry["family"])),
        )
        explicit_actions[key] = str(entry.get("action", "skip")).strip().lower()

    selected: list[dict[str, Any]] = []
    for raw_site in manifest.get("sites") or []:
        if not isinstance(raw_site, dict):
            continue
        family = canonical_policy_family_name(str(raw_site["family"]))
        insn = int(raw_site["insn"])
        action = explicit_actions.get((insn, family))
        if action is None:
            action = family_actions.get(family)
        if action is None:
            action = default_action
        if action != "apply":
            continue
        selected.append(
            {
                "insn": insn,
                "family": family,
                "pattern_kind": str(raw_site["pattern_kind"]),
            }
        )
    return selected


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    suite = load_suite(Path(args.suite).resolve())
    requested = set(args.benches or [])

    rows: list[dict[str, Any]] = []
    total_selected = 0
    total_eligible = 0
    selected_benchmarks = 0

    for benchmark in suite.benchmarks.values():
        if requested and benchmark.name not in requested:
            continue
        if benchmark.policy_file is None:
            continue

        policy_v2 = load_head_v2_policy(benchmark.policy_file)
        program_name = str(policy_v2.get("program", "")).strip()
        if not program_name:
            raise RuntimeError(f"{benchmark.name}: missing program name in HEAD v2 policy")

        manifest = dump_live_manifest(benchmark, program_name=program_name)
        eligible_sites = manifest.get("sites") or []
        selected_sites = selected_sites_for_v2_policy(policy_v2, manifest)

        eligible_family_counts = Counter(
            canonical_policy_family_name(str(site["family"]))
            for site in eligible_sites
            if isinstance(site, dict) and site.get("family") is not None
        )
        selected_family_counts = Counter(site["family"] for site in selected_sites)

        if selected_sites or args.include_empty:
            comments = [
                "Regenerated from HEAD version 2 policy semantics against a live framework-kernel manifest.",
                "Eligible live sites: "
                + (
                    ", ".join(
                        f"{family}={count}"
                        for family, count in sorted(eligible_family_counts.items())
                    )
                    if eligible_family_counts
                    else "none"
                ),
                "Selected live sites: "
                + (
                    ", ".join(
                        f"{family}={count}"
                        for family, count in sorted(selected_family_counts.items())
                    )
                    if selected_family_counts
                    else "none"
                ),
            ]
            text = render_policy_v3_text(
                program_name=program_name,
                sites=selected_sites,
                comments=comments,
            )
            parse_policy_v3(text)
            benchmark.policy_file.write_text(text)

        rows.append(
            {
                "benchmark": benchmark.name,
                "eligible": len(eligible_sites),
                "selected": len(selected_sites),
                "eligible_family_counts": dict(sorted(eligible_family_counts.items())),
                "selected_family_counts": dict(sorted(selected_family_counts.items())),
                "policy_file": str(benchmark.policy_file),
            }
        )
        total_eligible += len(eligible_sites)
        total_selected += len(selected_sites)
        if selected_sites:
            selected_benchmarks += 1

    for row in rows:
        print(
            f"{row['benchmark']}: selected {row['selected']}/{row['eligible']} "
            f"{row['selected_family_counts']}"
        )
    print(
        "summary: "
        f"benchmarks={len(rows)} "
        f"selected_benchmarks={selected_benchmarks} "
        f"selected_sites={total_selected} "
        f"eligible_sites={total_eligible}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
