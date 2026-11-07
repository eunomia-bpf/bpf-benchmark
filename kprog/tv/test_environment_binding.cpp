/* Catch forged exclusive sites, wrong opcode/width/order, missing markers and
 * LDDW continuations being mistaken for executable choice instructions.
 */
#include "../libnativeloader/src/native_environment_binding.hpp"
#include <cassert>
#include <iostream>

int main()
{
    // Catch disagreement between actual STXR field/overlap guards and all
    // four width/order encodings, including ZR/SP and every register triple.
    unsigned exclusive_words = 0;
    const bpf_insn marker = {.code = BPF_ALU64 | BPF_MOV | BPF_K,
        .dst_reg = 0, .src_reg = 9, .off = 5, .imm = -4};
    for (uint32_t width : {4U, 8U}) for (bool release : {false, true})
    for (uint32_t status = 0; status < 32; ++status)
    for (uint32_t source = 0; source < 32; ++source)
    for (uint32_t base = 0; base < 32; ++base) {
        const uint32_t word = 0x88007c00U | (width == 8 ? 1U << 30 : 0) |
            (release ? 1U << 15 : 0) | (status << 16) | (base << 5) | source;
        const unsigned char native[] = {uint8_t(word), uint8_t(word >> 8),
            uint8_t(word >> 16), uint8_t(word >> 24)};
        const bool expected = status != source && (base == 31 || status != base);
        assert(native_lab_exclusive_match(native, 4, 0, &marker, 1, 0, 0xfffffffcU) == expected);
        ++exclusive_words;
    }
    assert(exclusive_words == 131072);
    std::cout << "exclusive actual kernel matcher: 131072 width/order/register combinations PASS\n";
    for (uint32_t width : {4U, 8U}) for (bool release : {false, true}) {
        const uint32_t word = 0x88037c22U | (width == 8 ? 1U << 30 : 0) |
            (release ? 1U << 15 : 0); // STXR/STLXR w3,w/x2,[x1]
        std::vector<uint8_t> native{uint8_t(word),uint8_t(word >> 8),
            uint8_t(word >> 16),uint8_t(word >> 24)};
        const auto metadata = [&](const std::string &fields) {
            return "{\"version\":1,\"sites\":[{" + fields + "}]}";
        };
        const std::string fields = "\"source_pc\":16,\"offset\":0,\"width\":" +
            std::to_string(width) + ",\"release\":" + (release ? "true" : "false");
        auto sites = parse_native_environment_layout(metadata(fields), native);
        std::vector<bpf_insn> proof(2);
        proof[0] = {.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = 0,
            .src_reg = 9, .off = 5, .imm = 16};
        proof[1] = proof[0]; // Real compiler clones have independent visits.
        auto descriptors = bind_exclusive_environment(sites, native, proof);
        assert(descriptors.size() == 2 && descriptors[0].first == 0 &&
            descriptors[0].second == (uint64_t(16) << 32) &&
            descriptors[1].second == ((uint64_t(16) << 32) | 1));
        const auto reject = [](auto action) {
            try { action(); } catch (const std::runtime_error &) { return; }
            throw std::runtime_error("invalid exclusive binding accepted");
        };
        reject([&] { parse_native_environment_layout(metadata(fields + ",\"width\":4"), native); });
        reject([&] { parse_native_environment_layout(metadata(fields + ",\"unknown\":1"), native); });
        for (const auto &bad : {std::string("\"source_pc\":17,\"offset\":0,\"width\":4,\"release\":false"),
            std::string("\"source_pc\":16,\"offset\":1,\"width\":4,\"release\":false"),
            std::string("\"source_pc\":4294967296,\"offset\":0,\"width\":4,\"release\":false")})
            reject([&] { parse_native_environment_layout(metadata(bad), native); });
        std::string wrong = fields;
        const auto width_at = wrong.find("\"width\":") + 8;
        wrong[width_at] = width == 4 ? '8' : '4';
        reject([&] { parse_native_environment_layout(metadata(wrong), native); });
        wrong = fields.substr(0, fields.find("\"release\":")) + "\"release\":" + (release ? "false" : "true");
        reject([&] { parse_native_environment_layout(metadata(wrong), native); });
        reject([&] { parse_native_environment_layout(metadata(fields + "e0"), native); });
        reject([&] { parse_native_environment_layout("{\"version\":1,\"sites\":[{"+fields+"},]}", native); });
        native[3] ^= 4; // Different opcode, rather than another exclusive.
        reject([&] { parse_native_environment_layout(metadata(fields), native); });
        native[3] ^= 4;
        proof[0].imm = 20;
        reject([&] { bind_exclusive_environment(sites, native, proof); });
        proof[0].imm = 16; proof[0].dst_reg = 1;
        reject([&] { bind_exclusive_environment(sites, native, proof); });
        proof[0].dst_reg = 0;
        proof[0].code = BPF_LD | BPF_DW | BPF_IMM;
        reject([&] { bind_exclusive_environment(sites, native, proof); });
        proof.clear();
        reject([&] { bind_exclusive_environment(sites, native, proof); });
        proof = {{.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = 0,
            .src_reg = 9, .off = 5, .imm = 16}};
        reject([&] { bind_exclusive_environment({}, native, proof); });
        assert(!native_lab_exclusive_match(native.data(), 3, 0, proof.data(), 1, 0, 16));
        // A forged marker in the second LDDW word stays a continuation;
        // the next complete instruction remains an eligible boundary.
        auto scanner_proof = std::vector<bpf_insn>(3, proof[0]);
        scanner_proof[0].code = BPF_LD | BPF_DW | BPF_IMM;
        assert(!native_lab_exclusive_match(native.data(), 4, 0,
            scanner_proof.data(), 3, 1, 16));
        assert(native_lab_exclusive_match(native.data(), 4, 0,
            scanner_proof.data(), 3, 2, 16));
        // Status aliases source or base: constrained-unpredictable, no unique semantics.
        for (uint32_t status : {1U, 2U}) {
            const uint32_t alias = (word & ~(31U << 16)) | status << 16;
            native[2] = uint8_t(alias >> 16);
            reject([&] { parse_native_environment_layout(metadata(fields), native); });
        }
    }
    std::cout << "exclusive native bytes/source PC/width/order/marker binding regressions: PASS\n";
}
