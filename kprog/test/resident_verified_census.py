#!/usr/bin/env python3
"""Order the retained resident census by measured BPF time and submit it serially.

The retained source objects supply maps/BTF only. Current producer manifests
select P, and the existing registered service builds B from the kernel copy.
This load-only census complements the real application startup runs.
"""
import argparse
import collections
import contextlib
import importlib.util
import io
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "kprog"))
from corpus_resident_verifier import PROG_TYPES, failure_class, compiler_failures


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + "\n")


def map_profiles(selected, application):
    """Keep selected map profiles first, including anonymous inventory records."""
    names = {item.get("name") for item in selected}
    return list(selected) + [item for item in application if item.get("name") not in names]


def prepare(args):
    source = json.loads(args.inputs.read_text())
    producers = dict(item.split("=", 1) for item in args.producer)
    source["retained_inventory_head"] = source["source_head"]
    source["source_head"] = subprocess.check_output(
        ["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()
    resources = json.loads(args.resources.read_text())
    indexed = {(r["application"], r["source_prog_id"]): r for r in resources["programs"]}
    times, evidence = collections.Counter(), []
    for run in args.stats_run:
        for path in sorted((run / "details/apps").glob("*.json")):
            app = json.loads(path.read_text())
            records = (app.get("baseline") or {}).get("bpf") or {}
            for record in records.values():
                times[app["app"], record["name"]] += record["run_time_ns_delta"]
            evidence.append(dict(path=str(path), application=app["app"],
                                 baseline_programs=len(records)))
    totals = collections.Counter()
    for (app, name), value in times.items():
        totals[app] += value
    members = collections.Counter((r["application"], r["measurement"]["name"])
                                  for r in source["programs"])
    for row in source["programs"]:
        for candidate in row["native_candidates"]:
            previous = candidate["native_object"]
            selector = candidate["selector"]
            # Captured Cilium variants record their source object family;
            # other producers retain the original object basename.
            family = selector.get("config_family")
            filename = family + ".native.o" if family else Path(previous).name
            candidate["native_object"] = str(Path(producers[row["application"]]) / filename)
            candidate["retained_native_object"] = previous
        key = row["application"], row["measurement"]["name"]
        ns = times[key]
        row["priority"] = dict(measured_name=key[1], baseline_time_ns=ns,
                               application_time_ns=totals[key[0]],
                               application_time_share=ns / totals[key[0]] if totals[key[0]] else 0,
                               matching_census_instances=members[key],
                               retained_instance_time_ns=row["measurement"]["run_time_ns_delta"],
                               scope="Measured name family; matching instances share priority")
        resource = dict(indexed[row["application"], row["source_prog_id"]])
        old = Path(resource["bpf_object"])
        if resource.get("recheck_bpf_object_source"):
            resource["bpf_object"] = str(args.retained_root / old.relative_to("/var/tmp/kprog-tmp"))
        else:
            resource["bpf_object"] = str(args.source_resources / "bpf-resources" /
                                         (resource["bpf_object_sha256"] + ".bpf.o"))
        row["resource"] = resource
    source["programs"].sort(key=lambda r: (-r["priority"]["application_time_share"],
                                          -r["priority"]["baseline_time_ns"],
                                          -r["priority"]["retained_instance_time_ns"],
                                          r["application"], r["source_prog_id"]))
    source["stats_evidence"] = evidence
    source["scope"] = "Retained 549-instance census, current P producers and B model; load-only"
    source["kernel_head"] = subprocess.check_output(
        ["git", "-C", str(ROOT / "vendor/linux-framework"), "rev-parse", "HEAD"], text=True).strip()
    args.output.mkdir(parents=True, exist_ok=True)
    write(args.output / "inventory.json", source)
    summary = dict(instances=len(source["programs"]),
                   applications=dict(collections.Counter(r["application"] for r in source["programs"])),
                   native_candidate_counts=dict(collections.Counter(len(r["native_candidates"]) for r in source["programs"])),
                   resource_files_present=sum(Path(r["resource"]["bpf_object"]).is_file() for r in source["programs"]),
                   native_files_present=sum(Path(c["native_object"]).is_file()
                                            for r in source["programs"] for c in r["native_candidates"]),
                   stats_evidence=evidence,
                   first_twenty=[{k: r[k] for k in ("application", "source_prog_id", "name", "priority")}
                                 for r in source["programs"][:20]])
    write(args.output / "preparation.json", summary)
    print(json.dumps({k: v for k, v in summary.items() if k != "first_twenty"}), flush=True)


def guest(args):
    subprocess.run(["bash", "-eu", "-c",
                    "mountpoint -q /sys/fs/bpf || mount -t bpf bpffs /sys/fs/bpf"], check=True)
    spec = importlib.util.spec_from_file_location("resident_submit", ROOT / "kprog/selftests/submit.py")
    submit = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(submit)
    submit.tools_for_arch = lambda arch: (args.loader_directory,
        ROOT / "kprog/x86/native_lab/native_link/target/release/native-link")
    source = json.loads((args.output / "inventory.json").read_text())
    state, = args.service_state.glob("session-*/requests")
    app_maps = {a["application"]: a["map_inventory"] for a in source["applications"]}
    with (args.service_state.parent / "outcomes.jsonl").open("w") as journal:
        for row in source["programs"]:
            result = {k: row[k] for k in ("application", "source_prog_id", "name", "priority")}
            selected = row["native_candidates"]
            resource = row["resource"]
            if len(selected) != 1:
                result.update(stage="native_selection_failed", diagnostic="current producer candidates=%d" % len(selected))
            elif resource["resource_stage"] != "source_object_captured":
                result.update(stage="resource_failed", diagnostic=resource["resource_stage"])
            else:
                maps = map_profiles(row["map_info"], app_maps[row["application"]])
                record = dict(program=selected[0]["symbol"], bpf_object=resource["bpf_object"],
                              map_info=maps, prog_type=PROG_TYPES[row["program_info"]["type"]])
                with contextlib.redirect_stdout(io.StringIO()) as captured:
                    submit.direct("x86", state, Path(selected[0]["native_object"]), record)
                result["submission"] = json.loads(captured.getvalue())
                result["stage"] = result["submission"]["stage"]
                result["diagnostic"] = result["submission"].get("diagnostic", result["submission"].get("error", ""))
                result["compiler_failures"] = compiler_failures(result)
            result["class"] = failure_class(result)
            journal.write(json.dumps(result) + "\n")
            journal.flush()
            print(json.dumps({k: result[k] for k in ("application", "source_prog_id", "name", "stage", "class")}), flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("mode", choices=("prepare", "guest"))
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--inputs", type=Path)
    parser.add_argument("--resources", type=Path)
    parser.add_argument("--retained-root", type=Path)
    parser.add_argument("--source-resources", type=Path)
    parser.add_argument("--producer", action="append", default=[])
    parser.add_argument("--stats-run", type=Path, action="append", default=[])
    parser.add_argument("--service-state", type=Path)
    parser.add_argument("--loader-directory", type=Path)
    args = parser.parse_args()
    (prepare if args.mode == "prepare" else guest)(args)


if __name__ == "__main__":
    main()
