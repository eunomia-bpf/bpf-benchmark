# ARM startup helper calls

Helper160 (`bpf_ktime_get_coarse_ns`) and helper173 (`bpf_get_func_ip`) now
have real typed ARM simulator calls and entries in the shared generated
C/Lean/Python identity contract. All75 prior entries remain, giving77.
The existing helper ABI oracle passes154 cases, the independent identity
oracle79 cases, kernel-enum agreement and generated freshness pass. The
full345-module formal/C/Rust/wire check passes in a private19662b056 export
with only the eight helper paths overlaid. Its first attempt hit the existing
EntryEnvironment SAT timeout; the unchanged retry passes and both logs remain.
All six actual captured startup native/simulator pairs compile, including
helpers160/173. Runtime startup is still failing in the shared loader path;
these compilation results do not claim generation-bound startup completion.
The replay archive retains the changed contracts, helper bodies/oracles,
compiled six proofs and native compilation commands. Recheck with
`make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile helper-contract-check`.
