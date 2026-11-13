#!/usr/bin/env python3
"""Replay captured native-link plans offline, retaining every success and error."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import tarfile
from elftools.elf.elffile import ELFFile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('capture', 'linker', 'helper-names', 'output'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir()
    cache = args.output / 'native-link-cache'
    with tarfile.open(args.capture) as source:
        for member in source.getmembers():
            if Path(member.name).parts[0] == 'native-link-cache':
                source.extract(member, args.output, filter='data')
    canonical = set(json.loads(args.helper_names.read_text()).values())
    rows = []
    for plan in sorted(cache.glob('*.link-plan.json')):
        stem = plan.name.removesuffix('.link-plan.json')
        proof = cache / (stem + '.proof.o')
        if not proof.exists():
            proof = cache / (stem.split('.tmp.')[0] + '.proof.o')
        with proof.open('rb') as stream:
            elf = ELFFile(stream)
            symbols = list(elf.get_section_by_name('.symtab').iter_symbols())
            entries = [s.name for s in symbols if s['st_info']['type'] == 'STT_FUNC' and s['st_value'] == 0]
            needed = sorted({s.name for s in symbols if s['st_shndx'] == 'SHN_UNDEF' and s.name in canonical})
        if len(entries) != 1:
            raise ValueError('ambiguous proof entry: ' + str(proof))
        helpers = {h['name']: h['addr'] for h in json.loads(plan.read_text())['helpers']}
        result_dir = args.output / stem
        result_dir.mkdir()
        command = [str(args.linker), '--mode', 'kernel', '--input', str(proof), '--symbol', entries[0],
                   '--link-plan', str(plan), '--output', str(result_dir / 'blob.bin'),
                   '--output-relocs', str(result_dir / 'relocs.bin'),
                   '--output-map-patches', str(result_dir / 'maps.tsv'), '--output-abi', str(result_dir / 'abi.tsv')]
        result = subprocess.run(command, capture_output=True, text=True)
        (result_dir / 'stdout').write_text(result.stdout)
        (result_dir / 'stderr').write_text(result.stderr)
        rows.append(dict(symbol=entries[0], proof=str(proof), plan=str(plan), command=command,
                         returncode=result.returncode, helpers_required=needed,
                         canonical_helpers_without_plan_entry=[h for h in needed if h not in helpers],
                         linker_stderr=result.stderr,
                         plan_helper_count=len(helpers)))
    if not rows:
        raise ValueError('capture has no native link plans')
    (args.output / 'report.json').write_text(json.dumps(dict(
        capture=str(args.capture), capture_sha256=hashlib.sha256(args.capture.read_bytes()).hexdigest(),
        linker=str(args.linker), rows=rows,
        scope='Offline kernel-mode generation with recorded real plans; no kernel submission or native execution.',
        interpretation='Plan absence is raw evidence, not a failure classification: the linker consumes bpf_tail_call by inlining, without a helper address. Return status and stderr record actual errors.'), indent=2) + '\n')


if __name__ == '__main__':
    main()
