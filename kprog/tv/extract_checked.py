"""Read the module's exact pre-restoration verifier artifact; preserve all bytes."""
import argparse
import json
import struct
from pathlib import Path


def decode(data):
    if len(data) < 120:
        raise ValueError('truncated checked header')
    version, count, regions, maps, helpers, generation = struct.unpack_from('<6I', data)
    binding = struct.unpack_from('<24I', data, 24)
    if version != 1 or not count or not regions or not generation:
        raise ValueError('invalid checked header')
    size = 120 + count * 8 + regions * 16 + maps * 40 + helpers * 16
    if len(data) != size:
        raise ValueError('checked extent does not match records')
    if binding[0] != 2 or binding[1] not in (1, 2) or binding[2] or binding[3] != 1 or \
            binding[4] > 15 or binding[8] != regions or binding[14] + 1 != generation or \
            not binding[21] or binding[15] or binding[23]:
        raise ValueError('invalid generation-bound entry/ABI/context')
    program = data[120:120+count*8]
    position = 120+count*8
    region_records = [struct.unpack_from('<IIQ', data, position+i*16) for i in range(regions)]
    position += regions*16
    previous_end = 0
    for start, length, payload in region_records:
        if not length or start < previous_end or start + length > count:
            raise ValueError('invalid proof region')
        previous_end = start + length
        if payload & 15 or ((payload >> 20) & 0xffffffff) == 0:
            raise ValueError('invalid bound region payload')
    if region_records[-1][1] < binding[11] or region_records[-1][2] >> 20 != generation:
        raise ValueError('final proof region generation/extent mismatch')
    map_records = [struct.unpack_from('<8IQ', data, position+i*40) for i in range(maps)]
    position += maps*40
    helper_records = [struct.unpack_from('<IIQ', data, position+i*16) for i in range(helpers)]
    for pc, map_id, offset, kind, key, value, capacity, flags, pointer in map_records:
        if pc+1 >= count or program[pc*8] != 0x18 or program[pc*8+1] >> 4 not in (1,2) or not map_id:
            raise ValueError('map record does not match actual instruction')
        lo, hi = struct.unpack_from('<I', program, pc*8+4)[0], struct.unpack_from('<I', program, pc*8+12)[0]
        if pointer != lo | hi << 32:
            raise ValueError('map record pointer differs from actual expanded program')
    for pc, identity, function in helper_records:
        if pc >= count or program[pc*8] != 0x85 or program[pc*8+1] >> 4 or \
                identity != struct.unpack_from('<I', program, pc*8+4)[0]:
            raise ValueError('helper record does not match actual instruction')
    expected_maps = [i for i in range(count) if program[i*8] == 0x18 and program[i*8+1] >> 4 in (1,2)]
    expected_helpers = [i for i in range(count) if program[i*8] == 0x85 and program[i*8+1] >> 4 == 0]
    if [r[0] for r in map_records] != expected_maps or [r[0] for r in helper_records] != expected_helpers:
        raise ValueError('missing/duplicate map or helper record')
    return program, dict(version=version, generation=generation, binding=list(binding),
        regions=region_records, maps=map_records, helpers=helper_records)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('log', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    captures = [line.split()[1] for line in args.log.read_text().splitlines() if line.startswith('TV_CHECKED ')]
    if len(captures) != 1 or 'actual bound expanded artifact capture: PASS' not in args.log.read_text():
        raise ValueError('one completed actual bound load/capture is required')
    data = bytes.fromhex(captures[0])
    emit(data, args.output)


def emit(data, output):
    program, metadata = decode(data)
    output.mkdir(parents=True, exist_ok=True)
    (output/'checked.snapshot.bin').write_bytes(data)
    (output/'checked.program.bin').write_bytes(program)
    (output/'checked.metadata.json').write_text(json.dumps(metadata, indent=2)+'\n')
    lines = ['import SimpleCompiled', 'set_option maxRecDepth 4096', 'namespace KProgTV.SimpleChecked',
        'def program : Array KProgTV.Byte := #['+','.join(hex(b) for b in program)+']',
        'def binding : Array KProgTV.Byte := #['+','.join(hex(b) for b in data[24:120])+']',
        'theorem program_size : program.size = 232 := rfl',
        'theorem original_prefix : program.extract 0 216 = KProgTV.SimpleCompiled.proof.extract 0 216 := by native_decide',
        'theorem redirected_exit : KProgTV.BPF.decode program 27 = .ok ⟨5,0,0,0,0⟩ := rfl',
        'theorem stub_exit : KProgTV.BPF.decode program 28 = .ok ⟨149,0,0,0,0⟩ := rfl',
        'end KProgTV.SimpleChecked', '#print axioms KProgTV.SimpleChecked.original_prefix', '']
    (output/'SimpleChecked.lean').write_text('\n'.join(lines))
    print(f'actual expanded proof: {len(program)//8} instructions, {len(metadata["regions"])} bound region(s)')


if __name__ == '__main__':
    main()
