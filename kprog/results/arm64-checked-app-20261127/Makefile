.PHONY: guest
guest:
	python3 guest_controller.py
.PHONY: link-build link-arm-build
link-build:
	prlimit --as=17179869184 taskset -c 16 cargo test --manifest-path ../../x86/native_lab/native_link/Cargo.toml --release -j 1
	prlimit --as=17179869184 taskset -c 16 cargo build --manifest-path ../../x86/native_lab/native_link/Cargo.toml --release -j 1
link-arm-build:
	CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=aarch64-linux-gnu-gcc prlimit --as=17179869184 taskset -c 16 cargo build --manifest-path ../../x86/native_lab/native_link/Cargo.toml --release --target aarch64-unknown-linux-gnu -j 1
.PHONY: section-replay
section-replay:
	python3 section_replay.py
