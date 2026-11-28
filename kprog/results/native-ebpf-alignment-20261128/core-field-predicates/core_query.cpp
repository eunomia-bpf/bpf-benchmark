// Offline CO-RE calculation using the same libbpf resolver, no BPF loads or P edits.
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
extern "C" {
#include "btf.h"
#include "libbpf.h"
#include "relo_core.h"
int bpf_core_add_cands(struct bpf_core_cand *, size_t, const struct btf *, const char *, int, struct bpf_core_cand_list *);
}
static std::string q(const char *s) {
 std::string o="\""; if(s) for(const unsigned char c:std::string(s)) {
  if(c=='"'||c=='\\'){o+='\\';o+=char(c);} else if(c=='\n')o+="\\n";
  else if(c=='\r')o+="\\r"; else if(c=='\t')o+="\\t";
  else if(c<32){char b[8];snprintf(b,sizeof(b),"\\u%04x",c);o+=b;}else o+=char(c);
 } return o+'"';
}
static uint32_t u32(const unsigned char *p){uint32_t v;memcpy(&v,p,4);return v;}
struct Line {uint32_t off,file,text,loc;};
int main(int argc,char **argv) try {
 if(argc!=3)throw std::runtime_error("usage: core-query SOURCE_BPF_ELF TARGET_VMLINUX");
 btf_ext *ext=nullptr;btf *local=btf__parse_elf(argv[1],&ext);btf *target=btf__parse(argv[2],nullptr);
 if(libbpf_get_error(local)||libbpf_get_error(target))throw std::runtime_error("parse source/target BTF failed");
 std::cout<<"{\"source\":"<<q(argv[1])<<",\"target\":"<<q(argv[2])<<",\"rows\":[";
 uint32_t size=0;const auto *raw=ext?static_cast<const unsigned char*>(btf_ext__raw_data(ext,&size)):nullptr;
 std::map<std::string,std::vector<Line>> lines;std::map<uint32_t,std::vector<bpf_core_cand>> cache;
 std::map<uint32_t,size_t> kinds;bool first=true;unsigned errors=0;
 if(raw&&size>=32){
  const uint32_t hdr=u32(raw+4);
  auto block=[&](uint32_t off,uint32_t len,auto fn){
   if(!len)return;if(uint64_t(hdr)+off+len>size||len<4)throw std::runtime_error("bad BTF.ext block bounds");
   const unsigned char *p=raw+hdr+off,*end=p+len;uint32_t stride=u32(p);p+=4;
   while(p<end){if(end-p<8)throw std::runtime_error("bad sectionheader");auto name=btf__name_by_offset(local,u32(p));uint32_t n=u32(p+4);p+=8;
    if(!name||uint64_t(n)*stride>uint64_t(end-p))throw std::runtime_error("bad section records");
    for(uint32_t i=0;i<n;i++,p+=stride)fn(name,p,stride);
   }
  };
  block(u32(raw+16),u32(raw+20),[&](const char *sec,const unsigned char *p,uint32_t stride){if(stride<16)throw std::runtime_error("short lineinfo");lines[sec].push_back({u32(p),u32(p+4),u32(p+8),u32(p+12)});});
  block(u32(raw+24),u32(raw+28),[&](const char *sec,const unsigned char *p,uint32_t stride){
   if(stride<16)throw std::runtime_error("short coreinfo");bpf_core_relo relo{};memcpy(&relo,p,sizeof(relo));kinds[relo.kind]++;
   // Evaluate every relocation in ELF order: earlier records can prune candidates.
   // Retain other kinds too, rather than changing the predicate candidate history.
   const auto *type=btf__type_by_id(local,relo.type_id);if(!type)throw std::runtime_error("missing localtype");
   const char *name=btf__name_by_offset(local,type->name_off);if(!name)throw std::runtime_error("missing typename");
   auto it=cache.find(relo.type_id);
   if(it==cache.end()){
    bpf_core_cand origin{local,relo.type_id};bpf_core_cand_list found{};
    int rc=bpf_core_add_cands(&origin,bpf_core_essential_name_len(name),target,"vmlinux",1,&found);
    if(rc){free(found.cands);throw std::runtime_error("libbpf candidate search failed");}
    std::vector<bpf_core_cand> candidates;
    if(found.len)candidates.assign(found.cands,found.cands+found.len);
    free(found.cands);
    it=cache.emplace(relo.type_id,std::move(candidates)).first;
   }
   auto &v=it->second;bpf_core_cand_list candidates{v.data(),int(v.size())};bpf_core_spec scratch[3]{};bpf_core_relo_res res{};size_t before=v.size();
   int rc=bpf_core_calc_relo_insn(sec,&relo,0,local,&candidates,scratch,&res);if(rc)errors++;v.resize(candidates.len);
   char spec[2048]{};int formatted=bpf_core_format_spec(spec,sizeof(spec),&scratch[0]);
   const Line *line=nullptr;for(const auto &l:lines[sec])if(l.off<=relo.insn_off&&(!line||line->off<l.off))line=&l;
   if(!first)std::cout<<',';first=false;
   std::cout<<"{\"section\":"<<q(sec)<<",\"insn_off\":"<<relo.insn_off<<",\"kind\":"<<relo.kind<<",\"local_type_id\":"<<relo.type_id<<",\"local_type\":"<<q(name)<<",\"access\":"<<q(btf__name_by_offset(local,relo.access_str_off))<<",\"spec\":"<<q(formatted>=0?spec:nullptr)<<",\"status\":"<<rc<<",\"orig_val\":"<<res.orig_val<<",\"new_val\":"<<res.new_val<<",\"poison\":"<<(res.poison?"true":"false")<<",\"candidates_before\":"<<before<<",\"candidates_after\":"<<v.size();
   if(line)std::cout<<",\"file\":"<<q(btf__name_by_offset(local,line->file))<<",\"line\":"<<(line->loc>>10)<<",\"column\":"<<(line->loc&1023)<<",\"source_line\":"<<q(btf__name_by_offset(local,line->text));
   std::cout<<'}';
  });
 }
 std::cout<<"],\"errors\":"<<errors<<",\"core_kind_counts\":{";first=true;for(auto [kind,n]:kinds){if(!first)std::cout<<',';first=false;std::cout<<q(std::to_string(kind).c_str())<<':'<<n;}std::cout<<"},\"btf_ext_present\":"<<(ext?"true":"false")<<"}\n";
 btf_ext__free(ext);btf__free(local);btf__free(target);return errors?1:0;
} catch(const std::exception &e){std::cerr<<e.what()<<'\n';return 2;}
