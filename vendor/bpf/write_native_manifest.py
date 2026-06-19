#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import subprocess
from collections import defaultdict
from pathlib import Path
from typing import Iterable


BPF_LD_IMM64 = 0x18
BPF_CALL = 0x85

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

MAX_FILTER_VERSION = 64
MAX_EVENT_ID = 794

TRACEE_VERSIONED_FILTER_MAP_RULES = [
    map_rule("exact", "events_map_version", BPF_MAP_TYPE_HASH_OF_MAPS, 2, 4,
             MAX_FILTER_VERSION, True,
             inner=(BPF_MAP_TYPE_HASH, 4, 64, MAX_EVENT_ID)),
    map_rule("exact", "uid_filter_version", BPF_MAP_TYPE_HASH_OF_MAPS, 2, 4,
             MAX_FILTER_VERSION, True,
             inner=(BPF_MAP_TYPE_HASH, 4, 16, 256)),
    map_rule("exact", "pid_filter_version", BPF_MAP_TYPE_HASH_OF_MAPS, 2, 4,
             MAX_FILTER_VERSION, True,
             inner=(BPF_MAP_TYPE_HASH, 4, 16, 256)),
    map_rule("exact", "mnt_ns_filter_version", BPF_MAP_TYPE_HASH_OF_MAPS, 2, 4,
             MAX_FILTER_VERSION, True,
             inner=(BPF_MAP_TYPE_HASH, 4, 16, 256)),
    map_rule("exact", "pid_ns_filter_version", BPF_MAP_TYPE_HASH_OF_MAPS, 2, 4,
             MAX_FILTER_VERSION, True,
             inner=(BPF_MAP_TYPE_HASH, 4, 16, 256)),
    map_rule("exact", "uts_ns_filter_version", BPF_MAP_TYPE_HASH_OF_MAPS, 2, 4,
             MAX_FILTER_VERSION, True,
             inner=(BPF_MAP_TYPE_HASH, 16, 16, 256)),
    map_rule("exact", "comm_filter_version", BPF_MAP_TYPE_HASH_OF_MAPS, 2, 4,
             MAX_FILTER_VERSION, True,
             inner=(BPF_MAP_TYPE_HASH, 16, 16, 256)),
    map_rule("exact", "cgroup_id_filter_version", BPF_MAP_TYPE_HASH_OF_MAPS, 2,
             4, MAX_FILTER_VERSION, True,
             inner=(BPF_MAP_TYPE_HASH, 4, 16, 256)),
    map_rule("exact", "process_tree_map_version", BPF_MAP_TYPE_HASH_OF_MAPS, 2,
             4, MAX_FILTER_VERSION, True,
             inner=(BPF_MAP_TYPE_HASH, 4, 16, 10240)),
    map_rule("exact", "binary_filter_version", BPF_MAP_TYPE_HASH_OF_MAPS, 2, 4,
             MAX_FILTER_VERSION, True,
             inner=(BPF_MAP_TYPE_HASH, 260, 16, 256)),
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
    *TRACEE_VERSIONED_FILTER_MAP_RULES,
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


def source_object_for_native(root: Path, native_obj: Path) -> Path:
    name = native_obj.name
    if not name.endswith(".native.o"):
        raise SystemExit(f"cannot infer source BPF object for {native_obj}")
    return root / f"{name[:-len('.native.o')]}.o"


def scan_bpf_source_helpers(source_obj: Path) -> dict[str, set[int]]:
    try:
        from elftools.elf.elffile import ELFFile
    except ImportError as exc:
        raise SystemExit("pyelftools is required for --source-object-root") from exc

    by_program: dict[str, set[int]] = defaultdict(set)
    with source_obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        if symtab is None:
            raise SystemExit(f"source BPF object has no .symtab: {source_obj}")
        for sym in symtab.iter_symbols():
            info = sym["st_info"]
            if info["type"] != "STT_FUNC" or info["bind"] not in {"STB_GLOBAL", "STB_WEAK"}:
                continue
            if not isinstance(sym["st_shndx"], int):
                continue
            section = elf.get_section(sym["st_shndx"])
            if section is None or not (section["sh_flags"] & 0x4):
                continue
            data = section.data()
            start = int(sym["st_value"])
            size = int(sym["st_size"])
            if size <= 0:
                continue
            end = start + size
            if start < 0 or end > len(data) or size % 8 != 0:
                raise SystemExit(f"invalid BPF function bounds for {sym.name} in {source_obj}")
            helpers = by_program[sym.name[:15]]
            body = data[start:end]
            for off in range(0, len(body), 8):
                insn = body[off:off + 8]
                if insn[0] == BPF_CALL and insn[1] == 0:
                    helpers.add(int.from_bytes(insn[4:8], "little", signed=True))
                elif insn[0] == BPF_LD_IMM64:
                    # Skip the second half of an ldimm64 pair.
                    continue
    return by_program


def helper_signature(helpers: set[int] | None, ids: Iterable[int]) -> tuple[tuple[int, ...], tuple[int, ...]]:
    if helpers is None:
        return (), ()
    required = tuple(sorted(helper for helper in ids if helper in helpers))
    forbidden = tuple(sorted(helper for helper in ids if helper not in helpers))
    return required, forbidden


def parse_object_spec(raw: str) -> tuple[Path, dict[str, object]]:
    parts = raw.split(",")
    if not parts or not parts[0]:
        raise SystemExit("--object requires a native object path")
    path = Path(parts[0])
    attrs: dict[str, object] = {}
    for part in parts[1:]:
        key, sep, value = part.partition("=")
        if sep != "=" or not key or not value:
            raise SystemExit(f"invalid --object attribute: {part!r}")
        if key == "prog_type":
            attrs["prog_type"] = int(value, 0)
        elif key == "source_xlated_len":
            attrs["source_xlated_len"] = int(value, 0)
        elif key == "symbol":
            attrs["symbol"] = value
        elif key == "source_map_prefix":
            attrs.setdefault("source_map_prefixes", []).append(value)
        else:
            raise SystemExit(f"unsupported --object attribute: {key}")
    return path, attrs


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


def manifest_sort_key(key: tuple[object, ...]) -> tuple[str, ...]:
    return tuple("" if value is None else str(value) for value in key)


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
    parser.add_argument("--data-object", action="append", default=[])
    parser.add_argument("--skip-prefix", action="append", default=["LBB", "__check_"])
    parser.add_argument("--dedupe-program", choices=("none", "last"), default="none")
    parser.add_argument("--source-object-root", type=Path)
    parser.add_argument("--helper-disambiguate", action="append", type=lambda v: int(v, 0), default=[])
    args = parser.parse_args()

    output: Path = args.output
    entries_by_key: dict[tuple[object, ...], set[str]] = defaultdict(set)
    native_object_by_key: dict[tuple[object, ...], str] = {}
    helper_require_by_key: dict[tuple[object, ...], tuple[int, ...]] = {}
    helper_forbid_by_key: dict[tuple[object, ...], tuple[int, ...]] = {}
    selected_by_program: dict[tuple[object, ...], tuple[str, set[str]]] = {}
    selected_helpers_by_program: dict[tuple[object, ...], tuple[tuple[int, ...], tuple[int, ...]]] = {}
    source_helpers_cache: dict[Path, dict[str, set[int]]] = {}
    for raw in args.object:
        obj, attrs = parse_object_spec(raw)
        rel = rel_object(output, obj)
        source_helpers: dict[str, set[int]] | None = None
        if args.source_object_root:
            source_obj = source_object_for_native(args.source_object_root, obj)
            if not source_obj.is_file():
                raise SystemExit(f"source BPF object not found for {obj}: {source_obj}")
            source_helpers = source_helpers_cache.setdefault(
                source_obj, scan_bpf_source_helpers(source_obj))
        prefixes = attrs.get("source_map_prefixes") or [None]
        for symbol in text_symbols(args.llvm_nm, obj, tuple(args.skip_prefix)):
            if attrs.get("symbol") and symbol != attrs["symbol"]:
                continue
            program = symbol[:15]
            required, forbidden = helper_signature(
                None if source_helpers is None else source_helpers.get(program),
                args.helper_disambiguate)
            for prefix in prefixes:
                if args.dedupe_program == "last":
                    key = (program, attrs.get("prog_type"), prefix,
                           attrs.get("source_xlated_len"), required, forbidden)
                    if key not in selected_by_program or selected_by_program[key][0] != rel:
                        selected_by_program[key] = (rel, set())
                        selected_helpers_by_program[key] = (required, forbidden)
                    selected_by_program[key][1].add(symbol)
                else:
                    key = (program, rel, attrs.get("prog_type"), prefix,
                           attrs.get("source_xlated_len"), required, forbidden)
                    native_object_by_key[key] = rel
                    helper_require_by_key[key] = required
                    helper_forbid_by_key[key] = forbidden
                    entries_by_key[key].add(symbol)

    if args.dedupe_program == "last":
        for key, (rel, symbols) in selected_by_program.items():
            program, prog_type, prefix, source_xlated_len, required, forbidden = key
            out_key = (program, rel, prog_type, prefix, source_xlated_len,
                       required, forbidden)
            native_object_by_key[out_key] = rel
            helper_require_by_key[out_key] = selected_helpers_by_program[key][0]
            helper_forbid_by_key[out_key] = selected_helpers_by_program[key][1]
            entries_by_key[out_key].update(symbols)

    objects: list[dict[str, object]] = []
    for key in sorted(entries_by_key, key=manifest_sort_key):
        program, rel, prog_type, prefix, source_xlated_len, _required, _forbidden = key
        symbols = sorted(entries_by_key[key])
        entry: dict[str, object] = {
            "program": program,
            "native_object": native_object_by_key[key],
        }
        if len(symbols) == 1:
            entry["symbol"] = symbols[0]
        if prog_type is not None:
            entry["prog_type"] = prog_type
        if source_xlated_len is not None:
            entry["source_xlated_len"] = source_xlated_len
        if prefix is not None:
            entry["source_map_prefix"] = prefix
        required = helper_require_by_key.get(key, ())
        forbidden = helper_forbid_by_key.get(key, ())
        if required:
            if len(required) != 1:
                raise SystemExit("manifest supports one required helper discriminator")
            entry["source_has_helper"] = required[0]
        if forbidden:
            if len(forbidden) != 1:
                raise SystemExit("manifest supports one forbidden helper discriminator")
            entry["source_lacks_helper"] = forbidden[0]
        objects.append(entry)

    manifest: dict[str, object] = {
        "version": 1,
        "app": args.app,
        "status": "native-objects-proof-linked",
        "objects": objects,
    }
    if args.data_object:
        data_objects = []
        seen_data_objects: set[str] = set()
        for raw in args.data_object:
            rel = rel_object(output, Path(raw))
            if rel in seen_data_objects:
                continue
            seen_data_objects.add(rel)
            data_objects.append({"native_object": rel})
        manifest["data_objects"] = data_objects
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
