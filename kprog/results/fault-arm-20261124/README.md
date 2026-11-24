# B fault arm restored, 2026-11-24

aaca40148 (2026-11-22) made the __bpf__ arm of X86_SIM_L_ARCHITECTURAL_FAULT return ("r0 = 0; exit;"). With that
spelling the stock verifier accepts a B whose native program can divide by zero or overflow a quotient, while the
native `div` raises #DE: B stops simulating P at a processor fault. kprog/formal's whole `make check` failed at
tools/check_x86_divide_handler.py:73, which requires the fault marker r0 = 0; *(u64 *)(r0 + 0) = r0; exit in the
compiled zero/overflow divide programs (V receipt 18b72f4c4, m5-xor-full-20261123).

This commit stores through null again in the B arm and moves the after-acceptance matcher in
kprog/x86/compile_sim_ir.cpp back to that spelling. OTel r8, the request that motivated aaca40148, is rejected
earlier at class A with either spelling (aaca40148 message), so verified-path coverage stays as it was.

- `python3 tools/check_x86_divide_handler.py` (kprog/formal, under flock -s locks/timing, CPUs 8-11): rc 0, "x86 DIV
  handler:18432 actual CPU/encoded register-memory/high-byte results,9 valid BPF compiles and9 retained
  zero/overflow/AX-alias fault markers;2 narrow-result controls OK" (check_x86_divide_handler.log).
- compile-sim-ir rebuilt with the recipe of kprog/results/lto-apps-20261119/compiler-rebuild.log: sha256
  66adfac9f544a877…, the value aaca40148 records for the binary before its change; installed in place at
  /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir (was fd2c5ec5359117d3…).

The timed native path (direct native, the loader and native-link) is unchanged.
