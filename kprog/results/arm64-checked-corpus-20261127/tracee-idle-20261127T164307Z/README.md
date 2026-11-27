# Tracee idle ARM guest: measurement precedes syscall attachment

The frozen ARM guest20261127T140827Z reports corpus/app success, 33 baseline programs and2 post-native programs, but zero calls in both phases. The archived shim logs explain this directly. Times below are guest monotonic seconds, not operator UTC; `measure_start`/`measure_finish` are socket command-entry timestamps.

| event | baseline | post-native |
| --- | ---: | ---: |
| last startup `list_progs` request |56.895237|241.790136|
| measurement start request |74.722608|258.294188|
| measurement finish request |86.711320|281.498140|
| first raw tracepoint open |105.631288|none recorded|
| first `sys_enter` raw open |113.646663|none recorded|
| first `sys_exit` raw open |118.309470|none recorded|
| raw tracepoint open requests in full phase log |21|0|
| observed programs / active programs |33 /0|2 /0|

The first baseline raw-open succeeds on the following log line (`fd308`, errno0). Every baseline raw open occurs after the measurement-finish command. The actual measured stressors cap/set/sigfd/eventfd/kill/futex/prctl returned0 (11.920441s baseline,12.090298s post); successful stressors therefore do not establish that Tracee's syscall programs were attached. The run also has the frozen one warmup, one10-second sample and stats enabled. Internal stats boundaries are not separately instrumented, but no raw attachment exists anywhere in the recorded post phase, and baseline attachment begins18.919968s after its measurement-finish request.

Frozen source at the guest-start commit96d6087d8 matches the current framework files byte-for-byte. `TraceeAgentSession.__enter__` accepts healthz OR any collected stdout/stderr, combined with shim program presence. `wait_for_app_shim_programs` accepts a quiet interval in the tracked program-ID list (normal2seconds, loadtime-plan15seconds); `TraceeRunner.start` then sleeps its fixed5seconds. These conditions can finish while Tracee is still loading programs and before raw syscall attachment. The log does not identify which healthz/output OR branch succeeded, so this report does not choose one. `measure_app_phase` then runs the unchanged workload immediately.

The baseline is thus an early-start measurement, not evidence of quiet attached syscall filters. In the post phase, native loading is still underway: the last recorded load is `trace_ptrace` at882.816000s, and the separately published service result includes its CHUNK ioctl ENOENT failure. The captured phase never reaches raw syscall attachment. The precise process-exit/kill cause and kernel ENOENT branch are not established here. This ordering also explains why Spark run8's active Tracee calls do not guarantee that the slower emulated guest exercises the same path.

No benchmark framework, readiness rule, settle duration, workload, timeout, architecture flags, kernel or timing entry changed. No idle-coverage repair or new workload success is claimed. The common ARM startup/native-load work remains relevant; changing frozen readiness would require the operator's authorization. The full scalar-memory compile/paired-verifier job and queued Tetragon stage2 continue independently.

`diagnosis.json` pins the input archive SHA, complete per-phase events/counts and exact framework-source hashes; `timeline.tsv` provides log line numbers. Four compressed evidence files preserve both complete shim logs, the app result and corpus result; `framework-source.txt` preserves the actual referenced functions. Evidence is written directly into these result files, with no new unarchived RAW directory. Original Tracee service/corpus inputs remain available for the subsequent CHUNK investigation; FORMAL Cilium090610 and all active scalar inputs are untouched.
