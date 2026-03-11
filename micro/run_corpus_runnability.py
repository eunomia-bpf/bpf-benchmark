#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import re
import statistics
import subprocess
import sys
import tempfile
import time
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

from directive_census import filter_bpf_paths
from run_corpus_perf import (
    DEFAULT_CONTEXT_PATH,
    DEFAULT_PACKET_PATH,
    DEFAULT_TIMEOUT_SECONDS,
    ROOT_DIR,
    compute_correctness,
    compute_speedup_ratio,
    directive_scan_from_record,
    ensure_parent,
    format_ns,
    format_ratio,
    geomean,
    invocation_summary,
    list_programs,
    markdown_table,
    materialize_dummy_context,
    materialize_dummy_packet,
    relpath,
    run_command,
    runner_binary_from_config,
    summarize_failure_reason,
    summarize_stderr,
)
from run_corpus_tracing import Libbpf, TRIGGERS, measure_attached_program


DEFAULT_OUTPUT_JSON = ROOT_DIR / "docs" / "tmp" / "corpus-runnability-results.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-runnability-report.md"
DEFAULT_PACKET_REPEAT = 200
DEFAULT_TRACING_REPEAT = 10
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"

PACKET_PROG_TYPES = {
    "xdp",
    "sched_cls",
    "sched_act",
    "cgroup_skb",
    "socket_filter",
    "flow_dissector",
    "sk_skb",
    "sk_msg",
}

TRACING_SECTION_ROOTS = {
    "fentry",
    "fexit",
    "fmod_ret",
    "kprobe",
    "kretprobe",
    "ksyscall",
    "kretsyscall",
    "raw_tp",
    "raw_tracepoint",
    "tp",
    "tp_btf",
    "tracepoint",
}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Inventory runnable corpus BPF programs, scan directive sites, and "
            "collect packet/tracing benchmark data where feasible."
        )
    )
    parser.add_argument(
        "--output-json",
        default=str(DEFAULT_OUTPUT_JSON),
        help="Path for structured JSON results.",
    )
    parser.add_argument(
        "--output-md",
        default=str(DEFAULT_OUTPUT_MD),
        help="Path for markdown summary output.",
    )
    parser.add_argument(
        "--runner",
        help="Path to the micro_exec runner binary. Defaults to the suite config runner path.",
    )
    parser.add_argument(
        "--scanner",
        default=str(DEFAULT_SCANNER),
        help="Path to bpf-jit-scanner for offline xlated fallback scans.",
    )
    parser.add_argument(
        "--corpus-root",
        default=str(ROOT_DIR / "corpus" / "build"),
        help="Root directory scanned for corpus .bpf.o files.",
    )
    parser.add_argument(
        "--packet-repeat",
        type=int,
        default=DEFAULT_PACKET_REPEAT,
        help="Repeat count passed to packet-backed bpf_prog_test_run measurements.",
    )
    parser.add_argument(
        "--tracing-repeat",
        type=int,
        default=DEFAULT_TRACING_REPEAT,
        help="How many times to trigger each tracing workload.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-invocation timeout in seconds.",
    )
    parser.add_argument(
        "--filter",
        action="append",
        dest="filters",
        help="Only include object paths containing this substring. Repeatable.",
    )
    parser.add_argument(
        "--source",
        action="append",
        dest="sources",
        help="Only include corpus/build/<source>/... paths for this source name. Repeatable.",
    )
    parser.add_argument(
        "--max-programs",
        type=int,
        help="Stop after processing this many discovered programs.",
    )
    parser.add_argument(
        "--recompile-mode",
        choices=("v4", "v5"),
        default="v5",
        help="Directive recompile path used for probes and packet paired runs.",
    )
    return parser.parse_args()


def ensure_root() -> None:
    if os.geteuid() == 0:
        return
    os.execvp("sudo", ["sudo", "-n", sys.executable, str(Path(__file__).resolve()), *sys.argv[1:]])


def zero_scan() -> dict[str, int]:
    return {
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "total_sites": 0,
    }


def canonical_section_root(section_name: str) -> str:
    raw_root = section_name.split("/", 1)[0] if section_name else ""
    alias_map = {
        "fentry.s": "fentry",
        "fexit.s": "fexit",
        "fmod_ret.s": "fmod_ret",
        "iter.s": "iter",
        "lsm.s": "lsm",
        "raw_tracepoint.w": "raw_tracepoint",
        "struct_ops.s": "struct_ops",
    }
    if raw_root in alias_map:
        return alias_map[raw_root]
    if raw_root.startswith("kprobe"):
        return "kprobe"
    if raw_root.startswith("kretprobe"):
        return "kretprobe"
    if raw_root.startswith("ksyscall"):
        return "ksyscall"
    if raw_root.startswith("kretsyscall"):
        return "kretsyscall"
    if raw_root.startswith("uprobe"):
        return "uprobe"
    if raw_root.startswith("uretprobe"):
        return "uretprobe"
    if raw_root.startswith("usdt"):
        return "usdt"
    if raw_root.startswith("xdp"):
        return "xdp"
    if raw_root == "tcx" or raw_root.startswith("tc_") or raw_root.startswith("tcx") or raw_root.startswith("tc_packet_hook"):
        return "tc"
    return raw_root


def fallback_prog_type_name(section_name: str) -> str:
    root = canonical_section_root(section_name)
    if root == "xdp":
        return "xdp"
    if root == "tc":
        return "sched_cls"
    if root == "cgroup_skb":
        return "cgroup_skb"
    if root == "socket":
        return "socket_filter"
    if root in {"sk_skb", "sk_msg", "flow_dissector", "perf_event", "netfilter", "sk_lookup", "sockops"}:
        return {
            "sockops": "sock_ops",
        }.get(root, root)
    if root in {"kprobe", "kretprobe", "uprobe", "uretprobe", "usdt", "ksyscall", "kretsyscall"}:
        return "kprobe"
    if root in {"tracepoint", "tp"}:
        return "tracepoint"
    if root in {"raw_tp", "raw_tracepoint"}:
        return "raw_tracepoint"
    if root in {"fentry", "fexit", "fmod_ret", "lsm", "iter", "freplace"}:
        return "tracing"
    return "unknown"


def source_name_for_path(path: Path, corpus_root: Path) -> str:
    try:
        return path.relative_to(corpus_root).parts[0]
    except Exception:
        return "unknown"


def classify_program(section_name: str, prog_type_name: str) -> dict[str, str]:
    root = canonical_section_root(section_name)
    prog_type = prog_type_name or fallback_prog_type_name(section_name)

    if prog_type in PACKET_PROG_TYPES:
        return {
            "strategy": "packet_test_run",
            "reason": "packet-backed bpf_prog_test_run is available for this program type",
        }
    if root in TRACING_SECTION_ROOTS:
        return {
            "strategy": "tracing_attach_trigger",
            "reason": "requires load + attach + external trigger to collect runtime",
        }
    if root in {"uprobe", "uretprobe", "usdt"}:
        return {
            "strategy": "user_tracing_custom_target",
            "reason": "requires a matching userspace binary/probe target, so only loadability and sites are recorded",
        }
    if prog_type == "syscall":
        return {
            "strategy": "synthetic_syscall_only",
            "reason": "kernel test_run exists, but this harness does not treat it as a real attach+workload measurement",
        }
    if prog_type == "perf_event":
        return {
            "strategy": "perf_event_custom",
            "reason": "requires perf_event attachment and workload generation",
        }
    if prog_type in {"cgroup_sock", "cgroup_sock_addr", "cgroup_sockopt", "cgroup_sysctl", "cgroup_device"} or root in {"cgroup", "lsm_cgroup"}:
        return {
            "strategy": "cgroup_custom_harness",
            "reason": "requires cgroup/socket/sysctl-specific setup beyond the generic packet harness",
        }
    if prog_type == "lsm" or root == "lsm":
        return {
            "strategy": "lsm_custom_harness",
            "reason": "requires security hook attachment; current automation only records loadability and sites",
        }
    if prog_type in {"struct_ops", "ext"} or root in {"struct_ops", "freplace"}:
        return {
            "strategy": "kernel_registration_required",
            "reason": "requires struct_ops registration or freplace target registration instead of plain test_run",
        }
    if prog_type == "netfilter" or root == "netfilter":
        return {
            "strategy": "netfilter_custom_harness",
            "reason": "requires netfilter hook environment",
        }
    if prog_type in {"sock_ops", "sk_lookup", "sk_reuseport"} or root in {"sockops", "sk_lookup", "sk_reuseport"}:
        return {
            "strategy": "socket_custom_harness",
            "reason": "requires socket lifecycle or listener setup beyond packet test_run",
        }
    if root == "iter":
        return {
            "strategy": "iterator_custom_harness",
            "reason": "iterator programs require seq_file/iterator context rather than packet test_run",
        }
    return {
        "strategy": "load_only_other",
        "reason": "no generic real-program benchmark harness is wired up for this hook yet",
    }


def execution_plan(strategy: str, packet_path: Path, context_path: Path) -> dict[str, Any]:
    if strategy == "packet_test_run":
        return {
            "io_mode": "packet",
            "memory_path": packet_path,
            "input_size": 64,
            "raw_packet": True,
        }
    return {
        "io_mode": "context",
        "memory_path": context_path if strategy == "synthetic_syscall_only" else None,
        "input_size": 64 if strategy == "synthetic_syscall_only" else 0,
        "raw_packet": False,
    }


def build_kernel_command(
    runner: Path,
    object_path: Path,
    program_name: str,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    repeat: int,
    *,
    raw_packet: bool,
    compile_only: bool,
    recompile_mode: str | None,
    dump_xlated: Path | None = None,
) -> list[str]:
    command = [
        str(runner),
        "run-kernel",
        "--program",
        str(object_path),
        "--program-name",
        program_name,
        "--io-mode",
        io_mode,
        "--repeat",
        str(max(1, repeat)),
    ]
    if raw_packet:
        command.append("--raw-packet")
    if memory_path is not None:
        command.extend(["--memory", str(memory_path)])
    if input_size > 0:
        command.extend(["--input-size", str(input_size)])
    if recompile_mode == "v4":
        command.append("--recompile-all")
    elif recompile_mode == "v5":
        command.extend(["--recompile-all", "--recompile-v5"])
    if dump_xlated is not None:
        command.extend(["--dump-xlated", str(dump_xlated)])
    if compile_only:
        command.append("--compile-only")
    return command


def parse_v5_scanner_output(stdout: str) -> dict[str, Any]:
    patterns = {
        "cmov_sites": re.compile(r"^\s*cmov:\s+(\d+)\s*$"),
        "wide_sites": re.compile(r"^\s*wide:\s+(\d+)\s*$"),
        "rotate_sites": re.compile(r"^\s*rotate:\s+(\d+)\s*$"),
        "lea_sites": re.compile(r"^\s*lea:\s+(\d+)\s*$"),
        "accepted": re.compile(r"^Accepted\s+(\d+)\s+v5 site\(s\)\s*$"),
    }
    matches: dict[str, int] = {}
    for line in stdout.splitlines():
        for key, pattern in patterns.items():
            found = pattern.match(line.strip())
            if found:
                matches[key] = int(found.group(1))
                break

    if "accepted" not in matches:
        raise RuntimeError("scanner did not print a v5 summary")

    directive_scan = {
        "cmov_sites": matches.get("cmov_sites", 0),
        "wide_sites": matches.get("wide_sites", 0),
        "rotate_sites": matches.get("rotate_sites", 0),
        "lea_sites": matches.get("lea_sites", 0),
        "total_sites": (
            matches.get("cmov_sites", 0)
            + matches.get("wide_sites", 0)
            + matches.get("rotate_sites", 0)
            + matches.get("lea_sites", 0)
        ),
    }
    return {
        "accepted_rules": matches["accepted"],
        "directive_scan": directive_scan,
    }


def offline_scan_v5(scanner: Path, xlated_path: Path, timeout_seconds: int) -> dict[str, Any]:
    command = [str(scanner), "scan", "--xlated", str(xlated_path), "--all", "--v5"]
    start = time.monotonic()
    try:
        completed = subprocess.run(
            command,
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired as exc:
        return {
            "ok": False,
            "returncode": None,
            "timed_out": True,
            "duration_seconds": time.monotonic() - start,
            "stderr_tail": summarize_stderr(exc.stderr or ""),
            "stdout_tail": summarize_stderr(exc.stdout or ""),
            "error": f"scanner timeout after {timeout_seconds}s",
            "directive_scan": zero_scan(),
        }

    stdout = completed.stdout or ""
    stderr = completed.stderr or ""
    result = {
        "ok": completed.returncode == 0,
        "returncode": completed.returncode,
        "timed_out": False,
        "duration_seconds": time.monotonic() - start,
        "stderr_tail": summarize_stderr(stderr),
        "stdout_tail": summarize_stderr(stdout),
        "error": None,
        "directive_scan": zero_scan(),
    }
    if completed.returncode != 0:
        result["error"] = summarize_stderr(stderr) or summarize_stderr(stdout) or f"scanner failed (exit={completed.returncode})"
        return result

    try:
        parsed = parse_v5_scanner_output(stdout)
    except Exception as exc:
        result["ok"] = False
        result["error"] = str(exc)
        return result

    result["accepted_rules"] = parsed["accepted_rules"]
    result["directive_scan"] = parsed["directive_scan"]
    return result


def run_probe_bundle(
    runner: Path,
    scanner: Path | None,
    object_path: Path,
    program_name: str,
    plan: dict[str, Any],
    timeout_seconds: int,
    recompile_mode: str,
) -> dict[str, Any]:
    probe = run_command(
        build_kernel_command(
            runner,
            object_path,
            program_name,
            plan["io_mode"],
            plan["memory_path"],
            plan["input_size"],
            1,
            raw_packet=plan["raw_packet"],
            compile_only=True,
            recompile_mode=recompile_mode,
        ),
        timeout_seconds,
    )
    probe_summary = invocation_summary(probe)
    if probe["ok"]:
        return {
            "recompile_probe": probe_summary,
            "baseline_compile": None,
            "offline_scan": None,
            "loadable": True,
            "directive_scan": directive_scan_from_record(probe_summary),
            "scan_source": "runner_recompile_probe",
        }

    baseline_compile = run_command(
        build_kernel_command(
            runner,
            object_path,
            program_name,
            plan["io_mode"],
            plan["memory_path"],
            plan["input_size"],
            1,
            raw_packet=plan["raw_packet"],
            compile_only=True,
            recompile_mode=None,
        ),
        timeout_seconds,
    )
    baseline_summary = invocation_summary(baseline_compile)
    if not baseline_compile["ok"]:
        return {
            "recompile_probe": probe_summary,
            "baseline_compile": baseline_summary,
            "offline_scan": None,
            "loadable": False,
            "directive_scan": zero_scan(),
            "scan_source": "none",
        }

    offline_scan = None
    directive_scan = zero_scan()
    scan_source = "none"
    if scanner is not None and recompile_mode == "v5":
        with tempfile.TemporaryDirectory(prefix="bpf-xlated-") as tmpdir:
            xlated_path = Path(tmpdir) / "prog.xlated.bin"
            dump = run_command(
                build_kernel_command(
                    runner,
                    object_path,
                    program_name,
                    plan["io_mode"],
                    plan["memory_path"],
                    plan["input_size"],
                    1,
                    raw_packet=plan["raw_packet"],
                    compile_only=True,
                    recompile_mode=None,
                    dump_xlated=xlated_path,
                ),
                timeout_seconds,
            )
            dump_summary = invocation_summary(dump)
            if dump["ok"] and xlated_path.exists():
                offline_scan = offline_scan_v5(scanner, xlated_path, timeout_seconds)
                offline_scan["dump_compile"] = dump_summary
                if offline_scan["ok"]:
                    directive_scan = offline_scan["directive_scan"]
                    scan_source = "scanner_offline_xlated"
            else:
                offline_scan = {
                    "ok": False,
                    "returncode": dump.get("returncode"),
                    "timed_out": dump.get("timed_out"),
                    "duration_seconds": dump.get("duration_seconds"),
                    "stderr_tail": dump_summary["stderr_tail"],
                    "stdout_tail": "",
                    "error": dump_summary["error"] or "failed to dump xlated program",
                    "directive_scan": zero_scan(),
                    "dump_compile": dump_summary,
                }

    return {
        "recompile_probe": probe_summary,
        "baseline_compile": baseline_summary,
        "offline_scan": offline_scan,
        "loadable": True,
        "directive_scan": directive_scan,
        "scan_source": scan_source,
    }


def run_packet_measurements(
    runner: Path,
    object_path: Path,
    program_name: str,
    plan: dict[str, Any],
    packet_repeat: int,
    timeout_seconds: int,
    recompile_mode: str,
    directive_scan: dict[str, int],
) -> tuple[dict[str, Any] | None, dict[str, Any] | None, dict[str, Any], float | None]:
    baseline = run_command(
        build_kernel_command(
            runner,
            object_path,
            program_name,
            plan["io_mode"],
            plan["memory_path"],
            plan["input_size"],
            packet_repeat,
            raw_packet=plan["raw_packet"],
            compile_only=False,
            recompile_mode=None,
        ),
        timeout_seconds,
    )
    baseline_summary = invocation_summary(baseline)
    recompile_summary = None
    if baseline["ok"] and directive_scan["total_sites"] > 0:
        recompile = run_command(
            build_kernel_command(
                runner,
                object_path,
                program_name,
                plan["io_mode"],
                plan["memory_path"],
                plan["input_size"],
                packet_repeat,
                raw_packet=plan["raw_packet"],
                compile_only=False,
                recompile_mode=recompile_mode,
            ),
            timeout_seconds,
        )
        recompile_summary = invocation_summary(recompile)
    correctness = compute_correctness(baseline_summary, recompile_summary)
    speedup_ratio = compute_speedup_ratio(baseline_summary, recompile_summary)
    return baseline_summary, recompile_summary, correctness, speedup_ratio


def choose_tracing_trigger(section_name: str, program_name: str) -> tuple[Any | None, str | None]:
    root = canonical_section_root(section_name)
    if root not in TRACING_SECTION_ROOTS:
        return None, f"unsupported tracing section root `{root}`"

    target = section_name.split("/", 1)[1].lower() if "/" in section_name else ""
    if not target:
        return None, "missing attach target in section name"
    if "dummy_" in target:
        return None, "dynamic attach target placeholder"

    if any(token in target for token in ("unlink", "do_unlinkat")):
        return TRIGGERS["unlink"], None
    if "futex" in target:
        return TRIGGERS["futex"], None
    if any(token in target for token in ("execve", "sched_process_exec", "sched_process_exit", "security_bprm_check")):
        return TRIGGERS["execve"], None
    if any(token in target for token in ("sched_switch", "sched_wakeup", "sched_wakeup_new")):
        return TRIGGERS["sched"], None
    if any(token in target for token in ("kill", "tgkill")):
        return TRIGGERS["signal"], None
    if any(token in target for token in ("write", "vfs_write", "sys_enter_write")):
        return TRIGGERS["write-devnull"], None
    if any(token in target for token in ("open", "openat", "getattr")):
        return TRIGGERS["open-close"], None
    if any(token in target for token in ("tcp_", "sock", "connect", "accept")):
        return TRIGGERS["tcp-loopback"], None
    if any(
        token in target
        for token in (
            "block_",
            "bio",
            "folio",
            "page_cache",
            "filemap",
            "readahead",
            "mark_page_accessed",
        )
    ):
        return TRIGGERS["disk-io"], None
    if any(token in target for token in ("sys_enter", "sys_exit")):
        return TRIGGERS["generic-syscalls"], None
    if root in {"tracepoint", "tp", "raw_tracepoint", "raw_tp", "tp_btf"}:
        return TRIGGERS["generic-syscalls"], None

    return None, f"no trigger heuristic for section `{section_name}` / program `{program_name}`"


def true_runnable(record: dict[str, Any]) -> bool:
    baseline_run = record.get("baseline_run")
    tracing = record.get("tracing_measurement") or {}
    return bool(
        (baseline_run and baseline_run.get("ok"))
        or (tracing.get("ok") and tracing.get("run_cnt_delta", 0) > 0)
    )


def source_summary(records: list[dict[str, Any]]) -> list[dict[str, Any]]:
    grouped: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in records:
        grouped[record["source_name"]].append(record)

    rows: list[dict[str, Any]] = []
    for source_name, source_records in grouped.items():
        rows.append(
            {
                "source_name": source_name,
                "objects": len({item["object_path"] for item in source_records}),
                "programs": len(source_records),
                "loadable": sum(1 for item in source_records if item["loadable"]),
                "directive_bearing": sum(1 for item in source_records if item["directive_scan"]["total_sites"] > 0),
                "packet_runnable": sum(1 for item in source_records if (item.get("baseline_run") or {}).get("ok")),
                "packet_paired": sum(
                    1
                    for item in source_records
                    if (item.get("baseline_run") or {}).get("ok") and (item.get("recompile_run") or {}).get("ok")
                ),
                "tracing_positive": sum(
                    1
                    for item in source_records
                    if (item.get("tracing_measurement") or {}).get("ok")
                    and item["tracing_measurement"].get("run_cnt_delta", 0) > 0
                ),
                "true_runnable_programs": sum(1 for item in source_records if true_runnable(item)),
            }
        )
    rows.sort(key=lambda item: (-item["true_runnable_programs"], -item["directive_bearing"], item["source_name"]))
    return rows


def prog_type_summary(records: list[dict[str, Any]]) -> list[dict[str, Any]]:
    grouped: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in records:
        grouped[record["prog_type_name"] or "unknown"].append(record)

    rows: list[dict[str, Any]] = []
    for prog_type_name, prog_records in grouped.items():
        rows.append(
            {
                "prog_type_name": prog_type_name,
                "programs": len(prog_records),
                "objects": len({item["object_path"] for item in prog_records}),
                "loadable": sum(1 for item in prog_records if item["loadable"]),
                "directive_bearing": sum(1 for item in prog_records if item["directive_scan"]["total_sites"] > 0),
                "packet_runnable": sum(1 for item in prog_records if (item.get("baseline_run") or {}).get("ok")),
                "packet_paired": sum(
                    1
                    for item in prog_records
                    if (item.get("baseline_run") or {}).get("ok") and (item.get("recompile_run") or {}).get("ok")
                ),
                "tracing_positive": sum(
                    1
                    for item in prog_records
                    if (item.get("tracing_measurement") or {}).get("ok")
                    and item["tracing_measurement"].get("run_cnt_delta", 0) > 0
                ),
                "top_strategy": Counter(item["strategy"] for item in prog_records).most_common(1)[0][0],
            }
        )
    rows.sort(key=lambda item: (-item["programs"], item["prog_type_name"]))
    return rows


def object_summary(records: list[dict[str, Any]]) -> list[dict[str, Any]]:
    grouped: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in records:
        grouped[record["object_path"]].append(record)

    rows: list[dict[str, Any]] = []
    for object_path, object_records in grouped.items():
        strategy_counts = Counter(item["strategy"] for item in object_records)
        loadable = sum(1 for item in object_records if item["loadable"])
        packet_runnable = sum(1 for item in object_records if (item.get("baseline_run") or {}).get("ok"))
        packet_paired = sum(
            1
            for item in object_records
            if (item.get("baseline_run") or {}).get("ok") and (item.get("recompile_run") or {}).get("ok")
        )
        tracing_positive = sum(
            1
            for item in object_records
            if (item.get("tracing_measurement") or {}).get("ok")
            and item["tracing_measurement"].get("run_cnt_delta", 0) > 0
        )
        rows.append(
            {
                "object_path": object_path,
                "source_name": object_records[0]["source_name"],
                "programs": len(object_records),
                "loadable": loadable,
                "directive_sites": sum(item["directive_scan"]["total_sites"] for item in object_records),
                "directive_bearing_programs": sum(1 for item in object_records if item["directive_scan"]["total_sites"] > 0),
                "packet_candidates": sum(1 for item in object_records if item["strategy"] == "packet_test_run"),
                "packet_runnable": packet_runnable,
                "packet_paired": packet_paired,
                "tracing_candidates": sum(1 for item in object_records if item["strategy"] == "tracing_attach_trigger"),
                "tracing_positive": tracing_positive,
                "true_runnable": packet_runnable > 0 or tracing_positive > 0,
                "strategies": ", ".join(name for name, _ in strategy_counts.most_common(3)),
            }
        )
    rows.sort(
        key=lambda item: (
            not item["true_runnable"],
            -item["packet_runnable"],
            -item["tracing_positive"],
            -item["directive_sites"],
            item["object_path"],
        )
    )
    return rows


def build_summary(records: list[dict[str, Any]]) -> dict[str, Any]:
    loadable = [record for record in records if record["loadable"]]
    packet_candidates = [record for record in records if record["strategy"] == "packet_test_run"]
    packet_runnable = [record for record in packet_candidates if (record.get("baseline_run") or {}).get("ok")]
    packet_paired = [
        record
        for record in packet_candidates
        if (record.get("baseline_run") or {}).get("ok") and (record.get("recompile_run") or {}).get("ok")
    ]
    tracing_candidates = [record for record in records if record["strategy"] == "tracing_attach_trigger"]
    tracing_measured = [
        record for record in tracing_candidates if (record.get("tracing_measurement") or {}).get("ok")
    ]
    tracing_positive = [
        record
        for record in tracing_measured
        if record["tracing_measurement"].get("run_cnt_delta", 0) > 0
    ]
    directive_bearing = [record for record in loadable if record["directive_scan"]["total_sites"] > 0]
    speeds = [record["speedup_ratio"] for record in packet_paired if record["speedup_ratio"] is not None]
    avg_ns_values = [
        record["tracing_measurement"]["average_ns_per_run"]
        for record in tracing_positive
        if record["tracing_measurement"].get("average_ns_per_run") is not None
    ]

    family_totals = Counter()
    for record in loadable:
        family_totals["cmov_sites"] += record["directive_scan"]["cmov_sites"]
        family_totals["wide_sites"] += record["directive_scan"]["wide_sites"]
        family_totals["rotate_sites"] += record["directive_scan"]["rotate_sites"]
        family_totals["lea_sites"] += record["directive_scan"]["lea_sites"]

    load_failures = Counter()
    baseline_failures = Counter()
    recompile_failures = Counter()
    tracing_failures = Counter()
    skipped_reasons = Counter()
    for record in records:
        if not record["loadable"]:
            baseline_compile = record.get("baseline_compile")
            recompile_probe = record.get("recompile_probe")
            chosen = baseline_compile or recompile_probe
            load_failures[summarize_failure_reason(chosen)] += 1
        baseline_run = record.get("baseline_run")
        if baseline_run and not baseline_run.get("ok"):
            baseline_failures[summarize_failure_reason(baseline_run)] += 1
        recompile_run = record.get("recompile_run")
        if recompile_run and not recompile_run.get("ok"):
            recompile_failures[summarize_failure_reason(recompile_run)] += 1
        tracing = record.get("tracing_measurement")
        if tracing and not tracing.get("ok"):
            tracing_failures[tracing.get("error") or "measurement failed"] += 1
        if record.get("tracing_skip_reason"):
            skipped_reasons[record["tracing_skip_reason"]] += 1

    return {
        "programs_found": len(records),
        "objects_found": len({record["object_path"] for record in records}),
        "loadable_programs": len(loadable),
        "directive_bearing_programs": len(directive_bearing),
        "packet_candidate_programs": len(packet_candidates),
        "packet_runnable_programs": len(packet_runnable),
        "packet_paired_programs": len(packet_paired),
        "tracing_candidate_programs": len(tracing_candidates),
        "tracing_measured_programs": len(tracing_measured),
        "tracing_positive_programs": len(tracing_positive),
        "true_runnable_programs": sum(1 for record in records if true_runnable(record)),
        "true_runnable_objects": len({record["object_path"] for record in records if true_runnable(record)}),
        "packet_speedup_geomean": geomean([value for value in speeds if value is not None]),
        "packet_speedup_median": statistics.median(speeds) if speeds else None,
        "tracing_avg_ns_min": min(avg_ns_values) if avg_ns_values else None,
        "tracing_avg_ns_max": max(avg_ns_values) if avg_ns_values else None,
        "family_totals": dict(family_totals),
        "strategy_counts": dict(Counter(record["strategy"] for record in records)),
        "load_failures": dict(load_failures.most_common(12)),
        "baseline_failures": dict(baseline_failures.most_common(12)),
        "recompile_failures": dict(recompile_failures.most_common(12)),
        "tracing_failures": dict(tracing_failures.most_common(12)),
        "tracing_skip_reasons": dict(skipped_reasons.most_common(12)),
    }


def build_markdown(data: dict[str, Any]) -> str:
    summary = data["summary"]
    records = data["programs"]
    object_rows = data["objects"]
    source_rows = data["sources"]
    prog_type_rows = data["prog_types"]

    packet_paired = [
        record
        for record in records
        if (record.get("baseline_run") or {}).get("ok") and (record.get("recompile_run") or {}).get("ok")
    ]
    packet_paired.sort(key=lambda item: (-item["directive_scan"]["total_sites"], item["object_path"], item["program_name"]))

    tracing_positive = [
        record
        for record in records
        if (record.get("tracing_measurement") or {}).get("ok")
        and record["tracing_measurement"].get("run_cnt_delta", 0) > 0
    ]
    tracing_positive.sort(
        key=lambda item: (
            -item["directive_scan"]["total_sites"],
            item["tracing_measurement"].get("average_ns_per_run") or math.inf,
            item["object_path"],
            item["program_name"],
        )
    )

    backlog = [
        record
        for record in records
        if record["loadable"] and record["directive_scan"]["total_sites"] > 0 and not true_runnable(record)
    ]
    backlog.sort(
        key=lambda item: (
            -item["directive_scan"]["total_sites"],
            item["strategy"],
            item["object_path"],
            item["program_name"],
        )
    )

    lines: list[str] = [
        "# Corpus Runnability Report",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Runner: `{data['runner_binary']}`",
        f"- Scanner: `{data['scanner_binary']}`",
        f"- Corpus root: `{data['corpus_root']}`",
        f"- Packet repeat: {data['packet_repeat']}",
        f"- Tracing repeat: {data['tracing_repeat']}",
        f"- Recompile mode: `{data['recompile_mode']}`",
        f"- BPF objects scanned: {data['objects_scanned']}",
        f"- Programs discovered: {summary['programs_found']}",
        f"- Loadable programs: {summary['loadable_programs']}",
        f"- Programs with directive sites: {summary['directive_bearing_programs']}",
        f"- Packet-test-run candidates: {summary['packet_candidate_programs']}",
        f"- Packet baseline-runnable programs: {summary['packet_runnable_programs']}",
        f"- Packet paired baseline/recompile programs: {summary['packet_paired_programs']}",
        f"- Tracing attach+trigger candidates: {summary['tracing_candidate_programs']}",
        f"- Tracing programs with positive run_cnt delta: {summary['tracing_positive_programs']}",
        f"- Truly runnable programs: {summary['true_runnable_programs']}",
        f"- Truly runnable objects: {summary['true_runnable_objects']}",
        f"- Packet speedup geomean: {format_ratio(summary['packet_speedup_geomean'])}",
        "",
        "## Strategy Summary",
        "",
    ]
    lines.extend(
        markdown_table(
            ["Strategy", "Programs"],
            [[strategy, count] for strategy, count in sorted(summary["strategy_counts"].items())],
        )
    )
    lines.append("")

    lines.extend(
        [
            "## Directive Totals",
            "",
        ]
    )
    lines.extend(
        markdown_table(
            ["Metric", "Value"],
            [
                ["CMOV sites", summary["family_totals"].get("cmov_sites", 0)],
                ["WIDE sites", summary["family_totals"].get("wide_sites", 0)],
                ["ROTATE sites", summary["family_totals"].get("rotate_sites", 0)],
                ["LEA sites", summary["family_totals"].get("lea_sites", 0)],
                ["Tracing avg ns/run min", f"{summary['tracing_avg_ns_min']:.2f}" if summary["tracing_avg_ns_min"] is not None else "n/a"],
                ["Tracing avg ns/run max", f"{summary['tracing_avg_ns_max']:.2f}" if summary["tracing_avg_ns_max"] is not None else "n/a"],
            ],
        )
    )
    lines.append("")

    lines.extend(
        [
            "## By Program Type",
            "",
        ]
    )
    lines.extend(
        markdown_table(
            ["Prog Type", "Objects", "Programs", "Loadable", "Sites", "Packet Runnable", "Packet Paired", "Tracing +Runs", "Primary Strategy"],
            [
                [
                    row["prog_type_name"],
                    row["objects"],
                    row["programs"],
                    row["loadable"],
                    row["directive_bearing"],
                    row["packet_runnable"],
                    row["packet_paired"],
                    row["tracing_positive"],
                    row["top_strategy"],
                ]
                for row in prog_type_rows
            ],
        )
    )
    lines.append("")

    lines.extend(
        [
            "## By Source",
            "",
        ]
    )
    lines.extend(
        markdown_table(
            ["Source", "Objects", "Programs", "Loadable", "Sites", "Packet Runnable", "Packet Paired", "Tracing +Runs", "True Runnable"],
            [
                [
                    row["source_name"],
                    row["objects"],
                    row["programs"],
                    row["loadable"],
                    row["directive_bearing"],
                    row["packet_runnable"],
                    row["packet_paired"],
                    row["tracing_positive"],
                    row["true_runnable_programs"],
                ]
                for row in source_rows
            ],
        )
    )
    lines.append("")

    lines.extend(
        [
            "## Object Inventory",
            "",
        ]
    )
    lines.extend(
        markdown_table(
            ["Object", "Source", "Programs", "Loadable", "Site Programs", "Sites", "Packet Candidates", "Packet Runnable", "Packet Paired", "Tracing +Runs", "True Runnable", "Top Strategies"],
            [
                [
                    row["object_path"],
                    row["source_name"],
                    row["programs"],
                    row["loadable"],
                    row["directive_bearing_programs"],
                    row["directive_sites"],
                    row["packet_candidates"],
                    row["packet_runnable"],
                    row["packet_paired"],
                    row["tracing_positive"],
                    "yes" if row["true_runnable"] else "no",
                    row["strategies"],
                ]
                for row in object_rows
            ],
        )
    )
    lines.append("")

    if packet_paired:
        lines.extend(
            [
                "## Packet Paired Measurements",
                "",
            ]
        )
        lines.extend(
            markdown_table(
                ["Program", "Type", "Section", "Baseline ns", "Recompile ns", "Speedup", "Correct", "Sites", "CMOV", "WIDE", "ROTATE", "LEA"],
                [
                    [
                        f"{record['object_path']}:{record['program_name']}",
                        record["prog_type_name"],
                        record["section_name"],
                        format_ns(record["baseline_run"]["sample"].get("exec_ns")),
                        format_ns(record["recompile_run"]["sample"].get("exec_ns")),
                        format_ratio(record["speedup_ratio"]),
                        "match" if record["correctness"].get("matches") else "mismatch",
                        record["directive_scan"]["total_sites"],
                        record["directive_scan"]["cmov_sites"],
                        record["directive_scan"]["wide_sites"],
                        record["directive_scan"]["rotate_sites"],
                        record["directive_scan"]["lea_sites"],
                    ]
                    for record in packet_paired
                ],
            )
        )
        lines.append("")

    if tracing_positive:
        lines.extend(
            [
                "## Tracing Measurements",
                "",
            ]
        )
        lines.extend(
            markdown_table(
                ["Program", "Type", "Section", "Trigger", "Runs", "Run Time ns", "Avg ns/run", "Sites"],
                [
                    [
                        f"{record['object_path']}:{record['program_name']}",
                        record["prog_type_name"],
                        record["section_name"],
                        record["tracing_trigger_name"],
                        record["tracing_measurement"]["run_cnt_delta"],
                        format_ns(record["tracing_measurement"]["run_time_ns_delta"]),
                        f"{record['tracing_measurement']['average_ns_per_run']:.2f}" if record["tracing_measurement"].get("average_ns_per_run") is not None else "n/a",
                        record["directive_scan"]["total_sites"],
                    ]
                    for record in tracing_positive
                ],
            )
        )
        lines.append("")

    if backlog:
        lines.extend(
            [
                "## Directive-Bearing But Not Yet Runnable",
                "",
            ]
        )
        lines.extend(
            markdown_table(
                ["Program", "Type", "Section", "Strategy", "Sites", "Reason"],
                [
                    [
                        f"{record['object_path']}:{record['program_name']}",
                        record["prog_type_name"],
                        record["section_name"],
                        record["strategy"],
                        record["directive_scan"]["total_sites"],
                        record["strategy_reason"],
                    ]
                    for record in backlog[:100]
                ],
            )
        )
        lines.append("")

    inventory_failures = data.get("inventory_failures") or []
    if inventory_failures:
        lines.extend(
            [
                "## Inventory Failures",
                "",
            ]
        )
        lines.extend(
            markdown_table(
                ["Object", "Failure"],
                [[item["object_path"], item["error"]] for item in inventory_failures],
            )
        )
        lines.append("")

    if summary["load_failures"]:
        lines.extend(
            [
                "## Top Load Failures",
                "",
            ]
        )
        lines.extend(markdown_table(["Reason", "Count"], [[k, v] for k, v in summary["load_failures"].items()]))
        lines.append("")

    if summary["baseline_failures"]:
        lines.extend(
            [
                "## Top Packet Baseline Failures",
                "",
            ]
        )
        lines.extend(markdown_table(["Reason", "Count"], [[k, v] for k, v in summary["baseline_failures"].items()]))
        lines.append("")

    if summary["recompile_failures"]:
        lines.extend(
            [
                "## Top Recompile Failures",
                "",
            ]
        )
        lines.extend(markdown_table(["Reason", "Count"], [[k, v] for k, v in summary["recompile_failures"].items()]))
        lines.append("")

    if summary["tracing_failures"]:
        lines.extend(
            [
                "## Top Tracing Failures",
                "",
            ]
        )
        lines.extend(markdown_table(["Reason", "Count"], [[k, v] for k, v in summary["tracing_failures"].items()]))
        lines.append("")

    if summary["tracing_skip_reasons"]:
        lines.extend(
            [
                "## Top Tracing Skip Reasons",
                "",
            ]
        )
        lines.extend(markdown_table(["Reason", "Count"], [[k, v] for k, v in summary["tracing_skip_reasons"].items()]))
        lines.append("")

    lines.extend(
        [
            "## Notes",
            "",
            "- Program type comes from `micro_exec list-programs`, which now surfaces libbpf-inferred `prog_type` and `expected_attach_type` per program.",
            "- Packet-backed measurements use `bpf_prog_test_run_opts()` and the existing `micro_exec run-kernel` path.",
            "- Tracing measurements use real load + attach + trigger, then read `run_cnt` and `run_time_ns` from `bpf_prog_info`.",
            "- Directive counts prefer the live recompile probe. When that fails but the program still loads, the report falls back to `dump-xlated` plus `bpf-jit-scanner scan --xlated --v5`.",
            "- `syscall` programs are counted separately because the kernel has a synthetic test-run path, but this report does not treat that as a real attached workload benchmark.",
            "",
        ]
    )
    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    if args.packet_repeat < 1:
        raise SystemExit("--packet-repeat must be >= 1")
    if args.tracing_repeat < 1:
        raise SystemExit("--tracing-repeat must be >= 1")

    ensure_root()

    runner = Path(args.runner).resolve() if args.runner else runner_binary_from_config()
    if not runner.exists():
        raise SystemExit(f"runner binary not found: {runner}")

    scanner = Path(args.scanner).resolve()
    if not scanner.exists():
        scanner = None

    corpus_root = Path(args.corpus_root).resolve()
    if not corpus_root.exists():
        raise SystemExit(f"corpus root not found: {corpus_root}")

    packet_path = materialize_dummy_packet(DEFAULT_PACKET_PATH)
    context_path = materialize_dummy_context(DEFAULT_CONTEXT_PATH)
    raw_paths = sorted(corpus_root.rglob("*.bpf.o"))
    corpus_objects, skipped_non_bpf = filter_bpf_paths(raw_paths, ROOT_DIR)

    if args.filters:
        corpus_objects = [
            path for path in corpus_objects
            if any(token in relpath(path) for token in args.filters)
        ]
    if args.sources:
        allowed_sources = set(args.sources)
        corpus_objects = [
            path for path in corpus_objects
            if source_name_for_path(path, corpus_root) in allowed_sources
        ]

    libbpf = Libbpf()
    program_records: list[dict[str, Any]] = []
    inventory_failures: list[dict[str, Any]] = []

    for object_path in corpus_objects:
        inventory = list_programs(runner, object_path, args.timeout)
        if not inventory["ok"]:
            inventory_failures.append(
                {
                    "object_path": relpath(object_path),
                    "error": inventory["error"],
                    "stderr_tail": summarize_stderr(inventory["stderr"]),
                }
            )
            continue

        for program in inventory.get("inventory", []):
            section_name = str(program.get("section_name", ""))
            prog_type_name = str(program.get("prog_type_name", "") or "")
            if not prog_type_name:
                prog_type_name = fallback_prog_type_name(section_name)
            record: dict[str, Any] = {
                "object_path": relpath(object_path),
                "source_name": source_name_for_path(object_path, corpus_root),
                "program_name": str(program.get("name", "")),
                "section_name": section_name,
                "section_root": canonical_section_root(section_name),
                "insn_count": int(program.get("insn_count", 0)),
                "prog_type": int(program.get("prog_type", 0) or 0),
                "expected_attach_type": int(program.get("expected_attach_type", 0) or 0),
                "prog_type_name": prog_type_name,
                "attach_type_name": str(program.get("attach_type_name", "") or ""),
            }
            classification = classify_program(section_name, prog_type_name)
            record["strategy"] = classification["strategy"]
            record["strategy_reason"] = classification["reason"]
            plan = execution_plan(record["strategy"], packet_path, context_path)
            record["io_mode"] = plan["io_mode"]
            record["input_size"] = plan["input_size"]
            record["memory_path"] = str(plan["memory_path"]) if plan["memory_path"] is not None else None

            probe_bundle = run_probe_bundle(
                runner,
                scanner,
                object_path,
                record["program_name"],
                plan,
                args.timeout,
                args.recompile_mode,
            )
            record.update(probe_bundle)

            record["baseline_run"] = None
            record["recompile_run"] = None
            record["correctness"] = {"comparable": False, "matches": None}
            record["speedup_ratio"] = None
            record["tracing_trigger_name"] = None
            record["tracing_trigger_description"] = None
            record["tracing_skip_reason"] = None
            record["tracing_measurement"] = None

            if record["strategy"] == "packet_test_run" and record["loadable"]:
                baseline_run, recompile_run, correctness, speedup_ratio = run_packet_measurements(
                    runner,
                    object_path,
                    record["program_name"],
                    plan,
                    args.packet_repeat,
                    args.timeout,
                    args.recompile_mode,
                    record["directive_scan"],
                )
                record["baseline_run"] = baseline_run
                record["recompile_run"] = recompile_run
                record["correctness"] = correctness
                record["speedup_ratio"] = speedup_ratio
            elif record["strategy"] == "tracing_attach_trigger" and record["loadable"]:
                trigger, skip_reason = choose_tracing_trigger(section_name, record["program_name"])
                record["tracing_trigger_name"] = trigger.name if trigger else None
                record["tracing_trigger_description"] = trigger.description if trigger else None
                record["tracing_skip_reason"] = skip_reason
                if trigger is not None:
                    try:
                        record["tracing_measurement"] = measure_attached_program(
                            libbpf,
                            object_path,
                            record["program_name"],
                            trigger,
                            args.tracing_repeat,
                        )
                    except Exception as exc:  # pragma: no cover - surfaced in JSON results
                        record["tracing_measurement"] = {
                            "ok": False,
                            "error": str(exc),
                        }

            program_records.append(record)
            if args.max_programs is not None and len(program_records) >= args.max_programs:
                break

        if args.max_programs is not None and len(program_records) >= args.max_programs:
            break

    summary = build_summary(program_records)
    objects = object_summary(program_records)
    sources = source_summary(program_records)
    prog_types = prog_type_summary(program_records)

    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    ensure_parent(output_json)
    ensure_parent(output_md)

    data = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "repo_root": str(ROOT_DIR),
        "runner_binary": str(runner),
        "scanner_binary": str(scanner) if scanner is not None else None,
        "corpus_root": str(corpus_root),
        "packet_repeat": args.packet_repeat,
        "tracing_repeat": args.tracing_repeat,
        "recompile_mode": args.recompile_mode,
        "objects_scanned": len(corpus_objects),
        "skipped_non_bpf_artifacts": list(skipped_non_bpf),
        "inventory_failures": inventory_failures,
        "summary": summary,
        "objects": objects,
        "sources": sources,
        "prog_types": prog_types,
        "programs": program_records,
    }

    output_json.write_text(json.dumps(data, indent=2) + "\n")
    output_md.write_text(build_markdown(data) + "\n")

    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    print(
        f"objects={summary['objects_found']} "
        f"programs={summary['programs_found']} "
        f"true_runnable={summary['true_runnable_programs']}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
