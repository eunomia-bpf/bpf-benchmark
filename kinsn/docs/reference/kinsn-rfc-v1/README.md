# Kinsn RFC v1 patch series

Snapshot of the private-review email sent on 2026-10-03, subject `[RFC PATCH bpf-next v1 0/5] bpf: Add verified kinsn support`, based on bpf-next `2b5440b31caf`. It had not been posted to the bpf mailing list when collected; this directory does not imply upstream acceptance.

Read the [cover letter](v1-0000-cover-letter.patch), then patches [1](v1-0001-bpf-Add-verified-kinsn-descriptors-and-proof-lowe.patch), [2](v1-0002-bpf-x86-Emit-registered-kinsn-in-the-JIT.patch), [3](v1-0003-bpf-arm64-Emit-registered-kinsn-in-the-JIT.patch), [4](v1-0004-selftests-bpf-Exercise-kinsn-calls-and-verifier-r.patch), and [5](v1-0005-Documentation-bpf-Document-verified-kinsn-descrip.patch) in order.

[attachments.zip](attachments.zip) is the original download-all archive of the same six email attachments, provided for one-file sharing. The `.patch` files are the extracted copies. This is source material; the benchmark repository has not applied these patches to its kernel or run their tests as part of this copy.
