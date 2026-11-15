#!/usr/bin/env python3
"""Compare emitted code across a header edit without another source checkout.

Stream the historical/current header at the fixture's actual include location,
then check the current stream against an ordinary current compilation as well.
Compiler arguments follow --. One fixture build is replaced in place;
raw logs, commands and comparison results persist under --output.
"""
from __future__ import annotations

import argparse
import json
import os
from pathlib import Path
import re
import subprocess

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection


def allocated(path: Path):
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        sections = {s.name: s.data() for s in elf.iter_sections() if s["sh_flags"] & 2}
        relocations = []
        for section in elf.iter_sections():
            if not isinstance(section, RelocationSection):
                continue
            target = elf.get_section(section["sh_info"])
            if not target["sh_flags"] & 2:
                continue
            symbols = elf.get_section(section["sh_link"])
            for relocation in section.iter_relocations():
                symbol = symbols.get_symbol(relocation["r_info_sym"])
                symbol_entry = dict(symbol.entry)
                # The resolved name is compared below; its string-table offset
                # changes with ELF string packing and is not target identity.
                del symbol_entry["st_name"]
                relocations.append((target.name, dict(relocation.entry),
                                    symbol.name, symbol_entry))
        return sections, relocations


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for option in ("before", "header", "source", "output"):
        parser.add_argument("--" + option, required=True)
    parser.add_argument("--also-header", action="append", default=[],
                        help="replay an included header, after any parent supplied earlier")
    parser.add_argument("--ir-pass", help="production LLVM IR pass applied before the BPF backend")
    parser.add_argument("--objdump", help="record stage disassembly as raw diagnostic output")
    parser.add_argument("compiler", nargs=argparse.REMAINDER)
    args = parser.parse_args()
    compiler = args.compiler[1:] if args.compiler[:1] == ["--"] else args.compiler
    if not compiler:
        parser.error("provide the compiler and flags after --")
    root = Path(__file__).resolve().parents[3]
    header, source = Path(args.header).resolve(), Path(args.source).resolve()
    output = Path(args.output).resolve()
    build = root / "kprog/formal/build"
    build.mkdir(parents=True, exist_ok=True)
    product = build / (source.stem + ".o")
    preprocessed = build / (source.stem + ".i")
    # Unique run directories retain earlier successes and failed attempts.
    output.mkdir(parents=True, exist_ok=False)
    text = source.read_text()
    candidates = {f'#include "{header}"',
                  f'#include "{os.path.relpath(header, source.parent)}"'}
    includes = [line.strip() for line in text.splitlines() if line.strip() in candidates]
    if len(includes) != 1:
        raise SystemExit("fixture must contain one direct quoted include of the selected header")
    directive = includes[0]
    position = text.index(directive)
    resume = text[:position].count("\n") + 1
    revision = subprocess.check_output(["git", "rev-parse", args.before], cwd=root, text=True).strip()
    previous = subprocess.check_output(
        ["git", "show", f"{revision}:{header.relative_to(root).as_posix()}"], cwd=root, text=True)
    nested = [Path(path).resolve() for path in args.also_header]
    historical_nested = {path: subprocess.check_output(
        ["git", "show", f"{revision}:{path.relative_to(root).as_posix()}"],
        cwd=root, text=True) for path in nested}
    commands = []

    def run(stage, command, stdin=None):
        result = subprocess.run(command, input=stdin, capture_output=True, text=True)
        (output / f"{stage}.log").write_text(result.stdout + result.stderr)
        commands.append({"stage": stage, "argv": command, "exit": result.returncode})
        (output / "commands.json").write_text(json.dumps(commands, indent=2) + "\n")
        if result.returncode:
            raise SystemExit(f"{stage} exited {result.returncode}; see {output / (stage + '.log')}")

    (output / "header.diff").write_text(subprocess.check_output(
        ["git", "diff", "--", str(header.relative_to(root))] +
        [str(path.relative_to(root)) for path in nested], cwd=root, text=True))
    (output / "inputs.json").write_text(json.dumps({
        "before": revision, "header": str(header), "source": str(source),
        "also_headers": [str(path) for path in nested],
        "product": str(product), "preprocessed": str(preprocessed),
        "current_head": subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=root, text=True).strip(),
        "current_header_patch": "header.diff",
        "include": directive, "recipe": "Replace at the actual include; retain every preceding define.",
    }, indent=2) + "\n")
    flags = compiler + ["-iquote", str(header.parent), "-iquote", str(source.parent)]
    def compile_product(phase, unit):
        if args.ir_pass:
            ir = product.with_suffix(".bc")
            run(phase + "-frontend", flags + ["-emit-llvm", "-c", str(unit), "-o", str(ir)])
            run(phase + "-ir-pass", [args.ir_pass, str(ir), "-o", str(ir)])
            run(phase + "-compile", flags + ["-c", str(ir), "-o", str(product)])
        else:
            run(phase + "-compile", flags + ["-c", str(unit), "-o", str(product)])

    observations = {}
    for phase, body in (("before", previous), ("after", header.read_text())):
        for path in nested:
            # Earlier replacements carry #line locations for their own quoted
            # includes. Resolve those against that parent, rather than the root.
            parent, line, offset, sites = header, 1, 0, []
            for row in body.splitlines(keepends=True):
                marker = re.fullmatch(r'#line (\d+) "([^"]+)"\s*', row)
                quoted = re.fullmatch(r'\s*#include "([^"]+)"\s*', row)
                if marker:
                    line, parent = int(marker[1]), Path(marker[2])
                else:
                    if quoted and (parent.parent / quoted[1]).resolve() == path:
                        include = row.strip()
                        sites.append((offset + row.index(include), include, line, parent))
                    line += 1
                offset += len(row)
            if not sites:
                raise SystemExit(f"replayed include graph must contain {path}")
            contents = historical_nested[path] if phase == "before" else path.read_text()
            # Replace every occurrence: a guarded header may be included both
            # directly and through another header; its first inclusion wins.
            for at, include, line, parent in reversed(sites):
                body = (body[:at] + f'#line 1 "{path}"\n' + contents
                        + f'\n#line {line} "{parent}"\n' + body[at + len(include):])
        unit = (f'#line 1 "{source}"\n' + text[:position] + f'#line 1 "{header}"\n'
                + body + f'\n#line {resume} "{source}"\n' + text[position + len(directive):])
        run(phase + "-preprocess", flags + ["-E", "-x", "c", "-", "-o", str(preprocessed)], unit)
        compile_product(phase, preprocessed)
        observations[phase] = allocated(product)
        if args.objdump:
            run(phase + "-disassembly", [args.objdump, "-dr", str(product)])
    compile_product("normal", source)
    if args.objdump:
        run("normal-disassembly", [args.objdump, "-dr", str(product)])
    before, after, normal = observations["before"], observations["after"], allocated(product)
    for phase, (sections, relocations) in (("before", before), ("after", after), ("normal", normal)):
        (output / f"{phase}-layout.json").write_text(json.dumps({
            "allocated_section_bytes": {name: len(data) for name, data in sections.items()},
            "relocations": relocations,
        }, indent=2, default=dict) + "\n")
    result = {"allocated_sections_equal": before[0] == after[0],
              "allocated_relocations_equal": before[1] == after[1],
              "current_stream_equals_normal_build": after == normal,
              "allocated_section_bytes": {name: len(data) for name, data in after[0].items()},
              "allocated_relocations": len(after[1])}
    (output / "comparison.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result), flush=True)
    if not all(result[key] for key in ("allocated_sections_equal", "allocated_relocations_equal",
                                       "current_stream_equals_normal_build")):
        raise SystemExit(1)


if __name__ == "__main__":
    main()
