#!/usr/bin/env python3
"""Why each refused `__success` program was refused.

The task splits a rejected `__success` program between the native compile
and the simulator, so each rejection is read from the artifact the service
archived for its own request: the generator's failing command when
generation stopped, and the verifier's line when a candidate reached it.
The native object's own frame is measured beside them, because the stub's
frame and the program's stack share the kernel's 512 bytes.

Run it in the guest that boots the matching kernel, after the sweep has
written `results/submissions.json`:

    python3 kprog/selftests/triage.py
"""

import json
import pathlib
import re
import subprocess
import sys
import tarfile
import tempfile

ROOT = pathlib.Path(__file__).resolve().parents[2]
BUILD = ROOT / "kprog/selftests/build"
RESULTS = ROOT / "kprog/selftests/results/submissions.json"
MICRO = ROOT / "runner/build-llvmbpf/micro_exec"
STACK = 512

KIND = {3: "sched_cls", 6: "xdp", 8: "cgroup_skb"}


def frame_bytes(obj):
    """The largest stack frame the native object reserves, in bytes."""
    done = subprocess.run(["objdump", "-d", str(obj)], capture_output=True,
                          text=True)
    sizes = [int(m, 16) for m in
             re.findall(r"sub\s+\$0x([0-9a-f]+),%rsp", done.stdout)]
    return max(sizes) if sizes else 0


def start_service(state):
    """The trusted service, registered on the kernel's own endpoint."""
    proc = subprocess.Popen(
        [sys.executable, str(ROOT / "kprog/trusted_service.py"),
         "--arch", "1",
         "--endpoint", "/sys/kernel/debug/bpf_x86_native_lab/specializer",
         "--state", str(state),
         "--native-link",
         str(ROOT / "kprog/x86/native_lab/native_link/target/release/"
             "native-link"),
         "--loader",
         str(ROOT / "kprog/libnativeloader/build/trusted-native-loader")],
        stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
    line = proc.stdout.readline()
    if not json.loads(line)["ready"]:
        raise SystemExit("the trusted service did not register")
    return proc


def archive_causes(archive):
    """(generated, verifier) for one archived request, either may be empty."""
    with tempfile.TemporaryDirectory() as directory:
        with tarfile.open(archive) as tar:
            tar.extractall(directory)
        root = pathlib.Path(directory)
        commands = root / "request/generated/commands.jsonl"
        generated = ""
        if commands.exists():
            for line in commands.read_text().splitlines():
                done = json.loads(line)
                if done["returncode"]:
                    text = (done.get("stdout") or "") + \
                           (done.get("stderr") or "")
                    named = [x for x in text.splitlines()
                             if "rror" in x or "nknown" in x]
                    generated = named[-1].strip() if named else text.strip()
                    break
        stderr = root / "request/load.stderr"
        verifier = ""
        if stderr.exists():
            found = [x for x in stderr.read_text(errors="ignore").splitlines()
                     if "invalid " in x or "R10 off" in x]
            verifier = found[0].strip() if found else ""
        return generated, verifier


def main():
    rows = json.load(open(RESULTS))["programs"]
    refused = [r for r in rows if r["outcome"] == "refused"]
    if not refused:
        print("no refused program to triage")
        return 0
    state = pathlib.Path(tempfile.mkdtemp(prefix="triage-"))
    service = start_service(state)
    out = []
    try:
        for r in refused:
            stem = pathlib.Path(r["file"]).stem
            obj = BUILD / (stem + ".native.o")
            bpf = BUILD / (stem + "__" + r["program"] + ".bpf.o")
            found = json.loads(subprocess.run(
                [str(MICRO), "list-programs", "--program", str(bpf)],
                capture_output=True, text=True).stdout or "[]")
            kind = KIND.get(found[0]["prog_type"]) if found else None
            if kind is not None:
                subprocess.run(
                    [str(MICRO), "run-native-kernel", "--program", str(bpf),
                     "--native-program", str(obj), "--inner-repeat", "1",
                     "--native-kernel-prog-type", kind],
                    capture_output=True, text=True)
            archives = sorted(state.glob("*.failure.tar.gz"),
                              key=lambda a: int(a.name.split(".")[0]))
            generated, verifier = archive_causes(archives[-1])
            out.append(dict(
                file=r["file"], program=r["program"],
                native_frame=frame_bytes(obj) if obj.exists() else None,
                stack_budget=STACK,
                generated=generated,
                verifier=verifier))
    finally:
        service.terminate()
    print(json.dumps(out, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())