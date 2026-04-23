from __future__ import annotations

from collections import Counter
import json
import os
import re
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Mapping, Optional

from . import ensure_parent

_NON_ALNUM_RE = re.compile(r"[^A-Za-z0-9]+")
_STAMP_SUFFIX_RE = re.compile(
    r"_(?:authoritative|smoke)_\d{8}(?:_\d{6})?$|_\d{8}(?:_\d{6})?$"
)

MetadataBuilder = Callable[[str, str, str, Optional[str]], Mapping[str, Any]]


class ArtifactSession:
    def __init__(
        self,
        *,
        output_path: Path,
        run_type: str,
        generated_at: str,
        metadata_builder: MetadataBuilder,
    ) -> None:
        self.output_path = output_path.resolve()
        self.run_type = sanitize_artifact_token(run_type)
        self.started_at = generated_at
        self.metadata_builder = metadata_builder
        results_dir = self.output_path.parent.parent if self.output_path.parent.name == "dev" else self.output_path.parent
        self.run_dir = results_dir.resolve() / f"{self.run_type}_{artifact_timestamp(generated_at)}"
        self.run_dir.mkdir(parents=True, exist_ok=False)

    def write(
        self,
        *,
        status: str,
        progress_payload: Mapping[str, Any] | None = None,
        result_payload: Mapping[str, Any] | None = None,
        detail_payloads: Mapping[str, Any] | None = None,
        detail_texts: Mapping[str, str] | None = None,
        error_message: str | None = None,
    ) -> Path:
        updated_at = datetime.now(timezone.utc).isoformat()
        metadata = dict(self.metadata_builder(status, self.started_at, updated_at, error_message))
        metadata.setdefault("status", status)
        metadata.setdefault("started_at", self.started_at)
        metadata["last_updated_at"] = updated_at
        if str(status).startswith("completed"):
            metadata.setdefault("completed_at", updated_at)
        if error_message:
            metadata["error_message"] = error_message

        merged_details: dict[str, Any] = {}
        if result_payload is not None:
            merged_details["result.json"] = result_payload
        if progress_payload is not None:
            merged_details["progress.json"] = dict(progress_payload)
        if detail_payloads:
            merged_details.update(detail_payloads)

        metadata_payload = {"run_type": self.run_type, **metadata}
        if merged_details or detail_texts:
            metadata_payload["details_dir"] = "details"
        metadata_path = self.run_dir / "metadata.json"
        # VM artifact mounts can briefly lose just-created directories during sync.
        ensure_parent(metadata_path)
        metadata_path.write_text(json.dumps(metadata_payload, indent=2, sort_keys=True) + "\n")
        if merged_details or detail_texts:
            details_dir = self.run_dir / "details"
            details_dir.mkdir(parents=True, exist_ok=True)
            for relative_path, payload in merged_details.items():
                detail_path = details_dir / relative_path
                ensure_parent(detail_path)
                detail_path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")
            for relative_path, text in (detail_texts or {}).items():
                detail_path = details_dir / relative_path
                ensure_parent(detail_path)
                detail_path.write_text(text)
        return self.run_dir


def sanitize_artifact_token(value: str) -> str:
    token = _NON_ALNUM_RE.sub("_", value.strip()).strip("_")
    return token or "run"


def artifact_timestamp(generated_at: str | None = None) -> str:
    if generated_at:
        try:
            parsed = datetime.fromisoformat(generated_at.replace("Z", "+00:00"))
            return parsed.astimezone(timezone.utc).strftime("%Y%m%d_%H%M%S_%f")
        except ValueError:
            pass
    return datetime.now(timezone.utc).strftime("%Y%m%d_%H%M%S_%f")


def derive_run_type(output_path: Path, default_token: str) -> str:
    stem = output_path.stem
    stem = _STAMP_SUFFIX_RE.sub("", stem)
    return sanitize_artifact_token(stem or default_token)


def current_process_identity() -> dict[str, object]:
    pid = os.getpid()
    payload = {"launcher_pid": int(pid)}
    try:
        fields = Path(f"/proc/{int(pid)}/stat").read_text().split()
        if len(fields) >= 22:
            payload["launcher_start_ticks"] = int(fields[21])
    except (OSError, ValueError):
        pass
    try:
        boot_id = Path("/proc/sys/kernel/random/boot_id").read_text().strip()
    except OSError:
        boot_id = ""
    if boot_id:
        payload["launcher_boot_id"] = boot_id
    return payload


def summarize_benchmark_results(payload: Mapping[str, Any]) -> dict[str, Any]:
    summarized: dict[str, Any] = {
        key: value for key, value in payload.items() if key != "benchmarks"
    }
    runtime_names: set[str] = set()
    correctness_mismatches: list[str] = []
    passes_applied = Counter()
    final_disabled = Counter()
    total_verifier_retries = 0
    total_sites_applied = 0
    daemon_debug_entries = 0
    benchmark_summaries: list[dict[str, Any]] = []

    for benchmark in payload.get("benchmarks", []):
        if not isinstance(benchmark, Mapping):
            continue

        benchmark_summary = {
            key: value for key, value in benchmark.items() if key != "runs"
        }
        if benchmark_summary.get("correctness_mismatch"):
            correctness_mismatches.append(str(benchmark_summary.get("name", "unknown")))

        run_summaries: list[dict[str, Any]] = []
        for run in benchmark.get("runs", []):
            if not isinstance(run, Mapping):
                continue

            runtime_name = str(run.get("runtime", "unknown"))
            runtime_names.add(runtime_name)
            samples = run.get("samples", [])

            run_summary = {key: value for key, value in run.items() if key != "samples"}
            run_summary["sample_count"] = len(samples) if isinstance(samples, list) else 0

            run_passes = Counter()
            run_disabled = Counter()
            run_verifier_retries = 0
            run_sites_applied = 0
            run_daemon_debug_entries = 0

            if isinstance(samples, list):
                for sample in samples:
                    if not isinstance(sample, Mapping):
                        continue
                    rejit = sample.get("rejit")
                    if not isinstance(rejit, Mapping):
                        continue
                    run_verifier_retries += int(rejit.get("verifier_retries", 0) or 0)
                    run_sites_applied += int(rejit.get("total_sites_applied", 0) or 0)
                    if isinstance(rejit.get("daemon_response"), Mapping) or isinstance(
                        rejit.get("daemon_debug_ref"), str
                    ) or bool(rejit.get("daemon_debug_stripped")):
                        run_daemon_debug_entries += 1
                    for pass_name in rejit.get("passes_applied", []):
                        run_passes[str(pass_name)] += 1
                    for pass_name in rejit.get("final_disabled_passes", []):
                        run_disabled[str(pass_name)] += 1

            run_summary["optimization_summary"] = {
                "daemon_debug_entries": run_daemon_debug_entries,
                "final_disabled_passes": dict(sorted(run_disabled.items())),
                "passes_applied": dict(sorted(run_passes.items())),
                "total_sites_applied": run_sites_applied,
                "verifier_retries": run_verifier_retries,
            }

            run_summaries.append(run_summary)
            passes_applied.update(run_passes)
            final_disabled.update(run_disabled)
            total_verifier_retries += run_verifier_retries
            total_sites_applied += run_sites_applied
            daemon_debug_entries += run_daemon_debug_entries

        benchmark_summary["runs"] = run_summaries
        benchmark_summaries.append(benchmark_summary)

    summarized["benchmarks"] = benchmark_summaries
    summarized["optimization_summary"] = {
        "benchmark_count": len(benchmark_summaries),
        "correctness_mismatch_count": len(correctness_mismatches),
        "correctness_mismatches": correctness_mismatches,
        "daemon_debug_entries": daemon_debug_entries,
        "final_disabled_passes": dict(sorted(final_disabled.items())),
        "passes_applied": dict(sorted(passes_applied.items())),
        "runtime_names": sorted(runtime_names),
        "total_sites_applied": total_sites_applied,
        "total_verifier_retries": total_verifier_retries,
    }
    return summarized
