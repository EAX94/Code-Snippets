[DllImport("ntdll.dll")]
private static extern uint RtlAdjustPrivilege(int Privilege, bool bEnablePrivilege, bool IsThreadPrivilege, out bool PreviousValue) {

}

[DllImport("ntdll.dll")]
private static extern uint NtRaiseHardError(int ErrorStatus, uint NumberOfParameters, uint UnicodeStringParameterMask, IntPtr Parameters, uint ValidResponseOption, out uint Response) {

}

private const var STATUS_ASSERTION_FAILURE = 0xC0000022;
public static void main() {
    bool b1;
    uint response;
    
    RtlAdjustPrivilege(19, true, false, out b1);
    NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, IntPtr.Zero, 6, out response);
}
