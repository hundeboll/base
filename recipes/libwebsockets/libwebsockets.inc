# -*- mode:python; -*-
DESCRIPTION = "This is the libwebsockets C library for lightweight websocket \
clients and servers. "
HOMEPAGE = "http://libwebsockets.org"
LICENSE = "LGPL-2.1+program-based-on-libwebsockets-project-(http://libwebsockets.org)"

RECIPE_TYPES = "machine"

inherit c++ cmake auto-package-utils library pkgconfig

DEPENDS = "openssl libz libm"
DEPENDS_${PN} = "openssl libz libc libcrypto libdl libm libssl"
RDEPENDS_${PN} = "libz libc libcrypto libdl libm libssl "


# Split bin utils to individual packages in order to be able to take them along
# one at the time
AUTO_PACKAGE_UTILS = "libwebsockets-test-client  libwebsockets-test-echo \
libwebsockets-test-fraggle libwebsockets-test-ping libwebsockets-test-server\
 libwebsockets-test-server-extpoll "

AUTO_PACKAGE_UTILS_DEPENDS = "libc libcrypto libdl libm libssl libz"
AUTO_PACKAGE_UTILS_RDEPENDS = "libc libcrypto libdl libm libssl libz"

PACKAGES += "${PN}-test-server"
FILES_${PN}-test-server = "/usr/share/libwebsockets-test-server/*"
PACKAGES += "${PN}-cmake"
FILES_${PN}-cmake += "/usr/lib/cmake/libwebsockets/*"
