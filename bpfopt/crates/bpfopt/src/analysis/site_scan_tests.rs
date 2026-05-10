use super::site_scan::iter_sites;
use crate::insn::*;

#[test]
fn iter_sites_visits_only_instruction_boundaries() {
    let map = BpfInsn::ld_imm64(1, BPF_PSEUDO_MAP_FD, 7);
    let insns = vec![map[0], map[1], BpfInsn::mov64_imm(0, 1), BpfInsn::exit()];

    let visited = iter_sites(&insns, |insns, pc| Some(insn_width(&insns[pc])));

    assert_eq!(
        visited.iter().map(|site| site.pc).collect::<Vec<_>>(),
        vec![0, 2, 3]
    );
}

#[test]
fn iter_sites_keeps_pattern_length() {
    let insns = vec![BpfInsn::mov64_imm(0, 1), BpfInsn::exit()];

    let sites = iter_sites(&insns, |insns, pc| insns[pc].is_mov64_imm().then_some(1));

    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].pc, 0);
    assert_eq!(sites[0].len, 1);
}
