#!/usr/bin/env python3
"""Compare retained same-generation counter windows outside result.json."""
import argparse
from datetime import datetime
import json
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("decoded", type=Path, help="eqcodex-analyze.py output")
parser.add_argument("--pair", nargs=2, action="append", required=True)
args = parser.parse_args()
snapshots = {Path(record["snapshot"]).name: record
             for record in json.loads(args.decoded.read_text())}
windows = []
for first, last in args.pair:
    start, end = snapshots[first], snapshots[last]
    if start["metrics_map_id"] != end["metrics_map_id"]:
        raise ValueError(f"{first}/{last}: counter generations differ")
    seconds = (datetime.fromisoformat(end["time"]) - datetime.fromisoformat(start["time"])).total_seconds()
    metrics = {key: end["metrics"][key] - value for key, value in start["metrics"].items()}
    shared = start["collector"].keys() & end["collector"].keys()
    windows.append({
        "first": first, "last": last, "map_id": start["metrics_map_id"],
        "start_time": start["time"], "end_time": end["time"], "seconds": seconds,
        "metric_deltas": metrics,
        "frames_per_attempt": (metrics["metricID_UnwindNativeFrames"] / metrics["metricID_UnwindNativeAttempts"]
                               if metrics["metricID_UnwindNativeAttempts"] else None),
        "collector_deltas": {key: end["collector"][key] - start["collector"][key] for key in shared},
        "collector_only_in_start": sorted(start["collector"].keys() - end["collector"].keys()),
        "collector_only_in_end": sorted(end["collector"].keys() - start["collector"].keys()),
    })
print(json.dumps(windows, indent=2))
