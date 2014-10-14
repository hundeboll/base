# -*- mode:python; -*-
DESCRIPTION = "Mosquitto is an open source implementation of a\
	    server for version 3.1 and 3.1.1 of the MQTT protocol"

HOMEPAGE = "http://mosquitto.org"
LICENSE = "BSD-3-Clause"

RECIPE_TYPES = "machine"

S = "${SRCDIR}/mosquitto"

inherit c++ make pkgconfig

DEPENDS = "openssl libpthread librt libwebsockets-dev libz "
DEPENDS_${PN} = "openssl libpthread librt libwebsockets-dev libz "

RDEPENDS_${PN} = "libwebsockets"

# As of now include LDFLAGS+=-lz as the pkgconfig does not react on it
EXTRA_OEMAKE = "WITH_WEBSOCKETS=yes\
	      WITH_SRV=no \
	      WITH_UUID=no\
              LDFLAGS+=-lz prefix=/usr"

PACKAGES =+ " ${PN}-etc "
FILES_${PN}-etc = "/etc"
