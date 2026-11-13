#!/usr/bin/env python3
"""Order retained resident bodies by measured BPF time and submit representatives.

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
import shutil
import subprocess
import sys
import tarfile

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


def group_bodies(rows, bodies):
    """Keep priority order and complete membership; compare linked ELF bytes."""
    groups = {}
    for row in rows:
        candidates = row["native_candidates"]
        candidate = candidates[0] if len(candidates) == 1 else None
        body = bodies.get((candidate["native_object"], candidate["symbol"])) if candidate else None
        # A selection/link failure has no known linked body. Submit it rather
        # than assigning another program's observation to it.
        key = body if body is not None else (row["application"], row["source_prog_id"])
        group = groups.setdefault(key, dict(representative=row, members=[]))
        group["members"].append(row)
    return list(groups.values())


def group(args):
    source = json.loads(args.inputs.read_text())
    args.output.mkdir(parents=True, exist_ok=True)
    body_dir = args.output / "bodies"
    body_dir.mkdir(exist_ok=True)
    bodies, commands = {}, []
    for row in source["programs"]:
        if len(row["native_candidates"]) != 1:
            continue
        candidate = row["native_candidates"][0]
        key = candidate["native_object"], candidate["symbol"]
        if key in bodies:
            continue
        proof = body_dir / f"{len(commands)}.proof.o"
        command = [str(ROOT / "kprog/x86/native_lab/native_link/target/release/native-link"),
                   "--input", key[0], "--symbol", key[1], "--mode", "proof",
                   "--preserve-entry-abi", "--output", str(proof)]
        done = subprocess.run(command, capture_output=True, text=True)
        commands.append(dict(command=command, returncode=done.returncode,
                             stdout=done.stdout, stderr=done.stderr))
        bodies[key] = proof.read_bytes() if done.returncode == 0 else None
    write(args.output / "body-link-commands.json", commands)
    groups = group_bodies(source["programs"], bodies)
    by_instance = {(r["application"], r["source_prog_id"]): g
                   for g in groups for r in g["members"]}
    completed = [json.loads(line) for line in args.completed_journal.read_text().splitlines()]
    retained = {}
    for outcome in completed:
        g = by_instance[outcome["application"], outcome["source_prog_id"]]
        identity = id(g)
        if identity in retained or not outcome.get("submission", {}).get("service"):
            continue
        member = next(r for r in g["members"] if r["source_prog_id"] == outcome["source_prog_id"]
                      and r["application"] == outcome["application"])
        candidate, = member["native_candidates"]
        expected = bodies[candidate["native_object"], candidate["symbol"]]
        service = outcome["submission"]["service"]
        archive = service.get("artifact_archive", service.get("failure_archive"))
        with tarfile.open(archive) as captured:
            name = "request/generated/trusted_x86.proof.o"
            if name in captured.getnames() and expected is not None:
                if captured.extractfile(name).read() == expected:
                    retained[identity] = outcome
    pending, membership = [], []
    with (args.output / "retained-outcomes.jsonl").open("w") as journal:
        for number, g in enumerate(groups):
            row = dict(g["representative"], body_group=number)
            outcome = retained.get(id(g))
            membership.append(dict(body_group=number, representative=row,
                                   members=g["members"], retained_outcome=outcome))
            if outcome is None:
                pending.append(row)
            else:
                journal.write(json.dumps(dict(outcome, body_group=number)) + "\n")
    source.update(programs=pending, body_groups=membership,
                  scope="Distinct linked native bodies; representative load-only observations",
                  grouping=dict(identity="Complete canonical proof ELF byte equality including data/relocations",
                                input_inventory=str(args.inputs), previous_journal=str(args.completed_journal),
                                instances=sum(len(g["members"]) for g in groups),
                                bodies=len(groups), retained_bodies=len(retained), pending_bodies=len(pending)))
    write(args.output / "inventory.json", source)
    write(args.output / "preparation.json", source["grouping"])
    print(json.dumps(source["grouping"]), flush=True)


def replay_programs(groups, outcomes, classes):
    """Replay every observed body in a class, even after a later success."""
    observations = [(g["body_group"], g["retained_outcome"]) for g in groups
                    if g["retained_outcome"] is not None]
    observations.extend((r["body_group"], r) for r in outcomes)
    selected = {number for number, outcome in observations
                if failure_class(outcome) in classes}
    return [dict(g["representative"], body_group=g["body_group"])
            for g in groups if g["body_group"] in selected]


def write_replay_guests(source, output):
    """Partition all selected bodies into guest inputs for parallel isolation."""
    inventories = []
    for row in source["programs"]:
        directory = output / "bodies" / str(row["body_group"])
        directory.mkdir(parents=True, exist_ok=True)
        partition = dict(source, programs=[row], execution_partition=dict(
            body_group=row["body_group"], class_inventory=str(output / "inventory.json")))
        path = directory / "inventory.json"
        write(path, partition)
        inventories.append(str(path))
    return inventories


def replay(args):
    source = json.loads(args.inputs.read_text())
    outcomes = [json.loads(line)
                for journal in [args.completed_journal, *args.additional_journal]
                for line in journal.read_text().splitlines()]
    source["programs"] = replay_programs(source["body_groups"], outcomes, set(args.failure_class))
    selected = {r["body_group"] for r in source["programs"]}
    source["scope"] = "Affected-class body replay; separate from the full census"
    source["replay"] = dict(classes=args.failure_class, input_inventory=str(args.inputs),
                            completed_journal=str(args.completed_journal),
                            additional_journals=[str(path) for path in args.additional_journal],
                            bodies=len(selected),
                            represented_instances=sum(len(g["members"]) for g in source["body_groups"]
                                                      if g["body_group"] in selected),
                            controller_commit=subprocess.check_output(
                                ["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip())
    args.output.mkdir(parents=True, exist_ok=True)
    source["replay"]["guest_inventories"] = write_replay_guests(source, args.output)
    write(args.output / "inventory.json", source)
    write(args.output / "preparation.json", source["replay"])
    print(json.dumps(source["replay"]), flush=True)


def resume_programs(rows, outcomes, priority_rows):
    """Prioritize explicit class replays, then keep every unfinished body once."""
    completed = {row["body_group"] for row in outcomes}
    pending = [row for row in rows if row["body_group"] not in completed]
    selected = {}
    for row in [*priority_rows, *pending]:
        selected.setdefault(row["body_group"], row)
    return list(selected.values()), len(pending)


def resume(args):
    source = json.loads(args.inputs.read_text())
    outcomes = [json.loads(line)
                for journal in [args.completed_journal, *args.additional_journal]
                for line in journal.read_text().splitlines()]
    priority_rows = [row for inventory in args.priority_inventory
                     for row in json.loads(inventory.read_text())["programs"]]
    source["programs"], pending = resume_programs(source["programs"], outcomes, priority_rows)
    source["resume"] = dict(input_inventory=str(args.inputs),
                            completed_journals=[str(path) for path in
                                               [args.completed_journal, *args.additional_journal]],
                            priority_inventories=[str(path) for path in args.priority_inventory],
                            pending_bodies=pending, queued_bodies=len(source["programs"]),
                            additional_replay_bodies=len(source["programs"]) - pending,
                            controller_commit=subprocess.check_output(
                                ["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip())
    args.output.mkdir(parents=True, exist_ok=True)
    inventories = []
    for index in range(args.guest_count):
        directory = args.output / "queues" / str(index)
        directory.mkdir(parents=True, exist_ok=True)
        partition = dict(source, programs=source["programs"][index::args.guest_count],
                         execution_queue=dict(index=index, count=args.guest_count,
                                              source_inventory=str(args.output / "inventory.json")))
        path = directory / "inventory.json"
        write(path, partition)
        inventories.append(str(path))
    source["resume"]["guest_inventories"] = inventories
    write(args.output / "inventory.json", source)
    write(args.output / "preparation.json", source["resume"])
    print(json.dumps(source["resume"]), flush=True)


def checkpoint(args):
    """Snapshot already-paused guests, retaining unfinished journal bytes too."""
    args.output.mkdir(parents=True, exist_ok=True)
    queues = []
    for queue in args.queue:
        directory = args.output / queue.name
        directory.mkdir()
        journal = queue / "control/outcomes.jsonl"
        raw = journal.read_bytes()
        prefix = raw[:raw.rfind(b"\n") + 1]
        rows = [json.loads(line) for line in prefix.splitlines()]
        (directory / "journal.raw.jsonl").write_bytes(raw)
        (directory / "outcomes.jsonl").write_bytes(prefix)
        state = queue / "control/state"
        files = [dict(path=str(path), bytes=path.stat().st_size)
                 for path in sorted(state.rglob("*")) if path.is_file()]
        write(directory / "state-files.json", files)
        archive = directory / "state.tar.gz"
        with tarfile.open(archive, "w:gz", compresslevel=1) as captured:
            captured.add(state, arcname="state")
        queues.append(dict(queue=str(queue), journal=str(directory / "outcomes.jsonl"),
                           completed=len(rows), body_groups=[row["body_group"] for row in rows],
                           incomplete_journal_bytes=len(raw) - len(prefix),
                           state_files=len(files), state_archive=str(archive),
                           archive_bytes=archive.stat().st_size))
    write(args.output / "checkpoint.json", queues)
    print(json.dumps(queues), flush=True)


def retain_request_artifacts(result, directory):
    """Keep journal targets outside the service's temporary session directory."""
    service = result.get("submission", {}).get("service", {})
    for field in ("artifact_archive", "failure_archive"):
        if path := service.get(field):
            source = Path(path)
            directory.mkdir(parents=True, exist_ok=True)
            target = directory / source.name
            shutil.copyfile(source, target)
            service[field] = str(target)


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
            if "body_group" in row:
                result["body_group"] = row["body_group"]
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
                retain_request_artifacts(result, args.service_state.parent / "retained-requests" / state.parent.name)
                result["compiler_failures"] = compiler_failures(result)
            result["class"] = failure_class(result)
            journal.write(json.dumps(result) + "\n")
            journal.flush()
            print(json.dumps({k: result[k] for k in ("application", "source_prog_id", "name", "stage", "class")}), flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("mode", choices=("prepare", "group", "replay", "resume", "checkpoint", "guest"))
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--inputs", type=Path)
    parser.add_argument("--resources", type=Path)
    parser.add_argument("--retained-root", type=Path)
    parser.add_argument("--source-resources", type=Path)
    parser.add_argument("--producer", action="append", default=[])
    parser.add_argument("--stats-run", type=Path, action="append", default=[])
    parser.add_argument("--service-state", type=Path)
    parser.add_argument("--loader-directory", type=Path)
    parser.add_argument("--completed-journal", type=Path)
    parser.add_argument("--additional-journal", type=Path, action="append", default=[])
    parser.add_argument("--failure-class", action="append", default=[])
    parser.add_argument("--priority-inventory", type=Path, action="append", default=[])
    parser.add_argument("--guest-count", type=int, default=3)
    parser.add_argument("--queue", type=Path, action="append", default=[])
    args = parser.parse_args()
    {"prepare": prepare, "group": group, "replay": replay, "resume": resume,
     "checkpoint": checkpoint, "guest": guest}[args.mode](args)


if __name__ == "__main__":
    main()
