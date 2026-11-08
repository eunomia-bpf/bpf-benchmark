# Helper binding of the submitted native copy

The trusted worker supplies helper and map relocations for the native input that the specializer receives. Native-link resolves public map helper calls through its existing generic call path; direct-native invocations retain their existing map/CPU optimization hints. Functional tail-call ABI binding and ARM helper-call slots retain their definitions. Helper/map body optimization belongs in native compilation before submission, following the operator placement decision.

Warm static/shared loader, registered worker and service client builds complete with exit0. Existing service9 cases and actual BCC worker compilation controls complete with exit0. Whole BCC/Katran and original38 replay follow this loader epoch. All production source changes are in native_loader.cpp and native_loader_link_schema.hpp. This change adds runtime admission predicates0.
