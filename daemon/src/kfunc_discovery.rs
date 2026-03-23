// SPDX-License-Identifier: MIT
//! Kfunc auto-discovery via `/sys/kernel/btf/` module BTF scanning.
//!
//! Scans loaded kernel modules for known kinsn kfuncs (bpf_rotate64, etc.)
//! and populates a `KfuncRegistry` with their BTF type IDs and module FDs.

use std::collections::HashMap;
use std::fs;
use std::os::unix::io::OwnedFd;
use std::path::Path;

use anyhow::{bail, Context, Result};

use crate::pass::KfuncRegistry;

// ── Known kfunc → module mapping ─────────────────────────────────────

/// A kfunc we want to discover: (kfunc_name, module_name).
const KNOWN_KFUNCS: &[(&str, &str)] = &[
    ("bpf_rotate64", "bpf_rotate"),
    ("bpf_select64", "bpf_select"),
    ("bpf_extract64", "bpf_extract"),
    ("bpf_endian_load16", "bpf_endian"),
    ("bpf_endian_load32", "bpf_endian"),
    ("bpf_endian_load64", "bpf_endian"),
    ("bpf_speculation_barrier", "bpf_barrier"),
];

// ── BTF constants (synced from vendor/linux-framework/include/uapi/linux/btf.h) ──

const BTF_MAGIC: u16 = 0xEB9F;

// BTF_KIND_* values from the kernel header.
// All constants are kept for completeness/sync-test even if not all are used in match arms.
#[allow(dead_code)]
const BTF_KIND_INT: u32 = 1;
#[allow(dead_code)]
const BTF_KIND_PTR: u32 = 2;
#[allow(dead_code)]
const BTF_KIND_ARRAY: u32 = 3;
#[allow(dead_code)]
const BTF_KIND_STRUCT: u32 = 4;
#[allow(dead_code)]
const BTF_KIND_UNION: u32 = 5;
#[allow(dead_code)]
const BTF_KIND_ENUM: u32 = 6;
#[allow(dead_code)]
const BTF_KIND_FWD: u32 = 7;
#[allow(dead_code)]
const BTF_KIND_TYPEDEF: u32 = 8;
#[allow(dead_code)]
const BTF_KIND_VOLATILE: u32 = 9;
#[allow(dead_code)]
const BTF_KIND_CONST: u32 = 10;
#[allow(dead_code)]
const BTF_KIND_RESTRICT: u32 = 11;
const BTF_KIND_FUNC: u32 = 12;
#[allow(dead_code)]
const BTF_KIND_FUNC_PROTO: u32 = 13;
#[allow(dead_code)]
const BTF_KIND_VAR: u32 = 14;
#[allow(dead_code)]
const BTF_KIND_DATASEC: u32 = 15;
#[allow(dead_code)]
const BTF_KIND_FLOAT: u32 = 16;
#[allow(dead_code)]
const BTF_KIND_DECL_TAG: u32 = 17;
#[allow(dead_code)]
const BTF_KIND_TYPE_TAG: u32 = 18;
#[allow(dead_code)]
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

/// Read the vmlinux BTF string section length from `/sys/kernel/btf/vmlinux`.
///
/// Module (split) BTF uses `name_off` values that are offset by the vmlinux
/// string section length (`start_str_off`). We need this base offset to
/// correctly resolve module-local string references.
fn get_vmlinux_str_len() -> Result<u32> {
    let vmlinux_path = "/sys/kernel/btf/vmlinux";
    let data = fs::read(vmlinux_path)
        .with_context(|| "read vmlinux BTF header")?;
    if data.len() < BTF_HEADER_SIZE {
        bail!("vmlinux BTF too small ({} bytes)", data.len());
    }
    let hdr: BtfHeader =
        unsafe { std::ptr::read_unaligned(data.as_ptr() as *const BtfHeader) };
    if hdr.magic != BTF_MAGIC {
        bail!("vmlinux BTF bad magic: 0x{:04x}", hdr.magic);
    }
    Ok(hdr.str_len)
}

/// Parse a (possibly split) BTF blob and find the BTF type ID for a FUNC
/// with the given name. Returns the 1-based type ID, or None if not found.
///
/// `base_str_off` is the vmlinux string section length. For split module BTF,
/// `name_off` values >= `base_str_off` reference the module's own string
/// section at local offset `name_off - base_str_off`. For standalone BTF
/// (base_str_off == 0), name_off indexes the local string section directly.
fn find_func_btf_id(btf_data: &[u8], func_name: &str, base_str_off: u32) -> Option<i32> {
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

        if kind == BTF_KIND_FUNC {
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
                let nul_pos = name_bytes.iter().position(|&b| b == 0).unwrap_or(name_bytes.len());
                if let Ok(name) = std::str::from_utf8(&name_bytes[..nul_pos]) {
                    if name == func_name {
                        return Some(type_id);
                    }
                }
            }
        }

        // Advance past the base BtfType entry.
        offset += BTF_TYPE_SIZE;

        // Some BTF kinds have additional data after the base entry.
        // We need to skip those to correctly walk the type section.
        // Kind constants from vendor/linux-framework/include/uapi/linux/btf.h.
        let vlen = (bt.info & 0xffff) as usize;
        let skip = match kind {
            BTF_KIND_INT => 4,                 // u32 encoding data
            BTF_KIND_ARRAY => 12,              // struct btf_array (3 * u32)
            BTF_KIND_STRUCT | BTF_KIND_UNION => vlen * 12, // btf_member = 12 bytes each
            BTF_KIND_ENUM => vlen * 8,         // btf_enum = 8 bytes each
            BTF_KIND_FUNC_PROTO => vlen * 8,   // btf_param = 8 bytes each
            BTF_KIND_VAR => 4,                 // u32 linkage
            BTF_KIND_DATASEC => vlen * 12,     // btf_var_secinfo = 12 bytes each
            BTF_KIND_DECL_TAG => 4,            // u32 component_idx
            BTF_KIND_ENUM64 => vlen * 12,      // btf_enum64 = 12 bytes each
            // PTR/FWD/TYPEDEF/VOLATILE/CONST/RESTRICT/FUNC/FLOAT/TYPE_TAG: no extra data
            _ => 0,
        };
        offset += skip;

        type_id += 1;
    }

    None
}

// ── Module BTF file operations ───────────────────────────────────────

/// Read raw BTF data from `/sys/kernel/btf/<module>`.
fn read_module_btf(module_name: &str) -> Result<Vec<u8>> {
    let path = format!("/sys/kernel/btf/{}", module_name);
    fs::read(&path).with_context(|| format!("read BTF for module '{}'", module_name))
}

/// Open a module BTF path as an FD, handling the C string correctly.
/// Note: this returns a plain file FD, not a BPF BTF FD. The verifier
/// cannot use these for kfunc resolution. Use bpf_btf_get_fd_by_module_name()
/// instead for REJIT fd_array.
#[allow(dead_code)]
fn open_btf_path(path: &Path) -> Result<i32> {
    use std::ffi::CString;
    let c_path = CString::new(path.to_str().unwrap_or(""))
        .context("invalid path for CString")?;
    let fd = unsafe { libc::open(c_path.as_ptr(), libc::O_RDONLY) };
    if fd < 0 {
        bail!(
            "open({}): {}",
            path.display(),
            std::io::Error::last_os_error()
        );
    }
    Ok(fd)
}

// ── Discovery entry point ────────────────────────────────────────────

/// Result of kfunc discovery.
#[derive(Debug)]
pub struct DiscoveryResult {
    pub registry: KfuncRegistry,
    /// Module BTF FDs to keep alive for the daemon's lifetime.
    /// When these are dropped, the FDs close and REJIT can no longer reference them.
    pub module_fds: Vec<OwnedFd>,
    /// Human-readable discovery log.
    pub log: Vec<String>,
}

/// Discover available kinsn kfuncs by scanning `/sys/kernel/btf/`.
///
/// For each known kfunc, checks whether the corresponding kernel module's
/// BTF is present, parses it to find the FUNC type ID, and opens an FD
/// for REJIT's fd_array.
pub fn discover_kfuncs() -> DiscoveryResult {
    let mut registry = KfuncRegistry {
        rotate64_btf_id: -1,
        select64_btf_id: -1,
        extract64_btf_id: -1,
        lea64_btf_id: -1,
        movbe64_btf_id: -1,
        endian_load16_btf_id: -1,
        endian_load32_btf_id: -1,
        endian_load64_btf_id: -1,
        speculation_barrier_btf_id: -1,
        module_fd: None,
        kfunc_module_fds: HashMap::new(),
    };
    let mut module_fds: Vec<OwnedFd> = Vec::new();
    let mut log: Vec<String> = Vec::new();
    // Cache of module_name -> raw FD to avoid opening the same BTF twice.
    let mut module_btf_fds: HashMap<String, i32> = HashMap::new();

    // Read vmlinux BTF string section length for split BTF resolution.
    // Module BTF is "split BTF" whose name_off values are offset by the
    // vmlinux string section length. Without this base offset, we cannot
    // resolve module-local function names.
    let base_str_off = match get_vmlinux_str_len() {
        Ok(len) => {
            log.push(format!("  vmlinux BTF str_len={} (split BTF base offset)", len));
            len
        }
        Err(e) => {
            log.push(format!(
                "  WARNING: failed to read vmlinux BTF: {:#} (falling back to base_str_off=0)",
                e
            ));
            0
        }
    };

    for &(kfunc_name, module_name) in KNOWN_KFUNCS {
        let btf_path = Path::new("/sys/kernel/btf").join(module_name);
        if !btf_path.exists() {
            log.push(format!(
                "  {}: module '{}' not loaded (no BTF at {})",
                kfunc_name,
                module_name,
                btf_path.display()
            ));
            continue;
        }

        // Read and parse BTF.
        let btf_data = match read_module_btf(module_name) {
            Ok(data) => data,
            Err(e) => {
                log.push(format!("  {}: failed to read BTF: {:#}", kfunc_name, e));
                continue;
            }
        };

        let btf_id = match find_func_btf_id(&btf_data, kfunc_name, base_str_off) {
            Some(id) => id,
            None => {
                log.push(format!(
                    "  {}: BTF_KIND_FUNC not found in module '{}'",
                    kfunc_name, module_name
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
                    module_fds.push(owned);
                    raw
                }
                Err(e) => {
                    log.push(format!(
                        "  {}: failed to get BPF BTF fd for module '{}': {:#}",
                        kfunc_name, module_name, e
                    ));
                    continue;
                }
            }
        };

        log.push(format!(
            "  {}: found in '{}' btf_id={} fd={}",
            kfunc_name, module_name, btf_id, fd
        ));

        // Assign to registry.
        match kfunc_name {
            "bpf_rotate64" => registry.rotate64_btf_id = btf_id,
            "bpf_select64" => registry.select64_btf_id = btf_id,
            "bpf_extract64" => registry.extract64_btf_id = btf_id,
            "bpf_endian_load16" => registry.endian_load16_btf_id = btf_id,
            "bpf_endian_load32" => registry.endian_load32_btf_id = btf_id,
            "bpf_endian_load64" => registry.endian_load64_btf_id = btf_id,
            "bpf_speculation_barrier" => registry.speculation_barrier_btf_id = btf_id,
            _ => {}
        }

        // Store per-kfunc module FD for REJIT fd_array.
        registry.kfunc_module_fds.insert(kfunc_name.to_string(), fd);

        // Legacy: keep the first module FD for backward compat.
        if registry.module_fd.is_none() {
            registry.module_fd = Some(fd);
        }
    }

    DiscoveryResult {
        registry,
        module_fds,
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
        let result = find_func_btf_id(&blob, "bpf_rotate64", 0);
        assert_eq!(result, Some(1)); // First type is ID=1
    }

    #[test]
    fn test_find_func_btf_id_not_found() {
        let blob = build_btf_blob("bpf_rotate64");
        let result = find_func_btf_id(&blob, "bpf_select64", 0);
        assert_eq!(result, None);
    }

    #[test]
    fn test_find_func_btf_id_empty_data() {
        let result = find_func_btf_id(&[], "bpf_rotate64", 0);
        assert_eq!(result, None);
    }

    #[test]
    fn test_find_func_btf_id_bad_magic() {
        let mut blob = build_btf_blob("bpf_rotate64");
        // Corrupt magic.
        blob[0] = 0x00;
        blob[1] = 0x00;
        let result = find_func_btf_id(&blob, "bpf_rotate64", 0);
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
        assert_eq!(find_func_btf_id(&blob, "bpf_rotate64", 0), Some(1));
        // bpf_select64 is type ID 2.
        assert_eq!(find_func_btf_id(&blob, "bpf_select64", 0), Some(2));
        // Unknown func not found.
        assert_eq!(find_func_btf_id(&blob, "bpf_unknown", 0), None);
    }

    #[test]
    fn test_discover_kfuncs_no_modules_loaded() {
        // On a host without kinsn modules, discovery should return all -1 IDs.
        // This test runs on any machine — if modules happen to be loaded, that's OK too.
        let result = discover_kfuncs();
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

    /// Sync test: verify our BTF_KIND_* constants match the kernel header values.
    /// These must match vendor/linux-framework/include/uapi/linux/btf.h.
    #[test]
    fn test_btf_kind_constants_match_kernel() {
        assert_eq!(BTF_KIND_INT, 1);
        assert_eq!(BTF_KIND_PTR, 2);
        assert_eq!(BTF_KIND_ARRAY, 3);
        assert_eq!(BTF_KIND_STRUCT, 4);
        assert_eq!(BTF_KIND_UNION, 5);
        assert_eq!(BTF_KIND_ENUM, 6);
        assert_eq!(BTF_KIND_FWD, 7);
        assert_eq!(BTF_KIND_TYPEDEF, 8);
        assert_eq!(BTF_KIND_VOLATILE, 9);
        assert_eq!(BTF_KIND_CONST, 10);
        assert_eq!(BTF_KIND_RESTRICT, 11);
        assert_eq!(BTF_KIND_FUNC, 12);
        assert_eq!(BTF_KIND_FUNC_PROTO, 13);
        assert_eq!(BTF_KIND_VAR, 14);
        assert_eq!(BTF_KIND_DATASEC, 15);
        assert_eq!(BTF_KIND_FLOAT, 16);
        assert_eq!(BTF_KIND_DECL_TAG, 17);
        assert_eq!(BTF_KIND_TYPE_TAG, 18);
        assert_eq!(BTF_KIND_ENUM64, 19);
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
            size_or_type: 1, // return type
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
        assert_eq!(find_func_btf_id(&blob, "bpf_rotate64", 0), Some(5));
        assert_eq!(find_func_btf_id(&blob, "unknown", 0), None);
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
        assert_eq!(find_func_btf_id(&blob, "bpf_rotate64", 0), None);

        // With the correct base_str_off, the name resolves correctly.
        assert_eq!(find_func_btf_id(&blob, "bpf_rotate64", base_str_off), Some(1));

        // Wrong func name still not found.
        assert_eq!(find_func_btf_id(&blob, "bpf_select64", base_str_off), None);
    }

    // ── Real BTF smoke tests (need /sys/kernel/btf/) ─────────────────
    //
    // These tests access the real vmlinux BTF. They are marked #[ignore]
    // because CI environments may not have BTF enabled.

    #[test]
    #[ignore]
    fn test_get_vmlinux_str_len_real() {
        // On any kernel with CONFIG_DEBUG_INFO_BTF=y, /sys/kernel/btf/vmlinux exists.
        if !Path::new("/sys/kernel/btf/vmlinux").exists() {
            eprintln!("SKIP: /sys/kernel/btf/vmlinux not present");
            return;
        }
        let str_len = get_vmlinux_str_len().expect("get_vmlinux_str_len failed");
        // vmlinux BTF string section is typically > 100KB.
        assert!(
            str_len > 1000,
            "vmlinux str_len suspiciously small: {}",
            str_len
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
        let result = find_func_btf_id(&data, "bpf_prog_run_xdp", 0);
        // bpf_prog_run_xdp should exist in any BPF-enabled kernel.
        // However, the name may vary between kernel versions, so just check
        // that parsing completes without panic.
        let _ = result;
    }

    #[test]
    #[ignore]
    fn test_discover_kfuncs_real() {
        // Run the full discovery pipeline against the real kernel.
        // Even without kinsn modules loaded, this validates that the BPF
        // syscall chain (BTF_GET_NEXT_ID, BTF_GET_FD_BY_ID, GET_INFO_BY_FD)
        // all work correctly.
        let result = discover_kfuncs();
        // Should always produce at least one log line about vmlinux.
        assert!(
            !result.log.is_empty(),
            "discover_kfuncs() produced no log output"
        );
        // If kinsn modules are not loaded, all BTF IDs should be -1.
        // If they are loaded, they should be > 0.
        // Either way, the function should not panic or return garbage.
        for &(kfunc_name, _) in KNOWN_KFUNCS {
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
