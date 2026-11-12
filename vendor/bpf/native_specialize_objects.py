#!/usr/bin/env python3
"""Build one application's native objects with its frozen .rodata as constants.

Build-time form of the load-time specialization. The .rodata bytes the loader
finds in a program's .rodata map are captured once, from a real run
(native_capture_rodata.py); every native object of the application is then
rebuilt with those values as plain constants, so clang folds the reads and the
branches the configuration values decide -- the same folds the verifier does on
the eBPF side.

The value of a global is the bytes the loaded .rodata image holds at that
global's offset in the native object: the loader patches each native .rodata
symbol to map_value_addr + native offset, so the native object's own layout is
what the loaded image is indexed by. When the object's .rodata is larger than
the map value the loader keeps the object's own copy, and then the constant is
the object's initializer as it stands.

Every object is built twice: once with the Makefile's own source and flags
(<stem>.plain.o, the switch-off path) and once from the specialized unit
(<stem>.rodata.o). The difference between the two is the specialization's
effect.

Usage: native_specialize_objects.py --app tracee \
           --capture <run dir>/details/map-snapshots/<app> \
           --bpf-object <the app's .bpf.o> --output <dir> [--only <stem>...]
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent

NATIVE_CFLAGS = [
    "-O3", "-g", "-fPIC", "-c", "-DMICRO_NATIVE", "-fomit-frame-pointer",
    "-march=native", "-mno-red-zone", "-mgeneral-regs-only",
    "-fno-stack-protector", "-fno-asynchronous-unwind-tables",
    "-fno-unwind-tables", "-fno-jump-tables", "-fno-optimize-sibling-calls",
    "-Wno-unknown-attributes", "-mllvm", "-switch-to-lookup=false",
]


def bcc_tools() -> list[str]:
    return ["capable", "biosnoop", "vfsstat", "opensnoop", "syscount",
            "tcpconnect", "tcplife", "runqlat"]


def units_for_app(app: str) -> list[tuple[str, Path, list[str]]]:
    """(stem, source, flags) for each native object the image carries."""
    bpf = ROOT / "vendor" / "bpf"
    if app == "bcc":
        flags = [f"-include", str(bpf / "native_compat.h"),
                 f"-I{bpf}/bcc/libbpf-tools", f"-I{bpf}/bcc/libbpf-tools/x86",
                 f"-I{bpf}/bcc/src/cc/libbpf/include/uapi",
                 "-I/usr/include", "-I/usr/include/x86_64-linux-gnu"]
        return [(tool, bpf / f"bcc/libbpf-tools/{tool}.bpf.c", flags)
                for tool in bcc_tools()]
    if app == "tracee":
        flags = [f"-include", str(bpf / "native_compat.h"),
                 "-DMICRO_NATIVE_HELPER_MACROS", "-D__TARGET_ARCH_x86",
                 "-D__BPF_TRACING__", "-DCORE", "-DCOMMON_BUILD",
                 f"-I{bpf}/tracee/pkg/ebpf/c",
                 "-I/usr/include", "-I/usr/include/x86_64-linux-gnu"]
        units = [("tracee", bpf / "tracee/pkg/ebpf/c/tracee.bpf.c", flags)]
        for name in ("kprobe_check", "lsm_check"):
            units.append((f"lsm_support/{name}",
                          bpf / f"tracee/pkg/ebpf/c/lsmsupport/{name}.bpf.c",
                          flags + [f"-I{bpf}/tracee/pkg/ebpf/c/lsmsupport"]))
        return units
    raise SystemExit(f"native_specialize_objects: no object list for {app}")


def section_symbols(object_path: Path, section_prefix: str) -> dict[str, tuple[str, int, int]]:
    """name -> (section, offset in section, size) for objects in a section."""
    out = subprocess.run(["readelf", "-SW", str(object_path)],
                         capture_output=True, text=True).stdout
    sections: dict[int, tuple[str, int, int]] = {}
    for m in re.finditer(r"^\s*\[\s*(\d+)\]\s+(\S+)\s+(\S+)\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)",
                         out, re.M):
        sections[int(m.group(1))] = (m.group(2), int(m.group(4), 16), int(m.group(6), 16))
    symbols = subprocess.run(["readelf", "-sW", str(object_path)],
                             capture_output=True, text=True).stdout
    found: dict[str, tuple[str, int, int]] = {}
    for line in symbols.splitlines():
        fields = line.split()
        if len(fields) < 8 or not fields[0].endswith(":") or not fields[6].isdigit():
            continue
        if fields[3] != "OBJECT":
            continue
        section = sections.get(int(fields[6]))
        if not section or not section[0].startswith(section_prefix):
            continue
        found.setdefault(fields[7], (section[0], int(fields[1], 16) - section[1],
                                     int(fields[2])))
    return found


def loaded_rodata(capture: Path) -> dict[str, bytes]:
    """Tool name -> the .rodata image of the programs that read it.

    Each BCC tool names its .rodata map "<tool>.rodata"; the tracee object
    names it ".rodata". The map name is the join key between a captured
    program and the object built from the same source.
    """
    values: dict[str, bytes] = {}
    for ref in sorted(capture.glob("*/ref.json")):
        meta = json.loads(ref.read_text())
        map_name = meta.get("map_name", "")
        if map_name != ".rodata" and not map_name.endswith(".rodata"):
            continue
        dump = ref.parent / "map-values" / f"map-{meta['map_id']}.dump.json"
        if not dump.exists():
            continue
        entries = json.loads(dump.read_text())
        if not entries:
            continue
        image = bytes(int(byte, 16) for byte in entries[0]["value"])
        tool = map_name[: -len(".rodata")] if map_name.endswith(".rodata") \
            and map_name != ".rodata" else ""
        previous = values.setdefault(tool, image)
        if previous != image:
            sys.exit(f"{meta['prog_name']}: .rodata differs between references")
    return values


def plain_rodata_bytes(object_path: Path) -> bytes:
    """The object's .rodata contents, what the loader patches against."""
    sections = subprocess.run(["readelf", "-SW", str(object_path)],
                              capture_output=True, text=True).stdout
    for m in re.finditer(
            r"^\s*\[\s*\d+\]\s+\.rodata\s+PROGBITS\s+[0-9a-f]+\s+([0-9a-f]+)\s+([0-9a-f]+)",
            sections, re.M):
        offset, size = int(m.group(1), 16), int(m.group(2), 16)
        with open(object_path, "rb") as handle:
            handle.seek(offset)
            return handle.read(size)
    return b""


def plain_rodata_size(object_path: Path) -> int:
    """Bytes of the object's .rodata section, the loader's fit test."""
    sections = subprocess.run(["readelf", "-SW", str(object_path)],
                              capture_output=True, text=True).stdout
    for m in re.finditer(
            r"^\s*\[\s*\d+\]\s+\.rodata\s+\S+\s+[0-9a-f]+\s+[0-9a-f]+\s+([0-9a-f]+)",
            sections, re.M):
        return int(m.group(1), 16)
    return 0


def program_sizes(object_path: Path) -> dict[str, int]:
    """Executable section name -> bytes, one entry per BPF program."""
    sections = subprocess.run(["readelf", "-SW", str(object_path)],
                              capture_output=True, text=True).stdout
    return {m.group(1): int(m.group(2), 16) for m in re.finditer(
        r"^\s*\[\s*\d+\]\s+(\S+)\s+PROGBITS\s+[0-9a-f]+\s+[0-9a-f]+\s+([0-9a-f]+)\s+\S+\s+AX",
        sections, re.M)}


def run(argv: list[str]) -> None:
    result = subprocess.run(argv, capture_output=True, text=True)
    if result.returncode != 0:
        sys.stderr.write(result.stderr[-4000:])
        raise SystemExit(f"failed: {' '.join(argv[:4])} ...")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--app", required=True)
    parser.add_argument("--capture", required=True)
    parser.add_argument("--bpf-objects", default="",
                        help="directory of <stem>.bpf.o inputs")
    parser.add_argument("--output", required=True)
    parser.add_argument("--only", nargs="*", default=[])
    args = parser.parse_args()

    capture = Path(args.capture)
    output = Path(args.output).resolve()
    output.mkdir(parents=True, exist_ok=True)
    bpf_objects = Path(args.bpf_objects)
    loaded = loaded_rodata(capture)
    print(f"{args.app}: {len(loaded)} captured .rodata maps under {capture.name}",
          file=sys.stderr)

    # Every program of one BPF object reads the same .rodata globals, so the
    # values are identical across the captured programs; verify that, then use
    # the single image the object's own offsets index.
    if not loaded:
        raise SystemExit(f"no captured .rodata image under {capture}")

    for stem, source, flags in units_for_app(args.app):
        if args.only and stem not in args.only:
            continue
        tool = Path(stem).name
        if tool not in loaded and "" in loaded:
            # An object whose programs name their map ".rodata" (tracee) has a
            # single image, selected by the empty tool name.
            tool = ""
        if tool not in loaded:
            # BPF object names are truncated to 15 characters, so the map is
            # "<first 7 characters>.rodata"; match on that as well.
            short = tool[:7]
            match = [name for name in loaded if name and name[:7] == short]
            if len(match) == 1:
                tool = match[0]
        if tool not in loaded:
            print(f"{stem:22} no captured .rodata map", file=sys.stderr)
            continue
        reference = loaded[tool]
        directory = output / Path(stem).parent
        directory.mkdir(parents=True, exist_ok=True)
        base = directory / Path(stem).name
        plain = base.with_suffix(".plain.o")
        run(["clang-18", *NATIVE_CFLAGS, *flags, "-o", str(plain), str(source)])
        section = plain_rodata_size(plain)
        if section > len(reference):
            print(f"{stem:22} .rodata {section} > map value {len(reference)}; "
                  f"the object keeps its own copy", file=sys.stderr)

        unit = base.with_suffix(".unit.i")
        index = base.with_suffix(".decls.json")
        run([sys.executable, str(HERE / "native_specialize_prepares.py"),
             "--object", str(plain), "--output-dir", str(directory),
             "--", "clang-18", *NATIVE_CFLAGS, *flags, str(source)])
        # The prepares step names the unit after the object it read.
        produced_unit = directory / f"{Path(stem).name}.i"
        produced_index = produced_unit.with_suffix(".decls.json")

        # The loader indexes the loaded image by the plain object's .rodata
        # offsets, so the constants come from the plain object's own section.
        rodata_file = directory / f"{base.name}.rodata.bin"
        rodata_file.write_bytes(plain_rodata_bytes(plain))
        specialized = base.with_suffix(".rodata.i")
        run([sys.executable, str(HERE / "native_specialize.py"),
             "--unit", str(produced_unit), "--decls", str(produced_index),
             "--rodata", str(rodata_file), "--output", str(specialized)])
        spec_object = base.with_suffix(".rodata.o")
        run(["clang-18", *NATIVE_CFLAGS, str(specialized), "-o", str(spec_object)])

        before, after = program_sizes(plain), program_sizes(spec_object)
        changed = [(name, before[name], after.get(name, 0)) for name in before
                   if before[name] != after.get(name, 0)]
        total = sum(before.values()), sum(after.values())
        print(f"{stem:22} code {total[0]:>7} -> {total[1]:>7}  "
              f"({len(changed)} of {len(before)} programs changed)", file=sys.stderr)


if __name__ == "__main__":
    main()