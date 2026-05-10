use super::map_refs::{collect_map_bindings, MapRefsAnalysis};
use crate::insn::*;
use crate::pass::{Analysis, BpfProgram};
use std::collections::HashMap;

#[test]
fn map_refs_extracts_fd_and_idx_bindings() {
    let fd = BpfInsn::ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let idx_value = BpfInsn::ld_imm64(2, BPF_PSEUDO_MAP_IDX_VALUE, 1);
    let insns = vec![fd[0], fd[1], idx_value[0], idx_value[1], BpfInsn::exit()];
    let bindings = collect_map_bindings(&insns, &[101, 202], &HashMap::from([(42, 101)]));

    assert_eq!(bindings.bindings.len(), 2);
    assert_eq!(bindings.bindings[0].kind, MapPseudo::Fd);
    assert_eq!(bindings.bindings[0].map_idx, Some(0));
    assert_eq!(bindings.bindings[0].map_id, Some(101));
    assert_eq!(bindings.bindings[1].kind, MapPseudo::IdxValue);
    assert_eq!(bindings.bindings[1].map_idx, Some(1));
    assert_eq!(bindings.bindings[1].map_id, Some(202));
}

#[test]
fn map_refs_analysis_uses_program_bindings_after_deleted_fd_prefix() {
    let fd = BpfInsn::ld_imm64(1, BPF_PSEUDO_MAP_FD, 77);
    let mut program = BpfProgram::new(vec![fd[0], fd[1], BpfInsn::exit()]);
    program.map_ids = vec![303];
    program.map_fd_bindings = HashMap::from([(77, 303)]);

    let result = MapRefsAnalysis::run(&program);

    assert_eq!(result.bindings[0].map_id, Some(303));
}
