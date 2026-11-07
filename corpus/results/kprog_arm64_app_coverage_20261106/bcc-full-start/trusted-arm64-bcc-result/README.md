# Canonical ARM BCC full-start replay

Host status: `False`; guest exit: `1`. Service counts: `{"service_accepted": 16, "service_refused": 3}`; identity errors: `[]`. Application metadata/errors are retained in run/work.json, run/guest.json and run/corpus-results.

This replay uses canonical b890 ARM generation and 419b transport error propagation, with existing REJIT_TIMEOUT=0 so the serialized QEMU compiler queue can finish. The same readonly v35 eight-tool/two-start/four-stressor recipe and current kernel/modules/loader remain. The exclusive-retry kernel candidate is not applied; prior rejection is expected to remain. No application source, simulator, compiler flag or workload changes.

Raw archive: `run-20261107T172354861230Z.tar.gz`, SHA256 `70369c4760749672015fe1a8a1a6c2970e5a6d240c6a17eab42acf23148aeeda`. Every available closed request and unfinished directory is retained. The thin output redirect, Make command, pins and initial pre-QEMU output-directory error are also in the archive. QEMU timing is functional only. Program inventory and work-counter review still needs the actual closed application data; no all-six-app or whole O1-O4 claim.
