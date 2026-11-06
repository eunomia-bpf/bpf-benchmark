#!/usr/bin/env python3
"""Reject synthetic helper results and ID truncation at specialization time."""
import argparse
from pathlib import Path
import shlex
import subprocess

ROOT = Path(__file__).resolve().parent.parent


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--cc", default="cc")
    args = parser.parse_args()
    command = shlex.split(args.cc) + [
        "-O2", "-I.", "-I../x86", "-I../../kprog", "-I../../vendor/libbpf/src",
        "-c", "oracles/test_x86_helper_dispatch_route_host.c",
        "-o", "build/helper-error.o"]
    # A real armed constant must eliminate the failure arm and compile.
    result = subprocess.run(command + ["-DORA_NEGATIVE_HELPER=5ULL"],
                            cwd=ROOT, capture_output=True, text=True)
    if result.returncode:
        raise RuntimeError("armed helper did not compile:\n" + result.stderr)
    # Gaps, zero, full-width boundaries and a low32 alias must all fail.
    for identity in [0, 13, 194, (1 << 64) - 1, (1 << 32) + 1]:
        result = subprocess.run(command + [f"-DORA_NEGATIVE_HELPER={identity}ULL"],
                                cwd=ROOT, capture_output=True, text=True)
        if result.returncode == 0 or "unresolved x86 helper ID" not in result.stderr:
            raise RuntimeError(f"unarmed helper {identity} did not fail explicitly:\n"
                               + result.stderr)
    print("helper specialization: armed ID compiles; zero/gaps/full64/low32 alias fail explicitly")


if __name__ == "__main__":
    main()
