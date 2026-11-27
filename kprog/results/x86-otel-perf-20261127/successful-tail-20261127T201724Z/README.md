# Reproduced skipped shared tail call

The actual captured entry was run with known PID/PC mappings, a populated native program-array slot1 and count0. It returned-1 without reaching the target or incrementing the counter. Failure-branch instrumentation also remained untouched: control bypassed the expansion entirely. This is the pre-fix oracle failure, preserved as status1, not a successful test. The common source-address repair passes the same case; see ../shared-call-anchor-20261127. The earlier path-concatenation harness error is retained separately.
