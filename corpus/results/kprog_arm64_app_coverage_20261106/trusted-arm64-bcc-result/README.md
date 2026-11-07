# Canonical ARM BCC trusted-service replay

Host reported status: `True`; guest exit: `0`. Service completed counts: `{"service_accepted": 5, "service_refused": 1}`. Native identity errors: `[]`.

The canonical ARM worker receives kernel-copied native bytes. The existing readonly v35 standard `/qemu-run.sh` runs corpus.driver/BCC set with its eight tools, two starts and four existing stressors. The native application manifest contains no proof filenames. Existing current kernel,11 matching kinsn modules, module tree and loader are reused. Raw corpus results, counters, logs, kernel/memory evidence and each available closed service request are in `run-20261107T163609924222Z.tar.gz` (SHA256 `2eff867c2a71c15794d7ae3a229a132b5057d7a149d7b0500165a01a9a07cd85`). QEMU timing is functional only.

The preceding two zero-request startup failures and module CRC diagnosis are retained beside this run. This closed operational result still needs application inventory/work-counter review; it does not establish all-six-application or whole O1-O4 acceptance.
