#pragma once
#include "../include/native_loader.hpp"
#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <sstream>
#include <stdexcept>
#include <sys/file.h>
#include <sys/syscall.h>
#include <unistd.h>

namespace native_loader_detail {
/* A completed C-entry load emits one raw record when a path is selected. */
inline void append_timing_record(const std::string &path, int original_fd,
    const native_loader::LoadedProgram &loaded, uint64_t start_ns, uint64_t end_ns)
{
    if (path.empty()) return;
    const auto &t=loaded.timings;
    const long tid=syscall(SYS_gettid);
    if (tid<0) throw std::runtime_error("read loader timing tid: "+std::string(std::strerror(errno)));
    std::ostringstream record;
    record << "{\"pid\":" << getpid() << ",\"tid\":" << tid
        << ",\"original_fd\":" << original_fd << ",\"native_fd\":" << loaded.prog_fd
        << ",\"replaced\":" << (loaded.replaced ? "true" : "false")
        << ",\"start_ns\":" << start_ns << ",\"end_ns\":" << end_ns
        << ",\"total_ns\":" << end_ns-start_ns
        << ",\"source_context_ns\":" << t.source_context_ns
        << ",\"manifest_ns\":" << t.manifest_ns
        << ",\"companion_total_ns\":" << t.companion_total_ns
        << ",\"data_symbols_ns\":" << t.data_symbols_ns
        << ",\"companion_map_ptr_extract_ns\":" << t.companion_map_ptr_extract_ns
        << ",\"companion_lookup_spec_ns\":" << t.companion_lookup_spec_ns
        << ",\"cache_lookup_ns\":" << t.cache_lookup_ns
        << ",\"native_link_exec_ns\":" << t.native_link_exec_ns
        << ",\"native_link_read_ns\":" << t.native_link_read_ns
        << ",\"map_patch_ns\":" << t.map_patch_ns
        << ",\"upload_ns\":" << t.upload_ns
        << ",\"prog_load_ns\":" << t.prog_load_ns << "}\n";
    const std::string bytes=record.str();
    int fd=open(path.c_str(), O_WRONLY|O_CREAT|O_APPEND|O_CLOEXEC, 0600);
    if (fd<0) throw std::runtime_error("open loader timing log: "+std::string(std::strerror(errno)));
    int error=0;
    int lock_result;
    do { lock_result=flock(fd, LOCK_EX); } while (lock_result<0 && errno==EINTR);
    if (lock_result<0) error=errno;
    size_t offset=0;
    while (!error && offset<bytes.size()) {
        const ssize_t written=write(fd, bytes.data()+offset, bytes.size()-offset);
        if (written<0 && errno==EINTR) continue;
        if (written<=0) { error=written<0 ? errno : EIO; break; }
        offset+=static_cast<size_t>(written);
    }
    const int close_result=close(fd); // Closing releases the per-record file lock.
    if (close_result<0 && !error) error=errno;
    if (error) throw std::runtime_error("write/close loader timing log: "+std::string(std::strerror(error)));
}
}
