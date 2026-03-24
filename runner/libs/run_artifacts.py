from __future__ import annotations

from collections import Counter
import json
import re
import shutil
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Mapping

from . import ROOT_DIR, ensure_parent

ARTIFACT_KIND = "result_run"
ARTIFACT_VERSION = 1

_NON_ALNUM_RE = re.compile(r"[^A-Za-z0-9]+")
_STAMP_SUFFIX_RE = re.compile(
    r"_(?:authoritative|smoke)_\d{8}(?:_\d{6})?$|_\d{8}(?:_\d{6})?$"
)

MetadataBuilder = Callable[[str, str, str, str | None], Mapping[str, Any]]


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
        if status == "completed":
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

        return update_run_artifact(
            run_dir=self.run_dir,
            run_type=self.run_type,
            metadata=metadata,
            detail_payloads=merged_details or None,
            detail_texts=detail_texts,
        )


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


def derive_run_type(output_path: Path, fallback: str) -> str:
    stem = output_path.stem
    if stem.endswith(".latest"):
        stem = stem[: -len(".latest")]
    stem = _STAMP_SUFFIX_RE.sub("", stem)
    return sanitize_artifact_token(stem or fallback)


def repo_relative_path(path: Path) -> str:
    resolved = path.resolve()
    try:
        return str(resolved.relative_to(ROOT_DIR))
    except ValueError:
        return str(resolved)


def _managed_run_artifact_metadata(path: Path) -> dict[str, Any] | None:
    metadata_path = path / "metadata.json"
    if not metadata_path.is_file():
        return None
    try:
        payload = json.loads(metadata_path.read_text())
    except (OSError, json.JSONDecodeError):
        return None
    if (
        payload.get("artifact_kind") == ARTIFACT_KIND
        and payload.get("artifact_version") == ARTIFACT_VERSION
    ):
        return payload
    return None


def _is_managed_run_artifact(path: Path) -> bool:
    return _managed_run_artifact_metadata(path) is not None


def clear_previous_run_artifacts(results_dir: Path) -> None:
    if not results_dir.is_dir():
        return
    for child in results_dir.iterdir():
        if child.is_dir() and _is_managed_run_artifact(child):
            shutil.rmtree(child)


def clear_previous_run_details(results_dir: Path, *, run_type: str, keep_run_dir: Path) -> None:
    if not results_dir.is_dir():
        return

    normalized_run_type = sanitize_artifact_token(run_type)
    keep_resolved = keep_run_dir.resolve()
    for child in results_dir.iterdir():
        if not child.is_dir():
            continue
        if child.resolve() == keep_resolved:
            continue

        metadata = _managed_run_artifact_metadata(child)
        if metadata is None:
            continue
        if sanitize_artifact_token(str(metadata.get("run_type", ""))) != normalized_run_type:
            continue

        details_dir = child / "details"
        if details_dir.is_dir():
            shutil.rmtree(details_dir)


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
    summarized["paper_summary"] = {
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

    iteration_index = sample.get("iteration_index")
    iter_suffix = (
        f"iter{int(iteration_index):02d}"
        if isinstance(iteration_index, int)
        else f"sample{sample_index:02d}"
    )
    basename = (
        f"{sanitize_artifact_token(benchmark_name)}__"
        f"{sanitize_artifact_token(runtime_name)}__{iter_suffix}.json"
    )
    relative_path = f"daemon_debug/{basename}"
    detail_payload = {
        "benchmark": benchmark_name,
        "iteration_index": iteration_index,
        "rejit_summary": {
            key: value
            for key, value in rejit.items()
            if key != "daemon_response"
        },
        "result": sample.get("result"),
        "runtime": runtime_name,
        "sample_index": sample_index,
        "daemon_response": daemon_response,
    }
    index_entry = {
        "benchmark": benchmark_name,
        "iteration_index": iteration_index,
        "path": f"details/{relative_path}",
        "runtime": runtime_name,
        "sample_index": sample_index,
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


def extract_daemon_debug_details(payload: Mapping[str, Any]) -> tuple[dict[str, Any], int]:
    detail_payloads: dict[str, Any] = {}
    index_entries: list[dict[str, Any]] = []

    for benchmark in payload.get("benchmarks", []):
        if not isinstance(benchmark, Mapping):
            continue
        benchmark_name = str(benchmark.get("name", "unknown"))

        for run in benchmark.get("runs", []):
            if not isinstance(run, Mapping):
                continue
            runtime_name = str(run.get("runtime", "unknown"))
            samples = run.get("samples", [])
            if not isinstance(samples, list):
                continue

            for sample_index, sample in enumerate(samples):
                if not isinstance(sample, Mapping):
                    continue
                detail = _daemon_debug_detail_for_sample(
                    benchmark_name=benchmark_name,
                    runtime_name=runtime_name,
                    sample_index=sample_index,
                    sample=sample,
                )
                if detail is None:
                    continue
                relative_path, detail_payload, index_entry = detail
                detail_payloads[relative_path] = detail_payload
                index_entries.append(index_entry)

    if index_entries:
        detail_payloads["daemon_debug/index.json"] = index_entries

    return detail_payloads, len(index_entries)


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

    run_dir = results_dir / f"{sanitize_artifact_token(run_type)}_{artifact_timestamp(generated_at)}"
    run_dir.mkdir(parents=True, exist_ok=False)
    if not clear_existing:
        clear_previous_run_details(results_dir, run_type=run_type, keep_run_dir=run_dir)
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
