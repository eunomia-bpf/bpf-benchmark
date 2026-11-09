#!/usr/bin/env python3
"""Load-only stock-kernel pass over the retained resident-program census."""
from pathlib import Path
import argparse
import collections
import contextlib
import importlib.util
import io
import json
import os
import subprocess
import sys
import hashlib
import tarfile
import shutil
import select
import datetime

ROOT = Path("/workspaces/repository")


def guest(scratch):
    spec = importlib.util.spec_from_file_location("census_submit", ROOT / "kprog/selftests/submit.py")
    submit = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(submit)
    source = json.loads((scratch / "run-inventory.json").read_text())
    resources = {(r["application"], r["source_prog_id"]): r for r in
                 json.loads((scratch / "resource-index.json").read_text())["programs"]}
    state = scratch / "stock-state"
    state.mkdir(exist_ok=True)
    log = (scratch / "stock-service.log").open("w")
    service = subprocess.Popen([
        sys.executable, str(ROOT / "kprog/trusted_service.py"),
        "--arch", "1", "--endpoint", "/sys/kernel/debug/bpf_x86_native_lab/specializer",
        "--state", str(state), "--native-link", str(scratch / "native-link"),
        "--loader", str(ROOT / "kprog/libnativeloader/build/trusted-native-loader")],
        stdout=log, stderr=subprocess.STDOUT)
    records = []
    try:
        # The endpoint registers synchronously; the existing ready record
        # identifies completion of that registration.
        import time
        while service.poll() is None and '"ready": true' not in (scratch / "stock-service.log").read_text():
            time.sleep(0.1)
        if service.poll() is not None:
            raise RuntimeError((scratch / "stock-service.log").read_text())
        for row in source["programs"]:
            result = {k: row[k] for k in ["application", "source_prog_id", "name"]}
            selected = row["native_candidates"]
            resource = resources[(row["application"], row["source_prog_id"])]
            if len(selected) != 1:
                result.update(stage="native_selection_failed",
                              diagnostic="current producer candidates=%d" % len(selected))
            elif resource["resource_stage"] != "source_object_captured":
                result.update(stage="resource_failed", diagnostic=resource["resource_stage"])
            else:
                record = dict(program=selected[0]["symbol"], bpf_object=resource["bpf_object"])
                with contextlib.redirect_stdout(io.StringIO()) as captured:
                    submit.direct("x86", state, Path(selected[0]["native_object"]), record)
                output = captured.getvalue()
                result["submission"] = json.loads(output)
                result["stage"] = result["submission"]["stage"]
                result["diagnostic"] = result["submission"].get("diagnostic",
                                      result["submission"].get("error", ""))
            result["generated"] = result["stage"] in {
                "installed", "verifier_rejected", "compilation_failed", "load_failed"}
            result["compiled"] = result["stage"] in {
                "installed", "verifier_rejected", "load_failed"}
            service_record = result.get("submission", {}).get("service", {})
            captured_archive = service_record.get("artifact_archive", service_record.get("failure_archive"))
            if captured_archive and Path(captured_archive).exists():
                with tarfile.open(captured_archive) as archive:
                    names = archive.getnames()
                    result["generated"] = any(n.endswith("trusted_x86.bpf.c") for n in names)
                    result["compiled"] = result["stage"] != "compilation_failed" and any(
                        n.endswith("trusted_x86.bpf.o") for n in names)
            records.append(result)
            payload = dict(model_head=source["source_head"], attempted=len(records),
                           stages=dict(collections.Counter(r["stage"] for r in records)),
                           native_execution_calls=0,
                           resource_mode="source ELF maps/BTF with autoload=false",
                           programs=records)
            (scratch / "stock-progress.json").write_text(json.dumps(payload, indent=2) + "\n")
            print(result["application"], result["source_prog_id"], result["stage"], flush=True)
        (scratch / "stock-results.json").write_text((scratch / "stock-progress.json").read_text())
    finally:
        service.terminate()
        service.wait()
        log.close()


def namespace(scratch):
    """Reuse the committed model and the completed S17/S18 stock runtime."""
    os.unshare(os.CLONE_NEWNS)
    subprocess.run(["mount", "--make-rprivate", "/"], check=True)
    source = scratch / "source"
    paths = ["kprog/helper_abi.py", "kprog/trusted_generation.py", "kprog/trusted_service.py",
             "kprog/trusted_compile.py", "kprog/selftests/submit.py", "kprog/x86/trusted_specializer.py"]
    paths += [str(p.relative_to(source)) for p in (source / "kprog/x86").glob("*.h")]
    paths += [str(p.relative_to(source)) for p in (source / "kprog/x86/micro-prog").glob("*.py")]
    paths += [str(p.relative_to(source)) for p in (source / "kprog/formal/generated").glob("*.h")]
    for rel in paths:
        subprocess.run(["mount", "--bind", str(source / rel), str(ROOT / rel)], check=True)
    for name in ["libnative_loader.so", "trusted-native-loader"]:
        subprocess.run(["mount", "--bind", str(scratch / "stock-runtime" / name),
                        str(ROOT / "kprog/libnativeloader/build" / name)], check=True)
    compiler = subprocess.Popen([
        sys.executable, str(ROOT / "kprog/trusted_compile.py"), "serve",
        "--scope", str(scratch), "--state", str(scratch / "stock-compiler"),
        "--clang", str(source / "kprog/stock-path/bin/clang")],
        stdout=(scratch / "stock-compiler.log").open("w"), stderr=subprocess.STDOUT)
    try:
        command = ["taskset", "-c", "8-11", "vng", "--run",
                   "/var/tmp/kprog-tmp/S17/x86-build/arch/x86/boot/bzImage",
                   "--cpus", "2", "--memory", "2G",
                   "--rwdir=" + str(scratch) + "=" + str(scratch),
                   "--exec", "bash " + str(scratch / "stock-guest.sh"),
                   "--qemu-opts=-cpu host,+smap"]
        (scratch / "stock-command.json").write_text(json.dumps(command, indent=2) + "\n")
        with (scratch / "stock-console.log").open("w") as output:
            completed = subprocess.run(command, stdout=output, stderr=subprocess.STDOUT)
        (scratch / "stock-guest.exit").write_text(str(completed.returncode) + "\n")
    finally:
        (scratch / "stock-compiler/STOP").touch()
        compiler.wait()



def failure_class(row):
    stage = row["stage"]
    text = row.get("diagnostic", "")
    if stage == "installed":
        return "installed"
    if stage == "native_selection_failed":
        return "native_manifest_selection_gap"
    for phrase, label in [
        ("context layout handler required", "context_lowering"),
        ("invalid write to stack", "verifier_stack_access"),
        ("invalid read from stack", "verifier_stack_access"),
        ("invalid func unknown#-1", "simulator_fault_arm"),
        ("invalid bpf_context access", "verifier_context_access"),
        ("modified ctx ptr", "verifier_context_access"),
        ("invalid access to map value", "verifier_map_bounds"),
        ("unsupported instruction", "instruction_lowering"),
        ("unsupported mnemonic", "instruction_lowering"),
        ("unsupported helper", "helper_lowering"),
        ("unknown helper", "helper_lowering"),
        ("cannot allocate memory", "resource_memory"),
    ]:
        if phrase.lower() in text.lower():
            return label
    return stage


def host(scratch):
    previous = int((scratch / "worker.pid").read_text())
    try:
        descriptor = os.pidfd_open(previous)
        select.select([descriptor], [], [])
        os.close(descriptor)
    except ProcessLookupError:
        pass
    with (scratch / "stock-host.log").open("w") as log:
        done = subprocess.run([sys.executable, str(Path(__file__).resolve()),
                               "namespace", "--scratch", str(scratch)],
                              stdout=log, stderr=subprocess.STDOUT)
    result_path = scratch / "stock-results.json"
    if not result_path.exists():
        (scratch / "stock-setup.json").write_text(json.dumps(
            dict(returncode=done.returncode, result="setup_requires_continuation"),
            indent=2) + "\n")
        return
    result = json.loads(result_path.read_text())
    for row in result["programs"]:
        row["failure_class"] = failure_class(row)
    classes = collections.Counter(row["failure_class"] for row in result["programs"])
    result["ranked_classes"] = [{"failure_class": label, "programs": count}
                               for label, count in classes.most_common()]
    base = ROOT / "corpus/results/kprog_app_coverage_20261109/resident-census"
    base.mkdir(exist_ok=True)
    (base / "stock-results.json").write_text(json.dumps(result, indent=2) + "\n")
    apps = sorted({r["application"] for r in result["programs"]})
    table = ["Resident static census: actual stock-verifier outcomes", "",
             "| Failure class / installed | Programs | Generated | Compiled | Verifier accepted | Verifier rejected | " + " | ".join(apps) + " |",
             "| --- | ---: | ---: | ---: | ---: | ---: | " + " | ".join("---:" for _ in apps) + " |"]
    for label, count in classes.most_common():
        counts = [sum(r["failure_class"] == label and r["application"] == app
                      for r in result["programs"]) for app in apps]
        group = [r for r in result["programs"] if r["failure_class"] == label]
        stages = [sum(r["generated"] for r in group), sum(r["compiled"] for r in group),
                  sum(r["stage"] == "installed" for r in group),
                  sum(r["stage"] == "verifier_rejected" for r in group)]
        table.append("| " + label + " | " + str(count) + " | " +
                     " | ".join(map(str, stages + counts)) + " |")
    table += ["", "Every original instance retains its source ID and actual stage. "
              "Native execution requests:0. Source ELF maps/BTF are prepared with "
              "autoload=false; this static pass retains their declared initial resources. "
              "Application work and performance retain their separate runtime cohorts.",
              "", "Generation, compilation, resource preparation and verifier "
              "diagnostics accompany each row in stock-results.json. "
              "The immutable model revision is " + result["model_head"] + "."]
    (base / "ranked-failures.md").write_text("\n".join(table) + "\n")
    request_directory = base / "requests"
    request_directory.mkdir(exist_ok=True)
    raw_requests = []
    for path in sorted((scratch / "stock-state").glob("*.tar.gz")):
        target = request_directory / path.name
        shutil.copy2(path, target)
        raw_requests.append(target)
    with tarfile.open(base / "stock-raw.tar.gz", "w:gz") as archive:
        for name in ["stock-state/requests.jsonl", "stock-results.json", "stock-console.log",
                     "stock-service.log", "stock-host.log", "stock-guest.exit",
                     "stock-command.json", "stock-guest.sh", "resource-index.json",
                     "stock-runtime", "stock-compiler"]:
            path = scratch / name
            if path.exists():
                archive.add(path, arcname=name)
    spec = importlib.util.spec_from_file_location("census_publish",
        "/var/tmp/kprog-tmp/A/publication/publish.py")
    publisher = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(publisher)
    publication = publisher.publish([str(path.relative_to(ROOT)) for path in
        [base / name for name in ["stock-results.json", "ranked-failures.md", "stock-raw.tar.gz"]] +
        raw_requests],
        "Rank all resident x86 static census outcomes", "resident-stock-terminal")
    (scratch / "stock-publication.json").write_text(json.dumps(publication, indent=2) + "\n")
    with Path("/workspaces/.agent-state/kprog-lanes/COORDINATION.md").open("a") as notice:
        notice.write("\n- LOCAL A FOR C/R/COORDINATOR " +
                     datetime.datetime.now(datetime.timezone.utc).isoformat() +
                     ": PUSHED " + publication["commit"] + " resident static stock census " +
                     json.dumps(dict(classes)) + ". Every actual stage/source/context/raw "
                     "retained; native execution requests0. Ranked table published before "
                     "the largest-class generic fix. Model" + result["model_head"] + ".\n")

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("mode", choices=["guest", "namespace", "compile", "host"])
    parser.add_argument("--scratch", type=Path,
                        default=Path("/var/tmp/kprog-tmp/A/resident-census"))
    args, rest = parser.parse_known_args()
    if args.mode == "compile":
        sys.path.insert(0, str(ROOT / "kprog"))
        from trusted_compile import submit
        return submit(args.scratch / "stock-compiler",
                      Path(rest[rest.index("-c") + 1]),
                      Path(rest[rest.index("-o") + 1]), "x86")
    if args.mode == "host":
        host(args.scratch)
    elif args.mode == "guest":
        guest(args.scratch)
    else:
        namespace(args.scratch)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
