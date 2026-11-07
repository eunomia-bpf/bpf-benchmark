ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-x86-app-negative
.PHONY: proxy
proxy:
	install -d $(BUILD)
	g++ -std=c++20 -Wall -Wextra -Werror -O2 -fPIC -shared -D__EXPORTED_HEADERS__ -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/fidelity/application_negative_proxy.cpp $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -Wl,--exclude-libs,ALL -lelf -lz -ldl -pthread -o $(BUILD)/libapplication_negative_proxy.so
.PHONY: build
build:
	python3 $(ROOT)/kprog/fidelity/application_negative.py $(BUILD)/bcc
