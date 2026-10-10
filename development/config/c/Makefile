# From development/config/c run: make test, make coverage, make clean
CC = gcc
ROOT = ../..
BUILD = $(ROOT)/.build/c
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O0 -g
.PHONY: test coverage clean

test:
	@set -e; mkdir -p $(BUILD); \
	find $(ROOT)/P* -type f -path '*/c/main.test.c' | sort | while IFS= read -r testfile; do \
	  src=$$(dirname "$$testfile")/main.c; \
	  id=$$(basename $$(dirname $$(dirname "$$testfile"))); \
	  output="$(BUILD)/$$id"; \
	  $(CC) $(CFLAGS) "$$src" "$$testfile" -o "$$output"; \
	  "$$output"; \
	done

coverage:
	@set -e; mkdir -p $(BUILD); \
	find $(ROOT)/P* -type f -path '*/c/main.test.c' | sort | while IFS= read -r testfile; do \
	  src=$$(dirname "$$testfile")/main.c; \
	  id=$$(basename $$(dirname $$(dirname "$$testfile"))); \
	  output="$(BUILD)/$$id"; \
	  $(CC) $(CFLAGS) --coverage "$$src" "$$testfile" -o "$$output"; \
	  "$$output"; \
	done
	cd $(ROOT) && gcovr -r . --exclude '.*main\.test\.c$$' --html-details -o config/c/coverage.html

clean:
	rm -rf $(BUILD) $(ROOT)/config/c/coverage.html $(ROOT)/config/c/coverage.*.html
