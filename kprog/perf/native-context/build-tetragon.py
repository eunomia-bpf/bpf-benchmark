#!/usr/bin/env python3
"""Compile an explicitly selected target-BTF CO-RE native configuration.

Plain/native sources and the image manifest remain in place. Generated units,
translated units, plain objects and corrected objects are retained as evidence.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent


def run(argv):
    print(subprocess.list2cmdline([str(a) for a in argv]), flush=True)
    subprocess.run(argv, check=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--only", nargs="+", required=True)
    parser.add_argument("--build", default=HERE / "build-x86", type=Path)
    parser.add_argument("--kernel", default=Path("/workspaces/.agent-state/kprog-ck/build-x86/vmlinux"), type=Path)
    parser.add_argument("--manifest", default=ROOT / "vendor/build/native-bpf/x86/stage/tetragon/manifest.json", type=Path)
    args = parser.parse_args()
    spec = importlib.util.spec_from_file_location("native_objects", ROOT / "vendor/bpf/native_specialize_objects.py")
    native = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(native)
    units = {stem: (source, flags) for stem, source, flags in native.units_for_app("tetragon")}
    missing = set(args.only) - units.keys()
    if missing:
        parser.error(f"unknown Tetragon object names: {sorted(missing)}")
    args.output.mkdir(parents=True, exist_ok=True)
    for stem in args.only:
        source, flags = units[stem]
        plain = args.output / f"{stem}.plain.o"
        unit = args.output / f"{stem}.i"
        corrected = args.output / f"{stem}.core.i"
        obj = args.output / f"{stem}.native.o"
        run(["clang-18", *native.NATIVE_CFLAGS, *flags, source, "-o", plain])
        run(["clang-18", *native.NATIVE_CFLAGS, *flags, "-include", HERE / "core-queries.h", "-E", "-P", source, "-o", unit])
        run([args.build / "core-flavor-lower", unit, corrected, args.kernel])
        run(["clang-18", *native.NATIVE_CFLAGS, "-fms-extensions", "-Wno-deprecated-non-prototype", corrected, "-o", obj])
    manifest = json.loads(args.manifest.read_text())
    for entry in manifest["objects"]:
        name = Path(entry["native_object"]).name
        if name.removesuffix(".native.o") in args.only:
            entry["native_object"] = name
        else:
            entry["native_object"] = f"/opt/bpf-benchmark/native-bpf/x86_64/tetragon/{name}"
    (args.output / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
