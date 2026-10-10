#!/usr/bin/env python3
"""Analyze raw Cilium profiling artifacts without changing runner results."""

from __future__ import annotations

import argparse
import collections
import csv
import gzip
import json
import math
import re
import subprocess
import tempfile
from pathlib import Path
from typing import Mapping, Sequence


ROOT = Path(__file__).resolve().parents[1]
PHASE_BY_ARM = {"jit": "baseline", "kprog": "post_rejit"}
NATIVE_JIT_RE = re.compile(
    r"native-loader jit-info (?P<label>original|native) .*? id=(?P<id>\d+) "
    r"type=(?P<type>\d+) name=(?P<name>\S*) tag=(?P<tag>[0-9a-f]+) "
    r"jited_len=(?P<jited>\d+) xlated_len=(?P<xlated>\d+)"
)
NATIVE_TIMING_RE = re.compile(
    r"native-loader timings prog=(?P<prog>\S*) .*? original_id=(?P<original_id>\d+) "
    r"native_id=(?P<native_id>\d+) symbol=(?P<symbol>\S+) .*? "
    r"bpf_bytes=(?P<bpf_bytes>\d+) native_bytes=(?P<native_bytes>\d+)"
)
PKTS_RE = re.compile(r"pkts-sofar:\s*(\d+)")
UNRESOLVED_SYMBOLS = frozenset({"[unknown]", "unknown", "[.]", "[k]"})
IDLE_SYMBOLS = frozenset(
    {
        "acpi_idle_do_entry",
        "arch_cpu_idle",
        "cpu_startup_entry",
        "default_idle_call",
        "do_idle",
        "mwait_idle",
        "native_safe_halt",
        "pv_native_safe_halt",
    }
)


def _json(path: Path) -> object:
    return json.loads(path.read_text(encoding="utf-8"))


def _little_endian_hex_octets(value: object) -> int:
    if not isinstance(value, list) or not value:
        raise ValueError(f"expected non-empty octet list, got {value!r}")
    octets = bytes(int(str(item), 16) for item in value)
    return int.from_bytes(octets, "little")


def parse_perf_stat(path: Path) -> dict[str, int]:
    counters: dict[str, int] = {}
    with path.open(newline="", encoding="utf-8") as source:
        for row in csv.reader(source):
            if len(row) < 3 or not row[0].strip() or row[0].lstrip().startswith("#"):
                continue
            raw_count, event = row[0].strip(), row[2].strip()
            if raw_count in {"<not counted>", "<not supported>"}:
                raise RuntimeError(f"host perf event {event} was {raw_count}")
            canonical = event.split("/", 1)[1].rsplit("/", 1)[0] if "/" in event else event
            counters[canonical] = int(raw_count.replace(" ", ""))
    missing = {
        "cpu-cycles",
        "instructions",
        "branch-instructions",
        "branch-misses",
        "cache-misses",
    } - set(counters)
    if missing:
        raise RuntimeError(f"host perf stat is missing counters: {sorted(missing)}")
    return counters


def _branch_symbol(raw: str) -> str:
    symbol = raw.strip()
    if "(" in symbol and symbol.endswith(")"):
        symbol = symbol.rsplit("(", 1)[1][:-1]
    return re.sub(r"\+(?:0x)?[0-9a-fA-F]+$", "", symbol)


def _branch_history(line: str) -> list[tuple[str, str, str]]:
    branches: list[tuple[str, str, str]] = []
    for token in line.split():
        fields = token.split("/")
        if len(fields) < 3:
            continue
        source, target = (_branch_symbol(fields[0]), _branch_symbol(fields[1]))
        branch_type = fields[-1].upper()
        if source and target and branch_type:
            branches.append((source, target, branch_type))
    return branches


def reconstruct_active_lbr(
    leaf: str, branches: Sequence[tuple[str, str, str]]
) -> list[str]:
    """Reconstruct active calls from newest-to-oldest LBR CALL/RET records."""
    active = [leaf]
    current = leaf
    completed_depth = 0
    for source, target, branch_type in branches:
        is_return = branch_type == "RET" or branch_type.endswith("_RET")
        is_call = branch_type == "CALL" or branch_type.endswith("_CALL")
        if is_return:
            completed_depth += 1
        elif is_call and completed_depth:
            completed_depth -= 1
        elif is_call and target == current:
            active.append(source)
            current = source
    return active


def parse_perf_script(
    text: str,
) -> tuple[collections.Counter[str], list[list[str]], list[list[str]]]:
    """Parse perf-script callchains and LBR branch histories by sample block."""
    counts: collections.Counter[str] = collections.Counter()
    callgraphs: list[list[str]] = []
    branch_histories: list[list[tuple[str, str, str]]] = []
    for block in re.split(r"\n\s*\n", text.strip()):
        symbols: list[str] = []
        branches: list[tuple[str, str, str]] = []
        for line in block.splitlines():
            stripped = line.strip()
            match = re.match(r"(?:0x)?[0-9a-fA-F]+\s+(\S+)", stripped)
            if match is not None:
                symbols.append(match.group(1))
                branches.extend(_branch_history(stripped[match.end() :]))
        if not symbols:
            continue
        counts[symbols[0]] += 1
        callgraphs.append(symbols)
        branch_histories.append(branches)
    active_lbr = [
        reconstruct_active_lbr(callgraph[0], branches)
        for callgraph, branches in zip(callgraphs, branch_histories, strict=True)
    ]
    return counts, callgraphs, active_lbr


def classify_symbol(symbol: str, native_symbols: frozenset[str] = frozenset()) -> str:
    lowered = symbol.lower()
    if (
        lowered.startswith("bpf_prog_")
        or lowered.startswith("__bpf_prog_")
        or symbol in native_symbols
    ):
        return "bpf_code"
    map_tokens = (
        "map_lookup",
        "map_update",
        "map_delete",
        "lookup_elem",
        "lookup_nulls_elem",
        "update_elem",
        "delete_elem",
        "htab_",
        "lru_",
        "percpu_array",
        "array_map",
        "bpf_map_",
        "bpf_common_lru",
    )
    if any(token in lowered for token in map_tokens):
        return "maps"
    if lowered.startswith("bpf_") or lowered.startswith("__bpf_"):
        return "helpers"
    return "rest"


def classify_context(
    symbols: Sequence[str], native_symbols: frozenset[str] = frozenset()
) -> str:
    """Attribute a sample to the first datapath class in leaf-to-root context."""
    for symbol in symbols:
        category = classify_symbol(symbol, native_symbols)
        if category != "rest":
            return category
    return "rest"


def validate_callgraph_samples(
    symbol_counts: Mapping[str, int],
    callgraphs: Sequence[Sequence[str]],
    branch_histories: Sequence[Sequence[str]],
    native_symbols: frozenset[str] = frozenset(),
) -> None:
    resolved_leaves = sum(
        count
        for symbol, count in symbol_counts.items()
        if symbol.lower() not in UNRESOLVED_SYMBOLS
    )
    if resolved_leaves == 0:
        raise RuntimeError("perf record contains no resolved leaf symbols")
    if not any(len(callgraph) >= 2 for callgraph in callgraphs):
        raise RuntimeError("perf record contains no callchain with at least two frames")
    if not any(len(history) >= 2 for history in branch_histories):
        raise RuntimeError("perf record contains no reconstructed active LBR ancestry")
    if not any(
        classify_symbol(symbol, native_symbols) == "bpf_code"
        for symbols in (*callgraphs, *branch_histories)
        for symbol in symbols
    ):
        raise RuntimeError("perf record contains no BPF-code context")
    if native_symbols and not any(
        len(history) >= 2 and any(symbol in native_symbols for symbol in history)
        for history in branch_histories
    ):
        raise RuntimeError(
            "perf record contains no active LBR path crossing a live native BPF frame"
        )


def _run_perf_reports(perf: Path, arm_dir: Path) -> tuple[str, str]:
    data = arm_dir / "guest.perf.data"
    kallsyms = arm_dir / "guest.kallsyms"
    vmlinux = ROOT / "vendor" / "build" / "x86" / "linux" / "vmlinux"
    for path in (data, kallsyms, vmlinux):
        if not path.is_file():
            raise RuntimeError(f"required profiling artifact is missing: {path}")
    # The profile is kernel-only.  Hiding guest user DSOs avoids host perf
    # trying to synthesize PLT symbols from unrelated guest paths; current
    # perf versions can crash there after otherwise decoding all samples.
    with tempfile.TemporaryDirectory(prefix="cilium-profile-symfs-") as symfs:
        common = [
            "--symfs",
            symfs,
            "-i",
            str(data),
            "--kallsyms",
            str(kallsyms),
            "--vmlinux",
            str(vmlinux),
        ]
        report = subprocess.run(
            [
                str(perf),
                "report",
                "--stdio",
                "--percent-limit",
                "0",
                "--sort",
                "symbol",
                "--branch-history",
                *common,
            ],
            check=True,
            capture_output=True,
            text=True,
        ).stdout
        script = subprocess.run(
            [str(perf), "script", "-F", "ip,sym,brstacksym", *common],
            check=True,
            capture_output=True,
            text=True,
        ).stdout
    (arm_dir / "perf-report.txt").write_text(report, encoding="utf-8")
    with gzip.open(arm_dir / "perf-script.txt.gz", "wt", encoding="utf-8") as output:
        output.write(script)
    return report, script


def _program_attach_points(evidence: Path, live_net: Path) -> dict[int, list[str]]:
    attachments: dict[int, set[str]] = collections.defaultdict(set)
    net = _json(live_net)
    if isinstance(net, list):
        for namespace in net:
            if not isinstance(namespace, Mapping):
                continue
            for record in namespace.get("xdp", []):
                if isinstance(record, Mapping):
                    attachments[int(record["id"])].add(
                        f"xdp:{record.get('devname', '?')}:{record.get('mode', '?')}"
                    )
            for record in namespace.get("tc", []):
                if isinstance(record, Mapping):
                    attachments[int(record["prog_id"])].add(
                        f"tc:{record.get('devname', '?')}:{record.get('kind', '?')}"
                    )
    manifest = _json(evidence / "manifest.json")
    map_names: dict[str, str] = {}
    if isinstance(manifest, Mapping):
        raw_maps = manifest.get("program_array_dumps", {})
        if isinstance(raw_maps, Mapping):
            for map_id, record in raw_maps.items():
                if isinstance(record, Mapping):
                    map_names[str(map_id)] = str(record.get("name") or "prog_array")
    for dump_path in evidence.glob("map-*.prog-array.json"):
        match = re.match(r"map-(\d+)-", dump_path.name)
        if match is None:
            continue
        map_id = match.group(1)
        payload = _json(dump_path)
        if not isinstance(payload, list):
            continue
        for record in payload:
            if not isinstance(record, Mapping):
                continue
            program_id = _little_endian_hex_octets(record.get("value"))
            index = _little_endian_hex_octets(record.get("key"))
            attachments[program_id].add(
                f"tail-call:{map_names.get(map_id, dump_path.stem)}[{index}]"
            )
    return {program_id: sorted(points) for program_id, points in attachments.items()}


def _native_sizes(shim_log: Path) -> list[dict[str, object]]:
    jit: dict[tuple[str, int], dict[str, object]] = {}
    timings: list[dict[str, object]] = []
    for line in shim_log.read_text(encoding="utf-8", errors="replace").splitlines():
        jit_match = NATIVE_JIT_RE.search(line)
        if jit_match is not None:
            record = jit_match.groupdict()
            jit[(record["label"], int(record["id"]))] = {
                "name": record["name"],
                "tag": record["tag"],
                "bytes_jited": int(record["jited"]),
                "bytes_xlated": int(record["xlated"]),
            }
        timing_match = NATIVE_TIMING_RE.search(line)
        if timing_match is not None:
            record = timing_match.groupdict()
            original_id = int(record["original_id"])
            native_id = int(record["native_id"])
            original = jit.get(("original", original_id))
            native = jit.get(("native", native_id))
            if original is None or native is None:
                raise RuntimeError(
                    f"native size record lacks paired jit-info: {original_id}->{native_id}"
                )
            timings.append(
                {
                    "original_id": original_id,
                    "native_id": native_id,
                    "program": record["prog"],
                    "native_symbol": record["symbol"],
                    "native_ksym": f"bpf_prog_{native['tag']}_{native['name']}",
                    "jit_image_bytes": original["bytes_jited"],
                    "native_blob_bytes": int(record["native_bytes"]),
                    "native_stub_image_bytes": native["bytes_jited"],
                    "bpf_bytecode_bytes": int(record["bpf_bytes"]),
                }
            )
    if not timings:
        raise RuntimeError(f"native loader log contains no paired image sizes: {shim_log}")
    return timings


def _live_native_sizes(
    programs: Sequence[Mapping[str, object]], sizes: Sequence[Mapping[str, object]]
) -> list[dict[str, object]]:
    program_ids = {int(row["id"]) for row in programs}
    by_native_id: dict[int, dict[str, object]] = {}
    for raw in sizes:
        native_id = int(raw["native_id"])
        if native_id not in program_ids:
            continue
        if native_id in by_native_id:
            raise RuntimeError(f"duplicate native image size for live program ID {native_id}")
        by_native_id[native_id] = dict(raw)
    missing = sorted(program_ids - set(by_native_id))
    if missing:
        raise RuntimeError(
            f"native image sizes are missing for post-replacement program IDs: {missing}"
        )
    return [by_native_id[program_id] for program_id in sorted(program_ids)]


def _packet_metrics(workloads: object) -> dict[str, object]:
    if not isinstance(workloads, list) or len(workloads) != 1:
        raise RuntimeError("profile requires exactly one Cilium workload sample")
    workload = workloads[0]
    if not isinstance(workload, Mapping):
        raise RuntimeError("Cilium workload record is malformed")
    components = workload.get("components")
    if not isinstance(components, list) or not components:
        raise RuntimeError("Cilium workload has no packet-generator components")
    sent = 0
    errors = 0
    for component in components:
        if not isinstance(component, Mapping):
            continue
        matches = PKTS_RE.findall(str(component.get("stdout") or ""))
        if len(matches) != 1:
            raise RuntimeError("packet-generator output lacks one pkts-sofar counter")
        sent += int(matches[0])
        if int(component.get("returncode", -1)) != 0:
            errors += 1
    outcomes = workload.get("config", {})
    delta = outcomes.get("outcomes", {}).get("delta", {}) if isinstance(outcomes, Mapping) else {}
    receivers = delta.get("receivers", {}) if isinstance(delta, Mapping) else {}
    verdicts = delta.get("verdicts", {}) if isinstance(delta, Mapping) else {}
    received = 0
    rx_errors = 0
    rx_dropped = 0
    if isinstance(receivers, Mapping):
        for record in receivers.values():
            if not isinstance(record, Mapping):
                continue
            received += int(record.get("rx_packets", 0) or 0)
            rx_errors += int(record.get("rx_errors", 0) or 0)
            rx_dropped += int(record.get("rx_dropped", 0) or 0)
    outcome_verdicts: dict[str, dict[str, int]] = {}
    if isinstance(verdicts, Mapping):
        for name, record in verdicts.items():
            if not isinstance(record, Mapping):
                continue
            outcome_verdicts[str(name)] = {
                "count": int(record.get("count", 0) or 0),
                "bytes": int(record.get("bytes", 0) or 0),
            }
    return {
        "packets_sent": sent,
        "packets_received": received,
        "component_errors": errors,
        "rx_errors": rx_errors,
        "rx_dropped": rx_dropped,
        "verdicts": outcome_verdicts,
    }


def _verdict_count(packet_metrics: Mapping[str, object], name: str) -> int:
    verdicts = packet_metrics.get("verdicts", {})
    if not isinstance(verdicts, Mapping):
        return 0
    record = verdicts.get(name, {})
    return int(record.get("count", 0) or 0) if isinstance(record, Mapping) else 0


def _other_verdict_count(packet_metrics: Mapping[str, object]) -> int:
    verdicts = packet_metrics.get("verdicts", {})
    if not isinstance(verdicts, Mapping):
        return 0
    return sum(
        int(record.get("count", 0) or 0)
        for name, record in verdicts.items()
        if name not in {"reason=0,direction=1", "reason=0,direction=2"}
        and isinstance(record, Mapping)
    )


def _program_rows(
    phase: Mapping[str, object], evidence: Path, live_net: Path
) -> list[dict[str, object]]:
    attach_points = _program_attach_points(evidence, live_net)
    programs = phase.get("bpf")
    if not isinstance(programs, Mapping):
        raise RuntimeError("Cilium phase has no BPF counter mapping")
    rows: list[dict[str, object]] = []
    for raw in programs.values():
        if not isinstance(raw, Mapping):
            continue
        program_id = int(raw["id"])
        count = int(raw.get("run_cnt_delta", 0) or 0)
        runtime = int(raw.get("run_time_ns_delta", 0) or 0)
        rows.append(
            {
                "id": program_id,
                "name": str(raw.get("name") or ""),
                "type": str(raw.get("type") or ""),
                "attach_points": attach_points.get(program_id, []),
                "run_count": count,
                "run_time_ns": runtime,
                "ns_per_run": runtime / count if count else None,
                "bytes_jited": int(raw.get("bytes_jited", 0) or 0),
                "bytes_xlated": int(raw.get("bytes_xlated", 0) or 0),
            }
        )
    return sorted(rows, key=lambda item: (-int(item["run_count"]), int(item["id"])))


def analyze_run(
    profile_root: Path,
    run: Mapping[str, object],
    perf: Path,
) -> dict[str, object]:
    arm = str(run["arm"])
    run_id = str(run["run_id"])
    arm_dir = profile_root / str(run["profile_dir"])
    corpus_run = ROOT / str(run["corpus_run"])
    phase_name = PHASE_BY_ARM[arm]
    app_path = corpus_run / "details" / "apps" / "cilium__agent.json"
    app = _json(app_path)
    if not isinstance(app, Mapping) or app.get("status") != "ok":
        raise RuntimeError(f"Cilium corpus result is not ok: {app_path}")
    phase = app.get(phase_name)
    if not isinstance(phase, Mapping):
        raise RuntimeError(f"Cilium result lacks phase {phase_name}: {app_path}")
    evidence = (
        corpus_run
        / "details"
        / "bpf-evidence"
        / "cilium_agent"
        / phase_name
    )
    rows = _program_rows(phase, evidence, arm_dir / "guest-bpf-net.json")
    live_native_sizes: list[dict[str, object]] = []
    native_symbols: frozenset[str] = frozenset()
    if arm == "kprog":
        all_native_sizes = _native_sizes(
            corpus_run / "details" / "shim-logs" / "cilium__agent.post_rejit.log"
        )
        live_native_sizes = _live_native_sizes(rows, all_native_sizes)
        native_symbols = frozenset(
            str(record["native_ksym"]) for record in live_native_sizes
        )
    _, script = _run_perf_reports(perf, arm_dir)
    symbol_counts, callgraphs, branch_histories = parse_perf_script(script)
    if not symbol_counts:
        raise RuntimeError(f"perf record for {arm} contained no symbolized samples")
    validate_callgraph_samples(
        symbol_counts, callgraphs, branch_histories, native_symbols
    )
    idle_samples = sum(
        count for symbol, count in symbol_counts.items() if symbol.lower() in IDLE_SYMBOLS
    )
    unresolved_samples = sum(
        count
        for symbol, count in symbol_counts.items()
        if symbol.lower() in UNRESOLVED_SYMBOLS
    )
    categorized_leaves: collections.Counter[tuple[str, str]] = collections.Counter()
    category_counts: collections.Counter[str] = collections.Counter()
    active_lbr_samples = 0
    for callgraph, history in zip(callgraphs, branch_histories, strict=True):
        leaf = callgraph[0]
        if leaf.lower() in IDLE_SYMBOLS or leaf.lower() in UNRESOLVED_SYMBOLS:
            continue
        if len(history) >= 2:
            active_lbr_samples += 1
        category = classify_context([*callgraph, *history], native_symbols)
        category_counts[category] += 1
        categorized_leaves[(leaf, category)] += 1
    analyzed_samples = sum(category_counts.values())
    if analyzed_samples == 0:
        raise RuntimeError(f"perf record for {arm} has no non-idle resolved samples")
    packet_metrics = _packet_metrics(phase.get("workloads"))
    packets = int(packet_metrics["packets_sent"])
    if packets <= 0:
        raise RuntimeError(f"Cilium {arm} workload sent no packets")
    counters = parse_perf_stat(arm_dir / "host-perf-stat.csv")
    bpf_run_count = sum(int(row["run_count"]) for row in rows)
    bpf_run_time = sum(int(row["run_time_ns"]) for row in rows)
    guest_profile = _json(arm_dir / "guest-profile.json")
    if not isinstance(guest_profile, Mapping):
        raise RuntimeError(f"guest profile metadata is malformed: {arm_dir}")
    sample_period_cycles = int(guest_profile.get("sample_period_cycles", 0) or 0)
    if sample_period_cycles <= 0:
        raise RuntimeError(f"guest profile has no positive cycle period: {arm_dir}")
    categories = {
        category: {
            "samples": int(category_counts.get(category, 0)),
            "sample_fraction": category_counts.get(category, 0) / analyzed_samples,
            "estimated_guest_cycles_per_packet": category_counts.get(category, 0)
            * sample_period_cycles
            / packets,
        }
        for category in ("bpf_code", "helpers", "maps", "rest")
    }
    result: dict[str, object] = {
        "arm": arm,
        "run_id": run_id,
        "order": str(run["order"]),
        "position": int(run["position"]),
        "phase": phase_name,
        "corpus_run": str(corpus_run.relative_to(ROOT)),
        "packets": packet_metrics,
        "host_perf": {
            **counters,
            "ipc": counters["instructions"] / counters["cpu-cycles"],
            "branch_miss_rate": counters["branch-misses"]
            / counters["branch-instructions"],
            "cycles_per_packet": counters["cpu-cycles"] / packets,
            "instructions_per_packet": counters["instructions"] / packets,
            "branches_per_packet": counters["branch-instructions"] / packets,
            "branch_misses_per_packet": counters["branch-misses"] / packets,
            "cache_misses_per_packet": counters["cache-misses"] / packets,
        },
        "callgraph": {
            "samples": sum(symbol_counts.values()),
            "analyzed_samples": analyzed_samples,
            "excluded_idle_samples": idle_samples,
            "unresolved_samples": unresolved_samples,
            "callgraphs": len(callgraphs),
            "active_lbr_samples": active_lbr_samples,
            "active_lbr_coverage": active_lbr_samples / analyzed_samples,
            "sample_period_cycles": sample_period_cycles,
            "categories": categories,
            "top_symbols": [
                {"symbol": symbol, "samples": count, "category": category}
                for (symbol, category), count in categorized_leaves.most_common(40)
            ],
        },
        "bpf": {
            "active_programs": sum(int(row["run_count"]) > 0 for row in rows),
            "total_programs": len(rows),
            "total_run_count": bpf_run_count,
            "total_run_time_ns": bpf_run_time,
            "runs_per_packet": bpf_run_count / packets,
            "programs": rows,
        },
    }
    if arm == "kprog":
        result["live_native_image_sizes"] = live_native_sizes
    (arm_dir / "report.json").write_text(
        json.dumps(result, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    (arm_dir / "report.md").write_text(_arm_markdown(result), encoding="utf-8")
    return result


def _arm_markdown(result: Mapping[str, object]) -> str:
    host = result["host_perf"]
    bpf = result["bpf"]
    callgraph = result["callgraph"]
    assert isinstance(host, Mapping) and isinstance(bpf, Mapping) and isinstance(callgraph, Mapping)
    lines = [
        f"# Cilium {result['arm']} profile: {result['run_id']}",
        "",
        f"Order: `{result['order']}`, position: {result['position']}; corpus run: "
        f"`{result['corpus_run']}`; selected phase: `{result['phase']}`.",
        "",
        "| Metric | Value |",
        "| --- | ---: |",
        f"| cycles/packet | {float(host['cycles_per_packet']):.3f} |",
        f"| instructions/packet | {float(host['instructions_per_packet']):.3f} |",
        f"| IPC | {float(host['ipc']):.3f} |",
        f"| branches/packet | {float(host['branches_per_packet']):.3f} |",
        f"| branch misses/packet | {float(host['branch_misses_per_packet']):.6f} |",
        f"| branch miss rate | {float(host['branch_miss_rate']):.6%} |",
        f"| cache misses/packet | {float(host['cache_misses_per_packet']):.6f} |",
        f"| BPF runs/packet | {float(bpf['runs_per_packet']):.3f} |",
        f"| active BPF programs | {bpf['active_programs']} / {bpf['total_programs']} |",
        f"| analyzed call-graph samples | {callgraph['analyzed_samples']} / {callgraph['samples']} raw |",
        f"| excluded idle samples | {callgraph['excluded_idle_samples']} |",
        f"| unresolved samples | {callgraph['unresolved_samples']} |",
        f"| active-LBR coverage | {callgraph['active_lbr_samples']} / "
        f"{callgraph['analyzed_samples']} ({float(callgraph['active_lbr_coverage']):.3%}) |",
        "",
        "## Resolved non-idle context-attributed cost per packet",
        "",
        "Each resolved, non-idle sample is assigned to the first datapath class in its "
        "frame-pointer plus LBR context. This places spin-lock frames reached through "
        "`htab_lru_map_update_elem` or `bpf_common_lru_pop_free` under maps. Values are "
        "fixed-period sampled guest cycles, not wall-clock nanoseconds.",
        "",
        "| Category | Samples | Fraction | Estimated guest cycles/packet |",
        "| --- | ---: | ---: | ---: |",
    ]
    categories = callgraph["categories"]
    assert isinstance(categories, Mapping)
    for name in ("bpf_code", "helpers", "maps", "rest"):
        record = categories[name]
        assert isinstance(record, Mapping)
        lines.append(
            f"| {name} | {record['samples']} | {float(record['sample_fraction']):.3%} | "
            f"{float(record['estimated_guest_cycles_per_packet']):.3f} |"
        )
    lines += [
        "",
        "## Top symbols",
        "",
        "| Symbol | Category | Samples |",
        "| --- | --- | ---: |",
    ]
    top_symbols = callgraph["top_symbols"]
    assert isinstance(top_symbols, list)
    for record in top_symbols[:20]:
        assert isinstance(record, Mapping)
        lines.append(f"| `{record['symbol']}` | {record['category']} | {record['samples']} |")
    lines += [
        "",
        "## Per-program BPF counters",
        "",
        "| ID | Program | Attach point(s) | Runs | ns/run | JIT bytes |",
        "| ---: | --- | --- | ---: | ---: | ---: |",
    ]
    programs = bpf["programs"]
    assert isinstance(programs, list)
    for row in programs:
        assert isinstance(row, Mapping)
        if int(row["run_count"]) == 0:
            continue
        attach = ", ".join(str(item) for item in row["attach_points"]) or "tail/unresolved"
        lines.append(
            f"| {row['id']} | `{row['name']}` | {attach} | {row['run_count']} | "
            f"{float(row['ns_per_run']):.3f} | {row['bytes_jited']} |"
        )
    if "live_native_image_sizes" in result:
        lines += [
            "",
            "## Live-program JIT versus whole-program native image size",
            "",
            "Only native IDs in the measured post-replacement BPF counter set are included; "
            "earlier lifecycle replacements are excluded.",
            "",
            "| Original ID | Native ID | Symbol | JIT bytes | Native blob bytes | Native stub image bytes |",
            "| ---: | ---: | --- | ---: | ---: | ---: |",
        ]
        native_sizes = result["live_native_image_sizes"]
        assert isinstance(native_sizes, list)
        lines.append(
            f"| **total ({len(native_sizes)} live)** |  |  | "
            f"**{sum(int(row['jit_image_bytes']) for row in native_sizes)}** | "
            f"**{sum(int(row['native_blob_bytes']) for row in native_sizes)}** | "
            f"**{sum(int(row['native_stub_image_bytes']) for row in native_sizes)}** |"
        )
        for row in native_sizes:
            assert isinstance(row, Mapping)
            lines.append(
                f"| {row['original_id']} | {row['native_id']} | `{row['native_symbol']}` | "
                f"{row['jit_image_bytes']} | {row['native_blob_bytes']} | "
                f"{row['native_stub_image_bytes']} |"
            )
    return "\n".join(lines) + "\n"


def _counterbalanced_pairs(
    results: Sequence[Mapping[str, object]],
) -> list[tuple[str, Mapping[str, object], Mapping[str, object]]]:
    grouped: dict[str, dict[str, Mapping[str, object]]] = collections.defaultdict(dict)
    for result in results:
        order = str(result["order"])
        arm = str(result["arm"])
        if arm in grouped[order]:
            raise RuntimeError(f"duplicate {arm} run in order {order}")
        grouped[order][arm] = result
    pairs: list[tuple[str, Mapping[str, object], Mapping[str, object]]] = []
    for order in ("jit-kprog", "kprog-jit"):
        arms = grouped.get(order)
        if arms is None:
            continue
        if set(arms) != {"jit", "kprog"}:
            raise RuntimeError(f"order {order} does not contain both profile arms")
        pairs.append((order, arms["jit"], arms["kprog"]))
    return pairs


def _combined_markdown(results: Sequence[Mapping[str, object]]) -> str:
    lines = [
        "# Cilium JIT versus whole-program native profile",
        "",
        "These profiles are separate from timing runs, use the timing topology (host "
        "P-cores 0--7, 8 vCPUs, 64 GiB), and counterbalance fresh-boot order.",
        "",
        "| Order | Position | Arm | Packets | BPF runs/packet | aggregate BPF ns/run | cycles/packet | instructions/packet | IPC | branches/packet | branch misses/packet | branch miss rate | cache misses/packet |",
        "| --- | ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]
    for result in results:
        packets = result["packets"]
        host = result["host_perf"]
        bpf = result["bpf"]
        assert isinstance(packets, Mapping) and isinstance(host, Mapping) and isinstance(bpf, Mapping)
        lines.append(
            f"| {result['order']} | {result['position']} | {result['arm']} | "
            f"{packets['packets_sent']} | {float(bpf['runs_per_packet']):.3f} | "
            f"{int(bpf['total_run_time_ns']) / int(bpf['total_run_count']):.3f} | "
            f"{float(host['cycles_per_packet']):.3f} | {float(host['instructions_per_packet']):.3f} | "
            f"{float(host['ipc']):.3f} | {float(host['branches_per_packet']):.3f} | "
            f"{float(host['branch_misses_per_packet']):.6f} | "
            f"{float(host['branch_miss_rate']):.6%} | "
            f"{float(host['cache_misses_per_packet']):.6f} |"
        )
    pairs = _counterbalanced_pairs(results)
    if pairs:
        lines += [
            "",
            "## Within-order native/JIT ratios",
            "",
            "Ratios compare the two fresh boots within each order; values below 1.0 favor native.",
            "",
            "| Order | cycles/packet | instructions/packet | branches/packet | branch misses/packet | cache misses/packet | aggregate BPF ns/run |",
            "| --- | ---: | ---: | ---: | ---: | ---: | ---: |",
        ]
        ratio_rows: list[list[float]] = []
        for order, jit, kprog in pairs:
            jit_host, native_host = jit["host_perf"], kprog["host_perf"]
            jit_bpf, native_bpf = jit["bpf"], kprog["bpf"]
            assert isinstance(jit_host, Mapping) and isinstance(native_host, Mapping)
            assert isinstance(jit_bpf, Mapping) and isinstance(native_bpf, Mapping)
            values = [
                float(native_host[key]) / float(jit_host[key])
                for key in (
                    "cycles_per_packet",
                    "instructions_per_packet",
                    "branches_per_packet",
                    "branch_misses_per_packet",
                    "cache_misses_per_packet",
                )
            ]
            values.append(
                (int(native_bpf["total_run_time_ns"]) / int(native_bpf["total_run_count"]))
                / (int(jit_bpf["total_run_time_ns"]) / int(jit_bpf["total_run_count"]))
            )
            ratio_rows.append(values)
            lines.append(f"| {order} | " + " | ".join(f"{value:.4f}" for value in values) + " |")
        if len(ratio_rows) == 2:
            geomeans = [math.sqrt(first * second) for first, second in zip(*ratio_rows, strict=True)]
            lines.append(
                "| counterbalanced geometric mean | "
                + " | ".join(f"{value:.4f}" for value in geomeans)
                + " |"
            )
    lines += [
        "",
        "## Outcome counters",
        "",
        "| Order | Arm | Sent | Received | Component errors | RX errors | RX drops | Allow dir. 1 | Allow dir. 2 | Other verdicts |",
        "| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]
    for result in results:
        packets = result["packets"]
        assert isinstance(packets, Mapping)
        lines.append(
            f"| {result['order']} | {result['arm']} | {packets['packets_sent']} | {packets['packets_received']} | "
            f"{packets['component_errors']} | {packets['rx_errors']} | {packets['rx_dropped']} | "
            f"{_verdict_count(packets, 'reason=0,direction=1')} | "
            f"{_verdict_count(packets, 'reason=0,direction=2')} | "
            f"{_other_verdict_count(packets)} |"
        )
    lines += [
        "",
        "## Resolved non-idle context-attributed split",
        "",
        "Frame-pointer and LBR context assigns LRU map spin-lock samples to maps. "
        "The units are estimated guest sampled cycles per packet.",
        "",
        "| Order | Arm | BPF code cycles/packet | Helpers cycles/packet | Maps cycles/packet | Rest cycles/packet |",
        "| --- | --- | ---: | ---: | ---: | ---: |",
    ]
    for result in results:
        callgraph = result["callgraph"]
        assert isinstance(callgraph, Mapping)
        categories = callgraph["categories"]
        assert isinstance(categories, Mapping)
        values = []
        for category in ("bpf_code", "helpers", "maps", "rest"):
            record = categories[category]
            assert isinstance(record, Mapping)
            values.append(float(record["estimated_guest_cycles_per_packet"]))
        lines.append(
            f"| {result['order']} | {result['arm']} | {values[0]:.3f} | {values[1]:.3f} | {values[2]:.3f} | {values[3]:.3f} |"
        )
    lines += [
        "",
        "| Order | Arm | Unresolved leaf samples | Estimated unresolved sampled cycles/packet | Unresolved share of non-idle samples |",
        "| --- | --- | ---: | ---: | ---: |",
    ]
    for result in results:
        packets = result["packets"]
        callgraph = result["callgraph"]
        assert isinstance(packets, Mapping) and isinstance(callgraph, Mapping)
        unresolved = int(callgraph["unresolved_samples"])
        non_idle = unresolved + int(callgraph["analyzed_samples"])
        lines.append(
            f"| {result['order']} | {result['arm']} | {unresolved} | "
            f"{unresolved * int(callgraph['sample_period_cycles']) / int(packets['packets_sent']):.3f} | "
            f"{unresolved / non_idle:.3%} |"
        )
    lines += [
        "",
        "Raw counters, perf data, symbol snapshots, full call graphs, and per-program tables are in each arm directory.",
    ]
    return "\n".join(lines) + "\n"


def main(argv: Sequence[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--profile-root", type=Path, required=True)
    parser.add_argument("--perf", type=Path, required=True)
    args = parser.parse_args(argv)
    profile_root = args.profile_root.resolve()
    run_plan = _json(profile_root / "profile-runs.json")
    if not isinstance(run_plan, list) or not run_plan:
        raise RuntimeError("profile-runs.json must be a non-empty list")
    results: list[Mapping[str, object]] = []
    for raw_run in run_plan:
        if not isinstance(raw_run, Mapping):
            raise RuntimeError("profile-runs.json contains a malformed run")
        arm_name = str(raw_run.get("arm"))
        if arm_name not in PHASE_BY_ARM:
            raise RuntimeError(f"unknown profile arm in profile-runs.json: {arm_name}")
        required = {"run_id", "order", "position", "profile_dir", "corpus_run"}
        missing = sorted(required - set(raw_run))
        if missing:
            raise RuntimeError(f"profile run is missing fields: {missing}")
        results.append(analyze_run(profile_root, raw_run, args.perf.resolve()))
    (profile_root / "summary.json").write_text(
        json.dumps(results, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    (profile_root / "SUMMARY.md").write_text(
        _combined_markdown(results), encoding="utf-8"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
