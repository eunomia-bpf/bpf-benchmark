#!/usr/bin/env python3
"""Run the existing host recipe subset while native protocol cases are checked."""
import argparse
from pathlib import Path
import subprocess

FORMAL = Path(__file__).resolve().parents[2]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--from-source", default="test_x86_six_flags_host.c")
args = parser.parse_args()
expanded = subprocess.check_output(
    ["make", "--no-print-directory", "-s", "-n", "check"], cwd=FORMAL, text=True
).splitlines()
first = next(i for i, line in enumerate(expanded)
             if "oracles/" + args.from_source in line)
# Keep the current recipe's commands, continuations, ordering and failure
# propagation. No copied Makefile or alternate source/benchmark tree is made.
recipe = ".PHONY: host\nhost:\n" + "\n".join("\t" + line for line in expanded[first:]) + "\n"
subprocess.run(["make", "--no-print-directory", "-f", "-", "host"],
               cwd=FORMAL, input=recipe, text=True, check=True)
