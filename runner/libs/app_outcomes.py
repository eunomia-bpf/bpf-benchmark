from __future__ import annotations

import json
import subprocess
from dataclasses import replace
from typing import Callable, Mapping, Sequence

from . import resolve_bpftool_binary
from .workload import WorkloadResult


_LINK_STATS = (
    "rx_packets",
    "rx_bytes",
    "rx_errors",
    "rx_dropped",
    "tx_packets",
    "tx_bytes",
    "tx_errors",
    "tx_dropped",
)


def _run_json(command: Sequence[str]) -> object:
    completed = subprocess.run(command, check=True, capture_output=True, text=True)
    return json.loads(completed.stdout)


def _little_endian(raw: object) -> int:
    if not isinstance(raw, list):
        return 0
    try:
        return int.from_bytes(
            bytes(int(value, 0) if isinstance(value, str) else int(value) for value in raw),
            "little",
        )
    except (TypeError, ValueError):
        return 0


def _per_cpu_words(raw: object, word_count: int) -> list[int]:
    totals = [0] * word_count
    values = raw if isinstance(raw, list) else []
    if values and all(isinstance(value, int) for value in values):
        values = [{"value": values}]
    for cpu_value in values:
        if not isinstance(cpu_value, Mapping):
            continue
        data = cpu_value.get("value")
        if not isinstance(data, list):
            continue
        for index in range(word_count):
            start = index * 8
            totals[index] += _little_endian(data[start : start + 8])
    return totals


def _map_records() -> list[dict[str, object]]:
    payload = _run_json([resolve_bpftool_binary(), "-j", "map", "show"])
    if not isinstance(payload, list):
        return []
    return [dict(record) for record in payload if isinstance(record, Mapping)]


def _map_ids(name: str) -> list[int]:
    return sorted(
        int(record["id"])
        for record in _map_records()
        if str(record.get("name") or "") == name and int(record.get("id", 0) or 0) > 0
    )


def _map_dump(map_id: int) -> list[dict[str, object]]:
    payload = _run_json(
        [resolve_bpftool_binary(), "-j", "map", "dump", "id", str(int(map_id))]
    )
    if not isinstance(payload, list):
        return []
    return [dict(record) for record in payload if isinstance(record, Mapping)]


def _map_lookup(map_id: int, key: int) -> dict[str, object]:
    key_bytes = list(int(key).to_bytes(4, "little"))
    command = [
        resolve_bpftool_binary(),
        "-j",
        "map",
        "lookup",
        "id",
        str(int(map_id)),
        "key",
        "hex",
        *(f"{byte:02x}" for byte in key_bytes),
    ]
    try:
        payload = _run_json(command)
    except subprocess.CalledProcessError as exc:
        return {"error": (exc.stderr or exc.stdout or str(exc)).strip()}
    return dict(payload) if isinstance(payload, Mapping) else {"raw": payload}


def _link_stats(namespace: str, iface: str) -> dict[str, int]:
    result: dict[str, int] = {}
    for name in _LINK_STATS:
        command = [
            "ip",
            "netns",
            "exec",
            namespace,
            "cat",
            f"/sys/class/net/{iface}/statistics/{name}",
        ]
        completed = subprocess.run(command, check=True, capture_output=True, text=True)
        result[name] = int(completed.stdout.strip())
    return result


def _numeric_delta(before: object, after: object) -> object:
    if isinstance(before, int) and isinstance(after, int):
        return after - before
    if isinstance(before, Mapping) and isinstance(after, Mapping):
        keys = sorted(set(before) | set(after))
        return {
            str(key): _numeric_delta(before.get(key, 0), after.get(key, 0))
            for key in keys
        }
    return after


def cilium_outcome_snapshot() -> dict[str, object]:
    verdicts: dict[str, dict[str, int]] = {}
    map_ids = _map_ids("cilium_metrics")
    for map_id in map_ids:
        for record in _map_dump(map_id):
            key = record.get("key")
            if not isinstance(key, list) or len(key) < 2:
                continue
            reason = int(key[0])
            direction = int(key[1]) & 0x3
            count, byte_count = _per_cpu_words(record.get("values", record.get("value")), 2)
            aggregate = verdicts.setdefault(
                f"reason={reason},direction={direction}", {"count": 0, "bytes": 0}
            )
            aggregate["count"] += count
            aggregate["bytes"] += byte_count
    receivers = {
        namespace: _link_stats(namespace, "eth0")
        for namespace in ("bpfbench-cepa", "bpfbench-cepb")
    }
    return {"cilium_metrics_map_ids": map_ids, "verdicts": verdicts, "receivers": receivers}


_KATRAN_STATS_KEYS = {
    "vip_0": 0,
    "lru": 512,
    "lru_miss": 513,
    "new_conn_rate": 514,
    "fallback_lru": 515,
    "icmp_too_big": 516,
    "lpm_src": 517,
    "remote_encap": 518,
    "encap_fail": 519,
    "global_lru": 520,
    "consistent_hash_drop": 521,
    "decap": 522,
    "quic_icmp": 523,
    "icmp_ptb_v6": 524,
    "icmp_ptb_v4": 525,
    "xpop_decap_success": 526,
    "udp_flow_migration": 527,
    "total": 528,
    "tx": 529,
    "drop": 530,
    "pass": 531,
}


def _katran_counter(map_id: int, key: int) -> dict[str, int | str]:
    record = _map_lookup(map_id, key)
    if "error" in record:
        return {"error": str(record["error"])}
    first, second = _per_cpu_words(record.get("values", record.get("value")), 2)
    return {"packets_or_v1": first, "bytes_or_v2": second}


def katran_outcome_snapshot() -> dict[str, object]:
    stats_ids = _map_ids("stats")
    real_ids = _map_ids("reals_stats")
    counters: dict[str, object] = {}
    if stats_ids:
        map_id = stats_ids[-1]
        counters = {
            name: _katran_counter(map_id, key)
            for name, key in _KATRAN_STATS_KEYS.items()
        }
    real_counters: dict[str, object] = {}
    if real_ids:
        real_counters["real_1"] = _katran_counter(real_ids[-1], 1)
    return {
        "stats_map_ids": stats_ids,
        "reals_stats_map_ids": real_ids,
        "counters": counters,
        "real_counters": real_counters,
        "receiver": _link_stats("katran-real", "real0"),
    }


def run_with_outcomes(
    run: Callable[[], WorkloadResult],
    snapshot: Callable[[], dict[str, object]],
) -> WorkloadResult:
    before = snapshot()
    result = run()
    after = snapshot()
    config = dict(result.config or {})
    config["outcomes"] = {
        "before": before,
        "after": after,
        "delta": _numeric_delta(before, after),
    }
    return replace(result, config=config)
