# Tetragon YAML parse failure root cause, 2026-05-05

## Conclusion

The failing `yaml: line 2: did not find expected alphabetic or numeric character`
is a TracingPolicy load failure, not a Tetragon internal config failure and not a
kernel 7.0.0-rc2 behavior change.

The concrete offending file is:

```text
runner/assets/tetragon_policies/.pytest_cache/.gitignore
```

Its content is:

```text
# Created by pytest automatically.
*
```

Tetragon v1.6.1 walks every regular file under `--tracing-policy-dir`; it does
not filter by `.yaml` or `.yml`. The second line `*` is parsed by the Kubernetes
YAML stack as an alias marker with no alias name, which matches the observed
error:

```text
failed to unmarshal YAML: error converting YAML to JSON:
yaml: line 2: did not find expected alphabetic or numeric character
```

## Source Location

Tetragon image is pinned in `runner/containers/runner-runtime.Dockerfile:3` to
`quay.io/cilium/tetragon:v1.6.1@sha256:ff96...`.

Checked source tag:

```text
/tmp/tetragon-v1.6.1
HEAD a955aa31620f1d764c24f6fb1982f4d24d421910
tag api/v1.6.1
```

The fatal log line is emitted by the root command after `tetragonExecute()`
returns an error:

```text
cmd/tetragon/main.go:828-829
if err := tetragonExecute(); err != nil {
    logger.Fatal(log, "Failed to execute tetragon", logfields.Error, err)
}
```

The error is returned from TracingPolicy directory load:

```text
cmd/tetragon/main.go:531-534
err = loadTpFromDir(ctx, option.Config.TracingPolicyDir)
if err != nil {
    return err
}
```

`loadTpFromDir()` is the critical behavior. It walks all regular files; there is
no suffix filter:

```text
cmd/tetragon/main.go:568-590
err := fs.WalkDir(tpFS, ".", func(path string, d fs.DirEntry, err error) error {
    ...
    if d.IsDir() {
        if strings.Count(path, string(os.PathSeparator)) >= tpMaxDepth {
            return fs.SkipDir
        }
        return nil
    }
    ...
    if !st.Mode().IsRegular() {
        return nil
    }
    return addTracingPolicy(ctx, file)
})
```

`addTracingPolicy()` calls the TracingPolicy parser:

```text
cmd/tetragon/main.go:596-604
tp, err := tracingpolicy.FromFile(f)
if err != nil {
    return err
}
```

The exact `"failed to unmarshal YAML"` string is produced here:

```text
pkg/tracingpolicy/generictracingpolicy.go:90-94
func FromYAML(data string) (TracingPolicy, error) {
    var unstr unstructured.Unstructured
    if err := yaml.UnmarshalStrict([]byte(data), &unstr); err != nil {
        return nil, fmt.Errorf("failed to unmarshal YAML: %w", err)
    }
```

Therefore the error is from TracingPolicy YAML parsing, after Tetragon has
started its core observer path. It is not from `ReadConfigFile()` /
`ReadConfigDir()` for `/etc/tetragon` configuration.

One ordering clarification: source order loads the base sensor before starting
the gRPC server and before `loadTpFromDir()`:

```text
cmd/tetragon/main.go:472-477 loadInitialSensor()
cmd/tetragon/main.go:491     Serve(...)
cmd/tetragon/main.go:501     StartHealthServer(...)
cmd/tetragon/main.go:531     loadTpFromDir(...)
```

The observed result log interleaves the fatal line before some `__base__` sensor
messages, but source order still places policy loading after base sensor setup.

## Image Diff Evidence

The successful corpus run `x86_kvm_corpus_20260505_045315_748388` started at
`2026-05-05T04:53:15Z` and has:

```text
status=ok
baseline.bpf count=287
post_rejit.bpf count=287
```

A matching pre-failure local image is:

```text
141c755709d3 created 2026-05-04 21:50:43 PDT, size 4.62GB
```

Its policy directory contained only policy YAML files:

```text
bpf.yaml
datagram-with-sock-tracking.yaml
datagram_518.yaml
fd_install_cap_changes.yaml
filename_monitoring.yaml
host-changes/monitor-kernel-modules.yaml
process-exec/process-exec-elf-begin.yaml
raw_syscalls.yaml
rawtp.yaml
security-socket-connect.yaml
security_inode_follow_link.yaml
sys_mount.yaml
tcp-accept.yaml
tcp-connect-with-selectors.yaml
tty.yaml
```

The first failing run `x86_kvm_corpus_20260505_062108_053131` started at
`2026-05-05T06:21:08Z` / `2026-05-04 23:21:08 PDT`. A matching post-rebuild
image is:

```text
9f22ee478721 created 2026-05-04 23:18:33 PDT, size 4.72GB
```

Its policy directory had the same YAML files plus pytest cache files:

```text
.pytest_cache/.gitignore
.pytest_cache/CACHEDIR.TAG
.pytest_cache/README.md
bpf.yaml
...
```

The current workspace has the same hidden cache:

```text
runner/assets/tetragon_policies/.pytest_cache/.gitignore
runner/assets/tetragon_policies/.pytest_cache/CACHEDIR.TAG
runner/assets/tetragon_policies/.pytest_cache/README.md
runner/assets/tetragon_policies/.pytest_cache/v/cache/nodeids
```

The cache directory mtime is:

```text
2026-05-04 22:44:48 PDT
```

This is after the successful `045315` run and before commit `bdfcaa62`
(`2026-05-04 23:07 PDT`) and the first failing run (`2026-05-04 23:21 PDT`).

## Why bdfcaa62 Triggered It

`bdfcaa62` did not edit `runner/libs/app_runners/tetragon.py` or any Tetragon
policy YAML. Its relevant Dockerfile change was adding runtime packages:

```text
nodejs
php-cli
ruby
```

That Dockerfile change invalidated the runtime image build path and produced a
fresh runtime image after the hidden pytest cache already existed in the host
workspace.

The final runtime image copies all assets with:

```text
runner/containers/runner-runtime.Dockerfile:552
COPY --link runner/assets ./runner/assets
```

The final cleanup only removes `__pycache__` and only asserts that at least one
YAML file exists:

```text
runner/containers/runner-runtime.Dockerfile:563-566
find ./runner ./micro ./corpus -type d -name __pycache__ -prune -exec rm -rf {} +;
find ./runner/assets/tetragon_policies -type f \( -name '*.yaml' -o -name '*.yml' \) | grep -q .;
```

`.dockerignore` excludes `**/__pycache__` and `**/*.pyc`, but it does not exclude
`**/.pytest_cache`. The pytest cache files are ignored by Git because
`.pytest_cache/.gitignore` contains `*`, so normal `git status` hides them, but
Docker build context inclusion follows `.dockerignore`, not `.gitignore`.

That gives the causal chain:

```text
pytest creates runner/assets/tetragon_policies/.pytest_cache at 22:44 PDT
-> bdfcaa62 changes Dockerfile and forces a fresh runtime image build
-> Docker COPY runner/assets includes .pytest_cache because .dockerignore misses it
-> Tetragon receives --tracing-policy-dir runner/assets/tetragon_policies
-> Tetragon walks all regular files, including .pytest_cache/.gitignore
-> yaml parser fails on line 2 "*"
-> tetragon exits 255
```

The apt packages are only an indirect trigger through image invalidation. I found
no evidence that nodejs, ruby, or php created `/etc` files consumed by Tetragon.
The Tetragon config paths from `cmd/tetragon/conf.go` were absent in both old and
new images:

```text
/etc/tetragon                         MISSING
/usr/lib/tetragon                     MISSING
/usr/local/lib/tetragon               MISSING
/home/yunwei37/workspace/bpf-benchmark/tetragon.yaml MISSING
```

`strace` is not installed in the runtime image (`STRACE_MISSING`), and I did not
start a privileged Tetragon process on the host because project rules keep BPF
execution inside the VM. Source-level control flow plus image filesystem
inspection is sufficient here because the exact error string can only come from
`tracingpolicy.FromYAML()`.

## Hypotheses Checked

`bpf.yaml` one-space indentation is not the root cause. The successful image
`141c755709d3` used the 1098-byte `bpf.yaml` from commit `4972401e` and loaded
287 programs successfully. The current image has the user-adjusted 1134-byte
`bpf.yaml`, but the same failure persists because the parser fails before normal
policy YAML processing reaches the intended files.

Kernel 7.0.0-rc2 is not the root cause. The failing log mentions kernel
`7.0.0-rc2` only in the missing `/boot/config-7.0.0-rc2` diagnostic and later
base sensor messages. The fatal YAML string is produced by userspace YAML
parsing of a local file under `--tracing-policy-dir`.

`/etc` config drift is not the root cause. Tetragon's default config directories
are absent in both compared images, and the exact fatal string does not come from
the config reader path.

## Recommended Fix Direction

Do not change the Tetragon policy YAML content for this issue.

Recommended fixes, in decreasing directness:

1. Add a Docker context exclusion for pytest cache directories, for example
   `**/.pytest_cache` and `**/.pytest_cache/**` in `.dockerignore`.
2. Add a final image sanity check that fails the build if
   `runner/assets/tetragon_policies` contains any regular file that is not
   `.yaml` or `.yml`, because Tetragon v1.6.1 will try to parse every regular
   file there.
3. Optionally make the runner pass Tetragon a clean generated policy directory
   containing only selected YAML files, instead of passing the source asset
   directory directly.

The most robust minimal fix is to combine 1 and 2: exclude known local cache
directories from Docker context and make the runtime image fail fast if a
non-policy file still reaches the Tetragon policy directory.
