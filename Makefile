inc_dir := inc
src_dir := src
bin_dir := bin

project_name := splash
project := $(bin_dir)/$(project_name)

c_headers := $(wildcard $(inc_dir)/*.h)
c_sources := $(wildcard $(src_dir)/*.c)
c_objects := $(patsubst $(src_dir)/%.c, $(bin_dir)/%.o, $(c_sources))

c_std = -std=c11
c_opt = -O2
c_wrn = -Wall -Wextra -pedantic
c_inc = -Iinc
c_def = -DGAME_NAME="\"$(project_name)\""
CC ?= clang
CFLAGS := $(strip $(c_std) $(c_opt) $(c_wrn) $(c_inc) $(c_def))


.PHONY: all clean
all:
	@$(MAKE) $(project) 
clean:
	-rm -rf $(bin_dir)

$(project): $(c_objects)
	$(CC) $(CFLAGS) -Wl,-rpath,/usr/local/lib $^ -o $@ -lSDL3

$(bin_dir)/%.o: $(src_dir)/%.c $(wildcard $(inc_dir)/%.h) $(bin_dir)
	$(CC) $(CFLAGS) -c $< -o $@

$(bin_dir):
	-mkdir $@
