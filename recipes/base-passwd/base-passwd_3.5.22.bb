DESCRIPTION = "Base system password/group files."
SECTION = "base"
LICENSE = "GPL"

PR = "r2"

RECIPE_OPTIONS = "passwd_root"
DEFAULT_CONFIG_passwd_root = "$1$L9mzJfTZ$2ED5as2K2yZ98CN/BQuy1."

SRC_URI = "${DEBIAN_MIRROR}/main/b/base-passwd/base-passwd_${PV}.tar.gz"

S = "${WORKDIR}/base-passwd"

do_install () {
	install -D -p -m 644 passwd.master \
		${D}${sysconfdir}/passwd
	install -D -p -m 644 group.master \
		${D}${sysconfdir}/group
}

do_install_append () {
	sed -i 's#^root:.*#root:${RECIPE_OPTION_passwd_root}:0:0:root:/:/bin/sh#g' ${D}${sysconfdir}/passwd
}
