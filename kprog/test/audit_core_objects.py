"""Compare actual ELF CO-RE queries with libbpf and bound native observations.

Offline only. A DWARF layout is evidence about types, not an observation of
header macro expansion or final machine code. Missing observations stay so.
"""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def records(path):
    with path.open() as stream:
        return list(csv.DictReader(stream, delimiter='\t'))


def query_key(row):
    return int(row['local_type_id']), int(row['kind']), row['access']


def sha256(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def native_answers(path, source_sha256, native_sha256):
    if path is None:
        return {}
    witness = json.loads(Path(path).read_text())
    if (witness['source_sha256'], witness['native_sha256']) != (source_sha256, native_sha256):
        raise ValueError('Native observation witness belongs to different source/native bytes')
    answers = {}
    for row in witness['answers']:
        if type(row['value']) is not int or not 0 <= row['value'] < 1 << 64:
            raise ValueError('Observed CO-RE value must be a u64 bit pattern')
        if type(row['poison']) is not bool:
            raise ValueError('Observed poison state must be boolean')
        key, value = query_key(row), (row['value'], row['poison'])
        if key in answers and answers[key] != value:
            raise ValueError('Conflicting observed CO-RE answers: '+str(key))
        answers[key] = value
    return answers


def audit(args):
    args.output.mkdir(parents=True, exist_ok=True)
    objects = [row for row in json.loads(args.inventory.read_text())
               if not args.app or row['app'] in args.app]
    (args.output/'inventory.json').write_text(json.dumps(objects, indent=2)+'\n')
    summaries, failures = [], []
    target_sha256 = sha256(args.target)
    for obj in objects:
        out = args.output/obj['app']/obj['object']
        out.mkdir(parents=True, exist_ok=True)
        summary = dict(obj, counts=dict(relocations=0, equal=0, different=0, unobserved=0))
        commands = []

        def run(command, output):
            command = list(map(str, command))
            result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True)
            commands.append(dict(command=command, returncode=result.returncode,
                                 stdout=result.stdout, stderr=result.stderr))
            (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
            output.write_text(result.stdout)
            result.check_returncode()

        try:
            native, source = Path(obj['native']), Path(obj['source'])
            summary.update(native_sha256=sha256(native), source_sha256=sha256(source))
            if any(obj.get(key) for key in ('policy', 'report', 'report_native')):
                raise ValueError('Retired compatibility/compiler-report inventory; supply actual native observations')
            with source.open('rb') as stream:
                elf = ELFFile(stream)
                if elf['e_machine'] != 'EM_BPF':
                    raise ValueError('Source ELF is not BPF: '+str(source))
                ext = elf.get_section_by_name('.BTF.ext')
                if ext is None:
                    raise ValueError('Source ELF lacks .BTF.ext; zero CO-RE is not established')
                data = ext.data()
                core_bytes = struct.unpack_from('<I', data, 28)[0] if len(data) >= 32 else 0
            summary['core_relocation_bytes'] = core_bytes
            if not core_bytes:
                summary['observation'] = 'No CO-RE records in this supplied source ELF.'
            else:
                run([args.build/'core-reference', source, args.target], out/'kernel.tsv')
                refs = records(out/'kernel.tsv')
                summary['counts']['relocations'] = len(refs)
                observed = native_answers(obj.get('observations'), summary['source_sha256'],
                                          summary['native_sha256'])
                physical = None
                if obj.get('native_layout'):
                    run(['pahole', '--btf_encode_detached='+str(args.build/'native.btf'), native],
                        out/'pahole.stdout')
                    run([args.build/'core-reference', source, args.build/'native.btf', '--native-layout'],
                        out/'physical.tsv')
                    physical = records(out/'physical.tsv')
                    if len(refs) != len(physical):
                        raise ValueError('Kernel/native layout row counts differ')
                with (out/'comparison.csv').open('w') as stream:
                    writer = csv.writer(stream)
                    writer.writerow(['section', 'insn_off', 'root', 'kind', 'access', 'spec',
                                     'kernel_answer', 'kernel_poison', 'observed_answer',
                                     'observed_poison', 'comparison', 'layout_answer', 'layout_status'])
                    for index, ref in enumerate(refs):
                        key = query_key(ref)
                        expected = int(ref['resolved']), bool(int(ref['poison']))
                        answer = observed.get(key)
                        state = 'unobserved' if answer is None else 'equal' if answer == expected else 'different'
                        summary['counts'][state] += 1
                        layout_answer, layout_status = None, 'not_requested'
                        if physical is not None:
                            actual = physical[index]
                            if key != query_key(actual) or ref['insn_off'] != actual['insn_off']:
                                raise ValueError('Kernel/native layout row identity differs')
                            layout_status = actual['status']
                            if layout_status == 'native_layout' and not int(actual['poison']):
                                layout_answer = int(actual['resolved'])
                        writer.writerow([ref[k] for k in ['section', 'insn_off', 'root', 'kind', 'access', 'spec']] +
                                        [*expected, *(answer if answer is not None else (None, None)),
                                         state, layout_answer, layout_status])
                summary['observation'] = 'Bound native observations; optional DWARF layout is separate evidence.'
        except (OSError, ValueError, KeyError, subprocess.CalledProcessError) as error:
            summary['error'] = str(error)
            failures.append(dict(app=obj['app'], object=obj['object'], error=str(error)))
        summaries.append(summary)
        (out/'summary.json').write_text(json.dumps(summary, indent=2)+'\n')
        (args.output/'objects.json').write_text(json.dumps(summaries, indent=2)+'\n')
        print(obj['app'], obj['object'], summary.get('error', summary['counts']), flush=True)
    totals = {}
    for obj in summaries:
        app = totals.setdefault(obj['app'], dict(objects=0, errors=0, relocations=0, equal=0, different=0, unobserved=0))
        app['objects'] += 1
        app['errors'] += int('error' in obj)
        for key, value in obj['counts'].items():
            app[key] += value
    (args.output/'summary.json').write_text(json.dumps(dict(apps=totals, failures=failures,
        target=str(args.target), target_sha256=target_sha256,
        scope='Explicit source/native inventory, actual ELF CO-RE resolved directly by libbpf. '
              'Missing observations remain unobserved; DWARF does not prove header/code answers. '
              'No program load, execution, load-path check or performance claim.'), indent=2)+'\n')
    return int(bool(failures))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('output', 'build', 'inventory', 'target'):
        parser.add_argument('--'+name, type=Path, required=True)
    parser.add_argument('--app', action='append')
    raise SystemExit(audit(parser.parse_args()))
