#!/usr/bin/env python3
"""Weighted native-body census using one kernel submission per linked body."""
from pathlib import Path
import argparse
import collections
import concurrent.futures
import hashlib
import importlib.util
import json
import os
import shutil
import subprocess
import sys
import datetime

ROOT = Path("/workspaces/repository")
DEFAULT = Path("/var/tmp/kprog-tmp/A/resident-census-groups")
sys.path.insert(0, str(Path(__file__).resolve().parent))
import corpus_resident_verifier as census


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def write(path, value):
    Path(path).write_text(json.dumps(value, indent=2) + "\n")


def prepare(scratch, original):
    scratch.mkdir(parents=True, exist_ok=True)
    inventory = json.loads((original / "run-inventory.json").read_text())
    resources = json.loads((original / "resource-index.json").read_text())
    completed = json.loads((original / "stock-progress.json").read_text())
    completed_by_id = {r["source_prog_id"]: r for r in completed["programs"]}
    candidates = collections.defaultdict(list)
    for row in inventory["programs"]:
        candidate = row["native_candidates"][0]
        candidates[(candidate["native_object"], candidate["symbol"])].append(row)
    groups = {}
    proof_dir = scratch / "proofs"
    proof_dir.mkdir(exist_ok=True)
    for index, ((native, symbol), members) in enumerate(candidates.items()):
        proof = proof_dir / (str(index) + ".proof.o")
        command = [str(original / "native-link"), "--input", native, "--symbol", symbol,
                   "--mode", "proof", "--preserve-entry-abi", "--output", str(proof)]
        result = subprocess.run(command, text=True, capture_output=True)
        write(proof.with_suffix(".command.json"), dict(command=command,
              returncode=result.returncode, stdout=result.stdout, stderr=result.stderr))
        result.check_returncode()
        identity = sha(proof)
        group = groups.setdefault(identity, dict(body_sha256=identity,
            proof_object=str(proof), members=[], representative=members[0]))
        group["members"].extend(members)
        observed = [completed_by_id[r["source_prog_id"]] for r in members
                    if r["source_prog_id"] in completed_by_id]
        if observed and "outcome" not in group:
            row = dict(observed[0])
            row["compiler_failures"] = census.compiler_failures(row)
            row["failure_class"] = census.failure_class(row)
            group.update(outcome=row, observation="retained serial representative",
                         model_head=completed["model_head"])
    payload = dict(model_head=inventory["source_head"], original=str(original),
        instances=len(inventory["programs"]), candidate_groups=len(candidates),
        native_body_groups=len(groups), body_identity="SHA256 of complete native-link proof ELF, including executable/data sections and relocation identities",
        groups=list(groups.values()), controller_source_head=subprocess.check_output(
            ["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip())
    write(scratch / "groups.json", payload)
    return payload


def publish(scratch, data):
    base = ROOT / "corpus/results/kprog_app_coverage_20261109/resident-census/grouped-static"
    base.mkdir(parents=True, exist_ok=True)
    classes = collections.Counter()
    unique = collections.Counter()
    records = []
    for group in data["groups"]:
        outcome = group.get("outcome")
        label = outcome["failure_class"] if outcome else "pending"
        classes[label] += len(group["members"])
        unique[label] += 1
        records.append(dict(body_sha256=group["body_sha256"],
            representative_id=group["representative"]["source_prog_id"],
            symbol=group["representative"]["native_candidates"][0]["symbol"],
            instances=len(group["members"]),
            member_ids=[r["source_prog_id"] for r in group["members"]],
            stage=outcome["stage"] if outcome else "pending",
            failure_class=label, model_head=group.get("model_head", data["model_head"]),
            observation=group.get("observation", "queued representative"),
            outcome=outcome))
    result = dict(instances=data["instances"], native_body_groups=len(records),
        groups_completed=sum("outcome" in g for g in data["groups"]),
        represented_instances=sum(len(g["members"]) for g in data["groups"] if "outcome" in g),
        model_head=data["model_head"], body_identity=data["body_identity"],
        weighted_classes=dict(classes), unique_body_classes=dict(unique),
        instance_scope="Class distribution weighted by identical-body membership; each outcome is the actual representative submission",
        native_execution_requests=0, groups=records)
    write(base / "result.json", result)
    write(base / "membership.json", {k: v for k, v in data.items() if k != "groups"} |
        {"groups": [{k: v for k, v in g.items() if k != "outcome"} for g in data["groups"]]})
    lines = ["Grouped resident native-body census", "",
        str(result["groups_completed"]) + "/" + str(len(records)) + " native bodies have an actual representative outcome, covering " +
        str(result["represented_instances"]) + "/" + str(data["instances"]) + " weighted instances.",
        "", "| Failure class | Native bodies | Weighted instances |",
        "| --- | ---: | ---: |"]
    for label, count in classes.most_common():
        lines.append("| " + label + " | " + str(unique[label]) + " | " + str(count) + " |")
    lines += ["", "Each body is the complete linked native proof ELF with its executable bytes, data and relocation identities. Members retain their resident IDs and original resource/context inputs. The table weights a representative observation by body membership; the source program IDs identify the actual submissions.",
        "", "Model epoch: " + data["model_head"] + ". Retained completed requests supply their original raw records. Remaining representatives use separate stock-kernel guests and host compilers across CPUs8-19, one representative per body. Each guest uses one vCPU and2GiB. Application execution requests:0. The benchmark framework retains its frozen definition.",
        "", "The initial549-instance census and this275-instance grouped continuation retain separate epochs and counts. Runtime resources and BTF differences remain visible in membership.json; weighted body classes describe this census sampling rule."]
    (base / "README.md").write_text("\n".join(lines) + "\n")
    paths = [base / n for n in ["result.json", "membership.json", "README.md"]]
    raw_dir = base / "requests"
    raw_dir.mkdir(exist_ok=True)
    for group in data["groups"]:
        if "outcome" not in group:
            continue
        service = group["outcome"].get("submission", {}).get("service", {})
        archive = service.get("failure_archive", service.get("artifact_archive"))
        if archive and Path(archive).is_file():
            target = raw_dir / (group["body_sha256"] + ".tar.gz")
            if not target.exists():
                shutil.copy2(archive, target)
            paths.append(target)
    todo = ROOT / "kprog/docs/todo.md"
    text = todo.read_text()
    prefix = "- [ ] **A** 这 275 个程序的静态结果"
    for line in text.splitlines():
        if line.startswith(prefix):
            replacement = prefix + "，按 native body 分组并行：27 个候选入口组；实际 linked body " + str(len(records)) + " 组，完成 " + str(result["groups_completed"]) + " 组，覆盖 " + str(result["represented_instances"]) + "/275 加权实例。模型 " + data["model_head"][:9] + "；分类和原始记录见 resident-census/grouped-static，随后修最大的一类。"
            text = text.replace(line, replacement, 1)
            break
    todo.write_text(text)
    paths.append(todo)
    spec = importlib.util.spec_from_file_location("group_publish",
        "/var/tmp/kprog-tmp/A/publication/publish.py")
    publisher = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(publisher)
    receipt = publisher.publish([str(p.relative_to(ROOT)) for p in paths],
        "Publish weighted resident native-body failure classes", "grouped-native-classes")
    write(scratch / "publication.json", receipt)
    with Path("/workspaces/.agent-state/kprog-lanes/COORDINATION.md").open("a") as notice:
        notice.write("\n- LOCAL A FOR C/R/V/COORDINATOR " +
            datetime.datetime.now(datetime.timezone.utc).isoformat() + ": PUSHED " +
            receipt["commit"] + " grouped native census actual representatives " +
            str(result["groups_completed"]) + "/" + str(len(records)) + ", weighted " +
            str(result["represented_instances"]) + "/275; classes " +
            json.dumps(dict(classes)) + ". Per-group raw and membership published. Model" +
            data["model_head"] + "; native executions0. Coordinator14:35 sampling and CPU8-19 parallelism applied.\n")
    return result


def shard(scratch, original, group, cpu):
    work = scratch / "workers" / group["body_sha256"][:16]
    work.mkdir(parents=True, exist_ok=True)
    inventory = json.loads((original / "run-inventory.json").read_text())
    resources = json.loads((original / "resource-index.json").read_text())
    row = json.loads(json.dumps(group["representative"]))
    resource = next(r for r in resources["programs"] if r["source_prog_id"] == row["source_prog_id"])
    resource = dict(resource)
    for candidate in row["native_candidates"]:
        source = Path(candidate["native_object"])
        target = work / source.name
        if not target.exists():
            os.link(source, target)
        candidate["native_object"] = str(target)
    source = Path(resource["bpf_object"])
    target = work / source.name
    if not target.exists():
        os.link(source, target)
    resource["bpf_object"] = str(target)
    inventory.update(programs=[row], instances=1)
    resources["programs"] = [resource]
    write(work / "run-inventory.json", inventory)
    write(work / "resource-index.json", resources)
    write(work / "provenance.json", dict(model_head=inventory["source_head"],
        body_sha256=group["body_sha256"], weighted_instances=len(group["members"]),
        host_cpu=cpu, guest_cpus=1, coordinator="2026-11-09 14:35 grouped parallel census"))
    if not (work / "source").exists():
        (work / "source").symlink_to((original / "source").resolve(), target_is_directory=True)
    (work / "stock-runtime").mkdir(exist_ok=True)
    for source in (original / "stock-runtime").iterdir():
        if source.is_file() and not (work / "stock-runtime" / source.name).exists():
            os.link(source, work / "stock-runtime" / source.name)
    for name in ["native-link"]:
        if not (work / name).exists():
            os.link(original / name, work / name)
    driver = work / "driver.py"
    if not driver.exists():
        os.link(scratch / "controller-source/kprog/corpus_resident_verifier.py", driver)
    # The committed driver also owns its existing host compiler proxy mode.
    (work / "stock-compile-proxy").write_text("#!/bin/sh\nexec python3 " +
        str(driver) + " compile --scratch " + str(work) + ' "$@"\n')
    (work / "stock-compile-proxy").chmod(0o755)
    (work / "stock-guest.sh").write_text("#!/bin/bash\nset -e\nD=" + str(work) +
        '\nmountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug\n' +
        'mountpoint -q /sys/fs/bpf || mount -t bpf bpffs /sys/fs/bpf\n' +
        'insmod "$D/stock-runtime/kprog_stock.ko"\nexport CLANG="$D/stock-compile-proxy" PYTHONDONTWRITEBYTECODE=1\n' +
        "python3 " + str(driver) + ' guest --scratch "$D"\n')
    command = ["taskset", "-c", str(cpu), sys.executable, str(driver),
               "namespace", "--scratch", str(work)]
    with (work / "controller.log").open("w") as log:
        done = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT)
    result_path = work / "stock-results.json"
    if result_path.exists():
        outcome = json.loads(result_path.read_text())["programs"][0]
        outcome["compiler_failures"] = census.compiler_failures(outcome)
        outcome["failure_class"] = census.failure_class(outcome)
    else:
        outcome = dict(source_prog_id=row["source_prog_id"], name=row["name"],
            stage="transport_failed", failure_class="representative_guest_setup",
            diagnostic=(work / "controller.log").read_text(), returncode=done.returncode)
    completed = dict(group)
    completed.update(outcome=outcome, observation="group representative submission",
                     model_head=inventory["source_head"], worker=str(work), cpu=cpu)
    return completed


def run(scratch):
    data = json.loads((scratch / "groups.json").read_text())
    original = Path(data["original"])
    pending = [g for g in data["groups"] if "outcome" not in g]
    cpus = list(range(8, 20))
    # Each worker's CPU owns its serial kernel service and host Clang; the
    # twelve independent queues supply parallel B compilations.
    assignments = [pending[i::len(cpus)] for i in range(len(cpus))]
    import threading
    lock = threading.Lock()
    def drive_publish(cpu, groups):
        for group in groups:
            completed = shard(scratch, original, group, cpu)
            with lock:
                group.update(completed)
                write(scratch / "groups.json", data)
                publish(scratch, data)
    with concurrent.futures.ThreadPoolExecutor(max_workers=len(cpus)) as pool:
        futures = [pool.submit(drive_publish, cpu, groups) for cpu, groups in zip(cpus, assignments) if groups]
        for future in concurrent.futures.as_completed(futures):
            future.result()
    write(scratch / "complete.json", dict(groups=len(data["groups"]), instances=data["instances"]))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("mode", choices=["prepare", "publish", "run"])
    parser.add_argument("--scratch", type=Path, default=DEFAULT)
    parser.add_argument("--original", type=Path, default=Path("/var/tmp/kprog-tmp/A/resident-census-linked"))
    args = parser.parse_args()
    if args.mode == "prepare":
        data = prepare(args.scratch, args.original)
        print(json.dumps(dict(instances=data["instances"], groups=data["native_body_groups"],
            completed=sum("outcome" in g for g in data["groups"]))))
    elif args.mode == "publish":
        publish(args.scratch, json.loads((args.scratch / "groups.json").read_text()))
    else:
        run(args.scratch)


if __name__ == "__main__":
    main()
