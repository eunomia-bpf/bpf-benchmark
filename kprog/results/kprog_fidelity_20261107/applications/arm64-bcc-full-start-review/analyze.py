"""Recheck the closed ARM BCC archive; does not launch or alter a guest."""
from pathlib import Path
import hashlib, io, json, re, subprocess, tarfile

ROOT = Path(__file__).resolve().parents[5]
ARCHIVE = Path("corpus/results/kprog_arm64_app_coverage_20261106/bcc-full-start/trusted-arm64-bcc-result/run-20261107T172354861230Z.tar.gz")
COMMIT = "5d6d067cfd55a627d7f367054decc72e09bb7e51"
EXPECTED_SHA = "70369c4760749672015fe1a8a1a6c2970e5a6d240c6a17eab42acf23148aeeda"

def sha(data):
    return hashlib.sha256(data).hexdigest()

def main():
    raw = (ROOT / ARCHIVE).read_bytes()
    assert sha(raw) == EXPECTED_SHA
    assert raw == subprocess.check_output(["git", "show", f"{COMMIT}:{ARCHIVE}"], cwd=ROOT)
    reviewed = []
    with tarfile.open(fileobj=io.BytesIO(raw)) as outer:
        def read(name):
            return outer.extractfile(name).read()
        app_path = next(m.name for m in outer.getmembers()
                        if "/details/apps/" in m.name and m.name.endswith(".json"))
        app = json.loads(read(app_path))
        rows = [json.loads(line) for line in read("run/requests/requests.jsonl").splitlines()]
        archives = {int(m.name.split("/")[-1].split(".")[0]): m.name
                    for m in outer.getmembers()
                    if re.fullmatch(r"run/requests/\d+\.(success|failure)\.tar\.gz", m.name)}
        assert len(rows) == len(archives) == 19
        assert {r["request_id"] for r in rows} == set(archives)
        for row in rows:
            data = read(archives[row["request_id"]])
            with tarfile.open(fileobj=io.BytesIO(data)) as request:
                def req(name):
                    return request.extractfile("request/" + name).read()
                native = req("kernel.native.o")
                assert sha(native) == row["native_sha256"]
                assert req("generated/request.native.o") == native
                facts = json.loads(req("kernel.facts.json"))
                metadata = json.loads(req("kernel.metadata.json"))
                generation = json.loads(req("generation.metadata.json"))
                assert facts["id"] == row["source_prog_id"]
                assert generation["prog_type"] == facts["prog_type"]
                assert all(facts[k] == v for k, v in metadata["load_context"].items())
                stdout = req("load.stdout").decode()
                stderr = req("load.stderr").decode()
                entry = req("kernel.entry").decode().strip("\x00\n")
                proof = req("generated/trusted_arm64.proof.o")
                if row["status"] == 0:
                    loaded = json.loads(stdout)
                    assert loaded["status"] == 0 and loaded["prog_id"] == row["prog_id"]
                    assert loaded["request_id"] == row["request_id"]
                    diagnostic = []
                else:
                    diagnostic = [line for line in stderr.splitlines()
                                  if "infinite loop" in line or line.startswith(("processed ", "stub_load_error_summary="))]
                    assert any("infinite loop" in line for line in diagnostic)
                reviewed.append(dict(request_id=row["request_id"], entry=entry,
                    source_prog_id=row["source_prog_id"], bound_prog_id=row.get("prog_id"),
                    status=row["status"], native_sha256=sha(native), proof_sha256=sha(proof),
                    kernel_equals_generated_native=True, load_context_matches=True,
                    source_identities_sha256=sha(req("source-identities.json")),
                    archive_sha256=sha(data), verifier_diagnostics=diagnostic))
        work = json.loads(read("run/work.json"))
        assert work["completed_requests"] == rows
        guest = json.loads(read("run/guest.json"))
        drift = json.loads(read("run/service-source-drift.json"))
        workloads = app["baseline"]["workloads"]
        assert len(workloads) == 1 and workloads[0]["returncode"] == 0
        metrics = re.findall(r"stress-ng: metrc: \[\d+\]\s+(syscall|cap|set|sockfd)\s+(\d+)\s", workloads[0]["stdout"])
        assert len(metrics) == 4
        assert app["post_rejit"] is None and app["status"] == "error" and guest["ok"] is False
        return dict(source_commit=COMMIT, source_archive=str(ARCHIVE), archive_sha256=sha(raw),
            raw_app_member=app_path, raw_guest_exit=int(read("run/guest.exit")),
            app_status=app["status"], app_error_first_line=app["error"].splitlines()[0],
            framework_rejit_status=app["rejit_result"], post_rejit_sample=app["post_rejit"],
            baseline_programs=app["baseline"]["bpf"],
            baseline_stressor_bogo_ops={name:int(count) for name,count in metrics},
            baseline_workload_returncode=workloads[0]["returncode"],
            baseline_workload_command=workloads[0]["command"], request_count=len(reviewed),
            bound_request_count=sum(r["status"] == 0 for r in reviewed),
            refused_request_count=sum(r["status"] != 0 for r in reviewed), requests=reviewed,
            successful_bound_ids_distinct=len({r["bound_prog_id"] for r in reviewed if r["status"] == 0}),
            completed_post_rejit_workload_samples=0, source_drift_record=drift,
            execution_boundary="No completed post_rejit sample; partial startup may have executed hooks. This does not establish zero native executions.",
            coverage_boundary="19 service requests and 23 baseline programs are different inventories; this review does not claim 16/23 coverage or a complete native application run.",
            clock_boundary="Guest timestamps start in 1970; QEMU counters are functional evidence, not hardware performance.")
if __name__ == "__main__":
    print(json.dumps(main(), indent=2))
