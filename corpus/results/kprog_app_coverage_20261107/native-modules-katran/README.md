# katran: module epoch startup observations

Actual `x86_kvm_corpus_20261107_200111_941359`, existing whole-application startup through the common
native-only service, eight guest vCPUs/12GiB on20–23, one sample and duration two
seconds. The baseline reaches its startup prerequisite: tunnel4 insertion reports EINVAL and the kernel log attributes module BTF type/name validation.

| Baseline application entries observed | Feature probe attempts | Generated | Compiled | Accepted/bound | Specialization errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |

The service reports ready and receives zero native requests. The application
program denominator remains to be collected after successful startup. Actual
app/metadata status is error and outer driver status is0; coverage.json retains
those separate outcomes and every recorded source identity/drift field.

The captured image is a5b0 and boot image is2f12, while modules use the relinked
vmlinux76c6 base. The subsequent kernel-image-btf result completes incremental
bzImage packaging and records boot/module BTF equality for the next epoch.

coverage.json retains the startup diagnostics; service.tar.gz contains complete
kernel and registered-service logs; result.tar.gz contains the corpus tree;
launch.tar.gz contains commands, package manifest and source snapshots;
collection-evidence.tar.gz contains collector terminal output. Closed experiment
image tar and guest disk are retired. Application execution and universal safety
law responsibilities retain their respective runtime and formal evidence.
