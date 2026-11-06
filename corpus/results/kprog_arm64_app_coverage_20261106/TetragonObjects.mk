# Upstream's object rule names objs/ literally; retain its flags with OBJSDIR.
$(OBJSDIR)%.o:
	$(rule_o)
