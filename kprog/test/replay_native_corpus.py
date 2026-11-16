"""Replay canonical entries against retained real loader plans on the host."""
import argparse
import io
import json
from pathlib import Path
import subprocess
import tarfile
from elftools.elf.elffile import ELFFile


def request_plans(request, origin):
    names = set(request.getnames())
    if 'request/kernel.entry' not in names:
        return
    symbol = request.extractfile('request/kernel.entry').read().decode()
    facts = json.load(request.extractfile('request/kernel.facts.json'))
    with request.extractfile('request/kernel.native.o') as stream:
        source_files = elf_source_files(ELFFile(io.BytesIO(stream.read())))
    for plan in sorted(name for name in names if name.endswith('.link-plan.json')):
        yield symbol, dict(**origin, plan=plan, context=facts,
                           source_files=source_files), request.extractfile(plan).read()


def elf_source_files(elf):
    return sorted(symbol.name for symbol in elf.get_section_by_name('.symtab').iter_symbols()
                  if symbol['st_info']['type'] == 'STT_FILE')


def captured_requests(source):
    if isinstance(source, dict):
        yield source['symbol'], dict(plan=source['plan'], source='retained loader plan'), Path(source['plan']).read_bytes()
        return
    with tarfile.open(source) as service:
        if 'request/kernel.entry' in service.getnames():
            yield from request_plans(service, dict(archive=source))
            return
        for member in service:
            if not member.isfile() or not member.name.endswith(('.success.tar.gz', '.failure.tar.gz')):
                continue
            with tarfile.open(fileobj=io.BytesIO(service.extractfile(member).read())) as request:
                yield from request_plans(request, dict(archive=source, request=member.name))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--payload', type=Path, required=True)
    parser.add_argument('--captures', type=Path, required=True)
    parser.add_argument('--linker', type=Path, required=True)
    parser.add_argument('--context-compiler', type=Path, required=True)
    parser.add_argument('--kernel-btf', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--apps', nargs='+')
    parser.add_argument('--inventory', action='store_true')
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    captures = json.loads(args.captures.read_text())
    rows = []
    failures = 0
    for manifest in sorted(args.payload.glob('*/manifest.json')):
        app = manifest.parent.name
        if args.apps and app not in args.apps:
            continue
        contexts = {}
        for archive in captures.get(app, []):
            for symbol, record, data in captured_requests(archive):
                # Keep every recorded request: same-name bodies and map shapes
                # are not collapsed into an invented representative plan.
                contexts.setdefault(symbol, []).append((record, data))
        entries = json.loads(manifest.read_text())['objects']
        seen = set()
        expanded = []
        for entry in entries:
            native = manifest.parent / entry['native_object']
            if 'symbol' in entry:
                expanded.append((entry, entry['symbol']))
                continue
            with native.open('rb') as stream:
                elf = ELFFile(stream)
                symbols = [s.name for s in elf.get_section_by_name('.symtab').iter_symbols()
                           if s['st_info']['type']=='STT_FUNC' and s['st_shndx']!='SHN_UNDEF'
                           and s.name[:15]==entry['program']]
            # A truncated program name can select several full ELF symbols.
            # Replay all candidates rather than choosing one by name order.
            expanded.extend((entry, symbol) for symbol in symbols)
            if not symbols:
                raise ValueError(f'Manifest entry has no native symbol: {native} {entry}')
        for entry, symbol in expanded:
            key = (entry['native_object'], symbol)
            if key in seen:
                continue
            seen.add(key)
            index = len(rows)
            native = manifest.parent / key[0]
            with native.open('rb') as stream:
                elf = ELFFile(stream)
                function, = elf.get_section_by_name('.symtab').get_symbol_by_name(key[1])
                section = elf.get_section(function['st_shndx']).name
                source_files = elf_source_files(elf)
            row = dict(app=app, native=str(native), symbol=key[1],
                       captured_contexts=[record for record, _ in contexts.get(key[1], [])],
                       source_files=source_files, section=section, context_lto=None,
                       proof=None, kernel_replays=[], different_source_captures=[])
            rows.append(row)
            if not args.inventory:
                directory = args.output / str(index)
                directory.mkdir(exist_ok=True)
                proof = directory / 'entry.proof.o'
                selected = native
                if section.startswith('perf_event'):
                    selected = directory / 'physical.native.o'
                    command = [str(args.context_compiler), str(native), '--symbol', key[1],
                               '--kernel-btf', str(args.kernel_btf), '-o', str(selected)]
                    result = subprocess.run(command, capture_output=True, text=True)
                    row['context_lto'] = dict(command=command, returncode=result.returncode,
                                             stdout=result.stdout, stderr=result.stderr)
                    failures += result.returncode != 0
                if row['context_lto'] is None or row['context_lto']['returncode'] == 0:
                    command = [str(args.linker), '--input', str(selected), '--symbol', key[1],
                               '--mode', 'proof', '--preserve-entry-abi', '--output', str(proof)]
                    result = subprocess.run(command, capture_output=True, text=True)
                    row['proof'] = dict(command=command, returncode=result.returncode,
                                        stdout=result.stdout, stderr=result.stderr)
                    failures += result.returncode != 0
                    if result.returncode == 0:
                        for number, (record, data) in enumerate(contexts.get(key[1], [])):
                            # Cilium reuses full function names across distinct
                            # upstream translation units with different maps.
                            # Keep their facts visible, without pretending they
                            # describe this candidate object.
                            if (record.get('source_files') and source_files and
                                    record['source_files'] != source_files):
                                row['different_source_captures'].append(record)
                                continue
                            plan = directory / f'{number}.link-plan.json'
                            plan.write_bytes(data)
                            command = [str(args.linker), '--input', str(proof), '--symbol', key[1],
                                       '--mode', 'kernel', '--link-plan', str(plan),
                                       '--output', str(directory / f'{number}.blob'),
                                       '--output-relocs', str(directory / f'{number}.relocs'),
                                       '--output-map-patches', str(directory / f'{number}.maps'),
                                       '--output-abi', str(directory / f'{number}.abi')]
                            result = subprocess.run(command, capture_output=True, text=True)
                            row['kernel_replays'].append(dict(capture=record, command=command,
                                returncode=result.returncode, stdout=result.stdout, stderr=result.stderr))
                            failures += result.returncode != 0
            (args.output / 'report.json').write_text(json.dumps(dict(
                scope='Host proof extraction for every selected canonical entry; kernel-mode emission for each retained same-symbol load plan. No kernel execution. Same-name plans retain their separate original contexts; missing captures are listed, not replaced by synthetic addresses.',
                inventory_only=args.inventory, linker=str(args.linker), captures=str(args.captures),
                failures=failures, entries=rows), indent=2)+'\n')
        print(json.dumps(dict(app=app, entries=len(seen),
            entries_with_captured_plan=sum(bool(r['captured_contexts']) for r in rows if r['app']==app))), flush=True)
    return bool(failures)


if __name__ == '__main__':
    raise SystemExit(main())
