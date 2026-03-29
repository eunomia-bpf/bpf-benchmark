#!/usr/bin/env python3
from __future__ import annotations

"""Compatibility shim forwarding to ``corpus.orchestrator``."""

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from corpus.orchestrator import DEFAULT_MACRO_CORPUS_YAML, main as packet_main

__all__ = ["DEFAULT_MACRO_CORPUS_YAML", "packet_main"]
