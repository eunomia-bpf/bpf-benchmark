#!/usr/bin/env python3
"""Compile an explicitly selected target-BTF CO-RE native configuration.

Plain/native sources and the image manifest remain in place. Generated units,
translated units, plain objects and corrected objects are retained as evidence.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import importlib.util
import json
from pathlib import Path
import subprocess
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent


def run(argv, log):
    print(subprocess.list2cmdline([str(a) for a in argv]), file=log, flush=True)
    subprocess.run(argv, check=True, stdout=log, stderr=subprocess.STDOUT)


def code_sections(path):
    with path.open("rb") as stream:
        return {section.name: section.data() for section in ELFFile(stream).iter_sections()
                if section["sh_flags"] & 4}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", required=True, type=Path)
    selection = parser.add_mutually_exclusive_group(required=True)
    selection.add_argument("--only", nargs="+")
    selection.add_argument("--all", action="store_true")
    parser.add_argument("--jobs", default=1, type=int)
    parser.add_argument("--build", default=HERE / "build-x86", type=Path)
    parser.add_argument("--kernel", default=Path("/workspaces/.agent-state/kprog-ck/build-x86/vmlinux"), type=Path)
    parser.add_argument("--manifest", default=ROOT / "vendor/build/native-bpf/x86/stage/tetragon/manifest.json", type=Path)
    args = parser.parse_args()
    spec = importlib.util.spec_from_file_location("native_objects", ROOT / "vendor/bpf/native_specialize_objects.py")
    native = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(native)
    units = {stem: (source, flags) for stem, source, flags in native.units_for_app("tetragon")}
    manifest = json.loads(args.manifest.read_text())
    selected = sorted({Path(entry["native_object"]).name.removesuffix(".native.o")
                       for entry in manifest["objects"]}) if args.all else args.only
    missing = set(selected) - units.keys()
    if missing:
        parser.error(f"unknown Tetragon object names: {sorted(missing)}")
    args.output.mkdir(parents=True, exist_ok=True)

    def compile_unit(stem):
        source, flags = units[stem]
        plain = args.output / f"{stem}.plain.o"
        unit = args.output / f"{stem}.i"
        corrected = args.output / f"{stem}.core.i"
        obj = args.output / f"{stem}.native.o"
        with (args.output / f"{stem}.build.log").open("w") as log:
            run(["clang-18", *native.NATIVE_CFLAGS, *flags, source, "-o", plain], log)
            run(["clang-18", *native.NATIVE_CFLAGS, *flags, "-include", HERE / "core-queries.h", "-E", "-P", source, "-o", unit], log)
            run([args.build / "core-flavor-lower", unit, corrected, args.kernel], log)
            run(["clang-18", *native.NATIVE_CFLAGS, "-fms-extensions", "-Wno-deprecated-non-prototype", corrected, "-o", obj], log)
        before, after = code_sections(plain), code_sections(obj)
        shipped = args.manifest.parent / obj.name
        return {"object": stem, "source": str(source), "flags": flags,
                "plain_bytes_equal_shipped_code": before == code_sections(shipped),
                "plain_sections": {k: len(v) for k, v in before.items()},
                "corrected_sections": {k: len(v) for k, v in after.items()}}

    reports, failures = [], []
    with ThreadPoolExecutor(max_workers=args.jobs) as workers:
        pending = {workers.submit(compile_unit, stem): stem for stem in selected}
        for future in as_completed(pending):
            try:
                reports.append(future.result())
                print(f"compiled {pending[future]}", flush=True)
            except Exception as error:
                failures.append({"object": pending[future], "error": str(error)})
                print(f"failed {pending[future]}: {error}", flush=True)
    (args.output / "build-report.json").write_text(json.dumps({"completed": reports, "failures": failures}, indent=2) + "\n")
    if failures:
        raise SystemExit(1)
    for entry in manifest["objects"]:
        name = Path(entry["native_object"]).name
        if name.removesuffix(".native.o") in selected:
            entry["native_object"] = name
        else:
            entry["native_object"] = f"/opt/bpf-benchmark/native-bpf/x86_64/tetragon/{name}"
    (args.output / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
