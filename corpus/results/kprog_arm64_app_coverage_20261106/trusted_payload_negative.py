"""Run the existing 34 ARM native-only safety cases on the private candidate."""
import hashlib
import json
from pathlib import Path
import shutil
import sys
import tarfile

import trusted_payload_check as candidate

ROOT = candidate.ROOT
HERE = candidate.HERE
OUT = HERE / "trusted-bcc-frame-result/payload-negative"
BUILD = ROOT / "kprog/arm64/build/trusted-transport/payload-safety-inputs"
ORIGINAL = ROOT / "kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp"


def prepare():
    BUILD.mkdir(exist_ok=True)
    OUT.mkdir(exist_ok=True)
    rows = json.loads((ORIGINAL / "cases.json").read_text())
    source = ROOT / "kprog/formal/build/fidelity-trusted-arm64"
    pins = {}
    for name in ["bound-probe", "context_array.bpf.o", "context_hash.bpf.o"] + [r["name"] + ".native.o" for r in rows]:
        old, new = source / name, BUILD / name
        shutil.copyfile(old, new)
        shutil.copymode(old, new)
        pins[name] = hashlib.sha256(new.read_bytes()).hexdigest()
    for row in rows:
        assert row["native_sha256"] == pins[row["name"] + ".native.o"]
        manifest = json.loads(Path(row["manifest"]).read_text())
        manifest["objects"][0]["native_object"] = str(BUILD / (row["name"] + ".native.o"))
        path = BUILD / (row["name"] + ".manifest.json")
        path.write_text(json.dumps(manifest, indent=2) + "\n")
        row["manifest"] = str(path)
    (BUILD / "cases.json").write_text(json.dumps(rows, indent=2) + "\n")
    (BUILD / "input-pins.json").write_text(json.dumps(pins, indent=2) + "\n")
    with tarfile.open(OUT / "inputs.tar.gz", "w:gz") as archive:
        for p in sorted(BUILD.iterdir()):
            archive.add(p, arcname=p.name)


def guest(live):
    suite = candidate.load_module("compact_native_safety", ROOT / "kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/check.py")
    suite.ARCH, suite.BUILD, suite.OUT = "arm64", BUILD, live
    rows = json.loads((BUILD / "cases.json").read_text())
    (live / "cases.json").write_text(json.dumps(rows, indent=2) + "\n")
    suite.cases = lambda: rows
    classify = suite.classify

    def stage(record):
        trace = record.get("traceback", "")
        if "ValueError:" in trace and str(candidate.CANDIDATE / "arm64_abi.py") in trace:
            return "specialization_rejected", record["error"]
        return classify(record)

    suite.classify = stage
    popen = suite.subprocess.Popen

    def start(command, *args, **kwargs):
        if len(command) > 1 and Path(command[1]) == ROOT / "kprog/trusted_service.py":
            command = [command[0], str(HERE / "trusted_payload_check.py"), "service", *command[2:]]
        return popen(command, *args, **kwargs)

    suite.subprocess.Popen = start
    try:
        suite.check()
    finally:
        path = live / "outcomes.json"
        outcomes = json.loads(path.read_text()) if path.exists() else []
        accepted = sum(r["stage"] == "accepted_finding" for r in outcomes)
        ok = len(outcomes) == len(rows) and all(r["stage"] in {
            "valid_executed", "verifier_rejected", "specialization_rejected", "loader_rejected", "compiler_rejected"} for r in outcomes)
        (live / "guest.json").write_text(json.dumps(dict(ok=ok, cases=len(outcomes), expected_cases=len(rows), accepted_unsafe=accepted), indent=2) + "\n")


def main():
    if sys.argv[1:] == ["host"]:
        prepare()
        transport = candidate.transport()
        transport.HERE, transport.__file__ = OUT, __file__
        transport.host()
    elif len(sys.argv) in (3, 4) and sys.argv[1] == "guest":
        guest(Path(sys.argv[2]))
    else:
        raise SystemExit("usage: trusted_payload_negative.py host | guest LIVE [control]")


if __name__ == "__main__":
    main()
