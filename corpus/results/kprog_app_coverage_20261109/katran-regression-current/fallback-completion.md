# Complete startup after eBPF fallback

The current Katran replay generates and compiles P, then the verifier rejects an emitted stack write at -520. The source eBPF fd remains loaded. The existing startup observer waits for a completed bound attempt, while the shim previously counted replacements alone, keeping an all-fallback application in its startup wait. The shim now counts every returned bound attempt in its legacy native_bound_completed wire field. Actual native installation remains recorded by native replaced log entries and the service ledger. Source workload, runner and benchmark framework retain their bytes.

The XDP compiler repair and verifier rejection remain separate results. The active replay raw files are retained before the corrected shim replay.
