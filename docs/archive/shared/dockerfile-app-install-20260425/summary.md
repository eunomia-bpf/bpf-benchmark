# runner-runtime app install changes (2026-04-25)

## Changed files

- `runner/containers/runner-runtime.Dockerfile`
- `runner/libs/app_runners/suricata.py`
- `runner/libs/app_runners/loxilb.py`
- `runner/libs/app_runners/otel_profiler.py`
- `runner/libs/app_runners/__init__.py`
- `runner/libs/benchmark_catalog.py`
- `corpus/config/macro_apps.yaml`

## What changed

### 1. Runtime image installs

- `suricata`
  - Added `apt-get install suricata` in the final `runner-runtime` stage.
  - Added build-time verification for:
    - `/usr/bin/suricata` or `/usr/sbin/suricata`
    - `/usr/lib/suricata/ebpf/*.bpf`
  - Added repo-artifact symlink:
    - `/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/suricata/bin/suricata`

- `loxilb`
  - Added GitHub release `.deb` install for `v0.9.7` on `amd64` only:
    - `https://github.com/loxilb-io/loxilb/releases/download/v0.9.7/loxilb_0.9.7-amd64.deb`
  - Added build-time verification for:
    - `/usr/local/sbin/loxilb`
  - Added repo-artifact symlink:
    - `/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/loxilb/bin/loxilb`

- `otelcol-ebpf-profiler`
  - Added official tarball install into `/usr/local/bin`.
  - Added build-time verification for:
    - `/usr/local/bin/otelcol-ebpf-profiler`
  - Added repo-artifact symlink:
    - `/artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler`

### 2. Runner path updates

- `SuricataRunner` now checks:
  - `/usr/bin/suricata`
  - `/usr/sbin/suricata`

- `LoxilbRunner` now checks:
  - `/usr/local/sbin/loxilb`
  - `/usr/bin/loxilb`

- Added new `OtelProfilerRunner`:
  - binary candidates include repo-artifact paths and `/usr/local/bin/otelcol-ebpf-profiler`
  - creates a temporary minimal collector config
  - runs with:
    - `--feature-gates=+service.profilesSupport`
    - `--config <generated config>`
  - config uses:
    - `receivers.profiling`
    - `exporters.debug`
    - `service.pipelines.profiles`
  - reuses existing native-process lifecycle and workload execution

### 3. Registration and catalog

- Registered runner key:
  - `otelcol-ebpf-profiler`

- Added macro app definition:
  - `otelcol-ebpf-profiler/default`
  - runner: `otelcol-ebpf-profiler`
  - workload: `exec_storm`

## Important note about the requested OTel version

The requested tarball URL for `otelcol-ebpf-profiler v0.120.0` returned `404` when checked on **2026-04-25**:

- requested:
  - `https://github.com/open-telemetry/opentelemetry-collector-releases/releases/download/v0.120.0/otelcol-ebpf-profiler_0.120.0_linux_amd64.tar.gz`

Because that official asset is not published upstream, the Dockerfile now uses **`v0.140.0`**, which is the earliest verified official release URL that exists for this distribution.

## Validation

Ran successfully:

```bash
python3 -m py_compile \
  runner/libs/app_runners/__init__.py \
  runner/libs/app_runners/loxilb.py \
  runner/libs/app_runners/otel_profiler.py \
  runner/libs/app_runners/suricata.py \
  runner/libs/benchmark_catalog.py
```

```bash
python3 - <<'PY'
from pathlib import Path
from runner.libs.app_runners import get_app_runner
from runner.libs.app_suite_schema import load_app_suite_from_yaml

runner = get_app_runner('otelcol-ebpf-profiler', workload='exec_storm')
assert type(runner).__name__ == 'OtelProfilerRunner'
suite = load_app_suite_from_yaml(Path('corpus/config/macro_apps.yaml'))
assert any(app.name == 'otelcol-ebpf-profiler/default' for app in suite.apps)
print('import-ok')
PY
```

```bash
python3 - <<'PY'
from pathlib import Path
from runner.libs.app_runners.loxilb import LoxilbRunner
from runner.libs.app_runners.otel_profiler import OtelProfilerRunner
from runner.libs.app_runners.suricata import SuricataRunner

suricata = SuricataRunner(workload_kind='network')
loxilb = LoxilbRunner(workload_kind='network')
otel = OtelProfilerRunner(workload_kind='exec_storm')
assert Path('/usr/bin/suricata') in suricata._default_binary_candidates() or Path('/usr/sbin/suricata') in suricata._default_binary_candidates()
assert Path('/usr/local/sbin/loxilb') in loxilb._default_binary_candidates()
assert Path('/usr/local/bin/otelcol-ebpf-profiler') in otel._default_binary_candidates()
print('candidates-ok')
PY
```
