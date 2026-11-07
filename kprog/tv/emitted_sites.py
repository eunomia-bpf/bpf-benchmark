"""Bind callback-reported RX entries to actual JIT bytes; no ISA interpretation."""
import struct


def validate_emitted(data, metadata, native, relocs, jit, addresses, lengths):
    if len(data) < 16 or len(addresses) % 8 or len(lengths) % 4:
        raise ValueError('truncated emitted/JIT layout')
    version, count, source, reserved = struct.unpack_from('<4I', data)
    binding = metadata['binding']
    if version != 1 or reserved or not count or count != binding[8] or \
            source != binding[21] or len(data) != 16 + count * 24:
        raise ValueError('emission identity/count differs from accepted binding')
    if relocs:
        raise ValueError('relocated native needs final-patch validation before an exact-byte certificate')
    if binding[1] not in (1, 2) or len(native) != binding[7]:
        raise ValueError('wrong native architecture/extent')
    bases = [x[0] for x in struct.iter_unpack('<Q', addresses)]
    sizes = [x[0] for x in struct.iter_unpack('<I', lengths)]
    if not bases or len(bases) != len(sizes) or sum(sizes) != len(jit) or \
            any(not base or not size or base + size > 2**64 for base, size in zip(bases, sizes)):
        raise ValueError('actual JIT layout extent mismatch')
    regions = {}
    for _, _, payload in metadata['regions']:
        blob = (payload >> 8) & 511
        if blob in regions:
            raise ValueError('duplicate bound region')
        regions[blob] = (payload >> 20, (payload >> 4) & 15)
    if sorted(regions) != list(range(count)):
        raise ValueError('missing bound region')
    records, native_offset = [], 0
    for index in range(count):
        blob, generation, size, abi, address = struct.unpack_from('<4IQ', data, 16 + index * 24)
        if blob != index or (generation, abi) != regions[index] or abi != binding[4] or \
                not size or not address or (binding[1] == 2 and (size % 4 or address % 4)) or native_offset + size > len(native):
            raise ValueError('native site generation/ABI/extent mismatch')
        matches, image_offset = [], 0
        for base, length in zip(bases, sizes):
            delta = address - base
            if 0 <= delta and delta + size <= length:
                matches.append(image_offset + delta)
            image_offset += length
        if len(matches) != 1:
            raise ValueError('reported native entry is not in exactly one actual JIT function')
        offset = matches[0]
        if jit[offset:offset+size] != native[native_offset:native_offset+size]:
            raise ValueError('actual JIT bytes differ at the callback-reported entry')
        records.append(dict(blob_id=blob, generation=generation, abi_mask=abi,
            entry_address=address, jit_offset=offset, native_offset=native_offset, native_size=size))
        native_offset += size
    if native_offset != len(native) or records[-1]['native_offset'] != binding[6] or \
            records[-1]['native_size'] != binding[9]:
        raise ValueError('emission chunk layout differs from complete bound artifact')
    intervals = sorted((r['entry_address'], r['entry_address'] + r['native_size']) for r in records)
    if any(right[0] < left[1] for left, right in zip(intervals, intervals[1:])):
        raise ValueError('overlapping emitted native chunks')
    return records
