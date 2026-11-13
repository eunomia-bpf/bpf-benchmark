/* Completed-load records retain every phase and serialize concurrent writers. */
#include "../libnativeloader/src/native_loader_timings.hpp"
#include "../libnativeloader/src/native_loader_manifest.hpp"
#include <array>
#include <cstddef>
#include <exception>
#include <iostream>
#include <thread>

static_assert(offsetof(native_loader_c_result, prog_fd)==0);
static_assert(offsetof(native_loader_c_result, replaced)==4);
static_assert(offsetof(native_loader_c_result, error)==8);
static_assert(sizeof(native_loader_c_result::error)==65536);

/* Metadata must follow the same program/type selection as the native object. */
static void manifest_cases(const std::filesystem::path &output)
{
    const auto root=output/("manifest-"+std::to_string(getpid()));
    std::filesystem::create_directory(root);
    const auto write=[&](const std::string &name, const std::string &bytes) {
        std::ofstream file;
        file.exceptions(std::ios::badbit|std::ios::failbit);
        file.open(root/name);
        file << bytes;
        file.close();
    };
    write("native.o", "resolver artifact marker\n");
    bpf_prog_info info{};
    std::strcpy(info.name, "entry");
    info.type=BPF_PROG_TYPE_KPROBE;
    const auto resolve=[&](const std::string &name, const std::string &objects) {
        write(name, "{\"objects\":["+objects+"]}");
        return resolve_native_manifest(root/name, info, {}, [](uint32_t) -> bpf_map_info {
            throw std::runtime_error("metadata selection unexpectedly requested a map");
        });
    };
    const std::string selected=R"({"program":"entry","prog_type":2,"native_object":"native.o","symbol":"entry")";
    for (const std::string suffix : {"}", ",\"loader_timing_log\":\"\"}"}) {
        const auto result=resolve("disabled-"+std::to_string(suffix.size())+".json", selected+suffix);
        if (!result || !result->loader_timing_log.empty())
            throw std::runtime_error("optional manifest timing default changed");
    }
    const std::string ignored=R"({"program":"other","native_object":"missing.o","loader_timing_log":"wrong"},{"program":"entry","prog_type":6,"native_object":"missing.o","loader_timing_log":"wrong"},)";
    const auto enabled=resolve("enabled.json", ignored+selected+R"(,"loader_timing_log":"/tmp/phase log\"quoted\".jsonl"})");
    if (!enabled || enabled->loader_timing_log!="/tmp/phase log\"quoted\".jsonl" ||
        enabled->native_object_path!=root/"native.o" || enabled->symbol_name!="entry")
        throw std::runtime_error("selected manifest timing path or object changed");
    const auto filtered=resolve("filtered.json", ignored+selected+"}");
    if (!filtered || !filtered->loader_timing_log.empty())
        throw std::runtime_error("another entry activated timing");
    const auto unmatched=resolve("unmatched.json", R"({"program":"other","native_object":"missing.o","loader_timing_log":"wrong"})");
    if (unmatched) throw std::runtime_error("unmatched manifest selected a native object");
    bool failed=false;
    try { resolve("type-error.json", selected+",\"loader_timing_log\":3}"); }
    catch (const std::runtime_error &) { failed=true; }
    if (!failed) throw std::runtime_error("timing metadata parse error was lost");
}

int main(int argc, char **argv)
{
    try {
        if (argc!=2) throw std::runtime_error("provide persistent output directory");
        const auto root=std::filesystem::path(argv[1]);
        manifest_cases(root);
        const auto path=root/("phases-"+std::to_string(getpid())+".jsonl");
        native_loader::LoadedProgram loaded{};
        loaded.prog_fd=23; loaded.replaced=true;
        loaded.timings={5,6,7,8,9,10,11,12,1,2,3,4};
        native_loader_detail::append_timing_record("", 0, loaded, 100, 200);
        if (std::filesystem::exists(path)) throw std::runtime_error("disabled log wrote output");
        std::array<std::thread,4> workers;
        std::array<std::exception_ptr,4> errors{};
        for (unsigned w=0;w<workers.size();++w)
            workers[w]=std::thread([&,w] {
                try {
                    for (unsigned i=0;i<20;++i)
                        native_loader_detail::append_timing_record(path, w*20+i, loaded, 100, 200);
                } catch (...) { errors[w]=std::current_exception(); }
            });
        for (auto &worker:workers) worker.join();
        for (const auto &error:errors) if (error) std::rethrow_exception(error);
        bool failed=false;
        try { native_loader_detail::append_timing_record(root/"absent"/"phases", 0, loaded, 100, 200); }
        catch (const std::runtime_error &error) {
            failed=std::string(error.what()).find("open loader timing log:")==0;
        }
        if (!failed) throw std::runtime_error("timing log open error was lost");
        std::cout << path.string() << '\n';
        return 0;
    } catch (const std::exception &error) { std::cerr << error.what() << '\n'; return 1; }
}
