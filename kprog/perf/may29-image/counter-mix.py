#!/usr/bin/env python3
"""Normalize retained OTel window counters without equating sampled inputs.

Input is counter-windows.py output. Frame yield uses that unwinder's own
attempts; dispatch mix uses native attempts. A zero denominator remains null.
Other counters keep their source names and are not all labelled as errors.
"""
import argparse
import json
from pathlib import Path

FAMILIES = ('Native', 'Perl', 'Python', 'PHP', 'Ruby', 'V8', 'Hotspot', 'Dotnet')


def ratio(value, denominator):
    return value / denominator if denominator else None


def summarize(window):
    metrics = window['metric_deltas']
    native = metrics['metricID_UnwindNativeAttempts']
    result = {key: window[key] for key in
              ('first', 'last', 'map_id', 'start_time', 'end_time', 'seconds')}
    result['native_attempts'] = native
    result['native_attempts_per_second'] = ratio(native, window['seconds'])
    result['interpreter_dispatches'] = metrics['metricID_UnwindCallInterpreter']
    result['interpreter_dispatches_per_native_attempt'] = ratio(
        result['interpreter_dispatches'], native)
    result['families'] = {}
    for family in FAMILIES:
        prefix = 'metricID_Unwind' + family
        attempts_key, frames_key = prefix + 'Attempts', prefix + 'Frames'
        attempts, frames = metrics[attempts_key], metrics[frames_key]
        result['families'][family] = dict(attempts=attempts, frames=frames,
            frames_per_attempt=ratio(frames, attempts),
            attempts_per_native_attempt=ratio(attempts, native),
            other_counters={key: dict(delta=value, per_attempt=ratio(value, attempts))
                            for key, value in metrics.items()
                            if key.startswith(prefix) and key not in (attempts_key, frames_key)})
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('windows', type=Path)
    args = parser.parse_args()
    print(json.dumps([summarize(window) for window in json.loads(args.windows.read_text())], indent=2))


if __name__ == '__main__':
    main()
