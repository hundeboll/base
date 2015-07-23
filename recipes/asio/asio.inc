DESCRIPTION = "Asio is a cross-platform C++ library for network and low-level \
    I/O programming that provides developers with a consistent asynchronous \
    model using a modern C++ approach."
HOMEPAGE = "http://think-async.com/Asio"
LICENSE = "BSL-1.0"

inherit autotools c++

DEPENDS += "boost-dev libpthread openssl"

require conf/fetch/sourceforge.conf
SRC_URI = "${SOURCEFORGE_MIRROR}/${PN}/${PN}-${PV}.tar.bz2"
