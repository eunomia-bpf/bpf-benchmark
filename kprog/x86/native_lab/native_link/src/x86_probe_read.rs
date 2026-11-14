//! Opt-in helper LTO: preserve access policy, fault nesting, errors and full
//! destination zeroing. Recover source loads through existing EX_TYPE_BPF by
//! clearing R11 status, not by pretending a fault was a successful zero load.
use super::*;

fn absolute(bytes: &mut Vec<u8>, opcode: &[u8], address: u64) {
    bytes.extend_from_slice(opcode);
    bytes.extend_from_slice(&address.to_le_bytes());
}

fn jump(bytes: &mut Vec<u8>) -> usize {
    bytes.push(0xe9);
    let offset = bytes.len();
    bytes.extend_from_slice(&[0; 4]);
    offset
}

fn address(symbol: u64, anchor: u64, actual: u64) -> Result<u64> {
    u64::try_from(i128::from(symbol) - i128::from(anchor) + i128::from(actual))
        .map_err(|_| anyhow!("probe-read target address overflow"))
}

pub(super) fn routine(layout: &RuntimeProbeReadLayout, user: bool, actual: u64)
    -> Result<(Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>)> {
    let anchor = if user { layout.user_helper } else { layout.kernel_helper };
    let target = |symbol| address(symbol, anchor, actual);
    let current = target(layout.current_task)?;
    if current as u32 as i32 as i64 as u64 != current {
        bail!("probe-read current_task GS address is not sign-extended disp32");
    }
    let task_offset = i32::try_from(layout.pagefault_disabled)?.to_le_bytes();
    let mut b = vec![0x53,0x41,0x54,0x41,0x55,0x41,0x56,0x41,0x57]; // five saves; aligned calls
    b.extend_from_slice(&[0x49,0x89,0xfc,0x41,0x89,0xf5,0x49,0x89,0xd6]); // r12=dst,r13d=size,r14=src
    let mut relocs = Vec::new();
    let mut denied = Vec::new();
    if user {
        b.extend_from_slice(&[0x48,0x89,0xd0,0x4c,0x01,0xe8]); // src+u32 size
        denied.push(append_x86_jcc_rel32(&mut b, 0x82)); // carry
        absolute(&mut b, &[0x49,0xbb], target(layout.user_ptr_max)?);
        b.extend_from_slice(&[0x49,0x3b,0x03]); // cmp rax,[r11]: live USER_PTR_MAX
        denied.push(append_x86_jcc_rel32(&mut b, 0x87)); // above
    } else {
        b.extend_from_slice(&[0x4c,0x89,0xf7,0x44,0x89,0xee]); // kernel allowed(src,size)
    }
    relocs.push(RelocRecord { offset: b.len() as u32, kind: 1,
        target: target(if user { layout.nmi_uaccess_okay } else { layout.kernel_allowed })? });
    b.extend_from_slice(&X86_HELPER_CALL_REL32_SLOT);
    b.extend_from_slice(&[0x84,0xc0]); // policy callback bool
    denied.push(append_x86_jcc_rel32(&mut b, 0x84));
    b.extend_from_slice(&[0x65,0x48,0x8b,0x1c,0x25]); // rbx=gs:current_task
    b.extend_from_slice(&(current as u32).to_le_bytes());
    b.extend_from_slice(&[0xff,0x83]); b.extend_from_slice(&task_offset); // pagefault_disable
    if user {
        absolute(&mut b, &[0x49,0xbb], target(layout.boot_cpu_data)?);
        b.extend_from_slice(&[0x41,0xf7,0x83]); // test boot_cpu_data.x86_capability[9],SMAP
        b.extend_from_slice(&i32::try_from(layout.x86_capability+9*4)?.to_le_bytes());
        b.extend_from_slice(&(1u32<<20).to_le_bytes()); // sole x86 cpufeatures.h X86_FEATURE_SMAP
        b.extend_from_slice(&[0x41,0x0f,0x95,0xc7]); // setne r15b; retains feature across copy
        let no_smap = append_x86_jcc_rel32(&mut b, 0x84);
        b.extend_from_slice(&[0x0f,0x01,0xcb]); // STAC only with actual CPU SMAP capability
        let after = b.len(); patch_x86_rel32(&mut b, no_smap, after)?;
        b.extend_from_slice(&[0x0f,0xae,0xe8]); // LFENCE before source access
    }
    b.extend_from_slice(&[0x4c,0x89,0xe7,0x4c,0x89,0xf6,0x44,0x89,0xe9]); // copy args
    b.extend_from_slice(&[0x41,0xbb,1,0,0,0]); // R11 fault status=success
    b.extend_from_slice(&[0x83,0xf9,8]);
    let subword = append_x86_jcc_rel32(&mut b, 0x82);
    let word_loop = b.len();
    let mut sites = vec![LoadSite { offset: b.len() as u32, insn_len: 3, destination: 11 }];
    b.extend_from_slice(&[0x48,0x8b,0x06]); // mov rax,[rsi]; recovery clears R11
    b.extend_from_slice(&[0x45,0x85,0xdb]);
    let fault_word = append_x86_jcc_rel32(&mut b, 0x84);
    b.extend_from_slice(&[0x48,0x89,0x07,0x48,0x83,0xc7,8,0x48,0x83,0xc6,8,0x83,0xe9,8,0x83,0xf9,8]);
    let again = append_x86_jcc_rel32(&mut b, 0x83);
    patch_x86_rel32(&mut b, again, word_loop)?;
    let byte_start = b.len(); patch_x86_rel32(&mut b, subword, byte_start)?;
    b.extend_from_slice(&[0x85,0xc9]);
    let complete = append_x86_jcc_rel32(&mut b, 0x84);
    let byte_loop = b.len();
    sites.push(LoadSite { offset: b.len() as u32, insn_len: 3, destination: 11 });
    b.extend_from_slice(&[0x0f,0xb6,0x06,0x45,0x85,0xdb]); // movzx eax,byte[rsi]; status
    let fault_byte = append_x86_jcc_rel32(&mut b, 0x84);
    b.extend_from_slice(&[0x88,0x07,0x48,0xff,0xc7,0x48,0xff,0xc6,0xff,0xc9]);
    let again = append_x86_jcc_rel32(&mut b, 0x85);
    patch_x86_rel32(&mut b, again, byte_loop)?;
    let success = b.len(); patch_x86_rel32(&mut b, complete, success)?;
    b.extend_from_slice(&[0x31,0xc0]);
    let cleanup_success = jump(&mut b);
    let fault = b.len();
    patch_x86_rel32(&mut b, fault_word, fault)?; patch_x86_rel32(&mut b, fault_byte, fault)?;
    b.extend_from_slice(&[0x48,0xc7,0xc0,0xf2,0xff,0xff,0xff]); // -EFAULT, sign extended
    let cleanup = b.len(); patch_x86_rel32(&mut b, cleanup_success, cleanup)?;
    if user {
        b.extend_from_slice(&[0x45,0x84,0xff]); // saved SMAP feature
        let skip = append_x86_jcc_rel32(&mut b, 0x84);
        b.extend_from_slice(&[0x0f,0x01,0xca]); // CLAC, both success and fault
        let after = b.len(); patch_x86_rel32(&mut b, skip, after)?;
    }
    b.extend_from_slice(&[0xff,0x8b]); b.extend_from_slice(&task_offset); // pagefault_enable
    b.extend_from_slice(&[0x48,0x85,0xc0]);
    let clean_return = append_x86_jcc_rel32(&mut b, 0x84);
    let zero_fault = jump(&mut b);
    let deny = b.len();
    for branch in denied { patch_x86_rel32(&mut b, branch, deny)?; }
    b.extend_from_slice(&[0x48,0xc7,0xc0]);
    b.extend_from_slice(&(if user { -14i32 } else { -34i32 }).to_le_bytes());
    let zero = b.len(); patch_x86_rel32(&mut b, zero_fault, zero)?;
    b.extend_from_slice(&[0x4c,0x89,0xe7,0x44,0x89,0xe9,0x31,0xd2,0x83,0xf9,8]);
    let zero_tail = append_x86_jcc_rel32(&mut b, 0x82);
    let zero_word = b.len();
    b.extend_from_slice(&[0x48,0x89,0x17,0x48,0x83,0xc7,8,0x83,0xe9,8,0x83,0xf9,8]);
    let again = append_x86_jcc_rel32(&mut b, 0x83); patch_x86_rel32(&mut b, again, zero_word)?;
    let tail = b.len(); patch_x86_rel32(&mut b, zero_tail, tail)?;
    b.extend_from_slice(&[0x85,0xc9]);
    let zero_done = append_x86_jcc_rel32(&mut b, 0x84);
    let zero_byte = b.len();
    b.extend_from_slice(&[0x88,0x17,0x48,0xff,0xc7,0xff,0xc9]);
    let again = append_x86_jcc_rel32(&mut b, 0x85); patch_x86_rel32(&mut b, again, zero_byte)?;
    let end = b.len();
    patch_x86_rel32(&mut b, clean_return, end)?; patch_x86_rel32(&mut b, zero_done, end)?;
    b.extend_from_slice(&[0x41,0x5f,0x41,0x5e,0x41,0x5d,0x41,0x5c,0x5b,0xc3]);
    Ok((b,relocs,sites))
}

pub(super) fn share(blob: &mut Vec<u8>, relocs: &mut Vec<RelocRecord>,
                    layout: &RuntimeProbeReadLayout, helpers: &HashMap<String,u64>)
    -> Result<(Vec<(usize,usize)>,Vec<LoadSite>)> {
    let mut ranges = Vec::new();
    let mut loads = Vec::new();
    for (name,user) in [("bpf_probe_read_user",true),("bpf_probe_read_kernel",false)] {
        let Some(&helper) = helpers.get(name) else { continue; };
        let calls: Vec<_> = relocs.iter().filter(|r| r.kind == 1 && r.target == helper)
            .map(|r| r.offset as usize).collect();
        if calls.is_empty() { continue; }
        let start = blob.len();
        let (bytes,mut nested,mut sites) = routine(layout,user,helper)?;
        for &site in &calls {
            if blob.get(site..site+5) != Some(X86_HELPER_CALL_REL32_SLOT.as_slice()) {
                bail!("probe-read call at {site:#x} lost its E8 helper slot");
            }
            patch_x86_rel32(blob,site+1,start)?;
        }
        relocs.retain(|r| !(r.kind == 1 && r.target == helper));
        for reloc in &mut nested { reloc.offset = u32::try_from(start+reloc.offset as usize)?; }
        for site in &mut sites { site.offset = u32::try_from(start+site.offset as usize)?; }
        blob.extend_from_slice(&bytes);
        relocs.extend(nested); loads.extend(sites); ranges.push((start,blob.len()));
    }
    Ok((ranges,loads))
}

#[cfg(all(test,target_arch="x86_64",target_os="linux"))]
mod tests {
    use super::*;
    fn fixture() -> RuntimeProbeReadLayout {
        RuntimeProbeReadLayout { user_helper:0x1000,kernel_helper:0x2000,
            nmi_uaccess_okay:0x3000,kernel_allowed:0x4000,current_task:0,
            user_ptr_max:0x1111222233334444,boot_cpu_data:0x5555666677778888,
            pagefault_disabled:4,x86_capability:0 }
    }

    #[test]
    fn emitted_probe_reads_execute_success_fault_partial_zero_policy_and_nesting() -> Result<()> {
        let output = std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT").map(PathBuf::from)
            .unwrap_or_else(|| std::env::temp_dir().join(format!("probe-read-{}",std::process::id())));
        fs::create_dir_all(&output)?;
        let source = PathBuf::from(env!("CARGO_MANIFEST_DIR"))
            .join("../../../perf/native-context/test-probe-read.c");
        let driver = output.join("check");
        let compile = std::process::Command::new("cc")
            .args(["-O2","-Wall","-Wextra","-Werror","-no-pie"])
            .arg(source).arg("-o").arg(&driver).output()?;
        fs::write(output.join("compile.stdout"),&compile.stdout)?;
        fs::write(output.join("compile.stderr"),&compile.stderr)?;
        if !compile.status.success() { bail!("probe-read host fixture compile: {}",String::from_utf8_lossy(&compile.stderr)); }
        let layout = fixture();
        for user in [false,true] {
            let anchor = if user { layout.user_helper } else { layout.kernel_helper };
            let (bytes,relocs,sites) = routine(&layout,user,anchor)?;
            let stem = if user { "user" } else { "kernel" };
            let binary = output.join(format!("{stem}.bin"));
            let metadata = output.join(format!("{stem}.sites"));
            fs::write(&binary,&bytes)?;
            assert_eq!(sites.len(),2); assert_eq!(relocs.len(),1);
            let mut text = String::new();
            for site in sites { text.push_str(&format!("{} {} {}\n",site.offset,site.insn_len,site.destination)); }
            text.push_str(&format!("{}\n",relocs[0].offset));
            fs::write(&metadata,text)?;
            let run = std::process::Command::new(&driver).arg(binary).arg(metadata)
                .arg(if user { "1" } else { "0" }).output()?;
            fs::write(output.join(format!("{stem}.stdout")),&run.stdout)?;
            fs::write(output.join(format!("{stem}.stderr")),&run.stderr)?;
            assert!(run.status.success(),"{stem} host execution: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
            println!("{}",String::from_utf8_lossy(&run.stdout));
        }
        Ok(())
    }

    #[test]
    fn shared_probe_calls_keep_other_helpers_and_source_status_metadata() -> Result<()> {
        let layout = fixture();
        let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(4); blob.push(0xc3);
        let mut relocs = vec![RelocRecord{offset:0,kind:1,target:0x1000},
            RelocRecord{offset:5,kind:1,target:0x1000},RelocRecord{offset:10,kind:1,target:0x2000},
            RelocRecord{offset:15,kind:1,target:0x9999}];
        let helpers = HashMap::from([("bpf_probe_read_user".into(),0x1000),("bpf_probe_read_kernel".into(),0x2000)]);
        let (ranges,sites) = share(&mut blob,&mut relocs,&layout,&helpers)?;
        assert_eq!(ranges.len(),2); assert_eq!(sites.len(),4);
        for (offset,range) in [(0,ranges[0]),(5,ranges[0]),(10,ranges[1])] {
            let disp = i32::from_le_bytes(blob[offset+1..offset+5].try_into()?);
            assert_eq!(offset as i64+5+i64::from(disp),range.0 as i64);
        }
        assert!(relocs.iter().any(|r| r.offset==15 && r.target==0x9999));
        assert_eq!(relocs.len(),3,"one policy callback per shared routine");
        for site in sites {
            assert_eq!(site.destination,11);
            let decoded = x86_decoded_load_sites(&blob,&ranges).into_iter()
                .find(|s| s.offset==site.offset).expect("actual source load");
            assert_eq!(decoded.insn_len,site.insn_len);
            assert_eq!(decoded.destination,0,"default decoder chooses RAX; LTO must override to R11");
        }
        Ok(())
    }
}
