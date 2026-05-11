// SPDX-License-Identifier: MIT

use crate::analysis::{BlockId, InsnSite};
use crate::insn::*;
use crate::test_helpers::*;

#[test]
fn bbprogram_sites_in_block_treats_ldimm64_as_one_logical_site() {
    let wide = BpfInsn::ld_imm64(BPF_REG_1, 0, 0x1_0000_0000);
    let prog = lift_test_program(&[wide[0], wide[1], BpfInsn::exit()], &pass_ctx());

    // IMPL: needs BBProgram::sites_in_block(BlockId) -> impl Iterator<Item = InsnSite>.
    let sites = prog.sites_in_block(BlockId(0)).collect::<Vec<_>>();
    assert_eq!(
        sites,
        vec![InsnSite {
            block: BlockId(0),
            idx: 0
        }]
    );
}

#[test]
fn bbprogram_sites_in_block_excludes_terminator_from_body_iteration() {
    let prog = lift_test_program(
        &[
            BpfInsn::mov64_imm(BPF_REG_0, 0),
            BpfInsn::jeq_imm(BPF_REG_0, 0, 1),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::exit(),
        ],
        &pass_ctx(),
    );

    let sites = prog.sites_in_block(BlockId(0)).collect::<Vec<_>>();
    assert_eq!(
        sites,
        vec![InsnSite {
            block: BlockId(0),
            idx: 0
        }]
    );
}

#[test]
fn bbprogram_sites_can_include_terminators_when_requested() {
    let prog = lift_test_program(
        &[BpfInsn::jeq_imm(BPF_REG_0, 0, 1), BpfInsn::exit()],
        &pass_ctx(),
    );

    // IMPL: needs BBProgram::logical_sites_in_block(BlockId) as public API, or
    // BBProgram::sites_in_block_with_terminator(BlockId) equivalent.
    let sites = prog
        .sites_in_block_with_terminator(BlockId(0))
        .collect::<Vec<_>>();
    assert_eq!(
        sites,
        vec![InsnSite {
            block: BlockId(0),
            idx: 0
        }]
    );
}
