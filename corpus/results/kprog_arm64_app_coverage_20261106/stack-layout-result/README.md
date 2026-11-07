# ARM stack representation: frozen diagnostic result

Compile-time constant indexes retain their constants; dynamic/invalid indexes
retain the existing empty tied-register opacity. The byte accesses, widths,
native branches and architectural values are unchanged. The payload load uses
an equivalent switch over STACK/RETURN tags. There is no emitted bounds check.

All 23 actual BCC source candidates compile, and the negative artifact plus all 29
micro artifacts rebuild. The inherited representation's opensnoop sys_exit
maximum negative frame-pointer offset changes from 880 to 472 bytes. Tcplife
remains 584 bytes. These are disassembled stack offsets, not verifier acceptance.
The private v28 conditional-payload-store trial leaves both offsets unchanged
and is not promoted.

Checks against the candidate snapshot:
- 11,200 memory byte/tag cases pass under AddressSanitizer/UndefinedBehaviorSanitizer.
- Existing routing/helper hosts pass 6,401 + 6,401 + 21,688 + 1,152 + 192 + 154 cases.
- Full-system QEMU accepts fixed/dynamic accesses; uninitialized access is
  load-only and accepted by the existing privileged kernel contract.
- Four below/above/crossing/huge stack-access fixtures are verifier-rejected
  without native execution.
- Both existing entry-ABI controls match source/simulator/bound-native:
  result 37, retval 2, generation 1.

The raw archive includes compiler records, exact frozen simulator/generated
headers, BCC C/native/proof objects, all QEMU verifier logs, and control manifests.
The production include path is rewritten only for the self-contained snapshot.
The complete formal check is queued behind V's sole full check. Production
header changes remain uncommitted until validation. BCC v27 real app startup is
running separately; tcplife stack use and vfsstat exclusive-loop acceptance
remain open. No six-application completion or performance result is claimed.

Rebuild the diagnostic snapshot using the archived Makefile and paths:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile PHASE=bcc-layout-v27 COMPILE_ARGS='0 23 1200 1 8192'
make -C kprog/arm64 micro-proofs-build PROOF_BUILD_DIR=/workspaces/repository/kprog/arm64/build/layout-v27-micro NEGATIVE_PROOF_BUILD_DIR=/workspaces/repository/kprog/arm64/build/layout-v27-negative

```

Use fresh phase/build directories for a new compiler or simulator snapshot;
completed records preserve the original attempt.
