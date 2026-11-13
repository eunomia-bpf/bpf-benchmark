//! Linker-owned SysV memory routines. No kernel calls, SIMD, REP or overreads.
use super::*;
use std::collections::VecDeque;

#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub(super) struct Routine {
    copy: bool,
    length: Option<u16>,
    zero: bool,
}

impl Routine {
    fn operand(bytes: &mut Vec<u8>, opcode: &[u8], offset: u32) {
        bytes.extend_from_slice(opcode);
        let modrm = bytes.last_mut().expect("memory operand opcode");
        if offset == 0 {
            *modrm -= 0x80;
        } else if offset <= 127 {
            *modrm -= 0x40;
            bytes.push(offset as u8);
        } else {
            bytes.extend_from_slice(&offset.to_le_bytes());
        }
    }
    pub(super) fn at_call(name: &str, constants: Option<&HashMap<Register, u64>>) -> Option<Self> {
        let copy = match name {
            "memcpy" => true,
            "memset" => false,
            _ => return None,
        };
        let length = constants
            .and_then(|c| c.get(&Register::RDX))
            .copied()
            .filter(|&n| n <= 512)
            .map(|n| n as u16);
        let zero = !copy
            && constants
                .and_then(|c| c.get(&Register::RSI))
                .is_some_and(|v| v & 255 == 0);
        Some(Self { copy, length, zero })
    }

    pub(super) fn name(self) -> String {
        format!(
            "__native_link_local_{}_{}_{}",
            if self.copy { "memcpy" } else { "memset" },
            if self.zero { "zero" } else { "any" },
            self.length
                .map(|n| n.to_string())
                .unwrap_or_else(|| "dynamic".into())
        )
    }

    fn word(self, bytes: &mut Vec<u8>, offset: u32, width: u8) {
        if self.copy {
            let opcode: &[u8] = match width {
                8 => &[0x4c, 0x8b, 0x86], // mov r8,[rsi+disp]
                4 => &[0x44, 0x8b, 0x86],
                2 => &[0x44, 0x0f, 0xb7, 0x86],
                1 => &[0x44, 0x0f, 0xb6, 0x86],
                _ => unreachable!(),
            };
            Self::operand(bytes, opcode, offset);
        }
        let opcode: &[u8] = match width {
            8 => &[0x4c, 0x89, 0x87], // mov [rdi+disp],r8
            4 => &[0x44, 0x89, 0x87],
            2 => &[0x66, 0x44, 0x89, 0x87],
            1 => &[0x44, 0x88, 0x87],
            _ => unreachable!(),
        };
        Self::operand(bytes, opcode, offset);
    }

    fn advance(self, bytes: &mut Vec<u8>, size: u8) {
        bytes.extend_from_slice(&[0x48, 0x83, 0xc7, size]); // add rdi,size
        if self.copy {
            bytes.extend_from_slice(&[0x48, 0x83, 0xc6, size]);
        }
    }

    pub(super) fn bytes(self) -> Result<Vec<u8>> {
        let mut b = vec![0x48, 0x89, 0xf8]; // mov rax,rdi: original destination return
        if !self.copy {
            if self.zero {
                b.extend_from_slice(&[0x45, 0x31, 0xc0]);
            }
            // xor r8d,r8d
            else {
                b.extend_from_slice(&[0x44, 0x0f, 0xb6, 0xc6]); // movzx r8d,sil
                b.extend_from_slice(&[0x49, 0xb9]);
                b.extend_from_slice(&0x0101010101010101u64.to_le_bytes());
                b.extend_from_slice(&[0x4d, 0x0f, 0xaf, 0xc1]); // imul r8,r9
            }
        }
        if let Some(length) = self.length {
            let mut offset = 0;
            for width in [8, 4, 2, 1] {
                while u32::from(length) - offset >= u32::from(width) {
                    self.word(&mut b, offset, width);
                    offset += u32::from(width);
                }
            }
        } else {
            b.extend_from_slice(&[0x48, 0x83, 0xfa, 32]); // cmp rdx,32
            let small = append_x86_jcc_rel32(&mut b, 0x82);
            let loop32 = b.len();
            for offset in [0, 8, 16, 24] {
                self.word(&mut b, offset, 8);
            }
            self.advance(&mut b, 32);
            b.extend_from_slice(&[0x48, 0x83, 0xea, 32, 0x48, 0x83, 0xfa, 32]);
            let again = append_x86_jcc_rel32(&mut b, 0x83);
            patch_x86_rel32(&mut b, again, loop32)?;
            let tail = b.len();
            patch_x86_rel32(&mut b, small, tail)?;
            b.extend_from_slice(&[0x48, 0x83, 0xfa, 8]);
            let subword = append_x86_jcc_rel32(&mut b, 0x82);
            let loop8 = b.len();
            self.word(&mut b, 0, 8);
            self.advance(&mut b, 8);
            b.extend_from_slice(&[0x48, 0x83, 0xea, 8, 0x48, 0x83, 0xfa, 8]);
            let again = append_x86_jcc_rel32(&mut b, 0x83);
            patch_x86_rel32(&mut b, again, loop8)?;
            let tail = b.len();
            patch_x86_rel32(&mut b, subword, tail)?;
            for width in [4, 2, 1] {
                b.extend_from_slice(&[0xf6, 0xc2, width]); // test dl,width
                let skip = append_x86_jcc_rel32(&mut b, 0x84);
                self.word(&mut b, 0, width);
                if width != 1 {
                    self.advance(&mut b, width);
                }
                let end = b.len();
                patch_x86_rel32(&mut b, skip, end)?;
            }
        }
        b.push(0xc3);
        Ok(b)
    }
}

/// Must constants at each instruction entry, including CFG joins and loops.
/// Unknown indirect jumps disable specialization; unproven sizes use the loop.
pub(super) fn constants(
    bytes: &[u8],
    address: u64,
) -> Result<HashMap<u64, HashMap<Register, u64>>> {
    let instructions: Vec<_> = Decoder::with_ip(64, bytes, address, DecoderOptions::NONE)
        .into_iter()
        .collect();
    if instructions.iter().any(|i| i.is_invalid()) {
        bail!("invalid memory-specialization input");
    }
    if instructions.iter().any(|i| {
        i.flow_control() == FlowControl::IndirectBranch
            || (i.flow_control() == FlowControl::Call
                && i.near_branch_target() != i.next_ip()
                && i.near_branch_target() >= address
                && i.near_branch_target() < address + bytes.len() as u64)
    }) {
        return Ok(HashMap::new());
    }
    let indices: HashMap<_, _> = instructions
        .iter()
        .enumerate()
        .map(|(n, i)| (i.ip(), n))
        .collect();
    let mut states: Vec<Option<HashMap<Register, u64>>> = vec![None; instructions.len()];
    if states.is_empty() {
        return Ok(HashMap::new());
    }
    states[0] = Some(HashMap::new());
    let mut queue = VecDeque::from([0]);
    let mut info = InstructionInfoFactory::new();
    while let Some(index) = queue.pop_front() {
        let i = &instructions[index];
        let before = states[index].as_ref().expect("queued state");
        let mut after = before.clone();
        for r in info.info(i).used_registers() {
            if matches!(
                r.access(),
                OpAccess::Write
                    | OpAccess::CondWrite
                    | OpAccess::ReadWrite
                    | OpAccess::ReadCondWrite
            ) {
                if let Some(reg) = x86_gpr64_family(r.register()) {
                    after.remove(&reg);
                }
            }
        }
        if i.op0_kind() == OpKind::Register && matches!(i.op0_register().size(), 4 | 8) {
            let dst = x86_gpr64_family(i.op0_register());
            let value = if i.mnemonic() == Mnemonic::Mov {
                if i.op1_kind() == OpKind::Register {
                    x86_gpr64_family(i.op1_register()).and_then(|r| before.get(&r).copied())
                } else if matches!(
                    i.op1_kind(),
                    OpKind::Immediate32 | OpKind::Immediate64 | OpKind::Immediate32to64
                ) {
                    Some(i.try_immediate(1)?)
                } else {
                    None
                }
            } else if i.mnemonic() == Mnemonic::Xor
                && i.op1_kind() == OpKind::Register
                && i.op0_register() == i.op1_register()
            {
                Some(0)
            } else {
                None
            };
            if let (Some(reg), Some(value)) = (dst, value) {
                after.insert(
                    reg,
                    if i.op0_register().size() == 4 {
                        value as u32 as u64
                    } else {
                        value
                    },
                );
            }
        }
        if matches!(
            i.flow_control(),
            FlowControl::Call | FlowControl::IndirectCall
        ) {
            clear_x86_call_clobbered_registers(&mut after);
        }
        let mut successors = Vec::new();
        if matches!(
            i.flow_control(),
            FlowControl::UnconditionalBranch | FlowControl::ConditionalBranch
        ) {
            if let Some(&n) = indices.get(&i.near_branch_target()) {
                successors.push(n);
            }
        }
        if matches!(
            i.flow_control(),
            FlowControl::Next
                | FlowControl::Call
                | FlowControl::IndirectCall
                | FlowControl::ConditionalBranch
        ) && index + 1 < instructions.len()
        {
            successors.push(index + 1);
        }
        for n in successors {
            let merged = match &states[n] {
                None => after.clone(),
                Some(old) => old
                    .iter()
                    .filter(|(r, v)| after.get(r) == Some(v))
                    .map(|(&r, &v)| (r, v))
                    .collect(),
            };
            if states[n].as_ref() != Some(&merged) {
                states[n] = Some(merged);
                queue.push_back(n);
            }
        }
    }
    Ok(instructions
        .iter()
        .zip(states)
        .filter_map(|(i, s)| s.map(|s| (i.ip() - address, s)))
        .collect())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn memory_constants_join_branches_clobbers_and_loops() -> Result<()> {
        // Either length3 or length4 reaches the call: a linear scan would
        // incorrectly specialize this call to4 and overrun the3-byte path.
        let branch = [
            0x85, 0xff, 0x74, 7, 0xba, 3, 0, 0, 0, 0xeb, 5, 0xba, 4, 0, 0, 0, 0xe8, 0, 0, 0, 0,
            0xc3,
        ];
        assert!(!constants(&branch, 0)?[&16].contains_key(&Register::RDX));
        let equal = [
            0xba, 0x70, 1, 0, 0, 0x31, 0xf6, 0xe8, 0, 0, 0, 0, 0xe8, 0, 0, 0, 0, 0xc3,
        ];
        let states = constants(&equal, 0)?;
        assert_eq!(states[&7].get(&Register::RDX), Some(&368));
        assert_eq!(states[&7].get(&Register::RSI), Some(&0));
        assert!(!states[&12].contains_key(&Register::RDX));
        let partial = [0xba, 3, 0, 0, 0, 0xb2, 4, 0xe8, 0, 0, 0, 0, 0xc3];
        assert!(!constants(&partial, 0)?[&7].contains_key(&Register::RDX));
        let looped = [
            0xba, 3, 0, 0, 0, 0x48, 0xff, 0xca, 0x75, 0xfb, 0xe8, 0, 0, 0, 0, 0xc3,
        ];
        assert!(!constants(&looped, 0)?[&10].contains_key(&Register::RDX));
        let indirect = [0xba, 3, 0, 0, 0, 0xff, 0xe0];
        assert!(constants(&indirect, 0)?.is_empty());
        let local_call = [0xba, 3, 0, 0, 0, 0xe8, 1, 0, 0, 0, 0xc3, 0xc3];
        assert!(constants(&local_call, 0)?.is_empty());
        Ok(())
    }

    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    mod execution {
        use super::*;
        use std::ffi::c_void;
        unsafe extern "C" {
            fn mmap(
                addr: *mut c_void,
                len: usize,
                prot: i32,
                flags: i32,
                fd: i32,
                offset: i64,
            ) -> *mut c_void;
            fn mprotect(addr: *mut c_void, len: usize, prot: i32) -> i32;
            fn munmap(addr: *mut c_void, len: usize) -> i32;
        }
        struct Mapping {
            address: *mut c_void,
            length: usize,
        }
        impl Mapping {
            fn new(length: usize) -> Self {
                let address = unsafe { mmap(std::ptr::null_mut(), length, 3, 0x22, -1, 0) };
                assert_ne!(address as isize, -1);
                Self { address, length }
            }
            fn code(bytes: &[u8]) -> Self {
                let result = Self::new(bytes.len());
                unsafe {
                    std::ptr::copy_nonoverlapping(
                        bytes.as_ptr(),
                        result.address.cast(),
                        bytes.len(),
                    );
                }
                assert_eq!(unsafe { mprotect(result.address, result.length, 5) }, 0);
                result
            }
        }
        impl Drop for Mapping {
            fn drop(&mut self) {
                assert_eq!(unsafe { munmap(self.address, self.length) }, 0);
            }
        }

        pub(crate) fn call_blob(bytes: &[u8], dest: *mut u8, arg: usize, length: usize) -> *mut u8 {
            let code = Mapping::code(bytes);
            let f: unsafe extern "C" fn(*mut u8, usize, usize) -> *mut u8 =
                unsafe { std::mem::transmute(code.address) };
            unsafe { f(dest, arg, length) }
        }

        #[test]
        fn memory_routines_execute_unaligned_boundaries_fill_and_return() -> Result<()> {
            let lengths: Vec<usize> = (0..=65)
                .chain([127, 128, 129, 367, 368, 369, 511, 512, 513, 4096, 17111])
                .collect();
            for copy in [false, true] {
                for specialized in [false, true] {
                    for &length in &lengths {
                        for zero in [false, true].into_iter().filter(|z| !copy || !z) {
                            let routine = Routine {
                                copy,
                                length: (specialized && length <= 512).then_some(length as u16),
                                zero,
                            };
                            let bytes = routine.bytes()?;
                            let code = Mapping::code(&bytes);
                            let f: unsafe extern "C" fn(*mut u8, usize, usize) -> *mut u8 =
                                unsafe { std::mem::transmute(code.address) };
                            let mut decoder = Decoder::new(64, &bytes, DecoderOptions::NONE);
                            let mut info = InstructionInfoFactory::new();
                            while decoder.can_decode() {
                                let insn = decoder.decode();
                                assert!(!insn.is_invalid());
                                assert!(!insn.has_rep_prefix() && !insn.has_repne_prefix());
                                for reg in info.info(&insn).used_registers() {
                                    assert!(!reg.register().is_vector_register());
                                    if matches!(
                                        reg.access(),
                                        OpAccess::Write
                                            | OpAccess::ReadWrite
                                            | OpAccess::CondWrite
                                            | OpAccess::ReadCondWrite
                                    ) {
                                        assert!(!matches!(
                                            x86_gpr64_family(reg.register()),
                                            Some(
                                                Register::RBX
                                                    | Register::RBP
                                                    | Register::R12
                                                    | Register::R13
                                                    | Register::R14
                                                    | Register::R15
                                            )
                                        ));
                                    }
                                }
                            }
                            for offset in 0..8 {
                                for value in [0usize, 1, 0xff, 0x100, 0x1234]
                                    .into_iter()
                                    .filter(|v| !zero || v & 255 == 0)
                                {
                                    let mut dest = vec![0xa5; length + 32];
                                    let source: Vec<u8> = (0..length + 32)
                                        .map(|n| (n.wrapping_mul(37) & 255) as u8)
                                        .collect();
                                    let before = source.clone();
                                    let ptr = unsafe { dest.as_mut_ptr().add(offset + 8) };
                                    let arg = if copy {
                                        (unsafe { source.as_ptr().add(offset + 8) }) as usize
                                    } else {
                                        value
                                    };
                                    assert_eq!(unsafe { f(ptr, arg, length) }, ptr);
                                    let mut expected = vec![0xa5; length + 32];
                                    if copy {
                                        expected[offset + 8..offset + 8 + length].copy_from_slice(
                                            &source[offset + 8..offset + 8 + length],
                                        );
                                    } else {
                                        expected[offset + 8..offset + 8 + length].fill(value as u8);
                                    }
                                    assert_eq!(
                                        dest, expected,
                                        "{routine:?}, n={length}, offset={offset}, value={value}"
                                    );
                                    assert_eq!(source, before);
                                }
                            }
                        }
                    }
                }
            }
            Ok(())
        }

        #[test]
        fn memory_routines_do_not_read_or_write_past_guard_page() -> Result<()> {
            for length in (0..=65).chain([127, 128, 129, 367, 368, 369, 511, 512, 513, 4096]) {
                let source = Mapping::new(8192);
                let dest = Mapping::new(8192);
                for map in [&source, &dest] {
                    assert_eq!(
                        unsafe { mprotect(map.address.cast::<u8>().add(4096).cast(), 4096, 0) },
                        0
                    );
                }
                let src = unsafe { source.address.cast::<u8>().add(4096 - length) };
                let dst = unsafe { dest.address.cast::<u8>().add(4096 - length) };
                unsafe {
                    std::ptr::write_bytes(src, 0x5a, length);
                }
                for copy in [false, true] {
                    for specialized in [false, true] {
                        let routine = Routine {
                            copy,
                            length: (specialized && length <= 512).then_some(length as u16),
                            zero: false,
                        };
                        let arg = if copy { src as usize } else { 0x1234 };
                        assert_eq!(call_blob(&routine.bytes()?, dst, arg, length), dst);
                        let actual = unsafe { std::slice::from_raw_parts(dst, length) };
                        assert!(actual.iter().all(|&v| v == if copy { 0x5a } else { 0x34 }));
                    }
                }
            }
            for copy in [false, true] {
                for length in [None, Some(0)] {
                    let routine = Routine {
                        copy,
                        length,
                        zero: false,
                    };
                    assert!(call_blob(&routine.bytes()?, std::ptr::null_mut(), 0, 0).is_null());
                }
            }
            Ok(())
        }

        #[test]
        #[ignore = "opt-in host timing evidence, not a correctness or workload gate"]
        fn memory_host_microbenchmark() -> Result<()> {
            use std::hint::black_box;
            use std::time::Instant;
            let output = std::env::var_os("NATIVE_LINK_MEMORY_BENCH_OUTPUT").ok_or_else(|| {
                anyhow!("NATIVE_LINK_MEMORY_BENCH_OUTPUT is required for timing evidence")
            })?;
            let max_leaf = std::arch::x86_64::__cpuid(0).eax;
            let leaf = if max_leaf >= 7 {
                std::arch::x86_64::__cpuid_count(7, 0)
            } else {
                std::arch::x86_64::__cpuid_count(0, 0)
            };
            let fsrm = max_leaf >= 7 && leaf.edx & (1 << 4) != 0;
            let fsrs = max_leaf >= 7
                && leaf.eax >= 1
                && std::arch::x86_64::__cpuid_count(7, 1).eax & (1 << 11) != 0;
            let mut results = Vec::new();
            for copy in [false, true] {
                for length in [0, 16, 32, 64, 71, 144, 200, 368, 512, 1024, 4096, 16384] {
                    let mut forms = vec![(
                        "gpr_loop",
                        Routine {
                            copy,
                            length: None,
                            zero: !copy,
                        }
                        .bytes()?,
                    )];
                    if length <= 512 {
                        forms.push((
                            "gpr_unrolled",
                            Routine {
                                copy,
                                length: Some(length as u16),
                                zero: !copy,
                            }
                            .bytes()?,
                        ));
                    }
                    // These REP bodies are measurement controls only. Production
                    // does not select REP from an unmeasured CPUID heuristic.
                    let rep = if copy {
                        vec![0x48, 0x89, 0xf8, 0x48, 0x89, 0xd1, 0xf3, 0xa4, 0xc3]
                    } else {
                        vec![
                            0x49, 0x89, 0xf8, 0x48, 0x89, 0xf0, 0x48, 0x89, 0xd1, 0xf3, 0xaa, 0x4c,
                            0x89, 0xc0, 0xc3,
                        ]
                    };
                    forms.push(("rep", rep));
                    let code: Vec<_> = forms.iter().map(|(_, b)| Mapping::code(b)).collect();
                    for offset in [0, 1, 7] {
                        let mut dest = vec![0xa5u8; length + 64];
                        let source = vec![0x5au8; length + 64];
                        let dst = unsafe { dest.as_mut_ptr().add(offset) };
                        let arg = if copy {
                            (unsafe { source.as_ptr().add(7 - offset) }) as usize
                        } else {
                            0
                        };
                        for round in 0..5 {
                            for shift in 0..forms.len() {
                                let index = (round + shift) % forms.len();
                                let f: unsafe extern "C" fn(*mut u8, usize, usize) -> *mut u8 =
                                    unsafe { std::mem::transmute(code[index].address) };
                                for _ in 0..1000 {
                                    black_box(unsafe { f(dst, arg, length) });
                                }
                                let start = Instant::now();
                                for _ in 0..100_000 {
                                    black_box(unsafe {
                                        f(black_box(dst), black_box(arg), black_box(length))
                                    });
                                    if length != 0 {
                                        black_box(unsafe {
                                            std::ptr::read_volatile(dst.add(length - 1))
                                        });
                                    }
                                }
                                let elapsed = start.elapsed().as_nanos();
                                assert!(dest[offset..offset + length]
                                    .iter()
                                    .all(|&v| v == if copy { 0x5a } else { 0 }));
                                results.push(serde_json::json!({"copy":copy,"length":length,"offset":offset,
                                    "form":forms[index].0,"round":round,"iterations":100_000,"elapsed_ns":elapsed}));
                            }
                        }
                    }
                }
            }
            fs::write(
                output,
                serde_json::to_vec_pretty(&serde_json::json!({
                "host_cpuid":{"fsrm":fsrm,"fsrs":fsrs},"observations":results,
                "limits":["Hot host buffers with immediate read; not guest or workload throughput.",
                          "REP is a control only; no production selection was made."]}))?,
            )?;
            Ok(())
        }
    }

    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    pub(crate) use execution::call_blob;
}

#[cfg(all(test, target_arch = "x86_64", target_os = "linux"))]
pub(super) use tests::call_blob;
