from __future__ import annotations

from collections import Counter
import json
import os
import re
import shutil
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Mapping, Optional

from . import ROOT_DIR, ensure_parent

ARTIFACT_KIND = "result_run"
ARTIFACT_VERSION = 1

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
        clear_existing: bool = False,
    ) -> None:
        self.output_path = output_path.resolve()
        self.run_type = sanitize_artifact_token(run_type)
        self.started_at = generated_at
        self.metadata_builder = metadata_builder
        self.run_dir = create_run_artifact_dir(
            results_dir=result_root_for_output(self.output_path),
            run_type=self.run_type,
            generated_at=generated_at,
            clear_existing=clear_existing,
        )

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

        artifact_path = update_run_artifact(
            run_dir=self.run_dir,
            run_type=self.run_type,
            metadata=metadata,
            detail_payloads=merged_details or None,
            detail_texts=detail_texts,
        )
        if str(status).startswith("completed"):
            _prune_previous_run_details(
                results_dir=result_root_for_output(self.output_path),
                run_type=self.run_type,
                preserve_run_dir=self.run_dir,
            )
        return artifact_path


def sanitize_artifact_token(value: str) -> str:
    token = _NON_ALNUM_RE.sub("_", value.strip()).strip("_")
    return token or "run"


def artifact_timestamp(generated_at: str | None = None) -> str:
    if generated_at:
        try:
            parsed = datetime.fromisoformat(generated_at.replace("Z", "+00:00"))
            return parsed.astimezone(timezone.utc).strftime("%Y%m%d_%H%M%S")
        except ValueError:
            pass
    return datetime.now(timezone.utc).strftime("%Y%m%d_%H%M%S")


def result_root_for_output(output_path: Path) -> Path:
    parent = output_path.resolve().parent
    if parent.name == "dev":
        return parent.parent
    return parent


def derive_run_type(output_path: Path, default_token: str) -> str:
    stem = output_path.stem
    if stem.endswith(".latest"):
        stem = stem[: -len(".latest")]
    stem = _STAMP_SUFFIX_RE.sub("", stem)
    return sanitize_artifact_token(stem or default_token)


def repo_relative_path(path: Path) -> str:
    resolved = path.resolve()
    try:
        return str(resolved.relative_to(ROOT_DIR))
    except ValueError:
        return str(resolved)


def _read_proc_start_ticks(pid: int) -> int | None:
    try:
        fields = Path(f"/proc/{int(pid)}/stat").read_text().split()
    except OSError:
        return None
    if len(fields) < 22:
        return None
    try:
        return int(fields[21])
    except ValueError:
        return None


def _read_boot_id() -> str | None:
    try:
        boot_id = Path("/proc/sys/kernel/random/boot_id").read_text().strip()
    except OSError:
        return None
    return boot_id or None


def current_process_identity() -> dict[str, object]:
    pid = os.getpid()
    payload = {"launcher_pid": int(pid)}
    start_ticks = _read_proc_start_ticks(pid)
    if start_ticks is not None:
        payload["launcher_start_ticks"] = int(start_ticks)
    boot_id = _read_boot_id()
    if boot_id is not None:
        payload["launcher_boot_id"] = boot_id
    return payload


def _managed_run_artifact_metadata(path: Path) -> dict[str, Any] | None:
    metadata_path = path / "metadata.json"
    if not metadata_path.is_file():
        return None
    try:
        payload = json.loads(metadata_path.read_text())
    except (OSError, json.JSONDecodeError) as exc:
        raise RuntimeError(f"failed to read artifact metadata from {metadata_path}: {exc}") from exc
    if not isinstance(payload, dict):
        raise RuntimeError(f"artifact metadata is not a JSON object: {metadata_path}")
    if (
        payload.get("artifact_kind") == ARTIFACT_KIND
        and payload.get("artifact_version") == ARTIFACT_VERSION
    ):
        return payload
    return None


def _is_managed_run_artifact(path: Path) -> bool:
    return _managed_run_artifact_metadata(path) is not None


def _drop_corrupt_run_artifact(path: Path, exc: RuntimeError) -> None:
    print(
        f"warning: removing corrupt run artifact {path}: {exc}",
        file=sys.stderr,
    )
    shutil.rmtree(path)


def clear_previous_run_artifacts(results_dir: Path) -> None:
    if not results_dir.is_dir():
        return
    for child in results_dir.iterdir():
        if not child.is_dir():
            continue
        try:
            managed = _is_managed_run_artifact(child)
        except RuntimeError as exc:
            _drop_corrupt_run_artifact(child, exc)
            continue
        if managed:
            shutil.rmtree(child)


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


def _daemon_debug_detail_for_sample(
    *,
    benchmark_name: str,
    runtime_name: str,
    sample_index: int,
    sample: Mapping[str, Any],
) -> tuple[str, dict[str, Any], dict[str, Any]] | None:
    rejit = sample.get("rejit")
    if not isinstance(rejit, Mapping):
        return None

    daemon_response = rejit.get("daemon_response")
    if not isinstance(daemon_response, Mapping):
        return None

    sample_slot = sample.get("sample_index")
    effective_sample_index = int(sample_slot) if isinstance(sample_slot, int) else sample_index
    sample_suffix = (
        f"sample{effective_sample_index:02d}"
    )
    basename = (
        f"{sanitize_artifact_token(benchmark_name)}__"
        f"{sanitize_artifact_token(runtime_name)}__{sample_suffix}.json"
    )
    relative_path = f"daemon_debug/{basename}"
    detail_payload = {
        "benchmark": benchmark_name,
        "sample_index": effective_sample_index,
        "rejit_summary": {
            key: value
            for key, value in rejit.items()
            if key != "daemon_response"
        },
        "result": sample.get("result"),
        "runtime": runtime_name,
        "daemon_response": daemon_response,
    }
    index_entry = {
        "benchmark": benchmark_name,
        "sample_index": effective_sample_index,
        "path": f"details/{relative_path}",
        "runtime": runtime_name,
        "verifier_retries": int(rejit.get("verifier_retries", 0) or 0),
    }
    return relative_path, detail_payload, index_entry


def externalize_sample_daemon_debug(
    *,
    benchmark_name: str,
    runtime_name: str,
    sample_index: int,
    sample: dict[str, Any],
) -> tuple[str, dict[str, Any], dict[str, Any]] | None:
    detail = _daemon_debug_detail_for_sample(
        benchmark_name=benchmark_name,
        runtime_name=runtime_name,
        sample_index=sample_index,
        sample=sample,
    )
    if detail is None:
        return None

    relative_path, detail_payload, index_entry = detail
    rejit = sample.get("rejit")
    if isinstance(rejit, dict):
        sanitized_rejit = dict(rejit)
        sanitized_rejit.pop("daemon_response", None)
        sanitized_rejit["daemon_debug_ref"] = f"details/{relative_path}"
        sample["rejit"] = sanitized_rejit

    return relative_path, detail_payload, index_entry


def write_run_artifact(
    *,
    results_dir: Path,
    run_type: str,
    metadata: Mapping[str, Any],
    detail_payloads: Mapping[str, Any] | None = None,
    detail_texts: Mapping[str, str] | None = None,
    clear_existing: bool = False,
) -> Path:
    run_dir = create_run_artifact_dir(
        results_dir=results_dir,
        run_type=run_type,
        generated_at=str(metadata.get("generated_at", "")) or None,
        clear_existing=clear_existing,
    )
    update_run_artifact(
        run_dir=run_dir,
        run_type=run_type,
        metadata=metadata,
        detail_payloads=detail_payloads,
        detail_texts=detail_texts,
    )
    status = str(metadata.get("status") or "").strip().lower()
    if not status or status.startswith("completed"):
        _prune_previous_run_details(
            results_dir=results_dir,
            run_type=run_type,
            preserve_run_dir=run_dir,
        )
    return run_dir


def create_run_artifact_dir(
    *,
    results_dir: Path,
    run_type: str,
    generated_at: str | None = None,
    clear_existing: bool = False,
) -> Path:
    results_dir = results_dir.resolve()
    if clear_existing:
        clear_previous_run_artifacts(results_dir)
    _ensure_no_running_artifacts(
        results_dir=results_dir,
        run_type=run_type,
    )

    run_dir = results_dir / f"{sanitize_artifact_token(run_type)}_{artifact_timestamp(generated_at)}"
    run_dir.mkdir(parents=True, exist_ok=False)
    return run_dir


def update_run_artifact(
    *,
    run_dir: Path,
    run_type: str,
    metadata: Mapping[str, Any],
    detail_payloads: Mapping[str, Any] | None = None,
    detail_texts: Mapping[str, str] | None = None,
) -> Path:
    run_dir = run_dir.resolve()

    metadata_payload = {
        "artifact_kind": ARTIFACT_KIND,
        "artifact_version": ARTIFACT_VERSION,
        "run_type": sanitize_artifact_token(run_type),
        **dict(metadata),
    }

    if detail_payloads or detail_texts:
        metadata_payload["details_dir"] = "details"

    metadata_path = run_dir / "metadata.json"
    metadata_path.write_text(json.dumps(metadata_payload, indent=2, sort_keys=True) + "\n")

    if detail_payloads or detail_texts:
        details_dir = run_dir / "details"
        details_dir.mkdir(parents=True, exist_ok=True)

        for relative_path, payload in (detail_payloads or {}).items():
            detail_path = details_dir / relative_path
            ensure_parent(detail_path)
            detail_path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")

        for relative_path, text in (detail_texts or {}).items():
            detail_path = details_dir / relative_path
            ensure_parent(detail_path)
            detail_path.write_text(text)

    return run_dir


def load_latest_result_for_output(output_path: Path, *, default_run_type: str) -> dict[str, Any]:
    results_dir = result_root_for_output(output_path)
    run_type = sanitize_artifact_token(derive_run_type(output_path, default_run_type))
    if not results_dir.is_dir():
        raise RuntimeError(f"run artifact directory does not exist: {results_dir}")

    latest_dir: Path | None = None
    latest_metadata: dict[str, Any] | None = None
    latest_key: tuple[str, str, str] | None = None
    for child in sorted(results_dir.iterdir()):
        if not child.is_dir():
            continue
        metadata = _managed_run_artifact_metadata(child)
        if metadata is None:
            continue
        if sanitize_artifact_token(str(metadata.get("run_type", ""))) != run_type:
            continue
        started_at = str(metadata.get("started_at", ""))
        last_updated_at = str(metadata.get("last_updated_at", ""))
        candidate_key = (
            last_updated_at,
            started_at,
            child.name,
        )
        if latest_key is None or candidate_key > latest_key:
            latest_dir = child
            latest_metadata = metadata
            latest_key = candidate_key

    if latest_dir is None or latest_metadata is None:
        raise RuntimeError(
            f"no run artifact found for output {output_path} under {results_dir} (run_type={run_type})"
        )

    status = str(latest_metadata.get("status", "")).strip()
    if status != "completed":
        error_message = str(latest_metadata.get("error_message", "")).strip()
        detail = f" status={status!r}"
        if error_message:
            detail += f" error={error_message!r}"
        raise RuntimeError(f"latest run artifact did not complete:{detail} path={latest_dir}")

    result_path = latest_dir / "details" / "result.json"
    if not result_path.is_file():
        raise RuntimeError(f"completed run artifact is missing result payload: {result_path}")
    try:
        payload = json.loads(result_path.read_text())
    except (OSError, json.JSONDecodeError) as exc:
        raise RuntimeError(f"failed to read result payload from {result_path}: {exc}") from exc
    if not isinstance(payload, dict):
        raise RuntimeError(f"result payload is not a JSON object: {result_path}")
    return payload


def _ensure_no_running_artifacts(
    *,
    results_dir: Path,
    run_type: str,
) -> None:
    if not results_dir.is_dir():
        return
    run_type_token = sanitize_artifact_token(run_type)
    running_paths: list[str] = []
    for child in sorted(results_dir.iterdir()):
        if not child.is_dir():
            continue
        try:
            metadata = _managed_run_artifact_metadata(child)
        except RuntimeError as exc:
            _drop_corrupt_run_artifact(child, exc)
            continue
        if metadata is None:
            continue
        if sanitize_artifact_token(str(metadata.get("run_type", ""))) != run_type_token:
            continue
        status = str(metadata.get("status", "")).strip()
        if status != "running":
            continue
        pid_value = metadata.get("launcher_pid")
        start_ticks_value = metadata.get("launcher_start_ticks")
        boot_id_value = str(metadata.get("launcher_boot_id") or "").strip()
        try:
            launcher_pid = int(pid_value)
        except (TypeError, ValueError):
            launcher_pid = 0
        try:
            launcher_start_ticks = int(start_ticks_value)
        except (TypeError, ValueError):
            launcher_start_ticks = 0
        if launcher_pid <= 0 or launcher_start_ticks <= 0 or not boot_id_value:
            _mark_stale_running_artifact(
                child,
                metadata,
                reason=(
                    "previous benchmark artifact is still marked running but is missing launcher "
                    "identity metadata; treating it as stale before starting a new session"
                ),
            )
            continue
        current_start_ticks = _read_proc_start_ticks(launcher_pid)
        current_boot_id = _read_boot_id()
        if current_start_ticks is None:
            _mark_stale_running_artifact(
                child,
                metadata,
                reason=f"previous benchmark launcher pid {launcher_pid} is no longer running",
            )
            continue
        if current_boot_id != boot_id_value:
            _mark_stale_running_artifact(
                child,
                metadata,
                reason=(
                    f"previous benchmark launcher pid {launcher_pid} belongs to boot_id={boot_id_value}, "
                    f"current boot_id={current_boot_id or 'unknown'}"
                ),
            )
            continue
        if current_start_ticks != launcher_start_ticks:
            _mark_stale_running_artifact(
                child,
                metadata,
                reason=(
                    f"previous benchmark launcher pid {launcher_pid} exited and pid was reused "
                    f"(expected start_ticks={launcher_start_ticks}, found={current_start_ticks})"
                ),
            )
            continue
        running_paths.append(f"{child} (launcher_pid={launcher_pid})")
    if running_paths:
        raise RuntimeError(
            "refusing to start a new benchmark session while prior run artifacts are still marked running: "
            + ", ".join(running_paths)
        )


def _prune_previous_run_details(
    *,
    results_dir: Path,
    run_type: str,
    preserve_run_dir: Path | None = None,
) -> None:
    if not results_dir.is_dir():
        return
    run_type_token = sanitize_artifact_token(run_type)
    preserved = preserve_run_dir.resolve() if preserve_run_dir is not None else None
    for child in sorted(results_dir.iterdir()):
        if not child.is_dir():
            continue
        if preserved is not None and child.resolve() == preserved:
            continue
        try:
            metadata = _managed_run_artifact_metadata(child)
        except RuntimeError as exc:
            _drop_corrupt_run_artifact(child, exc)
            continue
        if metadata is None:
            continue
        if sanitize_artifact_token(str(metadata.get("run_type", ""))) != run_type_token:
            continue
        details_dir = child / "details"
        if details_dir.is_dir():
            shutil.rmtree(details_dir)


def _mark_stale_running_artifact(
    run_dir: Path,
    metadata: Mapping[str, Any],
    *,
    reason: str,
) -> None:
    updated_at = datetime.now(timezone.utc).isoformat()
    updated_metadata = dict(metadata)
    updated_metadata["status"] = "aborted"
    updated_metadata["error_message"] = reason
    updated_metadata["last_updated_at"] = updated_at
    updated_metadata.setdefault("aborted_at", updated_at)
    metadata_path = run_dir / "metadata.json"
    metadata_path.write_text(json.dumps(updated_metadata, indent=2, sort_keys=True) + "\n")
    progress_path = run_dir / "details" / "progress.json"
    if progress_path.is_file():
        try:
            progress_payload = json.loads(progress_path.read_text())
        except (OSError, json.JSONDecodeError) as exc:
            raise RuntimeError(f"failed to read progress payload from {progress_path}: {exc}") from exc
        if not isinstance(progress_payload, dict):
            raise RuntimeError(f"progress payload is not a JSON object: {progress_path}")
        updated_progress = dict(progress_payload)
        updated_progress["status"] = "aborted"
        updated_progress["error_message"] = reason
        updated_progress["aborted_at"] = updated_at
        progress_path.write_text(json.dumps(updated_progress, indent=2, sort_keys=True) + "\n")
    print(f"warning: marked stale run artifact aborted: {run_dir}: {reason}", file=sys.stderr)
