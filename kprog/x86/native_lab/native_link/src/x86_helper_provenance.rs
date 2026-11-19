//! Helper identities are facts at a CFG point, not a lexical last assignment:
//! a GOT-loaded helper address reaches an indirect call or tail jump.
use super::*;
use std::collections::{BTreeSet, VecDeque};

#[derive(Clone, Debug, PartialEq, Eq, PartialOrd, Ord)]
enum Value { Symbol(String) }
type Values = BTreeSet<Value>;
type State = HashMap<Register, Values>;

#[derive(Clone, Default)]
pub(super) struct Calls {
    pub single: HashMap<u64, String>,
    pub tails: HashSet<u64>,
    pub branch_targets: HashMap<u64, Vec<u64>>,
}

fn indirect_register(insn: &Instruction) -> Option<Register> {
    if !matches!(insn.flow_control(), FlowControl::IndirectCall | FlowControl::IndirectBranch)
        || insn.op0_kind() != OpKind::Register { return None; }
    x86_gpr64_family(insn.op0_register())
}

pub(super) fn calls(elf: &object::File, sym: &SymInfo,
    got: &HashMap<LocalSiteKey, String>, helpers: &HashMap<String, u64>) -> Result<Calls> {
    let bytes = read_symbol_bytes(elf, sym)?;
    let tables = readonly_relocs::control_targets(elf, sym)?;
    let values = analyze(&bytes, sym.address, &tables, |insn| {
        if insn.mnemonic() != Mnemonic::Mov || insn.op0_kind() != OpKind::Register ||
            insn.op0_register().size() != 8 || insn.op1_kind() != OpKind::Memory ||
            !insn.is_ip_rel_memory_operand() { return None; }
        let name = got.get(&local_site_key(sym, insn.next_ip()-sym.address-4))?;
        (name.starts_with("bpf_") || helpers.contains_key(name) || matches!(name.as_str(), "memcpy" | "memset"))
            .then(|| Value::Symbol(name.clone()))
    })?;
    let tails: HashSet<_> = Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE)
        .into_iter().filter(|i| i.flow_control() == FlowControl::IndirectBranch)
        .map(|i| i.ip()).collect();
    let mut result=Calls { branch_targets: tables, ..Calls::default() };
    for (ip, alternatives) in values {
        let names: BTreeSet<String> = alternatives.iter().map(|Value::Symbol(name)| name.clone()).collect();
        if names.len()==1 {
            result.single.insert(ip-sym.address,names.into_iter().next().unwrap());
        }
        if tails.contains(&ip) { result.tails.insert(ip-sym.address); }
    }
    Ok(result)
}

fn analyze(bytes: &[u8], base: u64, tables: &HashMap<u64, Vec<u64>>,
    symbolic: impl Fn(&Instruction) -> Option<Value>) -> Result<HashMap<u64, Values>> {
    let insns: Vec<_> = Decoder::with_ip(64, bytes, base, DecoderOptions::NONE).into_iter().collect();
    if insns.iter().any(Instruction::is_invalid) { bail!("invalid instruction in helper CFG"); }
    let indices: HashMap<_, _> = insns.iter().enumerate().map(|(i, insn)| (insn.ip(), i)).collect();
    if insns.is_empty() { return Ok(HashMap::new()); }
    let mut states: Vec<Option<State>> = vec![None; insns.len()];
    states[0] = Some(HashMap::new());
    let mut queue = VecDeque::from([0]);
    let mut factory = InstructionInfoFactory::new();
    while let Some(i) = queue.pop_front() {
        let insn = &insns[i];
        let mut state = states[i].clone().ok_or_else(|| anyhow!("missing reachable helper state"))?;
        let mut assigned = symbolic(insn).map(|value| (insn.op0_register(), Values::from([value])));
        if insn.mnemonic() == Mnemonic::Mov && insn.op_count() == 2 && insn.op0_kind() == OpKind::Register {
            let width = insn.op0_register().size();
            if width == 4 || width == 8 {
                let reg = x86_gpr64_family(insn.op0_register());
                if width == 8 && insn.op1_kind() == OpKind::Register && insn.op1_register().size() == width {
                    if let Some(value) = x86_gpr64_family(insn.op1_register()).and_then(|r| state.get(&r)) {
                        assigned = reg.map(|reg| (reg, value.clone()));
                    }
                }
            }
        }
        for register in factory.info(insn).used_registers() {
            if matches!(register.access(), OpAccess::Write | OpAccess::CondWrite | OpAccess::ReadWrite | OpAccess::ReadCondWrite) {
                if let Some(reg) = x86_gpr64_family(register.register()) { state.remove(&reg); }
            }
        }
        if matches!(insn.flow_control(), FlowControl::Call | FlowControl::IndirectCall) {
            clear_x86_call_clobbered_registers(&mut state);
        }
        if let Some((reg, value)) = assigned { state.insert(reg, value); }
        let mut successors = Vec::new();
        match insn.flow_control() {
            FlowControl::Next | FlowControl::Call | FlowControl::IndirectCall => successors.push(insn.next_ip()),
            FlowControl::ConditionalBranch => { successors.push(insn.next_ip()); successors.push(insn.near_branch_target()); }
            FlowControl::UnconditionalBranch => successors.push(insn.near_branch_target()),
            FlowControl::IndirectBranch => {
                if let Some(targets) = tables.get(&insn.ip()) { successors.extend(targets); }
                else if !indirect_register(insn).is_some_and(|reg| state.contains_key(&reg)) {
                    successors.extend(insns.iter().map(Instruction::ip));
                }
            }
            _ => {}
        }
        for target in successors {
            let Some(&j) = indices.get(&target) else {
                if target >= base && target < base+bytes.len() as u64 { bail!("helper CFG branch to {:#x} from {:#x} targets an interior byte", target, insn.ip()); }
                continue;
            };
            let changed = if let Some(previous) = &mut states[j] {
                let old = previous.clone();
                previous.retain(|reg, values| {
                    if let Some(incoming)=state.get(reg) {
                        values.extend(incoming.iter().cloned());true
                    } else { false }
                });
                *previous != old
            } else { states[j] = Some(state.clone()); true };
            if changed { queue.push_back(j); }
        }
    }
    Ok(insns.iter().enumerate().filter_map(|(i, insn)| {
        if tables.contains_key(&insn.ip()) { return None; }
        let reg = indirect_register(insn)?;
        states[i].as_ref()?.get(&reg).cloned().map(|value| (insn.ip(), value))
    }).collect())
}
