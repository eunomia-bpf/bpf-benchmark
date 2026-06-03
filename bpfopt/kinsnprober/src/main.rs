// SPDX-License-Identifier: MIT
//! kinsnprober — probe loaded kinsn BTF modules and emit target.json
//! consumed by `bpfopt --target`. Stock-kernel LD_PRELOAD shim execs this once
//! at startup so subsequent `bpfopt --pass <name>` invocations see every
//! registered kinsn kfunc.
//!
//! Pure CLI: reads no inputs, writes one JSON file. Uses libbpf-sys (BTF) and
//! the bpf(2) syscall directly; does not depend on bpfopt internals.

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use libbpf_sys::{
    btf, btf__find_by_name_kind, btf__free, btf__load_from_kernel_by_id,
    btf__load_from_kernel_by_id_split, btf__load_vmlinux_btf, libbpf_get_error,
    BTF_KIND_FUNC,
};
use serde::Serialize;
use std::collections::BTreeMap;
use std::ffi::{c_void, CString};
use std::path::PathBuf;
use std::ptr::NonNull;

#[derive(Parser)]
#[command(name = "kinsnprober", about = "Emit a bpfopt target.json from loaded kinsn BTF modules")]
struct Cli {
    /// Output file (target.json compatible with `bpfopt --target`).
    #[arg(long, value_name = "FILE")]
    out: PathBuf,
    /// Kinsn function names to probe. Defaults to the union of names declared
    /// across `runner/config/passes/*/default.yaml` — currently a fixed list
    /// generated from those yamls.
    #[arg(long, value_name = "NAME")]
    name: Vec<String>,
}

/// Default kinsn name list — union of every `kinsns:` entry across the runner
/// pass configs. Keep in sync with `runner/config/passes/*/default.yaml`. The
/// shim invokes kinsnprober with no `--name` flags and gets this set.
const DEFAULT_KINSN_NAMES: &[&str] = &[
    "bpf_arm64_ccmp_w", "bpf_arm64_ccmp_x", "bpf_arm64_cmp_w",
    "bpf_arm64_cmp_x", "bpf_arm64_csel_ne", "bpf_arm64_cset_x_cond",
    "bpf_arm64_extr_w", "bpf_arm64_extr_x", "bpf_arm64_ldr_w",
    "bpf_arm64_ldr_x", "bpf_arm64_ldrb", "bpf_arm64_ldrh",
    "bpf_arm64_mov_x", "bpf_arm64_prfm_pldl1keep", "bpf_arm64_rev16_w",
    "bpf_arm64_rev_w", "bpf_arm64_rev_x", "bpf_arm64_strb",
    "bpf_arm64_tst", "bpf_arm64_ubfm_x",
    "bpf_x86_bextrq", "bpf_x86_blsiq", "bpf_x86_blsrq", "bpf_x86_andl",
    "bpf_x86_bswapl", "bpf_x86_bswapq", "bpf_x86_cmp_cmovb",
    "bpf_x86_cmp_cmove", "bpf_x86_cmp_cmovne", "bpf_x86_leal",
    "bpf_x86_leaq", "bpf_x86_movb",
    "bpf_x86_movbe16", "bpf_x86_movbe32", "bpf_x86_movbe64",
    "bpf_x86_movl", "bpf_x86_movq", "bpf_x86_rolq", "bpf_x86_rolw",
    "bpf_x86_rorxl", "bpf_x86_movzbl", "bpf_x86_movzwl",
    "bpf_x86_popcntq", "bpf_x86_prefetcht0", "bpf_x86_shldl",
    "bpf_x86_shldq", "bpf_x86_shrdl", "bpf_x86_shrdq", "bpf_x86_shrq",
];

#[derive(Serialize)]
struct TargetJson {
    arch: String,
    kinsns: BTreeMap<String, TargetKinsnJson>,
}

#[derive(Serialize)]
struct TargetKinsnJson {
    btf_func_id: i32,
    btf_id: u32,
    call_offset: u32,
}

struct KernelBtf {
    ptr: NonNull<btf>,
}

impl KernelBtf {
    fn from_raw(context: &str, raw: *mut btf) -> Result<Self> {
        let err = unsafe { libbpf_get_error(raw as *const c_void) };
        if err != 0 {
            return Err(anyhow!("{context}: errno {}", -err));
        }
        let ptr = NonNull::new(raw).ok_or_else(|| anyhow!("{context} returned NULL"))?;
        Ok(Self { ptr })
    }
    fn load_vmlinux() -> Result<Self> {
        Self::from_raw("btf__load_vmlinux_btf", unsafe { btf__load_vmlinux_btf() })
    }
    fn load_by_id(id: u32) -> Result<Self> {
        Self::from_raw(
            &format!("btf__load_from_kernel_by_id({id})"),
            unsafe { btf__load_from_kernel_by_id(id) },
        )
    }
    fn load_by_id_split(id: u32, base: &KernelBtf) -> Result<Self> {
        Self::from_raw(
            &format!("btf__load_from_kernel_by_id_split({id})"),
            unsafe { btf__load_from_kernel_by_id_split(id, base.ptr.as_ptr()) },
        )
    }
    fn find_func(&self, name: &str) -> Result<Option<u32>> {
        let c_name = CString::new(name).map_err(|_| anyhow!("name has NUL: {name:?}"))?;
        let ret = unsafe {
            btf__find_by_name_kind(self.ptr.as_ptr(), c_name.as_ptr(), BTF_KIND_FUNC)
        };
        if ret >= 0 {
            return Ok(Some(ret as u32));
        }
        let errno = if ret < 0 { -ret } else { ret };
        if errno == libc::ENOENT {
            return Ok(None);
        }
        Err(anyhow!("btf__find_by_name_kind({name}): errno {errno}"))
    }
}

impl Drop for KernelBtf {
    fn drop(&mut self) {
        unsafe { btf__free(self.ptr.as_ptr()) };
    }
}

fn next_btf_id(start_id: u32) -> Result<Option<u32>> {
    let mut next: u32 = 0;
    let ret = unsafe { libbpf_sys::bpf_btf_get_next_id(start_id, &mut next) };
    if ret < 0 {
        let errno = std::io::Error::last_os_error().raw_os_error().unwrap_or(libc::EIO);
        if errno == libc::ENOENT { return Ok(None); }
        return Err(anyhow!("BPF_BTF_GET_NEXT_ID: errno {errno}"));
    }
    Ok(Some(next))
}

fn detect_arch() -> String {
    match std::env::consts::ARCH {
        "x86_64" => "x86_64",
        "aarch64" => "aarch64",
        other => other,
    }.to_string()
}

fn main() -> Result<()> {
    let cli = Cli::parse();
    let names: Vec<String> = if cli.name.is_empty() {
        DEFAULT_KINSN_NAMES.iter().map(|s| s.to_string()).collect()
    } else {
        cli.name
    };

    let vmlinux = KernelBtf::load_vmlinux().context("load vmlinux BTF")?;
    let mut found: BTreeMap<String, TargetKinsnJson> = BTreeMap::new();
    let mut module_slot: BTreeMap<u32, u32> = BTreeMap::new();
    let mut next_slot: u32 = 1;
    let mut start_id: u32 = 0;
    let mut saw_btf = false;

    loop {
        let Some(btf_id) = next_btf_id(start_id)? else { break };
        saw_btf = true;
        start_id = btf_id;
        // Standalone load works for vmlinux; split-load for modules.
        let (btf, is_module) = match KernelBtf::load_by_id(btf_id) {
            Ok(b) => (b, false),
            Err(_) => (KernelBtf::load_by_id_split(btf_id, &vmlinux)?, true),
        };
        for name in &names {
            if found.contains_key(name) { continue; }
            let Some(func_id) = btf.find_func(name)? else { continue };
            let func_id = i32::try_from(func_id)
                .map_err(|_| anyhow!("BTF func id overflows i32 for {name}"))?;
            let call_offset = if is_module {
                *module_slot.entry(btf_id).or_insert_with(|| {
                    let s = next_slot;
                    next_slot += 1;
                    s
                })
            } else {
                0
            };
            found.insert(name.clone(), TargetKinsnJson {
                btf_func_id: func_id,
                btf_id,
                call_offset,
            });
        }
        if found.len() == names.len() { break; }
    }

    if !saw_btf {
        bail!("no kernel BTF objects visible — is BPF enabled?");
    }

    let out = TargetJson { arch: detect_arch(), kinsns: found };
    let json = serde_json::to_string_pretty(&out)?;
    std::fs::write(&cli.out, json).with_context(|| format!("write {}", cli.out.display()))?;
    Ok(())
}
