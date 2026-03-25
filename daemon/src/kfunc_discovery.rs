// SPDX-License-Identifier: MIT
//! kinsn descriptor auto-discovery via `/sys/kernel/btf/` module BTF scanning.
//!
//! Scans loaded kernel modules for known kinsn descriptor variables and
//! populates a `KinsnRegistry` with their descriptor IDs and transport BTF FDs.

use std::collections::HashMap;
use std::fs;
use std::os::unix::io::OwnedFd;
use std::path::Path;

use anyhow::{bail, Context, Result};

use crate::insn::BPF_KINSN_ENC_PACKED_CALL;
use crate::pass::KinsnRegistry;

// ── Known kinsn descriptor → module mapping ──────────────────────────

/// A kinsn target we want to discover:
/// (registry_key, descriptor_var_name, module_name).
const KNOWN_KINSNS: &[(&str, &str, &str)] = &[
    ("bpf_rotate64", "bpf_rotate64_desc", "bpf_rotate"),
    ("bpf_select64", "bpf_select64_desc", "bpf_select"),
    ("bpf_extract64", "bpf_extract64_desc", "bpf_extract"),
    ("bpf_endian_load16", "bpf_endian_load16_desc", "bpf_endian"),
    ("bpf_endian_load32", "bpf_endian_load32_desc", "bpf_endian"),
    ("bpf_endian_load64", "bpf_endian_load64_desc", "bpf_endian"),
    (
        "bpf_speculation_barrier",
        "bpf_speculation_barrier_desc",
        "bpf_barrier",
    ),
];

// ── BTF constants (synced from vendor/linux-framework/include/uapi/linux/btf.h) ──

const BTF_MAGIC: u16 = 0xEB9F;

// BTF_KIND_* constants (from include/uapi/linux/btf.h).
// Production code uses the subset matched in extra_bytes_for_kind(); tests validate all values.
const BTF_KIND_INT: u32 = 1;
#[cfg_attr(not(test), allow(dead_code))]
const BTF_KIND_PTR: u32 = 2;
const BTF_KIND_ARRAY: u32 = 3;
const BTF_KIND_STRUCT: u32 = 4;
const BTF_KIND_UNION: u32 = 5;
const BTF_KIND_ENUM: u32 = 6;
#[cfg_attr(not(test), allow(dead_code))]
const BTF_KIND_FWD: u32 = 7;
#[cfg_attr(not(test), allow(dead_code))]
const BTF_KIND_TYPEDEF: u32 = 8;
#[cfg_attr(not(test), allow(dead_code))]
const BTF_KIND_VOLATILE: u32 = 9;
#[cfg_attr(not(test), allow(dead_code))]
const BTF_KIND_CONST: u32 = 10;
#[cfg_attr(not(test), allow(dead_code))]
const BTF_KIND_RESTRICT: u32 = 11;
const BTF_KIND_FUNC: u32 = 12;
const BTF_KIND_FUNC_PROTO: u32 = 13;
const BTF_KIND_VAR: u32 = 14;
const BTF_KIND_DATASEC: u32 = 15;
#[cfg_attr(not(test), allow(dead_code))]
const BTF_KIND_FLOAT: u32 = 16;
const BTF_KIND_DECL_TAG: u32 = 17;
#[cfg_attr(not(test), allow(dead_code))]
const BTF_KIND_TYPE_TAG: u32 = 18;
const BTF_KIND_ENUM64: u32 = 19;

/// Minimal BTF header (24 bytes).
#[repr(C)]
#[derive(Debug, Clone, Copy)]
struct BtfHeader {
    magic: u16,
    version: u8,
    flags: u8,
    hdr_len: u32,
    type_off: u32,
    type_len: u32,
    str_off: u32,
    str_len: u32,
}

const BTF_HEADER_SIZE: usize = std::mem::size_of::<BtfHeader>();

/// Minimal BTF type entry (12 bytes).
#[repr(C)]
#[derive(Debug, Clone, Copy)]
struct BtfType {
    name_off: u32,
    /// Bits [31:24] = vlen, [28] = kflag, [27:24] = kind (packed).
    /// Actually: kind_flag is bit 31, kind is bits [28:24], vlen is bits [15:0].
    info: u32,
    /// Type-specific data (for FUNC: type_id of the function prototype).
    size_or_type: u32,
}

const BTF_TYPE_SIZE: usize = std::mem::size_of::<BtfType>();

impl BtfType {
    fn kind(&self) -> u32 {
        (self.info >> 24) & 0x1f
    }
}

// ── BTF parsing ──────────────────────────────────────────────────────

fn btf_type_extra_bytes(bt: &BtfType) -> usize {
    let kind = bt.kind();
    let vlen = (bt.info & 0xffff) as usize;

    match kind {
        BTF_KIND_INT => 4,                             // u32 encoding data
        BTF_KIND_ARRAY => 12,                          // struct btf_array (3 * u32)
        BTF_KIND_STRUCT | BTF_KIND_UNION => vlen * 12, // btf_member = 12 bytes each
        BTF_KIND_ENUM => vlen * 8,                     // btf_enum = 8 bytes each
        BTF_KIND_FUNC_PROTO => vlen * 8,               // btf_param = 8 bytes each
        BTF_KIND_VAR => 4,                             // u32 linkage
        BTF_KIND_DATASEC => vlen * 12,                 // btf_var_secinfo = 12 bytes each
        BTF_KIND_DECL_TAG => 4,                        // u32 component_idx
        BTF_KIND_ENUM64 => vlen * 12,                  // btf_enum64 = 12 bytes each
        // PTR/FWD/TYPEDEF/VOLATILE/CONST/RESTRICT/FUNC/FLOAT/TYPE_TAG: no extra data
        _ => 0,
    }
}

fn count_btf_types(btf_data: &[u8]) -> Result<u32> {
    if btf_data.len() < BTF_HEADER_SIZE {
        bail!("BTF too small ({} bytes)", btf_data.len());
    }

    let hdr: BtfHeader = unsafe { std::ptr::read_unaligned(btf_data.as_ptr() as *const BtfHeader) };
    if hdr.magic != BTF_MAGIC {
        bail!("BTF bad magic: 0x{:04x}", hdr.magic);
    }

    let hdr_len = hdr.hdr_len as usize;
    let type_start = hdr_len + hdr.type_off as usize;
    let type_end = type_start + hdr.type_len as usize;
    if type_end > btf_data.len() {
        bail!("BTF type section exceeds blob");
    }

    let type_section = &btf_data[type_start..type_end];
    let mut offset = 0usize;
    let mut type_cnt = 1u32; // type ID 0 is void

    while offset + BTF_TYPE_SIZE <= type_section.len() {
        let bt: BtfType =
            unsafe { std::ptr::read_unaligned(type_section[offset..].as_ptr() as *const BtfType) };
        let extra = btf_type_extra_bytes(&bt);

        offset += BTF_TYPE_SIZE;
        if offset + extra > type_section.len() {
            bail!("BTF type section truncated");
        }
        offset += extra;
        type_cnt += 1;
    }

    if offset != type_section.len() {
        bail!("BTF type section has trailing bytes");
    }

    Ok(type_cnt)
}

/// Read the vmlinux layout pieces needed to interpret split module BTF blobs.
///
/// For `/sys/kernel/btf/<module>`:
/// - `name_off` values are biased by vmlinux's string-section length
/// - local module type IDs must be shifted by vmlinux's type count to match
///   the kernel-visible absolute BTF IDs accepted by the verifier
fn get_vmlinux_layout() -> Result<(u32, u32)> {
    let data = fs::read("/sys/kernel/btf/vmlinux").with_context(|| "read vmlinux BTF")?;
    if data.len() < BTF_HEADER_SIZE {
        bail!("vmlinux BTF too small ({} bytes)", data.len());
    }

    let hdr: BtfHeader = unsafe { std::ptr::read_unaligned(data.as_ptr() as *const BtfHeader) };
    if hdr.magic != BTF_MAGIC {
        bail!("vmlinux BTF bad magic: 0x{:04x}", hdr.magic);
    }

    Ok((hdr.str_len, count_btf_types(&data)?))
}

/// Parse a (possibly split) BTF blob and find the BTF type ID for `kind`
/// with the given name. Returns the 1-based type ID, or None if not found.
///
/// `base_str_off` is the vmlinux string section length. For split module BTF,
/// `name_off` values >= `base_str_off` reference the module's own string
/// section at local offset `name_off - base_str_off`. For standalone BTF
/// (base_str_off == 0), name_off indexes the local string section directly.
///
fn find_kind_btf_id(
    btf_data: &[u8],
    type_name: &str,
    kind_wanted: u32,
    base_str_off: u32,
    type_id_bias: u32,
) -> Option<i32> {
    if btf_data.len() < BTF_HEADER_SIZE {
        return None;
    }

    // Parse header.
    let hdr: BtfHeader = unsafe { std::ptr::read_unaligned(btf_data.as_ptr() as *const BtfHeader) };

    if hdr.magic != BTF_MAGIC {
        return None;
    }

    let hdr_len = hdr.hdr_len as usize;
    let type_start = hdr_len + hdr.type_off as usize;
    let type_end = type_start + hdr.type_len as usize;
    let str_start = hdr_len + hdr.str_off as usize;
    let str_end = str_start + hdr.str_len as usize;

    if type_end > btf_data.len() || str_end > btf_data.len() {
        return None;
    }

    let type_section = &btf_data[type_start..type_end];
    let str_section = &btf_data[str_start..str_end];
    let base_off = base_str_off as usize;

    // Walk the type section. BTF type IDs are 1-based.
    let mut offset = 0usize;
    let mut type_id: i32 = 1;

    while offset + BTF_TYPE_SIZE <= type_section.len() {
        let bt: BtfType =
            unsafe { std::ptr::read_unaligned(type_section[offset..].as_ptr() as *const BtfType) };

        let kind = bt.kind();

        if kind == kind_wanted {
            // Resolve name from string section.
            // For split BTF, name_off >= base_str_off means a module-local string
            // at local offset (name_off - base_str_off).
            // For standalone BTF (base_str_off == 0), name_off indexes directly.
            let raw_off = bt.name_off as usize;
            let local_off = if base_off > 0 && raw_off >= base_off {
                raw_off - base_off
            } else {
                raw_off
            };
            if local_off < str_section.len() {
                let name_bytes = &str_section[local_off..];
                let nul_pos = name_bytes
                    .iter()
                    .position(|&b| b == 0)
                    .unwrap_or(name_bytes.len());
                if let Ok(name) = std::str::from_utf8(&name_bytes[..nul_pos]) {
                    if name == type_name {
                        return Some(type_id + type_id_bias as i32);
                    }
                }
            }
        }

        // Advance past the base BtfType entry.
        offset += BTF_TYPE_SIZE;

        // Some BTF kinds have additional data after the base entry.
        // We need to skip those to correctly walk the type section.
        // Kind constants from vendor/linux-framework/include/uapi/linux/btf.h.
        let skip = btf_type_extra_bytes(&bt);
        offset += skip;

        type_id += 1;
    }

    None
}

fn find_func_btf_id(
    btf_data: &[u8],
    func_name: &str,
    base_str_off: u32,
    type_id_bias: u32,
) -> Option<i32> {
    find_kind_btf_id(
        btf_data,
        func_name,
        BTF_KIND_FUNC,
        base_str_off,
        type_id_bias,
    )
}

fn find_var_btf_id(
    btf_data: &[u8],
    var_name: &str,
    base_str_off: u32,
    type_id_bias: u32,
) -> Option<i32> {
    find_kind_btf_id(btf_data, var_name, BTF_KIND_VAR, base_str_off, type_id_bias)
}

// ── Module BTF file operations ───────────────────────────────────────

/// Read raw BTF data from `/sys/kernel/btf/<module>`.
fn read_module_btf(module_name: &str) -> Result<Vec<u8>> {
    let path = format!("/sys/kernel/btf/{}", module_name);
    fs::read(&path).with_context(|| format!("read BTF for module '{}'", module_name))
}

// ── Discovery entry point ────────────────────────────────────────────

/// Result of kinsn discovery.
#[derive(Debug)]
pub struct DiscoveryResult {
    pub registry: KinsnRegistry,
    /// Descriptor BTF FDs to keep alive for the daemon's lifetime.
    /// When these are dropped, the FDs close and REJIT can no longer reference them.
    pub btf_fds: Vec<OwnedFd>,
    /// Human-readable discovery log.
    pub log: Vec<String>,
}

/// Discover available kinsn descriptors by scanning `/sys/kernel/btf/`.
pub fn discover_kinsns() -> DiscoveryResult {
    let mut registry = KinsnRegistry {
        rotate64_btf_id: -1,
        select64_btf_id: -1,
        extract64_btf_id: -1,
        endian_load16_btf_id: -1,
        endian_load32_btf_id: -1,
        endian_load64_btf_id: -1,
        speculation_barrier_btf_id: -1,
        target_btf_fds: HashMap::new(),
        target_supported_encodings: HashMap::new(),
    };
    let mut btf_fds: Vec<OwnedFd> = Vec::new();
    let mut log: Vec<String> = Vec::new();
    // Cache of module_name -> raw FD to avoid opening the same BTF twice.
    let mut module_btf_fds: HashMap<String, i32> = HashMap::new();

    // Module BTF blobs in /sys/kernel/btf/<module> are split BTF. Their
    // `name_off` values are biased by vmlinux's string section, and their local
    // type IDs must be shifted by the vmlinux type count to obtain the kernel-
    // visible absolute IDs accepted by BPF_PSEUDO_KINSN_CALL.
    let (base_str_off, type_id_bias) = match get_vmlinux_layout() {
        Ok((str_len, type_cnt)) => {
            let type_id_bias = type_cnt.saturating_sub(1);
            log.push(format!(
                "  vmlinux BTF str_len={} type_cnt={} type_id_bias={}",
                str_len, type_cnt, type_id_bias
            ));
            (str_len, type_id_bias)
        }
        Err(e) => {
            log.push(format!(
                "  WARNING: failed to read vmlinux BTF: {:#} (falling back to split offsets/type bias=0)",
                e
            ));
            (0, 0)
        }
    };

    for &(registry_key, desc_name, module_name) in KNOWN_KINSNS {
        let btf_path = Path::new("/sys/kernel/btf").join(module_name);
        if !btf_path.exists() {
            log.push(format!(
                "  {}: module '{}' not loaded (no BTF at {})",
                registry_key,
                module_name,
                btf_path.display()
            ));
            continue;
        }

        // Read and parse BTF.
        let btf_data = match read_module_btf(module_name) {
            Ok(data) => data,
            Err(e) => {
                log.push(format!("  {}: failed to read BTF: {:#}", registry_key, e));
                continue;
            }
        };

        let btf_id = match find_var_btf_id(&btf_data, desc_name, base_str_off, type_id_bias) {
            Some(id) => id,
            None => {
                log.push(format!(
                    "  {}: BTF_KIND_VAR '{}' not found in module '{}'",
                    registry_key, desc_name, module_name
                ));
                continue;
            }
        };

        // Get a proper BPF BTF FD via BPF_BTF_GET_FD_BY_ID.
        // A regular open() of /sys/kernel/btf/<module> yields a plain file FD
        // that the verifier cannot use. We need a BPF subsystem BTF FD.
        let fd = if let Some(&existing_fd) = module_btf_fds.get(module_name) {
            // Reuse FD already opened for this module.
            existing_fd
        } else {
            match crate::bpf::bpf_btf_get_fd_by_module_name(module_name) {
                Ok(owned) => {
                    use std::os::unix::io::AsRawFd;
                    let raw = owned.as_raw_fd();
                    module_btf_fds.insert(module_name.to_string(), raw);
                    btf_fds.push(owned);
                    raw
                }
                Err(e) => {
                    log.push(format!(
                        "  {}: failed to get BPF BTF fd for module '{}': {:#}",
                        registry_key, module_name, e
                    ));
                    continue;
                }
            }
        };

        log.push(format!(
            "  {}: descriptor '{}' found in '{}' btf_id={} fd={}",
            registry_key, desc_name, module_name, btf_id, fd
        ));

        // Assign to registry.
        match registry_key {
            "bpf_rotate64" => registry.rotate64_btf_id = btf_id,
            "bpf_select64" => registry.select64_btf_id = btf_id,
            "bpf_extract64" => registry.extract64_btf_id = btf_id,
            "bpf_endian_load16" => registry.endian_load16_btf_id = btf_id,
            "bpf_endian_load32" => registry.endian_load32_btf_id = btf_id,
            "bpf_endian_load64" => registry.endian_load64_btf_id = btf_id,
            "bpf_speculation_barrier" => registry.speculation_barrier_btf_id = btf_id,
            _ => {}
        }

        // Store per-target BTF FD for REJIT transport.
        registry.target_btf_fds.insert(registry_key.to_string(), fd);
        registry
            .target_supported_encodings
            .insert(registry_key.to_string(), BPF_KINSN_ENC_PACKED_CALL);
    }

    DiscoveryResult {
        registry,
        btf_fds,
        log,
    }
}

// ── Tests ────────────────────────────────────────────────────────────

#[cfg(test)]
mod tests {
    use super::*;

    /// Build a minimal valid BTF blob with a single FUNC type.
    fn build_btf_blob(func_name: &str) -> Vec<u8> {
        // String section: NUL byte, then func_name, then NUL terminator.
        let mut str_section = vec![0u8]; // offset 0 = empty string
        let name_off = str_section.len() as u32;
        str_section.extend_from_slice(func_name.as_bytes());
        str_section.push(0); // NUL terminator

        // Type section: one BTF_KIND_FUNC entry.
        // info = (kind << 24) | vlen, where kind=12 (FUNC), vlen=0.
        let info: u32 = BTF_KIND_FUNC << 24;
        let bt = BtfType {
            name_off,
            info,
            size_or_type: 0, // type_id of proto (not needed for discovery)
        };
        let type_section: [u8; BTF_TYPE_SIZE] = unsafe { std::mem::transmute(bt) };

        // Build header.
        let hdr = BtfHeader {
            magic: BTF_MAGIC,
            version: 1,
            flags: 0,
            hdr_len: BTF_HEADER_SIZE as u32,
            type_off: 0,
            type_len: type_section.len() as u32,
            str_off: type_section.len() as u32,
            str_len: str_section.len() as u32,
        };
        let hdr_bytes: [u8; BTF_HEADER_SIZE] = unsafe { std::mem::transmute(hdr) };

        let mut blob = Vec::new();
        blob.extend_from_slice(&hdr_bytes);
        blob.extend_from_slice(&type_section);
        blob.extend_from_slice(&str_section);
        blob
    }

    #[test]
    fn test_find_func_btf_id_found() {
        let blob = build_btf_blob("bpf_rotate64");
        let result = find_func_btf_id(&blob, "bpf_rotate64", 0, 0);
        assert_eq!(result, Some(1)); // First type is ID=1
    }

    #[test]
    fn test_find_func_btf_id_not_found() {
        let blob = build_btf_blob("bpf_rotate64");
        let result = find_func_btf_id(&blob, "bpf_select64", 0, 0);
        assert_eq!(result, None);
    }

    #[test]
    fn test_find_func_btf_id_empty_data() {
        let result = find_func_btf_id(&[], "bpf_rotate64", 0, 0);
        assert_eq!(result, None);
    }

    #[test]
    fn test_find_func_btf_id_bad_magic() {
        let mut blob = build_btf_blob("bpf_rotate64");
        // Corrupt magic.
        blob[0] = 0x00;
        blob[1] = 0x00;
        let result = find_func_btf_id(&blob, "bpf_rotate64", 0, 0);
        assert_eq!(result, None);
    }

    #[test]
    fn test_find_func_btf_id_multiple_types() {
        // Build a BTF blob with two FUNC types.
        let mut str_section = vec![0u8]; // offset 0 = empty string
        let name1_off = str_section.len() as u32;
        str_section.extend_from_slice(b"bpf_rotate64\0");
        let name2_off = str_section.len() as u32;
        str_section.extend_from_slice(b"bpf_select64\0");

        let info: u32 = BTF_KIND_FUNC << 24;
        let bt1 = BtfType {
            name_off: name1_off,
            info,
            size_or_type: 0,
        };
        let bt2 = BtfType {
            name_off: name2_off,
            info,
            size_or_type: 0,
        };

        let mut type_section = Vec::new();
        let bytes1: [u8; BTF_TYPE_SIZE] = unsafe { std::mem::transmute(bt1) };
        let bytes2: [u8; BTF_TYPE_SIZE] = unsafe { std::mem::transmute(bt2) };
        type_section.extend_from_slice(&bytes1);
        type_section.extend_from_slice(&bytes2);

        let hdr = BtfHeader {
            magic: BTF_MAGIC,
            version: 1,
            flags: 0,
            hdr_len: BTF_HEADER_SIZE as u32,
            type_off: 0,
            type_len: type_section.len() as u32,
            str_off: type_section.len() as u32,
            str_len: str_section.len() as u32,
        };
        let hdr_bytes: [u8; BTF_HEADER_SIZE] = unsafe { std::mem::transmute(hdr) };

        let mut blob = Vec::new();
        blob.extend_from_slice(&hdr_bytes);
        blob.extend_from_slice(&type_section);
        blob.extend_from_slice(&str_section);

        // bpf_rotate64 is type ID 1.
        assert_eq!(find_func_btf_id(&blob, "bpf_rotate64", 0, 0), Some(1));
        // bpf_select64 is type ID 2.
        assert_eq!(find_func_btf_id(&blob, "bpf_select64", 0, 0), Some(2));
        // Unknown func not found.
        assert_eq!(find_func_btf_id(&blob, "bpf_unknown", 0, 0), None);
    }

    #[test]
    fn test_discover_kinsns_no_modules_loaded() {
        // On a host without kinsn modules, discovery should return all -1 IDs.
        // This test runs on any machine — if modules happen to be loaded, that's OK too.
        let result = discover_kinsns();
        // Just check the structure is valid.
        assert!(result.registry.rotate64_btf_id == -1 || result.registry.rotate64_btf_id > 0);
        assert!(result.registry.select64_btf_id == -1 || result.registry.select64_btf_id > 0);
        assert!(result.registry.extract64_btf_id == -1 || result.registry.extract64_btf_id > 0);
    }

    #[test]
    fn test_btf_header_size() {
        assert_eq!(BTF_HEADER_SIZE, 24);
    }

    #[test]
    fn test_btf_type_size() {
        assert_eq!(BTF_TYPE_SIZE, 12);
    }

    /// HIGH #4: Parse BTF_KIND constants from kernel header and verify.
    ///
    /// This replaces the old hardcoded assertions with values parsed directly
    /// from vendor/linux-framework/include/uapi/linux/btf.h. If the kernel
    /// changes BTF kind numbering, this test will catch the mismatch.
    #[test]
    fn test_btf_kind_constants_match_kernel() {
        let kernel_btf_kinds = parse_btf_kind_enum();
        assert!(
            !kernel_btf_kinds.is_empty(),
            "failed to parse any BTF_KIND entries from kernel btf.h header"
        );

        // Verify every BTF_KIND_* constant we define matches the kernel header.
        let checks: &[(&str, u32)] = &[
            ("BTF_KIND_INT", BTF_KIND_INT),
            ("BTF_KIND_PTR", BTF_KIND_PTR),
            ("BTF_KIND_ARRAY", BTF_KIND_ARRAY),
            ("BTF_KIND_STRUCT", BTF_KIND_STRUCT),
            ("BTF_KIND_UNION", BTF_KIND_UNION),
            ("BTF_KIND_ENUM", BTF_KIND_ENUM),
            ("BTF_KIND_FWD", BTF_KIND_FWD),
            ("BTF_KIND_TYPEDEF", BTF_KIND_TYPEDEF),
            ("BTF_KIND_VOLATILE", BTF_KIND_VOLATILE),
            ("BTF_KIND_CONST", BTF_KIND_CONST),
            ("BTF_KIND_RESTRICT", BTF_KIND_RESTRICT),
            ("BTF_KIND_FUNC", BTF_KIND_FUNC),
            ("BTF_KIND_FUNC_PROTO", BTF_KIND_FUNC_PROTO),
            ("BTF_KIND_VAR", BTF_KIND_VAR),
            ("BTF_KIND_DATASEC", BTF_KIND_DATASEC),
            ("BTF_KIND_FLOAT", BTF_KIND_FLOAT),
            ("BTF_KIND_DECL_TAG", BTF_KIND_DECL_TAG),
            ("BTF_KIND_TYPE_TAG", BTF_KIND_TYPE_TAG),
            ("BTF_KIND_ENUM64", BTF_KIND_ENUM64),
        ];

        for (name, our_value) in checks {
            let kernel_value = kernel_btf_kinds.get(*name).unwrap_or_else(|| {
                panic!(
                    "{} not found in kernel header btf.h enum (parsed {} entries)",
                    name,
                    kernel_btf_kinds.len()
                )
            });
            assert_eq!(
                *our_value, *kernel_value,
                "BTF_KIND constant mismatch: {} = {} in kfunc_discovery.rs but {} in kernel header",
                name, our_value, kernel_value
            );
        }
    }

    /// Parse the BTF_KIND enum from the kernel UAPI header and return a map
    /// of name -> numeric value.
    fn parse_btf_kind_enum() -> std::collections::HashMap<String, u32> {
        let header_path = concat!(
            env!("CARGO_MANIFEST_DIR"),
            "/../vendor/linux-framework/include/uapi/linux/btf.h"
        );
        let content =
            std::fs::read_to_string(header_path).expect("failed to read kernel btf.h header");

        let mut result = std::collections::HashMap::new();
        let mut in_enum = false;

        for line in content.lines() {
            let trimmed = line.trim();
            // The BTF_KIND enum starts with "enum {"
            if trimmed == "enum {" && !in_enum {
                in_enum = true;
                continue;
            }
            if in_enum && (trimmed.starts_with('}') || trimmed.starts_with("};")) {
                if !result.is_empty() {
                    break;
                }
                in_enum = false;
                continue;
            }
            if !in_enum {
                continue;
            }
            // Skip comments, empty lines, NR_BTF_KINDS, BTF_KIND_MAX
            if trimmed.is_empty()
                || trimmed.starts_with("//")
                || trimmed.starts_with("/*")
                || trimmed.starts_with("*")
                || trimmed.contains("NR_BTF_KINDS")
                || trimmed.contains("BTF_KIND_MAX")
            {
                continue;
            }
            // Strip trailing inline comments: "BTF_KIND_INT = 1, /* Integer */"
            let no_comment = if let Some(pos) = trimmed.find("/*") {
                &trimmed[..pos]
            } else {
                trimmed
            };
            let clean = no_comment.trim().trim_end_matches(',').trim();
            if clean.contains('=') {
                let parts: Vec<&str> = clean.splitn(2, '=').collect();
                let name = parts[0].trim().to_string();
                let val_str = parts[1].trim();
                if let Ok(val) = val_str.parse::<u32>() {
                    if name.starts_with("BTF_KIND_") {
                        result.insert(name, val);
                    }
                }
            }
        }
        result
    }

    /// Test BTF parsing with mixed kinds (not just FUNC).
    #[test]
    fn test_find_func_in_mixed_btf() {
        // Build a BTF blob with: INT, PTR, STRUCT(1 member), FUNC_PROTO(1 param), FUNC
        let mut str_section = vec![0u8]; // offset 0 = empty string
        let func_name_off = str_section.len() as u32;
        str_section.extend_from_slice(b"bpf_rotate64\0");

        let mut type_section = Vec::new();

        // Type 1: INT (kind=1, has 4 extra bytes)
        let int_type = BtfType {
            name_off: 0,
            info: (BTF_KIND_INT << 24),
            size_or_type: 4,
        };
        let bytes: [u8; BTF_TYPE_SIZE] = unsafe { std::mem::transmute(int_type) };
        type_section.extend_from_slice(&bytes);
        type_section.extend_from_slice(&[0u8; 4]); // INT extra data

        // Type 2: PTR (kind=2, no extra data)
        let ptr_type = BtfType {
            name_off: 0,
            info: (BTF_KIND_PTR << 24),
            size_or_type: 1,
        };
        let bytes: [u8; BTF_TYPE_SIZE] = unsafe { std::mem::transmute(ptr_type) };
        type_section.extend_from_slice(&bytes);

        // Type 3: STRUCT (kind=4, 1 member = 12 extra bytes)
        let struct_type = BtfType {
            name_off: 0,
            info: (BTF_KIND_STRUCT << 24) | 1, // vlen=1
            size_or_type: 8,
        };
        let bytes: [u8; BTF_TYPE_SIZE] = unsafe { std::mem::transmute(struct_type) };
        type_section.extend_from_slice(&bytes);
        type_section.extend_from_slice(&[0u8; 12]); // btf_member

        // Type 4: FUNC_PROTO (kind=13, 1 param = 8 extra bytes)
        let proto_type = BtfType {
            name_off: 0,
            info: (BTF_KIND_FUNC_PROTO << 24) | 1, // vlen=1
            size_or_type: 1,                       // return type
        };
        let bytes: [u8; BTF_TYPE_SIZE] = unsafe { std::mem::transmute(proto_type) };
        type_section.extend_from_slice(&bytes);
        type_section.extend_from_slice(&[0u8; 8]); // btf_param

        // Type 5: FUNC (kind=12, no extra data) -- this is what we're looking for
        let func_type = BtfType {
            name_off: func_name_off,
            info: (BTF_KIND_FUNC << 24),
            size_or_type: 4, // proto type_id
        };
        let bytes: [u8; BTF_TYPE_SIZE] = unsafe { std::mem::transmute(func_type) };
        type_section.extend_from_slice(&bytes);

        let hdr = BtfHeader {
            magic: BTF_MAGIC,
            version: 1,
            flags: 0,
            hdr_len: BTF_HEADER_SIZE as u32,
            type_off: 0,
            type_len: type_section.len() as u32,
            str_off: type_section.len() as u32,
            str_len: str_section.len() as u32,
        };
        let hdr_bytes: [u8; BTF_HEADER_SIZE] = unsafe { std::mem::transmute(hdr) };

        let mut blob = Vec::new();
        blob.extend_from_slice(&hdr_bytes);
        blob.extend_from_slice(&type_section);
        blob.extend_from_slice(&str_section);

        // The FUNC is type ID 5 (1-based).
        assert_eq!(find_func_btf_id(&blob, "bpf_rotate64", 0, 0), Some(5));
        assert_eq!(find_func_btf_id(&blob, "unknown", 0, 0), None);
    }

    /// Test split BTF: name_off is offset by a base vmlinux string section length.
    ///
    /// Simulates what the kernel exposes in `/sys/kernel/btf/<module>`:
    /// the FUNC's name_off = base_str_off + local_offset.
    #[test]
    fn test_find_func_split_btf() {
        let base_str_off: u32 = 2_000_000; // Simulated vmlinux str_len

        // Build a split BTF blob where name_off values are offset by base_str_off.
        let mut str_section = vec![0u8]; // offset 0 = empty string
        let local_name_off = str_section.len() as u32;
        str_section.extend_from_slice(b"bpf_rotate64\0");

        // The FUNC entry has name_off = base_str_off + local_name_off
        let split_name_off = base_str_off + local_name_off;
        let info: u32 = BTF_KIND_FUNC << 24;
        let bt = BtfType {
            name_off: split_name_off,
            info,
            size_or_type: 0,
        };
        let type_section: [u8; BTF_TYPE_SIZE] = unsafe { std::mem::transmute(bt) };

        let hdr = BtfHeader {
            magic: BTF_MAGIC,
            version: 1,
            flags: 0,
            hdr_len: BTF_HEADER_SIZE as u32,
            type_off: 0,
            type_len: type_section.len() as u32,
            str_off: type_section.len() as u32,
            str_len: str_section.len() as u32,
        };
        let hdr_bytes: [u8; BTF_HEADER_SIZE] = unsafe { std::mem::transmute(hdr) };

        let mut blob = Vec::new();
        blob.extend_from_slice(&hdr_bytes);
        blob.extend_from_slice(&type_section);
        blob.extend_from_slice(&str_section);

        // With base_str_off=0, the name_off is out of range -> not found.
        assert_eq!(find_func_btf_id(&blob, "bpf_rotate64", 0, 0), None);

        // With the correct base_str_off, the name resolves correctly.
        assert_eq!(
            find_func_btf_id(&blob, "bpf_rotate64", base_str_off, 0),
            Some(1)
        );

        // Wrong func name still not found.
        assert_eq!(
            find_func_btf_id(&blob, "bpf_select64", base_str_off, 0),
            None
        );
    }

    #[test]
    fn test_find_func_split_btf_type_id_bias() {
        let base_str_off: u32 = 2_000_000;
        let base_type_id_bias: u32 = 12345;

        let mut str_section = vec![0u8];
        let local_name_off = str_section.len() as u32;
        str_section.extend_from_slice(b"bpf_rotate64\0");

        let split_name_off = base_str_off + local_name_off;
        let bt = BtfType {
            name_off: split_name_off,
            info: BTF_KIND_FUNC << 24,
            size_or_type: 0,
        };
        let type_section: [u8; BTF_TYPE_SIZE] = unsafe { std::mem::transmute(bt) };

        let hdr = BtfHeader {
            magic: BTF_MAGIC,
            version: 1,
            flags: 0,
            hdr_len: BTF_HEADER_SIZE as u32,
            type_off: 0,
            type_len: type_section.len() as u32,
            str_off: type_section.len() as u32,
            str_len: str_section.len() as u32,
        };
        let hdr_bytes: [u8; BTF_HEADER_SIZE] = unsafe { std::mem::transmute(hdr) };

        let mut blob = Vec::new();
        blob.extend_from_slice(&hdr_bytes);
        blob.extend_from_slice(&type_section);
        blob.extend_from_slice(&str_section);

        assert_eq!(
            find_func_btf_id(&blob, "bpf_rotate64", base_str_off, base_type_id_bias),
            Some((base_type_id_bias + 1) as i32)
        );
    }

    // ── Real BTF smoke tests (need /sys/kernel/btf/) ─────────────────
    //
    // These tests access the real vmlinux BTF. They are marked #[ignore]
    // because CI environments may not have BTF enabled.

    #[test]
    #[ignore]
    fn test_get_vmlinux_base_info_real() {
        // On any kernel with CONFIG_DEBUG_INFO_BTF=y, /sys/kernel/btf/vmlinux exists.
        if !Path::new("/sys/kernel/btf/vmlinux").exists() {
            eprintln!("SKIP: /sys/kernel/btf/vmlinux not present");
            return;
        }
        let (str_len, type_cnt) = get_vmlinux_layout().expect("get_vmlinux_layout failed");
        // vmlinux BTF string section is typically > 100KB.
        assert!(
            str_len > 1000,
            "vmlinux str_len suspiciously small: {}",
            str_len
        );
        assert!(
            type_cnt > 1000,
            "vmlinux type count suspiciously small: {}",
            type_cnt
        );
    }

    #[test]
    #[ignore]
    fn test_find_func_in_real_vmlinux_btf() {
        // Parse the real vmlinux BTF and search for well-known kernel functions.
        let vmlinux_path = "/sys/kernel/btf/vmlinux";
        if !Path::new(vmlinux_path).exists() {
            eprintln!("SKIP: /sys/kernel/btf/vmlinux not present");
            return;
        }
        let data = fs::read(vmlinux_path).expect("read vmlinux BTF");
        // vmlinux is base BTF, so base_str_off=0.
        // MEDIUM #3: Assert that the result is Some for a well-known kernel function.
        // bpf_prog_run_xdp should exist in any BPF-enabled kernel with XDP support.
        let result = find_func_btf_id(&data, "bpf_prog_run_xdp", 0, 0);
        assert!(
            result.is_some(),
            "bpf_prog_run_xdp should exist in vmlinux BTF (found None)"
        );
        let btf_id = result.unwrap();
        assert!(
            btf_id > 0,
            "bpf_prog_run_xdp BTF ID should be positive, got {}",
            btf_id
        );
        eprintln!("  bpf_prog_run_xdp: btf_id={}", btf_id);
    }

    #[test]
    #[ignore]
    fn test_discover_kinsns_real() {
        // Run the full discovery pipeline against the real kernel.
        // Even without kinsn modules loaded, this validates that the BPF
        // syscall chain (BTF_GET_NEXT_ID, BTF_GET_FD_BY_ID, GET_INFO_BY_FD)
        // all work correctly.
        let result = discover_kinsns();
        // Should always produce at least one log line about vmlinux.
        assert!(
            !result.log.is_empty(),
            "discover_kinsns() produced no log output"
        );
        // If kinsn modules are not loaded, all BTF IDs should be -1.
        // If they are loaded, they should be > 0.
        // Either way, the function should not panic or return garbage.
        for &(kfunc_name, _, _) in KNOWN_KINSNS {
            let btf_id = match kfunc_name {
                "bpf_rotate64" => result.registry.rotate64_btf_id,
                "bpf_select64" => result.registry.select64_btf_id,
                "bpf_extract64" => result.registry.extract64_btf_id,
                "bpf_endian_load16" => result.registry.endian_load16_btf_id,
                "bpf_endian_load32" => result.registry.endian_load32_btf_id,
                "bpf_endian_load64" => result.registry.endian_load64_btf_id,
                "bpf_speculation_barrier" => result.registry.speculation_barrier_btf_id,
                _ => continue,
            };
            assert!(
                btf_id == -1 || btf_id > 0,
                "{} has invalid btf_id: {}",
                kfunc_name,
                btf_id
            );
        }
    }
}
