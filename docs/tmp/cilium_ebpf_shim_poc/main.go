package main

import (
	"bufio"
	"encoding/json"
	"errors"
	"flag"
	"fmt"
	"net"
	"os"
	"path/filepath"
	"runtime"
	"strconv"
	"strings"
	"time"

	"github.com/cilium/ebpf"
	"github.com/cilium/ebpf/asm"
)

type executeResponse struct {
	Status       string                    `json:"status"`
	ErrorMessage string                    `json:"error_message"`
	PerProgram   map[string]programOutcome `json:"per_program"`
}

type programOutcome struct {
	Status string        `json:"status"`
	Passes []passOutcome `json:"passes"`
}

type passOutcome struct {
	Status string `json:"status"`
	Error  any    `json:"error"`
}

func main() {
	var passName string
	var bpfopt string
	var timeoutSeconds int
	flag.StringVar(&passName, "pass", "noop", "bpfopt pass to run through shim")
	flag.StringVar(&bpfopt, "bpfopt", getenvDefault("BPFOPT_BIN", "bpfopt"), "bpfopt binary path")
	flag.IntVar(&timeoutSeconds, "timeout", 60, "bpfopt step timeout in seconds")
	flag.Parse()

	if strings.TrimSpace(passName) == "" {
		exitf("-pass must not be empty")
	}
	if timeoutSeconds <= 0 {
		exitf("-timeout must be positive")
	}

	prog, err := ebpf.NewProgram(&ebpf.ProgramSpec{
		Name:    "cilium_shim_poc",
		Type:    ebpf.SocketFilter,
		License: "GPL",
		Instructions: asm.Instructions{
			asm.LoadImm(asm.R0, 0, asm.DWord),
			asm.Return(),
		},
	})
	if err != nil {
		exitf("load cilium/ebpf program: %v", err)
	}
	fmt.Printf("loaded cilium/ebpf program fd=%d pid=%d\n", prog.FD(), os.Getpid())

	socketPath, err := waitForShimSocket(os.Getpid(), 5*time.Second)
	if err != nil {
		exitf("%v", err)
	}
	fmt.Printf("using shim socket %s\n", socketPath)

	command := fmt.Sprintf(
		"timeout %d %s --pass %s --input ${INPUT} --output ${OUTPUT} --report ${REPORT} --prog-type ${PROG_TYPE} --target ${TARGET}",
		timeoutSeconds,
		shellQuote(bpfopt),
		shellQuote(passName),
	)
	request := map[string]any{
		"cmd": "execute_plan",
		"steps": []map[string]any{
			{
				"name":      passName,
				"command":   command,
				"log_level": 1,
			},
		},
	}

	raw, err := shimRequest(socketPath, request)
	if err != nil {
		exitf("shim execute_plan request: %v", err)
	}
	fmt.Printf("shim response: %s\n", raw)

	if err := validateExecuteResponse(raw); err != nil {
		exitf("execute_plan failed: %v", err)
	}

	runtime.KeepAlive(prog)
	fmt.Println("cilium/ebpf load reached shim and execute_plan completed")
}

func getenvDefault(key, fallback string) string {
	if v := strings.TrimSpace(os.Getenv(key)); v != "" {
		return v
	}
	return fallback
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

func validateExecuteResponse(raw []byte) error {
	var resp executeResponse
	if err := json.Unmarshal(raw, &resp); err != nil {
		return err
	}
	if resp.Status != "ok" {
		if resp.ErrorMessage != "" {
			return errors.New(resp.ErrorMessage)
		}
		return fmt.Errorf("top-level status %q", resp.Status)
	}
	if len(resp.PerProgram) == 0 {
		return errors.New("response has no per_program entries")
	}
	for id, program := range resp.PerProgram {
		if program.Status != "ok" {
			return fmt.Errorf("program %s status %q", id, program.Status)
		}
		if len(program.Passes) == 0 {
			return fmt.Errorf("program %s has no pass results", id)
		}
		for i, pass := range program.Passes {
			if pass.Status != "ok" {
				return fmt.Errorf("program %s pass %d status %q error=%v", id, i, pass.Status, pass.Error)
			}
		}
	}
	return nil
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
