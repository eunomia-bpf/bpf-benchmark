Existing libbpf resource-only preparation

The common direct producer uses the existing bpf_object__prepare API to create/pin maps+BTF and relocate source context while every program remains autoload=false. This API already serves finish_simulator_proof in the common loader. Program loading and program-array FD initialization remain separate program lifecycle operations. The previous app component preserved the execve_rate fd-2 initializer error from bpf_object__load.

The existing original global_func8 positive control and edited original Tetragon execve_send input are load-only components through source0 and the paired88a runtime. Complete original source resources and object-default global values remain captured; actual full-application data/counters retain their own phase. Runtime admission additions:0.
