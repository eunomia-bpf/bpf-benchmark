"""Collect completed LLVM compiler diagnostics and the reported pass timings."""
import argparse
import csv
import json
from pathlib import Path
import shutil


def collect(raw, output):
    optimization = raw / 'optimization'
    result = json.loads((optimization / 'result.json').read_text())
    log = (optimization / 'stderr').read_text()
    table = log.split('Pass execution timing report', 1)[1].split(
        'Analysis execution timing report', 1)[0]
    rows = []
    for line in table.splitlines():
        fields = line.split()
        if len(fields) < 13 or not fields[0][0].isdigit():
            continue
        # LLVM prints four time columns, each followed by '( NN.N%)'.
        name = ' '.join(fields[12:])
        if name == 'Total':
            continue
        rows.append(dict(pass_name=name, user_seconds=float(fields[0]),
                         system_seconds=float(fields[3]),
                         cpu_seconds=float(fields[6]), wall_seconds=float(fields[9])))
    if not rows:
        raise ValueError('LLVM pass timing table is empty')
    output.mkdir(parents=True, exist_ok=True)
    with (output / 'passes.csv').open('w', newline='') as destination:
        writer = csv.DictWriter(destination, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    (output / 'optimization.json').write_text(json.dumps(result, indent=2) + '\n')
    shutil.copyfile(optimization / 'stderr', output / 'optimization.log')
    print(json.dumps(dict(exit=result['exit'], wall_seconds=result['wall_seconds'],
                          top_passes=rows[:4]), indent=2))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--raw', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    collect(args.raw, args.output)
