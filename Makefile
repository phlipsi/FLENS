all :
	mkdir -p lib
	$(MAKE) -C netlib
	$(MAKE) -C src/interface/blas
	$(MAKE) -C src/interface/lapack
	$(MAKE) -C test/blas
	$(MAKE) -C test/lapack

check :
	$(MAKE) -C test/blas check
	$(MAKE) -C test/lapack check

clean :
	$(MAKE) -C netlib clean
	$(MAKE) -C test/blas clean
	$(MAKE) -C test/lapack clean
	$(MAKE) -C src/interface/blas clean
	$(MAKE) -C src/interface/lapack clean
	rmdir lib

