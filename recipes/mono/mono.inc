DESCRIPTION = "Mono is an open source implementation of Microsoft's .NET Framework based on the ECMA standards for C# and the Common Language Runtime."
LICENSE = "LGPL-2.0"
RECIPE_TYPES = "native machine"

inherit autotools c++

# make the machine context depend on its native counter part to
# enable bootstrapping
DEPENDS = "libm libpthread librt libdl"
DEPENDS:>machine = " native:mono native:mono-jay"
SRC_URI = "http://download.mono-project.com/sources/mono/mono-${PV}.${SV}.tar.bz2"
SRC_URI:>machine = " file://enable-cross-mcs-build.patch"

# enable X11 if configured so by distro/machine
RECIPE_FLAGS = "x11"
MONO_X = "--with-x=no"
MONO_X:USE_x11 = "--with-x=yes"
DEPENDS:>USE_x11 = " libx11"

# comments to configure flags:
#   tls (thread local storage) fails to build with pthread
#   static_mono=no fails to build
EXTRA_OECONF = " \
    --enable-shared \
    --disable-rpath \
    --disable-system-aot \
    --with-gnu-ld \
    --with-tls=__thread \
    --with-static_mono=yes \
    --with-shared_mono=yes \
    --with-xen_opt=no \
    --with-mcs-docs=no \
    --with-sigaltstack=yes \
    ${MONO_X} \
"
EXTRA_OECONF:>native = " --disable-boehm"
EXTRA_OECONF:>machine = " --enable-mcs-build"

# the cross build should use the native version of the
# 'jay' binary, so fix the makefiles
DO_CONFIGURE_JAY = ""
DO_CONFIGURE_JAY:machine = "do_configure_jay"
do_configure[postfuncs] += "${DO_CONFIGURE_JAY}"
do_configure_jay() {
    find ${S} -name Makefile -exec sed -ir 's![^ \t]*jay/jay!jay!' {} \;
}

# fix cross build calls to mono
DO_CONFIGURE_LIBTOOL = ""
DO_CONFIGURE_LIBTOOL:machine = "do_configure_libtool"
do_configure[postfuncs] += "${DO_CONFIGURE_LIBTOOL}"
do_configure_libtool() {
    # make the wrapper use the native mono binary instead of libtooling it
    cat <<EOF > ${S}/runtime/mono-wrapper
#!/bin/sh
${BUILD_SYSROOT}/bin/mono --config ${S}/runtime/etc/mono/config "\$@"
EOF
}

# configure make to use native mcs and mono binaries
EXTRA_OEMAKE:machine = " \
    EXTERNAL_MCS=${BUILD_SYSROOT}/bin/mcs \
    EXTERNAL_RUNTIME=${BUILD_SYSROOT}/bin/mono \
    V=1 \
"

DO_INSTALL_FUNC = ""
DO_INSTALL_FUNC:native  = "do_install_native"
DO_INSTALL_FUNC:machine = "do_install_machine"
do_install() {
    ${DO_INSTALL_FUNC}
}

# partly rebuilds cannot find its own binaries, so
# help it out by updating the path
do_install_native() {
    export MONO_PATH=${S}/mcs/class/lib/basic
    export PATH=$PATH:${S}/runtime/_tmpinst/bin/
    do_install_make
}

do_install_machine() {
    do_install_make
}

# fix the mcs wrapper script to use the relative mono and
# mcs binaries from the staging dir
DO_INSTALL_MCS = ""
DO_INSTALL_MCS:native = "do_install_mcs"
do_install[postfuncs] += "${DO_INSTALL_MCS}"
do_install_mcs() {
    sed -i ${D}${bindir}/mcs \
        -e 's!/bin/mono!mono!' \
        -re 's!(/lib/mono/4.5/mcs.exe)!$(dirname $0)/..\1!'
}

FILES_${PN} += "${libdir} ${datadir}"

# create a native package for the jay binary and
# install that binary into it
PACKAGES:>native = " ${PN}-jay"
FILES_${PN}-jay:native = "${bindir}/jay"
DO_INSTALL_JAY = ""
DO_INSTALL_JAY:native = "do_install_jay"
do_install[postfuncs] += "${DO_INSTALL_JAY}"
do_install_jay() {
    install -d ${D}${bindir}
    install -m0755 ${S}/mcs/jay/jay ${D}${bindir}/jay
}
