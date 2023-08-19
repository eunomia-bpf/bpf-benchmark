# bpf-benchmark

A simple toolset to test the performance of various bpf runtime.

## Usage
- Install `clang` and `llvm`. If you are using `Debian`/`Ubuntu`, you can install them with `sudo apt install clang llvm`
- Get runtimes. Three runtimes were shipped, `llvm-jit`, `ebpf` and `ubpf`. If the executables don't work on your system, you can build them manually. 
- Install dependencies in `requirements.txt`
- Run `make -C bpf_progs`
- Run `run_benchmark.py`
- See output on the console, or images in `output`, or data json in `output/data.json`

## How to add a test
- Write an ebpf program, naming it `XXX.bpf.c` and put it in `bpf_progs`. It should contain a function with signature `unsigned long long bpf_main(void* mem)`. Other functions must be inlined (using `__always_inline`).
- (Optional) Write an file named `XXX.mem`, which will be used to be passed to the ebpf program when being executed, if available 
