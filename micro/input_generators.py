from __future__ import annotations

# Compatibility shim: the shared implementation now lives under runner/libs
# so runner's base layer no longer depends on micro/.
from runner.libs.input_generators import *  # noqa: F401,F403
