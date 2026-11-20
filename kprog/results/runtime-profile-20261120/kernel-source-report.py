"""Keep the source kernel-probe correction, including the failing control."""
import json
from pathlib import Path
import tarfile

here=Path(__file__).resolve().parent
base=Path('/workspaces/kprog-raw/perf/runtime-profile-20261120')
before=base/'source-kernel-before-20261120T035937Z'
after=base/'kernel-source-20261120T040024Z'
current=json.loads((after/'source-generation.json').read_text())
links=json.loads((after/'source-links.json').read_text())
report=dict(correction='81f126f69',fixture='5f822164b',before=str(before),after=str(after),
    before_make_exit=int((before/'exit-code').read_text()),
    after_make_exit=int((after/'exit-code').read_text()),
    after_entries=[dict(symbol=row['symbol'],status=row['status']) for row in current],
    host_copy_controls=99,host_string_forwarding_controls=51,
    proof_and_kernel_links=[dict(returncode=row['returncode'],command=row['command']) for row in links],
    source_evidence=[
        'include/linux/bpf.h:bpf_probe_read_kernel_common returns the nofault error and zeroes the full destination on error',
        'kernel/trace/bpf_trace.c:bpf_probe_read_kernel_str_common returns strncpy_from_kernel_nofault result and zeroes the full destination on error',
        'arch/x86/net/bpf_jit_comp.c:ex_handler_bpf resumes a faulting load with its destination register cleared, not a helper error result'],
    behavior='Source retains helper identities through B; existing late native C byte-copy common wrapper remains on; strings call the existing kernel helper',
    tools='Existing installed compiler/linker and Clang only; no toolchain change or tool build',
    scope='Controlled source ABI/return forwarding, byte-copy provider error zeroing, real-symbol links and P-to-B generation. Baseline provider-routing failure is not a kernel fault experiment. Stock/app fault execution, new P publication and application speed remain unmeasured.')
(here/'kernel-source-result.json').write_text(json.dumps(report,indent=2)+'\n')
with tarfile.open(here/'kernel-source-evidence.tar.gz','w:gz') as archive:
    for raw in [before,after]:
        archive.add(raw,arcname=raw.name)
print([(row['symbol'],row['status']) for row in current])
