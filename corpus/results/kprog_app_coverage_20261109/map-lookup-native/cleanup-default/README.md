# Matched native array cleanup with default register allocation

The control and candidate keep the original source, normal/cold inline1000 and default native register allocation. Both lower the same array lookups; the candidate adds only standard SROA/InstCombine/SimplifyCFG after lowering. The paired balancer component emits9049control versus8701candidate executable bytes. Complete4object paired payload follows. Frozen workload, kernel, simulator and original38inputs retain their definitions; timing and generation-bound acceptance are separate actual observations.

Complete paired4object control/candidate payloads are in payload.tar.gz, with manifests, plugins, exact commands and source/object hashes. Both use the same original source and default register allocation, and both lower21array sites. The candidate differs only by the standard cleanup pipeline. R times the unbound pair against the frozen JIT arm; native acceptance remains a separate actual run.
