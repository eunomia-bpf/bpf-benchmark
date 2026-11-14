#!/usr/bin/env python3
"""Package explicit upstream compiler batches without changing the image default."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--template', type=Path, required=True)
    parser.add_argument('--batch', nargs=2, action='append', required=True, metavar=('REPORT', 'BUILD'))
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--receipt', type=Path, required=True)
    args = parser.parse_args()
    selected = {}
    batches = []
    # Later explicit batches replace earlier entries, including failures. An
    # unsuccessful final compile remains an error, never an older fallback.
    for report_name, build_name in args.batch:
        report = Path(report_name)
        data = json.loads(report.read_text())
        batches.append(dict(path=str(report), sha256=digest(report), kernel_btf_sha256=data['kernel_btf_sha256']))
        for row in data['rows']:
            selected[row['unit']] = dict(row=row, build=Path(build_name) / row['unit'])
    manifest = json.loads(args.template.read_text())
    units = sorted({Path(row['native_object']).name.removesuffix('.native.o') for row in manifest['objects']})
    args.output.mkdir(parents=True, exist_ok=True)
    artifacts = []
    for unit in units:
        chosen = selected[unit]
        if chosen['row']['returncode'] != 0:
            raise ValueError('final compiler batch failed: ' + unit)
        record = dict(unit=unit, source=chosen['row']['source'], source_sha256=chosen['row']['source_sha256'], files=[])
        for suffix, destination in [('.native.o', '.native.o'), ('.direct.bpf.o', '.original.bpf.o')]:
            source = chosen['build'] / (unit + suffix)
            target = args.output / (unit + destination)
            with target.open('xb') as output:
                output.write(source.read_bytes())
            if digest(source) != digest(target):
                raise ValueError('packaged bytes differ: ' + str(target))
            record['files'].append(dict(source=str(source), path=str(target), bytes=target.stat().st_size, sha256=digest(target)))
        artifacts.append(record)
    for row in manifest['objects']:
        unit = Path(row['native_object']).name.removesuffix('.native.o')
        row.update(native_object=unit + '.native.o', kernel_helper_context=True,
                   kernel_data_layout=True, kernel_kfunc_context=True,
                   kernel_kfunc_btf=unit + '.original.bpf.o')
    output_manifest = args.output / 'manifest.json'
    with output_manifest.open('x') as output:
        json.dump(manifest, output, indent=2)
        output.write('\n')
    receipt = dict(recorded_at=datetime.now(timezone.utc).isoformat(),
                   template=dict(path=str(args.template), sha256=digest(args.template)), batches=batches,
                   manifest=dict(path=str(output_manifest), sha256=digest(output_manifest), rows=len(manifest['objects'])),
                   artifacts=artifacts,
                   scope='Explicit candidate bundle only. Default image/manifest unchanged; no kernel submission, installation or application equivalence claim.')
    with args.receipt.open('x') as output:
        json.dump(receipt, output, indent=2)
        output.write('\n')


if __name__ == '__main__':
    main()
