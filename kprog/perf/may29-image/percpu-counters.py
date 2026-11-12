#!/usr/bin/env python3
"""Read an application's own per-CPU counters out of a bpftool map dump.

The shim's capture skips any map over 64 KiB (bpfopt/shim/shim_snapshot.h:583), and
the maps that answer "did both arms do the same work" are exactly the big per-CPU
ones: OTel's `metrics` map is 84597 bytes across 64 CPUs, so every capture records
`{"skipped":true,"reason":"size_limit"}` and the counters never reach the artifacts.

This reads a dump taken in the guest instead:

    bpftool map dump id <id> --json > metrics.json

and sums each key's per-CPU values into a total, which is what a work comparison
needs. A percpu array's dump lists one entry per key with one value per CPU, so the
total for a key is the sum across CPUs; the per-CPU split is kept as well because a
single busy CPU is a different situation from a busy machine.

Usage: percpu-counters.py <dump.json> [<dump.json>...]

Prints each key's total and, when the dump carries them, the per-CPU values.
"""
import json
import pathlib
import sys


def entries(dump: object) -> list[dict]:
    """The key/value entries of a bpftool map dump, whatever its outer shape."""
    if isinstance(dump, list):
        return [e for e in dump if isinstance(e, dict)]
    if isinstance(dump, dict):
        for key in ("entries", "map", "values"):
            if isinstance(dump.get(key), list):
                return [e for e in dump[key] if isinstance(e, dict)]
        # A single-entry dump is sometimes the entry itself.
        if "key" in dump or "value" in dump:
            return [dump]
    return []


def _bytes_to_int(parts: list) -> int | None:
    """One little-endian value from bpftool's byte list, hex or decimal."""
    if not parts:
        return None
    total = 0
    for index, part in enumerate(parts):
        if isinstance(part, str):
            number = int(part, 16) if part.startswith("0x") else int(part)
        elif isinstance(part, int):
            number = part
        else:
            return None
        total |= (number & 0xFF) << (8 * index)
    return total


def per_cpu_values(entry: dict) -> list[int] | None:
    """The per-CPU values of one entry, in the shape bpftool actually emits.

    bpftool prints a percpu map as one entry per key with a `values` list of
    {"cpu": n, "value": ["0x..", ...]} per CPU, the value bytes least
    significant first. A dump that already carries plain integers is accepted
    too, so a flattened capture reads the same way.
    """
    values = entry.get("values")
    if isinstance(values, list):
        if all(isinstance(v, int) for v in values):
            return values
        out: list[int] = []
        for item in values:
            if isinstance(item, dict):
                number = _bytes_to_int(item.get("value") or [])
                if number is None:
                    return None
                out.append(number)
            else:
                return None
        return out or None
    value = entry.get("value")
    if isinstance(value, list) and all(isinstance(v, int) for v in value):
        return value
    if isinstance(value, list):
        single = _bytes_to_int(value)
        return [single] if single is not None else None
    return None


def main() -> None:
    paths = [pathlib.Path(arg) for arg in sys.argv[1:]]
    if not paths:
        sys.exit("usage: percpu-counters.py <dump.json> [...]")
    for path in paths:
        text = path.read_text()
        try:
            dump = json.loads(text)
        except json.JSONDecodeError:
            # A dump taken with the exit code appended to the same file; take the
            # JSON that precedes it.
            end = text.rfind("]")
            dump = json.loads(text[: end + 1]) if end > 0 else []
        rows = []
        for entry in entries(dump):
            values = per_cpu_values(entry)
            if values is None:
                continue
            key = entry.get("key", "?")
            if isinstance(key, list):
                number = _bytes_to_int(key)
                key = number if number is not None else key
            rows.append((key, sum(values), values))
        if not rows:
            print(f"{path.name}: no per-CPU values (shape: "
                  f"{type(dump).__name__}) -- is this a bpftool dump?")
            continue
        print(f"== {path.name}: {len(rows)} keys")
        total = sum(row[1] for row in rows)
        for key, summed, values in sorted(rows, key=lambda r: -r[1])[:16]:
            busy = sum(1 for v in values if v)
            print(f"   key {str(key):>4}  total {summed:14}  "
                  f"cpus {busy:3}/{len(values)}  max {max(values) if values else 0}")
        print(f"   {'TOTAL':>8} {total:14}")


if __name__ == "__main__":
    main()