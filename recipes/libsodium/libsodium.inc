inherit autotools c pkgconfig

DESCRIPTION = "libsodium - Sodium is a modern, easy-to-use software library for encryption, decryption, signatures, password hashing and more."
HOMEPAGE = "https://download.libsodium.org/doc/"
LICENSE = "ISC"
DEPENDS_${PN} = "libc"
RDEPENDS_${PN} = "libc"
PROVIDES_${PN} = "libsodium"
