// Observe native stack releases before the simulator runs. Hardware execution
// breakpoints leave the instruction bytes intact; no child signal handler runs.
#include <elf.h>
#include <gelf.h>
#include <libelf.h>
#include <sys/mman.h>
#include <sys/ptrace.h>
#include <sys/stat.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

static void require(bool ok, const std::string &message)
{
    if (!ok) throw std::runtime_error(message);
}
static void system_ok(bool ok, const char *operation)
{
    if (!ok) throw std::runtime_error(std::string(operation) + ": " + strerror(errno));
}
static void trace(enum __ptrace_request request, pid_t pid,
                  uintptr_t address = 0, uintptr_t data = 0)
{
    system_ok(ptrace(request, pid, (void *)address, (void *)data) != -1, "ptrace");
}
static uint64_t peek(pid_t pid, uintptr_t address)
{
    errno = 0;
    long value = ptrace(PTRACE_PEEKDATA, pid, (void *)address, nullptr);
    system_ok(value != -1 || errno == 0, "ptrace read");
    return (uint64_t)value;
}
static int wait_child(pid_t pid)
{
    int status;
    pid_t result;
    do result = waitpid(pid, &status, 0); while (result < 0 && errno == EINTR);
    system_ok(result == pid, "waitpid");
    return status;
}
static void trapped(int status)
{
    require(WIFSTOPPED(status) && WSTOPSIG(status) == SIGTRAP,
            "child did not stop at the expected hardware/step trap: " + std::to_string(status));
}
static user_regs_struct registers(pid_t pid)
{
    user_regs_struct regs;
    trace(PTRACE_GETREGS, pid, 0, (uintptr_t)&regs);
    return regs;
}
static void debug_register(pid_t pid, unsigned index, uint64_t value)
{
    trace(PTRACE_POKEUSER, pid, offsetof(struct user, u_debugreg) + index * sizeof(uint64_t), value);
}
static std::map<std::string, uint64_t> symbols(const char *path)
{
    require(elf_version(EV_CURRENT) != EV_NONE, "libelf initialization failed");
    int fd = open(path, O_RDONLY);
    system_ok(fd >= 0, "open observer ELF");
    Elf *elf = elf_begin(fd, ELF_C_READ, nullptr);
    require(elf != nullptr, "cannot read observer ELF");
    GElf_Ehdr ehdr;
    require(gelf_getehdr(elf, &ehdr) && ehdr.e_type == ET_EXEC && ehdr.e_machine == EM_X86_64,
            "observer must be a fixed-address x86 executable");
    std::map<std::string, uint64_t> out;
    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf, section))) {
        GElf_Shdr header;
        require(gelf_getshdr(section, &header), "cannot read ELF section");
        if (header.sh_type != SHT_SYMTAB) continue;
        Elf_Data *data = elf_getdata(section, nullptr);
        require(data && header.sh_entsize, "missing ELF symbols");
        for (size_t i = 0; i < header.sh_size / header.sh_entsize; ++i) {
            GElf_Sym sym;
            require(gelf_getsym(data, i, &sym), "cannot read ELF symbol");
            if (sym.st_shndx == SHN_UNDEF) continue;
            const char *name = elf_strptr(elf, header.sh_link, sym.st_name);
            require(name, "missing ELF symbol name");
            out[name] = sym.st_value;
        }
    }
    require(elf_end(elf) == 0, "cannot finish ELF read");
    system_ok(close(fd) == 0, "close observer ELF");
    return out;
}
static void publish(int fd, const std::vector<uint64_t> &words)
{
    std::vector<uint64_t> stream{words.size()};
    stream.insert(stream.end(), words.begin(), words.end());
    size_t bytes = stream.size() * sizeof(uint64_t);
    system_ok(ftruncate(fd, bytes) == 0, "resize input stream");
    size_t offset = 0;
    while (offset < bytes) {
        ssize_t wrote = pwrite(fd, (const char *)stream.data() + offset, bytes - offset, offset);
        if (wrote < 0 && errno == EINTR) continue;
        system_ok(wrote > 0, "write input stream");
        offset += wrote;
    }
}

int main(int argc, char **argv)
{
    pid_t child = -1;
    try {
        require(argc == 5, "usage: control-trace OBSERVER CASES OUT TRACE");
        char *end;
        errno = 0;
        unsigned long cases = strtoul(argv[2], &end, 10);
        require(!errno && *end == 0 && cases && argv[2][0] != '-', "invalid case count");
        auto sym = symbols(argv[1]);
        std::ofstream log(std::string(argv[3]) + "/input-witnesses.jsonl");
        require(log.good(), "cannot open hardware witness log");
        int fd = memfd_create("kprog-control-hardware-inputs", 0);
        system_ok(fd >= 0, "memfd_create");
        child = fork();
        system_ok(child >= 0, "fork observer");
        if (!child) {
            if (ptrace(PTRACE_TRACEME, 0, nullptr, nullptr) == -1) { perror("PTRACE_TRACEME"); _exit(126); }
            execl(argv[1], argv[1], argv[2], argv[3], argv[4], (char *)nullptr);
            perror("exec observer"); _exit(127);
        }
        trapped(wait_child(child));
        trace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_EXITKILL);
        trace(PTRACE_POKEDATA, child, sym.at("control_input_fd"), fd);
        unsigned count = (unsigned)peek(child, sym.at("form_count"));
        require(count > 0, "empty observer form matrix");
        std::vector<uint64_t> starts, ends;
        std::vector<unsigned long> seen(count, 0);
        for (unsigned i = 0; i < count; ++i) {
            starts.push_back(sym.at("native_pc_" + std::to_string(i)));
            ends.push_back(sym.at("native_next_" + std::to_string(i)));
            require(ends.back() > starts.back(), "invalid native body interval");
        }
        unsigned current = 0;
        auto arm = [&] {
            debug_register(child, 7, 0);
            debug_register(child, 0, starts[current]);
            debug_register(child, 1, current + 1 < count ? starts[current + 1] : 0);
            debug_register(child, 6, 0);
            debug_register(child, 7, current + 1 < count ? 5 : 1);
        };
        arm();
        trace(PTRACE_CONT, child);
        for (;;) {
            int status = wait_child(child);
            if (WIFEXITED(status)) {
                child = -1;
                for (unsigned i = 0; i < count; ++i)
                    require(seen[i] == cases, "native case coverage incomplete at form " + std::to_string(i));
                log.close();
                require(log.good(), "writing hardware witnesses failed");
                system_ok(close(fd) == 0, "close input stream");
                return WEXITSTATUS(status);
            }
            trapped(status);
            auto regs = registers(child);
            if (current + 1 < count && regs.rip == starts[current + 1]) {
                require(seen[current] == cases, "native form changed before all cases ran");
                ++current;
            }
            require(regs.rip == starts[current], "unexpected hardware breakpoint address");
            debug_register(child, 7, 0);
            uint64_t origin = regs.rsp;
            require(peek(child, sym.at("native_stack_base")) == origin, "native arena origin mismatch");
            std::vector<uint64_t> words;
            log << "{\"form\":" << current << ",\"case\":" << seen[current]
                << ",\"entry\":" << starts[current] << ",\"end\":" << ends[current]
                << ",\"stack_base\":" << origin << ",\"releases\":[";
            bool first = true;
            while (regs.rip != ends[current]) {
                require(regs.rip >= starts[current] && regs.rip < ends[current], "native control escaped body");
                auto before = regs;
                trace(PTRACE_SINGLESTEP, child);
                trapped(wait_child(child));
                regs = registers(child);
                if (regs.rsp <= before.rsp) continue;
                log << (first ? "" : ",") << "{\"pc\":" << before.rip
                    << ",\"next_pc\":" << regs.rip << ",\"old_sp\":" << before.rsp
                    << ",\"new_sp\":" << regs.rsp << ",\"words\":[";
                bool first_word = true;
                // Whole arena cells, then partial boundary bytes, in the
                // shared input ABI's order. Values come from hardware memory
                // immediately after this instruction releases the interval.
                for (uint64_t address = origin - 64; address < origin; address += 8) {
                    unsigned width = address >= before.rsp && address + 8 <= regs.rsp ? 8 : 1;
                    for (unsigned lane = 0; lane < 8; lane += width) {
                        uint64_t at = address + lane;
                        if (at < before.rsp || at + width > regs.rsp) continue;
                        uint64_t value = peek(child, at);
                        if (width == 1) value &= 255;
                        words.push_back(value);
                        log << (first_word ? "" : ",") << "{\"address\":" << at
                            << ",\"width\":" << width << ",\"value\":" << value << "}";
                        first_word = false;
                    }
                }
                log << "]}";
                first = false;
            }
            log << "],\"word_count\":" << words.size() << "}\n";
            log.flush();
            require(log.good(), "writing hardware witness failed");
            publish(fd, words);
            ++seen[current];
            // TF/RF are debugger machinery, not arithmetic inputs. Do not
            // propagate them into the unchanged native observation wrapper.
            regs.eflags &= ~((1ULL << 8) | (1ULL << 16));
            trace(PTRACE_SETREGS, child, 0, (uintptr_t)&regs);
            arm();
            trace(PTRACE_CONT, child);
        }
    } catch (const std::exception &error) {
        fprintf(stderr, "control hardware trace: %s\n", error.what());
        if (child > 0) {
            if (kill(child, SIGKILL) && errno != ESRCH) perror("kill owned observer");
            int status;
            if (waitpid(child, &status, 0) < 0 && errno != ECHILD) perror("reap owned observer");
        }
        return 1;
    }
}
