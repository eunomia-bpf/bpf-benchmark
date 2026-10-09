# Published figure comparison

All 224 regenerated bars match computed values and PDF vector geometry.
The 216 characterization/micro bars also match the published snapshot.
The eight archived policy bars match their original labels; regenerated policy bars
use median post/baseline. Corrected throughput labels are 1.074/1.119/0.984/1.065
(Cilium full/no-bulk, Katran full/conservative), and cost labels are
1.010/1.062/1.006/0.941. Archived policy labels remain 1.074/1.114/0.995/1.073
and 1.009/1.062/1.006/0.941.

162 characterization bars, 54 kinsn micro bars, and 8 policy bars.
Tolerances: 0.0001 for published PDFs (coordinate quantization), 0.000002 for regenerated PDFs. Policy heights use three-decimal rounding. Published policy checks compare `snapshot_expected_value` to PDF geometry;
`regenerated` records the corrected value. `figure-checks.json` records each comparison.
