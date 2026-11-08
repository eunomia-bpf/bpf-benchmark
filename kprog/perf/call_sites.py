#!/usr/bin/env python3
"""Call sites per program, from the link plans the native link produced.

Task 3 splits run time by kind of call site.  The plan is the authority for
which sites a program has: `helpers` are helper calls, `lookup_sites` are
map lookups (hash, per-cpu hash, LRU, or a call to a map-producing helper),
`update_sites` are map updates and `tail_call_maps` are tail-call targets.
Everything else in the body is computation.

The plan also carries synthetic helpers the linker adds for its own
bookkeeping; those are prefixed `__native_x86` and are not program calls.
"""

import argparse
import collections
import json
import pathlib
import sys

SYNTHETIC = "__native_x86"


def inventory(plan):
    """Call-site counts for one program's link plan."""
    helpers = [h["name"] for h in plan.get("helpers") or []
               if not h["name"].startswith(SYNTHETIC)]
    lookups = plan.get("lookup_sites") or []
    updates = plan.get("update_sites") or []
    returns = collections.Counter(item.get("kind") for item in lookups)
    return dict(
        helper_calls=len(helpers),
        helper_names=sorted(helpers),
        map_lookups=len(lookups),
        lookup_kinds=dict(returns),
        map_updates=len(updates),
        tail_call_maps=len(plan.get("tail_call_maps") or []),
        maps=len(plan.get("maps") or []),
    )


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--cache", required=True,
                    help="directory tree holding *.link-plan.json")
    ap.add_argument("--out", default="")
    args = ap.parse_args(argv[1:])

    rows = []
    for path in sorted(pathlib.Path(args.cache).rglob("*.link-plan.json")):
        try:
            plan = json.loads(path.read_text())
        except ValueError:
            continue
        rows.append(dict(plan=path.name, **inventory(plan)))
    if not rows:
        print("no link plan under " + args.cache, file=sys.stderr)
        return 1
    payload = dict(plans=len(rows), rows=rows)
    text = json.dumps(payload, indent=1)
    if args.out:
        pathlib.Path(args.out).write_text(text + "\n")
    print(text)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))