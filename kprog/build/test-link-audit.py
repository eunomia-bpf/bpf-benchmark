#!/usr/bin/env python3
"""Exercise audit transport against actual linker proof/kernel/error commands."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import tempfile


FLAGS = ["--runtime-map-lookups", "--local-memory-routines", "--runtime-known-map-lookups"]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--payload", type=Path, required=True)
    parser.add_argument("--evidence", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--scratch", type=Path, required=True)
    parser.add_argument("--replay", type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    args.scratch.mkdir(parents=True, exist_ok=True)
    attempt = Path(tempfile.mkdtemp(prefix="attempt-", dir=args.output))
    scratch = Path(tempfile.mkdtemp(prefix="attempt-", dir=args.scratch))
    binary = args.payload / "native-link.real"
    wrapper = args.payload / "native-link-on"
    source = args.evidence / "reference.proof.o"
    inventory = json.loads((args.evidence.parent / "report.json").read_text())
    native_source = Path(next(row["input"] for row in inventory["cases"] if row["label"] == "otel"))
    plan = args.evidence / "synthetic-plan.json"
    rows = []
    # The /proc/self/fd form catches accidental closure of inherited descriptors.
    with source.open("rb") as stream, native_source.open("rb") as native_stream:
        for mode, name in [("proof", "native_tracer_entry"), ("kernel", "native_tracer_entry"),
                           ("kernel", "entry_that_does_not_exist")]:
            label = mode + "-" + name
            current_source = native_source if mode == "proof" else source
            fd = native_stream.fileno() if mode == "proof" else stream.fileno()
            before = set((args.payload / "audit").glob("link-*")) if (args.payload / "audit").exists() else set()
            argv = ["--mode", mode, "--input", f"/proc/self/fd/{fd}", "--symbol", name,
                    "--link-plan=" + str(plan)]
            files = [("--output", "image")]
            if mode == "kernel":
                files += [("--output-relocs", "relocs"),
                          ("--output-map-patches", "maps"), ("--output-abi", "abi")]
            for flag, suffix in files:
                argv += [flag, str(scratch / (label + "." + suffix))]
            reference = subprocess.run([str(binary), *FLAGS, *argv],
                                       capture_output=True, pass_fds=(fd,))
            (attempt / (label + ".reference-command.json")).write_text(json.dumps(dict(
                command=[str(binary), *FLAGS, *argv], returncode=reference.returncode,
                stdout=reference.stdout.decode(), stderr=reference.stderr.decode()), indent=2) + "\n")
            assert reference.returncode == (1 if name == "entry_that_does_not_exist" else 0), label
            reference_files = {}
            for flag, suffix in files:
                path = scratch / (label + "." + suffix)
                if path.is_file():
                    reference_files[suffix] = path.read_bytes()
                    (attempt / (label + ".reference." + suffix)).write_bytes(path.read_bytes())
            env = dict(os.environ, KPROG_LINK_AUDIT_LABEL="host-regression-synthetic-plan")
            actual = subprocess.run([str(wrapper), *argv], capture_output=True,
                                    pass_fds=(fd,), env=env)
            assert (actual.returncode, actual.stdout, actual.stderr) == (
                reference.returncode, reference.stdout, reference.stderr), label
            new = set((args.payload / "audit").glob("link-*")) - before
            assert len(new) == 1, (label, new)
            directory = new.pop()
            record = json.loads((directory / "result.json").read_text())
            assert record["returncode"] == actual.returncode
            assert (directory / "input.elf").read_bytes() == current_source.read_bytes()
            assert (directory / "link-plan.json").read_bytes() == plan.read_bytes()
            assert record["input"]["sha256"] == hashlib.sha256(current_source.read_bytes()).hexdigest()
            if actual.returncode == 0:
                for flag, suffix in files:
                    audited = scratch / (label + "." + suffix)
                    if suffix not in reference_files:
                        assert not record["outputs"][suffix]["exists"] and not audited.exists()
                        continue
                    assert reference_files[suffix] == audited.read_bytes(), (label, suffix)
                    (attempt / (label + ".audit." + suffix)).write_bytes(audited.read_bytes())
                    assert (directory / record["outputs"][suffix]["capture"]).read_bytes() == reference_files[suffix]
            else:
                assert actual.returncode == 1, label
                assert not record["outputs"]["image"]["exists"]
            rows.append(dict(case=label, returncode=actual.returncode, capture=str(directory),
                             identical_exit_stdout_stderr=True, inherited_fd_preserved=True,
                             identical_emitted_files=actual.returncode == 0))
    incomplete = attempt / "incomplete-input"
    (incomplete / "link-incomplete").mkdir(parents=True)
    replay_output = attempt / "incomplete-replay"
    subprocess.run(["python3", str(args.replay), str(incomplete), "--linker", str(binary),
                    "--output", str(replay_output)], check=True)
    incomplete_report = json.loads((replay_output / "report.json").read_text())
    assert len(incomplete_report["cases"]) == 1
    assert incomplete_report["cases"][0]["completed_capture"] is False
    (attempt / "report.json").write_text(json.dumps(dict(
        cases=rows, incomplete_capture_reported=True,
        scope="Actual CLI transport/capture regressions, synthetic host plan only; no kernel execution."), indent=2) + "\n")


if __name__ == "__main__":
    main()
