from __future__ import annotations

import json
from pathlib import Path

import pytest

from corpus.driver import _validate_cilium_live_inventory_parity
from runner.libs.bpf_evidence import _live_program_graph, native_program_name_overrides


def _write_graph(path: Path, *, name: str, count: int, device: str = "bench0") -> None:
    path.mkdir(parents=True)
    (path / "live-program-graph.json").write_text(
        json.dumps(
            {
                "live_program_ids": list(range(count)),
                "inventory_signature": [{"type": "sched_cls", "name": name, "count": count}],
                "attachment_signature": [
                    {
                        "type": "tcx",
                        "device": device,
                        "attach_type": "tcx_ingress",
                        "program_type": "sched_cls",
                        "program_name": name,
                    }
                ],
            }
        )
        + "\n",
        encoding="utf-8",
    )


def test_cilium_inventory_parity_accepts_identical_live_graphs(tmp_path: Path) -> None:
    baseline = tmp_path / "baseline"
    post = tmp_path / "post"
    _write_graph(baseline, name="cil_from_netdev", count=3)
    _write_graph(post, name="cil_from_netdev", count=3)
    _validate_cilium_live_inventory_parity(baseline, post)
    record = json.loads((tmp_path / "inventory-parity.json").read_text(encoding="utf-8"))
    assert record["status"] == "pass"


def test_cilium_inventory_parity_rejects_extra_native_program(tmp_path: Path) -> None:
    baseline = tmp_path / "baseline"
    post = tmp_path / "post"
    _write_graph(baseline, name="cil_from_netdev", count=1)
    _write_graph(post, name="cil_from_netdev", count=3)
    with pytest.raises(RuntimeError, match="live program inventory differs"):
        _validate_cilium_live_inventory_parity(baseline, post)
    record = json.loads((tmp_path / "inventory-parity.json").read_text(encoding="utf-8"))
    assert record["status"] == "fail"


def test_native_program_names_are_recovered_by_exact_program_id(tmp_path: Path) -> None:
    log_path = tmp_path / "shim.log"
    log_path.write_text(
        "native-loader replaced prog=tail_handle_ipv native_id=41 "
        "symbol=tail_handle_ipv4_from_netdev native_object=/tmp/native.o\n"
        "native-loader replaced prog=tail_handle_ipv native_id=42 "
        "symbol=tail_handle_ipv4_from_host native_object=/tmp/native.o\n",
        encoding="utf-8",
    )
    overrides = native_program_name_overrides(log_path)
    graph = _live_program_graph(
        [
            {"id": 41, "name": "tail_handle_ipv", "type": "sched_cls", "map_ids": []},
            {"id": 42, "name": "tail_handle_ipv", "type": "sched_cls", "map_ids": []},
        ],
        [],
        {},
        [
            {"type": "tcx", "attach_type": "tcx_ingress", "devname": "a", "prog_id": 41},
            {"type": "tcx", "attach_type": "tcx_ingress", "devname": "b", "prog_id": 42},
        ],
        overrides,
    )
    assert graph["inventory_signature"] == [
        {"type": "sched_cls", "name": "tail_handle_ipv4_from_host", "count": 1},
        {"type": "sched_cls", "name": "tail_handle_ipv4_from_netdev", "count": 1},
    ]
    assert graph["canonical_name_overrides"] == {
        "41": "tail_handle_ipv4_from_netdev",
        "42": "tail_handle_ipv4_from_host",
    }


def test_native_program_name_log_rejects_conflicting_id(tmp_path: Path) -> None:
    log_path = tmp_path / "shim.log"
    log_path.write_text(
        "native-loader replaced native_id=41 symbol=first\n"
        "native-loader replaced native_id=41 symbol=second\n",
        encoding="utf-8",
    )
    with pytest.raises(RuntimeError, match="conflicting symbols"):
        native_program_name_overrides(log_path)
