# Registered-kfunc native-only safety

The existing generic suite completes38cases through kernel-owned native submissions and the registered trusted specializer:9positive native executions and29unsafe refusals (22verifier,6specializer,1loader). Each request archive matches its source native SHA. Unsafe fixtures use load-only commands; positive controls execute bound TEST_RUN and match data0/retval2.

The suite uses the exact registered-kfunc x86 kernel, coherent caller/worker pair and matching standard module tree. `safety.tar.gz` captures commands, sources, binaries, service requests, outcomes and full surrounding guest evidence.

```sh
python3 /workspaces/.agent-state/kprog-lanes/C/cilium-matched-modules-replay/safety/check.py check
```

The enclosing driver later attempted a second registered service in the same guest and reached a startup/readiness parsing exception before Cilium. The completed38-case suite retains its own outcome domain. The fresh single-service Cilium result is recorded separately in [cilium-matched-runtime](../cilium-matched-runtime/README.md).
