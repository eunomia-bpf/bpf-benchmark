# Native caller passes map capabilities into the kernel-owned request

The native caller now retains deduplicated live map FDs for resolved native
object resources beyond the source program's map set. It submits those FDs
through SUBMIT_RESOURCES with native bytes, entry and typed metadata. The kernel
pins the actual objects in the immutable request; the registered service obtains
each declared identity and shape through the capsule MAP query. Source-only
submissions retain the original SUBMIT route.

The authenticated worker also resolves extra map aliases through capsule MAP,
compares the returned ID/type/key/value/count/flags with the reopened actual
object, and binds the native symbol to that object. The producer continues to
submit native inputs; common service generation, verifier access checks and
artifact binding carry their existing roles. This closes the source-only
metadata omission behind Cilium's native cilium_percpu_trace_id reference.

The private component build exits0 and the12existing service tests pass. One
changed C++ object uses canonical flags and retained worker/libbpf objects
to build the private DSO and trusted loader; shared runtime binaries retain
their captured bytes. Kernel dependency c94fbff015cf supplies the matching wire
and actual FD mutation/close/duplicate/invalid/omitted-resource controls.
The component's wire hash matches that published source. Whole Cilium runtime
adoption follows the current Tracee batch with a coherent private image/module.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/native-resource-caller/Makefile check
```

observations.json pins sources, binaries and the kernel dependency. raw.tar.gz
retains original/adopted caller/service, flags, component build logs and kernel
regression receipt. The earlier component receipt records its actual
pre-publication wire state separately. Universal request lifetime, resource
identity, ISA/token/native-link and binding laws provide the safety argument;
component checks and the ensuing application batch provide execution evidence.
