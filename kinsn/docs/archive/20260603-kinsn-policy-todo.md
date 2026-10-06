# kinsn x86 policy todo

Current rule: bpfopt and the backend default to all-force kinsn lowering. App
YAML only narrows policy after measured performance evidence or for explicit
experiment isolation; it must not hide verifier/load failures.

- [x] Enable LEA under private-stack x86 JIT by mapping BPF_REG_10 to native
  R9 when `prog->aux->priv_stack_ptr` is set.
- [x] Remove temporary code-gate style selector defaults from bpfopt; default
  kinsn mode is all-force.
- [x] Smoke katran and tracee with all-force kinsn on x86 KVM.
- [x] Validate the tracee per-program policy smoke on x86 KVM.
- [x] Test OTEL cond_select-only isolation. It fails verifier/load on
  `perf_unwind_dot` with `R1 unbounded memory access`, so this is not a valid
  policy and must not be papered over by disabling that program.
- [ ] Run all six x86 KVM corpus apps with kinsn policy using the
  eval_native corpus method.
- [ ] Run x86 micro kinsn family coverage/performance with the same pass mode
  accounting.
- [ ] Generate `docs/figures/eval-kinsn-*.png`.
- [ ] Rewrite `docs/eval_kinsn.md` with artifact paths, raw apply coverage,
  post-hoc ratios, and caveats.
