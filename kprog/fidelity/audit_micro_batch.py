#!/usr/bin/env python3
"""Read standard micro batch outcomes and registered-service receipts offline."""
import argparse
from collections import Counter
import hashlib
import io
import json
from pathlib import Path
import subprocess
import tarfile
import yaml


def sha(data):
    return hashlib.sha256(data).hexdigest()


def read_json(archive, member):
    return json.loads(archive.extractfile(member).read())


def open_service(path):
    outer = tarfile.open(path)
    if "service/service.log" in outer.getnames():
        return outer
    files = [m for m in outer.getmembers() if m.isfile()]
    assert len(files) == 1, "expected a single service archive wrapper"
    data = outer.extractfile(files[0]).read()
    outer.close()
    return tarfile.open(fileobj=io.BytesIO(data))


def audit(raw_path, service_path, suite_path, publication, original_path):
    root = Path(__file__).resolve().parents[2]
    paths = [raw_path, service_path, suite_path]
    if original_path:
        paths.append(original_path)
    identities = {str(p.relative_to(root)): sha(p.read_bytes()) for p in paths}
    for path in [raw_path, service_path, suite_path]:
        rel = str(path.relative_to(root))
        committed = subprocess.check_output(["git", "show", publication + ":" + rel], cwd=root)
        assert sha(committed) == identities[rel], rel
    config = yaml.safe_load(suite_path.read_text())
    expected = {
        b["name"]: (b["expected_result"], b.get("expected_retval",
                      config["benchmark_defaults"]["expected_retval"]))
        for b in config["benchmarks"]
    }
    with tarfile.open(raw_path) as raw:
        members = [m for m in raw.getnames() if m.endswith("/details/result.json")]
        assert len(members) == 1, members
        result_bytes = raw.extractfile(members[0]).read()
        result = json.loads(result_bytes)
        prefix = members[0].removesuffix("/details/result.json")
        metadata = read_json(raw, prefix + "/metadata.json")
        driver_exit = int(raw.extractfile("driver/run.exit").read())
        running = read_json(raw, "driver/running-inputs.json")
        launch_hashes = running["sha256"]
        snapshots = {}
        for member in raw.getmembers():
            if member.isfile() and member.name.startswith(
                    ("driver/source-pins/", "final-source/")):
                value = sha(raw.extractfile(member).read())
                snapshots[member.name] = value
                if member.name.startswith("driver/source-pins/"):
                    source = member.name.removeprefix("driver/source-pins/")
                    if source in launch_hashes:
                        assert value == launch_hashes[source], source
    assert len(result["benchmarks"]) == len(expected)
    assert {b["name"] for b in result["benchmarks"]} == set(expected)
    samples = Counter()
    observed = []
    for bench in result["benchmarks"]:
        want = expected[bench["name"]]
        assert (bench["expected_result"], bench["expected_retval"]) == want
        for run in bench["runs"]:
            for sample in run["samples"]:
                assert (sample["result"], sample["retval"]) == want
                samples[run["runtime"]] += 1
                observed.append(dict(benchmark=bench["name"], runtime=run["runtime"],
                    inner_repeat=run["inner_repeat"], sample_index=sample["sample_index"],
                    result=sample["result"], retval=sample["retval"]))
    originals = {}
    if original_path:
        with tarfile.open(original_path) as source:
            for m in source.getmembers():
                if m.name.startswith("request-") and m.name.endswith("/kernel.native.o"):
                    prefix = m.name.rsplit("/", 1)[0]
                    entry = source.extractfile(prefix + "/kernel.entry").read().decode().strip()
                    assert entry not in originals
                    originals[entry] = source.extractfile(m).read()
    stages, identity_sets = Counter(), {}
    records, request_ids, source_ids, bound_ids = [], set(), set(), set()
    with open_service(service_path) as service:
        lifecycle = read_json(service, "service/summary.json")
        log = [json.loads(l) for l in service.extractfile("service/service.log").read().splitlines()]
        requests = [r for r in log if "request_id" in r]
        archives = {m for m in service.getnames()
                    if m.startswith("service/requests/") and m.endswith(".tar.gz")}
        consumed = set()
        for row in requests:
            assert row["request_id"] > 0 and row["request_id"] not in request_ids
            assert row["source_prog_id"] > 0
            request_ids.add(row["request_id"])
            source_ids.add(row["source_prog_id"])
            key = "artifact_archive" if row["status"] == 0 else "failure_archive"
            member = "service/requests/" + Path(row[key]).name
            assert member not in consumed
            consumed.add(member)
            payload = service.extractfile(member).read()
            with tarfile.open(fileobj=io.BytesIO(payload)) as request:
                native = request.extractfile("request/kernel.native.o").read()
                generated = request.extractfile("request/generated/request.native.o").read()
                entry = request.extractfile("request/kernel.entry").read().decode().strip()
                assert native == generated and sha(native) == row["native_sha256"]
                if originals:
                    assert native == originals[entry]
                facts = read_json(request, "request/kernel.facts.json")
                assert facts["id"] == row["source_prog_id"]
                commands = [json.loads(l) for l in
                    request.extractfile("request/generated/commands.jsonl").read().splitlines()]
                identities_now = read_json(request, "request/source-identities.json")
                identity_key = sha(json.dumps(identities_now, sort_keys=True).encode())
                identity_sets[identity_key] = identities_now
                record = {k: row[k] for k in
                          ["request_id", "source_prog_id", "native_sha256", "status"]}
                record.update(entry=entry, request_archive_sha256=sha(payload),
                    source_identity_set_sha256=identity_key,
                    command_returns=[dict(executable=Path(c["command"][0]).name,
                        returncode=c["returncode"]) for c in commands])
                if row["status"] == 0:
                    assert commands and all(c["returncode"] == 0 for c in commands)
                    assert any("-target" in c["command"] and "bpf" in c["command"] for c in commands)
                    load = read_json(request, "request/load.stdout")
                    assert load == {k: row[k] for k in ["request_id", "prog_id", "status"]}
                    assert row["prog_id"] > 0 and row["prog_id"] not in bound_ids
                    bound_ids.add(row["prog_id"])
                    objects = [m for m in request.getmembers() if
                               m.name.startswith("request/generated/trusted_") and
                               m.name.endswith(".bpf.o") and m.size > 0]
                    assert len(objects) == 1
                    record.update(stage="bound", bound_prog_id=row["prog_id"],
                                  compiled_object_sha256=sha(request.extractfile(objects[0]).read()))
                elif any(c["returncode"] for c in commands):
                    record.update(stage="compiler_error", service_error=row["error"])
                else:
                    text = request.extractfile("request/load.stderr").read().decode()
                    record.update(stage="loader_rejected", service_error=row["error"],
                                  loader_stderr=text)
                stages[record["stage"]] += 1
                records.append(record)
        assert archives == consumed
    return dict(source_publication=publication, input_sha256=identities,
        raw_result_sha256=sha(result_bytes), benchmarks=len(expected),
        launch_input_hashes=launch_hashes, captured_source_snapshots=snapshots,
        runtime_image_identity=running["image"],
        metadata_status=metadata["status"], driver_exit=driver_exit,
        samples_by_runtime=dict(samples), exact_result_and_retval_samples=len(observed),
        request_stages=dict(stages), terminal_requests=len(records),
        native_identity_matches=len(records),
        original_native_identity_matches=len(records) if originals else None,
        distinct_source_ids=len(source_ids), distinct_bound_ids=len(bound_ids),
        source_identity_sets=identity_sets, service_lifecycle=lifecycle,
        observations=observed, receipts=records,
        scope="Batch execution observations through the common service. Universal safety theorems retain their formal evidence path.")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for arg in ["raw", "service", "suite", "out"]:
        parser.add_argument("--" + arg, required=True, type=Path)
    parser.add_argument("--publication", required=True)
    parser.add_argument("--original-native-archive", type=Path)
    args = parser.parse_args()
    report = audit(args.raw.resolve(), args.service.resolve(), args.suite.resolve(),
                   args.publication, args.original_native_archive.resolve()
                   if args.original_native_archive else None)
    args.out.write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps({k: report[k] for k in ["benchmarks", "samples_by_runtime",
        "request_stages", "native_identity_matches", "distinct_bound_ids"]}))


if __name__ == "__main__":
    main()
