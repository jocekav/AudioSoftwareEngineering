#ifndef __MUSI6106_config_hdr__
#define __MUSI6106_config_hdr__

// set platform defines
#ifndef GTCMT_LINUX32
#cmakedefine GTCMT_LINUX32
#endif // GTCMT_LINUX32
#ifndef GTCMT_LINUX64
#cmakedefine GTCMT_LINUX64
#endif // GTCMT_LINUX64
#ifndef GTCMT_MACOSX
#cmakedefine GTCMT_MACOSX
#endif // GTCMT_MACOSX
#ifndef GTCMT_WIN32
#cmakedefine GTCMT_WIN32
#endif // GTCMT_WIN32
#ifndef GTCMT_WIN64
#cmakedefine GTCMT_WIN64
#endif // GTCMT_WIN64

//////////////////////////////////////////////////////////
// set module switches
#ifndef WITH_TESTS //!< UnitTest++ should be used for for testing
#cmakedefine WITH_TESTS
#endif // WITH_TESTS

// set the version number
#define MUSI6106_VERSION_MAJOR ${PROJECT_VERSION_MAJOR}
#define MUSI6106_VERSION_MINOR ${PROJECT_VERSION_MINOR}
#define MUSI6106_VERSION_PATCH ${PROJECT_VERSION_PATCH}

#endif // __MigEdit_config_hdr__
