# Tracee CMP representation and verified startup readiness

Actual whole-application batch x86_kvm_corpus_20261107_223700_265056
freshly generates/compiles6requests and binds the first5. Request6 finishes
compilation and reaches worker activation after the application closes; its
activation is refused. This stage precedes the request6verifier decision.
The original151-program JIT arm and native input7479850e2345 retain their
captured application/workload identities. All6terminal kernel native hashes
match their worker copies and receipts.

| Generated | Compiled | Bound | Worker activation failure | Confirmed verifier rejection |
| ---: | ---: | ---: | ---: | ---: |
|6|6|5|1|0|

The source runner uses a300-second readiness deadline. The captured common
service spans longer than that while processing the first6requests, and the
app closes with code-9 before request6activation. The source repair lets the
verified native phase wait for actual health through existing wait_healthy,
which continues to surface process exit and health-check errors. The JIT and
unbound phases retain their ordinary deadline. The existing incremental-corpus
test file passes16tests, including actual wait-loop regression with a simulated
400-second successful startup, ordinary phase deadlines and early app exit.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/tracee-verified-startup/Makefile check
```

The private CMP/read wrapper replaces the generated simulator include after
its original stack configuration and archives the actual compiled candidate C.
The two earlier compiler-wrapper attempts remain in compiler-include-diagnostic
and stack-include-diagnostic with complete source/commands/failure archives.
coverage.json and service/result/launch archives describe this corrected
wrapper epoch separately. readiness-fix.tar.gz retains original/adopted runner
and tests plus complete check output. The next whole-application retry combines
this source repair with the same native input and CMP/read representation.
Universal ISA/token/link/binding laws supply the safety argument; startup tests
and application archives provide the corresponding execution evidence.
