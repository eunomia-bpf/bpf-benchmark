use super::*;

fn block_for_original_pc(prog: &ProgramCFG, pc: usize) -> BlockId {
    prog.original_pc_to_site(pc)
        .map(|site| site.block)
        .expect("original pc should map to a block")
}

#[test]
fn lift_treats_ldimm64_as_one_logical_instruction_with_second_slot_metadata() {
    let imm = BpfInsn::ld_imm64(1, 0, 0x1122_3344_5566_7788);
    let insns = vec![imm[0], imm[1], BpfInsn::mov64_reg(0, 1), BpfInsn::exit()];

    let prog = lift(&insns, None).expect("lift should keep LD_IMM64 metadata");

    assert_eq!(prog.blocks[0].insns.len(), 2);
    assert!(prog
        .ldimm64_second_slot(InsnSite::for_test(BlockId(0), 0))
        .is_some());
}

#[test]
fn lift_assigns_pseudo_call_target_to_a_subprogram_frame() {
    let insns = vec![
        BpfInsn::pseudo_call_to(0, 3),
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::exit(),
    ];

    let prog = lift(&insns, None).expect("lift should resolve pseudo_call");
    let entry = &prog.blocks[0];
    let Terminator::Call {
        callee, return_to, ..
    } = entry.terminator
    else {
        panic!("entry block should end in a pseudo_call exit");
    };

    assert_eq!(prog.blocks[callee.0].frame, FrameId(1));
    assert_eq!(prog.blocks[return_to.0].frame, FrameId(0));
}

#[test]
fn lift_preserves_ja32_imm_targets_separately_from_ja_off_targets() {
    let ja32 = vec![
        BpfInsn::new(BPF_JMP32 | BPF_JA, 0, 0, 2),
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::mov64_imm(1, 1),
        BpfInsn::exit(),
    ];
    let ja = vec![
        BpfInsn::ja(2),
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::mov64_imm(1, 1),
        BpfInsn::exit(),
    ];

    for insns in [&ja32, &ja] {
        let prog = lift(insns, None).expect("lift should resolve unconditional jump");
        let target = block_for_original_pc(&prog, 3);
        let Terminator::Jump { target: actual, .. } = prog.blocks[0].terminator else {
            panic!("entry block should end in a jump");
        };
        assert_eq!(actual, target);
    }
}

#[test]
fn lift_resolves_conditional_branch_taken_and_fallthrough_blocks() {
    let insns = vec![
        BpfInsn::jeq_imm(1, 0, 1),
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::exit(),
    ];

    let prog = lift(&insns, None).expect("lift should resolve conditional branch");
    let taken_block = block_for_original_pc(&prog, 2);
    let fallthrough_block = block_for_original_pc(&prog, 1);
    let Terminator::CondBranch {
        taken, fallthrough, ..
    } = prog.blocks[0].terminator
    else {
        panic!("entry block should end in a conditional branch");
    };

    assert_eq!(taken, taken_block);
    assert_eq!(fallthrough, fallthrough_block);
}

#[test]
fn lift_records_exit_as_a_raw_terminator() {
    let insns = vec![BpfInsn::mov64_imm(0, 0), BpfInsn::exit()];

    let prog = lift(&insns, None).expect("lift should keep exit exit");

    let Terminator::Exit { insn } = prog.blocks[0].terminator else {
        panic!("block should end in exit");
    };
    assert_eq!(insn, BpfInsn::exit());
}

#[test]
fn lift_creates_subprogram_entry_blocks_for_pseudo_func_ldimm64_targets() {
    let callback = BpfInsn::ld_imm64(2, BPF_PSEUDO_FUNC, 3);
    let insns = vec![
        callback[0],
        callback[1],
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::exit(),
        BpfInsn::mov64_reg(0, 1),
        BpfInsn::exit(),
    ];

    let prog = lift(&insns, None).expect("lift should mark pseudo_func subprogram entry");
    let subprog_block = block_for_original_pc(&prog, 4);

    assert_eq!(prog.blocks[subprog_block.0].frame, FrameId(1));
}
