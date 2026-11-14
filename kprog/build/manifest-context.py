#!/usr/bin/env python3
"""Select original-program helper resolution in a separate runtime manifest."""
import argparse
import json
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--kernel-data-layout', action='store_true')
    parser.add_argument('--source-bpf-object', type=Path,
                        help='Original BPF ELF; relative paths are relative to the output manifest')
    args = parser.parse_args()
    if args.source_bpf_object:
        source = args.source_bpf_object
        if not source.is_absolute():
            source = args.output.parent / source
        source.resolve(strict=True)
    manifest = json.loads(args.input.read_text())
    for obj in manifest['objects']:
        obj['kernel_helper_context'] = True
        if args.source_bpf_object:
            obj['source_bpf_object'] = str(args.source_bpf_object)
        if args.kernel_data_layout:
            obj['kernel_data_layout'] = True
    with args.output.open('x') as output:
        json.dump(manifest, output, indent=2)
        output.write('\n')


if __name__ == '__main__':
    main()
