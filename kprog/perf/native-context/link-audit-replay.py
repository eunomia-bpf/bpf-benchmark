#!/usr/bin/env python3
"""Replay retained CLI inputs and bound plans, without kernel submission.

Only the selected optimization switch changes. All other captured flags/facts
are retained. Historical addresses are literal linker inputs, never dereferenced.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct
import subprocess

OUTPUTS = {"--output": "image", "--output-relocs": "relocs",
           "--output-map-patches": "maps", "--output-abi": "abi"}
SWITCH = "--runtime-known-map-lookups"


def rewrite(argv, replacements):
    result = []
    index = 0
    while index < len(argv):
        word = argv[index]
        key = word.split("=", 1)[0]
        if key in replacements:
            result.extend([key, str(replacements[key])])
            index += 1 if "=" in word else 2
        else:
            result.append(word)
            index += 1
    return result


def helper_targets(path):
    data = path.read_bytes()
    if len(data) % 16:
        raise ValueError("relocation ABI is not a sequence of16-byte records: " + str(path))
    return Counter(target for _, kind, target in struct.iter_unpack("<IIQ", data) if kind == 1)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("capture", type=Path)
    parser.add_argument("--linker", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--runtime-array-layout", type=Path,
                        help="Toggle runtime ARRAY dispatch instead of the known-map flag")
    parser.add_argument("--runtime-array-shared", action="store_true",
                        help="With --runtime-array-layout, toggle shared versus inline dispatch")
    parser.add_argument("--runtime-probe-read-layout", type=Path,
                        help="Toggle probe-read LTO; both kernel variants emit recovery ABI")
    args = parser.parse_args()
    if args.runtime_array_shared and not args.runtime_array_layout:
        parser.error("--runtime-array-shared requires --runtime-array-layout")
    if args.runtime_probe_read_layout and args.runtime_array_layout:
        parser.error("select one replay optimization at a time")
    args.output.mkdir(parents=True)
    binary_sha = hashlib.sha256(args.linker.read_bytes()).hexdigest()
    rows = []
    for source in sorted(args.capture.glob("link-*")):
        path = source / "result.json"
        if not path.is_file():
            rows.append(dict(capture=str(source), completed_capture=False))
            continue
        record = json.loads(path.read_text())
        row = dict(capture=str(source), completed_capture=True, label=record["label"],
                   mode=record["mode"], symbol=record["symbol"], actual_exit=record["returncode"],
                   same_linker_binary=binary_sha == record["binary_sha256"])
        if not record["input"] or not record["input"]["exists"]:
            row.update(replayable=False, reason="input-not-retained")
            rows.append(row)
            continue
        plan = json.loads((source / "link-plan.json").read_text()) if record["link_plan"] else {}
        row["lookup_map_kinds"] = dict(Counter(m["kind"] for m in plan.get("lookup_maps", [])))
        row["lookup_map_names"] = [m["name"] for m in plan.get("lookup_maps", [])]
        work = args.output / source.name
        work.mkdir()
        variants = {}
        for variant in ("on", "off"):
            replacements = {"--input": source / record["input"]["capture"]}
            if record["link_plan"]:
                replacements["--link-plan"] = source / record["link_plan"]["capture"]
            for flag, name in OUTPUTS.items():
                replacements[flag] = work / (variant + "." + name)
            argv = rewrite(record["command"][1:], replacements)
            if args.runtime_probe_read_layout:
                if record["mode"] == "kernel":
                    if any(w.split("=",1)[0] == "--abi-load-sites" for w in argv):
                        argv = rewrite(argv, {"--abi-load-sites": "true"})
                    else:
                        argv.extend(["--abi-load-sites", "true"])
                if variant == "on":
                    argv.extend(["--runtime-probe-read-layout", str(args.runtime_probe_read_layout)])
            elif args.runtime_array_layout:
                if variant == "on" or args.runtime_array_shared:
                    argv.extend(["--runtime-array-layout", str(args.runtime_array_layout)])
                if variant == "on" and args.runtime_array_shared:
                    argv.append("--runtime-array-shared")
            else:
                argv = [word for word in argv if word != SWITCH]
                if variant == "on":
                    argv.append(SWITCH)
            command = [str(args.linker), *argv]
            completed = subprocess.run(command, capture_output=True)
            (work / (variant + ".stdout")).write_bytes(completed.stdout)
            (work / (variant + ".stderr")).write_bytes(completed.stderr)
            variants[variant] = dict(command=command, returncode=completed.returncode)
        row.update(replayable=True, variants=variants)
        for variant in ("on", "off"):
            if variants[variant]["returncode"] == 0:
                row["captured_" + variant + "_bytes_equal"] = {
                    name: (source / entry["capture"]).read_bytes() == (work / (variant + "." + name)).read_bytes()
                    for name, entry in record["outputs"].items() if entry and entry["exists"]}
        if all(variants[v]["returncode"] == 0 for v in variants):
            row["on_off_equal"] = {
                name: (work / ("on." + name)).read_bytes() == (work / ("off." + name)).read_bytes()
                for name in OUTPUTS.values() if (work / ("on." + name)).is_file()}
            if (work / "on.relocs").is_file():
                on, off = helper_targets(work / "on.relocs"), helper_targets(work / "off.relocs")
                generic = [h["addr"] for h in plan.get("helpers", []) if h["name"] == "bpf_map_lookup_elem"]
                row["helper_calls_on_off"] = [sum(on.values()), sum(off.values())]
                row["generic_lookup_calls_on_off"] = ([sum(on[t] for t in generic), sum(off[t] for t in generic)]
                                                          if generic else None)
                row["helper_target_deltas"] = {hex(t): on[t] - off[t] for t in on.keys() | off.keys()
                                               if on[t] != off[t]}
        rows.append(row)
    (args.output / "report.json").write_text(json.dumps(dict(
        linker=str(args.linker), linker_sha256=binary_sha, cases=rows,
        switch=("--runtime-probe-read-layout" if args.runtime_probe_read_layout else
                "--runtime-array-shared" if args.runtime_array_shared else
                "--runtime-array-layout" if args.runtime_array_layout else SWITCH),
        scope="Offline replay only, no kernel execution or workload validity gate. "
              "Helper call deltas establish emitted transformation counts, not performance gains."), indent=2) + "\n")


if __name__ == "__main__":
    main()
