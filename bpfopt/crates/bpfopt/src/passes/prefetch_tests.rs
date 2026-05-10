use super::prefetch::*;
use crate::insn::XDP_PACKET_DATA_OFFSET as XDP_DATA_OFF;
use crate::insn::*;
use crate::pass::*;
use crate::pass::{AnalysisCache, PassContext};

fn filler(dst: u8, count: usize) -> Vec<BpfInsn> {
    (0..count)
        .map(|idx| BpfInsn::mov64_imm(dst, idx as i32))
        .collect()
}

fn ctx_with_prefetch_kfunc(btf_id: i32) -> PassContext {
    let mut ctx = PassContext::baseline();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name("bpf_prefetch", btf_id, 0)
        .unwrap();
    ctx
}

fn cold_prefetch_profile(execution_count: u64) -> PrefetchProfile {
    PrefetchProfile {
        execution_count,
        cache_references: execution_count,
        cache_misses: 0,
        miss_rate: 0.0,
    }
}

fn decode_prefetch_payload(payload: u64) -> anyhow::Result<u8> {
    let ptr_reg = (payload & 0xf) as u8;
    if ptr_reg > BPF_REG_10 {
        anyhow::bail!("prefetch ptr register {ptr_reg} is outside BPF_REG_0..BPF_REG_10");
    }
    if ((payload >> 4) & 0xf) != 0 {
        anyhow::bail!("prefetch payload has unsupported hint kind");
    }
    if payload >> 8 != 0 {
        anyhow::bail!("prefetch payload has non-zero reserved bits");
    }
    Ok(ptr_reg)
}

fn lookup_value_program() -> (BpfProgram, usize, usize) {
    let insns = vec![
        BpfInsn::helper_call(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::jeq_imm(BPF_REG_0, 0, 1),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
        BpfInsn::exit(),
    ];
    (BpfProgram::new(insns), 0, 2)
}

fn lookup_value_alias_program() -> (BpfProgram, usize, usize) {
    let insns = vec![
        BpfInsn::helper_call(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::mov64_reg(BPF_REG_6, BPF_REG_0),
        BpfInsn::jeq_imm(BPF_REG_6, 0, 1),
        BpfInsn::ldx_mem(BPF_DW, BPF_REG_1, BPF_REG_6, 8),
        BpfInsn::exit(),
    ];
    (BpfProgram::new(insns), 0, 3)
}

fn packet_program_with_filler(filler_count: usize) -> (BpfProgram, usize) {
    let mut insns = vec![BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_1, XDP_DATA_OFF)];
    insns.extend(filler(BPF_REG_3, filler_count));
    let load_pc = insns.len();
    insns.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_6, 0));
    insns.push(BpfInsn::exit());
    (BpfProgram::new(insns), load_pc)
}

fn run_prefetch_pass(program: &mut BpfProgram, ctx: &PassContext) -> PassResult {
    let mut cache = AnalysisCache::new();
    PrefetchPass.run(program, &mut cache, ctx).unwrap()
}

#[test]
fn prefetch_payload_round_trips_register_and_rejects_reserved_bits() {
    let payload = prefetch_payload(BPF_REG_2).unwrap();

    assert_eq!(decode_prefetch_payload(payload).unwrap(), BPF_REG_2);
    assert!(decode_prefetch_payload(payload | (1 << 4)).is_err());
    assert!(decode_prefetch_payload(payload | (1 << 8)).is_err());
    assert!(prefetch_payload(11).is_err());
}

#[test]
fn prefetch_pass_emits_map_value_prefetch_without_profile() {
    let (mut program, _call_pc, _load_pc) = lookup_value_program();
    let ctx = ctx_with_prefetch_kfunc(7777);

    let result = run_prefetch_pass(&mut program, &ctx);
    assert_eq!(result.sites_applied, 1);
    assert!(program.insns[2].is_kinsn_sidecar());
    assert_eq!(
        decode_prefetch_payload(program.insns[2].sidecar_payload()).unwrap(),
        BPF_REG_0
    );
    assert!(program.insns[3].is_call());
    assert_eq!(program.insns[3].src_reg(), BPF_PSEUDO_KINSN_CALL);
    assert_eq!(program.insns[3].imm, 7777);
    assert!(program.insns.last().unwrap().is_exit());
}

#[test]
fn prefetch_pass_uses_alias_register_for_map_value_deref() {
    let (mut program, _call_pc, _load_pc) = lookup_value_alias_program();
    let ctx = ctx_with_prefetch_kfunc(7777);

    let result = run_prefetch_pass(&mut program, &ctx);
    assert_eq!(result.sites_applied, 1);
    assert!(program.insns[3].is_kinsn_sidecar());
    assert_eq!(
        decode_prefetch_payload(program.insns[3].sidecar_payload()).unwrap(),
        BPF_REG_6
    );
}

#[test]
fn prefetch_pass_profile_can_filter_cold_map_value_site() {
    let (mut program, _call_pc, load_pc) = lookup_value_program();
    program.annotations[load_pc].prefetch_profile = Some(cold_prefetch_profile(100));
    let ctx = ctx_with_prefetch_kfunc(7777);

    let result = run_prefetch_pass(&mut program, &ctx);
    assert_eq!(result.sites_applied, 0);
    assert!(result
        .sites_skipped
        .iter()
        .any(|skip| skip.reason.contains("no observed cache misses")));
}

#[test]
fn prefetch_pass_emits_packet_prefetch_without_profile() {
    let (mut program, _load_pc) = packet_program_with_filler(8);
    let mut ctx = ctx_with_prefetch_kfunc(7777);
    ctx.prog_type = BPF_PROG_TYPE_XDP;

    let result = run_prefetch_pass(&mut program, &ctx);
    assert_eq!(result.sites_applied, 1);
    assert!(program.insns[1].is_kinsn_sidecar());
    assert_eq!(
        decode_prefetch_payload(program.insns[1].sidecar_payload()).unwrap(),
        BPF_REG_6
    );
}

#[test]
fn prefetch_pass_inserts_only_at_instruction_boundaries() {
    let wide = BpfInsn::ld_imm64(BPF_REG_3, 0, 123);
    let mut insns = vec![BpfInsn::ldx_mem(BPF_W, BPF_REG_6, BPF_REG_1, XDP_DATA_OFF)];
    insns.extend_from_slice(&wide);
    insns.extend(filler(BPF_REG_4, 8));
    insns.push(BpfInsn::ldx_mem(BPF_B, BPF_REG_0, BPF_REG_6, 0));
    insns.push(BpfInsn::exit());
    let mut program = BpfProgram::new(insns);
    let mut ctx = ctx_with_prefetch_kfunc(7777);
    ctx.prog_type = BPF_PROG_TYPE_XDP;

    let _result = run_prefetch_pass(&mut program, &ctx);
    assert!(program.insns[1].is_ldimm64());
    assert_eq!(program.insns[2].code, 0);
    assert!(program.insns[3].is_kinsn_sidecar());
}
