//! Helper LTO for bpf_ktime_get_ns: ktime_get_mono_fast_ns with the kvm-clock read inline, as one shared
//! leaf per image. The latch loop and nanosecond conversion follow kernel/time/timekeeping.c
//! (__ktime_get_fast_ns, timekeeping_cycles_to_ns), the read follows arch/x86/kernel/kvmclock.c
//! (kvm_clock_read: preempt_disable_notrace, this_cpu_pvti) and arch/x86/kernel/pvclock.c
//! (__pvclock_clocksource_read: version loop, ordered TSC read, pvclock_scale_delta). Where the kernel
//! takes another branch (a clocksource other than kvm_clock, a TSC without PVCLOCK_TSC_STABLE_BIT in both
//! the vCPU flags and valid_flags, or a delta above clock->max_cycles), the leaf returns the kernel's own
//! ktime_get_mono_fast_ns, so the value always comes from the kernel's definition.
use super::*;

fn field(bytes: &mut Vec<u8>, opcode: &[u8], offset: u32) -> Result<()> {
    memory::Routine::operand(bytes, opcode, i32::try_from(offset)? as u32);
    Ok(())
}

fn gs(address: u64, what: &str) -> Result<[u8; 4]> {
    if address as u32 as i32 as i64 as u64 != address {
        bail!("ktime {what} GS address is not sign-extended disp32");
    }
    Ok((address as u32).to_le_bytes())
}

fn jump(bytes: &mut Vec<u8>) -> usize {
    bytes.push(0xe9);
    let offset = bytes.len();
    bytes.extend_from_slice(&[0; 4]);
    offset
}

fn call(b: &mut Vec<u8>, relocs: &mut Vec<RelocRecord>, target: u64) {
    relocs.push(RelocRecord { offset: b.len() as u32, kind: 1, target });
    b.extend_from_slice(&X86_HELPER_CALL_REL32_SLOT);
}

/// The leaf takes no arguments, returns nanoseconds in RAX and uses caller-saved registers only:
/// R11=&tk_fast_mono, EDI=latch sequence, R10=tk_read_base, R8=clock, R9=pvti, ESI=pvti version.
pub(super) fn routine(l: &RuntimeKtimeLayout, mono_fast: u64) -> Result<(Vec<u8>, Vec<RelocRecord>)> {
    let preempt = gs(l.preempt_count, "__preempt_count")?;
    let hv = gs(l.hv_clock_per_cpu, "hv_clock_per_cpu")?;
    let p = l.pvti;
    let mut b = Vec::new();
    let mut relocs = Vec::new();
    b.extend_from_slice(&[0x49,0xbb]); b.extend_from_slice(&l.tk_fast_mono.to_le_bytes()); // r11=&tk_fast_mono
    let latch = b.len();
    field(&mut b, &[0x41,0x8b,0xbb], l.seq)?; // edi=read_seqcount_latch
    field(&mut b, &[0x4d,0x8d,0x93], l.base)?; // r10=&base[0]
    b.extend_from_slice(&[0x40,0xf6,0xc7,0x01]); // test dil,1
    let even = append_x86_jcc_rel32(&mut b, 0x84);
    b.extend_from_slice(&[0x49,0x81,0xc2]); b.extend_from_slice(&i32::try_from(l.tkr_size)?.to_le_bytes()); // r10=&base[1]
    let here = b.len(); patch_x86_rel32(&mut b, even, here)?;
    field(&mut b, &[0x4d,0x8b,0x82], l.tkr_clock)?; // r8=READ_ONCE(tkr->clock)
    b.extend_from_slice(&[0x48,0xb8]); b.extend_from_slice(&l.kvm_clock.to_le_bytes()); // rax=&kvm_clock
    b.extend_from_slice(&[0x49,0x39,0xc0]); // cmp r8,rax
    let mut kernel_call = vec![append_x86_jcc_rel32(&mut b, 0x85)];
    // kvm_clock_read: preempt_disable_notrace(); pvclock_clocksource_read_nowd(this_cpu_pvti())
    b.extend_from_slice(&[0x65,0xff,0x04,0x25]); b.extend_from_slice(&preempt); // incl gs:__preempt_count
    b.extend_from_slice(&[0x65,0x4c,0x8b,0x0c,0x25]); b.extend_from_slice(&hv); // r9=this_cpu_read(hv_clock_per_cpu)
    let pv = b.len();
    field(&mut b, &[0x41,0x8b,0xb1], p+l.pv_version)?; // esi=src->version
    b.extend_from_slice(&[0x83,0xe6,0xfe]); // pvclock_read_begin: version & ~1
    b.extend_from_slice(&[0x0f,0xae,0xe8,0x0f,0x31]); // rdtsc_ordered: lfence; rdtsc
    b.extend_from_slice(&[0x48,0xc1,0xe2,0x20,0x48,0x09,0xd0]); // rax=tsc
    field(&mut b, &[0x49,0x2b,0x81], p+l.pv_tsc_timestamp)?; // delta
    field(&mut b, &[0x41,0x0f,0xbe,0x89], p+l.pv_tsc_shift)?; // ecx=(s8)tsc_shift
    b.extend_from_slice(&[0x85,0xc9]);
    let negative = append_x86_jcc_rel32(&mut b, 0x88);
    b.extend_from_slice(&[0x48,0xd3,0xe0]); // delta <<= shift
    let scaled = jump(&mut b);
    let here = b.len(); patch_x86_rel32(&mut b, negative, here)?;
    b.extend_from_slice(&[0xf7,0xd9,0x48,0xd3,0xe8]); // delta >>= -shift
    let here = b.len(); patch_x86_rel32(&mut b, scaled, here)?;
    field(&mut b, &[0x41,0x8b,0x91], p+l.pv_mul)?; // edx=tsc_to_system_mul
    b.extend_from_slice(&[0x48,0xf7,0xe2,0x48,0x0f,0xac,0xd0,0x20]); // mulq; shrd $32
    field(&mut b, &[0x49,0x03,0x81], p+l.pv_system_time)?; // +system_time
    field(&mut b, &[0x41,0x0f,0xb6,0x91], p+l.pv_flags)?; // edx=flags
    field(&mut b, &[0x41,0x3b,0xb1], p+l.pv_version)?; // pvclock_read_retry
    let again = append_x86_jcc_rel32(&mut b, 0x85); patch_x86_rel32(&mut b, again, pv)?;
    b.extend_from_slice(&[0xf6,0xc2,0x01]); // flags & PVCLOCK_TSC_STABLE_BIT
    let unstable_flags = append_x86_jcc_rel32(&mut b, 0x84);
    b.extend_from_slice(&[0x48,0xb9]); b.extend_from_slice(&l.valid_flags.to_le_bytes()); // rcx=&valid_flags
    b.extend_from_slice(&[0xf6,0x01,0x01]); // valid_flags & PVCLOCK_TSC_STABLE_BIT
    let unstable_valid = append_x86_jcc_rel32(&mut b, 0x84);
    // preempt_enable_notrace: decl; on zero the PREEMPT_DYNAMIC static call, which keeps every register
    b.extend_from_slice(&[0x65,0xff,0x0c,0x25]); b.extend_from_slice(&preempt);
    let enabled = append_x86_jcc_rel32(&mut b, 0x85);
    call(&mut b, &mut relocs, l.preempt_schedule_notrace);
    let here = b.len(); patch_x86_rel32(&mut b, enabled, here)?;
    // timekeeping_cycles_to_ns, then now = tkr->base + ns
    field(&mut b, &[0x49,0x2b,0x82], l.tkr_cycle_last)?;
    field(&mut b, &[0x49,0x23,0x82], l.tkr_mask)?;
    field(&mut b, &[0x49,0x3b,0x80], l.max_cycles)?; // delta > clock->max_cycles
    kernel_call.push(append_x86_jcc_rel32(&mut b, 0x87));
    field(&mut b, &[0x41,0x8b,0x92], l.tkr_mult)?; // edx=mult
    b.extend_from_slice(&[0x48,0x0f,0xaf,0xc2]); // delta * mult
    field(&mut b, &[0x49,0x03,0x82], l.tkr_xtime_nsec)?;
    field(&mut b, &[0x41,0x8b,0x8a], l.tkr_shift)?; // ecx=shift
    b.extend_from_slice(&[0x48,0xd3,0xe8]); // >> shift
    field(&mut b, &[0x49,0x03,0x82], l.tkr_base)?; // + tkr->base
    field(&mut b, &[0x41,0x3b,0xbb], l.seq)?; // read_seqcount_latch_retry
    let retry = append_x86_jcc_rel32(&mut b, 0x85); patch_x86_rel32(&mut b, retry, latch)?;
    b.push(0xc3);
    // Unstable TSC: close the preemption bracket, then the kernel's own path.
    let unstable = b.len();
    patch_x86_rel32(&mut b, unstable_flags, unstable)?; patch_x86_rel32(&mut b, unstable_valid, unstable)?;
    b.extend_from_slice(&[0x65,0xff,0x0c,0x25]); b.extend_from_slice(&preempt);
    kernel_call.push(append_x86_jcc_rel32(&mut b, 0x85));
    call(&mut b, &mut relocs, l.preempt_schedule_notrace);
    let here = b.len();
    for branch in kernel_call { patch_x86_rel32(&mut b, branch, here)?; }
    b.extend_from_slice(&[0x48,0x83,0xec,0x08]); // sub rsp,8
    call(&mut b, &mut relocs, mono_fast);
    b.extend_from_slice(&[0x48,0x83,0xc4,0x08,0xc3]); // add rsp,8; ret
    let (bytes, relocs, _) = probe_read::compact((b, relocs, Vec::new()))?;
    Ok((bytes, relocs))
}

/// Every bpf_ktime_get_ns call, bound to ktime_get_mono_fast_ns, reaches one shared leaf.
pub(super) fn share(blob: &mut Vec<u8>, relocs: &mut Vec<RelocRecord>, layout: &RuntimeKtimeLayout, mono_fast: u64)
    -> Result<Option<(usize, usize)>> {
    let calls: Vec<usize> = relocs.iter().filter(|r| r.kind == 1 && r.target == mono_fast)
        .map(|r| r.offset as usize).collect();
    if calls.is_empty() { return Ok(None); }
    let (bytes, nested) = routine(layout, mono_fast)?;
    let start = blob.len();
    probe_read::redirect(blob, &calls, start)?;
    relocs.retain(|r| !(r.kind == 1 && r.target == mono_fast));
    for mut reloc in nested { reloc.offset = u32::try_from(start + reloc.offset as usize)?; relocs.push(reloc); }
    blob.extend_from_slice(&bytes);
    Ok(Some((start, blob.len())))
}

#[cfg(all(test,target_arch="x86_64",target_os="linux"))]
mod tests {
    use super::*;
    fn fixture() -> RuntimeKtimeLayout {
        RuntimeKtimeLayout { tk_fast_mono:0x1234567800000001, seq:0, base:8, tkr_size:56,
            tkr_clock:0, tkr_mask:8, tkr_cycle_last:16, tkr_mult:24, tkr_shift:28, tkr_xtime_nsec:32, tkr_base:40,
            max_cycles:8, kvm_clock:0x1234567800000002, preempt_count:0, hv_clock_per_cpu:8, pvti:0,
            pv_version:0, pv_tsc_timestamp:8, pv_system_time:16, pv_mul:24, pv_tsc_shift:28, pv_flags:29,
            valid_flags:0x1234567800000003, preempt_schedule_notrace:0x4000 }
    }

    #[test]
    fn clock_fields_preserve_rex_registers_widths_and_displacement_boundaries() -> Result<()> {
        let mut cases=0;
        for (opcode,mnemonic,register,base,width) in [
            (&[0x41,0x8b,0xbb][..],Mnemonic::Mov,Register::EDI,Register::R11,4),
            (&[0x4d,0x8d,0x93],Mnemonic::Lea,Register::R10,Register::R11,0),
            (&[0x4d,0x8b,0x82],Mnemonic::Mov,Register::R8,Register::R10,8),
            (&[0x41,0x8b,0xb1],Mnemonic::Mov,Register::ESI,Register::R9,4),
            (&[0x49,0x2b,0x81],Mnemonic::Sub,Register::RAX,Register::R9,8),
            (&[0x41,0x0f,0xbe,0x89],Mnemonic::Movsx,Register::ECX,Register::R9,1),
            (&[0x41,0x8b,0x91],Mnemonic::Mov,Register::EDX,Register::R9,4),
            (&[0x49,0x03,0x81],Mnemonic::Add,Register::RAX,Register::R9,8),
            (&[0x41,0x0f,0xb6,0x91],Mnemonic::Movzx,Register::EDX,Register::R9,1),
            (&[0x41,0x3b,0xb1],Mnemonic::Cmp,Register::ESI,Register::R9,4),
            (&[0x49,0x2b,0x82],Mnemonic::Sub,Register::RAX,Register::R10,8),
            (&[0x49,0x23,0x82],Mnemonic::And,Register::RAX,Register::R10,8),
            (&[0x49,0x3b,0x80],Mnemonic::Cmp,Register::RAX,Register::R8,8),
            (&[0x41,0x8b,0x92],Mnemonic::Mov,Register::EDX,Register::R10,4),
            (&[0x49,0x03,0x82],Mnemonic::Add,Register::RAX,Register::R10,8),
            (&[0x41,0x8b,0x8a],Mnemonic::Mov,Register::ECX,Register::R10,4),
            (&[0x41,0x3b,0xbb],Mnemonic::Cmp,Register::EDI,Register::R11,4)] {
            for offset in [0u32,1,127,128,4096,i32::MAX as u32] {
                let mut bytes=Vec::new();field(&mut bytes,opcode,offset)?;
                let mut decoder=Decoder::new(64,&bytes,DecoderOptions::NONE);
                let i=decoder.decode();assert!(!i.is_invalid() && !decoder.can_decode());
                assert_eq!((i.mnemonic(),i.op0_register(),i.memory_base()),(mnemonic,register,base));
                assert_eq!(i.memory_index(),Register::None);
                assert_eq!(i.memory_displacement64(),u64::from(offset));
                assert_eq!(i.len(),opcode.len()+if offset==0 {0}else if offset<=127 {1}else{4});
                if width!=0 {assert_eq!(i.memory_size().size(),width);}
                cases+=1;
            }
        }
        println!("clock fields: {cases} REX/register/width/offset encodings PASS");
        Ok(())
    }

    #[test]
    fn ktime_leaf_follows_the_kernel_formula_and_calls_the_kernel() -> Result<()> {
        let output = std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT").map(PathBuf::from)
            .unwrap_or_else(|| std::env::temp_dir().join(format!("ktime-{}",std::process::id())));
        fs::create_dir_all(&output)?;
        let source = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("fixtures/ktime_driver.c");
        let driver = output.join("ktime-check");
        let compile = std::process::Command::new("cc").args(["-O2","-Wall","-Wextra","-Werror","-no-pie"])
            .arg(source).arg("-o").arg(&driver).output()?;
        if !compile.status.success() { bail!("ktime fixture compile: {}",String::from_utf8_lossy(&compile.stderr)); }
        let layout = fixture();
        let (bytes, relocs) = routine(&layout, 0x5000)?;
        assert_eq!(relocs.len(), 3);
        assert_eq!(relocs.iter().map(|r|r.target).collect::<Vec<_>>(),[0x4000,0x4000,0x5000]);
        for r in &relocs {
            assert_eq!(&bytes[r.offset as usize..r.offset as usize+5],X86_HELPER_CALL_REL32_SLOT.as_slice(),
                "sizing must preserve each external E8+zero patch slot");
        }
        let mut text = relocs.len().to_string(); text.push(char::from(10));
        for r in &relocs { text.push_str(&format!("{} {}\n", r.offset, u32::from(r.target == 0x5000))); }
        fs::write(output.join("ktime.bin"), &bytes)?; fs::write(output.join("ktime.relocs"), text)?;
        let run = std::process::Command::new(&driver).arg(output.join("ktime.bin")).arg(output.join("ktime.relocs")).output()?;
        fs::write(output.join("ktime.stdout"), &run.stdout)?; fs::write(output.join("ktime.stderr"), &run.stderr)?;
        assert!(run.status.success(), "ktime host execution: {} {}", run.status, String::from_utf8_lossy(&run.stderr));
        println!("{}", String::from_utf8_lossy(&run.stdout));
        let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(2); blob[5]=0xe9; blob.push(0xc3);
        let mut calls = vec![RelocRecord{offset:0,kind:1,target:0x5000}, RelocRecord{offset:5,kind:1,target:0x5000},
            RelocRecord{offset:20,kind:1,target:0x9999}];
        let range = share(&mut blob, &mut calls, &layout, 0x5000)?.expect("one shared leaf");
        assert_eq!((blob[0],blob[5]),(0xe8,0xe9));
        for offset in [0usize, 5] {
            let rel = i32::from_le_bytes(blob[offset+1..offset+5].try_into()?);
            assert_eq!(offset as i64 + 5 + i64::from(rel), range.0 as i64);
        }
        for r in calls.iter().filter(|r|r.target!=0x9999) {
            assert_eq!(&blob[r.offset as usize..r.offset as usize+5],X86_HELPER_CALL_REL32_SLOT.as_slice(),
                "shared helper relocation must include the final leaf offset exactly once");
        }
        assert_eq!(calls.len(), 4, "the other call stays and the leaf brings its three calls");
        assert_eq!(calls.iter().filter(|r| r.target == 0x5000).count(), 1, "only the leaf's own fallback calls the kernel");
        Ok(())
    }
}
