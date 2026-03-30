from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


class KubeArmorRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return (
            ROOT_DIR / "corpus" / "build" / "KubeArmor" / "bin" / "kubearmor",
            ROOT_DIR / "runner" / "repos" / "KubeArmor" / "KubeArmor" / "kubearmor",
        )

    def _command(self, binary: Path) -> list[str]:
        return [str(binary), *self.loader_args]


__all__ = ["KubeArmorRunner"]
