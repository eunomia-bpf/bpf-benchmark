#!/usr/bin/env python3
"""Summarize load-time optimizer reports from a corpus artifact."""
from __future__ import annotations

import argparse
import json
from collections import Counter
from pathlib import Path


def find_reports_dir(target: Path) -> Path:
    if target.is_dir():
        for candidate in (
            target / "details" / "loadtime-reports",
            target / "loadtime-reports",
        ):
            if candidate.is_dir():
                return candidate
    if target.is_file() and target.name == "metadata.json":
        candidate = target.parent / "details" / "loadtime-reports"
        if candidate.is_dir():
            return candidate
    raise FileNotFoundError(f"no loadtime-reports directory under {target}")


def report_reason(report: dict) -> str | None:
    for item in report.get("diagnostics") or []:
        if item.startswith("not_applied_reason="):
            return item.split("=", 1)[1]
    return None


def summarize(reports_dir: Path) -> tuple[dict, dict[str, dict]]:
    total_reports = 0
    matched = 0
    applied = 0
    changed = 0
    skip_reasons: Counter[str] = Counter()
    no_apply_reasons: Counter[str] = Counter()
    per_app: dict[str, dict] = {}

    for path in sorted(reports_dir.glob("*.jsonl")):
        app_total = 0
        app_matched = 0
        app_applied = 0
        app_changed = 0
        app_skip: Counter[str] = Counter()
        app_no_apply: Counter[str] = Counter()
        for line in path.read_text().splitlines():
            if not line.strip():
                continue
            rec = json.loads(line)
            report = rec.get("report") or rec
            app_total += 1
            total_reports += 1
            sites_matched = int(report.get("sites_matched") or 0)
            sites_applied = int(report.get("sites_applied") or 0)
            app_matched += sites_matched
            matched += sites_matched
            app_applied += sites_applied
            applied += sites_applied
            if sites_applied > 0:
                app_changed += 1
                changed += 1
            for reason, count in (report.get("skip_reasons") or {}).items():
                app_skip[reason] += int(count or 0)
                skip_reasons[reason] += int(count or 0)
            reason = report_reason(report)
            if reason:
                app_no_apply[reason] += 1
                no_apply_reasons[reason] += 1
        per_app[path.name] = {
            "reports": app_total,
            "matched": app_matched,
            "applied": app_applied,
            "changed_reports": app_changed,
            "skip_reasons": dict(app_skip),
            "no_apply_reasons": dict(app_no_apply),
        }

    return (
        {
            "reports": total_reports,
            "matched": matched,
            "applied": applied,
            "changed_reports": changed,
            "skip_reasons": dict(skip_reasons),
            "no_apply_reasons": dict(no_apply_reasons),
        },
        per_app,
    )


def print_counter(counter: dict[str, int]) -> str:
    if not counter:
        return "-"
    return ", ".join(f"{k}={v}" for k, v in sorted(counter.items()))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("target", type=Path, help="corpus artifact dir or metadata.json")
    ap.add_argument("--per-app", action="store_true")
    args = ap.parse_args()

    reports_dir = find_reports_dir(args.target)
    total, per_app = summarize(reports_dir)
    print(f"# Load-time report summary: {reports_dir}")
    print(f"  reports:          {total['reports']}")
    print(f"  matched sites:    {total['matched']}")
    print(f"  applied sites:    {total['applied']}")
    print(f"  changed reports:  {total['changed_reports']}")
    print(f"  skip reasons:     {print_counter(total['skip_reasons'])}")
    print(f"  no-apply reasons: {print_counter(total['no_apply_reasons'])}")

    if args.per_app:
        print("\n## Per-app")
        print(f"{'Report file':<38} {'reports':>7} {'matched':>8} {'applied':>8} {'changed':>8}  reasons")
        print(f"{'-'*38} {'-'*7:>7} {'-'*8:>8} {'-'*8:>8} {'-'*8:>8}  {'-'*40}")
        for name, row in sorted(per_app.items()):
            reasons = print_counter(row["no_apply_reasons"])
            print(
                f"{name:<38} {row['reports']:>7} {row['matched']:>8} "
                f"{row['applied']:>8} {row['changed_reports']:>8}  {reasons}"
            )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
