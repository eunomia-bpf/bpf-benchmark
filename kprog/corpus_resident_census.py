#!/usr/bin/env python3
"""Enumerate retained application program instances for a static kprog census."""
from __future__ import annotations
import argparse
import collections
import importlib.util
import os
import sys
import traceback
import hashlib
import json
from pathlib import Path
import re
import subprocess
import tarfile

ROOT = Path(__file__).resolve().parents[1]


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def load_contexts(text):
    pending, records = {}, {}
    for line in text.splitlines():
        thread = re.search(r"pid=(\d+) tid=(\d+)", line)
        if not thread:
            continue
        key = thread.groups()
        if "BPF_PROG_LOAD type=" in line:
            pending[key] = dict(re.findall(r"(\w+)=([^\s]*)", line))
        elif "PROG_LOAD ->" in line and "kernel_prog_id=" in line:
            identifier = re.search(r"kernel_prog_id=(\d+)", line)
            if identifier and key in pending:
                records[int(identifier[1])] = pending.pop(key)
    return records


def collect(spec):
    rows, inputs = [], []
    for app in spec["applications"]:
        coverage = ROOT / app["coverage"]
        archive = ROOT / app["archive"]
        document = json.loads(coverage.read_text())
        measured = next(row["app"] for row in document["results"]
                        if row["application"] == app["application"])
        baseline = measured["baseline"]["bpf"]
        with tarfile.open(archive) as tf:
            prefix = "/" + app["evidence"] + "/baseline/"
            programs_member = next(m for m in tf
                                   if m.name.endswith(prefix + "program-inventory.json"))
            maps_member = next(m for m in tf
                               if m.name.endswith(prefix + "map-inventory.json"))
            programs = {p["id"]: p for p in json.loads(tf.extractfile(programs_member).read())}
            maps = {p["id"]: p for p in json.loads(tf.extractfile(maps_member).read())}
            shim_member = next(m for m in tf
                               if m.name.endswith("/" + app["shim"] + ".baseline.log"))
            contexts = load_contexts(tf.extractfile(shim_member).read().decode())
            dumps = {}
            for member in tf:
                if member.isfile() and prefix in member.name and member.name.endswith(".xlated.txt"):
                    match = re.search(r"/(\d+)-[^/]+\.xlated\.txt$", member.name)
                    if match:
                        dumps[int(match[1])] = tf.extractfile(member).read().decode()
        manifest_path = Path(app["producer"]) / "manifest.json"
        manifest = json.loads(manifest_path.read_text())
        inputs.append(dict(application=app["application"],
                           expected_instances=app["expected"], observed_instances=len(baseline),
                           coverage=app["coverage"], coverage_sha256=sha(coverage),
                           archive=app["archive"], archive_sha256=sha(archive),
                           manifest=str(manifest_path), manifest_sha256=sha(manifest_path),
                           map_inventory=list(maps.values())))
        for identifier, measurement in baseline.items():
            identifier = int(identifier)
            info = programs.get(identifier, measurement)
            name = info.get("name", "")
            context = contexts.get(identifier, {})
            helpers = set(int(value) for value in re.findall(r"#(\d+)", dumps.get(identifier, "")))
            candidates = []
            for entry in manifest["objects"]:
                if entry["program"] != name[:15]:
                    continue
                source_name = name if len(name) > 15 else None
                selected_name = entry.get("source_btf_symbol", entry.get("symbol"))
                if source_name and selected_name and selected_name != source_name:
                    continue
                if "source_bytecode_len" in entry and context.get("insn_cnt"):
                    if entry["source_bytecode_len"] != int(context["insn_cnt"]) * 8:
                        continue
                if "source_xlated_len" in entry and entry["source_xlated_len"] != info["bytes_xlated"]:
                    continue
                if "prog_type" in entry and context.get("type"):
                    if entry["prog_type"] != int(context["type"]):
                        continue
                if identifier in dumps:
                    if "source_has_helper" in entry and entry["source_has_helper"] not in helpers:
                        continue
                    if "source_lacks_helper" in entry and entry["source_lacks_helper"] in helpers:
                        continue
                names = [maps[i]["name"] for i in info.get("map_ids", []) if i in maps]
                if info.get("map_ids"):
                    if entry.get("source_map_prefix") and not any(n.startswith(entry["source_map_prefix"]) for n in names):
                        continue
                    if any(n.startswith(prefix) for prefix in entry.get("source_lacks_map_prefix", []) for n in names):
                        continue
                candidate = dict(native_object=str(Path(app["producer"]) / entry["native_object"]),
                                 symbol=entry.get("symbol", source_name or name), selector=entry)
                if not any((c["native_object"], c["symbol"]) ==
                           (candidate["native_object"], candidate["symbol"]) for c in candidates):
                    candidates.append(candidate)
            rows.append(dict(application=app["application"], source_prog_id=identifier,
                             name=name, measurement=measurement, program_info=info,
                             context=context, program_inventory_present=identifier in programs,
                             xlated_dump_present=identifier in dumps, helper_ids=sorted(helpers),
                             map_info=[maps[i] for i in info.get("map_ids", []) if i in maps],
                             manifest=str(manifest_path), native_candidates=candidates,
                             generation="pending", compile="pending", verifier="pending"))
    return dict(source_head=spec["source_head"], applications=inputs,
                instances=len(rows), programs=rows)



def native_bindings(path):
    """Use native ELF map/global identities for the ordinary generator interface."""
    from elftools.elf.elffile import ELFFile
    result = []
    with Path(path).open("rb") as fp:
        elf = ELFFile(fp)
        for symbol in elf.get_section_by_name(".symtab").iter_symbols():
            if (symbol["st_info"]["type"] != "STT_OBJECT" or
                    symbol["st_info"]["bind"] != "STB_GLOBAL" or
                    not isinstance(symbol["st_shndx"], int)):
                continue
            section = elf.get_section(symbol["st_shndx"])
            if section.name == ".maps":
                offset = None
            elif section.name.startswith((".rodata", ".data", ".bss", ".kconfig")):
                offset = symbol["st_value"] - section["sh_addr"]
            else:
                continue
            result.append(dict(native_symbol=symbol.name, value_offset=offset,
                               native_section=section.name, native_size=symbol["st_size"]))
    return result


def diagnostic_class(stage, text):
    if stage == "native_selection_failed":
        return "native_manifest_selection_gap"
    for phrase, label in [
        ("unsupported helper", "helper_lowering"),
        ("unknown helper", "helper_lowering"),
        ("unsupported instruction", "instruction_lowering"),
        ("unsupported mnemonic", "instruction_lowering"),
        ("unsupported opcode", "instruction_lowering"),
        ("stack limit", "compiler_stack"),
        ("stack size", "compiler_stack"),
        ("BPF stack", "compiler_stack"),
        ("unsupported", "specialization_unsupported"),
    ]:
        if phrase in text:
            return label
    return stage


def run_census(inventory, output, native_link, clang):
    """Visit every retained instance; each generation/compiler outcome stays raw."""
    spec = importlib.util.spec_from_file_location(
        "census_x86_specializer", ROOT / "kprog/x86/trusted_specializer.py")
    adapter = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(adapter)
    gen = adapter.gen
    output.mkdir(parents=True, exist_ok=True)
    observed = []
    source_head = json.loads(inventory.read_text())["source_head"]
    for row in json.loads(inventory.read_text())["programs"]:
        directory = output / ("%03d-%s-%s" % (
            len(observed), row["application"].replace("/", "_"), row["source_prog_id"]))
        directory.mkdir(exist_ok=True)
        result = {k: row[k] for k in ["application", "source_prog_id", "name"]}
        result.update(generation="pending", compile="pending", verifier="pending",
                      directory=str(directory), source_head=source_head)
        (directory / "input.json").write_text(json.dumps(row, indent=2) + "\n")
        stage = "native_selection_failed"
        try:
            if len(row["native_candidates"]) != 1:
                raise RuntimeError("current manifest candidates=%d" % len(row["native_candidates"]))
            candidate = row["native_candidates"][0]
            native = Path(candidate["native_object"])
            entry = candidate["symbol"]
            bindings = native_bindings(native)
            (directory / "bindings.json").write_text(json.dumps(bindings, indent=2) + "\n")
            result.update(native_object=str(native), native_sha256=sha(native), entry=entry)
            stage = "generation_failed"
            command = [str(native_link), "--input", str(native), "--symbol", entry,
                       "--mode", "proof", "--preserve-entry-abi",
                       "--output", str(directory / "trusted_x86.proof.o")]
            done = subprocess.run(command, text=True, capture_output=True)
            (directory / "link.json").write_text(json.dumps(dict(
                command=command, returncode=done.returncode,
                stdout=done.stdout, stderr=done.stderr), indent=2) + "\n")
            done.check_returncode()
            instructions, functions, exit_addr, rodata = gen.parse_native_linked_program(
                "trusted_x86", directory)
            kind = adapter.context_kind(int(row["context"]["type"]))
            text = gen.render_program(
                "trusted_x86", instructions, functions, kind=kind,
                exit_addr=exit_addr, rodata16=rodata, program_section="census/program",
                trusted_map_bindings=[{k: binding[k] for k in ["native_symbol", "value_offset"]}
                                      for binding in bindings])
            text = text.replace('#include "../x86_sim_local_bpf.h"',
                                '#include ' + json.dumps(str(ROOT / "kprog/x86/x86_sim_local_bpf.h")))
            source = directory / "trusted_x86.bpf.c"
            source.write_text(text)
            result["generation"] = "passed"
            stage = "compilation_failed"
            command = [str(clang), "-g", "-O3", "-mcpu=v4", "-target", "bpf",
                       "-mllvm", "-bpf-stack-size=4096", "-D__TARGET_ARCH_x86",
                       "-I", str(ROOT / "vendor/libbpf/include/uapi"),
                       "-I", str(ROOT / "vendor/libbpf/src"),
                       "-I", "/usr/include/x86_64-linux-gnu",
                       "-c", str(source), "-o", str(directory / "trusted_x86.bpf.o")]
            done = subprocess.run(command, text=True, capture_output=True)
            (directory / "compile.json").write_text(json.dumps(dict(
                command=command, returncode=done.returncode, source_sha256=sha(source),
                stdout=done.stdout, stderr=done.stderr), indent=2) + "\n")
            done.check_returncode()
            result.update(compile="passed", stage="compiled_pending_verifier")
        except Exception as error:
            result.update(stage=stage, error=str(error), traceback=traceback.format_exc())
            detail = str(error)
            if isinstance(error, subprocess.CalledProcessError):
                detail += (done.stderr or "") + (done.stdout or "")
            result["failure_class"] = diagnostic_class(stage, detail)
            if stage == "compilation_failed":
                result["compile"] = "failed"
            else:
                result["generation"] = "failed"
        (directory / "result.json").write_text(json.dumps(result, indent=2) + "\n")
        observed.append(result)
        (output / "progress.json").write_text(json.dumps(dict(
            source_head=source_head, attempted=len(observed),
            stages=dict(collections.Counter(r["stage"] for r in observed)),
            classes=dict(collections.Counter(r.get("failure_class", r["stage"]) for r in observed)),
            programs=observed), indent=2) + "\n")
        print(result["application"], result["source_prog_id"], result["stage"],
              result.get("failure_class", ""), flush=True)
    (output / "generation-compile.json").write_text((output / "progress.json").read_text())

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("inputs", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--run", action="store_true")
    parser.add_argument("--native-link", type=Path)
    parser.add_argument("--clang", type=Path, default=Path("/usr/lib/llvm-18/bin/clang"))
    args = parser.parse_args()
    if args.run:
        run_census(args.inputs, args.output, args.native_link, args.clang)
        return
    result = collect(json.loads(args.inputs.read_text()))
    args.output.write_text(json.dumps(result, indent=2) + "\n")
    for app in result["applications"]:
        rows = [r for r in result["programs"] if r["application"] == app["application"]]
        print(app["application"], len(rows),
              dict(collections.Counter(len(r["native_candidates"]) for r in rows)),
              "contexts", sum(bool(r["context"]) for r in rows))


if __name__ == "__main__":
    main()
