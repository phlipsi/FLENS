# CXX = g++
CXX = clang++

SOURCE_FILES = $(wildcard *.cc)
OBJECT_FILES = $(patsubst %.cc,%.o,$(SOURCE_FILES))

CXXFLAGS    += -I../../.. -std=c++11 -stdlib=libc++
LDFLAGS     +=

FLENSBLAS  = ../../../lib/blas_FLENS.a

all : $(OBJECT_FILES)
	ar crs $(FLENSBLAS) $(OBJECT_FILES)
	ranlib $(FLENSBLAS)

clean:
	$(RM) $(OBJECT_FILES) $(FLENSBLAS)
