#pragma once
#include <cstdint>
#include <map>
#include <set>
#include <string>
#include <vector>
struct LiftFunction {
    unsigned pc;
    std::string symbol;
    std::vector<uint8_t> bytes;
};
int lift_bpf_module(const std::vector<LiftFunction> &functions,
    const std::set<unsigned> &helpers, const std::map<unsigned,std::string> &calls,
    const char *output_path);
