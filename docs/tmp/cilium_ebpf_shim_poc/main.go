package main

/*
#include <errno.h>
#include <linux/perf_event.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <unistd.h>

static int poc_perf_event_open_tracepoint(uint64_t tracepoint_id) {
	struct perf_event_attr attr = {};
	attr.type = PERF_TYPE_TRACEPOINT;
	attr.size = sizeof(attr);
	attr.config = tracepoint_id;
	attr.sample_period = 1;
	attr.wakeup_events = 1;
	attr.disabled = 1;
	attr.inherit = 1;
	attr.exclude_kernel = 0;
	attr.exclude_hv = 1;
	return (int)syscall(SYS_perf_event_open, &attr, -1, 0, -1,
			    PERF_FLAG_FD_CLOEXEC);
}

static int poc_ioctl_set_bpf(int perf_fd, int prog_fd) {
	return ioctl(perf_fd, PERF_EVENT_IOC_SET_BPF, prog_fd);
}

static int poc_ioctl_enable(int perf_fd) {
	return ioctl(perf_fd, PERF_EVENT_IOC_ENABLE, 0);
}

static int poc_close_fd(int fd) {
	return close(fd);
}
*/
import "C"

import (
	"bufio"
	"encoding/json"
	"errors"
	"flag"
	"fmt"
	"net"
	"os"
	"os/exec"
	"path/filepath"
	"runtime"
	"strconv"
	"strings"
	"time"

	"github.com/cilium/ebpf"
	"github.com/cilium/ebpf/asm"
	"github.com/cilium/ebpf/link"
)

type executeResponse struct {
	Status       string                    `json:"status"`
	ErrorMessage string                    `json:"error_message"`
	PerProgram   map[string]programOutcome `json:"per_program"`
}

type programOutcome struct {
	Status  string        `json:"status"`
	Passes  []passOutcome `json:"passes"`
	Program programDetail `json:"program"`
}

type programDetail struct {
	ProgID   uint32 `json:"prog_id"`
	ProgName string `json:"prog_name"`
}

type passOutcome struct {
	Status string `json:"status"`
	Error  any    `json:"error"`
}

func main() {
	var passList string
	var bpfopt string
	var timeoutSeconds int
	flag.StringVar(&passList, "pass", "noop", "comma-separated bpfopt passes to run through shim")
	flag.StringVar(&bpfopt, "bpfopt", getenvDefault("BPFOPT_BIN", "bpfopt"), "bpfopt binary path")
	flag.IntVar(&timeoutSeconds, "timeout", 60, "bpfopt step timeout in seconds")
	flag.Parse()

	passes := parsePassList(passList)
	if len(passes) == 0 {
		exitf("-pass must not be empty")
	}
	if timeoutSeconds <= 0 {
		exitf("-timeout must be positive")
	}

	resources, err := loadPOCResources()
	if err != nil {
		exitf("%v", err)
	}

	socketPath, err := waitForShimSocket(os.Getpid(), 5*time.Second)
	if err != nil {
		exitf("%v", err)
	}
	fmt.Printf("using shim socket %s\n", socketPath)

	steps := make([]map[string]any, 0, len(passes))
	for _, passName := range passes {
		steps = append(steps, map[string]any{
			"name":      passName,
			"command":   buildPassCommand(timeoutSeconds, bpfopt, passName),
			"log_level": passLogLevel(passName),
		})
	}
	request := map[string]any{
		"cmd":   "execute_plan",
		"steps": steps,
	}

	raw, err := shimRequest(socketPath, request)
	if err != nil {
		exitf("shim execute_plan request: %v", err)
	}
	fmt.Printf("shim response: %s\n", raw)

	resp, err := validateExecuteResponse(raw)
	if err != nil {
		exitf("execute_plan failed: %v", err)
	}
	if err := resources.verifyCgroupLinkUpdated(resp); err != nil {
		exitf("execute_plan did not update cgroup link: %v", err)
	}
	if err := resources.verifyProgAttachUpdated(resp); err != nil {
		exitf("execute_plan did not update BPF_PROG_ATTACH cgroup: %v", err)
	}
	if err := resources.verifyRawTracepointUpdated(resp); err != nil {
		exitf("execute_plan did not update raw tracepoint: %v", err)
	}
	if err := resources.verifyXDPAttachUpdated(resp); err != nil {
		exitf("execute_plan did not update XDP attach: %v", err)
	}
	if err := resources.cleanup(); err != nil {
		exitf("cleanup: %v", err)
	}

	runtime.KeepAlive(resources)
	fmt.Println("cilium/ebpf map load, corpus attach families, and execute_plan completed")
}

type pocResources struct {
	counter              *ebpf.Map
	mapProgram           *ebpf.Program
	cgroupProgram        *ebpf.Program
	cgroupLink           *link.RawLink
	cgroupFile           *os.File
	cgroupPath           string
	progAttachProgram    *ebpf.Program
	progAttachFile       *os.File
	progAttachPath       string
	rawTraceProgram      *ebpf.Program
	rawTraceLink         link.Link
	perfProgram          *ebpf.Program
	perfFD               int
	xdpProgram           *ebpf.Program
	xdpIface             string
	xdpPeer              string
	xdpAttachedByBPFTOOL bool
}

func loadPOCResources() (*pocResources, error) {
	counter, mapProgram, err := loadMapProgram()
	if err != nil {
		return nil, err
	}
	resources := &pocResources{
		counter:    counter,
		mapProgram: mapProgram,
		perfFD:     -1,
	}
	cgroupProgram, cgroupLink, cgroupFile, cgroupPath, err := loadCgroupLinkProgram()
	if err != nil {
		return nil, errors.Join(err, resources.cleanup())
	}
	resources.cgroupProgram = cgroupProgram
	resources.cgroupLink = cgroupLink
	resources.cgroupFile = cgroupFile
	resources.cgroupPath = cgroupPath

	progAttachProgram, progAttachFile, progAttachPath, err := loadProgAttachCgroupProgram()
	if err != nil {
		return nil, errors.Join(err, resources.cleanup())
	}
	resources.progAttachProgram = progAttachProgram
	resources.progAttachFile = progAttachFile
	resources.progAttachPath = progAttachPath

	rawTraceProgram, rawTraceLink, err := loadRawTracepointProgram()
	if err != nil {
		return nil, errors.Join(err, resources.cleanup())
	}
	resources.rawTraceProgram = rawTraceProgram
	resources.rawTraceLink = rawTraceLink

	perfProgram, perfFD, err := loadPerfEventIoctlProgram()
	if err != nil {
		return nil, errors.Join(err, resources.cleanup())
	}
	resources.perfProgram = perfProgram
	resources.perfFD = perfFD

	xdpProgram, xdpIface, xdpPeer, err := loadExternalXDPProgram()
	if err != nil {
		return nil, errors.Join(err, resources.cleanup())
	}
	resources.xdpProgram = xdpProgram
	resources.xdpIface = xdpIface
	resources.xdpPeer = xdpPeer
	resources.xdpAttachedByBPFTOOL = true

	return resources, nil
}

func loadMapProgram() (*ebpf.Map, *ebpf.Program, error) {
	counter, err := ebpf.NewMap(&ebpf.MapSpec{
		Name:       "cilium_shim_map",
		Type:       ebpf.Array,
		KeySize:    4,
		ValueSize:  4,
		MaxEntries: 1,
	})
	if err != nil {
		return nil, nil, fmt.Errorf("create cilium/ebpf map: %w", err)
	}
	if err := counter.Put(uint32(0), uint32(7)); err != nil {
		closeErr := counter.Close()
		if closeErr != nil {
			return nil, nil, fmt.Errorf("seed cilium/ebpf map: %w; close map: %w", err, closeErr)
		}
		return nil, nil, fmt.Errorf("seed cilium/ebpf map: %w", err)
	}

	prog, err := ebpf.NewProgram(&ebpf.ProgramSpec{
		Name:         "cilium_map_poc",
		Type:         ebpf.SocketFilter,
		License:      "GPL",
		Instructions: socketFilterMapProgram(counter.FD()),
	})
	if err != nil {
		closeErr := counter.Close()
		if closeErr != nil {
			return nil, nil, fmt.Errorf("load map-referencing cilium/ebpf program: %w; close map: %w", err, closeErr)
		}
		return nil, nil, fmt.Errorf("load map-referencing cilium/ebpf program: %w", err)
	}

	var got uint32
	if err := counter.Lookup(uint32(0), &got); err != nil {
		closeErr := counter.Close()
		if closeErr != nil {
			return nil, nil, fmt.Errorf("lookup cilium/ebpf map: %w; close map: %w", err, closeErr)
		}
		return nil, nil, fmt.Errorf("lookup cilium/ebpf map: %w", err)
	}
	if got != 7 {
		closeErr := counter.Close()
		if closeErr != nil {
			return nil, nil, fmt.Errorf("cilium/ebpf map value %d, want 7; close map: %w", got, closeErr)
		}
		return nil, nil, fmt.Errorf("cilium/ebpf map value %d, want 7", got)
	}

	fmt.Printf("loaded map program fd=%d map_fd=%d map_value=%d pid=%d\n", prog.FD(), counter.FD(), got, os.Getpid())
	return counter, prog, nil
}

func socketFilterMapProgram(mapFD int) asm.Instructions {
	return asm.Instructions{
		asm.StoreImm(asm.RFP, -4, 0, asm.Word),
		asm.LoadMapPtr(asm.R1, mapFD),
		asm.Mov.Reg(asm.R2, asm.RFP),
		asm.Add.Imm(asm.R2, -4),
		asm.FnMapLookupElem.Call(),
		asm.JEq.Imm(asm.R0, 0, "miss"),
		asm.LoadMem(asm.R0, asm.R0, 0, asm.Word),
		asm.Return(),
		asm.Mov.Imm(asm.R0, 0).WithSymbol("miss"),
		asm.Return(),
	}
}

func loadCgroupLinkProgram() (*ebpf.Program, *link.RawLink, *os.File, string, error) {
	cgroupPath, err := createTempCgroup()
	if err != nil {
		return nil, nil, nil, "", err
	}
	cgroupFile, err := os.Open(cgroupPath)
	if err != nil {
		removeErr := os.Remove(cgroupPath)
		if removeErr != nil {
			return nil, nil, nil, "", fmt.Errorf("open temp cgroup: %w; remove temp cgroup: %w", err, removeErr)
		}
		return nil, nil, nil, "", fmt.Errorf("open temp cgroup: %w", err)
	}

	prog, err := ebpf.NewProgram(&ebpf.ProgramSpec{
		Name:         "cilium_link_poc",
		Type:         ebpf.CGroupSKB,
		AttachType:   ebpf.AttachCGroupInetEgress,
		License:      "MIT",
		Instructions: simpleReturnProgram(1),
	})
	if err != nil {
		cleanupErr := cleanupCgroup(cgroupFile, cgroupPath)
		if cleanupErr != nil {
			return nil, nil, nil, "", fmt.Errorf("load cgroup link program: %w; cleanup cgroup: %w", err, cleanupErr)
		}
		return nil, nil, nil, "", fmt.Errorf("load cgroup link program: %w", err)
	}

	rawLink, err := link.AttachRawLink(link.RawLinkOptions{
		Target:  int(cgroupFile.Fd()),
		Program: prog,
		Attach:  ebpf.AttachCGroupInetEgress,
	})
	if err != nil {
		cleanupErr := cleanupCgroup(cgroupFile, cgroupPath)
		if cleanupErr != nil {
			return nil, nil, nil, "", fmt.Errorf("attach cgroup BPF link: %w; cleanup cgroup: %w", err, cleanupErr)
		}
		return nil, nil, nil, "", fmt.Errorf("attach cgroup BPF link: %w", err)
	}

	info, err := rawLink.Info()
	if err != nil {
		closeErr := rawLink.Close()
		cleanupErr := cleanupCgroup(cgroupFile, cgroupPath)
		return nil, nil, nil, "", errors.Join(fmt.Errorf("query cgroup BPF link info: %w", err), closeErr, cleanupErr)
	}
	fmt.Printf("attached cgroup bpf_link fd=%d link_id=%d prog_id=%d cgroup=%s\n", rawLink.FD(), info.ID, info.Program, cgroupPath)
	return prog, rawLink, cgroupFile, cgroupPath, nil
}

func loadProgAttachCgroupProgram() (*ebpf.Program, *os.File, string, error) {
	cgroupPath, err := createTempCgroup()
	if err != nil {
		return nil, nil, "", err
	}
	cgroupFile, err := os.Open(cgroupPath)
	if err != nil {
		removeErr := os.Remove(cgroupPath)
		if removeErr != nil {
			return nil, nil, "", fmt.Errorf("open temp prog_attach cgroup: %w; remove temp cgroup: %w", err, removeErr)
		}
		return nil, nil, "", fmt.Errorf("open temp prog_attach cgroup: %w", err)
	}
	prog, err := ebpf.NewProgram(&ebpf.ProgramSpec{
		Name:         "cilium_prog_attach_poc",
		Type:         ebpf.CGroupSKB,
		AttachType:   ebpf.AttachCGroupInetIngress,
		License:      "MIT",
		Instructions: simpleReturnProgram(1),
	})
	if err != nil {
		cleanupErr := cleanupCgroup(cgroupFile, cgroupPath)
		return nil, nil, "", errors.Join(fmt.Errorf("load BPF_PROG_ATTACH cgroup program: %w", err), cleanupErr)
	}
	if err := link.RawAttachProgram(link.RawAttachProgramOptions{
		Target:  int(cgroupFile.Fd()),
		Program: prog,
		Attach:  ebpf.AttachCGroupInetIngress,
	}); err != nil {
		cleanupErr := cleanupCgroup(cgroupFile, cgroupPath)
		return nil, nil, "", errors.Join(fmt.Errorf("BPF_PROG_ATTACH cgroup program: %w", err), cleanupErr)
	}
	fmt.Printf("attached cgroup BPF_PROG_ATTACH prog_fd=%d cgroup=%s\n", prog.FD(), cgroupPath)
	return prog, cgroupFile, cgroupPath, nil
}

func loadRawTracepointProgram() (*ebpf.Program, link.Link, error) {
	prog, err := ebpf.NewProgram(&ebpf.ProgramSpec{
		Name:         "cilium_rawtp_poc",
		Type:         ebpf.RawTracepoint,
		License:      "MIT",
		Instructions: simpleReturnProgram(0),
	})
	if err != nil {
		return nil, nil, fmt.Errorf("load raw tracepoint program: %w", err)
	}
	rawLink, err := link.AttachRawTracepoint(link.RawTracepointOptions{
		Name:    "cgroup_mkdir",
		Program: prog,
	})
	if err != nil {
		return nil, nil, errors.Join(fmt.Errorf("BPF_RAW_TRACEPOINT_OPEN cgroup_mkdir: %w", err), prog.Close())
	}
	fmt.Printf("attached raw tracepoint prog_fd=%d\n", prog.FD())
	return prog, rawLink, nil
}

func loadPerfEventIoctlProgram() (*ebpf.Program, int, error) {
	tracepointID, err := readTracepointID("syscalls", "sys_enter_getpid")
	if err != nil {
		return nil, -1, err
	}
	prog, err := ebpf.NewProgram(&ebpf.ProgramSpec{
		Name:         "cilium_perf_ioctl_poc",
		Type:         ebpf.TracePoint,
		License:      "MIT",
		Instructions: simpleReturnProgram(0),
	})
	if err != nil {
		return nil, -1, fmt.Errorf("load perf-event ioctl tracepoint program: %w", err)
	}
	perfFD := int(C.poc_perf_event_open_tracepoint(C.uint64_t(tracepointID)))
	if perfFD < 0 {
		errno := errors.New("perf_event_open failed")
		closeErr := prog.Close()
		return nil, -1, errors.Join(errno, closeErr)
	}
	if rc := C.poc_ioctl_set_bpf(C.int(perfFD), C.int(prog.FD())); rc != 0 {
		err := errors.New("PERF_EVENT_IOC_SET_BPF failed")
		C.poc_close_fd(C.int(perfFD))
		return nil, -1, errors.Join(err, prog.Close())
	}
	if rc := C.poc_ioctl_enable(C.int(perfFD)); rc != 0 {
		err := errors.New("PERF_EVENT_IOC_ENABLE failed")
		C.poc_close_fd(C.int(perfFD))
		return nil, -1, errors.Join(err, prog.Close())
	}
	fmt.Printf("attached perf_event ioctl prog_fd=%d perf_fd=%d\n", prog.FD(), perfFD)
	return prog, perfFD, nil
}

func loadExternalXDPProgram() (*ebpf.Program, string, string, error) {
	iface := fmt.Sprintf("bpfrpoc%d", os.Getpid()%100000)
	peer := iface + "p"
	if err := runClean("ip", "link", "add", iface, "type", "veth", "peer", "name", peer); err != nil {
		return nil, "", "", err
	}
	cleanup := func() {
		_ = runClean("ip", "link", "del", iface)
	}
	if err := runClean("ip", "link", "set", iface, "up"); err != nil {
		cleanup()
		return nil, "", "", err
	}
	if err := runClean("ip", "link", "set", peer, "up"); err != nil {
		cleanup()
		return nil, "", "", err
	}
	prog, err := ebpf.NewProgram(&ebpf.ProgramSpec{
		Name:         "cilium_xdp_poc",
		Type:         ebpf.XDP,
		License:      "MIT",
		Instructions: simpleReturnProgram(2),
	})
	if err != nil {
		cleanup()
		return nil, "", "", fmt.Errorf("load XDP program: %w", err)
	}
	progID, err := currentProgramID(prog)
	if err != nil {
		cleanup()
		return nil, "", "", errors.Join(err, prog.Close())
	}
	if err := runClean("bpftool", "net", "attach", "xdpgeneric", "id", strconv.FormatUint(uint64(progID), 10), "dev", iface); err != nil {
		cleanup()
		return nil, "", "", errors.Join(fmt.Errorf("bpftool xdpgeneric attach: %w", err), prog.Close())
	}
	fmt.Printf("attached external XDP via bpftool prog_fd=%d prog_id=%d if=%s\n", prog.FD(), progID, iface)
	return prog, iface, peer, nil
}

func simpleReturnProgram(ret int32) asm.Instructions {
	return asm.Instructions{
		asm.Mov.Imm(asm.R0, ret),
		asm.Return(),
	}
}

func createTempCgroup() (string, error) {
	mount, err := cgroup2Mount()
	if err != nil {
		return "", err
	}
	path, err := os.MkdirTemp(mount, "bpfrejit-shim-poc-")
	if err != nil {
		return "", fmt.Errorf("create temp cgroup under %s: %w", mount, err)
	}
	return path, nil
}

func cgroup2Mount() (string, error) {
	raw, err := os.ReadFile("/proc/mounts")
	if err != nil {
		return "", fmt.Errorf("read /proc/mounts: %w", err)
	}
	for _, line := range strings.Split(string(raw), "\n") {
		fields := strings.Fields(line)
		if len(fields) >= 3 && fields[0] == "cgroup2" && fields[2] == "cgroup2" {
			return fields[1], nil
		}
	}
	return "", errors.New("cgroup2 mount not found")
}

func (r *pocResources) cleanup() error {
	/* The shim replaces and owns program fds during execute_plan, so this POC
	 * only closes resources whose fds are stable from the app's perspective. */
	var xdpDetach error
	if r.xdpAttachedByBPFTOOL && r.xdpIface != "" {
		xdpDetach = runClean("bpftool", "net", "detach", "xdpgeneric", "dev", r.xdpIface)
	}
	var xdpDelete error
	if r.xdpIface != "" {
		xdpDelete = runClean("ip", "link", "del", r.xdpIface)
	}
	var perfClose error
	if r.perfFD >= 0 {
		if rc := C.poc_close_fd(C.int(r.perfFD)); rc != 0 {
			perfClose = fmt.Errorf("close perf fd %d failed", r.perfFD)
		}
	}
	return errors.Join(
		closeLink(r.cgroupLink),
		closeLink(r.rawTraceLink),
		cleanupCgroup(r.cgroupFile, r.cgroupPath),
		cleanupCgroup(r.progAttachFile, r.progAttachPath),
		r.counter.Close(),
		perfClose,
		xdpDetach,
		xdpDelete,
	)
}

func (r *pocResources) verifyCgroupLinkUpdated(resp *executeResponse) error {
	want, err := programIDByName(resp, "cilium_link_poc")
	if err != nil {
		return err
	}
	info, err := r.cgroupLink.Info()
	if err != nil {
		return fmt.Errorf("query cgroup link after execute_plan: %w", err)
	}
	if uint32(info.Program) != want {
		return fmt.Errorf("cgroup link program id %d, want %d", info.Program, want)
	}
	fmt.Printf("verified cgroup bpf_link now points at prog_id=%d\n", want)
	return nil
}

func (r *pocResources) verifyProgAttachUpdated(resp *executeResponse) error {
	want, err := programIDByName(resp, "cilium_prog_attach_poc")
	if err != nil {
		return err
	}
	result, err := link.QueryPrograms(link.QueryOptions{
		Target: int(r.progAttachFile.Fd()),
		Attach: ebpf.AttachCGroupInetIngress,
	})
	if err != nil {
		return fmt.Errorf("query BPF_PROG_ATTACH cgroup: %w", err)
	}
	for _, program := range result.Programs {
		if uint32(program.ID) == want {
			fmt.Printf("verified BPF_PROG_ATTACH cgroup now points at prog_id=%d\n", want)
			return nil
		}
	}
	return fmt.Errorf("BPF_PROG_ATTACH cgroup missing prog_id=%d", want)
}

func (r *pocResources) verifyRawTracepointUpdated(resp *executeResponse) error {
	want, err := programIDByName(resp, "cilium_rawtp_poc")
	if err != nil {
		return err
	}
	raw, err := runCleanOutput("bpftool", "-j", "link", "show")
	if err != nil {
		return err
	}
	if !jsonContainsProgramID(raw, want) {
		return fmt.Errorf("bpftool link show missing raw tracepoint prog_id=%d", want)
	}
	fmt.Printf("verified raw tracepoint link now points at prog_id=%d\n", want)
	return nil
}

func (r *pocResources) verifyXDPAttachUpdated(resp *executeResponse) error {
	want, err := programIDByName(resp, "cilium_xdp_poc")
	if err != nil {
		return err
	}
	raw, err := runCleanOutput("bpftool", "-j", "net", "show", "dev", r.xdpIface)
	if err != nil {
		return err
	}
	if !jsonContainsProgramID(raw, want) {
		return fmt.Errorf("bpftool net show dev %s missing XDP prog_id=%d", r.xdpIface, want)
	}
	fmt.Printf("verified external XDP attach now points at prog_id=%d\n", want)
	return nil
}

func cleanupCgroup(cgroupFile *os.File, cgroupPath string) error {
	if cgroupFile == nil && cgroupPath == "" {
		return nil
	}
	var closeErr error
	if cgroupFile != nil {
		closeErr = cgroupFile.Close()
	}
	var removeErr error
	if cgroupPath != "" {
		removeErr = os.Remove(cgroupPath)
	}
	return errors.Join(closeErr, removeErr)
}

func closeLink(l link.Link) error {
	if l == nil {
		return nil
	}
	err := l.Close()
	if err != nil && strings.Contains(err.Error(), "bad file descriptor") {
		return nil
	}
	return err
}

func programIDByName(resp *executeResponse, name string) (uint32, error) {
	for _, program := range resp.PerProgram {
		if program.Program.ProgName == name {
			if program.Program.ProgID == 0 {
				return 0, fmt.Errorf("%s has zero prog_id in execute_plan response", name)
			}
			return program.Program.ProgID, nil
		}
	}
	return 0, fmt.Errorf("%s missing from execute_plan response", name)
}

func currentProgramID(prog *ebpf.Program) (uint32, error) {
	info, err := prog.Info()
	if err != nil {
		return 0, err
	}
	id, ok := info.ID()
	if !ok {
		return 0, errors.New("program info has no id")
	}
	return uint32(id), nil
}

func readTracepointID(group, name string) (uint64, error) {
	paths := []string{
		filepath.Join("/sys/kernel/tracing/events", group, name, "id"),
		filepath.Join("/sys/kernel/debug/tracing/events", group, name, "id"),
	}
	for _, path := range paths {
		raw, err := os.ReadFile(path)
		if err != nil {
			continue
		}
		id, err := strconv.ParseUint(strings.TrimSpace(string(raw)), 10, 64)
		if err != nil {
			return 0, fmt.Errorf("parse tracepoint id %s: %w", path, err)
		}
		return id, nil
	}
	return 0, fmt.Errorf("tracepoint id not found for %s/%s", group, name)
}

func runClean(name string, args ...string) error {
	_, err := runCleanOutput(name, args...)
	return err
}

func runCleanOutput(name string, args ...string) ([]byte, error) {
	cmd := exec.Command(name, args...)
	cmd.Env = envWithoutLDPreload(os.Environ())
	raw, err := cmd.CombinedOutput()
	if err != nil {
		return nil, fmt.Errorf("%s %s: %w: %s", name, strings.Join(args, " "), err, strings.TrimSpace(string(raw)))
	}
	return raw, nil
}

func envWithoutLDPreload(env []string) []string {
	out := make([]string, 0, len(env))
	for _, item := range env {
		if strings.HasPrefix(item, "LD_PRELOAD=") {
			continue
		}
		out = append(out, item)
	}
	return out
}

func jsonContainsProgramID(raw []byte, want uint32) bool {
	var value any
	if err := json.Unmarshal(raw, &value); err != nil {
		return false
	}
	return jsonValueContainsProgramID(value, want)
}

func jsonValueContainsProgramID(value any, want uint32) bool {
	switch v := value.(type) {
	case map[string]any:
		for key, item := range v {
			if (key == "id" || key == "prog_id") && jsonNumberEquals(item, want) {
				return true
			}
			if jsonValueContainsProgramID(item, want) {
				return true
			}
		}
	case []any:
		for _, item := range v {
			if jsonValueContainsProgramID(item, want) {
				return true
			}
		}
	}
	return false
}

func jsonNumberEquals(value any, want uint32) bool {
	switch v := value.(type) {
	case float64:
		return uint32(v) == want
	case string:
		parsed, err := strconv.ParseUint(v, 10, 32)
		return err == nil && uint32(parsed) == want
	default:
		return false
	}
}

func getenvDefault(key, fallback string) string {
	if v := strings.TrimSpace(os.Getenv(key)); v != "" {
		return v
	}
	return fallback
}

func parsePassList(raw string) []string {
	var passes []string
	for _, item := range strings.Split(raw, ",") {
		pass := strings.TrimSpace(item)
		if pass != "" {
			passes = append(passes, pass)
		}
	}
	return passes
}

func buildPassCommand(timeoutSeconds int, bpfopt string, passName string) string {
	base := fmt.Sprintf(
		"timeout %d %s --pass %s --input ${INPUT} --output ${OUTPUT} --report ${REPORT} --prog-type ${PROG_TYPE}",
		timeoutSeconds,
		shellQuote(bpfopt),
		shellQuote(passName),
	)
	switch passName {
	case "map_inline":
		return base + " --verifier-states ${VERIFIER_STATES} --target ${TARGET} -- --map-values ${MAP_VALUES} --map-ids ${MAP_IDS}"
	case "const_prop":
		return base + " --verifier-states ${VERIFIER_STATES} --target ${TARGET}"
	default:
		return base + " --target ${TARGET}"
	}
}

func passLogLevel(passName string) int {
	switch passName {
	case "map_inline", "const_prop":
		return 2
	default:
		return 1
	}
}

func waitForShimSocket(pid int, timeout time.Duration) (string, error) {
	deadline := time.Now().Add(timeout)
	candidates := shimSocketCandidates(pid)
	for {
		for _, candidate := range candidates {
			if _, err := os.Stat(candidate); err == nil {
				return candidate, nil
			}
		}
		if time.Now().After(deadline) {
			return "", fmt.Errorf("shim socket not found for pid %d; checked %s; set LD_PRELOAD to libbpfrejit_shim.so and keep BPFREJIT_SHIM_SOCK_DIR writable", pid, strings.Join(candidates, ", "))
		}
		time.Sleep(25 * time.Millisecond)
	}
}

func shimSocketCandidates(pid int) []string {
	name := "shim-" + strconv.Itoa(pid) + ".sock"
	candidates := make([]string, 0, 3)
	if dir := strings.TrimSpace(os.Getenv("BPFREJIT_SHIM_SOCK_DIR")); dir != "" {
		candidates = append(candidates, filepath.Join(dir, name))
	} else {
		candidates = append(candidates, filepath.Join("/var/run/bpfrejit", name))
	}
	candidates = append(candidates, filepath.Join("/tmp", "bpfrejit-shim-"+strconv.Itoa(pid)+".sock"))
	return candidates
}

func shimRequest(socketPath string, payload any) ([]byte, error) {
	conn, err := net.DialTimeout("unix", socketPath, 5*time.Second)
	if err != nil {
		return nil, err
	}
	if err := conn.SetDeadline(time.Now().Add(120 * time.Second)); err != nil {
		closeErr := conn.Close()
		if closeErr != nil {
			return nil, fmt.Errorf("set deadline: %w; close: %w", err, closeErr)
		}
		return nil, err
	}

	req, err := json.Marshal(payload)
	if err != nil {
		closeErr := conn.Close()
		if closeErr != nil {
			return nil, fmt.Errorf("marshal request: %w; close: %w", err, closeErr)
		}
		return nil, err
	}
	req = append(req, '\n')
	if _, err := conn.Write(req); err != nil {
		closeErr := conn.Close()
		if closeErr != nil {
			return nil, fmt.Errorf("write request: %w; close: %w", err, closeErr)
		}
		return nil, err
	}
	raw, err := bufio.NewReader(conn).ReadBytes('\n')
	if err != nil {
		closeErr := conn.Close()
		if closeErr != nil {
			return nil, fmt.Errorf("read response: %w; close: %w", err, closeErr)
		}
		return nil, err
	}
	if err := conn.Close(); err != nil {
		return nil, err
	}
	return raw, nil
}

func validateExecuteResponse(raw []byte) (*executeResponse, error) {
	var resp executeResponse
	if err := json.Unmarshal(raw, &resp); err != nil {
		return nil, err
	}
	if resp.Status != "ok" {
		if resp.ErrorMessage != "" {
			return nil, errors.New(resp.ErrorMessage)
		}
		return nil, fmt.Errorf("top-level status %q", resp.Status)
	}
	if len(resp.PerProgram) == 0 {
		return nil, errors.New("response has no per_program entries")
	}
	for id, program := range resp.PerProgram {
		if program.Status != "ok" {
			return nil, fmt.Errorf("program %s status %q", id, program.Status)
		}
		if len(program.Passes) == 0 {
			return nil, fmt.Errorf("program %s has no pass results", id)
		}
		for i, pass := range program.Passes {
			if pass.Status != "ok" {
				return nil, fmt.Errorf("program %s pass %d status %q error=%v", id, i, pass.Status, pass.Error)
			}
		}
	}
	return &resp, nil
}

func shellQuote(s string) string {
	if s == "" {
		return "''"
	}
	return "'" + strings.ReplaceAll(s, "'", "'\"'\"'") + "'"
}

func exitf(format string, args ...any) {
	fmt.Fprintf(os.Stderr, format+"\n", args...)
	os.Exit(1)
}
