# Verifier statistics on accepted B, and the loader's instruction-limit message (coordinator, 2026-11-25)

Both changes are on the verify side (kprog/libnativeloader/src/native_loader_trusted.cpp, the trusted loader that
loads B for the stock verifier); the native code that runs is unchanged (operator 2026-11-23: "如果和真实跑的代码无关
的 verify 改动可以留着").

1. Statistics (paper RQ4, verification cost). The trusted verify load sets BPF_LOG_LEVEL1 | BPF_LOG_STATS, with
   4 KiB more log buffer for the kernel's closing lines. For an accepted B it writes the closing lines
   ("verification time", "stack depth", "processed ... insns") to stderr, which the service saves as
   request/verify.stderr. A rejected B reports as before. Draft and its build check:
   /workspaces/kprog-raw/coordinator/sa-20261125/verifier-stats.
2. Message. "source proof subprogram section is not whole instructions" covered two conditions; the over-1M case
   now reports "source proof exceeds the BPF instruction limit: N instructions". The 5 Tracee requests of
   classfg-20261124T070800Z carrying the old text are over-1M entries (1,464,232 instructions,
   kprog/results/pointer-launder-20261122/remaining-classes.txt, f3bf8bae0). The conditions are the same as before.

Built into the verified base: `cmake --build /workspaces/.agent-state/kprog-ck/verified-loader --target
trusted-native-loader native_loader native_loader_shared` at 2026-11-25T11:11Z; the binary carries both strings.
The next checked corpus (checked-corpus-20261125-kdata2) records the statistics.
