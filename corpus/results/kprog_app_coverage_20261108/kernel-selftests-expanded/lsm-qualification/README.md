# Matched x86 LSM nullable-entry qualification

The expanded original315 cohort loads both published verifier_lsm programs through the ordinary stock BPF loader and native source_prog_id0. All siblings have autoload=false for the selected baseline load, and every native submission uses the existing maps/BTF-only producer. Attachments0, stock/native executions0.

| Original case | Stock original BPF | Native P / generated B | Actual verifier context |
| --- | --- | --- | --- |
| no_null_check | Reject after2instructions: trusted_ptr_or_null_file dereference | Reject after29instructions: pointer arithmetic on trusted_ptr_or_null | type29/expected27/target71327, sourceBTF0 for native |
| null_check | Installed | Installed | same target/nullable argument |

The actual paired x86 vmlinux BTF has bpf_lsm_mmap_file71327, prototype35653, arg0 file__nullable. Native P retains ctx[0] then file+32, matching the original BPF access chain. The current shared source hook line names file, while this retained runtime BTF names file__nullable; those source/runtime epochs stay explicitly distinct. A d4a23b5b captured ARM target70008/prototype16926/arg0 file and retained both P/B reads with an installed failure annotation. This exact parameter-name difference qualifies the paired-kernel/entry-ABI comparison; each runtime keeps its original counts and source identity.

summary.json contains both original verifier logs and native request/context/diagnostic records. raw.tar.gz retains the original C/annotations, whole resource BPF, both unchanged x86 native objects, the actual failed native/B/C archive, baseline script and BTF prototype observation. Current source qualification changes0; runtime admission additions0.
