from __future__ import annotations

from contextlib import contextmanager
from typing import Any

from .agent import bpftool_prog_show_records


@contextmanager
def enable_bpf_stats() -> Any:
    stats_path = "/proc/sys/kernel/bpf_stats_enabled"
    try:
        with open(stats_path) as f:
            enabled = f.read().strip() == "1"
    except OSError:
        enabled = False
    if not enabled:
        raise RuntimeError(
            f"BPF stats not enabled ({stats_path} != 1). "
            "Call ensure_bpf_stats_enabled() in suite setup first."
        )
    yield {"mode": "bpftool"}


def program_table_count() -> int:
    return len(bpftool_prog_show_records())
