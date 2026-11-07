#!/usr/bin/env python3
"""Check existing standard-micro raw results and every fresh service archive."""
from pathlib import Path
import hashlib
import io
import json
import tarfile
import yaml

ROOT = Path(__file__).resolve().parents[5]
OUT = Path(__file__).resolve().parent
SOURCE = ROOT / "corpus/results/kprog_app_coverage_20261107/native-only-micro"
PINNED = {
    "raw.tar.gz": "0a031f6fd5606e776373946b9d580ebddc46a35ad29b610790f614b038026cb1",
    "service-requests.tar.gz": "3e7638c1725f1f1ff1cba7bbfd262c0ac29d368fb9e28942926cb3b000ef0e7f",
}
def digest(raw):
    return hashlib.sha256(raw).hexdigest()
def read_json(archive, name):
    return json.loads(archive.extractfile(name).read())
for name, expected in PINNED.items():
    assert digest((SOURCE / name).read_bytes()) == expected, name
config_path = ROOT / "micro/config/micro_stage2.yaml"
config = yaml.safe_load(config_path.read_text())
expected = {b["name"]: (b["expected_result"], config["benchmark_defaults"]["expected_retval"])
            for b in config["benchmarks"]}
assert len(expected) == 13
with tarfile.open(SOURCE / "raw.tar.gz") as raw:
    result_bytes = raw.extractfile("micro-result/details/result.json").read()
    result = json.loads(result_bytes)
    metadata = read_json(raw, "micro-result/metadata.json")
    assert metadata["status"] == "completed"
    assert raw.extractfile("driver/run.exit").read().strip() == b"0"
    runner_sha = digest(raw.extractfile("driver/image-context/runner/build-llvmbpf/micro_exec").read())
    supervisor_sha = digest(raw.extractfile("driver/runtime-service.py").read())
    final_supervisor_sha = digest(raw.extractfile("final-source/kprog/trusted_service.py").read())
    header_sha = digest(raw.extractfile("final-source/kprog/x86/x86_sim_local_bpf.h").read())
assert header_sha == "d30d4ff18738cc24ab19776b986bc340fe8a4b8d6a539f4e0bb3008de3895327"
assert {b["name"] for b in result["benchmarks"]} == set(expected)
assert len(result["benchmarks"]) == 13
benchmarks = {}
for bench in result["benchmarks"]:
    name = bench["name"]
    wanted = expected[name]
    assert (bench["expected_result"], bench["expected_retval"]) == wanted
    assert len(bench["runs"]) == 3
    values = {}
    for run in bench["runs"]:
        assert run["inner_repeat"] == 1 and len(run["samples"]) == 1
        sample = run["samples"][0]
        assert isinstance(sample["result"], int) and isinstance(sample["retval"], int)
        assert (sample["result"], sample["retval"]) == wanted
        assert run["runtime"] not in values
        values[run["runtime"]] = {"result": sample["result"], "retval": sample["retval"]}
    assert set(values) == {"kernel", "native_kernel", "native_proof"}
    benchmarks[name] = {"expected_result": wanted[0], "expected_retval": wanted[1],
                        "runtimes": values, "requests": []}
source_sets = {}
request_ids, bound_ids, source_ids = set(), set(), set()
with tarfile.open(SOURCE / "service-requests.tar.gz") as service:
    lifecycle = read_json(service, "service/summary.json")
    assert lifecycle["service"]["ready"] and lifecycle["returncode"] == 0
    records = [json.loads(line) for line in service.extractfile("service/service.log").read().splitlines()]
    requests = [r for r in records if "request_id" in r]
    archive_names = [n for n in service.getnames() if n.startswith("service/requests/") and n.endswith(".tar.gz")]
    assert len(requests) == len(archive_names) == 26
    for row in requests:
        assert row["status"] == 0
        for field, seen in [("request_id", request_ids), ("prog_id", bound_ids), ("source_prog_id", source_ids)]:
            assert row[field] > 0 and row[field] not in seen
            seen.add(row[field])
        archive_name = "service/requests/" + Path(row["artifact_archive"]).name
        payload = service.extractfile(archive_name).read()
        with tarfile.open(fileobj=io.BytesIO(payload)) as request:
            native = request.extractfile("request/kernel.native.o").read()
            generated = request.extractfile("request/generated/request.native.o").read()
            assert digest(native) == digest(generated) == row["native_sha256"]
            artifacts = read_json(request, "request/generated/artifacts.json")
            name = artifacts["symbol"]
            assert name in benchmarks and artifacts["native_sha256"] == row["native_sha256"]
            assert request.extractfile("request/kernel.entry").read().decode().strip() == name
            load = read_json(request, "request/load.stdout")
            assert load == {k: row[k] for k in ["request_id", "prog_id", "status"]}
            commands = [json.loads(line) for line in request.extractfile("request/generated/commands.jsonl").read().splitlines()]
            assert commands and all(c["returncode"] == 0 for c in commands)
            assert any("-target" in c["command"] and "bpf" in c["command"] for c in commands)
            assert request.getmember("request/generated/trusted_x86.bpf.o").size > 0
            identities = read_json(request, "request/source-identities.json")
            assert identities[str(ROOT / "kprog/x86/x86_sim_local_bpf.h")] == header_sha
            identity = digest(json.dumps(identities, sort_keys=True).encode())
            source_sets[identity] = identities
            facts = read_json(request, "request/kernel.facts.json")
            assert facts["id"] == row["source_prog_id"]
            benchmarks[name]["requests"].append({
                "request_id": row["request_id"], "source_prog_id": row["source_prog_id"],
                "bound_prog_id": row["prog_id"], "native_sha256": row["native_sha256"],
                "request_archive_sha256": digest(payload), "source_identity_set_sha256": identity,
                "map_count": len(facts["maps"]), "fresh_compile_commands": len(commands),
            })
for name, bench in benchmarks.items():
    assert len(bench["requests"]) == 2, name
    assert len({r["native_sha256"] for r in bench["requests"]}) == 1, name
report = {
    "run": "x86_kvm_micro_20261107_173730_247516",
    "source_publication": "aaf7b9dc425f00ef9ee1f3e18ef0a5ef70e65201",
    "archives": PINNED, "raw_result_sha256": digest(result_bytes),
    "suite_sha256": digest(config_path.read_bytes()),
    "benchmarks_checked": 13, "exact_result_and_retval_samples": 39,
    "fresh_successful_requests": 26, "distinct_bound_program_ids": len(bound_ids),
    "kernel_to_generated_native_identity_matches": 26,
    "service_ready": lifecycle["service"]["ready"],
    "application_returncode": lifecycle["returncode"],
    "service_teardown_returncode": lifecycle["service_returncode"],
    "captured_runner_sha256": runner_sha,
    "captured_supervisor_sha256": supervisor_sha,
    "final_supervisor_sha256": final_supervisor_sha,
    "source_identity_sets": source_sets, "benchmarks": benchmarks,
    "scope": "independent reanalysis of existing raw functional run; no new execution or timing claim",
}
(OUT / "results.json").write_text(json.dumps(report, indent=2) + "\n")
print("13 benchmarks / 39 exact samples / 26 fresh compiled requests / 26 native-identity matches")
