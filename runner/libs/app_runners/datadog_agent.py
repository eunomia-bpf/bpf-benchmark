from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


class DatadogAgentRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return (
            ROOT_DIR / "corpus" / "build" / "datadog-agent" / "bin" / "system-probe",
            ROOT_DIR / "runner" / "repos" / "datadog-agent" / "bin" / "system-probe",
        )

    def _command(self, binary: Path) -> list[str]:
        return [str(binary), "run", *self.loader_args]


__all__ = ["DatadogAgentRunner"]
