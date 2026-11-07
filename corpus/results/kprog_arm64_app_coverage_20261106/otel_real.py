"""Pair every observed ARM OTel entry with original ELF-backed maps/globals."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
from elftools.elf.elffile import ELFFile
import coverage
ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / 'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
phase = Path(sys.argv[1]).resolve()
mode = sys.argv[2] if len(sys.argv) > 2 else 'generate'
if mode == 'link':
    original = phase / 'original/tracer.bpf.o'
    link_input = phase / 'original/tracer.link.bpf.o'
    with original.open('rb') as stream:
        elf = ELFFile(stream)
        removed = [item.name for item in elf.iter_sections() if item['sh_flags'] & 4]
        payloads = {item.name: item.data() for item in elf.iter_sections()
            if item['sh_flags'] & 2 and not item['sh_flags'] & 4 and item['sh_type']=='SHT_PROGBITS'}
    # This side input supplies original maps/globals, not duplicate app programs.
    # The upstream object remains intact and is the actual application's input.
    subprocess.run(['llvm-objcopy-18', *['--remove-section='+name for name in removed],
        '--remove-section=.BTF.ext', str(original), str(link_input)], check=True)
    with link_input.open('rb') as stream:
        elf = ELFFile(stream)
        if any(elf.get_section_by_name(name).data()!=data for name,data in payloads.items()):
            raise RuntimeError('link input changed original map/global bytes')
    (phase/'original/linkage.json').write_text(json.dumps(dict(removed_duplicate_code_sections=removed,
        unchanged_payload_sections=sorted(payloads)), indent=2)+'\n')
    for row in coverage.records(phase):
        if not row['ok']:
            raise RuntimeError('generation failed: ' + row['name'])
        args = [ROOT / 'vendor/build/x86/bpftool/bin/bpftool', 'gen', 'object',
            phase / 'objects' / (row['name'] + '.linked.bpf.o'),
            phase / 'objects' / (row['name'] + '.bpf.o'), link_input]
        result = subprocess.run(list(map(str, args)), capture_output=True, text=True)
        (phase / (row['name'] + '.link-original.json')).write_text(json.dumps(dict(
            returncode=result.returncode, stdout=result.stdout, stderr=result.stderr), indent=2) + '\n')
        if result.returncode:
            raise RuntimeError(result.stderr)
    sys.exit(0)
if mode == 'install':
    stage = ROOT / 'kprog/arm64/build/app-verified-stage/otelcol-ebpf-profiler'
    entries = json.loads((phase / 'manifest-entries.json').read_text())
    for entry in entries:
        name = 'otel_' + entry['symbol']
        for path in (phase/'native'/(name+'.proof.o'), phase/'objects'/(name+'.linked.bpf.o')):
            if not path.is_file(): raise RuntimeError('complete OTel payload missing: '+str(path))
    shutil.copy2(phase / 'native/otel.native.o', stage / 'otelcol-ebpf-profiler.native.o')
    manifest = stage / 'manifest.json'
    data = json.loads(manifest.read_text())
    programs = {entry['program'] for entry in entries}
    identities = {(entry['program'], entry['source_btf_symbol']) for entry in entries}
    data['objects'] = [old for old in data['objects'] if old.get('program') not in programs or
        ((old.get('source_btf_symbol') or old.get('symbol')) and
         (old['program'],old.get('source_btf_symbol') or old.get('symbol')) not in identities)]
    for entry in entries:
        symbol = entry['symbol']
        name = 'otel_' + symbol
        shutil.copy2(phase / 'native' / (name + '.proof.o'),
            stage / ('otelcol-ebpf-profiler.' + symbol + '.proof.o'))
        shutil.copy2(phase / 'objects' / (name + '.linked.bpf.o'), stage / entry['simulator_object'])
        data['objects'].append(entry)
    manifest.write_text(json.dumps(data, indent=2) + '\n')
    print('all observed OTel triples installed; every other entry retained')
    sys.exit(0)
if mode != 'generate':
    raise ValueError(mode)
phase.mkdir()
for name in ['native', 'original', 'sources']:
    (phase / name).mkdir()
native = phase / 'native/otel.native.o'
shutil.copy2(ROOT / 'vendor/build/native-bpf/arm64/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o', native)
original = phase / 'original/tracer.bpf.o'
subprocess.run(['llvm-objcopy-18', '--strip-debug', '--remove-section=.eh_frame',
    str(ROOT / 'vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.arm64'), str(original)], check=True)
header = phase / 'original/declarations.h'
variables = set(subprocess.check_output([str(ROOT / 'kprog/arm64/build/original-btf-declarations'),
    str(original), str(header)], text=True).splitlines())
with original.open('rb') as stream:
    elf = ELFFile(stream)
    functions = {s.name: (elf.get_section(s['st_shndx']).name, s['st_size'] // 8)
        for s in elf.get_section_by_name('.symtab').iter_symbols()
        if s['st_info']['type'] == 'STT_FUNC' and isinstance(s['st_shndx'], int)}
loads = [json.loads(line) for line in (HERE / 'runtime-context-v8/all-startup-loads.jsonl').read_text().splitlines()]
selected = {}
feature_probes = []
for loaded in loads:
    if 'otelcol' not in loaded['log']:
        continue
    candidates = [symbol for symbol, (_, count) in functions.items()
        if symbol[:15] == loaded['program'] and count == loaded['insn_count']]
    if not candidates and (loaded['program'] in {'', 'libbpf_nametest'} or
            (loaded['program']=='probe_bpf_perf_' and loaded['insn_count']<=6)):
        # Same named capability probe as shim_native_loader_is_libbpf_probe.
        feature_probes.append(loaded)
        continue
    if not candidates:
        raise RuntimeError('actual OTel source entry is absent: ' + json.dumps(loaded))
    # Kernel truncation can merge equal-size variants; retain every full ELF
    # function identity. The runtime manifest binds the source BTF symbol.
    for symbol in candidates:
        selected[symbol] = loaded
(phase / 'feature-probes.json').write_text(json.dumps(feature_probes, indent=2) + '\n')
(phase / 'load-pairing.json').write_text(json.dumps(selected, indent=2) + '\n')
rows = []
entries = []
for symbol, loaded in selected.items():
    section, _ = functions[symbol]
    name = 'otel_' + symbol
    proof = phase / 'native' / (name + '.proof.o')
    source = phase / 'sources' / (name + '.bpf.c')
    row = dict(name=name, proof=str(proof), source=str(source), stage='generate', ok=False,
        note='', original_object=str(original), original_name=symbol,
        program_type=loaded['type'], program_section=section)
    try:
        command = list(map(str, [ROOT / 'kprog/arm64/build/app-native-link/release/native-link',
            '--input', native, '--symbol', symbol, '--mode', 'proof',
            '--preserve-entry-abi', '--output', proof]))
        result = subprocess.run(command, capture_output=True, text=True, timeout=120)
        (phase / (name + '.link.json')).write_text(json.dumps(dict(command=command,
            returncode=result.returncode, stdout=result.stdout, stderr=result.stderr), indent=2) + '\n')
        if result.returncode:
            raise ValueError(result.stderr)
        bodies, rodata = gen.parse_native_linked_program(gen.Bench(name, symbol, 'raw'), phase / 'native')
        text = gen.render_program(name, symbol, bodies, 'raw', rodata16=rodata,
            linked_exit=True, program_section=section, original_source=header, original_symbols=variables)
        source.write_text(text.replace('ARM64_SIM_LICENSE();', ''))
        row['ok'] = True
    except ValueError as error:
        row['note'] = str(error)
    rows.append(row)
    entries.append(dict(program=loaded['program'], source_btf_symbol=symbol,
        prog_type=loaded['type'], source_bytecode_len=loaded['insn_count'] * 8,
        native_object='otelcol-ebpf-profiler.native.o', symbol=symbol,
        simulator_object=name + '.linked.bpf.o', simulator_program=name + '_arm64_sim_xdp'))
    (phase / 'programs.jsonl').write_text(''.join(json.dumps(item) + '\n' for item in rows))
(phase / 'manifest-entries.json').write_text(json.dumps(entries, indent=2) + '\n')
coverage.freeze_simulator(phase)
print(sum(row['ok'] for row in rows), '/', len(rows), 'observed OTel programs generate')
for row in rows:
    if not row['ok']:
        print(row['name'], row['note'])
sys.exit(int(any(not row['ok'] for row in rows)))
