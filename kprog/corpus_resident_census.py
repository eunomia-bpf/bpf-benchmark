#!/usr/bin/env python3
"""Enumerate retained application program instances for a static kprog census."""
from __future__ import annotations
import argparse
import collections
import hashlib
import json
from pathlib import Path
import re
import subprocess
import tarfile

ROOT = Path(__file__).resolve().parents[1]


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def load_contexts(text):
    pending, records = {}, {}
    for line in text.splitlines():
        thread = re.search(r"pid=(\d+) tid=(\d+)", line)
        if not thread:
            continue
        key = thread.groups()
        if "BPF_PROG_LOAD type=" in line:
            pending[key] = dict(re.findall(r"(\w+)=([^\s]*)", line))
        elif "PROG_LOAD ->" in line and "kernel_prog_id=" in line:
            identifier = re.search(r"kernel_prog_id=(\d+)", line)
            if identifier and key in pending:
                records[int(identifier[1])] = pending.pop(key)
    return records


def collect(spec):
    rows, inputs = [], []
    for app in spec["applications"]:
        coverage = ROOT / app["coverage"]
        archive = ROOT / app["archive"]
        document = json.loads(coverage.read_text())
        measured = next(row["app"] for row in document["results"]
                        if row["application"] == app["application"])
        baseline = measured["baseline"]["bpf"]
        with tarfile.open(archive) as tf:
            prefix = "/" + app["evidence"] + "/baseline/"
            programs_member = next(m for m in tf
                                   if m.name.endswith(prefix + "program-inventory.json"))
            maps_member = next(m for m in tf
                               if m.name.endswith(prefix + "map-inventory.json"))
            programs = {p["id"]: p for p in json.loads(tf.extractfile(programs_member).read())}
            maps = {p["id"]: p for p in json.loads(tf.extractfile(maps_member).read())}
            shim_member = next(m for m in tf
                               if m.name.endswith("/" + app["shim"] + ".baseline.log"))
            contexts = load_contexts(tf.extractfile(shim_member).read().decode())
            dumps = {}
            for member in tf:
                if member.isfile() and prefix in member.name and member.name.endswith(".xlated.txt"):
                    match = re.search(r"/(\d+)-[^/]+\.xlated\.txt$", member.name)
                    if match:
                        dumps[int(match[1])] = tf.extractfile(member).read().decode()
        manifest_path = Path(app["producer"]) / "manifest.json"
        manifest = json.loads(manifest_path.read_text())
        inputs.append(dict(application=app["application"],
                           expected_instances=app["expected"], observed_instances=len(baseline),
                           coverage=app["coverage"], coverage_sha256=sha(coverage),
                           archive=app["archive"], archive_sha256=sha(archive),
                           manifest=str(manifest_path), manifest_sha256=sha(manifest_path),
                           map_inventory=list(maps.values())))
        for identifier, measurement in baseline.items():
            identifier = int(identifier)
            info = programs.get(identifier, measurement)
            name = info.get("name", "")
            context = contexts.get(identifier, {})
            helpers = set(int(value) for value in re.findall(r"#(\d+)", dumps.get(identifier, "")))
            candidates = []
            for entry in manifest["objects"]:
                if entry["program"] != name[:15]:
                    continue
                source_name = name if len(name) > 15 else None
                selected_name = entry.get("source_btf_symbol", entry.get("symbol"))
                if source_name and selected_name and selected_name != source_name:
                    continue
                if "source_bytecode_len" in entry and context.get("insn_cnt"):
                    if entry["source_bytecode_len"] != int(context["insn_cnt"]) * 8:
                        continue
                if "source_xlated_len" in entry and entry["source_xlated_len"] != info["bytes_xlated"]:
                    continue
                if "prog_type" in entry and context.get("type"):
                    if entry["prog_type"] != int(context["type"]):
                        continue
                if identifier in dumps:
                    if "source_has_helper" in entry and entry["source_has_helper"] not in helpers:
                        continue
                    if "source_lacks_helper" in entry and entry["source_lacks_helper"] in helpers:
                        continue
                names = [maps[i]["name"] for i in info.get("map_ids", []) if i in maps]
                if info.get("map_ids"):
                    if entry.get("source_map_prefix") and not any(n.startswith(entry["source_map_prefix"]) for n in names):
                        continue
                    if any(n.startswith(prefix) for prefix in entry.get("source_lacks_map_prefix", []) for n in names):
                        continue
                candidate = dict(native_object=str(Path(app["producer"]) / entry["native_object"]),
                                 symbol=entry.get("symbol", source_name or name), selector=entry)
                if not any((c["native_object"], c["symbol"]) ==
                           (candidate["native_object"], candidate["symbol"]) for c in candidates):
                    candidates.append(candidate)
            rows.append(dict(application=app["application"], source_prog_id=identifier,
                             name=name, measurement=measurement, program_info=info,
                             context=context, program_inventory_present=identifier in programs,
                             xlated_dump_present=identifier in dumps, helper_ids=sorted(helpers),
                             map_info=[maps[i] for i in info.get("map_ids", []) if i in maps],
                             manifest=str(manifest_path), native_candidates=candidates,
                             generation="pending", compile="pending", verifier="pending"))
    return dict(source_head=spec["source_head"], applications=inputs,
                instances=len(rows), programs=rows)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("inputs", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    result = collect(json.loads(args.inputs.read_text()))
    args.output.write_text(json.dumps(result, indent=2) + "\n")
    for app in result["applications"]:
        rows = [r for r in result["programs"] if r["application"] == app["application"]]
        print(app["application"], len(rows),
              dict(collections.Counter(len(r["native_candidates"]) for r in rows)),
              "contexts", sum(bool(r["context"]) for r in rows))


if __name__ == "__main__":
    main()
