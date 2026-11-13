/* Completed-load records retain every phase and serialize concurrent writers. */
#include "../libnativeloader/src/native_loader_timings.hpp"
#include <array>
#include <cstddef>
#include <exception>
#include <iostream>
#include <thread>

static_assert(offsetof(native_loader_c_result, prog_fd)==0);
static_assert(offsetof(native_loader_c_result, replaced)==4);
static_assert(offsetof(native_loader_c_result, error)==8);
static_assert(sizeof(native_loader_c_result::error)==65536);

int main(int argc, char **argv)
{
    try {
        if (argc!=2) throw std::runtime_error("provide persistent output directory");
        const auto root=std::filesystem::path(argv[1]);
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
