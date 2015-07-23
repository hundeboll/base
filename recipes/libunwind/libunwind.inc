DESCRIPTION = "a portable and efficient C programming interface (API) to determine the call-chain of a program"
HOMEPAGE = "http://www.nongnu.org/libunwind"
LICENSE = "MIT"
COMPATIBLE_HOST_ARCHS = ".*linux"

inherit c++ autotools library auto-package-libs

SRC_URI = "http://download.savannah.nongnu.org/releases/${PN}/${PN}-${PV}.tar.gz"

AUTO_PACKAGE_LIBS = "unwind-ptrace unwind-arm unwind-coredump unwind-setjmp"
AUTO_PACKAGE_LIBS_DEPENDS = "libc libgcc-s"
AUTO_PACKAGE_LIBS_RDEPENDS = "libc libgcc-s"

LIBRARY_VERSION = "8"
LIBRARY_VERSION_${PN}-libunwind-coredump = "0"
LIBRARY_VERSION_${PN}-libunwind-ptrace = "0"
LIBRARY_VERSION_${PN}-libunwind-setjmp = "0"

DEPENDS_${PN} = "libc libgcc-s"
RDEPENDS_${PN} = "libc libgcc-s"
DEPENDS_${PN}-libunwind-arm = "libunwind"
RDEPENDS_${PN}-libunwind-arm = "libunwind"
DEPENDS_${PN}-libunwind-setjmp = "libunwind libunwind-arm"
RDEPENDS_${PN}-libunwind-setjmp = "libunwind libunwind-arm"
