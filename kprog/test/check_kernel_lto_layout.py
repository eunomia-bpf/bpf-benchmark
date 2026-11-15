"""Compare the normal loader's BTF facts with the retained sole-kernel facts."""
import argparse
import hashlib
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
    groups, historical, commands = [], [], []
    for name in ['array', 'hash', 'lpm', 'probe_read']:
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
        groups.append(dict(group=name, expected=expected, actual=actual[name],
                           equal=actual[name] == expected))
        old = args.historical_reference / ('runtime-' + name.replace('_', '-') + '-layout.json')
        previous = json.loads(old.read_text())
        historical.append(dict(group=name, reference=str(old), previous=previous,
                               different_fields=[k for k in actual[name] if actual[name][k] != previous[k]]))
    with (args.kernel / 'vmlinux').open('rb') as stream:
        kernel_btf_sha256 = hashlib.sha256(ELFFile(stream).get_section_by_name('.BTF').data()).hexdigest()
    live_btf_sha256 = hashlib.sha256((args.boot_capture/'kernel.btf').read_bytes()).hexdigest()
    result = dict(layout=actual, groups=groups, kernel=str(args.kernel), historical=historical,
                  kernel_btf_sha256=kernel_btf_sha256,
                  live_btf_sha256=live_btf_sha256,
                  kallsyms_sha256=hashlib.sha256((args.boot_capture/'kernel.kallsyms').read_bytes()).hexdigest(),
                  fields=sum(len(group['actual']) for group in groups),
                  scope='Live boot BTF/kallsyms against canonical boot ELF and independent C field resolver; no application execution')
    (args.output / 'result.json').write_text(json.dumps(result, indent=2) + '\n')
    if kernel_btf_sha256 != live_btf_sha256:
        raise ValueError('Canonical ELF BTF differs from the running boot kernel')
    if not all(group['equal'] for group in groups):
        raise ValueError('Loader LTO facts differ from independent live-boot facts; inspect result.json')
    print(json.dumps(dict(groups=len(groups), fields=result['fields'], equal=True)))


if __name__ == '__main__':
    main()
