"""Exercise actual ARM checked-native emission and its required frame ABI."""
import gzip
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import tarfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BUILD = Path('/var/tmp/kprog-tmp/perf/arm64-codegen-abi')
phase = sys.argv[1]
commands = []

def run(command, required=True):
    command = list(map(str, command))
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (HERE / ('abi-worker-' + phase + '-commands.json')).write_text(json.dumps(commands, indent=2) + '\n')
    if required:
        result.check_returncode()
    return result

spec = importlib.util.spec_from_file_location('arm_abi_checked', ROOT / 'kprog/arm64/trusted_specializer.py')
worker = importlib.util.module_from_spec(spec)
spec.loader.exec_module(worker)
source = HERE / 'abi_fixture.c'
bpf = BUILD / 'fixture.bpf.o'
run([ROOT / 'kprog/stock-path/bin/clang', *worker.b_flags(), '-c', source, '-o', bpf])
artifacts = dict(simulator_source=str(source), simulator_object=str(bpf),
                 simulator_program='atomic_entry', maps=[], context_kind='raw')
# The worker owns one canonical output directory beside its source. Its input
# here is a generated preprocessing product, not a second edited source tree.
prepared = BUILD / 'fixture.i'
run(['clang-18', '-E', source, '-o', prepared])
artifacts['simulator_source'] = str(prepared)
result = worker.compile_checked_simulator(artifacts,
    ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link',
    Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir'))
obj, proof = Path(result['native_object']), Path(result['native_proof_object'])
assembly = run(['aarch64-linux-gnu-objdump', '-dr', obj]).stdout
(HERE / ('abi-worker-' + phase + '.dis')).write_text(assembly)
plan = BUILD / 'empty-plan.json'
plan.write_text(json.dumps(dict(version=1, helpers=[], maps=[], lookup_sites=[], lookup_maps=[], update_sites=[])))
linked = run([ROOT / 'kprog/x86/native_lab/native_link/target/release/native-link',
    '--input', proof, '--symbol', 'atomic_entry', '--mode', 'kernel', '--link-plan', plan,
    '--output', BUILD / 'linked.bin', '--output-relocs', BUILD / 'linked.relocs',
    '--output-abi', BUILD / 'linked.abi'], required=False)
run(['aarch64-linux-gnu-gcc', '-O2', '-static', '-ffixed-x26', HERE / 'abi_driver.c', obj, '-o', BUILD / 'execute'])
execution = run(['qemu-aarch64-static', '-cpu', 'cortex-a57', BUILD / 'execute'], required=False)
with tarfile.open(HERE / ('abi-worker-' + phase + '-evidence.tar.gz'), 'w:gz') as archive:
    for path in sorted(BUILD.glob('checked-simulator.*')):
        archive.add(path, arcname=path.name)
    archive.add(BUILD / 'native-commands.jsonl', arcname='native-commands.jsonl')
    archive.add(bpf, arcname=bpf.name)
    archive.add(BUILD / 'execute', arcname='execute')
if phase == 'after' and (linked.returncode or execution.returncode):
    raise AssertionError('ARM native ABI regression remains')
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
              phase=phase, native_flags=worker.AARCH64_HELPER_FLAGS,
              kernel_link_returncode=linked.returncode, kernel_link_stderr=linked.stderr,
              execution_returncode=execution.returncode, execution_stdout=execution.stdout,
              execution_stderr=execution.stderr,
              scope='Actual checked compiler/proof/kernel-link diagnostic and Cortex-A57 userspace atomic/ABI observer. No stock B admission, real kernel tail-call execution, application, image or timing result.')
if phase == 'after':
    with tarfile.open(HERE / 'abi-worker-before-evidence.tar.gz') as before:
        record['frontend_ir_unchanged'] = before.extractfile('checked-simulator.bc').read() == (BUILD / 'checked-simulator.bc').read_bytes()
    if not record['frontend_ir_unchanged']:
        raise AssertionError('native ABI flags changed B frontend IR')
(HERE / ('abi-worker-' + phase + '-result.json')).write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record, indent=2))
