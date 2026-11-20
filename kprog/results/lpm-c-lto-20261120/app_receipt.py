"""Retain a completed app diagnostic, including failures and raw counters."""
import io
import argparse
import json
from pathlib import Path
import re
import subprocess
import sys
import tarfile
from elftools.elf.elffile import ELFFile

here = Path(__file__).resolve().parent
parser = argparse.ArgumentParser()
parser.add_argument('--raw', type=Path, default=Path('/workspaces/kprog-raw/perf/lpm-c-lto-20261120/otel-20261120T025007Z'))
parser.add_argument('--run', type=Path, default=Path('/workspaces/repository/corpus/results/x86_kvm_corpus_20261120_025243_099920'))
parser.add_argument('--name', default='app')
parser.add_argument('--revision', default='0ca3869fa')
parser.add_argument('--app', default='otelcol-ebpf-profiler/profiling')
args = parser.parse_args()
raw, app_run = args.raw, args.run
sys.path.insert(0, '/workspaces/repository/kprog')
from trusted_generation import native_map_label
app = json.loads((app_run/'details/apps'/(args.app.replace('/', '__')+'.json')).read_text())
rows = []
with tarfile.open(raw/'service.tar.gz') as service:
    journal = [json.loads(line) for line in service.extractfile('service/requests/requests.jsonl')]
    for record in journal:
        name = Path(record['artifact_archive']).name
        with tarfile.open(fileobj=io.BytesIO(service.extractfile('service/requests/'+name).read())) as capsule:
            files = set(capsule.getnames())
            row = {key: record[key] for key in ['request_id', 'source_prog_id', 'prog_id', 'native_sha256',
                'execution_path', 'status', 'b_generated', 'b_stock_passed'] if key in record}
            if 'request/generated/artifacts.json' in files:
                artifact = json.load(capsule.extractfile('request/generated/artifacts.json'))
                row['symbol'] = artifact['symbol']
            else:
                artifact = None
                row['symbol'] = capsule.extractfile('request/kernel.entry').read().decode().strip()
            if 'request/generated/checked-simulator.native.bc' in files:
                ir = subprocess.run(['llvm-dis-18', '-o', '-', '-'],
                    input=capsule.extractfile('request/generated/checked-simulator.native.bc').read(),
                    capture_output=True, check=True).stdout.decode()
                sites = [line for line in ir.splitlines() if 'call ptr @__kprog_array_lookup(' in line]
                selected = {kind: {} for kind in ['array', 'lpm', 'hash', 'percpu_array']}
                for mapping in artifact['maps']:
                    kind = {2: 'array', 11: 'lpm', 1: 'hash', 6: 'percpu_array'}.get(mapping['map_type'])
                    if kind:
                        label = re.escape(native_map_label(mapping['name']))
                        count = sum(bool(re.search('@(?:'+label+'|"'+label+'")(?=[,\\s)])', line)) for line in sites)
                        if count: selected[kind][mapping['name']] = count
                row['native_static_sites_by_map'] = selected
                for kind, mappings in selected.items(): row[kind+'_static_sites'] = sum(mappings.values())
                row['generic_lookup_static_sites'] = sum('call ptr @bpf_map_lookup_elem(' in line for line in ir.splitlines())
            if 'request/generated/checked-simulator.native.o' in files:
                elf = ELFFile(io.BytesIO(capsule.extractfile('request/generated/checked-simulator.native.o').read()))
                symbol = next(s for s in elf.get_section_by_name('.symtab').iter_symbols()
                              if s.name == artifact['simulator_program'])
                row['native_entry_bytes'] = symbol['st_size']
            if 'request/generated/checked-simulator.proof.o' in files:
                elf = ELFFile(io.BytesIO(capsule.extractfile('request/generated/checked-simulator.proof.o').read()))
                row['proof_executable_bytes'] = sum(s['sh_size'] for s in elf.iter_sections() if s['sh_flags'] & 4)
                row['proof_functions'] = {s.name: s['st_size'] for s in elf.get_section_by_name('.symtab').iter_symbols()
                                          if s['st_info']['type'] == 'STT_FUNC'}
            if 'request/generated/native-commands.jsonl' in files:
                commands = [json.loads(line) for line in capsule.extractfile('request/generated/native-commands.jsonl')]
                emitted = [item['command'] for item in commands if '-c' in item['command'] and
                           item['command'][-1].endswith('checked-simulator.native.o')]
                row['native_compile_flags'] = emitted[-1] if emitted else None
                row['native_no_red_zone_option'] = bool(emitted and '-force-attribute=noredzone' in emitted[-1])
                helper = [item['command'] for item in commands if '-emit-llvm' in item['command'] and
                          item['command'][-1].endswith('checked-simulator.helpers.bc')]
                row['helper_compile_flags'] = helper[-1] if helper else None
            if 'request/simulator-failure.json' in files:
                failure = json.load(capsule.extractfile('request/simulator-failure.json'))
                row['failure_stage'] = failure['stage']
                row['verifier_tail'] = failure.get('stderr', '').splitlines()[-12:]
            rows.append(row)
phases = {}
for phase in ['baseline', 'post_rejit']:
    if app[phase] is None:
        phases[phase] = None
        continue
    counters = app[phase]['bpf']
    count = sum(p['run_cnt_delta'] for p in counters.values())
    elapsed = sum(p['run_time_ns_delta'] for p in counters.values())
    components = []
    for component in [component for workload in app[phase]['workloads']
                      for component in (workload['components'] if 'components' in workload else [workload])]:
        matches = re.findall(r'ops=(\d+) elapsed_s=([\d.]+)', component['stderr'])
        components.append(dict(name=component['workload_name'], returncode=component['returncode'],
            self_counters=[dict(ops=int(ops), elapsed_s=float(seconds),
                ops_per_second=int(ops)/float(seconds)) for ops, seconds in matches],
            pktgen_pps=[int(value) for value in re.findall(r'\b(\d+)pps\b', component['stdout'])]))
    phases[phase] = dict(run_cnt=count, run_time_ns=elapsed, ns_per_call=elapsed/count if count else None,
                        programs=counters, workload_components=components,
                        workloads=app[phase]['workloads'])
ratio = (phases['baseline']['ns_per_call']/phases['post_rejit']['ns_per_call']
         if all(phases[phase] and phases[phase]['ns_per_call'] for phase in phases) else None)
result = dict(source_revision=args.revision, raw=str(raw), app_run=str(app_run), app=args.app,
    app_status=app['status'], app_error=app['error'], requests=rows, phases=phases,
    ebpf_over_native_per_call=ratio,
    scope='One frozen 10-second diagnostic per arm, CPU20-23, current image, installed tools. Report all checked/direct/failed paths, without causal isolation. Per-program counters are retained; summed time/count does not independently attribute tail calls. Static helper sites are not dynamic frequencies. Component throughput is reported separately.')
(here/(args.name+'-result.json')).write_text(json.dumps(result, indent=2)+'\n')
with tarfile.open(here/(args.name+'-evidence.tar.gz'), 'w:gz') as archive:
    archive.add(raw, arcname=raw.name)
    archive.add(app_run, arcname=app_run.name)
installed = [row for row in rows if row['status'] == 0]
print(json.dumps(dict(status=app['status'], installed=len(installed),
    checked=sum(row['execution_path']=='checked-sim-c' for row in installed),
    static_sites={kind: sum(row.get(kind+'_static_sites', 0) for row in installed
                  if row['execution_path']=='checked-sim-c') for kind in ['array', 'lpm', 'hash', 'percpu_array']},
    ns_per_call={phase: value['ns_per_call'] if value else None for phase, value in phases.items()}), indent=2))
