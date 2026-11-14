# Whole-word spill value preservation

The corrected transform completed 1,060 executions of each of the original and
lowered programs on the sole stock kernel. Both matched an independent C
arithmetic reference. The cases comprise all 36 pairs of six boundary values,
including signed-boundary bit patterns and addition overflow, plus 1,024
deterministic pseudorandom pairs.

The MIR fixture stores both input halves, crosses a basic-block boundary with
a live register, reloads and updates both halves, then combines them with the
live register. `scalar_spill_values.c` supplies skb mark/priority through
`bpf_prog_test_run_opts` and checks each return value. LLVM machine verification
also completed for both objects. The command was:

```sh
make -f kprog/test/scalar-spill-precision.mk values-run \
  OUTPUT=/workspaces/kprog-raw/perf/20261114-scalar-spill-precision/values-fixed
```

The initial prototype's first differing pair was mark 0, priority 1: return
12347 versus reference 12346. Its 32-bit self-copy was eliminated by LLVM,
preserving an unwanted upper half. Commit `671a70169` uses explicit 64-bit
left/right shifts for truncation. Both original and corrected logs, the
lowered MIR and the execution CSV are retained beside this report. This is a
compiler transformation test; corrected OTel main acceptance and application
execution retain their own results.

The fixture VM used CPUs 22–23, one vCPU, 2 GiB and a shared image lock.
The first hand-written MIR attempt's tied-operand diagnostic remains in the
lane's persistent run log; adding a physical register copy resolved it before
kernel execution. The default compiler path retains its existing behavior.
