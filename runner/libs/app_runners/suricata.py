from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


class SuricataRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return (
            ROOT_DIR / "corpus" / "build" / "suricata" / "bin" / "suricata",
            ROOT_DIR / "runner" / "repos" / "suricata" / "bin" / "suricata",
            Path("/usr/bin/suricata"),
        )


__all__ = ["SuricataRunner"]
