import io, os

os.chdir('/workspaces/repository')
BS = chr(92); QT = BS + '"'


def read(path):
    return io.open(path, encoding='utf-8').read().replace(chr(13), '')


def edit(path, pairs):
    t = io.open(path, encoding='utf-8').read()
    for a, b in pairs:
        assert t.count(a) == 1, (path, a)
        t = t.replace(a, b)
    io.open(path, 'w', encoding='utf-8').write(t)


S = 'kprog/x86/native_lab/native_link/src'
io.open(f'{S}/x86_task.rs', 'w', encoding='utf-8').write(read('/var/tmp/kprog-tmp/x86_task.rs'))
io.open('kprog/x86/native_lab/native_link/fixtures/task_driver.c', 'w', encoding='utf-8').write(read('/var/tmp/kprog-tmp/task_driver.c'))

edit(f'{S}/main.rs', [
    ('    #[serde(default)]\n    ktime: Option<RuntimeKtimeLayout>,\n}\n',
     '    #[serde(default)]\n    ktime: Option<RuntimeKtimeLayout>,\n'
     '    /// Credential facts for bpf_get_current_uid_gid; a boot without them keeps the helper call.\n'
     '    #[serde(default)]\n    cred: Option<RuntimeCredLayout>,\n}\n\n'
     '#[derive(Debug, Deserialize)]\nstruct RuntimeCredLayout {\n    task_cred: u32,\n    cred_uid: u32,\n    cred_gid: u32,\n}\n'),
])
edit(f'{S}/x86_probe_read.rs', [
    ('task_flags:0,task_personality:16,ktime:None,', 'task_flags:0,task_personality:16,ktime:None,cred:None,'),
    # Kernel strings: DEC ECX after the NUL branch ends the count with its own zero flag; a copied NUL is already
    # the terminator, so that branch lands after the final zero store.
    ('        b.extend_from_slice(&[0x88,0x07,0x48,0xff,0xc7,0x48,0xff,0xc6,0xff,0xc9,0x84,0xc0]);\n'
     '        let nul=append_x86_jcc_rel32(&mut b,0x84);\n'
     '        b.extend_from_slice(&[0x85,0xc9]);\n'
     '        let again=append_x86_jcc_rel32(&mut b,0x85);patch_x86_rel32(&mut b,again,loop_start)?;\n'
     '        let end=b.len();patch_x86_rel32(&mut b,nul,end)?;\n'
     '        b.extend_from_slice(&[0xc6,0x47,0xff,0,0x48,0x89,0xf8,0x4c,0x29,0xc0,0x48,0x63,0xc0]); // dst[-1]=0; length as signed int\n',
     '        b.extend_from_slice(&[0x88,0x07,0x48,0xff,0xc7,0x48,0xff,0xc6,0x84,0xc0]); // store; dst++; src++; test al,al\n'
     '        let nul=append_x86_jcc_rel32(&mut b,0x84);\n'
     '        b.extend_from_slice(&[0xff,0xc9]); // dec ecx: its zero flag ends the count\n'
     '        let again=append_x86_jcc_rel32(&mut b,0x85);patch_x86_rel32(&mut b,again,loop_start)?;\n'
     '        b.extend_from_slice(&[0xc6,0x47,0xff,0]); // count reached: dst[-1]=0\n'
     '        let end=b.len();patch_x86_rel32(&mut b,nul,end)?; // a copied NUL already ends the string\n'
     '        b.extend_from_slice(&[0x48,0x89,0xf8,0x4c,0x29,0xc0,0x48,0x63,0xc0]); // length as signed int\n'),
])
edit(f'{S}/x86.rs', [
    ('#[path = "x86_ktime.rs"]\nmod ktime;\n', '#[path = "x86_ktime.rs"]\nmod ktime;\n#[path = "x86_task.rs"]\nmod task;\n'),
    ('                show_lto_range(show, "ktime", range);\n                code_ranges.push(range);\n            }\n        }\n    }\n',
     '                show_lto_range(show, "ktime", range);\n                code_ranges.push(range);\n            }\n        }\n    }\n\n'
     '    // bpf_get_current_uid_gid calls reach one shared leaf that reads current->cred.\n'
     '    if let Some(layout) = runtime_probe_read_layout.filter(|_| !proof_mode) {\n'
     '        if let (Some(cred), Some(&helper)) = (layout.cred.as_ref(), helper_addrs.get("bpf_get_current_uid_gid")) {\n'
     '            if let Some(range) = task::share(&mut blob, &mut relocs, layout.current_task, cred, helper)? {\n'
     '                show_lto_range(show, "uid_gid", range);\n'
     '                code_ranges.push(range);\n'
     '            }\n        }\n    }\n'),
])
edit('kprog/libnativeloader/src/native_loader_lto.hpp', [
    ('    } catch (const std::runtime_error &) {\n    }\n    out << "}}";\n',
     '    } catch (const std::runtime_error &) {\n    }\n'
     '    // Credential facts for bpf_get_current_uid_gid: current->cred and its uid/gid.\n'
     '    try {\n'
     '        std::ostringstream c;\n'
     '        c << ",' + QT + 'cred' + QT + ':{' + QT + 'task_cred' + QT + ':" << offset(types, "task_struct", "cred")\n'
     '          << ",' + QT + 'cred_uid' + QT + ':" << offset(types, "cred", "uid", true)\n'
     '          << ",' + QT + 'cred_gid' + QT + ':" << offset(types, "cred", "gid", true) << "}";\n'
     '        out << c.str();\n'
     '    } catch (const std::runtime_error &) {\n    }\n'
     '    out << "}}";\n'),
])
print('edits ok')
