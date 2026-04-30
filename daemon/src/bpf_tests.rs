use super::*;

/// Helper: build a BPF_LD_IMM64 instruction pair with given dst_reg, src_reg, and imm.
fn make_ld_imm64(dst: u8, src: u8, imm_lo: i32, imm_hi: i32) -> [BpfInsn; 2] {
    [
        BpfInsn {
            code: BPF_LD | BPF_IMM | BPF_DW, // 0x18
            regs: (src << 4) | (dst & 0x0f),
            off: 0,
            imm: imm_lo,
        },
        BpfInsn {
            code: 0,
            regs: 0,
            off: 0,
            imm: imm_hi,
        },
    ]
}

/// Verify relocate_map_fds correctly identifies map references via src_reg,
/// not dst_reg. Missing map IDs is now a hard error.
#[test]
fn test_relocate_map_fds_src_reg_extraction() {
    // Instruction with dst_reg=0, src_reg=BPF_PSEUDO_MAP_FD(1), imm=42 (old fd).
    let ld_pair = make_ld_imm64(0, BPF_PSEUDO_MAP_FD, 42, 0);
    let mut insns = vec![ld_pair[0], ld_pair[1]];

    // No map_ids provided -> relocation must fail instead of silently continuing.
    let result = relocate_map_fds(&mut insns, &[]);
    assert!(result.is_err());
    // Old FD remains unpatched since there are no map_ids.
    assert_eq!(insns[0].imm, 42);
}

/// Verify that a BPF_LD_IMM64 with src_reg=0 (not a map reference) is NOT treated
/// as a map reference. This guards against the old bug where dst_reg was read instead
/// of src_reg.
#[test]
fn test_relocate_map_fds_ignores_non_map_ldimm64() {
    // dst_reg=1, src_reg=0 -> NOT a map reference (just a plain 64-bit immediate).
    let ld_pair = make_ld_imm64(1, 0, 99, 0);
    let mut insns = vec![ld_pair[0], ld_pair[1]];

    let result = relocate_map_fds(&mut insns, &[]);
    assert!(result.is_ok());
    let owned = result.unwrap();
    // No map references found, so no FDs returned.
    assert!(owned.is_empty());
    // Instruction unchanged.
    assert_eq!(insns[0].imm, 99);
}

/// Regression test: ensure that an instruction with dst_reg=1 but src_reg=0
/// is NOT mistakenly identified as BPF_PSEUDO_MAP_FD. The old code used
/// `regs & 0x0f` (dst_reg) instead of `(regs >> 4) & 0x0f` (src_reg).
#[test]
fn test_relocate_map_fds_regression_dst_vs_src() {
    // dst_reg=1 (BPF_PSEUDO_MAP_FD value in wrong field), src_reg=0.
    // The old bug would treat this as a map reference.
    let ld_pair = make_ld_imm64(1, 0, 7, 0);
    let mut insns = vec![ld_pair[0], ld_pair[1]];

    let result = relocate_map_fds(&mut insns, &[]);
    assert!(result.is_ok());
    assert!(result.unwrap().is_empty());

    // Now test the opposite: dst_reg=0, src_reg=1 (BPF_PSEUDO_MAP_FD).
    // This should be detected as a map reference.
    let ld_pair = make_ld_imm64(0, 1, 7, 0);
    let mut insns2 = vec![ld_pair[0], ld_pair[1]];

    let result2 = relocate_map_fds(&mut insns2, &[]);
    assert!(result2.is_err());
}

#[test]
fn test_dump_machine_code_groups_bytes_into_lines() {
    let bytes: Vec<u8> = (0..20u8).collect();
    let dump = dump_machine_code(&bytes);

    assert_eq!(dump.byte_len, 20);
    assert_eq!(dump.bytes_per_line, 16);
    assert_eq!(dump.lines.len(), 2);
    assert_eq!(
        dump.lines[0].raw_hex,
        "00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f"
    );
    assert_eq!(dump.lines[1].offset, 16);
    assert_eq!(dump.lines[1].raw_hex, "10 11 12 13");
}

/// Test relocate_map_fds with BPF_PSEUDO_MAP_VALUE (src_reg=2).
#[test]
fn test_relocate_map_fds_pseudo_map_value() {
    let ld_pair = make_ld_imm64(3, BPF_PSEUDO_MAP_VALUE, 55, 0);
    let mut insns = vec![ld_pair[0], ld_pair[1]];

    // Should detect 1 map reference (src_reg=2 = BPF_PSEUDO_MAP_VALUE).
    let result = relocate_map_fds(&mut insns, &[]);
    assert!(result.is_err());
    // imm unchanged since no map_ids to remap.
    assert_eq!(insns[0].imm, 55);
}

/// Test with multiple map references using different old FDs.
#[test]
fn test_relocate_map_fds_multiple_refs() {
    let ld1 = make_ld_imm64(1, BPF_PSEUDO_MAP_FD, 10, 0);
    let ld2 = make_ld_imm64(2, BPF_PSEUDO_MAP_FD, 11, 0);
    let ld3 = make_ld_imm64(3, BPF_PSEUDO_MAP_FD, 10, 0); // duplicate of first
    let mut insns = vec![ld1[0], ld1[1], ld2[0], ld2[1], ld3[0], ld3[1]];

    // 2 unique old FDs (10 and 11), but no map_ids -> hard failure.
    let result = relocate_map_fds(&mut insns, &[]);
    assert!(result.is_err());
}

#[test]
fn test_resolve_map_ids_for_relocation_uses_old_fd_binding_after_map_removal() {
    let resolved = resolve_map_ids_for_relocation(
        &[11, 12],
        &[101, 202, 303],
        &HashMap::from([(11, 202), (12, 303)]),
    );

    assert_eq!(resolved.get(&11), Some(&202));
    assert_eq!(resolved.get(&12), Some(&303));
}

// ── BPF cmd constant sync tests ──────────────────────────────────
//
// These tests parse the kernel UAPI header to verify our hardcoded
// constants match. This is the class of bug that caused BPF_BTF_GET_NEXT_ID
// to be wrong (22 instead of 23) for months.

/// Parse `enum bpf_cmd` from the kernel UAPI header and return a map
/// of name -> numeric value.
fn parse_bpf_cmd_enum() -> std::collections::HashMap<String, u32> {
    let header_path = concat!(
        env!("CARGO_MANIFEST_DIR"),
        "/../vendor/linux-framework/include/uapi/linux/bpf.h"
    );
    let content = std::fs::read_to_string(header_path).expect("failed to read kernel bpf.h header");

    let mut result = std::collections::HashMap::new();
    let mut in_enum = false;
    let mut next_val: u32 = 0;

    for line in content.lines() {
        let trimmed = line.trim();
        if trimmed.starts_with("enum bpf_cmd") {
            in_enum = true;
            next_val = 0;
            continue;
        }
        if in_enum && trimmed.starts_with('}') {
            break;
        }
        if !in_enum {
            continue;
        }
        // Skip empty lines, comments, __MAX_BPF_CMD
        if trimmed.is_empty()
            || trimmed.starts_with("//")
            || trimmed.starts_with("/*")
            || trimmed.starts_with('*')
            || trimmed.starts_with("__MAX")
        {
            continue;
        }
        // Parse lines like "BPF_MAP_CREATE," or "BPF_PROG_RUN = BPF_PROG_TEST_RUN,"
        let name_part = trimmed.trim_end_matches(',');
        if name_part.contains('=') {
            // Alias like BPF_PROG_RUN = BPF_PROG_TEST_RUN — skip (same value)
            let parts: Vec<&str> = name_part.split('=').collect();
            let name = parts[0].trim().to_string();
            let rhs = parts[1].trim();
            // rhs is another enum name — look it up
            if let Some(&val) = result.get(rhs) {
                result.insert(name, val);
            }
            // Do NOT increment next_val for aliases
            continue;
        }
        let name = name_part.trim().to_string();
        if name.starts_with("BPF_") {
            result.insert(name, next_val);
            next_val += 1;
        }
    }
    result
}

#[test]
fn test_bpf_cmd_constants_match_kernel_header() {
    let kernel_cmds = parse_bpf_cmd_enum();
    assert!(
        !kernel_cmds.is_empty(),
        "failed to parse any bpf_cmd entries from kernel header"
    );

    // Verify every constant we define in bpf.rs matches the kernel.
    let checks = [
        ("BPF_PROG_GET_NEXT_ID", BPF_PROG_GET_NEXT_ID),
        ("BPF_MAP_GET_NEXT_ID", BPF_MAP_GET_NEXT_ID),
        ("BPF_PROG_GET_FD_BY_ID", BPF_PROG_GET_FD_BY_ID),
        ("BPF_MAP_GET_FD_BY_ID", BPF_MAP_GET_FD_BY_ID),
        ("BPF_OBJ_GET_INFO_BY_FD", BPF_OBJ_GET_INFO_BY_FD),
        ("BPF_BTF_LOAD", BPF_BTF_LOAD),
        ("BPF_BTF_GET_FD_BY_ID", BPF_BTF_GET_FD_BY_ID),
        ("BPF_BTF_GET_NEXT_ID", BPF_BTF_GET_NEXT_ID),
        ("BPF_PROG_REJIT", BPF_PROG_REJIT),
    ];

    for (name, our_value) in &checks {
        let kernel_value = kernel_cmds.get(*name).unwrap_or_else(|| {
            panic!(
                "{} not found in kernel header enum bpf_cmd (parsed {} entries)",
                name,
                kernel_cmds.len()
            )
        });
        assert_eq!(
            *our_value, *kernel_value,
            "BPF cmd constant mismatch: {} = {} in bpf.rs but {} in kernel header",
            name, our_value, kernel_value
        );
    }
}

// ── Struct size and layout tests ─────────────────────────────────
//
// Each attr variant we still use must fit in 128 bytes (the kernel's
// union bpf_attr size). The legacy `AttrProgLoad` was deleted along with
// the BPF_PROG_LOAD-based per-pass pre-verify path; daemon-side verify
// goes through `AttrRejit` exclusively now.

#[test]
fn test_attr_struct_sizes_fit_bpf_attr() {
    assert_eq!(
        std::mem::size_of::<AttrGetNextId>(),
        128,
        "AttrGetNextId must be 128 bytes"
    );
    assert_eq!(
        std::mem::size_of::<AttrGetFdById>(),
        128,
        "AttrGetFdById must be 128 bytes"
    );
    assert_eq!(
        std::mem::size_of::<AttrGetInfoByFd>(),
        128,
        "AttrGetInfoByFd must be 128 bytes"
    );
    assert_eq!(
        std::mem::size_of::<AttrRejit>(),
        128,
        "AttrRejit must be 128 bytes"
    );
}

#[test]
fn test_attr_rejit_field_offsets() {
    // Verify AttrRejit field layout matches kernel's union bpf_attr.rejit.
    // Kernel layout (from bpf.h):
    //   __u32          prog_fd;       // offset 0
    //   __u32          insn_cnt;      // offset 4
    //   __aligned_u64  insns;         // offset 8
    //   __u32          log_level;     // offset 16
    //   __u32          log_size;      // offset 20
    //   __aligned_u64  log_buf;       // offset 24
    //   __aligned_u64  fd_array;      // offset 32
    //   __u32          fd_array_cnt;  // offset 40
    //   __u32          flags;         // offset 44

    let attr: AttrRejit = unsafe { std::mem::zeroed() };
    let base_addr = &attr as *const _ as usize;

    assert_eq!(
        &attr.prog_fd as *const _ as usize - base_addr,
        0,
        "prog_fd at wrong offset"
    );
    assert_eq!(
        &attr.insn_cnt as *const _ as usize - base_addr,
        4,
        "insn_cnt at wrong offset"
    );
    assert_eq!(
        &attr.insns as *const _ as usize - base_addr,
        8,
        "insns at wrong offset"
    );
    assert_eq!(
        &attr.log_level as *const _ as usize - base_addr,
        16,
        "log_level at wrong offset"
    );
    assert_eq!(
        &attr.log_size as *const _ as usize - base_addr,
        20,
        "log_size at wrong offset"
    );
    assert_eq!(
        &attr.log_buf as *const _ as usize - base_addr,
        24,
        "log_buf at wrong offset"
    );
    assert_eq!(
        &attr.fd_array as *const _ as usize - base_addr,
        32,
        "fd_array at wrong offset"
    );
    assert_eq!(
        &attr.fd_array_cnt as *const _ as usize - base_addr,
        40,
        "fd_array_cnt at wrong offset"
    );
    assert_eq!(
        &attr.flags as *const _ as usize - base_addr,
        44,
        "flags at wrong offset"
    );
}

#[test]
fn test_bpf_prog_info_size() {
    // BpfProgInfo includes BpfReJIT extension fields (orig_prog_len, orig_prog_insns).
    // Layout: orig_prog_len (u32, offset 228) + 4 bytes padding + orig_prog_insns (u64, offset 232).
    // Total: 232 + 8 = 240 bytes (with __attribute__((aligned(8)))).
    let size = std::mem::size_of::<BpfProgInfo>();
    assert_eq!(
        size, 240,
        "BpfProgInfo size mismatch: got {} bytes, expected 240 (from kernel struct bpf_prog_info)",
        size
    );
}

/// HIGH #1 + MEDIUM #1 + MEDIUM #2: Verify BpfProgInfo field-by-field layout
/// against known offsets from kernel `struct bpf_prog_info` in
/// vendor/linux-framework/include/uapi/linux/bpf.h.
///
/// The kernel struct uses `__aligned_u64` for 8-byte aligned fields.
/// Computing expected offsets manually from the kernel header:
///   __u32 type                 -> offset 0
///   __u32 id                   -> offset 4
///   __u8  tag[8]               -> offset 8
///   __u32 jited_prog_len       -> offset 16
///   __u32 xlated_prog_len      -> offset 20
///   __aligned_u64 jited_prog_insns -> offset 24
///   __aligned_u64 xlated_prog_insns -> offset 32
///   __u64 load_time            -> offset 40
///   __u32 created_by_uid       -> offset 48
///   __u32 nr_map_ids           -> offset 52
///   __aligned_u64 map_ids      -> offset 56
///   char name[16]              -> offset 64
///   __u32 ifindex              -> offset 80
///   __u32 gpl_compatible:1 + pad -> offset 84
///   __u64 netns_dev            -> offset 88
///   __u64 netns_ino            -> offset 96
///   __u32 nr_jited_ksyms       -> offset 104
///   __u32 nr_jited_func_lens   -> offset 108
///   __aligned_u64 jited_ksyms  -> offset 112
///   __aligned_u64 jited_func_lens -> offset 120
///   __u32 btf_id               -> offset 128
///   __u32 func_info_rec_size   -> offset 132
///   __aligned_u64 func_info    -> offset 136
///   __u32 nr_func_info         -> offset 144
///   __u32 nr_line_info         -> offset 148
///   __aligned_u64 line_info    -> offset 152
///   __aligned_u64 jited_line_info -> offset 160
///   __u32 nr_jited_line_info   -> offset 168
///   __u32 line_info_rec_size   -> offset 172
///   __u32 jited_line_info_rec_size -> offset 176
///   __u32 nr_prog_tags         -> offset 180
///   __aligned_u64 prog_tags    -> offset 184
///   __u64 run_time_ns          -> offset 192
///   __u64 run_cnt              -> offset 200
///   __u64 recursion_misses     -> offset 208
///   __u32 verified_insns       -> offset 216
///   __u32 attach_btf_obj_id    -> offset 220
///   __u32 attach_btf_id        -> offset 224
///   __u32 orig_prog_len        -> offset 228  (BpfReJIT extension)
///   __aligned_u64 orig_prog_insns -> offset 232 -> but struct aligned(8), so pad to 232? No.
///   Actually orig_prog_len is u32 at 228, and orig_prog_insns is __aligned_u64, so
///   it needs 8-byte alignment: pad from 232 -> stays at 232. Wait, 228+4=232 which IS
///   8-byte aligned, so orig_prog_insns is at offset 232... but that would make the struct
///   232+8=240 bytes. Let me verify via the actual Rust layout.
#[test]
fn test_bpf_prog_info_field_offsets() {
    let info = BpfProgInfo::default();
    let base = &info as *const _ as usize;

    // Helper macro to compute offset
    macro_rules! check_offset {
        ($field:ident, $expected:expr) => {
            let actual = &info.$field as *const _ as usize - base;
            assert_eq!(
                actual,
                $expected,
                "BpfProgInfo.{} offset mismatch: got {} expected {}",
                stringify!($field),
                actual,
                $expected
            );
        };
    }

    // Critical fields verified against kernel header struct bpf_prog_info
    check_offset!(prog_type, 0);
    check_offset!(id, 4);
    check_offset!(tag, 8);
    check_offset!(jited_prog_len, 16);
    check_offset!(xlated_prog_len, 20);
    check_offset!(jited_prog_insns, 24);
    check_offset!(xlated_prog_insns, 32);
    check_offset!(load_time, 40);
    check_offset!(created_by_uid, 48);
    check_offset!(nr_map_ids, 52);
    check_offset!(map_ids, 56);
    check_offset!(name, 64);
    check_offset!(ifindex, 80);
    check_offset!(gpl_compatible_pad, 84);
    check_offset!(netns_dev, 88);
    check_offset!(netns_ino, 96);
    check_offset!(nr_jited_ksyms, 104);
    check_offset!(nr_jited_func_lens, 108);
    check_offset!(jited_ksyms, 112);
    check_offset!(jited_func_lens, 120);
    check_offset!(btf_id, 128);
    check_offset!(func_info_rec_size, 132);
    check_offset!(func_info, 136);
    check_offset!(nr_func_info, 144);
    check_offset!(nr_line_info, 148);
    check_offset!(line_info, 152);
    check_offset!(jited_line_info, 160);
    check_offset!(nr_jited_line_info, 168);
    check_offset!(line_info_rec_size, 172);
    check_offset!(jited_line_info_rec_size, 176);
    check_offset!(nr_prog_tags, 180);
    check_offset!(prog_tags, 184);
    check_offset!(run_time_ns, 192);
    check_offset!(run_cnt, 200);
    check_offset!(recursion_misses, 208);
    check_offset!(verified_insns, 216);
    check_offset!(attach_btf_obj_id, 220);
    check_offset!(attach_btf_id, 224);

    // BpfReJIT extension fields (orig_prog_len, orig_prog_insns)
    // These are at the end of the kernel struct:
    //   __u32 orig_prog_len       -> offset 228
    //   __aligned_u64 orig_prog_insns -> must be 8-byte aligned
    check_offset!(orig_prog_len, 228);

    // orig_prog_insns: u32 at 228 occupies bytes 228..232.
    // __aligned_u64 needs 8-byte alignment. 232 % 8 == 0, so no padding needed.
    // But in our Rust struct it's declared as u64 after a u32, the compiler may
    // or may not pad. Let's just verify it's the expected value.
    let orig_insns_offset = &info.orig_prog_insns as *const _ as usize - base;
    // In the kernel struct, attach_btf_id is at 224, orig_prog_len at 228.
    // orig_prog_insns (__aligned_u64) must be at 232 (next 8-byte boundary after 232).
    // But wait: 228 + 4 = 232, which IS 8-byte aligned.
    // However, our Rust struct might not pad. Check both possibilities.
    assert!(
        orig_insns_offset >= 232,
        "orig_prog_insns should be at offset >= 232, got {}",
        orig_insns_offset
    );

    // Verify orig_prog_insns is the last field
    assert_eq!(
        orig_insns_offset + std::mem::size_of::<u64>(),
        std::mem::size_of::<BpfProgInfo>(),
        "orig_prog_insns should be the last field in BpfProgInfo"
    );
}

/// HIGH #1 continued: Parse kernel header to verify BpfProgInfo field layout.
/// This reads the actual kernel header file and computes struct field offsets
/// using C struct layout rules (including __aligned_u64 = 8-byte alignment).
#[test]
fn test_bpf_prog_info_layout_matches_kernel_header() {
    let header_path = concat!(
        env!("CARGO_MANIFEST_DIR"),
        "/../vendor/linux-framework/include/uapi/linux/bpf.h"
    );
    let content = std::fs::read_to_string(header_path).expect("failed to read kernel bpf.h header");

    // Find the struct bpf_prog_info definition and extract field names+types.
    let mut in_struct = false;
    let mut fields: Vec<(String, usize, usize)> = Vec::new(); // (name, size, alignment)
    for line in content.lines() {
        let trimmed = line.trim();
        if trimmed == "struct bpf_prog_info {" {
            in_struct = true;
            continue;
        }
        if in_struct && trimmed.starts_with('}') {
            break;
        }
        if !in_struct {
            continue;
        }
        // Skip comments and empty lines
        if trimmed.is_empty()
            || trimmed.starts_with("/*")
            || trimmed.starts_with("*")
            || trimmed.starts_with("//")
        {
            continue;
        }
        // Parse field: e.g., "__u32 type;" or "__aligned_u64 jited_prog_insns;"
        // or "__u8  tag[BPF_TAG_SIZE];" or "char name[BPF_OBJ_NAME_LEN];"
        // or "__u32 gpl_compatible:1;" or "__u32 :31; /* alignment pad */"
        let clean = trimmed.trim_end_matches(';').trim();
        // Skip anonymous bitfields like "__u32 :31"
        if clean.contains(":") && !clean.contains("_compatible") {
            // Check if it's a named bitfield (like gpl_compatible:1) or anonymous
            let parts: Vec<&str> = clean.split_whitespace().collect();
            if parts.len() >= 2 && parts[1].starts_with(':') {
                // Anonymous bitfield like "__u32 :31" — skip (part of previous u32)
                continue;
            }
        }

        // Parse type and name
        let parts: Vec<&str> = clean.split_whitespace().collect();
        if parts.len() < 2 {
            continue;
        }
        let type_str = parts[0];
        let mut name_str = parts[1].trim_end_matches(|c: char| c == ',' || c == ';');
        // Handle bitfield notation: "gpl_compatible:1"
        if let Some(colon) = name_str.find(':') {
            name_str = &name_str[..colon];
        }
        // Handle array notation: "tag[BPF_TAG_SIZE]" -> "tag"
        let field_name = if let Some(bracket) = name_str.find('[') {
            &name_str[..bracket]
        } else {
            name_str
        };

        // Determine size and alignment
        let (size, align) = match type_str {
            "__u32" | "__s32" => {
                if clean.contains("[BPF_TAG_SIZE]") {
                    (8, 1) // __u8 tag[8] — but this is __u32 tag... wait
                } else if clean.contains("gpl_compatible") {
                    // gpl_compatible:1 + :31 pad = 4 bytes total
                    (4, 4)
                } else {
                    (4, 4)
                }
            }
            "__u8" => {
                if clean.contains("[BPF_TAG_SIZE]") {
                    (8, 1)
                } else {
                    (1, 1)
                }
            }
            "char" => {
                if clean.contains("[BPF_OBJ_NAME_LEN]") {
                    (16, 1)
                } else {
                    (1, 1)
                }
            }
            "__u64" | "__s64" => (8, 8),
            "__aligned_u64" => (8, 8),
            _ => continue,
        };

        fields.push((field_name.to_string(), size, align));
    }

    assert!(
        !fields.is_empty(),
        "failed to parse any fields from struct bpf_prog_info"
    );

    // Compute offsets using C struct layout rules
    let mut offset = 0usize;
    let mut kernel_offsets: Vec<(String, usize)> = Vec::new();
    for (name, size, align) in &fields {
        // Align to field alignment
        let padding = (align - (offset % align)) % align;
        offset += padding;
        kernel_offsets.push((name.clone(), offset));
        offset += size;
    }

    // Verify our Rust struct matches the kernel layout for key fields
    let info = BpfProgInfo::default();
    let base = &info as *const _ as usize;

    let rust_offsets: Vec<(&str, usize)> = vec![
        ("type", &info.prog_type as *const _ as usize - base),
        ("id", &info.id as *const _ as usize - base),
        ("tag", &info.tag as *const _ as usize - base),
        (
            "jited_prog_len",
            &info.jited_prog_len as *const _ as usize - base,
        ),
        (
            "xlated_prog_len",
            &info.xlated_prog_len as *const _ as usize - base,
        ),
        ("nr_map_ids", &info.nr_map_ids as *const _ as usize - base),
        ("name", &info.name as *const _ as usize - base),
        ("btf_id", &info.btf_id as *const _ as usize - base),
        ("run_time_ns", &info.run_time_ns as *const _ as usize - base),
        ("run_cnt", &info.run_cnt as *const _ as usize - base),
        (
            "verified_insns",
            &info.verified_insns as *const _ as usize - base,
        ),
        (
            "attach_btf_obj_id",
            &info.attach_btf_obj_id as *const _ as usize - base,
        ),
        (
            "attach_btf_id",
            &info.attach_btf_id as *const _ as usize - base,
        ),
        (
            "orig_prog_len",
            &info.orig_prog_len as *const _ as usize - base,
        ),
        (
            "orig_prog_insns",
            &info.orig_prog_insns as *const _ as usize - base,
        ),
    ];

    for (rust_name, rust_offset) in &rust_offsets {
        // The kernel header uses "type" for prog_type; map it
        let kernel_name = *rust_name;
        if let Some((_, kernel_offset)) = kernel_offsets.iter().find(|(n, _)| n == kernel_name) {
            assert_eq!(
                *rust_offset, *kernel_offset,
                "BpfProgInfo field '{}' offset mismatch: Rust={} kernel={}",
                rust_name, rust_offset, kernel_offset
            );
        }
    }
}

#[test]
fn test_bpf_prog_info_name_str() {
    let mut info = BpfProgInfo::default();
    // Empty name (all zeros)
    assert_eq!(info.name_str(), "");

    // Normal name
    info.name[0] = b'x';
    info.name[1] = b'd';
    info.name[2] = b'p';
    assert_eq!(info.name_str(), "xdp");

    // Full-length name (no NUL terminator within array)
    for i in 0..BPF_OBJ_NAME_LEN {
        info.name[i] = b'a';
    }
    assert_eq!(info.name_str(), "a".repeat(BPF_OBJ_NAME_LEN));
}

#[test]
fn test_btf_info_struct_size() {
    // BtfInfo must be exactly 128 bytes (padded to match bpf_attr size).
    assert_eq!(
        std::mem::size_of::<BtfInfo>(),
        128,
        "BtfInfo must be 128 bytes"
    );
}

/// HIGH #5: Verify BtfInfo field layout matches kernel `struct bpf_btf_info`.
///
/// From vendor/linux-framework/include/uapi/linux/bpf.h:
///   struct bpf_btf_info {
///       __aligned_u64 btf;       // offset 0
///       __u32 btf_size;          // offset 8
///       __u32 id;                // offset 12
///       __aligned_u64 name;      // offset 16
///       __u32 name_len;          // offset 24
///       __u32 kernel_btf;        // offset 28
///   } __attribute__((aligned(8)));
#[test]
fn test_btf_info_field_offsets() {
    let info: BtfInfo = unsafe { std::mem::zeroed() };
    let base = &info as *const _ as usize;

    assert_eq!(
        &info.btf as *const _ as usize - base,
        0,
        "BtfInfo.btf at wrong offset"
    );
    assert_eq!(
        &info.btf_size as *const _ as usize - base,
        8,
        "BtfInfo.btf_size at wrong offset"
    );
    assert_eq!(
        &info.id as *const _ as usize - base,
        12,
        "BtfInfo.id at wrong offset"
    );
    assert_eq!(
        &info.name as *const _ as usize - base,
        16,
        "BtfInfo.name at wrong offset"
    );
    assert_eq!(
        &info.name_len as *const _ as usize - base,
        24,
        "BtfInfo.name_len at wrong offset"
    );
    assert_eq!(
        &info.kernel_btf as *const _ as usize - base,
        28,
        "BtfInfo.kernel_btf at wrong offset"
    );
}

/// HIGH #5 continued: Parse kernel header to verify BtfInfo layout.
#[test]
fn test_btf_info_layout_matches_kernel_header() {
    let header_path = concat!(
        env!("CARGO_MANIFEST_DIR"),
        "/../vendor/linux-framework/include/uapi/linux/bpf.h"
    );
    let content = std::fs::read_to_string(header_path).expect("failed to read kernel bpf.h header");

    // Find struct bpf_btf_info
    let mut in_struct = false;
    let mut field_names: Vec<String> = Vec::new();
    for line in content.lines() {
        let trimmed = line.trim();
        if trimmed == "struct bpf_btf_info {" {
            in_struct = true;
            continue;
        }
        if in_struct && trimmed.starts_with('}') {
            break;
        }
        if !in_struct
            || trimmed.is_empty()
            || trimmed.starts_with("/*")
            || trimmed.starts_with("*")
            || trimmed.starts_with("//")
        {
            continue;
        }
        let clean = trimmed.trim_end_matches(';').trim();
        let parts: Vec<&str> = clean.split_whitespace().collect();
        if parts.len() >= 2 {
            field_names.push(parts[1].trim_end_matches(';').to_string());
        }
    }

    // Verify the kernel header has the expected fields in order
    assert!(
        field_names.contains(&"btf".to_string()),
        "kernel bpf_btf_info missing 'btf' field"
    );
    assert!(
        field_names.contains(&"btf_size".to_string()),
        "kernel bpf_btf_info missing 'btf_size' field"
    );
    assert!(
        field_names.contains(&"id".to_string()),
        "kernel bpf_btf_info missing 'id' field"
    );
    assert!(
        field_names.contains(&"name".to_string()),
        "kernel bpf_btf_info missing 'name' field"
    );
    assert!(
        field_names.contains(&"name_len".to_string()),
        "kernel bpf_btf_info missing 'name_len' field"
    );
    assert!(
        field_names.contains(&"kernel_btf".to_string()),
        "kernel bpf_btf_info missing 'kernel_btf' field"
    );
}

#[test]
fn test_relocate_map_fds_with_non_map_instructions() {
    // Program with no LD_IMM64 instructions at all.
    let mut insns = vec![
        BpfInsn::mov64_imm(0, 42),
        BpfInsn {
            // exit instruction: BPF_JMP(0x05) | BPF_EXIT(0x90) = 0x95
            code: 0x95,
            regs: 0,
            off: 0,
            imm: 0,
        },
    ];
    let result = relocate_map_fds(&mut insns, &[]);
    assert!(result.is_ok());
    assert!(result.unwrap().is_empty());
}

#[test]
fn test_relocate_map_fds_empty_program() {
    let mut insns: Vec<BpfInsn> = vec![];
    let result = relocate_map_fds(&mut insns, &[]);
    assert!(result.is_ok());
    assert!(result.unwrap().is_empty());
}

#[test]
fn test_mock_array_lookup_returns_zero_for_in_range_missing_key() {
    let mut info = BpfMapInfo::default();
    info.id = 9001;
    info.map_type = BPF_MAP_TYPE_ARRAY;
    info.key_size = 4;
    info.value_size = 8;
    info.max_entries = 4;
    install_mock_map(
        info.id,
        MockMapState {
            info,
            frozen: true,
            values: std::collections::HashMap::new(),
        },
    );

    let value = bpf_map_lookup_elem_by_id(9001, &[2, 0, 0, 0], 8).expect("array lookup");
    assert_eq!(value, vec![0u8; 8]);
}

#[test]
fn test_mock_hash_lookup_missing_key_still_errors() {
    let mut info = BpfMapInfo::default();
    info.id = 9002;
    info.map_type = 1;
    info.key_size = 4;
    info.value_size = 8;
    info.max_entries = 4;
    install_mock_map(
        info.id,
        MockMapState {
            info,
            frozen: true,
            values: std::collections::HashMap::new(),
        },
    );

    let err = bpf_map_lookup_elem_by_id(9002, &[2, 0, 0, 0], 8).expect_err("hash miss");
    assert!(err.to_string().contains("missing key"));
}

#[test]
fn test_mock_percpu_array_lookup_uses_full_blob_size() {
    let mut info = BpfMapInfo::default();
    info.id = 9003;
    info.map_type = BPF_MAP_TYPE_PERCPU_ARRAY;
    info.key_size = 4;
    info.value_size = 4;
    info.max_entries = 4;
    let mut value = vec![0u8; round_up_8(4) * 2];
    value[..4].copy_from_slice(&7u32.to_le_bytes());
    value[8..12].copy_from_slice(&7u32.to_le_bytes());
    install_mock_map(
        info.id,
        MockMapState {
            info,
            frozen: true,
            values: std::collections::HashMap::from([(1u32.to_le_bytes().to_vec(), value.clone())]),
        },
    );

    let lookup_size = bpf_map_lookup_value_size_by_id(9003).expect("lookup size");
    assert_eq!(lookup_size, value.len());
    let fetched =
        bpf_map_lookup_elem_by_id(9003, &1u32.to_le_bytes(), lookup_size).expect("lookup");
    assert_eq!(fetched, value);
}

#[test]
fn test_mock_percpu_array_lookup_returns_zero_for_in_range_missing_key() {
    let mut info = BpfMapInfo::default();
    info.id = 9004;
    info.map_type = BPF_MAP_TYPE_PERCPU_ARRAY;
    info.key_size = 4;
    info.value_size = 8;
    info.max_entries = 4;
    install_mock_map(
        info.id,
        MockMapState {
            info,
            frozen: true,
            values: std::collections::HashMap::new(),
        },
    );

    let lookup_size = bpf_map_lookup_value_size_by_id(9004).expect("lookup size");
    let value = bpf_map_lookup_elem_by_id(9004, &2u32.to_le_bytes(), lookup_size).expect("lookup");
    assert_eq!(value, vec![0u8; lookup_size]);
}
