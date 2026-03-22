# Katran E2E gRPC Setup Fix

Date: `2026-03-19`  
Repo: `/home/yunwei37/workspace/bpf-benchmark`  
Issue: `#205`

## Summary

- The Katran E2E blocker was not the DSR datapath. The datapath already worked.
- The blocker was the **userspace gRPC build path**: trying to rebuild `katran_server_grpc` in the benchmark path was too heavy and too fragile for E2E.
- The practical fix is to **stop compiling the gRPC server during the E2E run** and use the checked-in bundle at `e2e/cases/katran/bin/katran_server_grpc`.

## What Actually Blocked / Timed Out

- `corpus/repos/katran/` is a sparse checkout and does not contain `example_grpc/`, so the official gRPC server cannot be built from the corpus checkout directly.
- Prior Katran build notes already showed that the official userspace build path pulled in a heavy `folly`/`grpc` dependency chain and hit multiple concrete blockers:
  - GCC/`folly` warning-probe failures
  - path-sensitive `FOLLY_XLOG_STRIP_PREFIXES` macro breakage under the original build root
  - `example_grpc` needing `C++20` instead of the upstream `C++17`
- Inference from the current harness: if this compile were kept inside the Katran E2E setup path, the timeout boundary would be the `300s` limit in `run_setup_script()` inside [`e2e/cases/katran/case.py`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py).

## Fix Implemented

- [`e2e/cases/katran/setup.sh`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/setup.sh)
  - Resolve the repo root from the script location instead of relying on `pwd`.
  - Discover the checked-in `katran_server_grpc` bundle deterministically.
- [`e2e/cases/katran/case.py`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py)
  - Add direct fallback discovery for the bundled server binary, so Katran can still resolve it even when setup was skipped earlier.
- [`e2e/run.py`](/home/yunwei37/workspace/bpf-benchmark/e2e/run.py)
  - Remove the redundant Katran VM pre-step that ran `setup.sh` out of band and then forced `--skip-setup`.
  - The Katran case now runs setup once, inside the benchmark flow, and records the resolved server path in the payload.

## Verification

### Bundle checks

- `bash e2e/cases/katran/setup.sh`
  - resolved `KATRAN_SERVER_BINARY=/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/bin/katran_server_grpc`
- `sha256sum e2e/cases/katran/bin/katran_server_grpc`
  - `f5cc6db8f20fd68be7676e663cd1a9c37c270e2865c09d8805d9f2cf5c15b1ce`
- `e2e/cases/katran/bin/katran_server_grpc --help`
  - starts successfully

### End-to-end runs

Commands used:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 e2e/run.py katran --vm --kernel vendor/linux-framework/arch/x86/boot/bzImage --smoke --timeout 2400
python3 e2e/run.py katran --vm --kernel vendor/linux-framework/arch/x86/boot/bzImage --timeout 2400
python3 e2e/run.py katran --vm --kernel vendor/linux-framework/arch/x86/boot/bzImage --timeout 2400
```

Observed after the fix:

- smoke run: success
- authoritative run: success
- repeat authoritative run: success again
- setup metadata now records the bundled server path instead of incorrectly reporting `katran_server_binary: null`

Latest saved authoritative artifact:

- [`e2e/results/katran_authoritative_20260319.json`](/home/yunwei37/workspace/bpf-benchmark/e2e/results/katran_authoritative_20260319.json)
- [`e2e/results/katran-e2e-real.md`](/home/yunwei37/workspace/bpf-benchmark/e2e/results/katran-e2e-real.md)

Latest saved authoritative result summary:

- control plane: `bpftool_direct_map`
- bundled server detected: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/bin/katran_server_grpc`
- HTTP: `5/5` succeeded
- IPIP decap packets: `30`
- live sites: `94`
- policy remap: `4` explicit `wide` sites applied
- recompile: `1/1` program applied successfully
- BPF avg ns/run: `407.6 -> 507.0` (`+24.4%`, regression)
- mean HTTP latency: `14.05 ms -> 9.56 ms` (`-31.9%`)

Important context:

- Before this fix, the same-day Katran bring-up had already shown a functional DSR run with `603.7 -> 351.8` avg ns/run.
- After the setup fix, I reran the benchmark twice and both reruns remained functionally correct but did **not** reproduce that earlier positive BPF result.
- Conclusion: **#205 is fixed as a setup/runtime integration issue, not as a new performance win.**

## Conclusion

- Katran E2E no longer depends on rebuilding `katran_server_grpc` during the benchmark.
- The benchmark now resolves the checked-in bundle deterministically and records it correctly in the result payload.
- End-to-end Katran DSR verification passes in VM.
- Performance should be treated separately from this fix; the latest reruns are functional but currently slower in BPF avg ns/run than baseline.
