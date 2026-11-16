"""Audit retained OTel counters and compare current context code with retained P."""
import json
import pathlib
import re
import subprocess
import sys

from elftools.elf.elffile import ELFFile

ROOT = pathlib.Path('/workspaces/repository')
RAW, TMP = map(pathlib.Path, sys.argv[1:])
RUNS = ['102445_806916', '125155_179400', '163206_529710', '172620_968192']

def symbol(path, name):
    with path.open('rb') as stream:
        elf = ELFFile(stream)
        item = next(s for s in elf.get_section_by_name('.symtab').iter_symbols()
                    if s.name == name and isinstance(s['st_shndx'], int))
        section = elf.get_section(item['st_shndx'])
        start, length = item['st_value'] - section['sh_addr'], item['st_size']
        relocations = []
        for reloc_section in elf.iter_sections():
            if reloc_section['sh_type'] not in ['SHT_REL', 'SHT_RELA']:
                continue
            if reloc_section['sh_info'] != item['st_shndx']:
                continue
            names = elf.get_section(reloc_section['sh_link'])
            for reloc in reloc_section.iter_relocations():
                at = reloc['r_offset'] - item['st_value']
                if 0 <= at < length:
                    relocations.append([at, reloc['r_info_type'],
                                        names.get_symbol(reloc['r_info_sym']).name,
                                        reloc['r_addend'] if reloc.is_RELA() else None])
        return section.data()[start:start + length], relocations

report = {'runs': {}, 'stage_comparisons': []}
for run in RUNS:
    directory = ROOT / ('corpus/results/x86_kvm_corpus_20261116_' + run) / 'details'
    data = json.loads((directory / 'apps/otelcol-ebpf-profiler__profiling.json').read_text())
    contract = json.loads((directory / 'result.json').read_text())
    row = {'bpf_stats': contract['bpf_stats'], 'samples': contract['samples'],
           'workload_seconds': contract['workload_seconds'], 'phases': {}}
    for phase in ['baseline', 'post_rejit']:
        entries = list(data[phase]['bpf'].values())
        calls = sum(p['run_cnt_delta'] for p in entries)
        elapsed = sum(p['run_time_ns_delta'] for p in entries)
        series = []
        for sample in data[phase]['workloads']:
            languages = {}
            for component in sample['components']:
                match = re.search(r'ops=(\d+)', component['stderr'])
                if match:
                    language = component['config']['language']
                    languages[language] = languages.get(language, 0) + int(match[1])
            series.append(languages)
        row['phases'][phase] = {
            'measured_programs': len(entries),
            'installed_bytes': sum(p['bytes_jited'] for p in entries),
            'programs': {p['name']: {'bytes': p['bytes_jited'],
                         'calls': p['run_cnt_delta'], 'time_ns': p['run_time_ns_delta']}
                         for p in entries},
            'total_calls': calls, 'total_ns': elapsed,
            'ns_per_call': elapsed / calls if calls else None,
            'integer_loop_operations_by_language': series,
        }
    row['integer_loop_sum_ratios'] = [sum(b.values()) / sum(a.values())
        for a, b in zip(row['phases']['baseline']['integer_loop_operations_by_language'],
                        row['phases']['post_rejit']['integer_loop_operations_by_language'])]
    report['runs'][run] = row

old = report['runs'][RUNS[0]]['phases']['post_rejit']['programs']
new = report['runs'][RUNS[-1]]['phases']['post_rejit']['programs']
report['installed_size_deltas'] = {name: new[name]['bytes'] - value['bytes']
                                   for name, value in old.items()}

inventory = json.loads(pathlib.Path(
    '/workspaces/kprog-raw/perf/20261116-native-corpus-before-publication/report.json').read_text())
stage = ROOT / 'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto'
for name in ['native_tracer_entry', 'perf_unwind_native', 'perf_unwind_v8']:
    entry = next(e for e in inventory['entries']
                 if e['app'] == 'otelcol-ebpf-profiler' and e['symbol'] == name)
    previous = pathlib.Path(entry['context_lto']['command'][-1])
    current = TMP / (name + '.native.o')
    command = [str(stage), entry['native'], '--symbol', name, '--prog-type', '7',
               '--kernel-btf', '/workspaces/.agent-state/kprog-ck/build-x86/vmlinux',
               '-o', str(current)]
    result = subprocess.run(command, text=True, capture_output=True)
    (RAW / (name + '.log')).write_text(result.stdout + result.stderr)
    result.check_returncode()
    old_bytes, old_relocs = symbol(previous, name)
    new_bytes, new_relocs = symbol(current, name)
    report['stage_comparisons'].append({
        'symbol': name, 'retained': str(previous), 'command': command,
        'retained_bytes': len(old_bytes), 'current_bytes': len(new_bytes),
        'instruction_bytes_equal': old_bytes == new_bytes,
        'relocation_identities_equal': old_relocs == new_relocs,
        'relocation_count': len(new_relocs),
    })

report['cost_split'] = {
    'current_full_round_profile': 'pending diagnostic profile on CPUs 20-23',
    'retained_old_stats1_ns_per_call': {
        phase: report['runs']['125155_179400']['phases'][phase]['ns_per_call']
        for phase in ['baseline', 'post_rejit']},
    'body_helpers_maps': 'program counters do not separate these; no split inferred from byte size',
}
(RAW / 'audit.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({'stage': report['stage_comparisons'],
                  'size_deltas': report['installed_size_deltas']}, indent=2))
