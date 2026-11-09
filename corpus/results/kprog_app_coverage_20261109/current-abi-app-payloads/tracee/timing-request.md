# tracee native input handoff

Complete native input: `/var/tmp/kprog-tmp/C/current-abi-app-payloads/payloads/tracee`. Image destination: `/artifacts/user/native-bpf/x86_64/tracee/`. Current producer source and artifact identities are in summary.json. Existing command shape, with R retaining its restored image and original arm controls:

```sh
make -C /workspaces/repository __runtime-vm-corpus PLATFORM=kvm ARCH=x86 RUNTIME_CONTAINER_IMAGE="$R_IMAGE_WITH_C_P" SAMPLES=3 WORKLOAD_DURATION=180
```

R records complete startup and work counters before attributing throughput. This handoff records native compiler outputs; current verifier and whole-work outcomes retain their own actual service receipts.
