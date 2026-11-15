"""Compare the normal loader's BTF facts with the retained sole-kernel facts."""
import argparse
import hashlib
import json
from pathlib import Path

from elftools.elf.elffile import ELFFile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--layout', type=Path, required=True)
    parser.add_argument('--kernel', type=Path, required=True)
    parser.add_argument('--reference', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    actual = json.loads(args.layout.read_text())
    groups = []
    for name in ['array', 'hash', 'lpm', 'probe_read']:
        reference = args.reference / ('runtime-' + name.replace('_', '-') + '-layout.json')
        expected = json.loads(reference.read_text())
        groups.append(dict(group=name, expected=expected, actual=actual[name],
                           equal=actual[name] == expected, reference=str(reference)))
    with (args.kernel / 'vmlinux').open('rb') as stream:
        kernel_btf_sha256 = hashlib.sha256(ELFFile(stream).get_section_by_name('.BTF').data()).hexdigest()
    result = dict(layout=actual, groups=groups, kernel=str(args.kernel),
                  kernel_btf_sha256=kernel_btf_sha256,
                  system_map_sha256=hashlib.sha256((args.kernel / 'System.map').read_bytes()).hexdigest(),
                  fields=sum(len(group['actual']) for group in groups),
                  scope='One target-kernel BTF/System.map layout comparison; no VM or application execution')
    (args.output / 'result.json').write_text(json.dumps(result, indent=2) + '\n')
    if not all(group['equal'] for group in groups):
        raise ValueError('Loader LTO facts differ from retained sole-kernel facts; inspect result.json')
    print(json.dumps(dict(groups=len(groups), fields=result['fields'], equal=True)))


if __name__ == '__main__':
    main()
