#!/usr/bin/env python3
from __future__ import annotations

import argparse
import sys
import json
import subprocess
from collections import defaultdict
from pathlib import Path
from typing import Iterable



BPF_MAP_TYPE_HASH = 1
BPF_MAP_TYPE_ARRAY = 2
BPF_MAP_TYPE_PROG_ARRAY = 3
BPF_MAP_TYPE_PERF_EVENT_ARRAY = 4
BPF_MAP_TYPE_PERCPU_HASH = 5
BPF_MAP_TYPE_PERCPU_ARRAY = 6
BPF_MAP_TYPE_STACK_TRACE = 7
BPF_MAP_TYPE_LRU_HASH = 9
BPF_MAP_TYPE_LRU_PERCPU_HASH = 10
BPF_MAP_TYPE_LPM_TRIE = 11
BPF_MAP_TYPE_ARRAY_OF_MAPS = 12
BPF_MAP_TYPE_HASH_OF_MAPS = 13
BPF_MAP_TYPE_RINGBUF = 27


def map_rule(
    match: str,
    pattern: str,
    type_: int,
    key_size: int = 0,
    value_size: int = 0,
    max_entries: int = 0,
    object_scoped: bool = False,
    exclude: str | None = None,
    inner: tuple[int, int, int, int] | None = None,
    native_symbol: str | None = None,
) -> dict[str, object]:
    entry: dict[str, object] = {
        "match": match,
        "pattern": pattern,
        "type": type_,
    }
    if key_size:
        entry["key_size"] = key_size
    if value_size:
        entry["value_size"] = value_size
    if max_entries:
        entry["max_entries"] = max_entries
    if object_scoped:
        entry["object_scoped"] = True
    if exclude is not None:
        entry["exclude"] = exclude
    if native_symbol is not None:
        entry["native_symbol"] = native_symbol
    if inner is not None:
        inner_type, inner_key_size, inner_value_size, inner_max_entries = inner
        entry["inner_type"] = inner_type
        entry["inner_key_size"] = inner_key_size
        entry["inner_value_size"] = inner_value_size
        entry["inner_max_entries"] = inner_max_entries
    return entry


CILIUM_MAP_RULES = [
    map_rule("suffix", "_fix", BPF_MAP_TYPE_HASH),
    map_rule("suffix", "_dyn", BPF_MAP_TYPE_LPM_TRIE),
    map_rule("suffix", "_version", BPF_MAP_TYPE_HASH_OF_MAPS, value_size=4, max_entries=64),
    map_rule("exact", "cilium_ratelimit_metrics", BPF_MAP_TYPE_HASH, 4, 8, 64),
    map_rule("exact", "cilium_ratelimit", BPF_MAP_TYPE_LRU_HASH, 8, 16, 1024),
    map_rule("exact", "cilium_lb4_reverse_nat", BPF_MAP_TYPE_HASH, 2, 6, 65536),
    map_rule("exact", "cilium_lb6_reverse_nat", BPF_MAP_TYPE_HASH, 2, 18, 65536),
    # Cilium sizes this NAT map from host memory (591427 in the 64G guest); type, key and value
    # sizes separate it from cilium_snat_v4_alloc_retries under the shared 15-character name.
    map_rule("exact", "cilium_snat_v4_external", BPF_MAP_TYPE_LRU_HASH, 14, 40),
    map_rule("exact", "cilium_snat_v4_alloc_retries", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 4, 33),
    map_rule("exact", "cilium_l2_responder_v4", BPF_MAP_TYPE_HASH, 8, 8, 4096),
    map_rule("exact", "cilium_l2_responder_v6", BPF_MAP_TYPE_HASH, 24, 8, 4096),
    map_rule("exact", "cilium_devices", BPF_MAP_TYPE_HASH, 4, 16, 512, True),
    map_rule("exact", "cilium_policy_v2", BPF_MAP_TYPE_LPM_TRIE, 12, 12, 16384, True),
    map_rule("exact", "cilium_nodeport_nat_buffer", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 18, 1, True),
    map_rule("exact", "cilium_nodeport_neigh4", BPF_MAP_TYPE_LRU_HASH, 4, 8, object_scoped=True),
    map_rule("exact", "cilium_nodeport_neigh6", BPF_MAP_TYPE_LRU_HASH, 16, 8, object_scoped=True),
    map_rule("exact", "cilium_tail_call_buffer6", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 60, 1, True),
    map_rule("exact", "cilium_tail_call_buffer4", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 60, 1, True),
    map_rule("prefix", "cilium_calls", BPF_MAP_TYPE_PROG_ARRAY, 4, 4,
             object_scoped=True, native_symbol="cilium_calls"),
]

TRACEE_TETRAGON_MAP_RULES = [
    map_rule("exact", "execve_calls", BPF_MAP_TYPE_PROG_ARRAY, 4, 4, 2, True),
    map_rule("exact", "tcpmon_map", BPF_MAP_TYPE_PERF_EVENT_ARRAY, 4, 4, 8, True),
    map_rule("exact", "tg_rb_events", BPF_MAP_TYPE_RINGBUF, max_entries=524288, object_scoped=True),
    map_rule("exact", "buffer_heap_map", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 4352, 1, True),
    map_rule("prefix", "string_maps_", BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8, True,
             exclude="string_maps_heap"),
    map_rule("exact", "string_maps_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 16384, 1, True),
    map_rule("exact", "substring_map", BPF_MAP_TYPE_ARRAY, 4, 100, 1, True),
    map_rule("exact", "tg_errmetrics_map", BPF_MAP_TYPE_LRU_PERCPU_HASH, 12, 4, 1024, True),
    map_rule("exact", "tg_conf_map", BPF_MAP_TYPE_ARRAY, 4, 48, 1, True),
    map_rule("exact", "policy_conf", BPF_MAP_TYPE_ARRAY, 4, 1, 1, True),
    map_rule("exact", "execve_msg_heap_map", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 6224, 1, True),
    map_rule("exact", "tg_binary_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 792, 1, True),
    map_rule("exact", "tg_parents_bin", BPF_MAP_TYPE_LRU_HASH, 4, 792, 1, True),
    map_rule("exact", "execve_map", BPF_MAP_TYPE_HASH, 4, 896, 32768, True),
    map_rule("exact", "execve_map_stats", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 8, 3, True),
    map_rule("exact", "execve_val", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 896, 1, True),
    map_rule("exact", "execve_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 4112, 1, True),
    map_rule("exact", "tg_execve_joined_info_map", BPF_MAP_TYPE_LRU_HASH, 8, 16, 8192, True),
    map_rule("exact", "tg_execve_joined_info_map_stats", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 8, 3, True),
    map_rule("exact", "tg_stats_map", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 14336, 1, True),
    map_rule("exact", "tg_cgrps_tracking_map", BPF_MAP_TYPE_HASH, 8, 144, 32768, True),
    map_rule("exact", "tg_cgrps_tracking_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 144, 1, True),
    map_rule("exact", "tg_cgrps_msg_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 4312, 1, True),
    map_rule("exact", "tg_cgtracker_map", BPF_MAP_TYPE_HASH, 8, 8, 1, True),
    map_rule("exact", "string_prefix_maps", BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8, True),
    map_rule("exact", "string_prefix_maps_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 260, 1, True),
    map_rule("exact", "string_postfix_maps", BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8, True),
    map_rule("exact", "string_postfix_maps_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 132, 1, True),
    map_rule("exact", "cgroup_rate_options_map", BPF_MAP_TYPE_ARRAY, 4, 16, 1, True),
    map_rule("exact", "cgroup_rate_map", BPF_MAP_TYPE_PERCPU_HASH, 8, 40, 1, True),
    map_rule("exact", "throttle_heap_map", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 160, 1, True),
    map_rule("exact", "tg_mbset_map", BPF_MAP_TYPE_HASH, 256, 8, 1024, True),
    map_rule("exact", "tg_mbset_gen", BPF_MAP_TYPE_ARRAY, 4, 8, 1, True),
    map_rule("exact", "data_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 32768, 1, True),
    map_rule("exact", "heap_ro_zero", BPF_MAP_TYPE_ARRAY, 4, 16384, 1, True),
    map_rule("exact", "heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 4104, 1, True),
    map_rule("exact", "process_call_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 25632, 1, True),
    map_rule("exact", "override_tasks", BPF_MAP_TYPE_HASH, 8, 4, 1, True),
    map_rule("exact", "enforcer_data", BPF_MAP_TYPE_HASH, 8, 12, 1, True),
    map_rule("exact", "enforcer_missed_notifications", BPF_MAP_TYPE_HASH, 12, 4, 128, True),
    map_rule("exact", "ratelimit_map", BPF_MAP_TYPE_LRU_HASH, 224, 8, object_scoped=True),
    map_rule("exact", "ratelimit_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 352, 1, True),
    map_rule("exact", "retprobe_map", BPF_MAP_TYPE_HASH, 16, 24, 1024, True),
    map_rule("exact", "fdinstall_map", BPF_MAP_TYPE_LRU_HASH, 16, 4104, object_scoped=True),
    map_rule("exact", "stack_trace_map", BPF_MAP_TYPE_STACK_TRACE, 4, 1016, object_scoped=True),
    map_rule("exact", "sleepable_preload", BPF_MAP_TYPE_HASH, 8, 4100, object_scoped=True),
    map_rule("exact", "tg_ipv6_ext_heap", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 8, 1, True),
    map_rule("exact", "tg_mb_sel_opts", BPF_MAP_TYPE_ARRAY, 4, 12, 10, True),
    map_rule("exact", "tg_mb_paths", BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 10, True),
    map_rule("exact", "addr4lpm_maps", BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8, True),
    map_rule("exact", "addr6lpm_maps", BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8, True),
    map_rule("exact", "policy_stats", BPF_MAP_TYPE_ARRAY, 4, 80, 1, True),
    map_rule("exact", "filter_map", BPF_MAP_TYPE_ARRAY, 4, 4096, 1, True),
    map_rule("exact", "config_map", BPF_MAP_TYPE_ARRAY, 4, 736, 1, True),
    map_rule("exact", "write_offload", BPF_MAP_TYPE_HASH, 8, 16, 1, True),
    map_rule("exact", "argfilter_maps", BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8, True),
    map_rule("exact", "policy_filter_maps", BPF_MAP_TYPE_HASH_OF_MAPS, 4, 4, 128, True,
             inner=(BPF_MAP_TYPE_HASH, 8, 1, 1)),
    map_rule("exact", "policy_filter_cgroup_maps", BPF_MAP_TYPE_HASH_OF_MAPS, 8, 4, 1024, True,
             inner=(BPF_MAP_TYPE_HASH, 4, 1, 128)),
    map_rule("exact", "exit_heap_map", BPF_MAP_TYPE_PERCPU_ARRAY, 4, 40, 1, True),
]


def map_rules_for_app(app: str) -> list[dict[str, object]]:
    if app == "cilium":
        return CILIUM_MAP_RULES
    if app in {"tracee", "tetragon"}:
        return TRACEE_TETRAGON_MAP_RULES
    return []


def parse_object_spec(raw: str) -> tuple[Path, Path | None]:
    path, sep, source = raw.partition(",source=")
    if not path:
        raise SystemExit("--object requires a native object path")
    return Path(path), (Path(source) if sep else None)


def function_facts(obj: Path) -> dict[str, tuple[str, list[str]]]:
    """ELF section and referenced map symbols of every function in a native object."""
    try:
        from elftools.elf.elffile import ELFFile
        from elftools.elf.relocation import RelocationSection
    except ImportError as exc:
        raise SystemExit("pyelftools is required to read native objects") from exc
    facts: dict[str, tuple[str, list[str]]] = {}
    with obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        if symtab is None:
            raise SystemExit(f"native object has no .symtab: {obj}")
        sections = list(elf.iter_sections())
        maps_sections = {i for i, sec in enumerate(sections) if sec.name in (".maps", "maps")}
        functions: dict[int, list[tuple[int, int, str]]] = defaultdict(list)
        for sym in symtab.iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and isinstance(sym["st_shndx"], int):
                functions[sym["st_shndx"]].append((int(sym["st_value"]), int(sym["st_size"]), sym.name))
        used: dict[str, set[str]] = defaultdict(set)
        for rel_section in sections:
            if not isinstance(rel_section, RelocationSection):
                continue
            index = rel_section["sh_info"]
            if index not in functions:
                continue
            rel_symbols = sections[rel_section["sh_link"]]
            for rel in rel_section.iter_relocations():
                target = rel_symbols.get_symbol(rel["r_info_sym"])
                if not isinstance(target["st_shndx"], int) or target["st_shndx"] not in maps_sections:
                    continue
                for start, size, name in functions[index]:
                    if start <= rel["r_offset"] < start + max(size, 1):
                        used[name].add(target.name)
        for index, items in functions.items():
            for _start, _size, name in items:
                facts[name] = (sections[index].name, sorted(used[name]))
    return facts


def text_symbols(llvm_nm: str, obj: Path, skip_prefixes: tuple[str, ...]) -> list[str]:
    completed = subprocess.run(
        [llvm_nm, "--defined-only", "--format=posix", str(obj)],
        check=True,
        capture_output=True,
        text=True,
    )
    out: list[str] = []
    for line in completed.stdout.splitlines():
        fields = line.split()
        if len(fields) < 2 or fields[1] not in {"T", "t"}:
            continue
        symbol = fields[0]
        if any(symbol.startswith(prefix) for prefix in skip_prefixes):
            continue
        out.append(symbol)
    if not out:
        raise SystemExit(f"no native text symbols in {obj}")
    return out


def rel_object(output: Path, obj: Path) -> str:
    try:
        return str(obj.resolve().relative_to(output.parent.resolve()))
    except ValueError:
        return str(obj)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--app", required=True)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--llvm-nm", required=True)
    parser.add_argument("--object", action="append", required=True)
    parser.add_argument("--skip-prefix", action="append", default=["LBB", "__check_"])

    args = parser.parse_args()

    output: Path = args.output
    objects: list[dict[str, object]] = []
    for raw in args.object:
        obj, source = parse_object_spec(raw)
        if source is not None and not source.is_file():
            raise SystemExit(f"source BPF object {source} for {obj} is missing")
        rel = rel_object(output, obj)
        facts = function_facts(obj)
        by_program: dict[str, list[str]] = defaultdict(list)
        for symbol in text_symbols(args.llvm_nm, obj, tuple(args.skip_prefix)):
            by_program[symbol[:15]].append(symbol)
        for program in sorted(by_program):
            symbols = sorted(by_program[program])
            entry: dict[str, object] = {
                "program": program,
                "native_object": rel,
            }
            if len(symbols) == 1:
                entry["symbol"] = symbols[0]
                section, _maps = facts.get(symbols[0], ("", []))
                if section:
                    entry["section"] = section
            if source is not None:
                entry["source_bpf_object"] = rel_object(output, source)
            objects.append(entry)

    manifest: dict[str, object] = {
        "version": 1,
        "app": args.app,
        "status": "native-objects-proof-linked",
        "objects": objects,
    }
    map_rules = map_rules_for_app(args.app)
    if map_rules:
        manifest["map_rules"] = map_rules

    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(
        json.dumps(manifest, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
    )


if __name__ == "__main__":
    main()
