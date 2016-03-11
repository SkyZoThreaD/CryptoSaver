/* 
 * Auditing VFS module for samba.  Log selected file operations to syslog
 * facility.
 *
 * Copyright (C) Tim Potter			1999-2000
 * Copyright (C) Alexander Bokovoy		2002
 * Copyright (C) Stefan (metze) Metzmacher	2002
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

// Part of CryptoSaver copyright 2016 SkyZoThreaD skyzothread@gmmail.com

// this module simply logs some operations to the cryptosaverd service.
// https://github.com/SkyZoThreaD/CryptoSaver

#include "includes.h"
#include "system/time.h"
#include "system/filesys.h"
#include "smbd/smbd.h"
#include "smbd/globals.h"
#include "ntioctl.h"
#include "smbprofile.h"
#include "../libcli/security/security.h"
#include "passdb/lookup_sid.h"
#include "source3/include/msdfs.h"
#include "librpc/gen_ndr/ndr_dfsblobs.h"
#include "lib/util/tevent_unix.h"
#include "lib/asys/asys.h"
#include "lib/util/tevent_ntstatus.h"
//#include "lib/sys_rw.h"


#include "includes.h"
#include "system/filesys.h"
#include "system/syslog.h"
#include "smbd/smbd.h"
#include "lib/param/loadparm.h"

#include <sys/types.h>
#include <sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include <sys/select.h>

#include <time.h>

#include <stdio.h>

#undef DBGC_CLASS
#define DBGC_CLASS DBGC_VFS

bool send_infos(const char *one, const char *two)
{
	int sock;
   	struct sockaddr_in server;

    	//Create socket
    	sock = socket(AF_INET , SOCK_STREAM , 0);
    	if (sock == -1)
    	{
        	return false;
    	}

    	server.sin_addr.s_addr = inet_addr("127.0.0.1");
    	server.sin_family = AF_INET;
    	server.sin_port = htons( 8888 );

    	//Connect to remote server
    	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    	{
        	return false;
    	}
	send(sock, one, strlen(one), 0);
	send(sock, two, strlen(two), 0);

	close(sock);

	return true;
}

static NTSTATUS cryptosaver_create_file(vfs_handle_struct *handle,
				      struct smb_request *req,
				      uint16_t root_dir_fid,
				      struct smb_filename *smb_fname,
				      uint32_t access_mask,
				      uint32_t share_access,
				      uint32_t create_disposition,
				      uint32_t create_options,
				      uint32_t file_attributes,
				      uint32_t oplock_request,
				      struct smb2_lease *lease,
				      uint64_t allocation_size,
				      uint32_t private_flags,
				      struct security_descriptor *sd,
				      struct ea_list *ea_list,
				      files_struct **result_fsp,
				      int *pinfo,
				      const struct smb2_create_blobs *in_context_blobs,
				      struct smb2_create_blobs *out_context_blobs)
{
	const char* str_create_disposition;
	switch (create_disposition) {
	case FILE_SUPERSEDE   :str_create_disposition = "supersede";break;
	case FILE_OVERWRITE_IF:str_create_disposition = "overwrite_if";break;
	case FILE_OPEN        :str_create_disposition = "open";break;
	case FILE_OVERWRITE   :str_create_disposition = "overwrite";break;
	case FILE_CREATE      :str_create_disposition = "create";break;
	case FILE_OPEN_IF     :str_create_disposition = "open_if";break;
	}
	
	
	if(create_disposition == FILE_OVERWRITE_IF)
	{
		/*
		conn->session_info->unix_info->unix_name,
		conn->connectpath,
		conn->session_info->unix_token->gid,
		conn->session_info->unix_info->sanitized_username,
		conn->session_info->info->domain_name,
		*/
			
		send_infos(smb_fname->base_name, handle->conn->session_info->info->domain_name);
	}
	
	return SMB_VFS_NEXT_CREATE_FILE(
				handle,					/* handle */
				req,					/* req */
				root_dir_fid,				/* root_dir_fid */
				smb_fname,				/* fname */
				access_mask,				/* access_mask */
				share_access,				/* share_access */
				create_disposition,			/* create_disposition*/
				create_options,				/* create_options */
				file_attributes,			/* file_attributes */
				oplock_request,				/* oplock_request */
				lease,					/* lease */
				allocation_size,			/* allocation_size */
				private_flags,
				sd,					/* sd */
				ea_list,				/* ea_list */
				result_fsp,				/* result */
				pinfo,					/* pinfo */
				in_context_blobs, out_context_blobs);	/* create context */
}

static struct vfs_fn_pointers vfs_cryptosaver_fns = {
	.create_file_fn = cryptosaver_create_file,
};

NTSTATUS vfs_cryptosaver_init(void);
NTSTATUS vfs_cryptosaver_init(void)
{
	return smb_register_vfs(SMB_VFS_INTERFACE_VERSION, "cryptosaver",
				&vfs_cryptosaver_fns);

}
