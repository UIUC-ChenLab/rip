// <ORIGINAL-AUTHOR>: Benjamin Kemper
// <COMPONENT>: os-apis
// <FILE-TYPE>: component public header

/*!
 * @defgroup OS_APIS_FILE File
 * @brief Contains file related os apis
 */

#ifndef OS_APIS_FILE_H
#define OS_APIS_FILE_H


/*! @ingroup OS_APIS_FILE
 * File open modes
 */
typedef enum
{
    // For File objects                                     // For Directory objects
    // -----------------------------------------------------------------------------
    OS_FILE_OPEN_TYPE_READ                            = (1<<0),  // List members
    OS_FILE_OPEN_TYPE_WRITE                           = (1<<1),  // Add file
    OS_FILE_OPEN_TYPE_APPEND                          = (1<<2),  // Add sub-directory
    OS_FILE_OPEN_TYPE_TRUNCATE                        = (1<<3),  // N/A
    OS_FILE_OPEN_TYPE_CREATE                          = (1<<4),  // N/A
    OS_FILE_OPEN_TYPE_CREATE_EXCL                     = (1<<5),  // Create exclusively
    OS_FILE_OPEN_TYPE_DELETE                          = (1<<6),  // Delete
    OS_FILE_OPEN_TYPE_CLOSE_ON_EXEC                   = (1<<7)   // Close on exec (Unix systems only)
} OS_FILE_OPEN_TYPE;


/*! @ingroup OS_APIS_FILE
 * File permission modes
 */
typedef enum
{
    OS_FILE_PERMISSION_TYPE_READ                 = (1<<0),
    OS_FILE_PERMISSION_TYPE_WRITE                = (1<<1),
    OS_FILE_PERMISSION_TYPE_EXECUTE              = (1<<2)
} OS_FILE_PERMISSION_TYPE;

#define OS_APIS_FILE_PERMISSION_TYPE_ALL (OS_FILE_PERMISSION_TYPE_READ | \
                                          OS_FILE_PERMISSION_TYPE_WRITE| \
                                          OS_FILE_PERMISSION_TYPE_EXECUTE)

/*! @ingroup OS_APIS_FILE
 * File seek modes
 */
typedef enum
{
    //! Offset is set to the given @b offset bytes
    OS_FILE_SEEK_SET                 = 0,

    //! Offset is set to its current location plus @b offset bytes
    OS_FILE_SEEK_CUR                 = (1<<0),

    //! Offset is set to the size of the file plus @b offset bytes
    OS_FILE_SEEK_END                 = (1<<1)
} OS_FILE_SEEK_TYPE;

/*! @ingroup OS_APIS_FILE
 * Machine unique ID for file
 */
typedef struct _OS_FILE_UNIQUE_ID
{
    UINT64 _reserved[2];  // Reserved
} OS_FILE_UNIQUE_ID;


/*! @ingroup OS_APIS_FILE
 * File permission modes
 */
typedef enum
{
    OS_FILE_ATTRIBUTES_NONE                            = 0,
    OS_FILE_ATTRIBUTES_EXIST                           = (1<<0), // file exist
    OS_FILE_ATTRIBUTES_REGULAR                         = (1<<1), // file is regular
    OS_FILE_ATTRIBUTES_DIRECTORY                       = (1<<2), // file is directory
    OS_FILE_ATTRIBUTES_SYMLINK                         = (1<<3)  // file is symlink
} OS_FILE_ATTRIBUTES;


/*! @ingroup OS_APIS_FILE
 * The file name specified by path is opened for reading and/or writing,
 * as specified by the argument @b flags.
 *
 * @param[in]     path      File path.
 * @param[in]     flags     or'ed @ref OS_FILE_OPEN_TYPE. If mode @b OS_FILE_OPEN_TYPE_CREATE \n
 *                          was given, the file is created with @b mode.
 * @param[in]     mode      If a new file will be created as a result of this operation, this is the
 *                          mode of this newly created file. This argument contains values from
 *                          @ref OS_FILE_PERMISSION_TYPE combined with bitwise OR.
 * @param[out]    fd        Returned file descriptor
 *
 * @retval OS_RETURN_CODE_NO_ERROR              If the operation succeeded
 * @retval OS_RETURN_CODE_FILE_OPEN_FAILED      If the operation Failed
 * @return
 *      @b fd    - Assigned with the file descriptor\n
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X*\n
 *   @b CPU:   All\n
 */
OS_RETURN_CODE OS_OpenFD(const CHAR* path, INT flags, INT mode, NATIVE_FD* fd);


/*! @ingroup OS_APIS_FILE
 * Attempts to write @b count bytes of data to the object referenced by the descriptor
 * @b fd from the buffer pointed to by @b buffer.
 *
 * @param[in]       fd           File descriptor
 * @param[in]       buffer       Data buffer
 * @param[in,out]   count        Bytes to write
 *
 * @retval     OS_RETURN_CODE_NO_ERROR              If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_WRITE_FAILED     If the operation failed
 * @return
 *      @b size     Assigned with the number of bytes successfully written\n
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_WriteFD(NATIVE_FD fd, const VOID *buffer, USIZE *count);


/*! @ingroup OS_APIS_FILE
 * Attempts to read @b count bytes of data from the object referenced by the descriptor
 * @b fd to the buffer pointed to by @b buffer.
 *
 * @param[in]       fd           File descriptor
 * @param[in,out]   count        Bytes to read
 * @param[out]      buffer       Output buffer
 *
 * @retval     OS_RETURN_CODE_NO_ERROR              If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_READ_FAILED      If the operation failed
 * @return
 *      @b size     Assigned with the number of bytes successfully read \n
 *      @b buffer   Contains @b count bytes that were read from @b fd \n
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_ReadFD(NATIVE_FD fd, USIZE *count, VOID *buffer);


/*! @ingroup OS_APIS_FILE
 * Reposition the offset of the file descriptor @b fd to the an offset in,
 * the file denoted by offset.
 * The offset is measured with relation to a starting point determined by the
 * directive @b whence.
 *
 * @param[in]       fd           File descriptor
 * @param[in]       whence       @ref OS_FILE_SEEK_TYPE
 * @param[in,out]   offset       Bytes to move
 *
 * @retval     OS_RETURN_CODE_NO_ERROR              If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_SEEK_FAILED      If the operation failed
 * @return
 *      @b offset    - Assigned with the number of bytes successfully read\n
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_SeekFD(NATIVE_FD fd, INT whence, INT64 *offset);


/*! @ingroup OS_APIS_FILE
 * Closes @b fd and removes references to it from the process.
 *
 * @param[in]  fd    File descriptor
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_CLOSE_FAILED  If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_CloseFD(NATIVE_FD fd);

/*! @ingroup OS_APIS_FILE
 * Delete a file by name
 *
 * @param[in]  name      File path.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_DELETE_FAILED If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_DeleteFile(const CHAR* name);

/*! @ingroup OS_APIS_FILE
 * Flush the object referenced by the descriptor @b fd.
 *
 * @param[in] fd    File descriptor
 *
 * @retval     OS_RETURN_CODE_NO_ERROR      If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_FLUSH_FAILED  If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Windows \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_FlushFD(NATIVE_FD fd);


/*! @ingroup OS_APIS_FILE
 * Query @b fd's file attributes
 *
 * @param[in]  fd    File descriptor
 * @param[out] attr  File attributes
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_QUERY_FAILED  If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_GetFDAttributes(NATIVE_FD fd, OS_FILE_ATTRIBUTES *attr);


/*! @ingroup OS_APIS_FILE
 * Retrieve the current permissions for the specified file.
 *
 * @param[in]  fd            File descriptor
 * @param[out] permissions   or'ed @ref OS_FILE_PERMISSION_TYPE.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_QUERY_FAILED  If the operation failed
 *
 * @remark
 * On Unix, will provide the user (not group/other) permissions.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_FilePermissionsFD(NATIVE_FD fd, OS_FILE_PERMISSION_TYPE *permissions);

/*! @ingroup OS_APIS_FILE
 * Retrieves size in bytes of @b fd.
 *
 * @param[in]  fd            File descriptor
 * @param[out] size          Number of bytes.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_QUERY_FAILED  If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_FileSizeFD(NATIVE_FD fd, USIZE* size);

/*! @ingroup OS_APIS_FILE
 * Retrieves size in bytes of @b fd.
 *
 * @param[out] cwd           Buffer to receive the CWD.
 * @param[in]  len           Max buffer length.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_QUERY_FAILED  If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_Cwd(CHAR* cwd, INT len);

/*! @ingroup OS_APIS_FILE
 * Sets a new current directory. Optionally records the previous directory.
 *
 * @param[in]  dir           The directory to move to.
 * @param[out] cwd          Buffer to receive the CWD.
 * @param[in]  len          Max buffer length for cwd.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_QUERY_FAILED  If current directory capture failed
 * @retval     OS_RETURN_CODE_FILE_OPEN_FAILED   If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_Chdir(const CHAR* dir, CHAR* cwd, INT len);

/*! @ingroup OS_APIS_FILE
 * Opens a directory for browsing.
 *
 * @param[in]  name         Directory file name to open.
 * @param[out] fd           Pointer to returned file descriptor.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_OPEN_FAILED   If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_OpenDirFD(const CHAR* name, NATIVE_FD* fd);

/*! @ingroup OS_APIS_FILE
 * Creates a directory.
 *
 * @param[in]  name         Directory file name to create.
 * @param[in]  mode         File mode to create the directory.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded.
 * @retval     OS_RETURN_CODE_FILE_EXIST         Directory exists.
 * @retval     OS_RETURN_CODE_FILE_OPEN_FAILED   If the operation failed.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_MkDir(const CHAR* name, INT mode);

/*! @ingroup OS_APIS_FILE
 * Deletes a directory.
 *
 * @param[in]  name         Directory file name to delete.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded.
 * @retval     OS_RETURN_CODE_FILE_DELETE_FAILED If the operation failed.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_DeleteDirectory(const CHAR* name);

/*! @ingroup OS_APIS_FILE
 * Check whether a file descriptor is the application's console.
 * A file descriptor is the application's console if:
 *   1. The file of the underlying descriptor is a terminal device.
 *   2. The terminal device is the tty master (or console) of the current application.
 *
 * The practical implication of a console file descriptor is that every write
 * operation to it needs to be flushed right away because the user on the
 * other side expects to see output immediately.
 *
 * @param[in]  fd           File descriptor to check.
 * @param[out] isConsole    non-zero if 'fd' is the application's console.
 *                          Zero otherwise.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded.
 * @retval     OS_RETURN_CODE_FILE_QUERY_FAILED  If the operation failed.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_IsConsoleFD(NATIVE_FD fd, INT* isConsole);

/*! @ingroup OS_APIS_FILE
 * Attempts to read @b count bytes of data from the directory referenced by the descriptor
 * @b fd to the buffer pointed to by @b buffer.
 * A console file descriptor usually needs to be flushed after every read/write operation.
 *
 * @param[in]       fd           File descriptor
 * @param[in,out]   count        Bytes to read/Bytes read
 * @param[out]      buffer       Output buffer
 *
 * @retval     OS_RETURN_CODE_NO_ERROR              If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_READ_FAILED      If the operation failed
 * @return
 *      @b count     - Assigned with the number of bytes successfully read \n
 *      @b buffer    - Contains @b count bytes that were read from @b fd \n
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_ReadDirectoryFD(NATIVE_FD fd, USIZE* count, VOID* buffer);

/*! @ingroup OS_APIS_FILE
 * Get the permissions type requested when @b fd was opened.
 * This is useful to check whether we can read or write @b fd.
 *
 * @param[in]  fd           File descriptor to check.
 * @param[out] mode         The permissions of the file descriptor.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded.
 * @retval     OS_RETURN_CODE_FILE_QUERY_FAILED  If the operation failed.
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_GetFDAccessMode(NATIVE_FD fd, OS_FILE_OPEN_TYPE* mode);

/*! @ingroup OS_APIS_FILE
 * Reads the symbolic link pointed by @b path.
 * Returns the path that the symlink points to.
 *
 * @param[in]     path      Path to the symbolic link to read.
 * @param[out]    buf       The path where the symlink points to.
 * @param[in,out] size      The number of bytes in @b buf, returns the
 *                          number of bytes filled inside @b buf.
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded.
 * @retval     OS_RETURN_CODE_FILE_QUERY_FAILED  If the operation failed.
 *
 * @par Availability:
 *   @b O/S:   Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_ReadLink(const CHAR* path, CHAR* buf, USIZE* size);

/*! @ingroup OS_APIS_FILE
 * Query file attributes of the file denoted by @b path
 *
 * @param[in]  path  Path to file
 * @param[out] attr  File attributes
 *
 * @retval     OS_RETURN_CODE_NO_ERROR           If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_QUERY_FAILED  If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_GetFileAttributes(const CHAR* path, OS_FILE_ATTRIBUTES* attr);

/*! @ingroup OS_APIS_FILE
 * Renamed the file @b oldPath to @b newPath
 *
 * @param[in]  oldPath  Filename to rename
 * @param[in]  newPath  New filename to rename to
 *
 * @retval     OS_RETURN_CODE_NO_ERROR              If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_OPERATION_FAILED If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Windows, Linux & OS X* \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_RenameFile(const CHAR* oldPath, const CHAR* newPath);

/*! @ingroup OS_APIS_FILE
 * Get unique ID for an opened file, identified by a file descriptor.
 * Two opened file descriptors for the same physical file are guaranteed
 * to have the same unique ID.
 *
 * @param[in]  fd       File descriptor to calculate an ID.
 * @param[out] uniqueId The calculate unique ID (opaque binary data)
 *
 * @retval     OS_RETURN_CODE_NO_ERROR              If the operation succeeded
 * @retval     OS_RETURN_CODE_FILE_QUERY_FAILED     If the operation failed
 *
 * @par Availability:
 *   @b O/S:   Linux \n
 *   @b CPU:   All \n
 */
OS_RETURN_CODE OS_FileUniqueID(NATIVE_FD fd, OS_FILE_UNIQUE_ID* uniqueId);

# define OS_APIS_STDERR_FILENAME ((const CHAR*)((ADDRINT)2))

#endif // file guard
