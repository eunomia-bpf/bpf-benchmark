from __future__ import annotations

from datetime import datetime, timezone

from runner.libs import ROOT_DIR, docs_tmp_dir, scratch_date_stamp


def test_scratch_date_stamp_preserves_supplied_calendar_day() -> None:
    stamp = scratch_date_stamp(datetime(2026, 3, 26, 23, 59, 58, tzinfo=timezone.utc))
    assert stamp == "20260326"


def test_docs_tmp_dir_partitions_paths_by_date_without_touching_fs() -> None:
    path = docs_tmp_dir("guest-scripts", stamp="20260326", ensure=False)
    assert path == ROOT_DIR / "docs" / "tmp" / "20260326" / "guest-scripts"
