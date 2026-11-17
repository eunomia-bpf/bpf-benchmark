/* A failed native stub load is diagnosed from the verifier's own log, and the
 * line it is about precedes the summary: a tail kept from the end of a 238 KB
 * log starts after that line. NUL-separated segments do the same to any
 * consumer reading the message as a C string. */
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

int main()
{
    const std::string head = "0: R1=ctx() R10=fp0\n";
    const std::string failure =
        "112: (79) r3 = *(u64 *)(r1 +112)    ; R1=invalid\n"
        "R1 invalid mem access 'scalar'\n";
    const std::string summary =
        "processed 4502 insns (limit 1000000) max_states_per_insn 4 "
        "total_states 127 peak_states 127 mark_read 0\n";

    std::string text = head + failure;
    const size_t nul_at = 15000;
    while (text.size() < nul_at) text += "  ; R2=scalar() R3=scalar(id=12)\n";
    std::string tail = summary;
    while (text.size() + 1 + tail.size() < 20000) {
        tail = "  ; R4=fp-216 R5=0x2c " + std::to_string(tail.size()) + "\n" + tail;
    }

    std::vector<char> log(text.begin(), text.end());
    log.push_back('\0');
    log.insert(log.end(), tail.begin(), tail.end());
    const std::string kept = verifier_log_text(log, log.size());

    if (kept.find("R1 invalid mem access 'scalar'") == std::string::npos) {
        std::cerr << "failing line dropped; kept " << kept.size() << " of "
                  << log.size() << " bytes\n";
        return 1;
    }
    if (kept.find(summary) == std::string::npos) {
        std::cerr << "summary dropped; kept " << kept.size() << " bytes\n";
        return 1;
    }
    if (kept.find('\0') != std::string::npos) {
        std::cerr << "embedded NUL survives into the message\n";
        return 1;
    }
    if (kept.size() != log.size()) {
        std::cerr << "retained " << kept.size() << " of " << log.size() << " bytes\n";
        return 1;
    }
    std::cout << "verifier log retained whole, NUL segments separated\n";
}