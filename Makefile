
.PHONY: format
format:
	find . -iname *.h -o -iname *.cpp | xargs clang-format --style=google -i
