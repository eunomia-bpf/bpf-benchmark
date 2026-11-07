"""Expose exact simple_packet inputs and actual expanded B, without ISA semantics."""
import argparse
from pathlib import Path
from extract_checked import decode, extract_exports
from extract_simple_arm64 import function_bytes

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('log', type=Path)
p.add_argument('directory', type=Path)
p.add_argument('exports', type=Path)
a = p.parse_args()
root = a.directory
extract_exports(a.log.read_text(), a.exports)
native = function_bytes(root/'native-link/simple_packet.proof.o', 'simple_packet_xdp', 'EM_AARCH64')
proof = function_bytes(root/'simple_packet.bpf.o', 'simple_packet_arm64_sim_xdp', 'EM_BPF')
programs = []
for path in sorted(a.exports.glob('*/load.json')):
    record = path.parent
    program, meta = decode((record/'checked.snapshot.bin').read_bytes())
    if (record/'native.bin').read_bytes() != native or (record/'proof-input.bin').read_bytes() != proof or \
            (record/'native.relocs').read_bytes() or meta['binding'][11] * 8 != len(proof) or \
            meta['binding'][2:5] != [0,1,0] or meta['binding'][12:14] != [6,37] or \
            meta['binding'][16:21] != [0]*5 or meta['binding'][22] != 1 or meta['maps'] or meta['helpers']:
        raise ValueError('captured code/proof/entry/ABI identity mismatch')
    programs.append(program)
if len(programs) != 2 or programs[0] != programs[1]:
    raise ValueError('two identical actual expanded programs required')
lines = ['import ARM64Path', 'import BPFPath', 'set_option maxRecDepth 4096', 'namespace KProgTV.PacketCompiled']
for name, data in [('native', native), ('proof', proof), ('program', programs[0])]:
    lines.append('def '+name+' : Array KProgTV.Byte := #['+','.join(hex(b) for b in data)+']')
lines += ['theorem native_size : native.size = 68 := rfl',
    'theorem proof_size : proof.size = 200 := rfl',
    'theorem program_size : program.size = 208 := rfl',
    'theorem checked_prefix : program.extract 0 192 = proof.extract 0 192 := by native_decide',
    'theorem redirected_exit : KProgTV.BPF.decode program 24 = .ok ⟨5,0,0,0,0⟩ := rfl',
    'theorem stub_exit : KProgTV.BPF.decode program 25 = .ok ⟨149,0,0,0,0⟩ := rfl',
    'end KProgTV.PacketCompiled', '#print axioms KProgTV.PacketCompiled.checked_prefix', '']
(root/'PacketCompiled.lean').write_text('\n'.join(lines))
print(f'simple_packet actual ELF/capture identities: native={len(native)} BPF={len(proof)} checked={len(programs[0])}: PASS')
