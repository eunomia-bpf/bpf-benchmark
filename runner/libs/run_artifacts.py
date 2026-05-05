from __future__ import annotations

import json
import os
import re
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Mapping, Optional

from . import ensure_parent

_NON_ALNUM_RE = re.compile(r"[^A-Za-z0-9]+")
_STAMP_SUFFIX_RE = re.compile(r"_(?:authoritative_)?\d{8}(?:_\d{6})?$")

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
        except ValueError:
            raise ValueError(f"invalid generated_at timestamp: {generated_at!r}") from None
        return parsed.astimezone(timezone.utc).strftime("%Y%m%d_%H%M%S_%f")
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


