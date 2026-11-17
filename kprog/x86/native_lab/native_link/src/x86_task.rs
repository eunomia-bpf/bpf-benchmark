//! Helper LTO for bpf_get_current_uid_gid, as one shared leaf per image: (gid << 32) | uid read from
//! current->cred, as kernel/bpf/helpers.c returns it. The helper converts both ids through init_user_ns,
//! whose uid and gid maps are the identity on every u32 value (kernel/user.c: one extent covering
//! [0, 0xfffffffe]; an id outside it returns (u32)-1, the same value) and are written once at boot
//! (user_namespace.c map_write takes a map only while it has no extents). A NULL current returns -EINVAL.
use super::*;

fn load_field(bytes: &mut Vec<u8>, opcode: &[u8], offset: u32) -> Result<()> {
    let offset = i32::try_from(offset)?;
    memory::Routine::operand(bytes, opcode, offset as u32);
    Ok(())
}

/// RAX=current, then current->cred; EDX=gid; result in RAX. Caller-saved registers only.
pub(super) fn uid_gid(current_task: u64, l: &RuntimeCredLayout) -> Result<Vec<u8>> {
    let current = probe_read::gs_disp32(current_task, "current_task")?;
    let mut b = vec![0x65,0x48,0x8b,0x04,0x25]; b.extend_from_slice(&current); // rax=current
    b.extend_from_slice(&[0x48,0x85,0xc0]); // test rax,rax
    let null = append_x86_jcc_rel32(&mut b, 0x84);
    load_field(&mut b, &[0x48,0x8b,0x80], l.task_cred)?; // rax=current->cred
    // Published credentials are immutable; the existing BTF facts require u32 fields.
    // On x86 the adjacent UID/GID pair already has the helper's packed order.
    if u64::from(l.cred_gid) == u64::from(l.cred_uid) + 4 {
        load_field(&mut b, &[0x48,0x8b,0x80], l.cred_uid)?;
    } else {
        load_field(&mut b, &[0x8b,0x90], l.cred_gid)?;
        load_field(&mut b, &[0x8b,0x80], l.cred_uid)?;
        b.extend_from_slice(&[0x48,0xc1,0xe2,0x20,0x48,0x09,0xd0]);
    }
    b.push(0xc3);
    let here = b.len(); patch_x86_rel32(&mut b, null, here)?;
    b.extend_from_slice(&[0x48,0xc7,0xc0,0xea,0xff,0xff,0xff,0xc3]); // -EINVAL
    let (bytes, _, _) = probe_read::compact((b, Vec::new(), Vec::new()))?;
    Ok(bytes)
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
        let mut layouts=vec![
            RuntimeCredLayout{task_cred:16,cred_uid:8,cred_gid:12},
            RuntimeCredLayout{task_cred:17,cred_uid:7,cred_gid:11},
            RuntimeCredLayout{task_cred:0,cred_uid:0,cred_gid:4},
            RuntimeCredLayout{task_cred:100,cred_uid:123,cred_gid:127},
            RuntimeCredLayout{task_cred:128,cred_uid:124,cred_gid:128},
            RuntimeCredLayout{task_cred:256,cred_uid:128,cred_gid:132},
            RuntimeCredLayout{task_cred:128,cred_uid:0,cred_gid:8},
            RuntimeCredLayout{task_cred:127,cred_uid:24,cred_gid:4},
            RuntimeCredLayout{task_cred:0,cred_uid:128,cred_gid:256}];
        if let Some(path)=std::env::var_os("NATIVE_LINK_TASK_LAYOUT") {
            let facts:serde_json::Value=serde_json::from_str(&fs::read_to_string(path)?)?;
            layouts.push(serde_json::from_value(facts["layout"].clone())?);
        }
        let mut sizes=String::from("layout task_cred uid gid packed bytes\n");
        for (i,l) in layouts.iter().enumerate() {
            let bytes=uid_gid(0,l)?;
            let packed=u64::from(l.cred_gid)==u64::from(l.cred_uid)+4;
            let mut decoder=Decoder::new(64,&bytes,DecoderOptions::NONE);let mut reads=0;
            while decoder.can_decode() {
                let insn=decoder.decode();assert!(!insn.is_invalid());
                reads+=usize::from((0..insn.op_count()).any(|op|insn.op_kind(op)==OpKind::Memory));
            }
            assert_eq!(reads,if packed {3}else{4},"do not fuse nonadjacent/reversed fields");
            let name=if i==0 {"uid-gid".to_owned()}else{format!("uid-gid-layout{i}")};
            let binary=output.join(format!("{name}.bin"));fs::write(&binary,&bytes)?;
            let run=std::process::Command::new(&driver).arg(binary)
                .args([l.task_cred.to_string(),l.cred_uid.to_string(),l.cred_gid.to_string()]).output()?;
            fs::write(output.join(format!("{name}.stdout")),&run.stdout)?;
            fs::write(output.join(format!("{name}.stderr")),&run.stderr)?;
            assert!(run.status.success(),"UID layout{i}: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
            println!("{}",String::from_utf8_lossy(&run.stdout));
            sizes.push_str(&format!("{i} {} {} {} {packed} {}\n",l.task_cred,l.cred_uid,l.cred_gid,bytes.len()));
        }
        fs::write(output.join("uid-gid-sizes.txt"),sizes)?;
        let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(2); blob[5]=0xe9; blob.push(0xc3);
        let mut calls = vec![RelocRecord{offset:0,kind:1,target:0x7000}, RelocRecord{offset:5,kind:1,target:0x7000},
            RelocRecord{offset:20,kind:1,target:0x9999}];
        let range = share(&mut blob, &mut calls, 0, &layout, 0x7000)?.expect("one shared leaf");
        assert_eq!((blob[0],blob[5]),(0xe8,0xe9));
        for offset in [0usize, 5] {
            let rel = i32::from_le_bytes(blob[offset+1..offset+5].try_into()?);
            assert_eq!(offset as i64 + 5 + i64::from(rel), range.0 as i64);
        }
        assert_eq!(calls.len(), 1, "the other helper call stays");
        Ok(())
    }
}
