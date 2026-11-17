#!/usr/bin/env python3
"""One-shot named-map meet regression and existing-analysis CFG propagation."""
from pathlib import Path
import sys
p=Path('kprog/x86/native_lab/native_link/src/x86_known_maps.rs');s=p.read_text()
if sys.argv[1]=='test':
    anchor='''    #[test]
    fn joins_partial_writes_and_arithmetic_erase_provenance() -> Result<()> {'''
    test='''    #[test]
    fn map_bindings_meet_across_branches_and_loops() -> Result<()> {
        // Both edges retain the same preceding identity, even at a zero-length join.
        let names=track(&[0x48,0x8b,0x3d,0,0,0,0,0x74,0,0xe8,0,0,0,0,0xc3])?;
        assert_eq!(names.get(&9).map(String::as_str),Some("map"));
        // Either arm establishes its own map. Only equal named identities meet.
        let bytes=[0x85,0xff,0x74,9,0x48,0x8b,0x3d,0,0,0,0,0xeb,7,
                   0x48,0x8b,0x3d,0,0,0,0,0xe8,0,0,0,0,0xc3];
        let sym=SymInfo{name:"entry".into(),section_index:object::SectionIndex(1),address:0,size:bytes.len() as u64};
        for same in [true,false] {
            let got=HashMap::from([(local_site_key(&sym,7),"map".into()),
                (local_site_key(&sym,16),if same {"map".into()}else{"other".into()})]);
            let names=arguments(&bytes,&sym,&got,&HashMap::new(),
                &HashMap::from([("map".into(),0x1000),("other".into(),0x2000)]),&HashMap::new())?;
            assert_eq!(names.get(&20).map(String::as_str),if same {Some("map")}else{None});
        }
        // A callee-saved map survives a loop only if no backedge destroys it.
        for kill in [false,true] {
            let mut bytes=vec![0x4c,0x8b,0x25,0,0,0,0,0x4c,0x89,0xe7,0xe8,0,0,0,0];
            if kill {bytes.extend_from_slice(&[0x45,0x31,0xe4]);}
            bytes.extend_from_slice(&[0x85,0xc0,0x75,if kill {0xf1}else{0xf4},0xc3]);
            let names=track(&bytes)?;
            assert_eq!(names.get(&10).map(String::as_str),if kill {None}else{Some("map")});
        }
        // A first-iteration fact is not a fixed-point fact for caller-saved RDI.
        let names=track(&[0x48,0x8b,0x3d,0,0,0,0,0xe8,0,0,0,0,0x85,0xc0,0x75,0xf7,0xc3])?;
        assert!(!names.contains_key(&7));
        println!("named map CFG: agreeing/disagreeing joins, callee/caller loop clobbers PASS");
        Ok(())
    }

'''
    assert s.count(anchor)==1;s=s.replace(anchor,test+anchor)
    old='''            vec![0x74,0, 0xe8,0,0,0,0], // branch enters call directly
'''
    assert s.count(old)==1;s=s.replace(old,'')
elif sys.argv[1]=='fix':
    s=s.replace('''//! Conservative map-pointer provenance within native basic blocks.
//!
//! Facts start only at named map GOT loads. Joins, arithmetic, partial writes,
//! memory reloads and caller-clobbered registers cannot inherit a map identity.''',
'''//! Named map-pointer provenance. Every reachable predecessor must agree at a join.
//! Arithmetic, partial writes, memory reloads and caller-clobbered registers lose identity.''')
    start=s.index('    let mut boundaries = HashSet::from([sym.address]);')
    end=s.index('        let local_ip = insn.ip() - sym.address;',start)
    new='''    let indices:HashMap<_,_>=instructions.iter().enumerate().map(|(n,i)|(i.ip(),n)).collect();
    let mut states:Vec<Option<HashMap<Register,String>>>=vec![None;instructions.len()];
    if states.is_empty() {return Ok(HashMap::new());}
    states[0]=Some(HashMap::new());
    let mut queue=std::collections::VecDeque::from([0]);
    let mut result=HashMap::new();
    let mut factory=InstructionInfoFactory::new();
    while let Some(index)=queue.pop_front() {
        let insn=&instructions[index];
        let mut registers=states[index].as_ref().expect("queued map state").clone();
'''
    s=s[:start]+new+s[end:]
    old='''            if let Some(name) = registers.get(&Register::RDI) {
                result.insert(local_ip, name.clone());
            }
'''
    new='''            if let Some(name) = registers.get(&Register::RDI) {
                result.insert(local_ip, name.clone());
            } else { result.remove(&local_ip); }
'''
    assert s.count(old)==1;s=s.replace(old,new)
    old='''        if let Some((reg, name)) = assigned { registers.insert(reg, name); }
    }
    Ok(result)'''
    new='''        if let Some((reg, name)) = assigned { registers.insert(reg, name); }
        let mut successors=Vec::new();
        if insn.flow_control()==FlowControl::IndirectBranch {
            for target in &branch_targets[&insn.ip()] {
                if let Some(&n)=indices.get(target) {successors.push(n);}
            }
        }
        if matches!(insn.flow_control(),FlowControl::UnconditionalBranch|FlowControl::ConditionalBranch) {
            if let Some(&n)=indices.get(&insn.near_branch_target()) {successors.push(n);}
        }
        if matches!(insn.flow_control(),FlowControl::Next|FlowControl::Call|
            FlowControl::IndirectCall|FlowControl::ConditionalBranch) && index+1<instructions.len() {
            successors.push(index+1);
        }
        for n in successors {
            let merged=match &states[n] {
                None=>registers.clone(),
                Some(old)=>old.iter().filter(|(r,name)|registers.get(r)==Some(*name))
                    .map(|(&r,name)|(r,name.clone())).collect(),
            };
            if states[n].as_ref()!=Some(&merged) {states[n]=Some(merged);queue.push_back(n);}
        }
    }
    Ok(result)'''
    assert s.count(old)==1;s=s.replace(old,new)
else:raise ValueError('Use test or fix')
p.write_text(s)
