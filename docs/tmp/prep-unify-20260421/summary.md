# Prep Unify Summary

## `local_prep_targets()` diff

```diff
 if suite in _RUNTIME_IMAGE_SUITES:
     image_tar = runtime_container_image_tar_path(workspace, arch)
-    if not (str(executor).strip() == "aws-ssh" and image_tar.is_file()):
-        targets.append(image_tar)
+    targets.append(image_tar)
```

This removes the AWS-only existence short-circuit and lets make's native dep tracking decide whether the runtime image tar is stale.

## `build.mk` dep graph check

Verified `runner/mk/build.mk` already includes the expected runtime-image deps:

- `$(BUILD_RULE_FILES)` -> `Makefile` and `runner/mk/build.mk`
- `$(RUNNER_RUNTIME_CONTAINERFILE)`
- `$(DOCKERIGNORE_FILE)`
- `$(DAEMON_SOURCE_FILES)`
- `$(RUNNER_SOURCE_FILES)`
- `$(TEST_UNITTEST_SOURCE_FILES)`

Also verified the existing broader runtime-image inputs already cover the relevant Python/config trees:

- `$(RUNNER_RUNTIME_SOURCE_FILES)` includes `runner/**/*.py|yaml|env`, so `runner/libs/**` changes already force an image rebuild.
- `$(MICRO_RUNTIME_SOURCE_FILES)`, `$(CORPUS_RUNTIME_SOURCE_FILES)`, and `$(E2E_RUNTIME_SOURCE_FILES)` already cover the runtime suite content copied into the image.

No missing runtime-affecting source input was found for the current image build, so `runner/mk/build.mk` was left unchanged.

## Validation

Requested syntax check:

```bash
python3 -m compileall runner/ corpus/ e2e/
```

Result: fails on pre-existing vendored Python 2 scripts under `runner/repos/`, not on the changed code. Representative failures:

```text
*** Error compiling 'runner/repos/calico/cni-plugin/contrib/test_scripts/benchmark.py'...
SyntaxError: Missing parentheses in call to 'print'

*** Error compiling 'runner/repos/suricata/qa/sock_to_gzip_file.py'...
SyntaxError: multiple exception types must be parenthesized
```

Focused compile for the touched path passed:

```bash
python3 -m py_compile \
  runner/libs/workspace_layout.py \
  runner/libs/run_target_suite.py \
  runner/suites/_common.py \
  runner/suites/micro.py \
  runner/suites/test.py \
  corpus/driver.py \
  e2e/driver.py
```

Dry-run rebuild proof:

Note: top-level `make -n aws-e2e RUN_TARGET_ARCH=x86_64` only prints the wrapper shell case statement; it does not descend into the nested prep `make` inside `runner.libs.run_target_suite`. To validate the real prep dependency graph without launching AWS, I dry-ran the concrete prep target resolved by `local_prep_targets()`:

```text
/home/yunwei37/workspace/bpf-benchmark/.cache/container-images/x86_64-runner-runtime.image.tar
```

Dirty source -> rebuild planned:

```bash
touch -d "2099-01-01 00:00:00" /home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py
make -n /home/yunwei37/workspace/bpf-benchmark/.cache/container-images/x86_64-runner-runtime.image.tar RUN_TARGET_ARCH=x86_64 2>&1 | grep -E "docker build|image-runner-runtime-image-tar"
```

Output:

```text
docker build --platform linux/amd64 \
```

Clean target -> no rebuild planned:

```bash
touch -d "2099-01-01 00:01:00" /home/yunwei37/workspace/bpf-benchmark/.cache/container-images/x86_64-runner-runtime.image.tar
make -n /home/yunwei37/workspace/bpf-benchmark/.cache/container-images/x86_64-runner-runtime.image.tar RUN_TARGET_ARCH=x86_64 2>&1 | grep -E "docker build|image-runner-runtime-image-tar"
```

Output:

```text
# no output
```

The source and target mtimes were restored after the probe so the cache state remained unchanged after validation.

## `workspace_layout.py` fixes

- `kinsn_module_dir()` now returns `/artifacts/kinsn` only inside the runtime image. Host-side execution now uses `workspace/module/x86` or `workspace/module/arm64` according to `target_arch`.
- `kernel_modules_root()` no longer deletes `target_arch` or hardcodes the x86 module path for all KVM runs. Outside the runtime image, KVM now asserts `x86_64` and returns `repo_artifact_root(workspace, target_arch) / "kernel-modules"`. Non-KVM executors still return `/`.

## Commit Hashes

- `52f2ab8c` `[prep] unify KVM/AWS image rebuild on make dep tracking (drop AWS short-circuit)`
- `10c1a392` `[workspace] respect target_arch in kinsn_module_dir / kernel_modules_root outside runtime image`

## Edge Cases

- `make -n aws-e2e ...` is not sufficient to inspect prep rebuild scheduling because the actual local-prep `make` runs inside Python at execution time.
- Repo-wide `compileall runner/ corpus/ e2e/` is currently blocked by vendored Python 2 files under `runner/repos/`.
