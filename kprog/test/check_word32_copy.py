"""Stock-verifier regression for copied scalar bounds and prior width repairs."""
import json
from pathlib import Path
import subprocess
import sys

root, output, bpftool = map(Path, sys.argv[1:])
output.mkdir(parents=True, exist_ok=True)
cases = [
    ("copy-before", root / "before/word32-copy.bpf.o", False),
    ("copy-after", root / "after/word32-copy.bpf.o", True),
    ("signed-after", root / "signed-after/signed-bound.bpf.o", True),
    *[(f"partial-{lane}", root / f"partial-after/lane{lane}.bpf.o", True)
      for lane in (0, 8, 16)],
]
rows = []
for label, program, expected_accept in cases:
    command = [str(bpftool), "-d", "prog", "load", str(program),
               f"/sys/fs/bpf/verified_word32_{label}", "type", "kprobe"]
    done = subprocess.run(command, capture_output=True, text=True)
    (output / f"{label}.stdout").write_text(done.stdout)
    (output / f"{label}.stderr").write_text(done.stderr)
    rows.append(dict(label=label, command=command, returncode=done.returncode,
                     expected_accept=expected_accept))
(output / "observations.json").write_text(json.dumps(rows, indent=2) + "\n")
print(json.dumps(rows), flush=True)
if any((row["returncode"] == 0) != row["expected_accept"] for row in rows):
    raise SystemExit("word32 copy/width regression failed; all verifier logs retained")
