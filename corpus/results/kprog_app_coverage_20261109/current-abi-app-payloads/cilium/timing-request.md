# Cilium current native input handoff

Captured full configuration payload: `/var/tmp/kprog-tmp/C/current-abi-cilium-payload/payloads/cilium`, image destination `/artifacts/user/native-bpf/x86_64/cilium/`. Use the recorded configuration identity for this payload. The existing live paired compiler builds fresh configurations at startup from their actual headers; its current compiler/native-source closure accompanies producer.tar.gz. Retain the restored May29 workload/launcher and current external-thunk flags when producing P. R owns complete startup and packet/action/work accounting.

```sh
make -C /workspaces/repository __runtime-vm-corpus PLATFORM=kvm ARCH=x86 RUNTIME_CONTAINER_IMAGE="$R_IMAGE_WITH_C_P" SAMPLES=3 WORKLOAD_DURATION=180
```
