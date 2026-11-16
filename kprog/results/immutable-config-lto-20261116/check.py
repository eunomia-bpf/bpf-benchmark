"""Exercise trusted constant consumption without pretending to be a guest capture."""
import json
import pathlib
import subprocess
import sys

root = pathlib.Path('/workspaces/repository')
raw, tmp = map(pathlib.Path, sys.argv[1:])
tool = root / 'vendor/build/native-bpf/x86/stage/kprog-perf-context-lto'
kernel = pathlib.Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')
linker = root / 'kprog/x86/native_lab/native_link/target/release/native-link'

def run(args, log):
    result = subprocess.run(list(map(str, args)), capture_output=True, text=True)
    (raw / log).write_text(result.stdout + result.stderr)
    result.check_returncode()
    return result.stdout

def compile_lto(source, symbol, values, name):
    facts = raw / (name + '.json')
    facts.write_text(json.dumps(values))
    output = tmp / (name + '.native.o')
    run([tool, source, '--symbol', symbol, '--prog-type', 5,
         '--kernel-btf', kernel, '--immutable-globals', facts, '-o', output], name + '.log')
    return output

def disassemble(path, name):
    return run(['llvm-objdump-18', '-dr', path], name + '.disasm')

source = tmp / 'fixture.native.o'
before = disassemble(source, 'fixture-before')
assert 'bpf_probe_read_kernel' in before
outputs = []
for enabled in [0, 1]:
    values = {'enabled': enabled.to_bytes(4, 'little').hex(),
              'signed_config': (0x8000000000000001).to_bytes(8, 'little').hex(),
              'aggregate': '00' * 8, 'ordered_value': '00' * 4}
    after = compile_lto(source, 'entry', values, 'fixture-' + str(enabled))
    assembly = disassemble(after, 'fixture-' + str(enabled))
    if enabled == 0:
        assert 'bpf_probe_read_kernel' not in assembly
        assert 'signed_config-' not in assembly
        for name in ['mutable_value', 'aggregate', 'ordered_value']:
            assert name in assembly, name
    else:
        assert 'bpf_probe_read_kernel' in assembly
    outputs.append({'snapshot_enabled': enabled, 'cold_call': bool(enabled)})

# This real-object replay uses only the workload's source-derived process-count
# setting, not a captured frozen map. Guest map eligibility still needs its check.
bcc = root / 'vendor/build/native-bpf/x86/stage/bcc/syscount.native.o'
after = compile_lto(bcc, 'sys_exit', {'count_by_process': '00'}, 'syscount')
sizes = {}
for label, path in [('before', bcc), ('after', after)]:
    proof = tmp / ('syscount-' + label + '.proof.o')
    run([linker, '--input', path, '--symbol', 'sys_exit', '--output', proof,
         '--mode', 'proof'], 'syscount-' + label + '-proof.log')
    sections = run(['llvm-size-18', '-A', proof], 'syscount-' + label + '-size.txt')
    sizes[label] = next(int(line.split()[1]) for line in sections.splitlines()
                        if line.split() and line.split()[0] == '.text')
report = {'fixture_snapshots': outputs, 'aggregate_and_atomic_loads': 'preserved',
          'mutable_load': 'preserved', 'syscount_sys_exit_proof_text_bytes': sizes,
          'bcc_fact_provenance': 'source-derived workload setting; not a guest snapshot',
          'guest_eligibility_and_installed_per_call': 'pending publication'}
# Binding now precedes LTO. Exercise raw P entry extraction for the context,
# generated-function and packet paths affected by this ordering.
entries = [('otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o', 'native_tracer_entry'),
           ('otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o', 'custom__generic'),
           ('tetragon/bpf_execve_event_v61.native.o', 'event_execve'),
           ('cilium/bpf_lxc.native.o', 'cil_from_container')]
for index, (path, symbol) in enumerate(entries):
    run([linker, '--input', root / 'vendor/build/native-bpf/x86/stage' / path,
         '--symbol', symbol, '--output', tmp / ('raw-entry-' + str(index) + '.proof.o'),
         '--mode', 'proof'], 'raw-entry-' + str(index) + '.log')
report['raw_entry_extraction'] = [symbol for _, symbol in entries]
(raw / 'host-result.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps(report))
