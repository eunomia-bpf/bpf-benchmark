# Public Cilium metadata and native frame contract

Source: ed85c9c02, kernel 83e0fabe355d. Diagnostic include correction:
67a6f1134. This implements the source portion of todo section 0 item 1.

The existing BTF answer generator now supplies the public cb offset as
sk_buff.cb + qdisc_skb_cb.data and the classid offset from the same kernel.
The native view places its five public words at that location, preserves
the other field offsets and performs the intended classid clear.

The native image's existing callee_saved_mask now controls the kernel saves
and native tail pops. The direct loader writes that mask inside its existing
upload transaction; the registered path already carries it in the image.
Native ABI-preserving bodies carry mask zero and retain their own C saves.
The unused stub parameter and its old sidecar comment were removed.

Host subset, CPUs 16–19 with a 12 GiB address-space limit:

- Raw: /workspaces/kprog-raw/perf/20261116-cilium-cb-frame/retry1.
- Controller 1819180 completed at 2026-11-16T17:41:32Z, exit 0.
- The two-view layout fixture passes: cb at 48, classid at 46. It checks all
  sk_buff bytes, including preservation of the surrounding qdisc fields.
- Linker suite: 48 passed, 3 existing ignored. The existing production tail
  fixture now also checks that mask-zero images pop zero outer saved registers.
- Loader build passes; all seven Cilium native objects and their proof
  markers rebuild through the existing producer target.

The first successful host run built the linker test binary. A subsequent
production-linker build refreshes the normal CLI before the next load-plan
replay; its progress is retained in retry1/production-linker-build.log.

The first diagnostic run stopped at a libc/kernel wchar_t typedef collision
in the fixture. Its complete output remains in the parent raw directory.
The correction uses the existing physical-layout tool's header convention.

Rebuilt cil_from_container has 1274 P bytes; the retained pre-publication
replay reports 1268 for that native symbol. The six added bytes implement
the intended 16-bit classid store. Actual cb stores now address 48, 52, 56,
60 and 64; classid addresses 46. Mask-zero kernel wrapper code removes
four push/pop pairs, fourteen bytes by instruction accounting. These are
static source/P observations, separate from installed image bytes and timing.

The timing image remains 6641a7e1 while C runs its breadth round. The sole
kernel source advances to 83e0fabe355d; the in-place kernel build, module/image
publication, actual cil_from_container BPF_PROG_TEST_RUN comparison and
per-call/installed-byte measurement follow that round under the image lock.
The frozen benchmark entry and settings stay unchanged. All existing LTO
pieces remain together; the operator's performance/size targets remain open.
