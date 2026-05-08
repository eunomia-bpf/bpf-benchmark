"""Adapter that translates legacy `apply_rejit(prog_ids, enabled_passes)` calls
into the daemon's `execute_plan` socket protocol.

Daemon no longer enumerates pass × prog itself; instead it executes a list of
bash command strings per program with `${VAR}` placeholders the daemon
substitutes. This module owns the translation: read pass metadata from
`bpfopt list-passes --json`, build per-pass step templates with the right
side-input flags, and produce the kinsn_probes list daemon needs to populate
target.json.

Runner callers stay on the old `apply_rejit` surface — only this file knows
the new protocol shape.
"""
from __future__ import annotations

import json
import subprocess
from typing import Any, Sequence


def load_pass_metadata(bpfopt: str = "bpfopt") -> dict[str, dict[str, Any]]:
    """Return a map of canonical pass name → metadata dict from
    `bpfopt list-passes --json`. Daemon used to call this internally; the
    runner adapter calls it once per session and caches.
    """
    completed = subprocess.run(
        [bpfopt, "list-passes", "--json"],
        check=True,
        capture_output=True,
        text=True,
    )
    entries = json.loads(completed.stdout)
    if not isinstance(entries, list):
        raise RuntimeError(f"{bpfopt} list-passes --json did not return a JSON array")
    metadata: dict[str, dict[str, Any]] = {}
    for entry in entries:
        if not isinstance(entry, dict):
            raise RuntimeError(f"{bpfopt} list-passes --json entry is not an object")
        canonical = str(entry.get("canonical_name") or "").strip()
        if not canonical:
            raise RuntimeError(f"{bpfopt} list-passes --json entry has no canonical_name")
        metadata[canonical] = entry
    if not metadata:
        raise RuntimeError(f"{bpfopt} list-passes --json returned no passes")
    return metadata


BPFOPT_STEP_TIMEOUT_SECS = 6000  # 100 min hard cap per bpfopt invocation; killed by `timeout(1)`


def build_step_spec(
    pass_name: str,
    pass_meta: dict[str, Any],
    *,
    next_pass_meta: dict[str, Any] | None = None,
) -> dict[str, Any]:
    """Compose one structured step entry for the daemon `execute_plan` socket
    call. Each step is `{name, command, log_level}`:

    - `name`: canonical pass name; daemon echoes it back as `pass_name` in
      the response so analysis tools see real pass names instead of `step_N`.
    - `command`: full bash template using daemon-substituted `${VAR}`
      placeholders. The `timeout` prefix kills bpfopt after
      `BPFOPT_STEP_TIMEOUT_SECS`; daemon sees exit 124 and records it as a
      FailedBpfopt step, so a hung pass cannot stall the whole request.
    - `log_level`: BPF_PROG_REJIT verifier log level. The daemon overwrites
      `verifier_states_path` to point at the most recent rejit log after every
      step, so the only consumer of step N's log is step N+1. Therefore step N
      uses L2 iff its IMMEDIATE successor declares `needs_verifier_states`;
      otherwise L1 with a smaller (1 MiB) log buffer is sufficient.
    """
    parts = [
        f"timeout {BPFOPT_STEP_TIMEOUT_SECS}",
        "bpfopt",
        f"--pass {pass_name}",
        "--input ${INPUT}",
        "--output ${OUTPUT}",
        "--report ${REPORT}",
        "--prog-type ${PROG_TYPE}",
    ]
    if bool(pass_meta.get("needs_target")):
        parts.append("--target ${TARGET}")
    if bool(pass_meta.get("needs_verifier_states")):
        parts.append("--verifier-states ${VERIFIER_STATES}")
    pass_local = ["${PASS_LOCAL_ARGS}"]
    if bool(pass_meta.get("needs_map_values")):
        pass_local.append("--map-values ${MAP_VALUES}")
        pass_local.append("--map-ids ${MAP_IDS}")
    parts.append("--")
    parts.extend(pass_local)
    log_level = 2 if next_pass_meta is not None and bool(next_pass_meta.get("needs_verifier_states")) else 1
    command = " ".join(parts)
    # When KEEP_WORKDIRS=all, prefix the step with a cp dumping the daemon-fed
    # INPUT to the workdir, then force the step to fail so daemon's
    # failure_artifacts mechanism tarballs the whole workdir (incl. the captured
    # input) back to the host.
    import os as _os
    if _os.environ.get("KEEP_WORKDIRS", "").strip().lower() == "all":
        command = (
            "cp ${INPUT} ${WORKDIR}/captured-input-" + pass_name + ".bin && "
            + command
            + " && false"
        )
    return {
        "name": pass_name,
        "command": command,
        "log_level": log_level,
    }


def build_kinsn_probes(
    pass_metas: dict[str, dict[str, Any]],
    enabled_passes: Sequence[str],
) -> list[dict[str, Any]]:
    """Collect the union of `kinsns_used` across the chosen passes into the
    `kinsn_probes` list daemon expects to populate target.json.
    """
    by_name: dict[str, set[str]] = {}
    for pass_name in enabled_passes:
        meta = pass_metas.get(pass_name)
        if meta is None:
            raise RuntimeError(
                f"pass {pass_name!r} not found in bpfopt list-passes --json output"
            )
        for kinsn in meta.get("kinsns_used") or []:
            json_name = str(kinsn.get("json_name") or "").strip()
            aliases = [
                str(a).strip()
                for a in (kinsn.get("probe_aliases") or [])
                if str(a).strip()
            ]
            if not json_name or not aliases:
                raise RuntimeError(
                    f"pass {pass_name!r} declares an invalid kinsn metadata entry"
                )
            by_name.setdefault(json_name, set()).update(aliases)
    return [
        {"name": json_name, "aliases": sorted(aliases)}
        for json_name, aliases in sorted(by_name.items())
    ]


def build_execute_plan_payload(
    prog_ids: Sequence[int],
    enabled_passes: Sequence[str],
    pass_metas: dict[str, dict[str, Any]],
) -> dict[str, Any]:
    """Assemble the full `execute_plan` socket payload for legacy callers
    that still think in terms of (prog_ids, enabled_passes).

    Every prog gets the same step list — the legacy contract has no per-prog
    differentiation. New per-prog/per-step planning belongs in a future
    plan generator that bypasses this adapter.
    """
    if not prog_ids:
        raise ValueError("execute_plan requires at least one prog_id")
    passes = [str(p).strip() for p in enabled_passes if str(p).strip()]
    if not passes:
        raise ValueError("execute_plan requires at least one pass")
    steps = [
        build_step_spec(
            p,
            pass_metas[p],
            next_pass_meta=pass_metas[passes[i + 1]] if i + 1 < len(passes) else None,
        )
        for i, p in enumerate(passes)
    ]
    return {
        "cmd": "execute_plan",
        "programs": [
            {"prog_id": int(pid), "steps": steps} for pid in prog_ids
        ],
        "kinsn_probes": build_kinsn_probes(pass_metas, passes),
    }
