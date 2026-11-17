#!/usr/bin/env python3
"""Use already resolved code-table edges in the existing constant analysis."""
import argparse
import difflib
from pathlib import Path

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--apply', action='store_true')
args = p.parse_args()
root = Path('/workspaces/repository/kprog/x86/native_lab/native_link/src')
prepared = []


def edit(name, pairs):
    path = root/name
    before = path.read_text()
    after = before
    for old, new, count in pairs:
        assert after.count(old) == count, (name, old, after.count(old), count)
        after = after.replace(old, new)
    prepared.append((path, before, after))


edit('x86_memory.rs', [
    ('    address: u64,\n) -> Result<HashMap<u64, HashMap<Register, u64>>> {',
     '    address: u64,\n    branch_targets: &HashMap<u64, Vec<u64>>,\n) -> Result<HashMap<u64, HashMap<Register, u64>>> {', 1),
    ('    if instructions.iter().any(|i| {\n        i.flow_control() == FlowControl::IndirectBranch',
     '''    let indices: HashMap<_, _> = instructions.iter().enumerate()
        .map(|(n,i)| (i.ip(),n)).collect();
    if instructions.iter().any(|i| {
        (i.flow_control() == FlowControl::IndirectBranch
            && !branch_targets.get(&i.ip()).is_some_and(|targets|
                !targets.is_empty() && targets.iter().all(|target| indices.contains_key(target))))''', 1),
    ('''    let indices: HashMap<_, _> = instructions
        .iter()
        .enumerate()
        .map(|(n, i)| (i.ip(), n))
        .collect();
''', '', 1),
    ('        let mut successors = Vec::new();',
     '''        let mut successors = Vec::new();
        if i.flow_control() == FlowControl::IndirectBranch {
            for target in &branch_targets[&i.ip()] {
                successors.push(indices[target]);
            }
        }''', 1),
    ('constants(&branch, 0)?', 'constants(&branch, 0, &HashMap::new())?', 1),
    ('constants(&equal, 0)?', 'constants(&equal, 0, &HashMap::new())?', 1),
    ('constants(&partial, 0)?', 'constants(&partial, 0, &HashMap::new())?', 1),
    ('constants(&looped, 0)?', 'constants(&looped, 0, &HashMap::new())?', 1),
    ('constants(&indirect, 0)?', 'constants(&indirect, 0, &HashMap::new())?', 1),
    ('constants(&local_call, 0)?', 'constants(&local_call, 0, &HashMap::new())?', 1),
    ('    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]\n    mod execution {',
     '''    #[test]
    fn constant_counts_meet_all_resolved_table_edges_at_nonzero_addresses() -> Result<()> {
        // The indirect jump reaches either size8 or size16, then one call.
        // Ignoring one edge would specialize that call to the wrong count.
        let mut bytes=vec![0xbe,8,0,0,0,0xff,0xe0,
            0xbe,8,0,0,0,0xeb,5,0xbe,16,0,0,0,0xe8,0,0,0,0,0xc3];
        let base=0x4000;
        let edges=HashMap::from([(base+5,vec![base+7,base+14])]);
        let facts=constants(&bytes,base,&edges)?;
        assert!(!facts[&19].contains_key(&Register::RSI));
        bytes[15]=8;
        assert_eq!(constants(&bytes,base,&edges)?[&19].get(&Register::RSI),Some(&8));
        assert!(constants(&bytes,base,&HashMap::new())?.is_empty());
        let invalid=HashMap::from([(base+5,vec![base+7,base+15])]);
        assert!(constants(&bytes,base,&invalid)?.is_empty(),"mid-instruction edge is not a fact");
        Ok(())
    }

    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    mod execution {''', 1),
])
edit('x86.rs', [
    ('''        let memory_constants = memory::constants(&bytes, sym.address)?;
        let helper_calls = if symbol_key(sym) == symbol_key(entry) { entry_helpers.clone() }
            else { helper_provenance::calls(elf, sym, &got_relocations, helper_addrs)? };''',
     '''        let helper_calls = if symbol_key(sym) == symbol_key(entry) { entry_helpers.clone() }
            else { helper_provenance::calls(elf, sym, &got_relocations, helper_addrs)? };
        let memory_constants = memory::constants(&bytes, sym.address, &helper_calls.branch_targets)?;''', 1),
])

for path, before, after in prepared:
    if args.apply:
        path.write_text(after)
    else:
        print(''.join(difflib.unified_diff(before.splitlines(True), after.splitlines(True),
                                        fromfile=str(path), tofile=str(path))), end='')
