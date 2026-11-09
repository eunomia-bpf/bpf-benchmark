include /workspaces/repository/vendor/repos/tetragon/bpf/Makefile

$(OBJSDIR)%.o: $(PROCESSDIR)%.c
	$(rule_o)
