BUILD_DIR = .build

define lower
	lwr=$(shell echo $(2) | tr A-Z a-z)
	$(1) := $$(lwr)
endef

mkpath:
	$(eval $(call lower,subdir,$(build_type)))
	-mkdir -p ${BUILD_DIR}/${subdir}

build_target: mkpath
build_target:
	$(eval $(call lower,subdir,$(build_type)))
	cd ${BUILD_DIR}/${subdir} && cmake -DCMAKE_BUILD_TYPE=${build_type} ../..
	cd ${BUILD_DIR}/${subdir} && make -j`lscpu | grep "CPU(s)" | head -n1 | awk '{ print $$2 }'`

release: build_type=Release
release: build_target

debug: build_type=Debug
debug: build_target

install_target:
	$(eval $(call lower,subdir,$(build_type)))
	sudo cp ${BUILD_DIR}/${subdir}/libcppterm.so /usr/local/lib
	-@sudo mkdir -p /usr/local/include/cppterm
	sudo rsync -avm --include='*.h' -f 'hide,! */' src/ /usr/local/include/cppterm

install_debug: subdir=debug
install_debug: install_target

install_release: subdir=release
install_release: install_target

clean:
	-rm -rf ${BUILD_DIR}/debug
	-rm -rf ${BUILD_DIR}/release
	sudo rm /usr/local/lib/libcppterm.so
	sudo rm -rf /usr/local/include/cppterm

run_target: build_target
run_target:
	$(eval $(call lower,subdir,$(build_type)))
	LD_LIBRARY_PATH="/usr/local/lib" ${BUILD_DIR}/${subdir}/${app}

run_test: app=test
run_test: run_target

run_test_debug: build_type=Debug
run_test_debug: run_test
