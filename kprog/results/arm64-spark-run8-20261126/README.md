# arm64 run 8, 2026-11-26

Operator 2026-11-26 10:54Z: "arm 也要确保出数字"; 10:55Z: "要确保每一个应用的数字都是最好的, 不能倒退."

Step 1 (`chain.sh`) rebuilds the arm64 image from the committed tree. The tree carries the key-size C hash routines for
every key size from 1 to 512 bytes (42cd0d591), whose x86 six-app check passed on image 7a11cb60285a (4ce03654f). It then
runs the QEMU six-app functional check (`make -C kprog/perf/one-image-arm64 check`). Logs and exit codes go to
/workspaces/kprog-raw/coordinator/arm64-run8-20261126/.

Step 2 is the Spark timing with the frozen arm64 entry (kprog/perf/one-image-arm64/spark-rotate.sh: 3 x 180 s per arm,
stats off then on, breadth first), six applications over the two Sparks. DeepSeek is paused for this single test and
restored right after, as in runs 5-7 (spark-manage docs/configuration-decisions/2026-11-21-kprog-arm64-spark-kvm-timing.md).
Results follow below.
