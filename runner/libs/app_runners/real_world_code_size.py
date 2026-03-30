from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .libbpf_bootstrap import LibbpfBootstrapRunner


DEFAULT_BINARY_ROOT = ROOT_DIR / "corpus" / "build" / "libbpf-bootstrap" / "bin"


class RealWorldCodeSizeRunner(LibbpfBootstrapRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        if self.object_path is None:
            return ()
        return (DEFAULT_BINARY_ROOT / self.object_path.name.removesuffix(".bpf.o"),)


__all__ = ["RealWorldCodeSizeRunner"]
