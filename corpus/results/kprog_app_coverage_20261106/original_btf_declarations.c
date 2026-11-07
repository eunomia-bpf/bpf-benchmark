/* Preserve original map/value/global BTF types for static ELF linking. */
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <linux/btf.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct output { FILE *file; int error; };
static void print(void *opaque, const char *format, va_list arguments)
{
    struct output *out=opaque;
    if (vfprintf(out->file,format,arguments)<0) out->error=1;
}
int main(int argc,char **argv)
{
    if(argc!=3) return 2;
    struct btf *btf=btf__parse_elf(argv[1],NULL);
    if(libbpf_get_error(btf)) return 1;
    struct output out={.file=fopen(argv[2],"w")};
    if(!out.file) {btf__free(btf);return 1;}
    struct btf_dump *dump=btf_dump__new(btf,print,&out,NULL);
    if(libbpf_get_error(dump)) {fclose(out.file);btf__free(btf);return 1;}
    int failed=0;
    fputs("#include <linux/bpf.h>\n#include <bpf_helpers.h>\n",out.file);
    for(__u32 id=1;id<btf__type_cnt(btf);id++) {
        const struct btf_type *type=btf__type_by_id(btf,id);
        if(!btf_is_var(type)) continue;
        const char *name=btf__name_by_offset(btf,type->name_off);
        if(!name || !*name) {failed=1;break;}
        if(!strcmp(name,"LICENSE") || !strcmp(name,"_license")) continue;
        if(btf_dump__dump_type(dump,type->type)) {failed=1;break;}
        struct btf_dump_emit_type_decl_opts opts={.sz=sizeof(opts),.field_name=name};
        fputs("extern ",out.file);
        if(btf_dump__emit_type_decl(dump,type->type,&opts)) {failed=1;break;}
        fputs(";\n",out.file);
        if(printf("%s\n",name)<0) {failed=1;break;}
    }
    btf_dump__free(dump);btf__free(btf);
    if(ferror(out.file) || out.error) failed=1;
    if(fclose(out.file)) failed=1;
    if(fflush(stdout)) failed=1;
    return failed;
}
