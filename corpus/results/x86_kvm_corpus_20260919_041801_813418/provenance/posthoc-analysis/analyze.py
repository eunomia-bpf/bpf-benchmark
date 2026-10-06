#!/usr/bin/env python3
"""Post-hoc analysis of raw corpus artifacts; never imported by the runner."""
import json
import re
import sys
from pathlib import Path

STRESS = re.compile(
    r"metrc:\s*\[\d+\]\s+(\S+)\s+(\d+)\s+([\d.]+)\s+"
    r"([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)"
)
LOOP = re.compile(r"(\w+) int_loop ops=(\d+) elapsed_s=([\d.]+) worker=(\d+)")
PACKET = re.compile(r"(\d+)pps.*?errors:\s*(\d+)")


def text_of(workload):
    return (workload.get("stdout") or "") + "\n" + (workload.get("stderr") or "")


def metric(app, workloads):
    if app == "otelcol-ebpf-profiler/profiling":
        languages, workers, native = {}, [], []
        for workload in workloads:
            for component in workload["components"]:
                text = text_of(component)
                for match in LOOP.finditer(text):
                    language, operations, seconds, worker = match.groups()
                    rate = int(operations) / float(seconds)
                    workers.append(dict(language=language, worker=int(worker),
                                        operations=int(operations), seconds=float(seconds), rate=rate))
                    languages[language] = languages.get(language, 0) + rate
                for match in STRESS.finditer(text):
                    native.append(dict(stressor=match[1], operations=int(match[2]),
                                       reported_real_seconds=float(match[3]),
                                       reported_ops_per_s=float(match[6])))
        if not workers:
            raise ValueError("OTel language operation records missing")
        return dict(unit="language_loop_ops/s", rate=sum(languages.values()),
                    languages=languages, workers=workers, native_stress=native)
    if app in {"cilium/agent", "katran"}:
        components = []
        for workload in workloads:
            for component in workload["components"]:
                match = PACKET.search(text_of(component))
                if match is None:
                    raise ValueError("pktgen result missing")
                components.append(dict(name=component["workload_name"],
                                       pps=int(match[1]), errors=int(match[2])))
        return dict(unit="sender_pps", rate=sum(c["pps"] for c in components),
                    errors=sum(c["errors"] for c in components), components=components)
    operations, seconds, stressors = 0, 0.0, []
    for workload in workloads:
        seconds += workload["duration_s"]
        matches = list(STRESS.finditer(text_of(workload)))
        if not matches:
            raise ValueError("stress-ng metrics missing")
        for match in matches:
            operations += int(match[2])
            stressors.append(dict(name=match[1], operations=int(match[2]),
                                  reported_real_seconds=float(match[3]),
                                  reported_ops_per_s=float(match[6])))
    return dict(unit="bogo_ops/whole_workload_second", rate=operations / seconds,
                operations=operations, workload_seconds=seconds, stressors=stressors)


def analyze(run_dir):
    records = []
    for path in sorted((run_dir / "details/apps").glob("*.json")):
        data = json.loads(path.read_text())
        result = dict(app=data["app"], status=data["status"], error=data.get("error", ""),
                      artifact=str(path))
        reports = run_dir / "details/loadtime-reports" / (path.stem + ".jsonl")
        if reports.exists():
            rows = [json.loads(line) for line in reports.read_text().splitlines() if line.strip()]
            changed = [row for row in rows if (row.get("report") or {}).get("sites_applied", 0)]
            result["rewrites"] = dict(
                report_rows=len(rows), changed_load_instances=len(changed),
                sites_matched=sum((r.get("report") or {}).get("sites_matched", 0) for r in rows),
                sites_applied=sum(r["report"]["sites_applied"] for r in changed),
                report_errors=[r for r in rows if r.get("report_error")],
            )
        log_path = run_dir / "details/shim-logs" / (path.stem + ".post_rejit.log")
        if log_path.exists():
            lines = log_path.read_text(errors="replace").splitlines()
            result["original_preflight_rejections"] = [line for line in lines
                if "loadtime original bytecode rejected" in line]
            result["candidate_errors"] = [line for line in lines
                if "loadtime" in line and re.search(r"failed|rejected", line)
                and "original bytecode rejected" not in line]
            rejected_reports = []
            for line in result["candidate_errors"]:
                match = re.search(r"log=([^; ]+)", line)
                if match:
                    report_path = Path(match[1]).parent / "report.0.json"
                    if report_path.exists():
                        report = json.loads(report_path.read_text())
                        rejected_reports.append(dict(
                            report_path=str(report_path), verifier_log=match[1],
                            sites_matched=report.get("sites_matched"),
                            sites_rewritten_but_not_deployed=report.get("sites_applied"),
                            insn_count_before=report.get("insn_count_before"),
                            insn_count_after=report.get("insn_count_after"),
                        ))
            result["rejected_candidate_reports"] = rejected_reports
            pending, deployed, failed = {}, [], []
            for line in lines:
                identity = re.search(r"pid=(\d+) tid=(\d+)", line)
                if identity is None:
                    continue
                key = identity.groups()
                optimized = re.search(r"loadtime optimized prog=(\S*) insns=(\d+)->(\d+)", line)
                if optimized:
                    pending[key] = optimized.groups()
                loaded = re.search(r"PROG_LOAD -> fd=(-?\d+) errno=(\d+)", line)
                if loaded and key in pending:
                    entry = dict(program=pending.pop(key)[0], fd=int(loaded[1]), errno=int(loaded[2]))
                    (deployed if entry["fd"] >= 0 else failed).append(entry)
            result["deployment"] = dict(successful_changed_loads=len(deployed),
                                         failed_changed_loads=failed, unmatched_log_events=len(pending))
        if all((data.get(phase) or {}).get("workloads") for phase in ("baseline", "post_rejit")):
            baseline = metric(data["app"], data["baseline"]["workloads"])
            treatment = metric(data["app"], data["post_rejit"]["workloads"])
            result.update(baseline=baseline, treatment=treatment,
                          change_percent=100 * (treatment["rate"] / baseline["rate"] - 1))
        records.append(result)
    return dict(run_dir=str(run_dir), metadata=json.loads((run_dir / "metadata.json").read_text()),
                apps=records)


if __name__ == "__main__":
    print(json.dumps([analyze(Path(p).resolve()) for p in sys.argv[1:]], indent=2))
