#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
"""Generate a prefetch profile JSON from candidate diagnostics TSV.

The input TSV is produced outside the benchmark framework from raw bpfopt
diagnostics. The output is a profile file consumed by the bpfopt `prefetch`
pass via `--profile`.
"""

from __future__ import annotations

import argparse
import csv
import json
import sys
from pathlib import Path


REQUIRED_COLUMNS = {
    "pc",
    "source",
    "ptr_reg",
    "ptr_root_pc",
    "ptr_def_pc",
    "mem_off",
    "dependent_load_depth",
}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate a bpfopt prefetch profile from diagnostics candidates."
    )
    parser.add_argument(
        "--input",
        required=True,
        type=Path,
        help="Candidate diagnostics TSV.",
    )
    parser.add_argument(
        "--output",
        required=True,
        type=Path,
        help="Output prefetch profile JSON.",
    )
    parser.add_argument(
        "--source",
        default="map-value",
        help="Candidate source to include. Default: map-value.",
    )
    parser.add_argument(
        "--max-sites",
        type=int,
        default=12,
        help="Maximum profile points to emit. Default: 12.",
    )
    parser.add_argument(
        "--hint",
        default="pldl1keep",
        help="Per-point hint written into the profile. Default: pldl1keep.",
    )
    parser.add_argument(
        "--policy",
        default="corpus-generated-map-value",
        help="Policy label written into the profile.",
    )
    parser.add_argument(
        "--rank-column",
        help=(
            "Optional numeric TSV column used to rank candidates before dedup. "
            "If omitted, candidates are ranked by BPF PC."
        ),
    )
    parser.add_argument(
        "--rank-descending",
        action="store_true",
        help="Sort --rank-column from high to low. PC tie-breakers remain ascending.",
    )
    parser.add_argument(
        "--horizon",
        type=int,
        default=1,
        help="Metadata horizon value written into the profile. Default: 1.",
    )
    parser.add_argument(
        "--degree",
        type=int,
        default=1,
        help="Metadata degree value written into the profile. Default: 1.",
    )
    return parser.parse_args()


def parse_positive_int(name: str, value: int) -> int:
    if value <= 0:
        raise ValueError(f"{name} must be positive, got {value}")
    return value


def parse_tsv_int(row: dict[str, str], column: str) -> int:
    value = row[column]
    try:
        return int(value, 0)
    except ValueError as exc:
        raise ValueError(f"column {column} must be an integer, got {value!r}") from exc


def validate_columns(fieldnames: list[str] | None) -> None:
    if fieldnames is None:
        raise ValueError("input TSV is empty or missing a header")
    missing = sorted(REQUIRED_COLUMNS.difference(fieldnames))
    if missing:
        raise ValueError(f"input TSV is missing required columns: {', '.join(missing)}")


def parse_optional_rank(row: dict[str, str], rank_column: str | None) -> float | None:
    if rank_column is None:
        return None
    if rank_column not in row:
        raise ValueError(f"rank column {rank_column!r} is not present in input TSV")
    value = row[rank_column]
    try:
        return float(value)
    except ValueError as exc:
        raise ValueError(
            f"rank column {rank_column!r} must be numeric, got {value!r}"
        ) from exc


def load_candidates(
    path: Path, source: str, rank_column: str | None
) -> list[dict[str, int | float | str | None]]:
    rows: list[dict[str, int | float | str | None]] = []
    with path.open(newline="", encoding="utf-8") as handle:
        reader = csv.DictReader(handle, delimiter="\t")
        validate_columns(reader.fieldnames)
        for row in reader:
            if row["source"] != source:
                continue
            pc = parse_tsv_int(row, "pc")
            ptr_reg = parse_tsv_int(row, "ptr_reg")
            ptr_root_pc = parse_tsv_int(row, "ptr_root_pc")
            ptr_def_pc = parse_tsv_int(row, "ptr_def_pc")
            mem_off = parse_tsv_int(row, "mem_off")
            dependent_load_depth = parse_tsv_int(row, "dependent_load_depth")
            rank_value = parse_optional_rank(row, rank_column)
            if ptr_reg < 0 or ptr_reg > 10:
                raise ValueError(f"ptr_reg must be 0..10, got {ptr_reg} at pc {pc}")
            rows.append(
                {
                    "pc": pc,
                    "ptr_reg": ptr_reg,
                    "ptr_root_pc": ptr_root_pc,
                    "ptr_def_pc": ptr_def_pc,
                    "mem_off": mem_off,
                    "dependent_load_depth": dependent_load_depth,
                    "rank_value": rank_value,
                }
            )
    return rows


def select_distinct_pointer_defs(
    rows: list[dict[str, int | float | str | None]],
    max_sites: int,
    rank_column: str | None,
    rank_descending: bool,
) -> list[dict[str, int | float | str | None]]:
    selected: list[dict[str, int | float | str | None]] = []
    seen: set[tuple[int, int]] = set()
    if rank_column is None:
        ordered = sorted(rows, key=lambda row: (int(row["pc"]), int(row["ptr_reg"])))
    elif rank_descending:
        ordered = sorted(
            rows,
            key=lambda row: (
                -float(row["rank_value"]),
                int(row["pc"]),
                int(row["ptr_reg"]),
            ),
        )
    else:
        ordered = sorted(
            rows,
            key=lambda row: (
                float(row["rank_value"]),
                int(row["pc"]),
                int(row["ptr_reg"]),
            ),
        )
    for row in ordered:
        key = (int(row["ptr_def_pc"]), int(row["ptr_reg"]))
        if key in seen:
            continue
        seen.add(key)
        selected.append(row)
        if len(selected) >= max_sites:
            break
    return selected


def build_profile(
    rows: list[dict[str, int | float | str | None]],
    source: str,
    policy: str,
    hint: str,
    horizon: int,
    degree: int,
    rank_column: str | None,
) -> dict[str, list[dict[str, int | str]]]:
    points: list[dict[str, int | str]] = []
    for row in rows:
        rank_note = ""
        if rank_column is not None:
            rank_note = f" {rank_column}={row['rank_value']}"
        points.append(
            {
                "pc": int(row["pc"]),
                "reg": int(row["ptr_reg"]),
                "action": "prefetch",
                "policy": policy,
                "horizon": horizon,
                "degree": degree,
                "hint": hint,
                "reason": (
                    "generated from prefetch diagnostics candidate: "
                    f"source={source} ptr_root_pc={row['ptr_root_pc']} "
                    f"ptr_def_pc={row['ptr_def_pc']} mem_off={row['mem_off']} "
                    f"dependent_load_depth={row['dependent_load_depth']}{rank_note}"
                ),
            }
        )
    return {"map_value_policy_points": points}


def main() -> int:
    args = parse_args()
    try:
        max_sites = parse_positive_int("--max-sites", args.max_sites)
        horizon = parse_positive_int("--horizon", args.horizon)
        degree = parse_positive_int("--degree", args.degree)
        candidates = load_candidates(args.input, args.source, args.rank_column)
        selected = select_distinct_pointer_defs(
            candidates, max_sites, args.rank_column, args.rank_descending
        )
        profile = build_profile(
            selected,
            args.source,
            args.policy,
            args.hint,
            horizon,
            degree,
            args.rank_column,
        )
        args.output.parent.mkdir(parents=True, exist_ok=True)
        with args.output.open("w", encoding="utf-8") as handle:
            json.dump(profile, handle, indent=2)
            handle.write("\n")
    except (OSError, ValueError) as exc:
        print(f"prefetch_profile_from_candidates.py: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
