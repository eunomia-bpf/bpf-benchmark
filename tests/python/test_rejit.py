from __future__ import annotations

import json
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import rejit


def test_apply_result_treats_missing_inlined_map_entries_as_empty() -> None:
    result = rejit._apply_result_from_response(
        {
            "status": "ok",
            "summary": {"applied": True, "total_sites_applied": 0},
            "program": {"prog_name": "balancer_ingress"},
        },
        output="{}",
        exit_code=0,
    )

    assert result["applied"] is True
    assert result["inlined_map_entries"] == []
    assert result["kernel_prog_name"] == "balancer_ingress"


def test_apply_result_preserves_error_field_when_message_is_missing() -> None:
    result = rejit._apply_result_from_response(
        {
            "status": "error",
            "error": "BPF_PROG_REJIT: Invalid argument (os error 22)",
            "summary": {"applied": False, "total_sites_applied": 0},
            "program": {"prog_name": "event_execve"},
        },
        output="{}",
        exit_code=1,
    )

    assert result["applied"] is False
    assert result["error"] == "BPF_PROG_REJIT: Invalid argument (os error 22)"
    assert result["kernel_prog_name"] == "event_execve"


def test_socket_error_result_preserves_supplied_exit_code() -> None:
    result = rejit._socket_error_result(
        123,
        "socket optimize timed out after 120s for prog 123",
        exit_code=124,
    )

    assert result["applied"] is False
    assert result["exit_code"] == 124
    assert "timed out" in str(result["error"])


def test_optimize_request_preserves_structured_error_response(monkeypatch) -> None:
    monkeypatch.setattr(
        rejit,
        "_daemon_request",
        lambda *args, **kwargs: {
            "status": "error",
            "message": "final REJIT failed",
            "summary": {"applied": False, "total_sites_applied": 1},
            "passes": [
                {
                    "pass_name": "const_prop",
                    "changed": False,
                    "verify": {
                        "status": "rejected",
                        "error_message": "synthetic verifier rejection",
                    },
                    "rollback": {
                        "action": "restored_pre_pass_snapshot",
                        "restored_insn_count": 17,
                    },
                    "sites_applied": 1,
                    "sites_skipped": 0,
                    "insns_before": 17,
                    "insns_after": 17,
                    "insn_delta": 0,
                    "diagnostics": [],
                }
            ],
        },
    )

    response = rejit._optimize_request(
        Path("/tmp/daemon.sock"),
        123,
        enabled_passes=["const_prop"],
        dry_run=False,
    )

    assert response["status"] == "error"
    assert response["passes"][0]["verify"]["status"] == "rejected"
    assert response["passes"][0]["rollback"]["action"] == "restored_pre_pass_snapshot"


def test_benchmark_rejit_enabled_passes_respects_explicit_empty_env(monkeypatch) -> None:
    monkeypatch.setenv("BPFREJIT_BENCH_PASSES", "")

    assert rejit.benchmark_rejit_enabled_passes() == []


def test_benchmark_rejit_enabled_passes_uses_default_when_env_missing(monkeypatch) -> None:
    monkeypatch.delenv("BPFREJIT_BENCH_PASSES", raising=False)

    assert rejit.benchmark_rejit_enabled_passes() == [
        "wide_mem", "rotate", "cond_select", "extract", "endian_fusion",
        "map_inline", "const_prop", "dce",
        "bounds_check_merge", "skb_load_bytes_spec", "bulk_memory",
    ]


def test_benchmark_config_enabled_passes_prefers_policy_default() -> None:
    config = {
        "passes": {
            "active_list": ["const_prop"],
        },
        "policy": {
            "default": {
                "passes": ["const_prop", "dce", "wide_mem"],
            },
        },
    }

    assert rejit.benchmark_config_enabled_passes(config) == ["const_prop", "dce", "wide_mem"]


def test_benchmark_policy_required_site_passes_collects_unique_values() -> None:
    config = {
        "policy": {
            "rules": [
                {"match": {"has_sites": ["map_inline", "const_prop"]}},
                {"match": {"prog_type": "xdp"}},
                {"match": {"has_sites": ["map_inline", "wide_mem"]}},
            ],
        },
    }

    assert rejit.benchmark_policy_required_site_passes(config) == [
        "map_inline",
        "const_prop",
        "wide_mem",
    ]


def test_load_benchmark_config_fails_when_config_is_missing(monkeypatch, tmp_path: Path) -> None:
    missing = tmp_path / "missing-benchmark-config.yaml"
    monkeypatch.setattr(rejit, "_BENCHMARK_CONFIG_PATH", missing)
    rejit._load_benchmark_root_config.cache_clear()
    try:
        with pytest.raises(SystemExit, match="benchmark config file not found"):
            rejit.load_benchmark_config()
    finally:
        rejit._load_benchmark_root_config.cache_clear()


def test_resolve_program_enabled_passes_applies_ordered_rules() -> None:
    config = {
        "policy": {
            "default": {
                "passes": ["const_prop", "dce"],
            },
            "rules": [
                {
                    "match": {"prog_type": "xdp"},
                    "enable": ["wide_mem"],
                },
                {
                    "match": {"repo": "katran"},
                    "enable": ["endian_fusion"],
                },
                {
                    "match": {"has_sites": ["map_inline"]},
                    "enable": ["map_inline"],
                },
                {
                    "match": {"prog_type": "kprobe"},
                    "passes": ["const_prop"],
                    "disable": ["dce"],
                },
            ],
        },
    }

    xdp_passes = rejit.resolve_program_enabled_passes(
        config,
        context={"repo": "katran", "prog_type": "xdp"},
        site_counts={"map_inline": 3},
    )
    kprobe_passes = rejit.resolve_program_enabled_passes(
        config,
        context={"repo": "katran", "prog_type": "kprobe"},
        site_counts={"map_inline": 3},
    )

    assert xdp_passes == ["const_prop", "dce", "wide_mem", "endian_fusion", "map_inline"]
    assert kprobe_passes == ["const_prop"]


def test_apply_daemon_rejit_empty_pass_list_uses_socket(monkeypatch) -> None:
    calls: list[tuple[str, object]] = []

    def fake_apply_one_via_socket(socket_path, prog_id, enabled_passes, **kwargs):
        del kwargs
        calls.append(("socket", (socket_path, prog_id, list(enabled_passes))))
        return {
            "applied": True,
            "output": "",
            "exit_code": 0,
            "counts": {"total_sites": 0, "applied_sites": 0},
            "error": "",
        }

    monkeypatch.setattr(
        rejit,
        "_start_daemon_server",
        lambda _daemon_binary: (_ for _ in ()).throw(AssertionError("unexpected daemon restart")),
    )
    monkeypatch.setattr(rejit, "_apply_one_via_socket", fake_apply_one_via_socket)

    result = rejit.apply_daemon_rejit(
        [123],
        enabled_passes=[],
        daemon_socket_path=Path("/tmp/daemon.sock"),
    )

    assert result["applied"] is True
    assert ("socket", (Path("/tmp/daemon.sock"), 123, [])) in calls


def test_apply_daemon_rejit_branch_flip_profiles_before_optimize(monkeypatch) -> None:
    calls: list[tuple[str, object]] = []

    def fake_prepare_branch_flip_profile(socket_path, **kwargs):
        del kwargs
        calls.append(("profile", socket_path))
        return None

    def fake_apply_one_via_socket(socket_path, prog_id, enabled_passes, **kwargs):
        del kwargs
        calls.append(("socket", (socket_path, prog_id, list(enabled_passes))))
        return {
            "applied": True,
            "output": "",
            "exit_code": 0,
            "counts": {"total_sites": 1, "applied_sites": 1},
            "error": "",
        }

    monkeypatch.setattr(
        rejit,
        "_start_daemon_server",
        lambda _daemon_binary: (_ for _ in ()).throw(AssertionError("unexpected daemon restart")),
    )
    monkeypatch.setattr(rejit, "_prepare_branch_flip_profile", fake_prepare_branch_flip_profile)
    monkeypatch.setattr(rejit, "_apply_one_via_socket", fake_apply_one_via_socket)

    result = rejit.apply_daemon_rejit(
        [123],
        enabled_passes=["branch_flip"],
        daemon_socket_path=Path("/tmp/daemon.sock"),
    )

    assert result["applied"] is True
    assert ("profile", Path("/tmp/daemon.sock")) in calls
    assert ("socket", (Path("/tmp/daemon.sock"), 123, ["branch_flip"])) in calls


def test_scan_programs_uses_supplied_daemon_socket_without_restart(monkeypatch) -> None:
    calls: list[tuple[str, object]] = []
    daemon_proc = object()

    def fake_optimize_request(socket_path, prog_id, enabled_passes, dry_run, **kwargs):
        calls.append(("optimize", (socket_path, prog_id, enabled_passes, dry_run, kwargs)))
        return {
            "status": "ok",
            "passes": [{"pass_name": "map_inline", "sites_found": 2}],
            "program": {
                "prog_name": f"prog_{prog_id}",
                "prog_type": 6,
                "orig_insn_count": 42,
            },
        }

    monkeypatch.setattr(
        rejit,
        "_start_daemon_server",
        lambda _daemon_binary: (_ for _ in ()).throw(AssertionError("unexpected daemon restart")),
    )
    monkeypatch.setattr(rejit, "_optimize_request", fake_optimize_request)

    result = rejit.scan_programs(
        [123],
        Path("/tmp/fake-daemon"),
        daemon_socket_path=Path("/tmp/existing.sock"),
        daemon_proc=daemon_proc,
        daemon_stdout_path=Path("/tmp/daemon.stdout.log"),
        daemon_stderr_path=Path("/tmp/daemon.stderr.log"),
        timeout_seconds=33,
    )

    assert result[123]["error"] == ""
    assert result[123]["counts"]["map_inline_sites"] == 2
    assert calls == [
        (
            "optimize",
            (
                Path("/tmp/existing.sock"),
                123,
                None,
                True,
                {
                    "daemon_proc": daemon_proc,
                    "stdout_path": Path("/tmp/daemon.stdout.log"),
                    "stderr_path": Path("/tmp/daemon.stderr.log"),
                    "timeout_seconds": 33.0,
                },
            ),
        )
    ]


def test_apply_daemon_rejit_uses_supplied_daemon_socket_without_restart(monkeypatch) -> None:
    calls: list[tuple[str, object]] = []
    daemon_proc = object()

    def fake_apply_one_via_socket(socket_path, prog_id, enabled_passes, **kwargs):
        calls.append(("socket", (socket_path, prog_id, list(enabled_passes), kwargs)))
        return {
            "applied": True,
            "output": "",
            "exit_code": 0,
            "counts": {"total_sites": 1, "applied_sites": 1},
            "error": "",
        }

    monkeypatch.setattr(
        rejit,
        "_start_daemon_server",
        lambda _daemon_binary: (_ for _ in ()).throw(AssertionError("unexpected daemon restart")),
    )
    monkeypatch.setattr(rejit, "_apply_one_via_socket", fake_apply_one_via_socket)

    result = rejit.apply_daemon_rejit(
        [123],
        enabled_passes=["map_inline"],
        daemon_socket_path=Path("/tmp/existing.sock"),
        daemon_proc=daemon_proc,
        daemon_stdout_path=Path("/tmp/daemon.stdout.log"),
        daemon_stderr_path=Path("/tmp/daemon.stderr.log"),
    )

    assert result["applied"] is True
    assert result["counts"] == {"total_sites": 1, "applied_sites": 1}
    assert calls == [
        (
            "socket",
            (
                Path("/tmp/existing.sock"),
                123,
                ["map_inline"],
                {
                    "daemon_proc": daemon_proc,
                    "stdout_path": Path("/tmp/daemon.stdout.log"),
                    "stderr_path": Path("/tmp/daemon.stderr.log"),
                },
            ),
        )
    ]


def test_prepare_branch_flip_profile_sends_start_stop(monkeypatch) -> None:
    requests: list[dict[str, object]] = []
    sleeps: list[float] = []

    def fake_profile_request(_socket_path, payload, **kwargs):
        del kwargs
        requests.append(dict(payload))
        return {"status": "ok"}

    monkeypatch.setattr(rejit, "_profile_request", fake_profile_request)
    monkeypatch.setattr(rejit.time, "sleep", lambda seconds: sleeps.append(seconds))

    result = rejit._prepare_branch_flip_profile(Path("/tmp/daemon.sock"))

    assert result is None
    assert requests == [
        {"cmd": "profile-start", "interval_ms": 1000},
        {"cmd": "profile-stop"},
    ]
    assert sleeps == [1.0]


def test_apply_daemon_rejit_requires_prog_ids() -> None:
    try:
        rejit.apply_daemon_rejit([])
    except ValueError as exc:
        assert "at least one prog_id" in str(exc)
    else:
        raise AssertionError("expected ValueError for empty prog_ids")


def test_apply_daemon_rejit_requires_daemon_socket_path() -> None:
    with pytest.raises(ValueError, match="daemon_socket_path"):
        rejit.apply_daemon_rejit([123])


def test_apply_one_via_socket_sends_explicit_empty_pass_list(monkeypatch) -> None:
    sent_payload: dict[str, object] = {}

    class FakeSocket:
        def settimeout(self, _timeout):
            return None

        def connect(self, _path):
            return None

        def sendall(self, payload: bytes) -> None:
            sent_payload.update(json.loads(payload.decode().strip()))

        def recv(self, _size: int) -> bytes:
            return b'{"status":"ok","summary":{"applied":true,"total_sites_applied":0},"program":{"prog_name":"x"}}\n'

        def __enter__(self):
            return self

        def __exit__(self, exc_type, exc, tb):
            del exc_type, exc, tb
            return False

    monkeypatch.setattr(rejit.socket, "socket", lambda *args, **kwargs: FakeSocket())

    result = rejit._apply_one_via_socket(Path("/tmp/daemon.sock"), 321, [])

    assert result["applied"] is True
    assert sent_payload == {"cmd": "optimize", "prog_id": 321, "enabled_passes": []}
