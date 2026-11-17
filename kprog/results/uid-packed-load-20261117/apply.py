#!/usr/bin/env python3
"""Fuse adjacent immutable UID/GID fields and compact the existing leaf."""
from pathlib import Path
p=Path('kprog/x86/native_lab/native_link/src/x86_memory.rs');s=p.read_text()
old='    fn operand(bytes: &mut Vec<u8>, opcode: &[u8], offset: u32) {'
assert s.count(old)==1;s=s.replace(old,old.replace('    fn ','    pub(super) fn '));p.write_text(s)
p=Path('kprog/x86/native_lab/native_link/src/x86_task.rs');s=p.read_text()
old='''fn disp(value: u32) -> Result<[u8; 4]> {
    Ok(i32::try_from(value)?.to_le_bytes())
}'''
new='''fn load_field(bytes: &mut Vec<u8>, opcode: &[u8], offset: u32) -> Result<()> {
    let offset = i32::try_from(offset)?;
    memory::Routine::operand(bytes, opcode, offset as u32);
    Ok(())
}'''
assert s.count(old)==1;s=s.replace(old,new)
old='''    b.extend_from_slice(&[0x48,0x8b,0x80]); b.extend_from_slice(&disp(l.task_cred)?); // rax=current->cred
    b.extend_from_slice(&[0x8b,0x90]); b.extend_from_slice(&disp(l.cred_gid)?); // edx=cred->gid
    b.extend_from_slice(&[0x8b,0x80]); b.extend_from_slice(&disp(l.cred_uid)?); // eax=cred->uid
    b.extend_from_slice(&[0x48,0xc1,0xe2,0x20,0x48,0x09,0xd0,0xc3]); // rax|=rdx<<32; ret'''
new='''    load_field(&mut b, &[0x48,0x8b,0x80], l.task_cred)?; // rax=current->cred
    // Published credentials are immutable; the existing BTF facts require u32 fields.
    // On x86 the adjacent UID/GID pair already has the helper's packed order.
    if u64::from(l.cred_gid) == u64::from(l.cred_uid) + 4 {
        load_field(&mut b, &[0x48,0x8b,0x80], l.cred_uid)?;
    } else {
        load_field(&mut b, &[0x8b,0x90], l.cred_gid)?;
        load_field(&mut b, &[0x8b,0x80], l.cred_uid)?;
        b.extend_from_slice(&[0x48,0xc1,0xe2,0x20,0x48,0x09,0xd0]);
    }
    b.push(0xc3);'''
assert s.count(old)==1;s=s.replace(old,new)
old='''    Ok(b)
}'''
new='''    let (bytes, _, _) = probe_read::compact((b, Vec::new(), Vec::new()))?;
    Ok(bytes)
}'''
assert s.count(old)==1;s=s.replace(old,new)
old='''        fs::write(output.join("uid-gid.bin"), uid_gid(0, &layout)?)?;
        let run = std::process::Command::new(&driver).arg(output.join("uid-gid.bin")).output()?;
        fs::write(output.join("uid-gid.stdout"), &run.stdout)?; fs::write(output.join("uid-gid.stderr"), &run.stderr)?;
        assert!(run.status.success(), "uid_gid host execution: {} {}", run.status, String::from_utf8_lossy(&run.stderr));
        println!("{}", String::from_utf8_lossy(&run.stdout));'''
new='''        let mut layouts=vec![
            RuntimeCredLayout{task_cred:16,cred_uid:8,cred_gid:12},
            RuntimeCredLayout{task_cred:17,cred_uid:7,cred_gid:11},
            RuntimeCredLayout{task_cred:0,cred_uid:0,cred_gid:4},
            RuntimeCredLayout{task_cred:100,cred_uid:123,cred_gid:127},
            RuntimeCredLayout{task_cred:128,cred_uid:124,cred_gid:128},
            RuntimeCredLayout{task_cred:256,cred_uid:128,cred_gid:132},
            RuntimeCredLayout{task_cred:128,cred_uid:0,cred_gid:8},
            RuntimeCredLayout{task_cred:127,cred_uid:24,cred_gid:4},
            RuntimeCredLayout{task_cred:0,cred_uid:128,cred_gid:256}];
        if let Some(path)=std::env::var_os("NATIVE_LINK_TASK_LAYOUT") {
            let facts:serde_json::Value=serde_json::from_str(&fs::read_to_string(path)?)?;
            layouts.push(serde_json::from_value(facts["layout"].clone())?);
        }
        let mut sizes=String::from("layout task_cred uid gid packed bytes\\n");
        for (i,l) in layouts.iter().enumerate() {
            let bytes=uid_gid(0,l)?;
            let packed=u64::from(l.cred_gid)==u64::from(l.cred_uid)+4;
            let mut decoder=Decoder::new(64,&bytes,DecoderOptions::NONE);let mut reads=0;
            while decoder.can_decode() {
                let insn=decoder.decode();assert!(!insn.is_invalid());
                reads+=usize::from((0..insn.op_count()).any(|op|insn.op_kind(op)==OpKind::Memory));
            }
            assert_eq!(reads,if packed {3}else{4},"do not fuse nonadjacent/reversed fields");
            let name=if i==0 {"uid-gid".to_owned()}else{format!("uid-gid-layout{i}")};
            let binary=output.join(format!("{name}.bin"));fs::write(&binary,&bytes)?;
            let run=std::process::Command::new(&driver).arg(binary)
                .args([l.task_cred.to_string(),l.cred_uid.to_string(),l.cred_gid.to_string()]).output()?;
            fs::write(output.join(format!("{name}.stdout")),&run.stdout)?;
            fs::write(output.join(format!("{name}.stderr")),&run.stderr)?;
            assert!(run.status.success(),"UID layout{i}: {} {}",run.status,String::from_utf8_lossy(&run.stderr));
            println!("{}",String::from_utf8_lossy(&run.stdout));
            sizes.push_str(&format!("{i} {} {} {} {packed} {}\\n",l.task_cred,l.cred_uid,l.cred_gid,bytes.len()));
        }
        fs::write(output.join("uid-gid-sizes.txt"),sizes)?;'''
assert s.count(old)==1;s=s.replace(old,new);p.write_text(s)
p=Path('kprog/x86/native_lab/native_link/fixtures/task_driver.c')
assert 'task->cred 16, cred->uid 8, cred->gid 12' in p.read_text()
p.write_text(r'''#define _GNU_SOURCE
#include <assert.h>
#include <asm/prctl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <unistd.h>

/* Dynamic layouts catch unsafe adjacent-field fusion and displacement truncation.
 * The highest credential field ends at, or just before, an inaccessible page. */
static struct { void *current; } percpu;
static uint32_t next(uint32_t *state)
{
    *state = *state * 1664525u + 1013904223u;
    return *state;
}
int main(int argc, char **argv)
{
    assert(argc == 5);
    unsigned task_offset = strtoul(argv[2], NULL, 10);
    unsigned uid_offset = strtoul(argv[3], NULL, 10);
    unsigned gid_offset = strtoul(argv[4], NULL, 10);
    size_t extent = (uid_offset > gid_offset ? uid_offset : gid_offset) + 4u;
    assert(extent + 7 <= 4096); /* Test inputs, not a production layout limit. */
    FILE *f = fopen(argv[1], "rb"); assert(f);
    assert(!fseek(f, 0, SEEK_END)); long size = ftell(f); assert(size > 0); rewind(f);
    unsigned char *code = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_32BIT, -1, 0);
    assert(code != MAP_FAILED && fread(code, 1, size, f) == (size_t)size); assert(!fclose(f));
    assert(!mprotect(code, size, PROT_READ|PROT_EXEC));
    uint64_t (*uid_gid)(void) = (uint64_t (*)(void))code;
    unsigned char *task = calloc((size_t)task_offset + sizeof(void *), 1); assert(task);
    unsigned char *pages = mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    assert(pages != MAP_FAILED && !mprotect(pages + 4096, 4096, PROT_NONE));
    uintptr_t old_gs;
    assert(!syscall(SYS_arch_prctl, ARCH_GET_GS, &old_gs));
    assert(!syscall(SYS_arch_prctl, ARCH_SET_GS, &percpu));
    unsigned vectors = 0;
    uint32_t state = 0x9145abcd;
    static const uint32_t ids[][2] = {{0,0},{1000,2000},{0xfffffffeu,1},{0xffffffffu,0xffffffffu},{7,0xfffffffeu}};
    static const unsigned slacks[] = {0,1,3,7};
    for (unsigned a = 0; a < sizeof(slacks)/sizeof(slacks[0]); ++a) {
        unsigned char *cred = pages + 4096 - extent - slacks[a];
        memcpy(task + task_offset, &cred, sizeof(cred)); percpu.current = task;
        for (unsigned i = 0; i < 133; ++i) {
            uint32_t uid = i < 5 ? ids[i][0] : next(&state);
            uint32_t gid = i < 5 ? ids[i][1] : next(&state);
            assert(!mprotect(pages, 4096, PROT_READ|PROT_WRITE));
            memset(pages, 0xa5, 4096);
            memcpy(cred + uid_offset, &uid, sizeof(uid));
            memcpy(cred + gid_offset, &gid, sizeof(gid));
            assert(!mprotect(pages, 4096, PROT_READ));
            assert(uid_gid() == ((uint64_t)gid << 32 | uid)); ++vectors;
        }
    }
    percpu.current = NULL; assert(uid_gid() == (uint64_t)-22); ++vectors;
    assert(!syscall(SYS_arch_prctl, ARCH_SET_GS, old_gs));
    assert(!munmap(pages, 8192) && !munmap(code, size)); free(task);
    printf("uid_gid leaf: read-only/guard/unaligned/live IDs/NULL current, %u vectors PASS
", vectors);
    return 0;
}
''')
