# Delete CLI Args / Vars Report (2026-04-23)

## Candidate deletions

| Item | Location | Evidence | Planned action |
| --- | --- | --- | --- |
| corpus `--output-md` | `runner/suites/corpus.py:44`, `runner/suites/corpus.py:92-100`, `corpus/driver.py:71` | `rg -n 'args\\.output_md\\b|getattr\\(args, .output_md' corpus/driver.py` returned `0` refs. The suite wrapper only synthesizes `--output-md` and forwards it to `corpus/driver.py`, which never reads it. | delete |
| e2e `--output-md` | `e2e/driver.py:93`, `e2e/driver.py:189`, `e2e/driver.py:205-206` | `rg -n 'args\\.output_md\\b|getattr\\(args, .output_md' e2e/driver.py` only found the parser/defaulting path at `205-206`; there is no write path after parse. | delete |
| `ARM64_IMAGE` | `Makefile:19` | `rg -n '\\bARM64_IMAGE\\b' Makefile runner/mk/build.mk` only found the definition. | delete |
| `ARM64_EFI_IMAGE` | `Makefile:20` | `rg -n '\\bARM64_EFI_IMAGE\\b' Makefile runner/mk/build.mk` only found the definition. | delete |
| `ARM64_AWS_IMAGE` | `Makefile:21` | `rg -n '\\bARM64_AWS_IMAGE\\b' Makefile runner/mk/build.mk` only found the definition. | delete |
| `ARM64_AWS_EFI_IMAGE` | `Makefile:22` | `rg -n '\\bARM64_AWS_EFI_IMAGE\\b' Makefile runner/mk/build.mk` only found the definition. | delete |
| `ARM64_AWS_CACHE_ROOT` | `Makefile:17` | After deleting the dead ARM64 AWS image paths, `rg -n '\\bARM64_AWS_CACHE_ROOT\\b' Makefile runner/mk/build.mk` only found the definition. | delete |
| `ARM64_AWS_BUILD_DIR` | `Makefile:18` | After deleting the dead ARM64 AWS image paths, `rg -n '\\bARM64_AWS_BUILD_DIR\\b' Makefile runner/mk/build.mk` only found the definition. | delete |
| `ACTIVE_CONTAINER_PLATFORM` | `runner/mk/build.mk:49` | `rg -n '\\bACTIVE_CONTAINER_PLATFORM\\b' Makefile runner/mk/build.mk` only found the definition. | delete |
| `RUNNER_CLANG_DIR` | `runner/mk/build.mk:30` | `rg -n '\\bRUNNER_CLANG_DIR\\b' Makefile runner/mk/build.mk` only found the definition. | delete |
| e2e hidden `args.tools` | `e2e/driver.py:340-369` | `rg -n 'args\\.tools\\b|getattr\\(args, \"tools\"' e2e/driver.py e2e/cases/bcc/case.py` returned only the local config helper write/read pair; no case consumes it. | delete |
| e2e hidden `args.scripts` | `e2e/driver.py:377-382` | `rg -n 'args\\.scripts\\b|getattr\\(args, \"scripts\"' e2e/driver.py e2e/cases/bpftrace/case.py` returned only the local config helper write/read pair; no case consumes it. | delete |
| e2e hidden `args.workloads` | `e2e/driver.py:393` | `rg -n 'args\\.workloads\\b|getattr\\(args, \"workloads\"' e2e/driver.py e2e/cases/scx/case.py` returned no consumer in the SCX case path. | delete |

## Deleted items

| Item | Action taken | Notes |
| --- | --- | --- |
| corpus `--output-md` | deleted from `runner/suites/corpus.py` and `corpus/driver.py` | The wrapper had been computing and forwarding a markdown path, but the corpus driver never read it or wrote a top-level markdown output. |
| e2e `--output-md` | deleted from `e2e/driver.py` | The driver only parsed/defaulted it; no later code wrote to that path. Removing it also let `CaseSpec.default_output_md` and the per-case default imports disappear. |
| e2e hidden `args.tools` / `args.scripts` / `args.workloads` | deleted from `e2e/driver.py` | These were dead suite-config scratch fields. They were written during suite filtering but never consumed by the BCC, bpftrace, or SCX case runners. |
| dead ARM64 path vars | deleted `ARM64_AWS_CACHE_ROOT`, `ARM64_AWS_BUILD_DIR`, `ARM64_IMAGE`, `ARM64_EFI_IMAGE`, `ARM64_AWS_IMAGE`, `ARM64_AWS_EFI_IMAGE` from `Makefile` | All six were pure dead definitions after grep verification. |
| dead build vars | deleted `RUNNER_CLANG_DIR` and `ACTIVE_CONTAINER_PLATFORM` from `runner/mk/build.mk` | Both had zero expansion sites outside their own definitions. |

## Not deleted

| Item | Reason kept |
| --- | --- |
| daemon CLI `serve --socket` | `docs/kernel-jit-optimization-plan.md:169` requires the daemon interface to be exactly `serve --socket ...`, and `daemon/src/main.rs:34-38,73` still consumes it. |
| `BPFREJIT_VM_DOCKER_ROOT` / `BPFREJIT_VM_DOCKER_DISK` / `BPFREJIT_VM_DOCKER_DISK_SIZE` | `runner/libs/kvm_executor.py:30-32` still reads them as live executor overrides. I did not have zero-reference evidence to delete them. |
| `BPFREJIT_BCC_COMPAT_HEADER` / `BPFREJIT_BCC_EXTRA_CFLAGS` | `runner/libs/app_runners/bcc.py:360-361` writes them into the tool subprocess env and `runner/libs/app_runners/bcc.py:130,146` reads them from the injected `sitecustomize` path, so they are active internal plumbing, not dead env surface. |
| `ARM64_BUILD_DIR` | After the dead image-path removals it is still referenced by `export ARM64_BUILD_DIR` and `clean`, so it no longer meets the zero-reference threshold used for this pass. |

## Validation

| Command | Result |
| --- | --- |
| `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile runner/suites/corpus.py corpus/driver.py e2e/driver.py` | exit 0 |
| `source /home/yunwei37/workspace/.venv/bin/activate && make check` | exit 0 |
| `make -n vm-corpus` | `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm corpus -- --samples "30"` |
| `make -n vm-e2e` | `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm e2e -- --e2e-cases "all"` |

## git diff --shortstat

Full repo worktree at finish:
`18 files changed, 282 insertions(+), 402 deletions(-)`

Touched-file subset for this cleanup:
`5 files changed, 3 insertions(+), 46 deletions(-)`

Note: this report file is new and untracked, so `git diff --shortstat` does not count it.

## Self review

- New non-comment non-blank code lines in code files: `3` (`<= 10`).
- No new CLI flag, env var, or config field was added.
- No compatibility fallback or deprecation shim was kept for removed surface.
- No forbidden file was edited, and no `vm-*` test target was executed.
