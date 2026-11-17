//! Helper LTO for bpf_get_current_uid_gid, as one shared leaf per image: (gid << 32) | uid read from
//! current->cred, as kernel/bpf/helpers.c returns it. The helper converts both ids through init_user_ns,
//! whose uid and gid maps are the identity on every u32 value (kernel/user.c: one extent covering
//! [0, 0xfffffffe]; an id outside it returns (u32)-1, the same value) and are written once at boot
//! (user_namespace.c map_write takes a map only while it has no extents). A NULL current returns -EINVAL.
use super::*;

fn disp(value: u32) -> Result<[u8; 4]> {
    Ok(i32::try_from(value)?.to_le_bytes())
}

/// RAX=current, then current->cred; EDX=gid; result in RAX. Caller-saved registers only.
pub(super) fn uid_gid(current_task: u64, l: &RuntimeCredLayout) -> Result<Vec<u8>> {
    let current = probe_read::gs_disp32(current_task, "current_task")?;
    let mut b = vec![0x65,0x48,0x8b,0x04,0x25]; b.extend_from_slice(&current); // rax=current
    b.extend_from_slice(&[0x48,0x85,0xc0]); // test rax,rax
    let null = append_x86_jcc_rel32(&mut b, 0x84);
    b.extend_from_slice(&[0x48,0x8b,0x80]); b.extend_from_slice(&disp(l.task_cred)?); // rax=current->cred
    b.extend_from_slice(&[0x8b,0x90]); b.extend_from_slice(&disp(l.cred_gid)?); // edx=cred->gid
    b.extend_from_slice(&[0x8b,0x80]); b.extend_from_slice(&disp(l.cred_uid)?); // eax=cred->uid
    b.extend_from_slice(&[0x48,0xc1,0xe2,0x20,0x48,0x09,0xd0,0xc3]); // rax|=rdx<<32; ret
    let here = b.len(); patch_x86_rel32(&mut b, null, here)?;
    b.extend_from_slice(&[0x48,0xc7,0xc0,0xea,0xff,0xff,0xff,0xc3]); // -EINVAL
    Ok(b)
}

/// Every bpf_get_current_uid_gid call reaches one shared leaf.
pub(super) fn share(blob: &mut Vec<u8>, relocs: &mut Vec<RelocRecord>, current_task: u64, layout: &RuntimeCredLayout,
                    helper: u64) -> Result<Option<(usize, usize)>> {
    let calls: Vec<usize> = relocs.iter().filter(|r| r.kind == 1 && r.target == helper)
        .map(|r| r.offset as usize).collect();
    if calls.is_empty() { return Ok(None); }
    let bytes = uid_gid(current_task, layout)?;
    let start = blob.len();
    probe_read::redirect(blob, &calls, start)?;
    relocs.retain(|r| !(r.kind == 1 && r.target == helper));
    blob.extend_from_slice(&bytes);
    Ok(Some((start, blob.len())))
}

#[cfg(all(test,target_arch="x86_64",target_os="linux"))]
mod tests {
    use super::*;

    #[test]
    fn uid_gid_leaf_reads_current_cred_and_rejects_null_current() -> Result<()> {
        let output = std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT").map(PathBuf::from)
            .unwrap_or_else(|| std::env::temp_dir().join(format!("uid-gid-{}",std::process::id())));
        fs::create_dir_all(&output)?;
        let source = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("fixtures/task_driver.c");
        let driver = output.join("task-check");
        let compile = std::process::Command::new("cc").args(["-O2","-Wall","-Wextra","-Werror","-no-pie"])
            .arg(source).arg("-o").arg(&driver).output()?;
        if !compile.status.success() { bail!("task fixture compile: {}",String::from_utf8_lossy(&compile.stderr)); }
        let layout = RuntimeCredLayout { task_cred:16, cred_uid:8, cred_gid:12 };
        fs::write(output.join("uid-gid.bin"), uid_gid(0, &layout)?)?;
        let run = std::process::Command::new(&driver).arg(output.join("uid-gid.bin")).output()?;
        fs::write(output.join("uid-gid.stdout"), &run.stdout)?; fs::write(output.join("uid-gid.stderr"), &run.stderr)?;
        assert!(run.status.success(), "uid_gid host execution: {} {}", run.status, String::from_utf8_lossy(&run.stderr));
        println!("{}", String::from_utf8_lossy(&run.stdout));
        let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(2); blob.push(0xc3);
        let mut calls = vec![RelocRecord{offset:0,kind:1,target:0x7000}, RelocRecord{offset:5,kind:1,target:0x7000},
            RelocRecord{offset:20,kind:1,target:0x9999}];
        let range = share(&mut blob, &mut calls, 0, &layout, 0x7000)?.expect("one shared leaf");
        for offset in [0usize, 5] {
            let rel = i32::from_le_bytes(blob[offset+1..offset+5].try_into()?);
            assert_eq!(offset as i64 + 5 + i64::from(rel), range.0 as i64);
        }
        assert_eq!(calls.len(), 1, "the other helper call stays");
        Ok(())
    }
}
