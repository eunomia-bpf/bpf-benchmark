#!/usr/bin/env python3
"""Compare regenerated Clight build products with the retained Git baseline."""
import argparse
import json
from pathlib import Path
import subprocess

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("baseline")
args = parser.parse_args()
root = Path(__file__).resolve().parents[4]
prefix = "kprog/formal/KProgFormal/Clight"
paths = subprocess.check_output(
    ["git", "ls-tree", "-r", "--name-only", args.baseline, "--", prefix],
    cwd=root, text=True).splitlines()
if not paths:
    raise SystemExit("baseline contains no Clight exports")
rows = []
for name in paths:
    size = 0
    same = True
    with subprocess.Popen(["git", "show", f"{args.baseline}:{name}"],
                          cwd=root, stdout=subprocess.PIPE) as old:
        with (root / name).open("rb") as actual:
            while True:
                expected = old.stdout.read(1 << 20)
                got = actual.read(len(expected) if expected else 1)
                size += len(expected)
                same = same and expected == got
                if not expected:
                    break
        if old.wait() != 0:
            raise SystemExit(f"git could not read {name}")
    rows.append({"path": name, "bytes": size, "identical": same})
print(json.dumps({"baseline": args.baseline, "files": rows}, indent=2))
raise SystemExit(0 if all(row["identical"] for row in rows) else 1)
