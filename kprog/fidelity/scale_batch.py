"""Resume production scale compilation and verification, retaining every stage."""
import argparse
from datetime import datetime, timezone
import json
from pathlib import Path
import subprocess
import time

ROOT = Path(__file__).resolve().parents[2]


def main(args):
    args.out.mkdir(parents=True, exist_ok=True)
    common = ['make', '-C', str(ROOT/'kprog/fidelity'),
              'SCALE_BUILD='+str(args.build), 'SCALE_RECORDS='+str(args.records)]
    jobs = [
        ('subset', [*common, 'scale-kvm', 'SCALE_OUT='+str(args.out/'subset-kernel')]),
        ('compile', [*common, 'scale-build', 'SCALE_SIZES=10000 100000', 'SCALE_ARGS=--stock-pipeline']),
        ('kernel', [*common, 'scale-kvm', 'SCALE_OUT='+str(args.out/'kernel')]),
    ]
    if args.dry_run:
        print(json.dumps(dict(wait_pid=args.wait_pid, jobs=jobs), indent=2))
        return 0
    state = dict(started=datetime.now(timezone.utc).isoformat(), wait_pid=args.wait_pid,
                 scope='Existing 100/1K subset followed by production 10K/100K compile and final kernel batch',
                 stages=[])

    def save():
        (args.out/'state.json').write_text(json.dumps(state, indent=2)+'\n')

    save()
    if args.wait_pid:
        subprocess.run(['tail', '--pid='+str(args.wait_pid), '-f', '/dev/null'], check=True)
    for name, command in jobs:
        stage = dict(name=name, command=command, started=datetime.now(timezone.utc).isoformat())
        state['stages'].append(stage)
        save()
        start = time.monotonic()
        with (args.out/(name+'.log')).open('w') as log:
            result = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT)
        stage.update(returncode=result.returncode, wall_seconds=time.monotonic()-start,
                     finished=datetime.now(timezone.utc).isoformat())
        save()
    state.update(finished=datetime.now(timezone.utc).isoformat(),
                 returncode=int(any(stage['returncode'] != 0 for stage in state['stages'])))
    save()
    return state['returncode']


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'records', 'out'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--wait-pid', type=int, default=0)
    parser.add_argument('--dry-run', action='store_true')
    raise SystemExit(main(parser.parse_args()))
