"""Capture/compare default proof-stage native bytes for the six real manifests.

These are linker outputs, not verifier acceptance or application execution.
Keep failed commands as well as successful ELF outputs in the raw directory.
"""
import argparse
import json
from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
APPS = ["bcc", "katran", "otelcol-ebpf-profiler", "cilium", "tetragon", "tracee"]


def capture(linker, directory):
    directory.mkdir(parents=True, exist_ok=False)
    rows = []
    for app in APPS:
        manifest = ROOT / "vendor/build/native-bpf/x86/stage" / app / "manifest.json"
        for index, item in enumerate(json.loads(manifest.read_text())["objects"]):
            native = manifest.parent / item["native_object"]
            symbol = item.get("symbol", item["program"])
            output = directory / f"{app}-{index:04d}.proof.o"
            command = [str(linker), "--input", str(native), "--symbol", symbol,
                       "--mode", "proof", "--output", str(output)]
            result = subprocess.run(command, text=True, capture_output=True)
            row = dict(app=app, native_object=str(native), symbol=symbol,
                       output=output.name, command=command, returncode=result.returncode,
                       stdout=result.stdout, stderr=result.stderr)
            rows.append(row)
            with (directory / "commands.jsonl").open("a") as log:
                log.write(json.dumps(row) + "\n")
        print(app, "captured", flush=True)
    return rows


def compare(before, after, rows):
    reference = [json.loads(line) for line in (before / "commands.jsonl").read_text().splitlines()]
    differences = []
    if len(reference) != len(rows):
        raise ValueError("manifest entry count changed during linker comparison")
    for old, new in zip(reference, rows):
        if any(old[key] != new[key] for key in ("app", "native_object", "symbol", "returncode")):
            differences.append(dict(app=new["app"], symbol=new["symbol"], changed="identity/status"))
        elif not new["returncode"]:
            with (before / old["output"]).open("rb") as left, (after / new["output"]).open("rb") as right:
                old_elf, new_elf = ELFFile(left), ELFFile(right)
                for section in (".text", ".native_link_abi"):
                    if old_elf.get_section_by_name(section).data() != new_elf.get_section_by_name(section).data():
                        differences.append(dict(app=new["app"], symbol=new["symbol"], changed=section))
    (after / "comparison.json").write_text(json.dumps(dict(entries=len(rows), differences=differences), indent=2) + "\n")
    print(json.dumps(dict(entries=len(rows), differences=differences)), flush=True)
    return bool(differences)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("directory", type=Path)
    parser.add_argument("--reference", type=Path)
    args = parser.parse_args()
    linker = ROOT / "kprog/x86/native_lab/native_link/target/release/native-link"
    rows = capture(linker, args.directory)
    raise SystemExit(compare(args.reference, args.directory, rows) if args.reference else 0)
