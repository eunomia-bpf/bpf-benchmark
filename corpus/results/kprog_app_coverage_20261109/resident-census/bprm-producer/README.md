Tetragon credential-commit native input

The native-tetragon recipe includes the credential-commit source family already present in the reference BPF corpus. Incremental compilation emits tg_kp_bprm_committing_creds with the common native ABI and flags; compiler exit 0. The archive retains the native ELF, exact command and compiler log. The original eBPF source and frozen workload retain their bytes. Stock-verifier outcome follows the static continuation.
