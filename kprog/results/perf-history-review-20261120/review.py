#!/usr/bin/env python3
"""Read-only historical reduction using the existing evaluation implementation."""
import hashlib
import json
import statistics
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from analysis.corpus_analyze import collect_per_program, geomean


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def describe(rows):
    values = [row["ratio"] for row in rows]
    return {"count": len(rows), "median": statistics.median(values) if values else None,
            "geomean": geomean(values) if values else None,
            "faster": sum(v < 1 for v in values)}


def main():
    otel = []
    tracee = []
    tracee_index_path = ROOT / "kprog/results/ratio-spread-20261120/tracee-november.json"
    tracee_index = json.loads(tracee_index_path.read_text())
    for meta_path in sorted((ROOT / "corpus/results").glob("x86_kvm_corpus_*/metadata.json")):
        run = meta_path.parent.name
        date = run.split("_")[3]
        if not "20261107" <= date <= "20261120":
            continue
        meta = json.loads(meta_path.read_text())
        for app_key in ("otelcol-ebpf-profiler__profiling", "tracee__monitor"):
            path = meta_path.parent / "details/apps" / (app_key + ".json")
            if not path.exists():
                continue
            app = json.loads(path.read_text())
            pairs = collect_per_program({"results": [app]}, 100, pair_by="name-type")
            common = {"run": run, "date": date, "samples": meta.get("samples"),
                      "seconds": meta.get("workload_seconds"), "status": app.get("status"),
                      "input": str(path.relative_to(ROOT)), "input_sha256": digest(path),
                      "metadata_sha256": digest(meta_path)}
            if app_key.startswith("otel"):
                for pair in pairs:
                    if pair["name"].startswith("native_tracer_e"):
                        otel.append(dict(common, **pair))
            elif run in tracee_index:
                tracee.append(dict(common, retained=len(pairs), ratio=geomean([p["ratio"] for p in pairs]),
                                   reported_rounded_ratio=tracee_index[run]["geomean"]))
    early = [r for r in otel if r["date"] < "20261114"]
    late = [r for r in otel if r["date"] >= "20261114"]
    report = {"method": "existing collect_per_program(min_runs=100,pair_by=name-type,applied_only=False)",
              "direction": "post per-call time / baseline per-call time; below one is faster",
              "otel": {"early": describe(early), "late": describe(late), "rows": otel,
                       "samples": {str(s): {"early": describe([r for r in early if r["samples"] == s]),
                                              "late": describe([r for r in late if r["samples"] == s])}
                                   for s in sorted({r["samples"] for r in otel}, key=str)}},
              "tracee": {"scope": "all runs listed by OMP, without outlier removal",
                         "input_index_sha256": digest(tracee_index_path), "summary": describe(tracee),
                         "rows": tracee, "missing_runs": sorted(set(tracee_index) - {r["run"] for r in tracee})},
              "limits": ["Calendar dates are not code/image identities or controlled causality.",
                         "Old OTel unequal-work evidence is in equal-work-20261113/report.md.",
                         "No raw run is discarded and no benchmark or paper is modified."]}
    out = Path(__file__).with_name("report.json")
    out.write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps({"otel_early": report["otel"]["early"], "otel_late": report["otel"]["late"],
                      "tracee_all": report["tracee"]["summary"], "missing_tracee": report["tracee"]["missing_runs"]}, indent=2))


if __name__ == "__main__":
    main()
