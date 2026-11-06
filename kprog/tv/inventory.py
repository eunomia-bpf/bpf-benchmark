#!/usr/bin/env python3
"""Retain exact artifact identities and outstanding obligations per program.

This is an inventory, not a TV implementation. It never produces certificates.
"""
from __future__ import annotations

import argparse
import gzip
import hashlib
import io
import json
from pathlib import Path

import yaml
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def identity(path: Path) -> dict:
    if not path.exists():
        return {"path": str(path), "error": "artifact_missing"}
    raw = path.read_bytes()
    elf = ELFFile(io.BytesIO(raw))
    code = []
    symbols = []
    relocations = []
    for section in elf.iter_sections():
        if section["sh_flags"] & 4 and section["sh_size"]:
            code.append({"section": section.name, "bytes": section["sh_size"],
                         "sha256": hashlib.sha256(section.data()).hexdigest()})
        if section["sh_type"] == "SHT_SYMTAB":
            for symbol in section.iter_symbols():
                if symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_shndx"] != "SHN_UNDEF":
                    symbols.append({"name": symbol.name, "section": symbol["st_shndx"],
                                    "offset": symbol["st_value"], "bytes": symbol["st_size"]})
        if section["sh_type"] in ("SHT_REL", "SHT_RELA"):
            relocations.append({"section": section.name, "count": section.num_relocations()})
    return {"path": str(path), "sha256": hashlib.sha256(raw).hexdigest(),
            "machine": elf["e_machine"], "code": code, "functions": symbols,
            "relocations": relocations}


def pending(arch: str, population: str, name: str, native: Path,
            artifacts: list[dict], **evidence) -> dict:
    return {"arch": arch, "population": population, "name": name,
            "status": "not_validated", "native_input": identity(native),
            "compiled_bpf_candidates": artifacts,
            "error": "reference_whole_state_and_compiled_bpf_semantics_unavailable",
            "open_obligations": ["native_byte_decode", "entry_ABI_relation",
                                 "per_block_state_and_effect_trace_refinement",
                                 "post_link_instantiated_proof_identity",
                                 "whole_program_binding"], **evidence}


def micro(arch: str):
    config = ROOT / "micro/config/micro_pure_jit.yaml"
    config_bytes = config.read_bytes()
    for bench in yaml.safe_load(config_bytes)["benchmarks"]:
        name = bench["name"]
        base = bench["base_name"]
        directory = ROOT / f"kprog/{arch}/micro-prog/build"
        native = directory / f"native-link/{base}.proof.o"
        candidates = [directory / f"{base}.bpf.o",
                      ROOT / f"kprog/test/build-{arch}/{arch}_sim_proofs/{base}.bpf.o"]
        yield pending(arch, "micro", name, native, [identity(p) for p in candidates],
                      config=str(config), config_sha256=hashlib.sha256(config_bytes).hexdigest())


def applications(arch: str):
    directory = ROOT / ("corpus/results/kprog_app_coverage_20261106" if arch == "x86"
                        else "corpus/results/kprog_arm64_app_coverage_20261106")
    inventories = sorted(directory.glob("*/programs.jsonl"))
    if not inventories:
        raise FileNotFoundError(f"application inventories missing: {directory}")
    for inventory in inventories:
        inventory_bytes = inventory.read_bytes()
        inventory_sha256 = hashlib.sha256(inventory_bytes).hexdigest()
        for line in inventory_bytes.splitlines():
            row = json.loads(line)
            name = row["name"]
            compile_record = inventory.parent / f"compile/{name}.json"
            evidence = {"inventory": str(inventory), "inventory_sha256": inventory_sha256,
                        "generation": row}
            candidates = []
            if compile_record.exists():
                compiled = json.loads(compile_record.read_text())
                evidence["compile_record"] = str(compile_record)
                evidence["compile_returncode"] = compiled["returncode"]
                command = compiled["command"]
                candidates.append(identity(Path(command[command.index("-o") + 1])))
            else:
                evidence["compile_record_error"] = "compile_record_missing"
            verify_record = inventory.parent / f"verify/{name}.json"
            if verify_record.exists():
                verified = json.loads(verify_record.read_text())
                evidence["verify_record"] = str(verify_record)
                evidence["verify_returncode"] = verified["returncode"]
            yield pending(arch, "application", name, Path(row["proof"]), candidates,
                          phase=inventory.parent.name, **evidence)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    args.out.parent.mkdir(parents=True, exist_ok=True)
    with args.out.open("w") as output:
        for arch in ("x86", "arm64"):
            for records in (micro(arch), applications(arch)):
                for row in records:
                    output.write(json.dumps(row, sort_keys=True) + "\n")
    args.out.with_suffix(args.out.suffix + ".gz").write_bytes(
        gzip.compress(args.out.read_bytes(), mtime=0))
    print(f"Wrote {args.out}; no translation-validation certificates exist.")
    return 0  # Inventory succeeded; every program's validation status is explicit.


if __name__ == "__main__":
    raise SystemExit(main())
