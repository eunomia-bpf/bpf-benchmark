// SPDX-License-Identifier: MIT
// Program-level pseudo-map reference binding extraction.

use crate::insn::{insn_width, BpfInsn, MapPseudo};
use crate::pass::{Analysis, BpfProgram};

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MapBinding {
    pub pc_load: usize,
    pub kind: MapPseudo,
    pub imm: i32,
    pub value_offset: u32,
    pub map_idx: Option<usize>,
    pub map_id: Option<u32>,
}

#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct MapRefsResult {
    pub bindings: Vec<MapBinding>,
}

pub struct MapRefsAnalysis;

impl Analysis for MapRefsAnalysis {
    type Result = MapRefsResult;

    fn run(program: &BpfProgram) -> MapRefsResult {
        collect_map_bindings(&program.insns, &program.map_ids, &program.map_fd_bindings)
    }
}

pub fn collect_map_bindings(
    insns: &[BpfInsn],
    map_ids: &[u32],
    fd_bindings: &std::collections::HashMap<i32, u32>,
) -> MapRefsResult {
    let mut bindings = Vec::new();
    let mut fd_order = Vec::<i32>::new();
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = insns[pc];
        if let Some(kind) = insn.map_pseudo() {
            let value_offset = insns.get(pc + 1).map_or(0, |next| next.imm as u32);
            let (map_idx, map_id) =
                resolve_map_ref(kind, insn.imm, map_ids, fd_bindings, &mut fd_order);
            bindings.push(MapBinding {
                pc_load: pc,
                kind,
                imm: insn.imm,
                value_offset,
                map_idx,
                map_id,
            });
        }
        pc += insn_width(&insn);
    }

    MapRefsResult { bindings }
}

fn resolve_map_ref(
    kind: MapPseudo,
    imm: i32,
    map_ids: &[u32],
    fd_bindings: &std::collections::HashMap<i32, u32>,
    fd_order: &mut Vec<i32>,
) -> (Option<usize>, Option<u32>) {
    if kind.uses_index() {
        let Ok(index) = usize::try_from(imm) else {
            return (None, None);
        };
        return (Some(index), map_ids.get(index).copied());
    }

    if !fd_order.contains(&imm) {
        fd_order.push(imm);
    }
    let index = fd_order.iter().position(|fd| *fd == imm);
    let map_id = fd_bindings
        .get(&imm)
        .copied()
        .or_else(|| index.and_then(|idx| map_ids.get(idx).copied()));
    (index, map_id)
}
