# -*- mode:python; -*-
DESCRIPTION = "A tool to generate squashfs filesystem as a normal (non-root) user."
LICENSE = "GPL"

COMPATIBLE_HOST_ARCHS = ".*linux .*darwin"

inherit make c

DEPENDS += "libz libm ${DEPENDS_LIBC}"
DEPENDS_LIBC = "libpthread"

require conf/fetch/sourceforge.conf
SRC_URI = "http://downloads.sourceforge.net/project/squashfs/squashfs/squashfs${PV}/squashfs${PV}.tar.gz"

S = "${SRCDIR}/squashfs4.2/squashfs-tools/"

RECIPE_TYPES = "machine native sdk"

do_install() {
  mkdir -p ${D}/bin/
  install -m 0755 ${S}/mksquashfs ${D}/bin/
  install -m 0755 ${S}/unsquashfs ${D}/bin/
}

DEPENDS_${PN} = "${DEPENDS}"
RDEPENDS_${PN} = "${DEPENDS}"
