"""Catch missing/repeated preambles or chunks and compiling partial B after an error."""
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

root = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location("stream_specializer", root / "kprog/x86/trusted_specializer.py")
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
clang, directory = sys.argv[1], Path(sys.argv[2])
directory.mkdir(parents=True, exist_ok=True)
# Exercise the existing chunk boundary cheaply; production's chunk size stays unchanged.
module.PIECE_SOURCE_BYTES = 80
source_text = """#include <linux/bpf.h>
#include <bpf_helpers.h>
#define STEP(N) total += input[N] + __LINE__ + __FILE__[0]
SEC("kprobe/stream") int stream(void *ctx) {
volatile __u64 *input = ctx;
__u64 total = 0;
x86_l_0:
STEP(0); STEP(1); STEP(2); STEP(3); STEP(4); STEP(5); STEP(6); STEP(7);
x86_l_1:
STEP(0); STEP(1); STEP(2); STEP(3); STEP(4); STEP(5); STEP(6); STEP(7);
x86_l_2:
STEP(0); STEP(1); STEP(2); STEP(3); STEP(4); STEP(5); STEP(6); STEP(7);
x86_l_3:
return total;
}
char LICENSE[] SEC("license") = "GPL";
"""

def execute(case, text):
    work = directory / case
    work.mkdir()
    source, obj = work / "stream.bpf.c", work / "stream.bpf.o"
    source.write_text(text)
    calls = []

    def run(command):
        command = [str(value) for value in command]
        done = subprocess.run(command, capture_output=True, text=True)
        calls.append(dict(command=command, returncode=done.returncode,
                          stdout=done.stdout, stderr=done.stderr))
        (work / "commands.json").write_text(json.dumps(calls, indent=2) + "\n")
        done.check_returncode()

    if case == "preprocessor-error":
        try:
            module.compile_simulator(clang, source, obj, run)
        except subprocess.CalledProcessError:
            assert len(calls) >= 2 and calls[-1]["returncode"]
            assert all("-c" not in call["command"] for call in calls)
            assert not obj.exists()
            return dict(case=case, commands=len(calls), error_propagated=True)
        raise AssertionError("preprocessing error was ignored")

    module.compile_simulator(clang, source, obj, run)
    expanded = [Path(call["command"][-1]) for call in calls if "-E" in call["command"]]
    assert len(expanded) >= 2
    # Independent reference: the previous, materialized token-join algorithm.
    parts = [path.read_bytes().split((module.PIECE_MARK + "\n").encode()) for path in expanded]
    expected = parts[0][0] + b"".join(part[1] for part in parts)
    observed = source.with_suffix(".i").read_bytes()
    assert observed == expected
    assert obj.stat().st_size > 0
    return dict(case=case, pieces=len(parts), preprocessed_bytes=len(observed),
                token_join_sha256=hashlib.sha256(observed).hexdigest(), exact_join=True)

observations = [execute("valid", source_text),
                execute("preprocessor-error", source_text.replace("x86_l_2:\n", "x86_l_2:\n#error deliberate preprocessing failure\n"))]
(directory / "observations.json").write_text(json.dumps(observations, indent=2) + "\n")
print(json.dumps(observations), flush=True)
