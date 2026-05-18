"""Translate a runner-provided shim yaml config into BPFREJIT_SHIM_* env vars.

Used by the corpus runner to inject per-app shim configuration into the
process env before launching an app under LD_PRELOAD. Keeps the C shim free
of yaml parsing.

Recognized yaml keys (all optional, sensible defaults applied):

    passes:           [noop]                 # passes to run via bpfopt subprocess
    tick_ms:          1500                   # worker thread cadence
    periodic_dump_ms: 0                      # 0 disables periodic state JSON
    bpfopt_path:      /usr/local/bin/bpfopt
    sock_dir:         /var/run/bpfrejit
    sock_disable:     false
    log_path:         /tmp/bpfrejit_shim.log
    dump_dir:         /tmp/bpfrejit_shim_dumps

Example yaml:

    # corpus/config/macro_apps.yaml fragment
    apps:
      - name: tracee
        shim:
          passes: [noop, dce, map_inline]
          tick_ms: 2000
          sock_dir: /var/run/bpfrejit
"""

from __future__ import annotations

import os
from typing import Mapping


_ENV_MAP = {
    "passes": "BPFREJIT_SHIM_RUN_BPFOPT",
    "tick_ms": "BPFREJIT_SHIM_TICK_MS",
    "periodic_dump_ms": "BPFREJIT_SHIM_PERIODIC_DUMP_MS",
    "bpfopt_path": "BPFREJIT_BPFOPT_PATH",
    "sock_dir": "BPFREJIT_SHIM_SOCK_DIR",
    "sock_disable": "BPFREJIT_SHIM_SOCK_DISABLE",
    "log_path": "BPFREJIT_SHIM_LOG",
    "dump_dir": "BPFREJIT_SHIM_DIR",
    "preload_path": "LD_PRELOAD",
}


def shim_env_from_yaml(shim_cfg: Mapping[str, object] | None) -> dict[str, str]:
    """Convert a yaml shim block to a {ENV: value} dict.

    The runner is expected to pass shim_cfg as the yaml-parsed shim section
    of the per-app config (or None for "use defaults"). The resulting dict can
    be merged into subprocess env.
    """
    if not shim_cfg:
        return {}
    out: dict[str, str] = {}
    for key, val in shim_cfg.items():
        env_name = _ENV_MAP.get(key)
        if env_name is None:
            continue
        if isinstance(val, list):
            out[env_name] = ",".join(str(v) for v in val)
        elif isinstance(val, bool):
            out[env_name] = "1" if val else "0"
        elif val is None:
            continue
        else:
            out[env_name] = str(val)
    return out


def merge_shim_env(
    base_env: Mapping[str, str], shim_cfg: Mapping[str, object] | None
) -> dict[str, str]:
    """Return a new env dict combining base_env with shim_cfg-derived vars.

    Existing entries in base_env are preserved; shim_cfg overrides any keys
    it sets. To clear an env var, set the yaml value to null.
    """
    merged = dict(base_env)
    merged.update(shim_env_from_yaml(shim_cfg))
    return merged


def _cli() -> int:
    """Read yaml on stdin, emit shell `export KEY=value` lines on stdout.

    Allows shell pipelines to consume the config without importing python.

        cat shim.yaml | python3 shim_env_from_yaml.py
    """
    import sys

    try:
        import yaml  # type: ignore[import-untyped]
    except ImportError:
        print("error: PyYAML required for CLI mode", file=sys.stderr)
        return 1
    doc = yaml.safe_load(sys.stdin) or {}
    env = shim_env_from_yaml(doc)
    for k, v in env.items():
        # Shell-quote.
        v_quoted = "'" + v.replace("'", "'\\''") + "'"
        print(f"export {k}={v_quoted}")
    return 0


if __name__ == "__main__":
    raise SystemExit(_cli())
