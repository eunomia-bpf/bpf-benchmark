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
    args = parser.parse_args()
    manifest = json.loads(args.input.read_text())
    for obj in manifest['objects']:
        obj['kernel_helper_context'] = True
        if args.kernel_data_layout:
            obj['kernel_data_layout'] = True
    with args.output.open('x') as output:
        json.dump(manifest, output, indent=2)
        output.write('\n')


if __name__ == '__main__':
    main()
