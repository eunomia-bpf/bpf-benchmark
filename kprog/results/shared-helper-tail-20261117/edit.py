#!/usr/bin/env python3
"""Preview a shared-leaf tail-transfer fix; --apply edits the sole tree.

Apply after the pending batch-2 snapshot, then run actual host validation.
"""
import argparse
import difflib
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--apply', action='store_true')
args = parser.parse_args()
root = Path('/workspaces/repository/kprog/x86/native_lab/native_link/src')
changes = {
    'x86_probe_read.rs': [
        ('''        if blob.get(site..site+5) != Some(X86_HELPER_CALL_REL32_SLOT.as_slice()) {
            bail!("probe-read call at {site:#x} lost its E8 helper slot");
        }''', '''        if !matches!(blob.get(site..site+5), Some([0xe8 | 0xe9, 0, 0, 0, 0])) {
            bail!("helper branch at {site:#x} lost its rel32 slot");
        }'''),
        ('    fn fixture() -> RuntimeProbeReadLayout {', '''    // A helper tail jump must stay a jump: adding a CALL adds a return frame.
    #[test]
    fn shared_leaf_redirect_preserves_call_and_tail_opcodes() -> Result<()> {
        let mut blob=vec![0xe8,0,0,0,0,0xe9,0,0,0,0,0xc3];
        redirect(&mut blob,&[0,5],10)?;
        for (site,opcode) in [(0usize,0xe8),(5,0xe9)] {
            assert_eq!(blob[site],opcode);
            let rel=i32::from_le_bytes(blob[site+1..site+5].try_into()?);
            assert_eq!(site as i64+5+i64::from(rel),10);
        }
        assert_eq!(blob[10],0xc3);
        Ok(())
    }

    fn fixture() -> RuntimeProbeReadLayout {'''),
    ],
    'x86_ktime.rs': [
        ('''    for &site in &calls {
        if blob.get(site..site+5) != Some(X86_HELPER_CALL_REL32_SLOT.as_slice()) {
            bail!("ktime call at {site:#x} lost its E8 helper slot");
        }
        patch_x86_rel32(blob, site+1, start)?;
    }''', '    probe_read::redirect(blob, &calls, start)?;'),
        ('let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(2); blob.push(0xc3);',
         'let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(2); blob[5]=0xe9; blob.push(0xc3);'),
        ('        for offset in [0usize, 5] {\n',
         '        assert_eq!((blob[0],blob[5]),(0xe8,0xe9));\n        for offset in [0usize, 5] {\n'),
    ],
    'x86_task.rs': [
        ('let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(2); blob.push(0xc3);',
         'let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(2); blob[5]=0xe9; blob.push(0xc3);'),
        ('        for offset in [0usize, 5] {\n',
         '        assert_eq!((blob[0],blob[5]),(0xe8,0xe9));\n        for offset in [0usize, 5] {\n'),
    ],
    'x86_runtime_array.rs': [
        ('''    for &site in &sites {
        if blob.get(site..site+5) != Some(X86_HELPER_CALL_REL32_SLOT.as_slice()) {
            bail!("shared ARRAY call at {site:#x} lost its helper slot");
        }
        let disp = i32::try_from(start as i64 - (site + 5) as i64)?;
        blob[site+1..site+5].copy_from_slice(&disp.to_le_bytes());
    }''', '    probe_read::redirect(blob, &sites, start)?;'),
        ('let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(3);',
         'let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(3); blob[5]=0xe9;'),
        ('        for site in [0usize, 5] {\n',
         '        assert_eq!((blob[0],blob[5]),(0xe8,0xe9));\n        for site in [0usize, 5] {\n'),
    ],
    'x86_lpm_lookup.rs': [
        ('''    for site in calls {
        if blob.get(site..site+5)!=Some(X86_HELPER_CALL_REL32_SLOT.as_slice()){bail!("LPM LTO lost generic-helper E8 slot");}
        patch_x86_rel32(blob,site+1,start)?;
    }''', '    probe_read::redirect(blob,&calls,start)?;'),
        ('        println!("{}",String::from_utf8_lossy(&run.stdout));Ok(())',
         '''        println!("{}",String::from_utf8_lossy(&run.stdout));
        let mut blob=vec![0xe8,0,0,0,0,0xe9,0,0,0,0,0xc3];
        let mut relocs=vec![RelocRecord{offset:0,kind:1,target:0x1234},
                            RelocRecord{offset:5,kind:1,target:0x1234}];
        let range=share(&mut blob,&mut relocs,&layout,0x1234)?.expect("shared LPM");
        assert_eq!((blob[0],blob[5]),(0xe8,0xe9));
        for site in [0usize,5] {
            let rel=i32::from_le_bytes(blob[site+1..site+5].try_into()?);
            assert_eq!(site as i64+5+i64::from(rel),range.0 as i64);
        }
        assert_eq!(relocs.len(),1,"only the existing generic kernel call remains");
        assert_eq!(&blob[relocs[0].offset as usize..relocs[0].offset as usize+5],
                   X86_HELPER_CALL_REL32_SLOT.as_slice());
        Ok(())'''),
    ],
}
prepared = []
for name, pairs in changes.items():
    path = root / name
    original = path.read_text()
    text = original
    for old, new in pairs:
        assert text.count(old) == 1, (name, old, text.count(old))
        text = text.replace(old, new)
    prepared.append((path, original, text))
for path, original, text in prepared:
    if args.apply:
        path.write_text(text)
    else:
        print(''.join(difflib.unified_diff(original.splitlines(True), text.splitlines(True),
                                        fromfile=str(path), tofile=str(path))), end='')
