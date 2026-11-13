#!/usr/bin/env python3
"""Decode native x86 tail dispatch in saved JIT images, alongside kernel BTF.

This is offline analysis of retained bytes. It changes neither a program nor
the benchmark protocol, and reports offsets rather than inferring executions.
"""
import argparse
import json
from pathlib import Path
import re
import struct
import subprocess


def disassemble(path):
    return subprocess.run(
        ["objdump", "-D", "-b", "binary", "-m", "i386:x86-64", str(path)],
        check=True, capture_output=True, text=True).stdout


def inspect(path):
    data = path.read_bytes()
    sites = []
    for match in re.finditer(rb"\x89\xd2\x39\x96", data):
        start = match.start()
        end = data.find(b"\xff\xe1", start)
        if end < 0:
            raise ValueError(f"{path}:{start:#x}: dispatch jump missing")
        body = data[start:end + 2]
        array = re.search(rb"\x48\x8b\x8c\xd6(.{4})", body, re.DOTALL)
        target = re.search(rb"\x48\x8b\x89(.{4})\x48(?:\x83\xc1(.)|\x81\xc1(.{4}))\xff\xe1$",
                           body, re.DOTALL)
        frame = re.search(rb"\x48\x8b\x84\x24(.{4})\x48\x8b\x80(.{4})", body, re.DOTALL)
        live = re.search(rb"\x48\x8b\x85(.{4})", body, re.DOTALL)
        if array is None or target is None or (frame is None and live is None):
            raise ValueError(f"{path}:{start:#x}: unrecognized dispatch encoding")
        sites.append({
            "offset": start,
            "map_max_entries": struct.unpack_from("<I", body, 4)[0],
            "array_ptrs": struct.unpack("<I", array[1])[0],
            "prog_bpf_func": struct.unpack("<I", target[1])[0],
            "target_entry": int.from_bytes(target[2] or target[3], "little", signed=True),
            "saved_frame_rsp_offset": struct.unpack("<i", frame[1])[0] if frame else None,
            "counter_pointer_frame_offset": struct.unpack("<i", frame[2] if frame else live[1])[0],
            "bytes": body.hex(),
        })
    return {"path": str(path), "size": len(data), "sites": sites}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--kernel", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("images", nargs="+", type=Path)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    layouts = {}
    for name in ("bpf_map", "bpf_array", "bpf_prog"):
        layout = subprocess.run(["pahole", "-C", name, str(args.kernel)],
                                check=True, capture_output=True, text=True).stdout
        (args.output / f"{name}.txt").write_text(layout)
        layouts[name] = layout
    rows = []
    for index, path in enumerate(args.images):
        rows.append(inspect(path))
        (args.output / f"{index}-{path.stem}.asm").write_text(disassemble(path))
    (args.output / "dispatch.json").write_text(json.dumps({
        "kernel": str(args.kernel), "layouts": layouts, "images": rows,
    }, indent=2) + "\n")
    print(json.dumps({"images": len(rows), "sites": sum(len(r["sites"]) for r in rows),
                      "output": str(args.output)}))


if __name__ == "__main__":
    main()
