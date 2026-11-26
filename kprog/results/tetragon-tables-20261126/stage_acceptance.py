"""Compare full staged C-generation acceptance while reusing offline_link.py.

Historical Python modules are evaluated from Git in memory, never checked out
or copied into another source tree. No compiler, image or native input changes.
"""
import fcntl
import io
import json
from pathlib import Path
import runpy
import subprocess
import sys
import tarfile
import traceback
import types
from datetime import datetime, timezone

from elftools.elf.elffile import ELFFile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
STAGE = ROOT / 'vendor/build/native-bpf/x86/stage'
LINKER = ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link'
OFFLINE = ROOT / 'kprog/results/restore-529-20261121/offline_link.py'
BASELINE = '06d05f8f0^'
sys.path.insert(0, str(ROOT / 'kprog/x86'))
import trusted_specializer as worker


def now():
    return datetime.now(timezone.utc).strftime('%Y-%m-%dT%H:%M:%SZ')


def historical(name, path):
    module = types.ModuleType(name)
    module.__file__ = str(ROOT / path)
    sys.modules[name] = module
    text = subprocess.check_output(['git', 'show', BASELINE + ':' + path], cwd=ROOT, text=True)
    exec(compile(text, BASELINE + ':' + path, 'exec'), module.__dict__)
    return module


old_abi = historical('stage_before_abi', 'kprog/x86/micro-prog/x86_abi.py')
old_tables = historical('stage_before_tables', 'kprog/x86/micro-prog/x86_relative_tables.py')
old_gen = historical('stage_before_generator', 'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
old_gen.check_definedness = old_abi.check_definedness
old_gen.lower_relative_tables = old_tables.lower_relative_tables


def metadata(obj, symbol, entry):
    with obj.open('rb') as stream:
        elf = ELFFile(stream)
        symbols = list(elf.get_section_by_name('.symtab').iter_symbols())
        root = next(s for s in symbols if s.name == symbol and isinstance(s['st_shndx'], int))
        section = elf.get_section(root['st_shndx']).name
        bindings = []
        for item in symbols:
            if item['st_info']['type'] != 'STT_OBJECT' or not isinstance(item['st_shndx'], int):
                continue
            owner = elf.get_section(item['st_shndx']).name
            if owner == '.maps':
                bindings.append(dict(native_symbol=item.name, value_offset=None))
            elif owner == '.bss' or owner.startswith('.bss.') or owner == '.data' or owner.startswith('.data.'):
                bindings.append(dict(native_symbol=item.name, value_offset=0))
    kind = worker.context_kind(entry['prog_type']) if 'prog_type' in entry else (
        'xdp' if section.startswith('xdp') else 'tc' if section.startswith('tc/') or section == 'tc'
        else 'cgroup_skb' if section.startswith('cgroup_skb/') else 'raw')
    return dict(kind=kind, program_section=section, trusted_map_bindings=bindings)


def generate(generator, name, directory, options):
    try:
        insns, functions, end, rodata = generator.parse_native_linked_program(name, directory)
        text = generator.render_program(name, insns, functions, exit_addr=end, rodata16=rodata, **options)
        return dict(status='generated', source_bytes=len(text.encode())), text.encode()
    except Exception as error:
        return dict(status='refused', error_type=type(error).__name__, error=str(error),
                    traceback=traceback.format_exc()), None


def add_bytes(archive, name, data):
    item = tarfile.TarInfo(name)
    item.size = len(data)
    archive.addfile(item, io.BytesIO(data))


def publish(out, message):
    with open('/workspaces/.agent-state/kprog-lanes/locks/git', 'a') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        with (out / 'publication.log').open('a') as log:
            paths = [str(path.relative_to(ROOT)) for path in out.iterdir() if path.is_file()]
            for command in [['git', 'add', '-f', '--', *paths],
                            ['git', 'commit', '--only', '-m', message, '--', *paths],
                            ['git', 'push', 'origin', 'master']]:
                subprocess.run(command, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, check=True)


def main(out):
    out.mkdir()
    catalog, entries, unresolved = [], {}, []
    for manifest in sorted(STAGE.glob('*/manifest.json')):
        data = json.loads(manifest.read_text())
        for entry in data['objects']:
            if not entry.get('native_object'):
                continue
            obj = STAGE / manifest.parent.name / Path(entry['native_object']).name
            if not entry.get('symbol'):
                unresolved.append(dict(app=manifest.parent.name, entry=entry))
                continue
            key = (str(obj), entry['symbol'])
            if key not in entries:
                entries[key] = entry
                catalog.append(dict(app=manifest.parent.name, object=str(obj), symbol=entry['symbol']))
    (out / 'catalog.json').write_text(json.dumps(dict(explicit=catalog, runtime_resolved_groups=unresolved,
        historical_scope='P3 aggregate289 has no matching retained manifest snapshot; current explicit pairs are compared in full, not relabeled289.'), indent=2) + '\n')
    record = dict(started_utc=now(), baseline=subprocess.check_output(
        ['git', 'rev-parse', BASELINE], cwd=ROOT, text=True).strip(),
        source=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
        scope='Existing full-stage proof/kernel link with stand-in plan; full C rendering with identical ELF-derived section/context and map/value externs on both versions. No B compilation, stock verification, live binding or native execution.', cases=[])
    (out / 'controller.json').write_text(json.dumps(record, indent=2) + '\n')
    # Keep one canonical set of build-stage outputs; completed case evidence is
    # archived before the existing tool replaces those outputs for the next pair.
    real_run = subprocess.run
    pending = {}

    def observe(command, *args, **kwargs):
        result = real_run(command, *args, **kwargs)
        words = list(map(str, command))
        if not words or words[0] != str(LINKER) or '--mode' not in words:
            return result
        mode = words[words.index('--mode') + 1]
        if mode == 'proof':
            pending.clear()
            pending.update(object=words[words.index('--input') + 1],
                symbol=words[words.index('--symbol') + 1], commands=[])
        pending['commands'].append(dict(command=words, returncode=result.returncode,
            stdout=result.stdout, stderr=result.stderr))
        if mode == 'proof' and result.returncode == 0:
            return result
        obj, symbol = Path(pending['object']), pending['symbol']
        row = dict(number=len(record['cases']), app=obj.parent.name, object=str(obj), symbol=symbol,
                   link_returncode=result.returncode, started_utc=now(), commands=pending['commands'])
        directory = Path(words[words.index('--output') + 1]).parent
        case_archive = out / ('case-%03d.tar.gz' % row['number'])
        with tarfile.open(case_archive, 'w:gz') as archive:
            for path in sorted(directory.iterdir()):
                if path.is_file():
                    archive.add(path, arcname='link/' + path.name)
            proof = directory / 'p.proof.o'
            generation_command = [str(LINKER), '--input', str(obj), '--symbol', symbol,
                '--mode', 'proof', '--preserve-entry-abi', '--output', str(proof)]
            linked = real_run(generation_command, text=True, capture_output=True)
            row['commands'].append(dict(command=generation_command, returncode=linked.returncode,
                stdout=linked.stdout, stderr=linked.stderr))
            if linked.returncode == 0:
                archive.add(proof, arcname='generation/p.proof.o')
                options = metadata(obj, symbol, entries[str(obj), symbol])
                row['generation_metadata'] = options
                row['before'], before = generate(old_gen, 'p', directory, options)
                row['current'], current = generate(worker.gen, 'p', directory, options)
                row['source_unchanged'] = before == current if before is not None and current is not None else None
                for name, data in [('before', before), ('current', current)]:
                    if data is not None:
                        add_bytes(archive, name + '/p.bpf.c', data)
            else:
                row['before'] = row['current'] = dict(status='proof-failed')
            row['ended_utc'] = now()
            add_bytes(archive, 'case.json', (json.dumps(row, indent=2) + '\n').encode())
        record['cases'].append(row)
        with (out / 'journal.jsonl').open('a') as stream:
            stream.write(json.dumps(row) + '\n')
        (out / 'progress.json').write_text(json.dumps(dict(updated_utc=now(), completed=len(record['cases']),
            total=len(catalog), app=row['app'], symbol=symbol), indent=2) + '\n')
        print(row['number'], row['app'], symbol, row['before']['status'], row['current']['status'], flush=True)
        completed = len(record['cases'])
        if completed == len(catalog) or catalog[completed]['app'] != row['app']:
            (out / 'controller.json').write_text(json.dumps(record, indent=2) + '\n')
            publish(out, 'Record staged generation acceptance for ' + row['app'])
        return result

    status = 1
    try:
        archive = subprocess.Popen(['tar', '-C', str(STAGE), '-cf', '-', '.'], stdout=subprocess.PIPE)
        compressed = subprocess.Popen(['zstd', '-T1', '-3'], stdin=archive.stdout, stdout=subprocess.PIPE)
        archive.stdout.close()
        split = real_run(['split', '-b', '48000000', '-', str(out / 'native-inputs.tar.zst.part-')],
                         stdin=compressed.stdout)
        compressed.stdout.close()
        record['input_archive_status'] = [archive.wait(), compressed.wait(), split.returncode]
        if any(record['input_archive_status']):
            raise RuntimeError('native input archive failed: ' + str(record['input_archive_status']))
        subprocess.run = observe
        sys.argv = [str(OFFLINE), str(STAGE), 'x86']
        # The existing tool's one temporary output directory lives with the raw
        # result, rather than ephemeral /tmp. No sources are copied there.
        import tempfile
        tempfile.tempdir = str(out)
        runpy.run_path(str(OFFLINE), run_name='__main__')
        regressions = [r['number'] for r in record['cases'] if
                       r['before']['status'] == 'generated' and r['current']['status'] != 'generated']
        record['regressions'] = regressions
        record['generation_counts'] = {phase: {status: sum(r[phase]['status'] == status for r in record['cases'])
            for status in sorted({r[phase]['status'] for r in record['cases']})} for phase in ['before', 'current']}
        record['link_failures'] = [r['number'] for r in record['cases'] if r['link_returncode']]
        record['unexpected_generation_errors'] = [r['number'] for r in record['cases'] if any(
            r[phase].get('error_type') not in {None, 'ValueError'} for phase in ['before', 'current'])]
        record['missing_pairs'] = sorted(set(entries) - {(r['object'], r['symbol']) for r in record['cases']})
        status = int(bool(regressions or record['missing_pairs'] or record['link_failures'] or
                          record['unexpected_generation_errors']))
    finally:
        subprocess.run = real_run
        record.update(ended_utc=now(), controller_status=status)
        if sys.exc_info()[1] is not None:
            record['exception'] = traceback.format_exc()
        (out / 'controller.json').write_text(json.dumps(record, indent=2) + '\n')
        try:
            publish(out, 'Record full staged generation acceptance comparison')
        finally:
            lane = Path('/workspaces/.agent-state/kprog-lanes/perf')
            with (lane / 'resume-msg.md').open('a') as message:
                message.write(f'\nFull staged acceptance comparison ended status {status}. Read {out}/controller.json, journal.jsonl, catalog.json, publication.log and per-case archives. Record pre06d/current acceptance, historical289/current catalog scope, fix any actual regression and continue phase1. Full timing stays frozen.\n')
            stop = lane / 'STOP'
            if stop.exists() and stop.read_text().startswith('PERF stage acceptance:'):
                stop.unlink()
    return status


if __name__ == '__main__':
    if sys.argv[1] == 'smoke':
        location = HERE / 'calls/unused_local'
        results = {name: generate(gen, 'test', location, dict(kind='raw', program_section='.text'))[0]
                   for name, gen in [('before', old_gen), ('current', worker.gen)]}
        (HERE / 'stage-acceptance-smoke.json').write_text(json.dumps(results, indent=2) + '\n')
        print(json.dumps(results))
        sys.exit(int(any(r['status'] != 'generated' for r in results.values())))
    sys.exit(main(Path(sys.argv[1]).resolve()))
