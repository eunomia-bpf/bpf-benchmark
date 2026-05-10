// SPDX-License-Identifier: MIT
// Per-instruction liveness analysis.

use std::collections::HashSet;

use crate::insn::*;
use crate::pass::{Analysis, BpfProgram, KinsnRegistry, RegSet};

/// Per-instruction liveness: which registers are live before/after each insn.
#[derive(Clone, Debug)]

pub struct LivenessResult {
    pub live_out: Vec<HashSet<u8>>,
    pub use_def: Vec<RegUseDefSet>,
}

impl LivenessResult {
    pub fn use_def_at(&self, pc: usize) -> Option<&RegUseDefSet> {
        self.use_def.get(pc)
    }
}

#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct RegUseDefSet {
    pub uses: HashSet<u8>,
    pub defs: HashSet<u8>,
}

pub struct LivenessAnalysis;

impl LivenessAnalysis {
    pub fn run_with_kinsn_registry(
        program: &BpfProgram,
        registry: &KinsnRegistry,
    ) -> anyhow::Result<LivenessResult> {
        run_liveness(program, Some(registry))
    }
}

impl Analysis for LivenessAnalysis {
    type Result = LivenessResult;

    fn run(program: &BpfProgram) -> LivenessResult {
        run_liveness(program, None).expect("context-free liveness cannot fail")
    }
}

fn run_liveness(
    program: &BpfProgram,
    kinsn_registry: Option<&KinsnRegistry>,
) -> anyhow::Result<LivenessResult> {
    let n = program.insns.len();
    let use_def = program_use_def_sets(&program.insns, kinsn_registry)?;
    let mut live_in = vec![HashSet::new(); n];
    let mut live_out = vec![HashSet::new(); n];

    // Standard backward dataflow to fixed point.
    let mut updated = true;
    while updated {
        updated = false;
        for pc in (0..n).rev() {
            let RegUseDefSet { uses, defs } = &use_def[pc];

            let mut new_out = HashSet::new();
            for s in get_successors(program, pc) {
                if s < n {
                    new_out.extend(&live_in[s]);
                }
            }

            let mut new_in: HashSet<u8> = new_out.difference(defs).cloned().collect();
            new_in.extend(uses);

            if new_in != live_in[pc] || new_out != live_out[pc] {
                live_in[pc] = new_in;
                live_out[pc] = new_out;
                updated = true;
            }
        }
    }

    Ok(LivenessResult { live_out, use_def })
}

fn program_use_def_sets(
    insns: &[BpfInsn],
    kinsn_registry: Option<&KinsnRegistry>,
) -> anyhow::Result<Vec<RegUseDefSet>> {
    let mut use_def = insns.iter().map(insn_use_def_set).collect::<Vec<_>>();
    let Some(registry) = kinsn_registry else {
        return Ok(use_def);
    };

    for pc in 0..insns.len() {
        let call = &insns[pc];
        if !call.is_call_kinsn() {
            continue;
        }
        let Some(sidecar_pc) = pc.checked_sub(1) else {
            anyhow::bail!("kinsn call at pc {pc} is missing its packed sidecar");
        };
        let sidecar = &insns[sidecar_pc];
        if !sidecar.is_kinsn_sidecar() {
            anyhow::bail!("kinsn call at pc {pc} is missing its packed sidecar");
        }

        let descriptor = registry.lookup_by_kinsn_call(call.imm, call.off)?;
        let payload = sidecar.sidecar_payload();
        let payload_bytes = payload.to_le_bytes();
        (descriptor.decode_proof)(&payload_bytes)
            .proof_len()
            .map_err(|err| {
                anyhow::anyhow!(
                    "failed to decode proof region for {} at pc {pc}: {err}",
                    descriptor.canonical_name
                )
            })?;

        let uses = (descriptor.register_uses)(payload);
        validate_register_uses(descriptor.canonical_name, pc, &uses)?;
        use_def[sidecar_pc].uses.clear();
        use_def[sidecar_pc].defs.clear();
        use_def[pc].uses = uses;
        use_def[pc].defs.clear();
    }

    Ok(use_def)
}

fn validate_register_uses(name: &str, pc: usize, uses: &RegSet) -> anyhow::Result<()> {
    for &reg in uses {
        if reg > BPF_REG_10 {
            anyhow::bail!("{name} kinsn call at pc {pc} uses invalid register r{reg}");
        }
    }
    Ok(())
}

pub fn insn_use_def_set(insn: &BpfInsn) -> RegUseDefSet {
    let mut uses = HashSet::new();
    let mut defs = HashSet::new();

    let class = insn.class();

    match class {
        BPF_ALU64 | BPF_ALU => {
            let op = bpf_op(insn.code);
            if op == BPF_MOV {
                defs.insert(insn.dst_reg());
                if bpf_src(insn.code) == BPF_X {
                    uses.insert(insn.src_reg());
                }
            } else {
                defs.insert(insn.dst_reg());
                uses.insert(insn.dst_reg());
                if bpf_src(insn.code) == BPF_X {
                    uses.insert(insn.src_reg());
                }
            }
        }
        BPF_LDX => {
            defs.insert(insn.dst_reg());
            uses.insert(insn.src_reg());
        }
        BPF_ST | BPF_STX => {
            uses.insert(insn.dst_reg());
            if class == BPF_STX {
                uses.insert(insn.src_reg());
            }
        }
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                // BPF calling convention: r1-r5 are arguments (used),
                // r0 is return value (defined), r1-r5 are clobbered (defined).
                for r in 1..=5 {
                    uses.insert(r);
                }
                for r in 0..=5 {
                    defs.insert(r);
                }
            } else if insn.is_exit() {
                uses.insert(0);
            } else {
                if bpf_src(insn.code) == BPF_X {
                    uses.insert(insn.src_reg());
                }
                if !insn.is_ja() {
                    uses.insert(insn.dst_reg());
                }
            }
        }
        BPF_LD => {
            defs.insert(insn.dst_reg());
        }
        _ => {}
    }

    RegUseDefSet { uses, defs }
}

/// Get successor PCs for instruction at `pc`.
fn get_successors(program: &BpfProgram, pc: usize) -> Vec<usize> {
    let insn = &program.insns[pc];
    let mut succs = Vec::new();
    let next = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };

    if insn.is_exit() {
        // No successors
    } else if insn.is_ja() {
        if let Some(target) = insn.branch_target_pc(pc) {
            succs.push(target);
        }
    } else if insn.is_cond_jmp() {
        succs.push(next);
        if let Some(target) = insn.branch_target_pc(pc) {
            succs.push(target);
        }
    } else {
        succs.push(next);
    }

    succs
}
