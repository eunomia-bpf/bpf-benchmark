"""Instantiate concrete TV with actual completed simple loads and RX entries."""
import argparse
import json
import struct
from pathlib import Path
from extract_checked import decode
from emitted_sites import validate_emitted

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('exports', type=Path)
parser.add_argument('output', type=Path)
args = parser.parse_args()
args.output.mkdir(parents=True, exist_ok=True)
records = sorted(args.exports.glob('*/emitted.bin'))
if not records:
    raise ValueError('actual emission records required')
for record in records:
    path = record.parent
    files = {name: (path/name).read_bytes() for name in ['emitted.bin', 'checked.snapshot.bin',
        'native.bin', 'native.relocs', 'jit.bin', 'jit-addresses.bin', 'jit-lengths.bin', 'load.json']}
    program, metadata = decode(files['checked.snapshot.bin'])
    load = json.loads(files['load.json'])
    binding = metadata['binding']
    sites = validate_emitted(files['emitted.bin'], metadata, files['native.bin'], files['native.relocs'],
        files['jit.bin'], files['jit-addresses.bin'], files['jit-lengths.bin'])
    if len(sites) != 1 or binding[2:5] != [0,1,0] or binding[12:14] != [6,37] or \
            binding[16:21] != [0]*5 or binding[22] != 1 or load['version'] != 1 or \
            load['source_prog_id'] != binding[21] or load['generation'] != metadata['generation'] or \
            path.name != f"{load['source_prog_id']}-{load['native_prog_id']}":
        raise ValueError('completed simple supported inline XDP invocation identity required')
    site = sites[0]
    namespace = 'KProgTV.SimpleEmitted_' + path.name.replace('-', '_')
    lines = ['import SimpleCheckedBlocks', 'namespace '+namespace,
        'open KProgFormal.Reference', 'set_option maxRecDepth 4096']
    arrays = {'native': files['native.bin'], 'program': program, 'jit': files['jit.bin'],
        'bindingBytes': files['checked.snapshot.bin'][24:120],
        'snapshotBytes': files['checked.snapshot.bin'], 'emissionBytes': files['emitted.bin']}
    for name, data in arrays.items():
        lines.append('def '+name+' : Array KProgTV.Byte := #['+','.join(hex(b) for b in data)+']')
    lines += [f'def entry : Nat := {binding[2]}', f'def jitOffset : Nat := {site["jit_offset"]}',
        f'def jitBase : Nat := {struct.unpack_from("<Q", files["jit-addresses.bin"])[0]}',
        f'def entryAddress : Nat := {site["entry_address"]}',
        'def artifact : KProgTV.Artifact where', '  nativeBytes := native.toList',
        '  proofBytes := program.toList', '  entry := entry', '  abi := bindingBytes.toList',
        '  metadata := snapshotBytes.toList ++ emissionBytes.toList',
        'theorem native_is_certified : native = KProgTV.SimpleCompiled.native := rfl',
        'theorem proof_is_checked : program = KProgTV.SimpleChecked.program := rfl',
        'theorem actual_jit_entry : jit.extract jitOffset (jitOffset + native.size) = native ∧',
        '    jitBase + jitOffset = entryAddress := by exact ⟨rfl, by decide⟩',
        'theorem artifact_identity : artifact.nativeBytes = KProgTV.SimpleCompiled.native.toList ∧',
        '    artifact.proofBytes = KProgTV.SimpleChecked.program.toList ∧ artifact.entry = 0 :=',
        '  ⟨congrArg Array.toList native_is_certified, congrArg Array.toList proof_is_checked, rfl⟩',
        '''theorem accepted_bound_prefix_checked (n : AArch64.State) (p : KProgTV.BPF.State)
    (context pointer limit : Word) (first second : KProgTV.Event)
    (entryConditions : KProgTV.SimpleBlocks.EntryConditions n p context pointer limit first second)
    (accepted : KProgTV.Artifact → Prop) (checked : KProgTV.Artifact → KProgTV.Event → Prop)
    (proofEntry : KProgTV.Artifact → KProgTV.BPF.State → Prop)
    (verifierSound : ∀ a, accepted a → a.proofBytes = KProgTV.SimpleChecked.program.toList →
      proofEntry a (KProgTV.SimpleEntryCertificate.proofBefore p context 0) → ∀ trace last,
      KProgTV.Execution KProgTV.SimpleCheckedPlatform.instructionStep
        (KProgTV.SimpleEntryCertificate.proofBefore p context 0) trace last →
      ∀ event ∈ trace, checked a event)
    (executed : KProgTV.Artifact) (bound : executed = artifact)
    (acceptance : accepted artifact)
    (admittedEntry : proofEntry artifact (KProgTV.SimpleEntryCertificate.proofBefore p context 0))
    {trace : List KProgTV.Event} {last : AArch64.State}
    (run : KProgTV.Execution
      (KProgTV.ARM64Path.instructionStep (BitVec.ofNat 64 executed.entry) executed.nativeBytes.toArray)
      (KProgTV.SimpleEntryCertificate.before n context) trace last) :
    ∀ event ∈ trace, checked artifact event :=
  KProgTV.SimpleCheckedBlocks.bound_native_prefix_checked n p context pointer limit first second
    entryConditions accepted checked proofEntry verifierSound artifact executed bound
    artifact_identity.1 artifact_identity.2.2 artifact_identity.2.1 acceptance admittedEntry run''',
        'end '+namespace, '#print axioms '+namespace+'.actual_jit_entry',
        '#print axioms '+namespace+'.accepted_bound_prefix_checked', '']
    (args.output/('SimpleEmitted_'+path.name.replace('-', '_')+'.lean')).write_text('\n'.join(lines))
    print(path.name+': emitted native/program/entry/ABI/metadata certificate input generated')
