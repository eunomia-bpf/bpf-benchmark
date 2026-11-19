"""Prepare post-verification erasure of verifier-rejected interpreter paths."""
from pathlib import Path
import difflib
path=Path('kprog/x86/compile_sim_ir.cpp');old=path.read_text()
needle='''      // Both unresolved dispatch and architectural faults are verifier errors
      // if reachable. Preserve the fault in the LTO output, never a return value.
      b.CreateCall(Intrinsic::getDeclaration(m.get(),Intrinsic::trap));'''
replacement='''      // The service invokes native compilation only after stock B acceptance.
      // These invalid B paths were proved unreachable; expose that fact to
      // native optimization instead of retaining verifier-only runtime traps.
      b.CreateAssumption(b.getFalse());'''
assert needle in old
new=old.replace(needle,replacement,1)
Path('kprog/results/native-verified-paths-20261119/implementation.patch').write_text(''.join(
 difflib.unified_diff(old.splitlines(True),new.splitlines(True),fromfile='a/'+str(path),tofile='b/'+str(path))))
