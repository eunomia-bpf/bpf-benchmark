//! Actual-map ARRAY dispatch. Layout comes from the running target's ABI,
//! never from another lookup's positional metadata or an inferred inner type.
//! Mirrors kernel/bpf/arraymap.c array_map_lookup_elem under the caller's
//! existing BPF map lifetime/RCU protection; it introduces no pointer cache.
use super::*;

pub(super) fn prefix(layout: &RuntimeArrayLayout) -> Result<Vec<u8>> {
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
    bytes.extend_from_slice(&[0xeb, 9]); // skip xor(2),jmp(2),call(5)
    let null = bytes.len();
    bytes.extend_from_slice(&[0x31, 0xc0, 0xeb, 5]); // NULL; skip helper call
    bytes[generic_branch] = u8::try_from(bytes.len() - generic_branch - 1)?;
    bytes[null_branch] = u8::try_from(null - null_branch - 1)?;
    Ok(bytes)
}

#[cfg(all(test, target_arch = "x86_64", target_os = "linux"))]
mod tests {
    use super::*;

    #[test]
    fn runtime_array_executes_key_bounds_mask_wide_product_and_other_type_dispatch() -> Result<()> {
        // Deliberately non-kernel fixture offsets catch hard-coded layout use.
        let layout = RuntimeArrayLayout { map_type: 12, max_entries: 24, elem_size: 32,
            index_mask: 36, value: 64, array_type: 2 };
        let mut code = prefix(&layout)?;
        // Real local call, followed by continuation RET. Generic leaf returns
        // original RDI xor RSI, exposing any corruption of either argument.
        code.extend_from_slice(&[0xe8,1,0,0,0,0xc3,0x48,0x89,0xf8,0x48,0x31,0xf0,0xc3]);
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
        Ok(())
    }
}
