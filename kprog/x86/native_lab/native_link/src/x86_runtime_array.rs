//! Actual-map ARRAY dispatch. Layout comes from the running target's ABI,
//! never from another lookup's positional metadata or an inferred inner type.
//! Mirrors kernel/bpf/arraymap.c array_map_lookup_elem under the caller's
//! existing BPF map lifetime/RCU protection; it introduces no pointer cache.
use super::*;

pub(super) fn prefix(layout: &RuntimeArrayLayout) -> Result<Vec<u8>> {
    build_prefix(layout, 5, 0)
}

fn build_prefix(layout: &RuntimeArrayLayout, skip: u8, generic_offset: u8) -> Result<Vec<u8>> {
    let mut bytes = vec![0x81, 0xbf]; // cmp dword [rdi+map_type], ARRAY
    bytes.extend_from_slice(&i32::try_from(layout.map_type)?.to_le_bytes());
    bytes.extend_from_slice(&layout.array_type.to_le_bytes());
    bytes.extend_from_slice(&[0x75, 0]); // jne generic helper
    let generic_branch = bytes.len() - 1;
    bytes.extend_from_slice(&[0x8b, 0x06]); // mov eax,[rsi]: u32 key
    bytes.extend_from_slice(&[0x3b, 0x87]); // cmp eax,[rdi+max_entries]
    bytes.extend_from_slice(&i32::try_from(layout.max_entries)?.to_le_bytes());
    bytes.extend_from_slice(&[0x73, 0]); // jae null
    let null_branch = bytes.len() - 1;
    bytes.extend_from_slice(&[0x23, 0x87]); // and eax,[rdi+index_mask]
    bytes.extend_from_slice(&i32::try_from(layout.index_mask)?.to_le_bytes());
    bytes.extend_from_slice(&[0x8b, 0x97]); // mov edx,[rdi+elem_size]
    bytes.extend_from_slice(&i32::try_from(layout.elem_size)?.to_le_bytes());
    bytes.extend_from_slice(&[0x48, 0x0f, 0xaf, 0xc2]); // imul rax,rdx: u64 product
    bytes.extend_from_slice(&[0x48, 0x8d, 0x84, 0x07]); // lea rax,[rdi+rax+value]
    bytes.extend_from_slice(&i32::try_from(layout.value)?.to_le_bytes());
    bytes.extend_from_slice(&[0xeb, 4 + skip]); // skip NULL body and generic slot
    let null = bytes.len();
    bytes.extend_from_slice(&[0x31, 0xc0, 0xeb, skip]); // NULL; skip generic slot
    bytes[generic_branch] = u8::try_from(bytes.len() - generic_branch - 1)? + generic_offset;
    bytes[null_branch] = u8::try_from(null - null_branch - 1)?;
    Ok(bytes)
}

fn routine(layout: &RuntimeArrayLayout) -> Result<(Vec<u8>, usize)> {
    let mut bytes = build_prefix(layout, 0, 1)?;
    bytes.push(0xc3); // ARRAY/NULL return; other types branch past this RET.
    bytes.extend_from_slice(&[0x48, 0x83, 0xec, 8]); // Align nested SysV call.
    let call = bytes.len();
    // Both native loaders require an E8 rel32 helper slot. Keep that ABI,
    // rather than emitting a tail JMP that the direct loader rejects.
    bytes.extend_from_slice(&X86_HELPER_CALL_REL32_SLOT);
    bytes.extend_from_slice(&[0x48, 0x83, 0xc4, 8, 0xc3]);
    Ok((bytes, call))
}

pub(super) fn share(blob: &mut Vec<u8>, relocs: &mut Vec<RelocRecord>,
                    layout: &RuntimeArrayLayout, helper: u64) -> Result<Option<(usize, usize)>> {
    let sites: Vec<usize> = relocs.iter().filter(|r|
        r.kind == NATIVE_LAB_RELOC_HELPER_CALL_REL32 && r.target == helper)
        .map(|r| r.offset as usize).collect();
    if sites.is_empty() { return Ok(None); }
    let start = blob.len();
    let (bytes, call) = routine(layout)?;
    for &site in &sites {
        if blob.get(site..site+5) != Some(X86_HELPER_CALL_REL32_SLOT.as_slice()) {
            bail!("shared ARRAY call at {site:#x} lost its helper slot");
        }
        let disp = i32::try_from(start as i64 - (site + 5) as i64)?;
        blob[site+1..site+5].copy_from_slice(&disp.to_le_bytes());
    }
    relocs.retain(|r| !(r.kind == NATIVE_LAB_RELOC_HELPER_CALL_REL32 && r.target == helper));
    blob.extend_from_slice(&bytes);
    relocs.push(RelocRecord { offset: u32::try_from(start + call)?,
        kind: NATIVE_LAB_RELOC_HELPER_CALL_REL32, target: helper });
    Ok(Some((start, blob.len())))
}

#[cfg(all(test, target_arch = "x86_64", target_os = "linux"))]
mod tests {
    use super::*;

    #[test]
    fn runtime_array_executes_key_bounds_mask_wide_product_and_other_type_dispatch() -> Result<()> {
        // Deliberately non-kernel fixture offsets catch hard-coded layout use.
        let layout = RuntimeArrayLayout { map_type: 12, max_entries: 24, elem_size: 32,
            index_mask: 36, value: 64, array_type: 2 };
        for shared in [false, true] {
            let (mut code, call) = if shared { routine(&layout)? } else {
                let mut code = prefix(&layout)?;
                let call = code.len();
                code.extend_from_slice(&[0xe8,0,0,0,0,0xc3]);
                (code, call)
            };
            let disp = i32::try_from(code.len() as i64 - (call + 5) as i64)?;
            code[call+1..call+5].copy_from_slice(&disp.to_le_bytes());
            if shared {
                // The nested generic helper must see SysV RSP%16==8.
                code.extend_from_slice(&[0x48,0x89,0xe0,0x83,0xe0,15,0x83,0xf8,8,
                    0x74,6,0xb8,0xfe,0xca,0xad,0xde,0xc3]);
            }
            // Generic leaf returns original RDI xor RSI, exposing argument damage.
            code.extend_from_slice(&[0x48,0x89,0xf8,0x48,0x31,0xf0,0xc3]);
            let mut map = [0u8; 128];
            let ptr = map.as_mut_ptr();
            let mut set = |offset: u32, value: u32| map[offset as usize..offset as usize+4]
                .copy_from_slice(&value.to_ne_bytes());
            set(layout.map_type, 2);
            set(layout.max_entries, 5);
            set(layout.index_mask, 7);
            set(layout.elem_size, 24);
            for index in [0u32, 1, 4, 5, u32::MAX] {
                let key = (0xa5a5_a5a5u64 << 32) | u64::from(index);
                let result = memory::call_blob(&code, ptr, &key as *const _ as usize, 0) as usize;
                let expected = if index >= 5 { 0 } else { ptr as usize + 64 + index as usize*24 };
                assert_eq!(result, expected, "u32 key/bounds index={index}");
            }
            // Product must not truncate to32 bits, nor dereference the computed
            // value pointer. Mask is read from the live map rather than max-1.
            for (mask, size) in [(3u32, 24), (7, u32::MAX)] {
                map[36..40].copy_from_slice(&mask.to_ne_bytes());
                map[32..36].copy_from_slice(&size.to_ne_bytes());
                let key = 4u32;
                let result = memory::call_blob(&code, ptr, &key as *const _ as usize, 0) as usize;
                assert_eq!(result, (ptr as usize).wrapping_add(64 + u64::from(key & mask) as usize*size as usize));
            }
            // Non-ARRAY must branch before dereferencing even the key pointer.
            for kind in [1u32, 6, 12] {
                map[12..16].copy_from_slice(&kind.to_ne_bytes());
                assert_eq!(memory::call_blob(&code, ptr, 1, 0) as usize, ptr as usize ^ 1);
            }
        }
        Ok(())
    }

    #[test]
    fn shared_calls_target_one_routine_and_keep_unrelated_relocations() -> Result<()> {
        let layout = RuntimeArrayLayout { map_type: 12, max_entries: 24, elem_size: 32,
            index_mask: 36, value: 64, array_type: 2 };
        let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(3);
        blob.push(0xc3);
        let mut relocs = vec![RelocRecord { offset: 0, kind: 1, target: 0x1234 },
            RelocRecord { offset: 5, kind: 1, target: 0x1234 },
            RelocRecord { offset: 10, kind: 1, target: 0x5678 }];
        let range = share(&mut blob, &mut relocs, &layout, 0x1234)?.expect("two lookups");
        assert_eq!(range, (16, 83), "one67-byte routine, not one per call");
        for site in [0usize, 5] {
            let disp = i32::from_le_bytes(blob[site+1..site+5].try_into()?);
            assert_eq!((site+5) as i64 + i64::from(disp), 16);
        }
        assert_eq!(&blob[10..15], X86_HELPER_CALL_REL32_SLOT.as_slice());
        assert_eq!(relocs.len(), 2);
        assert!(relocs.iter().any(|r| r.offset == 10 && r.target == 0x5678));
        let external = relocs.iter().find(|r| r.target == 0x1234).expect("generic helper");
        assert_eq!(external.offset, 16+57);
        assert_eq!(&blob[external.offset as usize..external.offset as usize+5],
            X86_HELPER_CALL_REL32_SLOT.as_slice(), "sameE8 slot accepted by both loaders");
        Ok(())
    }
}
