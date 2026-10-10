.PHONY: c-test c-coverage c-sanitize c-lint c-format c-format-check c-clean

c-test:
	$(MAKE) -f config/c/Makefile test

c-coverage:
	$(MAKE) -f config/c/Makefile coverage

c-sanitize:
	$(MAKE) -f config/c/Makefile sanitize

c-lint:
	$(MAKE) -f config/c/Makefile lint

c-format:
	$(MAKE) -f config/c/Makefile format

c-format-check:
	$(MAKE) -f config/c/Makefile format-check

c-clean:
	$(MAKE) -f config/c/Makefile clean
