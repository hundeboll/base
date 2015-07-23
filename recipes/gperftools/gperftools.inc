DESCRIPTION = "Fast, multi-threaded malloc() and nifty performance analysis tools"
HOMEPAGE = "http://code.google.com/p/gperftools/"
LICENSE = "BSD"
DEPENDS = "libunwind libpthread"
COMPATIBLE_HOST_ARCHS = ".*linux"

inherit autotools c++ auto-package-libs
AUTO_PACKAGE_LIBS = "profiler tcmalloc tcmalloc_minimal tcmalloc_debug tcmalloc_minimal_debug tcmalloc_and_profiler"
AUTO_PACKAGE_LIBS_DEPENDS = "libc libgcc-s libm libstdc++"
AUTO_PACKAGE_LIBS_RDEPENDS = "libc libgcc-s libm libstdc++"
LIBRARY_VERSION = "4"
LIBRARY_VERSION_${PN}-libprofiler = "0"

DEPENDS_${PN} = "libc libgcc-s libm libpthread libstdc++"
RDEPENDS_${PN} = "libc libgcc-s libm libpthread libstdc++"


DEPENDS_${PN}-libtcmalloc += "libpthread"
RDEPENDS_${PN}-libtcmalloc += "libpthread"

DEPENDS_${PN}-libtcmalloc-minimal += "libpthread"
RDEPENDS_${PN}-libtcmalloc-minimal += "libpthread"

DEPENDS_${PN}-libtcmalloc-debug += "libpthread"
RDEPENDS_${PN}-libtcmalloc-debug += "libpthread"

DEPENDS_${PN}-libtcmalloc-minimal-debug += "libpthread"
RDEPENDS_${PN}-libtcmalloc-minimal-debug += "libpthread"

DEPENDS_${PN}-libtcmalloc-and-profiler += "libpthread"
RDEPENDS_${PN}-libtcmalloc-and-profiler += "libpthread"
