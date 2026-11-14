"""Measure six-app CO-RE inputs against sole-kernel libbpf and native layouts.

Compiler reports and native DWARF layouts are separate observations. Neither
is relabelled as a measurement of every final native machine instruction.
"""
import argparse
import collections
import csv
import json
from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = Path(__file__).resolve().parents[2]
STAGE = ROOT/'vendor/build/native-bpf/x86/stage'
PRODUCTS = ROOT/'vendor/build/native-bpf/x86/7.0.0-rc2+'


def inventory():
    rows = []

    def add(app, native, source, policy='compat', report=None, report_native=None):
        rows.append(dict(app=app, object=native.name, native=str(native),
                         source=str(source), policy=policy,
                         report=str(report) if report else None,
                         report_native=str(report_native) if report_native else None))

    for native in sorted((ROOT/'corpus/results/tracee-samesource-20261114').glob('*.native.o')):
        unit = native.name.removesuffix('.native.o')
        source = ROOT/'vendor/build/.tracee-build/x86/dist'
        source /= unit+'.bpf.o' if unit == 'tracee' else 'lsm_support/'+unit+'.bpf.o'
        report = Path('/var/tmp/kprog-tmp/C/tracee-samesource/tracee.core.json') if unit == 'tracee' else None
        report_native = Path('/var/tmp/kprog-tmp/C/tracee-samesource/tracee.native.o') if report else None
        add('tracee', native, source, report=report, report_native=report_native)
    for native in sorted((ROOT/'corpus/results/bcc-samesource-20261114').glob('*.native.o')):
        stem = PRODUCTS/'native/bcc'/native.name.removesuffix('.native.o')
        add('bcc', native, stem.with_suffix('.bpf.o'), 'compat',
            stem.with_suffix('.core.json'), stem.with_suffix('.native.o'))
    for native in sorted(Path('/var/tmp/kprog-tmp/C/tetra-img').glob('*.native.o')):
        add('tetragon', native, ROOT/'vendor/build/x86/tetragon'/
            native.name.replace('.native.o', '.o'), 'tetragon-compat')
    for native in sorted((STAGE/'cilium').glob('*.native.o')):
        add('cilium', native, ROOT/'vendor/bpf/cilium/bpf'/native.name.replace('.native.o', '.o'))
    for native in sorted((STAGE/'katran').glob('*.native.o')):
        add('katran', native, PRODUCTS/'katran'/native.name.replace('.native.o', '.bpf.o'))
    original = ROOT/'corpus/results/perf-combined-codegen-source-all-20261114/tracer.original.bpf.o'
    for native in sorted((STAGE/'otelcol-ebpf-profiler').glob('*.native.o')):
        add('otel', native, original)
    add('otel', ROOT/'corpus/results/perf-combined-codegen-source-all-20261114/otelcol-ebpf-profiler.native.o',
        original, 'selected-combined')
    return rows


def records(path):
    with path.open() as stream:
        return list(csv.DictReader(stream, delimiter='\t'))


def query_key(row):
    return int(row['local_type_id']), int(row['kind']), row['access']


def report_queries(path):
    queries = {}
    for row in json.loads(path.read_text()):
        name = row['global']
        access = '0' if name.startswith('llvm.btf_type_id.') else name.split('$', 1)[1]
        key = row['local_type_id'], row['kind'], access
        value = (row['resolved'] % (1 << 64), row['poison'])
        if key in queries and queries[key] != value:
            raise ValueError('Compiler report has conflicting answers: '+str(key))
        queries[key] = value
    return queries


def allocated_binding(path):
    """Debug layouts can retain the pre-CO-RE source type after IR resolution."""
    with path.open('rb') as stream:
        elf = ELFFile(stream)
        sections = {section.name: section.data() for section in elf.iter_sections()
                    if section['sh_flags'] & 2}
        relocations = []
        for section in elf.iter_sections():
            if not isinstance(section, RelocationSection):
                continue
            target = elf.get_section(section['sh_info'])
            if not target['sh_flags'] & 2:
                continue
            symbols = elf.get_section(section['sh_link'])
            for relocation in section.iter_relocations():
                symbol = symbols.get_symbol(relocation['r_info_sym'])
                index = symbol['st_shndx']
                owner = elf.get_section(index).name if isinstance(index, int) else index
                relocations.append((target.name, relocation['r_offset'], relocation['r_info_type'],
                                    relocation['r_addend'] if section.is_RELA() else None,
                                    symbol.name, owner, symbol['st_value'], symbol['st_size']))
        return sections, sorted(relocations)


def audit(args):
    args.output.mkdir(parents=True, exist_ok=True)
    objects = [r for r in inventory() if not args.app or r['app'] in args.app]
    (args.output/'inventory.json').write_text(json.dumps(objects, indent=2)+'\n')
    summaries = []
    failures = []
    for obj in objects:
        out = args.output/obj['app']/obj['object']
        out.mkdir(parents=True, exist_ok=True)
        summary = dict(obj)
        summary['counts'] = dict(relocations=0, equal=0, different=0, unobserved=0)
        commands = []

        def run(target, **variables):
            cmd = ['make', '-f', str(ROOT/'kprog/test/core-audit.mk'), target,
                   'OUTPUT='+str(out), *[k+'='+str(v) for k, v in variables.items()]]
            result = subprocess.run(cmd, cwd=ROOT, text=True, capture_output=True)
            commands.append(dict(command=cmd, returncode=result.returncode,
                                 stdout=result.stdout, stderr=result.stderr))
            (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
            result.check_returncode()

        try:
            native, source = Path(obj['native']), Path(obj['source'])
            if not native.is_file() or not source.is_file():
                raise FileNotFoundError('Object or source ELF absent: '+str(obj))
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
                summary['observation'] = 'No CO-RE records in the supplied source ELF; no native answer inferred.'
            else:
                run('reference', SOURCE=source)
                target_path = out/'reference.tsv'
                target_path.rename(out/'kernel.tsv')
                refs = records(out/'kernel.tsv')
                summary['counts']['relocations'] = len(refs)
                report = report_queries(Path(obj['report'])) if obj['report'] else {}
                report_counts = collections.Counter()
                report_bound = bool(obj['report_native'] and
                                    native.read_bytes() == Path(obj['report_native']).read_bytes())
                summary['native_equals_report_build_object'] = report_bound
                report_code_bound = bool(obj['report_native'] and
                    allocated_binding(native) == allocated_binding(Path(obj['report_native'])))
                summary['native_allocated_bytes_and_relocations_equal_report_build'] = report_code_bound
                run('native-layout', NATIVE=native)
                run('reference', SOURCE=source, TARGET=args.build/'native.btf',
                    REFERENCE_ARGS='--native-layout')
                target_path.rename(out/'physical.tsv')
                physical = records(out/'physical.tsv')
                if len(refs) != len(physical):
                    raise ValueError('Kernel/native row counts differ')
                with (out/'comparison.csv').open('w') as stream:
                    writer = csv.writer(stream)
                    writer.writerow(['section', 'insn_off', 'root', 'kind', 'access', 'spec',
                                     'kernel_answer', 'kernel_poison', 'native_answer', 'observation',
                                     'comparison', 'report_comparison'])
                    for ref, actual in zip(refs, physical):
                        if query_key(ref) != query_key(actual) or ref['insn_off'] != actual['insn_off']:
                            raise ValueError('Kernel/native row identity differs')
                        expected = int(ref['resolved']), bool(int(ref['poison']))
                        reported = report.get(query_key(ref))
                        report_state = 'absent' if reported is None else 'equal' if reported == expected else 'different'
                        report_counts[report_state] += 1
                        answer = None
                        observation = actual['status']
                        kind = int(ref['kind'])
                        if report_code_bound and reported is not None:
                            answer = reported
                            observation = 'compiler_report_allocated_bytes_and_relocations_match'
                        elif kind == 2 and obj['policy'] == 'tetragon-compat':
                            # These are the two expression-specific exceptions
                            # in native_compat.h. Source call sites are
                            # bpf_cgroup.h:134 and bpf_cgtracker.c:29.
                            zero = ((ref['root'], ref['access']) in {
                                ('kernfs_node___old', '0:0:1'),
                                ('cgroup___new', '0:1')})
                            answer = (int(not zero), False)
                            observation = 'native_compat_tetragon_expression_policy'
                        elif kind in {2, 8, 10}:
                            answer = (1, False)
                            observation = 'native_compat_constant_one'
                        elif kind in {0, 1, 9, 11} and actual['status'] == 'native_layout' and not int(actual['poison']):
                            answer = (int(actual['resolved']), False)
                            observation = 'exact_native_dwarf_layout'
                        state = 'unobserved' if answer is None else 'equal' if answer == expected else 'different'
                        summary['counts'][state] += 1
                        writer.writerow([ref[k] for k in ['section', 'insn_off', 'root', 'kind', 'access', 'spec']] +
                                        [expected[0], expected[1], None if answer is None else answer[0],
                                         observation, state, report_state])
                summary['compiler_report_comparison'] = dict(report_counts)
                summary['observation'] = 'Layout/macro or compiler-report comparison; not per-machine-instruction tracing.'
        except (OSError, ValueError, subprocess.CalledProcessError) as error:
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
        scope='Current staged outputs, Tetragon image export, selected Tracee/BCC and combined OTel. '
              'OTel split units share one source ELF; counts are per object, not unique source queries. '
              'Missing observations stay explicit. No guest, load-path check or performance claim.'), indent=2)+'\n')
    return int(bool(failures))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--app', action='append')
    raise SystemExit(audit(parser.parse_args()))
