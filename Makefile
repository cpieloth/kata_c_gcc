doc_dir=doc
build_dir=build

md2html_cmd:=pandoc -s -f markdown

all:
	@echo "make doc   - Generate documentation in HTML (requires pandoc)"

doc: clean
	mkdir -p $(build_dir)/$(doc_dir)
	for file in $(wildcard $(doc_dir)/*.md) ; do \
		echo Generating HTML for $$file ; \
		$(md2html_cmd) $$file -o $(build_dir)/$$file.html ; \
	done

clean:
	$(RM) -rf $(build_dir)
