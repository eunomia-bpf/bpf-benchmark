from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from ..workload import run_exec_storm
from .process_support import NativeProcessRunner, WorkloadResult, run_sleep_workload


DEFAULT_OBJECT_ROOT = ROOT_DIR / "corpus" / "build" / "libbpf-bootstrap" / "examples" / "c"
DEFAULT_BINARY_ROOT = ROOT_DIR / "corpus" / "build" / "libbpf-bootstrap" / "bin"


def _binary_name_for_object(object_path: Path) -> str:
    return object_path.name.removesuffix(".bpf.o")


class LibbpfBootstrapRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        if self.object_path is None:
            return ()
        return (DEFAULT_BINARY_ROOT / _binary_name_for_object(self.object_path),)

    def _run_workload(self, seconds: float) -> WorkloadResult:
        if self.object_path is None:
            return run_sleep_workload(seconds)
        stem = _binary_name_for_object(self.object_path)
        if stem in {"bootstrap", "bootstrap_legacy"}:
            return run_exec_storm(max(1, int(round(seconds))), 2)
        return run_sleep_workload(seconds)


__all__ = ["LibbpfBootstrapRunner"]
