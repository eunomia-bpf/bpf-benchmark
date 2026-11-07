/* Load unsafe mutations inside the real app's intercepted loader call.
 * Only the unchanged successful replacement is returned to the application.
 */
#include "../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <dlfcn.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <set>
#include <sstream>
#include <stdexcept>

namespace {
using Load = decltype(&native_loader_load_from_fd_with_manifest_path_btf_and_context);
struct Case { std::string symbol, name, manifest; };
std::mutex lock;
std::set<std::string> completed;

const char *required(const char *name)
{
    const char *value = std::getenv(name);
    if (!value || !*value) throw std::runtime_error(std::string("missing ") + name);
    return value;
}

std::string quote(const std::string &value)
{
    std::ostringstream out;
    out << '"';
    for (unsigned char c : value) {
        if (c == '"' || c == '\\') out << '\\' << c;
        else if (c < 32) out << "\\u" << std::hex << std::setw(4) << std::setfill('0') << unsigned(c);
        else out << c;
    }
    out << '"';
    return out.str();
}

struct Real {
    void *handle;
    Load load;
    unsigned (*abi)();
    Real() : handle(dlopen(required("F_REAL_NATIVE_LOADER_SO"), RTLD_NOW | RTLD_LOCAL))
    {
        if (!handle) throw std::runtime_error(dlerror());
        load = reinterpret_cast<Load>(dlsym(handle, "native_loader_load_from_fd_with_manifest_path_btf_and_context"));
        abi = reinterpret_cast<unsigned (*)()>(dlsym(handle, "native_loader_bound_proof_abi_version"));
        if (!load || !abi) throw std::runtime_error("real loader lacks its context-aware bound ABI");
    }
};
Real &real() { static Real instance; return instance; }

void append(const std::string &record)
{
    std::ofstream out(required("F_NATIVE_NEGATIVE_LOG"), std::ios::app);
    out.exceptions(std::ios::failbit | std::ios::badbit);
    out << record << '\n';
    out.close();
}

unsigned generations(int fd)
{
    bpf_prog_info info{};
    uint32_t size = sizeof(info);
    if (bpf_obj_get_info_by_fd(fd, &info, &size)) throw std::runtime_error("read bound program info failed");
    if (!info.xlated_prog_len || info.xlated_prog_len % sizeof(bpf_insn))
        throw std::runtime_error("invalid bound instruction size");
    std::vector<bpf_insn> insns(info.xlated_prog_len / sizeof(bpf_insn));
    info = {};
    info.xlated_prog_len = insns.size() * sizeof(bpf_insn);
    info.xlated_prog_insns = reinterpret_cast<uintptr_t>(insns.data());
    if (bpf_obj_get_info_by_fd(fd, &info, &size)) throw std::runtime_error("read bound instructions failed");
    unsigned count = 0;
    for (const auto &i : insns)
        if (i.code == (BPF_ALU64 | BPF_MOV | BPF_K) && i.src_reg == BPF_PSEUDO_KINSN_SIDECAR && i.imm)
            ++count;
    return count;
}

std::vector<Case> cases()
{
    std::ifstream input(required("F_NATIVE_NEGATIVE_CASES"));
    if (!input) throw std::runtime_error("open application negative case list failed");
    std::vector<Case> result;
    std::set<std::pair<std::string, std::string>> unique;
    for (std::string line; std::getline(input, line); ) {
        auto a = line.find('\t'), b = line.find('\t', a == std::string::npos ? 0 : a + 1);
        if (a == std::string::npos || b == std::string::npos || line.find('\t', b + 1) != std::string::npos)
            throw std::runtime_error("case list must contain symbol TAB case TAB absolute manifest");
        Case c{line.substr(0, a), line.substr(a + 1, b - a - 1), line.substr(b + 1)};
        if (c.symbol.empty() || c.name.empty() || c.manifest.empty() || c.manifest[0] != '/' ||
            !unique.emplace(c.symbol, c.name).second)
            throw std::runtime_error("invalid or duplicate application negative case");
        result.push_back(std::move(c));
    }
    if (input.bad() || result.empty()) throw std::runtime_error("empty or unreadable application negative case list");
    return result;
}
}

extern "C" unsigned native_loader_bound_proof_abi_version()
{
    try { return real().abi(); }
    catch (const std::exception &e) { std::fprintf(stderr, "application negative proxy: %s\n", e.what()); return 0; }
}

extern "C" int native_loader_load_from_fd_with_manifest_path_btf_and_context(
    int source_fd, const char *manifest, const char *source_path, const int *fd_array,
    uint32_t fd_count, uint32_t btf_id, const void *func_info, uint32_t func_count,
    uint32_t func_size, uint32_t expected_attach, uint32_t attach_btf,
    uint32_t attach_btf_obj, uint32_t attach_prog,
    const native_loader_source_load_context *context, native_loader_c_result *out)
{
    std::lock_guard guard(lock);
    int safe_fd = -1;
    try {
        auto call = [&](const char *path, native_loader_c_result *result) {
            return real().load(source_fd, path, source_path, fd_array, fd_count, btf_id,
                              func_info, func_count, func_size, expected_attach, attach_btf,
                              attach_btf_obj, attach_prog, context, result);
        };
        int status = call(manifest, out);
        if (status) return status;
        safe_fd = out->prog_fd;
        if (!out->replaced || safe_fd < 0) throw std::runtime_error("unchanged application control was not replaced");
        std::string symbol(out->selected_symbol);
        if (!completed.insert(symbol).second) return status;
        const auto controls = generations(safe_fd);
        if (!controls) throw std::runtime_error("unchanged application control has no bound generation");
        bpf_prog_info source{};
        uint32_t size = sizeof(source);
        if (bpf_obj_get_info_by_fd(source_fd, &source, &size)) throw std::runtime_error("read real source program info failed");
        std::ostringstream metadata;
        metadata << "\"symbol\":" << quote(symbol) << ",\"source_id\":" << source.id
                 << ",\"source_type\":" << source.type << ",\"source_name\":" << quote(source.name)
                 << ",\"source_btf_id\":" << btf_id << ",\"func_info_count\":" << func_count
                 << ",\"func_info_rec_size\":" << func_size << ",\"fd_array_count\":" << fd_count
                 << ",\"expected_attach_type\":" << expected_attach << ",\"attach_btf_id\":" << attach_btf
                 << ",\"prog_flags\":" << (context ? context->prog_flags : 0);
        append("{\"event\":\"control\"," + metadata.str() + ",\"native_id\":" +
               std::to_string(out->native_prog_id) + ",\"generations\":" + std::to_string(controls) + "}");
        for (const auto &test : cases()) {
            if (test.symbol != symbol) continue;
            native_loader_c_result candidate{};
            int rc = call(test.manifest.c_str(), &candidate);
            unsigned count = 0;
            if (!rc) {
                if (!candidate.replaced || candidate.prog_fd < 0) throw std::runtime_error("mutation returned no replacement");
                try { count = generations(candidate.prog_fd); }
                catch (...) { if (close(candidate.prog_fd)) std::abort(); throw; }
                if (close(candidate.prog_fd)) throw std::runtime_error("close accepted mutation failed");
                candidate.prog_fd = -1;
                if (!count) throw std::runtime_error("accepted mutation lacks a bound generation");
            } else if (candidate.prog_fd >= 0) {
                if (close(candidate.prog_fd)) throw std::runtime_error("close failed mutation descriptor failed");
                candidate.prog_fd = -1;
                throw std::runtime_error("failed mutation unexpectedly returned a descriptor");
            }
            append("{\"event\":\"mutation\"," + metadata.str() + ",\"case\":" + quote(test.name) +
                   ",\"manifest\":" + quote(test.manifest) + ",\"returncode\":" + std::to_string(rc) +
                   ",\"generations\":" + std::to_string(count) + ",\"error\":" + quote(candidate.error) + "}");
        }
        return status;
    } catch (const std::exception &e) {
        if (safe_fd >= 0 && close(safe_fd)) std::abort();
        if (out) { out->prog_fd = -1; std::snprintf(out->error, sizeof(out->error), "application negative proxy: %s", e.what()); }
        return -1;
    }
}
