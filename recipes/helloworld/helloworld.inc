DESCRIPTION = "Test applications for Mono"

DEPENDS = "native:mono"
SRC_URI = "https://github.com/netroby/mono-helloworld/archive/${SRC_REV}.zip"
S = "${SRCDIR}/mono-helloworld-${SRC_REV}"
FILES_${PN} = "${bindir}/hello.exe"
RDEPENDS_${PN} = "mono"

do_compile() {
    mcs hello.cs
}

do_install() {
    install -d ${D}${bindir}
    install ${S}/hello.exe ${D}${bindir}/hello.exe
}
