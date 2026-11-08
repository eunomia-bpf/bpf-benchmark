#!/usr/bin/env python3
"""Submit the compiled selftest programs through the five-step path.

`selftests.py` enumerates the kernel's annotated programs and compiles the C
ones to native x86-64.  This script takes those objects, loads the matching
BPF program the way an application does, and submits it through the trusted
native path, then compares the outcome with the kernel's own annotation.

The comparison is the whole point:

  * a `__failure` program that loads and runs means the native path accepts
    something the verifier must reject -- a faithfulness defect;
  * a `__success` program the verifier rejects means the path lost a
    program the kernel accepts;
  * a program that never reaches the verifier (compile, generation) is
    coverage, not agreement.

Each program is run the way an application loads it: the BPF object is
loaded first (`micro_exec run-native-kernel --program ...`), which is what
gives the loader an `original_prog_fd` and a source bytecode to bind
against, with `--native-program` naming the object compiled from the same
source.

Usage: submit.py [--table DIR] [--out DIR] [--limit N] [--only NAME]
"""

import argparse
import json
import os
import pathlib
import re
import subprocess
import sys
import tempfile

ROOT = pathlib.Path(__file__).resolve().parents[2]
DEFAULT_TABLE = ROOT / "kprog/selftests/build"


def run(cmd, cwd=None, timeout=120):
    """Run one submission; returns (returncode, stdout, stderr)."""
    try:
        done = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True,
                              timeout=timeout)
        return done.returncode, done.stdout, done.stderr
    except subprocess.TimeoutExpired:
        return 124, "", "timeout after %ds" % timeout


# `micro_exec`'s stub type has to match the object's own program type, and
# it names them as the CLI does rather than by number.
KIND = {3: "sched_cls", 6: "xdp", 8: "cgroup_skb"}


def program_type(micro_exec, obj):
    """The libbpf program type number of the object's single program."""
    rc, so, se = run([micro_exec, "list-programs", "--program", str(obj)],
                     timeout=60)
    if rc != 0:
        return None
    try:
        return json.loads(so)[0]["prog_type"]
    except (ValueError, KeyError, IndexError):
        return None


def start_service(arch=1):
    """Start the trusted service the kernel hands each job to.

    The kernel end queues a submission and waits for a registered service to
    specialize it, so without one every load ends in ENOTCONN.
    """
    endpoint = pathlib.Path("/sys/kernel/debug/bpf_x86_native_lab/specializer")
    if not endpoint.exists():
        return None, None
    state = pathlib.Path(tempfile.mkdtemp(prefix="trusted-"))
    proc = subprocess.Popen(
        [sys.executable, str(ROOT / "kprog/trusted_service.py"),
         "--arch", str(arch), "--endpoint", str(endpoint),
         "--state", str(state),
         "--native-link",
         str(ROOT / "kprog/x86/native_lab/native_link/target/release/"
             "native-link"),
         "--loader", str(ROOT / "kprog/libnativeloader/build/"
                             "trusted-native-loader")],
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    line = proc.stdout.readline()
    try:
        if not json.loads(line)["ready"]:
            return None, proc
    except (ValueError, KeyError):
        return None, proc
    return proc, proc


# A rejection only means something if the native path was reached.  When
# the companion BPF object fails to load, the loader never submits, so the
# program agrees with its annotation for a reason that says nothing about
# the native path.
COMPANION = "companion bpf_object__load failed"


def classify(rc, stderr):
    """What happened to one program, in terms of what the path exercised."""
    if rc == 0:
        return "ran"
    if COMPANION in stderr:
        return "companion-failed"
    return "refused"


def program_names(micro_exec, obj):
    """The programs one object holds, by name.

    `micro_exec` runs exactly one program per object, so an object with
    several must be skipped until it can be split: the kernel collects
    unrelated programs in one file, and libbpf enumerates them from BTF
    rather than the ELF section, so filtering the section is not enough.
    """
    rc, so, se = run([micro_exec, "list-programs", "--program", str(obj)],
                     timeout=60)
    if rc != 0:
        return []
    try:
        return [p["name"] for p in json.loads(so)]
    except (ValueError, KeyError):
        return []


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--table", default=str(DEFAULT_TABLE))
    ap.add_argument("--out", default=str(ROOT / "kprog/selftests/results"))
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--only", default="")
    ap.add_argument("--micro-exec",
                    default=str(ROOT / "runner/build-llvmbpf/micro_exec"))
    args = ap.parse_args(argv[1:])

    table = pathlib.Path(args.table) / "programs.json"
    out = pathlib.Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    rows = json.load(open(table))["programs"]

    # Submit only programs whose file compiled and whose entry symbol is
    # present: a program without a native entry has nothing to bind.
    work = [r for r in rows
            if r["body"] == "c" and r.get("compiled") and r.get("entry")]
    if args.only:
        work = [r for r in work if args.only in r["program"]]
    if args.limit:
        work = work[:args.limit]

    service, _ = start_service()
    if service is None:
        print("no trusted service: the kernel endpoint is absent",
              file=sys.stderr)
        return 1

    results = []
    skipped = []
    for r in work:
        src = pathlib.Path(r["path"])
        bpf = pathlib.Path(r.get("bpf_object") or "")
        obj = pathlib.Path(args.table) / (src.stem + ".native.o")
        names = program_names(args.micro_exec, bpf)
        if len(names) != 1 or names[0] != r["program"]:
            # Several programs share the object, or the entry name differs
            # from the object's only program.
            skipped.append(dict(file=r["file"], program=r["program"],
                                expect=r["expect"], programs=names,
                                reason=("object holds %d programs" % len(names)
                                        if len(names) != 1
                                        else "name mismatch")))
            continue
        kind = KIND.get(program_type(args.micro_exec, bpf))
        if kind is None:
            # The stub is created for one of three types; another type
            # would be rejected, so record why instead of guessing.
            skipped.append(dict(file=r["file"], program=r["program"],
                                expect=r["expect"],
                                programs=names, reason="unsupported type"))
            continue
        cmd = [args.micro_exec, "run-native-kernel", "--program", str(bpf),
               "--native-program", str(obj), "--inner-repeat", "1",
               "--native-kernel-prog-type", kind]
        rc, so, se = run(cmd, timeout=120)
        results.append(dict(file=r["file"], program=r["program"],
                            section=r["section"], expect=r["expect"],
                            returncode=rc,
                            outcome=classify(rc, se),
                            stdout=so[-600:], stderr=se[-600:]))

    service.terminate()
    counts = {"submitted": len(results), "skipped": len(skipped)}
    for outcome in ("ran", "refused", "companion-failed"):
        counts[outcome] = sum(1 for x in results if x["outcome"] == outcome)
    # Agreement counts only the programs whose native path actually ran:
    # a companion failure decides the outcome before the native path is
    # involved, so counting it as agreement would claim the path agreed
    # with an annotation it was never compared against.
    for want in ("failure", "success"):
        sel = [x for x in results if x["expect"] == want
               and x["outcome"] != "companion-failed"]
        counts[want] = len(sel)
        counts[want + "_agrees"] = sum(
            1 for x in sel
            if (want == "failure") == (x["outcome"] == "refused"))
    json.dump(dict(counts=counts, programs=results, skipped=skipped),
              open(out / "submissions.json", "w"), indent=1)
    print(json.dumps(counts, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))