"""Isolate x86 map call selection from unrelated shared working changes."""
import difflib,sys
from pathlib import Path
STATE=Path('/workspaces/.agent-state/kprog-lanes/C/map-identity-source')
HERE=Path(__file__).resolve().parent
TESTS='''    #[test]
    fn unknown_lookup_map_keeps_generic_helper_and_named_sites_available() -> Result<()> {
        let mut site = test_lookup_site("stats", 0x1000);
        site.kind = LookupKind::PerCpuArray;
        site.max_entries = 1024;
        let sites = vec![site];
        let mut used = vec![false];
        let selected = select_lookup_site(&sites, &HashMap::new(), &mut used,
            0, None, "balancer_ingress", 0x2000)?;
        assert!(matches!(selected.2.kind, LookupKind::Call));
        assert_eq!(selected.2.target_addr, 0x2000);
        assert_eq!(selected.1, None);
        assert_eq!(used, vec![false]);
        let named = select_lookup_site(&sites, &HashMap::new(), &mut used,
            1, Some("stats"), "balancer_ingress", 0x2000)?;
        assert!(matches!(named.2.kind, LookupKind::PerCpuArray));
        Ok(())
    }

    #[test]
    fn unknown_lookup_map_requires_real_generic_helper_target() {
        let sites = vec![test_lookup_site("stats", 0x1000)];
        let mut used = vec![false];
        assert!(select_lookup_site(&sites, &HashMap::new(), &mut used,
            0, None, "entry", 0).is_err());
        assert_eq!(used, vec![false]);
    }

    #[test]
    fn unknown_update_map_does_not_borrow_named_site_by_order() -> Result<()> {
        let sites = vec![test_update_site("stats", 0x1000)];
        let mut used = vec![false];
        assert_eq!(select_update_site(&sites, &mut used, 0, None)?, None);
        assert_eq!(used, vec![false]);
        assert_eq!(select_update_site(&sites, &mut used, 1, Some("stats"))?,
            Some(("0".to_string(), 0)));
        Ok(())
    }

    #[test]
    fn unmatched_update_map_does_not_borrow_another_maps_site() -> Result<()> {
        let sites = vec![test_update_site("stats", 0x1000)];
        let mut used = vec![false];
        assert_eq!(select_update_site(&sites, &mut used, 0, Some("fallback_cache"))?, None);
        assert_eq!(used, vec![false]);
        Ok(())
    }

'''
for tag,root in [('current',STATE/'current/kprog/x86/native_lab/native_link'),('runtime',STATE/'runtime')]:
 before=(HERE/(tag+'-before.rs')).read_text();candidate=before
 if sys.argv[1]=='fixed':
  bad='''    if let Some((idx, spec)) = lookup_sites.iter().enumerate().find(|(idx, _)| !used[*idx]) {
        used[idx] = true;
        return Ok((idx.to_string(), Some(idx), spec.clone()));
    }
'''
  assert candidate.count(bad)==1
  candidate=candidate.replace(bad,'''    // Source BPF and native compiler call orders are not map identities.
    // An unresolved runtime map must retain the original generic helper.
''')
  bad='''    if native_call_index < update_sites.len() && !used[native_call_index] {
        used[native_call_index] = true;
        return Ok(Some((native_call_index.to_string(), native_call_index)));
    }
'''
  assert candidate.count(bad)==1;candidate=candidate.replace(bad,'')
  bad='''    Ok(update_sites
        .iter()
        .enumerate()
        .find(|(idx, _)| !used[*idx])
        .map(|(idx, _)| {
            used[idx] = true;
            (idx.to_string(), idx)
        }))'''
  assert candidate.count(bad)==1;candidate=candidate.replace(bad,'''    // Returning None leaves the original map_update_elem helper call intact.
    // Never specialize a dynamic or unmatched map using another call's shape.
    Ok(None)''')
 anchor='    #[test]\n    fn helper_call_reloc_slot_encodes_only_call_rel32()'
 assert candidate.count(anchor)==1;candidate=candidate.replace(anchor,TESTS+anchor)
 (root/'src/x86.rs').write_text(candidate)
 if sys.argv[1]=='fixed':
  patch=''.join(difflib.unified_diff(before.splitlines(True),candidate.splitlines(True),fromfile='a/kprog/x86/native_lab/native_link/src/x86.rs',tofile='b/kprog/x86/native_lab/native_link/src/x86.rs'))
  (HERE/(tag+'-candidate.patch')).write_text(patch)
