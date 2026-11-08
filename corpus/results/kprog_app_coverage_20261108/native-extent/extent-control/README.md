# Exact native emission extent functional control

The paired candidate kernel/module use the native emit=false extent and request-owned emission storage. This control retains every original native instruction: scalar initialization,64 LEA instructions, retval2 and RET. Its264-byte original text exercises the former128-byte scratch boundary. The private producer uses64KiB transport chunks; original BCC/Katran replays retain their128-byte loader transport. Canonical source/runtime adoption follows the paired shared-build handoff.

| Native input | Compiled | Kernel status | TEST_RUN producer |
| --- | ---: | ---: | ---: |
| small | 1 | 0 | 0 |
| medium | 1 | 0 | 0 |

The earlier32780-byte control retains its original native input and both archived compiler outcomes. The host retry reaches Clang18 source-location exhaustion during macro expansion, before stock verification/JIT emission. Its actual compiler diagnosis remains a generator coverage item. This functional control supplies a separate measured extent domain.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/native-extent/extent-control/Makefile native replay
```

[summary.json](summary.json) holds observed stages and native joins; [raw.tar.gz](raw.tar.gz) retains actual source/native/BPF/compiler/verifier/execution records. Runtime admission additions0.
