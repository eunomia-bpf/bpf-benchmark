// SPDX-License-Identifier: MIT
//! Kfunc auto-discovery via `/sys/kernel/btf/` module BTF scanning.
//!
//! Scans loaded kernel modules for known kinsn kfuncs (bpf_rotate64, etc.)
//! and populates a `KfuncRegistry` with their BTF type IDs and module FDs.

use std::fs;
use std::os::unix::io::{FromRawFd, OwnedFd};
use std::path::Path;

use anyhow::{bail, Context, Result};

use crate::pass::KfuncRegistry;

// ── Known kfunc → module mapping ─────────────────────────────────────

/// A kfunc we want to discover: (kfunc_name, module_name).
const KNOWN_KFUNCS: &[(&str, &str)] = &[
    ("bpf_rotate64", "bpf_rotate"),
    ("bpf_select64", "bpf_select"),
    ("bpf_extract64", "bpf_extract"),
];

// ── BTF constants ────────────────────────────────────────────────────

const BTF_MAGIC: u16 = 0xEB9F;
const BTF_KIND_FUNC: u32 = 12;

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

/// Parse a BTF blob and find the BTF type ID for a FUNC with the given name.
/// Returns the 1-based type ID, or None if not found.
fn find_func_btf_id(btf_data: &[u8], func_name: &str) -> Option<i32> {
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

    // Walk the type section. BTF type IDs are 1-based.
    let mut offset = 0usize;
    let mut type_id: i32 = 1;

    while offset + BTF_TYPE_SIZE <= type_section.len() {
        let bt: BtfType =
            unsafe { std::ptr::read_unaligned(type_section[offset..].as_ptr() as *const BtfType) };

        let kind = bt.kind();

        if kind == BTF_KIND_FUNC {
            // Resolve name from string section.
            let name_off = bt.name_off as usize;
            if name_off < str_section.len() {
                let name_bytes = &str_section[name_off..];
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
        let vlen = (bt.info & 0xffff) as usize;
        let skip = match kind {
            1 => 4,              // INT: u32 encoding data
            2 | 3 => vlen * 12, // STRUCT/UNION: btf_member = 12 bytes each
            4 => vlen * 8,      // ENUM: btf_enum = 8 bytes each
            8 => vlen * 8,      // FUNC_PROTO: btf_param = 8 bytes each
            11 => 4,            // VAR: u32 linkage
            13 => vlen * 12,    // DATASEC: btf_var_secinfo = 12 bytes each
            15 => 4,            // DECL_TAG: u32 component_idx
            17 => vlen * 12,    // ENUM64: btf_enum64 = 12 bytes each
            _ => 0,             // PTR/FWD/TYPEDEF/VOLATILE/CONST/RESTRICT/FUNC/FLOAT/TYPE_TAG
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
        module_fd: None,
    };
    let mut module_fds: Vec<OwnedFd> = Vec::new();
    let mut log: Vec<String> = Vec::new();

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

        let btf_id = match find_func_btf_id(&btf_data, kfunc_name) {
            Some(id) => id,
            None => {
                log.push(format!(
                    "  {}: BTF_KIND_FUNC not found in module '{}'",
                    kfunc_name, module_name
                ));
                continue;
            }
        };

        // Open the module BTF fd.
        let fd = match open_btf_path(&btf_path) {
            Ok(fd) => fd,
            Err(e) => {
                log.push(format!("  {}: failed to open BTF fd: {:#}", kfunc_name, e));
                continue;
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
            _ => {}
        }

        // Store the first module FD for REJIT fd_array.
        // All three kfuncs share the same module BTF convention, but
        // each module has its own BTF fd. For now, store the first one
        // found; the REJIT path may need multiple fds later.
        if registry.module_fd.is_none() {
            registry.module_fd = Some(fd);
        }

        module_fds.push(unsafe { OwnedFd::from_raw_fd(fd) });
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
        let result = find_func_btf_id(&blob, "bpf_rotate64");
        assert_eq!(result, Some(1)); // First type is ID=1
    }

    #[test]
    fn test_find_func_btf_id_not_found() {
        let blob = build_btf_blob("bpf_rotate64");
        let result = find_func_btf_id(&blob, "bpf_select64");
        assert_eq!(result, None);
    }

    #[test]
    fn test_find_func_btf_id_empty_data() {
        let result = find_func_btf_id(&[], "bpf_rotate64");
        assert_eq!(result, None);
    }

    #[test]
    fn test_find_func_btf_id_bad_magic() {
        let mut blob = build_btf_blob("bpf_rotate64");
        // Corrupt magic.
        blob[0] = 0x00;
        blob[1] = 0x00;
        let result = find_func_btf_id(&blob, "bpf_rotate64");
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
        assert_eq!(find_func_btf_id(&blob, "bpf_rotate64"), Some(1));
        // bpf_select64 is type ID 2.
        assert_eq!(find_func_btf_id(&blob, "bpf_select64"), Some(2));
        // Unknown func not found.
        assert_eq!(find_func_btf_id(&blob, "bpf_unknown"), None);
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
}
