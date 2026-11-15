# Normal boot-kernel LTO plan

2026-11-15, lane PERF. Source: 73ef21ede, bde7aae19, 5ffcf3d10,
971dc5f25, d50c6994a, d34ba357f; paired publication: 18b5225fb,
c2ed8c28f. All pushed to master.

The loader now supplies one structured `kernel_layout` from the boot kernel's
BTF and kallsyms. Its exact serialization also enters the image cache key.
Kernel linking uses ARRAY, hash, LPM and probe-read facts together. Four layout
CLI selectors, the optional load-site ABI selector and six candidate shell
wrappers are deleted. Recovery metadata is emitted with the ABI. Proof-mode
symbolic linking remains a distinct operation.

The authoritative functional capture is
`/workspaces/kprog-raw/perf/20261115-normal-layout-plan/boot-ready`:
2 vCPUs, 4 GiB guest RAM, CPUs 16–17, 16 GiB process address-space cap,
image shared lock, no timing lock. It ended successfully. The production C++
fact collector ran inside the sole boot kernel. Host verification in
`authoritative/job` also exited zero:

| Check | Result |
| --- | --- |
| Production C++ facts vs independent existing C BTF resolver | 38/38 equal |
| Live and canonical ELF BTF | both `87b89a9770178d2b4e290b2a00f8bbdd681be60e3817de657af0b035eeb71f90` |
| Full loader syntax | pass |
| Actual clang → proof → kernel-link map fixtures | 13 executions pass |
| Relative code table | 8 targets, 320 native + 320 shared-simulator executions pass |
| Existing private-state counterexamples | 2 refusals retained |

The map cases include named ARRAY, dynamic ARRAY using real boot-layout
offsets, and a non-ARRAY helper continuation preserving arguments and return.
The ordinary helper-shape suite separately passed six adjacent/separated/
hoisted immediate/PLT cases (`call-shapes-fixed/job`). Rust source tests
passed 33 cases with one existing ignored test before the incidents below.
The explicit normal ELF used for authoritative host checks is the existing
Cargo deps product `native_link-89e6cdf9b2bb753e`, SHA256
`31806730e4d268e89b51806d2e0207812dc5e1b869e974d6f3304e5f90169955`.

Two integration mistakes occurred and are retained in the evidence:

1. Our test Makefile let GNU Make infer `cc vmlinux.o -o vmlinux`. The PIE
   link failed and Make deleted the canonical ELF. The boot image and running
   guests remained unchanged. The initial repair from a module-build
   `vmlinux.unstripped` restored the wrong metadata, so its 38/38 check was
   against module data and is superseded. We then extracted the unchanged
   boot image with the kernel's own extractor. Canonical ELF SHA256 is exactly
   the prior `f3743c05960fc700e29f31e0035a23cdd4b2500d5e6e7542984d5f6fba75babe`,
   build ID `d5f06faf5af883d24ba16a9687f8fadb4de81b98`. Both repair receipts
   and the failed Make log are included. The test Makefile disables builtin
   rules. Independent final checks use live boot kallsyms, not module System.map.
   Historical layout scalars match; seven historical symbol addresses differ.
2. Rebuilding the repository linker while the old census loader still used
   its path caused body 93/request 39 to fail on the retired
   `--abi-load-sites` argument. This is an invocation mismatch, not a stock
   verifier rejection. To preserve that already-running job, the deployment
   path temporarily points to its existing retained all-LTO payload; no
   compatibility branch was added to source. Subsequent bodies 94–98 installed.
   All production linker build targets now take image EX and unlink that alias
   before Cargo publication, so they cannot overwrite the retained raw input.

Paired normal loader/linker/bounds publication is queued as PID 783752,
waiting for image EX behind existing guest consumers. It has not published
yet. Functional probe, map and shared-ARRAY jobs 785732/785733/785734 wait for
that process, then take image SH on CPUs 16–19; each has a 16 GiB address-space
cap. Their queue/preflight logs remain in the raw directory. The publication
records its actual source HEAD and tool hashes when it executes. It updates
the one existing base; it does not rebuild the kernel or runtime image.

No whole-app, stock acceptance of the table fixture, application speed or
code-size gain is claimed. Table stock/checked-native acceptance and actual
normal-base functional results remain open. All evidence is collected by
`../collect_normal_lto_step.py`; raw archives, inputs and failed attempts stay.
