// SPDX-License-Identifier: MIT
//! Daemon-owned pass execution wrappers.
//!
//! bpfopt runs pure bytecode transforms. The daemon wraps that runner with
//! live-kernel concerns: kinsn fd_array transport, per-pass verifier dry-runs,
//! verifier-state refresh, and rollback on rejected transforms.

use std::collections::HashMap;
use std::os::unix::io::RawFd;
use std::sync::{Arc, Mutex};

use anyhow::Result;
use bpfopt::{insn, pass};
use serde::Serialize;

/// Live daemon resolver: descriptor BTF FDs are transported through fd_array
/// slots, and CALL.off stores the 1-based fd_array slot.
#[derive(Debug)]
pub(crate) struct FdArrayKinsnCallResolver {
    target_btf_fds: HashMap<String, RawFd>,
    required_btf_fds: Mutex<Vec<RawFd>>,
}

impl FdArrayKinsnCallResolver {
    pub(crate) fn new(target_btf_fds: HashMap<String, RawFd>) -> Self {
        Self {
            target_btf_fds,
            required_btf_fds: Mutex::new(Vec::new()),
        }
    }

    pub(crate) fn reset_required_btf_fds(&self) -> Result<()> {
        self.required_btf_fds
            .lock()
            .map_err(|_| anyhow::anyhow!("kinsn fd-array resolver lock poisoned"))?
            .clear();
        Ok(())
    }

    pub(crate) fn required_btf_fds(&self) -> Result<Vec<RawFd>> {
        Ok(self
            .required_btf_fds
            .lock()
            .map_err(|_| anyhow::anyhow!("kinsn fd-array resolver lock poisoned"))?
            .clone())
    }

    pub(crate) fn restore_required_btf_fds(&self, snapshot: Vec<RawFd>) -> Result<()> {
        *self
            .required_btf_fds
            .lock()
            .map_err(|_| anyhow::anyhow!("kinsn fd-array resolver lock poisoned"))? = snapshot;
        Ok(())
    }

    pub(crate) fn all_btf_fds(&self) -> Vec<RawFd> {
        let mut fds: Vec<RawFd> = self.target_btf_fds.values().copied().collect();
        fds.sort();
        fds.dedup();
        fds
    }

    fn ensure_required_btf_fd_slot(&self, btf_fd: RawFd) -> Result<i16> {
        let mut required = self
            .required_btf_fds
            .lock()
            .map_err(|_| anyhow::anyhow!("kinsn fd-array resolver lock poisoned"))?;
        if let Some(idx) = required.iter().position(|&fd| fd == btf_fd) {
            return Ok(idx as i16 + 1);
        }

        required.push(btf_fd);
        Ok(required.len() as i16)
    }
}

impl pass::KinsnCallResolver for FdArrayKinsnCallResolver {
    fn call_off_for_target_name(
        &self,
        registry: &pass::KinsnRegistry,
        target_name: &str,
    ) -> Result<i16> {
        if let Some(&btf_fd) = self.target_btf_fds.get(target_name) {
            return self.ensure_required_btf_fd_slot(btf_fd);
        }
        Ok(registry.call_off_for_target_name(target_name))
    }
}

#[derive(Clone, Debug)]
pub(crate) struct DaemonContext {
    pub(crate) pass_context: pass::PassContext,
    pub(crate) kinsn_resolver: Arc<FdArrayKinsnCallResolver>,
}

impl DaemonContext {
    pub(crate) fn new(
        mut pass_context: pass::PassContext,
        target_btf_fds: HashMap<String, RawFd>,
    ) -> Self {
        let kinsn_resolver = Arc::new(FdArrayKinsnCallResolver::new(target_btf_fds));
        pass_context.kinsn_call_resolver = kinsn_resolver.clone();
        Self {
            pass_context,
            kinsn_resolver,
        }
    }
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
#[serde(rename_all = "snake_case")]
pub(crate) enum PassVerifyStatus {
    NotNeeded,
    Accepted,
    Rejected,
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
pub(crate) struct PassVerifyResult {
    pub(crate) status: PassVerifyStatus,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub(crate) error_message: Option<String>,
    #[serde(skip)]
    pub(crate) verifier_states: Arc<[pass::VerifierInsn]>,
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
pub(crate) struct PassRollbackResult {
    pub(crate) action: String,
    pub(crate) restored_insn_count: usize,
}

impl Default for PassVerifyResult {
    fn default() -> Self {
        Self::not_needed()
    }
}

impl PassVerifyResult {
    pub(crate) fn not_needed() -> Self {
        Self {
            status: PassVerifyStatus::NotNeeded,
            error_message: None,
            verifier_states: Arc::from([]),
        }
    }

    #[cfg_attr(not(test), allow(dead_code))]
    pub(crate) fn accepted() -> Self {
        Self {
            status: PassVerifyStatus::Accepted,
            error_message: None,
            verifier_states: Arc::from([]),
        }
    }

    #[cfg_attr(not(test), allow(dead_code))]
    pub(crate) fn accepted_with_verifier_states(states: Vec<pass::VerifierInsn>) -> Self {
        Self {
            status: PassVerifyStatus::Accepted,
            error_message: None,
            verifier_states: Arc::from(states),
        }
    }

    pub(crate) fn rejected(error_message: impl Into<String>) -> Self {
        Self {
            status: PassVerifyStatus::Rejected,
            error_message: Some(error_message.into()),
            verifier_states: Arc::from([]),
        }
    }

    fn rejected_change(&self) -> bool {
        matches!(self.status, PassVerifyStatus::Rejected)
    }
}

impl PassRollbackResult {
    pub(crate) fn restored_pre_pass_snapshot(restored_insn_count: usize) -> Self {
        Self {
            action: "restored_pre_pass_snapshot".to_string(),
            restored_insn_count,
        }
    }
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct PassDebugTrace {
    pub(crate) pass_name: String,
    pub(crate) changed: bool,
    pub(crate) verify: PassVerifyResult,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub(crate) bytecode_before: Option<insn::BpfBytecodeDump>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub(crate) bytecode_after: Option<insn::BpfBytecodeDump>,
}

#[derive(Clone, Debug)]
pub(crate) struct VerifiedPassResult {
    pub(crate) result: pass::PassResult,
    pub(crate) verify: PassVerifyResult,
    pub(crate) rollback: Option<PassRollbackResult>,
}

#[derive(Clone, Debug)]
pub(crate) struct VerifiedPipelineResult {
    pub(crate) pass_results: Vec<VerifiedPassResult>,
    pub(crate) total_sites_applied: usize,
    pub(crate) program_changed: bool,
    pub(crate) debug_traces: Vec<PassDebugTrace>,
}

pub(crate) fn run_with_verifier<V>(
    pm: &pass::PassManager,
    program: &mut pass::BpfProgram,
    ctx: &pass::PassContext,
    kinsn_resolver: &FdArrayKinsnCallResolver,
    verifier: &mut V,
) -> Result<VerifiedPipelineResult>
where
    V: FnMut(&str, &pass::BpfProgram) -> Result<PassVerifyResult>,
{
    let mut cache = pass::AnalysisCache::new();
    let mut pass_results = Vec::new();
    let mut total_sites = 0usize;
    let mut any_changed = false;
    let mut debug_traces = Vec::new();
    let mut pass_idx = 0usize;

    while let Some(pass_ref) = pm.pass_at(pass_idx) {
        if !pm.pass_allowed(pass_ref, ctx)? {
            pass_idx += 1;
            continue;
        }

        let has_fixed_point_pair = if pass_ref.name() == "const_prop" {
            match pm.pass_at(pass_idx + 1) {
                Some(next) if next.name() == "dce" => pm.pass_allowed(next, ctx)?,
                _ => false,
            }
        } else {
            false
        };

        if has_fixed_point_pair {
            for _ in 0..pass::CONST_PROP_DCE_FIXED_POINT_MAX_ITERS {
                let const_result = run_single_pass_with_verifier(
                    pm,
                    pass_ref,
                    program,
                    &mut cache,
                    ctx,
                    kinsn_resolver,
                    verifier,
                    &mut debug_traces,
                )?;
                if const_result.result.changed {
                    total_sites += const_result.result.sites_applied;
                }
                any_changed |= const_result.result.changed;

                let dce_pass = pm
                    .pass_at(pass_idx + 1)
                    .expect("checked DCE fixed-point pair");
                let dce_result = run_single_pass_with_verifier(
                    pm,
                    dce_pass,
                    program,
                    &mut cache,
                    ctx,
                    kinsn_resolver,
                    verifier,
                    &mut debug_traces,
                )?;
                if dce_result.result.changed {
                    total_sites += dce_result.result.sites_applied;
                }
                any_changed |= dce_result.result.changed;

                let pair_changed = const_result.result.changed || dce_result.result.changed;
                pass_results.push(const_result);
                pass_results.push(dce_result);

                if !pair_changed {
                    break;
                }
            }

            pass_idx += 2;
            continue;
        }

        let result = run_single_pass_with_verifier(
            pm,
            pass_ref,
            program,
            &mut cache,
            ctx,
            kinsn_resolver,
            verifier,
            &mut debug_traces,
        )?;
        if result.result.changed {
            total_sites += result.result.sites_applied;
        }
        any_changed |= result.result.changed;
        pass_results.push(result);
        pass_idx += 1;
    }

    Ok(VerifiedPipelineResult {
        pass_results,
        total_sites_applied: total_sites,
        program_changed: any_changed,
        debug_traces,
    })
}

pub(crate) fn run_with_profiling_and_verifier<V>(
    pm: &pass::PassManager,
    program: &mut pass::BpfProgram,
    ctx: &pass::PassContext,
    profiling: Option<&pass::ProfilingData>,
    kinsn_resolver: &FdArrayKinsnCallResolver,
    verifier: &mut V,
) -> Result<VerifiedPipelineResult>
where
    V: FnMut(&str, &pass::BpfProgram) -> Result<PassVerifyResult>,
{
    if let Some(data) = profiling {
        program.inject_profiling(data);
    }
    run_with_verifier(pm, program, ctx, kinsn_resolver, verifier)
}

fn run_single_pass_with_verifier<V>(
    pm: &pass::PassManager,
    pass_ref: &dyn pass::BpfPass,
    program: &mut pass::BpfProgram,
    cache: &mut pass::AnalysisCache,
    ctx: &pass::PassContext,
    kinsn_resolver: &FdArrayKinsnCallResolver,
    verifier: &mut V,
    debug_traces: &mut Vec<PassDebugTrace>,
) -> Result<VerifiedPassResult>
where
    V: FnMut(&str, &pass::BpfProgram) -> Result<PassVerifyResult>,
{
    pm.run_required_analyses(pass_ref, program, cache);

    let before_program = program.clone();
    let before_required_fds = kinsn_resolver.required_btf_fds()?;
    let before_insns = before_program.insns.clone();
    let insns_before = before_insns.len();
    let mut result = pass_ref.run(program, cache, ctx)?;
    result.insns_before = insns_before;
    result.insns_after = program.insns.len();

    let mut verify = PassVerifyResult::not_needed();
    let mut rollback = None;

    if result.changed {
        let tentative_after = insn::dump_bytecode_compact(&program.insns);
        verify = verifier(result.pass_name.as_str(), program)?;
        let keep_change = !verify.rejected_change();
        debug_traces.push(PassDebugTrace {
            pass_name: result.pass_name.clone(),
            changed: keep_change,
            verify: verify.clone(),
            bytecode_before: Some(insn::dump_bytecode_compact(&before_insns)),
            bytecode_after: Some(tentative_after),
        });

        if keep_change {
            program.verifier_states = verify.verifier_states.clone();
            cache.invalidate_all();
            program.sync_annotations();
        } else {
            *program = before_program;
            kinsn_resolver.restore_required_btf_fds(before_required_fds)?;
            result.changed = false;
            result.insns_after = program.insns.len();
            rollback = Some(PassRollbackResult::restored_pre_pass_snapshot(
                result.insns_after,
            ));
        }
    } else {
        debug_traces.push(PassDebugTrace {
            pass_name: result.pass_name.clone(),
            changed: false,
            verify: PassVerifyResult::not_needed(),
            bytecode_before: None,
            bytecode_after: None,
        });
    }

    Ok(VerifiedPassResult {
        result,
        verify,
        rollback,
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    fn exit_insn() -> insn::BpfInsn {
        insn::BpfInsn::new(insn::BPF_JMP | insn::BPF_EXIT, 0, 0, 0)
    }

    fn ctx_for_pass_manager(
        pm: &pass::PassManager,
        resolver: Arc<FdArrayKinsnCallResolver>,
    ) -> pass::PassContext {
        let mut ctx = pass::PassContext::test_default();
        ctx.kinsn_call_resolver = resolver;
        ctx.policy.enabled_passes = pm.pass_names().into_iter().map(str::to_string).collect();
        ctx
    }

    struct AppendNopPass;

    impl pass::BpfPass for AppendNopPass {
        fn name(&self) -> &str {
            "append_nop"
        }

        fn run(
            &self,
            program: &mut pass::BpfProgram,
            _analyses: &mut pass::AnalysisCache,
            _ctx: &pass::PassContext,
        ) -> Result<pass::PassResult> {
            program.insns.push(insn::BpfInsn::nop());
            Ok(pass::PassResult {
                pass_name: self.name().into(),
                changed: true,
                sites_applied: 1,
                ..Default::default()
            })
        }
    }

    struct KinsnAppendPass;

    impl pass::BpfPass for KinsnAppendPass {
        fn name(&self) -> &str {
            "kinsn_append"
        }

        fn run(
            &self,
            program: &mut pass::BpfProgram,
            _analyses: &mut pass::AnalysisCache,
            ctx: &pass::PassContext,
        ) -> Result<pass::PassResult> {
            let off = ctx
                .kinsn_call_resolver
                .call_off_for_target_name(&ctx.kinsn_registry, "bpf_rotate64")?;
            program
                .insns
                .push(insn::BpfInsn::call_kinsn_with_off(777, off));
            Ok(pass::PassResult {
                pass_name: self.name().into(),
                changed: true,
                sites_applied: 1,
                ..Default::default()
            })
        }
    }

    #[test]
    fn verifier_accept_refreshes_program_verifier_states() {
        let mut pm = pass::PassManager::new();
        pm.add_pass(AppendNopPass);
        let resolver = Arc::new(FdArrayKinsnCallResolver::new(HashMap::new()));
        let ctx = ctx_for_pass_manager(&pm, resolver.clone());
        let mut program = pass::BpfProgram::new(vec![exit_insn()]);

        let result = run_with_verifier(&pm, &mut program, &ctx, &resolver, &mut |_, _| {
            Ok(PassVerifyResult::accepted_with_verifier_states(vec![
                verifier_delta_state(0, 0),
                verifier_delta_state(1, 1),
            ]))
        })
        .unwrap();

        assert!(result.program_changed);
        assert_eq!(program.verifier_states.len(), 2);
        assert_eq!(program.verifier_states[1].pc, 1);
        assert_eq!(
            result.pass_results[0].verify.status,
            PassVerifyStatus::Accepted
        );
    }

    fn verifier_delta_state(pc: usize, r0: u64) -> pass::VerifierInsn {
        pass::VerifierInsn {
            pc,
            frame: 0,
            from_pc: None,
            kind: pass::VerifierInsnKind::InsnDeltaState,
            speculative: false,
            regs: HashMap::from([(
                0,
                pass::RegState {
                    reg_type: "scalar".to_string(),
                    value_width: pass::VerifierValueWidth::Bits64,
                    precise: true,
                    exact_value: Some(r0),
                    tnum: Some(pass::Tnum { value: r0, mask: 0 }),
                    range: pass::ScalarRange {
                        smin: Some(r0 as i64),
                        smax: Some(r0 as i64),
                        umin: Some(r0),
                        umax: Some(r0),
                        smin32: Some(r0 as u32 as i32),
                        smax32: Some(r0 as u32 as i32),
                        umin32: Some(r0 as u32),
                        umax32: Some(r0 as u32),
                    },
                    offset: None,
                    id: None,
                },
            )]),
            stack: HashMap::new(),
        }
    }

    #[test]
    fn verifier_rejection_rolls_back_program_and_fd_slots() {
        let mut pm = pass::PassManager::new();
        pm.add_pass(KinsnAppendPass);
        pm.add_pass(AppendNopPass);
        let resolver = Arc::new(FdArrayKinsnCallResolver::new(HashMap::from([(
            "bpf_rotate64".to_string(),
            42,
        )])));
        let mut ctx = ctx_for_pass_manager(&pm, resolver.clone());
        ctx.kinsn_registry.rotate64_btf_id = 777;
        let mut program = pass::BpfProgram::new(vec![exit_insn()]);

        let result = run_with_verifier(&pm, &mut program, &ctx, &resolver, &mut |pass_name, _| {
            if pass_name == "kinsn_append" {
                return Ok(PassVerifyResult::rejected("synthetic verifier rejection"));
            }
            Ok(PassVerifyResult::accepted())
        })
        .unwrap();

        assert!(result.program_changed);
        assert_eq!(program.insns.len(), 2);
        assert!(program.insns[0].is_exit());
        assert_eq!(program.insns[1], insn::BpfInsn::nop());
        assert_eq!(resolver.required_btf_fds().unwrap(), Vec::<RawFd>::new());
        assert_eq!(
            result.pass_results[0].rollback,
            Some(PassRollbackResult::restored_pre_pass_snapshot(1))
        );
        assert_eq!(
            result.pass_results[0].verify.status,
            PassVerifyStatus::Rejected
        );
        assert_eq!(
            result.pass_results[1].verify.status,
            PassVerifyStatus::Accepted
        );
    }
}
