//! Helper LTO: preserve access policy, fault nesting, errors and full
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

fn gs_disp32(address: u64, what: &str) -> Result<[u8; 4]> {
    if address as u32 as i32 as i64 as u64 != address {
        bail!("probe-read {what} GS address is not sign-extended disp32");
    }
    Ok((address as u32).to_le_bytes())
}

pub(super) fn routine(layout: &RuntimeProbeReadLayout, user: bool, actual: u64)
    -> Result<(Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>)> {
    if user { user_leaf(layout, actual) } else { kernel_routine(layout, actual, false) }
}

/// RDI=dst, RSI=src, ECX=size, R11=1. Eight-byte words, then an empty remainder goes straight
/// to success; otherwise one 4-, one 2- and one 1-byte step, as mm/maccess.c copies. Every load
/// is a recovered site whose fault clears R11; success leaves EAX=0.
fn copy_words(b: &mut Vec<u8>, sites: &mut Vec<LoadSite>, faults: &mut Vec<usize>) -> Result<()> {
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

/// copy_from_user_nofault as a leaf: __access_ok, nmi_uaccess_okay, pagefault_disable, STAC
/// with SMAP, copy, CLAC, pagefault_enable; denial and faults zero the destination. It uses
/// caller-saved registers only: R8=dst, R9D=size, RDX=src and then the SMAP flag, R10=current.
fn user_leaf(layout: &RuntimeProbeReadLayout, actual: u64)
    -> Result<(Vec<u8>, Vec<RelocRecord>, Vec<LoadSite>)> {
    let target = |symbol| address(symbol, layout.user_helper, actual);
    let current = gs_disp32(target(layout.current_task)?, "current_task")?;
    let loaded_mm = gs_disp32(target(layout.cpu_tlbstate)?.wrapping_add(u64::from(layout.tlb_loaded_mm)),
        "cpu_tlbstate.loaded_mm")?;
    let task_offset = i32::try_from(layout.pagefault_disabled)?.to_le_bytes();
    let mm_offset = i32::try_from(layout.task_mm)?.to_le_bytes();
    let mut b = vec![0x49,0x89,0xf8,0x41,0x89,0xf1]; // r8=dst, r9d=size; RDX keeps src
    let mut denied = Vec::new();
    // __access_ok(src,size): src+size <= USER_PTR_MAX without wrap. USER_PTR_MAX is TASK_SIZE_MAX
    // (at least 2^47 - PAGE_SIZE) and exceeds every u32 size, so this is src <= USER_PTR_MAX-size.
    absolute(&mut b, &[0x49,0xbb], target(layout.user_ptr_max)?);
    b.extend_from_slice(&[0x49,0x8b,0x03,0x4c,0x29,0xc8,0x48,0x39,0xc2]); // rax=[r11]-r9; cmp rdx,rax
    denied.push(append_x86_jcc_rel32(&mut b, 0x87)); // above
    // nmi_uaccess_okay: this CPU's cpu_tlbstate.loaded_mm equals current->mm.
    b.extend_from_slice(&[0x65,0x4c,0x8b,0x14,0x25]); b.extend_from_slice(&current); // r10=gs:current_task
    b.extend_from_slice(&[0x65,0x48,0x8b,0x04,0x25]); b.extend_from_slice(&loaded_mm); // rax=gs:loaded_mm
    b.extend_from_slice(&[0x49,0x3b,0x82]); b.extend_from_slice(&mm_offset); // cmp rax,[r10+mm]
    denied.push(append_x86_jcc_rel32(&mut b, 0x85));
    b.extend_from_slice(&[0x41,0xff,0x82]); b.extend_from_slice(&task_offset); // pagefault_disable
    b.extend_from_slice(&[0x48,0x89,0xd6]); // rsi=src
    absolute(&mut b, &[0x49,0xbb], target(layout.boot_cpu_data)?);
    b.extend_from_slice(&[0x41,0xf7,0x83]); // test boot_cpu_data.x86_capability[9],SMAP
    b.extend_from_slice(&i32::try_from(layout.x86_capability+9*4)?.to_le_bytes());
    b.extend_from_slice(&(1u32<<20).to_le_bytes()); // sole x86 cpufeatures.h X86_FEATURE_SMAP
    b.extend_from_slice(&[0x0f,0x95,0xc2]); // setne dl; retains the feature across the copy
    let no_smap = append_x86_jcc_rel32(&mut b, 0x84);
    b.extend_from_slice(&[0x0f,0x01,0xcb]); // STAC only with actual CPU SMAP capability
    let after = b.len(); patch_x86_rel32(&mut b, no_smap, after)?;
    b.extend_from_slice(&[0x4c,0x89,0xc7,0x44,0x89,0xc9,0x41,0xbb,1,0,0,0]); // rdi=dst, ecx=size, r11d=1
    let mut sites = Vec::new(); let mut faults = Vec::new();
    copy_words(&mut b, &mut sites, &mut faults)?;
    let cleanup_success = jump(&mut b);
    let fault = b.len();
    for branch in faults { patch_x86_rel32(&mut b, branch, fault)?; }
    b.extend_from_slice(&[0x48,0xc7,0xc0,0xf2,0xff,0xff,0xff]); // -EFAULT, sign extended
    let cleanup = b.len(); patch_x86_rel32(&mut b, cleanup_success, cleanup)?;
    b.extend_from_slice(&[0x84,0xd2]); // saved SMAP feature
    let skip = append_x86_jcc_rel32(&mut b, 0x84);
    b.extend_from_slice(&[0x0f,0x01,0xca]); // CLAC, both success and fault
    let after = b.len(); patch_x86_rel32(&mut b, skip, after)?;
    b.extend_from_slice(&[0x41,0xff,0x8a]); b.extend_from_slice(&task_offset); // pagefault_enable
    b.extend_from_slice(&[0x48,0x85,0xc0]);
    let clean_return = append_x86_jcc_rel32(&mut b, 0x84);
    let zero_fault = jump(&mut b);
    let deny = b.len();
    for branch in denied { patch_x86_rel32(&mut b, branch, deny)?; }
    b.extend_from_slice(&[0x48,0xc7,0xc0,0xf2,0xff,0xff,0xff]); // -EFAULT
    let zero = b.len(); patch_x86_rel32(&mut b, zero_fault, zero)?;
    let zero_done = zero_fill(&mut b, &[0x4c,0x89,0xc7,0x44,0x89,0xc9])?; // rdi=r8, ecx=r9d
    let end = b.len();
    patch_x86_rel32(&mut b, clean_return, end)?; patch_x86_rel32(&mut b, zero_done, end)?;
    b.push(0xc3);
    Ok((b, Vec::new(), sites))
}

/// copy_from_kernel_nofault and strncpy_from_kernel_nofault as leaves: copy_from_kernel_nofault_allowed
/// inline (an address below TASK_SIZE_MAX + PAGE_SIZE, in the vsyscall page, or non-canonical at
/// boot_cpu_data.x86_virt_bits gets -ERANGE; width zero allows), pagefault_disable, copy,
/// pagefault_enable; denial and faults zero the destination. It uses caller-saved registers only:
/// R8=dst, R9D=size, RDX=src, R10=current.
fn kernel_routine(layout: &RuntimeProbeReadLayout, actual: u64, string: bool)
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
    absolute(&mut b, &[0x49,0xbb], target(layout.user_ptr_max)?);
    b.extend_from_slice(&[0x49,0x8b,0x03,0x48,0x05,0,0x10,0,0,0x48,0x39,0xc2]); // rax=[r11]+4096; cmp rdx,rax
    denied.push(append_x86_jcc_rel32(&mut b, 0x82)); // below
    // is_vsyscall_vaddr: (vaddr & PAGE_MASK) == VSYSCALL_ADDR, -10UL << 20
    b.extend_from_slice(&[0x48,0x89,0xd0,0x48,0x25,0,0xf0,0xff,0xff,0x48,0x3d,0,0,0x60,0xff]);
    denied.push(append_x86_jcc_rel32(&mut b, 0x84));
    // Canonical at boot_cpu_data.x86_virt_bits. Shift counts are taken mod 64, so width zero shifts by zero and
    // the address compares equal: early boot (width zero) allows, as the C source does.
    absolute(&mut b, &[0x49,0xbb], target(layout.boot_cpu_data)?);
    b.extend_from_slice(&[0x41,0x0f,0xb6,0x8b]); // movzx ecx,byte[r11+x86_virt_bits]
    b.extend_from_slice(&i32::try_from(layout.x86_virt_bits)?.to_le_bytes());
    b.extend_from_slice(&[0xf7,0xd9,0x48,0x89,0xd0,0x48,0xd3,0xe0,0x48,0xd3,0xf8,0x48,0x39,0xd0]); // shl/sar by 64-bits; cmp rax,rdx
    denied.push(append_x86_jcc_rel32(&mut b, 0x85));
    b.extend_from_slice(&[0x65,0x4c,0x8b,0x14,0x25]); b.extend_from_slice(&current); // r10=gs:current_task
    b.extend_from_slice(&[0x41,0xff,0x82]); b.extend_from_slice(&task_offset); // pagefault_disable
    b.extend_from_slice(&[0x48,0x89,0xd6,0x4c,0x89,0xc7,0x44,0x89,0xc9,0x41,0xbb,1,0,0,0]); // rsi=src, rdi=dst, ecx=size, r11d=1
    let mut sites=Vec::new(); let mut faults=Vec::new();
    if string {
        let loop_start=b.len();
        sites.push(LoadSite{offset:b.len() as u32,insn_len:3,destination:11});
        b.extend_from_slice(&[0x0f,0xb6,0x06,0x45,0x85,0xdb]);
        faults.push(append_x86_jcc_rel32(&mut b,0x84));
        b.extend_from_slice(&[0x88,0x07,0x48,0xff,0xc7,0x48,0xff,0xc6,0xff,0xc9,0x84,0xc0]);
        let nul=append_x86_jcc_rel32(&mut b,0x84);
        b.extend_from_slice(&[0x85,0xc9]);
        let again=append_x86_jcc_rel32(&mut b,0x85);patch_x86_rel32(&mut b,again,loop_start)?;
        let end=b.len();patch_x86_rel32(&mut b,nul,end)?;
        b.extend_from_slice(&[0xc6,0x47,0xff,0,0x48,0x89,0xf8,0x4c,0x29,0xc0,0x48,0x63,0xc0]); // dst[-1]=0; length as signed int
    } else {
        copy_words(&mut b, &mut sites, &mut faults)?;
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
    Ok((b, Vec::new(), sites))
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
    absolute(&mut b, &[0x49,0xbb], target(layout.user_ptr_max)?);
    b.extend_from_slice(&[0x49,0x8b,0x03]); // rax=TASK_SIZE_MAX
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

fn redirect(blob: &mut Vec<u8>, calls: &[usize], start: usize) -> Result<()> {
    for &site in calls {
        if blob.get(site..site+5) != Some(X86_HELPER_CALL_REL32_SLOT.as_slice()) {
            bail!("probe-read call at {site:#x} lost its E8 helper slot");
        }
        patch_x86_rel32(blob,site+1,start)?;
    }
    Ok(())
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

pub(super) fn share(blob: &mut Vec<u8>, relocs: &mut Vec<RelocRecord>,
                    layout: &RuntimeProbeReadLayout, helpers: &HashMap<String,u64>)
    -> Result<(Vec<(usize,usize)>,Vec<LoadSite>)> {
    let mut ranges = Vec::new();
    let mut loads = Vec::new();
    let mut scalar = [None, None]; // shared kernel and user routine starts
    for (name,user,string) in [("bpf_probe_read_user",true,false),("bpf_probe_read_kernel",false,false),("bpf_probe_read_kernel_str",false,true)] {
        let Some(&helper) = helpers.get(name) else { continue; };
        let calls = calls_to(relocs, helper);
        if calls.is_empty() { continue; }
        let anchor=if string {let Some(&regular)=helpers.get("bpf_probe_read_kernel") else {continue;};regular} else {helper};
        let built = if string {kernel_routine(layout,anchor,true)?} else {routine(layout,user,anchor)?};
        relocs.retain(|r| !(r.kind == 1 && r.target == helper));
        let start = append(blob, relocs, &mut ranges, &mut loads, built)?;
        redirect(blob, &calls, start)?;
        if !string { scalar[usize::from(user)] = Some(start); }
    }
    if let (Some(&compat), Some(&user_anchor), Some(&kernel_anchor)) = (helpers.get("bpf_probe_read_compat"),
            helpers.get("bpf_probe_read_user"), helpers.get("bpf_probe_read_kernel")) {
        let calls = calls_to(relocs, compat);
        if !calls.is_empty() {
            for user in [false, true] {
                if scalar[usize::from(user)].is_none() {
                    let built = routine(layout, user, if user {user_anchor} else {kernel_anchor})?;
                    scalar[usize::from(user)] = Some(append(blob, relocs, &mut ranges, &mut loads, built)?);
                }
            }
            let (Some(kernel), Some(user)) = (scalar[0], scalar[1]) else { bail!("compat probe read needs both routines"); };
            relocs.retain(|r| !(r.kind == 1 && r.target == compat));
            let start = blob.len();
            let bytes = compat_dispatch(layout, kernel_anchor, start, user, kernel)?;
            blob.extend_from_slice(&bytes); ranges.push((start, blob.len()));
            redirect(blob, &calls, start)?;
        }
    }
    Ok((ranges,loads))
}

pub(super) fn percpu(layout: Option<&RuntimeProbeReadLayout>, helpers: &HashMap<String,u64>, name: &str)
    -> Result<Option<Vec<Instruction>>> {
    let wide=name=="bpf_get_current_task";
    let target=if wide {
        let Some(layout)=layout else {return Ok(None);};
        [("bpf_probe_read_kernel",layout.kernel_helper),("bpf_probe_read_user",layout.user_helper)]
            .into_iter().find_map(|(name,anchor)|helpers.get(name).map(|actual|address(layout.current_task,anchor,*actual)))
            .transpose()?
    } else if name=="bpf_get_smp_processor_id" {helpers.get(X86_CPU_NUMBER_HELPER_KEY).copied()}
    else {None};
    let Some(target)=target else {return Ok(None);};
    if target as u32 as i32 as i64 as u64!=target {return Ok(None);}
    let mut bytes=vec![0x65];if wide {bytes.push(0x48);}
    bytes.extend_from_slice(&[0x8b,0x04,0x25]);bytes.extend_from_slice(&(target as u32).to_le_bytes());
    Ok(Some(declared_byte_chunks(&bytes)?))
}

#[cfg(all(test,target_arch="x86_64",target_os="linux"))]
mod tests {
    use super::*;
    fn fixture() -> RuntimeProbeReadLayout {
        RuntimeProbeReadLayout { user_helper:0x1000,kernel_helper:0x2000,
            current_task:0,
            user_ptr_max:0x1111222233334444,boot_cpu_data:0x5555666677778888,
            pagefault_disabled:4,x86_capability:0,task_flags:0,task_personality:16,ktime:None,
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
        for mode in 0..3 {
            let user=mode==1;let string=mode==2;
            let anchor = if user { layout.user_helper } else { layout.kernel_helper };
            let (bytes,relocs,sites) = if string {kernel_routine(&layout,anchor,true)?} else {routine(&layout,user,anchor)?};
            let stem = if string {"kernel-string"} else if user { "user" } else { "kernel" };
            let binary = output.join(format!("{stem}.bin"));
            let metadata = output.join(format!("{stem}.sites"));
            fs::write(&binary,&bytes)?;
            assert_eq!(sites.len(),if string {1} else {4}); assert!(relocs.is_empty());
            let mut text = sites.len().to_string();text.push(char::from(10));
            for site in sites { text.push_str(&format!("{} {} {}\n",site.offset,site.insn_len,site.destination)); }
            fs::write(&metadata,text)?;
            let run = std::process::Command::new(&driver).arg(binary).arg(metadata)
                .arg(mode.to_string()).output()?;
            fs::write(output.join(format!("{stem}.stdout")),&run.stdout)?;
            fs::write(output.join(format!("{stem}.stderr")),&run.stderr)?;
            assert!(run.status.success(),"{stem} host execution: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
            println!("{}",String::from_utf8_lossy(&run.stdout));
        }
        // bpf_probe_read (compat): the call reaches a dispatcher that picks the user or the kernel leaf.
        let mut blob = X86_HELPER_CALL_REL32_SLOT.to_vec(); blob.push(0xc3);
        let mut relocs = vec![RelocRecord{offset:0,kind:1,target:0x3000}];
        let helpers = HashMap::from([("bpf_probe_read_compat".into(),0x3000),
            ("bpf_probe_read_user".into(),layout.user_helper),("bpf_probe_read_kernel".into(),layout.kernel_helper)]);
        let (ranges,sites) = share(&mut blob,&mut relocs,&layout,&helpers)?;
        assert!(relocs.is_empty()); assert_eq!(ranges.len(),3); assert_eq!(sites.len(),8);
        let mut text = sites.len().to_string(); text.push(char::from(10));
        for site in sites { text.push_str(&format!("{} {} {}\n",site.offset,site.insn_len,site.destination)); }
        fs::write(output.join("compat.bin"),&blob)?; fs::write(output.join("compat.sites"),text)?;
        let run = std::process::Command::new(&driver).arg(output.join("compat.bin")).arg(output.join("compat.sites"))
            .arg("5").output()?;
        fs::write(output.join("compat.stdout"),&run.stdout)?; fs::write(output.join("compat.stderr"),&run.stderr)?;
        assert!(run.status.success(),"compat host execution: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
        println!("{}",String::from_utf8_lossy(&run.stdout));
        let helpers=HashMap::from([("bpf_probe_read_kernel".into(),layout.kernel_helper),
            (X86_CPU_NUMBER_HELPER_KEY.into(),8)]);
        for (mode,name,inline) in [(3,"current-task",percpu(Some(&layout),&helpers,"bpf_get_current_task")?.unwrap()),
            (4,"cpu",percpu(Some(&layout),&helpers,"bpf_get_smp_processor_id")?.unwrap())] {
            let mut bytes=BlockEncoder::encode(64,InstructionBlock::new(&inline,0),BlockEncoderOptions::NONE)?.code_buffer;
            bytes.push(0xc3);let path=output.join(format!("{name}.bin"));fs::write(&path,bytes)?;
            let run=std::process::Command::new(&driver).arg(path).arg("unused").arg(mode.to_string()).output()?;
            fs::write(output.join(format!("{name}.stdout")),&run.stdout)?;
            assert!(run.status.success(),"{name}: {}",String::from_utf8_lossy(&run.stderr));
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
        assert_eq!(ranges.len(),2); assert_eq!(sites.len(),8);
        for (offset,range) in [(0,ranges[0]),(5,ranges[0]),(10,ranges[1])] {
            let disp = i32::from_le_bytes(blob[offset+1..offset+5].try_into()?);
            assert_eq!(offset as i64+5+i64::from(disp),range.0 as i64);
        }
        assert!(relocs.iter().any(|r| r.offset==15 && r.target==0x9999));
        assert_eq!(relocs.len(),1,"both shared routines read their policy inline; the other helper call stays");
        let mut strings=X86_HELPER_CALL_REL32_SLOT.repeat(2);
        let mut calls=vec![RelocRecord{offset:0,kind:1,target:0x5000},RelocRecord{offset:5,kind:1,target:0x6000}];
        let names=HashMap::from([("bpf_probe_read_kernel".into(),0x2000),
            ("bpf_probe_read_kernel_str".into(),0x5000),("bpf_probe_read_user_str".into(),0x6000)]);
        let (on,loads)=share(&mut strings,&mut calls,&layout,&names)?;
        assert_eq!(on.len(),1);assert_eq!(loads.len(),1);assert_eq!(loads[0].destination,11);
        assert!(calls.iter().any(|r|r.offset==5 && r.target==0x6000),"user strings retain original helper");
        assert!(!calls.iter().any(|r|r.target==0x5000));
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
