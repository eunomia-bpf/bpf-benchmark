#!/usr/bin/env python3
"""Build a context-corrected OTel candidate selected by NATIVE_MANIFEST.

The image's default manifest and objects stay in place. Inputs are the native
producer's existing source/flags; intermediate LLVM files are build outputs.
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
    parser.add_argument("--build", default=HERE / "build-x86", type=Path)
    parser.add_argument("--manifest", default=ROOT / "vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/manifest.json", type=Path)
    args = parser.parse_args()
    spec = importlib.util.spec_from_file_location("native_objects", ROOT / "vendor/bpf/native_specialize_objects.py")
    native = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(native)
    args.output.mkdir(parents=True, exist_ok=True)
    objects = []
    flags = native.NATIVE_CFLAGS
    for stem, source, includes in native.units_for_app("otel"):
        original = args.output / f"{stem}.bc"
        corrected = args.output / f"{stem}.physical.bc"
        obj = args.output / f"{stem}.native.o"
        run(["clang-18", *flags, *includes, "-emit-llvm", source, "-o", original])
        run([args.build / "perf-context-lower", original, "--layout", args.build / "layout.json", "-o", corrected])
        run(["clang-18", *flags, corrected, "-o", obj])
        objects.append(obj)
    combined = args.output / "otelcol-ebpf-profiler.native.o"
    run(["clang-18", "-r", "-o", combined, *objects])
    manifest = json.loads(args.manifest.read_text())
    for entry in manifest["objects"]:
        entry["native_object"] = combined.name
    (args.output / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
