"""Summarize raw artifact records; this is experiment analysis, not runner code."""
import collections
import csv
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parent
totals = collections.defaultdict(collections.Counter)
causes = collections.Counter()
rows = []
for phase in ("baseline", "cilium-baseline", "unbounded", "cilium-unbounded", "label", "cilium-label", "finite"):
    directory = ROOT / phase
    group = phase.removeprefix("cilium-")
    for line in (directory / "programs.jsonl").read_text().splitlines():
        record = json.loads(line)
        if record["stage"] != "generate":
            continue
        app = Path(record["proof"]).parent.name
        counts = totals[(group, app)]
        counts["total"] += 1
        counts["generated"] += record["ok"]
        status, cause = "generation-failed", record["note"]
        if record["ok"]:
            compiled = directory / "compile" / (record["name"] + ".json")
            status, cause = "compile-pending", ""
            if compiled.exists():
                # Early compiler records contain hundreds of MB of repeated
                # label warnings. Read the status prefix and diagnostic tail;
                # the complete JSON remains archived as raw evidence.
                with compiled.open() as stream:
                    prefix = stream.read(16384)
                    stream.seek(0, 2)
                    stream.seek(max(0, stream.tell() - 16384))
                    tail = stream.read()
                code = re.search(r'"returncode": (-?\d+)', prefix)
                if code is None:
                    raise ValueError(f"missing compiler returncode: {compiled}")
                result = {"returncode": int(code[1]), "stderr": tail.replace("\\n", "\n")}
                counts["compile-done"] += 1
                if result["returncode"] != 0:
                    status = "compile-failed"
                    errors = re.findall(r"(?:fatal )?error: ([^\n]+)", result["stderr"])
                    cause = errors[0] if errors else f"compiler exit {result['returncode']}"
                else:
                    counts["compiled"] += 1
                    status = "verify-pending"
                    verified = directory / "verify" / (record["name"] + ".json")
                    if verified.exists():
                        result = json.loads(verified.read_text())
                        if result["returncode"] == 0:
                            counts["accepted"] += 1
                            status = "artifact-accepted"
                        else:
                            log = verified.with_suffix(".verifier.log")
                            if log.exists() and log.stat().st_size:
                                status = "verifier-rejected"
                                counts["rejected"] += 1
                                messages = log.read_text().strip().splitlines()
                                cause = messages[-2] if messages[-1].startswith("processed ") else messages[-1]
                            else:
                                status = "load-preparation-failed"
                                counts["load-failed"] += 1
                                cause = result["stderr"].strip().splitlines()[0]
        counts[status] += 1
        if cause:
            causes[(group, status, cause)] += 1
        rows.append((app, record["name"], phase, status, cause))
with (ROOT / "coverage.csv").open("w") as output:
    writer = csv.writer(output, lineterminator="\n")
    writer.writerow(("app", "artifact", "phase", "status", "cause"))
    writer.writerows(rows)
lines = ["| Phase | Application | Available artifacts | Generation attempted | Generated | Compile done | Compiled | Artifact accepted | Verifier rejected | Load preparation failed |",
         "| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |"]
apps = sorted(app for group, app in totals if group == "baseline")
for group in ("baseline", "unbounded", "label", "finite"):
    for app in apps:
        c = totals[(group, app)]
        available = totals[("baseline", app)]["total"]
        lines.append(f"| {group} | {app} | {available} | " + " | ".join(str(c[k]) for k in
                     ("total", "generated", "compile-done", "compiled", "accepted", "rejected", "load-failed")) + " |")
lines.extend(("", "Failure causes at this checkpoint:", ""))
for (group, stage, cause), count in causes.most_common():
    lines.append(f"- {count} × {group}/{stage}: `{cause}`")
(ROOT / "tables.md").write_text("\n".join(lines) + "\n")
