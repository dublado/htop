/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_SolarisProcess
#define HEADER_SolarisProcess
/*
htop - SolarisProcess.h
(C) 2015 Hisham H. Muhammad
(C) 2017,2018 Guy M. Broome
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "Settings.h"
#include <zone.h>

typedef enum SolarisProcessFields {
   // Add platform-specific fields here, with ids >= 100
   ZONEID   = 100,
   ZONE  = 101,
   PROJID = 102,
   TASKID = 103,
   POOLID = 104,
   CONTID = 105,
   LWPID = 106,
   LAST_PROCESSFIELD = 107,
} SolarisProcessField;


typedef struct SolarisProcess_ {
   Process    super;
   int        kernel;
   zoneid_t   zoneid;
   char*      zname;
   taskid_t   taskid;
   projid_t   projid;
   poolid_t   poolid;
   ctid_t     contid;
   bool       is_lwp;
   pid_t      realpid;
   pid_t      realppid;
   pid_t      lwpid;
} SolarisProcess;


#ifndef Process_isKernelThread
#define Process_isKernelThread(_process) (_process->kernel == 1)
#endif

#ifndef Process_isUserlandThread
#define Process_isUserlandThread(_process) (_process->pid != _process->tgid)
#endif


extern ProcessClass SolarisProcess_class;

extern ProcessFieldData Process_fields[];

extern ProcessPidColumn Process_pidColumns[];

SolarisProcess* SolarisProcess_new(Settings* settings);

void Process_delete(Object* cast);

void SolarisProcess_writeField(Process* this, RichString* str, ProcessField field);

long SolarisProcess_compare(const void* v1, const void* v2);

bool Process_isThread(Process* this);

#endif
