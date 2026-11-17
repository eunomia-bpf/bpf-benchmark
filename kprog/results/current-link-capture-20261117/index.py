#!/usr/bin/env python3
"""Record the actual new paired captures from one diagnostic app startup."""
import argparse
import json
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--before', type=Path, required=True)
parser.add_argument('--app', required=True)
parser.add_argument('--returncode', type=int, required=True)
parser.add_argument('--output', type=Path, required=True)
args = parser.parse_args()
captures = Path('/workspaces/repository/corpus/results/current-link-capture-20261117/captures')
before = set(json.loads(args.before.read_text()))
rows = []
errors = []
other_invocations = []
for folder in sorted(captures.iterdir()):
    if not folder.is_dir() or folder.name in before:
        continue
    try:
        adapter = json.loads((folder / 'adapter.json').read_text())
        argv = adapter['argv']
        if adapter['mode'] != 'kernel':
            other_invocations.append(dict(capture=str(folder), **adapter))
            continue
        plan_path = folder / 'link-plan.json'
        proof_path = folder / 'entry.proof.o'
        plan = json.loads(plan_path.read_text())
        proof_size = proof_path.stat().st_size
        row = dict(app=args.app, symbol=argv[argv.index('--symbol')+1],
            proof=str(proof_path), plan=str(plan_path), capture=str(folder),
            proof_bytes=proof_size, linker_returncode=adapter['returncode'],
            kernel_layout_sections=sorted(plan.get('kernel_layout', {})),
            probe_read_fields=sorted(plan.get('kernel_layout', {}).get('probe_read', {})))
        rows.append(row)
    except (OSError, ValueError, KeyError, TypeError) as error:
        errors.append(dict(capture=str(folder), error=str(error)))
result = dict(app=args.app, guest_returncode=args.returncode, captures=rows, capture_errors=errors,
    other_invocations=other_invocations,
    scope='Actual new kernel-link requests, including linker failures, archived by the capture adapter. '
          'No helper/layout facts are added. Missing/failed loads remain in the guest and shim logs; '
          'an empty capture list does not imply no native work. Functional capture, not official timing.')
args.output.write_text(json.dumps(result, indent=2)+'\n')
print(f'{args.app}: guest rc={args.returncode}, paired captures={len(rows)}, capture errors={len(errors)}')
raise SystemExit(int(bool(errors)))
