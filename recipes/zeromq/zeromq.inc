inherit autotools pkgconfig c c++ auto-package-utils

DESCRIPTION = "Zeromq - The Intelligent Transport Layer"
HOMEPAGE = "http://www.zeromq.org"
LICENSE = "LGPLv3+"
SRC_URI = "http://download.zeromq.org/zeromq-${PV}.tar.gz"

AUTO_PACKAGE_UTILS = "libzmq curve_keygen"
PROVIDES_${PN} = "libzmq"
PROVIDES_${PN}-dev = "libzmq-dev"
COMMON_DEPENDS = "libc libgcc libm libpthread libsodium libstdc++"
DEPENDS = "libsodium-dev libpthread"
DEPENDS_${PN} = "${COMMON_DEPENDS}"
RDEPENDS_${PN} = "${COMMON_DEPENDS}"
DEPENDS_${PN}-libzmq = "${COMMON_DEPENDS}"
RDEPENDS_${PN}-libzmq = "${COMMON_DEPENDS}"
DEPENDS_${PN}-curve-keygen = "libzmq ${COMMON_DEPENDS}"
RDEPENDS_${PN}-curve-keygen = "libzmq ${COMMON_DEPENDS}"
