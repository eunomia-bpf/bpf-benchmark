#!/usr/bin/env python3
from __future__ import annotations

"""Corpus orchestrator placeholder.

TODO: implement the orchestrator-only corpus flow described in
``docs/kernel-jit-optimization-plan.md`` section 5.6, using shared
``runner/libs/app_runners/`` modules and socket-only daemon coordination.
"""

from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parent.parent
DEFAULT_MACRO_CORPUS_YAML = ROOT_DIR / "corpus" / "config" / "macro_corpus.yaml"


def main(argv: list[str] | None = None) -> int:
    del argv
    raise SystemExit(
        "TODO: corpus/orchestrator.py is the only supported corpus entrypoint under the new architecture"
    )


if __name__ == "__main__":
    raise SystemExit(main())
