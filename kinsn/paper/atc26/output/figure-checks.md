# Published figure comparison

All 226 regenerated bars match computed values and the vector geometry of both
the published camera-ready PDFs and the regenerated PDFs.

162 characterization bars, 54 kinsn micro bars, and 10 bars in Figure 6
(throughput and BPF cost for Cilium full, Cilium without bulk copy, Cilium
whole-program native, Katran full and Katran conservative). Figure 6 values are
median post/baseline ratios rounded to three decimals: throughput
1.074/1.119/1.194/0.984/1.065 and BPF cost 1.010/1.062/0.704/1.006/0.941.

Tolerances: 0.0001 for published PDFs (coordinate quantization), 0.000002 for regenerated PDFs. `figure-checks.json` records each comparison.
