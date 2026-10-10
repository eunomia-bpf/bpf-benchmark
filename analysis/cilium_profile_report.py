#!/usr/bin/env python3
"""Analyze raw Cilium profiling artifacts without changing runner results."""

from __future__ import annotations

import argparse
import collections
import csv
import json
import re
import subprocess
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


def parse_perf_script(text: str) -> tuple[collections.Counter[str], list[list[str]]]:
    """Parse perf-script blocks; the first line is the sampled leaf IP."""
    counts: collections.Counter[str] = collections.Counter()
    callgraphs: list[list[str]] = []
    for block in re.split(r"\n\s*\n", text.strip()):
        symbols: list[str] = []
        for line in block.splitlines():
            stripped = line.strip()
            match = re.match(r"(?:0x)?[0-9a-fA-F]+\s+(\S+)", stripped)
            if match is not None:
                symbols.append(match.group(1))
        if not symbols:
            continue
        counts[symbols[0]] += 1
        callgraphs.append(symbols)
    return counts, callgraphs


def classify_symbol(symbol: str) -> str:
    lowered = symbol.lower()
    if lowered.startswith("bpf_prog_") or lowered.startswith("__bpf_prog_"):
        return "bpf_code"
    map_tokens = (
        "map_lookup",
        "map_update",
        "map_delete",
        "lookup_elem",
        "update_elem",
        "delete_elem",
        "htab_",
        "lru_",
        "percpu_array",
        "array_map",
        "bpf_map_",
    )
    if any(token in lowered for token in map_tokens):
        return "maps"
    if lowered.startswith("bpf_") or lowered.startswith("__bpf_"):
        return "helpers"
    return "rest"


def validate_callgraph_samples(
    symbol_counts: Mapping[str, int], callgraphs: Sequence[Sequence[str]]
) -> None:
    unresolved = {"[unknown]", "unknown", "[.]", "[k]"}
    resolved_leaves = sum(
        count for symbol, count in symbol_counts.items() if symbol.lower() not in unresolved
    )
    if resolved_leaves == 0:
        raise RuntimeError("perf record contains no resolved leaf symbols")
    if not any(len(callgraph) >= 2 for callgraph in callgraphs):
        raise RuntimeError("perf record contains no callchain with at least two frames")
    if not any(
        classify_symbol(symbol) == "bpf_code" and count > 0
        for symbol, count in symbol_counts.items()
    ):
        raise RuntimeError("perf record contains no BPF-code leaf samples")


def _run_perf_reports(perf: Path, arm_dir: Path) -> tuple[str, str]:
    data = arm_dir / "guest.perf.data"
    kallsyms = arm_dir / "guest.kallsyms"
    vmlinux = ROOT / "vendor" / "build" / "x86" / "linux" / "vmlinux"
    for path in (data, kallsyms, vmlinux):
        if not path.is_file():
            raise RuntimeError(f"required profiling artifact is missing: {path}")
    common = [
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
            *common,
        ],
        check=True,
        capture_output=True,
        text=True,
    ).stdout
    script = subprocess.run(
        [str(perf), "script", "-F", "ip,sym", *common],
        check=True,
        capture_output=True,
        text=True,
    ).stdout
    (arm_dir / "perf-report.txt").write_text(report, encoding="utf-8")
    (arm_dir / "perf-script.txt").write_text(script, encoding="utf-8")
    return report, script


def _program_attach_points(evidence: Path) -> dict[int, list[str]]:
    attachments: dict[int, set[str]] = collections.defaultdict(set)
    net = _json(evidence / "bpftool-net.json")
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
                    "jit_image_bytes": original["bytes_jited"],
                    "native_blob_bytes": int(record["native_bytes"]),
                    "native_stub_image_bytes": native["bytes_jited"],
                    "bpf_bytecode_bytes": int(record["bpf_bytes"]),
                }
            )
    if not timings:
        raise RuntimeError(f"native loader log contains no paired image sizes: {shim_log}")
    return timings


def _require_native_size_coverage(
    programs: Sequence[Mapping[str, object]], sizes: Sequence[Mapping[str, object]]
) -> None:
    program_ids = {int(row["id"]) for row in programs}
    native_ids = {int(row["native_id"]) for row in sizes}
    missing = sorted(program_ids - native_ids)
    if missing:
        raise RuntimeError(
            f"native image sizes are missing for post-replacement program IDs: {missing}"
        )


def _packet_metrics(workloads: object) -> dict[str, int]:
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
    return {
        "packets_sent": sent,
        "packets_received": received,
        "component_errors": errors,
        "rx_errors": rx_errors,
        "rx_dropped": rx_dropped,
    }


def _program_rows(phase: Mapping[str, object], evidence: Path) -> list[dict[str, object]]:
    attach_points = _program_attach_points(evidence)
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


def analyze_arm(profile_root: Path, arm: str, perf: Path, corpus_run: Path) -> dict[str, object]:
    arm_dir = profile_root / arm
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
    _, script = _run_perf_reports(perf, arm_dir)
    symbol_counts, callgraphs = parse_perf_script(script)
    if not symbol_counts:
        raise RuntimeError(f"perf record for {arm} contained no symbolized samples")
    validate_callgraph_samples(symbol_counts, callgraphs)
    category_counts: collections.Counter[str] = collections.Counter()
    for symbol, count in symbol_counts.items():
        category_counts[classify_symbol(symbol)] += count
    packet_metrics = _packet_metrics(phase.get("workloads"))
    packets = packet_metrics["packets_sent"]
    if packets <= 0:
        raise RuntimeError(f"Cilium {arm} workload sent no packets")
    counters = parse_perf_stat(arm_dir / "host-perf-stat.csv")
    rows = _program_rows(phase, evidence)
    bpf_run_count = sum(int(row["run_count"]) for row in rows)
    bpf_run_time = sum(int(row["run_time_ns"]) for row in rows)
    sample_period_ns = 1_000_000
    categories = {
        category: {
            "samples": int(category_counts.get(category, 0)),
            "sample_fraction": category_counts.get(category, 0) / sum(symbol_counts.values()),
            "estimated_cpu_ns_per_packet": category_counts.get(category, 0)
            * sample_period_ns
            / packets,
        }
        for category in ("bpf_code", "helpers", "maps", "rest")
    }
    result: dict[str, object] = {
        "arm": arm,
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
            "callgraphs": len(callgraphs),
            "categories": categories,
            "top_symbols": [
                {"symbol": symbol, "samples": count, "category": classify_symbol(symbol)}
                for symbol, count in symbol_counts.most_common(40)
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
        native_sizes = _native_sizes(
            corpus_run / "details" / "shim-logs" / "cilium__agent.post_rejit.log"
        )
        _require_native_size_coverage(rows, native_sizes)
        result["native_image_sizes"] = native_sizes
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
        f"# Cilium {result['arm']} profile",
        "",
        f"Corpus run: `{result['corpus_run']}`; selected phase: `{result['phase']}`.",
        "",
        "| Metric | Value |",
        "| --- | ---: |",
        f"| cycles/packet | {float(host['cycles_per_packet']):.3f} |",
        f"| instructions/packet | {float(host['instructions_per_packet']):.3f} |",
        f"| IPC | {float(host['ipc']):.3f} |",
        f"| branch misses/packet | {float(host['branch_misses_per_packet']):.6f} |",
        f"| cache misses/packet | {float(host['cache_misses_per_packet']):.6f} |",
        f"| BPF runs/packet | {float(bpf['runs_per_packet']):.3f} |",
        f"| active BPF programs | {bpf['active_programs']} / {bpf['total_programs']} |",
        f"| call-graph samples | {callgraph['samples']} |",
        "",
        "## Sampled time per packet",
        "",
        "| Category | Samples | Fraction | Estimated CPU ns/packet |",
        "| --- | ---: | ---: | ---: |",
    ]
    categories = callgraph["categories"]
    assert isinstance(categories, Mapping)
    for name in ("bpf_code", "helpers", "maps", "rest"):
        record = categories[name]
        assert isinstance(record, Mapping)
        lines.append(
            f"| {name} | {record['samples']} | {float(record['sample_fraction']):.3%} | "
            f"{float(record['estimated_cpu_ns_per_packet']):.3f} |"
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
    if "native_image_sizes" in result:
        lines += [
            "",
            "## JIT versus whole-program native image size",
            "",
            "| Original ID | Native ID | Symbol | JIT bytes | Native blob bytes | Native stub image bytes |",
            "| ---: | ---: | --- | ---: | ---: | ---: |",
        ]
        native_sizes = result["native_image_sizes"]
        assert isinstance(native_sizes, list)
        for row in native_sizes:
            assert isinstance(row, Mapping)
            lines.append(
                f"| {row['original_id']} | {row['native_id']} | `{row['native_symbol']}` | "
                f"{row['jit_image_bytes']} | {row['native_blob_bytes']} | "
                f"{row['native_stub_image_bytes']} |"
            )
    return "\n".join(lines) + "\n"


def _combined_markdown(results: Mapping[str, Mapping[str, object]]) -> str:
    lines = [
        "# Cilium JIT versus whole-program native profile",
        "",
        "These profiling runs are separate from timing runs and reuse the unchanged Cilium corpus setup.",
        "",
        "| Arm | Packets | BPF runs/packet | cycles/packet | instructions/packet | IPC | branch misses/packet | cache misses/packet |",
        "| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]
    for arm in ("jit", "kprog"):
        if arm not in results:
            continue
        result = results[arm]
        packets = result["packets"]
        host = result["host_perf"]
        bpf = result["bpf"]
        assert isinstance(packets, Mapping) and isinstance(host, Mapping) and isinstance(bpf, Mapping)
        lines.append(
            f"| {arm} | {packets['packets_sent']} | {float(bpf['runs_per_packet']):.3f} | "
            f"{float(host['cycles_per_packet']):.3f} | {float(host['instructions_per_packet']):.3f} | "
            f"{float(host['ipc']):.3f} | {float(host['branch_misses_per_packet']):.6f} | "
            f"{float(host['cache_misses_per_packet']):.6f} |"
        )
    lines += [
        "",
        "| Arm | BPF code ns/packet | Helpers ns/packet | Maps ns/packet | Rest ns/packet |",
        "| --- | ---: | ---: | ---: | ---: |",
    ]
    for arm in ("jit", "kprog"):
        if arm not in results:
            continue
        categories = results[arm]["callgraph"]["categories"]  # type: ignore[index]
        assert isinstance(categories, Mapping)
        values = []
        for category in ("bpf_code", "helpers", "maps", "rest"):
            record = categories[category]
            assert isinstance(record, Mapping)
            values.append(float(record["estimated_cpu_ns_per_packet"]))
        lines.append(
            f"| {arm} | {values[0]:.3f} | {values[1]:.3f} | {values[2]:.3f} | {values[3]:.3f} |"
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
    run_map = _json(profile_root / "corpus-runs.json")
    if not isinstance(run_map, Mapping):
        raise RuntimeError("corpus-runs.json must be a mapping")
    results: dict[str, Mapping[str, object]] = {}
    for arm, raw_path in run_map.items():
        arm_name = str(arm)
        if arm_name not in PHASE_BY_ARM:
            raise RuntimeError(f"unknown profile arm in corpus-runs.json: {arm_name}")
        corpus_run = ROOT / str(raw_path)
        results[arm_name] = analyze_arm(
            profile_root, arm_name, args.perf.resolve(), corpus_run
        )
    (profile_root / "summary.json").write_text(
        json.dumps(results, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    (profile_root / "SUMMARY.md").write_text(
        _combined_markdown(results), encoding="utf-8"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
