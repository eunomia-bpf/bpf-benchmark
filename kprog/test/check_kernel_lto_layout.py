"""Compare the normal loader's BTF facts with the retained sole-kernel facts."""
import argparse
import json
import subprocess
from pathlib import Path

from elftools.elf.elffile import ELFFile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--layout', type=Path, required=True)
    parser.add_argument('--kernel', type=Path, required=True)
    parser.add_argument('--boot-capture', type=Path, required=True)
    parser.add_argument('--reference-compiler', type=Path, required=True)
    parser.add_argument('--historical-reference', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    actual = json.loads(args.layout.read_text())
    with (args.kernel / 'vmlinux').open('rb') as stream:
        canonical_btf = args.output / 'canonical.btf'
        canonical_btf.write_bytes(ELFFile(stream).get_section_by_name('.BTF').data())
    groups, historical, commands = [], [], []
    for name in ['array', 'lpm', 'probe_read']:
        command = [str(args.reference_compiler), str(args.boot_capture/'kernel.btf')]
        if name == 'probe_read':
            command += ['--probe-read', str(args.boot_capture/'kernel.kallsyms')]
        elif name != 'array':
            command += ['--'+name]
        completed = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=completed.returncode,
                             stdout=completed.stdout, stderr=completed.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        completed.check_returncode()
        expected = json.loads(completed.stdout)
        command = [command[0], str(canonical_btf), *command[2:]]
        canonical = subprocess.run(command, text=True, capture_output=True)
        commands.append(dict(command=command, returncode=canonical.returncode,
                             stdout=canonical.stdout, stderr=canonical.stderr))
        (args.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        canonical.check_returncode()
        canonical_expected = json.loads(canonical.stdout)
        groups.append(dict(group=name, expected=expected, actual=actual[name],
                           canonical_expected=canonical_expected,
                           equal=actual[name] == expected == canonical_expected))
        old = args.historical_reference / ('runtime-' + name.replace('_', '-') + '-layout.json')
        previous = json.loads(old.read_text())
        historical.append(dict(group=name, reference=str(old), previous=previous,
                               different_fields=[k for k in actual[name] if actual[name][k] != previous[k]]))
    result = dict(layout=actual, groups=groups, kernel=str(args.kernel), historical=historical,
                  fields=sum(len(group['actual']) for group in groups),
                  scope='Live boot and canonical ELF BTF fields resolved independently; BTF type IDs/order may differ; no application execution')
    (args.output / 'result.json').write_text(json.dumps(result, indent=2) + '\n')
    if not all(group['equal'] for group in groups):
        raise ValueError('Loader LTO facts differ from independent live-boot facts; inspect result.json')
    print(json.dumps(dict(groups=len(groups), fields=result['fields'], equal=True)))


if __name__ == '__main__':
    main()
