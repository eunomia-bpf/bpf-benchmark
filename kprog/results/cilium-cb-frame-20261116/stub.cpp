// Frame-metadata serialization: a direct fallback must describe P's tail frame.
#include "../../libnativeloader/src/native_loader.cpp"
#include <cstdio>

int main()
{
    for (int fd : {-1, 0, 17}) {
        const auto code = native_stub_program(fd);
        const auto tail = std::find_if(code.begin(), code.end(), [](const auto &i) {
            return i.code == (BPF_JMP | BPF_CALL) && i.imm == BPF_FUNC_tail_call;
        });
        if (code.front().code != (BPF_ALU64 | BPF_MOV | BPF_K) ||
            code.front().dst_reg != BPF_REG_0 || code.front().imm != 0)
            return 1;
        if (fd < 0) {
            if (code.size() != 2 || tail != code.end() || code[1].code != (BPF_JMP | BPF_EXIT))
                return 2;
        } else {
            if (tail == code.end() || code[1].code != (BPF_JMP | BPF_JNE | BPF_K) ||
                code[1].dst_reg != BPF_REG_0 || code[1].imm != 0 ||
                code[3].code != (BPF_JMP | BPF_EXIT))
                return 3;
            const auto marker = 2 + code[1].off;
            if (marker < 0 || static_cast<size_t>(marker + 1) >= code.size() ||
                code[marker].code != (BPF_LD | BPF_DW | BPF_IMM) ||
                code[marker].dst_reg != BPF_REG_2 ||
                code[marker].src_reg != BPF_PSEUDO_MAP_FD || code[marker].imm != fd ||
                code[marker + 1].code != 0 || tail->dst_reg != 0 || tail->src_reg != 0)
                return 4;
        }
    }
    std::puts("{\"plain_and_tail_stub_contracts\":3,\"includes_fd_zero\":true}");
}
