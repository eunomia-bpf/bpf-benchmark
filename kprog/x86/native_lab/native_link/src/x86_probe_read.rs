//! Helper LTO: preserve access policy, fault nesting, errors and full
//! destination zeroing. Recover source loads through existing EX_TYPE_BPF by
//! clearing R11 status, not by pretending a fault was a successful zero load.
use super::*;

fn absolute(bytes: &mut Vec<u8>, opcode: &[u8], address: u64) {
    bytes.extend_from_slice(opcode);
    bytes.extend_from_slice(&address.to_le_bytes());
}

// Use a 64-bit-address-size absolute SIB operand; disp32 is sign extended.
// Values remain live. Other addresses use the same R11 scratch as before.
fn live_global(bytes: &mut Vec<u8>, compact: &[u8], wide: &[u8], address: u64) {
    if address as u32 as i32 as i64 as u64 == address {
        bytes.extend_from_slice(compact);
        bytes.extend_from_slice(&(address as u32).to_le_bytes());
    } else {
        absolute(bytes, &[0x49,0xbb], address);
        bytes.extend_from_slice(wide);
    }
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

pub(super) fn gs_disp32(address: u64, what: &str) -> Result<[u8; 4]> {
    if address as u32 as i32 as i64 as u64 != address {
        bail!("probe-read {what} GS address is not sign-extended disp32");
    }
    Ok((address as u32).to_le_bytes())
}

/// RDI=dst, RSI=src, ECX=size, R11=1. Eight-byte words, then an empty remainder goes straight
/// to success; otherwise one 4-, one 2- and one 1-byte step, as mm/maccess.c copies. Every load
/// is a recovered site whose fault clears R11; success leaves EAX=0.
fn copy_fixed(b: &mut Vec<u8>, sites: &mut Vec<LoadSite>, faults: &mut Vec<usize>, size: u32) -> Result<()> {
    let words=size/8;
    if words>1 {b.push(0xb9);b.extend_from_slice(&words.to_le_bytes());}
    let word_loop=b.len();
    for width in [8u32,4,2,1] {
        let present=if width==8 {words!=0} else {size & width != 0};
        if !present {continue;}
        let load:&[u8]=match width {8=>&[0x48,0x8b,0x06],4=>&[0x8b,0x06],
            2=>&[0x0f,0xb7,0x06],1=>&[0x0f,0xb6,0x06],_=>unreachable!()};
        sites.push(LoadSite{offset:b.len() as u32,insn_len:load.len() as u16,destination:11});
        b.extend_from_slice(load);b.extend_from_slice(&[0x45,0x85,0xdb]);
        faults.push(append_x86_jcc_rel32(b,0x84));
        b.extend_from_slice(match width {8=>&[0x48,0x89,0x07][..],4=>&[0x89,0x07],
            2=>&[0x66,0x89,0x07],1=>&[0x88,0x07],_=>unreachable!()});
        if (width==8 && words>1) || size & (width-1)!=0 {
            b.extend_from_slice(&[0x48,0x83,0xc7,width as u8,0x48,0x83,0xc6,width as u8]);
        }
        if width==8 && words>1 {
            b.extend_from_slice(&[0xff,0xc9]);
            let again=append_x86_jcc_rel32(b,0x85);patch_x86_rel32(b,again,word_loop)?;
        }
    }
    b.extend_from_slice(&[0x31,0xc0]);
    Ok(())
}

fn copy_words(b: &mut Vec<u8>, sites: &mut Vec<LoadSite>, faults: &mut Vec<usize>, fixed: Option<u32>) -> Result<()> {
    if let Some(size)=fixed {return copy_fixed(b,sites,faults,size);}
    b.extend_from_slice(&[0x83,0xf9,8]);
    let subword = append_x86_jcc_rel32(b, 0x82);
    let word_loop = b.len();
    sites.push(LoadSite { offset: b.len() as u32, insn_len: 3, destination: 11 });
    b.extend_from_slice(&[0x48,0x8b,0x06]); // mov rax,[rsi]; recovery clears R11
    b.extend_from_slice(&[0x45,0x85,0xdb]);
    faults.push(append_x86_jcc_rel32(b, 0x84));
    b.extend_from_slice(&[0x48,0x89,0x07,0x48,0x83,0xc7,8,0x48,0x83,0xc6,8,0x83,0xe9,8,0x83,0xf9,8]);
    let again = append_x86_jcc_rel32(b, 0x83);
    patch_x86_rel32(b, again, word_loop)?;
    let tail_start = b.len(); patch_x86_rel32(b, subword, tail_start)?;
    b.extend_from_slice(&[0x85,0xc9]); // test ecx,ecx
    let empty = append_x86_jcc_rel32(b, 0x84);
    b.extend_from_slice(&[0x83,0xf9,4]); // cmp ecx,4
    let below4 = append_x86_jcc_rel32(b, 0x82);
    sites.push(LoadSite { offset: b.len() as u32, insn_len: 2, destination: 11 });
    b.extend_from_slice(&[0x8b,0x06,0x45,0x85,0xdb]); // mov eax,[rsi]; status
    faults.push(append_x86_jcc_rel32(b, 0x84));
    b.extend_from_slice(&[0x89,0x07,0x48,0x83,0xc7,4,0x48,0x83,0xc6,4,0x83,0xe9,4]);
    let two = b.len(); patch_x86_rel32(b, below4, two)?;
    b.extend_from_slice(&[0x83,0xf9,2]); // cmp ecx,2
    let below2 = append_x86_jcc_rel32(b, 0x82);
    sites.push(LoadSite { offset: b.len() as u32, insn_len: 3, destination: 11 });
    b.extend_from_slice(&[0x0f,0xb7,0x06,0x45,0x85,0xdb]); // movzx eax,word[rsi]; status
    faults.push(append_x86_jcc_rel32(b, 0x84));
    b.extend_from_slice(&[0x66,0x89,0x07,0x48,0x83,0xc7,2,0x48,0x83,0xc6,2,0x83,0xe9,2]);
    let one = b.len(); patch_x86_rel32(b, below2, one)?;
    b.extend_from_slice(&[0x85,0xc9]);
    let complete = append_x86_jcc_rel32(b, 0x84);
    sites.push(LoadSite { offset: b.len() as u32, insn_len: 3, destination: 11 });
    b.extend_from_slice(&[0x0f,0xb6,0x06,0x45,0x85,0xdb]); // movzx eax,byte[rsi]; status
    faults.push(append_x86_jcc_rel32(b, 0x84));
    b.extend_from_slice(&[0x88,0x07]);
    let success = b.len(); patch_x86_rel32(b, complete, success)?; patch_x86_rel32(b, empty, success)?;
    b.extend_from_slice(&[0x31,0xc0]);
    Ok(())
}

/// Zero the whole destination from the saved dst and size that `saved` moves into RDI and ECX;
/// returns the branch that leaves after a zero-length destination.
fn zero_fill(b: &mut Vec<u8>, saved: &[u8]) -> Result<usize> {
    b.extend_from_slice(saved);
    b.extend_from_slice(&[0x31,0xd2,0x83,0xf9,8]);
    let zero_tail = append_x86_jcc_rel32(b, 0x82);
    let zero_word = b.len();
    b.extend_from_slice(&[0x48,0x89,0x17,0x48,0x83,0xc7,8,0x83,0xe9,8,0x83,0xf9,8]);
    let again = append_x86_jcc_rel32(b, 0x83); patch_x86_rel32(b, again, zero_word)?;
    let tail = b.len(); patch_x86_rel32(b, zero_tail, tail)?;
    b.extend_from_slice(&[0x85,0xc9]);
    let zero_done = append_x86_jcc_rel32(b, 0x84);
    let zero_byte = b.len();
    b.extend_from_slice(&[0x88,0x17,0x48,0xff,0xc7,0xff,0xc9]);
    let again = append_x86_jcc_rel32(b, 0x85); patch_x86_rel32(b, again, zero_byte)?;
    Ok(zero_done)
}

/// strncpy_from_user's word path masks the bytes after NUL. A word fault retries at the same
/// address bytewise; only a byte fault fails. RDX and R11 are scratch after each status test.
fn copy_user_string(b: &mut Vec<u8>, sites: &mut Vec<LoadSite>, faults: &mut Vec<usize>) -> Result<()> {
    b.extend_from_slice(&[0x83,0xf9,8]);
    let short = append_x86_jcc_rel32(b,0x82);
    let words = b.len();
    b.extend_from_slice(&[0x41,0xbb,1,0,0,0]);
    sites.push(LoadSite{offset:b.len() as u32,insn_len:3,destination:11});
    b.extend_from_slice(&[0x48,0x8b,0x06,0x45,0x85,0xdb]);
    let retry = append_x86_jcc_rel32(b,0x84);
    absolute(b,&[0x48,0xba],0xfefefefefefefeff);
    b.extend_from_slice(&[0x48,0x01,0xc2,0x49,0x89,0xc3,0x49,0xf7,0xd3,0x4c,0x21,0xda]);
    absolute(b,&[0x49,0xbb],0x8080808080808080);
    b.extend_from_slice(&[0x4c,0x21,0xda]); // (word - ones) & ~word & high_bits
    let zero_word = append_x86_jcc_rel32(b,0x85);
    b.extend_from_slice(&[0x48,0x89,0x07,0x48,0x83,0xc7,8,0x48,0x83,0xc6,8,0x83,0xe9,8,0x83,0xf9,8]);
    let again = append_x86_jcc_rel32(b,0x83); patch_x86_rel32(b,again,words)?;
    let remainder = jump(b);
    let nul = b.len(); patch_x86_rel32(b,zero_word,nul)?;
    // BSF selects the first zero byte even when subtraction borrows across later bytes.
    b.extend_from_slice(&[0x48,0x0f,0xbc,0xca,0x83,0xe1,0xf8,0x48,0xc7,0xc2,0xff,0xff,0xff,0xff,
        0x48,0xd3,0xe2,0x48,0xf7,0xd2,0x48,0x21,0xd0,0x48,0x89,0x07,
        0xc1,0xe9,3,0x48,0x8d,0x7c,0x0f,1]); // mask/store word; rdi += first_zero + 1
    let word_done = jump(b);
    let bytes = b.len();
    for branch in [short,retry,remainder] {patch_x86_rel32(b,branch,bytes)?;}
    b.extend_from_slice(&[0x85,0xc9]);
    let empty = append_x86_jcc_rel32(b,0x84);
    let byte = b.len();
    b.extend_from_slice(&[0x41,0xbb,1,0,0,0]); // reset after a word fault or mask scratch
    sites.push(LoadSite{offset:b.len() as u32,insn_len:3,destination:11});
    b.extend_from_slice(&[0x0f,0xb6,0x06,0x45,0x85,0xdb]);
    faults.push(append_x86_jcc_rel32(b,0x84));
    b.extend_from_slice(&[0x88,0x07,0x48,0xff,0xc7,0x48,0xff,0xc6,0x84,0xc0]);
    let zero_byte = append_x86_jcc_rel32(b,0x84);
    b.extend_from_slice(&[0xff,0xc9]);
    let again = append_x86_jcc_rel32(b,0x85); patch_x86_rel32(b,again,byte)?;
    let truncated = b.len(); patch_x86_rel32(b,empty,truncated)?;
    b.extend_from_slice(&[0xc6,0x47,0xff,0]); // count exhaustion forces the last copied byte to NUL
    let done = b.len();
    for branch in [zero_byte,word_done] {patch_x86_rel32(b,branch,done)?;}
    b.extend_from_slice(&[0x48,0x89,0xf8,0x4c,0x29,0xc0,0x48,0x63,0xc0]); // length includes NUL, cast to int
    Ok(())
}

/// User read leaves: scalar __access_ok/nmi_uaccess_okay or string masked_user_access_begin,
/// pagefault_disable, STAC
/// with SMAP, copy, CLAC, pagefault_enable; denial and faults zero the destination. It uses
/// caller-saved registers only: R8=dst, R9D=size, R10=current. Scalar keeps SMAP in DL;
/// string keeps it in R9 bit32 so its word-mask scratch cannot destroy the cleanup state.
fn user_leaf(layout: &RuntimeProbeReadLayout, actual: u64, string: bool, fixed: Option<u32>)
    -> Result<(Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>)> {
    let target = |symbol| address(symbol, layout.user_helper, actual);
    let current = gs_disp32(target(layout.current_task)?, "current_task")?;
    let task_offset = i32::try_from(layout.pagefault_disabled)?.to_le_bytes();
    let mut b = vec![0x49,0x89,0xf8,0x41,0x89,0xf1]; // r8=dst, r9d=size; RDX keeps src
    let zero_return=if string {
        b.extend_from_slice(&[0x31,0xc0,0x45,0x85,0xc9]);
        Some(append_x86_jcc_rel32(&mut b,0x84))
    } else {None};
    let mut denied = Vec::new();
    // __access_ok(src,size): src+size <= USER_PTR_MAX without wrap. USER_PTR_MAX is TASK_SIZE_MAX
    // (at least 2^47 - PAGE_SIZE) and exceeds every u32 size, so this is src <= USER_PTR_MAX-size.
    live_global(&mut b, &[0x48,0x8b,0x04,0x25], &[0x49,0x8b,0x03], target(layout.user_ptr_max)?);
    if string {
        b.extend_from_slice(&[0x48,0x39,0xc2,0x48,0x0f,0x47,0xd0]); // rdx=min(src,USER_PTR_MAX)
    } else {
        b.extend_from_slice(&[0x4c,0x29,0xc8,0x48,0x39,0xc2]);
        denied.push(append_x86_jcc_rel32(&mut b, 0x87));
    }
    // nmi_uaccess_okay: this CPU's cpu_tlbstate.loaded_mm equals current->mm.
    b.extend_from_slice(&[0x65,0x4c,0x8b,0x14,0x25]); b.extend_from_slice(&current); // r10=gs:current_task
    if !string {
        let loaded_mm = gs_disp32(target(layout.cpu_tlbstate)?.wrapping_add(u64::from(layout.tlb_loaded_mm)),
            "cpu_tlbstate.loaded_mm")?;
        b.extend_from_slice(&[0x65,0x48,0x8b,0x04,0x25]); b.extend_from_slice(&loaded_mm);
        b.extend_from_slice(&[0x49,0x3b,0x82]); b.extend_from_slice(&i32::try_from(layout.task_mm)?.to_le_bytes());
        denied.push(append_x86_jcc_rel32(&mut b, 0x85));
    }
    b.extend_from_slice(&[0x41,0xff,0x82]); b.extend_from_slice(&task_offset); // pagefault_disable
    b.extend_from_slice(&[0x48,0x89,0xd6]); // rsi=src
    live_global(&mut b, &[0xf7,0x04,0x25], &[0x41,0xf7,0x03],
        target(layout.boot_cpu_data)?.wrapping_add(u64::from(layout.x86_capability)+9*4)); // test capability[9],SMAP
    b.extend_from_slice(&(1u32<<20).to_le_bytes()); // sole x86 cpufeatures.h X86_FEATURE_SMAP
    if !string {b.extend_from_slice(&[0x0f,0x95,0xc2]);} // setne dl
    let no_smap = append_x86_jcc_rel32(&mut b, 0x84);
    b.extend_from_slice(&[0x0f,0x01,0xcb]); // STAC only with actual CPU SMAP capability
    if string {b.extend_from_slice(&[0x49,0x0f,0xba,0xe9,32]);} // bts r9,32
    let after = b.len(); patch_x86_rel32(&mut b, no_smap, after)?;
    b.extend_from_slice(&[0x4c,0x89,0xc7]); // rdi=dst
    if string || fixed.is_none() {b.extend_from_slice(&[0x44,0x89,0xc9]);} // ecx=size
    if !string {b.extend_from_slice(&[0x41,0xbb,1,0,0,0]);}
    let mut sites = Vec::new(); let mut faults = Vec::new();
    if string {copy_user_string(&mut b,&mut sites,&mut faults)?;} else {copy_words(&mut b,&mut sites,&mut faults,fixed)?;}
    let cleanup_success = jump(&mut b);
    let fault = b.len();
    for branch in faults { patch_x86_rel32(&mut b, branch, fault)?; }
    b.extend_from_slice(&[0x48,0xc7,0xc0,0xf2,0xff,0xff,0xff]); // -EFAULT, sign extended
    let cleanup = b.len(); patch_x86_rel32(&mut b, cleanup_success, cleanup)?;
    if string {b.extend_from_slice(&[0x49,0x0f,0xba,0xe1,32]);} else {b.extend_from_slice(&[0x84,0xd2]);}
    let skip = append_x86_jcc_rel32(&mut b, if string {0x83} else {0x84});
    b.extend_from_slice(&[0x0f,0x01,0xca]); // CLAC, both success and fault
    let after = b.len(); patch_x86_rel32(&mut b, skip, after)?;
    b.extend_from_slice(&[0x41,0xff,0x8a]); b.extend_from_slice(&task_offset); // pagefault_enable
    b.extend_from_slice(&[0x48,0x85,0xc0]);
    let clean_return = append_x86_jcc_rel32(&mut b, if string {0x89} else {0x84});
    let zero_fault = jump(&mut b);
    if !string {
        let deny = b.len();
        for branch in denied { patch_x86_rel32(&mut b, branch, deny)?; }
        b.extend_from_slice(&[0x48,0xc7,0xc0,0xf2,0xff,0xff,0xff]); // -EFAULT
    }
    let zero = b.len(); patch_x86_rel32(&mut b, zero_fault, zero)?;
    let zero_done = zero_fill(&mut b, &[0x4c,0x89,0xc7,0x44,0x89,0xc9])?; // rdi=r8, ecx=r9d
    let end = b.len();
    patch_x86_rel32(&mut b, clean_return, end)?; patch_x86_rel32(&mut b, zero_done, end)?;
    if let Some(branch)=zero_return {patch_x86_rel32(&mut b,branch,end)?;}
    b.push(0xc3);
    compact((b, Vec::new(), sites))
}

/// copy_from_kernel_nofault and strncpy_from_kernel_nofault as leaves: copy_from_kernel_nofault_allowed
/// inline (an address below TASK_SIZE_MAX + PAGE_SIZE, in the vsyscall page, or non-canonical at
/// boot_cpu_data.x86_virt_bits gets -ERANGE; width zero allows), pagefault_disable, copy,
/// pagefault_enable; denial and faults zero the destination. It uses caller-saved registers only:
/// R8=dst, R9D=size, RDX=src, R10=current.
fn kernel_routine(layout: &RuntimeProbeReadLayout, actual: u64, string: bool, fixed: Option<u32>)
    -> Result<(Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>)> {
    let target = |symbol| address(symbol, layout.kernel_helper, actual);
    let current = gs_disp32(target(layout.current_task)?, "current_task")?;
    let task_offset = i32::try_from(layout.pagefault_disabled)?.to_le_bytes();
    let mut b = vec![0x49,0x89,0xf8,0x41,0x89,0xf1]; // r8=dst, r9d=size; RDX keeps src
    let zero_return=if string {
        b.extend_from_slice(&[0x31,0xc0,0x45,0x85,0xc9]); // a zero count returns 0 ahead of the policy
        Some(append_x86_jcc_rel32(&mut b,0x84))
    } else {None};
    let mut denied = Vec::new();
    // vaddr < TASK_SIZE_MAX + PAGE_SIZE; this kernel sets USER_PTR_MAX = TASK_SIZE_MAX (cpu/common.c).
    live_global(&mut b, &[0x48,0x8b,0x04,0x25], &[0x49,0x8b,0x03], target(layout.user_ptr_max)?);
    b.extend_from_slice(&[0x48,0x05,0,0x10,0,0,0x48,0x39,0xc2]); // rax=TASK_SIZE_MAX+4096; cmp rdx,rax
    denied.push(append_x86_jcc_rel32(&mut b, 0x82)); // below
    // is_vsyscall_vaddr: (vaddr & PAGE_MASK) == VSYSCALL_ADDR, -10UL << 20
    b.extend_from_slice(&[0x48,0x89,0xd0,0x48,0x25,0,0xf0,0xff,0xff,0x48,0x3d,0,0,0x60,0xff]);
    denied.push(append_x86_jcc_rel32(&mut b, 0x84));
    // Canonical at boot_cpu_data.x86_virt_bits. Shift counts are taken mod 64, so width zero shifts by zero and
    // the address compares equal: early boot (width zero) allows, as the C source does.
    live_global(&mut b, &[0x0f,0xb6,0x0c,0x25], &[0x41,0x0f,0xb6,0x0b],
        target(layout.boot_cpu_data)?.wrapping_add(u64::from(layout.x86_virt_bits))); // movzx ecx,byte[virt_bits]
    b.extend_from_slice(&[0xf7,0xd9,0x48,0x89,0xd0,0x48,0xd3,0xe0,0x48,0xd3,0xf8,0x48,0x39,0xd0]); // shl/sar by 64-bits; cmp rax,rdx
    denied.push(append_x86_jcc_rel32(&mut b, 0x85));
    b.extend_from_slice(&[0x65,0x4c,0x8b,0x14,0x25]); b.extend_from_slice(&current); // r10=gs:current_task
    b.extend_from_slice(&[0x41,0xff,0x82]); b.extend_from_slice(&task_offset); // pagefault_disable
    b.extend_from_slice(&[0x48,0x89,0xd6,0x4c,0x89,0xc7]); // rsi=src, rdi=dst
    if string || fixed.is_none() {b.extend_from_slice(&[0x44,0x89,0xc9]);}
    b.extend_from_slice(&[0x41,0xbb,1,0,0,0]); // r11d=1
    let mut sites=Vec::new(); let mut faults=Vec::new();
    if string {
        let loop_start=b.len();
        sites.push(LoadSite{offset:b.len() as u32,insn_len:3,destination:11});
        b.extend_from_slice(&[0x0f,0xb6,0x06,0x45,0x85,0xdb]);
        faults.push(append_x86_jcc_rel32(&mut b,0x84));
        b.extend_from_slice(&[0x88,0x07,0x48,0xff,0xc7,0x48,0xff,0xc6,0x84,0xc0]); // store; dst++; src++; test al,al
        let nul=append_x86_jcc_rel32(&mut b,0x84);
        b.extend_from_slice(&[0xff,0xc9]); // dec ecx: its zero flag ends the count
        let again=append_x86_jcc_rel32(&mut b,0x85);patch_x86_rel32(&mut b,again,loop_start)?;
        b.extend_from_slice(&[0xc6,0x47,0xff,0]); // count reached: dst[-1]=0
        let end=b.len();patch_x86_rel32(&mut b,nul,end)?; // a copied NUL already ends the string
        b.extend_from_slice(&[0x48,0x89,0xf8,0x4c,0x29,0xc0,0x48,0x63,0xc0]); // length as signed int
    } else {
        copy_words(&mut b, &mut sites, &mut faults,fixed)?;
    }
    let cleanup_success = jump(&mut b);
    let fault = b.len();
    for branch in faults {patch_x86_rel32(&mut b,branch,fault)?;}
    b.extend_from_slice(&[0x48,0xc7,0xc0,0xf2,0xff,0xff,0xff]); // -EFAULT, sign extended
    let cleanup = b.len(); patch_x86_rel32(&mut b, cleanup_success, cleanup)?;
    b.extend_from_slice(&[0x41,0xff,0x8a]); b.extend_from_slice(&task_offset); // pagefault_enable
    b.extend_from_slice(&[0x48,0x85,0xc0]);
    let clean_return = append_x86_jcc_rel32(&mut b, if string {0x89} else {0x84});
    let zero_fault = jump(&mut b);
    let deny = b.len();
    for branch in denied { patch_x86_rel32(&mut b, branch, deny)?; }
    b.extend_from_slice(&[0x48,0xc7,0xc0]);
    b.extend_from_slice(&(-34i32).to_le_bytes()); // -ERANGE
    let zero = b.len(); patch_x86_rel32(&mut b, zero_fault, zero)?;
    let zero_done = zero_fill(&mut b, &[0x4c,0x89,0xc7,0x44,0x89,0xc9])?; // rdi=r8, ecx=r9d
    let end = b.len();
    patch_x86_rel32(&mut b, clean_return, end)?; patch_x86_rel32(&mut b, zero_done, end)?;
    if let Some(branch)=zero_return {patch_x86_rel32(&mut b,branch,end)?;}
    b.push(0xc3);
    compact((b, Vec::new(), sites))
}

/// bpf_probe_read (compat) as bpf_trace.c defines it: an address below TASK_SIZE is read as user memory,
/// the rest as kernel memory. TASK_SIZE is TASK_SIZE_MAX (USER_PTR_MAX on this kernel) unless the task has
/// TIF_ADDR32 (bit 27 of thread_info.flags), where it is IA32_PAGE_OFFSET: 0xc0000000 under the
/// ADDR_LIMIT_3GB (0x8000000) personality and 0xffffe000 otherwise (page_64_types.h). RDI, ESI and RDX
/// reach the chosen leaf unchanged.
fn compat_dispatch(layout: &RuntimeProbeReadLayout, actual: u64, start: usize, user: usize, kernel: usize)
    -> Result<Vec<u8>> {
    let target = |symbol| address(symbol, layout.kernel_helper, actual);
    let current = gs_disp32(target(layout.current_task)?, "current_task")?;
    let mut b = vec![0x65,0x4c,0x8b,0x14,0x25]; b.extend_from_slice(&current); // r10=gs:current_task
    b.extend_from_slice(&[0x41,0xf7,0x82]); b.extend_from_slice(&i32::try_from(layout.task_flags)?.to_le_bytes());
    b.extend_from_slice(&(1u32<<27).to_le_bytes()); // test TIF_ADDR32
    let ia32 = append_x86_jcc_rel32(&mut b, 0x85);
    live_global(&mut b, &[0x48,0x8b,0x04,0x25], &[0x49,0x8b,0x03], target(layout.user_ptr_max)?);
    let to_compare = jump(&mut b);
    let here = b.len(); patch_x86_rel32(&mut b, ia32, here)?;
    b.extend_from_slice(&[0xb8,0x00,0xe0,0xff,0xff]); // eax=0xffffe000
    b.extend_from_slice(&[0x41,0xf7,0x82]); b.extend_from_slice(&i32::try_from(layout.task_personality)?.to_le_bytes());
    b.extend_from_slice(&0x0800_0000u32.to_le_bytes()); // test ADDR_LIMIT_3GB
    let full = append_x86_jcc_rel32(&mut b, 0x84);
    b.extend_from_slice(&[0xb8,0x00,0x00,0x00,0xc0]); // eax=0xc0000000
    let compare = b.len(); patch_x86_rel32(&mut b, to_compare, compare)?; patch_x86_rel32(&mut b, full, compare)?;
    b.extend_from_slice(&[0x48,0x39,0xc2,0x0f,0x82]); // cmp rdx,rax; jb user
    let rel = i64::try_from(user)? - i64::try_from(start + b.len() + 4)?;
    b.extend_from_slice(&i32::try_from(rel)?.to_le_bytes());
    b.push(0xe9); // jmp kernel
    let rel = i64::try_from(kernel)? - i64::try_from(start + b.len() + 4)?;
    b.extend_from_slice(&i32::try_from(rel)?.to_le_bytes());
    Ok(b)
}

fn calls_to(relocs: &[RelocRecord], helper: u64) -> Vec<usize> {
    relocs.iter().filter(|r| r.kind == 1 && r.target == helper).map(|r| r.offset as usize).collect()
}

pub(super) fn redirect(blob: &mut Vec<u8>, calls: &[usize], start: usize) -> Result<()> {
    for &site in calls {
        if !matches!(blob.get(site..site+5), Some([0xe8 | 0xe9, 0, 0, 0, 0])) {
            bail!("helper branch at {site:#x} lost its rel32 slot");
        }
        patch_x86_rel32(blob,site+1,start)?;
    }
    Ok(())
}

pub(super) fn compact(routine: (Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>))
    -> Result<(Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>)> {
    let (bytes, mut relocs, mut sites) = routine;
    let mut decoder = Decoder::new(64, &bytes, DecoderOptions::NONE);
    let instructions: Vec<_> = decoder.iter().collect();
    let indices: HashMap<_,_> = instructions.iter().enumerate()
        .map(|(i,insn)| (insn.ip() as u32,i)).collect();
    let encoded = BlockEncoder::encode(64, InstructionBlock::new(&instructions,0),
        BlockEncoderOptions::RETURN_NEW_INSTRUCTION_OFFSETS)?;
    for reloc in &mut relocs {reloc.offset=encoded.new_instruction_offsets[indices[&reloc.offset]];}
    for site in &mut sites {site.offset=encoded.new_instruction_offsets[indices[&site.offset]];}
    Ok((encoded.code_buffer,relocs,sites))
}

fn append(blob: &mut Vec<u8>, relocs: &mut Vec<RelocRecord>, ranges: &mut Vec<(usize,usize)>,
          loads: &mut Vec<LoadSite>, routine: (Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>)) -> Result<usize> {
    let (bytes, mut nested, mut sites) = routine;
    let start = blob.len();
    for reloc in &mut nested { reloc.offset = u32::try_from(start+reloc.offset as usize)?; }
    for site in &mut sites { site.offset = u32::try_from(start+site.offset as usize)?; }
    blob.extend_from_slice(&bytes);
    relocs.extend(nested); loads.extend(sites); ranges.push((start,blob.len()));
    Ok(start)
}

pub(super) fn constant_size(name: &str, facts: Option<&HashMap<Register,u64>>) -> Option<u32> {
    if matches!(name,"bpf_probe_read_kernel"|"bpf_probe_read_user"|"bpf_probe_read_compat"|"bpf_probe_read") {
        facts?.get(&Register::RSI).map(|size| *size as u32)
    } else {None}
}

fn common_size(calls: &[usize], counts: &HashMap<usize,u32>) -> Option<u32> {
    let first=*counts.get(calls.first()?)?;
    calls.iter().all(|site| counts.get(site)==Some(&first)).then_some(first)
}

pub(super) fn share(blob: &mut Vec<u8>, relocs: &mut Vec<RelocRecord>,
                    layout: &RuntimeProbeReadLayout, helpers: &HashMap<String,u64>, counts: &HashMap<usize,u32>)
    -> Result<(Vec<(usize,usize)>,Vec<LoadSite>)> {
    let mut ranges = Vec::new();
    let mut loads = Vec::new();
    let sizes=[false,true].map(|user| {
        let mut calls=Vec::new();
        for name in [if user {"bpf_probe_read_user"} else {"bpf_probe_read_kernel"},"bpf_probe_read_compat"] {
            if let Some(&helper)=helpers.get(name) {calls.extend(calls_to(relocs,helper));}
        }
        common_size(&calls,counts)
    });
    let mut leaves = [[None,None],[None,None]]; // [string][user] shared routine starts
    for (name,user,string) in [("bpf_probe_read_user",true,false),("bpf_probe_read_kernel",false,false),
            ("bpf_probe_read_kernel_str",false,true),("bpf_probe_read_user_str",true,true)] {
        let Some(&helper) = helpers.get(name) else { continue; };
        let calls = calls_to(relocs, helper);
        if calls.is_empty() { continue; }
        let anchor=if string {let Some(&regular)=helpers.get(if user {"bpf_probe_read_user"} else {"bpf_probe_read_kernel"}) else {continue;};regular} else {helper};
        let built = if user {user_leaf(layout,anchor,string,if string {None} else {sizes[1]})?} else {kernel_routine(layout,anchor,string,if string {None} else {sizes[0]})?};
        relocs.retain(|r| !(r.kind == 1 && r.target == helper));
        let start = append(blob, relocs, &mut ranges, &mut loads, built)?;
        redirect(blob, &calls, start)?;
        leaves[usize::from(string)][usize::from(user)] = Some(start);
    }
    for (name,string) in [("bpf_probe_read_compat",false),("bpf_probe_read_compat_str",true)] {
        let (Some(&compat), Some(&user_anchor), Some(&kernel_anchor)) = (helpers.get(name),
            helpers.get("bpf_probe_read_user"), helpers.get("bpf_probe_read_kernel")) else {continue;};
        let calls = calls_to(relocs, compat);
        if calls.is_empty() {continue;}
        let mut targets=[0usize;2];
        for user in [false, true] {
            let slot=&mut leaves[usize::from(string)][usize::from(user)];
            let start=if let Some(start)=*slot {start} else {
                let built=if user {user_leaf(layout,user_anchor,string,if string {None} else {sizes[1]})?} else {kernel_routine(layout,kernel_anchor,string,if string {None} else {sizes[0]})?};
                let start=append(blob,relocs,&mut ranges,&mut loads,built)?;
                *slot=Some(start);start
            };
            targets[usize::from(user)]=start;
        }
        let [kernel,user]=targets;
        relocs.retain(|r| !(r.kind == 1 && r.target == compat));
        let start = blob.len();
        let bytes = compat_dispatch(layout, kernel_anchor, start, user, kernel)?;
        blob.extend_from_slice(&bytes); ranges.push((start, blob.len()));
        redirect(blob, &calls, start)?;
    }
    Ok((ranges,loads))
}

pub(super) fn direct_load(layout: Option<&RuntimeProbeReadLayout>, helpers: &HashMap<String,u64>, name: &str)
    -> Result<Option<Vec<Instruction>>> {
    let task=matches!(name,"bpf_get_current_task"|"bpf_get_current_task_btf");
    let ticks=name=="bpf_jiffies64";
    let target=if task || ticks {
        let Some(layout)=layout else {return Ok(None);};
        let symbol=if ticks {let Some(symbol)=layout.jiffies else {return Ok(None);};symbol} else {layout.current_task};
        [("bpf_probe_read_kernel",layout.kernel_helper),("bpf_probe_read_user",layout.user_helper)]
            .into_iter().find_map(|(name,anchor)|helpers.get(name).map(|actual|address(symbol,anchor,*actual)))
            .transpose()?
    } else if name=="bpf_get_smp_processor_id" {helpers.get(X86_CPU_NUMBER_HELPER_KEY).copied()}
    else {None};
    let Some(target)=target else {return Ok(None);};
    let fits=target as u32 as i32 as i64 as u64==target;
    let mut bytes=Vec::new();
    if ticks && !fits {absolute(&mut bytes,&[0x48,0xa1],target);} else {
        if !fits {return Ok(None);}
        if !ticks {bytes.push(0x65);}
        if task || ticks {bytes.push(0x48);}
        bytes.extend_from_slice(&[0x8b,0x04,0x25]);bytes.extend_from_slice(&(target as u32).to_le_bytes());
    }
    Ok(Some(declared_byte_chunks(&bytes)?))
}

#[cfg(all(test,target_arch="x86_64",target_os="linux"))]
mod tests {
    use super::*;
    #[test]
    fn local_branch_sizing_preserves_helper_slots_load_sites_and_global_append() -> Result<()> {
        // Both sides of the short-branch boundary, forward/backward edges,
        // and a relocated kernel-call slot before a recovered source load.
        let mut cases=0;
        for padding in [0,1,115,116,117,118,120,124,127,128,129,200] {
            let mut bytes=vec![0x48,0x89,0xf8,0x48,0x85,0xff]; // rax=rdi; test rdi
            let null=append_x86_jcc_rel32(&mut bytes,0x84);
            let forward=jump(&mut bytes);bytes.resize(bytes.len()+padding,0x90);
            let worker=bytes.len();patch_x86_rel32(&mut bytes,forward,worker)?;
            let call=bytes.len();bytes.extend_from_slice(&X86_HELPER_CALL_REL32_SLOT);
            let load=bytes.len();bytes.extend_from_slice(&[0x48,0x8b,0x07,0xff,0xce]); // load; dec esi
            let again=append_x86_jcc_rel32(&mut bytes,0x85);patch_x86_rel32(&mut bytes,again,worker)?;
            let end=bytes.len();patch_x86_rel32(&mut bytes,null,end)?;bytes.push(0xc3);
            let routine=(bytes.clone(),vec![RelocRecord{offset:call as u32,kind:1,target:0x1234}],
                vec![LoadSite{offset:load as u32,insn_len:3,destination:11}]);
            let (sized,relocs,sites)=compact(routine)?;
            assert!(sized.len()<bytes.len());
            assert_eq!(&sized[relocs[0].offset as usize..relocs[0].offset as usize+5],
                X86_HELPER_CALL_REL32_SLOT.as_slice());
            assert_eq!((relocs[0].kind,relocs[0].target),(1,0x1234));
            assert_eq!((sites[0].insn_len,sites[0].destination),(3,11));
            assert_eq!(&sized[sites[0].offset as usize..sites[0].offset as usize+3],&bytes[load..load+3]);
            let mut a=Decoder::new(64,&bytes,DecoderOptions::NONE);
            let mut b=Decoder::new(64,&sized,DecoderOptions::NONE);
            let old:Vec<_>=a.iter().collect();let new:Vec<_>=b.iter().collect();
            assert_eq!(old.len(),new.len());
            let mapped:HashMap<_,_>=old.iter().zip(&new).map(|(a,b)|(a.ip(),b.ip())).collect();
            for (a,b) in old.iter().zip(&new) {
                assert_eq!((a.mnemonic(),a.condition_code()),(b.mnemonic(),b.condition_code()));
                if matches!(a.flow_control(),FlowControl::ConditionalBranch|FlowControl::UnconditionalBranch|FlowControl::Call) {
                    assert_eq!(b.near_branch64(),mapped[&a.near_branch64()]);
                }
            }
            let (twice,twice_relocs,twice_sites)=compact((sized.clone(),relocs.clone(),sites.clone()))?;
            assert_eq!(twice,sized);assert_eq!(twice_relocs[0].offset,relocs[0].offset);
            assert_eq!(twice_sites[0].offset,sites[0].offset);
            for prefix in [0,11] {
                let mut blob=vec![0x90;prefix];let mut global_relocs=Vec::new();
                let mut ranges=Vec::new();let mut global_sites=Vec::new();
                let start=append(&mut blob,&mut global_relocs,&mut ranges,&mut global_sites,
                    (sized.clone(),relocs.clone(),sites.clone()))?;
                assert_eq!(start,prefix);assert_eq!(ranges,vec![(prefix,prefix+sized.len())]);
                assert_eq!(global_sites[0].offset as usize,prefix+sites[0].offset as usize);
                let helper=blob.len();blob.extend_from_slice(&[0xfe,0x02,0xc3]); // inc byte [rdx]; ret
                patch_x86_rel32(&mut blob,global_relocs[0].offset as usize+1,helper)?;
                let source=0x123456789abcdef0u64;let mut hits=0u8;
                assert!(memory::call_blob(&blob,std::ptr::null_mut(),3,&mut hits as *mut _ as usize).is_null());
                assert_eq!(hits,0);
                for count in [1usize,3] {
                    hits=0;
                    let result=memory::call_blob(&blob,&source as *const _ as *mut u8,count,&mut hits as *mut _ as usize);
                    assert_eq!(result as u64,source);assert_eq!(hits as usize,count);
                }
                cases+=1;
            }
        }
        println!("Probe branch layout:24 mixed-edge/relocation/recovery/append cases PASS");
        Ok(())
    }

    // A helper tail jump must stay a jump: adding a CALL adds a return frame.
    #[test]
    fn shared_leaf_redirect_preserves_call_and_tail_opcodes() -> Result<()> {
        let mut blob=vec![0xe8,0,0,0,0,0xc3,0xe9,0,0,0,0,0xb8,77,0,0,0,0xc3];
        redirect(&mut blob,&[0,6],11)?;
        for (site,opcode) in [(0usize,0xe8),(6,0xe9)] {
            assert_eq!(blob[site],opcode);
            let rel=i32::from_le_bytes(blob[site+1..site+5].try_into()?);
            assert_eq!(site as i64+5+i64::from(rel),11);
        }
        assert_eq!(memory::call_blob(&blob,std::ptr::null_mut(),0,0) as usize,77);
        assert_eq!(memory::call_blob(&blob[6..],std::ptr::null_mut(),0,0) as usize,77);
        Ok(())
    }

    // Catch accidental 0x67 zero-extension and signed-disp32 boundary errors.
    #[test]
    fn compact_global_operands_preserve_full_effective_addresses() {
        for address in [0u64, 0x7fffffff, 0xffffffff80000000, u64::MAX,
                        0x80000000, 0xffffffff7fffffff, 0x1111222233334444] {
            let compact_address=address as u32 as i32 as i64 as u64==address;
            for (compact,wide,test) in [
                (&[0x48,0x8b,0x04,0x25][..],&[0x49,0x8b,0x03][..],false),
                (&[0x0f,0xb6,0x0c,0x25][..],&[0x41,0x0f,0xb6,0x0b][..],false),
                (&[0xf7,0x04,0x25][..],&[0x41,0xf7,0x03][..],true)] {
                let mut bytes=Vec::new();live_global(&mut bytes,compact,wide,address);
                if test {bytes.extend_from_slice(&(1u32<<20).to_le_bytes());}
                let mut decoder=Decoder::new(64,&bytes,DecoderOptions::NONE);
                if !compact_address {
                    let load=decoder.decode();
                    assert_eq!(load.op0_register(),Register::R11);
                    assert_eq!(load.immediate64(),address);
                }
                let operand=decoder.decode();assert!(!operand.is_invalid());
                assert_eq!(operand.memory_index(),Register::None);
                if compact_address {
                    assert_eq!(operand.memory_base(),Register::None);
                    assert_eq!(operand.memory_displacement64(),address);
                    assert_eq!(bytes.len(),compact.len()+4+if test {4} else {0});
                } else {
                    assert_eq!(operand.memory_base(),Register::R11);
                    assert_eq!(operand.memory_displacement64(),0);
                }
                assert!(!decoder.can_decode());
            }
        }
    }

    #[test]
    fn fixed_scalar_counts_join_all_callers_and_bound_copy_code() -> Result<()> {
        let registers=HashMap::from([(Register::RSI,0x100000008),(Register::RDX,16)]);
        assert_eq!(constant_size("bpf_probe_read_kernel",Some(&registers)),Some(8));
        assert_eq!(constant_size("bpf_probe_read_user_str",Some(&registers)),None);
        assert_eq!(constant_size("bpf_probe_read_user",None),None);
        let counts=HashMap::from([(0usize,8u32),(5,8),(10,16)]);
        assert_eq!(common_size(&[0,5],&counts),Some(8));
        assert_eq!(common_size(&[0,10],&counts),None);
        assert_eq!(common_size(&[0,15],&counts),None);
        let mut generic=Vec::new();copy_words(&mut generic,&mut Vec::new(),&mut Vec::new(),None)?;
        for size in [0u32,1,2,3,4,7,8,9,15,16,17,144,1024,u32::MAX] {
            let mut bytes=Vec::new();let mut sites=Vec::new();
            copy_words(&mut bytes,&mut sites,&mut Vec::new(),Some(size))?;
            assert!(bytes.len()<generic.len(),"counted body must not unroll a large size");
            assert_eq!(sites.len(),usize::from(size>=8)+(size&7).count_ones() as usize);
        }
        let layout=fixture();
        let helpers=HashMap::from([("bpf_probe_read_user".into(),layout.user_helper),
            ("bpf_probe_read_kernel".into(),layout.kernel_helper),("bpf_probe_read_compat".into(),0x3000)]);
        for (user_size,compat_size,expected) in [(Some(8),Some(8),2),(Some(16),Some(8),5),(Some(8),None,8)] {
            let mut blob=X86_HELPER_CALL_REL32_SLOT.repeat(3);blob[5]=0xe9;blob.push(0xc3);
            let mut relocs=vec![RelocRecord{offset:0,kind:1,target:layout.kernel_helper},
                RelocRecord{offset:5,kind:1,target:0x3000},RelocRecord{offset:10,kind:1,target:layout.user_helper}];
            let mut facts=HashMap::from([(0usize,8u32)]);
            if let Some(size)=user_size {facts.insert(10,size);}
            if let Some(size)=compat_size {facts.insert(5,size);}
            let (ranges,sites)=share(&mut blob,&mut relocs,&layout,&helpers,&facts)?;
            assert_eq!(ranges.len(),3,"reuse one user and one kernel body plus compat dispatcher");
            assert_eq!(sites.len(),expected,"meet direct and compat counts for each domain");
        }
        Ok(())
    }

    fn fixture() -> RuntimeProbeReadLayout {
        RuntimeProbeReadLayout { user_helper:0x1000,kernel_helper:0x2000,
            current_task:0,jiffies:Some(0x1111222233334444),
            user_ptr_max:0x1111222233334444,boot_cpu_data:0x5555666677778888,
            pagefault_disabled:4,x86_capability:0,task_flags:0,task_personality:16,ktime:None,cred:None,
            cpu_tlbstate:8,tlb_loaded_mm:0,task_mm:8,x86_virt_bits:40 }
    }

    #[test]
    fn emitted_probe_reads_execute_success_fault_partial_zero_policy_and_nesting() -> Result<()> {
        let output = std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT").map(PathBuf::from)
            .unwrap_or_else(|| std::env::temp_dir().join(format!("probe-read-{}",std::process::id())));
        fs::create_dir_all(&output)?;
        let source = PathBuf::from(env!("CARGO_MANIFEST_DIR"))
            .join("fixtures/probe_read_driver.c");
        let driver = output.join("check");
        let compile = std::process::Command::new("cc")
            .args(["-O2","-Wall","-Wextra","-Werror","-no-pie"])
            .arg(source).arg("-o").arg(&driver).output()?;
        fs::write(output.join("compile.stdout"),&compile.stdout)?;
        fs::write(output.join("compile.stderr"),&compile.stderr)?;
        if !compile.status.success() { bail!("probe-read host fixture compile: {}",String::from_utf8_lossy(&compile.stderr)); }
        let layout = fixture();
        for pass in 0..8 {
            let mode=pass%4;
            let compact=pass>=4;
            let mut layout=fixture();
            if compact {layout.user_ptr_max=0x12340000;layout.boot_cpu_data=0x12350000;}
            let user=mode==1 || mode==3;let string=mode>=2;
            let anchor = if user { layout.user_helper } else { layout.kernel_helper };
            let (bytes,relocs,sites) = if user {user_leaf(&layout,anchor,string,None)?} else {kernel_routine(&layout,anchor,string,None)?};
            let stem = if mode==3 {"user-string"} else if string {"kernel-string"} else if user { "user" } else { "kernel" };
            let stem=format!("{stem}{}",if compact {"-compact"} else {""});
            let binary = output.join(format!("{stem}.bin"));
            let metadata = output.join(format!("{stem}.sites"));
            fs::write(&binary,&bytes)?;
            assert_eq!(sites.len(),if mode==3 {2} else if string {1} else {4}); assert!(relocs.is_empty());
            let mut text = sites.len().to_string();text.push(char::from(10));
            for site in sites { text.push_str(&format!("{} {} {}\n",site.offset,site.insn_len,site.destination)); }
            fs::write(&metadata,text)?;
            let run = std::process::Command::new(&driver).arg(binary).arg(metadata)
                .arg((if mode==3 {7} else {mode}).to_string()).output()?;
            fs::write(output.join(format!("{stem}.stdout")),&run.stdout)?;
            fs::write(output.join(format!("{stem}.stderr")),&run.stderr)?;
            assert!(run.status.success(),"{stem} host execution: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
            println!("{}",String::from_utf8_lossy(&run.stdout));
        }
        // Both compat helpers select the corresponding user/kernel leaves, sharing each one once.
        for (stem,name,target,mode,load_count) in [("compat","bpf_probe_read_compat",0x3000,5,8),
                ("compat-string","bpf_probe_read_compat_str",0x7000,8,3)] {
        let mut blob = X86_HELPER_CALL_REL32_SLOT.to_vec(); blob.push(0xc3);
        let mut relocs = vec![RelocRecord{offset:0,kind:1,target}];
        let helpers = HashMap::from([(name.into(),target),
            ("bpf_probe_read_user".into(),layout.user_helper),("bpf_probe_read_kernel".into(),layout.kernel_helper)]);
        let (ranges,sites) = share(&mut blob,&mut relocs,&layout,&helpers,&HashMap::new())?;
        assert!(relocs.is_empty()); assert_eq!(ranges.len(),3); assert_eq!(sites.len(),load_count);
        let mut text = sites.len().to_string(); text.push(char::from(10));
        for site in sites { text.push_str(&format!("{} {} {}\n",site.offset,site.insn_len,site.destination)); }
        fs::write(output.join(format!("{stem}.bin")),&blob)?; fs::write(output.join(format!("{stem}.sites")),text)?;
        let run = std::process::Command::new(&driver).arg(output.join(format!("{stem}.bin"))).arg(output.join(format!("{stem}.sites")))
            .arg(mode.to_string()).output()?;
        fs::write(output.join(format!("{stem}.stdout")),&run.stdout)?; fs::write(output.join(format!("{stem}.stderr")),&run.stderr)?;
        assert!(run.status.success(),"{stem} host execution: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
        println!("{}",String::from_utf8_lossy(&run.stdout));
        }
        for compact in [false,true] {
            let mut fixed_layout=fixture();
            if compact {fixed_layout.user_ptr_max=0x12340000;fixed_layout.boot_cpu_data=0x12350000;}
            for user in [false,true] {
                let anchor=if user {fixed_layout.user_helper} else {fixed_layout.kernel_helper};
                for size in [0u32,1,2,3,4,7,8,9,15,16,17,31,32,33,63,64,65,144,257,512,768,1024] {
                    let (bytes,relocs,sites)=if user {user_leaf(&fixed_layout,anchor,false,Some(size))?}
                        else {kernel_routine(&fixed_layout,anchor,false,Some(size))?};
                    assert!(relocs.is_empty());
                    let stem=format!("{}-fixed-{size}{}",if user {"user"} else {"kernel"},if compact {"-compact"} else {""});
                    let binary=output.join(format!("{stem}.bin"));fs::write(&binary,&bytes)?;
                    let metadata=output.join(format!("{stem}.sites"));
                    let mut text=format!("{}\n",sites.len());
                    for site in sites {text.push_str(&format!("{} {} {}\n",site.offset,site.insn_len,site.destination));}
                    fs::write(&metadata,text)?;
                    let run=std::process::Command::new(&driver).arg(binary).arg(metadata)
                        .arg(if user {"11"} else {"10"}).arg(size.to_string()).output()?;
                    fs::write(output.join(format!("{stem}.stdout")),&run.stdout)?;
                    fs::write(output.join(format!("{stem}.stderr")),&run.stderr)?;
                    assert!(run.status.success(),"{stem}: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
                    println!("{}",String::from_utf8_lossy(&run.stdout));
                }
            }
        }
        let helpers=HashMap::from([("bpf_probe_read_kernel".into(),layout.kernel_helper),
            (X86_CPU_NUMBER_HELPER_KEY.into(),8)]);
        for (mode,name,inline) in [(3,"current-task",direct_load(Some(&layout),&helpers,"bpf_get_current_task")?.unwrap()),
            (3,"current-task-btf",direct_load(Some(&layout),&helpers,"bpf_get_current_task_btf")?.unwrap()),
            (4,"cpu",direct_load(Some(&layout),&helpers,"bpf_get_smp_processor_id")?.unwrap()),
            (6,"jiffies",direct_load(Some(&layout),&helpers,"bpf_jiffies64")?.unwrap())] {
            let mut bytes=BlockEncoder::encode(64,InstructionBlock::new(&inline,0),BlockEncoderOptions::NONE)?.code_buffer;
            bytes.push(0xc3);let path=output.join(format!("{name}.bin"));fs::write(&path,bytes)?;
            let run=std::process::Command::new(&driver).arg(path).arg("unused").arg(mode.to_string()).output()?;
            fs::write(output.join(format!("{name}.stdout")),&run.stdout)?;
            assert!(run.status.success(),"{name}: {}",String::from_utf8_lossy(&run.stderr));
        }
        let mut layout=fixture();
        layout.jiffies=Some(0xffff_ffff_8123_4560);
        let inline=direct_load(Some(&layout),&helpers,"bpf_jiffies64")?.unwrap();
        let bytes=BlockEncoder::encode(64,InstructionBlock::new(&inline,0),BlockEncoderOptions::NONE)?.code_buffer;
        assert_eq!(bytes,[0x48,0x8b,0x04,0x25,0x60,0x45,0x23,0x81],"one live qword load, no GS prefix or address-size override");
        layout.jiffies=None;
        assert!(direct_load(Some(&layout),&helpers,"bpf_jiffies64")?.is_none(),"older load facts keep the kernel helper");
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
        let (ranges,sites) = share(&mut blob,&mut relocs,&layout,&helpers,&HashMap::new())?;
        assert_eq!(ranges.len(),2); assert_eq!(sites.len(),8);
        for (offset,range) in [(0,ranges[0]),(5,ranges[0]),(10,ranges[1])] {
            let disp = i32::from_le_bytes(blob[offset+1..offset+5].try_into()?);
            assert_eq!(offset as i64+5+i64::from(disp),range.0 as i64);
        }
        assert!(relocs.iter().any(|r| r.offset==15 && r.target==0x9999));
        assert_eq!(relocs.len(),1,"both shared routines read their policy inline; the other helper call stays");
        let mut strings=X86_HELPER_CALL_REL32_SLOT.repeat(4);
        let mut calls=vec![RelocRecord{offset:0,kind:1,target:0x5000},RelocRecord{offset:5,kind:1,target:0x6000},
            RelocRecord{offset:10,kind:1,target:0x7000},RelocRecord{offset:15,kind:1,target:0x7000}];
        let names=HashMap::from([("bpf_probe_read_kernel".into(),0x2000),("bpf_probe_read_user".into(),0x1000),
            ("bpf_probe_read_kernel_str".into(),0x5000),("bpf_probe_read_user_str".into(),0x6000),
            ("bpf_probe_read_compat_str".into(),0x7000)]);
        let (on,loads)=share(&mut strings,&mut calls,&layout,&names,&HashMap::new())?;
        assert_eq!(on.len(),3);assert_eq!(loads.len(),3);assert!(loads.iter().all(|s|s.destination==11));
        assert!(calls.is_empty(),"compat calls reuse the existing user/kernel string leaves");
        for (site,target) in [(0,on[0].0),(5,on[1].0),(10,on[2].0),(15,on[2].0)] {
            let displacement=i32::from_le_bytes(strings[site+1..site+5].try_into()?);
            assert_eq!(site as i64+5+i64::from(displacement),target as i64);
        }
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
