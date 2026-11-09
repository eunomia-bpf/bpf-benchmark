# Six-save entry: original upstream315 load replay

The same 315 compiled C-written upstream programs and 1917-row catalog ran
through the matching six-save kernel and model epoch
96b561e22981f4a5a0b03ec5b7b0374998e546ed. Each program retains its original
kernel annotation. All 315 operations are load-only; native execution requests total 0.

| Stage | Original frame | Six-save frame |
| --- | ---: | ---: |
| Installed | 15 | 17 |
| Verifier rejected | 68 | 66 |
| Generation failed | 202 | 202 |
| Resource failed | 30 | 30 |
| Submitted | 285 | 285 |

Three annotated success programs change from verifier rejection to installation:
dynptr_overwrite_unref, dynptr_invalidate_slice_success and test_xdp
(verifier_sockmap_mutate.c). The annotated failure no_null_check changes from
installation to verifier rejection. The continuing installed annotated failure
is test_dynptr_reg_type in dynptr_fail.c. The diagnostic record and service
archives retain every rejection cause and the complete generated B artifacts.

The driver, guest and make each exit 0 after iterating all 315 inputs.
These exits describe queue completion. The installed failure and outstanding
generation/resource results remain findings. The stock bpf_testmod fixture
profile matches the original-frame run; fixture-enabled coverage is a separate cohort.

Reproduce with the entry-frame Makefile targets kernel module linker prepare
selftests315 and REVISION=96b561e22981f4a5a0b03ec5b7b0374998e546ed.
The summary records each transition, input and runtime hash. Concatenate the available
raw.tar.gz.partNN files in lexical order to recover raw.tar.gz. The manifest records archive and part hashes.
The archive includes table objects, catalogs, all load/service/compiler records,
commands, guest script, dmesg and exits. The original comparison sits in
../before-selftests315/.
