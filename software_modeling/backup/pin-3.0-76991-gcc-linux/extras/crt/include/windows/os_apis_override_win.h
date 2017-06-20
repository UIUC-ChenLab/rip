// <ORIGINAL-AUTHOR>: Barak Nirenberg
// <COMPONENT>: os-apis
// <FILE-TYPE>: component public header

#include "os-apis.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef OS_RETURN_CODE (*OS_FnPtrWriteFD)(NATIVE_FD fd, const void *buffer, USIZE *size);
typedef OS_RETURN_CODE (*OS_FnPtrReadFD)(NATIVE_FD fd, USIZE *size, void *buffer);
typedef OS_RETURN_CODE (*OS_FnPtrIsConsoleFD)(NATIVE_FD fd, INT* isConsole);
typedef UINT32 (*OS_FnNtCreateFile)(NATIVE_FD* hFile, 
                                      const CHAR * fileName,
                                      UINT32 accessMask,
                                      UINT32 objAttributes,
                                      UINT32 fileAttributes,
                                      UINT32 shareAccess,
                                      UINT32 createDisposition,
                                      UINT32 createOptions);

typedef struct _FileApiOverrides
{
    OS_FnPtrWriteFD writeFd;
    OS_FnPtrReadFD readFd;
    OS_FnPtrIsConsoleFD isConsoleFd;
    OS_FnNtCreateFile ntCreateFile;
} FileApiOverrides;

typedef VOID (*OS_FnPtrSetFileApiOverrides)(FileApiOverrides* overrides);
typedef FileApiOverrides* (*OS_FnPtrGetFileApiOverrides)();

#ifdef _BUILDING_OSAPIS
__declspec(dllexport)
#else
__declspec(dllimport)
#endif
VOID __cdecl OS_SetFileApiOverrides(FileApiOverrides* overrides);
FileApiOverrides* OS_GetFileApiOverrides();

#ifdef __cplusplus
}
#endif
