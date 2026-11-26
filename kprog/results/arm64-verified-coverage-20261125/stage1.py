"""Arm64 verified-path coverage: B generation and aarch64 proof, per object.

Every arm64 native object the manifests name is turned into B, lowered by the
checked tools for aarch64, and linked to a proof object. Objects run in a
process pool, one job per manifest entry, and a finished object is skipped, so
an interrupted sweep resumes where it stopped. The stock verifier's verdict on
each proof is what a guest pass adds.

Manifest entries without a single entry symbol are the dedupe groups of
vendor/bpf/write_native_manifest.py: one 16-character program name covers
several text symbols, and only the kernel's own request names which one, so
they are counted and left for the guest.
"""
import argparse
import ast
import json
import os
from pathlib import Path
import shutil
import sys
import traceback
from concurrent.futures import ProcessPoolExecutor

ROOT = Path('/workspaces/repository')
sys.path.insert(0, str(ROOT / 'kprog'))
sys.path.insert(0, str(ROOT / 'kprog/arm64'))

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--app', action='append', default=[])
parser.add_argument('--out', type=Path, required=True)
parser.add_argument('--root', type=Path,
                    default=ROOT / 'vendor/build/native-bpf/arm64/7.0.0-rc2+/native')
parser.add_argument('--compiler', type=Path, default=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir'))
parser.add_argument('--context-compiler', type=Path, default=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/context-lower'))
parser.add_argument('--native-link', type=Path,
                    default=ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link')
parser.add_argument('--jobs', type=int, default=12)
args = parser.parse_args()


def section_maps(object_path, symbol):
    """Map names from the relocation table of the section that defines symbol."""
    from elftools.elf.elffile import ELFFile
    with Path(object_path).open('rb') as stream:
        image = ELFFile(stream)
        symbols = image.get_section_by_name('.symtab')
        defined = [entry for entry in symbols.iter_symbols()
                   if entry.name == symbol and entry['st_size']]
        if not defined:
            return []
        holder = image.get_section(defined[0]['st_shndx']).name
        for section in image.iter_sections():
            if section['sh_type'] not in ('SHT_RELA', 'SHT_REL'):
                continue
            stem = section.name[4:] if section.name.startswith('.rela') else section.name[4:]
            if stem != holder:
                continue
            names = set()
            table = image.get_section(section['sh_link'])
            for relocation in section.iter_relocations():
                name = table.get_symbol(relocation.entry['r_info_sym']).name
                if name and not name.startswith('bpf_') and name not in ('memcpy', 'memset'):
                    names.add(name)
            return sorted(names)
        return []


def declare(names):
    return [dict(name=name, map_type=2, key_size=4, value_size=4, max_entries=1,
                 map_flags=0, value_offset=None) for name in sorted(names)]


def specialize_with_maps(worker, native, symbol, names, job, native_link):
    """Generate B, adding the maps the generator reports as still missing.

    The generator walks the reachable native instructions itself, so its
    reported gap is exactly the reachable map set; a relocation table only
    covers the section that holds the entry. A retry writes into a fresh
    directory, so a re-run of an unfinished object starts from a clean job.
    """
    for attempt in range(8):
        metadata = dict(version=1, prog_type=1, section='kprobe/trusted',
                        maps=declare(names), kernel_btf='/sys/kernel/btf/vmlinux')
        target = job / 'generated' if attempt == 0 else job / f'generated-{attempt}'
        shutil.rmtree(target, ignore_errors=True)
        try:
            return worker.specialize(native, symbol, metadata, target, native_link)
        except ValueError as error:
            marker = 'native relocation lacks an original map declaration: '
            if marker not in str(error):
                raise
            missing = set(ast.literal_eval(str(error).split(marker, 1)[1]))
            if missing <= set(names):
                raise
            names = set(names) | missing
    raise RuntimeError('map declarations did not converge')


def covered(job):
    return any(job.glob('generated*/checked-simulator.native.o'))


def run_entry(item):
    """One manifest entry: generate B, then the aarch64 checked leg."""
    import trusted_specializer as worker
    app, index, entry, job, native_path, compiler, context_compiler, native_link = item
    symbol = entry['symbol']
    row = dict(app=app, index=index, symbol=symbol, verdict='')
    try:
        artifacts = specialize_with_maps(worker, Path(native_path).read_bytes(), symbol,
                                         set(section_maps(native_path, symbol)),
                                         Path(job), Path(native_link))
    except Exception as error:
        row.update(verdict='generation', error=str(error), traceback=traceback.format_exc())
        (Path(job) / 'error.json').write_text(json.dumps(row, indent=2) + '\n')
        return row
    try:
        worker.compile_checked_simulator(artifacts, Path(native_link), Path(compiler),
                                         context_compiler=Path(context_compiler))
        row['verdict'] = 'proof'
    except Exception as error:
        row.update(verdict='checked', error=str(error), traceback=traceback.format_exc())
        (Path(job) / 'error.json').write_text(json.dumps(row, indent=2) + '\n')
    return row


apps = args.app or sorted(path.name for path in args.root.iterdir() if path.is_dir())
args.out.mkdir(parents=True, exist_ok=True)

work, counts, failures = [], {}, {}
for app in apps:
    manifest_path = args.root / app / 'manifest.json'
    if not manifest_path.exists():
        print(f'{app}: no manifest', flush=True)
        continue
    objects = json.loads(manifest_path.read_text())['objects']
    counts[app] = dict(objects=len(objects), deduped=0, done=0)
    failures[app] = []
    for index, entry in enumerate(objects):
        job = args.out / app / f'{index:04d}'
        if 'symbol' not in entry:
            counts[app]['deduped'] += 1
            continue
        if covered(job):
            counts[app]['done'] += 1
            continue
        work.append((app, index, entry, str(job),
                     str(args.root / app / entry['native_object']),
                     str(args.compiler), str(args.context_compiler), str(args.native_link)))

print(f'{len(work)} objects to run, {args.jobs} at a time', flush=True)
with ProcessPoolExecutor(max_workers=args.jobs) as pool:
    for row in pool.map(run_entry, work, chunksize=1):
        counts[row['app']]['done'] += row['verdict'] == 'proof'
        if row['verdict'] != 'proof':
            failures[row['app']].append(row)
        print(f"{row['app']} {row['index']} {row['symbol']} {row['verdict']}", flush=True)

rows = []
for app in counts:
    summary = dict(app=app, **counts[app], failures=failures[app])
    rows.append(summary)
    (args.out / f'{app}.json').write_text(json.dumps(summary, indent=2) + '\n')
    print(f"{app}: objects={counts[app]['objects']} deduped={counts[app]['deduped']} "
          f"proof={counts[app]['done']} failed={len(failures[app])}", flush=True)
(args.out / 'stage1.json').write_text(json.dumps(rows, indent=2) + '\n')
