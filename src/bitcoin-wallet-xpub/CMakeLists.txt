# Find header and source files
FILE(GLOB bitcoin-wallet-xpub_header ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
FILE(GLOB bitcoin-wallet-xpub_source ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Set target libraries
ADD_LIBRARY(bitcoin-wallet-xpub SHARED ${bitcoin-wallet-xpub_source})
ADD_LIBRARY(bitcoin-wallet-xpub_static STATIC ${bitcoin-wallet-xpub_source})

find_package(PkgConfig REQUIRED)

# Set output name of static library
SET_TARGET_PROPERTIES(bitcoin-wallet-xpub_static PROPERTIES OUTPUT_NAME bitcoin-wallet-xpub)

# Set version settings
SET(VERSION_STRING ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})
SET_TARGET_PROPERTIES(bitcoin-wallet-xpub bitcoin-wallet-xpub_static PROPERTIES
    VERSION "${VERSION_STRING}"
    SOVERSION "${SO_VERSION}")
#

pkg_check_modules (LIBBITCOINSYSTEMCPP libbitcoin-system)
#
TARGET_LINK_LIBRARIES(bitcoin-wallet-xpub)

# Install to appropriate destinations
INSTALL(FILES ${bitcoin-wallet-xpub_header} DESTINATION include/bitcoin-wallet-xpub)

INSTALL(TARGETS bitcoin-wallet-xpub bitcoin-wallet-xpub_static
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib)
