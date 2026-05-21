module cilium-ebpf-shim-poc

go 1.25.0

require github.com/cilium/ebpf v0.0.0

require golang.org/x/sys v0.43.0 // indirect

replace github.com/cilium/ebpf => ../../../vendor/repos/cilium-ebpf
